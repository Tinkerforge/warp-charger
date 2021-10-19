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

#include "evse.h"

#include "bindings/errors.h"

#include "api.h"
#include "event_log.h"
#include "task_scheduler.h"
#include "tools.h"
#include "web_server.h"
#include "modules.h"

#include <functional>

extern EventLog logger;

extern TaskScheduler task_scheduler;
extern TF_HalContext hal;
extern WebServer server;

extern API api;
extern bool firmware_update_allowed;

EVSE::EVSE() : DeviceModule("evse", "EVSE", "EVSE", std::bind(&EVSE::setup_evse, this))
{
    evse_state = Config::Object({
        {"iec61851_state", Config::Uint8(0)},
        {"vehicle_state", Config::Uint8(0)},
        {"contactor_state", Config::Uint8(0)},
        {"contactor_error", Config::Uint8(0)},
        {"charge_release", Config::Uint8(0)},
        {"allowed_charging_current", Config::Uint16(0)},
        {"error_state", Config::Uint8(0)},
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
        {"gpio", Config::Array({Config::Bool(false),Config::Bool(false),Config::Bool(false),Config::Bool(false), Config::Bool(false)}, Config::Bool(false), 5, 5, Config::type_id<Config::ConfBool>())},
        {"hardware_version", Config::Uint8(0)},
        {"charging_time", Config::Uint32(0)},
    });

    evse_max_charging_current = Config::Object ({
        {"max_current_configured", Config::Uint16(0)},
        {"max_current_incoming_cable", Config::Uint16(0)},
        {"max_current_outgoing_cable", Config::Uint16(0)},
        {"max_current_managed", Config::Uint16(0)},
    });

    evse_auto_start_charging = Config::Object({
        {"auto_start_charging", Config::Bool(true)}
    });

    evse_auto_start_charging_update = Config::Object({
        {"auto_start_charging", Config::Bool(true)}
    });
    evse_current_limit = Config::Object({
        {"current", Config::Uint(32000, 6000, 32000)}
    });

    evse_stop_charging = Config::Null();
    evse_start_charging = Config::Null();

    evse_managed_current = Config::Object ({
        {"current", Config::Uint16(0)}
    });

    evse_managed = Config::Object({
        {"managed", Config::Bool(false)}
    });

    evse_managed_update = Config::Object({
        {"managed", Config::Bool(false)},
        {"password", Config::Uint32(0)}
    });

    evse_user_calibration = Config::Object({
        {"user_calibration_active", Config::Bool(false)},
        {"voltage_diff", Config::Int16(0)},
        {"voltage_mul", Config::Int16(0)},
        {"voltage_div", Config::Int16(0)},
        {"resistance_2700", Config::Int16(0)},
        {"resistance_880", Config::Array({
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
            }, Config::Int16(0), 14, 14, Config::type_id<Config::ConfInt>())},
    });

    evse_button_state = Config::Object({
        {"button_press_time", Config::Uint32(0)},
        {"button_release_time", Config::Uint32(0)},
        {"button_pressed", Config::Bool(false)},
    });

    evse_reflash = Config::Null();
    evse_reset = Config::Null();
}

void EVSE::setup()
{
    setup_evse();
    if(!device_found)
        return;

    task_scheduler.scheduleWithFixedDelay("update_all_data", [this](){
        update_all_data();
    }, 0, 250);

#ifdef MODULE_CM_NETWORKING_AVAILABLE
    cm_networking.register_client([this](uint16_t current){
        set_managed_current(current);
    });

    task_scheduler.scheduleWithFixedDelay("evse_send_cm_networking_client", [this](){
        cm_networking.send_client_update(
            evse_state.get("iec61851_state")->asUint(),
            evse_state.get("vehicle_state")->asUint(),
            evse_state.get("error_state")->asUint(),
            evse_state.get("charge_release")->asUint(),
            evse_state.get("uptime")->asUint(),
            evse_low_level_state.get("charging_time")->asUint(),
            evse_state.get("allowed_charging_current")->asUint(),
            min(evse_max_charging_current.get("max_current_configured")->asUint(),
                min(evse_max_charging_current.get("max_current_incoming_cable")->asUint(),
                    evse_max_charging_current.get("max_current_outgoing_cable")->asUint())),
            evse_managed.get("managed")->asBool()
        );
    }, 1000, 1000);

    task_scheduler.scheduleWithFixedDelay("evse_managed_current_watchdog", [this]() {
        if (!deadline_elapsed(this->last_current_update + 30000))
            return;
        if(!this->shutdown_logged)
            logger.printfln("Got no managed current update for more than 30 seconds. Setting managed current to 0");
        this->shutdown_logged = true;
        is_in_bootloader(tf_evse_set_managed_current(&device, 0));
    }, 1000, 1000);
#endif
}

