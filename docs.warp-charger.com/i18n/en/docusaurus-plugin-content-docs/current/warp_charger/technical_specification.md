---
sidebar_position: 4
---

# Technical Specification

The WARP3 Charger has the following technical specification:

### Electrical Properties

| Property | Value |
|-|-|
| Charging Standard | DIN EN 61851‐1 |
| Nominal Voltage | 230 V 1-phase AC / 400 V 3-phase AC |
| Nominal Frequency | 50 Hz |
| Power Consumption | Basic / Smart ≤ 3 W; Pro ≤ 5 W (Standby, WiFi active) |
| Nominal Current | 16 A / 32 A (depending on variant 11 kW/22 kW) |
| Operating Temperature | ‐25 °C to +50 °C (Average over 24 h: < 35 °C) |
| Fault Current Detection | DC 6 mA (integrated) |
| Current Measurement | Integrated MID‐certified electricity meter according to EU Measuring Instruments Directive 2014/32/EU (Pro only) |
| §14a EnWG Controllable | Via internal shutdown input, via interfaces, or [WARP Energy Manager](/warp_energy_manager/introduction.md) |

### Mechanical Properties

| Property | Value |
|-|-|
| Vehicle Charging Plug | Type 2 |
| Charging Cable Length | 5.0 m and 7.5 m (*) |
| Supply Line Cross-Section | 2.5 mm² to 10 mm² |
| Supply Line Entry | From bottom and rear possible |
| Wallbox Dimensions | 280 × 215 × 95 mm (W/H/D, Bounding Box) |
| Mounting | [See Drilling Template](https://www.warp-charger.com/documents/WARP3_Bohrschablone.pdf) |
| Weight | Depending on cable length, approx. 8 kg (*) |
| Protection Class | IP54 (splash-proof, suitable for outdoor use) |
| Scope of Delivery | Wallbox, operating manual incl. installation instructions, drilling template, test protocol, 3x NFC‐cards |

### Software Properties

| Property | Value |
|-|-|
| Charging Current | Configurable in 1 mA steps |
| Phase Switching | Internal between single-phase and three-phase |
| CP Disconnect | Automatic simulation of cable plugging and unplugging to wake up cars |
| Access Control | NFC (RFID), web interface, API |
| Charge Management | Static / dynamic integrated, max. 64 WARP Charger |
| Charging Modes | PV excess charging, Eco mode with dynamic electricity prices and PV forecast, fast charging |
| NFC‐Tags | 3 NFC cards included in delivery, max. 32 can be learned |
| NFC Types | NFC Forum Type1, Type2, Type3 and Mifare Classic supported (custom cards can also be learned) |
| Users | Max. 32 configurable |
| Interfaces | HTTP, MQTT, Modbus/TCP, OCPP, SunSpec |
| Modbus Registers | WARP Charger table and simulation of Bender CC613 and Keba C-Series |

(*) Depending on wallbox variant (Basic / Smart / Pro, 5 m / 7.5 m, 11 kW / 22 kW).
