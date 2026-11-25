---
sidebar_position: 4
---

# EEBUS

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

EEBUS ist ein Kommunikationsstandard, der unter anderem von Energienetzbetreibern genutzt wird, um steuerbare Verbrauchseinrichtungen (z.B. Wallboxen, Wärmepumpen) gemäß [§14a EnWG](/docs/webinterface/energy_management/p14a_enwg.md) zu steuern und die Einspeisung von Erzeugungsanlagen (z.B. PV-Anlagen) gemäß [§9 EEG](#einspeisebegrenzung) zu begrenzen. Die EEBUS-Schnittstelle ist auf WARP Chargern und WARP Energy Managern verfügbar.

## Funktionsweise

EEBUS nutzt mDNS zur Geräteerkennung  und das SHIP-Protokoll (Smart Home IP) zur Verbindungsherstellung im lokalen Netzwerk. Die Kommunikation erfolgt verschlüsselt über TLS/WebSocket. Die Geräte identifizieren sich gegenseitig über einen SKI (Subject Key Identifier).

## Verfügbare Use Cases

EEBUS definiert verschiedene Use Cases für unterschiedliche Anwendungsbereiche.

### Netzbetreibersteuerung

- **LPC** (Limitation of Power Consumption, Actor: Controllable System): Ermöglicht dem Netzbetreiber, die Leistungsaufnahme zu begrenzen. Wird von Steuerboxen zur Netzsteuerung gemäß §14a EnWG verwendet. Verfügbar auf WARP Charger und Energy Manager.
- **LPP** (Limitation of Power Production, Actor: Controllable System): Ermöglicht dem Netzbetreiber, die Einspeisung zu begrenzen (§9 EEG). Die Begrenzung kann über eine [Automatisierungsregel](#einspeisebegrenzung) an den Wechselrichter weitergegeben werden. Nur Energy Manager.

### E-Mobility (nur WARP Charger)

- **EVCC** (EV Commissioning and Configuration, Actor: EV): Informationen über das angeschlossene Elektrofahrzeug (Kommunikationsstandard, Leistungsgrenzen, asymmetrisches Laden).
- **EVSECC** (EVSE Commissioning and Configuration, Actor: EVSE): Betriebszustand der Ladestation und eventuelle Fehlerzustände.
- **EVCEM** (EV Charging Electricity Measurement, Actor: EV): Messwerte des Ladevorgangs (Strom, Leistung, geladene Energie pro Phase).
- **MPC** (Monitoring of Power Consumption, Actor: Monitored Unit): Überwachung der Leistungsaufnahme der Wallbox mit Messwerten für Leistung, Strom, Spannung und Frequenz.

### Energiemanagement (nur Energy Manager)

- **MGCP** (Monitoring of Grid Connection Point, Actor: Grid Connection Point): Überwachung des Netzanschlusspunkts mit Messwerten für Leistung, Energie, Strom, Spannung und Frequenz.


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

## Einspeisebegrenzung nach §9 EEG (nur Energy Manager) {#einspeisebegrenzung}

<DeviceCompatibility supported={['wem1', 'wem2']} />

Über den Use Case **LPP** kann die Steuerbox des Netzbetreibers die Einspeiseleistung begrenzen. Der WARP Energy Manager kann die Erzeugung der PV-Anlage nicht selbst regeln. Die Begrenzung wird daher über eine [Automatisierungsregel](/docs/webinterface/energy_manager/automation.md) an den Wechselrichter weitergegeben, z.B. indem ein Relais des Energy Managers einen Digitaleingang des Wechselrichters schaltet. Welche Einspeiseleistung der Wechselrichter bei geschlossenem Eingang zulässt (z.B. 0 %), wird im Wechselrichter konfiguriert.

Dazu werden zwei Regeln mit der Bedingung **§9 EEG (EEBUS-Einspeisebegrenzung)** angelegt:

* Wenn §9 EEG (EEBUS-Einspeisebegrenzung) **ausgelöst** wird, Relais schließen.
* Wenn §9 EEG (EEBUS-Einspeisebegrenzung) **nicht mehr ausgelöst** ist, Relais öffnen.

Die Bedingung gilt als ausgelöst, wenn

* die Steuerbox eine Begrenzung aktiviert hat oder
* die Verbindung zur Steuerbox unterbrochen ist (Failsafe-Zustand) und das von der Steuerbox vorgegebene Failsafe-Limit gilt.

Nach einem Neustart gilt bis zur erneuten Übernahme durch die Steuerbox (maximal 120 Sekunden) ebenfalls das Failsafe-Limit. Der aktuelle Zustand wird nach jedem Neustart und nach dem Aktivieren von EEBUS an die Automatisierungsregeln gemeldet, sodass das Relais immer den aktuellen Zustand widerspiegelt. Wird EEBUS deaktiviert, gilt die Bedingung als nicht mehr ausgelöst.

Das aktuell vorgegebene Limit und der Zustand des Use Cases werden im Bereich **Details** der EEBUS-Seite angezeigt.

## Weitere Informationen

- [§14a EnWG](/docs/webinterface/energy_management/p14a_enwg.md) — Zentrale §14a-EnWG-Steuerung
- [Steuerbare Verbrauchseinrichtung (Tutorial)](/docs/tutorials/verbrauchseinrichtung.md) — Übersicht über die verschiedenen Möglichkeiten zur Umsetzung
