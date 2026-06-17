---
sidebar_position: 6
---

# Loxone

## Einführung

Dein [WARP Charger](@current-charger/introduction) ist mit dem Miniserver von [Loxone](https://www.loxone.com/dede/produkte/gebaeude-und-hausautomation-miniserver/) kompatibel.
Loxone ist ein Unternehmen das Produkte zur Gebäudeautomation entwickelt und vertreibt. 

Der WARP Charger kann an den Loxone Miniserver über [Modbus/TCP](/docs/interfaces/modbus/introduction), [MQTT](/docs/interfaces/mqtt_http/introduction) oder [EEBUS](/docs/interfaces/EEBUS) angebunden werden.
Beide Geräte müssen dafür nur eine Netzwerkanbindung haben.

:::note
Der [WARP Energy Manager](@current-wem/introduction) [WARP Charger](@current-charger/introduction) ist mit dem Loxone auch über MQTT kompatibel. 
Der Miniserver bringt aber keinen eigenen MQTT Broker mit, daher muss erst ein Broker im Netz installiert werden.
Die Einrichtung von MQTT Datempunkten muss vollständig manuell erfolgen und wird daher nur fortgeschrittenene Benutzern empfohlen.  
:::

{/*
:::note
Der Loxone Miniserver unterstützt auch EEBUS. 
Damit wäre es möglich den Stromzähler des WARP Chargers auszulesen.
Leider konnten wir bei tests
:::
*/}
## Einbindung via Modbus/TCP
### Konfiguration des WARP Chargers

Zuerst wird der WARP Charger entsprechend der Anleitung für [Modbus/TCP](/docs/interfaces/modbus/introduction) konfiguriert.

Der Modus muss mindestens auf Lesezugriff gesetzt werden, wenn der Miniserver den Charger steuern soll, muss natürlich Lese-/Schreibzugriff gesetzt werden. 

Als Registertabelle wird die Tabelle des WARP Chargers gesetzt. 

Damit ist der Warp Charger für Modbus/TCP vorbereitet. 

### Konfiguration des Loxone Miniservers

Wir gehen davon aus das dein Loxone Miniserver bereits konfiguriert ist und du dich mit der Loxone Config Software bereits verbunden hast. 

Zuerst wird ein Modbusserver angelegt:

![Modbusserver select](/img/smart_home/loxone/modbus_select.png)

Dieser wird dann mit der IP Adresse und dem Port konfiguriert.

![Modbus Config](/img/smart_home/loxone/modbus_config.png)

Anschließend muss ein Modbus Gerät hinzugefügt werden. 
Um das zu vereinfachen empfehlen wir die WARP Vorlagen zu verwenden:

- [Loxone Modbus Vorlage Deutsch](/img/smart_home/loxone/MB_Warp3_Complete_DE.xml)
- [Loxone Modbus Vorlage Englisch](/img/smart_home/loxone/MB_Warp3_Complete_EN.xml)

Diese werden über den Modbusserver importiert. 
Anschließend kann der Warp Charger direkt aus einer Template angelegt werden.

Nach dem das Gerät angelegt wurde, am besten die Konfiguration auf dem Miniserver speichern. 
Anschließend kann man einen Testbefehl senden. 
Einfach einen Sensor auswählen, rechtsklick und einen Testbefehl senden. 
Das Ergebnis ist im Modbus Monitor zu sehen. 

Die [Modbus Registertabelle](/docs/interfaces/modbus/registertable) erklärt die Funktionen und Wertebereich der Sensoren und Aktuatoren.

:::note
Einige Modbus funktionen werden über mehrere Sensoren oder Aktuatoren dargestellt da der Miniserver nur Datentypen von 16 bis 64 bit kennt. 
Diese Daten müssen mithilfe von Bausteinen zuerst verarbeitet werden bevor sie korrekt interpretiert oder geschrieben werden können.
:::

:::note
Einige Registereinträge sind nicht in der Template enthalten. 
So sind die LED Parameter nicht enthalten. Um die LED zu steuern müssen 160 bits in 10 Register geschrieben werden, der Miniserver kann aber maximal 64 bits in einem Befehl schreiben.
:::
