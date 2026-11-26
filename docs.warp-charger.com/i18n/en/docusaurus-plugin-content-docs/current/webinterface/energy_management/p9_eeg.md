---
sidebar_position: 12
---

# §9 EEG

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wem1', 'wem2']} />

§9 of the German Renewable Energy Sources Act (Erneuerbare-Energien-Gesetz, EEG) obliges operators of PV systems to allow the grid operator to reduce the feed-in power. The grid operator specifies a power limit via a control box.

The WARP Energy Manager receives this limit and passes it to the inverter via its relays. Many inverters have an input for ripple control receivers (often called DRM or RSE) that limits the feed-in to 0 %, 30 %, 60 % or 100 % of the rated power. Each relay of the Energy Manager is connected to the contact of one level. The Energy Manager converts the limit of the grid operator into one of these levels and closes the matching relay. No automation rules are required.

![image](/img/webinterface/energy_management/p9_eeg.png)

## Connecting the inverter

Each relay in use is connected to the inverter's contact for one level, e.g. relay 1 to the contact for 30 % and relay 2 to the contact for 0 %. Which pin of the inverter belongs to which level is described in the inverter's manual.

- At most one relay is closed at a time. When the level changes, the old relay is opened first and the new one is closed afterwards.
- If no relay is closed, 100 % always applies. The inverter must be configured to feed in with full power if no contact is closed. A contact for 100 % is not connected.
- The WARP Energy Manager 2.0 has two relays, so two levels are available in addition to 100 %. The WARP Energy Manager has one relay and therefore one additional level.

:::note

Relays used by §9 EEG can no longer be switched by [automation rules](/webinterface/energy_manager/automation.md) or the API.

:::

## Configuration

### §9 EEG enabled

Enables or disables the §9 EEG control. When it is disabled, the relays in use are opened and released.

### Signal source

The signal source determines where the limit of the grid operator is received from:

- **EEBUS**: The limit is received from the grid operator's control box via the EEBUS use case **LPP** (Limitation of Power Production). EEBUS must also be enabled under `Interfaces` -> `EEBUS`. See [EEBUS interface](/interfaces/eebus.md#einspeisebegrenzung).
- **API**: The limit is set via the HTTP/MQTT API. Details can be found in the API documentation under [`p9_eeg/control_update`](/docs/interfaces/mqtt_http/api_reference/p9_eeg).

### Inverter rated power

The AC rated power of the inverter in watts. The levels of the inverter refer to its rated power, not to the installed module power (kWp). The rated power is listed in the inverter's datasheet.

### Relay 1 and relay 2

The level the inverter applies while the relay is closed: **0 %**, **30 %**, **60 %** or **Not used**. The corresponding power is shown next to each level. Each level can only be assigned to one relay. At least one relay must be used.

### Default level

The level that applies as long as the signal source has not provided a limit. 100 % and the levels of the relays in use are available.

- **API**: The default level applies after a reboot until the first call of `p9_eeg/control_update`.
- **EEBUS**: The default level applies while EEBUS is disabled or still starting. It is also the pre-configured failsafe value of the LPP use case. This value applies after a reboot and if the connection to the control box is lost. If the control box has written its own failsafe value, that value has priority.

## Calculation of the level

The Energy Manager always uses the highest available level that complies with the limit of the grid operator.

Example with an inverter with a rated power of 10000 W, relay 1 set to 30 % and relay 2 set to 0 %:

| Limit of the grid operator | Level | Closed relay |
|---|---|---|
| No limitation | 100 % | None |
| 10000 W and more | 100 % | None |
| 4200 W | 30 % (3000 W) | Relay 1 |
| 3000 W | 30 % (3000 W) | Relay 1 |
| 2999 W | 0 % (0 W) | Relay 2 |

If the limit is below the lowest available level (e.g. 2000 W if only 30 % is used), the lowest level is applied and a notice is shown. In this case the limit is not complied with. For a complete shutdown, a relay must be configured to 0 %.

## Status

If §9 EEG is enabled, the current state is shown at the top of the page:

- **Status**: The currently applied level, e.g. "Not limited (100 %)", "Feed-in limited to 30 %" or "Default level active (100 %)".
- **Requested limit**: The limit specified by the signal source in watts (only while a limitation is active).

In addition, the status display of the web interface (top right, in the app on the status page) shows the entry "9 EEG" with the current state.

## Automation

For further actions during a limitation, e.g. switching on a consumer, the condition **§9 EEG (feed-in limitation)** is available in the [automation rules](/webinterface/energy_manager/automation.md). It reacts to the states **Limited** and **Not limited**. The feed-in counts as limited if a level below 100 % is applied. This applies regardless of the signal source, i.e. also when controlled via the API and for the default level.

## Further information

- [EEBUS interface](/interfaces/eebus.md): Details on the EEBUS connection
- [§14a EnWG](/webinterface/energy_management/p14a_enwg.md): Limitation of the power consumption of controllable consumer devices
