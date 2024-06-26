import React from "react";

// ----------------------------------------------------------------------------
// Please respect order by manufacturer, then by name, when adding new entries.
// ----------------------------------------------------------------------------
export const meters = [
  {
    manufacturer: "Deye",
    name: "SUN-Serie",
    protocol: "Modbus/TCP",
    note: "Hybrid-Wechselrichter für Nieder- und Hochspannungsbatterien",
    note_url: "/docs/compatible_meters#deye",
  },
  {
    manufacturer: "E3DC",
    name: "Hauskraftwerke",
    protocol: "SunSpec",
    note_url: "/docs/compatible_meters#e3dc",
  },
  {
    manufacturer: "Eastron",
    name: "SDM630",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
    note_url: "/docs/compatible_meters#eastron",
  },
  {
    manufacturer: "Eastron",
    name: "SDM630MCT",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
    note_url: "/docs/compatible_meters#eastron",
  },
  {
    manufacturer: "Eastron",
    name: "SDM72V2",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
    note_url: "/docs/compatible_meters#eastron",
  },
  {
    manufacturer: "elgris",
    name: "Smart Meter LAN 2.0",
    protocol: "SunSpec",
    note_url: "/docs/compatible_meters#elgris",
  },
  {
    manufacturer: "Eltako",
    name: "DSZ15DZMOD",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
    note_url: "/docs/compatible_meters#eltako",
  },
  {
    manufacturer: "Fronius",
    name: "GEN24-Serie",
    protocol: "SunSpec",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#fronius",
  },
  {
    manufacturer: "Fronius",
    name: "Primo- und Symo-Serie",
    protocol: "SunSpec",
    note: "String-Wechselrichter",
    note_url: "/docs/compatible_meters#fronius",
  },
  {
    manufacturer: "Kostal",
    name: "Smart Energy Meter (KSEM G2)",
    protocol: "SunSpec",
    note: "Smart Energy Meter",
    note_url: "/docs/compatible_meters#kostal",
  },
  {
    manufacturer: "Kostal",
    name: "Piko und Plenticore",
    protocol: "SunSpec",
    note: "Wechselrichter",
    note_url: "/docs/compatible_meters#kostal",
  },
  {
    manufacturer: "Shelly",
    name: "Shelly TBD",
    protocol: "HTTP",
    note: "Support für Shelly kommt in Kürze",
    note_url: "/docs/compatible_meters#shelly",
  },
  {
    manufacturer: "SMA",
    name: "Energy Meter 2.0",
    protocol: "SMA Speedwire",
    note: "Smart Meter",
    note_url: "/docs/compatible_meters#sma",
  },
  {
    manufacturer: "SMA",
    name: "Sunny Boy 2.5 / 3.6",
    protocol: "SunSpec",
    note: "Wechselrichter",
    note_url: "/docs/compatible_meters#sma",
  },
  {
    manufacturer: "SMA",
    name: "Sunny Home Manager 1.0 / 2.0",
    protocol: "SMA Speedwire",
    note: "HEMS / Smart Meter",
    note_url: "/docs/compatible_meters#sma",
  },
  {
    manufacturer: "SolarEdge",
    name: "SolarEdge Home Wechselrichter",
    protocol: "SunSpec",
    note: "Wechselrichter inkl. daran angeschlossenen Energiezähler",
    note_url: "/docs/compatible_meters#solaredge",
  },
  {
    manufacturer: "Solarmax",
    name: "Max.Storage",
    protocol: "Modbus/TCP",
    note: "Speichersystem",
    note_url: "/docs/compatible_meters#solarmax",
  },
  {
    manufacturer: "Sungrow",
    name: "SG-Serie",
    protocol: "Modbus/TCP",
    note: "String-Wechselrichter",
    note_url: "/docs/compatible_meters#sungrow",
  },
  {
    manufacturer: "Sungrow",
    name: "SH-Serie",
    protocol: "Modbus/TCP",
    note: "Hybrid-Wechselrichter",
    note_url: "/docs/compatible_meters#sungrow",
  },
  {
    manufacturer: "Tasmota",
    name: "Smart Meter Interface - IR Lesekopf",
    protocol: "HTTP",
    note: "SMART Meter Interface um Stromzähler mittels IR Lesekopf auszulesen",
    note_url: ""
  },
  {
    manufacturer: "Tinkerforge",
    name: "WARP API",
    protocol: "HTTP",
    note: "Siehe MQTT und HTTP Meter API",
    note_url: "/docs/mqtt_http/api_reference/meters",
  },
  {
    manufacturer: "Tinkerforge",
    name: "WARP API",
    protocol: "MQTT",
    note: "Siehe MQTT und HTTP Meter API",
    note_url: "/docs/mqtt_http/api_reference/meters",
  },
  {
    manufacturer: "Victron Energy",
    name: "GX und damit verbundene Geräte",
    protocol: "Modbus/TCP",
    note: "Alle GX Geräte, z.B.: Cerbo GX und damit verbundene Geräte (Multiplus, Quattro etc.)",
    note_url: "/docs/compatible_meters#victron",
  },
  {
    manufacturer: "YTL",
    name: "DEM4A",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
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
    header: "Protokoll",
    accessorKey: "protocol",
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
