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

interface NFCState {
    detected_tags: boolean[],
}

function update_nfc_state(state: NFCState) {

}

interface AuthorizedTag {
    tag_name: string,
    tag_type: number,
    tag_id: number[]
}

interface NFCConfig {
    require_tag_to_start: boolean,
    require_tag_to_stop: boolean,
    authorized_tags: AuthorizedTag[]
}

let authorized_tag_count = -1;

function toHexBytes(lst: number[]) {
    return lst.map((x) => {
        let r = x.toString(16).toUpperCase();
        return r.length == 1 ? "0" + r: r;
    }).slice(0, 7).join(":");
}

function fromHexBytes(s: string) {
    return s.split(":").map((x) => parseInt(x, 16));
}

function update_nfc_config(cfg: NFCConfig, force: boolean) {
    if (!force && !$('#nfc_save_button').prop('disabled'))
        return;

    $('#nfc_require_tag_to_start').prop("checked", cfg.require_tag_to_start);
    $('#nfc_require_tag_to_stop').prop("checked", cfg.require_tag_to_stop);

    if (cfg.authorized_tags.length != authorized_tag_count) {
        let authorized_tags = "";
        for (let i = 0; i < cfg.authorized_tags.length; i++) {
            authorized_tags += `<div class="col mb-4">
                    <div class="card h-100">
                        <div class="card-header d-flex justify-content-between align-items-center">
                            <span class="h5" id="nfc_authorized_tag_${i}_tag_id" style="margin-bottom: 0"></span>
                            <button type="button" class="btn btn-sm btn-outline-secondary"
                                id="nfc_authorized_tag_${i}_remove">
                                <span data-feather="trash-2"></span>
                            </button>
                        </div>

                        <div class="card-body">
                            <div class="form-group">
                                <label for="nfc_authorized_tag_${i}_tag_name" class="form-label">${__("nfc.script.tag_name")}</label>
                                <input type="text" class="form-control" id="nfc_authorized_tag_${i}_tag_name" class="form-label">
                            </div>
                            <div class="form-group">
                                <label for="nfc_authorized_tag_${i}_tag_type" class="form-label">${__("nfc.script.tag_type")}</label>
                                <select id="nfc_authorized_tag_${i}_tag_type" class="form-control">
                                    <option value="0">${__("nfc.content.type_0")}</option>
                                    <option value="1">${__("nfc.content.type_1")}</option>
                                    <option value="2">${__("nfc.content.type_2")}</option>
                                    <option value="3">${__("nfc.content.type_3")}</option>
                                    <option value="4">${__("nfc.content.type_4")}</option>
                                </select>
                            </div>
                        </div>
                        <div class="card-footer">
                            <small id="nfc_authorized_tag_${i}_last_seen" style="visibility: hidden;">${__("nfc.script.last_seen_unknown")}</small>
                        </div>
                    </div>
                </div>`;
        }
        authorized_tags += `<div class="col mb-4">
        <div class="card h-100">
            <div class="card-header d-flex justify-content-between align-items-center">
                <span class="h5" style="margin-bottom: 0">${__("nfc.script.add_tag")}</span>
                <button type="button" class="btn btn-sm btn-outline-secondary" style="visibility: hidden;">
                        <span data-feather="trash-2"></span>
                </button>
            </div>
            <div class="card-body">
                <button id="nfc_add_charger" type="button" class="btn btn-light btn-lg btn-block" style="height: 100%;" data-toggle="modal" data-target="#nfc_add_tag_modal"><span data-feather="plus-circle"></span></button>
            </div>
            <div class="card-footer">
                <small style="visibility: hidden;">Zuletzt gesehen: blah</small>
            </div>
        </div>
    </div>`;
        $('#nfc_authorized_tags').html(authorized_tags);
        authorized_tag_count = cfg.authorized_tags.length;
        feather.replace();
        for (let i = 0; i < cfg.authorized_tags.length; i++) {
            $(`#nfc_authorized_tag_${i}_remove`).on("click", () => {
                $('#nfc_save_button').prop("disabled", false);
                update_nfc_config(collect_nfc_config(null, i), true)
            });
        }
    }

    for (let i = 0; i < cfg.authorized_tags.length; i++) {
        const s = cfg.authorized_tags[i];
        $(`#nfc_authorized_tag_${i}_tag_name`).val(s.tag_name);
        $(`#nfc_authorized_tag_${i}_tag_type`).val(s.tag_type);
        $(`#nfc_authorized_tag_${i}_tag_id`).html(toHexBytes(s.tag_id));
    }
}

