from evse import evse
from meter import meter
from nfc import nfc
from charge_manager import charge_manager
from mqtt import mqtt
from wifi import wifi
from ethernet import ethernet
from network import network
from ntp import ntp
from users import users
from charge_tracker import charge_tracker
from misc import misc
from info import info
from wireguard import wireguard
from rtc import rtc
from modbus_tcp import modbus_tcp
from ocpp import ocpp
from authentication import authentication
from energy_manager import energy_manager
from charge_limits import charge_limits
from require_meter import require_meter
from certs import certs
from automation import automation
from meters import meters
from meters_legacy_api import meters_legacy_api
from power_manager import power_manager
from day_ahead_prices import day_ahead_prices
from front_panel import front_panel
from heating import heating
from solar_forecast import solar_forecast

mods = [
    evse,
    meters,
    require_meter,
    charge_manager,
    users,
    charge_tracker,
    nfc,
    network,
    wifi,
    ethernet,
    ntp,
    mqtt,
    modbus_tcp,
    ocpp,
    wireguard,
    rtc,
    certs,
    info,
    authentication,
    misc,
    energy_manager,
    power_manager,
    charge_limits,
    automation,
    meters_legacy_api,
    meter,
    day_ahead_prices,
    front_panel,
    heating,
    solar_forecast,
]
