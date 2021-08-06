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

import $ from "jquery";

import * as util from "../util";

import feather = require("feather-icons");

declare function __(s: string): string;

interface EVSEState {
    iec61851_state: number,
    vehicle_state: number,
    contactor_state: number,
    contactor_error: number,
    charge_release: number,
    allowed_charging_current: number,
    error_state: number,
    lock_state: number,
    time_since_state_change: number
    uptime: number
}

function update_evse_state(state: EVSEState) {
    util.update_button_group("btn_group_iec_state", state.iec61851_state);

    util.update_button_group("btn_group_evse_state", state.vehicle_state);

    $('#status_start_charging').prop("disabled", state.vehicle_state != 1);
    $('#status_stop_charging').prop("disabled", state.vehicle_state != 2);

    let allowed_charging_current = util.toLocaleFixed(state.allowed_charging_current / 1000.0, 3) + " A";
    $('#allowed_charging_current').val(allowed_charging_current);

    util.update_button_group("btn_group_ac1", (state.contactor_state & 1) == 1 ? 1 : 0);
    util.update_button_group("btn_group_ac2", state.contactor_state > 1 ? 1 : 0);
    util.update_button_group("btn_group_contactor_error", state.contactor_error != 0 ? 1 : 0, state.contactor_error != 0 ? __("evse.script.error_code") + " " + state.contactor_error : null);
    util.update_button_group("btn_group_charge_release", state.charge_release);
    util.update_button_group("btn_group_error_state", state.error_state == 0 ? 0 : state.error_state - 1); // 1 is not a valid error state
    util.update_button_group("btn_group_lock_state", state.lock_state);

    $('#uptime').val(util.format_timespan(Math.floor(state.uptime / 1000)));
    $('#time_since_state_change').val(util.format_timespan(Math.floor(state.time_since_state_change / 1000)));

    if (state.iec61851_state == 2) {
        $("#evse_state_charging_text").html(__("evse.script.charging_for") + " ");
        $('#evse_state_charging_charge_time').html(util.format_timespan(Math.floor(state.time_since_state_change / 1000)));
    } else if ($('#evse_state_charging_charge_time').html() != "") {
        $("#evse_state_charging_text").html(__("evse.script.last_charge_took") + " ");
    } else {
        $("#evse_state_charging_text").html(__("evse.status.charging"));
    }
}

interface EVSEHardwareConfiguration {
    jumper_configuration: number,
    has_lock_switch: boolean,
}

function update_evse_hardware_configuration(cfg: EVSEHardwareConfiguration) {
    util.update_button_group("btn_group_has_lock_switch", cfg.has_lock_switch ? 1 : 0);
    util.update_button_group("btn_group_jumper_config", cfg.jumper_configuration);
    $('#evse_row_lock_switch').prop('hidden', !cfg.has_lock_switch);
}

interface EVSELowLevelState {
    led_state: number,
    cp_pwm_duty_cycle: number,
    adc_values: Uint16Array,
    voltages: Int16Array,
    resistances: Uint32Array,
    gpio: boolean[],
}

function update_evse_low_level_state(state: EVSELowLevelState) {
    util.update_button_group("btn_group_led_state", state.led_state);

    for(let i = 0; i < 24; ++i) {
        //intentionally inverted: the high button is the first
        util.update_button_group(`btn_group_gpio${i}`, state.gpio[i] ? 0 : 1);
    }

    $('#pwm_duty_cycle').val(util.toLocaleFixed(state.cp_pwm_duty_cycle / 10, 1) + " %");

    for(let i = 0; i < 5; ++i) {
        $(`#adc_value_${i}`).val(state.adc_values[i]);
    }

    for(let i = 0; i < 5; ++i) {
        $(`#voltage_${i}`).val(util.toLocaleFixed(state.voltages[i] / 1000.0, 3) + " V");
    }

    for(let i = 0; i < 5; ++i) {
        $(`#resistance_${i}`).val(state.resistances[i] + " Ω");
    }
}

