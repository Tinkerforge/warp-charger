---
sidebar_position: 2
---

# Home Assistant

## Einführung

Dein [WARP Charger](@current-charger/introduction) oder [WARP Energy Manager](@current-wem/introduction) ist mit [Home Assistant](https://www.home-assistant.io) kompatibel.
Home Assistant ist eine Open-Source-Lösung zur Hausautomation mit einer breiten Unterstützung von Geräten.

Zur Anbindung der WARP Geräte können Modbus und MQTT genutzt werden. In dieser Anleitung verwenden wir MQTT.
Weiterhin wird davon ausgegangen, dass Home Assistant bereits installiert und in Betrieb genommen wurde.
Eine Anleitung dazu findet man auf der [offiziellen Website](https://www.home-assistant.io/installation/).

## MQTT

### Einrichten von MQTT in Home Assistant

Zuerst muss MQTT in Home Assistant aktiviert werden.
Gehe dafür in der Weboberfläche auf **Einstellungen** -> **Geräte & Dienste** -> **Integration hinzufügen**.
In dem Fenster, das sich öffnet, nach "MQTT" suchen und auswählen.
Es stehen verschiedene MQTT-Integrationen zur Verfügung.
Wir benötigen die einfache MQTT-Integration:

![MQTT Integration Selection](/img/smart_home/homeassistant/mqtt_selection.png)

Anschließend wird nach dem MQTT-Broker gefragt.
Wenn kein eigener MQTT-Broker genutzt werden soll, ist es am einfachsten, die offizielle MQTT-Broker-App zu verwenden.
Diese wird automatisch installiert.

![MQTT Broker Selection](/img/smart_home/homeassistant/mqtt_broker_select.png)

:::warning
Wenn Home Assistant als Docker-Container installiert wurde, ist das Hinzufügen von Apps über die Weboberfläche nicht möglich.
Der MQTT-Broker muss in diesem Fall separat installiert und konfiguriert werden.
Die Installation im Docker-Container ist daher nur fortgeschrittenen Benutzern zu empfehlen.
:::
![MQTT Broker install success](/img/smart_home/homeassistant/mqtt_broker_install_success.png)

Zuletzt geht man auf **Einstellungen** -> **Apps** -> **Mosquitto broker** -> **Konfiguration** und legt dort einen Login an. 
Hier findet man auch die Ports für die verschiedenen MQTT-Protokolle.

Speichern nicht vergessen!

![MQTT Broker Login creation](/img/smart_home/homeassistant/mqtt_broker_login.png)

### Einrichten von MQTT im WARP Charger/WARP Energy Manager

Der MQTT Broker wird in den MQTT Einstellungen entsprechend der [Einführung](/docs/interfaces/mqtt_http/introduction) hinterlegt.

Für eine automatische Einbindung in Home Assistant empfehlen wir, den Discovery-Modus zu aktivieren und auf "Homeassistant" zu setzen.
![HA Autodiscovery](/img/smart_home/homeassistant/mqtt_discovery.png) 
Standardmäßig ist "homeassistant" das Topic, auf dem Home Assistant auf Discovery-Nachrichten wartet.
Die Discovery-Nachrichten werden alle 15 Minuten ausgesendet. Es kann also bis zu einer Viertelstunde dauern, bis die Geräte in Home Assistant auftauchen.

### MQTT Sensorwerte in Home Assistant via Autodiscovery

Die Autodiscovery fügt verschiedene Sensoren und Steuerelemente automatisch hinzu. Welche hinzugefügt werden, hängt davon ab, ob es sich bei dem Gerät um einen WARP Charger oder WARP Energy Manager handelt und welche Funktionen aktiviert sind (z.B. PV-Ertragsprognose).

Die Autodiscovery entfernt automatisch hinzugefügte Elemente, sollten diese nicht mehr verfügbar sein.

#### Automatisch hinzugefügte Entities
Die folgenden Entities werden via Autodiscovery bereitgestellt:

| Name | Typ | Beschreibung | Verfügbar wenn |
|------|-----|--------------|----------------|
| Ladestatus | Sensor | Aktueller Ladestatus der Wallbox | EVSE vorhanden (WARP Charger) |
| Aktueller Lademodus EVSE | Sensor | Zeigt den aktuellen Lademodus des EVSE als Enum an | EVSE vorhanden (WARP Charger) |
| Ladestromlimit | Number | Maximaler Ladestrom in A (0–32 A), steuerbar | EVSE vorhanden (WARP Charger) |
| Erlaubter Ladestrom | Sensor | Aktuell erlaubter Ladestrom in A | EVSE vorhanden (WARP Charger) |
| Ladevorgang starten | Button | Startet den Ladevorgang | EVSE vorhanden (WARP Charger) |
| Ladevorgang beenden | Button | Beendet den Ladevorgang | EVSE vorhanden (WARP Charger) |
| Wallbox-Ladekabel verbunden | Binary Sensor | Zeigt an ob ein Ladekabel angeschlossen ist | EVSE vorhanden (WARP Charger) |
| Wallbox ladebereit | Binary Sensor | Zeigt an ob die Wallbox ladebereit ist | EVSE vorhanden (WARP Charger) |
| Wallbox lädt | Binary Sensor | Zeigt an ob gerade geladen wird | EVSE vorhanden (WARP Charger) |
| Wallbox-Fehler | Binary Sensor | Zeigt an ob ein Fehler vorliegt | EVSE vorhanden (WARP Charger) |
| Wallbox verfügbar | Binary Sensor | Zeigt an ob die Wallbox erreichbar ist | EVSE vorhanden (WARP Charger) |
| Fronttaster gedrückt | Binary Sensor | Zeigt an ob der Fronttaster gedrückt ist | EVSE vorhanden (WARP Charger) |
| Limitiert nach §14a ENWG | Sensor | Zeigt an ob eine Limitierung nach §14a EnWG aktiv ist | §14a EnWG in der Konfiguration aktiviert |
| Aktiver Lademodus | Select | Lademodus auswählen (Schnell, Aus, PV, Min + PV), steuerbar | PV-Überschussladen oder dynamisches Lastmanagement aktiviert |
| Aktueller Lademodus | Sensor | Zeigt den aktuell aktiven Lademodus an | PV-Überschussladen oder dynamisches Lastmanagement aktiviert |
| PV Ertragsprognose morgen | Sensor | Prognostizierter PV-Ertrag für morgen in kWh | PV-Ertragsprognose aktiviert |
| PV Ertragsprognose heute | Sensor | Prognostizierter PV-Ertrag für heute in kWh | PV-Ertragsprognose aktiviert |
| PV Ertragsprognose ab jetzt | Sensor | Verbleibender prognostizierter PV-Ertrag für heute in kWh | PV-Ertragsprognose aktiviert |
| Börsenstrompreis | Sensor | Aktueller Börsenstrompreis in ct/kWh | Dynamische Strompreise aktiviert |

Zusätzlich werden pro konfiguriertem Zähler-Slot (Zähler 0 bis N) die folgenden Messwerte bereitgestellt, sofern der jeweilige Messwert vom Zähler unterstützt wird:

| Name | Beschreibung | Einheit |
|------|--------------|---------|
| Spannung (L1-N) | Spannung Phase L1 gegen Neutralleiter | V |
| Spannung (L2-N) | Spannung Phase L2 gegen Neutralleiter | V |
| Spannung (L3-N) | Spannung Phase L3 gegen Neutralleiter | V |
| Strom (Bezug plus Einspeisung) (L1) | Strom auf Phase L1 | A |
| Strom (Bezug plus Einspeisung) (L2) | Strom auf Phase L2 | A |
| Strom (Bezug plus Einspeisung) (L3) | Strom auf Phase L3 | A |
| Wirkleistung (Bezug minus Einspeisung) (Σ L1, L2, L3) | Gesamte Wirkleistung | W |
| Wirkenergie (Bezug) (Σ L1, L2, L3; seit letztem Zurücksetzen) | Bezogene Wirkenergie seit letztem Reset | kWh |
| Wirkenergie (Einspeisung) (Σ L1, L2, L3; seit letztem Zurücksetzen) | Eingespeiste Wirkenergie seit letztem Reset | kWh |
| Leistungsfaktor (Σ L1, L2, L3) | Leistungsfaktor, Vorzeichen gibt Richtung des Stromflusses an | - |
| Frequenz (⌀ L1, L2, L3) | Netzfrequenz | Hz |


:::note
Die Lokalisierung der Entitäten hängt von der Sprache des Webinterfaces des WARP Chargers/WARP Energy Managers ab.
:::

## Modbus/TCP
:::note
Coming soon...
:::

* [Modbus/TCP](/docs/interfaces/modbus/introduction)


