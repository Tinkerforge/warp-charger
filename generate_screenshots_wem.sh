#!/bin/sh

#status
python3 screenshot.py -o manual_energy_manager/img/resized/web_status.png -H $1 -p -c '#sidebar-energy_manager-group' '#sidebar-network-group' '#sidebar-interfaces-group' '#sidebar-system-group' --full 1280

python3 screenshot.py -o manual_energy_manager/img/resized/web_em_energy_analysis.png -H $1 --crop -c '#sidebar-em-energy-analysis' -e '#em-energy-analysis' --full 1280

#energy manager group
python3 screenshot.py -o manual_energy_manager/img/resized/web_em_settings.png -H $1 --crop -c '#sidebar-energy_manager-group' '#sidebar-energy_manager' -e '#energy_manager' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_em_meter_config.png -H $1 --crop -c '#sidebar-energy_manager-group' '#sidebar-em_meter_config' -e '#em_meter_config' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_charge_manager.png -H $1 --crop -c '#sidebar-energy_manager-group' '#sidebar-charge_manager' -e '#charge_manager' --full 1280

# network group
python3 screenshot.py -o manual_energy_manager/img/resized/web_network.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-network' -e '#network' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_wifi_sta.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-sta' -e '#wifi-sta' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_wifi_ap.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-ap' -e '#wifi-ap' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_ethernet.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-ethernet' -e '#ethernet' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_wireguard.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wireguard' -e '#wireguard' --full 1280

# interfaces group
python3 screenshot.py -o manual_energy_manager/img/resized/web_mqtt.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-mqtt' -e '#mqtt' --full 1280

# system group
python3 screenshot.py -o manual_energy_manager/img/resized/web_ntp.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-ntp' -e '#ntp' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_em_sdcard.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-em_sdcard' -e '#em_sdcard' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_authentication.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-authentication' -e '#authentication' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_event_log.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-event_log' -e '#event_log' --full 1280
python3 screenshot.py -o manual_energy_manager/img/resized/web_firmware_update.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-flash' -e '#flash' --full 1280

echo "Manually crop web_status.png!"