interface EVSEMaxChargingCurrent {
    max_current_configured: number,
    max_current_incoming_cable: number,
    max_current_outgoing_cable: number,
    max_current_managed: number
}

let last_max_charging_current: EVSEMaxChargingCurrent = null;
let last_managed: EVSEManaged = null;

function update_allowed_current_status() {
    let real_maximum = Math.min(last_max_charging_current.max_current_configured,
                                last_max_charging_current.max_current_incoming_cable,
                                last_max_charging_current.max_current_outgoing_cable);

    let managed = last_managed != null && last_managed.managed;
    if (managed) {
        real_maximum = Math.min(real_maximum, last_max_charging_current.max_current_managed);
    }

    let status_string = util.toLocaleFixed(real_maximum / 1000.0, 3) + " A " + __("evse.script.by") + " ";

    let status_list = [];
    if (real_maximum == last_max_charging_current.max_current_configured)
        status_list.push(__("evse.script.configuration"));
    if (real_maximum == last_max_charging_current.max_current_managed)
        status_list.push(__("evse.script.management"));
    if (real_maximum == last_max_charging_current.max_current_outgoing_cable)
        status_list.push(__("evse.script.outgoing"));
    if (real_maximum == last_max_charging_current.max_current_incoming_cable)
        status_list.push(__("evse.script.incoming"));

    status_string += status_list.join(", ");

    $('#evse_status_allowed_charging_current').val(status_string);
}

function update_evse_max_charging_current(state: EVSEMaxChargingCurrent) {
    $('#max_current_configured').val(util.toLocaleFixed(state.max_current_configured / 1000.0, 3) + " A");
    $('#max_current_incoming_cable').val(util.toLocaleFixed(state.max_current_incoming_cable / 1000.0, 3) + " A");
    $('#max_current_outgoing_cable').val(util.toLocaleFixed(state.max_current_outgoing_cable / 1000.0, 3) + " A");
    $('#max_current_managed').val(util.toLocaleFixed(state.max_current_managed / 1000.0, 3) + " A");

    let theoretical_maximum = Math.min(state.max_current_incoming_cable, state.max_current_outgoing_cable);
    let theoretical_maximum_str = util.toLocaleFixed(theoretical_maximum / 1000.0, 0) + " A";
    $('#status_charging_current').prop("max", theoretical_maximum / 1000);
    $("#status_charging_current_maximum").on("click", () => set_charging_current(theoretical_maximum));
    $('#status_charging_current_maximum').html(theoretical_maximum_str);

    if($('#status_charging_current_save').prop("disabled")) {
        $('#status_charging_current').val(util.toLocaleFixed(state.max_current_configured / 1000.0, 3));
    }

    last_max_charging_current = state;
    update_allowed_current_status();
}

function set_charging_current(current: number) {
    $('#status_charging_current_save').prop("disabled", true);
    $.ajax({
        url: '/evse/current_limit',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify({"current": current}),
        success: () => {
            $('#status_charging_current_save').html(feather.icons.check.toSvg());
        },
        error: (xhr, status, error) => {
            $('#status_charging_current_save').prop("disabled", false);
            util.add_alert("evse_set_charging_current_failed", "alert-danger", __("evse.script.set_charging_current_failed"), error + ": " + xhr.responseText);
        }
    });
}

interface EVSEAutoStart {
    auto_start_charging: boolean
}

function update_evse_auto_start_charging(x: EVSEAutoStart) {
    $('#status_auto_start_charging').prop("checked", x.auto_start_charging);
}

function set_auto_start_charging(auto_start_charging: boolean) {
    $.ajax({
        url: '/evse/auto_start_charging_update',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify({"auto_start_charging": auto_start_charging}),
        error: (xhr, status, error) => util.add_alert("evse_set_auto_start_charging_failed", "alert-danger",  __("evse.script.auto_start_charging_update"), error + ": " + xhr.responseText)
    });
}

