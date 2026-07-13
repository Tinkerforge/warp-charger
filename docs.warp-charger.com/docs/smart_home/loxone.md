---
sidebar_position: 6
---

# Loxone

## Einführung

Dein [WARP Charger](@current-charger/introduction) ist mit dem Miniserver von [Loxone](https://www.loxone.com/dede/produkte/gebaeude-und-hausautomation-miniserver/) kompatibel.
Loxone ist ein Unternehmen, das Produkte zur Gebäudeautomation entwickelt und vertreibt. 

Der WARP Charger kann an den Loxone Miniserver über [Modbus/TCP](/docs/interfaces/modbus/introduction) oder [MQTT](/docs/interfaces/mqtt_http/introduction) angebunden werden.
Beide Geräte benötigen dafür lediglich eine Netzwerkanbindung.

:::note
Der [WARP Energy Manager](@current-wem/introduction) und [WARP Charger](@current-charger/introduction) sind auch über MQTT mit Loxone kompatibel. 
Der Miniserver bringt jedoch keinen eigenen MQTT-Broker mit, daher muss zuerst ein Broker im Netzwerk installiert werden.
Die Einrichtung von MQTT-Datenpunkten muss vollständig manuell erfolgen und wird daher nur fortgeschrittenen Benutzern empfohlen.  
:::


:::note
Der Loxone Miniserver unterstützt auch EEBUS. 
Damit wäre es möglich den Stromzähler des WARP Chargers auszulesen.
Leider ist eine Verbindung mit dem Loxone Miniserver über EEBUS sehr instabil und kommt of nicht zustande, daher kann dies aktuell nicht empfohlen werden.
:::

## Einbindung via Modbus/TCP
### Konfiguration des WARP Chargers

Zuerst wird der WARP Charger entsprechend der Anleitung für [Modbus/TCP](/docs/interfaces/modbus/introduction) konfiguriert.

Der Modus muss mindestens auf Lesezugriff gesetzt werden. Wenn der Miniserver den Charger steuern soll, muss Lese-/Schreibzugriff gesetzt werden. 

Als Registertabelle wird die Tabelle des WARP Chargers ausgewählt. 

Damit ist der WARP Charger für Modbus/TCP vorbereitet. 

### Konfiguration des Loxone Miniservers

Wir gehen davon aus, dass dein Loxone Miniserver bereits konfiguriert ist und du dich mit der Loxone Config Software bereits verbunden hast. 

Zuerst wird ein Modbus-Server angelegt:

![Modbusserver select](/img/smart_home/loxone/modbus_select.png)

Dieser wird mit der IP-Adresse und dem Port konfiguriert.

![Modbus Config](/img/smart_home/loxone/modbus_config.png)

Anschließend muss ein Modbus-Gerät hinzugefügt werden. 
Um das zu vereinfachen, empfehlen wir die WARP-Vorlagen zu verwenden:

- <a href="/de/img/smart_home/loxone/MB_Warp3_Complete_DE.xml" download>Loxone WARP Vorlage Deutsch</a>
- <a href="/de/img/smart_home/loxone/MB_Warp3_Complete_EN.xml" download>Loxone WARP Vorlage Englisch</a>

Diese werden über den Modbus-Server importiert. 

![Modbus import](/img/smart_home/loxone/import_template.png)

Anschließend kann der WARP Charger direkt aus einem Template angelegt werden.

Nachdem das Gerät angelegt wurde, sollte die Konfiguration auf dem Miniserver gespeichert werden. 
Anschließend kann ein Testbefehl gesendet werden. 
Dazu einfach einen Sensor auswählen, Rechtsklick und einen Testbefehl senden. 
Das Ergebnis ist im Modbus-Monitor zu sehen. 

Die [Modbus-Registertabelle](/docs/interfaces/modbus/registertable) erklärt die Funktionen und Wertebereiche der Sensoren und Aktuatoren.

:::note
Einige Modbus-Funktionen werden über mehrere Sensoren oder Aktuatoren dargestellt, da der Miniserver nur Datentypen von 16 bis 64 Bit kennt. 
Diese Daten müssen mithilfe von Bausteinen zuerst verarbeitet werden, bevor sie korrekt interpretiert oder geschrieben werden können.
:::

:::note
Einige Registereinträge sind nicht im Template enthalten. 
So sind beispielsweise die LED-Parameter nicht enthalten. Um die LED zu steuern, müssen 160 Bit in 10 Register in einem Befehl geschrieben werden, der Miniserver kann jedoch maximal 64 Bit in einem Befehl schreiben.
:::
