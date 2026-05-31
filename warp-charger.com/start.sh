#!/bin/bash
cd "$(dirname "$0")"
source .venv/bin/activate
./.venv/bin/gunicorn -w 2 --bind unix:app.sock app:app
