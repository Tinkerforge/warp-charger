---
sidebar_position: 4
---

# Technical Specification

### Electrical Properties

| Property | Value |
|-|-|
| Charging Standard | DIN EN 61851‐1 / ISO 15118-2 / (ISO 15118-20 via software update) |
| Charging Power | 1.4 kW to 11 kW / 22 kW* |
| Nominal Voltage | 230 V / 400 V / single-phase/three-phase AC |
| Nominal Frequency | 50 Hz |
| Nominal Current | 16 A / 32 A (depending on variant 11 kW/22 kW) |
| Phase Switching | Internal between single-phase and three-phase |
| Fault Current Detection | DC 6 mA (integrated) |
| Current Measurement (Pro only) | Integrated MID‐certified energy meter (Iskra WM3M4) according to EU Measuring Instruments Directive 2014/32/EU |
| Standby (WiFi active) | Smart ≤ 3 W; Pro ≤ 5 W |

### Connections & Cabling

| Property | Value |
|-|-|
| Vehicle Charging Plug | Type 2 |
| Charging Cable Length | 5.0 m and 7.5 m or custom length(*) |
| Supply Line Cross-Section | 2.5 mm² to 10 mm² |
| Supply Line Entry | M32 - From bottom and rear possible |
| Supply Line Diameter | 11 mm to 21 mm |
| Data Cable Entry | M25 - From bottom and rear possible. M25 sealing insert with two 9 mm holes |

### Mechanics & Housing

| Property | Value |
|-|-|
| Dimensions | 280 × 215 × 95 mm (W/H/D, Bounding Box) |
| Weight | Depending on cable length, approx. 8 kg (*) |
| Protection Class | IP54 (splash-proof, suitable for outdoor use) |
| Impact Resistance | Housing IK09 (7 Joule according to EN 60079-0) |
| Operating Temperature | ‐25 °C to +50 °C (Average over 24 h: < 35 °C) |

### Communication & Interfaces

| Property | Value |
|-|-|
| Interfaces | HTTP, MQTT, EEBUS, Modbus/TCP, OCPP, SunSpec |
| §14a EnWG Controllable | Via internal shutdown input, EEBUS, via interfaces, or [WARP Energy Manager](@current-wem/introduction) |

### Access & User Management

| Property | Value |
|-|-|
| Access Control | NFC (RFID), web interface, Autocharge, Android/iOS app, API |
| NFC‐Tags | 3 NFC cards included in delivery, max. 32 can be learned |
| Users | Max. 32 configurable |

### Features

| Property | Value |
|-|-|
| Energy Meters | Access to readings from energy meters, inverters and battery storage systems over the network. More than 100 third-party devices supported. |
| Charge Management | Integrated static/dynamic management; can be configured as a charge manager for up to 64 WARP, WARP2, WARP3 and/or WARP4 Chargers. |
| Central Management | Can optionally provide centralized user management and charge tracking. |
| Dynamic Electricity Prices | Supports all tariffs. Electricity prices from the ENTSO-E electricity market. Configurable surcharges. Price calendar with surcharges by day of the week and time of day. |
| Eco Mode | Automatic cost-optimized charging by a configurable departure time. Uses solar forecast data, PV excess charging and dynamic electricity prices. |
| Solar Forecast | Via api.forecast.solar. Up to 6 PV planes can be configured. |
| PV Excess Charging | Takes readings from the grid connection and battery storage into account. Automatic phase switching. |
| Battery Control | Controls the charging and discharging behavior of battery storage systems. Up to 64 rules can be defined. |
| Automation Rules | Up to 14 rules can be defined to implement custom automations without programming. |
| Charge Tracker | Records up to 32768 charging processes locally on the charger. Pro version only: Includes charged energy. |

### Scope of Delivery

| Property | Value |
|-|-|
| Scope of Delivery | Charger, operating manual incl. installation instructions, drilling template, test protocol, 3x NFC‐cards |

(*) Depending on variant/equipment.
