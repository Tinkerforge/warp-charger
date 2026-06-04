#!/usr/bin/env python3
"""
Parses devices.table.js from docs.warp-charger.com and generates
a JSON file for use in the warp-charger.com compatible devices page.
"""

import json
import re
from pathlib import Path

# This script lives in scripts/; ROOT is the warp-charger.com project root.
ROOT = Path(__file__).resolve().parent.parent
DOCS_TABLE = ROOT.parent / "docs.warp-charger.com" / "docs" / "compatible_devices" / "devices.table.js"
OUTPUT = ROOT / "data" / "compatible_devices.json"

# Logo file mapping: manufacturer name -> logo filename (without extension)
LOGO_MAP = {
    "Alpha ESS": "alpha_ess",
    "APsystems": "apsystems",
    "BYD": "byd",
    "Carlo Galvazzi": "carlo_gavazzi",  # note: typo in docs source
    "Carlo Gavazzi": "carlo_gavazzi",
    "Chisage": "chisage",
    "Deye": "deye",
    "E3DC": "e3dc",
    "Eastron": "eastron",
    "elgris": "elgris",
    "Eltako": "eltako",
    "Fox ESS": "foxess",
    "Fronius": "fronius",
    "Goodwe": "goodwe",
    "Growatt": "growatt",
    "Hailei": "hailei",
    "Hoymiles": "hoymiles",
    "Huawei": "huawei",
    "Janitza": "janitza",
    "Kaco": "kaco",
    "Kostal": "kostal",
    "Q-Cells": "qcells",
    "RCT": "rct_power",
    "SAX Power": "sax_power",
    "Shelly": "shelly",
    "Siemens": "siemens",
    "SMA": "sma",
    "SolarEdge": "solaredge",
    "Solarmax": None,
    "Solax": "solax",
    "Solis": "solis",
    "Sungrow": "sungrow",
    "Tasmota": "tasmota",
    "Tinkerforge": None,
    "Varta": "varta",
    "Victron Energy": "victron",
    "YTL": "ytl",
}


def parse_devices_js(path: Path) -> list[dict]:
    """Parse the JS devices array into Python dicts."""
    content = path.read_text()

    # Extract the devices array content
    match = re.search(r"export const devices\s*=\s*\[(.+?)\n\];", content, re.DOTALL)
    if not match:
        raise ValueError("Could not find 'export const devices' array")

    array_content = match.group(1)

    # Parse each object {...}
    devices = []
    for obj_match in re.finditer(r"\{([^}]+)\}", array_content):
        obj_str = obj_match.group(1)
        device = {}
        for field_match in re.finditer(r'(\w+)\s*:\s*"([^"]*)"', obj_str):
            device[field_match.group(1)] = field_match.group(2)
        if device:
            devices.append(device)

    return devices


def aggregate_by_manufacturer(devices: list[dict]) -> list[dict]:
    """Group devices by manufacturer and aggregate their properties."""
    manufacturers = {}

    for d in devices:
        name = d.get("manufacturer", "")
        if name not in manufacturers:
            manufacturers[name] = {
                "name": name,
                "devices": [],
                "interfaces": set(),
                "roles": set(),
                "features": set(),
                "link": d.get("link", ""),
            }

        m = manufacturers[name]
        m["devices"].append(d.get("device", ""))

        # Collect interfaces
        conn = d.get("connection", "")
        for iface in re.split(r",\s*", conn):
            if iface:
                m["interfaces"].add(iface)

        # Collect measurement roles
        if d.get("grid") in ("x", "(x)"):
            m["roles"].add("Netzanschluss")
        if d.get("pv") in ("x", "(x)"):
            m["roles"].add("PV-Erzeugung")
        if d.get("battery") in ("x", "(x)"):
            m["roles"].add("Batteriespeicher")
        if d.get("load") in ("x", "(x)"):
            m["roles"].add("Verbraucher")

        # Collect features
        if d.get("pve") in ("x", "(x)"):
            m["features"].add("PVÜ")
        if d.get("dlm") in ("x", "(x)"):
            m["features"].add("dLM")
        if d.get("bat") in ("x", "(x)"):
            m["features"].add("BS")

    # Convert to sorted list with serializable types
    result = []
    for name, m in manufacturers.items():
        logo = LOGO_MAP.get(name)
        if logo is None:
            continue  # Skip manufacturers without logos

        docs_url = "https://docs.warp-charger.com/de" + m["link"] if m["link"] else ""

        result.append({
            "name": name,
            "file": logo,
            "interfaces": sorted(m["interfaces"]),
            "roles": sorted(m["roles"]),
            "features": sorted(m["features"]),
            "models": ", ".join(m["devices"]),
            "docs_url": docs_url,
        })

    # Sort by name
    result.sort(key=lambda x: x["name"].lower())
    return result


# Manufacturers not in devices.table.js but should appear on website
EXTRA_MANUFACTURERS = []


def main():
    print(f"Reading: {DOCS_TABLE}")
    devices = parse_devices_js(DOCS_TABLE)
    print(f"  Parsed {len(devices)} device entries")

    aggregated = aggregate_by_manufacturer(devices)
    aggregated.extend(EXTRA_MANUFACTURERS)
    aggregated.sort(key=lambda x: x["name"].lower())
    print(f"  Aggregated into {len(aggregated)} manufacturers (with logos)")

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(aggregated, indent=2, ensure_ascii=False) + "\n")
    print(f"  Written: {OUTPUT}")


if __name__ == "__main__":
    main()
