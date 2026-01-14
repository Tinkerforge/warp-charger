---
sidebar_position: 1
---

# Energy Meters

:::note

Energy meters can be configured for WARP Chargers and the WARP Energy Manager.

:::

![image](/img/webinterface/energy_management/wem2-energy_meters.jpeg)

On this page, communication with energy meters can be configured. Since the WARP3 Charger Pro has a built-in energy meter,
this is preconfigured for all WARP3 Chargers Pro. For the WARP3 Charger Smart, this meter can be removed.

The graph displays the measured power of all configured energy meters, either as a progression over
the last 48 hours or as a live view. The view of each meter can be expanded to show additional statistics
and measurement values. To do this, click on the respective blue arrow.

A total of five energy meters can be configured. These include energy meters, inverters, or batteries that can be read via SunSpec, Modbus/TCP, or SMA Speedwire interface.
Compatible energy meters can be connected to the WARP Energy Manager via RS485 and read out. Additionally, virtual energy meters can be created that can be populated via
the [API](/interfaces/mqtt_http/introduction.md).

The list of compatible devices is continuously being expanded. It can be found under [compatible devices](/compatible_devices/introduction.md).



For [photovoltaic excess charging](/tutorials/pv_excess_charging.md), it is necessary to create an energy meter
that measures the power excess (typically at the mains connection). If [dynamic load management](/tutorials/chargemanagement.md) is to be implemented, an energy meter at the grid connection is also necessary. This must be able to measure the phase currents in addition to the total power.

SunSpec (via Modbus TCP) devices can be automatically detected after specifying the host. Depending on the capabilities of the SunSpec device, various measurement values are retrieved. Modbus TCP devices that do not support SunSpec can also be read. We offer predefined
register tables for certain devices. Modbus TCP devices not supported by us can be read via a custom register table.
