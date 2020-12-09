import $ from "jquery";

import * as util from "../util";

let evse_charge_start = -1;
let evse_charge_time = -1;
let last_evse_charge_time = -1;

interface UnixTimestampMSResult {
    timestamp: number
}

function show_rtc(data: UnixTimestampMSResult) {
    let d = new Date(data.timestamp);
    $('#rtc_datetime').html(d.toISOString());
    if (evse_charge_start > 0) {
        evse_charge_time = d.getTime() - new Date(evse_charge_start).getTime();
        $('#evse_state_charging_charge_time').html(format_timespan(Math.floor(evse_charge_time / 1000)));
    } else {
        if (evse_charge_time > 0) {
            last_evse_charge_time = evse_charge_time;
            $('#evse_state_charging_charge_time').html(format_timespan(Math.floor(last_evse_charge_time / 1000)));
        }
        evse_charge_time = -1;
        //$('#evse_state_charging_charge_time').html("");
    }
}

function format_timespan(secs: number) {
    let days = 0;
    let hours = 0;
    let mins = 0;

    let dayString = "";
    let hourString = "";
    let minString = "";
    let secString = "";

    if (secs >= 60 * 60 * 24) {
        days = Math.floor(secs / (60 * 60 * 24));
        if (days > 1) {
            dayString = days + " days, ";
        } else if (days > 0) {
            dayString = days + " day, ";
        }
        secs %= 60 * 60 * 24;
    }

    if (secs >= 60 * 60) {
        hours = Math.floor(secs / (60 * 60));
        if (hours >= 10) {
            hourString = hours + ":";
        } else {
            hourString = "0" + hours + ":";
        }
        secs %= 60 * 60;
    } else {
        hourString = "00:";
    }

    if (secs >= 60) {
        mins = Math.floor(secs / 60);
        if (mins >= 10) {
            minString = mins + ":";
        } else {
            minString = "0" + mins + ":";
        }
        secs %= 60;
    } else {
        minString = "00:";
    }

    if (secs >= 10) {
        secString = secs.toString();
    } else {
        secString = "0" + secs;
    }

    return dayString + hourString + minString + secString;
}
/*
interface EVSEChargingState {
    state: number,
    start: number
}

function update_evse_charging_state(state: EVSEChargingState) {
    const button_dict: { [idx: number]: string } = {
        0: "#evse_state_not_connected",
        1: "#evse_state_connected",
        2: "#evse_state_charging",
        3: "#evse_state_error",
    };

    const outline_dict: { [idx: number]: string } = {
        0: "btn-outline-primary",
        1: "btn-outline-warning",
        2: "btn-outline-success",
        3: "btn-outline-danger",
    };

    const non_outline_dict: { [idx: number]: string } = {
        0: "btn-primary",
        1: "btn-warning",
        2: "btn-success",
        3: "btn-danger",
    };

    for (let i = 0; i < 4; ++i) {
        if (i == state.state) {
            $(button_dict[i]).removeClass(outline_dict[i]);
            $(button_dict[i]).addClass(non_outline_dict[i]);
        } else {
            $(button_dict[i]).removeClass(non_outline_dict[i]);
            $(button_dict[i]).addClass(outline_dict[i]);
        }
    }

    if (state.state == 2) {
        $("#evse_state_charging_text").html("Charging for ");
    } else if (last_evse_charge_time > 0 || evse_charge_time > 0) {
        $("#evse_state_charging_text").html("Last charge took ");
    } else {
        $("#evse_state_charging_text").html("Charging");
    }

    evse_charge_start = state.start;
}*/


interface EVSEState {
    iec61851_state: number,
    contactor_state: number,
    contactor_error: number,
    allowed_charging_current: number,
    lock_state: number,
    time_since_state_change: number
    uptime: number
}

function update_evse_state(state: EVSEState) {
    util.update_button_group("btn_group_iec_state", state.iec61851_state);
    // Handle state D (3) and E/F (4) as error
    util.update_button_group("btn_group_evse_state", Math.min(3, state.iec61851_state));

    $('#allowed_charging_current').val((state.allowed_charging_current / 1000.0).toFixed(3) + "A");

    util.update_button_group("btn_group_ac1", (state.contactor_state & 1) == 1 ? 1 : 0);
    util.update_button_group("btn_group_ac2", state.contactor_state > 1 ? 1 : 0);
    util.update_button_group("btn_group_contactor_error", state.contactor_error != 0 ? 1 : 0, state.contactor_error != 0 ? "Error Code " + state.contactor_error : null);
    util.update_button_group("btn_group_lock_state", state.lock_state);

    $('#uptime').val(format_timespan(Math.floor(state.uptime / 1000)));
    $('#time_since_state_change').val(format_timespan(Math.floor(state.time_since_state_change / 1000)));

    if (state.iec61851_state == 2) {
        $("#evse_state_charging_text").html("Charging for ");
        $('#evse_state_charging_charge_time').html(format_timespan(Math.floor(state.time_since_state_change / 1000)));
    } else if ($('#evse_state_charging_charge_time').html() != "") {
        $("#evse_state_charging_text").html("Last charge took ");
    } else {
        $("#evse_state_charging_text").html("Charging");
    }
    /**/
}

