---
sidebar_position: 5
---

# Troubleshooting

The status LED of the WARP Energy Manager 1.0 blinks in case of errors. The
color indicates the type of error.

## Status LED Blink Codes

### Status LED blinks yellow

If PV excess charging is enabled, the status LED breathes yellow as soon as
power is drawn from the grid. This is not an error state. If PV excess charging
is not active and the status LED blinks yellow, the WARP Energy Manager is not
connected to the configured WiFi and no LAN cable is connected.

### Status LED blinks red

If the status LED blinks red, the WARP Energy Manager is in an error state.
Reasons can be a failed contactor monitoring or an internal error. The web
interface provides more detailed information.

### Status LED blinks purple

If the status LED blinks purple, the configuration is not complete. At least
the minimum configuration described under
[Configuration and Setup](/docs/wem1/configuration_and_setup) must be made so
that the Energy Manager works correctly.

## Fuse Replacement

The WARP Energy Manager is internally protected by two 5 × 20 mm fine fuses
(medium time-lag (M), 500 mA). Tinkerforge uses fuses of type "ESKA 521.014".
One fuse is located in the input path of the 230 V power supply (L). The other
fuse is located in the switching output of the contactor control.
