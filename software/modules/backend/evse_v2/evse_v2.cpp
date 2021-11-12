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

EVSEV2::EVSEV2() : DeviceModule("evse", "EVSE 2.0", "EVSE 2.0", std::bind(&EVSEV2::setup_evse, this))
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
                Config::Uint16(0),
                Config::Uint16(0),
            }, Config::Uint16(0), 7, 7, Config::type_id<Config::ConfUint>())
        },
        {"voltages", Config::Array({
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
                Config::Int16(0),
            }, Config::Int16(0), 7, 7, Config::type_id<Config::ConfInt>())
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
            }, Config::Bool(false), 24, 24, Config::type_id<Config::ConfBool>())},
        {"charging_time", Config::Uint32(0)}
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
            3, 3, Config::type_id<Config::ConfBool>())},
        {"phases_connected", Config::Array({Config::Bool(false),Config::Bool(false),Config::Bool(false)},
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
        {"shutdown_input", Config::Uint8(0)},
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

    evse_button_configuration = Config::Object({
        {"button", Config::Uint8(2)}
    });

    evse_button_configuration_update = Config::Object({
        {"button", Config::Uint8(2)}
    });

    evse_button_state = Config::Object({
        {"button_press_time", Config::Uint32(0)},
        {"button_release_time", Config::Uint32(0)},
        {"button_pressed", Config::Bool(false)},
    });

    evse_control_pilot_configuration = Config::Object({
        {"control_pilot", Config::Uint8(0)}
    });

    evse_control_pilot_configuration_update = Config::Object({
        {"control_pilot", Config::Uint8(0)}
    });
}

void EVSEV2::setup()
{
    setup_evse();
    if(!device_found)
        return;

    task_scheduler.scheduleWithFixedDelay("update_all_data", [this](){
        update_all_data();
    }, 0, 250);
}

String EVSEV2::get_evse_debug_header() {
    return "millis,iec61851_state,vehicle_state,contactor_state,contactor_error,charge_release,allowed_charging_current,error_state,lock_state,time_since_state_change,uptime,led_state,cp_pwm_duty_cycle,adc_values_0,adc_values_1,adc_values_2,adc_values_3,adc_values_4,,adc_values_5,adc_values_6,voltages_0,voltages_1,voltages_2,voltages_3,voltages_4,voltages_5,voltages_6,resistances_0,resistances_1,gpio_0,gpio_1,gpio_2,gpio_3,gpio_4,gpio_5,gpio_6,gpio_7,gpio_8,gpio_9,gpio_10,gpio_11,gpio_12,gpio_13,gpio_14,gpio_15,gpio_16,gpio_17,gpio_18,gpio_19,gpio_20,gpio_21,gpio_22,gpio_23,charging_time\n";
}

String EVSEV2::get_evse_debug_line() {
    if(!initialized)
        return "EVSE is not initialized!";

    uint8_t iec61851_state, vehicle_state, contactor_state, contactor_error, charge_release, error_state, lock_state;
    uint16_t allowed_charging_current;
    uint32_t time_since_state_change, uptime;

    int rc = tf_evse_v2_get_state(&device,
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

    uint16_t adc_values[7];
    int16_t voltages[7];
    uint32_t resistances[2];
    bool gpio[24];
    uint32_t charging_time;

    rc = tf_evse_v2_get_low_level_state(&device,
        &led_state,
        &cp_pwm_duty_cycle,
        adc_values,
        voltages,
        resistances,
        gpio,
        &charging_time);

    if(rc != TF_E_OK) {
        return String("evse_get_low_level_state failed: rc: ") + String(rc);
    }

    char line[230] = {0};
    snprintf(line, sizeof(line)/sizeof(line[0]), "%lu,%u,%u,%u,%u,%u,%u,%u,%u,%lu,%lu,%u,%u,%u,%u,%u,%u,%u,%u,%u,%d,%d,%d,%d,%d,%d,%d,%u,%u,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%u\n",
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
        adc_values[0],adc_values[1],adc_values[2],adc_values[3],adc_values[4],adc_values[5],adc_values[6],
        voltages[0],voltages[1],voltages[2],voltages[3],voltages[4],voltages[5],voltages[6],
        resistances[0],resistances[1],
        gpio[0] ? '1' : '0',gpio[1] ? '1' : '0',gpio[2] ? '1' : '0',gpio[3] ? '1' : '0',
        gpio[4] ? '1' : '0',gpio[5] ? '1' : '0',gpio[6] ? '1' : '0',gpio[7] ? '1' : '0',
        gpio[8] ? '1' : '0',gpio[9] ? '1' : '0',gpio[10] ? '1' : '0',gpio[11] ? '1' : '0',
        gpio[12] ? '1' : '0',gpio[13] ? '1' : '0',gpio[14] ? '1' : '0',gpio[15] ? '1' : '0',
        gpio[16] ? '1' : '0',gpio[17] ? '1' : '0',gpio[18] ? '1' : '0',gpio[19] ? '1' : '0',
        gpio[20] ? '1' : '0',gpio[21] ? '1' : '0',gpio[22] ? '1' : '0',gpio[23] ? '1' : '0',
        charging_time
        );

    return String(line);
}


String EVSEV2::get_evse_monitor_header() {
    return "millis,"
            "state,iec,vehicle,contactor,_error,charge_release,allowed_current,error,lock,t_state_change,uptime,"
            "low_level_state,led,cp_pwm,adc_0,adc_1,adc_2,adc_3,adc_4,adc_5,adc_6,voltage_0,voltage_1,voltage_2,voltage_3,voltage_4,voltage_5,voltage_6,resistances_0,resistances_1,charging_time"
            "hardware_cfg,jumper,has_lock_switch,"
            "max_charging_current,configured,incoming,outgoing,"
            "auto_start,auto_start,"
            "energy_meter_values,power,energy_rel,energy_abs,"
            "dc_fault_current_state,dc_fault,"
            "gpio_cfg,shutdown_input_cfg,input_cfg,output_cfg,"
            "gpios,gpio_0,gpio_1,gpio_2,gpio_3,gpio_4,gpio_5,gpio_6,gpio_7,gpio_8,gpio_9,gpio_10,gpio_11,gpio_12,gpio_13,gpio_14,gpio_15,gpio_16,gpio_17,gpio_18,gpio_19,gpio_20,gpio_21,gpio_22,gpio_23\n";
}

String EVSEV2::get_evse_monitor_line() {
    if(!initialized)
        return "EVSE is not initialized!";

    char line[300] = {0};
    snprintf(line, sizeof(line)/sizeof(line[0]), "%lu,,%u,%u,%u,%u,%u,%u,%u,%u,%lu,%lu,,%u,%u,%u,%u,%u,%u,%u,%u,%u,%d,%d,%d,%d,%d,%d,%d,%u,%u,%u,,%u,%c,,%u,%u,%u,%u,,%c,,%lu,%lu,%lu,,%u,,%u,%u,%u,,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,\n",
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
        evse_low_level_state.get("adc_values")->get(5)->asUint(),
        evse_low_level_state.get("adc_values")->get(6)->asUint(),
        evse_low_level_state.get("voltages")->get(0)->asInt(),
        evse_low_level_state.get("voltages")->get(1)->asInt(),
        evse_low_level_state.get("voltages")->get(2)->asInt(),
        evse_low_level_state.get("voltages")->get(3)->asInt(),
        evse_low_level_state.get("voltages")->get(4)->asInt(),
        evse_low_level_state.get("voltages")->get(5)->asInt(),
        evse_low_level_state.get("voltages")->get(6)->asInt(),
        evse_low_level_state.get("resistances")->get(0)->asUint(),
        evse_low_level_state.get("resistances")->get(1)->asUint(),
        evse_low_level_state.get("charging_time")->asUint(),

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

        evse_gpio_configuration.get("shutdown_input")->asUint(),
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
    is_in_bootloader(tf_evse_v2_set_managed_current(&device, current));
    this->last_current_update = millis();
    this->shutdown_logged = false;
}

void EVSEV2::register_urls()
{
    if (!device_found)
        return;


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
        if (!evse_managed.get("managed")->asBool()) {
            // Push back the next check for 30 seconds: If managed gets enabled,
            // we want to wait 30 seconds before setting the current for the first time.
            this->last_current_update = millis();
            return;
        }
        if(!this->shutdown_logged)
            logger.printfln("Got no managed current update for more than 30 seconds. Setting managed current to 0");
        this->shutdown_logged = true;
        is_in_bootloader(tf_evse_v2_set_managed_current(&device, 0));
    }, 1000, 1000);
#endif

    api.addState("evse/state", &evse_state, {}, 1000);
    api.addState("evse/hardware_configuration", &evse_hardware_configuration, {}, 1000);
    api.addState("evse/low_level_state", &evse_low_level_state, {}, 1000);
    api.addState("evse/max_charging_current", &evse_max_charging_current, {}, 1000);
    api.addState("evse/auto_start_charging", &evse_auto_start_charging, {}, 1000);
    api.addState("evse/energy_meter_values", &evse_energy_meter_values, {}, 1000);
    api.addState("evse/energy_meter_state", &evse_energy_meter_state, {}, 1000);
    api.addState("evse/dc_fault_current_state", &evse_dc_fault_current_state, {}, 1000);

    api.addCommand("evse/reset_dc_fault_current", &evse_reset_dc_fault_current, {}, [this](){
        is_in_bootloader(tf_evse_v2_reset_dc_fault_current(&device, evse_reset_dc_fault_current.get("password")->asUint()));
    }, true);

    api.addState("evse/gpio_configuration", &evse_gpio_configuration, {}, 1000);
    api.addCommand("evse/gpio_configuration_update", &evse_gpio_configuration, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_gpio_configuration(&device, evse_gpio_configuration.get("shutdown_input")->asUint(),
                                                                  evse_gpio_configuration.get("input")->asUint(),
                                                                  evse_gpio_configuration.get("output")->asUint()));
    }, true);

    api.addState("evse/button_configuration", &evse_button_configuration, {}, 1000);
    api.addCommand("evse/button_configuration_update", &evse_button_configuration_update, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_button_configuration(&device, evse_button_configuration_update.get("button")->asUint()));
    }, true);

    api.addCommand("evse/auto_start_charging_update", &evse_auto_start_charging_update, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_charging_autostart(&device, evse_auto_start_charging_update.get("auto_start_charging")->asBool()));
    }, false);

    api.addCommand("evse/current_limit", &evse_current_limit, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_max_charging_current(&device, evse_current_limit.get("current")->asUint()));
    }, false);

    api.addCommand("evse/stop_charging", &evse_stop_charging, {}, [this](){is_in_bootloader(tf_evse_v2_stop_charging(&device));}, true);
    api.addCommand("evse/start_charging", &evse_start_charging, {}, [this](){is_in_bootloader(tf_evse_v2_start_charging(&device));}, true);

    api.addCommand("evse/managed_current_update", &evse_managed_current, {}, [this](){
        is_in_bootloader(tf_evse_v2_set_managed_current(&device, evse_managed_current.get("current")->asUint()));
    }, true);

    api.addState("evse/managed", &evse_managed, {}, 1000);
    api.addCommand("evse/managed_update", &evse_managed_update, {"password"}, [this](){
        is_in_bootloader(tf_evse_v2_set_managed(&device, evse_managed_update.get("managed")->asBool(), evse_managed_update.get("password")->asUint()));
    }, true);

    api.addState("evse/button_state", &evse_button_state, {}, 250);

    api.addState("evse/control_pilot_configuration", &evse_control_pilot_configuration, {}, 1000);
    api.addCommand("evse/control_pilot_configuration_update", &evse_control_pilot_configuration_update, {}, [this](){
        auto cp = evse_control_pilot_configuration_update.get("control_pilot")->asUint();
        int rc = tf_evse_v2_set_control_pilot_configuration(&device, cp);
        logger.printfln("updating control pilot to %u. rc %d", cp, rc);
        is_in_bootloader(rc);
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

    this->DeviceModule::register_urls();
}

void EVSEV2::loop()
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

void EVSEV2::setup_evse()
{
    if (!this->DeviceModule::setup_device()) {
        return;
    }

    uint8_t jumper_configuration;
    bool has_lock_switch;

    int result = tf_evse_v2_get_hardware_configuration(&device, &jumper_configuration, &has_lock_switch);

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
}


void EVSEV2::update_all_data() {
    if(!initialized)
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

    // get_all_data_2
    uint8_t led_state;
	uint16_t cp_pwm_duty_cycle;
	uint16_t adc_values[7];
	int16_t voltages[7];
	uint32_t resistances[2];
	bool gpio[24];
	uint32_t charging_time;
	uint16_t max_current_configured;
	uint16_t max_current_incoming_cable;
	uint16_t max_current_outgoing_cable;
	uint16_t max_current_managed;
	bool autostart;

    // get_all_data_3
    float power;
	float energy_relative;
	float energy_absolute;
	bool phases_active[3];
	bool phases_connected[3];
	bool available;
	uint32_t error_count[6];
	uint8_t dc_fault_current_state;
	uint8_t shutdown_input_configuration;
	uint8_t input_configuration;
	uint8_t output_configuration;
	bool managed;
	int16_t indication;
	uint16_t duration;
	uint8_t button_configuration;
	uint32_t button_press_time;
	uint32_t button_release_time;
	bool button_pressed;
    uint8_t control_pilot;

    int rc = tf_evse_v2_get_all_data_1(&device,
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
        &has_lock_switch);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    rc = tf_evse_v2_get_all_data_2(&device,
        &led_state,
        &cp_pwm_duty_cycle,
        adc_values,
        voltages,
        resistances,
        gpio,
        &charging_time,
        &max_current_configured,
        &max_current_incoming_cable,
        &max_current_outgoing_cable,
        &max_current_managed,
        &autostart);

    if(rc != TF_E_OK) {
        is_in_bootloader(rc);
        return;
    }

    rc = tf_evse_v2_get_all_data_3(&device,
        &power,
        &energy_relative,
        &energy_absolute,
        phases_active,
        phases_connected,
        &available,
        error_count,
        &dc_fault_current_state,
        &shutdown_input_configuration,
        &input_configuration,
        &output_configuration,
        &managed,
        &indication,
        &duration,
        &button_configuration,
        &button_press_time,
        &button_release_time,
        &button_pressed,
        &control_pilot);

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
    evse_low_level_state.get("led_state")->updateUint(led_state);
    evse_low_level_state.get("cp_pwm_duty_cycle")->updateUint(cp_pwm_duty_cycle);
    evse_low_level_state.get("charging_time")->updateUint(charging_time);

    for(int i = 0; i < sizeof(adc_values)/sizeof(adc_values[0]); ++i)
        evse_low_level_state.get("adc_values")->get(i)->updateUint(adc_values[i]);

    for(int i = 0; i < sizeof(voltages)/sizeof(voltages[0]); ++i)
        evse_low_level_state.get("voltages")->get(i)->updateInt(voltages[i]);

    for(int i = 0; i < sizeof(resistances)/sizeof(resistances[0]); ++i)
        evse_low_level_state.get("resistances")->get(i)->updateUint(resistances[i]);

    for(int i = 0; i < sizeof(gpio)/sizeof(gpio[0]); ++i)
        evse_low_level_state.get("gpio")->get(i)->updateBool(gpio[i]);

    // get_max_charging_current
    evse_max_charging_current.get("max_current_configured")->updateUint(max_current_configured);
    evse_max_charging_current.get("max_current_incoming_cable")->updateUint(max_current_incoming_cable);
    evse_max_charging_current.get("max_current_outgoing_cable")->updateUint(max_current_outgoing_cable);
    evse_max_charging_current.get("max_current_managed")->updateUint(max_current_managed);

    // get_charging_autostart
    evse_auto_start_charging.get("auto_start_charging")->updateBool(autostart);

    // get_managed
    evse_managed.get("managed")->updateBool(managed);

    // get_energy_meter_values
    evse_energy_meter_values.get("power")->updateFloat(power);
    evse_energy_meter_values.get("energy_rel")->updateFloat(energy_relative);
    evse_energy_meter_values.get("energy_abs")->updateFloat(energy_absolute);

    for(int i = 0; i < 3; ++i)
        evse_energy_meter_values.get("phases_active")->get(i)->updateBool(phases_active[i]);

    for(int i = 0; i < 3; ++i)
        evse_energy_meter_values.get("phases_connected")->get(i)->updateBool(phases_connected[i]);

    // get_energy_meter_state
    evse_energy_meter_state.get("available")->updateBool(available);
    for(int i = 0; i < sizeof(error_count)/sizeof(error_count[0]); ++i)
        evse_energy_meter_state.get("error_count")->get(i)->updateUint(error_count[i]);

    // get_dc_fault_current_state
    evse_dc_fault_current_state.get("state")->updateUint(dc_fault_current_state);

    // get_gpio_configuration
    evse_gpio_configuration.get("shutdown_input")->updateUint(shutdown_input_configuration);
    evse_gpio_configuration.get("input")->updateUint(input_configuration);
    evse_gpio_configuration.get("output")->updateUint(output_configuration);

    // get_button_configuration
    evse_button_configuration.get("button")->updateUint(button_configuration);

    // get_button_state
    evse_button_state.get("button_press_time")->updateUint(button_press_time);
    evse_button_state.get("button_release_time")->updateUint(button_release_time);
    evse_button_state.get("button_pressed")->updateBool(button_pressed);

    // get_control_pilot
    evse_control_pilot_configuration.get("control_pilot")->updateUint(control_pilot);
}
