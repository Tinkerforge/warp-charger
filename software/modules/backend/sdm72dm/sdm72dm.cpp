#include "sdm72dm.h"

#include "bindings/errors.h"

#include "tools.h"

#include "ArduinoJson.h"
#include "AsyncJson.h"

extern TF_HalContext hal;
extern AsyncWebServer server;
extern AsyncEventSource events;

SDM72DM::SDM72DM() {
    state = Config::Object({
        {"power", Config::Object({
                {"total", Config::Float(0.0)},
                {"import", Config::Float(0.0)},
                {"export", Config::Float(0.0)}
            })
        },
        {"energy_rel", Config::Object({
                {"total", Config::Float(0.0)},
                {"import", Config::Float(0.0)},
                {"export", Config::Float(0.0)}
            })
        },
        {"energy_abs", Config::Object({
                {"total", Config::Float(0.0)},
                {"import", Config::Float(0.0)},
                {"export", Config::Float(0.0)}
            })
        },
    });
    user_data.expected_request_id = 0;
    user_data.value_to_write = nullptr;
    user_data.done = true;
}

void read_input_registers_handler(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, uint16_t input_registers_length, uint16_t input_registers_chunk_offset, uint16_t input_registers_chunk_data[29], void *user_data) {
    SDM72DM::UserData *ud = (SDM72DM::UserData *) user_data;

    if(request_id != ud->expected_request_id || ud->expected_request_id == 0) {
        tf_hal_printf("Unexpected request id %I8u, expected %I8u\n", request_id, ud->expected_request_id);
        ud->done = true;
        return;
    }

    if(exception_code != 0) {
        tf_hal_printf("Request %I8u: Exception code %I8d\n", request_id, exception_code);
        ud->done = true;
        return;
    }

    if(input_registers_length != 2) {
        tf_hal_printf("Request %I8u: Unexpected response length %I16u\n", request_id, input_registers_length);
        ud->done = true;
        return;
    }

    if(ud->value_to_write == nullptr) {
        tf_hal_printf("value to write was nullptr\n");
        ud->done = true;
        return;
    }

    union {
        float f;
        uint16_t regs[2];
    } value;

    value.regs[1] = input_registers_chunk_data[0];
    value.regs[0] = input_registers_chunk_data[1];

    ud->value_to_write->updateFloat(value.f);
    ud->done = true;
}

void write_multiple_registers_handler(struct TF_RS485 *device, uint8_t request_id, int8_t exception_code, void *user_data) {
    SDM72DM::UserData *ud = (SDM72DM::UserData *) user_data;

    if(request_id != ud->expected_request_id || ud->expected_request_id == 0) {
        tf_hal_printf("Unexpected request id %I8u, expected %I8u\n", request_id, ud->expected_request_id);
        ud->done = true;
        return;
    }

    if(exception_code != 0) {
        tf_hal_printf("Exception code %I8d", exception_code);
        ud->done = true;
        return;
    }

    ud->done = true;
}

void SDM72DM::setup() {
    for(int i = 0; i < power_history.size(); ++i) {
        //float f = 5000.0 * sin(PI/120.0 * i) + 5000.0;
        // Use negative values to mark that these are pre-filled.
        power_history.push(-1);
    }

    char uid[7] = {0};
    if (!find_uid_by_did(&hal, TF_RS485_DEVICE_IDENTIFIER, uid)) {
        tf_hal_printf("No RS485 bricklet found. Disabling power meter\n");
        return;
    }

    if(tf_rs485_create(&rs485, uid, &hal) != TF_E_OK){
        initialized = false;
        return;
    }

    tf_rs485_set_mode(&rs485, TF_RS485_MODE_MODBUS_MASTER_RTU);
    tf_rs485_set_rs485_configuration(&rs485, 9600, TF_RS485_PARITY_NONE, TF_RS485_STOPBITS_1, TF_RS485_WORDLENGTH_8, TF_RS485_DUPLEX_HALF);
    tf_rs485_set_modbus_configuration(&rs485, 1, 1000);

    tf_rs485_register_modbus_master_read_input_registers_response_low_level_callback(&rs485, read_input_registers_handler, &user_data);
    tf_rs485_register_modbus_master_write_multiple_registers_response_callback(&rs485, write_multiple_registers_handler, &user_data);
    initialized = true;
}

