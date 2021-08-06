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

#include "evse_v2.h"
#include "evse_v2_firmware.h"

#include "bindings/errors.h"

#include "api.h"
#include "event_log.h"
#include "task_scheduler.h"
#include "tools.h"
#include "web_server.h"
#include "modules.h"

extern EventLog logger;

extern TaskScheduler task_scheduler;
extern TF_HalContext hal;
extern WebServer server;

extern API api;
extern bool firmware_update_allowed;

EVSEV2::EVSEV2()
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
        {"led_state", Config::Uint8(0)},
        {"cp_pwm_duty_cycle", Config::Uint16(0)},
        {"adc_values", Config::Array({
                Config::Uint16(0),
                Config::Uint16(0),
                Config::Uint16(0),
                Config::Uint16(0),
                Config::Uint16(0),
            }, Config::Uint16(0), 5, 5, Config::type_id<Config::ConfUint>())
        },
        {"voltages", Config::Array({
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
            }, Config::Int16(0), 5, 5, Config::type_id<Config::ConfInt>())
        },
        {"resistances", Config::Array({
                Config::Uint32(0),
                Config::Uint32(0),
            }, Config::Uint32(0), 2, 2, Config::type_id<Config::ConfUint>())
        },
        {"gpio", Config::Array({
            Config::Bool(false), Config::Bool(false),  Config::Bool(false),Config::Bool(false),
            Config::Bool(false), Config::Bool(false),  Config::Bool(false),Config::Bool(false),
            Config::Bool(false), Config::Bool(false),  Config::Bool(false),Config::Bool(false),
            Config::Bool(false), Config::Bool(false),  Config::Bool(false),Config::Bool(false),
            Config::Bool(false), Config::Bool(false),  Config::Bool(false),Config::Bool(false),
            Config::Bool(false), Config::Bool(false),  Config::Bool(false),Config::Bool(false),
            }, Config::Bool(false), 24, 24, Config::type_id<Config::ConfBool>())}
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

    evse_energy_meter_values = Config::Object({
        {"power", Config::Float(0)},
        {"energy_rel", Config::Float(0)},
        {"energy_abs", Config::Float(0)},
         {"phases_active", Config::Array({Config::Bool(false),Config::Bool(false),Config::Bool(false)},
            Config::Bool(false),
            3, 3, Config::type_id<Config::ConfBool>())}
    });

    evse_energy_meter_state = Config::Object({
        {"available", Config::Bool(false)},
        {"error_count", Config::Array({
                Config::Uint32(0),
                Config::Uint32(0),
                Config::Uint32(0),
                Config::Uint32(0),
                Config::Uint32(0),
                Config::Uint32(0),
            }, Config::Uint32(0), 6, 6, Config::type_id<Config::ConfUint>())}
    });

    evse_dc_fault_current_state = Config::Object({
        {"state", Config::Uint8(0)}
    });

    evse_reset_dc_fault_current = Config::Object({
        {"password", Config::Uint32(0)} //0xDC42FA23
    });

    evse_gpio_configuration = Config::Object({
        {"enable_input", Config::Uint8(0)},
        {"input", Config::Uint8(0)},
        {"output", Config::Uint8(0)}
    });


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
}

void EVSEV2::setup()
{
    setup_evse();
    if(!evse_found)
        return;

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

    task_scheduler.scheduleWithFixedDelay("update_evse_energy_meter_values", [this](){
        update_evse_energy_meter_values();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_energy_meter_state", [this](){
        update_evse_energy_meter_state();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_dc_fault_current_state", [this](){
        update_evse_dc_fault_current_state();
    }, 0, 1000);

    task_scheduler.scheduleWithFixedDelay("update_evse_gpio_configuration", [this](){
        update_evse_gpio_configuration();
    }, 0, 1000);


    task_scheduler.scheduleWithFixedDelay("update_evse_managed", [this](){
        update_evse_managed();
    }, 0, 1000);

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
            evse_state.get("allowed_charging_current")->asUint()
        );
    }, 1000, 1000);

    task_scheduler.scheduleWithFixedDelay("evse_managed_current_watchdog", [this]() {
        if (!deadline_elapsed(this->last_current_update + 30000))
            return;
        if (!evse_managed.get("managed")->asBool()) {
            // Push back the next check for 30 seconds: If managed gets enabled,
            // we want to wait 30 seconds before setting the current for the first time.
            this->last_current_update = millis();
            return;
        }
        if(!this->shutdown_logged)
            logger.printfln("Got no managed current update for more than 30 seconds. Setting managed current to 0");
        this->shutdown_logged = true;
        is_in_bootloader(tf_evse_v2_set_managed_current(&evse, 0));
    }, 1000, 1000);
