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
  },
  {
    manufacturer: "Eastron",
    name: "SDM630",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
  },
  {
    manufacturer: "Eastron",
    name: "SDM630MCT",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
  },
  {
    manufacturer: "Eastron",
    name: "SDM72V2",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
  },
  {
    manufacturer: "elgris",
    name: "Smart Meter LAN 2.0",
    protocol: "SunSpec",
    note: "",
  },
  {
    manufacturer: "Eltako",
    name: "DSZ15DZMOD",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
  },
  {
    manufacturer: "Fronius",
    name: "GEN24-Serie",
    protocol: "SunSpec",
    note: "Hybrid-Wechselrichter",
  },
  {
    manufacturer: "Fronius",
    name: "Symo-Serie",
    protocol: "SunSpec",
    note: "String-Wechselrichter",
  },
  {
    manufacturer: "Kostal",
    name: "Smart Energy Meter (KSEM G2)",
    protocol: "SunSpec",
    note: "",
  },
  {
    manufacturer: "Shelly",
    name: "Shelly TBD",
    protocol: "HTTP",
    note: "Support für Shelly kommt in Kürze",
  },
  {
    manufacturer: "SMA",
    name: "Energy Meter 2.0",
    protocol: "SMA Speedwire",
    note: "",
  },
  {
    manufacturer: "SMA",
    name: "Sunny Boy 2.5 / 3.6",
    protocol: "SunSpec",
    note: "",
  },
  {
    manufacturer: "SMA",
    name: "Sunny Home Manager 1.0 / 2.0",
    protocol: "SMA Speedwire",
    note: "",
  },
  {
    manufacturer: "Solarmax",
    name: "Max.Storage",
    protocol: "Modbus/TCP",
    note: "Support für Solarmax folgt in Kürze",
  },
  {
    manufacturer: "Sungrow",
    name: "SG-Serie",
    protocol: "Modbus/TCP",
    note: "String-Wechselrichter",
  },
  {
    manufacturer: "Sungrow",
    name: "SH-Serie",
    protocol: "Modbus/TCP",
    note: "Hybrid-Wechselrichter",
  },
  {
    manufacturer: "Tasmota",
    name: "Smart Meter Interface - IR Lesekopf",
    protocol: "HTTP",
    note: "SMART Meter Interface um Stromzähler mittels IR Lesekopf auszulesen",
    note_url: "https://www.tinkerunity.org/topic/12255-z%C3%A4hler-des-netzbetreibers-sml-ir-hichi%E2%80%A6-f%C3%BCr-pv-%C3%BCberschuss/?do=findComment&comment=55374"
  },
  {
    manufacturer: "Tinkerforge",
    name: "WARP Push-API",
    protocol: "HTTP",
    note: "Siehe MQTT und HTTP API -> API-Referenz -> meters",
    note_url: "https://docs.warp-charger.com/docs/mqtt_http/api_reference/meters",
  },
  {
    manufacturer: "Tinkerforge",
    name: "WARP Push-API",
    protocol: "MQTT",
    note: "Siehe MQTT und HTTP API -> API-Referenz -> meters",
    note_url: "https://docs.warp-charger.com/docs/mqtt_http/api_reference/meters",
  },
  {
    manufacturer: "Victron Energy",
    name: "GX Geräte",
    protocol: "Modbus/TCP",
    note: "Alle GX Geräte, z.B.: Cerbo GX",
  },
  {
    manufacturer: "YTL",
    name: "DEM4A",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager (direkt angeschlossen)",
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
    cell: ({ cell, row: { original } }) => original.note_url != undefined ? (
      <a href={original.note_url}>
        {cell.getValue()}
      </a>
    ) : (
      cell.getValue()
    ),
  },
];
