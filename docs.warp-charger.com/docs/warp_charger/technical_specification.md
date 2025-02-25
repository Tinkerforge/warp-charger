---
sidebar_position: 4
---

# Technische Spezifikation

Der WARP3 Charger zeichnet sich durch folgende technische Spezifikation aus:

### Elektrische Eigenschaften

| Eigenschaft | Wert |
|-|-|
| Ladestandard | DIN EN 61851‐1 |
| Nennspannung | 230 V 1-phasig AC / 400 V 3-phasig AC |
| Nennfrequenz | 50 Hz |
| Stromverbrauch | Basic / Smart ≤ 3 W; Pro ≤ 5 W (Standby, WLAN aktiv) |
| Nennstrom | 16 A / 32 A (*) |
| Betriebstemperatur | ‐25 °C bis +50 °C (Durchschnitt in 24 h: < 35 °C) |
| Fehlerstromerkennung | DC 6 mA (integriert) |
| Strommessung | Integrierter MID‐geeichter Stromzähler nach EU‐Messgeräterichtlinie 2014/32/EU (nur Pro) |
| §14a EnWG steuerbar | Mittels internen Abschalteingang, über Schnittstellen oder WARP Energy Manager |

### Mechanische Eigenschaften

| Eigenschaft | Wert |
|-|-|
| Fahrzeugladestecker | Typ 2 |
| Ladekabellänge | 5,0 m und 7,5 m (*) |
| Zuleitungsquerschnitt | 2,5 mm² bis 10 mm² |
| Zuleitungseinführung | Von der Unterseite und Rückseite möglich |
| Abmessungen Wallbox | 280 × 215 × 95 mm (B/H/T, Bounding Box) |
| Anbringung | [Siehe Bohrschablone](https://www.warp-charger.com/documents/WARP3_Bohrschablone.pdf) |
| Gewicht | Je nach Kabellänge, ca. 8 kg (*) |
| Schutzart | IP54 (spritzwassergeschützt, für den Außenbereich geeignet) |
| Lieferumfang | Wallbox, Betriebsanleitung inkl. Installationsanleitung, Bohrschablone, Prüfprotokoll, 3x NFC‐Karten |

### Software Eigenschaften

| Eigenschaft | Wert |
|-|-|
| Ladestrom | Konfigurierbar in 1 mA Schritten |
| Phasenumschaltung | Intern zwischen einphasig und dreiphasig |
| CP-Trennung | Automatische Simulation von an- und abstecken des Kabels zum Aufwecken von Autos |
| Zugangsverriegelung | NFC (RFID), Webinterface, API |
| Lastmanagement | Statisch / dynamisch integriert, max. 64 WARP Charger |
| Lademodi | PV-Überschussladen, Eco-Modus mit dynamischen Strompreisen und PV-Prognose, Schnellladen |
| NFC‐Tags | 3 NFC Karten im Lieferumfang, max. 32 anlernbar |
| NFC Typen | NFC Forum Typ1, Typ2, Typ3 und Mifare Classic unterstützt (auch eigene Karten anlernbar) |
| Benutzer | Max. 32 konfigurierbar |
| Schnittstellen | HTTP, MQTT, Modbus/TCP, OCPP, SunSpec |
| Modbus-Register | WARP Charger Tabelle und Simulation von Bender CC613 und Keba C-Series |

(*) Je nach Variante der Wallbox (Basic / Smart / Pro, 5 m / 7,5 m, 11 kW / 22 kW).
