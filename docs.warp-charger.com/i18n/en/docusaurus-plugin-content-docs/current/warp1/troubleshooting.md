---
sidebar_position: 5
---

# Troubleshooting

Error states are indicated by the charger through the LED in the cover. For the WARP1 Charger
Smart and WARP1 Charger Pro variants, the status page of the charge controller provides
further information.

## Error Diagnosis

### Charger LED is off

There are various possible causes for this error state:

 * The charger is disabled via the key switch. See [Controls](/warp1/assembly_and_installation.md).
 * The charger LED turns off after about 15 minutes of inactivity. Pressing the button or connecting an electric vehicle wakes the charger again and the LED should light up permanently again.
 * The charger is not powered. Possible causes: power outage, fuse or residual current circuit breaker has tripped.
 * The internal charge controller is without power. The charger has two internal fine fuses; one of them may be defective.
 * The internal connection cable to the cover was plugged onto the button rotated by 180°.

### Charger LED flashes very quickly

After switching on the power supply, the charger calibrates the DC fault current detection.
After approx. 10 seconds, the calibration should be complete and the charger LED should light
up permanently (ready for operation).

### Charger LED flashes twice at intervals (web interface shows switch error)

The charger was not installed correctly. The switch setting of the charge controller is still
at factory state. See [Setting the Charging Current](/warp1/assembly_and_installation.md#setting-the-charging-current).

### Charger LED flashes three times at intervals (web interface shows calibration error)

The DC calibration could not be completed. Disconnect the power supply to the charger and
switch it on again after 5 seconds. The calibration should now be successful.

:::note

With firmware older than 1.1.0, no vehicle may be connected when switching on the charger so
that the calibration is successful.

:::

### Charger LED flashes four times at intervals (web interface shows contactor error)

There are various possible causes for this error state:

 * Grounding fault of the charger, check grounding
 * Phase L1 without voltage
 * Contactor does not switch on correctly (no voltage for L1 after the contactor), no contact
 * Contactor does not switch off correctly (voltage of L1 is still present after the contactor despite switching off), "contactor is stuck"
 * One of the internal fine fuses is defective.

### Charger LED flashes five times at intervals (web interface shows communication error)

There is a communication error with the electric vehicle. If this occurs for the first time,
disconnect the charging cable from the vehicle, wait 10 seconds and reconnect the charging
cable to the vehicle (restart charging process).

If the problem persists, there may be various reasons:

 * There is a fault with the charging cable (short circuit, dirty / moist contacts, etc.). The charger must then be taken out of operation immediately and professionally repaired.
 * There is a technical defect in the vehicle.
 * There is a technical defect in the charger (charge controller defective, etc.).
 * The vehicle requests IEC 61851-1 status "D" (charging with ventilation). This mode is not supported by the charger.
 * The vehicle transmits IEC 61851-1 status E or F. In both cases, this is an error detected by the vehicle.

### The charger is not reachable via WiFi, but the LED is lit

In this case, check whether the charger has possibly gone into access point fallback. As in
the delivery state, the charger then opens its own WiFi. If the access data has not been
changed, it corresponds to the factory settings and can be found on the sticker on the back
of the manual.

## Spare Parts

Spare parts for the WARP1 Charger [are available in our shop](https://shop.warp-charger.com/en/spare-parts/warp1-spare-parts.html):

| Article number | Component |
|-|-|
| WARP-CASE | WARP Charger Case |
| WARP-CON-4P-63A | Contactor 4-pole, DIN rail, 63 A |
| WARP-DC-PROTECT | DC residual current protection module 6 mA |
| WARP-METER-3PH-MID | Bidirectional three-phase meter, 3 phases, RS485, MID |
| WARP-PS-12V | DIN rail power supply 230 V AC to 12 V, 1.25 A |
| WARP-T2-5M-16A | Type 2 plug with 5 m cable, 11 kW / 16 A |
| WARP-T2-5M-32A | Type 2 plug with 5 m cable, 22 kW / 32 A |
| WARP-T2-75M-16A | Type 2 plug with 7.5 m cable, 11 kW / 16 A |
| WARP-T2-75M-32A | Type 2 plug with 7.5 m cable, 22 kW / 32 A |
| 113 | ESP32 Brick |
| 277 | RS485 Bricklet |
| 2159 | EVSE Bricklet |
| 6150 | Bricklet cable 15 cm (7p-7p) |
| 6189 | 7 V to 28 V to 5 V inline power supply |

## Circuit Diagram

A circuit diagram is available in a separate document.

## Fuse Replacement

The charger is internally protected by two 6.3×32 mm fine fuses (medium time-lag (m),
500 mA). Tinkerforge uses fuses of type "ESKA 632.214".
