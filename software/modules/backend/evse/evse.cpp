#include "evse.h"

#include "bindings/errors.h"

#include "tools.h"

#include "modules/task_scheduler/task_scheduler.h"

extern TaskScheduler task_scheduler;
extern TF_HalContext hal;
extern AsyncWebServer server;
extern AsyncEventSource events;

EVSE::EVSE()
{
    evse_state = Config::Object({
        {"iec61851_state", Config::Uint8(0)},
        {"vehicle_state", Config::Uint8(0)},
        {"contactor_state", Config::Uint8(0)},
        {"contactor_error", Config::Uint8(0)},
        {"allowed_charging_current", Config::Uint16(0)},
        {"lock_state", Config::Uint8(0)},
        {"time_since_state_change", Config::Uint32(0)},
        {"uptime", Config::Uint32(0)}
    });

    evse_hardware_configuration = Config::Object({
        {"jumper_configuration", Config::Uint8(0)},
        {"has_lock_switch", Config::Bool(false)}
    });

    evse_low_level_state = Config::Object ({
        {"low_level_mode_enabled", Config::Bool(false)},
        {"led_state", Config::Uint8(0)},
        {"cp_pwm_duty_cycle", Config::Uint16(0)},
        {"adc_values", Config::Array({
                Config::Uint16(0),
                Config::Uint16(0),
            }, Config::Uint16(0), 2, 2, Config::type_id<Config::ConfUint>())
        },
        {"voltages", Config::Array({
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
            }, Config::Int16(0), 3, 3, Config::type_id<Config::ConfInt>())
        },
        {"resistances", Config::Array({
                Config::Uint32(0),
                Config::Uint32(0),
            }, Config::Uint32(0), 2, 2, Config::type_id<Config::ConfUint>())
        },
        {"gpio", Config::Array({Config::Bool(false),Config::Bool(false),Config::Bool(false),Config::Bool(false), Config::Bool(false)}, Config::Bool(false), 5, 5, Config::type_id<Config::ConfBool>())}
    });

    evse_max_charging_current = Config::Object ({
        {"max_current_configured", Config::Uint16(0)},
        {"max_current_incoming_cable", Config::Uint16(0)},
        {"max_current_outgoing_cable", Config::Uint16(0)},
    });

    evse_auto_start_charging = Config::Object({
        {"auto_start_charging", Config::Bool(true)}
    });
}

void EVSE::setup()
{
    setup_evse();
    task_scheduler.scheduleWithFixedDelay("update_evse_state", [this](){
        update_evse_state();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_low_level_state", [this](){
        update_evse_low_level_state();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_max_charging_current", [this](){
        update_evse_max_charging_current();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_auto_start_charging", [this](){
        update_evse_auto_start_charging();
    }, 0, 1000);
}

