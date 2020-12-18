import $ from "jquery";

import * as util from "../util";

interface EVSEState {
    iec61851_state: number,
    vehicle_state: number,
    contactor_state: number,
    contactor_error: number,
    allowed_charging_current: number,
    lock_state: number,
    time_since_state_change: number
    uptime: number
}

function update_evse_state(state: EVSEState) {
    util.update_button_group("btn_group_iec_state", state.iec61851_state);

    util.update_button_group("btn_group_evse_state", state.vehicle_state);

    let allowed_charging_current = (state.allowed_charging_current / 1000.0).toFixed(3) + "A";
    $('#allowed_charging_current').val(allowed_charging_current);

    if($('#status_charging_current_save').prop("disabled")) {
        $('#status_charging_current').val(state.allowed_charging_current / 1000);
    }

    util.update_button_group("btn_group_ac1", (state.contactor_state & 1) == 1 ? 1 : 0);
    util.update_button_group("btn_group_ac2", state.contactor_state > 1 ? 1 : 0);
    util.update_button_group("btn_group_contactor_error", state.contactor_error != 0 ? 1 : 0, state.contactor_error != 0 ? "Error Code " + state.contactor_error : null);
    util.update_button_group("btn_group_lock_state", state.lock_state);

    $('#uptime').val(format_timespan(Math.floor(state.uptime / 1000)));
    $('#time_since_state_change').val(util.format_timespan(Math.floor(state.time_since_state_change / 1000)));

    if (state.iec61851_state == 2) {
        $("#evse_state_charging_text").html("Charging for ");
        $('#evse_state_charging_charge_time').html(util.format_timespan(Math.floor(state.time_since_state_change / 1000)));
    } else if ($('#evse_state_charging_charge_time').html() != "") {
        $("#evse_state_charging_text").html("Last charge took ");
    } else {
        $("#evse_state_charging_text").html("Charging");
    }
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
    gpio: boolean[]
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

    let theoretical_maximum = Math.min(state.max_current_incoming_cable, state.max_current_outgoing_cable);
    let theoretical_maximum_str = (theoretical_maximum / 1000.0).toFixed(0) + " A";
    $('#status_charging_current').prop("max", theoretical_maximum / 1000);
    $('#status_charging_current_maximum').html("Max ("+theoretical_maximum_str+")");
}

function set_charging_current(current: number) {
    $.ajax({
        url: '/evse_current_limit',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify({"current": current}),
        success: () => $('#status_charging_current_save').prop("disabled", true),
        error: (_x, _y, error) => util.show_alert("alert-danger", "Failed to set charging current.", error)
    });
}

export function init() {
    $("#status_charging_current_minimum").on("click", () => set_charging_current(6000));
    $("#status_charging_current_maximum").on("click", () => set_charging_current(32000));
    let input = $('#status_charging_current');
    let save_btn = $('#status_charging_current_save');
    input.on("input", () => save_btn.prop("disabled", false));

    save_btn.on("click", () => {
        if(input.val() >= 6 || input.val() <= 32)
            set_charging_current(Number(input.val() * 1000));
    });

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
}

export function updateLockState(module_init) {
    console.log(module_init.sdm72dm);
    $('#sidebar-evse').prop('hidden', !module_init.sdm72dm);
}
