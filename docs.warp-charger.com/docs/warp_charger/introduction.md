---
sidebar_position: 1
---

# Einführung

:::note

Diese Beschriebung bezieht sich auf den WARP3 Charger. Für Informationen zu älteren
Modellen, also dem WARP2 Charger oder WARP1 Charger, kann auf die 
jeweilige Betriebsanleitung unter https://warp-charger.com/downloads zurückgegriffen werden.

:::


Mit dem WARP3 Charger bieten wir die dritte Generation der hochwertigen und langlebigen Wallbox, mit der du dein Elektrofahrzeug laden kannst. Die Wallbox ist "Made in Germany“, das heißt von uns in Deutschland entwickelt
und gefertigt. Sie ist modular aufgebaut, sodass einzelne Komponenten einfach ausgetauscht werden können. Bei der Auswahl der Bauteile legen wir großen Wert auf eine hohe Qualität. Sowohl die Hardware als auch die Software
sind Open Source.

![image](/img/warp_charger/front.png)

## Features

Die WARP3 Charger Wallbox verfügt, abhängig von der Variante, über folgende Features:

 * Typ 2 Ladekabel (DIN EN 61851-1)
 * Ladeleistung einstellbar von 1,4kW bis zu 11kW oder 22kW (je nach Modell)
 * Integrierte Phasenumschaltung (1-phasiges / 3-phasiges Laden)
 * Integrierte CP-Trennung und intelligientes Aufwecken von Fahrzeugen
 * PV-Überschussladen inkl. Eco-Modus (dynamische Strompreise + PV-Überschuss)
 * Integriertes Lastmanagement (statisch, dynamisch) von bis zu 64 WARP Charger Wallboxen
 * Zugriff auf Stromzähler am Netzanschluss, Photovoltaik-Wechselrichter, Batteriespeicher
 * Photovoltaik-Prognose
 * Dynamische Strompreise unabhängig vom Stromanbieter
 * Unterstützung von §14a EnwG - "Steuerbare Verbrauchseinrichtung"

## Varianten

Den WARP3 Charger bieten wir in drei Varianten an:
Basic, Smart und Pro. Alle Varianten sind mit einer V4A Edelstahlfrontblende versehen, die optional im Farbton
DB703 pulverbeschichtet geliefert werden kann.

### WARP3 Charger Basic

![image](/img/warp_charger/warp3_basic_open.jpg)

Der WARP3 Charger Basic ist das einfachste Modell. Mit diesem kann ein Elektrofahrzeug nach DIN EN 61851-1 Mode 3 geladen werden. Das eigentliche
Ladegerät ist im Elektrofahrzeug verbaut. Dieses entscheidet ob es an der Wallbox ein-, zwei- oder dreiphasig lädt.
Jede Wallbox kann ein- oder dreiphasig angeschlossen werden und ist als
11 kW- und 22 kW Variante erhältlich. Die 11kW- und die 22kW-Variante unterscheiden sich nur durch den Leitungsquerschnitt des
Typ-2-Ladekabels der Wallbox. Der maximale Ladestrom kann über einen Konfigurationsschalter in der Wallbox bei der Installation durch eine Elektrofachkraft
von 6 A bis 16 A (dreiphasig 11 kW) bzw. von 6 A bis 32 A (dreiphasig 22 kW) eingestellt werden.

Nach dem Einstecken des Typ-2-Ladesteckers in das Fahrzeug zeigt die RGB-LED auf der Frontblende der Wallbox den Ladezustand des Fahrzeugs an. Im Inneren des
LED-Rings befindet sich ein Taster.

### WARP3 Charger Smart

![image](/img/warp_charger/warp3_smart_open.jpg)

Der WARP3 Charger Smart ist im Vergleich zur Variante Basic zusätzlich mit einem WLAN- und LAN-fähigen
Controller ausgestattet. Dieser kann als Access Point ein eigenes WLAN eröffnen oder in ein vorhandenes Netzwerk
eingebunden werden. Alternativ ist ein Anschluss per LAN möglich. Dazu kann ein LAN-Kabel in die Wallbox geführt
werden. Per WLAN oder LAN kann auf das Webinterface des WARP3 Chargers Smart zugegriffen werden. Auf diesem kann man
den aktuellen Ladezustand einsehen und Einstellungen an der Wallbox vornehmen. Beispielsweise kann über
das Webinterface das Ladeverhalten und die maximale Ladeleistung konfiguriert werden.

Soll die Wallbox in andere Systeme integriert werden, so stehen die Schnittstellen MQTT, HTTP, Modbus TCP
und OCPP zur Verfügung. Der WARP3 Charger Smart bietet die Möglichkeit, Ladevorgänge per NFC (RFID) freizuschalten. Über die Webseite
können dazu NFC-Tags angelernt und verwaltet werden. Ladevorgänge können lokal auf der Wallbox aufgezeichnet werden. Die Wallbox ermöglicht es, ein
Ladelogbuch der Ladevorgänge mit Zeitstempel, Dauer und der verwendeten Ladekarte als PDF- oder CSV-Datei zu erstellen.

