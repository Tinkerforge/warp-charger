---
sidebar_position: 2
---

# Assembly and Installation

:::note

Much of the online documentation applies to WARP1, WARP2 and WARP3. However, assembly
and installation differs slightly between the three generations. This
documentation is designed for WARP3. For help with assembly and installation of WARP1 and
WARP2, please refer to the respective operating manuals at https://warp-charger.com/downloads.

:::

### Scope of Delivery

The wallbox delivery includes:
-   Pre-assembled wallbox including cover
-   DIN A4 envelope with:
    -   [Operating Manual](https://www.warp-charger.com/documents/WARP3_Betriebsanleitung.pdf)
    -   Test protocol of the wallbox
    -   [Drilling Template](https://www.warp-charger.com/documents/WARP3_Bohrschablone.pdf)

For Smart and Pro variants additionally:
-   Three NFC cards

The wallbox is delivered in corrugated cardboard packaging, the envelope with
accessories is located in the upper level of the packaging. The cable is coiled
in the lower level.

![image](/img/warp_charger/packaging_opened.jpg)

### Installation Location

If possible, the wallbox should be installed protected from weather conditions.
Direct sunlight should be avoided to prevent unnecessary heating of the wallbox.
Adequate ventilation must be ensured. The dust protection cap of the Type 2 plug should
not be attached if it could fill with water from rain or similar. In this case,
corrosion of the plug contacts could occur.

### Wall Mounting

To mount the wallbox, the cover must be removed. For this, the
four Phillips screws (marked red in the image) must be loosened. After loosening the
screws, it can be removed from the wallbox.

![image](/img/warp_charger/warp_screw_points_ready.jpg)

The button in the cover is connected via a cable and must be
disconnected from the cable by pressing the latch (marked blue).

![image](/img/warp_charger/warp3_frontLEDcable_arrow.jpg)

Additionally, the grounding plug (marked green) must be unplugged
from the front panel. Only then can the cover be completely set aside.

After removing the cover, the housing can be mounted
on the wall. The included drilling template can be used for drilling
the mounting holes. When mounting, ensure a sufficiently stable surface.

We recommend using 5 mm or 6 mm screws for mounting. The required
screw length depends on the surface. The screw head diameter must not
exceed 11 mm, otherwise the screw will not fit into
the corresponding opening in the housing. For mounting on a
stone wall, for example, 5×80 mm wood screws with
8×50 mm wall plugs can be used.

The drilling template is also available here for download: [Drilling Template WARP Charger 3](https://www.warp-charger.com/documents/WARP3_Bohrschablone.pdf)

### Requirements for Electrical Installation

The selection of cable cross-section and circuit protection for the
wallbox supply line must comply with national regulations. Typically, the wallbox
is connected three-phase. For this, a three-phase circuit breaker with
C-characteristic should be used. For single-phase operation of the
wallbox, a single-phase circuit breaker must be used accordingly. 
The wallbox has internal DC fault current detection. This interrupts 
the charging process at a DC fault current ≥ 6 mA.
Therefore, only an upstream Type A 30mA AC residual-current device (RCCB)
is necessary. The wallbox may only be connected in a TN / TT network.

## Electrical Connection

:::note

The work described in this section may only be performed by a
qualified electrician.

:::

After the wallbox has been mounted, it can now be connected.
The cover must be removed for this.

### Connecting the Supply Line

![image](/img/warp_charger/warp_cable_cut_ready.jpg)

The supply line should be prepared for all variants as shown in the photo above.
We recommend stripping the cable to a length of at least 130 mm. 
For the terminals, a stripping length of 10 mm to 12 mm is specified.

The supply line is connected to the internal terminal block. To offer
maximum freedom of movement with rigid conductors, the wires are
routed in a small loop over the terminal block and connected to the
free spring terminal positions. The wires are inserted into the terminals
according to the sequence and terminal labels.

![image](/img/warp_charger/warp3_smart_open_connected.jpg)

Finally, the cable gland must be tightened. The gland has a clamping
range of 11 mm to 22 mm and should be tightened to 10 Nm according to
the manufacturer.

The correct seating of the wires and phase assignment must be checked after
installation! All connections within the wallbox must be tightened.
Next, the maximum charging current must be set.

### Alternative: Cable Entry from the Rear

The cable entry of the WARP3 Charger from the bottom (delivery state)
can be converted so that cable entry is from the rear. For this, the
cable gland (M32) for the supply line and the cable gland for the
network cable must be unscrewed from the wallbox housing. The holes in
the rear of the wallbox are sealed from inside with blind plugs in the
delivery state. These must be removed and screwed into the now open
holes at the bottom. The cable glands are then screwed into the
wallbox housing from the rear.

![image](/img/warp_charger/warp3_back.jpg)

### Variant with Factory-Connected Supply Line

If the wallbox is ordered with a pre-installed supply line from the factory,
it must be connected outside the wallbox. The colors are assigned according
to DIN and as follows: L1 brown, L2 black, L3 gray, N blue, PE yellow/green.

The correct seating of the wires and phase assignment must be checked after
installation! Then the maximum charging current must be set.

### Alternative: Cable Entry from the Rear

The cable entry of the WARP3 Charger from the bottom (factory default) can be modified so that the cable entry is from the rear. To do this, the cable entry (M32) for the supply line and the cable entry for the network cable must be unscrewed from the wallbox housing. The holes in the rear of the wallbox are sealed from the inside with blind plugs in the factory default state. These must be removed and screwed into the now open holes on the bottom. The cable entries are then screwed into the wallbox housing from the rear.

![image](/img/warp_charger/warp3_back.jpg)

### Variant with Factory-Installed Supply Line

If the wallbox is ordered with a factory pre-installed supply line, it must be connected outside the wallbox. The wire colors follow DIN standards and are assigned as follows: L1 brown, L2 black, L3 gray, N blue, PE yellow/green.

The correct seating of the wires and phase assignment must be checked after installation! Afterwards, the maximum charging current must be set.

### Single-Phase Operation

All wallboxes can be connected and operated single-phase.
For this, phase L1 must be connected, as it is also used for
power supply to the wallbox. L2 and L3 are only switched through by the
wallbox and can therefore remain unconnected.

A WARP3 Charger Smart or Pro should be configured for
[single-phase operation](/webinterface/wallbox/settings.md) in the web interface.

### Setting the Charging Current

The maximum allowed charging current must be set depending on the house-side
circuit protection. The charging current must not be set higher
than allowed by the supply line or circuit protection.

To set the charging current, the cover must be opened. The maximum
charging current is set via four DIP switches on the right of the charge controller
(EVSE) as follows (maximum allowed charging current in gray):

![image](/img/warp_charger/warp3_switch_location.jpg)

The various switch positions are documented in the following photo.
In factory state, the switches are set so that the wallbox is inactive ("invalid").

As an example, in the first row, second photo from left, switch 1 is
set to "ON" and switches 2, 3 and 4 are set to "OFF". This sets a
maximum charging power of approx. 4 kW (3×6 A) for three-phase operation.
If the wallbox is only connected single-phase, the vehicle can draw
a maximum of 1.4 kW (1×6 A) via the wallbox.

![image](/img/warp_charger/hardware_dip_vertical.png)

The switch position and associated maximum charging current may only be
changed after installation by a qualified electrician taking into account
the mentioned conditions!

:::note

If no maximum charging current is set (0A), the wallbox is in an
error state.

:::




### Creating LAN / RJ45 Cable

To connect the WARP3 Charger via LAN, a LAN / RJ45 cable must be prepared.
The RJ45 cable can be routed into the wallbox using a cable gland.
On the charge controller (on the right in the wallbox) there is an
RJ45 socket where the routed cable can be plugged in. We recommend
routing the cable in an arc to the left over the terminal block. Larger
plugs, for example tool-free or RJ45 plugs with an LSA connection,
can also be used.

![image](/img/warp_charger/warp3_pro_open_highlighted_LAN.jpg)

## Testing

Each wallbox was individually tested at the factory according to IEC 60364-6 and the
corresponding valid national regulations; the respective test protocol is included.
Nevertheless, a test of the entire installation according to the same regulations is
necessary before initial commissioning.

When measuring insulation resistance, a lower value is measured for L1
(approx. 1 MΩ), as the installed charge controller has an optocoupler
with a 1 MΩ series resistor between L1 and PE (grounding monitoring).
If an EVSE adapter is used during measurement, erroneous measurements on
L2, L3 and N (measured against PE) may occur due to the mentioned
monitoring circuit in interaction with the EVSE adapter. If this is the case,
the insulation measurement must be performed without an EVSE adapter
directly at the Type 2 plug.

The internal DC fault current detection is automatically tested by the wallbox.

After the wallbox has been installed and the correct electrical
installation has been verified, the wallbox can be commissioned.
In the first step, the power supply to the wallbox is switched on.
The LED then flashes very quickly in magenta. The wallbox performs
a calibration of the DC fault current detection during the first three seconds.
After completing this calibration, the LED lights up continuously.
The wallbox is now ready for operation. If the LED does not now
light up permanently in blue, an error has been detected.

Next, an electric vehicle can be connected to the wallbox for charging.
To do this, the protective cap is removed from the charging plug and
the plug is inserted into the charging socket of the electric vehicle. After
a few seconds, a contactor in the wallbox should audibly switch and
the vehicle should indicate the start of the charging process. During
charging, the LED "breathes" blue. When charging is complete, it
lights up permanently. After approx. 15 minutes of inactivity, the LED
is switched off.

Using the front button, a charging process can be immediately interrupted
(default setting). Alternatively, the charging cable can be unlocked from the
electric vehicle, which also interrupts the charging process. To restart
the charging process in both cases, the connection to the vehicle must be
disconnected and then reconnected (unplug and replug the cable) or the
charging process must be restarted via the web interface.

## Controls

The RGB LED built into the front button can assume different colors
depending on the operating state. The behavior when the button is pressed
can be configured in the wallbox web interface.

Additionally, the Smart and Pro wallbox variants have an NFC module
that allows charging authorization e.g. via chip card. A detailed
description can be found in the section [NFC Tags](/webinterface/users/nfc-tags.md).

## EVSE Terminal Block / Shutdown Input

On the right in the wallbox is the charge controller. Next to the
DIP switch where the maximum charging current is set, there is a
terminal block. The CP line of the Type 2 charging cable is connected to this,
as well as the PP resistor that defines the maximum current of the
charging cable.

Additionally, there is the shutdown input ("EN") here. This input
must be short-circuited with PE to be active. PE is available multiple
times on the terminal block. For configuration of the shutdown input,
see [Controllable Consumption Device according to §14a EnWG](/tutorials/verbrauchseinrichtung.md).

![image](/img/warp_charger/evse_clamp.jpg)
