---
sidebar_position: 4
---

# EEBUS

EEBUS ist ein Kommunikationsstandard, der unter anderem von Energienetzbetreibern genutzt wird, um steuerbare Verbrauchseinrichtungen (z.B. Wallboxen, Wärmepumpen) gemäß [§14a EnWG](/docs/webinterface/energy_management/p14a_enwg.md) zu steuern. Die EEBUS-Schnittstelle ist auf WARP Chargern und WARP Energy Managern verfügbar.

## Funktionsweise

EEBUS nutzt das SHIP-Protokoll (Smart Home IP) zur Geräteerkennung und Verbindungsherstellung im lokalen Netzwerk. Die Kommunikation erfolgt verschlüsselt über TLS/WebSocket. Die Geräte identifizieren sich gegenseitig über einen SKI (Subject Key Identifier).

## Verügbare Use Cases

EEBUS definiert verschiedene Use Cases für unterschiedliche Anwendungsbereiche.

### Netzbetreibersteuerung

- **LPC** (Limitation of Power Consumption): Ermöglicht dem Netzbetreiber, die Leistungsaufnahme zu begrenzen. Wird von Steuerboxen zur Netzsteuerung gemäß §14a EnWG verwendet. Verfügbar auf WARP Charger und Energy Manager.

### E-Mobility (nur WARP Charger)

- **EVCC** (EV Commissioning and Configuration): Informationen über das angeschlossene Elektrofahrzeug (Kommunikationsstandard, Leistungsgrenzen, asymmetrisches Laden).
- **EVSECC** (EVSE Commissioning and Configuration): Betriebszustand der Ladestation und eventuelle Fehlerzustände.
- **EVCEM** (EV Charging Electricity Measurement): Messwerte des Ladevorgangs (Strom, Leistung, geladene Energie pro Phase).
- **MPC** (Monitoring of Power Consumption): Überwachung der Leistungsaufnahme der Wallbox mit Messwerten für Leistung, Strom, Spannung und Frequenz.

### Energiemanagement (nur Energy Manager)

- **MGCP** (Monitoring of Grid Connection Point): Überwachung des Netzanschlusspunkts mit Messwerten für Leistung, Energie, Strom, Spannung und Frequenz.


## Konfiguration

Die EEBUS-Schnittstelle wird über die Seite **EEBUS** im Webinterface konfiguriert.

![image](/img/interfaces/eebus/eebus.png)

### SKI (Subject Key Identifier)

Der SKI ist ein eindeutiger kryptographischer Bezeichner für das Gerät. Wenn das Gerät mit z.B. einer Steuerbox kommunizieren soll, wird der SKI bei der Einrichtung der Steuerbox benötigt.

### Details

Im aufklappbaren Bereich **Details** werden die aktuellen Werte der aktiven Use Cases angezeigt. Die angezeigten Werte spiegeln die jeweils neuesten EEBUS-Kommunikationsdaten wider.

### EEBUS aktiviert

Aktiviert oder deaktiviert die EEBUS-Kommunikation. EEBUS ist standardmäßig deaktiviert.

### Geräte hinzufügen (Pairing)

EEBUS-Geräte müssen sich gegenseitig vertrauen, bevor sie kommunizieren können. Verbindungen von unbekannten Geräten werden abgelehnt.

Über den "+"-Button können neue Geräte hinzugefügt werden.

![image](/img/interfaces/eebus/eebus_add.png)

Falls ein Gerät nicht automatisch erkannt wird, ist es möglich die SKI und Adresse/Port/WSS-Pfad manuell anzugeben. Einem hinzugefügten Gerät wird standardmäßig vertraut.


## Weitere Informationen

- [§14a EnWG](/docs/webinterface/energy_management/p14a_enwg.md) — Zentrale §14a-EnWG-Steuerung
- [Steuerbare Verbrauchseinrichtung (Tutorial)](/docs/tutorials/verbrauchseinrichtung.md) — Übersicht über die verschiedenen Möglichkeiten zur Umsetzung
