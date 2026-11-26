---
sidebar_position: 13
---

# OVE R 37

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc4']} />

The Austrian OVE directive R 37 specifies requirements for charging stations for electric vehicles that support the power grid. These include, for example, disconnecting on undervoltage and a delayed, slow reconnection after a grid disturbance. The WARP4 Charger implements these functions directly in the charge controller.

The page appears under `Energy Management` if **Austria** is selected as country under [System -> Settings](/webinterface/system/settings.md). If OVE R 37 is enabled, the page stays visible even if the country is changed later.

![image](/img/webinterface/energy_management/ove_r37.png)

:::note

The configuration must only be changed by a qualified electrician. Saving requires the electrician password `Ele4223W`.

:::

## Functions

If OVE R 37 is enabled, the following functions apply. Voltage, current and frequency are measured by the energy meter of the charger.

- **Undervoltage trip**: If the voltage of a phase stays below the trip threshold for longer than the observation time, charging is interrupted.
- **Reconnection**: After a trip, charging only resumes once all phase voltages are between 0.9 and 1.09 pu (207 V to 251 V) and the mains frequency is between 49.9 Hz and 50.1 Hz, and these conditions have been met for the entire reconnect wait time. If a condition is violated in the meantime, the wait time starts again.
- **Ramp-up**: After reconnecting, the charging current starts at 6 A and increases by 1 A per minute up to 32 A.
- **Restart**: After a restart of the charger (e.g. after a power failure), charging does not resume immediately. If a vehicle is connected within 30 seconds, the same procedure as after a trip applies (wait time and ramp-up).
- **Symmetry**: Single- and two-phase charging is limited to 16 A. During three-phase charging, the charging current is limited to 16 A if the phase currents differ by more than 16 A.
- **Random start delay**: Charging with a preset start time, e.g. via an [automation rule](/webinterface/wallbox/automation.md), starts with a random delay of 0 to 300 seconds.

Whether OVE R 37 is currently blocking or limiting charging can also be seen on the [Charge Status](/webinterface/wallbox/charge_status.md) page under the charging current limit **OVE R 37**.

## Configuration

### OVE R 37 enabled

Enables or disables the OVE R 37 functions.

The following parameters are already set to the default values required by the directive on delivery. Usually OVE R 37 only needs to be enabled.

### Undervoltage trip threshold

The voltage below which a trip occurs. It is given in thousandths of the nominal voltage of 230 V (‰ pu). The default value 800 corresponds to 0.80 pu, i.e. about 184 V.

### Undervoltage observation time

How long the voltage must stay below the trip threshold before a trip occurs. Default: 3000 ms.

### Reconnect wait time

How long the reconnection conditions must be met before charging resumes after a trip. 0 to 300 seconds are allowed, default: 60 s.

### Electrician password

Required to save the configuration.

## Status

If OVE R 37 is enabled, the current state is shown at the top of the page:

- **OVE R 37 state**:
  - **Normal**: Charging is possible without restrictions.
  - **Tripped**: Charging was interrupted, the reconnection conditions are not met.
  - **Waiting for reconnect**: The conditions are met, the reconnect wait time is running.
  - **Ramping up**: The ramp-up is active.
  - **Waiting after restart**: The charger was restarted less than 30 seconds ago.
- **Trip reason**: The reason of the last trip, e.g. undervoltage.
- **Charge start delay**: Shown while the random start delay is running.
- **Voltage in range**: Whether all connected phase voltages are between 0.9 and 1.1 pu (207 V to 253 V). A voltage outside of this range does not trip automatically. A trip only occurs below the undervoltage trip threshold.
- **Frequency in range**: Whether the mains frequency is between 49.9 Hz and 50.1 Hz. The frequency never trips an active charge, it is only a condition for reconnection.

## Further information

- [System -> Settings](/webinterface/system/settings.md): Selection of the country
- [Charge Status](/webinterface/wallbox/charge_status.md): Charging current limits of the charger
