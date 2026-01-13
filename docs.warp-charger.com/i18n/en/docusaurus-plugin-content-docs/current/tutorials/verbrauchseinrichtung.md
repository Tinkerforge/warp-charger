---
sidebar_position: 6
---

# Controllable Consumption Device According to §14a EnWG

Wallboxes are classified as controllable
consumption devices according to §14a EnWG, as their connection power exceeds 4.2 kW.

WARP3 Chargers can be controlled by the grid operator in various ways.
Which option can be used depends on the requirements
of the local grid operator.

### Interfaces (EEBus, OCPP, Modbus TCP, HTTP, MQTT)

In general, the charging power of the wallbox can be controlled via all implemented
interfaces. Grid operators currently use
OCPP or Modbus TCP for control, if at all.

In the future, [EEBus](/interfaces/eebus.md) is intended to serve as the interface
for controlling consumption devices by grid operators.

### Ripple Control Receiver/Control Box Directly at WARP Charger

A potential-free contact (voltage-free switching contact) can be connected at the
shutdown input inside the wallbox. For this, a
control line from the ripple control receiver or the grid operator's control box
must be routed into the wallbox and connected to the charge controller.
For details on the connection at the terminal block, see
[Assembly and Installation](/warp_charger/assembly_and_installation.md#evse-klemmblock--abschalteingang).

In the wallbox's standard configuration, charging is limited to 4200 W when
the shutdown input is closed. This behavior can be adjusted in the
web interface under `Wallbox` -> `Settings`.

![image](/img/tutorials/verbrauchseinrichtung/14enwg_input.png)

### Ripple Control Receiver/Control Box via WARP Energy Manager

Instead of routing a control line into the wallbox, there is also the
option to connect the inputs of the WARP Energy Manager to the
ripple control receiver or control box. The WARP Energy
Manager then controls the power of the wallbox(es) via the network
(LAN/WLAN). A separate control line is not required. The WARP Energy
Manager must be configured as the load manager of the respective wallbox(es)
for this purpose. Subsequently, the following rule must be created in `Energy Manager` ->
`Automation`:

![image](/img/tutorials/verbrauchseinrichtung/14enwg_wem_add_rule.png)

Instead of 6 A, 18 A must be selected for single-phase operation.

In the automation list, the added automation rule then appears
as follows:

![image](/img/tutorials/verbrauchseinrichtung/14enwg_wem_rule_added.png)

Similarly, another rule must be created that removes the maximum total current limitation when the input is open.
For this, "Limit maximum total current" must be selected again as the action, but this time with the option "Reset maximum total current (...A)" as the mode.