function start_charging() {
    $.ajax({
        url: '/evse/start_charging',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify(null),
        error: (xhr, status, error) => util.add_alert("evse_set_start_charging_failed", "alert-danger", __("evse.script.start_charging_failed"), error + ": " + xhr.responseText)
    });
}

function stop_charging() {
    $.ajax({
        url: '/evse/stop_charging',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify(null),
        error: (xhr, status, error) => util.add_alert("evse_set_stop_charging_failed", "alert-danger",  __("evse.script.stop_charging_failed"), error + ": " + xhr.responseText)
    });
}

interface EVSEManaged {
    managed: boolean;
}

function update_evse_managed(m: EVSEManaged) {
    $('#evse_charge_management').prop("checked", m.managed);
    $('#evse_charging_current_managed_ignored').html(m.managed ? "" : __("evse.script.managed_current_ignored"));
    last_managed = m;
    update_allowed_current_status();
}

interface EVSEDCFaultCurrentState {
    state: number
}

function update_evse_dc_fault_current_state(s: EVSEDCFaultCurrentState) {
    util.update_button_group("btn_group_dc_fault_current_state", s.state);

    $('#evse_reset_dc_fault_current').prop('disabled', s.state == 0);
}

function reset_dc_fault_current() {
    //TODO: show modal, call evse/reset_dc_fault_current
    //evse_reset_dc_fault_modal

}

interface EVSEGPIOConfiguration {
    enable_input: number,
    input: number,
    output: number
}

let debug_log = "";
let meter_chunk = "";

function allow_debug(b: boolean) {
    $('#debug_start').prop("disabled", !b);
    $('#debug_stop').prop("disabled", b);
    if (!b) {
        window.onbeforeunload = (e: Event) => {
            e.preventDefault();
            // returnValue is not a boolean, but the string to be shown
            // in the "are you sure you want to close this tab" message
            // box. However this string is only shown in some browsers.
            e.returnValue = <any>__("evse.script.tab_close_warning");
        }
    } else {
        window.onbeforeunload = null;
    }
}

function debug_start() {
    debug_log = "";
    let status = <HTMLInputElement>$('#debug_label')[0];
    status.value = __("evse.script.loading_debug_report");
    allow_debug(false);
    $.get("/debug_report")
        .fail(() => {
            status.value = __("evse.script.loading_debug_report_failed");
            allow_debug(true);
        })
        .done((result) => {
            debug_log += JSON.stringify(result) + "\n\n";

            status.value = __("evse.script.loading_event_log");

            $.get("/event_log")
                .fail(() => {
                    status.value = __("evse.script.loading_event_log_failed");
                    allow_debug(true);
                })
                .done((result) => {
                    debug_log += result + "\n";

                    status.value = __("evse.script.starting_debug");

                    $.get("/evse/start_debug")
                        .fail(() => {
                            status.value = __("evse.script.starting_debug_failed");
                            allow_debug(true);
                        })
                        .done((result) => {
                            status.value = __("evse.script.debug_running");
                        });
                });
        });
}

function downloadToFile(content: BlobPart, filename: string, contentType: string) {
    const a = document.createElement('a');
    const file = new Blob([content], {type: contentType});

    a.href= URL.createObjectURL(file);
    a.download = filename;
    a.click();

    URL.revokeObjectURL(a.href);
};

function debug_stop() {
    let status = <HTMLInputElement>$('#debug_label')[0];

    allow_debug(true);

    $.get("/evse/stop_debug")
        .fail(() => {
            status.value = __("evse.script.debug_stop_failed");
        })
        .done((result) => {
            status.value = __("evse.script.debug_stopped");
            $.get("/debug_report")
                .fail(() => {
                    status.value = __("evse.script.loading_debug_report_failed");
                })
                .done((result) => {
                    debug_log += "\n" + JSON.stringify(result) + "\n\n";

                    status.value = __("evse.script.loading_event_log");

                    $.get("/event_log")
                        .fail(() => {
                            status.value = __("evse.script.loading_event_log_failed");
                        })
                        .done((result) => {
                            debug_log += result + "\n";
                            status.value = __("evse.script.debug_done");

                            downloadToFile(debug_log, "evse-debug-log-" + (new Date()).toISOString().replace(/:/gi, "-").replace(/\./gi, "-") + ".txt", "text/plain");
                        });
                });
        });
}


