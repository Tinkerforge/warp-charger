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

declare function __(s: string): string;

import Chartist = require("chartist");
import ctAxisTitle = require("chartist-plugin-axistitle");

// Duplicated in evse/main.ts
interface MeterState {
    power: number,
    energy_rel: number,
    energy_abs: number,
}

function update_meter_state(state: MeterState) {
    $('#status_meter_power').val(util.toLocaleFixed(state.power, 0) + " W");
    $('#meter_power').val(util.toLocaleFixed(state.power, 0) + " W");

    $('#meter_energy_rel').val(util.toLocaleFixed(state.energy_rel, 3) + " kWh");

    $('#meter_energy_abs').val(util.toLocaleFixed(state.energy_abs, 3) + " kWh");
}


let graph_update_interval: number = null;
let status_interval: number = null;

function update_live_meter() {
    $.get("/meter/live").done(function (result) {
        let values = result["samples"];
        let sps = result["samples_per_second"];
        let labels = [];

        let now = Date.now();
        let start = now - 1000 * values.length / sps;
        let last_minute = -1;
        for(let i = 0; i < values.length + 1; ++i) {
            let d = new Date(start + i * (1000 * (1/sps)));
            if(d.getSeconds() == 0 && d.getMinutes() != last_minute) {
                labels[i] = d.toLocaleTimeString(navigator.language, {hour: '2-digit', minute: '2-digit'});
                last_minute = d.getMinutes();
            }
            else {
                labels[i] = null;
            }
        }

        let data = {
            labels: labels,
            series: [
                values
            ]
        };
        meter_chart.update(data);
    });
}

function update_history_meter() {
    $.get("/meter/history").done(function (values: Number[]) {
        const HISTORY_MINUTE_INTERVAL = 4;
        const VALUE_COUNT = 48 * (60 / HISTORY_MINUTE_INTERVAL);
        const LABEL_COUNT = 9;
        const VALUES_PER_LABEL = VALUE_COUNT / (LABEL_COUNT - 1); // - 1 for the last label that has no values

        if (values.length != VALUE_COUNT) {
            console.log("Unexpected number of values to plot!");
            return;
        }

        let labels = [];

        let now = Date.now();
        let start = now - 1000 * 60 * 60 * 48;
        for(let i = 0; i < values.length + 1; ++i) {
            if (i % VALUES_PER_LABEL == 0) {
                let d = new Date(start + i * (1000 * 60 * HISTORY_MINUTE_INTERVAL));
                labels[i] = d.toLocaleTimeString(navigator.language, {hour: '2-digit', minute: '2-digit'});
            }
            else {
                labels[i] = null;
            }
        }

        let data = {
            labels: labels,
            series: [
                values
            ]
        };
        meter_chart.update(data);
    });
}

function meter_chart_change_time(value: string) {
    if (graph_update_interval != null) {
        clearInterval(graph_update_interval);
        graph_update_interval = null;
    }

    if (value == "live") {
        update_live_meter();
        graph_update_interval = window.setInterval(update_live_meter, 1000);
        return;
    } else if (value == "history") {
        update_history_meter();
        graph_update_interval = window.setInterval(update_history_meter, 10000);
    } else {
        console.log("Unknown plot type!");
    }
}

let meter_chart: Chartist.IChartistLineChart;
let status_meter_chart: Chartist.IChartistLineChart;

function init_chart() {
    let data = {};

    // Create a new line chart object where as first parameter we pass in a selector
    // that is resolving to our chart container element. The Second parameter
    // is the actual data object.
    meter_chart = new Chartist.Line('#meter_chart', <any>data, {
        fullWidth: true,
        showPoint: false,
        axisX: {
            offset: 50,
            labelOffset: {x: 0, y: 5}
        },
        axisY: {
            scaleMinSpace: 40,
            onlyInteger: true,
            offset: 50,
            labelOffset: {x: 0, y: 6}
        },
        plugins: [
            ctAxisTitle({
                axisX: {
                axisTitle: __("sdm72dm.script.time"),
                axisClass: "ct-axis-title",
                offset: {
                    x: 0,
                    y: 40
                },
                textAnchor: "middle"
                },
                axisY: {
                axisTitle: __("sdm72dm.script.power"),
                axisClass: "ct-axis-title",
                offset: {
                    x: 0,
                    y: 12
                },
                flipTitle: true
                }
            })
        ]
    });

    let input = <HTMLInputElement>document.getElementById("meter_chart_time_select");
    meter_chart_change_time(input.value);
}

function update_status_chart() {
    $.get("/meter/history").done(function (values: number[]) {
        const HISTORY_MINUTE_INTERVAL = 4;
        const VALUE_COUNT = 48 * (60 / HISTORY_MINUTE_INTERVAL);
        const LABEL_COUNT = 5;
        const VALUES_PER_LABEL = VALUE_COUNT / (LABEL_COUNT - 1); // - 1 for the last label that has no values

        if (values.length != VALUE_COUNT) {
            console.log("Unexpected number of values to plot!");
            return;
        }

        let labels = [];

        let now = Date.now();
        let start = now - 1000 * 60 * 60 * 48;
        for(let i = 0; i < values.length + 1; ++i) {
            if (i % VALUES_PER_LABEL == 0) {
                let d = new Date(start + i * (1000 * 60 * HISTORY_MINUTE_INTERVAL));
                labels[i] = d.toLocaleTimeString(navigator.language, {hour: '2-digit', minute: '2-digit'});
            }
            else {
                labels[i] = null;
            }
        }

        let data = {
            labels: labels,
            series: [
                values
            ]
        };

        // This is a hack in three ways:
        // 1. We don't have any mechanism to communicate with the evse module if it is even compiled in,
        //    so we just assume that it is and ask for the allowed current.
        // 2. This only calculates the correct value if we charge with three phases. This is okay for the moment,
        //    as the energy meter itself will only work correctly if powered with a three-phase current.
        // 3. This breaks if we start shipping wallboxes that have a type 2 socket instead of a fixed cable,
        //    because the max_current_outgoing_cable can then change.
        $.get("/evse/max_charging_current")
         .done((result) => {
                let allowed_current = Math.min(result.max_current_incoming_cable, result.max_current_outgoing_cable);
                let configured_max = allowed_current / 1000 * 3 * 230;
                init_status_chart(0, Math.max(configured_max, Math.max(...values))),
                status_meter_chart.update(data);
            })
          .fail(() => {
                console.log("Failed to query max charging current.");
                init_status_chart(0, Math.max(...values)),
                status_meter_chart.update(data);
            });
    });
}

