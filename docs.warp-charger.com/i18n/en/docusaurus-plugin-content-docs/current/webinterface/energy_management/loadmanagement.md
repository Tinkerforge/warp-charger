---
sidebar_position: 5
---

# Charge Management

:::note

The configuration of charge management is also described in the tutorial [Charge Management](/tutorials/chargemanagement.md).

:::

With charge management, it is possible to distribute an available total charging current among up to 64 WARP Chargers. A [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md) is configured as
a charge manager, which controls the other up to 63 chargers (WARP Energy Manager: 64 chargers) in the cluster and assigns them charging currents.

![image](/img/webinterface/energy_management/warp-loadmanagement.jpeg)

On the charge management page, an ***Automatic minimum charging current*** can be enabled: The Type 2 charging standard defines 6A as the minimum charging current. However, not all vehicles support this charging current depending on the charging mode (single-phase/three-phase).
In some cases, a slightly higher minimum charging current must be selected.

## Dynamic Load Management

To use dynamic load management, an [energy meter](/webinterface/energy_management/energy_meters.md) must first be added
that can measure the phase currents at the mains connection. This can also be used for [PV excess charging](/tutorials/pv_excess_charging.md) if desired, but dynamic load management
can also be used without a PV system. This energy meter must be created beforehand.

The following settings are then necessary for dynamic load management:

* **Energy meter**: Energy meter on which the dynamic load management regulates.
* **Maximum current at grid connection**: Maximum permissible phase current at the grid connection. This is typically the rated value of the circuit breaker. Dynamic load management ensures that this value is not exceeded.
* **Power consumption of the largest single consumer**: Expected power consumption of the largest consumer. This could be, for example, an instantaneous water heater or a heat pump, but at minimum 16 amperes from a Schuko socket. The value represents the largest expected
sudden jump in power consumption at the meter that the dynamic load management must be able to compensate for in the short term (in under 30 seconds).
* **Additional safety margin**: Additional percentage safety margin that is factored in by dynamic load management.
