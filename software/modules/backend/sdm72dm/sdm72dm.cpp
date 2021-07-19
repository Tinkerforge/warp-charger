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

#include "sdm72dm.h"

#include "bindings/errors.h"

#include "api.h"
#include "event_log.h"
#include "tools.h"
#include "task_scheduler.h"
#include "web_server.h"

extern EventLog logger;

extern TF_HalContext hal;
extern WebServer server;
extern TaskScheduler task_scheduler;

extern API api;

SDM72DM::SDM72DM() {
    state = Config::Object({
        {"power", Config::Float(0.0)},
        {"energy_rel", Config::Float(0.0)},
        {"energy_abs", Config::Float(0.0)},
    });

    error_counters = Config::Object({
        {"meter", Config::Uint32(0)},
        {"bricklet", Config::Uint32(0)},
        {"bricklet_reset", Config::Uint32(0)},
    });

    energy_meter_reset = Config::Null();

    user_data.expected_request_id = 0;
    user_data.value_to_write = nullptr;
    user_data.done = SDM72DM::UserDataDone::DONE;
}

void read_input_registers_handler(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, uint16_t input_registers_length, uint16_t input_registers_chunk_offset, uint16_t input_registers_chunk_data[29], void *user_data) {
    SDM72DM::UserData *ud = (SDM72DM::UserData *) user_data;

    if(request_id != ud->expected_request_id || ud->expected_request_id == 0) {
        logger.printfln("Unexpected request id %u, expected %u", request_id, ud->expected_request_id);
        ud->done = SDM72DM::UserDataDone::ERROR;
        return;
    }

    if(exception_code != 0) {
        logger.printfln("Request %u: Exception code %d", request_id, exception_code);
        ud->done = SDM72DM::UserDataDone::ERROR;
        return;
    }

    if(input_registers_length != 2) {
        logger.printfln("Request %u: Unexpected response length %I16u", request_id, input_registers_length);
        ud->done = SDM72DM::UserDataDone::ERROR;
        return;
    }

    if(ud->value_to_write == nullptr) {
        logger.printfln("value to write was nullptr");
        ud->done = SDM72DM::UserDataDone::ERROR;
        return;
    }

    union {
        float f;
        uint16_t regs[2];
    } value;

    value.regs[1] = input_registers_chunk_data[0];
    value.regs[0] = input_registers_chunk_data[1];

    ud->value_to_write->updateFloat(value.f);
    ud->done = SDM72DM::UserDataDone::DONE;
}

void write_multiple_registers_handler(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, void *user_data) {
    SDM72DM::UserData *ud = (SDM72DM::UserData *) user_data;

    if(request_id != ud->expected_request_id || ud->expected_request_id == 0) {
        logger.printfln("Unexpected request id %u, expected %u", request_id, ud->expected_request_id);
        ud->done = SDM72DM::UserDataDone::ERROR;
        return;
    }

    if(exception_code != 0) {
        logger.printfln("Exception code %d", exception_code);
        ud->done = SDM72DM::UserDataDone::ERROR;
        return;
    }

    ud->done = SDM72DM::UserDataDone::DONE;
}

bool SDM72DM::setupRS485() {
    int rc = TF_E_OK;
    rc = tf_rs485_create(&rs485, uid, &hal);
    if(rc != TF_E_OK)
        return false;

    rc = tf_rs485_set_mode(&rs485, TF_RS485_MODE_MODBUS_MASTER_RTU);
    if(rc != TF_E_OK)
        return false;

    rc = tf_rs485_set_rs485_configuration(&rs485, 9600, TF_RS485_PARITY_NONE, TF_RS485_STOPBITS_1, TF_RS485_WORDLENGTH_8, TF_RS485_DUPLEX_HALF);
    if(rc != TF_E_OK)
        return false;

    rc = tf_rs485_set_modbus_configuration(&rs485, 1, 1000);
    if(rc != TF_E_OK)
        return false;

    tf_rs485_register_modbus_master_read_input_registers_response_low_level_callback(&rs485, read_input_registers_handler, &user_data);
    tf_rs485_register_modbus_master_write_multiple_registers_response_callback(&rs485, write_multiple_registers_handler, &user_data);
    return true;
}

void SDM72DM::checkRS485State() {
    uint8_t mode = 0;
    int rc = tf_rs485_get_mode(&rs485, &mode);
    if(rc != TF_E_OK) {
        logger.printfln("Failed to get RS485 mode, rc: %d", rc);
        error_counters.get("bricklet")->updateUint(error_counters.get("bricklet")->asUint() + 1);
        return;
    }
    if (mode != TF_RS485_MODE_MODBUS_MASTER_RTU) {
        logger.printfln("RS485 mode invalid. Did the bricklet reset?");
        error_counters.get("bricklet_reset")->updateUint(error_counters.get("bricklet_reset")->asUint() + 1);
        setupRS485();
    }
}