function init_status_chart(min_value=0, max_value=0) {
    let data = {};

    // Create a new line chart object where as first parameter we pass in a selector
    // that is resolving to our chart container element. The Second parameter
    // is the actual data object.
    status_meter_chart = new Chartist.Line('#status_meter_chart', <any>data, {
        fullWidth: true,
        showPoint: false,
        low: min_value,
        high: max_value,
        axisX: {
            offset: 50,
            labelOffset: {x: 0, y: 5}
        },
        axisY: {
            scaleMinSpace: 40,
            onlyInteger: true,
            offset: 60,
            labelOffset: {x: 0, y: 6}
        },
        plugins: [
            ctAxisTitle({
                axisX: {
                axisTitle: __("sdm72dm.script.time"),
                axisClass: "ct-axis-title",
                offset: {
                    x: 0,
                    y: 40
                },
                textAnchor: "middle"
                },
                axisY: {
                axisTitle: __("sdm72dm.script.power"),
                axisClass: "ct-axis-title",
                offset: {
                    x: -10,
                    y: 15
                },
                flipTitle: true
                }
            })
        ]
    });


}

function energy_meter_reset_statistics() {
    $.ajax({
        url: '/meter/reset',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify(null)
    });
}

export function init() {
    let input = <HTMLInputElement>document.getElementById("meter_chart_time_select");
    input.addEventListener(
        "change", () => meter_chart_change_time(input.value)
    );

    (<HTMLButtonElement>document.getElementById("energy_meter_reset_statistics_button")).addEventListener("click", energy_meter_reset_statistics);

    // The energy meter tab layout is generated when it is shown first.
    // We have to create the chart then, to make sure it is scaled correctly.
    // Immediately deregister afterwards, as we don't want to recreate the chart
    // every time.
    $('#sidebar-meter').on('shown.bs.tab', function (e) {
        init_chart();
    });

    $('#sidebar-meter').on('hidden.bs.tab', function (e) {
        if (graph_update_interval != null) {
            clearInterval(graph_update_interval);
            graph_update_interval = null;
        }
    });

    $('#sidebar-status').on('shown.bs.tab', function (e) {
        init_status_chart();
        update_status_chart();
    });

    init_status_chart();
    update_status_chart();
    status_interval = window.setInterval(update_status_chart, 60*1000);
}

export function addEventListeners(source: EventSource) {
    source.addEventListener('meter/state', function (e: util.SSE) {
        update_meter_state(<MeterState>(JSON.parse(e.data)));
    }, false);
}

export function updateLockState(module_init: any) {
    $('#sidebar-meter').prop('hidden', !module_init.sdm72dm);
    $('#status-meter').prop('hidden', !module_init.sdm72dm);

    if(!module_init.sdm72dm) {
        if (graph_update_interval != null) {
            clearInterval(graph_update_interval);
            graph_update_interval = null;
        }

        if (status_interval != null) {
            clearInterval(status_interval);
            status_interval = null;
        }
    } else {
        if (status_interval == null) {
            status_interval = window.setInterval(update_status_chart, 60*1000);
        }
    }
}

export function getTranslation(lang: string) {
    const translations: {[index: string]:any} = {
        "de": {
            "sdm72dm": {
                "status": {
                    "charge_history": "Ladeverlauf",
                    "current_power": "Leistungs&shy;aufnahme"
                },
                "navbar": {
                    "energy_meter": "Stromzähler"
                },
                "content": {
                    "energy_meter": "Stromzähler",
                    "history": "Verlauf (48 h)",
                    "live": "Live",
                    "statistics": "Statistiken",
                    "reset_statistics": "Zurücksetzen",
                    "power": "Leistungs&shy;aufnahme",
                    "energy": "Strom&shy;verbrauch",
                    "energy_since_reset": "seit dem letzten Zurücksetzen",
                    "energy_lifetime": "seit Herstellung des Stromzählers"
                },
                "script": {
                    "time": "Uhrzeit",
                    "power": "Leistung (Watt)"
                }
            }
        },
        "en": {
            "sdm72dm": {
                "status": {
                    "charge_history": "Charge history",
                    "current_power": "Power draw"
                },
                "navbar": {
                    "energy_meter": "Energy Meter"
                },
                "content": {
                    "energy_meter": "Energy Meter",
                    "history": "History (48 h)",
                    "live": "Live",
                    "statistics": "Statistics",
                    "reset_statistics": "Reset",
                    "power": "Power draw",
                    "energy": "Energy consumption",
                    "energy_since_reset": "since last reset",
                    "energy_lifetime": "since manufactoring of the energy meter"
                },
                "script": {
                    "time": "Time of day",
                    "power": "Power (Watt)"
                }
            }
        }
    };
    return translations[lang];
}