#endif
}

String EVSEV2::get_evse_debug_header() {
    return "millis,iec61851_state,vehicle_state,contactor_state,contactor_error,charge_release,allowed_charging_current,error_state,lock_state,time_since_state_change,uptime,led_state,cp_pwm_duty_cycle,adc_values_0,adc_values_1,adc_values_2,adc_values_3,adc_values_4,voltages_0,voltages_1,voltages_2,voltages_3,voltages_4,resistances_0,resistances_1,gpio_0,gpio_1,gpio_2,gpio_3,gpio_4,gpio_5,gpio_6,gpio_7,gpio_8,gpio_9,gpio_10,gpio_11,gpio_12,gpio_13,gpio_14,gpio_15,gpio_16,gpio_17,gpio_18,gpio_19,gpio_20,gpio_21,gpio_22,gpio_23\n";
}

String EVSEV2::get_evse_debug_line() {
    if(!initialized)
        return "EVSE is not initialized!";

    uint8_t iec61851_state, vehicle_state, contactor_state, contactor_error, charge_release, error_state, lock_state;
    uint16_t allowed_charging_current;
    uint32_t time_since_state_change, uptime;

    int rc = tf_evse_v2_get_state(&evse,
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

    uint8_t led_state;
    uint16_t cp_pwm_duty_cycle;

    uint16_t adc_values[5];
    int16_t voltages[5];
    uint32_t resistances[2];
    bool gpio[24];

    rc = tf_evse_v2_get_low_level_state(&evse,
        &led_state,
        &cp_pwm_duty_cycle,
        adc_values,
        voltages,
        resistances,
        gpio);

    if(rc != TF_E_OK) {
        return String("evse_get_low_level_state failed: rc: ") + String(rc);
    }

    char line[230] = {0};
    snprintf(line, sizeof(line)/sizeof(line[0]), "%lu,%u,%u,%u,%u,%u,%u,%u,%u,%lu,%lu,%u,%u,%u,%u,%u,%u,%u,%d,%d,%d,%d,%d,%u,%u,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c\n",
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
        led_state,
        cp_pwm_duty_cycle,
        adc_values[0],adc_values[1],adc_values[2],adc_values[3],adc_values[4],
        voltages[0],voltages[1],voltages[2],voltages[3],voltages[4],
        resistances[0],resistances[1],
        gpio[0] ? '1' : '0',gpio[1] ? '1' : '0',gpio[2] ? '1' : '0',gpio[3] ? '1' : '0',
        gpio[4] ? '1' : '0',gpio[5] ? '1' : '0',gpio[6] ? '1' : '0',gpio[7] ? '1' : '0',
        gpio[8] ? '1' : '0',gpio[9] ? '1' : '0',gpio[10] ? '1' : '0',gpio[11] ? '1' : '0',
        gpio[12] ? '1' : '0',gpio[13] ? '1' : '0',gpio[14] ? '1' : '0',gpio[15] ? '1' : '0',
        gpio[16] ? '1' : '0',gpio[17] ? '1' : '0',gpio[18] ? '1' : '0',gpio[19] ? '1' : '0',
        gpio[20] ? '1' : '0',gpio[21] ? '1' : '0',gpio[22] ? '1' : '0',gpio[23] ? '1' : '0'
        );

    return String(line);
}


String EVSEV2::get_evse_monitor_header() {
    return "millis,"
            "state,iec,vehicle,contactor,_error,charge_release,allowed_current,error,lock,t_state_change,uptime,"
            "low_level_state,led,cp_pwm,adc_0,adc_1,adc_2,adc_3,adc_4,voltage_0,voltage_1,voltage_2,voltage_3,voltage_4,resistances_0,resistances_1,"
            "hardware_cfg,jumper,has_lock_switch,"
            "max_charging_current,configured,incoming,outgoing,"
            "auto_start, auto_start,"
            "energy_meter_values,power,energy_rel,energy_abs,"
            "dc_fault_current_state,dc_fault,"
            "gpio_cfg, enable_input_cfg, input_cfg, output_cfg,"
            "gpios,gpio_0,gpio_1,gpio_2,gpio_3,gpio_4,gpio_5,gpio_6,gpio_7,gpio_8,gpio_9,gpio_10,gpio_11,gpio_12,gpio_13,gpio_14,gpio_15,gpio_16,gpio_17,gpio_18,gpio_19,gpio_20,gpio_21,gpio_22,gpio_23\n";
}

String EVSEV2::get_evse_monitor_line() {
    if(!initialized)
        return "EVSE is not initialized!";

    uint8_t iec61851_state, vehicle_state, contactor_state, contactor_error, charge_release, error_state, lock_state;
    uint16_t allowed_charging_current;
    uint32_t time_since_state_change, uptime;

    uint8_t led_state;
    uint16_t cp_pwm_duty_cycle;

    uint16_t adc_values[5];
    int16_t voltages[5];
    uint32_t resistances[2];
    bool gpio[24];

    uint8_t jumper_configuration;
    bool has_lock_switch;

    uint16_t configured, incoming, outgoing, managed;

    bool auto_start_charging;

    uint32_t power, energy_rel, energy_abs;

    uint8_t dc_fault_current_state;

    uint8_t input, output;

    char line[300] = {0};
    snprintf(line, sizeof(line)/sizeof(line[0]), "%lu,,%u,%u,%u,%u,%u,%u,%u,%u,%lu,%lu,,%u,%u,%u,%u,%u,%u,%u,%d,%d,%d,%d,%d,%u,%u,,%u,%c,,%u,%u,%u,%u,,%c,,%lu,%lu,%lu,,%u,,%u,%u,,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,\n",
        millis(),

        evse_state.get("iec61851_state")->asUint(),
        evse_state.get("vehicle_state")->asUint(),
        evse_state.get("contactor_state")->asUint(),
        evse_state.get("contactor_error")->asUint(),
        evse_state.get("charge_release")->asUint(),
        evse_state.get("allowed_charging_current")->asUint(),
        evse_state.get("error_state")->asUint(),
        evse_state.get("lock_state")->asUint(),
        evse_state.get("time_since_state_change")->asUint(),
        evse_state.get("uptime")->asUint(),

        evse_low_level_state.get("led_state")->asUint(),
        evse_low_level_state.get("cp_pwm_duty_cycle")->asUint(),
        evse_low_level_state.get("adc_values")->get(0)->asUint(),
        evse_low_level_state.get("adc_values")->get(1)->asUint(),
        evse_low_level_state.get("adc_values")->get(2)->asUint(),
        evse_low_level_state.get("adc_values")->get(3)->asUint(),
        evse_low_level_state.get("adc_values")->get(4)->asUint(),
        evse_low_level_state.get("voltages")->get(0)->asInt(),
        evse_low_level_state.get("voltages")->get(1)->asInt(),
        evse_low_level_state.get("voltages")->get(2)->asInt(),
        evse_low_level_state.get("voltages")->get(3)->asInt(),
        evse_low_level_state.get("voltages")->get(4)->asInt(),
        evse_low_level_state.get("resistances")->get(0)->asUint(),
        evse_low_level_state.get("resistances")->get(1)->asUint(),

        evse_hardware_configuration.get("jumper_configuration")->asUint(),
        evse_hardware_configuration.get("has_lock_switch")->asBool() ? '1' : '0',

        evse_max_charging_current.get("max_current_configured")->asUint(),
        evse_max_charging_current.get("max_current_incoming_cable")->asUint(),
        evse_max_charging_current.get("max_current_outgoing_cable")->asUint(),
        evse_max_charging_current.get("max_current_managed")->asUint(),

        evse_auto_start_charging.get("auto_start_charging")->asBool() ? '1': '0',

        evse_energy_meter_values.get("power")->asUint(),
        evse_energy_meter_values.get("energy_rel")->asUint(),
        evse_energy_meter_values.get("energy_abs")->asUint(),

        evse_dc_fault_current_state.get("state")->asUint(),

        evse_gpio_configuration.get("enable_input")->asUint(),
        evse_gpio_configuration.get("input")->asUint(),
        evse_gpio_configuration.get("output")->asUint(),

        evse_low_level_state.get("gpio")->get(0) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(1) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(2) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(3) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(4) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(5) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(6) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(7) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(8) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(9) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(10) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(11) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(12) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(13) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(14) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(15) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(16) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(17) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(18) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(19) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(20) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(21) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(22) ? '1' : '0',
        evse_low_level_state.get("gpio")->get(23) ? '1' : '0'
        );

    return String(line);
}


void EVSEV2::set_managed_current(uint16_t current) {
    is_in_bootloader(tf_evse_v2_set_managed_current(&evse, current));
    this->last_current_update = millis();
    this->shutdown_logged = false;
}

void EVSEV2::register_urls()
{
    if (!evse_found)
        return;

    api.addState("evse/state", &evse_state, {}, 1000);
    api.addState("evse/hardware_configuration", &evse_hardware_configuration, {}, 1000);
    api.addState("evse/low_level_state", &evse_low_level_state, {}, 1000);
    api.addState("evse/max_charging_current", &evse_max_charging_current, {}, 1000);
    api.addState("evse/auto_start_charging", &evse_auto_start_charging, {}, 1000);
    api.addState("evse/energy_meter_values", &evse_energy_meter_values, {}, 1000);
    api.addState("evse/energy_meter_state", &evse_energy_meter_state, {}, 1000);
    api.addState("evse/dc_fault_current_state", &evse_dc_fault_current_state, {}, 1000);

    api.addCommand("evse/reset_dc_fault_current", &evse_reset_dc_fault_current, {}, [this](){
        is_in_bootloader(tf_evse_v2_reset_dc_fault_current(&evse, evse_reset_dc_fault_current.get("password")->asUint()));
    }, true);

    api.addState("evse/gpio_configuration", &evse_gpio_configuration, {}, 1000);
    api.addCommand("evse/gpio_configuration_update", &evse_gpio_configuration, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_gpio_configuration(&evse, evse_gpio_configuration.get("enable_input")->asUint(),
                                                                  evse_gpio_configuration.get("input")->asUint(),
                                                                  evse_gpio_configuration.get("output")->asUint()));
    }, true);

    api.addCommand("evse/auto_start_charging_update", &evse_auto_start_charging_update, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_charging_autostart(&evse, evse_auto_start_charging_update.get("auto_start_charging")->asBool()));
    }, false);

    api.addCommand("evse/current_limit", &evse_current_limit, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_max_charging_current(&evse, evse_current_limit.get("current")->asUint()));
    }, false);

    api.addCommand("evse/stop_charging", &evse_stop_charging, {}, [this](){tf_evse_v2_stop_charging(&evse);}, true);
    api.addCommand("evse/start_charging", &evse_start_charging, {}, [this](){tf_evse_v2_start_charging(&evse);}, true);

    api.addCommand("evse/managed_current_update", &evse_managed_current, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_managed_current(&evse, evse_managed_current.get("current")->asUint()));
    }, true);

    api.addState("evse/managed", &evse_managed, {}, 1000);
    api.addCommand("evse/managed_update", &evse_managed_update, {"password"}, [this](){
        is_in_bootloader(tf_evse_v2_set_managed(&evse, evse_managed_update.get("managed")->asBool(), evse_managed_update.get("password")->asUint()));
    }, true);

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

    server.on("/evse/monitor_header", HTTP_GET, [this](WebServerRequest request){
        request.send(200, "text/csv", this->get_evse_monitor_header().c_str());
    });

    server.on("/evse/monitor_line", HTTP_GET, [this](WebServerRequest request){
        request.send(200, "text/csv", this->get_evse_monitor_line().c_str());
    });
}