void SDM72DM::register_urls() {
    server.on("/meter_state", HTTP_GET, [this](AsyncWebServerRequest *request) {
        if(!initialized) {
            request->send(400, "text/html", "not initialized");
            return;
        }

        auto *response = request->beginResponseStream("application/json; charset=utf-8");
        state.write_to_stream(*response);
        request->send(response);
    });

    server.on("/power_history", HTTP_GET, [this](AsyncWebServerRequest *request) {
        if(!initialized) {
            request->send(400, "text/html", "not initialized");
            return;
        }

        auto *response = request->beginResponseStream("application/json; charset=utf-8");

        int32_t val;
        power_history.peek(&val);
        // Negative values are prefilled, because the ESP was booted less than 48 hours ago.
        if(val < 0)
            response->print("[null");
        else
            response->printf("[%d", (int)val);

        for(int i = 1; i < power_history.used() && power_history.peek_offset(&val, i); ++i) {
            // Negative values are prefilled, because the ESP was booted less than 48 hours ago.
            if(val < 0)
                response->print(", null");
            else
                response->printf(",%d", (int)val);
        }
        response->printf("]");
        request->send(response);
    });

    server.on("/power_live", HTTP_GET, [this](AsyncWebServerRequest *request) {
        if(!initialized) {
            request->send(400, "text/html", "not initialized");
            return;
        }

        auto *response = request->beginResponseStream("application/json; charset=utf-8");

        int32_t val;
        interval_samples.peek(&val);
        float samples_per_second = 0;
        if(this->samples_per_interval > 0) {
            samples_per_second = ((float)this->samples_per_interval) / (60 * HISTORY_MINUTE_INTERVAL);
        } else {
            samples_per_second = (float)this->samples_last_interval / millis() * 1000;
        }
        response->printf("{\"samples_per_second\": %f, \"samples\":[%d", samples_per_second, val);

        for(int i = 1; (i < interval_samples.used() - 1) && interval_samples.peek_offset(&val, i); ++i) {
            response->printf(",%d", val);
        }
        response->printf("]}");
        request->send(response);
    });

    server.on("/energy_meter_reset", HTTP_ANY, [this](AsyncWebServerRequest *request) {
        if(!initialized) {
            request->send(400, "text/html", "not initialized");
            return;
        }
        energy_meter_reset_requested = true;
        request->send(200, "text/html", "reset initiated");
    });
}

void SDM72DM::onEventConnect(AsyncEventSourceClient *client)
{
    client->send(state.to_string().c_str(), "meter_state", millis(), 1000);
}

void SDM72DM::loop()
{
    if(!initialized)
        return;

    if(!user_data.done && !deadline_elapsed(callback_deadline_ms))
        return;

    if(!user_data.done) {
        printf("rs485 deadline reached!\n");
    }


    if(energy_meter_reset_requested) {
        energy_meter_reset_requested = false;

        user_data.done = false;
        user_data.value_to_write = nullptr;

        uint16_t payload = 0x0003;
        tf_rs485_modbus_master_write_multiple_registers(&rs485, 1, 61457, &payload, 1, &user_data.expected_request_id);
        return;
    }

    Config *to_write = nullptr;
    uint32_t start_address = 0;

    switch(modbus_read_state) {
        case 0:
            to_write = state.get("power")->get("total");
            start_address = 53;
            break;
        case 1:
            to_write = state.get("power")->get("import");
            start_address = 1281;
            break;
        case 2:
            to_write = state.get("power")->get("export");
            start_address = 1283;
            break;

        case 3:
            to_write = state.get("energy_rel")->get("total");
            start_address = 385;
            break;
        case 4:
            to_write = state.get("energy_rel")->get("import");
            start_address = 389;
            break;
        case 5:
            to_write = state.get("energy_rel")->get("export");
            start_address = 391;
            break;

        case 6:
            to_write = state.get("energy_abs")->get("total");
            start_address = 343;
            break;
        case 7:
            to_write = state.get("energy_abs")->get("import");
            start_address = 73;
            break;
        case 8:
            to_write = state.get("energy_abs")->get("export");
            start_address = 75;

        default:
            break;
    }

    user_data.value_to_write = to_write;
    user_data.done = false;
    int rc = tf_rs485_modbus_master_read_input_registers(&rs485, 1, start_address, 2, &user_data.expected_request_id);
    if(rc != TF_E_OK || user_data.expected_request_id == 0) {
        printf("Failed to read energy meter registers starting at %u: rc %d, request_id: %u\n", start_address, rc, user_data.expected_request_id);
    }

    if(modbus_read_state < 8)
        ++modbus_read_state;
    else {
        modbus_read_state = 0;

        if(send_event_allowed(&events)) {
            events.send(state.to_string().c_str(), "meter_state", millis());
        }

        interval_samples.push(state.get("power")->get("import")->asFloat());
        ++samples_last_interval;

        if(deadline_elapsed(interval_end_ms)) {
            float interval_sum = 0;
            int32_t val;
            for(int i = 0; i < samples_last_interval; ++i) {
                interval_samples.peek_offset(&val, interval_samples.used() - 1 - i);
                interval_sum += val;
            }

            power_history.push((int32_t)(interval_sum / samples_last_interval));
            samples_per_interval = samples_last_interval;
            samples_last_interval = 0;
            interval_end_ms = millis() + 1000 * 60 * HISTORY_MINUTE_INTERVAL;
        }
    }

    // This protects against lost callback responses.
    // If the callback packet is lost,
    // user_data.done would never be set to true.
    callback_deadline_ms = millis() + 3000;
}
