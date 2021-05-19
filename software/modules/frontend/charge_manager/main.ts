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

declare function __(s: string): string;

interface Charger {
    last_update: number,
    uptime: number,
    supported_current: number,
    allowed_current: number,
    wants_to_charge: boolean,
    is_charging: boolean,
    last_sent_config: number,
    allocated_current: number
}

interface ChargeManagerState {
    state: number,
    chargers: Charger[]
}

let charger_count = 0;

function update_charge_manager_state(state: ChargeManagerState) {
    if (state.chargers.length != charger_count) {
        let chargers_html = "";
        for (let i = 0; i < state.chargers.length; i++) {
            chargers_html += `
                <div
                    class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
                    <span class="h3">${__("charge_manager.content.charger")} ${i}</span>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_last_update" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.last_update")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_last_update" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_uptime" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.uptime")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_uptime" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_supported_current" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.supported_current")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_supported_current" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_allowed_current" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.allowed_current")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_allowed_current" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_wants_to_charge" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.wants_to_charge")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_wants_to_charge" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_is_charging" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.is_charging")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_is_charging" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_last_sent_config" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.last_sent_config")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_last_sent_config" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>

                <div class="form-group row">
                    <div class="col-lg-4">
                        <label for="charger_${i}_allocated_current" class="col-form-label">
                            <span class="form-label">${__("charge_manager.content.allocated_current")}</span>
                        </label>
                    </div>
                    <div class="col-lg-4">
                        <input id="charger_${i}_allocated_current" class="form-control" type="text"
                            placeholder="..." readonly>
                    </div>
                </div>`
        }
        $('#chargers').html(chargers_html);
        charger_count = state.chargers.length;

    }
    for (let i = 0; i < state.chargers.length; i++) {
        const s = state.chargers[i];
        $(`#charger_${i}_last_update`).val(s.last_update);
        $(`#charger_${i}_uptime`).val(s.uptime);
        $(`#charger_${i}_supported_current`).val(s.supported_current);
        $(`#charger_${i}_allowed_current`).val(s.allowed_current);
        $(`#charger_${i}_wants_to_charge`).val(s.wants_to_charge);
        $(`#charger_${i}_is_charging`).val(s.is_charging);
        $(`#charger_${i}_last_sent_config`).val(s.last_sent_config);
        $(`#charger_${i}_allocated_current`).val(s.allocated_current);
    }
}

export function init() {

}

export function addEventListeners(source: EventSource) {
    source.addEventListener('charge_manager/state', function (e: util.SSE) {
        update_charge_manager_state(<ChargeManagerState>(JSON.parse(e.data)));
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
                },
                "navbar": {
                    "charge_manager": "Lastmanager"
                },
                "content": {
                    "charge_manager": "Lastmanager",
                    "state": "Zustand",
                    "charger": "Wallbox",
                    "last_update": "Letztes Update",
                    "uptime": "Laufzeit",
                    "supported_current": "Unterstützter Strom",
                    "allowed_current": "Erlaubter Strom",
                    "wants_to_charge": "Wartet auf Manager",
                    "is_charging": "Lädt",
                    "last_sent_config": "Letztes Config-Update",
                    "allocated_current": "Zugewiesener Strom",
                },
                "script": {
                }
            }
        },
        "en": {
            "evse": {
                "status": {
                },
                "navbar": {
                    "charge_manager": "Lastmanager"
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
                },
                "script": {
                }
            }
        }
    };
    return translations[lang];
}
