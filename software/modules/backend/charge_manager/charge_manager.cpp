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


extern API api;
extern TaskScheduler task_scheduler;

ChargeManager::ChargeManager()
{
    charge_manager_config = Config::Object({
        {"enable_charge_manager", Config::Bool(false)},
        {"available_current", Config::Uint16(0)}, //TODO: Allow to change this dynamically without restart
        {"chargers", Config::Array(
            {},
            Config::Object({
                {"host", Config::Str("", 128)},
                {"port", Config::Uint16(80)},
                {"username", Config::Str("", 64)},
                {"password", Config::Str("", 64)},
            }),
            0, 5, Config::type_id<Config::ConfObject>()
        )}
    });

    charge_manager_state = Config::Object({
        {"state", Config::Uint8(0)}, // 0 - active, 1 - shutdown
        {"chargers", Config::Array(
            {},
            Config::Object({
                {"last_update", Config::Uint32(0)},
                {"uptime", Config::Uint32(0)},
                {"supported_current", Config::Uint16(0)},
                {"allowed_current", Config::Uint16(0)},
                {"wants_to_charge", Config::Bool(false)},
                {"is_charging", Config::Bool(false)},

                {"last_sent_config", Config::Uint32(0)},
                {"allocated_current", Config::Uint16(0)},
            }),
            0, 6, Config::type_id<Config::ConfObject>()
        )}
    });
}

void ChargeManager::update_local_evse_state(Config *target) {
    auto *state = api.getState("evse/state");
    // Don't update if the uptimes are the same.
    // This means, that the EVSE hangs or the communication
    // is not working. As last_update will now hang too,
    // the management will stop all charging after some time.
    if(target->get("uptime")->asUint() == state->get("uptime")->asUint())
        return;

    target->get("uptime")->updateUint(state->get("uptime")->asUint());
    target->get("wants_to_charge")->updateBool(state->get("charge_release")->asUint() == 3); // CHARGE_RELEASE_CHARGE_MANAGEMENT
    target->get("is_charging")->updateBool(state->get("vehicle_state")->asUint() == 2); //VEHICLE_STATE_CHARGING

    target->get("allowed_current")->updateUint(state->get("allowed_charging_current")->asUint());
    target->get("last_update")->updateUint(millis());
}

void ChargeManager::start_evse_state_update() {
    if(request_in_progress)
        return;

    ++current_charger;
    auto &chargers = charge_manager_config_in_use.get("chargers")->asArray();

    if (current_charger == chargers.size()) {
        this->update_local_evse_state(&charge_manager_state.get("chargers")->asArray()[current_charger]);
        return;
    }
    else if (current_charger > chargers.size()) {
        current_charger = 0;
    }

    auto *charger = &chargers[current_charger];
    Config *target = &charge_manager_state.get("chargers")->asArray()[current_charger];

    client.regOnClosed([this](){
        logger.printfln("Closed");
        request_in_progress = false;
    });
    client.regOnError([this](){
        logger.printfln("Error");
        request_in_progress = false;
    });
    client.regOnResponse([this, target](const HttpResponse& rsp){
        size_t to_read = 0;
        rsp.getPayload(to_read);
        logger.printfln("Response");

        //TODO: don't hard-code this!
        StaticJsonDocument<384> doc;
        DeserializationError error = deserializeJson(doc, rsp.getPayload(to_read), to_read);

        if (error) {
            Serial.print(F("deserializeJson() failed: "));
            Serial.println(error.f_str());
            request_in_progress = false;
            return;
        }

        // Don't update if the uptimes are the same.
        // This means, that the EVSE hangs or the communication
        // is not working. As last_update will now hang too,
        // the management will stop all charging after some time.
        if(target->get("uptime")->asUint() == doc["uptime"]) {
            request_in_progress = false;
            return;
        }

        //TODO: This should be done in the main thread, i.e. in a task.
        target->get("uptime")->updateUint(doc["uptime"]);
        target->get("wants_to_charge")->updateBool(doc["charge_release"] == 3); // CHARGE_RELEASE_CHARGE_MANAGEMENT
        target->get("is_charging")->updateBool(doc["vehicle_state"] == 2); //VEHICLE_STATE_CHARGING
        target->get("allowed_current")->updateUint(doc["allowed_charging_current"]);
        target->get("last_update")->updateUint(millis());

        request_in_progress = false;
        client.end();
    });

    ++request_id;
    uint32_t local_request_id = request_id;
    request_in_progress = true;

    String url = String("http://") + charger->get("host")->asString() + String(":") + String(charger->get("port")->asUint()) + String("/evse/state");

    if(!client.begin(url) || !client.GET()) {
        request_in_progress = false;
        client.end();
        return;
    }

    task_scheduler.scheduleOnce("unblock_cm_http_client", [this, local_request_id](){
        if(!request_in_progress || this->request_id != local_request_id)
            return;
        logger.printfln("unblocking with reset");
        client.abort();
        request_in_progress = false;
    }, 5000);
}

