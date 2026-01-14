---
sidebar_position: 4
---

# PV Excess Charging

:::note

The configuration of PV excess charging is also described in the tutorial [Photovoltaic Excess Charging](/tutorials/pv_excess_charging.md).

:::

The goal of photovoltaic excess charging is to charge an electric vehicle with the unused power from a photovoltaic system, rather than feeding it into the grid. The focus here is on maximizing self-consumption of solar power. This function can be performed by a [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md).

![image](/img/webinterface/energy_management/warp-pv_excess_charging.jpeg)

The following settings can be configured on this page:
 * **Excess charging enabled**: Enables or disables the PV excess controller.
 * **Default charging mode**: The charging mode that is used after a restart of the WARP3 Charger.
 * **Power meter**: The power meter used to measure the PV excess. This power meter must be created under [Power Meters](/webinterface/energy_management/energy_meters.md).
 * **Min+PV: Minimum charging power**: Specifies the power that may be drawn from the grid in *Min+PV* charging mode.
 * **Control behavior**: Specifies the grid consumption target for regulation, for example to prioritize a battery storage higher or lower than vehicle charging.
 * **Cloud filter**: Adjusts the inertia of the controller. In partly cloudy weather, it is useful for the controller to react sluggishly so that brief fluctuations in PV power are smoothed out.

If a battery storage system is present, it will regulate against the PV excess controller. If the battery storage can be read via a [power meter](/webinterface/energy_management/energy_meters.md), the storage can be directly considered by the controller.
For this, the following settings must be configured:
 * **Power meter**: The power meter assigned to the battery storage
 * **Storage priority**: Here you can configure whether chargers or storage are prioritized higher.
 * **Grid consumption and feed-in tolerance**: The control target value for regulation.