void EVSE::register_urls()
{
    server.on("/evse_charging_state", HTTP_GET, [this](AsyncWebServerRequest *request) {
        auto *response = request->beginResponseStream("application/json; charset=utf-8");
        evse_charging_state.write_to_stream(*response);
        request->send(response);
    });

    server.on("/evse_state", HTTP_GET, [this](AsyncWebServerRequest *request) {
        auto *response = request->beginResponseStream("application/json; charset=utf-8");
        evse_state.write_to_stream(*response);
        request->send(response);
    });

    server.on("/evse_hardware_configuration", HTTP_GET, [this](AsyncWebServerRequest *request) {
        auto *response = request->beginResponseStream("application/json; charset=utf-8");
        evse_hardware_configuration.write_to_stream(*response);
        request->send(response);
    });

    server.on("/evse_low_level_state", HTTP_GET, [this](AsyncWebServerRequest *request) {
        auto *response = request->beginResponseStream("application/json; charset=utf-8");
        evse_low_level_state.write_to_stream(*response);
        request->send(response);
    });

    server.on("/evse_max_charging_current", HTTP_GET, [this](AsyncWebServerRequest *request) {
        auto *response = request->beginResponseStream("application/json; charset=utf-8");
        evse_max_charging_current.write_to_stream(*response);
        request->send(response);
    });

    server.on("/evse_auto_start_charging", HTTP_GET, [this](AsyncWebServerRequest *request) {
        auto *response = request->beginResponseStream("application/json; charset=utf-8");
        evse_auto_start_charging.write_to_stream(*response);
        request->send(response);
    });

    AsyncCallbackJsonWebHandler *evse_auto_start_charging_handler = new AsyncCallbackJsonWebHandler("/evse_auto_start_charging", [this](AsyncWebServerRequest *request, JsonVariant &json){
        if(!json["auto_start_charging"].is<bool>()) {
            request->send(400, "text/html", "expected a boolean");
            return;
        }

        bool new_auto_start = json["auto_start_charging"].as<bool>();

        task_scheduler.scheduleOnce("change_charging_current", [this, new_auto_start](){
            int rc = tf_evse_set_charging_autostart(&evse, new_auto_start);
            Serial.printf("rc: %d\n", rc);
            check_bootloader_state(rc);
        }, 0);

        request->send(200, "text/html", "Updating auto start");
    });

    server.addHandler(evse_auto_start_charging_handler);

    server.on("/evse_stop_charging", HTTP_GET, [this](AsyncWebServerRequest *request) {
        task_scheduler.scheduleOnce("stop_charging", [this](){
            tf_evse_stop_charging(&evse);
        }, 0);
        request->send(200, "text/html", String("Stopping charging"));
    });

    server.on("/evse_start_charging", HTTP_GET, [this](AsyncWebServerRequest *request) {
        task_scheduler.scheduleOnce("start_charging", [this](){
            tf_evse_start_charging(&evse);
        }, 0);
        request->send(200, "text/html", String("Startping charging"));
    });

    AsyncCallbackJsonWebHandler *evse_current_limit_handler = new AsyncCallbackJsonWebHandler("/evse_current_limit", [this](AsyncWebServerRequest *request, JsonVariant &json){
        if(!json["current"].is<uint16_t>()) {
            request->send(400, "text/html", "expected an unsigned integer between 6000 and 32000");
            return;
        }

        uint16_t new_current = json["current"].as<uint16_t>();
        if(new_current < 6000 || new_current > 32000) {
            request->send(400, "text/html", "value was not between 6000 and 32000");
            return;
        }

        task_scheduler.scheduleOnce("change_charging_current", [this, new_current](){
            check_bootloader_state(tf_evse_set_max_charging_current(&evse, new_current));
        }, 0);

        request->send(200, "text/html", String("Limiting current") + String(new_current));
    });

    server.addHandler(evse_current_limit_handler);

    task_scheduler.scheduleWithFixedDelay("sse_evse_state", [this](){
        if(!send_event_allowed(&events))
            return;

        events.send(evse_state.to_string().c_str(), "evse_state", millis());
    }, 10000, 10000);
}

void EVSE::onEventConnect(AsyncEventSourceClient *client)
{
    client->send(evse_hardware_configuration.to_string().c_str(), "evse_hardware_configuration", millis(), 1000);
    client->send(evse_state.to_string().c_str(), "evse_state", millis(), 1000);
    client->send(evse_low_level_state.to_string().c_str(), "evse_low_level_state", millis(), 1000);
    client->send(evse_max_charging_current.to_string().c_str(), "evse_max_charging_current", millis(), 1000);
    client->send(evse_auto_start_charging.to_string().c_str(), "evse_auto_start_charging", millis(), 1000);
}

void EVSE::loop()
{
    static uint32_t last_check = 0;
    if(evse_found && !initialized && deadline_elapsed(last_check + 10000)) {
        last_check = millis();
        if(!is_in_bootloader(TF_E_TIMEOUT))
            setup_evse();
    }
}

void EVSE::setup_evse()
{
    char uid[7] = {0};
    if (!find_uid_by_did(&hal, TF_EVSE_DEVICE_IDENTIFIER, uid)) {
        Serial.println("No EVSE bricklet found. Disabling EVSE support.");
        return;
    }
    evse_found = true;

    auto result = tf_evse_create(&evse, uid, &hal);
    if(result != TF_E_OK) {
        Serial.printf("EVSE init failed (rc %d). Disabling EVSE support.\n", result);
        return;
    }

    uint8_t jumper_configuration;
    bool has_lock_switch;

    result = tf_evse_get_hardware_configuration(&evse, &jumper_configuration, &has_lock_switch);

    if (result != TF_E_OK) {
        if(!is_in_bootloader(result)) {
            Serial.printf("EVSE hardware config query failed (rc %d). Disabling EVSE support.\n", result);
        }
        return;
    } else {
        evse_hardware_configuration.get("jumper_configuration")->updateUint(jumper_configuration);
        evse_hardware_configuration.get("has_lock_switch")->updateBool(has_lock_switch);
    }

    initialized = true;
}

