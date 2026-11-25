---
sidebar_position: 4
---

# EEBUS

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

EEBUS is a communication standard used by energy grid operators, among others, to control controllable consumer devices (e.g. chargers, heat pumps) in accordance with [§14a EnWG](/webinterface/energy_management/p14a_enwg.md) and to limit the feed-in of generation plants (e.g. PV systems) in accordance with [§9 EEG](#einspeisebegrenzung). The EEBUS interface is available on WARP Chargers and WARP Energy Managers.

## How it works

EEBUS uses mDNS for device discovery and the SHIP protocol (Smart Home IP) for connection establishment in the local network. Communication is encrypted via TLS/WebSocket. Devices identify each other using an SKI (Subject Key Identifier).

## Available use cases

EEBUS defines various use cases for different applications.

### Grid operator control

- **LPC** (Limitation of Power Consumption, Actor: Controllable System): Allows the grid operator to limit power consumption. Used by control boxes for grid control according to §14a EnWG. Available on WARP Charger and Energy Manager.
- **LPP** (Limitation of Power Production, Actor: Controllable System): Allows the grid operator to limit the feed-in (§9 EEG). The limitation can be passed on to the inverter with an [automation rule](#einspeisebegrenzung). Energy Manager only.

### E-Mobility (WARP Charger only)

- **EVCC** (EV Commissioning and Configuration, Actor: EV): Information about the connected electric vehicle (communication standard, power limits, asymmetric charging).
- **EVSECC** (EVSE Commissioning and Configurationn, Actor: EVSE): Operating state of the charging station and any error conditions.
- **EVCEM** (EV Charging Electricity Measurement, Actor: EV): Measurements of the charging process (current, power, charged energy per phase).
- **MPC** (Monitoring of Power Consumption, Actor: Monitored Unit): Monitoring of the charger power consumption with measurements for power, current, voltage, and frequency.

### Energy management (Energy Manager only)

- **MGCP** (Monitoring of Grid Connection Point, Actor: Grid Connection Point): Monitoring of the grid connection point with measurements for power, energy, current, voltage, and frequency.


## Configuration

The EEBUS interface is configured on the **EEBUS** page in the web interface.

![image](/img/interfaces/eebus/eebus.png)

### SKI (Subject Key Identifier)

The SKI is a unique cryptographic identifier for the device. If the device needs to communicate with e.g. a control box ("Steuerbox"), the SKI may be required during setup of the control box.

### EEBUS enabled

Enables or disables EEBUS communication. EEBUS is disabled by default.

### Details

The expandable **Details** section displays the current values of active use cases. The displayed values reflect the latest EEBUS communication data.

### Adding devices (pairing)

EEBUS devices must mutually trust each other before they can communicate. Connections from unknown devices are rejected.

![image](/img/interfaces/eebus/eebus_add.png)

If a device is not automatically detected, it is possible to set the SKI and address/port/wss path manually. A device that was added is trusted by default.

## Feed-in limitation according to §9 EEG (Energy Manager only) {#einspeisebegrenzung}

<DeviceCompatibility supported={['wem1', 'wem2']} />

With the use case **LPP**, the control box of the grid operator can limit the feed-in power. The WARP Energy Manager cannot control the production of the PV system itself. The limitation is therefore passed on to the inverter with an [automation rule](/webinterface/energy_manager/automation.md), e.g. by switching a digital input of the inverter with a relay of the Energy Manager. The feed-in power the inverter allows while the input is closed (e.g. 0 %) is configured in the inverter.

To do so, create two rules with the condition **§9 EEG (EEBUS feed-in limitation)**:

* If §9 EEG (EEBUS feed-in limitation) is **triggered**, close the relay.
* If §9 EEG (EEBUS feed-in limitation) is **no longer triggered**, open the relay.

The condition is triggered if

* the control box activated a limitation or
* the connection to the control box is interrupted (failsafe state) and the failsafe limit specified by the control box applies.

After a restart, the failsafe limit also applies until the control box takes over control again (at most 120 seconds). The current state is reported to the automation rules after every restart and after enabling EEBUS, so that the relay always reflects the current state. If EEBUS is disabled, the condition is no longer triggered.

The currently specified limit and the state of the use case are shown in the **Details** section of the EEBUS page.


## Further information

- [§14a EnWG](/webinterface/energy_management/p14a_enwg.md) — Central §14a EnWG control
- [Controllable Consumption Device (Tutorial)](/tutorials/verbrauchseinrichtung.md) — Overview of the various implementation options