function collect_nfc_config(new_tag: AuthorizedTag = null, remove_tag: number = null) : NFCConfig {
    let tags: AuthorizedTag[] = [];
    for(let i = 0; i < authorized_tag_count; ++i) {
        if (remove_tag !== null && i == remove_tag)
            continue;
        let c: AuthorizedTag = {
            tag_type: parseInt($(`#nfc_authorized_tag_${i}_tag_type`).val().toString()),
            tag_name: $(`#nfc_authorized_tag_${i}_tag_name`).val().toString(),
            tag_id: fromHexBytes($(`#nfc_authorized_tag_${i}_tag_id`).html().toString())
        }
        tags.push(c);
    }
    if (new_tag != null)
        tags.push(new_tag);

    return {
        require_tag_to_start: $('#nfc_require_tag_to_start').prop("checked"),
        require_tag_to_stop: $('#nfc_require_tag_to_stop').prop("checked"),
        authorized_tags: tags
    };
}

function save_nfc_config() {
    let payload = collect_nfc_config();

    $.ajax({
        url: '/nfc/config_update',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify(payload),
        success: () => {
            $('#nfc_save_button').prop("disabled", true);
            $('#nfc_reboot').modal('show');
        },
        error: (xhr, status, error) => util.add_alert("nfc_config_update_failed", "alert-danger", __("nfc.script.save_failed"), error + ": " + xhr.responseText)
    });
}

interface NFCSeenTag {
    tag_type: number,
    tag_id: number[]
    last_seen: number
}

