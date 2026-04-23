---
sidebar_position: 4
---

# EEBUS

EEBUS is a communication standard used by energy grid operators, among others, to control controllable consumer devices (e.g. wallboxes, heat pumps) in accordance with [§14a EnWG](/webinterface/energy_management/p14a_enwg.md). The EEBUS interface is available on WARP Chargers and WARP Energy Managers.

## How it works

EEBUS uses the SHIP protocol (Smart Home IP) for device discovery and connection establishment in the local network. Communication is encrypted via TLS/WebSocket. Devices identify each other using an SKI (Subject Key Identifier).

## Available use cases

EEBUS defines various use cases for different applications.

### Grid operator control

- **LPC** (Limitation of Power Consumption): Allows the grid operator to limit power consumption. Used by control boxes for grid control according to §14a EnWG. Available on WARP Charger and Energy Manager.

### E-Mobility (WARP Charger only)

- **EVCC** (EV Commissioning and Configuration): Information about the connected electric vehicle (communication standard, power limits, asymmetric charging).
- **EVSECC** (EVSE Commissioning and Configuration): Operating state of the charging station and any error conditions.
- **EVCEM** (EV Charging Electricity Measurement): Measurements of the charging process (current, power, charged energy per phase).
- **MPC** (Monitoring of Power Consumption): Monitoring of the wallbox power consumption with measurements for power, current, voltage, and frequency.

### Energy management (Energy Manager only)

- **MGCP** (Monitoring of Grid Connection Point): Monitoring of the grid connection point with measurements for power, energy, current, voltage, and frequency.


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


## Further information

- [§14a EnWG](/webinterface/energy_management/p14a_enwg.md) — Central §14a EnWG control
- [Controllable Consumption Device (Tutorial)](/tutorials/verbrauchseinrichtung.md) — Overview of the various implementation options
