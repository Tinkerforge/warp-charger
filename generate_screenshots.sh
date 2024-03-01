#!/bin/sh

# status

python3 screenshot.py -o manual/img_warp2/resized/web_status.png -H $1 -c '#sidebar-evse-group' '#sidebar-network-group' '#sidebar-interfaces-group' '#sidebar-users-group' '#sidebar-system-group' --full

# evse group
python3 screenshot.py -o manual/img_warp2/resized/web_evse2.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-evse' -e '#evse' -l '#evse > div:nth-child(1) > div:nth-child(1) > div:nth-child(31)' --full -w 1016
python3 screenshot.py -o manual/img_warp2/resized/web_evse2_settings.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-evse-settings' -e '#evse-settings' --full

python3 screenshot.py -o manual/img_warp2/resized/web_meter.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-meters' -e '#meters' --full
python3 screenshot.py -o manual/img_warp2/resized/web_charge_tracker.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-charge_tracker' -e '#charge_tracker' --full
python3 screenshot.py -o manual/img_warp2/resized/web_charge_manager.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-charge_manager' -e '#charge_manager' --full

# network group
python3 screenshot.py -o manual/img_warp2/resized/web_network.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-network' -e '#network' --full
python3 screenshot.py -o manual/img_warp2/resized/web_wifi_ap.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-ap' -e '#wifi-ap' --full
python3 screenshot.py -o manual/img_warp2/resized/web_wifi_sta.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-sta' -e '#wifi-sta' --full
python3 screenshot.py -o manual/img_warp2/resized/web_ethernet.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-ethernet' -e '#ethernet' --full
python3 screenshot.py -o manual/img_warp2/resized/web_wireguard.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wireguard' -e '#wireguard' --full

# interfaces group

python3 screenshot.py -o manual/img_warp2/resized/web_mqtt.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-mqtt' -e '#mqtt' --full
python3 screenshot.py -o manual/img_warp2/resized/web_modbus_tcp.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-modbus_tcp' -e '#modbus_tcp' --full
python3 screenshot.py -o manual/img_warp2/resized/web_ocpp.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-ocpp' -e '#ocpp' --full

# users group

python3 screenshot.py -o manual/img_warp2/resized/web_nfc.png -H $1 --crop -c '#sidebar-users-group' '#sidebar-nfc' -e '#nfc' --full
python3 screenshot.py -o manual/img_warp2/resized/web_users.png -H $1 --crop -c '#sidebar-users-group' '#sidebar-users' -e '#users' --full

# system group
python3 screenshot.py -o manual/img_warp2/resized/web_ntp.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-ntp' -e '#ntp' --full
python3 screenshot.py -o manual/img_warp2/resized/web_event_log.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-event_log' -e '#event_log' --full
python3 screenshot.py -o manual/img_warp2/resized/web_firmware_update.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-flash' -e '#flash' --full

cp manual/img_warp2/resized/web_status_full.png warp-charger.com/img_warp2/impressions/web3.png
cp manual/img_warp2/resized/web_meter_full.png warp-charger.com/img_warp2/impressions/web1.png
cp manual/img_warp2/resized/web_wifi_sta_full.png warp-charger.com/img_warp2/impressions/web2.png
