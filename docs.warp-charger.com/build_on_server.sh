#!/bin/sh
# Simple auto-deploy from github
# This is called on docs.warp-charger.com with cron

set -e

REPO_DIR="/var/www/git/warp-charger/docs.warp-charger.com"
BRANCH="master"

cd "$REPO_DIR"

# Fetch updates
/usr/bin/git fetch origin "$BRANCH"

LOCAL_HASH=$(/usr/bin/git rev-parse HEAD)
REMOTE_HASH=$(/usr/bin/git rev-parse "origin/$BRANCH")

# Exit silently if nothing changed
[ "$LOCAL_HASH" = "$REMOTE_HASH" ] && exit 0

# Update working tree
/usr/bin/git reset --hard "origin/$BRANCH"

# Build only when changes were pulled
/usr/local/bin/npm ci
/usr/local/bin/npm run build

# Deploy build output
cp -r build/* build_release/