void EVSEV2::loop()
{
    static uint32_t last_check = 0;
    if(evse_found && !initialized && deadline_elapsed(last_check + 10000)) {
        last_check = millis();
        if(!is_in_bootloader(TF_E_TIMEOUT))
            setup_evse();
    }

#ifdef MODULE_WS_AVAILABLE
    static uint32_t last_debug = 0;
    if(debug && deadline_elapsed(last_debug + 50)) {
        last_debug = millis();
        ws.pushStateUpdate(this->get_evse_debug_line(), "evse/debug");
    }
#endif
}

void EVSEV2::setup_evse()
{
    char uid[7] = {0};
    if (!find_uid_by_did(&hal, TF_EVSE_V2_DEVICE_IDENTIFIER, uid)) {
        logger.printfln("No EVSE 2.0 bricklet found. Disabling EVSE 2.0 support.");
        return;
    }
    evse_found = true;

    int result = ensure_matching_firmware(&hal, uid, "EVSE 2.0", "EVSE 2.0", evse_v2_firmware_version, evse_v2_bricklet_firmware_bin, evse_v2_bricklet_firmware_bin_len, &logger);
    if(result != 0) {
        return;
    }

    result = tf_evse_v2_create(&evse, uid, &hal);
    if(result != TF_E_OK) {
        logger.printfln("Failed to initialize EVSE 2.0 bricklet. Disabling EVSE 2.0 support.");
        return;
    }

    uint8_t jumper_configuration;
    bool has_lock_switch;

    result = tf_evse_v2_get_hardware_configuration(&evse, &jumper_configuration, &has_lock_switch);

    if (result != TF_E_OK) {
        if(!is_in_bootloader(result)) {
            logger.printfln("EVSE 2.0 hardware config query failed (rc %d). Disabling EVSE 2.0 support.", result);
        }
        return;
    } else {
        evse_hardware_configuration.get("jumper_configuration")->updateUint(jumper_configuration);
        evse_hardware_configuration.get("has_lock_switch")->updateBool(has_lock_switch);
    }

    initialized = true;

    update_evse_energy_meter_state();
}

