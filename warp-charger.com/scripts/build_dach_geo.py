#!/usr/bin/env python3
"""
Build DACH (DE/AT/CH) geometry assets for the electrician-finder map.

Outputs (both committed, both served from /static/tiles/):

  static/tiles/dach.json       FeatureCollection with one MultiPolygon covering
                               Germany + Austria + Switzerland. Used both as the
                               `pmtiles extract --region` clip and as the crisp
                               border-line source in style.json.

  static/tiles/dach-mask.json  FeatureCollection with one Polygon whose outer
                               ring is the whole world and whose holes are the
                               DACH outlines. A semi-transparent fill over this
                               dims everything *outside* DACH while leaving the
                               three countries clear.

Source: Natural Earth 1:10m admin-0 countries (public domain). The raw download
is cached under .bin/ (git-ignored); the two derived files are committed.

Dependencies: Python standard library only.
"""

from __future__ import annotations

import json
import os
import sys
import urllib.request

# This script lives in scripts/; HERE is the warp-charger.com project root.
HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CACHE = os.path.join(HERE, ".bin", "ne_10m_admin_0_countries.geojson")
OUT_DACH = os.path.join(HERE, "static", "tiles", "dach.json")
OUT_MASK = os.path.join(HERE, "static", "tiles", "dach-mask.json")

SOURCE_URL = (
    "https://raw.githubusercontent.com/nvkelso/natural-earth-vector/"
    "master/geojson/ne_10m_admin_0_countries.geojson"
)

# Match on any of the common Natural Earth ISO/admin code fields, so a single
# odd value (NE sometimes sets ISO_A3 to "-99") never drops a country.
TARGETS = {"DEU", "AUT", "CHE"}
CODE_FIELDS = ("ISO_A3", "ISO_A3_EH", "ADM0_A3", "SOV_A3")

PRECISION = 5  # decimal places (~1 m); keeps the committed files small

# World ring in lon/lat. Latitude clamped to the Web-Mercator valid range so the
# fill covers the entire visible map without spilling into undefined territory.
WORLD_RING = [
    [-180.0, -85.0511],
    [180.0, -85.0511],
    [180.0, 85.0511],
    [-180.0, 85.0511],
    [-180.0, -85.0511],
]


def log(msg: str) -> None:
    print(msg, file=sys.stderr)


def fetch_source() -> dict:
    if not os.path.exists(CACHE):
        os.makedirs(os.path.dirname(CACHE), exist_ok=True)
        log("Downloading Natural Earth 10m admin-0 countries ...")
        log(f"  {SOURCE_URL}")
        urllib.request.urlretrieve(SOURCE_URL, CACHE)
    else:
        log(f"Using cached source: {os.path.relpath(CACHE, HERE)}")
    with open(CACHE, encoding="utf-8") as fh:
        return json.load(fh)


def iso_codes(props: dict) -> set:
    codes = set()
    for key in CODE_FIELDS:
        val = props.get(key)
        if isinstance(val, str):
            codes.add(val)
    return codes


def round_ring(ring):
    return [[round(pt[0], PRECISION), round(pt[1], PRECISION)] for pt in ring]


def polygons_of(geom):
    """Yield each polygon (a list of rings) from a Polygon/MultiPolygon."""
    kind = geom.get("type")
    if kind == "Polygon":
        yield geom["coordinates"]
    elif kind == "MultiPolygon":
        yield from geom["coordinates"]
    else:
        log(f"  skipping unexpected geometry type: {kind!r}")


def feature_collection(geometry, name):
    return {
        "type": "FeatureCollection",
        "features": [
            {"type": "Feature", "properties": {"name": name}, "geometry": geometry}
        ],
    }


def write_json(path, obj):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(obj, fh, separators=(",", ":"))
        fh.write("\n")
    size_kb = os.path.getsize(path) / 1024
    log(f"  wrote {os.path.relpath(path, HERE)} ({size_kb:.0f} KB)")


def bbox_of(polygons):
    xs = [pt[0] for poly in polygons for pt in poly[0]]
    ys = [pt[1] for poly in polygons for pt in poly[0]]
    return min(xs), min(ys), max(xs), max(ys)


def main() -> int:
    data = fetch_source()

    dach_polygons = []  # list of polygons (each a list of rings)
    matched = []
    for feat in data.get("features", []):
        props = feat.get("properties") or {}
        if iso_codes(props) & TARGETS:
            name = props.get("ADMIN") or props.get("NAME") or "?"
            polys = [
                [round_ring(r) for r in poly]
                for poly in polygons_of(feat.get("geometry") or {})
            ]
            dach_polygons.extend(polys)
            matched.append((name, len(polys)))

    if not matched:
        log("ERROR: no DEU/AUT/CHE features matched - Natural Earth schema change?")
        return 1

    for name, count in sorted(matched):
        log(f"  matched {name}: {count} polygon(s)")

    bbox = bbox_of(dach_polygons)
    log("  DACH bbox: {:.3f},{:.3f},{:.3f},{:.3f}".format(*bbox))

    # dach.json: full MultiPolygon (rings incl. interior holes).
    write_json(
        OUT_DACH,
        feature_collection(
            {"type": "MultiPolygon", "coordinates": dach_polygons}, "DACH"
        ),
    )

    # dach-mask.json: world rectangle (outer ring) with each DACH outer ring as
    # a hole. Interior holes/enclaves are intentionally ignored (negligible).
    mask_rings = [round_ring(WORLD_RING)] + [poly[0] for poly in dach_polygons]
    write_json(
        OUT_MASK,
        feature_collection({"type": "Polygon", "coordinates": mask_rings}, "dach-mask"),
    )

    log("Done.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