interface EVSEHardwareConfiguration {
    jumper_configuration: number,
    has_lock_switch: boolean,
}

function update_evse_hardware_configuration(cfg: EVSEHardwareConfiguration) {
    util.update_button_group("btn_group_has_lock_switch", cfg.has_lock_switch ? 1 : 0);
    util.update_button_group("btn_group_jumper_config", cfg.jumper_configuration);
}

interface EVSELowLevelState {
    low_level_mode_enabled: boolean,
    led_state: number,
    cp_pwm_duty_cycle: number,
    adc_values: Uint16Array,
    voltages: Int16Array,
    resistances: Uint32Array,
    gpio: boolean[],
    motor_direction: boolean,
    motor_duty_cycle: number
}

function update_evse_low_level_state(state: EVSELowLevelState) {
    util.update_button_group("btn_group_low_level_mode_enabled", state.low_level_mode_enabled ? 1 : 0);
    util.update_button_group("btn_group_led_state", state.led_state);

    for(let i = 0; i < 5; ++i) {
        util.update_button_group("btn_group_gpio" + i, state.gpio[i] ? 1 : 0);
        util.update_button_group("btn_group_gpio" + i, state.gpio[i] ? 1 : 0);
        util.update_button_group("btn_group_gpio" + i, state.gpio[i] ? 1 : 0);
        util.update_button_group("btn_group_gpio" + i, state.gpio[i] ? 1 : 0);
        util.update_button_group("btn_group_gpio" + i, state.gpio[i] ? 1 : 0);
    }

    $('#pwm_duty_cycle').val((state.cp_pwm_duty_cycle / 10).toFixed(1) + "%");

    $('#adc_value_0').val(state.adc_values[0]);
    $('#adc_value_1').val(state.adc_values[1]);

    $('#voltage_0').val((state.voltages[0] / 1000.0).toFixed(3) + "V");
    $('#voltage_1').val((state.voltages[1] / 1000.0).toFixed(3) + "V");
    $('#voltage_2').val((state.voltages[2] / 1000.0).toFixed(3) + "V");

    $('#resistance_0').val(state.resistances[0] + "Ω");
    $('#resistance_1').val(state.resistances[1] + "Ω");

    util.update_button_group("btn_group_motor_direction", state.motor_direction ? 1 : 0);
    $('#motor_duty_cycle').val(state.motor_duty_cycle);
}

interface EVSEMaxChargingCurrent {
    max_current_configured: number,
    max_current_incoming_cable: number,
    max_current_outgoing_cable: number
}

function update_evse_max_charging_current(state: EVSEMaxChargingCurrent) {
    $('#max_current_configured').val((state.max_current_configured / 1000.0).toFixed(3) + "A");
    $('#max_current_incoming_cable').val((state.max_current_incoming_cable / 1000.0).toFixed(3) + "A");
    $('#max_current_outgoing_cable').val((state.max_current_outgoing_cable / 1000.0).toFixed(3) + "A");
}

export function init() {

}

export function addEventListeners(source: EventSource) {
    source.addEventListener('evse_state', function (e: util.SSE) {
        update_evse_state(<EVSEState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('evse_low_level_state', function (e: util.SSE) {
        update_evse_low_level_state(<EVSELowLevelState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('evse_max_charging_current', function (e: util.SSE) {
        update_evse_max_charging_current(<EVSEMaxChargingCurrent>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('evse_hardware_configuration', function (e: util.SSE) {
        update_evse_hardware_configuration(<EVSEHardwareConfiguration>(JSON.parse(e.data)));
    }, false);

    //source.addEventListener('unix_timestamp_ms', function (e: util.SSE) {
    //    show_rtc(<UnixTimestampMSResult>(JSON.parse(e.data)));
    //}, false);

}

export function updateLockState(module_init) {
    console.log(module_init.sdm72dm);
    $('#sidebar-evse').prop('hidden', !module_init.sdm72dm);
}
