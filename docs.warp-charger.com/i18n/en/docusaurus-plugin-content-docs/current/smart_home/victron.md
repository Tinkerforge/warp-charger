---
sidebar_position: 8
---

# Victron

## Integration of WARP Chargers into Venus OS Devices

Victron uses dbus on Venus OS devices (e.g. the Cerbo GX). Other
devices can also be connected via dbus. Victron itself offers
integration of chargers into Venus OS. With the project

[dbus-warp-charger](https://github.com/Tinkerforge/dbus-warp-charger)

WARP Chargers can be integrated into Venus OS. Venus OS then controls
the WARP Charger. However, Victron does not offer support for automatic
phase switching, so this is not supported.

For custom integrations, the following interfaces are otherwise available:

* [MQTT/HTTP API](/interfaces/mqtt_http/introduction.md)
* [Modbus/TCP](/interfaces/modbus/introduction.md)


## Integrating Victron Devices into WARP Devices

Alternatively, it is also possible to integrate Victron devices into [WARP Chargers](/warp_charger/introduction.md) or the
[WARP Energy Manager](/warp_energy_manager/introduction.md).

In this case, the WARP Charger or WARP Energy Manager queries the data from the Victron
devices. Control remains with the WARP device. All functions are thus retained. For example,
automatic phase switching for [PV excess charging](/tutorials/pv_excess_charging.md)
or [dynamic load management](/tutorials/chargemanagement.md) is possible.

See also:
 * [Compatible Devices Introduction](/compatible_devices/introduction.md)
 * [Compatible Victron Devices](/compatible_devices/devices.mdx#victron-energy)
