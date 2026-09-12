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

Für eine automatische Einbindung in Home Assistant wird der Discovery-Modus auf "Home Assistant/openHAB/Domoticz/FHEM" gesetzt.
![HA Autodiscovery](/img/smart_home/homeassistant/mqtt_discovery.png)
Das Discovery-Topic-Präfix ist standardmäßig `homeassistant` und muss mit der Konfiguration von Home Assistant übereinstimmen. Es muss sich vom Topic-Präfix der MQTT-API unterscheiden.

Die Discovery-Nachrichten werden beim Start der Discovery und danach alle 15 Minuten gesendet und vom Broker gespeichert (Retain). Nach jeder Discovery-Runde werden auch die zugehörigen Zustände erneut gesendet, damit Home Assistant die aktuellen Werte mit den neuen Sensordefinitionen auswertet.

### MQTT Sensorwerte in Home Assistant via Autodiscovery

Die Autodiscovery fügt verschiedene Sensoren und Steuerelemente automatisch hinzu. Welche hinzugefügt werden, hängt davon ab, ob es sich bei dem Gerät um einen WARP Charger oder WARP Energy Manager handelt und welche Funktionen aktiviert sind (z.B. PV-Ertragsprognose).

Die Autodiscovery entfernt automatisch hinzugefügte Entitäten, wenn die zugehörige Funktion deaktiviert oder der Messwert nicht mehr vom konfigurierten Zähler unterstützt wird. Beim Deaktivieren der Discovery oder Ändern des Discovery-Topic-Präfixes werden die bisherigen Discovery-Nachrichten gelöscht.

Bei aktiviertem MQTT-Lesezugriff ohne Schreibzugriff (`read_only`) sind die Steuerelemente nicht verfügbar. Zum Steuern des Ladestromlimits muss außerdem die **Externe Steuerung** unter **Wallbox → Einstellungen** aktiviert sein.

#### Automatisch hinzugefügte Entities
Die folgenden Entities werden via Autodiscovery bereitgestellt:

| Name | Typ | Beschreibung | Verfügbar wenn |
|------|-----|--------------|----------------|
| Ladestatus | Sensor | Numerischer Ladestatus: 0 = Nicht verbunden, 1 = Warte auf Freigabe, 2 = Ladebereit, 3 = Lädt, 4 = Fehler | EVSE vorhanden (WARP Charger) |
| Ladestatus (Text) | Sensor | Derselbe Ladestatus als lokalisierter Text (Enum) | EVSE vorhanden (WARP Charger) |
| Aktueller Lademodus EVSE | Sensor | Lademodus der Wallbox als lokalisierter Text, einschließlich Standardmodus | EVSE vorhanden (WARP Charger) |
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
| Aktiver Lademodus | Select | Lademodus auswählen; bietet nur die aktuell unterstützten Modi an (siehe unten) | Lastmanagement aktiviert und auswählbare Lademodi vorhanden |
| Aktueller Lademodus | Sensor | Aktiver Lademodus des Lastmanagements als lokalisierter Text | Lastmanagement aktiviert |
| PV Ertragsprognose morgen | Sensor | Prognostizierter PV-Ertrag für morgen in kWh | PV-Ertragsprognose aktiviert |
| PV Ertragsprognose heute | Sensor | Prognostizierter PV-Ertrag für heute in kWh | PV-Ertragsprognose aktiviert |
| PV Ertragsprognose ab jetzt | Sensor | Verbleibender prognostizierter PV-Ertrag für heute in kWh | PV-Ertragsprognose aktiviert |
| Börsenstrompreis | Sensor | Aktueller Börsenstrompreis in ct/kWh | Dynamische Strompreise aktiviert |

Der numerische Sensor **Ladestatus** behält seine bisherige Discovery-ID `chargerstate`. Der zusätzliche Textsensor verwendet `chargerstate_text`.

#### Lademodi

Die Auswahl **Aktiver Lademodus** richtet sich nach den vom Lastmanagement gemeldeten unterstützten Modi und entspricht den verfügbaren Modi im Webinterface:

| Aktivierte Funktionen | Auswählbare Lademodi |
|----------------------|---------------------|
| Weder PV-Überschussladen noch Eco | Schnell, Aus |
| PV-Überschussladen | Schnell, Aus, PV, Min + PV |
| Eco | Schnell, Aus, Eco, Eco + Min |
| PV-Überschussladen und Eco | Schnell, Aus, PV, Eco + PV |

