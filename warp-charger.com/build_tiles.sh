#!/usr/bin/env bash
#
# Build the self-hosted basemap assets for the electrician finder:
#   - static/tiles/basemap.pmtiles  (DACH cutout of the Protomaps v4 basemap)
#   - static/tiles/fonts/...        (glyphs for cluster-count digits)
#
# All map data is served from our own origin afterwards, so the running site
# makes zero third-party requests for the map.
#
# Tunable via environment variables:
#   MAXZOOM  highest zoom level to include           (default 9, ~90 MB)
#   REGION   GeoJSON Polygon/MultiPolygon to clip to (default: static/tiles/dach.json)
#   BBOX     min_lon,min_lat,max_lon,max_lat         (fallback if REGION unset)
#   SRC      source pmtiles archive (local or URL)   (default: Protomaps daily)

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

PMTILES_VERSION="1.30.3"
MAXZOOM="${MAXZOOM:-9}"
# Clip to the exact DACH outline (Germany+Austria+Switzerland) rather than a
# rectangle, so the basemap carries no neighbouring-country tiles. BBOX is kept
# as a fallback for `REGION=` overrides that point at a bare bbox build.
REGION="${REGION:-static/tiles/dach.json}"
BBOX="${BBOX:-5.5,45.5,17.4,55.3}"
SRC="${SRC:-https://data.source.coop/protomaps/openstreetmap/v4.pmtiles}"

BIN_DIR=".bin"
PMTILES_BIN="$BIN_DIR/pmtiles"
TILES_DIR="static/tiles"
OUT="$TILES_DIR/basemap.pmtiles"
FONTS_DIR="$TILES_DIR/fonts"
FONT_NAME="Noto Sans Regular"
FONT_BASE_URL="https://protomaps.github.io/basemaps-assets/fonts"

mkdir -p "$BIN_DIR" "$TILES_DIR"

# --- 1. Ensure the go-pmtiles CLI is available -----------------------------
if [ ! -x "$PMTILES_BIN" ]; then
    echo "Downloading go-pmtiles ${PMTILES_VERSION}..."
    case "$(uname -m)" in
        x86_64|amd64) ARCH="x86_64" ;;
        aarch64|arm64) ARCH="arm64" ;;
        *) echo "Unsupported architecture: $(uname -m)" >&2; exit 1 ;;
    esac
    URL="https://github.com/protomaps/go-pmtiles/releases/download/v${PMTILES_VERSION}/go-pmtiles_${PMTILES_VERSION}_Linux_${ARCH}.tar.gz"
    curl -sSL "$URL" -o "$BIN_DIR/go-pmtiles.tar.gz"
    tar -xzf "$BIN_DIR/go-pmtiles.tar.gz" -C "$BIN_DIR" pmtiles
    rm -f "$BIN_DIR/go-pmtiles.tar.gz"
    chmod +x "$PMTILES_BIN"
fi

# --- 2. Extract the DACH cutout --------------------------------------------
if [ -n "$REGION" ]; then
    # Build the DACH region geometry on demand (also produces the map mask).
    if [ ! -f "$REGION" ]; then
        echo "Region geometry $REGION missing, generating with build_dach_geo.py..."
        if [ -x ".venv/bin/python" ]; then
            .venv/bin/python scripts/build_dach_geo.py
        else
            python3 scripts/build_dach_geo.py
        fi
    fi
    echo "Extracting basemap (region=$REGION maxzoom=$MAXZOOM)..."
    echo "  source: $SRC"
    "$PMTILES_BIN" extract "$SRC" "$OUT" --region="$REGION" --maxzoom="$MAXZOOM"
else
    echo "Extracting basemap (bbox=$BBOX maxzoom=$MAXZOOM)..."
    echo "  source: $SRC"
    "$PMTILES_BIN" extract "$SRC" "$OUT" --bbox="$BBOX" --maxzoom="$MAXZOOM"
fi
echo "Done: $OUT ($(du -h "$OUT" | cut -f1))"

# --- 3. Fetch glyphs (digits only) for cluster-count labels ----------------
# Range 0-255 covers ASCII digits, which is all the cluster counters render.
GLYPH_DIR="$FONTS_DIR/$FONT_NAME"
if [ ! -f "$GLYPH_DIR/0-255.pbf" ]; then
    echo "Downloading glyphs for '$FONT_NAME'..."
    mkdir -p "$GLYPH_DIR"
    ENC_NAME="${FONT_NAME// /%20}"
    curl -sSL "$FONT_BASE_URL/$ENC_NAME/0-255.pbf" -o "$GLYPH_DIR/0-255.pbf"
fi
echo "Done: $GLYPH_DIR/0-255.pbf"

echo "Basemap assets ready in $TILES_DIR/"