void ChargeManager::update_local_current(Config *target) {
    String error = api.callCommand("evse/managed_current_update", Config::ConfUpdateObject{{
        {"current", target->get("allocated_current")->asUint()}
    }});

    if (error != "") {
        logger.printfln("Failed to update local current: %s", error.c_str());
    }
}

void ChargeManager::send_current() {
    if(request_in_progress)
        return;

    auto &chargers = charge_manager_config_in_use.get("chargers")->asArray();

    if (current_charger == chargers.size()) {
        this->update_local_current(&charge_manager_state.get("chargers")->asArray()[current_charger]);
        return;
    }

    auto *charger = &chargers[current_charger];
    Config *target = &charge_manager_state.get("chargers")->asArray()[current_charger];

    client.regOnClosed([this](){
        logger.printfln("Closed");
        request_in_progress = false;
    });
    client.regOnError([this](){
        logger.printfln("Error");
        request_in_progress = false;
    });
    client.regOnResponse([this, target](const HttpResponse& rsp){
        size_t to_read = 0;
        rsp.getPayload(to_read);
        logger.printfln("Response");
        request_in_progress = false;
        client.end();
    });

    ++request_id;
    uint32_t local_request_id = request_id;
    request_in_progress = true;

    String url = String("http://") + charger->get("host")->asString() + String(":") + String(charger->get("port")->asUint()) + String("/evse/managed_current_update");

    if(!client.begin(url)){
        client.end();
        request_in_progress = false;
        return;
    }

    client.addHeader("Content-Type", "application/json");

    buf = String("{\"current\": ") + String(target->get("allocated_current")->asUint()) + String("}");

    if(!client.PUT(buf)) {
        client.end();
        request_in_progress = false;
        return;
    }

    task_scheduler.scheduleOnce("unblock_cm_http_client", [this, local_request_id](){
        if(!request_in_progress || this->request_id != local_request_id)
            return;
        logger.printfln("unblocking with reset");
        client.abort();
        request_in_progress = false;
    }, 5000);
}


void ChargeManager::setup()
{
    api.restorePersistentConfig("charge_manager/config", &charge_manager_config);
    api.addState("charge_manager/state", &charge_manager_state, {}, 1000);

    charge_manager_config_in_use = charge_manager_config;

    if(!charge_manager_config_in_use.get("enable_charge_manager")->asBool()) {
        return;
    }

    for(int i = 0; i < charge_manager_config_in_use.get("chargers")->asArray().size() + 1; ++i) {
        charge_manager_state.get("chargers")->add();
    }

    task_scheduler.scheduleWithFixedDelay("trigger_evse_state_update", [this](){
        static bool flip_flop = true;
        if (flip_flop)
            this->start_evse_state_update();
        else
            this->send_current();
        flip_flop = !flip_flop;
    }, 1000, 1000);

    task_scheduler.scheduleWithFixedDelay("distribute current", [this](){this->distribute_current();}, 10000, 10000);
    initialized = true;
}

#define TIMEOUT_MS 32000

