---
sidebar_position: 2
---

# Home Assistant

## Einführung

Dein [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) ist mit [Home Assistant](https://www.home-assistant.io)  kompatibel. 
Home Assistant ist eine Open-Source Lösung zur Hausautomation mit einer breiten Unterstützung von Geräten. 

Zur Anbindung der WARP Geräte können Modbus und MQTT genutzt werden. In dieser Anleitung werden wir MQTT verwenden. 
Weiterhin wird davon ausgegangen das Home Assistant bereits installiert und in Betrieb genommen wurde. 
Eine Anleitung dafür findet man auf der [offiziellen Website](https://www.home-assistant.io/installation/). 

## MQTT

### Einrichten von MQTT in Homeassistant

Zuerst muss MQTT in Homeassistant aktiviert werden. 
Gehe dafür in der Webobefläche auf **Einstellungen** -> **Geräte & Dienste** -> **Integration hinzufügen**. 
In dem Fenster welches sich öffnet anschließend nach "MQTT" suchen und auswählen.
Es stehen verschiedene MQTT Integrationen zu verfügung. 
Wir brauchen einfach nur MQTT:

![MQTT Integration Selection](/img/smart_home/homeassistant/mqtt_selection.png)

Anschließend wird nach dem MQTT-Broker gefragt. 
Wenn kein eigener MQTT Broker genutzt werden soll ist es am einfachsten die offizielle Mqtt Broker-App zu verwenden. 
Diese wird automatisch installiert. 

![MQTT Broker Selection](/img/smart_home/homeassistant/mqtt_broker_select.png)

:::warning
Wenn Home Assistant als Docker Container installiert wurde, ist das hinzufügen von Apps über die Weboberfläche nicht möglich. 
Der MQTT Broker muss dementsprechend selber installiert und konfiguriert werden. 
Die Installation im Docker Container ist daher nur fortgeschrittenen Benutzern zu empfehlen. 
:::
![MQTT Broker install success](/img/smart_home/homeassistant/mqtt_broker_install_success.png)

Zuletzt geht man auf **Einstellungen** -> **Apps** -> **Mosquitto broker** -> **Konfiguration** und legt dort einen Login an. 
Hier findet man auch die Ports für die verschiedenen MQTT Protokolle.

Speichern nicht vergessen!

![MQTT Broker Login creation](/img/smart_home/homeassistant/mqtt_broker_login.png)

### Einrichten von MQTT im WARP Charger/WARP Energy Manager

Der MQTT Broker wird in den MQTT Einstellungen entsprechend der [Einführung](/docs/interfaces/mqtt_http/introduction) hinterlegt.

Für eine Automatische Einbindung in Home Assistant empfehlen wir den Discovery Modus zu aktivieren und auf "Homeassistant" setzen. 
![HA Autodiscovery](/img/smart_home/homeassistant/mqtt_discovery.png) 
Standardmäßig ist "homeassistant" das Topic auf dem Home Assistant auf Discovery Nachrichten wartet. 
Die Discovery Nachrichten werden alle 15 Minuten ausgesendet. Es kann also bis zu einer Viertelstunde dauern bis die Geräte in Home Assistant auftauchen.

### MQTT Sensorwerte in Home Assistant

Die Autodiscovery fügt verschiedene Sensoren und Steuerelmente automatisch hinzu. Welche hinzugefügt werden hängt davon ab ob es sich bei dem Gerät um einen WARP Charger oder Warp Energy Manager handelt. 
Einige Werte werden als deaktivierte Entitäten hinzugefügt. 

![Deaktivierte Entities](/img/smart_home/homeassistant/ha_disabled_entities.png) 

Diese müssen händisch aktiviert werden wenn die betreffende Funktion im WARP Charger oder WARP Energy Manager aktiviert wird. 
Dort findet man beispielsweise die Stromzählerwerte beim Energy Manager und die PV Ertragsprognosen.

:::note
Die Lokalisierung der Entitäten hängt von der Sprache des Webinterface vom WARP Charger/WARP Energy Manager ab. 
:::

## Modbus/TCP
:::note
Coming soon...
:::

* [Modbus/TCP](/docs/interfaces/modbus/introduction)


