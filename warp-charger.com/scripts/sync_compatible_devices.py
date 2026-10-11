#!/usr/bin/env python3
"""
Parses the German and English devices.table.js from docs.warp-charger.com and
generates a JSON file (one manufacturer list per language) for use in the
warp-charger.com compatible devices page.
"""

import json
import re
from pathlib import Path

# This script lives in scripts/; ROOT is the warp-charger.com project root.
ROOT = Path(__file__).resolve().parent.parent
DOCS = ROOT.parent / "docs.warp-charger.com"
DOCS_TABLES = {
    "de": DOCS / "docs" / "compatible_devices" / "devices.table.js",
    "en": DOCS / "i18n" / "en" / "docusaurus-plugin-content-docs" / "current" / "compatible_devices" / "devices.table.js",
}
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
    "Solarmax": "solarmax",
    "Solax": "solax",
    "Solis": "solis",
    "Sonnen": "sonnen",
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


# Measurement locations (same wording as the "measurement" section of the page) and features per language
ROLE_NAMES = {
    "de": {"grid": "Netzanschluss", "pv": "PV-Erzeugung", "battery": "Batteriespeicher", "load": "Verbraucher"},
    "en": {"grid": "Grid Connection", "pv": "PV Generation", "battery": "Battery Storage", "load": "Consumers"},
}
FEATURE_NAMES = {
    "de": {"pve": "PVÜ", "dlm": "dLM", "bat": "BS"},
    "en": {"pve": "PVE", "dlm": "DLM", "bat": "BC"},
}


def aggregate_by_manufacturer(devices: list[dict], lang: str) -> list[dict]:
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
        for key, role in ROLE_NAMES[lang].items():
            if d.get(key) in ("x", "(x)"):
                m["roles"].add(role)

        # Collect features
        for key, feature in FEATURE_NAMES[lang].items():
            if d.get(key) in ("x", "(x)"):
                m["features"].add(feature)

    # Convert to sorted list with serializable types
    result = []
    for name, m in manufacturers.items():
        logo = LOGO_MAP.get(name)
        if logo is None:
            continue  # Skip manufacturers without logos

        docs_url = f"https://docs.warp-charger.com/{lang}" + m["link"] if m["link"] else ""

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


# Manufacturers not in devices.table.js but should appear on website (per language)
EXTRA_MANUFACTURERS = {"de": [], "en": []}


def main():
    result = {}
    for lang, table in DOCS_TABLES.items():
        print(f"Reading: {table}")
        devices = parse_devices_js(table)
        print(f"  Parsed {len(devices)} device entries")

        aggregated = aggregate_by_manufacturer(devices, lang)
        aggregated.extend(EXTRA_MANUFACTURERS[lang])
        aggregated.sort(key=lambda x: x["name"].lower())
        print(f"  Aggregated into {len(aggregated)} manufacturers (with logos)")
        result[lang] = aggregated

    names = {lang: [m["name"] for m in ms] for lang, ms in result.items()}
    if names["de"] != names["en"]:
        print(f"  WARNING: manufacturers differ between the languages: "
              f"only de {sorted(set(names['de']) - set(names['en']))}, only en {sorted(set(names['en']) - set(names['de']))}")

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n")
    print(f"  Written: {OUTPUT}")


if __name__ == "__main__":
    main()
