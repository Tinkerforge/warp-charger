"""On-demand address lookup with a persistent cache and cross-worker throttle."""

import json
import math
import time
import urllib.error
import urllib.parse
import urllib.request

from electrician_store import ADDRESS_FIELDS, connect

COUNTRIES = {"DE": "Deutschland", "AT": "Österreich", "CH": "Schweiz"}
NOMINATIM_URL = "https://nominatim.openstreetmap.org/search"
USER_AGENT = "warp-charger.com electrician-finder geocoder (info@tinkerforge.com)"


class GeocodingError(Exception):
    pass


def address_key(data):
    return json.dumps([data[key].strip().casefold() for key in ADDRESS_FIELDS], ensure_ascii=False)


def coordinates(lat, lon):
    try:
        lat, lon = float(lat), float(lon)
    except (ValueError, TypeError):
        raise ValueError("Bitte gültige Breiten- und Längengrade eingeben.") from None
    if not math.isfinite(lat) or not math.isfinite(lon) or not -90 <= lat <= 90 or not -180 <= lon <= 180:
        raise ValueError("Koordinaten liegen außerhalb des gültigen Bereichs.")
    return round(lat, 6), round(lon, 6)


def lookup(query, country):
    params = {"q": query, "format": "jsonv2", "limit": 1, "addressdetails": 1,
              "countrycodes": country.lower()}
    req = urllib.request.Request(NOMINATIM_URL + "?" + urllib.parse.urlencode(params),
                                 headers={"User-Agent": USER_AGENT, "Accept": "application/json"})
    try:
        with urllib.request.urlopen(req, timeout=4) as response:
            results = json.loads(response.read(1_000_000).decode("utf-8"))
        if not isinstance(results, list):
            raise ValueError("Unexpected geocoder response")
        if not results:
            return None
        result = results[0]
        lat, lon = coordinates(result["lat"], result["lon"])
        precise = bool(result.get("address", {}).get("house_number"))
        return {"lat": lat, "lon": lon, "source": "address" if precise else "approximate",
                "label": result.get("display_name", query)}
    except (OSError, ValueError, KeyError, TypeError, IndexError, AttributeError) as exc:
        raise GeocodingError("Adresssuche derzeit nicht verfügbar. Bitte erneut versuchen oder den Standort manuell setzen.") from exc


def geocode(path, data, refresh=False):
    key = address_key(data)
    with connect(path) as db:
        cached = db.execute("SELECT result FROM geocode_cache WHERE address = ?", (key,)).fetchone()
    if cached and not refresh:
        return json.loads(cached["result"])

    country = COUNTRIES[data["country"]]
    queries = [f"{data['street']}, {data['postal_code']} {data['city']}, {country}",
               f"{data['postal_code']} {data['city']}, {country}", f"{data['city']}, {country}"]
    for index, query in enumerate(queries):
        # Reserve a request slot atomically, then release SQLite before sleeping/network I/O.
        with connect(path) as db:
            db.execute("BEGIN IMMEDIATE")
            row = db.execute("SELECT value FROM rate_limits WHERE key = 'geocoding'").fetchone()
            now = time.time()
            slot = max(now, row["value"] if row else now)
            if slot - now > 4:
                raise GeocodingError("Adresssuche ist beschäftigt. Bitte in einigen Sekunden erneut versuchen.")
            db.execute("INSERT OR REPLACE INTO rate_limits VALUES ('geocoding', ?, 0)", (slot + 1.1,))
        time.sleep(max(0, slot - time.time()))
        result = lookup(query, data["country"])
        if result:
            if index:
                result["source"] = "approximate"
            with connect(path) as db:
                db.execute("INSERT OR REPLACE INTO geocode_cache VALUES (?, ?)", (key, json.dumps(result)))
            return result
    raise GeocodingError("Adresse nicht gefunden. Bitte Adresse korrigieren oder den Standort manuell setzen.")
