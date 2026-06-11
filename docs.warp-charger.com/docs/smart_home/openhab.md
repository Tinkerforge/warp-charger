---
sidebar_position: 7
---

# OpenHAB

## Einführung

Dein [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) ist mit [OpenHAB](https://www.openhab.org) kompatibel.
OpenHAB ist eine Open-Source Softwarelösung zur Heimautomation welche Komponenten verschiedenster Anbieter hersteller- und protokollneutral in einer Plattform verbindet.

Zur Anbindung der WARP Geräte kann MQTT genutzt werden. 
Da OpenHAB den selben Discovery Mechanismus wie [Home Assistant](/docs/smart_home/home_assistant) unterstützt ist die Integration sehr gut möglich.

## Einbindung via MQTT

### Konfiguration OpenHAB
Wir gehen davon aus das du OpenHAB bereits installiert hast. Weiterhin brauchst du einen MQTT-Broker weil OpenHAB keinen Broker selber integriert. Wir empfehlen [Mosquitto](https://mosquitto.org).

Nach dem initialen Setup müssen die nötigen Bindings installiert werden. 
Wir brauchen die MQTT Binding und die Home Assistant Binding.

![MQTT Bindings](/img/smart_home/openhab/binding_install.png)

Nach der Installation konfigurieren wir die Bindings. 

Zuerst den MQTT broker: 

Dazu gehen wir auf *Settings &rarr; Things &rarr; "+" &rarr; MQTT Binding &rarr; MQTT Broker*.
Dort wird dann die Adresse des Brokers eingetragen. 
Wenn auf dem Broker ein Benutzername oder Passwort gesetzt ist, oder MQTTS (MQTT über TLS) verwendet werden soll, kann das in den erweiterten Einstellungen gesetzt werden. 
Wichtig ist auch das in den erweiterten Einstellungen die Discovery aktiviert ist. 

### Konfiguration WARP Charger/WARP Energy Manager

Der WARP Charger/WARP Energy Manager wird wie in [WARP Adapter](/docs/interfaces/mqtt_http/introduction) beschrieben konfiguriert. 
Als Broker-Hostname wird dabei die Adresse des eingerichteten MQTT Brokers eingetragen. 
Der Discovery Modus wird auf Home Assistant gesetzt und das Topic Präfix auf "homeassistant".

## Integration in OpenHAB

Nach dem beide Seite konfiguriert sind sollte das WARP Gerät in *Settings &rarr; Things &rarr; Inbox* auftauchen. Das kann bis zu einer Viertelstunde dauern.
Um eine schnelle discovery zu erzwingen kann man auch zuerst das WARP Gerät neu starten und, sollte das nicht geholfen haben, den OpenHAB Server. 

Die entdecken Geräte werden aus der Inbox als Thing hinzugefügt.

Zuletzt fügen wir noch die Geräte zum Model hinzu *Settings &rarr; Model*. 
*Create Equipment from Thing* und wählen das WARP Gerät aus.

Die Beschreibung der Datenpunkte und unter welchen Umständen diese vorhanden sind findet man in der [Home Assistant Dokumentation](/docs/smart_home/home_assistant#mqtt-sensorwerte-in-home-assistant-via-autodiscovery) 