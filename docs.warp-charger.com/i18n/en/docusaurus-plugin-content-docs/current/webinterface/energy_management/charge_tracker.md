---
sidebar_position: 3
---

# Charge Tracker

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc1', 'wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />


![image](/img/webinterface/wallbox/charge_tracker.png)

The WARP Charger records all charging processes performed.

A WARP charger or WARP energy manager, that is the charge manager of multiple chargers with central management enabled, will track all charges of controlled chargers.

The following information is stored per charging process:
 * Start date and time of the charging process, if date and time are known.
 * User who started the charging process, if known.
 * Meter reading at start and end of the charging process (only for chargers with an energy meter, e.g. WARP Charger Pro). From this, the charged energy in kWh is calculated.
 * Duration of the charging process
 * Charger that was used (with central management by a charge manager)

Up to 32768 charging processes can be recorded.

## Electricity price

From the recorded information and the configured electricity price, the costs of the charging processes are calculated.
The costs are not recorded per charging process, but calculated based on the configured electricity price.
This means in particular that when the electricity price is changed, the displayed costs of older charging processes are also changed.

The electricity price configured here is always used. A [dynamic electricity price](/webinterface/energy_management/dynamic_tariffs.md) is not taken into account.
Additionally, the total energy charged into the vehicle is always recorded, regardless of its source (grid connection, battery storage, PV, etc.).

## Assignment to users

For charging processes to be assigned to a user:
 * at least one user must be created and either the charge authorization in user management or the central management in charge manager must be enabled.
 * an [NFC tag](/webinterface/users/user_management.md#nfc-release) or, on the WARP4 Charger, a [vehicle](/webinterface/users/vehicles.md#assignment-to-users) must be assigned to the user. Charging processes authorized via Autocharge are assigned to the user of the detected vehicle.

In the factory state, three users with one NFC tag each are configured. Then only charge authorization under [User Management](/webinterface/users/user_management.md) needs to be enabled.

## Email delivery

If [remote access](/webinterface/system/remote_access.md) is set up, the charge log can be sent automatically by email to remote access users.
At the beginning of each month, the charge log of the previous month is sent to the configured users. It is only sent once the time is synchronized and no charging process is active.
The time of the next sending is shown under **Next send**.

Up to five remote access users can be configured. For each user, user filter, charger filter, file type, language, **Hide empty charges** and, depending on the file type, letterhead or CSV format can be set.
**Test Send** in the dialog immediately sends a charge log to the selected user.

:::note

For technical reasons, the charge logs sent by email are not end-to-end encrypted.

:::

## Download charge-log

Recorded charging processes can be downloaded either as a ***PDF*** or as a ***CSV*** document compatible with common spreadsheet programs.
The generated document can be pre-filtered:
 * **User filter**: Only charging processes of a specific user, of all configured users or of deleted users.
 * **Charger filter**: Only charging processes of a specific charger, of all controlled chargers or of deleted chargers. Relevant with central management by a charge manager.
 * **Time filter**: Only charging processes in a specific time period.
 * **Hide empty charges**: Charging processes with at most 1 Wh charged are not included.

**Language** selects whether the document is generated in German or English.

If the charging processes are downloaded as PDF, a ***letterhead*** can additionally be specified. This can contain a maximum of 6 lines of 50 characters each. The letterhead is embedded in the PDF so that it is visible in the window of an envelope with standard
folding.

If the charging processes are downloaded as CSV, you can choose between two formats:
 * **Excel-compatible**: Creates a CSV file that can be loaded by Excel without import configuration. The field separator is a semicolon, in the first line this is marked (for other language versions) with `sep=;`. The file is Windows-1252 encoded, so possibly not all usernames can be displayed.
 * **RFC 4180**: Creates a CSV file formatted according to RFC 4180. The field separator is a comma, the file is UTF-8 encoded.

If remote access is set up, **Send via email to** sends the document directly to a remote access user instead of downloading it.

## Tracked charges

![image](/img/webinterface/wallbox/charge_tracker2.png)

This section shows the number of recorded charging processes and the start time of the oldest recorded charging process.
**Last charges** shows the last 30 charging processes with user, start time, charged energy, duration and charger. If an electricity price is configured, the costs are shown as well.

**Remove all tracked charges** deletes all recorded charging processes and the username history. The device is restarted afterwards. This action cannot be undone.