let unauth_tag_list_length = 0;
function update_nfc_seen_tags(seen_tags: NFCSeenTag[]) {
    let current_nfc_config = collect_nfc_config(null, null);

    let unauth_seen_tags: NFCSeenTag[] = [];

    let auth_seen_tags: NFCSeenTag[] = [];
    let auth_seen_ids: number[] = [];

outer_loop:
    for(let i = 0; i < seen_tags.length; ++i) {
        if (seen_tags[i].tag_id.every((x) => x == 0))
            break;

        for (let auth_tag_idx = 0; auth_tag_idx < current_nfc_config.authorized_tags.length; ++auth_tag_idx) {
            let auth_tag = current_nfc_config.authorized_tags[auth_tag_idx];
            if (auth_tag.tag_type != seen_tags[i].tag_type)
                continue;

            if (auth_tag.tag_id.length != seen_tags[i].tag_id.length)
                continue;

            if (auth_tag.tag_id.some((y, j, _array) => y != seen_tags[i].tag_id[j]))
                continue;

            auth_seen_tags.push(seen_tags[i]);
            auth_seen_ids.push(auth_tag_idx);

            continue outer_loop;
        }

        unauth_seen_tags.push(seen_tags[i]);
    }

    for(let i = 0; i < auth_seen_tags.length; ++i) {
        $(`#nfc_authorized_tag_${auth_seen_ids[i]}_last_seen`).prop("style",  "");
        $(`#nfc_authorized_tag_${auth_seen_ids[i]}_last_seen`).text(__("nfc.content.last_seen") + util.format_timespan(Math.floor(auth_seen_tags[i].last_seen / 1000)));
    }

    for (let i = 0; i < current_nfc_config.authorized_tags.length; ++i) {
        if (auth_seen_ids.includes(i))
            continue;
        $(`#nfc_authorized_tag_${i}_last_seen`).prop("style",  "visibility: hidden;");
    }

    if (unauth_seen_tags.length < unauth_tag_list_length) {
        $('#nfc_seen_tags > button').slice(unauth_seen_tags.length).remove();
        unauth_tag_list_length = unauth_seen_tags.length;
    }

    while (unauth_seen_tags.length > unauth_tag_list_length) {
        $('#nfc_seen_tags').append(`<button type="button" id="nfc_seen_tag_${unauth_tag_list_length}" class="list-group-item list-group-item-action">
        <h5 id="nfc_seen_tag_${unauth_tag_list_length}_id" class="mb-1 pr-2"></h5>
        <div class="d-flex w-100 justify-content-between">
            <span id="nfc_seen_tag_${unauth_tag_list_length}_last_seen"></span>
            <span id="nfc_seen_tag_${unauth_tag_list_length}_type"></span>
        </div>
         </button>`)
        ++unauth_tag_list_length;
    }

    for(let i = 0; i < unauth_tag_list_length; ++i) {
        $(`#nfc_seen_tag_${i}_id`).text(toHexBytes(unauth_seen_tags[i].tag_id));
        $(`#nfc_seen_tag_${i}_type`).text(__(`nfc.content.type_${unauth_seen_tags[i].tag_type}`));
        $(`#nfc_seen_tag_${i}_last_seen`).text(__("nfc.content.last_seen") + util.format_timespan(Math.floor(unauth_seen_tags[i].last_seen / 1000)));

        $(`#nfc_seen_tag_${i}`).on("click", () => {
            $(`#nfc_config_tag_new_tag_id`).val(toHexBytes(unauth_seen_tags[i].tag_id));
            $(`#nfc_config_tag_new_tag_type`).val(unauth_seen_tags[i].tag_type);
        });
    }

    $('#nfc_config_tag_no_seen').prop("hidden", unauth_tag_list_length != 0);
}

function nfc_save_reboot() {
    $('#nfc_reboot').modal('hide');
    util.reboot();
}

export function init() {
    (<HTMLButtonElement>document.getElementById("nfc_reboot_button")).addEventListener("click", nfc_save_reboot);

    let form = <HTMLFormElement>$('#nfc_config_form')[0];
    form.addEventListener('input', function (event: Event) {
        $('#nfc_save_button').prop("disabled", false);
    }, false);

    form.addEventListener('submit', function (event: Event) {
        form.classList.add('was-validated');
        event.preventDefault();
        event.stopPropagation();

        if (form.checkValidity() === false) {
            return;
        }

        save_nfc_config();
    }, false);

    $('#nfc_save_tag').on("click", () => {
        let form = <HTMLFormElement>$('#nfc_add_tag_form')[0];
        if (form.checkValidity() === false) {
            return;
        }

        $('#nfc_add_tag_modal').modal('hide');
        $('#nfc_save_button').prop("disabled", false);

        let new_config = collect_nfc_config({
            tag_name: $('#nfc_config_tag_new_name').val().toString(),
            tag_id: fromHexBytes($('#nfc_config_tag_new_tag_id').val().toString()),
            tag_type: parseInt($('#nfc_config_tag_new_tag_type').val().toString())
        }, null);

        update_nfc_config(new_config, true);
    });
}

export function addEventListeners(source: EventSource) {
    source.addEventListener('nfc/state', function (e: util.SSE) {
        update_nfc_state(<NFCState>(JSON.parse(e.data)));
    }, false);

    source.addEventListener('nfc/config', function (e: util.SSE) {
        update_nfc_config(<NFCConfig>(JSON.parse(e.data)), false);
    }, false);

    source.addEventListener('nfc/seen_tags', function (e: util.SSE) {
        update_nfc_seen_tags(<NFCSeenTag[]>(JSON.parse(e.data)));
    }, false);
}