Mehrere WARP3 Charger können sich einen Stromanschluss teilen. Das eingebaute Lastmanagement kann dabei den Gesamtstrom aller Wallboxen dynamisch begrenzen.
Das integrierte Energiemanagement ermöglicht die Anbindung der Wallbox direkt an Photovoltaik-Wechselrichter oder Stromzähler und ermöglicht ein photovoltaikgeführtes
Überschussladen. Die Wallbox kann dazu zwischen ein- und dreiphasigem Laden umschalten (Phasenumschaltung). Damit  kann ein Elektrofahrzeug bereits mit einem Überschuss
von 1,4 kW geladen werden (einphasige Ladung mit 6 A Ladestrom). Mittels Automatisierungsregeln können eigene Ideen umgesetzt werden. Die Regeln basieren auf einer Bedingung
und einer damit verknupften Aktion. Zum Beispiel kann man Ladezeiten definieren oder abhängig von der erkannten NFC-Karte oder einer empfangenen MQTT-Nachricht
zwischen verschiedenen Lademodi wechseln.

Neben dem reinen PV-Überschussladen kann die Wallbox auch dynamische Strompreise nutzen. Dazu kann die Wallbox die aktuellen Stromerzeugungskosten von der Strombörse abrufen.
Weitere Kostenanteile kannst du spezifisch für deinen Stromanbieter konfigurieren. Mit einer PV-Ertragsprognose kann die Wallbox die zu erwartenen PV-Erträge ermitteln. Bis zu sechs
Dachflächen mit verschiedenen Ausrichtungen können hierzu konfiguriert werden.

Im Eco+PV Modus kann die Wallbox mit den Daten des dynamischen Strompreises und der PV-Ertragsprognose dann selbst entscheiden ob Nachts der günstige Strom zum Laden
des Fahrzeugs genutzt werden soll, oder ob auf einen PV-Überschuss gewartet werden soll. Es muss einfach nur die gewünschte Abfahrtszeit konfiguriert werden, sowie die Stunden die das Fahrzeug geladen werden soll.

### WARP3 Charger Pro

![image](/img/warp_charger/warp3_pro_open.jpg)

Der WARP3 Charger Pro bietet alle Funktionen der Variante Smart. Zusätzlich ist dieser mit einem MID-geeichten Stromzähler (EU-Messgeräterichtlinie 2014/32/EU) ausgestattet, der misst, wie viel Energie
(kWh) geladen wurde. Die geladene Energie wird bei aktiviertem Ladelogbuch bei jedem Ladevorgang erfasst und ermöglicht somit zum Beispiel die Abrechnung von Ladevorgängen für Dienstwagen. Der auf der Hutschiene im
WARP3 Charger Pro montierte Stromzähler des Herstellers Eltako ist ein MID-geeichtes deutsches Markenprodukt.

WARP3 Charger Pro Wallboxen besitzen zusätzlich einen Vorteil im Vergleich zu den WARP3 Charger Smart Wallboxen, wenn sie in einem gemeinsamen dynamischen Lastmanagement eingesetzt werden:
Da der Lastmanager mit den internen Stromzählern der Wallboxen ermitteln kann wie die Phasenströme zu den Fahrzeugen aussehen, kann ein effizienteres dynamisches Lastmanagement realisiert werden.

### Optionale Ausstattung

Alle Wallboxen werden mit einem fest angeschlossenen 5 m- oder 7,5 m-Ladekabel mit Typ-2-Stecker geliefert. In
der Standardausführung werden alle WARP3 Charger ohne Anschlusskabel (Zuleitung zur Wallbox) ausgeliefert. In
diesem Fall muss bei der Installation ein Anschlusskabel bereitgestellt und in der Wallbox angeschlossen werden.
Die Einfuhrung des Anschlusskabels kann entweder von der Unter- oder von der Rückseite der Wallbox erfolgen.
Optional kann jede Wallbox mit einem bereits ab Werk installierten Anschlusskabel bestellt werden. Zusätzlich
besteht die Möglichkeit, dieses mit einem CEE-Stecker ausstatten zu lassen. Fur die optionalen Anschlusskabel verwenden
wir folgende Leitungen und CEE-Stecker:

 * 11 kW Gummianschlussleitung H07RN-F 5G4 (4mm² Querschnitt) + 16 A-CEE-Stecker
 * 22 kW Gummianschlussleitung H07RN-F 5G6 (6mm² Querschnitt) + 32 A-CEE-Stecker

### Individuelle Gravur/Eigenes Logo

Wallboxen können auch mit einer individuellen Gravur bestellt werden. In diesem Fall wird das standardmäßig auf die
Frontblende gravierte WARP-Logo durch das gewünschte Logo ersetzt.
