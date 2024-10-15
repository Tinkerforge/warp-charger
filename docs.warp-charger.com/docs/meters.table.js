import React from "react";

// ----------------------------------------------------------------------------
// Please respect order by manufacturer, then by name, when adding new entries.
// ----------------------------------------------------------------------------
export const meters = [
  {
    manufacturer: "Alpha ESS",
    name: "Smile Heimspeicher",
    connection: "Modbus/TCP",
    note: "Heimspeicher mit integriertem Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#alpha-ess",
  },
  {
    manufacturer: "Carlo Galvazzi",
    name: "EM24",
    connection: "Modbus/TCP",
    note: "Smart Meter",
    note_url: "/docs/compatible_meters#carlo-galvazzi",
  },
  {
    manufacturer: "Deye",
    name: "SUN-Serie",
    connection: "Modbus/TCP",
    note: "Hybrid-Wechselrichter für Nieder- und Hochspannungsbatterien",
    note_url: "/docs/compatible_meters#deye",
  },
  {
    manufacturer: "E3DC",
    name: "Hauskraftwerke",
    connection: "SunSpec",
    note_url: "/docs/compatible_meters#e3dc",
  },
  {
    manufacturer: "Eastron",
    name: "SDM630 (V2, V3)",
    connection: "WARP Energy Manager",
    note: "Stromzähler direkt am WARP Energy Manager angeschlossen",
    note_url: "/docs/compatible_meters#eastron",
  },
  {
    manufacturer: "Eastron",
    name: "SDM630MCT",
    connection: "WARP Energy Manager",
    note: "Stromzähler direkt am WARP Energy Manager angeschlossen",
    note_url: "/docs/compatible_meters#eastron",
  },
  {
    manufacturer: "Eastron",
    name: "SDM72V2",
    connection: "WARP Energy Manager",
    note: "Stromzähler direkt am WARP Energy Manager angeschlossen",
    note_url: "/docs/compatible_meters#eastron",
  },
  {
    manufacturer: "elgris",
    name: "Smart Meter LAN 2.0",
    connection: "SunSpec",
    note: "Smart Meter",
    note_url: "/docs/compatible_meters#elgris",
  },
  {
    manufacturer: "Eltako",
    name: "DSZ15DZMOD",
    connection: "WARP Energy Manager",
    note: "Stromzähler direkt am WARP Energy Manager angeschlossen",
    note_url: "/docs/compatible_meters#eltako",
  },
  {
    manufacturer: "Fronius",
    name: "GEN24-Serie",
    connection: "SunSpec",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#fronius",
  },
  {
    manufacturer: "Fronius",
    name: "Primo- und Symo-Serie",
    connection: "SunSpec",
    note: "String-Wechselrichter",
    note_url: "/docs/compatible_meters#fronius",
  },
  { 
    manufacturer: "Fox ESS",
    name: "Hybrid Serie H1, H3, AC Serie",
    connection: "Modbus RTU mit Wandler",
    note: "hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#fox-ess",
  },
  {
    manufacturer: "Goodwe",
    name: "EHB Serie",
    connection: "Modbus/TCP",
    note: "String-Wechselrichter",
    note_url: "/docs/compatible_meters#goodwe",
  },
  {
    manufacturer: "Goodwe",
    name: "EH, EM, ES, ET",
    connection: "Modbus/TCP",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#goodwe",
  },
{
    manufacturer: "Hailei",
    name: "Hybrid Wechselrichter TBD",
    connection: "Modbus/TCP",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#hailei",
  },
  {
    manufacturer: "Huawei",
    name: "SUN2000 Serie",
    connection: "Modbus/TCP",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#huawei",
  },
  {
    manufacturer: "Goodwe",
    name: "BT, SBP, BH-Serie",
    connection: "Modbus/TCP",
    note: "Batterie-Wechselrichter",
    note_url: "/docs/compatible_meters#goodwe",
  },
  {
    manufacturer: "Kaco",
    name: "Blueplanet Hybrid NH3 Wechselrichter",
    connection: "SunSpec",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#kaco",
  },
  {
    manufacturer: "Kaco",
    name: "Blueplanet NX3 und TL3 Wechselrichter",
    connection: "SunSpec",
    note: "String-Wechselrichter",
    note_url: "/docs/compatible_meters#kaco",
  },
  {
    manufacturer: "Kostal",
    name: "Smart Energy Meter (KSEM G2)",
    connection: "SunSpec",
    note: "Smart Meter",
    note_url: "/docs/compatible_meters#kostal",
  },
  {
    manufacturer: "Kostal",
    name: "Piko und Plenticore",
    connection: "SunSpec",
    note: "Wechselrichter",
    note_url: "/docs/compatible_meters#kostal",
  },
  {
    manufacturer: "RCT",
    name: "RCT POWER INVERTER + STORAGE",
    connection: "RCT Power Serial Communication",
    note: "Hybrid, Batterie und String-Wechselrichter",
    note_url: "/docs/compatible_meters#rct",
  },
  {
    manufacturer: "Shelly",
    name: "Shelly Pro EM und Shelly Pro 3EM",
    connection: "Modbus/TCP",
    note: "1-phasige und 3-phasige Wandler-Stromzähler mit 1TE",
    note_url: "/docs/compatible_meters#shelly",
  },
  {
    manufacturer: "Siemens",
    name: "SENTRON PAC2200/PAC3200",
    connection: "Modbus/TCP",
    note: "Smart Meter",
    note_url: "/docs/compatible_meters#siemens",
  },
  {
    manufacturer: "SMA",
    name: "Energy Meter 2.0",
    connection: "SMA Speedwire",
    note: "Smart Meter",
    note_url: "/docs/compatible_meters#sma",
  },
  {
    manufacturer: "SMA",
    name: "Sunny Boy 2.5 / 3.6",
    connection: "SunSpec",
    note: "Wechselrichter",
    note_url: "/docs/compatible_meters#sma",
  },
  {
    manufacturer: "SMA",
    name: "Sunny Home Manager 1.0 / 2.0",
    connection: "SMA Speedwire",
    note: "HEMS / Smart Meter",
    note_url: "/docs/compatible_meters#sma",
  },
  {
    manufacturer: "SolarEdge",
    name: "SolarEdge Home Wechselrichter",
    connection: "SunSpec",
    note: "Wechselrichter inkl. daran angeschlossenen Energiezähler",
    note_url: "/docs/compatible_meters#solaredge",
  },
  {
    manufacturer: "Solarmax",
    name: "Max.Storage",
    connection: "Modbus/TCP",
    note: "Speichersystem",
    note_url: "/docs/compatible_meters#solarmax",
  },
  {
    manufacturer: "Solax",
    name: "X1 & X3 Hybrid",
    connection: "Modbus/TCP",
    note: "Hybridwechselrichter",
    note_url: "/docs/compatible_meters#solax",
  },
  {
    manufacturer: "Solax",
    name: "X1 & X3 Mini Boost MIC und Pro",
    connection: "Modbus/TCP",
    note: "Stringwechselrichter",
    note_url: "/docs/compatible_meters#solax",
  },
  {
    manufacturer: "Sungrow",
    name: "SG-Serie",
    connection: "Modbus/TCP",
    note: "String-Wechselrichter",
    note_url: "/docs/compatible_meters#sungrow",
  },
  {
    manufacturer: "Sungrow",
    name: "SH-Serie",
    connection: "Modbus/TCP",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#sungrow",
  },
  {
    manufacturer: "Tasmota",
    name: "Smart Meter Interface - IR Lesekopf",
    connection: "HTTP",
    note: "SMART Meter Interface um Netz-Stromzähler mittels IR Lesekopf auszulesen",
    note_url: "/docs/compatible_meters#tasmota"
  },
  {
    manufacturer: "Tinkerforge",
    name: "WARP API",
    connection: "HTTP",
    note: "Siehe MQTT und HTTP Meter API",
    note_url: "/docs/mqtt_http/api_reference/meters",
  },
  {
    manufacturer: "Tinkerforge",
    name: "WARP API",
    connection: "MQTT",
    note: "Siehe MQTT und HTTP Meter API",
    note_url: "/docs/mqtt_http/api_reference/meters",
  },
  {
    manufacturer: "Victron Energy",
    name: "GX und damit verbundene Geräte",
    connection: "Modbus/TCP",
    note: "Alle GX Geräte, z.B.: Cerbo GX und damit verbundene Geräte (Multiplus, Quattro etc.)",
    note_url: "/docs/compatible_meters#victron",
  },
  {
    manufacturer: "YTL",
    name: "DEM4A",
    connection: "WARP Energy Manager",
    note: "Stromzähler direkt am WARP Energy Manager angeschlossen",
    note_url: "/docs/compatible_meters#ytl",
  },
];

// ----------------------------------------------------------------------------
// SortableDataTable column definition
// ----------------------------------------------------------------------------
export const columns = [
 {
    header: "Hersteller",
    accessorKey: "manufacturer",
    className: "sortable-data-table left nowrap",
  },
  {
    header: "Name",
    accessorKey: "name",
    className: "sortable-data-table left nowrap",
  },
  {
    header: "Anbindung",
    accessorKey: "connection",
    className: "sortable-data-table left nowrap",
  },
  {
    header: "Hinweis",
    accessorKey: "note",
    className: "sortable-data-table left",
    cell: ({ cell, row: { original } }) => (original.note != undefined || original.note == "" )? 
      original.note_url != undefined ? (
        <a href={original.note_url}>{cell.getValue()}</a>
      ) : (
        cell.getValue()
    ) : (
      original.note_url != undefined ? (
        <a href={original.note_url}>Weitere Informationen</a>
      ) : (
      "x"
      )
    ),
  },
];
