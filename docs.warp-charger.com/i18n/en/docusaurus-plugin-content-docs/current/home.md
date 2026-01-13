---
sidebar_position: 0
---

# Introduction

Welcome to the documentation pages of the WARP product line from
Tinkerforge.

Here you will find the documentation for installation and configuration of:
* [WARP3 Charger](/warp_charger/introduction.md),
* [WARP Energy Manager](/warp_energy_manager/introduction.md) and
* [WARP Charger Stand](/warp_ladesäule/introduction.md).


This documentation is constantly maintained and expanded. If you have ideas for
additional documentation or examples, please let us know. We also gladly
add more [compatible devices](/compatible_devices/introduction.md)
to the list or good questions/answers to the [FAQ](/faq.md).

### Philosophy

We believe that products belong to customers. That's why we develop
solutions with open interfaces and consistently pursue an
open source concept (hardware and software). Our products are developed and manufactured
in Germany (Made in Germany). We design our
products for long service life, focus on quality and easy
repairability.

#### Community

The development of our products is done in close cooperation with our community:
 * [Tinkerunity](https://www.tinkerunity.org/forum/13-warp-charger/)

Whether new ideas, bug reports or beta testers: We appreciate the intensive collaboration!

#### Open Interfaces

[WARP Energy Manager 2.0](/warp_energy_manager/introduction.md), [WARP3 Charger Smart and WARP3 Charger Pro](/warp_charger/introduction.md) can
be integrated into other systems using open interfaces:
* [MQTT/HTTP API](/interfaces/mqtt_http/introduction.md)
* [Modbus Interface](/interfaces/modbus/introduction.md)
* [OCPP](/interfaces/ocpp.md) (WARP Charger only)

#### No Cloud Required

We try to implement as many functions as possible locally on the device.
For example, the charging log is stored locally on the wallboxes. If
a billing PDF should be generated from it, this is done on the
wallbox and in your browser without a cloud.

In cases where we technically depend on data from a cloud
(e.g.: [PV Forecast](/webinterface/energy_management/solar_forecast.md), [Dynamic Electricity Prices](/webinterface/energy_management/dynamic_tariffs.md), [Remote Access](/webinterface/system/remote_access.md)), we still try to implement as many
functions on the respective device as possible and not in the cloud.
This means we try to avoid storing data in the cloud whenever possible, but rather
store it locally on the devices.

For example, [Remote Access](/webinterface/system/remote_access.md), which is also used by the Android and iOS apps,
is technically a VPN tunnel between the browser/app and the device (WARP Charger or WARP Energy Manager).
Data exchange is encrypted between the two participants. We have no access to your device or your data.

### Compatibility with Third-Party Devices

Our goal is that our products also work with devices from other manufacturers.
This makes it possible to access data from PV inverters, electricity meters
or battery storage systems from other manufacturers and use them for example for PV excess charging
or dynamic load management.

The list of compatible devices can be found here: [List of Compatible Devices](/compatible_devices/introduction.md)

### Using Solar Power

#### Photovoltaic Excess Charging

[WARP3 Charger Smart and Pro](/warp_charger/introduction.md)
can perform [PV excess charging](/tutorials/pv_excess_charging.md) directly and without additional hardware.
This means that instead of feeding excess energy from the PV system
into the power grid, it is charged into the electric vehicle.
To do this, the wallbox only needs to be electrically connected and brought
into the network via LAN or WLAN. Additionally, an
electricity meter must be available at the house connection, which can be
read by the wallbox. PV excess charging is then performed using the power measurement values from this
electricity meter. An overview of
currently supported devices that can measure power at the house connection
can be found in the article
[compatible devices](/compatible_devices/introduction.md).

#### Operating Heating with Photovoltaic Excess

Similar to PV excess charging, a [WARP Energy Manager 2.0](/warp_energy_manager/introduction.md)
can be used to set a [heat pump with SG-Ready interface](/webinterface/energy_management/heater.md) to extended
operation mode. This way, the PV excess can also be used for heating.

### Dynamic Electricity Prices

[WARP3 Charger Smart and Pro](/warp_charger/introduction.md) and the [WARP Energy Manager 2.0](/warp_energy_manager/introduction.md)
can directly retrieve electricity generation prices from the power exchange. Additional costs such as grid fees and taxes can be
individually configured. This way we support any provider of dynamic electricity prices without depending on an individual implementation
of the provider's interfaces.

### §14a - Controllable Consumption Devices
Wallboxes, heat pumps and battery storage systems are so-called controllable consumption devices according to §14A. We offer
various options for meeting the legal requirements. See [Tutorial - Controllable Consumption Devices](/tutorials/verbrauchseinrichtung.md)


### Charge Management

#### Operating Multiple Chargers on One Line - Static Load Management

If multiple WARP Chargers share a supply line, the
charging currents of the connected chargers may need to be limited.
WARP3 Charger Smart and WARP3 Charger Pro have integrated
[charge management](/tutorials/chargemanagement.md).
The chargers only need to be within a
network (LAN, WLAN). A separate electricity meter is not necessary for
*static* load management.

#### Insufficiently Dimensioned Grid Connection - Dynamic Load Management

If the grid connection is not sufficiently dimensioned to operate one or
more chargers, [dynamic load management](/tutorials/chargemanagement.md) helps.
Especially with larger properties, the grid connection is often mathematically maxed out
if it is assumed that all consumers are switched on.
In practice, however, this almost never happens, so chargers
can still be operated. The chargers must then be controlled depending on
the current phase currents at the grid connection to ensure
that none of the three phases is overloaded.
If a suitable electricity meter is available at the grid connection that can
measure the phase currents, dynamic load management can be handled directly
by a WARP Charger. An overview of
currently supported devices that can measure power at the house connection
can be found in the article
[compatible devices](/compatible_devices/introduction.md).

