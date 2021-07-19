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
    state: number
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
    default_available_current: number,
    chargers: ChargerConfig[]
}

let charger_state_count = -1;

function update_charge_manager_state(state: ChargeManagerState) {
    if (state.chargers.length != charger_state_count) {
        let charger_content = "";
        let charger_status = "";
        for (let i = 0; i < state.chargers.length; i++) {
            charger_content += `
                <div
                    class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
                    <span class="h3" id="charge_manager_content_charger_${i}_name"></span>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_last_update" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.last_update")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_last_update" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_uptime" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.uptime")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_uptime" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_supported_current" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.supported_current")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_supported_current" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_allowed_current" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.allowed_current")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_allowed_current" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_wants_to_charge" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.wants_to_charge")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_wants_to_charge" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_is_charging" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.is_charging")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_is_charging" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_last_sent_config" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.last_sent_config")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_last_sent_config" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <label for="charge_manager_content_charger_${i}_allocated_current" class="col-lg-3 col-xl-2 col-form-label form-label">${__("charge_manager.content.allocated_current")}</label>
                    <div class="col-lg-9 col-xl-6">
                        <input id="charge_manager_content_charger_${i}_allocated_current" class="form-control" type="text" placeholder="..." readonly>
                    </div>
                </div>`

            if (i % 2 == 0) {
                if (i != 0) {
                    charger_status += '</div>';
                }
                charger_status += '<div class="card-deck mb-4">';
            }

            charger_status += `
            <div class="card">
                <h5 id="charge_manager_status_charger_${i}_name" class="card-header"></h5>
                <div class="card-body">
                    <h5 id="charge_manager_status_charger_${i}_state" class="card-title"></h5>
                    <p id="charge_manager_status_charger_${i}_info" class="card-text"></p>
                </div>
                <div class="card-footer">
                    <small id="charge_manager_status_charger_${i}_update" class="text-muted"></small>
                </div>
            </div>
            `
        }
        charger_status += '</div>';
        $('#charge_manager_content').html(charger_content);
        $('#charge_manager_status_chargers').html(charger_status);
        charger_state_count = state.chargers.length;
        $('#charge_manager_status_controlled_chargers').prop('hidden', charger_state_count == 0);
    }
    for (let i = 0; i < state.chargers.length; i++) {
        const s = state.chargers[i];
        $(`#charge_manager_content_charger_${i}_name`).text(s.name);
        $(`#charge_manager_content_charger_${i}_last_update`).val(util.format_timespan(Math.floor((state.uptime - s.last_update) / 1000)));
        $(`#charge_manager_content_charger_${i}_uptime`).val(util.format_timespan(Math.floor(s.uptime / 1000)));
        $(`#charge_manager_content_charger_${i}_supported_current`).val(util.toLocaleFixed(s.supported_current / 1000.0, 3) + " A (wird noch ignoriert)");
        $(`#charge_manager_content_charger_${i}_allowed_current`).val(util.toLocaleFixed(s.allowed_current / 1000.0, 3) + " A");
        $(`#charge_manager_content_charger_${i}_wants_to_charge`).val(s.wants_to_charge.toString());
        $(`#charge_manager_content_charger_${i}_is_charging`).val(s.is_charging.toString());
        $(`#charge_manager_content_charger_${i}_last_sent_config`).val(util.format_timespan(Math.floor((state.uptime - s.last_sent_config) / 1000)));
        $(`#charge_manager_content_charger_${i}_allocated_current`).val(util.toLocaleFixed(s.allocated_current / 1000.0, 3) + " A");

        $(`#charge_manager_status_charger_${i}_name`).text(s.name);
        $(`#charge_manager_status_charger_${i}_state`).text(__(`charge_manager.script.charge_state_${s.state}`));

        $(`#charge_manager_status_charger_${i}_info`).text(util.toLocaleFixed(s.allocated_current / 1000.0, 3) + " " + __("charge_manager.script.ampere_allocated"));

        let last_update = Math.floor((state.uptime - s.last_update) / 1000);
        $(`#charge_manager_status_charger_${i}_update`).text(__("charge_manager.script.last_update_prefix") +  util.format_timespan(last_update) + (__("charge_manager.script.last_update_suffix")));
        $(`#charge_manager_status_charger_${i}_update`).prop("hidden", last_update == 0);
    }

    util.update_button_group("btn_group_charge_manager_state", state.state);
}

