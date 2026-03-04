---
sidebar_position: 1
---

# EVCC

### Einführung

Dein WARP Charger ist mit [EVCC](https://evcc.io) kompatibel. EVCC ist eine Open-Source-Lösung, mit der du auf einfache Weise den Überschuss deiner Photovoltaik-Anlage zum Laden deines Elektroautos benutzen kannst. EVCC implementiert zudem weitere APIs, mit denen du zum Beispiel eine Hausbatterie bevorzugt, oder dein Elektroauto bis zu einem gewünschten Ladestand laden kannst. Weitere Informationen zu EVCC findest du auf [evcc.io](https://evcc.io), detaillierte Dokumentation, ein Support-Forum und den Quellcode im [GitHub-Repository](https://github.com/andig/evcc).

![EVCC Schema](/img/evcc/evcc-schema.svg)

:::info
Einige der Funktionen, die EVCC bietet, z.B PV-Überschussladen und Batteriesteuerung können auch vom WARP Charger bzw. WARP Energy Manager selbst ausgeführt werden. EVCC unterstützt aber eine größere Anzahl Geräten, beispielsweise auch Wallboxen anderer Hersteller und kann Informationen über angeschlossene Fahrzeuge aus Cloud-APIs abfragen. Bestimmte Funktionen von EVCC (aber nicht die Integration der WARP-Produkte!) erfordern es, dass du ein [EVCC-Sponsor-Token](https://docs.evcc.io/docs/sponsorship) kaufst.
:::

Diese Anleitung zeigt dir, wie du EVCC aufsetzt und deinen WARP Charger mit EVCC verknüpfst. Hierfür benötigst du neben deinem WARP Charger nur einen Rechner, auf dem EVCC ausgeführt werden soll. Wir verwenden im Folgenden einen Raspberry Pi. EVCC kann auch auf [anderen Plattformen](https://docs.evcc.io/docs/installation) installiert werden, aber da die Steuerung des WARP Chargers möglichst robust sein soll, bietet es sich an ein System nur für diesen Einsatzzweck abzustellen.

### Vorbereitung des Raspberry Pis

Zunächst musst du eine SD-Karte mit dem Betriebssystem für den Raspberry Pi vorbereiten. Am einfachsten ist das mit dem [Raspberry Pi Imager](https://www.raspberrypi.org/software/), alternativ folgst du der [offiziellen Anleitung von EVCC](https://docs.evcc.io/docs/installation/linux-image). Der RPi-Imager lädt das ausgewählte Betriebssystem herunter und flasht es auf eine angeschlossene Micro-SD-Karte. Bei der Auswahl des Betriebssystems kannst du unter "Other specific-purpose OS" -> "Home automation" -> "EVCC" die aktuelle Version von EVCC zur Installation auswählen.

![Raspberry Pi Imager Screenshot](/img/evcc/rpi_imager.png)

Nach dem Beschreiben der SD-Karte kannst du diese in den Raspberry Pi einstecken und ihn booten. Das Webinterface von EVCC unter https://evcc.local sollte nach ein bis zwei Minuten erreichbar sein.

Nach Vergabe des Adminstrator-Passworts kannst du mit der Konfiguration beginnen. Klicke auf "Wallbox oder Heizung hinzufügen" -> "Ladepunkt hinzufügen" und vergib einen Namen, z.B. "WARP Charger". Danach kannst du deinen WARP Charger-Typ aus der Liste der unterstützten Wallboxen auswählen. Du musst dann die Adresse eingeben unter der EVCC den WARP Charger erreichen kann und, falls konfiguriert, Benutzername und Passwort des Webinterfaces eintragen. Wenn du einen WARP2 Charger mit vorgeschaltetem WARP Energy Manager zur Phasenumschaltung verwendest, kannst du dieses Setup auswählen und musst dann auch Adresse und möglicherweise Zugangsdaten des Energy Managers eintragen.

Nach einem Klick auf "prüfen" sollte der Status der Wallbox angezeigt werden und du kannst die Konfiguration speichern.

![EVCC-Web-UI-Screenshot](/img/evcc/evcc_ui.png)

Danach müssen noch EVCC-spezifische Ladeeinstellungen konfiguriert werden um die Einrichtung abzuschließen. Du musst danach EVCC neustarten (durch Klick auf den Button unten), damit der WARP Charger gesteuert wird, kannst aber noch weitere [Geräte, Integrationen und Funktionen](https://docs.evcc.io/docs/Home) von EVCC konfigurieren.
