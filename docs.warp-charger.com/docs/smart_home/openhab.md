---
sidebar_position: 7
---

# OpenHAB

## Einführung

Dein [WARP Charger](@current-charger/introduction) oder [WARP Energy Manager](@current-wem/introduction) ist mit [OpenHAB](https://www.openhab.org) kompatibel.
OpenHAB ist eine Open-Source-Softwarelösung zur Heimautomation, welche Komponenten verschiedenster Anbieter hersteller- und protokollneutral in einer Plattform verbindet.

Zur Anbindung der WARP Geräte kann MQTT genutzt werden. 
Da OpenHAB den gleichen Discovery-Mechanismus wie [Home Assistant](/docs/smart_home/home_assistant) unterstützt, ist eine nahtlose Integration möglich.

## Einbindung via MQTT

### Konfiguration OpenHAB
Wir gehen davon aus, dass du OpenHAB bereits installiert hast. Weiterhin brauchst du einen MQTT-Broker, da OpenHAB keinen Broker integriert. Wir empfehlen [Mosquitto](https://mosquitto.org).

Nach dem initialen Setup müssen die nötigen Bindings installiert werden. 
Wir benötigen das MQTT Binding und das Home Assistant Binding.

![MQTT Bindings](/img/smart_home/openhab/binding_install.png)

Nach der Installation muss nur MQTT konfiguriert werden. 

Dazu gehen wir auf *Settings &rarr; Things &rarr; "+" &rarr; MQTT Binding &rarr; MQTT Broker*.
Dort wird die Adresse des Brokers eingetragen. 
Wenn auf dem Broker ein Benutzername oder Passwort gesetzt ist, oder MQTTS (MQTT über TLS) verwendet werden soll, kann das in den erweiterten Einstellungen konfiguriert werden. 
Wichtig ist auch, dass in den erweiterten Einstellungen die Discovery aktiviert ist. 

### Konfiguration WARP Charger/WARP Energy Manager

Der WARP Charger/WARP Energy Manager wird wie in [MQTT/HTTP API](/docs/interfaces/mqtt_http/introduction) beschrieben konfiguriert. 
Als Broker-Hostname wird die Adresse des eingerichteten MQTT-Brokers eingetragen. 
Der Discovery-Modus wird auf "Home Assistant/openHAB/Domoticz/FHEM" gesetzt und das Discovery-Topic-Präfix auf `homeassistant`. Das Discovery-Topic-Präfix muss sich vom Topic-Präfix der MQTT-API unterscheiden. Der frühere generische Modus wird nicht mehr benötigt; bestehende Konfigurationen werden automatisch umgestellt.

## Integration in OpenHAB

Nachdem beide Seiten konfiguriert sind, sollte das WARP Gerät in *Settings &rarr; Things &rarr; Inbox* auftauchen. Discovery-Nachrichten werden beim Start der Discovery und danach alle 15 Minuten gesendet und vom Broker gespeichert (Retain). Änderungen an den Discovery-Einstellungen werden ohne Neustart übernommen. Nach jeder Discovery-Runde werden auch die zugehörigen Zustände erneut gesendet.

Die entdeckten Geräte werden aus der Inbox als Thing hinzugefügt.

Zuletzt fügen wir die Geräte zum Model hinzu: *Settings &rarr; Model*. 
Wähle *Create Equipment from Thing* und wähle das WARP Gerät aus.

Die Beschreibung der Datenpunkte und unter welchen Umständen diese vorhanden sind, findet man in der [Home Assistant Dokumentation](/docs/smart_home/home_assistant#mqtt-sensorwerte-in-home-assistant-via-autodiscovery).
