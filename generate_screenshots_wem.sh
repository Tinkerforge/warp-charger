#!/bin/sh

#status
python3 screenshot.py -o manual_energy_manager/img/resized/web_status.png -H $1 -p -c '#sidebar-energy_manager-group' '#sidebar-network-group' '#sidebar-interfaces-group' '#sidebar-system-group'

python3 screenshot.py -o manual_energy_manager/img/resized/web_em_energy_analysis.png -H $1 --crop -c '#sidebar-em-energy-analysis' -e '#em-energy-analysis'

#energy manager group
python3 screenshot.py -o manual_energy_manager/img/resized/web_em_settings.png -H $1 --crop -c '#sidebar-energy_manager-group' '#sidebar-energy_manager' -e '#energy_manager'
python3 screenshot.py -o manual_energy_manager/img/resized/web_em_meter_config.png -H $1 --crop -c '#sidebar-energy_manager-group' '#sidebar-em_meter_config' -e '#em_meter_config'
python3 screenshot.py -o manual_energy_manager/img/resized/web_charge_manager.png -H $1 --crop -c '#sidebar-energy_manager-group' '#sidebar-charge_manager' -e '#charge_manager'

# network group
python3 screenshot.py -o manual_energy_manager/img/resized/web_network.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-network' -e '#network'
python3 screenshot.py -o manual_energy_manager/img/resized/web_wifi_sta.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-sta' -e '#wifi-sta'
python3 screenshot.py -o manual_energy_manager/img/resized/web_wifi_ap.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wifi-ap' -e '#wifi-ap'
python3 screenshot.py -o manual_energy_manager/img/resized/web_ethernet.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-ethernet' -e '#ethernet'
python3 screenshot.py -o manual_energy_manager/img/resized/web_wireguard.png -H $1 --crop -c '#sidebar-network-group' '#sidebar-wireguard' -e '#wireguard'

# interfaces group
python3 screenshot.py -o manual_energy_manager/img/resized/web_mqtt.png -H $1 --crop -c '#sidebar-interfaces-group' '#sidebar-mqtt' -e '#mqtt'

# system group
python3 screenshot.py -o manual_energy_manager/img/resized/web_ntp.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-ntp' -e '#ntp'
python3 screenshot.py -o manual_energy_manager/img/resized/web_ntp.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-em_sdcard' -e '#em_sdcard'
python3 screenshot.py -o manual_energy_manager/img/resized/web_ntp.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-authentication' -e '#authentication'
python3 screenshot.py -o manual_energy_manager/img/resized/web_event_log.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-event_log' -e '#event_log'
python3 screenshot.py -o manual_energy_manager/img/resized/web_firmware_update.png -H $1 --crop -c '#sidebar-system-group' '#sidebar-flash' -e '#flash'

echo "Manually crop web_status.png!"
