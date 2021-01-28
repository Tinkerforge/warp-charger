#pragma once

#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"
#include "config.h"

#include "bindings/bricklet_evse.h"

#define EVSE_CHARGING_STATE_NOT_CONNECTED 0
#define EVSE_CHARGING_STATE_CONNECTED 1
#define EVSE_CHARGING_STATE_CHARGING 2
#define EVSE_CHARGING_STATE_ERROR 3

class EVSE {
public:
    EVSE();
    void setup();
    void register_urls();
    void onEventConnect(AsyncEventSourceClient *client);
    void loop();

    bool evse_found = false;
    bool initialized = false;

private:
    void setup_evse();
    void update_evse_state();
    void update_evse_low_level_state();
    void update_evse_max_charging_current();
    void update_evse_auto_start_charging();
    bool is_in_bootloader(int rc);
    bool flash_firmware();
    bool flash_plugin(int regular_plugin_upto);
    bool wait_for_bootloader_mode(int mode);

    Config evse_state;
    Config evse_hardware_configuration;
    Config evse_low_level_state;
    Config evse_max_charging_current;
    Config evse_auto_start_charging;
    Config evse_auto_start_charging_update;
    Config evse_current_limit;
    Config evse_stop_charging;
    Config evse_start_charging;

    TF_EVSE evse;
};
