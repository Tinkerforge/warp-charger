import React from "react";

// ----------------------------------------------------------------------------
// Please respect order by name when adding new entries.
// ----------------------------------------------------------------------------
export const meters = [
  {
    name: "Color Control GX",
    manufacturer: "Victron Energy",
    protocol: "Modbus/TCP",
    note: "Support für Victron Energy kommt in Kürze",
  },
  {
    name: "DEM4A",
    manufacturer: "YTL",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager",
  },
  {
    name: "DSZ15DZMOD",
    manufacturer: "Eltako",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager",
  },
  {
    name: "Energy Meter 2.0",
    manufacturer: "SMA",
    protocol: "Speedwire",
    note: "",
  },
  {
    name: "Hybrid Wechselrichter",
    manufacturer: "Deye",
    protocol: "Modbus/TCP",
    note: "Support für Deye kommt in Kürze",
  },
  {
    name: "Hybrid Wechselrichter (SH Serie)",
    manufacturer: "Sungrow",
    protocol: "Modbus/TCP",
    note: "Support für Sungrow kommt in Kürze",
  },
  {
    name: "SDM630",
    manufacturer: "Eastron",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager",
  },
  {
    name: "SDM630MCT",
    manufacturer: "Eastron",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager",
  },
  {
    name: "SDM72V2",
    manufacturer: "Eastron",
    protocol: "Modbus/RTU",
    note: "Nur über WARP Energy Manager",
  },
  {
    name: "Shelly TBD",
    manufacturer: "Shelly",
    protocol: "HTTP",
    note: "Support für Shelly kommt in Kürze",
  },
  {
    name: "Smart Energy Meter (KSEM G2)",
    manufacturer: "Kostal",
    protocol: "SunSpec",
    note: "",
  },
  {
    name: "Smart Meter LAN 2.0",
    manufacturer: "elgris",
    protocol: "SunSpec",
    note: "",
  },
  {
    name: "String Wechselrichter (SG Serie)",
    manufacturer: "Sungrow",
    protocol: "Modbus/TCP",
    note: "Support für Sungrow kommt in Kürze",
  },
  {
    name: "Sunny Boy 2.5",
    manufacturer: "SMA",
    protocol: "SunSpec",
    note: "",
  },
  {
    name: "Sunny Boy 3.6",
    manufacturer: "SMA",
    protocol: "SunSpec",
    note: "",
  },
  {
    name: "Sunny Home Manager 1.0/2.0",
    manufacturer: "SMA",
    protocol: "Speedwire",
    note: "",
  },
  {
    name: "Symo 8.2-3-M",
    manufacturer: "Fronius",
    protocol: "SunSpec",
    note: "",
  },
  {
    name: "Symo 12.5-3",
    manufacturer: "Fronius",
    protocol: "SunSpec",
    note: "",
  },
  {
    name: "WARP Push-API",
    manufacturer: "Tinkerforge",
    protocol: "HTTP",
    note: "Siehe MQTT und HTTP API -> API-Referenz -> meters",
    note_url: "https://docs.warp-charger.com/mqtt_http/api_referenz/meters",
  },
  {
    name: "WARP Push-API",
    manufacturer: "Tinkerforge",
    protocol: "MQTT",
    note: "Siehe MQTT und HTTP API -> API-Referenz -> meters",
    note_url: "https://docs.warp-charger.com/mqtt_http/api_referenz/meters",
  },
];

// ----------------------------------------------------------------------------
// SortableDataTable column definition
// ----------------------------------------------------------------------------
export const columns = [
  {
    header: "Name",
    accessorKey: "name",
    className: "sortable-data-table left nowrap",
  },
  {
    header: "Hersteller",
    accessorKey: "manufacturer",
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