void SDM72DM::setup() {
    for(int i = 0; i < power_history.size(); ++i) {
        //float f = 5000.0 * sin(PI/120.0 * i) + 5000.0;
        // Use negative values to mark that these are pre-filled.
        power_history.push(-1);
    }

    if (!find_uid_by_did(&hal, TF_RS485_DEVICE_IDENTIFIER, uid)) {
        logger.printfln("No RS485 bricklet found. Disabling power meter\n");
        initialized = false;
        hardware_available = false;
        return;
    }
    hardware_available = true;

    initialized = setupRS485();

    task_scheduler.scheduleWithFixedDelay("check_rs485_config", [this](){
        this->checkRS485State();
    }, 5 * 60 * 1000, 5 * 60 * 1000);
}

void SDM72DM::register_urls() {
    if (!hardware_available)
        return;

    api.addState("meter/state", &state, {}, 1000);
    api.addState("meter/error_counters", &error_counters, {}, 1000);

    api.addCommand("meter/reset", &energy_meter_reset, {}, [this](){
        this->energy_meter_reset_requested = true;
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

void SDM72DM::loop()
{
    if(!initialized)
        return;

    if(user_data.done == UserDataDone::NOT_DONE && !deadline_elapsed(callback_deadline_ms))
        return;

    if(user_data.done == UserDataDone::NOT_DONE) {
        logger.printfln("rs485 deadline reached!");
        this->checkRS485State();
    }

    if(user_data.done != UserDataDone::NOT_DONE && !deadline_elapsed(next_read_deadline_ms))
        return;

    if(energy_meter_reset_requested) {
        energy_meter_reset_requested = false;

        user_data.done = UserDataDone::NOT_DONE;
        user_data.value_to_write = nullptr;

        uint16_t payload = 0x0003;
        tf_rs485_modbus_master_write_multiple_registers(&rs485, 1, 61457, &payload, 1, &user_data.expected_request_id);
        if (user_data.expected_request_id == 0) {
            this->checkRS485State();
        }
        return;
    }

    Config *to_write = nullptr;
    uint32_t start_address = 0;

    switch(modbus_read_state) {
        case 0:
            to_write = state.get("power");
            start_address = 1281;
            break;
        case 1:
            to_write = state.get("energy_rel");
            start_address = 389;
            break;
        case 2:
            to_write = state.get("energy_abs");
            start_address = 73;
            break;
        /*case 0:
            to_write = state.get("power_total");
            start_address = 53;
            break;
        case 1:
            to_write = state.get("power_import");
            start_address = 1281;
            break;
        case 2:
            to_write = state.get("power_export");
            start_address = 1283;
            break;

        case 3:
            to_write = state.get("energy_rel_total");
            start_address = 385;
            break;
        case 4:
            to_write = state.get("energy_rel_import");
            start_address = 389;
            break;
        case 5:
            to_write = state.get("energy_rel_export");
            start_address = 391;
            break;

        case 6:
            to_write = state.get("energy_abs_total");
            start_address = 343;
            break;
        case 7:
            to_write = state.get("energy_abs_import");
            start_address = 73;
            break;
        case 8:
            to_write = state.get("energy_abs_export");
            start_address = 75;
        */
        default:
            break;
    }

    auto last_user_data_done = user_data.done;

    user_data.value_to_write = to_write;
    user_data.done = UserDataDone::NOT_DONE;
    int rc = tf_rs485_modbus_master_read_input_registers(&rs485, 1, start_address, 2, &user_data.expected_request_id);
    if(rc != TF_E_OK || user_data.expected_request_id == 0) {
        logger.printfln("Failed to read energy meter registers starting at %u: rc %d, request_id: %u", start_address, rc, user_data.expected_request_id);
        this->checkRS485State();
    }

    if(modbus_read_state < 2)
        ++modbus_read_state;
    else {
        modbus_read_state = 0;
        next_read_deadline_ms = next_read_deadline_ms + 500;

        if (last_user_data_done == UserDataDone::DONE) {
            int16_t val = (int16_t)min((float)INT16_MAX, state.get("power")->asFloat());
            interval_samples.push(val);
            ++samples_last_interval;
        } else if (last_user_data_done == UserDataDone::ERROR) {
            error_counters.get("meter")->updateUint(error_counters.get("meter")->asUint() + 1);
        } else {
            error_counters.get("bricklet")->updateUint(error_counters.get("bricklet")->asUint() + 1);
        }

        if(deadline_elapsed(interval_end_ms)) {
            float interval_sum = 0;
            int16_t val;
            for(int i = 0; i < samples_last_interval; ++i) {
                interval_samples.peek_offset(&val, interval_samples.used() - 1 - i);
                interval_sum += val;
            }

            power_history.push((int16_t)(interval_sum / samples_last_interval));
            samples_per_interval = samples_last_interval;
            samples_last_interval = 0;
            interval_end_ms = millis() + 1000 * 60 * HISTORY_MINUTE_INTERVAL;
        }
    }

    // This protects against lost callback responses.
    // If the callback packet is lost,
    // user_data.done would never be set to ::DONE.
    callback_deadline_ms = millis() + 3000;
}
