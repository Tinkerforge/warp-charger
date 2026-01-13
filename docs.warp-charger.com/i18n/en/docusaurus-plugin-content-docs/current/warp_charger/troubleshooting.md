---
sidebar_position: 5
---

# Troubleshooting

Error states are indicated by the wallbox through the LED in the front button in red. For the WARP3 Charger Smart and WARP3 Charger Pro variants, the web interface or the [Charging Status page](/webinterface/wallbox/charge_status.md) provides more information.

## Error Diagnosis

### LED is off

There are various possible causes for this error state:

 * The LED turns off after about 15 minutes of inactivity. Pressing the button or connecting an electric vehicle wakes the wallbox again and the LED should light up permanently in blue again.
 * The wallbox is not powered. Possible causes: power outage, fuse or residual current device has tripped.
 * The internal charge controller is without power. The wallbox has an internal fine fuse, which may be defective.
 * The internal connection cable to the cover was not plugged in correctly (e.g., rotated 180° at the button).

### LED flashes very quickly in magenta

After switching on the power supply, the wallbox calibrates the DC fault current detection. After three seconds, the calibration should be complete and the LED should light up permanently in blue (ready for operation).

### LED flashes twice red at intervals, web interface shows switch error

The wallbox was not installed correctly. The switch setting of the charge controller is still at factory state.

### LED flashes three times red at intervals, web interface shows DC error

A DC fault current was detected. The error can be reset either via the wallbox's website or by briefly disconnecting the wallbox's power supply.

### LED flashes four times red at intervals, web interface shows contactor error or PE error

There are two different error states for this blink code with different possible causes:

Contactor error:

 * One of the contactors does not switch on correctly
 * One of the contactors does not switch off correctly,
 * "The contactor is stuck"

The wallbox's web interface provides more information about which contactor is affected.

PE error:

 * Phase L1 without voltage (possibly L1/N reversed)
 * Grounding fault of the wallbox (possibly PE not correctly connected)

### LED flashes five times red at intervals, web interface shows communication error

There is a communication error with the electric vehicle. If this occurs for the first time, disconnect the charging cable from the vehicle, wait 10 seconds and reconnect the charging cable to the vehicle (restart charging process).
If the problem persists, there may be various reasons:

 * There is a fault with the charging cable (short circuit, dirty / moist contacts, etc.). The wallbox must then be taken out of operation immediately and repaired.
 * There is a technical defect in the vehicle.
 * There is a technical defect in the wallbox (charge controller defective, etc.).
 * The vehicle requests IEC 61851-1 status "D - Charging with ventilation". This mode is not supported by the wallbox.
 * The vehicle transmits IEC 61851-1 status E or F. In both cases, this is an error detected by the vehicle.

### The wallbox is not reachable via LAN / WiFi, but the LED is blue

In this case, check whether the wallbox has possibly gone into access point fallback. As in factory state, the wallbox then opens its own WiFi.
If the access data has not been changed, it corresponds to the factory settings and can be found on the sticker on the back of the manual.

## Recovery Mode

If the wallbox neither opens its access point nor can the web interface be accessed via a configured network, the recovery mode can be started as follows:

 1. Power off the wallbox
 2. Hold down the button in the cover
 3. Restore power to the wallbox (possibly with a second person).
 4. Hold the button for approximately 20 seconds (at least 10, but maximum 30).

The wallbox then starts in recovery mode. First, the network settings are deleted and login is disabled. It should then be possible to access the wallbox again via the access point.
By disconnecting and reconnecting power within the first minute in recovery mode, a factory reset can be triggered.

## Factory Reset

If the web interface does not function correctly or the configuration is defective, all settings can be reset to factory state on the Firmware Update page.

**Note** Factory reset will lose all configurations, created users, learned NFC tags and recorded charging processes.
After reset, the web interface restarts and opens the access point with the SSID and passphrase noted on the sticker. The wallbox can now be configured again.

To prevent recorded charging processes from being lost, alternatively only the configuration can be reset. Created users (but not the user history of the charge tracker) and NFC tags are still deleted.
If a network connection can be established but the web interface itself no longer works, an attempt can be made to open the recovery page. If a connection exists via the wallbox's access point, the recovery page can be
accessed at http://10.0.0.1/recovery. With an existing connection to a network, the page can be reached at http://configured_hostname/recovery, e.g., http://warp3-ABC/recovery. On the recovery page, the wallbox can be
restarted or reset to factory state (Factory Reset), and firmware updates can be installed, debug reports downloaded, and the HTTP API used.

## Solving Charging Problems

If charging interruptions occur, this can have various causes. Possible causes can be faulty installation of the wallbox or a technical defect of the wallbox or vehicle. The following points should be checked:

 * **Type 2 plug seating:** A Type 2 plug that is not fully inserted can cause a vehicle not to charge or only to charge in an emergency charging mode with minimal power. An indication of this can be that the vehicle does not correctly lock the Type 2 plug.
 * **Inspection of all components:** All components should be checked for damage and moisture.
 * **Wallbox web interface:** Only available for Smart and Pro variants. The status page indicates the charging status, the allowed charging current and the reason for any limitations from the wallbox's perspective. More detailed information is provided on the Charging Status page. A charging log can also be generated here,
which records all values of the charging process.
 * **Measurement by a qualified electrician:** Electrical problems can be diagnosed by a qualified electrician. They can check whether all conductors are correctly connected.

## Charge Management Errors

When using charge management, two types of errors can occur: charger errors that only affect a specific charger, and management errors where charging is stopped at all controlled chargers.
Charger errors must be resolved at the corresponding charger. The [Charging Status](/webinterface/wallbox/charge_status.md) of the respective charger provides help here.

The following explains the diagnosis of management errors:

 * **Communication error / Charger not reachable**: A charger cannot be reliably reached. There may be a connection problem. In this case, check the network connection or network cable and the IP configuration of the charger.
 * **Firmware incompatible:** Charge management requires compatible firmware on all participating chargers. The current firmware versions should be compatible with each other, even when WARP(1), WARP2 and WARP3 Charger are used in a charge management network.
 * **External control disabled:** External control is disabled on one of the chargers to be controlled. This means no control by the charge manager is possible. External control can be enabled on the Chargers page.
 * **Charge controller not reachable:** The charge controller of a charger cannot be reached, but the charger itself can. In this case, the event log of the affected charger should be checked.
 * **Charge controller not responding:** The charge controller of a charger does not respond to current allocations. In this case, the event log of the affected charger should be checked.

## Fuse Replacement

The wallbox is internally protected by a 5×20 mm fine fuse (slow-blow (T), 2 A). Tinkerforge uses fuses of type "ESKA 522.520". The fuse is located on the right in the wallbox on the charge controller (EVSE) in a green fuse housing.
