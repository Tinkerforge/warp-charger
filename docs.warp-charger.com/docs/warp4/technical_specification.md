---
sidebar_position: 4
---

# Technische Spezifikation

### Elektrische Leistungsdaten

| Eigenschaft | Wert |
|-|-|
| Ladestandard | DIN EN 61851‐1 / ISO 15118-2 / (ISO 15118-20 über Softwareupdate) |
| Ladeleistung | 1,4 kW bis 11 kW / 22 kW* |
| Nennspannung | 230 V / 400 V / 1/3 AC |
| Nennfrequenz | 50 Hz |
| Nennstrom | 16 A / 32 A (abhängig von Variante 11 kW/22 kW) |
| Phasenumschaltung | Intern zwischen ein- und dreiphasig |
| Fehlerstromerkennung | DC 6 mA (integriert) |
| Strommessung (nur Pro)| Integrierter MID‐geeichter Stromzähler (Iskra WM3M4) nach EU‐Messgeräterichtlinie 2014/32/EU |
| Standby (WLAN an) | Smart ≤ 3 W; Pro ≤ 5 W |

### Anschluss & Verkabelung

| Eigenschaft | Wert |
|-|-|
| Fahrzeugladestecker | Typ 2 |
| Ladekabellänge | 5,0 m, 7,5 m oder Sonderlänge(*) |
| Zuleitungsquerschnitt | 2,5 mm² bis 10 mm² |
| Zuleitungseinführung | M32 - Von der Unterseite und Rückseite möglich |
| Zuleitungsdurchmesser | 11 mm bis 21 mm |
| Datenleitungseinführung | M25 - Von der Unterseite und Rückseite möglich. M25 Dichteinsatz mit 2x 9mm Bohrungen |

### Mechanik & Gehäuse

| Eigenschaft | Wert |
|-|-|
| Abmessungen | 280 × 215 × 95 mm (B/H/T, Bounding Box) |
| Gewicht | Je nach Kabellänge, ca. 8 kg (*) |
| Schutzart | IP54 (spritzwassergeschützt, für den Außenbereich geeignet) |
| Schlagfestigkeit | Gehäuse IK09 (7 Joule nach EN 60079-0) |
| Betriebstemperatur | ‐25 °C bis +50 °C (Durchschnitt in 24 h: < 35 °C) |


### Kommunikation & Schnittstellen

| Eigenschaft | Wert |
|-|-|
| Schnittstellen | HTTP, MQTT, EEBUS, Modbus/TCP, OCPP, SunSpec |
| §14a EnWG steuerbar | Mittels internen Abschalteingang, EEBUS, über Schnittstellen oder [WARP Energy Manager](@current-wem/introduction) |

### Zugang & Benutzerverwaltung

| Eigenschaft | Wert |
|-|-|
| Zugangsverriegelung | NFC (RFID), Webinterface, Autocharge, Android-/iOS-App, API |
| NFC‐Tags | 3 NFC Karten im Lieferumfang, max. 32 anlernbar |
| Benutzer | Max. 32 konfigurierbar |


### Features

| Eigenschaft | Wert |
|-|-|
| Stromzähler | Zugriff auf Messwerte von Stromzählern, Wechselrichtern, Batteriespeichern über das Netzwerk. Mehr als 100 Fremd-Geräte unterstützt. |
| Lastmanagement | Statisch/dynamisch integriert, kann als Lastmanager für max. 64 WARP, WARP2, WARP3 und/oder WARP4 Charger konfiguriert werden. |
| Zentrale Verwaltung | Kann optional die Benutzerverwaltung und das Ladelogbuch zentral übernehmen. |
| Dynamische Strompreise | Unterstützung aller Tarife. Strompreise von Strombörse ENTSO-E. Aufschläge definierbar. Preiskalender konfigurierbar mit Aufschlägen pro Wochentag und Uhrzeit. |
| Eco-Modus | Automatische kostenoptimierte Ladung bis zu definierbarer Abfahrtszeit. Nutzung von PV-Prognosedaten, PV-Überschussladen und dyn. Strompreise.|
| PV-Prognose | Mittels api.forecast.solar. Bis zu 6 PV-Flächen definierbar. |
| PV-Überschussladen | Beachtet Messwerte vom Netzanschluss und Batteriespeicher. Automatische Phasenumschaltung. |
| Batteriesteuerung | Ermöglicht die Steuerung das Lade- und Entladeverhaltens von Batteriespeichern. Bis zu 64 Regeln definierbar. |
| Automatisierungsregeln | Bis zu 14 Regeln definierbar um eigene Automatisierungen ohne Programmieren umzusetzen. |
| Ladelogbuch | Der Ladetracker zeichnet bis zu 32768 Ladevorgänge lokal auf der Wallbox auf. Nur Pro Version: Inkl. geladene Energie. |


### Features

| Eigenschaft | Wert |
|-|-|
| Lieferumfang | Wallbox, Betriebsanleitung inkl. Installationsanleitung, Bohrschablone, Prüfprotokoll, 3x NFC‐Karten |

(*) abhängig von Variante/Ausstattung
