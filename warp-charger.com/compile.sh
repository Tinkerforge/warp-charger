#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Install dependencies if needed
if [ ! -d node_modules ]; then
    echo "Installing dependencies..."
    npm install
fi

echo "Syncing compatible devices..."
.venv/bin/python sync_compatible_devices.py
echo "Done: data/compatible_devices.json"

echo "Compiling TypeScript..."
npx esbuild src/ts/index.ts --bundle --outfile=static/js/output.min.js --format=iife --minify
echo "Done: static/js/output.min.js"

echo "Compiling Tailwind CSS..."
npx @tailwindcss/cli -i ./src/input.css -o ./static/css/output.min.css --minify
echo "Done: static/css/output.min.css"
