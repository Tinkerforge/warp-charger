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

#include "modules.h"

#include "ArduinoJson.h"

#include <algorithm>

extern API api;
extern TaskScheduler task_scheduler;
extern char uid[7];

// Keep in sync with cm_networing.h
#define MAX_CLIENTS 6

#define CHARGE_MANAGER_ERROR_CHARGER_UNREACHABLE 128
#define CHARGE_MANAGER_ERROR_EVSE_UNREACHABLE 129
#define CHARGE_MANAGER_ERROR_EVSE_NONREACTIVE 130
#define CHARGE_MANAGER_CLIENT_ERROR_START 192

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
            0, MAX_CLIENTS, Config::type_id<Config::ConfObject>()
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

                {"state", Config::Uint8(0)}, //0 - no vehicle, 1 - user blocked, 2 - manager blocked, 3, car blocked, 4 - charging, 5 - error, 6 - charged
                {"error", Config::Uint8(0)} //0 - OK, 1 - Unreachable, 2 - FW mismatch, 3 - not managed
            }),
            0, MAX_CLIENTS, Config::type_id<Config::ConfObject>()
        )}
    });

    charge_manager_available_current = Config::Object({
        {"current", Config::Uint32(0)},
    });
}

uint8_t get_charge_state(uint8_t vehicle_state, uint8_t iec61851_state, uint8_t charge_release, uint32_t charging_time, uint16_t target_allocated_current) {
    if (vehicle_state == 0) //VEHICLE_STATE_NOT_CONNECTED
        return 0;
    if (vehicle_state == 2) // VEHICLE_STATE_CHARGING
        return 4;
    if (vehicle_state == 3) //VEHICLE_STATE_ERROR
        return 5;
    if (vehicle_state == 1 && iec61851_state == 0 && charge_release != 3) //VEHICLE_STATE_CONNECTED, IEC61851_STATE_A
        return 1;
    if (charge_release == 3 && target_allocated_current == 0) { // CHARGE_RELEASE_CHARGE_MANAGEMENT
        if (charging_time == 0)
            return 2;
        else
            return 6;
    }
    if (charge_release == 3 && target_allocated_current > 0)
        return 3;

    logger.printfln("Unknown state!");
    return 5;
}

