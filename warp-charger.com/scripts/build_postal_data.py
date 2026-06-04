#!/usr/bin/env python3
"""
Build the DACH postal-code -> coordinates dataset used for the "find an
electrician" zip-code search.

Downloads the GeoNames postal-code exports for Germany, Austria and
Switzerland and condenses them into ``data/postal_dach.json``:

    {
      "DE": {"10115": {"lat": 52.5323, "lon": 13.3846, "place": "Berlin"}, ...},
      "AT": {...},
      "CH": {...}
    }

Where a postal code maps to several places the
coordinates are averaged to a centroid and the first place name is kept.

Data: GeoNames (https://www.geonames.org/), licensed CC BY 4.0.
"""

import io
import json
import sys
import urllib.request
import zipfile
from collections import defaultdict
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent  # project root (this script lives in scripts/)
OUTPUT_PATH = BASE_DIR / "data" / "postal_dach.json"
COUNTRIES = ("DE", "AT", "CH")
DOWNLOAD_URL = "https://download.geonames.org/export/zip/{cc}.zip"
USER_AGENT = "warp-charger.com postal-data builder (info@tinkerforge.com)"


def fetch_country(cc: str) -> bytes:
    url = DOWNLOAD_URL.format(cc=cc)
    print(f"  downloading {url} ...")
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    with urllib.request.urlopen(req, timeout=60) as resp:
        return resp.read()


def parse_country(cc: str, payload: bytes) -> dict:
    """Parse a GeoNames {cc}.txt (tab-separated) into {plz: {lat, lon, place}}."""
    with zipfile.ZipFile(io.BytesIO(payload)) as zf:
        text = zf.read(f"{cc}.txt").decode("utf-8")

    # GeoNames postal format columns (tab separated):
    # 0 country, 1 postal_code, 2 place_name, 3 admin1, 4 admin1_code,
    # 5 admin2, 6 admin2_code, 7 admin3, 8 admin3_code, 9 lat, 10 lon, 11 accuracy
    grouped = defaultdict(lambda: {"lats": [], "lons": [], "place": ""})
    for line in text.splitlines():
        cols = line.split("\t")
        if len(cols) < 11:
            continue
        plz, place, lat, lon = cols[1].strip(), cols[2].strip(), cols[9].strip(), cols[10].strip()
        if not plz or not lat or not lon:
            continue
        try:
            latf, lonf = float(lat), float(lon)
        except ValueError:
            continue
        entry = grouped[plz]
        entry["lats"].append(latf)
        entry["lons"].append(lonf)
        if not entry["place"]:
            entry["place"] = place

    result = {}
    for plz, entry in grouped.items():
        n = len(entry["lats"])
        result[plz] = {
            "lat": round(sum(entry["lats"]) / n, 4),
            "lon": round(sum(entry["lons"]) / n, 4),
            "place": entry["place"],
        }
    return result


def main() -> int:
    data = {}
    for cc in COUNTRIES:
        try:
            payload = fetch_country(cc)
            data[cc] = parse_country(cc, payload)
            print(f"  {cc}: {len(data[cc])} postal codes")
        except Exception as exc:  # noqa: BLE001
            print(f"  ! failed for {cc}: {exc}", file=sys.stderr)
            data[cc] = {}

    if not any(data.values()):
        print("No postal data downloaded; leaving existing file untouched.", file=sys.stderr)
        return 1

    OUTPUT_PATH.write_text(json.dumps(data, ensure_ascii=False, separators=(",", ":")) + "\n", encoding="utf-8")
    total = sum(len(v) for v in data.values())
    print(f"  Wrote {total} postal codes to {OUTPUT_PATH.name}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
