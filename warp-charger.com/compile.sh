#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Install/update dependencies. Run unconditionally (not just when node_modules
# is missing) so newly added packages are picked up on deploy. npm install is
# idempotent and near-instant when everything is already up to date.
echo "Installing dependencies..."
npm install
.venv/bin/python -m pip install -r requirements.txt

echo "Syncing compatible devices..."
.venv/bin/python scripts/sync_compatible_devices.py
echo "Done: data/compatible_devices.json"

# Geocode the electrician directory (data/electricians.csv -> .geocoded.json).
echo "Geocoding electrician directory..."
.venv/bin/python scripts/geocode_electricians.py
echo "Done: data/electricians.geocoded.json"

echo "Subsetting Material Symbols icon font..."
.venv/bin/python scripts/subset_icons.py

echo "Compiling TypeScript..."
npx esbuild src/ts/index.ts --bundle --outfile=static/js/output.min.js --format=iife --minify
echo "Done: static/js/output.min.js"

echo "Compiling electrician-finder bundle..."
npx esbuild src/ts/electrician-finder.ts --bundle --outfile=static/js/finder.min.js --format=iife --minify
echo "Done: static/js/finder.min.js (+ finder.min.css)"

# Self-hosted basemap tiles for the electrician finder.
# Large: Only build when missing; refresh manually with ./build_tiles.sh.
if [ ! -f static/tiles/basemap.pmtiles ]; then
    echo "Basemap tiles missing, building (downloads ~90 MB from Protomaps)..."
    ./build_tiles.sh
else
    echo "Basemap tiles present, skipping (run ./build_tiles.sh to refresh)."
fi

echo "Compiling Tailwind CSS..."
npx @tailwindcss/cli -i ./src/input.css -o ./static/css/output.min.css --minify
echo "Done: static/css/output.min.css"

# Pre-compress text assets so nginx can serve them via brotli_static/gzip_static.
echo "Pre-compressing static assets (.br / .gz)..."
find static -type f \( -name '*.css' -o -name '*.js' -o -name '*.svg' \
    -o -name '*.json' -o -name '*.xml' -o -name '*.map' \) -print0 \
    | while IFS= read -r -d '' f; do
        if command -v brotli >/dev/null 2>&1; then
            brotli -f -q 11 -o "$f.br" "$f"
        fi
        gzip -9 -f -k "$f"
    done
echo "Done: pre-compressed assets"