String EVSE::get_evse_debug_header() {
    return "\"millis,iec,vehicle,contactor,_error,charge_release,allowed_current,error,lock,t_state_change,uptime,low_level_mode_enabled,led,cp_pwm,adc_pe_cp,adc_pe_pp,voltage_pe_cp,voltage_pe_pp,voltage_pe_cp_max,resistance_pe_cp,resistance_pe_pp,gpio_in,gpio_out,gpio_motor_in,gpio_relay,gpio_motor_error,hardware_version,charging_time\"";
}

String EVSE::get_evse_debug_line() {
    if(!initialized)
        return "EVSE is not initialized!";

    uint8_t iec61851_state, vehicle_state, contactor_state, contactor_error, charge_release, error_state, lock_state;
    uint16_t allowed_charging_current;
    uint32_t time_since_state_change, uptime;

    int rc = tf_evse_get_state(&device,
        &iec61851_state,
        &vehicle_state,
        &contactor_state,
        &contactor_error,
        &charge_release,
        &allowed_charging_current,
        &error_state,
        &lock_state,
        &time_since_state_change,
        &uptime);

    if(rc != TF_E_OK) {
        return String("evse_get_state failed: rc: ") + String(rc);
    }

    bool low_level_mode_enabled;
    uint8_t led_state;
    uint16_t cp_pwm_duty_cycle;

    uint16_t adc_values[2];
    int16_t voltages[3];
    uint32_t resistances[2];
    bool gpio[5];
    uint8_t hardware_version;
    uint32_t charging_time;

    rc = tf_evse_get_low_level_state(&device,
        &low_level_mode_enabled,
        &led_state,
        &cp_pwm_duty_cycle,
        adc_values,
        voltages,
        resistances,
        gpio,
        &hardware_version,
        &charging_time);

    if(rc != TF_E_OK) {
        return String("evse_get_low_level_state failed: rc: ") + String(rc);
    }

    char line[150] = {0};
    snprintf(line, sizeof(line)/sizeof(line[0]), "[%lu,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%c,%u,%u,%u,%u,%d,%d,%d,%u,%u,%c,%c,%c,%c,%c,%u,%u]",
        millis(),
        iec61851_state,
        vehicle_state,
        contactor_state,
        contactor_error,
        charge_release,
        allowed_charging_current,
        error_state,
        lock_state,
        time_since_state_change,
        uptime,
        low_level_mode_enabled ? '1' : '0',
        led_state,
        cp_pwm_duty_cycle,
        adc_values[0],adc_values[1],
        voltages[0],voltages[1],voltages[2],
        resistances[0],resistances[1],
        gpio[0] ? '1' : '0',gpio[1] ? '1' : '0',gpio[2] ? '1' : '0',gpio[3] ? '1' : '0',gpio[4] ? '1' : '0',
        hardware_version,
        charging_time);

    return String(line);
}

void EVSE::set_managed_current(uint16_t current) {
    is_in_bootloader(tf_evse_set_managed_current(&device, current));
    this->last_current_update = millis();
    this->shutdown_logged = false;
}

