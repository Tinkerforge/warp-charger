---
sidebar_position: 6
---

# Controllable Consumption Device According to §14a EnWG

Chargers are classified as controllable consumption devices according to
§14a EnWG, as their connection power exceeds 4.2 kW.

WARP Chargers and WARP Energy Managers include a dedicated
[§14a EnWG module](/webinterface/energy_management/p14a_enwg.md)
that centrally configures grid operator control.
Depending on the selected signal source, when a control signal is
received the calculated power limit is automatically applied to the
configured consumers (wallboxes and/or heating).

Which signal source can be used depends on the requirements of the
local grid operator and the device being used.

## Signal sources

### Charger shutdown input (WARP Charger only)

A potential-free contact (voltage-free switching contact) can be connected
at the shutdown input inside the charger. For this, a control line from
the ripple control receiver or the grid operator's control box must be
routed into the charger and connected to the charge controller. For
details on the connection at the terminal block, see
[Assembly and Installation](/warp_charger/assembly_and_installation.md#evse-klemmblock--abschalteingang).

In the §14a EnWG module, select **Charger shutdown input** as the signal
source. The power limit is then automatically applied as soon as the
grid operator switches the input.

![image](/img/webinterface/energy_management/p14a_enwg.png)

### Energy Manager input (Energy Manager only)

Instead of routing a control line into the charger, there is also the
option to connect one of the four inputs of the WARP Energy Manager to
the ripple control receiver or control box. The WARP Energy Manager then
controls the power of the charger(s) via the network (LAN/WLAN). A
separate control line to the charger is not required.

In the §14a EnWG module, select **Energy Manager input** as the signal
source and configure the corresponding input (1-4).

### EEBUS

[EEBUS](/docs/interfaces/eebus) is the designated interface for grid
operator control of consumer devices. In the §14a EnWG module, select
**EEBUS** as the signal source. The control signal is then received via
the EEBUS interface.

### API (HTTP/MQTT)

The control signal can also be received via the HTTP or MQTT API. In
the §14a EnWG module, select **API** as the signal source. Details can
be found in the API documentation under `p14a_enwg/control_update`.

### Other interfaces (OCPP, Modbus TCP)

In general, the charging power of the charger can also be controlled via
all other implemented interfaces. Grid operators currently use OCPP or
Modbus TCP for control, if at all. These interfaces do not use the §14a
EnWG module but control the charger directly.

## Further information

- [§14a EnWG module (configuration)](/webinterface/energy_management/p14a_enwg.md) — Documentation of all settings
- [Heating](/webinterface/energy_management/heater.md) — SG-Ready control configuration
- [EEBUS interface](/docs/interfaces/eebus) — Details on the EEBUS connection