Ändert sich die Liste der unterstützten Modi, wird die Discovery erneut gesendet. Die Sensoren **Aktueller Lademodus** und **Aktueller Lademodus EVSE** können zusätzlich **Min**, **Eco + Min + PV** und **Standardmodus** anzeigen. **Standardmodus** ist kein auswählbarer Modus.

#### Fahrzeugdaten (WARP4)

WARP4 stellt zusätzlich die folgenden Sensoren bereit:

| Name | Beschreibung | Einheit |
|------|--------------|---------|
| Fahrzeugname | Name des erkannten Fahrzeugs | - |
| Fahrzeug MAC Adresse | MAC-Adresse des erkannten Fahrzeugs | - |
| Fahrzeug Ladestand | Ladestand der Fahrzeugbatterie | % |
| Fahrzeug Akkukapazität | Kapazität der Fahrzeugbatterie | kWh |

Die Fahrzeugsensoren sind nur verfügbar, wenn eine Fahrzeug-MAC-Adresse erkannt wurde. Nicht vorliegende Werte für Ladestand oder Akkukapazität werden als **unbekannt** angezeigt. Fahrzeugname und MAC-Adresse sind schreibgeschützte Sensoren.

#### Zählerwerte

Die "Legacy-Zählersensoren" bleiben mit ihren ursprünglichen Discovery-IDs erhalten, sofern das Gerät die entsprechenden Zählerfunktionen bereitstellt:

| Name | Discovery-ID | Beschreibung | Einheit |
|------|--------------|--------------|---------|
| Leistungsaufnahme | `powernow` | Aktuelle Leistung aus `meter/values` | W |
| Stromverbrauch absolut | `energyabs` | Absoluter Energiezählerstand aus `meter/values` | kWh |
| Stromverbrauch relativ | `energyrel` | Energiezählerstand seit dem letzten Zurücksetzen aus `meter/values` | kWh |
| Strom L1 / L2 / L3 | `current_l1` / `current_l2` / `current_l3` | Phasenströme aus `meter/all_values`, sofern verfügbar | A |

Zusätzlich werden pro konfiguriertem Zähler-Slot die folgenden Messwerte bereitgestellt, sofern der jeweilige Messwert vom Zähler unterstützt wird. Die Entitätsnamen enthalten den konfigurierten Zählernamen. Die Messwert-ID bezeichnet den Wert in der Zähler-API:

| Name | Messwert-ID | Beschreibung | Einheit |
|------|-------------|--------------|---------|
| Spannung (L1-N / L2-N / L3-N) | 1 / 2 / 3 | Spannung je Phase gegen Neutralleiter | V |
| Strom (Bezug minus Einspeisung) (L1 / L2 / L3) | 14 / 18 / 22 | Vorzeichenbehafteter Strom je Phase | A |
| Wirkleistung (Bezug minus Einspeisung) (Σ L1, L2, L3) | 74 | Gesamte Wirkleistung | W |
| Wirkenergie (Bezug) (Σ L1, L2, L3; seit Herstellung) | 209 | Absoluter Zählerstand für bezogene Wirkenergie | kWh |
| Wirkenergie (Einspeisung) (Σ L1, L2, L3; seit Herstellung) | 211 | Absoluter Zählerstand für eingespeiste Wirkenergie | kWh |
| Gleichspannung | 10 | DC-Spannung | V |
| Gleichstrom | 35 | DC-Strom | A |
| Leistung (DC) | 160 | DC-Leistung | W |
| Energie (Bezug) (DC; seit Herstellung) | 405 | Absoluter DC-Energiebezug | kWh |
| Energie (Einspeisung) (DC; seit Herstellung) | 407 | Absolute DC-Energieeinspeisung | kWh |
| Gleichspannung (⌀ PV) | 430 | Mittlere PV-Gleichspannung | V |
| Gleichstrom (Einspeisung) (Σ PV) | 441 | Gesamter PV-Gleichstrom | A |
| Leistung (Bezug minus Einspeisung) (Σ PV; DC) | 453 | Gesamte PV-Gleichstromleistung | W |
| Energie (Einspeisung) (Σ PV; DC; seit Herstellung) | 472 | Absoluter PV-Energieertrag | kWh |
| Ladestand | 387 | Batterieladestand | % |
| Kapazität | 475 | Batteriekapazität | kWh |
| Frequenz (⌀ L1, L2, L3) | 364 | Netzfrequenz | Hz |


:::note
Die Lokalisierung der Entitäten hängt von der Sprache des Webinterfaces des WARP Chargers/WARP Energy Managers ab.
:::

## Modbus/TCP
:::note
Coming soon...
:::

* [Modbus/TCP](/docs/interfaces/modbus/introduction)
