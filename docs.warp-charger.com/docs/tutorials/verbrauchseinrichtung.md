---
sidebar_position: 6
---

# Steuerbare Verbrauchseinrichtung nach §14a EnWG

Wallboxen gehören nach §14a EnWG zu sogenannten Steuerbaren
Verbrauchseinrichtungen, da deren Anschlussleistung mehr als 4,2 kW
beträgt.

WARP Charger und WARP Energy Manager verfügen über ein dediziertes
[§14a-EnWG-Modul](/docs/webinterface/energy_management/p14a_enwg.md),
das die Steuerung durch den Netzbetreiber zentral konfiguriert.
Abhängig von der gewählten Signalquelle wird bei Empfang eines
Steuersignals das berechnete Leistungslimit automatisch auf die
konfigurierten Verbraucher (Wallboxen und/oder Heizung) angewendet.

Welche Signalquelle genutzt werden kann, hängt von den Vorgaben
des örtlichen Netzbetreibers und dem eingesetzten Gerät ab.

## §14a EnWG Module

Nutzer mit steuerbaren Verbrauchseinrichtungen werden finanziell entlastet, indem sie günstigere Netzentgelte 
bezahlen. Dazu kann ein Modul gewählt werden:

### Modul 1 - Pauschale Reduktion

Bei Modul 1 wird das Netzentgelt pauschal für einen angenonmmenen fixen Stromverbrauch reduziert. Daraus ergibt sich ein fixer Euro-Betrag der jährlich über die Stromrechnung gutgeschrieben wird.
Diese Gutschrift ist pauschal und dementsprechend unabhängig vom eigenen Stromverbrauch. Für die technische Umsetzung von Modul 1 ist keine zusätzliche Hardware notwendig.
Die Reduktion hat keine technischen Auswirkungen auf WARP Charger oder WARP Energy Manager. Dieses Modul lohnt sich bei sehr niedrigen Stromverbräuchen.

### Modul 2 - Prozentuale 60% Reduktion

Bei diesem Modul wird das Netzentgelt pauschal auf 40 Prozent reduziert. Technisch ist ein eigener Verbrauchszähler für die Verbrauchseinrichtung notwendig. 
Durch diesen Stromzähler entstehen zusätzliche Kosten (Zählergebühr). Das reduzierte Entgelt wird nur für den Strombezug über diesen Zähler berechnet. 
Auch Modul 2 hat keine technischen Auswirkungen auf WARP Charger oder WARP Energy Manager. Diese Option ist eigentlich nur für Verbraucher mit hohem Stromverbrauch interessant.

### Modul 3 - Pauschale + Zeitvariable Reduktion

Modul 3 kann nur in Kombination mit Modul 1 genutzt werden. Es wird eine pauschale Gutschrift gezahlt, zusätzlich sind die
Netzentgelte aber zeitvariabel in drei Stufen. Das heißt je nach Tageszeit müssen verschiedene Netzentgelte gezahlt werden.
Es gibt einen Standardtarif mit "normalen" Netzentgelten, einen Hochtarif mit deutlich teureren Netzentgelten und einen Niedrigtarif mit günstigen Netzentgelten.
Die Uhrzeiten zu denen die Tarife gelten werden vom jeweiligen Netzbetreiber festgelegt und sind verschieden.

Mit Modul 3 lohnt es sich den Stromverbrauch von Geräten wie Wallboxen oder Wärmepumpen in Niedrigtarif-Zeiten zu legen.
Dies ist für [WARP Charger Wallboxen](/docs/warp_charger/introduction)
automatisch mit dem [Eco-Modus](/docs/webinterface/energy_management/eco_mode) und für Wärmepumpen mit dem 
[WARP Energy Manager 2.0](/docs/warp_energy_manager/introduction) und dessen [Heizungsmodul](/docs/webinterface/energy_management/heater) möglich.

Technisch ist für das Modul 3 ein intelligentes Messsystem notwendig (iMSys = Smart Meter + Smart Meter Gateway).
Über eine daran angeschlossene Steuerbox wird die Steuerbare Verbrauchseinrichtung gesteuert. Diese Steuerbox gibt es in zwei Ausführungen.

