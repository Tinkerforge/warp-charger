---
sidebar_position: 3
---

# Features

WARP Charger and Energy Manager report the respectively supported features on the topic [`info/features`](api_reference/info#info_features). Using the features, it is possible for an application to use the API in such a way that it is compatible with all versions and variants of the WARP Charger. Feature requirements are noted on API topics in the reference. The following features can be offered:

## `evse` Charge Controller

A charge controller is available. This feature should be present on all WARP Chargers whose hardware is functional.

## `cp_disconnect` Control Pilot Disconnect

The charge controller can interrupt the Control Pilot signal.

## `phase_switch` Phase Switch

Hardware and configuration allow manual phase switching with the API [`power_manager/external_control_update`](api_reference/power_manager#power_manager_external_control_update).

## `button_configuration` Button Configuration

The behavior of the button on the front of the charger can be reconfigured. With WARP1 this is not possible, as the button and the key switch cannot be distinguished from each other.

## `ethernet` Ethernet

An ESP Ethernet Brick is installed. A LAN connection is possible.

## `meters` Energy Meters

Values could be successfully read from at least one energy meter.

## `nfc` NFC Bricklet

An NFC bricklet was found. Authorization via NFC is possible.

## `rtc` Real Time Clock

An RTC bricklet or the RTC chip of a WARP3 or an Energy Manager was found. The system time is retained across restarts even without network time synchronization.

## `meter` (deprecated API) Energy Meter

An energy meter and hardware for reading it via RS485 is available. This feature is only set when an energy meter has been successfully read via Modbus at least once.

## `meter_phases` (deprecated API) Energy Meter Measures by Phase

The installed energy meter can measure energy and other measurement values of individual phases.

## `meter_all_values` (deprecated API) Energy Meter Measures Additional Values

The installed energy meter can read additional measurement values.
