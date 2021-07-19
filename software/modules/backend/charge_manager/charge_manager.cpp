/* warp-charger
 * Copyright (C) 2020-2021 Erik Fleckstein <erik@tinkerforge.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "charge_manager.h"

#include <Arduino.h>
#include "time.h"

#include "api.h"
#include "task_scheduler.h"
#include "tools.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_http_client.h"

#include "modules/firmware_update/firmware_update.h"

#include "modules/evse/charge_management_protocol.h"

#include "ArduinoJson.h"

extern API api;
extern TaskScheduler task_scheduler;

extern FirmwareUpdate firmware_update;

ChargeManager::ChargeManager()
{
    charge_manager_config = Config::Object({
        {"enable_charge_manager", Config::Bool(false)},
        {"default_available_current", Config::Uint32(0)},
        {"chargers", Config::Array(
            {
                Config::Object({
                    {"host", Config::Str("127.0.0.1", 64)},
                    {"name", Config::Str("Lokale Wallbox", 32)}
                })
            },
            Config::Object({
                {"host", Config::Str("", 64)},
                {"name", Config::Str("", 32)}
            }),
            0, 6, Config::type_id<Config::ConfObject>()
        )}
    });

    charge_manager_state = Config::Object({
        {"state", Config::Uint8(0)}, // 0 - not configured, 1 - active, 2 - shutdown
        {"uptime", Config::Uint32(0)},
        {"chargers", Config::Array(
            {},
            Config::Object({
                {"name", Config::Str("", 32)},
                {"last_update", Config::Uint32(0)},
                {"uptime", Config::Uint32(0)},
                {"supported_current", Config::Uint16(0)},
                {"allowed_current", Config::Uint16(0)},
                {"wants_to_charge", Config::Bool(false)},
                {"is_charging", Config::Bool(false)},

                {"last_sent_config", Config::Uint32(0)},
                {"allocated_current", Config::Uint16(0)},

                {"state", Config::Uint8(0)}, //0 - no vehicle, 1 - user blocked, 2 - manager blocked, 3, car blocked, 4 - charging, 5 - error
                {"error", Config::Uint8(0)} //0 - OK, 1 - Unreachable, 2 - FW mismatch
            }),
            0, 6, Config::type_id<Config::ConfObject>()
        )}
    });

    charge_manager_available_current = Config::Object({
        {"current", Config::Uint32(0)},
    });
}

uint8_t get_charge_state(uint8_t vehicle_state, uint8_t iec61851_state, uint8_t charge_release, uint16_t target_allocated_current) {
    if (vehicle_state == 0) //VEHICLE_STATE_NOT_CONNECTED
        return 0;
    if (vehicle_state == 2) // VEHICLE_STATE_CHARGING
        return 4;
    if (vehicle_state == 3) //VEHICLE_STATE_ERROR
        return 5;
    if (vehicle_state == 1 && iec61851_state == 0 && charge_release != 3) //VEHICLE_STATE_CONNECTED, IEC61851_STATE_A
        return 1;
    if (charge_release == 3 && target_allocated_current == 0) // CHARGE_RELEASE_CHARGE_MANAGEMENT
        return 2;
    if (charge_release == 3 && target_allocated_current > 0)
        return 3;

    logger.printfln("Unknown state!");
    return 5;
}

void ChargeManager::start_manager_task() {
    std::vector<Config> &chargers = charge_manager_config_in_use.get("chargers")->asArray();

    struct sockaddr_in dest_addrs[6] = {0};

    for(int i = 0; i < chargers.size(); ++i) {
        dest_addrs[i].sin_addr.s_addr = inet_addr(chargers[i].get("host")->asString().c_str());
        dest_addrs[i].sin_family = AF_INET;
        dest_addrs[i].sin_port = htons(CHARGE_MANAGEMENT_PORT);
    }

    int sock = create_socket(true);
    if (sock < 0)
        return;

    task_scheduler.scheduleWithFixedDelay("charge_manager_send", [this, sock, dest_addrs](){
        static uint32_t next_seq_num = 1;
        static int i = 0;

        std::vector<Config> &chargers = charge_manager_config_in_use.get("chargers")->asArray();

        if (i >= chargers.size())
            i = 0;

        Config &charger = chargers[i];

        request_packet request;
        request.header.version[0] = _MAJOR_;
        request.header.version[1] = _MINOR_;
        request.header.version[2] = _PATCH_;
        request.header.seq_num = next_seq_num;
        ++next_seq_num;

        Config &state = charge_manager_state.get("chargers")->asArray()[i];

        request.allocated_current = state.get("allocated_current")->asUint();

        int err = sendto(sock, &request, sizeof(request), 0, (sockaddr *)&dest_addrs[i], sizeof(dest_addrs[i]));

        if(err < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                // Intentionally don't increment i here, we want to resend to this charger next.
                return;
            logger.printfln("Failed to send to %s. errno: %d", charger.get("host")->asString().c_str(), errno);
            ++i;
            return;
        }
        if (err != sizeof(request)) {
            logger.printfln("Failed to send to %s. sendto truncated request (of %u bytes) to %d bytes.", sizeof(request), err);
            ++i;
            return;
        }
        //logger.printfln("Sent update to %s (%s); Current: %u", charger.get("name")->asString().c_str(), inet_ntoa(dest_addrs[i].sin_addr), request.allocated_current);

        ++i;
    }, 1000, 1000);


    task_scheduler.scheduleWithFixedDelay("charge_manager_receive_task", [this, chargers, sock, dest_addrs](){
        static uint8_t last_seen_seq_num[6] = {255, 255, 255, 255, 255, 255};
        response_packet recv_buf[2] = {0};
        struct sockaddr_in source_addr;
        socklen_t socklen = sizeof(source_addr);

        int len = recvfrom(sock, recv_buf, sizeof(recv_buf), 0, (sockaddr *)&source_addr, &socklen);

        if (len < 0) {
            if (errno != EAGAIN && errno != EWOULDBLOCK)
                logger.printfln("recvfrom failed: errno %d", errno);
            return;
        }

        if (len != sizeof(response_packet)) {
            logger.printfln("Received datagram of wrong size %d from %s", len, inet_ntoa(source_addr.sin_addr));
            return;
        }

        int charger_idx = -1;
        for(int i = 0; i < chargers.size(); ++i)
            if (source_addr.sin_family == dest_addrs[i].sin_family &&
                source_addr.sin_port == dest_addrs[i].sin_port &&
                source_addr.sin_addr.s_addr == dest_addrs[i].sin_addr.s_addr) {
                charger_idx = i;
                break;
            }

        if (charger_idx == -1) {
            logger.printfln("Received packet from unknown %s. Is the configuration complete?", inet_ntoa(source_addr.sin_addr));
            return;
        }

        response_packet response;
        memcpy(&response, recv_buf, sizeof(response));

        if (response.header.seq_num <= last_seen_seq_num[charger_idx] && last_seen_seq_num[charger_idx] - response.header.seq_num < 5) {
            logger.printfln("Received stale (out of order?) packet from %s (%s). Last seen seq_num is %u, Received seq_num is %u",
                chargers[charger_idx].get("name")->asString().c_str(),
                inet_ntoa(source_addr.sin_addr),
                last_seen_seq_num[charger_idx],
                response.header.seq_num);
            return;
        }

        if (response.header.version[0] != _MAJOR_ || response.header.version[1] != _MINOR_ || response.header.version[2] != _PATCH_) {
            logger.printfln("Received packet from %s (%s) with incompatible firmware. Our version is %u.%u.%u, received packet had %u.%u.%u",
                chargers[charger_idx].get("name")->asString().c_str(),
                inet_ntoa(source_addr.sin_addr),
                _MAJOR_, _MINOR_, _PATCH_,
                response.header.version[0],
                response.header.version[1],
                response.header.version[2]);
            return;
        }

        last_seen_seq_num[charger_idx] = response.header.seq_num;

        Config &target = charge_manager_state.get("chargers")->asArray()[charger_idx];
        // Don't update if the uptimes are the same.
        // This means, that the EVSE hangs or the communication
        // is not working. As last_update will now hang too,
        // the management will stop all charging after some time.
        if(target.get("uptime")->asUint() == response.uptime) {
            logger.printfln("Received stale charger state from %s (%s). Reported EVSE uptime (%u) is the same as in the last state. Is the EVSE still reachable?",
                chargers[charger_idx].get("name")->asString().c_str(),
                inet_ntoa(source_addr.sin_addr),
                response.uptime);
            return;
        }

        target.get("uptime")->updateUint(response.uptime);
        target.get("wants_to_charge")->updateBool(response.charge_release == 3); // CHARGE_RELEASE_CHARGE_MANAGEMENT
        target.get("is_charging")->updateBool(response.vehicle_state == 2); //VEHICLE_STATE_CHARGING
        target.get("allowed_current")->updateUint(response.allowed_charging_current);
        target.get("last_update")->updateUint(millis());
        target.get("state")->updateUint(get_charge_state(response.vehicle_state,
                                                            response.iec61851_state,
                                                            response.charge_release,
                                                            target.get("allocated_current")->asUint()));
        charge_manager_state.get("uptime")->updateUint(millis());
    }, 100, 100);
}

void ChargeManager::setup()
{
    api.restorePersistentConfig("charge_manager/config", &charge_manager_config);

    charge_manager_config_in_use = charge_manager_config;

    if(!charge_manager_config_in_use.get("enable_charge_manager")->asBool() || charge_manager_config_in_use.get("chargers")->asArray().size() == 0) {
        initialized = true;
        return;
    }
    charge_manager_state.get("state")->updateUint(1);

    charge_manager_available_current.get("current")->updateUint(charge_manager_config_in_use.get("default_available_current")->asUint());
    for(int i = 0; i < charge_manager_config_in_use.get("chargers")->asArray().size(); ++i) {
        charge_manager_state.get("chargers")->add();
        charge_manager_state.get("chargers")->get(i)->get("name")->updateString(charge_manager_config_in_use.get("chargers")->get(i)->get("name")->asString());
    }

    //xTaskCreatePinnedToCore(&http_work, "http_work_task", 8192, this, 1, NULL, 1);
    start_manager_task();

    task_scheduler.scheduleWithFixedDelay("distribute current", [this](){this->distribute_current();}, 10000, 10000);
    initialized = true;
}

#define TIMEOUT_MS 32000

#define DISTRIBUTION_LOG_LEN 2048
char distribution_log[DISTRIBUTION_LOG_LEN] = {0};

void ChargeManager::distribute_current() {
    std::lock_guard<std::mutex> lock(state_mutex);
    uint32_t available_current = charge_manager_available_current.get("current")->asUint();

    static bool last_print_local_log_was_error = false;
    bool print_local_log = false;
    char *local_log = distribution_log;
    local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log), "Redistributing current\n");

    auto &chargers = charge_manager_state.get("chargers")->asArray();
    // Handle unreachable EVSEs
    bool unreachable_evse_found = false;
    for (int i = 0; i < chargers.size(); ++i) {
        auto &charger = chargers[i];
        auto *charger_cfg = charge_manager_config_in_use.get("chargers")->get(i);

        // Charger does not respond anymore
        if(deadline_elapsed(charger.get("last_update")->asUint() + TIMEOUT_MS)) {
            unreachable_evse_found = true;
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            Can't reach EVSE of %s (%s): last_update too old.\n",
                                  charger_cfg->get("name")->asString().c_str(), charger_cfg->get("host")->asString().c_str());
            if(chargers[i].get("state")->updateUint(5)) {
                print_local_log = !last_print_local_log_was_error;
                last_print_local_log_was_error = true;
            }
            break;
        }

        // Charger did not update the charging current in time
        if(charger.get("allocated_current")->asUint() < charger.get("allowed_current")->asUint() && deadline_elapsed(charger.get("last_sent_config")->asUint() + TIMEOUT_MS)) {
            unreachable_evse_found = true;
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            EVSE of %s (%s) did not react in time.\n",
                                  charger_cfg->get("name")->asString().c_str(), charger_cfg->get("host")->asString().c_str());
            if(chargers[i].get("state")->updateUint(5)) {
                print_local_log = !last_print_local_log_was_error;
                last_print_local_log_was_error = true;
            }
            break;
        }
    }

    if (unreachable_evse_found) {
        // Shut down everything.
        available_current = 0;
        print_local_log = true;
        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                              "            Unreachable or unreactive EVSE(s) found. Setting available current to 0 mA.\n");
        charge_manager_state.get("state")->updateUint(2);
    } else {
        charge_manager_state.get("state")->updateUint(1);
        if (last_print_local_log_was_error) {
            last_print_local_log_was_error = false;
            print_local_log = true;
        }
    }

    // Calculate current per charger.
    // For now, every charger gets the same current.
    // This does not consider chargers with different current limitations yet.
    int chargers_requesting_current = 0;
    for (auto &charger : chargers) {
        if (!charger.get("is_charging")->asBool() && !charger.get("wants_to_charge")->asBool()) {
            continue;
        }
        ++chargers_requesting_current;
    }

    local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                          "            %d chargers request current\n",
                          chargers_requesting_current);

    // Allocate current

    // Stage 1: Limit boxes already charging.
    uint16_t current_per_charger = chargers_requesting_current == 0 ? 0 : MIN(32000, MAX(6000, available_current / chargers_requesting_current));

    local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                          "            Current per charger: %u\n",
                          current_per_charger);

    bool skip_stage_2 = false;
    for (int i = 0; i < chargers.size(); ++i) {
        auto &charger = chargers[i];
        auto *charger_cfg = charge_manager_config_in_use.get("chargers")->get(i);

        if (!charger.get("is_charging")->asBool()) {
            continue;
        }
        if(available_current < current_per_charger) {
            // We don't have enough current left. This happens for example if we have 16A available and 3 boxes want to charge.
            // The minimal charge current is 6A, so with only 4A left for the third box, it may not start charging.
            // Assign 0 to current_per_charger here, so that we always can allocate current_per_charger to the following chargers.
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 1: not enough current left (%d)\n",
                                  available_current);
            available_current = 0;
            current_per_charger = 0;
        }

        available_current -= current_per_charger;

        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                              "            stage 1: allocated %d mA to %s (%s).\n",
                              current_per_charger, charger_cfg->get("name")->asString().c_str(), charger_cfg->get("host")->asString().c_str());

        if(charger.get("allocated_current")->updateUint(current_per_charger)) {
            print_local_log = true;
            charger.get("last_sent_config")->updateUint(millis());
        }

        if(!skip_stage_2 && current_per_charger < charger.get("allocated_current")->asUint() || current_per_charger < charger.get("allowed_current")->asUint()) {
            // Skip stage 2 to wait for the charger to adapt to the now smaller limit.
            // Some cars are slow to adapt to a new limit.
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 1: Throttled a charger. Skipping stage 2\n",
                                  available_current);

            skip_stage_2 = true;
        }
    }

    // Stage 2: Allow boxes to charge if any current is left.
    // This will allocate 0 if no current is left.
    if (!skip_stage_2) {
        for (int i = 0; i < chargers.size(); ++i) {
            auto &charger = chargers[i];
            auto *charger_cfg = charge_manager_config_in_use.get("chargers")->get(i);
            if (charger.get("is_charging")->asBool() || !charger.get("wants_to_charge")->asBool()) {
                continue;
            }

            if(available_current < current_per_charger) {
                // See above
                local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                      "            stage 2: not enough current left (%d)\n",
                                      available_current);

                available_current = 0;
                current_per_charger = 0;
            }
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 2: allocated %d mA to %s (%s).\n",
                                  current_per_charger, charger_cfg->get("name")->asString().c_str(), charger_cfg->get("host")->asString().c_str());

            available_current -= current_per_charger;
            if(charger.get("allocated_current")->updateUint(current_per_charger)) {
                print_local_log = true;
                charger.get("last_sent_config")->updateUint(millis());
            }
        }
    }

    // Stage 3: Block any box that does not charge right now and does not want to charge.
    // This should be unnecessary, as the boxes automatically set their limit to 0 if
    // they are done charging. Better safe than sorry
    for (int i = 0; i < chargers.size(); ++i) {
        auto &charger = chargers[i];
        auto *charger_cfg = charge_manager_config_in_use.get("chargers")->get(i);
        if (charger.get("is_charging")->asBool() || charger.get("wants_to_charge")->asBool()) {
            continue;
        }

        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                              "            stage 3: blocking %s (%s) as it does not want to charge.\n",
                              charger_cfg->get("name")->asString().c_str(), charger_cfg->get("host")->asString().c_str());

        if(charger.get("allocated_current")->updateUint(0)) {
            print_local_log = true;
            charger.get("last_sent_config")->updateUint(millis());
        }
    }

    if (print_local_log)
        logger.write(distribution_log, local_log - distribution_log);
}

void ChargeManager::register_urls()
{
    api.addPersistentConfig("charge_manager/config", &charge_manager_config, {"password"}, 1000);
    api.addState("charge_manager/state", &charge_manager_state, {}, 1000);
    api.addState("charge_manager/available_current", &charge_manager_available_current, {}, 1000);
    api.addCommand("charge_manager/available_current_update", &charge_manager_available_current, {}, [](){}, false);
}

void ChargeManager::loop()
{

}