#### Steuerbox mit Schaltausgängen (stufenweise Leistungsreduzierung)
Diese Steuerbox besitzt Schaltausgänge mit denen die Leistung der Verbrauchseinrichtungen reduziert werden können. Dies ist Vergleichbar mit den
alten Rundsteuerempfängern. Für das Auslesen von Schaltausgängen bieten wir mehrere Möglichkeiten der Umsetzung, die nachfolgend beschrieben sind.

#### Steuerbox mit digitaler Schnittstelle (dynamische Leistungsreduzierung)
Bei dieser Steuerbox wird eine digitale Schnittstelle genutzt um die Leistung der Verbrauchseinrichtungen zu reduzieren.
Vorgesehen hierfür ist [EEBUS](#eebus). Die Steuerung erfolgt über das Netzwerk. Der WARP Charger oder 
WARP Energy Manager kann direkt mittels EEBUS, wie nachfolgend beschrieben, gesteuert werden.


## Technische Umsetzung

Zur Umsetzung der Steuerbarkeit nach §14a gibt es verschiedene Optionen, die nachfolgend erklärt werden.

### Rundsteuerempfänger/Steuerbox am WARP Charger

Am Abschalteingang innerhalb der Wallbox kann ein potentialfreier
Kontakt (spannungsfreier Schaltkontakt) angeschlossen werden. Dazu muss
eine Steuerleitung vom Rundsteuerempfänger oder der Steuerbox des
Netzbetreibers in die Wallbox gelegt und am Ladecontroller angeschlossen
werden. Für Details zum Anschluss am Klemmbock siehe
[Montage und Installation](/docs/warp_charger/assembly_and_installation.md#evse-klemmblock--abschalteingang).

Im §14a-EnWG-Modul wird als Signalquelle **Abschalteingang der Wallbox**
ausgewählt. Das Leistungslimit wird dann automatisch angewendet,
sobald der Netzbetreiber den Eingang schaltet.

![image](/img/webinterface/energy_management/p14a_enwg.png)

### Rundsteuerempfänger/Steuerbox am WARP Energy Manager

Anstatt eine Steuerleitung in die Wallbox zu legen, besteht auch die
Möglichkeit, einen der vier Eingänge des WARP Energy Managers mit dem
Rundsteuerempfänger oder der Steuerbox zu verbinden. Der WARP Energy
Manager steuert dann die Leistung der Wallbox(en) über das Netzwerk
(LAN/WLAN). Eine gesonderte Steuerleitung zur Wallbox entfällt.

Im §14a-EnWG-Modul wird als Signalquelle **Eingang des Energy Managers**
ausgewählt und der entsprechende Eingang (1-4) konfiguriert.


### EEBUS

[EEBUS](/docs/interfaces/eebus) ist die vorgesehene Schnittstelle
zur Steuerung von Verbrauchseinrichtungen seitens der Netzbetreiber.
Im §14a-EnWG-Modul wird als Signalquelle **EEBUS** ausgewählt.
Das Steuersignal wird dann über die EEBUS-Schnittstelle empfangen.

WARP Charger Wallboxen oder auch der WARP Energy Manager können dann auf die Steuerbefehle reagieren.

### API (HTTP/MQTT)

Das Steuersignal kann auch per HTTP- oder MQTT-API empfangen werden.
Im §14a-EnWG-Modul wird als Signalquelle **API** ausgewählt.
Details zur API finden sich in der API-Dokumentation unter `p14a_enwg/control_update`.

### Weitere Schnittstellen (OCPP, Modbus TCP)

Generell kann die Ladeleistung der Wallbox auch über alle weiteren
implementierten Schnittstellen gesteuert werden. Netzbetreiber setzen
zur Steuerung aktuell wenn überhaupt OCPP oder Modbus TCP ein.
Diese Schnittstellen nutzen nicht das §14a-EnWG-Modul, sondern steuern
die Wallbox direkt.

## Weitere Informationen

- [§14a-EnWG-Modul (Konfiguration)](/docs/webinterface/energy_management/p14a_enwg.md) — Dokumentation aller Einstellungen
- [Heizung](/docs/webinterface/energy_management/heater.md) — Konfiguration der SG-Ready-Steuerung
- [EEBUS-Schnittstelle](/docs/interfaces/eebus) — Details zur EEBUS-Anbindung
