#!/usr/bin/env python3
"""
Geocode the electrician directory.

Reads ``data/electricians.csv``, resolves each entry's
address to coordinates and writes ``data/electricians.geocoded.json`` for the
"find an electrician" page.

Geocoding uses the public OpenStreetMap Nominatim service. Results are cached
in ``data/geocode_cache.json`` keyed by the normalized address, so unchanged
rows are never re-requested. This call happens at build time only.

Rows may pre-supply ``lat``/``lon`` columns to skip geocoding entirely.

Usage:
    python scripts/geocode_electricians.py            # geocode (uses/updates cache)
    python scripts/geocode_electricians.py --offline  # never hit the network; cache only
"""

import argparse
import csv
import json
import re
import sys
import time
import urllib.parse
import urllib.request
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent  # project root (this script lives in scripts/)
CSV_PATH = BASE_DIR / "data" / "electricians.csv"
OUTPUT_PATH = BASE_DIR / "data" / "electricians.geocoded.json"
CACHE_PATH = BASE_DIR / "data" / "geocode_cache.json"

NOMINATIM_URL = "https://nominatim.openstreetmap.org/search"
USER_AGENT = "warp-charger.com electrician-finder geocoder (info@tinkerforge.com)"
REQUEST_INTERVAL = 1.1  # seconds between Nominatim requests (usage policy: <= 1/s)

COUNTRY_NAMES = {"DE": "Deutschland", "AT": "Österreich", "CH": "Schweiz"}


def slugify(value: str) -> str:
    """Make a stable, URL/DOM-safe id from a name."""
    value = value.lower()
    replacements = {"ä": "ae", "ö": "oe", "ü": "ue", "ß": "ss", "é": "e", "è": "e", "à": "a"}
    for src, dst in replacements.items():
        value = value.replace(src, dst)
    value = re.sub(r"[^a-z0-9]+", "-", value).strip("-")
    return value or "electrician"


def normalize_address(row: dict) -> str:
    """Build a canonical address string used for geocoding + cache keys."""
    parts = [
        row.get("street", "").strip(),
        f"{row.get('postal_code', '').strip()} {row.get('city', '').strip()}".strip(),
        COUNTRY_NAMES.get(row.get("country", "").strip().upper(), row.get("country", "").strip()),
    ]
    return ", ".join(p for p in parts if p)


def load_cache() -> dict:
    if CACHE_PATH.exists():
        try:
            return json.loads(CACHE_PATH.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            print(f"  ! cache at {CACHE_PATH} is corrupt, starting fresh", file=sys.stderr)
    return {}


def save_cache(cache: dict) -> None:
    CACHE_PATH.write_text(json.dumps(cache, indent=2, ensure_ascii=False, sort_keys=True) + "\n", encoding="utf-8")


def nominatim_lookup(query: str, country: str) -> dict | None:
    """Query Nominatim for a single best match. Returns {'lat','lon'} or None."""
    params = {"q": query, "format": "jsonv2", "limit": "1", "addressdetails": "0"}
    cc = country.strip().lower()
    if cc in ("de", "at", "ch"):
        params["countrycodes"] = cc
    url = f"{NOMINATIM_URL}?{urllib.parse.urlencode(params)}"
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT, "Accept": "application/json"})
    try:
        with urllib.request.urlopen(req, timeout=20) as resp:
            results = json.loads(resp.read().decode("utf-8"))
    except Exception as exc:  # noqa: BLE001 - network/parse errors -> skip gracefully
        print(f"  ! Nominatim error for {query!r}: {exc}", file=sys.stderr)
        return None
    if not results:
        return None
    return {"lat": round(float(results[0]["lat"]), 6), "lon": round(float(results[0]["lon"]), 6)}


def geocode_row(row: dict, cache: dict, offline: bool, throttle: list) -> dict | None:
    """Resolve coordinates for one row using (in order) explicit columns, cache, Nominatim."""
    # 1. Explicit coordinates in the CSV win.
    lat, lon = row.get("lat", "").strip(), row.get("lon", "").strip()
    if lat and lon:
        return {"lat": round(float(lat), 6), "lon": round(float(lon), 6)}

    key = normalize_address(row)
    if key in cache:
        return cache[key]

    if offline:
        print(f"  ! no cached coordinates for {key!r} (offline)", file=sys.stderr)
        return None

    country = row.get("country", "").strip().upper()
    # Try most-specific query first, then progressively coarser fallbacks.
    queries = [
        normalize_address(row),
        f"{row.get('postal_code', '').strip()} {row.get('city', '').strip()}, {COUNTRY_NAMES.get(country, country)}",
        f"{row.get('city', '').strip()}, {COUNTRY_NAMES.get(country, country)}",
    ]
    for query in queries:
        if not query.strip(" ,"):
            continue
        # Throttle: at most one request per REQUEST_INTERVAL.
        wait = REQUEST_INTERVAL - (time.monotonic() - throttle[0])
        if wait > 0:
            time.sleep(wait)
        throttle[0] = time.monotonic()

        coords = nominatim_lookup(query, country)
        if coords:
            cache[key] = coords
            return coords
    print(f"  ! could not geocode {key!r}", file=sys.stderr)
    return None


def main() -> int:
    parser = argparse.ArgumentParser(description="Geocode the electrician directory CSV.")
    parser.add_argument("--offline", action="store_true", help="use only cached coordinates, never hit the network")
    args = parser.parse_args()

    if not CSV_PATH.exists():
        print(f"No CSV at {CSV_PATH}; nothing to do.")
        OUTPUT_PATH.write_text("[]\n", encoding="utf-8")
        return 0

    cache = load_cache()
    throttle = [0.0]  # mutable holder for the timestamp of the last request

    with CSV_PATH.open(encoding="utf-8-sig", newline="") as f:
        rows = list(csv.DictReader(f))

    print(f"Geocoding {len(rows)} electricians from {CSV_PATH.name} ...")
    electricians = []
    missing = 0
    for row in rows:
        name = row.get("name", "").strip()
        if not name:
            continue
        coords = geocode_row(row, cache, args.offline, throttle)
        if not coords:
            missing += 1
            continue
        electricians.append({
            "id": slugify(name),
            "name": name,
            "street": row.get("street", "").strip(),
            "postal_code": row.get("postal_code", "").strip(),
            "city": row.get("city", "").strip(),
            "country": row.get("country", "").strip().upper(),
            "phone": row.get("phone", "").strip(),
            "email": row.get("email", "").strip(),
            "website": row.get("website", "").strip(),
            "lat": coords["lat"],
            "lon": coords["lon"],
        })

    # Stable order -> clean diffs.
    electricians.sort(key=lambda e: (e["country"], e["city"], e["name"]))

    # Ensure ids are unique even when two rows share a company name, so the
    # map<->list highlighting and DOM ids never collide (-2, -3, ... suffixes).
    seen: dict = {}
    for e in electricians:
        base = e["id"]
        seen[base] = seen.get(base, 0) + 1
        if seen[base] > 1:
            e["id"] = f"{base}-{seen[base]}"

    save_cache(cache)
    OUTPUT_PATH.write_text(json.dumps(electricians, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(f"  Wrote {len(electricians)} entries to {OUTPUT_PATH.name}"
          + (f" ({missing} could not be geocoded)" if missing else ""))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
