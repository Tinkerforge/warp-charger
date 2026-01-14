---
sidebar_position: 1
---

# Settings

Various settings of the charge controller can be modified on this page:

![image](/img/webinterface/wallbox/warp-settings.jpeg)

## Manual Charge Release

When manual charge release is enabled, a charging process is never started automatically.
Each charging process must be started via the web interface, the API, or (depending on button settings)
the button. Manual charge release blocks in addition to any other active
charging current limits. This means that it does not need to be enabled if charging processes are controlled,
for example, with user authorization via NFC tag, or control via OCPP.


## Status LED Control

Allows control of the front LED with an external controller or via
the API, e.g. for external NFC authorization.

## Boost Mode

The charging electronics of some vehicles interpret a charging current prescribed by the WARP3 Charger too low.
Boost mode attempts to compensate for this effect by communicating a slightly higher charging current.


## Meter Monitoring

An energy meter is installed in the WARP3 Charger Pro. When this option is enabled, a charging process is interrupted
or not released if the energy meter or communication with it appears to be faulty. When
meter monitoring is enabled, it is thus ensured that the charged energy is recorded for every logged charging process.


## Time Limit

Sets a general time limit for charging processes. After the limit expires, a vehicle must be disconnected to enable another charging process. The time limit can be overridden for the
next or current charging process on the status page.

## Energy Limit

Sets a general energy limit for charging processes on the WARP3 Charger Pro. This function
is configured analogously to the time limit.

## Button Setting

This configures the function of the button on the front of the WARP3 Charger. In semi-public spaces,
for example, it may be useful to prohibit stopping charging via button.

## Shutdown Input

For example, a ripple control receiver can be connected to the shutdown input. Here you can set how to react to changes
at the shutdown input. In the default wallbox configuration, the limit is set to 4200 W when the shutdown input is closed, see
[Controllable Consumption Device according to §14a EnWG](/tutorials/verbrauchseinrichtung.md).


## Vehicle Wake-up Call

The charging electronics of some vehicles enter a power-saving mode if a
charging process is not started within a certain time. The vehicle wake-up call attempts to automatically
wake such charging electronics if the vehicle does not respond within 30 seconds when
power is available. This is implemented by briefly disconnecting the control pilot or CP signal.


## Automatic Phase Switching

:::note

This function only affects load management, as unused phases can be detected and released for other chargers
(phase-optimized load management).

:::

This option is only available for the WARP3 Charger Pro. If
the option is enabled, during an ongoing charging process the internal energy meter determines whether the
vehicle is only charging single-phase. If this is the case, the charger automatically switches to single-phase charging.


## Supply Line

Here you configure whether the charger is connected three-phase or
single-phase. If the charger is only connected single-phase and configured as such here,
the second contactor for phases L2 and L3 is never switched, and the charging power limitation
according to §14a EnWG is calculated accordingly.