void EVSE::register_urls()
{
    if (!device_found)
        return;

    api.addState("evse/state", &evse_state, {}, 1000);
    api.addState("evse/hardware_configuration", &evse_hardware_configuration, {}, 1000);
    api.addState("evse/low_level_state", &evse_low_level_state, {}, 1000);
    api.addState("evse/max_charging_current", &evse_max_charging_current, {}, 1000);
    api.addState("evse/auto_start_charging", &evse_auto_start_charging, {}, 1000);

    api.addCommand("evse/auto_start_charging_update", &evse_auto_start_charging_update, {}, [this](){
        is_in_bootloader(tf_evse_set_charging_autostart(&device, evse_auto_start_charging_update.get("auto_start_charging")->asBool()));
    }, false);

    api.addCommand("evse/current_limit", &evse_current_limit, {}, [this](){
        is_in_bootloader(tf_evse_set_max_charging_current(&device, evse_current_limit.get("current")->asUint()));
    }, false);

    api.addCommand("evse/stop_charging", &evse_stop_charging, {}, [this](){is_in_bootloader(tf_evse_stop_charging(&device));}, true);
    api.addCommand("evse/start_charging", &evse_start_charging, {}, [this](){is_in_bootloader(tf_evse_start_charging(&device));}, true);

    api.addCommand("evse/managed_current_update", &evse_managed_current, {}, [this](){
        this->set_managed_current(evse_managed_current.get("current")->asUint());
    }, true);

    api.addState("evse/managed", &evse_managed, {}, 1000);
    api.addCommand("evse/managed_update", &evse_managed_update, {"password"}, [this](){
        is_in_bootloader(tf_evse_set_managed(&device, evse_managed_update.get("managed")->asBool(), evse_managed_update.get("password")->asUint()));
    }, true);

    api.addState("evse/user_calibration", &evse_user_calibration, {}, 1000);
    api.addCommand("evse/user_calibration_update", &evse_user_calibration, {}, [this](){
        int16_t resistance_880[14];
        evse_user_calibration.get("resistance_880")->fillArray<int16_t, Config::ConfInt>(resistance_880, sizeof(resistance_880)/sizeof(resistance_880[0]));

        is_in_bootloader(tf_evse_set_user_calibration(&device,
            0xCA11B4A0,
            evse_user_calibration.get("user_calibration_active")->asBool(),
            evse_user_calibration.get("voltage_diff")->asInt(),
            evse_user_calibration.get("voltage_mul")->asInt(),
            evse_user_calibration.get("voltage_div")->asInt(),
            evse_user_calibration.get("resistance_2700")->asInt(),
            resistance_880
            ));
    }, true);

    api.addState("evse/button_state", &evse_button_state, {}, 250);

#ifdef MODULE_WS_AVAILABLE
    server.on("/evse/start_debug", HTTP_GET, [this](WebServerRequest request) {
        task_scheduler.scheduleOnce("enable evse debug", [this](){
            ws.pushStateUpdate(this->get_evse_debug_header(), "evse/debug_header");
            debug = true;
        }, 0);
        request.send(200);
    });

    server.on("/evse/stop_debug", HTTP_GET, [this](WebServerRequest request){
        task_scheduler.scheduleOnce("enable evse debug", [this](){
            debug = false;
        }, 0);
        request.send(200);
    });
#endif

    this->DeviceModule::register_urls();
}

void EVSE::loop()
{
    this->DeviceModule::loop();

#ifdef MODULE_WS_AVAILABLE
    static uint32_t last_debug = 0;
    if(debug && deadline_elapsed(last_debug + 50)) {
        last_debug = millis();
        ws.pushStateUpdate(this->get_evse_debug_line(), "evse/debug");
    }
#endif
}

void EVSE::setup_evse()
{
    if (!this->DeviceModule::setup_device())
        return;

    uint8_t jumper_configuration;
    bool has_lock_switch;

    int result = tf_evse_get_hardware_configuration(&device, &jumper_configuration, &has_lock_switch);

    if (result != TF_E_OK) {
        if(!is_in_bootloader(result)) {
            logger.printfln("EVSE hardware config query failed (rc %d). Disabling EVSE support.", result);
        }
        return;
    } else {
        evse_hardware_configuration.get("jumper_configuration")->updateUint(jumper_configuration);
        evse_hardware_configuration.get("has_lock_switch")->updateBool(has_lock_switch);
    }

    initialized = true;
}

