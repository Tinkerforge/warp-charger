#!/bin/sh
# Auto-deploy script for warp-charger.com
# Called via cron (as root). Git operations run as the service user.
#
# Branch selection based on hostname:
#   stagingwww -> stagingwww.warp-charger.com branch
#   otherwise  -> master branch
#
# Initial setup on the server (run once as service user):
#
#   cd /home/www
#   git clone --depth=1 --filter=blob:none --sparse \
#       git@github.com:Tinkerforge/warp-charger.git warp-charger
#   cd warp-charger
#   git sparse-checkout set warp-charger.com firmwares documents

set -e

# Determine branch and user based on hostname
HOSTNAME=$(hostname)
if [ "$HOSTNAME" = "stagingwww" ]; then
    BRANCH="stagingwww.warp-charger.com"
    SERVICE_USER="stagingwww"
else
    BRANCH="master"
    SERVICE_USER="www"
fi

REPO_DIR="/home/$SERVICE_USER/warp-charger"
SITE_DIR="$REPO_DIR/warp-charger.com"

NEEDS_RESTART=0

cd "$REPO_DIR"
su -s /bin/sh "$SERVICE_USER" -c "/usr/bin/git fetch --depth=1 origin $BRANCH"

LOCAL_HASH=$(su -s /bin/sh "$SERVICE_USER" -c "/usr/bin/git rev-parse HEAD")
REMOTE_HASH=$(su -s /bin/sh "$SERVICE_USER" -c "/usr/bin/git rev-parse origin/$BRANCH")

if [ "$LOCAL_HASH" != "$REMOTE_HASH" ]; then
    su -s /bin/sh "$SERVICE_USER" -c "/usr/bin/git reset --hard origin/$BRANCH"
    # Rebuild assets
    cd "$SITE_DIR"
    su -s /bin/sh "$SERVICE_USER" -c "./compile.sh"
    NEEDS_RESTART=1
fi

if [ "$NEEDS_RESTART" = "1" ]; then
    /usr/bin/systemctl restart warp-charger.com
fi
