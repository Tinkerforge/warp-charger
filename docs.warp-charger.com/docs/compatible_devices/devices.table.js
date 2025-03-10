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

export const devices = [
  {
    manufacturer: "Alpha ESS",
    device: "Smile Heimspeicher",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#alpha-ess",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "-"
  },
  {
    manufacturer: "APsystems",
    device: "Mikrowechselrichter mittels ECU-R oder ECU-C",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#apsystems",
    grid: "-",
    pv: "x",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "Carlo Galvazzi",
    device: "EM24 Smart Meter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#carlo-galvazzi",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Deye",
    device: "SUN-Serie Hybrid-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#deye",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x"
  },
  {
    manufacturer: "E3DC",
    device: "S10, S20 Hauskraftwerke",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#e3dc",
    grid: "x",
    pv: "x",
    battery: "?",
    load: "?"
  },
  {
    manufacturer: "Eastron",
    device: "SDM630 (V2, V3)",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eastron",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Eastron",
    device: "SDM630MCT",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eastron",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Eastron",
    device: "SDM72V2",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eastron",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "elgris",
    device: "Smart Meter LAN 2.0",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#elgris",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Eltako",
    device: "DSZ15DZMOD",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#eltako",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Fronius",
    device: "GEN24-Serie Hybrid-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "?"
  },
  {
    manufacturer: "Fronius",
    device: "Primo- und Symo-Serie String-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#fronius",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-"
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
    load: "?"
  },
  {
    manufacturer: "Goodwe",
    device: "EHB Serie String-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#goodwe",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "Goodwe",
    device: "EH, EM, ES, ET Hybrid-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#goodwe",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x"
  },
  {
    manufacturer: "Hailei",
    device: "Hybrid Wechselrichter (x)",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#hailei",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x"
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
    load: "-"
  },
  {
    manufacturer: "Huawei",
    device: "SUN2000 Serie Hybrid-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#huawei",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x"
  },
  {
    manufacturer: "Goodwe",
    device: "BT, SBP, BH-Serie Batterie-Wechselrichter",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#goodwe",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x"
  },
  {
    manufacturer: "Kaco",
    device: "Blueplanet Hybrid NH3 Hybrid-Wechselrichter",
    connection: "SunSpec",
    note: "Hybrid-Wechselrichter",
    link: "/docs/compatible_devices/devices#kaco",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "?"
  },
  {
    manufacturer: "Kaco",
    device: "Blueplanet NX3 und TL3 String-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#kaco",
    grid: "?",
    pv: "x",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "Kostal",
    device: "Smart Energy Meter (KSEM G2)",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#kostal",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Kostal",
    device: "Piko und Plenticore",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#kostal",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "?"
  },
  {
    manufacturer: "RCT",
    device: "RCT POWER STORAGE",
    connection: "RCT PSC",
    link: "/docs/compatible_devices/devices#rct",
    grid: "x",
    pv: "-",
    battery: "x",
    load: "-"
  },
  {
    manufacturer: "Shelly",
    device: "Shelly Pro EM und Shelly Pro 3EM",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#shelly",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Siemens",
    device: "SENTRON PAC2200/PAC3200",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#siemens",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "SMA",
    device: "Energy Meter 2.0",
    connection: "SMA Speedwire",
    link: "/docs/compatible_devices/devices#sma",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Boy 2.5 / 3.6",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#sma",
    grid: "?",
    pv: "x",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "SMA",
    device: "Sunny Home Manager 1.0 / 2.0",
    connection: "SMA Speedwire",
    link: "/docs/compatible_devices/devices#sma",
    grid: "x",
    pv: "-",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "SolarEdge",
    device: "SolarEdge Synergie PV-Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#solaredge",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "SolarEdge",
    device: "SolarEdge Home Wechselrichter",
    connection: "SunSpec",
    link: "/docs/compatible_devices/devices#solaredge",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "?"
  },
  {
    manufacturer: "Solarmax",
    device: "Max.Storage",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#solarmax",
    grid: "x",
    pv: "-",
    battery: "x",
    load: "-"
  },
  {
    manufacturer: "Solax",
    device: "X1 & X3 Hybrid",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#solax",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "?"
  },
  {
    manufacturer: "Solax",
    device: "X1 & X3 Mini Boost MIC und Pro",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#solax",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "Sungrow",
    device: "SG-Serie",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#sungrow",
    grid: "x",
    pv: "x",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "Sungrow",
    device: "SH-Serie",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#sungrow",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x"
  },
  {
    manufacturer: "Tasmota",
    device: "Smart Meter Interface - IR Lesekopf",
    connection: "HTTP",
    link: "/docs/compatible_devices/devices#tasmota",
    grid: "x",
    pv: "-",
    battery: "-",
    load: "-"
  },
  {
    manufacturer: "Tinkerforge",
    device: "WARP API",
    connection: "HTTP",
    link: "/interfaces/mqtt_http/api_reference/meters",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Tinkerforge",
    device: "WARP API",
    connection: "MQTT",
    link: "/interfaces/mqtt_http/api_reference/meters",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
  {
    manufacturer: "Victron Energy",
    device: "GX und damit verbundene Geräte",
    connection: "Modbus/TCP",
    link: "/docs/compatible_devices/devices#victron",
    grid: "x",
    pv: "x",
    battery: "x",
    load: "x"
  },
  {
    manufacturer: "YTL",
    device: "DEM4A",
    connection: "WARP Energy Manager",
    link: "/docs/compatible_devices/devices#ytl",
    grid: "(x)",
    pv: "(x)",
    battery: "(x)",
    load: "(x)"
  },
];

function text_to_bubble(text, name) {
    if (text === "x") {
        return <div class="device available">{name}</div>
    } else if (text === "(x)") {
        return <div class="device optional">{name}</div>
    } else if (text === "?") {
        return <div class="device maybe">{name}</div>
    } else if (text === "-") {
        return <div class="device unavailable">{name}</div>
    } else {
        return <div>ERROR</div>
    }
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
    header: "Klasse (Messort)",
    accessorKey: "load",
    className: "sortable-data-table left",
    cell: ({ cell, row: { original } }) => (
        <div style={{display: 'flex'}}>
            <div>{text_to_bubble(original.grid,    "Netz"    )}</div>
            <div>{text_to_bubble(original.pv,      "PV"      )}</div>
            <div>{text_to_bubble(original.battery, "Batterie")}</div>
            <div>{text_to_bubble(original.load,    "Last"    )}</div>
        </div>
    ),
  },
];