void ChargeManager::start_manager_task() {
    std::vector<Config> &chargers = charge_manager_config_in_use.get("chargers")->asArray();

    std::vector<String> hosts;
    std::vector<String> names;
    for(int i = 0; i < chargers.size(); ++i) {
        hosts.push_back(chargers[i].get("host")->asString());
        names.push_back(chargers[i].get("name")->asString());
    }

    cm_networking.register_manager(hosts, names, [this, chargers](
            uint8_t client_id,
            uint8_t iec61851_state,
            uint8_t vehicle_state,
            uint8_t error_state,
            uint8_t charge_release,
            uint32_t uptime,
            uint32_t charging_time,
            uint16_t allowed_charging_current,
            uint16_t supported_current
        ){
            Config &target = charge_manager_state.get("chargers")->asArray()[client_id];
            // Don't update if the uptimes are the same.
            // This means, that the EVSE hangs or the communication
            // is not working. As last_update will now hang too,
            // the management will stop all charging after some time.
            if(target.get("uptime")->asUint() == uptime) {
                logger.printfln("Received stale charger state from %s (%s). Reported EVSE uptime (%u) is the same as in the last state. Is the EVSE still reachable?",
                    chargers[client_id].get("name")->asString().c_str(), chargers[client_id].get("host")->asString().c_str(),
                    uptime);
                if (deadline_elapsed(target.get("last_update")->asUint() + 10000)) {
                    target.get("state")->updateUint(5);
                    if (target.get("error")->updateUint(CHARGE_MANAGER_ERROR_EVSE_UNREACHABLE))
                        logger.printfln("%u %u %u",__LINE__, client_id, target.get("error")->asUint());
                }

                return;
            }

            target.get("uptime")->updateUint(uptime);

            target.get("wants_to_charge")->updateBool((charging_time == 0 && charge_release == 3 && vehicle_state == 1) || vehicle_state == 2); // CHARGE_RELEASE_CHARGE_MANAGEMENT
            target.get("is_charging")->updateBool(vehicle_state == 2); //VEHICLE_STATE_CHARGING
            target.get("allowed_current")->updateUint(allowed_charging_current);
            target.get("supported_current")->updateUint(supported_current);
            target.get("last_update")->updateUint(millis());

            if (error_state != 0) {
                target.get("error")->updateUint(CHARGE_MANAGER_CLIENT_ERROR_START + error_state);
            }

            auto current_error = target.get("error")->asUint();
            if (current_error < 128 || current_error == CHARGE_MANAGER_ERROR_EVSE_UNREACHABLE) {
                if (target.get("error")->updateUint(0))
                    logger.printfln("%u %u %u",__LINE__, client_id, target.get("error")->asUint());
            }

            current_error = target.get("error")->asUint();
            if (current_error == 0 || current_error >= CHARGE_MANAGER_CLIENT_ERROR_START)
                target.get("state")->updateUint(get_charge_state(vehicle_state,
                                                                iec61851_state,
                                                                charge_release,
                                                                charging_time,
                                                                target.get("allocated_current")->asUint()));
            charge_manager_state.get("uptime")->updateUint(millis());
    }, [this, chargers](uint8_t client_id, uint8_t error){
        Config &target = charge_manager_state.get("chargers")->asArray()[client_id];
        target.get("state")->updateUint(5);
        if (target.get("error")->updateUint(error))
            logger.printfln("%u %u %u",__LINE__, client_id, target.get("error")->asUint());
    });

    task_scheduler.scheduleWithFixedDelay("charge_manager_send", [this, chargers](){
        static int i = 0;

        if (i >= chargers.size())
            i = 0;

        Config &state = charge_manager_state.get("chargers")->asArray()[i];
        if(cm_networking.send_manager_update(i, state.get("allocated_current")->asUint()))
            ++i;

    }, 1000, 1000);
}

int idx_array[MAX_CLIENTS] = {0};

