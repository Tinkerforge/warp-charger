#!/bin/sh
python3 screenshot.py -o manual/img_warp2/resized/web_charge_manager.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-charge_manager' -e '#charge_manager'
python3 screenshot.py -o manual/img_warp2/resized/web_ethernet.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-ethernet' -e '#ethernet'
python3 screenshot.py -o manual/img_warp2/resized/web_event_log.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-event_log' -e '#event_log'
python3 screenshot.py -o manual/img_warp2/resized/web_evse2.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-evse' -e '#evse' -l '#evse > div:nth-child(29)'
python3 screenshot.py -o manual/img_warp2/resized/web_evse2_settings.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-evse-settings' -e '#evse-settings'
python3 screenshot.py -o manual/img_warp2/resized/web_firmware_update.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-flash' -e '#flash'
python3 screenshot.py -o manual/img_warp2/resized/web_meter.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-meter' -e '#meter'
python3 screenshot.py -o manual/img_warp2/resized/web_mqtt.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-mqtt' -e '#mqtt'
python3 screenshot.py -o manual/img_warp2/resized/web_nfc.png -H $1 --crop -c '#sidebar-users-group' '#sidebar-nfc' -e '#nfc'
python3 screenshot.py -o manual/img_warp2/resized/web_status.png -H $1 -c '#sidebar-evse-group' '#sidebar-network-group' '#sidebar-interfaces-group' '#sidebar-users-group' '#sidebar-system-group'
python3 screenshot.py -o manual/img_warp2/resized/web_network.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-network' -e '#network'
python3 screenshot.py -o manual/img_warp2/resized/web_ntp.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-ntp' -e '#ntp'
python3 screenshot.py -o manual/img_warp2/resized/web_wifi_ap.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-ap' -e '#wifi-ap'
python3 screenshot.py -o manual/img_warp2/resized/web_wifi_sta.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-sta' -e '#wifi-sta'
python3 screenshot.py -o manual/img_warp2/resized/web_wireguard.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wireguard' -e '#wireguard'
python3 screenshot.py -o manual/img_warp2/resized/web_charge_tracker.png -H $1 --crop -c '#sidebar-evse-group' '#sidebar-charge_tracker' -e '#charge_tracker'
python3 screenshot.py -o manual/img_warp2/resized/web_modbus_tcp.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-modbus_tcp' -e '#modbus_tcp'
python3 screenshot.py -o manual/img_warp2/resized/web_ocpp.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-ocpp' -e '#ocpp'
python3 screenshot.py -o manual/img_warp2/resized/web_users.png -H $1 --crop -c '#sidebar-users-group' '#sidebar-users' -e '#users'
python3 screenshot.py -o manual/img_warp2/resized/web_users_new.png -H $1 --crop -c '#sidebar-users-group' '#sidebar-users' '#users_config_form > div:nth-child(4) > div:nth-child(2) > div:nth-child(1) > div:nth-child(4) > div:nth-child(1) > div:nth-child(2) > button:nth-child(1)' -e 'div.modal.show' --style "div.modal.show {height: 630px}"  -w 2560
cp manual/img_warp2/resized/web_status.png warp-charger.com/img_warp2/impressions/web3.png
cp manual/img_warp2/resized/web_meter.png warp-charger.com/img_warp2/impressions/web1.png
cp manual/img_warp2/resized/web_wifi_sta.png warp-charger.com/img_warp2/impressions/web2.png
echo "Manually crop web_users_new.png"
