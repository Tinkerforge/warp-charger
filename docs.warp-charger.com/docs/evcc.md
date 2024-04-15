---
sidebar_position: 7
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

### Installation des MQTT-Brokers

Die Kommunikation zwischen dem WARP Charger und EVCC erfordert den Einsatz eines MQTT-Brokers. Auf dem Raspberry Pi kann mit `sudo apt install mosquitto mosquitto-clients` der [Mosquitto](https://mosquitto.org/)\-MQTT-Broker installiert werden. Mosquitto startet sofort und bei jedem Start des Systems automatisch.

Seit Mosquitto 2.0.0 muss explizit erlaubt werden, dass Mosquitto auf Netzwerk-Interfaces Verbindungen annimmt. Hierzu musst du eine neue Konfigurationsdatei namens `/etc/mosquitto/conf.d/default.conf` mit einem Texteditor deiner Wahl, auf der Konsole zum Beispiel mit `nano`[\*](https://xkcd.com/378/) anlegen und folgenden Inhalt einfügen:

listener 1883

Außerdem erlaubt Mosquitto 2.0.0 standardmäßig nur Verbindungen konfigurierter Benutzer. Einen Benutzer kannst du mit [`mosquitto_passwd`](https://mosquitto.org/man/mosquitto_passwd-1.html) anlegen. Alternativ kannst du in `/etc/mosquitto/conf.d/default.conf` zusätzlich

allow\_anonymous true

einfügen, um Verbindungen ohne Benutzername und Kennwort zu erlauben.

Damit die geänderte Konfiguration verwendet wird, musst du Mosquitto danach mit `sudo systemctl restart mosquitto` neustarten, bzw. falls du Mosquitto manuell, also nicht über den systemd-Service, starten möchtest, musst du `mosquitto -c /etc/mosquitto/mosquitto.conf` verwenden.

### Verknüpfen des WARP Chargers

(Mehr Informationen zur MQTT-Konfiguration findest du in der [API-Dokumentation](https://www.warp-charger.com/api.html))

Im Webinterface des WARP Chargers kannst du jetzt die Verbindung zum MQTT-Broker konfigurieren. Hierzu musst du unter `Schnittstellen -> MQTT` die Verbindung aktivieren und den Host eintragen (`raspberrypi` falls du ihn nicht geändert hast). Alternativ kannst du die IP-Adresse des Pis verwenden. Diese kannst du in der Konsole mit `ip -brief a` auslesen: unter eth0 die der LAN-Verbindung, oder unter wlan0 die der WLAN-Verbindung. Danach kannst du die Konfigurationsänderung durch Klicken auf Speichern anwenden. Das Webinterface startet dann neu.

Um zu Testen, ob die Verbindung zum MQTT-Broker funktioniert, kannst du zunächst die Status-Seite des Webinterfaces prüfen. Der Status der MQTT-Verbindung sollte auf Verbunden stehen. Falls das nicht der Fall ist, kannst du im Ereignislog nachsehen, was das Problem ist. Als weiteren Test kannst du in der Konsole des Pis die empfangenen Nachrichten mitlesen: `mosquitto_sub -v -t 'warp/#'` bzw. bei einem WARP2 Charger `mosquitto_sub -v -t 'warp2/#'` liefert empfangene Nachrichten aller Wallboxen, die mit dem Broker verbunden sind.

Damit EVCC später den WARP Charger steuern darf, musst du unter `Wallbox -> Ladeeinstellungen` die externe Steuerung erlauben.

![MQTT UI](/img/mqtt/mqtt_ui.png)

MQTT-Konfiguration

### Verknüpfen des WARP Energy Managers (optional)

Falls du einen WARP Energy Manager und das zugehörige Schütz zur Phasenumschaltung installiert hast, kannst du EVCC die Phasenumschaltung steuern lassen, um deinen PV-Überschuss besser auszunutzen.

Hierzu musst du zuerst, analog zum WARP Charger, die MQTT-Verbindung des Energy Managers konfigurieren. Die Verbindung kannst du wieder in der Konsole des Pis testen: `mosquitto_sub -v -t 'wem/#'` liefert empfangene Nachrichten aller Energy Manager, die mit dem Broker verbunden sind.

Damit EVCC später den WARP Energy Manager steuern darf, musst du unter `Energiemanager -> Einstellungen` den Umschaltungsmodus auf externe Steuerung (EVCC) ändern. Das PV-Überschussladen des Energy Managers wird dann deaktiviert, da EVCC diese Aufgabe übernehmen soll.

![EVCC WARP Energy Manager](/img/evcc/evcc_wem.png)

Energy-Manager-Konfiguration

### Installation und Konfiguration von EVCC

Die Installation und Konfiguration von EVCC auf einem Raspberry Pi wird in der [EVCC-Dokumentation](https://docs.evcc.io/docs/installation/linux) erklärt. Alternativ kann EVCC wie [hier beschrieben](https://docs.evcc.io/docs/installation/docker) als Docker-Container installiert werden. Falls du die Verbindung von EVCC und dem WARP Charger testen willst ohne die notwendigen Zähler einzurichten kannst du diese simulieren, wie im nächsten Abschnitt beschrieben.

Bei der Ausführung von `evcc configure` kannst du als Wallbox `TinkerForge WARP Charger Smart` bzw. `TinkerForge WARP Charger Pro` auswählen und folgende Hinweise beachten:

*   Als IP-Adresse oder Hostname musst du **nicht** den entsprechenden Wert der Wallbox, sondern den in vorherigen Abschnitt konfigurierten Broker-Hostname oder dessen IP-Adresse eintragen.
*   Das Topic ist der in der MQTT-Konfiguration gesetzte Topic-Präfix, z.B. warp/ABC. Mit diesem beginnt das Topic jeder Nachricht, die du mit `mosquitto_sub -v -t 'warp/#'` bzw. `mosquitto_sub -v -t 'warp2/#'` sehen kannst.
*   Wenn du wie oben beschrieben einen WARP Energy Manager zur Phasenumschaltung verwenden möchtest, musst du den MQTT-Topic-Präfix des Energy Managers (z.B. wem/XYZ) angeben, wenn `evcc configure` nach energymanager fragt.

### Simulation von Stromzählern

`evcc configure` unterstützt derzeit nur die Konfiguration "echter" Zähler. Simulierte Zähler können aber von Hand in die von `evcc configure` erstellte evcc.yaml-Datei eingetragen werden.

Hierzu musst du die angelegte Konfigurationsdatei (`/etc/evcc.yaml`) mit einem Texteditor deiner Wahl, auf der Konsole zum Beispiel mit `nano`[\*](https://xkcd.com/378/) editieren. Falls du bei der Konfiguration keine Zähler konfiguriert hast, sollte der site-Block der Konfigurationsdatei bis auf den Titel leer sein:

```
site:
  title: Mein Zuhause
  meters:
```

Über dem site-Block fügen wir jetzt zwei simulierte Stromzähler hinzu. Der erste Zähler (gridmeter) misst den aktuellen Netzbezug bzw. die Netzeinspeisung am Hausanschluss, der zweite misst die aktuelle Einspeisung der Solaranlage (pvmeter). Wir simulieren eine dauerhafte Einspeisung von 10 kW und eine Netzeinspeisung von 9 kW:

```
meters:
- name: gridmeter
  type: custom
  power:
    source: script
    cmd: /bin/sh -c 'echo -9000'
- name: pvmeter
  type: custom
  power:
    source: script
    cmd: /bin/sh -c 'echo 10000'
```

Die hinzugefügten Stromzähler müssen dann im site-Block registriert werden:

```
site:
  title: Mein Zuhause
  meters:
    grid: gridmeter
    pv: pvmeter
```

Nach einem Neustart durch `sudo systemctl restart evcc` sollte die EVCC-Seite die simulierten Zähler anzeigen. Mit `evcc configure` können später echte Stromzähler hinzugefügt werden.

Hier die vollständige Konfigurationsdatei (getestet mit EVCC Version 0.95):

```
# open evcc at http://evcc.local:7070
network:
  schema: http
  host: evcc.local # .local suffix announces the hostname on MDNS
  port: 7070

log: info
levels:
  cache: error

interval: 10s # control cycle interval

chargers:
- type: template
  template: tinkerforge-warp
  host: 192.168.178.72
  port: 1883
  topic: warp/ABC
  timeout: 30s
  energymanager: wem/XYZ # EnergyManager MQTT Topic (falls installiert) (optional)
  name: wallbox1

loadpoints:
- title: Garage
  charger: wallbox1
  mode: off
  phases: 3
  mincurrent: 6
  maxcurrent: 16
  resetOnDisconnect: false

meters:
- name: gridmeter
  type: custom
  power:
    source: script
    cmd: /bin/sh -c 'echo -9000'
- name: pvmeter
  type: custom
  power:
    source: script
    cmd: /bin/sh -c 'echo 10000'

site:
  title: Mein Zuhause
  meters:
    grid: gridmeter
    pv: pvmeter
```