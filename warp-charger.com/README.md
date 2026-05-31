# WARP Charger Website

## Setup

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
npm install
```

## Build

```bash
./compile.sh
```

This runs all build steps in order:

1. Syncs compatible devices data from `docs.warp-charger.com`
2. Compiles TypeScript (`src/ts/`) into `static/js/output.min.js`
3. Compiles Tailwind CSS (`src/input.css`) into `static/css/output.min.css`

## Run

```bash
source .venv/bin/activate
python app.py
```

The dev server automatically starts file watchers for TypeScript and Tailwind CSS.
