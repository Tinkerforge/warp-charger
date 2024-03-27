#!/bin/sh

# status

python3 screenshot.py -o manual/img_warp3/resized/web_status.png -H $1#status -c '#nav-list > li:nth-child(2) > div:nth-child(1)' '#nav-list > li:nth-child(3) > div:nth-child(1)' '#nav-list > li:nth-child(4) > div:nth-child(1)' '#nav-list > li:nth-child(5) > div:nth-child(1)' '#nav-list > li:nth-child(6) > div:nth-child(1)' '#nav-list > li:nth-child(7) > div:nth-child(1)' --full

# evse group
python3 screenshot.py -o manual/img_warp3/resized/web_evse_settings.png -H $1#evse_settings --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_evse.png -H $1#evse --crop -e '.tab-content' --full -w 1016
python3 screenshot.py -o manual/img_warp3/resized/web_charge_tracker.png -H $1#charge_tracker --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_automation.png -H $1#automation --crop -e '.tab-content' --full

#energy management group
python3 screenshot.py -o manual/img_warp3/resized/web_meters.png -H $1#meters --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_charge_manager_chargers.png -H $1#charge_manager_chargers --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_pv_excess_settings.png -H $1#pv_excess_settings --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_charge_manager_settings.png -H $1#charge_manager_settings --crop -e '.tab-content' --full

# network group
python3 screenshot.py -o manual/img_warp3/resized/web_network.png -H $1#network --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_wifi_sta.png -H $1#wifi_sta --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_wifi_ap.png -H $1#wifi_ap --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_ethernet.png -H $1#ethernet --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_wireguard.png -H $1#wireguard --crop -e '.tab-content' --full

# interfaces group

python3 screenshot.py -o manual/img_warp3/resized/web_mqtt.png -H $1#mqtt --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_modbus_tcp.png -H $1#modbus_tcp --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_ocpp.png -H $1#ocpp --crop -e '.tab-content' --full

# users group

python3 screenshot.py -o manual/img_warp3/resized/web_nfc.png -H $1#nfc --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_users.png -H $1#users --crop -e '.tab-content' --full

# system group
python3 screenshot.py -o manual/img_warp3/resized/web_certs.png -H $1#certs --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_ntp.png -H $1#ntp --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_rtc.png -H $1#rtc --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_event_log.png -H $1#event_log --crop -e '.tab-content' --full
python3 screenshot.py -o manual/img_warp3/resized/web_firmware_update.png -H $1#firmware_update --crop -e '.tab-content' --full

cp manual/img_warp3/resized/web_status_full.png warp-charger.com/img_warp3/impressions/web3.png
cp manual/img_warp3/resized/web_meter_full.png warp-charger.com/img_warp3/impressions/web1.png
cp manual/img_warp3/resized/web_wifi_sta_full.png warp-charger.com/img_warp3/impressions/web2.png