let charger_config_count = -1;

function update_charge_manager_config(config: ChargeManagerConfig) {
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
                        <div class="card-footer">
                            <small id="charge_manager_status_charger_${i}_update" class="text-muted">Unterstützter Strom: (noch nicht implementiert)</small>
                        </div>
                    </div>
                </div>`;
        }
        charger_configs += `<div class="col mb-4">
        <div class="card h-100">
            <div class="card-header d-flex justify-content-between align-items-center">
                <span class="h5" style="margin-bottom: 0">Wallbox hinzufügen</span>
                <button type="button" class="btn btn-sm btn-outline-secondary" style="visibility: hidden;">
                        <span data-feather="trash-2"></span>
                </button>
            </div>
            <div class="card-body">
                <button id="charge_manager_add_charger" type="button" class="btn btn-light btn-lg btn-block" style="height: 100%;" data-toggle="modal" data-target="#charge_manager_add_charger_modal"><span data-feather="plus-circle"></span></button>
            </div>
            <div class="card-footer">
                <small class="text-muted" style="visibility: hidden;">Unterstützter Strom: (noch nicht implementiert)</small>
            </div>
        </div>
    </div>`;
        $('#charge_manager_configs').html(charger_configs);
        charger_config_count = config.chargers.length;
        feather.replace();
        for (let i = 0; i < config.chargers.length; i++) {
            $(`#charge_manager_content_${i}_remove`).on("click", () => save_charge_manager_config(null, i));
        }
    }
    console.log("start");
    for (let i = 0; i < config.chargers.length; i++) {
        console.log("hier", i);
        const s = config.chargers[i];
        console.log(s);
        $(`#charge_manager_config_charger_${i}_name`).html(s.name);
        $(`#charge_manager_config_charger_${i}_host`).val(s.host);
    }

    $('#charge_manager_enable').prop("checked", config.enable_charge_manager);
    $('#charge_manager_default_available_current').val(util.toLocaleFixed(config.default_available_current / 1000, 3));
}

function save_charge_manager_config(new_charger: ChargerConfig = null, remove_charger: number = null) {
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

    let payload: ChargeManagerConfig = {
       enable_charge_manager: $('#charge_manager_enable').is(':checked'),
       default_available_current: Math.round(<number>$('#charge_manager_default_available_current').val() * 1000),
       chargers: chargers
    };

    $.ajax({
        url: '/charge_manager/config_update',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify(payload),
        success: () => $('#charge_manager_reboot').modal('show'),
        error: (xhr, status, error) => util.show_alert("alert-danger", __("charge_manager.script.save_failed"), error + ": " + xhr.responseText)
    });
}

function charge_manager_save_reboot() {
    $('#charge_manager_reboot').modal('hide');
    util.reboot();
}

export function init() {
    (<HTMLButtonElement>document.getElementById("charge_manager_reboot_button")).addEventListener("click", charge_manager_save_reboot);

    let form = <HTMLFormElement>$('#charge_manager_config_form')[0];
    form.addEventListener('submit', function (event: Event) {
        form.classList.add('was-validated');
        event.preventDefault();
        event.stopPropagation();

        if (form.checkValidity() === false) {
            return;
        }

        save_charge_manager_config(null, null);
    }, false);

    $('#charge_manager_save_charger').on("click", () => {
        let form = <HTMLFormElement>$('#charge_manager_add_charger_form')[0];
        if (form.checkValidity() === false) {
            return;
        }

        $('#charge_manager_add_charger_modal').modal('hide');

        save_charge_manager_config({
            host: $(`#charge_manager_config_charger_new_host`).val().toString(),
            name: $(`#charge_manager_config_charger_new_name`).val().toString(),
        }, null);
    });
}

