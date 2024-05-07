#!/bin/sh

# Simple auto-deploy from github
# This is called on docs.warp-charger.com with cron
cd /var/www/git/warp-charger/docs.warp-charger.com/
/usr/local/bin/npm ci
/usr/local/bin/npm run build
cp -r build/* build_release/
