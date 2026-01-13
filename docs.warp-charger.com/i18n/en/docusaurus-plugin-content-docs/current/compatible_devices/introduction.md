---
sidebar_position: 1
---

# Introduction

The [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md) can directly access data from
other third-party devices.

This includes data from power meters (for example at the grid connection),
data from PV inverters about current generation,
as well as data on battery storage power or power consumption data from loads. The read data
can be used by a WARP Charger or WARP Energy Manager
to control wallboxes (PV excess charging), for PV excess utilization of a heat pump, or for
dynamic load management.

The WARP Energy Manager additionally records the collected data locally on its SD card. Via the web interface, the recorded data can be analyzed in the [Energy Analysis](/webinterface/energy_manager/energy_analysis.md).

To access the data, we depend on the [interfaces](/compatible_devices/interfaces.md) provided by the respective device manufacturer.
Depending on the device and manufacturer, the appropriate [interface](/compatible_devices/interfaces.md) must be configured in the web interface under [Power Meters](/webinterface/energy_management/energy_meters.md)
on the [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md).

:::note

The list of compatible devices can be found here: [List of Compatible Devices](/compatible_devices/devices.mdx)

:::



## Measurement Location of Device Data

We distinguish between four different measurement locations for data sources. These are listed below.
Some devices support multiple measurement locations simultaneously. For example, there are hybrid inverters that provide data
for all four measurement locations.

The measurement locations are used to assign and consolidate individual data sources and
to create an energy overview from them.

Power meters without a fixed role can be manually assigned to a measurement location. Thus, a power meter can be installed
to measure, for example, the load. It is also possible to install a power meter at the grid connection
and assign it the measurement location "Grid Connection" if no readable power meter is available.

### Grid Connection

If a PV system is already installed, a meter ("smart meter") is usually also installed at the grid connection.
This is then connected to the PV inverter and can often be read via the inverter.
We support various ways to access these meters.

### PV

PV inverters (including hybrid inverters) often provide data on their current PV generation.

### Battery Storage

A hybrid inverter is a combination of a photovoltaic inverter and a battery inverter.
These inverters often provide not only data on PV generation but also data on the current battery power (charging/discharging).
There are also pure battery inverters that can be accessed.

In the future, control of the storage will also be possible for many models.

### Load

To capture where the generated power flows, there is the measurement location "Load". Some inverters also have a readable load output.

## Applications
### PV Excess Charging

For [PV excess charging](/tutorials/pv_excess_charging.md), the
WARP Charger or WARP Energy Manager must have access to a
power meter at the **Grid Connection (Grid)**, as only there can the actual
PV excess be determined.

:::note

For PV excess charging, a power meter must be configured that contains at least the following value:
***Active Power (Import minus Export); Σ L1, L2, L3 [W]***

This value is used for control. Additional values can be configured but are not technically necessary.

:::

If a battery storage is additionally available and can also be read,
it makes sense to also configure it so that PV excess charging can
take it into account.

*PV excess charging controls the sum of active power so that excess power
is charged into a vehicle instead of being fed back into the power grid.*

### Dynamic Load Management

For [dynamic load management](/tutorials/chargemanagement.md), the
WARP Charger or WARP Energy Manager must have access to a
power meter at the **Grid Connection (Grid)**, as only there can the current
phase currents be determined.

:::note

For dynamic load management, a power meter must be configured that contains at least the following values:
 * ***Current (Import minus Export); L1 [A]*** or ***Current (Import plus Export); L1 [A]*** or ***Current (Import); L1 [A]***
 * ***Current (Import minus Export); L2 [A]*** or ***Current (Import plus Export); L2 [A]*** or ***Current (Import); L2 [A]***
 * ***Current (Import minus Export); L3 [A]*** or ***Current (Import plus Export); L3 [A]*** or ***Current (Import); L3 [A]***

These values are used for control. Additional values can be configured but are not technically necessary.
Whether ***"Import"***, ***"Import minus Export"***, ***"Import plus Export"*** must be selected depends on the respective power meter. This can be tested if in doubt.

:::

*Dynamic load management controls charging processes so that the maximum configured phase current is not exceeded on any phase (L1, L2, L3).*

### Battery Control

For controlling battery storage, there is a dedicated page: [Battery Storage](compatible_devices/batteries.md)
