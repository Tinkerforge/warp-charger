import { text } from "cheerio";
import React from "react";

// ----------------------------------------------------------------------------
// Please respect order by manufacturer, then by name, when adding new entries.
// ----------------------------------------------------------------------------

// Syntax
// x -> available
// (x) -> available, position dependend
// ? -> we have no information
// - -> not availble

//battery not documented yet

export const devices = [
  {
    manufacturer: "Alpha ESS",
    device: "Smile Heimspeicher",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#alpha-ess",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",  // should be available
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "APsystems",
    device: "Mikrowechselrichter mittels ECU-R oder ECU-C",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#apsystems",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "Carlo Galvazzi",
    device: "Smart Meter: EM24, EM100, ET100, EM210, EM270, EM280, EM300, ET300, EM510, EM530, EM540",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#carlo-galvazzi",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Deye",
    device: "SUN-Serie Hybrid-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#deye",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "E3DC",
    device: "S10, S20 Hauskraftwerke",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#e3dc",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "-",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Eastron",
    device: "SDM630 (V2, V3)",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eastron",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Eastron",
    device: "SDM630MCT",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eastron",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Eastron",
    device: "SDM72V2",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eastron",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "elgris",
    device: "Smart Meter LAN 2.0",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#elgris",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Eltako",
    device: "DSZ15DZMOD",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eltako",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Fox ESS",
    device: "Hybrid Serie H1, H3, AC Serie",
    connection: "Modbus/RTU",
    note: "hybrid-Wechselrichter",
    link: "/docs/compatible_devices/devices#fox-ess",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "-", //meter no currents available
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Fronius",
    device: "Argeno String-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "Fronius",
    device: "GEN24- und GEN24 Plus-Serie Hybrid-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Fronius",
    device: "Primo- und Symo-Serie String-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Fronius",
    device: "Tauro-Serie String-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Fronius",
    device: "Verto-Serie String-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Fronius",
    device: "Verto Plus-Serie Hybrid-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Goodwe",
    device: "EHB Serie String-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#goodwe",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Goodwe",
    device: "EH, EM, ES, ET Hybrid-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#goodwe",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Goodwe",
    device: "BT, SBP, BH-Serie Batterie-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#goodwe",
    grid: "?",
    pv: "-",
    battery: "x",
    load: "x",
    dlm: "?",
    pve: "?",
    bat: "-"
  },
  {
    manufacturer: "Hailei", //is alpha ess
    device: "HL-TPH10K Hybrid Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#hailei",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-", // should be available
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Hoymiles",
    device: "Mikrowechselrichter HMS/HMT mittels DTU-Pro-S",
    connection: "SunSpec",
    note: "Mikrowechselrichter der HMS und HMT Serie ",
    link: "/docs/compatible_devices/devices#hoymiles",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "Huawei",
    device: "SUN2000 Hybrid-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#sun2000",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Huawei",
    device: "EMMA Energiemanager",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#emma",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Kaco",
    device: "Blueplanet Hybrid NH3 Hybrid-Wechselrichter",
    connection: "SunSpec",
    note: "Hybrid-Wechselrichter",
    link: "/docs/compatible_devices/devices#kaco",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "Kaco",
    device: "Blueplanet NX3 und TL3 String-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#kaco",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "Kostal",
    device: "Smart Energy Meter (KSEM G2)",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#kostal",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Kostal",
    device: "Piko und Plenticore",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#kostal",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Q-Cells",
    device: "Q.HOME Serie",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#q-cells",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Q-Cells",
    device: "Q.VOLT Serie",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#q-cells",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "RCT",
    device: "RCT POWER STORAGE",
    connection: "RCT PSC",
    link: "/docs/compatible_devices/devices#rct",
    grid: "x",
    pv: "-", //no pv
    battery: "x",
    load: "-",
    dlm: "-", //not available
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "SAX Power",
    device: "Power Home und Power Home Plus",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#sax-power",
    grid: "x",
    pv: "-",
    battery: "x",
    load: "-",
    dlm: "-",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Shelly",
    device: "Shelly Pro EM und Shelly Pro 3EM",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#shelly",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Siemens",
    device: "SENTRON PAC2200, PAC3120, PAC3200, PAC3220, PAC4200, PAC4220",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#siemens",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Boy 3.0 / 3.6 / 4.0 / 5.0 / 6.0",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#sma",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Boy Smart Energy 3.6 / 4.0 / 5.0 / 6.0",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#sma",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Tripower 3.0 / 4.0 / 5.0 / 6.0 / 8.0 / 10.0",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#sma",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Tripower Smart Energy 5.0 / 6.0 / 8.0 / 10.0",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#sma",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Tripower CORE1",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#sma",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Highpower PEAK3",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#sma",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "-",
    bat: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Home Manager 1.0 / 2.0, SMA Energy Meter 2.0",
    connection: "SMA Speedwire",
    link: "/docs/compatible_devices/devices#sma",
    grid: "x",
    pv: "-",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "SolarEdge",
    device: "SolarEdge Synergie PV-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#solaredge",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "SolarEdge",
    device: "SolarEdge Home Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#solaredge",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Solarmax",
    device: "Max.Storage",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#solarmax",
    grid: "x",
    pv: "-",
    battery: "x",
    load: "-",
    dlm: "-", //currents not available
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Solax",
    device: "X1 & X3 Hybrid",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#solax",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Solax",
    device: "X1 & X3 Mini Boost MIC und Pro",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#solax",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Sungrow",
    device: "SG-Serie",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#sg-serie",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Sungrow",
    device: "SH-Serie",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#sh-serie",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "-",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Tasmota",
    device: "Smart Meter Interface - IR Lesekopf",
    connection: "HTTP",
    link: "/docs/compatible_devices/devices#tasmota",
    grid: "x",
    pv: "-",
    battery: "-",
    load: "-",
    dlm: "-",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Tinkerforge",
    device: "WARP Meters API HTTP",
    connection: "HTTP",
    link: "/docs/compatible_devices/devices#http-api",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Tinkerforge",
    device: "WARP Meters API MQTT",
    connection: "MQTT",
    link: "/docs/compatible_devices/devices#mqtt-api",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Victron Energy",
    device: "GX und damit verbundene Geräte",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#victron-energy",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "-",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "Victron Energy",
    device: "EM540, ET340, ET112, EM24 Stromzähler",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#victron-energy",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
  {
    manufacturer: "YTL",
    device: "DEM4A",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#ytl",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x",
    dlm: "x",
    pve: "x",
    bat: "-"
  },
];

function text_to_bubble(text, name, show_unavailable = true) {
    if (text === "x") {
        return <div class="device available">{name}</div>
    } else if (text === "(x)") {
        return <div class="device optional">{name}</div>
    } else if (text === "?") {
        return <div class="device maybe">{name}</div>
    } else if (text === "-") {
        if (show_unavailable) {
            return <div class="device unavailable">{name}</div>
        } else {
            return <div></div>
        }
    } else {
        return <div>ERROR</div>
    }
}

function text_to_bubble2(text, name, show_unavailable = true) {
    if (text === "x") {
        return <div class="application available">{name}</div>
    } else if (text === "(x)") {
        return <div class="application optional">{name}</div>
    } else if (text === "?") {
        return <div class="application maybe">{name}</div>
    } else if (text === "-") {
        if (show_unavailable) {
            return <div class="application unavailable">{name}</div>
        } else {
            return <div></div>
        }
    } else {
        return <div>ERROR</div>
    }
}

export function manufacturer_to_bubbles(manufacturer, device = undefined) {
  let data = devices.find(device => device.manufacturer === manufacturer)
  if (data === undefined) {
    return <div>ERROR1</div>
  }

  if(device != undefined) {
    data = devices.find(data => data.device === device)
    if (data === undefined) {
      return <div>ERROR2</div>
    }
  }

  return <div class="manufacturer_devices">
    <div>{text_to_bubble(data.grid,    "Netz",     false)}</div>
    <div>{text_to_bubble(data.pv,      "PV",       false)}</div>
    <div>{text_to_bubble(data.battery, "Speicher", false)}</div>
    <div>{text_to_bubble(data.load,    "Last",     false)}</div>
    <div>&nbsp; &nbsp; &nbsp; </div>
    <div>{text_to_bubble2(data.pve,    "PVÜ", false)}</div>
    <div>{text_to_bubble2(data.dlm,    "dLM", false)}</div>
    <div>{text_to_bubble2(data.bat,    "BAT", false)}</div>
  </div>
}

// ----------------------------------------------------------------------------
// SortableDataTable column definition
// ----------------------------------------------------------------------------
export const columns = [
 {
    header: "Hersteller",
    accessorKey: "manufacturer",
    className: "sortable-data-table left nowrap",
    cell: ({ cell, row: { original } }) => (original.manufacturer != undefined || original.manufacturer == "" )?
      original.link != undefined ? (
        <a href={original.link}>{cell.getValue()}</a>
      ) : (
        cell.getValue()
    ) : (
      original.link != undefined ? (
        <a href={original.link}>Weitere Informationen</a>
      ) : (
      "x"
      )
    ),
  },
  {
    header: "Gerät/ Serie",
    accessorKey: "device",
    className: "sortable-data-table left nowrap",
  },
  {
    header: "Schnittstelle",
    accessorKey: "connection",
    className: "sortable-data-table left nowrap",
  },
  {
    header: "Messort",
    accessorKey: "load",
    className: "sortable-data-table left",
    cell: ({ cell, row: { original } }) => (
        <div style={{display: 'flex'}}>
            <div>{text_to_bubble(original.grid,    "Netz"    )}</div>
            <div>{text_to_bubble(original.pv,      "PV"      )}</div>
            <div>{text_to_bubble(original.battery, "Speicher")}</div>
            <div>{text_to_bubble(original.load,    "Last"    )}</div>
        </div>
    ),
  },
  {
    header: "Anwendung",
    accessorKey: "dlm",
    className: "sortable-data-table left",
    cell: ({ cell, row: { original } }) => (
        <div style={{display: 'flex'}}>
            <div>{text_to_bubble2(original.pve,    "PVÜ"  )}</div>
            <div>{text_to_bubble2(original.dlm,    "dLM"  )}</div>
            <div>{text_to_bubble2(original.bat,    "BAT"  )}</div>
        </div>
    ),
  },
];