void ChargeManager::distribute_current() {
    uint32_t available_current = charge_manager_config_in_use.get("available_current")->asUint();

    auto &chargers = charge_manager_state.get("chargers")->asArray();
    // Handle unreachable EVSEs
    bool unreachable_evse_found = false;
    for (auto &charger : chargers) {
        // Charger does not respond anymore
        if(deadline_elapsed(charger.get("last_update")->asUint() + TIMEOUT_MS)) {
            unreachable_evse_found = true;
            logger.printfln("unreachable EVSE: last_update too old.");
            break;
        }

        // Charger did not update the charging current in time
        if(charger.get("allocated_current")->asUint() < charger.get("allowed_current")->asUint() && deadline_elapsed(charger.get("last_sent_config")->asUint() + TIMEOUT_MS)) {
            unreachable_evse_found = true;
            logger.printfln("unreachable EVSE: allocated_current too old.");
            break;
        }
    }

    if (unreachable_evse_found) {
        // Shut down everything.
        available_current = 0;
        logger.printfln("unreachable EVSE(s) found. setting allowed current to 0.");
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

    logger.printfln("%d chargers request current", chargers_requesting_current);

    // Allocate current

    // Stage 1: Limit boxes already charging.
    uint16_t current_per_charger = chargers_requesting_current == 0 ? 0 : MAX(6000, available_current / chargers_requesting_current);
    logger.printfln("current_per_charger: %u", current_per_charger);
    bool skip_stage_2 = false;
    for (auto &charger : chargers) {
        if (!charger.get("is_charging")->asBool()) {
            continue;
        }
        if(available_current < current_per_charger) {
            // We don't have enough current left. This happens for example if we have 16A available and 3 boxes want to charge.
            // The minimal charge current is 6A, so with only 4A left for the third box, it may not start charging.
            // Assign 0 to current_per_charger here, so that we always can allocate current_per_charger to the following chargers.
            logger.printfln("not enough current left (%d)", available_current);
            available_current = 0;
            current_per_charger = 0;
        }

        available_current -= current_per_charger;
        if(current_per_charger < charger.get("allocated_current")->asUint() || current_per_charger < charger.get("allowed_current")->asUint()) {
            // Skip stage 2 to wait for the charger to adapt to the now smaller limit.
            // Some cars are slow to adapt to a new limit.
            // TODO: Check if skipping one round i.e. 10 seconds is enough.
            logger.printfln("skipping stage 2", available_current);
            skip_stage_2 = true;
        }
        logger.printfln("allocated %d mA to charger.", current_per_charger);
        if(charger.get("allocated_current")->updateUint(current_per_charger))
            charger.get("last_sent_config")->updateUint(millis());
    }

    // Stage 2: Allow boxes to charge if any current is left.
    // This will allocate 0 if no current is left.
    if (!skip_stage_2) {
        for (auto &charger : chargers) {
            if (charger.get("is_charging")->asBool() || !charger.get("wants_to_charge")->asBool()) {
                continue;
            }

            if(available_current < current_per_charger) {
                // See above
                logger.printfln("stage 2: not enough current left (%d)", available_current);
                available_current = 0;
                current_per_charger = 0;
            }
            logger.printfln("stage 2: allocated %d mA to charger.", current_per_charger);
            available_current -= current_per_charger;
            if(charger.get("allocated_current")->updateUint(current_per_charger))
                charger.get("last_sent_config")->updateUint(millis());
        }
    }

    // Stage 3: Block any box that does not charge right now and does not want to charge.
    // This should be unnecessary, as the boxes automatically set their limit to 0 if
    // they are done charging. Better safe than sorry
    for (auto &charger : chargers) {
        if (charger.get("is_charging")->asBool() || charger.get("wants_to_charge")->asBool()) {
            continue;
        }
        if(charger.get("allocated_current")->updateUint(0))
            charger.get("last_sent_config")->updateUint(millis());
    }
}

void ChargeManager::register_urls()
{
    api.addPersistentConfig("charge_manager/config", &charge_manager_config, {}, 1000);
    api.addState("charge_manager/state", &charge_manager_state, {}, 1000);
}

void ChargeManager::loop()
{

}