export function updateLockState(module_init: any) {
    $('#sidebar-nfc').prop('hidden', !module_init.nfc);
    $('#nfc_require_tag_to_stop_desc').html(module_init.evse_v2 ? __("nfc.content.require_tag_to_stop_desc") :  __("nfc.content.warp1_require_tag_to_stop_desc"))
}

export function getTranslation(lang: string) {
    const translations: {[index: string]:any} = {
        "de": {
            "nfc": {
                "status": {
                    "nfc": "NFC",
                },
                "navbar": {
                    "nfc": "NFC"
                },
                "content": {
                    "nfc": "NFC-Freischaltung",
                    "state": "State",
                    "state_muted": " ",
                    "config": "Config",
                    "config_muted": " ",
                    "seen_tags": "Seen Tags",
                    "seen_tags_muted": " ",
                    "require_tag_to_start": "Start mit Tag",
                    "require_tag_to_start_desc": "Wenn aktiviert, wird ein berechtigtes Tag zum Starten einer Ladung benötigt. Über das Webinterface kann weiterhin ohne Tag geladen werden.",
                    "require_tag_to_stop": "Stop mit Tag",
                    "require_tag_to_stop_desc": "Wenn aktiviert wird ein berechtigtes Tag zum Stoppen einer Ladung benötigt. Über das Webinterface kann eine Ladung weiterhin ohne Tag abgebrochen werden. <b>Achtung: Die Stop-Funktion des Knopfes an der Wallbox wird damit deaktiviert!</b>",
                    "warp1_require_tag_to_stop_desc": "Wenn aktiviert kann mit einem berechtigten Tag eine Ladung gestoppt werden. Über das Webinterface kann eine Ladung weiterhin ohne Tag abgebrochen werden. <b>Achtung: Die Stop-Funktion des Knopfes an der Wallbox ist bei WARP 1 nicht deaktivierbar!</b>",
                    "save": "Speichern",
                    "authorized_tags": "Berechtigte Tags",

                    "add_tag_modal_title": "Berechtigtes Tag hinzufügen",
                    "add_tag_modal_seen_tags": "Zuletzt erkannte Tags",
                    "add_tag_modal_name": "Tag-Name",
                    "add_tag_modal_tag_id": "Tag-ID",
                    "add_tag_modal_tag_type": "Tag-Typ",
                    "add_tag_modal_abort": "Verwerfen",
                    "add_tag_modal_save": "Hinzufügen",
                    "last_seen": "Erkannt vor ",
                    "type_0": "Mifare Classic",
                    "type_1": "NFC Forum Typ 1",
                    "type_2": "NFC Forum Typ 2",
                    "type_3": "NFC Forum Typ 3",
                    "type_4": "NFC Forum Typ 4",
                    "add_tag_description": "Das neue Tag kann zum Anlernen an die Wallbox gehalten werden. Alternativ können Tag-ID und Tag-Typ manuell angegeben werden.",

                    "reboot_title": "Neu starten um Konfiguration anzuwenden",
                    "reboot_content": "Die geänderten NFC-Einstellungen werden nur nach einem Neustart angewendet. Jetzt neu starten?",
                    "abort": "Abbrechen",
                    "reboot": "Neu starten",
                },
                "script": {
                    "add_tag": "Tag hinzufügen",
                    "tag_name": "Tag-Name",
                    "tag_type": "Tag-Typ",
                    "last_seen_unknown": "placeholder"
                }
            }
        },
        "en": {
            "nfc": {
                "status": {
                    "nfc": "NFC",
                },
                "navbar": {
                    "nfc": "NFC"
                },
                "content": {
                    "nfc": "NFC",
                    "state": "State",
                    "state_muted": " ",
                    "config": "Config",
                    "config_muted": " ",
                    "seen_tags": "Seen Tags",
                    "seen_tags_muted": " ",
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
