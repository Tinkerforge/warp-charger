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

#include "evse_v2_meter.h"

#include "bindings/errors.h"

#include "api.h"
#include "event_log.h"
#include "tools.h"
#include "task_scheduler.h"
#include "web_server.h"
#include "modules.h"

extern EventLog logger;

extern TF_HalContext hal;
extern WebServer server;
extern TaskScheduler task_scheduler;
extern Config modules;

extern API api;

#define DETAILED_VALUES_COUNT 85

EVSEV2Meter::EVSEV2Meter() {
    state = Config::Object({
        {"power", Config::Float(0.0)},
        {"energy_rel", Config::Float(0.0)},
        {"energy_abs", Config::Float(0.0)},
        {"phases_active", Config::Array({Config::Bool(false),Config::Bool(false),Config::Bool(false)},
            Config::Bool(false),
            3, 3, Config::type_id<Config::ConfBool>())},
        {"phases_connected", Config::Array({Config::Bool(false),Config::Bool(false),Config::Bool(false)},
            Config::Bool(false),
            3, 3, Config::type_id<Config::ConfBool>())}
    });

    detailed_values = Config::Array({},
        Config::Float(0),
        0, DETAILED_VALUES_COUNT, Config::type_id<Config::ConfFloat>());
/*
    error_counters = Config::Object({
        {"meter", Config::Uint32(0)},
        {"bricklet", Config::Uint32(0)},
        {"bricklet_reset", Config::Uint32(0)},
    });
*/
    energy_meter_reset = Config::Null();
}

void EVSEV2Meter::setupEVSE(bool update_module_initialized) {
    evse_v2.update_all_data();

    if(!evse_v2.evse_energy_meter_state.get("available")->asBool()) {
        task_scheduler.scheduleOnce("setup_evsev2_meter", [this](){
            this->setupEVSE(true);
        }, 3000);
        return;
    }

    hardware_available = true;

    for(int i = 0; i < power_history.size(); ++i) {
        //float f = 5000.0 * sin(PI/120.0 * i) + 5000.0;
        // Use negative state to mark that these are pre-filled.
        power_history.push(-1);
    }

    for(int i = 0; i < DETAILED_VALUES_COUNT; ++i) {
        detailed_values.add();
    }

    task_scheduler.scheduleWithFixedDelay("update_evse_meter_values", [this](){
        float power, energy_rel, energy_abs;
        bool phases_active[3], phases_connected[3];
        if (tf_evse_v2_get_energy_meter_values(&evse_v2.device, &power, &energy_rel, &energy_abs, phases_active, phases_connected) != TF_E_OK)
            return;

        state.get("power")->updateFloat(power);
        state.get("energy_rel")->updateFloat(energy_rel);
        state.get("energy_abs")->updateFloat(energy_abs);

        for(int i = 0; i < 3; ++i)
            state.get("phases_active")->get(i)->updateBool(phases_active[i]);

        for(int i = 0; i < 3; ++i)
            state.get("phases_connected")->get(i)->updateBool(phases_connected[i]);

        int16_t val = (int16_t)min((float)INT16_MAX, power);
        interval_samples.push(val);
        ++samples_last_interval;
    }, 500, 500);

    task_scheduler.scheduleWithFixedDelay("update_evse_meter_history", [this](){
        float interval_sum = 0;
        int16_t val;
        for(int i = 0; i < samples_last_interval; ++i) {
            interval_samples.peek_offset(&val, interval_samples.used() - 1 - i);
            interval_sum += val;
        }

        power_history.push((int16_t)(interval_sum / samples_last_interval));
        samples_per_interval = samples_last_interval;
        samples_last_interval = 0;
    }, 1000 * 60 * HISTORY_MINUTE_INTERVAL, 1000 * 60 * HISTORY_MINUTE_INTERVAL);

    task_scheduler.scheduleWithFixedDelay("update_evse_meter_detailed_values", [this](){
        uint16_t len;
        float result[DETAILED_VALUES_COUNT] = {0};
        if (tf_evse_v2_get_energy_meter_detailed_values(&evse_v2.device, result, &len) != TF_E_OK)
            return;

        for(int i = 0; i < DETAILED_VALUES_COUNT; ++i) {
            detailed_values.get(i)->updateFloat(result[i]);
        }
    }, 1000, 1000);

    initialized = true;

    if(update_module_initialized)
        modules.get("evse_v2_meter")->updateBool(true);
}