void EVSEV2::update_evse_low_level_state() {
    if(!initialized)
        return;

    uint8_t led_state;
    uint16_t cp_pwm_duty_cycle;

    uint16_t adc_values[5];
    int16_t voltages[5];
    uint32_t resistances[2];
    bool gpio[24];

    int rc = tf_evse_v2_get_low_level_state(&evse,
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
}

void EVSEV2::update_evse_state() {
    if(!initialized)
        return;
    uint8_t iec61851_state, vehicle_state, contactor_state, contactor_error, charge_release, error_state, lock_state;
    uint16_t allowed_charging_current;
    uint32_t time_since_state_change, uptime;

    int rc = tf_evse_v2_get_state(&evse,
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
        is_in_bootloader(rc);
        return;
    }

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
}

void EVSEV2::update_evse_max_charging_current() {
    if(!initialized)
        return;
    uint16_t configured, incoming, outgoing, managed;

    int rc = tf_evse_v2_get_max_charging_current(&evse,
        &configured,
        &incoming,
        &outgoing,
        &managed);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_max_charging_current.get("max_current_configured")->updateUint(configured);
    evse_max_charging_current.get("max_current_incoming_cable")->updateUint(incoming);
    evse_max_charging_current.get("max_current_outgoing_cable")->updateUint(outgoing);
    evse_max_charging_current.get("max_current_managed")->updateUint(managed);
}

void EVSEV2::update_evse_auto_start_charging() {
    if(!initialized)
        return;
    bool auto_start_charging;

    int rc = tf_evse_v2_get_charging_autostart(&evse,
        &auto_start_charging);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_auto_start_charging.get("auto_start_charging")->updateBool(auto_start_charging);
}

void EVSEV2::update_evse_managed() {
    if(!initialized)
        return;
    bool managed;

    int rc = tf_evse_v2_get_managed(&evse,
        &managed);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_managed.get("managed")->updateBool(managed);
}

void EVSEV2::update_evse_energy_meter_values() {
    if(!initialized)
        return;

    float power, energy_rel, energy_abs;
    bool phases_active[3];

    int rc = tf_evse_v2_get_energy_meter_values(&evse,
        &power,
        &energy_rel,
        &energy_abs,
        phases_active);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_energy_meter_values.get("power")->updateFloat(power);
    evse_energy_meter_values.get("energy_rel")->updateFloat(energy_rel);
    evse_energy_meter_values.get("energy_abs")->updateFloat(energy_abs);
    for(int i = 0; i < 3; ++i)
            evse_energy_meter_values.get("phases_active")->get(i)->updateBool(phases_active[i]);
}

void EVSEV2::update_evse_energy_meter_state() {
    if(!initialized)
        return;

    bool available;
    uint32_t error_count[6];

    int rc = tf_evse_v2_get_energy_meter_state(&evse,
        &available,
        error_count);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_energy_meter_state.get("available")->updateBool(available);
    for(int i = 0; i < sizeof(error_count)/sizeof(error_count[0]); ++i)
        evse_energy_meter_state.get("error_count")->get(i)->updateUint(error_count[i]);
}

void EVSEV2::update_evse_dc_fault_current_state() {
    if(!initialized)
        return;

    uint8_t state;

    int rc = tf_evse_v2_get_dc_fault_current_state(&evse,
        &state);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_dc_fault_current_state.get("state")->updateUint(state);
}

void EVSEV2::update_evse_gpio_configuration() {
    if(!initialized)
        return;

    uint8_t enable_input, input, output;

    int rc = tf_evse_v2_get_gpio_configuration(&evse,
        &enable_input,
        &input,
        &output);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    evse_gpio_configuration.get("enable_input")->updateUint(enable_input);
    evse_gpio_configuration.get("input")->updateUint(input);
    evse_gpio_configuration.get("output")->updateUint(output);
}

bool EVSEV2::is_in_bootloader(int rc) {
    if(rc != TF_E_TIMEOUT && rc != TF_E_NOT_SUPPORTED)
        return false;

    uint8_t mode;
    int bootloader_rc = tf_evse_v2_get_bootloader_mode(&evse, &mode);
    if(bootloader_rc != TF_E_OK) {
        return false;
    }

    if(mode != TF_EVSE_V2_BOOTLOADER_MODE_FIRMWARE) {
        initialized = false;
    }

    return mode != TF_EVSE_V2_BOOTLOADER_MODE_FIRMWARE;
}