void EVSE::update_evse_low_level_state() {
    if(!initialized)
        return;
    bool low_level_mode_enabled;
    uint8_t led_state;
    uint16_t cp_pwm_duty_cycle;

    uint16_t adc_values[2];
    int16_t voltages[3];
    uint32_t resistances[2];
    bool gpio[5];

    int rc = tf_evse_get_low_level_state(&evse,
        &low_level_mode_enabled,
        &led_state,
        &cp_pwm_duty_cycle,
        adc_values,
        voltages,
        resistances,
        gpio);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_low_level_state.get("low_level_mode_enabled")->updateBool(low_level_mode_enabled);
    evse_low_level_state.get("led_state")->updateUint(led_state);
    evse_low_level_state.get("cp_pwm_duty_cycle")->updateUint(cp_pwm_duty_cycle);

    for(int i = 0; i < sizeof(adc_values)/sizeof(adc_values[0]); ++i)
        evse_low_level_state.get("adc_values")->get(i)->updateUint(adc_values[i]);

    for(int i = 0; i < sizeof(voltages)/sizeof(voltages[0]); ++i)
        evse_low_level_state.get("voltages")->get(i)->updateInt(voltages[i]);

    for(int i = 0; i < sizeof(resistances)/sizeof(resistances[0]); ++i)
        evse_low_level_state.get("resistances")->get(i)->updateUint(resistances[i]);

    for(int i = 0; i < sizeof(gpio)/sizeof(gpio[0]); ++i)
        evse_low_level_state.get("gpio")->get(i)->updateBool(gpio[i]);

    if(!send_event_allowed(&events))
        return;

    events.send(evse_low_level_state.to_string().c_str(), "evse_low_level_state", millis());
}

void EVSE::update_evse_state() {
    if(!initialized)
        return;
    uint8_t iec61851_state, vehicle_state, contactor_state, contactor_error, lock_state;
    uint16_t allowed_charging_current;
    uint32_t time_since_state_change, uptime;

    int rc = tf_evse_get_state(&evse,
        &iec61851_state,
        &vehicle_state,
        &contactor_state,
        &contactor_error,
        &allowed_charging_current,
        &lock_state,
        &time_since_state_change,
        &uptime);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_state.get("iec61851_state")->updateUint(iec61851_state);
    evse_state.get("vehicle_state")->updateUint(vehicle_state);
    evse_state.get("contactor_state")->updateUint(contactor_state);
    evse_state.get("contactor_error")->updateUint(contactor_error);
    evse_state.get("allowed_charging_current")->updateUint(allowed_charging_current);
    evse_state.get("lock_state")->updateUint(lock_state);
    evse_state.get("time_since_state_change")->updateUint(time_since_state_change);
    evse_state.get("uptime")->updateUint(uptime);

    if(iec61851_state == EVSE_CHARGING_STATE_CHARGING) {
        digitalWrite(GREEN_LED, LOW);
    }
    else {
        digitalWrite(GREEN_LED, HIGH);
    }

    if(!send_event_allowed(&events))
        return;

    events.send(evse_state.to_string().c_str(), "evse_state", millis());
}

void EVSE::update_evse_max_charging_current() {
    if(!initialized)
        return;
    uint16_t configured, incoming, outgoing;

    int rc = tf_evse_get_max_charging_current(&evse,
        &configured,
        &incoming,
        &outgoing);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_max_charging_current.get("max_current_configured")->updateUint(configured);
    evse_max_charging_current.get("max_current_incoming_cable")->updateUint(incoming);
    evse_max_charging_current.get("max_current_outgoing_cable")->updateUint(outgoing);

    if(!send_event_allowed(&events))
        return;

    events.send(evse_max_charging_current.to_string().c_str(), "evse_max_charging_current", millis());
}

void EVSE::update_evse_auto_start_charging() {
    if(!initialized)
        return;
    bool auto_start_charging;

    int rc = tf_evse_get_charging_autostart(&evse,
        &auto_start_charging);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_auto_start_charging.get("auto_start_charging")->updateBool(auto_start_charging);

    if(!send_event_allowed(&events))
        return;

    events.send(evse_auto_start_charging.to_string().c_str(), "evse_auto_start_charging", millis());
}

bool EVSE::is_in_bootloader(int rc) {
    if(rc != TF_E_TIMEOUT && rc != TF_E_NOT_SUPPORTED)
        return false;

    uint8_t mode;
    int bootloader_rc = tf_evse_get_bootloader_mode(&evse, &mode);
    if(bootloader_rc != TF_E_OK) {
        return false;
    }

    if(mode != TF_EVSE_BOOTLOADER_MODE_FIRMWARE) {
        initialized = false;
    }

    return mode != TF_EVSE_BOOTLOADER_MODE_FIRMWARE;
}
