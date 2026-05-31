---
sidebar_position: 1
---

# Introduction

With the WARP4 Charger, we offer the fourth generation of the high-quality and durable charger with which you can charge your electric vehicle. The charger is "Made in Germany", meaning it is developed and manufactured by us in Germany.
It has a modular design, so that individual components can be easily replaced. We place great emphasis on high quality when selecting the components. Both the hardware and the software
are open source. The WARP4 Charger is designed for a long service life and is already prepared for bidirectional charging.

![image](/img/warp4_charger/warp4_front.png)

## Features

Depending on the variant, the WARP4 Charger offers the following features:

 * Type 2 charging cable (DIN EN 61851-1, ISO 15118)
 * Charging power adjustable from 1.4 kW up to 11 kW or 22 kW (depending on model)
 * Integrated phase switching (single-phase / three-phase charging)
 * Integrated CP disconnection and intelligent vehicle wake-up
 * ISO 15118: Autocharge (vehicle identification via the charging cable) and reading of the state of charge (SoC)
 * Hardware-side prepared for bidirectional charging (V2H/V2G) (Pro)
 * PV excess charging incl. Eco Mode (dynamic tariff + PV excess)
 * Integrated charge management (static, dynamic) of up to 64 WARP Chargers
 * Access to energy meters at the grid connection, photovoltaic inverters, battery storage
 * Compatibility with over 100 devices from other manufacturers
 * Solar Forecast
 * Dynamic tariff independent of the electricity provider
 * Support for §14a EnWG - "Controllable Consumption Device"
 * All features run locally on the charger - no cloud requirement, no telemetry

## Variants

We offer the WARP4 Charger in two variants:
Smart and Pro. The two variants differ in that the Pro version has a built-in MID energy meter
and the Smart version does not. All variants come with a V4A stainless steel front panel, which can optionally be supplied powder-coated in the color
DB703.

### WARP4 Charger Smart

![image](/img/warp4_charger/warp4_smart_open.jpg)

With the WARP4 Charger Smart, an electric vehicle can be charged according to DIN EN 61851-1 Mode 3. The actual
charger is built into the electric vehicle. It decides whether to charge single-phase, two-phase, or three-phase at the charger.
Each charger can be connected single-phase or three-phase and is available as an
11 kW and 22 kW variant. The 11 kW and 22 kW variants differ only in the conductor cross-section of the
charger's Type 2 charging cable. The maximum charging current can be set via a configuration switch in the charger during installation by a qualified electrician,
from 6 A to 16 A (three-phase 11 kW) or from 6 A to 32 A (three-phase 22 kW).

After plugging the Type 2 charging connector into the vehicle, the RGB LED on the front panel of the charger indicates the charging state of the vehicle. A button is located inside the
LED ring. At the position where the Pro variant has the energy meter installed, the Smart has the DC fault current protection module.

The WARP4 Charger Smart is equipped with a Wi-Fi- and LAN-capable
controller. This can open its own Wi-Fi network as an access point or be integrated into an existing network.
Alternatively, a connection via LAN is possible. For this, a LAN cable can be routed into the charger.
The web interface of the WARP4 Charger Smart can be accessed via Wi-Fi or LAN. On it you can
view the current charging state and make settings on the charger. For example, the charging behavior and the maximum charging power can be configured via
the web interface.

If the charger is to be integrated into other systems, the interfaces MQTT, HTTP, Modbus TCP
and OCPP are available. The WARP4 Charger Smart offers the option to authorize charging via NFC (RFID). NFC tags can be taught in and managed via the web interface.
Charges can be recorded locally on the charger. The charger makes it possible to create a
charge log of the charges with timestamp, duration, and the charging card used, as a PDF or CSV file.

Multiple WARP4 Chargers can share a single power connection. The built-in charge management can dynamically limit the total current of all chargers.
The integrated energy management enables the charger to be connected directly to photovoltaic inverters or energy meters and allows photovoltaic-guided
excess charging. To do this, the charger can switch between single-phase and three-phase charging (phase switching). This means an electric vehicle can already be charged with an excess
of 1.4 kW (single-phase charging at 6 A charging current). Custom ideas can be implemented using automation rules. The rules are based on a condition
and an action linked to it. For example, you can define charging times or switch between different charging modes depending on the detected NFC card or a received MQTT message.

In addition to pure PV excess charging, the charger can also use a dynamic tariff. To do this, the charger can retrieve the current electricity generation costs from the electricity exchange.
You can configure further cost components specifically for your electricity provider. With a solar forecast, the charger can determine the expected PV yields. Up to six
roof surfaces with different orientations can be configured for this.

In Eco+PV mode, the charger can then decide on its own, based on the data from the dynamic tariff and the solar forecast, whether to use cheap electricity at night to charge
the vehicle, or whether to wait for PV excess. You simply need to configure the desired departure time as well as the number of hours the vehicle should be charged.

### WARP4 Charger Pro

![image](/img/warp4_charger/warp4_pro_open.jpg)

The WARP4 Charger Pro offers all the functions of the Smart variant. In addition, it is equipped with a MID-certified Iskra WM3M4 energy meter (EU Measuring Instruments Directive 2014/32/EU) that measures how much energy
(kWh) has been charged. With the charge log activated, the charged energy is recorded for each charge, thus enabling, for example, the billing of charges for company cars. The energy meter is mounted horizontally
and visible from the outside through a window on the left side of the housing.

WARP4 Charger Pro units also have an additional advantage compared to the WARP4 Charger Smart units when used in a shared dynamic charge management:
Since the charge manager can use the internal energy meters of the chargers to determine the phase currents to the vehicles, more efficient dynamic charge management can be realized.

Furthermore, the WARP4 Charger Pro is hardware-side prepared for bidirectional charging (V2H/V2G).

### Optional Equipment

All chargers are supplied with a permanently connected 5 m or 7.5 m charging cable with a Type 2 connector. In
the standard configuration, all WARP4 Chargers are delivered without a supply cable (feed line to the charger). In
this case, a supply cable must be provided and connected in the charger during installation.
The supply cable can be introduced either from the bottom or from the back of the charger.
Optionally, each charger can be ordered with a supply cable already installed at the factory. Additionally,
it can be fitted with a CEE plug. For the optional supply cables we use
the following cables and CEE plugs:

 * 11 kW rubber connection cable H07RN-F 5G4 (4 mm² cross-section) + 16 A CEE plug
 * 22 kW rubber connection cable H07RN-F 5G6 (6 mm² cross-section) + 32 A CEE plug

### Individual Engraving/Custom Logo

Chargers can also be ordered with an individual engraving. In this case, the WARP logo that is engraved on the front panel by default is replaced with the desired logo.
