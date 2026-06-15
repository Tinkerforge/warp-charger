---
sidebar_position: 2
---

# Assembly and Installation

## Safety Instructions

The charger is designed so that safe operation is ensured when it has been
installed correctly, is in perfect technical condition and this
operating manual is followed.

:::warning

The charger may only be installed by a qualified electrician.

:::

### Intended Use

With the WARP2 Charger, electric vehicles can be charged in accordance with DIN EN 61851-1. The
charger is not suitable for other applications. Use in places where
explosive or flammable substances are stored is not permitted. Any
modification of the charging system, as well as operation with extension cables,
multiple sockets or similar, is prohibited. The charging plug must be protected against damage,
moisture and contamination and must not be used if safe operation
cannot be ensured.

:::warning

No charging process may be carried out with a damaged, contaminated or moist charging plug.

:::

### Device Malfunction / Technical Defect

If there are signs of a technical defect, the power supply
of the charger must be disconnected immediately by switching off the charger fuse in the distribution box. The
fuse must be marked with a note that it must not be switched on again. Afterwards,
a qualified electrician must be informed.

### Protective Devices of the Charger

AC fault current protection is ensured by the building-side Type A
AC residual current circuit breaker (RCCB) or a specially installed Type A
30 mA residual current circuit breaker. The charger is equipped with an integrated
DC fault current monitoring. In the event of a DC fault current ≥ 6 mA, this fault current
is detected by the charger and the connection to the vehicle is immediately
interrupted (contactor switches off). The charger is then in an
error state and can only be reset by switching the power supply off and on or via the
web interface.

:::warning

If a DC fault current occurs, the cause must be determined! A DC fault current
can "blind" the upstream residual current circuit breaker, so that
AC fault currents are then no longer correctly detected!

:::

In addition, the charger offers further protective devices: These include permanent
grounding monitoring (PE). If the grounding is interrupted, the charger goes into an
error state. Furthermore, the charger checks with every switching operation whether the installed contactor
switches correctly. If the contactor no longer switches correctly, the charger
also goes into an error state. Errors can be diagnosed as described in the
[Troubleshooting](/warp2/troubleshooting.md) section.

## Assembly

### Scope of Delivery

The charger delivery includes:

-   Pre-assembled charger including cover
-   DIN A4 envelope with:
    -   Operating manual
    -   Test protocol of the charger
    -   Drilling template

For the Smart and Pro variants additionally:

-   Three NFC cards

### Installation Location

If possible, the charger should be installed protected from weather conditions.
Direct sunlight should be avoided to prevent unnecessary heating of the
charger. Adequate ventilation must be ensured. The
dust protection cap of the Type 2 plug should not be attached if it could fill
with water from rain or similar. In this case, corrosion of the
contacts of the Type 2 plug could occur.

### Wall Mounting

To mount the charger, the cover must be removed. For this, the four
Phillips screws must be loosened. After loosening the screws, the cover can be removed from the
charger.

![image](/img/warp2/warp_screw_points_ready.jpg)

The button in the cover is connected via a cable and must be disconnected from the cable by pressing the
latch.

![image](/img/warp2/warp2_button_and_gnd_600.jpg)

Additionally, the grounding plug must be unplugged from the front panel. Only then can
the cover be completely set aside.

After removing the cover, the housing can be mounted on the wall. The included drilling template can be used for drilling
the mounting holes. When mounting, ensure a sufficiently stable surface.

We recommend using 5 mm or 6 mm screws for mounting. The required
screw length depends on the surface. The screw head diameter must not exceed
11 mm, otherwise the screw will not fit through the corresponding opening in the
housing. For mounting on a stone wall, for example,
5×80 mm wood screws with 8×50 mm wall plugs can be used.

### Requirements for Electrical Installation

The selection of cable cross-section and circuit protection of the charger supply line must
comply with national regulations. Typically, the charger
is connected three-phase. For this, a three-phase miniature circuit breaker
with C-characteristic should be used. For single-phase operation of the charger,
a single-phase miniature circuit breaker must be used accordingly. The charger has
internal DC fault current detection, which interrupts the charging process at a
DC fault current ≥ 6 mA. Therefore, only an upstream Type A
30 mA residual current circuit breaker (RCCB) is necessary. The charger may only be connected in a TN / TT network.

## Electrical Connection

:::note

The work described in this section may only be performed by a qualified
electrician.

:::

After the charger has been mounted, it can now be connected. For this, the
cover must be removed.

![image](/img/warp2/warp_cable_cut_ready.jpg)

The supply line must be prepared for all variants as shown in the photo above.
We recommend stripping the cable to a length of 23 cm. For the
terminals, a stripping length of 10 mm to 12 mm is specified.

How this supply line is connected differs between the Basic / Smart variants
(without meter) and Pro (with meter) and is described below.

### Basic / Smart Variant

![image](/img/warp2/warp2_basic_top_open.jpg)

