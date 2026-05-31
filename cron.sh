#!/bin/sh
# Auto-deploy script for warp-charger.com and docs.warp-charger.com
# Called via cron (as root). Git operations and builds run as the service user.
#
# Both sites live in the same git checkout, so a single fetch determines what
# changed; each site is only rebuilt when files below its directory changed.
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
#   git sparse-checkout set warp-charger.com firmwares documents docs.warp-charger.com

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
DOCS_DIR="$REPO_DIR/docs.warp-charger.com"

run_as_user() {
    su -s /bin/sh "$SERVICE_USER" -c "$1"
}

cd "$REPO_DIR"
run_as_user "/usr/bin/git fetch --depth=1 origin $BRANCH"

LOCAL_HASH=$(run_as_user "/usr/bin/git rev-parse HEAD")
REMOTE_HASH=$(run_as_user "/usr/bin/git rev-parse origin/$BRANCH")

# Exit silently if nothing changed
[ "$LOCAL_HASH" = "$REMOTE_HASH" ] && exit 0

# Determine which paths changed before updating the working tree
CHANGED=$(run_as_user "/usr/bin/git diff --name-only $LOCAL_HASH origin/$BRANCH")

# Update working tree
run_as_user "/usr/bin/git reset --hard origin/$BRANCH"

# Rebuild warp-charger.com when its inputs changed
if echo "$CHANGED" | grep -qE '^(warp-charger\.com|firmwares|documents)/'; then
    cd "$SITE_DIR"
    run_as_user "./compile.sh"
    /usr/bin/systemctl restart warp-charger.com
fi

# Rebuild docs.warp-charger.com when its inputs changed
if echo "$CHANGED" | grep -qE '^docs\.warp-charger\.com/'; then
    cd "$DOCS_DIR"
    run_as_user "/usr/local/bin/npm ci"
    run_as_user "/usr/local/bin/npm run build"
    run_as_user "/usr/bin/rsync -a --delete build/ build_release/"
fi
