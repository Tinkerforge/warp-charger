/* warp-charger
 * Copyright (C) 2021 Erik Fleckstein <erik@tinkerforge.com>
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

interface Charger {
    name: string,
    last_update: number,
    uptime: number,
    supported_current: number,
    allowed_current: number,
    wants_to_charge: boolean,
    is_charging: boolean,
    last_sent_config: number,
    allocated_current: number,
    state: number,
    error: number
}

interface ChargeManagerState {
    state: number,
    uptime: number,
    chargers: Charger[]
}

interface ChargerConfig {
    host: string,
    name: string
}

interface ChargeManagerConfig {
    enable_charge_manager: boolean,
    enable_watchdog: boolean,
    verbose: boolean,
    default_available_current: number,
    maximum_available_current: number,
    minimum_current: number,
    chargers: ChargerConfig[]
}

let charger_state_count = -1;

function update_charge_manager_state(state: ChargeManagerState) {
    if (state.chargers.length != charger_state_count) {
        let charger_content = "";
        let charger_status = "";
        for (let i = 0; i < state.chargers.length; i++) {
            if (i % 2 == 0) {
                if (i != 0) {
                    charger_status += '</div>';
                }
                charger_status += '<div class="card-deck mb-4">';
            }

            charger_status += `
            <div class="card">
                <h5 id="charge_manager_status_charger_${i}_name" class="card-header"></h5>
                <div id="charge_manager_status_charger_${i}_body" class="card-body">
                    <h5 id="charge_manager_status_charger_${i}_state" class="card-title"></h5>
                    <p id="charge_manager_status_charger_${i}_info" class="card-text"></p>
                </div>
                <div class="card-footer">
                    <small id="charge_manager_status_charger_${i}_details"></small>
                </div>
            </div>
            `
        }
        charger_status += '</div>';
        $('#charge_manager_content').html(charger_content);
        $('#charge_manager_status_chargers').html(charger_status);
        charger_state_count = state.chargers.length;
        $('#charge_manager_status_controlled_chargers').prop('hidden', charger_state_count == 0);
        $('#charge_manager_status_available_current_form').prop('hidden', charger_state_count == 0);
    }
    for (let i = 0; i < state.chargers.length; i++) {
        const s = state.chargers[i];

        $(`#charge_manager_status_charger_${i}_name`).text(s.name);
        if (s.state != 5) {
            if (state.state == 2) {
                $(`#charge_manager_status_charger_${i}_body`).addClass("bg-danger text-white bg-disabled");
                $(`#charge_manager_status_charger_${i}_state`).text(__("charge_manager.script.charge_state_blocked_by_other_box"));
                $(`#charge_manager_status_charger_${i}_info`).text(__("charge_manager.script.charge_state_blocked_by_other_box_details"));
            } else {
                $(`#charge_manager_status_charger_${i}_body`).removeClass("bg-danger text-white bg-disabled");
                $(`#charge_manager_status_charger_${i}_state`).text(__(`charge_manager.script.charge_state_${s.state}`));
                $(`#charge_manager_status_charger_${i}_info`).text(util.toLocaleFixed(s.allocated_current / 1000.0, 3) + " " + __("charge_manager.script.ampere_allocated"));
            }
        }
        else {
            if (s.error < 192)
                $(`#charge_manager_status_charger_${i}_state`).text(__("charge_manager.script.charge_error_type_management"));
            else
                $(`#charge_manager_status_charger_${i}_state`).text(__("charge_manager.script.charge_error_type_client"));

            $(`#charge_manager_status_charger_${i}_body`).addClass("bg-danger text-white bg-disabled");
            $(`#charge_manager_status_charger_${i}_info`).text(__(`charge_manager.script.charge_error_${s.error}`));
        }

        let last_update = Math.floor((state.uptime - s.last_update) / 1000);
        let status_text = util.toLocaleFixed(s.supported_current / 1000.0, 3) + " " + __("charge_manager.script.ampere_supported");

        if (last_update >= 10)
            status_text += "; " + __("charge_manager.script.last_update_prefix") + util.format_timespan(last_update) + (__("charge_manager.script.last_update_suffix"));
        $(`#charge_manager_status_charger_${i}_details`).text(status_text);
    }

    util.update_button_group("btn_group_charge_manager_state", state.state);
}

let charger_config_count = -1;

function set_available_current(current: number) {
    $('#charge_manager_status_available_current_save').prop("disabled", true);
    $.ajax({
        url: '/charge_manager/available_current_update',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify({"current": current}),
        success: () => {
            $('#charge_manager_status_available_current_save').html(feather.icons.check.toSvg());
        },
        error: (xhr, status, error) => {
            $('#charge_manager_status_available_current_save').prop("disabled", false);
            util.add_alert("charge_manager_set_available_current_failed", "alert-danger", __("charge_manager.script.set_available_current_failed"), error + ": " + xhr.responseText);
        }
    });
}

function update_available_current(current: number) {
    if($('#charge_manager_status_available_current_save').prop("disabled")) {
        util.setNumericInput("charge_manager_status_available_current", current / 1000, 3);
    }
}

function update_charge_manager_config(config: ChargeManagerConfig, force: boolean) {
    $('#charge_manager_status_available_current').prop("max", config.maximum_available_current / 1000.0);
    $("#charge_manager_status_available_current_maximum").on("click", () => set_available_current(config.default_available_current));
    $('#charge_manager_status_available_current_maximum').html(util.toLocaleFixed(config.default_available_current / 1000.0, 0) + " A");

    update_available_current(config.default_available_current);

    if (!force && !$('#charge_manager_save_button').prop("disabled"))
        return;

    $('#charge_manager_enable').prop("checked", config.enable_charge_manager);
    $('#charge_manager_enable_watchdog').prop("checked", config.enable_watchdog);
    $('#charge_manager_verbose').prop("checked", config.verbose);
    util.setNumericInput("charge_manager_default_available_current", config.default_available_current / 1000, 3);
    util.setNumericInput("charge_manager_maximum_available_current", config.maximum_available_current / 1000, 3);
    util.setNumericInput("charge_manager_minimum_current", config.minimum_current / 1000, 3);

    if (config.chargers.length != charger_config_count) {
        let charger_configs = "";
        for (let i = 0; i < config.chargers.length; i++) {
            charger_configs += `<div class="col mb-4">
                    <div class="card h-100">
                        <div class="card-header d-flex justify-content-between align-items-center">
                            <span class="h5" id="charge_manager_config_charger_${i}_name" style="margin-bottom: 0"></span>
                            <button type="button" class="btn btn-sm btn-outline-secondary"
                                id="charge_manager_content_${i}_remove">
                                <span data-feather="trash-2"></span>
                            </button>
                        </div>

                        <div class="card-body">
                            <div class="form-group">
                                <label for="charge_manager_config_charger_${i}_host">Host</label>
                                <input type="text" class="form-control" id="charge_manager_config_charger_${i}_host">
                            </div>
                        </div>
                    </div>
                </div>`;
        }
        charger_configs += `<div class="col mb-4">
        <div class="card h-100">
            <div class="card-header d-flex justify-content-between align-items-center">
                <span class="h5" style="margin-bottom: 0">${__("charge_manager.script.add_wallbox")}</span>
                <button type="button" class="btn btn-sm btn-outline-secondary" style="visibility: hidden;">
                        <span data-feather="trash-2"></span>
                </button>
            </div>
            <div class="card-body">
                <button id="charge_manager_add_charger" type="button" class="btn btn-light btn-lg btn-block" style="height: 100%;" data-toggle="modal" data-target="#charge_manager_add_charger_modal"><span data-feather="plus-circle"></span></button>
                <span id="charge_manager_add_charger_disabled" hidden>${__("charge_manager.script.add_charger_disabled")}</span>
            </div>
        </div>
    </div>`;
        $('#charge_manager_configs').html(charger_configs);
        charger_config_count = config.chargers.length;
        feather.replace();
        for (let i = 0; i < config.chargers.length; i++) {
            $(`#charge_manager_content_${i}_remove`).on("click", () => {
                $('#charge_manager_save_button').prop("disabled", false);
                update_charge_manager_config(collect_charge_manager_config(null, i), true);
            });
        }
    }

    $('#charge_manager_add_charger').prop("hidden", config.chargers.length >= 10);
    $('#charge_manager_add_charger_disabled').prop("hidden", config.chargers.length < 10);

    for (let i = 0; i < config.chargers.length; i++) {
        const s = config.chargers[i];
        $(`#charge_manager_config_charger_${i}_name`).html(s.name);
        $(`#charge_manager_config_charger_${i}_host`).val(s.host);
    }
}

function collect_charge_manager_config(new_charger: ChargerConfig = null, remove_charger: number = null) : ChargeManagerConfig {
    let chargers: ChargerConfig[] = [];
    for(let i = 0; i < charger_config_count; ++i) {
        if (remove_charger !== null && i == remove_charger)
            continue;
        let c: ChargerConfig = {
            host: $(`#charge_manager_config_charger_${i}_host`).val().toString(),
            name: $(`#charge_manager_config_charger_${i}_name`).html().toString(),
        }
        chargers.push(c);
    }
    if (new_charger != null)
        chargers.push(new_charger);

    return {
       enable_charge_manager: $('#charge_manager_enable').is(':checked'),
       enable_watchdog: $('#charge_manager_enable_watchdog').is(':checked'),
       verbose: $('#charge_manager_verbose').is(':checked'),
       default_available_current: Math.round(<number>$('#charge_manager_default_available_current').val() * 1000),
       maximum_available_current: Math.round(<number>$('#charge_manager_maximum_available_current').val() * 1000),
       minimum_current: Math.round(<number>$('#charge_manager_minimum_current').val() * 1000),
       chargers: chargers
    };
}

function save_charge_manager_config() {
    let payload = collect_charge_manager_config();

    $.ajax({
        url: '/charge_manager/config_update',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify(payload),
        success: () => {
            $('#charge_manager_save_button').prop("disabled", true);
            $('#charge_manager_reboot').modal('show');
        },
        error: (xhr, status, error) => util.add_alert("charge_manager_config_update_failed", "alert-danger", __("charge_manager.script.save_failed"), error + ": " + xhr.responseText)
    });
}

function charge_manager_save_reboot() {
    $('#charge_manager_reboot').modal('hide');
    util.reboot();
}

export function init() {
    (<HTMLButtonElement>document.getElementById("charge_manager_reboot_button")).addEventListener("click", charge_manager_save_reboot);

    let form = <HTMLFormElement>$('#charge_manager_config_form')[0];
    form.addEventListener('input', function (event: Event) {
        $('#charge_manager_save_button').prop("disabled", false);
    }, false);

    form.addEventListener('submit', function (event: Event) {
        $('#charge_manager_default_available_current').prop("max", $('#charge_manager_maximum_available_current').val());

        form.classList.add('was-validated');
        event.preventDefault();
        event.stopPropagation();

        if (form.checkValidity() === false) {
            return;
        }

        save_charge_manager_config();
    }, false);

    $('#charge_manager_save_charger').on("click", () => {
        let form = <HTMLFormElement>$('#charge_manager_add_charger_form')[0];

        if (form.checkValidity() === false) {
            return;
        }

        $('#charge_manager_add_charger_modal').modal('hide');
        $('#charge_manager_save_button').prop("disabled", false);

        let new_config = collect_charge_manager_config({
            host: $(`#charge_manager_config_charger_new_host`).val().toString(),
            name: $(`#charge_manager_config_charger_new_name`).val().toString(),
        }, null);

        update_charge_manager_config(new_config, true);
    });

    $("#charge_manager_status_available_current_minimum").on("click", () => set_available_current(0));

    let input = $('#charge_manager_status_available_current');
    let save_btn = $('#charge_manager_status_available_current_save');
    input.on("input", () => {
        save_btn.html(feather.icons.save.toSvg());
        save_btn.prop("disabled", false);
    });


    let form2 = <HTMLFormElement>$('#charge_manager_status_available_current_form')[0];

    form2.addEventListener('submit', function (event: Event) {
        event.preventDefault();
        event.stopPropagation();

        if (form.checkValidity() === false) {
            return;
        }

        set_available_current(Math.round(<number>input.val() * 1000));
    }, false);
}

export function addEventListeners(source: EventSource) {
    source.addEventListener('charge_manager/state', function (e: util.SSE) {
        update_charge_manager_state(<ChargeManagerState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('charge_manager/config', function (e: util.SSE) {
        update_charge_manager_config(<ChargeManagerConfig>(JSON.parse(e.data)), false);
    }, false);

    source.addEventListener('charge_manager/available_current', function (e: util.SSE) {
        update_available_current(JSON.parse(e.data)["current"]);
    }, false);
}

export function updateLockState(module_init: any) {
    $('#sidebar-charge_manager').prop('hidden', !module_init.charge_manager);
}

export function getTranslation(lang: string) {
    const translations: {[index: string]:any} = {
        "de": {
            "charge_manager": {
                "status": {
                    "charge_manager": "Lastmanager",
                    "not_configured": "Unkonfiguriert",
                    "manager": "Aktiv",
                    "error": "Fehler",
                    "managed_boxes": "Kontrollierte Wallboxen",
                    "available_current": "Verfügbarer Strom",
                    "available_current_minimum": "0 A",
                    "available_current_maximum": "...",
                },
                "navbar": {
                    "charge_manager": "Lastmanager"
                },
                "content": {
                    "charge_manager": "Lastmanager",
                    "enable_charge_manager": "Lastmanager aktivieren",
                    "enable_charge_manager_desc": "<a href=\"https://www.warp-charger.com/#documents\">siehe Betriebsanleitung für Details</a>",
                    "enable_watchdog": "Watchdog aktivieren",
                    "enable_watchdog_desc": "Setzt den verfügbaren Strom auf die Voreinstellung, wenn er nicht spätestens alle 30 Sekunden aktualisiert wurde.",
                    "verbose": "Stromverteilung protokollieren",
                    "verbose_desc": "Erzeugt Einträge im Ereignis-Log, wenn Strom umverteilt wird.",
                    "default_available_current": "<span class=\"form-label pr-2\">Voreingestellt verfügbarer Strom</span><span class=\"text-muted\">wird nach Neustart des Lastmanagers verwendet</span>",
                    "default_available_current_invalid": "Der voreingestellt verfügbare Strom darf maximal so groß sein wie der maximale verfügbare Strom!",
                    "maximum_available_current": "<span class=\"form-label pr-2\">Maximal verfügbarer Strom</span><span class=\"text-muted\">verfügbarer Strom kann über Webinterface und API nur bis zu diesem Wert eingestellt werden</span>",
                    "minimum_current": "<span class=\"form-label pr-2\">Minimaler Ladestrom</span><span class=\"text-muted\">muss mindestens verfügbar sein, damit eine Wallbox lädt</span>",
                    "save": "Speichern",
                    "managed_boxes": "Kontrollierte Wallboxen",

                    "add_charger_modal_title": "Wallbox hinzufügen",
                    "add_charger_modal_name": "Anzeigename",
                    "add_charger_modal_host": "IP-Adresse (Hostnamen werden noch nicht unterstützt)",
                    "add_charger_modal_abort": "Verwerfen",
                    "add_charger_modal_save": "Hinzufügen",

                    "reboot_title": "Neu starten um Konfiguration anzuwenden",
                    "reboot_content": "Die geänderten Lastmanagement-Einstellungen werden nur nach einem Neustart angewendet. Jetzt neu starten?",
                    "abort": "Abbrechen",
                    "reboot": "Neu starten",
                },
                "script": {
                    "charge_state_0": "Kein Fahrzeug angeschlossen",
                    "charge_state_1": "Warte auf Nutzerfreigabe",
                    "charge_state_2": "Warte auf Manager-Freigabe",
                    "charge_state_3": "Laden freigegeben",
                    "charge_state_4": "Lädt",
                    "charge_state_5": "Fehler",
                    "charge_state_6": "Laden abgeschlossen",

                    "charge_error_type_management": "Managementfehler",
                    "charge_error_type_client": "Wallbox-Fehler",

                    "charge_error_0": "OK",
                    "charge_error_1": "Kommunikationsfehler",
                    "charge_error_2": "Firmware inkompatibel",
                    "charge_error_3": "Lastmanagement deaktiviert",
                    "charge_error_128": "Wallbox nicht erreichbar",
                    "charge_error_129": "Ladecontroller nicht erreichbar",
                    "charge_error_130": "Ladecontroller reagiert nicht",

                    "charge_error_192": "OK",
                    "charge_error_193": "Schalterfehler",
                    "charge_error_194": "DC-Fehlerstromschutzfehler",
                    "charge_error_195": "Schützfehler",
                    "charge_error_196": "Fahrzeug-Kommunikationsfehler",

                    "charge_state_blocked_by_other_box": "Blockiert",
                    "charge_state_blocked_by_other_box_details": "Fehler bei anderer Wallbox",

                    "ampere_allocated": "A zugeteilt",
                    "ampere_supported": "A unterstützt",
                    "last_update_prefix": "Gestört seit ",
                    "last_update_suffix": " ",
                    "save_failed": "Speichern der Lastmanager-Konfiguration fehlgeschlagen",
                    "set_available_current_failed": "Setzen des verfügbaren Stroms fehlgeschlagen",
                    "add_wallbox": "Wallbox hinzufügen",
                    "add_charger_disabled": "Es werden nur bis zu 10 Wallboxen unterstützt."
                }
            }
        },
        "en": {
            "charge_manager": {
                "status": {
                    "charge_manager": "Charge manager",
                    "not_configured": "Not configured",
                    "manager": "Active",
                    "error": "Error",
                    "managed_boxes": "Managed chargers",
                    "available_current": "Available current",
                    "available_current_minimum": "0 A",
                    "available_current_maximum": "...",
                },
                "navbar": {
                    "charge_manager": "Charge Manager"
                },
                "content": {
                    "charge_manager": "Charge Manager",
                    "enable_charge_manager": "Enable charge manager",
                    "enable_charge_manager_desc": "<a href=\"https://www.warp-charger.com/#documents\">see manual for details</a>",
                    "enable_watchdog": "Enable watchdog",
                    "enable_watchdog_desc": "Sets the available current to the default value if it is not updated every 30 seconds.",
                    "verbose": "Log current distribution",
                    "verbose_desc": "Creates log entries whenever current is redistributed.",
                    "default_available_current": "<span class=\"form-label pr-2\">Default available current</span><span class=\"text-muted\">will be used after charge manager reboot</span>",
                    "default_available_current_invalid": "The default available current can at most be as much as the maximum available current!",
                    "maximum_available_current": "<span class=\"form-label pr-2\">Maximum available current</span><span class=\"text-muted\">available current can only be set to at most this value using the API and web interface</span>",
                    "minimum_current": "<span class=\"form-label pr-2\">Minimal charge current</span><span class=\"text-muted\">must be available to start a charger</span>",

                    "add_charger_modal_title": "Add charger",
                    "add_charger_modal_name": "Display name",
                    "add_charger_modal_host": "IP Address (Hostnames are not supported yet)",
                    "add_charger_modal_abort": "Discard",
                    "add_charger_modal_save": "Save",

                    "reboot_title": "Restart to apply configuration",
                    "reboot_content": "The modified Charge manager configuration will only be applied after a restart. Reboot now?",
                    "abort": "Abort",
                    "reboot": "Reboot",
                    "save": "Save",

                    "managed_boxes": "Managed chargers",

                },
                "script": {
                    "charge_state_0": "No vehicle connected",
                    "charge_state_1": "Waiting for user release",
                    "charge_state_2": "Waiting for manager release",
                    "charge_state_3": "Charging cleared",
                    "charge_state_4": "Charging",
                    "charge_state_5": "Error",
                    "charge_state_6": "Charging done",

                    "charge_error_type_management": "Management error",
                    "charge_error_type_client": "Charger error",

                    "charge_error_0": "OK",
                    "charge_error_1": "Communication error",
                    "charge_error_2": "Firmware incompatible",
                    "charge_error_3": "Charge management deactivated",
                    "charge_error_128": "Charger unreachable",
                    "charge_error_129": "EVSE unreachable ",
                    "charge_error_130": "EVSE does not react",

                    "charge_error_192": "OK",
                    "charge_error_193": "Switch error",
                    "charge_error_194": "DC fault protector error",
                    "charge_error_195": "Contactor error",
                    "charge_error_196": "Vehicle communication error",

                    "charge_state_blocked_by_other_box": "Blocked",
                    "charge_state_blocked_by_other_box_details": "Error with another charger",

                    "ampere_allocated": "A allocated",
                    "ampere_supported": "A supported",

                    "last_update_prefix": "Unavailable since",
                    "last_update_suffix": "",
                    "save_failed": "Failed to save the charge manager configuration",
                    "set_available_current_failed": "Failed to set the available current",
                    "add_wallbox": "Add charger",
                    "add_charger_disabled": "Only up to 10 chargers are supported."
                }
            }
        }
    };
    return translations[lang];
}