export function init() {
    $("#status_charging_current_minimum").on("click", () => set_charging_current(6000));
    $("#status_charging_current_maximum").on("click", () => set_charging_current(32000));

    $('#evse_reset_dc_fault_current').on("click", () => $('#evse_reset_dc_fault_modal').modal('show'));
    $('#evse_reset_dc_fault_modal_button').on("click", () => {
        $('#evse_reset_dc_fault_modal').modal('hide');
        $.ajax({
            url: '/evse/reset_dc_fault_current',
            method: 'PUT',
            contentType: 'application/json',
            data: JSON.stringify({"password": 0xDC42FA23}),
            error: (xhr, status, error) => {
                util.add_alert("evse_reset_dc_fault_current_failed", "alert-danger", __("evse.script.reset_dc_fault_current_failed"), error + ": " + xhr.responseText);
            }
        });
    });


    $("#status_stop_charging").on("click", stop_charging);
    $("#status_start_charging").on("click", start_charging);

    $('#status_auto_start_charging').on("change", () => set_auto_start_charging($('#status_auto_start_charging').prop('checked')));

    let input = $('#status_charging_current');
    let save_btn = $('#status_charging_current_save');
    input.on("input", () => {
        save_btn.html(feather.icons.save.toSvg());
        save_btn.prop("disabled", false);
    });


    let form = <HTMLFormElement>$('#evse_status_charging_current_form')[0];

    form.addEventListener('submit', function (event: Event) {
        event.preventDefault();
        event.stopPropagation();

        if (form.checkValidity() === false) {
            return;
        }

        set_charging_current(Math.round(<number>input.val() * 1000));
    }, false);

    $("#debug_start").on("click", debug_start);
    $("#debug_stop").on("click", debug_stop);

    allow_debug(true);

    $('#evse_charge_management').on("change", () => {
        let enable = $('#evse_charge_management').is(":checked");
        $.ajax({
            url: '/evse/managed_update',
            method: 'PUT',
            contentType: 'application/json',
            data: JSON.stringify({"managed": enable, "password": enable ? 0x00363702 : 0x036370FF}),
            error: (xhr, status, error) => util.add_alert("evse_managed_update_failed", "alert-danger", __("evse.script.save_failed"), error + ": " + xhr.responseText)
        });
    });
}

//From sdm72dm/main.ts
interface MeterState {
    power: number,
    energy_rel: number,
    energy_abs: number,
}