export function addEventListeners(source: EventSource) {
    source.addEventListener('charge_manager/state', function (e: util.SSE) {
        update_charge_manager_state(<ChargeManagerState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('charge_manager/config', function (e: util.SSE) {
        update_charge_manager_config(<ChargeManagerConfig>(JSON.parse(e.data)));
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
                    "managed_boxes": "Kontrollierte Wallboxen"
                },
                "navbar": {
                    "charge_manager": "Lastmanager"
                },
                "content": {
                    "charge_manager": "Lastmanager",
                    "enable_charge_manager": "Lastmanager aktivieren",
                    "enable_charge_manager_desc": "<a href=\"https://www.warp-charger.com/#documents\">siehe Betriebsanleitung für Details</a></span>",
                    "default_available_current": "Verfügbarer Strom",
                    "save": "Speichern",
                    "managed_boxes": "Kontrollierte Wallboxen",
                    "state": "Zustand",
                    "charger": "Wallbox",
                    "last_update": "Letztes Update vor",
                    "uptime": "Laufzeit",
                    "supported_current": "Unterstützter Strom",
                    "allowed_current": "Erlaubter Strom",
                    "wants_to_charge": "Wartet auf Manager",
                    "is_charging": "Lädt",
                    "last_sent_config": "Letzte Stromzuweisung vor",
                    "allocated_current": "zugeteilter Strom",
                    "unchanged": "unverändert",
                    "low_level_state": "Low-Level-Zustand",
                    "low_level_state_show": "Anzeigen / Verstecken",

                    "add_charger_modal_title": "Wallbox hinzufügen",
                    "add_charger_modal_name": "Anzeigename",
                    "add_charger_modal_host": "IP-Adresse (Hostnamen werden noch nicht unterstützt)",
                    "add_charger_modal_abort": "Verwerfen",
                    "add_charger_modal_save": "Speichern",

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
                    "ampere_allocated": "Ampere zugeteilt",
                    "last_update_prefix": "Letztes Update vor ",
                    "last_update_suffix": " ",
                    "save_failed": "Speichern der Lastmanager-Konfiguration fehlgeschlagen"
                }
            }
        },
        "en": {
            "charge_manager": {
                "status": {
                    "charge_manager": "Charge Manager",
                    "not_configured": "Not configured",
                    "manager": "Active",
                    "error": "Error",
                    "managed_boxes": "Managed Chargers"
                },
                "navbar": {
                    "charge_manager": "Charge Manager"
                },
                "content": {
                    "charge_manager": "Charge Manager",
                    "state": "State",
                    "charger": "Charger",
                    "last_update": "Last Update",
                    "uptime": "Uptime",
                    "supported_current": "Supported current",
                    "allowed_current": "Allowed current",
                    "wants_to_charge": "Waiting for manager",
                    "is_charging": "Is charging",
                    "last_sent_config": "Last sent config",
                    "allocated_current": "Allocated current",
                    "low_level_state": "Low Level State",
                    "low_level_state_show": "Show / Hide",

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

                    "default_available_current": "Available current",
                    "enable_charge_manager": "Enable charge manager",
                    "enable_charge_manager_desc": "<a href=\"https://www.warp-charger.com/#documents\">see manual for details</a>",
                    "managed_boxes": "Managed chargers",

                },
                "script": {
                    "charge_state_0": "No vehicle connected",
                    "charge_state_1": "Waiting for user release",
                    "charge_state_2": "Waiting for manager release",
                    "charge_state_3": "Charging cleared",
                    "charge_state_4": "Charging",
                    "charge_state_5": "Error",
                    "ampere_allocated": "Ampere allocated",
                    "last_update_prefix": "Last update ",
                    "last_update_suffix": " ago",
                    "save_failed": "Failed to save the charge manager configuration"
                }
            }
        }
    };
    return translations[lang];
}

