---
sidebar_position: 1
---

# EVCC

### Einführung

Dein WARP Charger ist mit [EVCC](https://evcc.io) kompatibel. EVCC ist eine Open-Source-Lösung, mit der du auf einfache Weise den Überschuss deiner Photovoltaik-Anlage zum Laden deines Elektroautos benutzen kannst. EVCC implementiert zudem weitere APIs, mit denen du zum Beispiel eine Hausbatterie bevorzugt, oder dein Elektroauto bis zu einem gewünschten Ladestand laden kannst. Weitere Informationen zu EVCC findest du auf [evcc.io](https://evcc.io), detaillierte Dokumentation, ein Support-Forum und den Quellcode im [GitHub-Repository](https://github.com/andig/evcc).

Diese Anleitung zeigt dir, wie du EVCC aufsetzt, deinen WARP Charger mit EVCC verknüpfst und wie weitere Komponenten, beispielhaft ein Elektroauto eingebunden werden können. Hierfür benötigst du neben deinem WARP Charger nur einen Rechner, auf dem EVCC ausgeführt werden soll. Wir verwenden im Folgenden einen Raspberry Pi. EVCC kann auch auf anderen Plattformen installiert werden, aber da die Steuerung des WARP Chargers möglichst robust sein soll, bietet es sich an ein System nur für diesen Einsatzzweck abzustellen. Die notwendigen Zähler, die die Stromerzeugung einer PV-Anlage, sowie den Gesamtverbrauch des Hauses messen, kannst du direkt in EVCC konfigurieren, oder zunächst simulieren.

![EVCC Schema](/img/evcc/evcc-schema.svg)

Ladesteuerung mit EVCC

### Vorbereitung des Raspberry Pis

Zunächst musst du eine SD-Karte mit dem Betriebssystem für den Raspberry Pi vorbereiten. Am einfachsten ist das mit dem [Raspberry Pi Imager](https://www.raspberrypi.org/software/). Der RPi-Imager lädt das ausgewählte Betriebssystem herunter und flasht es auf eine angeschlossene Micro-SD-Karte. Wenn du mit der Benutzung einer Linux-Konsole vertraut bist, empfehlen wir das Raspberry Pi OS Lite, das im Imager unter `OS auswählen` -> `Raspberry Pi OS (other)` zu finden ist. Falls du mit einer graphischen Oberfläche arbeiten möchtest, kannst du das normale Raspberry Pi OS verwenden. Mit der Tastenkombination STRG+SHIFT+X kannst du die erweiterten Optionen öffnen um z.B. den SSH-Server zu aktivieren, oder ein WLAN-Netzwerk, die Spracheinstellungen und einen Hostnamen zu konfigurieren. Der Imager flasht nach Auswahl der SD-Karte und klicken auf `Schreiben` das Betriebssystem auf die Micro-SD-Karte.

![Raspberry Pi Imager Screenshot](/img/evcc/rpi_imager.png)

Raspberry Pi Imager

Du kannst jetzt die Micro-SD-Karte in den Raspberry Pi einlegen und ihn booten. Nachdem du dich gegebenenfalls eingeloggt hast (per SSH auf `pi@raspberry`, oder in der Textkonsole als `pi`; Passwort ist jeweils `raspberrypi`), solltest du zunächst, falls du die graphische Oberfläche gebootet hast, dem Einrichtungs-Wizard folgen. In beiden Fällen solltest du danach in der Konsole mit `sudo apt update` und `sudo apt upgrade` das System aktualisieren. Danach kannst du den Pi mit `sudo reboot` neustarten.

### Verknüpfen des WARP Chargers über die HTTP-API ab EVCC Version >= 300.4

Im Webinterface von EVCC muss in der Konfiguration (Laden & Heizen) / Wallbox nun nichts weiter eingegeben werden als die IP-Adresse oder der mDNS Hostname.

Es muss sonst nichts weiter auf der dem WARP Charger konfiguriert werden.

:::note
Insbesondere sollte unter `Energiemanagement -> Wallboxen` die Fremdsteuerung deaktiviert werden. Die Fremdsteuerung an dieser Stelle bezieht sich nur das Lastmanagement von WARP Chargern untereinander. Wenn per EVCC ein PV-Überschussladen erfolgen soll, dann muss auch unter `Energiemanagement -> PV-Überschussladen` das Überschussladen deaktiviert werden. Das Überschussladen kann nur entweder vom WARP Charger selbst oder von EVCC geregelt werden. Nicht von beiden gleichzeitig.
:::

### Verknüpfen des WARP Energy Managers 1.0 (optional)


Falls du einen WARP Energy Manager 1.0 und das zugehörige Schütz zur Phasenumschaltung installiert hast, kannst du EVCC die Phasenumschaltung steuern lassen, um deinen PV-Überschuss besser auszunutzen.

Hierzu musst du zuerst, analog zum WARP Charger, die MQTT-Verbindung des Energy Managers konfigurieren. Die Verbindung kannst du wieder in der Konsole des Pis testen: `mosquitto_sub -v -t 'wem/#'` liefert empfangene Nachrichten aller Energy Manager, die mit dem Broker verbunden sind.

Damit EVCC später den WARP Energy Manager steuern darf, musst du unter `Energiemanager -> Einstellungen` den Umschaltungsmodus auf externe Steuerung (EVCC) ändern. Das PV-Überschussladen des Energy Managers wird dann deaktiviert, da EVCC diese Aufgabe übernehmen soll.

:::note
Wird eine WARP Energy Manager 1.0 von EVCC verwendet um die Phasenumschaltung einer WARP2 Wallbox durchzuführen, dann sollten auf dem WARP Energy Manager keine Einstellungen zum PV-Überschussladen oder Lastmanagement vorgenommen werden. Diese Funktionen konkurrieren ansonsten mit der Steuerung durch EVCC.
:::

![EVCC WARP Energy Manager](/img/evcc/evcc_wem.png)

Energy-Manager-Konfiguration

### Installation und Konfiguration von EVCC

Die Installation und Konfiguration von EVCC auf einem Raspberry Pi wird in der [EVCC-Dokumentation](https://docs.evcc.io/docs/installation/linux) erklärt. Alternativ kann EVCC wie [hier beschrieben](https://docs.evcc.io/docs/installation/docker) als Docker-Container installiert werden. Falls du die Verbindung von EVCC und dem WARP Charger testen willst ohne die notwendigen Zähler einzurichten kannst du diese simulieren, wie im nächsten Abschnitt beschrieben.

Bei der Ausführung von `evcc configure` kannst du als Wallbox `TinkerForge WARP Charger Smart` bzw. `TinkerForge WARP Charger Pro` auswählen und folgende Hinweise beachten:

*   Als IP-Adresse oder Hostname musst du **nicht** den entsprechenden Wert der Wallbox, sondern den in vorherigen Abschnitt konfigurierten Broker-Hostname oder dessen IP-Adresse eintragen.
*   Das Topic ist der in der MQTT-Konfiguration gesetzte Topic-Präfix, z.B. warp/ABC. Mit diesem beginnt das Topic jeder Nachricht, die du mit `mosquitto_sub -v -t 'warp/#'` oder `mosquitto_sub -v -t 'warp2/#'` oder `mosquitto_sub -v -t 'warp3/#'` sehen kannst.
*   Wenn du wie oben beschrieben einen WARP Energy Manager zur Phasenumschaltung verwenden möchtest, musst du den MQTT-Topic-Präfix des Energy Managers (z.B. wem/XYZ) angeben, wenn `evcc configure` nach energymanager fragt.