export function addEventListeners(source: EventSource) {
    source.addEventListener('evse/state', function (e: util.SSE) {
        update_evse_state(<EVSEState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('evse/low_level_state', function (e: util.SSE) {
        update_evse_low_level_state(<EVSELowLevelState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('evse/max_charging_current', function (e: util.SSE) {
        update_evse_max_charging_current(<EVSEMaxChargingCurrent>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('evse/hardware_configuration', function (e: util.SSE) {
        update_evse_hardware_configuration(<EVSEHardwareConfiguration>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('evse/auto_start_charging', function (e: util.SSE) {
        update_evse_auto_start_charging(<EVSEAutoStart>(JSON.parse(e.data)));
    }, false);

    source.addEventListener("evse/managed", function (e: util.SSE) {
        update_evse_managed(<EVSEManaged>(JSON.parse(e.data)));
    }, false);

    source.addEventListener("evse/dc_fault_current_state", function (e: util.SSE) {
        update_evse_dc_fault_current_state(<EVSEDCFaultCurrentState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener("evse/debug_header", function (e: util.SSE) {
        debug_log += e.data.slice(1, -1);
        if (meter_chunk.length > 0) {
            debug_log += ",power,energy_rel,energy_abs";
        }
        debug_log += "\n";
    }, false);

    source.addEventListener("evse/debug", function (e: util.SSE) {
        debug_log += e.data.slice(1, -1) + meter_chunk + "\n";
    }, false);

    source.addEventListener("meter/state", function (e: util.SSE) {
        let ms = <MeterState>(JSON.parse(e.data));
        meter_chunk = "," + ms.power + "," + ms.energy_rel + "," + ms.energy_abs;
    }, false);
}

export function updateLockState(module_init: any) {
    $('#sidebar-evse').prop('hidden', !module_init.evse_v2);
    $('#status-evse').prop('hidden', !module_init.evse_v2);
}

export function getTranslation(lang: string) {
    const translations: {[index: string]:any} = {
        "de": {
            "evse": {
                "status": {
                    "evse": "Fahrzeugstatus",
                    "not_connected": "Getrennt",
                    "connected": "Verbunden",
                    "charging": "Lädt",
                    "error": "Fehler",
                    "configured_charging_current": "Konfigurierter Ladestrom",
                    "allowed_charging_current": "Erlaubter Ladestrom",
                    "charging_current_minimum": "6 A",
                    "charging_current_maximum": "Max",
                    "charge_control": "Ladesteuerung",
                    "auto_start_charging": "Autostart",
                    "start_charging": "Start",
                    "stop_charging": "Stop"
                },
                "navbar": {
                    "evse": "Ladecontroller"
                },
                "content": {
                    "evse": "Ladecontroller (EVSE)",
                    "state": "Zustand",
                    "iec_state": "IEC-61851-Zustand",
                    "iec_state_a": "A (getrennt)",
                    "iec_state_b": "B (verbunden)",
                    "iec_state_c": "C (lädt)",
                    "iec_state_d": "D (nicht unterstützt)",
                    "iec_state_ef": "E/F (Fehler)",
                    "contactor_state": "Schützprüfung",
                    "contactor_names": "vor Schütz, nach Schütz, Zustand",
                    "contactor_not_live": "Stromlos",
                    "contactor_live": "Stromführend",
                    "contactor_ok": "OK",
                    "contactor_error": "Fehler",
                    "charge_release": "Ladefreigabe",
                    "charge_release_automatic": "Automatisch",
                    "charge_release_manual": "Manuell",
                    "charge_release_deactivated": "Deaktiviert",
                    "charge_release_managed": "Lastmanagement",
                    "allowed_charging_current": "Erlaubter Ladestrom",
                    "error_state": "Fehlerzustand",
                    "error_state_desc": "<a href=\"https://www.warp-charger.com/#documents\">siehe Betriebsanleitung für Details</a>",
                    "error_ok": "OK",
                    "error_switch": "Schalter",
                    "error_contactor": "Schütz",
                    "error_communication": "Kommunikation",
                    "error_dc_fault_current": "DC-Fehlerstromschutz",
                    "lock_state": "Kabelverriegelung",
                    "lock_init": "Start",
                    "lock_open": "Offen",
                    "lock_closing": "Schließend",
                    "lock_close": "Geschlossen",
                    "lock_opening": "Öffnend",
                    "lock_error": "Fehler",
                    "time_since_state_change": "Zeit seit Zustandswechsel",
                    "uptime": "Laufzeit",
                    "configuration": "Hardware-Konfiguration",
                    "has_lock_switch": "Kabelverriegelung vorhanden",
                    "lock_no": "Nein",
                    "lock_yes": "Ja",
                    "jumper_config_max_current": "Maximalstrom der Zuleitung",
                    "jumper_config": "durch Schalter konfiguriert",
                    "jumper_config_software": "Software",
                    "jumper_config_unconfigured": "Unkonfiguriert",
                    "charging_current": "Ladestromgrenzen",
                    "charging_current_muted": "Minimum der Ladestromgrenzen",
                    "charging_current_configured": "Konfiguriert",
                    "charging_current_max_incoming": "Zuleitung",
                    "charging_current_max_outgoing": "Typ-2-Ladekabel",
                    "charging_current_managed": "Lastmanagement",
                    "low_level_state": "Low-Level-Zustand",
                    "low_level_state_show": "Anzeigen / Verstecken",
                    "low_level_mode": "Low-Level-Modus",
                    "low_level_state_disabled": "Deaktiviert",
                    "low_level_state_enabled": "Aktiviert",
                    "led_state": "LED-Zustand",
                    "led_state_off": "Aus",
                    "led_state_on": "An",
                    "led_state_blinking": "Blinkend",
                    "led_state_flickering": "Flackernd",
                    "led_state_breathing": "Atmend",
                    "cp_pwm_dc": "CP-PWM-Tastverhältnis",
                    "adc_values": "ADC-Werte",
                    "adc_names": "PE-CP, PE-PP",
                    "voltages": "Spannungen",
                    "voltage_names": "PE-CP, PE-PP, Maximalspannung PE-CP",
                    "resistances": "Widerstände",
                    "resistance_names": "PE-CP, PE-PP",
                    "gpios": "GPIOs",
                    "gpio_names_0": "Stromkonfiguration 0, Motorfehler, Gleichstromfehler, Stromkonfiguration 1",
                    "gpio_names_1": "DC-Fehlerstromschutz-Test, Abschaltung, Taster, CP-PWM",
                    "gpio_names_2": "Motoreingangsschalter, Schützsteuerung, Konfigurierbarer Ausgang, CP-Trennung",
                    "gpio_names_3": "Motor aktiv, Motor-Phase, Schützprüfung vorher, Schützprüfung nachher",
                    "gpio_names_4": "Konfigurierbarer Eingang, DC X6, DC X30, LED",
                    "gpio_names_5": "Nicht belegt",
                    "gpio_low": "Low",
                    "gpio_high": "High",
                    "debug": "Ladeprotokoll",
                    "debug_start": "Start",
                    "debug_stop": "Stop + Download",
                    "debug_description": "Ladeprotokoll erstellen",
                    "debug_description_muted": "zur Diagnose bei Ladeproblemen",
                    "settings": "Einstellungen",
                    "charge_management_description": "Lastmanagement",
                    "charge_management_description_muted": "<a href=\"https://www.warp-charger.com/#documents\">siehe Betriebsanleitung für Details</a>",
                    "charge_management_enable": "Erlaubt anderen Wallboxen diese zu steuern",

                    "dc_fault_current_state": "DC-Fehlerstrom&shy;zustand",
                    "dc_fault_current_state_desc": "",
                    "dc_fault_current_ok": "OK",
                    "dc_fault_current_6_ma": "Gleichstromfehler",
                    "dc_fault_current_system": "Systemfehler",
                    "dc_fault_current_unknown": "Unbekannter Fehler",
                    "dc_fault_current_calibration": "Kalibrierungsfehler",
                    "dc_fault_current_reset": "Zurücksetzen",

                    "reset_dc_fault_title": "Zurücksetzen des DC-Fehlerstromschutzmoduls",
                    "reset_dc_fault_content": "Durch das Zurücksetzen des Moduls kann wieder geladen werden. <b>Es muss sichergestellt sein, dass der Grund für das Auslösen des Moduls behoben wurde!</b> <a href=\"https://www.warp-charger.com/#documents\">Siehe Betriebsanleitung für Details.</a> Soll das DC-Fehlerstromschutzmodul wirklich zurückgesetzt werden?",
                    "abort": "Abbrechen",
                    "reset": "Zurücksetzen",

                    "gpio_enable": "Abschalteingang",
                    "gpio_enable_muted": "<a href=\"https://www.warp-charger.com/#documents\">siehe Betriebsanleitung für Details</a>",
                    "gpio_enable_not_configured": "Nicht konfiguriert",
                    "gpio_enable_active_open": "Abschalten wenn geschlossen",
                    "gpio_enable_active_close": "Abschalten wenn geöffnet",
                    "not_configured": "Nicht konfiguriert",
                    "todo": "TODO",
                    "gpio_in": "Konfigurierbarer Eingang",
                    "gpio_in_muted": " ",
                    "gpio_out": "Konfigurierbarer Ausgang",
                    "gpio_out_muted": " ",
                },
                "script": {
                    "error_code": "Fehlercode",
                    "charging_for": "Lädt seit",
                    "last_charge_took": "Letztes Laden dauerte",
                    "set_charging_current_failed": "Konnte Ladestrom nicht setzen",
                    "auto_start_charging_update": "Lade-Autostart setzen fehlgeschlagen.",
                    "start_charging_failed": "Ladestart auslösen fehlgeschlagen",
                    "stop_charging_failed": "Ladestop auslösen fehlgeschlagen",
                    "tab_close_warning": "Die Aufzeichnung des Ladecontroller-Logs wird abgebrochen, wenn der Tab geschlossen wird.",
                    "loading_debug_report": "Lade Debug-Report",
                    "loading_debug_report_failed": "Laden des Debug-Reports fehlgeschlagen",
                    "loading_event_log": "Lade Event-Log",
                    "loading_event_log_failed": "Laden des Event-Logs fehlgeschlagen",
                    "starting_debug": "Aktiviere Aufzeichnung des Ladecontroller-Logs.",
                    "starting_debug_failed": "Aktivierung der Aufzeichung des Ladecontroller-Logs fehlgeschlagen.",
                    "debug_running": "Aufzeichnung läuft. Tab nicht schließen!",
                    "debug_stop_failed": "Stoppen der Aufzeichnung des Ladecontroller-Logs fehlgeschlagen.",
                    "debug_stopped": "Aufzeichung des Ladecontroller-Logs gestoppt.",
                    "debug_done": "Abgeschlossen.",
                    "managed_current_ignored": "ignoriert; Lastmanagement deaktiviert",

                    "by": "durch",
                    "configuration": "Konfiguration",
                    "management": "Lastmanagement",
                    "outgoing": "Ladekabel",
                    "incoming": "Zuleitung",

                    "save_failed": "(De-)Aktivieren des Lastmanagements fehlgeschlagen",
                    "reset_dc_fault_current_failed": "Zurücksetzen des DC-Fehlerstromschutzmoduls fehlgeschlagen"
                }
            }
        },
        "en": {
            "evse": {
                "status": {
                    "evse": "Vehicle state",
                    "not_connected": "Disconnected",
                    "connected": "Connected",
                    "charging": "Charging",
                    "error": "Error",
                    "configured_charging_current": "Configurerd charging current",
                    "allowed_charging_current": "Allowed charging current",
                    "charging_current_minimum": "6 A",
                    "charging_current_maximum": "Max",
                    "charge_control": "Charge control",
                    "auto_start_charging": "Auto-start",
                    "start_charging": "Start",
                    "stop_charging": "Stop"
                },
                "navbar": {
                    "evse": "Charge Controller"
                },
                "content": {
                    "evse": "Charge Controller (EVSE)",
                    "state": "State",
                    "iec_state": "IEC 61851 state",
                    "iec_state_a": "A (disconnected)",
                    "iec_state_b": "B (connected)",
                    "iec_state_c": "C (charging)",
                    "iec_state_d": "D (not supported)",
                    "iec_state_ef": "E/F (error)",
                    "contactor_state": "Contactor check",
                    "contactor_names": "before contactor, after contactor, state",
                    "contactor_not_live": "Not live",
                    "contactor_live": "Live",
                    "contactor_ok": "OK",
                    "contactor_error": "Error",
                    "charge_release": "Charge release",
                    "charge_release_automatic": "Automatic",
                    "charge_release_manual": "Manual",
                    "charge_release_deactivated": "Deactivated",
                    "charge_release_managed": "Managed",
                    "allowed_charging_current": "Allowed charging current",
                    "error_state": "Error state",
                    "error_state_desc": "<a href=\"https://www.warp-charger.com/#documents\">see manual for details</a>",
                    "error_ok": "OK",
                    "error_switch": "Switch error",
                    "error_calibration": "Calibration error",
                    "error_contactor": "Contactor error",
                    "error_communication": "Communication error",
                    "lock_state": "Cable lock",
                    "lock_init": "Init",
                    "lock_open": "Open",
                    "lock_closing": "Closing",
                    "lock_close": "Close",
                    "lock_opening": "Opening",
                    "lock_error": "Error",
                    "time_since_state_change": "Time since state change",
                    "uptime": "Uptime",
                    "configuration": "Hardware configuration",
                    "has_lock_switch": "Cable lock available",
                    "lock_no": "No",
                    "lock_yes": "Yes",
                    "jumper_config_max_current": "Max current of supply cable",
                    "jumper_config": "switch configured",
                    "jumper_config_software": "Software",
                    "jumper_config_unconfigured": "Unconfigured",
                    "charging_current": "Charging current limits",
                    "charging_current_muted": "Minimum of the charging current limits",
                    "charging_current_configured": "Configured",
                    "charging_current_max_incoming": "Supply cable",
                    "charging_current_max_outgoing": "Type 2 cable",
                    "charging_current_managed": "Managed",
                    "low_level_state": "Low Level State",
                    "low_level_state_show": "Show / Hide",
                    "low_level_mode": "Low level mode",
                    "low_level_state_disabled": "Disabled",
                    "low_level_state_enabled": "Enabled",
                    "led_state": "LED state",
                    "led_state_off": "Off",
                    "led_state_on": "On",
                    "led_state_blinking": "Blinking",
                    "led_state_flickering": "Flickering",
                    "led_state_breathing": "Breathing",
                    "cp_pwm_dc": "CP PWM duty cycle",
                    "adc_values": "ADC values",
                    "adc_names": "PE-CP, PE-PP",
                    "voltages": "Voltages",
                    "voltage_names": "PE-CP, PE-PP, high voltage PE-CP",
                    "resistances": "Resistances",
                    "resistance_names": "PE-CP, PE-PP",
                    "gpios": "GPIOs",
                    "gpio_names": "input, output, motor input switch, relay, motor fault",
                    "gpio_low": "Low",
                    "gpio_high": "High",
                    "debug": "Charge log",
                    "debug_start": "Start",
                    "debug_stop": "Stop + download",
                    "debug_description": "Create charge log",
                    "debug_description_muted": "to diagnose charging problems",

                    "settings": "Settings",
                    "charge_management_description": "Charge management",
                    "charge_management_description_muted": "<a href=\"https://www.warp-charger.com/#documents\">see manual for details</a>",
                    "charge_management_enable": "Enables other chargers to control this one",

                },
                "script": {
                    "error_code": "Error code",
                    "charging_for": "Charging for",
                    "last_charge_took": "Last charge took",
                    "set_charging_current_failed": "Failed to set charging current",
                    "auto_start_charging_update": "Failed to set auto charge.",
                    "start_charging_failed": "Failed to start charging",
                    "stop_charging_failed": "Failed to stop charging",
                    "tab_close_warning": "Charge log capture will be aborted if this tab is closed.",
                    "loading_debug_report": "Loading debug report",
                    "loading_debug_report_failed": "Loading debug reprot failed",
                    "loading_event_log": "Loading event log",
                    "loading_event_log_failed": "Loading event log failed",
                    "starting_debug": "Starting charge log capture",
                    "starting_debug_failed": "Starting charge log capture failed.",
                    "debug_running": "Capturing. Don't close tab!",
                    "debug_stop_failed": "Stopping charge log capture failed",
                    "debug_stopped": "Stopped charge log capture",
                    "debug_done": "Done",

                    "by": "by",
                    "configuration": "configuration",
                    "management": "charge management",
                    "outgoing": "charging cable",
                    "incoming": "supply cable",

                    "save_failed": "(De)Activating the charge mananagement failed",
                    "managed_current_ignored": "ignored; Charge management deactivated",
                }
            }
        }
    };
    return translations[lang];
}
