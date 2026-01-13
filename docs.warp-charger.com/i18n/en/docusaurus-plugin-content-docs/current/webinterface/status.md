---
sidebar_position: 1
---

# Status

The status page differs between a [WARP3 Charger](/warp_charger/introduction.md) and
a [WARP Energy Manager 2.0](/warp_energy_manager/introduction.md). It provides general information about the
device's state. In part, it also offers
configuration options, such as switching the charging mode
of wallboxes.

## Status (WARP3 Charger)

![image](/img/webinterface/status/warp3-status.jpeg)

:::note

The elements displayed on the status page depend on which
modules have been enabled in the wallbox web interface.

:::

On this status page, the **charging mode** of the wallbox can be set.
Which charging modes are offered depends on whether the wallbox has been configured for
PV excess charging and whether eco mode has been enabled.

The **charging status** provides information on whether a vehicle is connected to the wallbox,
whether the charging process has been authorized, and whether the vehicle is charging.

With the **charge control** and **configured charging current**, the charging process can be manually
controlled. The charging current can be used to set an additional current limit.

Via the **time limit** or **energy limit** (WARP Charger Pro only), a charging process
can be time-limited or a maximum energy amount (kWh) can be specified.

The **charging history** displays the charging power over time and is only available for WARP Charger Pro
wallboxes.

If users are configured, the **last charging processes** are displayed. These contain
information about the user who charged, the charging duration, and for WARP Charger Pro wallboxes, the amount of energy charged.

The status page also displays information about load management if enabled.
Additionally, information about the interfaces is provided, including IP addresses, WiFi connection strength, etc.

### More Examples
Examples with eco charging mode and activated charging schedule in load management with multiple wallboxes.
![image](/img/webinterface/status/warp3-status2.jpeg)
![image](/img/webinterface/status/warp3-status3.jpeg)

## Status (WARP Energy Manager)

![image](/img/webinterface/status/wem2-status.jpeg)

:::note

The elements displayed on the status page depend on which
modules have been enabled in the Energy Manager web interface.

:::

On the Energy Manager status page, information about the
current **power** from power meters is displayed. If the power meters have been
configured, an overview of the power progression related to
PV generation, grid consumption or feed-in, home battery, and consumption can be viewed here.

This WARP Energy Manager has been configured as a load manager for wallboxes.
Therefore, the **charging mode** for the wallboxes can be set.
Which charging modes are offered depends on whether the Energy Manager has been configured for
PV excess charging and whether eco mode has been enabled.

The **controlled wallboxes** and their status managed by the Energy Manager are displayed.

The status of the **SG-Ready** interface (heating) and information about the current
electricity price (**Current Market Price** and **Average Price**) are also displayed.

The data for **PV Yield Forecast** is partially visible in this screenshot.
