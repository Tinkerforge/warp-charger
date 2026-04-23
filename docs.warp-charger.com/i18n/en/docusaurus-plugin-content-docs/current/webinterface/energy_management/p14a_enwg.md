---
sidebar_position: 10
---

# §14a EnWG

§14a of the German Energy Industry Act (Energiewirtschaftsgesetz, EnWG) allows grid operators to temporarily reduce the power consumption of controllable consumer devices (wallboxes, heat pumps, battery storage, air conditioning) to prevent local grid overload. The devices are never fully shut off. A minimum of 4200 W always remains available.

This page configures the central §14a EnWG control. Depending on the selected signal source, when a control signal is received the calculated power limit is automatically applied to the configured consumers (wallboxes and/or heating).

:::note

The §14a EnWG control is available on the WARP Charger and the WARP Energy Manager. Depending on the device, different signal sources and target devices are available.

:::

![image](/img/webinterface/energy_management/p14a_enwg.png)

## Configuration

### §14a EnWG enabled

Enables or disables the §14a EnWG control. When disabled, no power limits are applied.

### Signal source

The signal source determines where the grid operator's control signal is received from. The following options are available:

- **Charger shutdown input** (WARP Charger only): The signal is received via the potential-free shutdown input inside the wallbox. A ripple control receiver or control box from the grid operator is connected directly to the shutdown input.
- **Energy Manager input** (Energy Manager only): The signal is received via one of the four inputs of the WARP Energy Manager. The ripple control receiver or control box is connected to an input of the Energy Manager. The wallboxes are then controlled via the network.
- **EEBUS**: The control signal is received via the [EEBus interface](/docs/interfaces/eebus). EEBus is the designated interface for grid operator control of consumer devices.
- **API**: The control signal is received via the HTTP/MQTT API. Details can be found in the API documentation under `p14a_enwg/control_update`.

### Input (only with signal source "Energy Manager input")

Selects the input (1–4) of the WARP Energy Manager to which the ripple control receiver or control box is connected.

### Device count

Number of controllable consumer devices managed by the energy management system. The minimum power for a single device is 4200 W. For multiple devices, the minimum power is calculated using simultaneity factors:

**4200 W + (number of devices − 1) × simultaneity factor × 4200 W**

| Device count | Simultaneity factor | Calculated limit |
|---|---|---|
| 1 | — | 4200 W |
| 2 | 0.80 | 7560 W |
| 3 | 0.75 | 10500 W |
| 4 | 0.70 | 13020 W |
| 5 | 0.65 | 15120 W |
| 6 | 0.60 | 16800 W |
| 7 | 0.55 | 18060 W |
| 8 | 0.50 | 18900 W |
| 9+ | 0.45 | 18900 W + n × 0.45 × 4200 W |

### Active on

Determines at which input state the power limit becomes active:

- **Closed**: The limit is applied when the input is closed (default configuration).
- **Open**: The limit is applied when the input is open.

### Target devices

This section configures which consumers the power limit should be applied to:

- **This charger** (WARP Charger only): Applies the power limit to the local wallbox.
- **Managed chargers**: Applies the power limit to all wallboxes managed via load management.
- **Heating** (Energy Manager only): Applies the power limit to the connected heating system (heat pump via SG-Ready). When heating is enabled as a target device, the **Heating max. power** can additionally be configured.

### Heating max. power (Energy Manager only)

Specifies the maximum power draw of the heating system in watts.

## Status

When the §14a EnWG control is enabled, the current status is displayed at the top of the configuration page:

- **Status**: Shows whether the power limit is currently active or inactive.
- **Current limit**: Shows the currently applied power limit in watts (only visible when active).

Additionally, a warning banner is displayed on the **Status page** when the power limit is active (e.g. "Power limited to 4200 W").

## Differences between WARP Charger and Energy Manager

| | WARP Charger | Energy Manager |
|---|---|---|
| **Signal source "Input"** | Charger shutdown input | Energy Manager input 1–4 |
| **Input selection** | Not available (single input only) | Input 1–4 selectable |
| **This charger** | Available | Not available |
| **Heating** | Not available | Available |
| **Heating max. power** | Not available | Available |

## Further information

- [Controllable Consumption Device According to §14a EnWG (Tutorial)](/tutorials/verbrauchseinrichtung.md) — Overview of the various implementation options
- [Heating](/webinterface/energy_management/heater.md) — SG-Ready control configuration
- [EEBus interface](/docs/interfaces/eebus) — Details on the EEBus connection
