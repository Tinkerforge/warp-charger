---
sidebar_position: 1
---

# Introduction

:::note

This description refers to the WARP3 Charger. For information about older
models, specifically the WARP2 Charger or WARP1 Charger, please refer to the
respective operating manuals at https://warp-charger.com/downloads.

:::


With the WARP3 Charger, we offer the third generation of our high-quality and durable wallbox for charging your electric vehicle. The wallbox is "Made in Germany", meaning developed
and manufactured by us in Germany. It features a modular design, allowing individual components to be easily replaced. When selecting components, we place great emphasis on high quality. Both the hardware and software
are open source.

![image](/img/warp_charger/front.png)

## Features

The WARP3 Charger wallbox offers the following features, depending on the variant:

 * Type 2 charging cable (DIN EN 61851-1)
 * Adjustable charging power from 1.4kW up to 11kW or 22kW (depending on model)
 * Integrated phase switching (1-phase / 3-phase charging)
 * Integrated CP disconnect and intelligent vehicle wake-up
 * PV excess charging including Eco mode (dynamic electricity prices + PV excess)
 * Integrated load management (static, dynamic) for up to 64 WARP Charger wallboxes
 * Access to electricity meters at grid connection, photovoltaic inverters, battery storage
 * Photovoltaic forecast
 * Dynamic electricity prices independent of electricity provider
 * Support for §14a EnwG - "Controllable Consumption Device"

## Variants

We offer the WARP3 Charger in three variants:
Basic, Smart and Pro. All variants feature a V4A stainless steel front panel, which can optionally be delivered
powder-coated in color DB703.

### WARP3 Charger Basic

![image](/img/warp_charger/warp3_basic_open.jpg)

The WARP3 Charger Basic is the simplest model. With this, an electric vehicle can be charged according to DIN EN 61851-1 Mode 3. The actual
charger is built into the electric vehicle. The vehicle decides whether it charges single-phase, two-phase or three-phase at the wallbox.
Each wallbox can be connected single-phase or three-phase and is
available in 11 kW and 22 kW variants. The 11kW and 22kW variants differ only in the conductor cross-section of the
Type 2 charging cable of the wallbox. The maximum charging current can be set via a configuration switch in the wallbox during installation by a qualified electrician
from 6 A to 16 A (three-phase 11 kW) or from 6 A to 32 A (three-phase 22 kW).

After inserting the Type 2 charging plug into the vehicle, the RGB LED on the front panel of the wallbox displays the vehicle's charging status. Inside the
LED ring there is a button.

### WARP3 Charger Smart

![image](/img/warp_charger/warp3_smart_open.jpg)

The WARP3 Charger Smart is equipped with a WLAN and LAN-capable controller in comparison to the Basic variant.
This can open its own WLAN as an access point or be integrated into an existing network.
Alternatively, a connection via LAN is possible. For this, a LAN cable can be routed
into the wallbox. The WARP3 Charger Smart's web interface can be accessed via WLAN or LAN. On this, you can
view the current charging status and make settings on the wallbox. For example, the charging behavior
and maximum charging power can be configured via the web interface.

If the wallbox is to be integrated into other systems, the interfaces MQTT, HTTP, Modbus TCP
and OCPP are available. The WARP3 Charger Smart offers the ability to authorize charging processes via NFC (RFID). NFC tags can be
learned and managed via the website. Charging processes can be recorded locally on the wallbox. The wallbox enables you to create a
charging logbook of charging processes with timestamp, duration and the NFC card used as a PDF or CSV file.

Multiple WARP3 Chargers can share a power connection. The built-in load management can dynamically limit the total current of all wallboxes.
The integrated energy management enables direct connection of the wallbox to photovoltaic inverters or electricity meters and enables photovoltaic-controlled
excess charging. For this purpose, the wallbox can switch between single-phase and three-phase charging (phase switching). This means an electric vehicle can be charged with an excess
of 1.4 kW (single-phase charging with 6 A charging current). Custom ideas can be implemented using automation rules. The rules are based on a condition
and an associated action. For example, you can define charging times or switch between different charging modes
depending on the recognized NFC card or a received MQTT message.

In addition to pure PV excess charging, the wallbox can also use dynamic electricity prices. For this, the wallbox can retrieve current electricity generation costs from the electricity exchange.
You can configure additional cost components specifically for your electricity provider. With a PV yield forecast, the wallbox can determine the expected PV yields. Up to six
roof surfaces with different orientations can be configured for this purpose.

In Eco+PV mode, the wallbox can use the dynamic electricity price data and PV yield forecast to decide whether cheap electricity should be used at night
to charge the vehicle, or whether it should wait for PV excess. You simply need to configure the desired departure time and the hours the vehicle should be charged.

### WARP3 Charger Pro

![image](/img/warp_charger/warp3_pro_open.jpg)

The WARP3 Charger Pro offers all the functions of the Smart variant. Additionally, it is equipped with a MID-certified electricity meter (EU Measuring Instruments Directive 2014/32/EU) that measures how much energy
(kWh) has been charged. When the charging logbook is activated, the charged energy is recorded for each charging process and thus enables, for example, billing of charging processes for company cars. The electricity meter mounted on the DIN rail in the
WARP3 Charger Pro is manufactured by Eltako and is a MID-certified German brand product.

WARP3 Charger Pro wallboxes have an additional advantage compared to WARP3 Charger Smart wallboxes when used in shared dynamic load management:
Since the load manager can determine the phase currents to the vehicles using the internal electricity meters of the wallboxes, more efficient dynamic load management can be realized.

### Optional Equipment

All wallboxes are supplied with a permanently connected 5 m or 7.5 m charging cable with Type 2 plug. In
the standard version, all WARP3 Chargers are supplied without a connection cable (supply line to the wallbox). In
this case, a connection cable must be provided during installation and connected in the wallbox.
The connection cable can be routed either from the bottom or from the rear of the wallbox.
Optionally, each wallbox can be ordered with a connection cable already installed at the factory. Additionally,
there is the option to have this equipped with a CEE plug. For the optional connection cables, we use
the following cables and CEE plugs:

 * 11 kW rubber connection cable H07RN-F 5G4 (4mm² cross-section) + 16 A CEE plug
 * 22 kW rubber connection cable H07RN-F 5G6 (6mm² cross-section) + 32 A CEE plug

### Individual Engraving/Custom Logo

Wallboxes can also be ordered with an individual engraving. In this case, the WARP logo that is
engraved on the front panel by default is replaced with the desired logo.