void ChargeManager::setup()
{
    String default_hostname = String(__HOST_PREFIX__) + String("-") + String(uid);
    if (!api.restorePersistentConfig("charge_manager/config", &charge_manager_config)) {
        charge_manager_config.get("chargers")->get(0)->get("name")->updateString(default_hostname);
    }

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
        idx_array[i] = i;
    }

    for(int i = charge_manager_config_in_use.get("chargers")->asArray().size(); i < MAX_CLIENTS; ++i)
        idx_array[i] = -1;

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
    local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log), "Redistributing current%c", '\0');

    auto &chargers = charge_manager_state.get("chargers")->asArray();
    auto &configs = charge_manager_config_in_use.get("chargers")->asArray();

    uint32_t current_array[MAX_CLIENTS] = {0};

    // Handle unreachable EVSEs
    bool unreachable_evse_found = false;
    for (int i = 0; i < chargers.size(); ++i) {
        auto &charger = chargers[i];
        auto &charger_cfg = configs[i];

        auto charger_error = charger.get("error")->asUint();
        if (charger_error != CM_NETWORKING_ERROR_NO_ERROR &&
            charger_error != CHARGE_MANAGER_ERROR_CHARGER_UNREACHABLE &&
            charger_error != CHARGE_MANAGER_ERROR_EVSE_NONREACTIVE &&
            charger_error < CHARGE_MANAGER_CLIENT_ERROR_START) {
            unreachable_evse_found = true;
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 0: %s (%s) reports error %u.%c",
                                  charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), charger.get("error")->asUint(), '\0');

            print_local_log = !last_print_local_log_was_error;
            last_print_local_log_was_error = true;
            break;
        }

        // Charger does not respond anymore
        if(deadline_elapsed(charger.get("last_update")->asUint() + TIMEOUT_MS)) {
            unreachable_evse_found = true;
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 0: Can't reach EVSE of %s (%s): last_update too old.%c",
                                  charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), '\0');
            if(chargers[i].get("state")->updateUint(5)) {
                if (chargers[i].get("error")->updateUint(CHARGE_MANAGER_ERROR_CHARGER_UNREACHABLE))
                    logger.printfln("%u %u %u",__LINE__, i, chargers[i].get("error")->asUint());
                print_local_log = !last_print_local_log_was_error;
                last_print_local_log_was_error = true;
            }
            break;
        } else if (chargers[i].get("error")->asUint() == CHARGE_MANAGER_ERROR_CHARGER_UNREACHABLE) {
            chargers[i].get("error")->updateUint(CM_NETWORKING_ERROR_NO_ERROR);
            logger.printfln("%u %u",__LINE__, chargers[i].get("error")->asUint());
        }

        // Charger did not update the charging current in time
        if(charger.get("allocated_current")->asUint() < charger.get("allowed_current")->asUint() && deadline_elapsed(charger.get("last_sent_config")->asUint() + TIMEOUT_MS)) {
            unreachable_evse_found = true;
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 0: EVSE of %s (%s) did not react in time.%c",
                                  charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), '\0');
            if(chargers[i].get("state")->updateUint(5)) {
                if (chargers[i].get("error")->updateUint(CHARGE_MANAGER_ERROR_EVSE_NONREACTIVE))
                    logger.printfln("%u %u %u",__LINE__, i, chargers[i].get("error")->asUint());
                print_local_log = !last_print_local_log_was_error;
                last_print_local_log_was_error = true;
            }
        } else if (chargers[i].get("error")->asUint() == CHARGE_MANAGER_ERROR_EVSE_NONREACTIVE) {
            if (chargers[i].get("error")->updateUint(CM_NETWORKING_ERROR_NO_ERROR))
                logger.printfln("%u %u %u",__LINE__, i, chargers[i].get("error")->asUint());
            break;
        }
    }

    if (unreachable_evse_found) {
        // Shut down everything.
        available_current = 0;
        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                              "            stage 0: Unreachable, unreactive or misconfigured EVSE(s) found. Setting available current to 0 mA.%c", '\0');
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
                          "            %d charger%s request%s current. %u mA available.%c",
                          chargers_requesting_current, chargers_requesting_current == 1 ? "" : "s", chargers_requesting_current == 1 ? "s" : "", available_current, '\0');

    // Allocate current
    std::stable_sort(idx_array, idx_array + chargers.size(), [chargers](int left, int right) {
        return chargers[left].get("supported_current")->asUint() < chargers[right].get("supported_current")->asUint();
    });

    std::stable_sort(idx_array, idx_array + chargers.size(), [chargers](int left, int right) {
        bool left_charging = chargers[left].get("is_charging")->asBool();
        bool right_charging = chargers[right].get("is_charging")->asBool();
        return left_charging && !right_charging;
    });

    int chargers_allocated_current_to = 0;
    int chargers_handled = 0;
    for(int i = 0; i < chargers.size(); ++i) {
        auto &charger = chargers[idx_array[i]];

        if (!charger.get("is_charging")->asBool() && !charger.get("wants_to_charge")->asBool()) {
            continue;
        }

        uint16_t current_to_set = 6000;
        ++chargers_handled;

        if (available_current < 6000) {
            current_to_set = 0;
        }

        if (current_to_set > 0) {
            ++chargers_allocated_current_to;
        }

        current_array[idx_array[i]] = current_to_set;
        available_current -= current_to_set;

        auto &charger_cfg = configs[idx_array[i]];
        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 0: Calculated target for %s (%s) of %u mA. %u mA left. %c",
                                  charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), current_to_set, available_current, '\0');
    }

    if (available_current > 0) {
        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                          "            %u mA still available. Recalculating targets.%c",
                          available_current, '\0');

        int chargers_reallocated = 0;
        for(int i = 0; i < chargers.size(); ++i) {
            if (current_array[idx_array[i]] == 0)
                continue;

            auto &charger = chargers[idx_array[i]];
            uint16_t current_per_charger = available_current / (chargers_allocated_current_to - chargers_reallocated);
            uint16_t current_to_add = MIN(charger.get("supported_current")->asUint() - current_array[idx_array[i]], current_per_charger);
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                    "            stage 0: current_per_charger %u avail %u alloc_to %u reallocd %u to_add %u%c",
                                    current_per_charger, available_current, chargers_allocated_current_to, chargers_reallocated, current_to_add, '\0');
            ++chargers_reallocated;

            current_array[idx_array[i]] += current_to_add;
            available_current -= current_to_add;

            auto &charger_cfg = configs[idx_array[i]];
            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                    "            stage 0: Recalculated target for %s (%s) of %u mA. %u mA left. %c",
                                    charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), current_array[idx_array[i]], available_current, '\0');
        }
    }

    // Throttle chargers
    bool skip_stage_2 = false;
    for (int i = 0; i < chargers.size(); ++i) {
        auto &charger = chargers[i];

        if (!charger.get("is_charging")->asBool() && !charger.get("wants_to_charge")->asBool()) {
            continue;
        }

        auto &charger_cfg = configs[i];
        uint16_t current_to_set = current_array[i];

        bool will_throttle = current_to_set < charger.get("allocated_current")->asUint() || current_to_set < charger.get("allowed_current")->asUint();

        if (!will_throttle) {
            continue;
        }

        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                              "            stage 1: Throttled %s (%s) to %d mA.%c",
                              charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), current_to_set, '\0');

        if(charger.get("allocated_current")->updateUint(current_to_set)) {
            print_local_log = true;
            charger.get("last_sent_config")->updateUint(millis());
        }

        // Skip stage 2 to wait for the charger to adapt to the now smaller limit.
        // Some cars are slow to adapt to a new limit. The standard requires them to
        // react in 5 seconds.
        // More correct would be to detect whether the throttled current limit
        // was accepted by the box more than 5 seconds ago (so that we can be sure the timing fits)
        // However this is complicated and waiting a complete cycle (i.e. 10 seconds)
        // works good enough.
        if(!skip_stage_2) {

            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            stage 1: Throttled a charger. Skipping stage 2%c",'\0');

            skip_stage_2 = true;
        }
    }

    if (!skip_stage_2) {
        for (int i = 0; i < chargers.size(); ++i) {
            auto &charger = chargers[i];

             if (!charger.get("is_charging")->asBool() && !charger.get("wants_to_charge")->asBool()) {
                continue;
            }

            auto &charger_cfg = configs[i];
            uint16_t current_to_set = current_array[i];

            // > instead of >= to only catch chargers that were not already modified in stage 1.
            bool will_not_throttle = current_to_set > charger.get("allocated_current")->asUint() || current_to_set > charger.get("allowed_current")->asUint();

            if (!will_not_throttle) {
                continue;
            }

            local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                "            stage 2: Unthrottled %s (%s) to %d mA.%c",
                                charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), current_to_set, '\0');

            if(charger.get("allocated_current")->updateUint(current_to_set)) {
                print_local_log = true;
                charger.get("last_sent_config")->updateUint(millis());
            }
        }
    } else {
        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                                  "            Skipping stage 2%c", '\0');
    }

    // Stage 3: Block any box that does not charge right now and does not want to charge.
    // This should be unnecessary, as the boxes automatically set their limit to 0 if
    // they are done charging. Better safe than sorry
    for (int i = 0; i < chargers.size(); ++i) {
        auto &charger = chargers[i];
        auto &charger_cfg = configs[i];
        if (charger.get("is_charging")->asBool() || charger.get("wants_to_charge")->asBool()) {
            continue;
        }

        local_log += snprintf(local_log, DISTRIBUTION_LOG_LEN - (local_log - distribution_log),
                              "            stage 3: Blocking %s (%s).%c",
                              charger_cfg.get("name")->asString().c_str(), charger_cfg.get("host")->asString().c_str(), '\0');

        if(charger.get("allocated_current")->updateUint(0)) {
            print_local_log = true;
            charger.get("last_sent_config")->updateUint(millis());
        }
    }

    if (print_local_log) {
        local_log = distribution_log;
        size_t len = strlen(local_log);
        while (len > 0) {
            logger.write(local_log, len);
            local_log += len + 1;
            if ((local_log - distribution_log) >= DISTRIBUTION_LOG_LEN)
                break;
            len = strlen(local_log);
        }
    }
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