void EVSEV2Meter::setup() {
    initialized = false;
    hardware_available = false;

    if (!evse_v2.initialized) {
        // If the EVSE is not initialized, we will never be able to reach the energy meter.
        return;
    }

    setupEVSE(false);
}

void EVSEV2Meter::register_urls() {
    api.addState("meter/state", &state, {}, 1000);
    api.addState("meter/detailed_values", &detailed_values, {}, 1000);
    //api.addState("meter/error_counters", &error_counters, {}, 1000); TODO: use api.getstate

    api.addCommand("meter/reset", &energy_meter_reset, {}, [this](){
        if(!initialized) {
            return;
        }

        tf_evse_v2_reset_energy_meter(&evse_v2.device);
    }, true);

    server.on("/meter/history", HTTP_GET, [this](WebServerRequest request) {
        if(!initialized) {
            request.send(400, "text/html", "not initialized");
            return;
        }

        const size_t buf_size = RING_BUF_SIZE * 6 + 100;
        char buf[buf_size] = {0};
        size_t buf_written = 0;

        int16_t val;
        power_history.peek(&val);
        // Negative values are prefilled, because the ESP was booted less than 48 hours ago.
        if(val < 0)
            buf_written += snprintf(buf + buf_written, buf_size - buf_written, "%s", "[null");
        else
            buf_written += snprintf(buf + buf_written, buf_size - buf_written, "[%d", (int)val);

        for(int i = 1; i < power_history.used() && power_history.peek_offset(&val, i) && buf_written < buf_size; ++i) {
            // Negative values are prefilled, because the ESP was booted less than 48 hours ago.
            if(val < 0)
                buf_written += snprintf(buf + buf_written, buf_size - buf_written, "%s", ",null");
            else
                buf_written += snprintf(buf + buf_written, buf_size - buf_written, ",%d", (int)val);
        }

        if (buf_written < buf_size)
            buf_written += snprintf(buf + buf_written, buf_size - buf_written, "%c", ']');

        request.send(200, "application/json; charset=utf-8", buf, buf_written);
    });

    server.on("/meter/live", HTTP_GET, [this](WebServerRequest request) {
        if(!initialized) {
            request.send(400, "text/html", "not initialized");
            return;
        }

        const size_t buf_size = RING_BUF_SIZE * 6 + 100;
        char buf[buf_size] = {0};
        size_t buf_written = 0;

        int16_t val;
        interval_samples.peek(&val);
        float samples_per_second = 0;
        if(this->samples_per_interval > 0) {
            samples_per_second = ((float)this->samples_per_interval) / (60 * HISTORY_MINUTE_INTERVAL);
        } else {
            samples_per_second = (float)this->samples_last_interval / millis() * 1000;
        }
        buf_written += snprintf(buf + buf_written, buf_size - buf_written, "{\"samples_per_second\":%f,\"samples\":[%d", samples_per_second, val);

        for(int i = 1; (i < interval_samples.used() - 1) && interval_samples.peek_offset(&val, i) && buf_written < buf_size; ++i) {
            buf_written += snprintf(buf + buf_written, buf_size - buf_written, ",%d", val);
        }
        if (buf_written < buf_size)
            buf_written += snprintf(buf + buf_written, buf_size - buf_written, "%s", "]}");
        request.send(200, "application/json; charset=utf-8", buf, buf_written);
    });
}

void EVSEV2Meter::loop()
{

}
