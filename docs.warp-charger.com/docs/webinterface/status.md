---
sidebar_position: 1
---

# Status

Die Statusseite unterscheidet sich zwischen einem [WARP3 Charger](/docs/warp_charger/introduction) und
einem [WARP Energy Manager 2.0](/docs/warp_energy_manager/introduction). Sie stellt generelle Informationen zu dem
Zustand des Geräts bereit. Zum Teil bietet sie auch
Einstellungsmöglichkeiten, so zum Beispiel das Umschalten des Lademodus
von Wallboxen.

## Status (WARP3 Charger)

![image](/img/webinterface/status/warp3-status.jpeg)

:::note

Die auf der Status-Seite dargestellten Elemente hängen davon ab, welche
Module im Webinterface der Wallbox aktiviert wurden.

:::

Auf dieser Statusseite kann der **Lademodus** der Wallbox eingestellt werden.
Welche Lademodi angeboten werden, hängt davon ab ob die Wallbox für ein
PV-Überschussladen konfiguriert wurde und ob der Eco-Modus aktiviert wurde.

Der **Ladestatus** gibt Informationen dazu ob ein Fahrzeug an der Wallbox angeschlossen ist,
ob der Ladevorgang freigegeben wurde und ob das Fahrzeug lädt.

Mit der **Ladesteuerung** und dem **Konfigurierten Ladestrom** kann manuell der Ladevorgang
gesteuert werden. So kann mit dem Ladestrom ein zusätzliches Stromlimit gesetzt werden.

Über das **Zeitlimit** oder **Energielimit** (nur WARP Charger Pro) kann ein Ladevorgang
zeitlich begrenzt oder eine maximale Energiemenge (kWh) vorgegeben werden.

Der **Ladeverlauf** stellt die Ladeleistung zeitbezogen dar und ist nur bei WARP Charger Pro
Wallboxen verfügbar.

Werden Benutzer eingerichtet so werden die **Letzten Ladevorgänge** dargestellt. In diesen finden sich
Informationen zum Benutzer der geladen hat, die Ladedauer und für WARP Charger Pro Wallboxen die geladene
Energiemenge.

Die Statusseite stellt, sofern aktiviert, auch Informationen zum Lastmanagement dar.
Zusätzlich werden Informationen zu den Schnittstellen gegeben. Darunter IP-Adressen, die Stärke der WLAN-Verbindung etc.

### Weitere Beispiele
Beispiele mit Eco-Lademodus und aktiviertem Ladeplan in einem Lastmanagement mit mehreren Wallboxen.
![image](/img/webinterface/status/warp3-status2.jpeg)
![image](/img/webinterface/status/warp3-status3.jpeg)

## Status (WARP Energy Manager)

![image](/img/webinterface/status/wem2-status.jpeg)

:::note

Die auf der Status-Seite dargestellten Elemente hängen davon ab, welche
Module im Webinterface des Energy Managers aktiviert wurden.

:::

Auf der Status-Seite des Energy Managers werden Informationen zu den
aktuellen **Leistungen** von Stromzählern dargestellt. Wurden die Stromzähler
konfiguriert, so kann hier ein Überblick über den Leistungsverlauf bezogen auf
die PV-Erzeugung, dem Netzbezug oder Netzeinspeisung, dem Hausakku und dem Verbrauch.

Dieser WARP Energy Manager wurde als Lastmanager für Wallboxen konfiguriert.
Daher kann der **Lademodus** für die Wallboxen eingestellt werden.
Welche Lademodi angeboten werden, hängt davon ab ob der Energy Manager für ein
PV-Überschussladen konfiguriert wurde und ob der Eco-Modus aktiviert wurde.

Dargestellt werden die vom Energy Manager **kontrollierten Wallboxen** und deren Zustand.

Der Zustand der **SG-Ready** Schnittstelle (Heizung) und Informationen zum aktuellen
Strompreis (**Aktueller Börsenpreis** und **Durchschnittspreis**) werden ebenfalls dargestellt.

Ansatzweise sind die Daten zur **PV-Ertragsprognose** in diesem Screenshot sichtbar.