void EVSE::update_all_data() {
    if (!initialized)
        return;

    // get_all_data_1
    uint8_t iec61851_state;
    uint8_t vehicle_state;
    uint8_t contactor_state;
    uint8_t contactor_error;
    uint8_t charge_release;
    uint16_t allowed_charging_current;
    uint8_t error_state;
    uint8_t lock_state;
    uint32_t time_since_state_change;
    uint32_t uptime;
    uint8_t jumper_configuration;
    bool has_lock_switch;
    bool low_level_mode_enabled;
    uint8_t led_state;
    uint16_t cp_pwm_duty_cycle;
    uint16_t adc_values[2];
    int16_t voltages[3];
    uint32_t resistances[2];
    bool gpio[5];
    uint8_t hardware_version;
    uint32_t charging_time;
    uint16_t max_current_configured;
    uint16_t max_current_incoming_cable;
    uint16_t max_current_outgoing_cable;
    uint16_t max_current_managed;
    bool autostart;
    bool managed;

    // get_all_data_2
    bool user_calibration_active;
    int16_t voltage_diff;
    int16_t voltage_mul;
    int16_t voltage_div;
    int16_t resistance_2700;
    int16_t resistance_880[14];
    int16_t indication;
    uint16_t duration;
    uint32_t button_press_time;
    uint32_t button_release_time;
    bool button_pressed;

    int rc = tf_evse_get_all_data_1(&device,
        &iec61851_state,
        &vehicle_state,
        &contactor_state,
        &contactor_error,
        &charge_release,
        &allowed_charging_current,
        &error_state,
        &lock_state,
        &time_since_state_change,
        &uptime,
        &jumper_configuration,
        &has_lock_switch,
        &low_level_mode_enabled,
        &led_state,
        &cp_pwm_duty_cycle,
        adc_values,
        voltages,
        resistances,
        gpio,
        &hardware_version,
        &charging_time,
        &max_current_configured,
        &max_current_incoming_cable,
        &max_current_outgoing_cable,
        &max_current_managed,
        &autostart,
        &managed);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    rc = tf_evse_get_all_data_2(&device,
        &user_calibration_active,
        &voltage_diff,
        &voltage_mul,
        &voltage_div,
        &resistance_2700,
        resistance_880,
        &indication,
        &duration,
        &button_press_time,
        &button_release_time,
        &button_pressed);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    // get_state
    firmware_update_allowed = vehicle_state == 0;

    evse_state.get("iec61851_state")->updateUint(iec61851_state);
    evse_state.get("vehicle_state")->updateUint(vehicle_state);
    evse_state.get("contactor_state")->updateUint(contactor_state);
    bool contactor_error_changed = evse_state.get("contactor_error")->updateUint(contactor_error);
    evse_state.get("charge_release")->updateUint(charge_release);
    evse_state.get("allowed_charging_current")->updateUint(allowed_charging_current);
    bool error_state_changed = evse_state.get("error_state")->updateUint(error_state);
    evse_state.get("lock_state")->updateUint(lock_state);
    evse_state.get("time_since_state_change")->updateUint(time_since_state_change);
    evse_state.get("uptime")->updateUint(uptime);

    if (contactor_error_changed) {
        if (contactor_error != 0) {
            logger.printfln("EVSE: Contactor error %d", contactor_error);
        } else {
            logger.printfln("EVSE: Contactor error cleared");
        }
    }

    if (error_state_changed) {
        if (error_state != 0) {
            logger.printfln("EVSE: Error state %d", error_state);
        } else {
            logger.printfln("EVSE: Error state cleared");
        }
    }

    // get_low_level_state
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

    evse_low_level_state.get("hardware_version")->updateUint(hardware_version);
    evse_low_level_state.get("charging_time")->updateUint(charging_time);

    // get_max_charging_current
    evse_max_charging_current.get("max_current_configured")->updateUint(max_current_configured);
    evse_max_charging_current.get("max_current_incoming_cable")->updateUint(max_current_incoming_cable);
    evse_max_charging_current.get("max_current_outgoing_cable")->updateUint(max_current_outgoing_cable);
    evse_max_charging_current.get("max_current_managed")->updateUint(max_current_managed);

    // get_charging_autostart
    evse_auto_start_charging.get("auto_start_charging")->updateBool(autostart);

    // get_managed
    evse_managed.get("managed")->updateBool(managed);

    // get_user_calibration
    evse_user_calibration.get("user_calibration_active")->updateBool(user_calibration_active);
    evse_user_calibration.get("voltage_diff")->updateInt(voltage_diff);
    evse_user_calibration.get("voltage_mul")->updateInt(voltage_mul);
    evse_user_calibration.get("voltage_div")->updateInt(voltage_div);
    evse_user_calibration.get("resistance_2700")->updateInt(resistance_2700);

    for(int i = 0; i < sizeof(resistance_880)/sizeof(resistance_880[0]); ++i)
        evse_user_calibration.get("resistance_880")->get(i)->updateInt(resistance_880[i]);

    // get_button_state
    evse_button_state.get("button_press_time")->updateUint(button_press_time);
    evse_button_state.get("button_release_time")->updateUint(button_release_time);
    evse_button_state.get("button_pressed")->updateBool(button_pressed);
}
