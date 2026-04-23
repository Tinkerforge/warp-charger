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

## Signalquellen

### Rundsteuerempfänger/Steuerbox direkt am WARP Charger

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

### Rundsteuerempfänger/Steuerbox mittels WARP Energy Manager

Anstatt eine Steuerleitung in die Wallbox zu legen, besteht auch die
Möglichkeit, einen der vier Eingänge des WARP Energy Managers mit dem
Rundsteuerempfänger oder der Steuerbox zu verbinden. Der WARP Energy
Manager steuert dann die Leistung der Wallbox(en) über das Netzwerk
(LAN/WLAN). Eine gesonderte Steuerleitung zur Wallbox entfällt.

Im §14a-EnWG-Modul wird als Signalquelle **Eingang des Energy Managers**
ausgewählt und der entsprechende Eingang (1-4) konfiguriert.


### EEBus

[EEBus](/docs/interfaces/eebus) ist die vorgesehene Schnittstelle
zur Steuerung von Verbrauchseinrichtungen seitens der Netzbetreiber.
Im §14a-EnWG-Modul wird als Signalquelle **EEBus** ausgewählt.
Das Steuersignal wird dann über die EEBus-Schnittstelle empfangen.

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
- [EEBus-Schnittstelle](/docs/interfaces/eebus) — Details zur EEBus-Anbindung
