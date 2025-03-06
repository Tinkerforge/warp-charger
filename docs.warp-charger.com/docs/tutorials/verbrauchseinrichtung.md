---
sidebar_position: 3
---

# Steuerbare Verbrauchseinrichtung nach §14a EnWG

Wallboxen gehören nach §14a EnWG zu sogenannten Steuerbaren
Verbrauchseinrichtungen, da deren Anschlussleistung mehr als 4,2 kW
beträgt.

WARP3 Charger können auf verschiedenen Arten vom Netzbetreiber gesteuert
werden. Welche Möglichkeit genutzt werden kann, hängt von den Vorgaben
des örtlichen Netzbetreibers ab.

### Schnittstellen (OCPP, Modbus TCP, HTTP, MQTT)

Generell kann die Ladeleistung der Wallbox über alle implementierten
Schnittstellen gesteuert werden. Netzbetreiber setzen
zur Steuerung typischerweise OCPP oder Modbus TCP ein.

### Rundsteuerempfänger/Steuerbox direkt am WARP Charger

Am Abschalteingang innerhalb der Wallbox kann ein potentialfreier
Kontakt (spannungsfreier Schaltkontakt) angeschlossen werden. Dazu muss
eine Steuerleitung vom Rundsteuerempfänger oder der Steuerbox des
Netzbetreibers in die Wallbox gelegt und am Ladecontroller angeschlossen
werden. Für Details zum Anschluss am Klemmbock siehe
[Montage und Installation](assembly_and_installation.md#evse-klemmblock--abschalteingang).

In der Standardkonfiguration der Wallbox wird auf 4200 W limitiert, wenn
der Abschalteingang geschlossen ist. Dieses Verhalten kann im
Webinterface unter `Wallbox` -> `Einstellungen` angepasst
werden.

![image](/img/first_steps/14enwg_input.png)

### Rundsteuerempfänger/Steuerbox mittels WARP Energy Manager

Anstatt eine Steuerleitung in die Wallbox zu legen, besteht auch die
Möglichkeit, die Eingänge des WARP Energy Managers mit dem
Rundsteuerempfänger oder der Steuerbox zu verbinden. Der WARP Energy
Manager steuert dann die Leistung der Wallbox(en) über das Netzwerk
(LAN/WLAN). Eine gesonderte Steuerleitung entfällt. Der WARP Energy
Manager muss hierfür als Lastmanager der betreffenden Wallbox(en)
konfiguriert werden. Anschließend muss in `Energiemanager` ->
`Automatisierung` folgende Regel angelegt werden:

![image](/img/first_steps/14enwg_wem_add_rule.png)

Statt 6 A muss bei einphasigem Betrieb 18 A ausgewählt werden.

In der Automatisierungsliste sieht die hinzugefügte Automatisierungsregel
dann wie folgt aus

![image](/img/first_steps/14enwg_wem_rule_added.png)