In the Basic and Smart charger variants, the supply line is connected to an internal
terminal block. To offer maximum freedom of movement with rigid conductors,
the wires are routed around the terminal block and connected to the free spring terminal positions.
The wires are inserted into the terminals according to the sequence and terminal labels.

Finally, the cable gland must be tightened. The gland has a
clamping range of 11 mm to 22 mm and should be tightened to 10 Nm according to the manufacturer.

The correct seating of the wires and the phase assignment must be checked after the installation!
All connections within the charger must be tightened. Next, the
maximum charging current must be set (see section
[Setting the Charging Current](#setting-the-charging-current)).

### Pro Variant

![image](/img/warp2/warp2_pro_top_open.jpg)

For space reasons, the Pro variant only has a terminal block for PE. The
supply line wires except PE must be connected at the top of the meter.

Finally, the cable gland must be tightened. The gland has a
clamping range of 11 mm to 22 mm and should be tightened to 10 Nm according to the manufacturer.

The correct seating of the wires and the phase assignment must be checked after the installation!
All connections within the charger must be tightened. Next, the
maximum charging current must be set (see section
[Setting the Charging Current](#setting-the-charging-current)).

### Variant with Factory-Connected Supply Line

If the charger is ordered with a supply line pre-installed at the factory, it must be
connected outside the charger. The colors are assigned according to DIN and as
follows: L1 brown, L2 black, L3 gray, N blue, PE yellow/green.

The correct seating of the wires and the phase assignment must be checked after the installation!
Next, the maximum charging current must be set.

### Cable Entry from the Rear

From version 2.1 of the WARP Charger, the cable entry can be converted from the bottom
(delivery state) so that cable entry is from the rear.

For this, the cable entry (M32) for the supply line and the cable entry for the
network cable must be unscrewed from the charger housing. The holes in the rear of the
charger are sealed from the inside with blind plugs in the delivery state. These must be
removed and screwed into the now open holes at the bottom. The
cable entries are then screwed into the charger housing from the rear.

![image](/img/warp2/warp2_1_back_wp_ready_1000.jpg)

### Single-Phase Operation

All chargers can also be connected and operated single-phase. For this,
phase L1 must be connected, as this phase is also used for the power supply of the charger.
L2 and L3 are only switched through by the charger and can therefore
remain unconnected.

A WARP2 Charger Smart or Pro should be configured for
[single-phase operation](/docs/webinterface/wallbox/settings) in the web interface.

### Setting the Charging Current

The maximum allowed charging current must be set depending on the building-side
circuit protection. The charging current must not be set higher than the
circuit protection allows.

To set the charging current, the cover must be opened. The maximum charging current is set as
follows via two slide switches on the internal charge controller (EVSE):

![image](/img/warp2/warp2_current_configure_w_caption_600.jpg)

The various switch positions are documented in the photo above. The black block
represents the position of the switch in each case. In factory state, the switches are
set so that the charger is inactive. In the photo, the upper switch is set as an example to
the left and the lower one to the middle position. This sets a
maximum charging power for three-phase operation of 9 kW (3×13 A). If
the charger is only connected single-phase, a maximum of 3 kW (1×13 A) can be drawn from the
house connection via the charger.

:::warning

The switch position and the associated maximum charging current may only be
changed after installation by a qualified electrician taking into account the
mentioned conditions!

:::

| Switch top (1) | Switch bottom (2) | Current | Charging power single-phase | Charging power three-phase |
|-|-|-|-|-|
| left | left | 0 A | 0 kW | 0 kW |
| middle | left | 6 A | 1.4 kW | 4.1 kW |
| right | left | 10 A | 2.3 kW | 6.0 kW |
| left | middle | 13 A | 3.0 kW | 9.0 kW |
| middle | middle | 16 A | 3.7 kW | 11.0 kW |
| right | middle | 20 A | 4.6 kW | 13.8 kW |
| left | right | 25 A | 5.6 kW | 17.3 kW |
| middle | right | 32 A | 7.4 kW | 22.0 kW |

:::note

If no maximum charging current is set (0 A), the charger is in an error state.

:::

### Creating LAN / RJ45 Cable

To connect the WARP Charger via LAN, a LAN / RJ45 cable must be prepared.
Depending on the version of the charger, the execution differs here.

#### WARP 2.1

From version 2.1 of the WARP Charger, the RJ45 cable can simply be routed into the charger by means of a
cable entry. In the charger there is a
wired RJ45 socket to which the routed cable can simply be connected by means of an RJ45 plug
attached to the cable. Larger
RJ45 plugs, such as tool-free RJ45 plugs or RJ45 plugs with an LSA connection,
can thus also be used.

![image](/img/warp2/warp2_1_top_ready_1000.jpg)

#### WARP 2.0

In the WARP Charger 2.0, there is a splash-proof RJ45 feed-through on the
bottom, to which the controller installed in the charger is internally connected. To
connect a LAN cable, the blind cover must be unscrewed.

![image](/img/warp2/warp2_ethernet3_circle_600.jpg)

Then a LAN cable (e.g. Cat. 7) must be prepared as follows:

1.  Pull the LAN cable through the attachment.
2.  Crimp the supplied RJ45 plug onto the LAN cable. The contacting is
    typically done according to TIA-568 scheme A or B. The scheme used should be identical on both
    sides of the cable.

    ![image](/img/warp2/warp2_rj45_1_600.jpg)

    :::note

    The supplied RJ45 plug should be used. Tool-free RJ45 plugs
    cannot be used in the WARP Charger 2.0 due to the limited space in the plug attachment.

    :::

3.  Pull the cable back into the attachment and tighten the strain relief hand-tight.

    ![image](/img/warp2/warp2_rj45_2_600.jpg)

Finally, the RJ45 plug is inserted into the charger and the union nut is
tightened hand-tight.

![image](/img/warp2/warp2_ethernet4_600.jpg)

## Controllable Consumption Device according to §14a EnWG

According to §14a EnWG, chargers belong to so-called Controllable Consumption Devices, as
their connected load is over 4.2 kW. WARP Chargers can be controlled by the grid operator in various ways. Which
option can be used depends on the requirements of the local grid operator. Further information can be found in the tutorial
[Controllable Consumption Device according to §14a EnWG](/docs/tutorials/verbrauchseinrichtung).

#### Interfaces (OCPP, Modbus TCP, HTTP, MQTT)

In general, the charging power of the charger can be controlled via all implemented interfaces. Grid operators typically use OCPP or Modbus TCP
for control.

#### Ripple Control Receiver / Control Box

A potential-free contact (voltage-free switching contact) can be connected to the shutdown input inside the charger. For this, a control line from the ripple control receiver
or the control box of the grid operator must be routed into the charger and connected at the charge controller
(lower board) at the three-pole connector labeled "Enable" at pin 1 and pin 2.
For the charger to switch off, the setting "Shutdown input" must be configured under Charger -> Charge settings
to "Limit to 4300 W when closed" or "when
open".

#### Ripple Control Receiver / Control Box (using WARP Energy Manager)

Instead of routing a control line all the way into the charger, there is also the option to connect the
inputs of the WARP Energy Manager to the ripple control receiver or the control box.
The WARP Energy Manager then controls the power of the charger(s) via the
network (LAN/WLAN). A separate control line is not required. The WARP Energy Manager must
be configured as the load manager of the relevant charger(s) for this. Afterwards, the
following rule must be created in "Energy Manager" -> "Automation":

-   **Condition:** "Input 3 switched" (or input 4) -> "to closed"
-   **Action:** "Limit maximum total current"
-   **Maximum total current:** 6 A (or 18 A for single-phase connection)

## Testing

At the factory, each charger was individually tested according to IEC 60364-6 and the
corresponding valid national regulations; the respective measurement protocol is included. Before initial
commissioning, a test of the entire installation according to the same regulations is
nevertheless necessary.

When measuring the insulation resistance, a lower value is measured for L1 (approx.
249 kΩ). The background to this is that the installed charge controller has one
optocoupler each with a 249 kΩ series resistor, before and after the contactor, between L1 and PE
(grounding monitoring, contactor monitoring). If an EVSE adapter is
used during the measurement, erroneous measurements on L2, L3 and N (measured against PE) may
occur due to the mentioned monitoring circuit in interaction with the
EVSE adapter. If this is the case, the insulation measurement must be performed without an EVSE adapter directly at the Type 2 plug.

The internal DC fault current detection is automatically tested by the charger.

After the charger has been installed and the correct electrical installation has been verified,
the charger can be commissioned. In the first step, the power supply to the
charger is switched on. The blue LED then flashes very quickly. The charger performs in
the first three seconds a calibration of the DC fault current detection. After completion
of this calibration, the LED lights up continuously. The charger is now ready for operation. If
the LED does not now light up permanently, an error has been detected (see
[Troubleshooting](/warp2/troubleshooting.md)).

Next, an electric vehicle can be connected to the charger for charging. To do this,
the protective cap is removed from the charging plug and the plug is inserted into the charging socket of the
electric vehicle. After a short time, the contactor in the charger should audibly
switch and the vehicle should indicate the start of the charging process. The blue LED
"breathes" during the charging process. When the charging process is finished, the LED lights up
permanently. After approx. 15 minutes of inactivity, the LED switches off.

## Controls

Pressing the button on the front immediately interrupts an active charging process.
Alternatively, the charging cable can be unlocked from the electric vehicle, which also interrupts the
charging process. To restart the charging process, in
both cases the connection to the vehicle must be disconnected and then reestablished
(unplug and replug the cable).

Additionally, the Smart and Pro charger variants have an NFC module, which enables a
charging authorization e.g. via chip card. A detailed description can be found in the
section [User Management](/docs/webinterface/users/user_management).
