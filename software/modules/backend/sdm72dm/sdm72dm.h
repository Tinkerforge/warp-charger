#pragma once

#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"

#include "bindings/bricklet_rs485.h"

#include "config.h"
#include "ringbuffer.h"

// How many hours to keep the coarse history for
#define HISTORY_HOURS 48
// How many minutes to keep the fine history for.
// This also controls the coarseness of the coarse history.
// For example 4 means that we accumulate 4 minutes of samples
// with the maximum rate i.e. ~ 3 samples per second (Querying the state
// takes about 380 ms).
// When we have 4 minutes worth of samples, we take the average
// and add it to the coarse history.
#define HISTORY_MINUTE_INTERVAL 4

class SDM72DM {
public:
    SDM72DM();
    void setup();
    void register_urls();
    void loop();

    enum class UserDataDone {
        NOT_DONE,
        DONE,
        ERROR
    };

    struct UserData {
        Config *value_to_write;
        uint8_t expected_request_id;
        UserDataDone done;
    };

    bool initialized = false;

private:
    void modbus_read();

    Config config;
    Config state;
    Config energy_meter_reset;
    Config error_counters;

    TF_RS485 rs485;
    int modbus_read_state = 0;
    int samples_last_interval = 0;
    int samples_per_interval = -1;
    uint32_t interval_end_ms = 1000 * 60 * HISTORY_MINUTE_INTERVAL;
    TF_Ringbuffer<int32_t, 3 * 60 * HISTORY_MINUTE_INTERVAL> interval_samples;

    uint32_t next_modbus_read_deadline = 0;
    uint32_t next_power_history_entry = 0;
    UserData user_data;
    TF_Ringbuffer<int32_t, HISTORY_HOURS * (60 / HISTORY_MINUTE_INTERVAL) + 1> power_history;

    bool energy_meter_reset_requested;

    uint32_t callback_deadline_ms = 0;
    uint32_t next_read_deadline_ms = 0;
};
