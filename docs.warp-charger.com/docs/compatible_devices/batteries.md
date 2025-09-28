---
sidebar_position: 4
---

# Batteriespeicher

:::note

    Die Steuerung von Batteriespeichern befindet sich zur Zeit noch in der Entwicklung und ist noch nicht Teil der Release-Firmware!
    
    Eine Beta-Firmware wird zeitnah im Forum auf [Tinkerunity](https://tinkerunity.org) veröffentlicht.

    Es kann nicht garantiert werden, dass diese Batteriespeicher-Einstellungen bei einem Firmwareupdate korrekt übernommen werden!
:::


## Steuerung von Batteriespeichern

Viele Hersteller unterstützen die externe Steuerung von Batteriespeichern mittels [Modbus/TCP](/docs/compatible_devices/interfaces#modbustcp) Schnittstelle.
Meist wird der Batteriespeicher über den angeschlossenen Wechselrichter gesteuert und nicht die Batterie direkt. Die zur Verfügung gestellten Register zur Steuerung unterscheiden sich je nach Hersteller und Gerät, so dass nicht alle Geräte
alle Funktionen unterstützen. Auch die Umsetzung der jeweiligen Funktion unterscheidet sich stark von Gerät zu Gerät!

### Generelle Idee

Der Speicher wird von uns nicht geregelt. Er übt seine vom Hersteller definierte Funktion aus. Das heißt im Normalfall wird ein PV-Überschuss zur Ladung des Speichers genutzt und der Speicher versucht die Leistungsaufnahme eines Verbrauchers
zu kompensieren. Mit den nachfolgend aufgeführten Funktionen kann aber in diese Regelung eingegriffen werden.

## Anlegen eines Batteriespeichers

Wir ermöglichen es einen Batteriespeicher mittels Modbus/TCP zu steuern. Wir versuchen für uns bekannte Speicher Voreinstellungen zu bieten, die direkt ausgewählt werden können.
Leider ist es nicht einfach die korrekten Werte ohne Zugriff auf eine Anlage zu ermitteln. Daher sind wir hier sehr auf die Community angewiesen.

Ist keine Voreinstellung für einen Speicher hinterlegt, so können die jeweiligen Register händisch angelegt werden. Es können drei nachfolgend aufgelistet Funktionen implementiert werden. 
Es müssen nicht alle Funktionen für den jeweiligen Speicher implementiert werden. Wird aber eine Funktion implementiert, so muss auch die Aufhebung dieser Funktion implementiert werden.

Es können einzelne Register, aber auch mehrere Register in einem Befehl geschrieben werden. Es wird empfohlen Register, die aufeinanderfolgend sind, als ein Block in einem Befehl zu schreiben. 

### Laden vom Netz erlauben

Diese Funktion versucht den Speicher zu zwingen, auf 100% SoC zu laden. Wird die Ladeleistung nicht über PV gedeckt, so soll der Speicher mit Strom aus dem Netz laden. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Genereller "Minimum SoC" auf 100% setzen. Dies funktioniert aber nur, wenn das System dann auch Strom aus dem Netz zum Laden bezieht.
 * Setzen und Aktivieren eines Ladeplans mit dem Uhrzeitbereich 00:00-23:59 Uhr und einem Ziel-SoC von 100%.

### Entladen verbieten

Mit dieser Funktion wird dem Speicher verboten zu entladen. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Setzen des "Maximalen Entladestroms" auf 0A.
 * Setzen des "Minimum SoC" auf 100%. Dies funktioniert nur, wenn das System dann NICHT Strom aus dem Netz zum Laden bezieht sonder nur das Entladen deaktiviert.

### Laden verbieten

Diese Funktion verbietet dem Speicher das Laden. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Setzen des "Maximalen Ladestroms" auf 0A.
 * Setzen der "Maximalen Ladeleistung" auf 0W.

## Zeitplan für dy­na­mi­schen Strom­preis

Mit dem Strompreisplan können günstige und teure Stunden definiert werden. Diese Eigenschaften können dann in den Regeln verwendet werden. Es müssen nur die Anzahl der jeweiligen Stunden in 15min Schritten definiert werden.
Ein Graph zeigt die Stunden dann für den aktuellen Strompreisverlauf an.

## Verwendung des Batteriespeichers - Definition von Regeln

Für jede Funktion können mehrere Regeln definiert werden. Eine Funktion wird ausgeführt, wenn alle Bedingungen einer zugeordneten Regel erfüllt sind. Ist keine Regel für eine Funktion erfüllt, so wird die Funktion deaktiviert. 
Sprich es wird zyklisch die Aufhebung der Funktion ausgeführt (die jeweiligen Modbus-Register geschrieben).

Jede Regel besteht aus einer Beschreibung (Freitext für den Nutzer) und mehreren Bedingungen. Es müssen nicht alle Bedinungen definiert werden. Sollen nur zwei Bedingungen genutzt werden, so kann der Rest auf "ignoriert" gestellt werden.
Folgende Bedingungen können definiert werden: Einem Zeitraum, der Angabe eines Batterieladestands (SoC), eines Strompreises und der Wert der PV-Ertragsprognose. Zusätzlich kann ein Strompreisplan aktiviert werden, in dem die teuersten
und die günstigesten X Stunden definiert werden. Als letztes kann der Lademodus "Schnellladung" als Bedingung genutzt werden.

Der Vergleich zu den angegebenen Werten kann als "kleiner als" oder "größer als" definiert werden. Soll ein Wert nicht verwendet werden, so ist "wird ignoriert" zu konfigurieren.

## Beispiel-Regeln
Die nachfolgenden Regeln dienen als Beispiel. Für die eigene Nutzung müssen die Parameter angepasst werden.

### Ladung-vom-Netz-Erlaubnis

Sind alle definierten Bedingungen einer Regel erfüllt, so wird der Speicher aus dem Netz geladen.

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Batterie</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1.</td><td>-</td><td>< 60 %</td><td>< 5,0ct</td><td>< 20kWh</td><td>Günstig</td><td>-</td></tr>
<tr><td>2.</td><td>-</td><td>< 30%</td><td>-</td><td>-</td><td>Günstig</td><td>-</td></tr>
</table>

Die erste Regel dient dazu den Speicher wieder bis zu 60% mit "günstigen" Strom zu laden, wenn der erwartete PV-Ertrag an dem aktuellen Tag nicht ausreicht. Dazu werden die im Strompreisplan definierten "günstigen" Stunden genutzt. Aber nur, wenn deren Kosten unter 5ct liegen.
Die zweite Regel ist dazu gedacht, dass wenn die erste Regel nicht greift, bei einem SoC unter 30% dennoch zu den günstigen Stunden bis 30% zu laden.

### Bat­te­rie­ent­la­dungs-Verbot

Sind alle definierten Bedingungen einer Regel erfüllt, so wird der Speicher nicht mehr entladen.

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Batterie</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1.</td><td>-</td><td>< 20%</td><td>-</td><td>-</td><td>Nicht teuer</td><td>-</td></tr>
<tr><td>2.</td><td>-</td><td>-</td><td>-</td><td>-</td><td>-</td><td>Aktiv</td></tr>
</table>

Die erste Regel dient dazu eine Reserve von 20% gegen hohe Strompreise zu lassen. Ist der Strom "Nicht teuer" und der SoC kleiner 20% wird der Speicher nicht mehr weiter entladen. Wechselt der Strom allerdings auf "teuer", so greift diese Regel nicht und der Speicher wird entladen.
Die zweite Regel dient dazu den Speicher nicht zu entladen, wenn ein Fahrzeug mittels "Schnelladung" entladen wird. Wenn gewünscht kann dies auch mit einem SoC verknüpft werden.


### Bat­te­rie­la­dungs-Verbot

Sind alle definierten Bedingungen einer Regel erfüllt, so wird der Speicher nicht mehr geladen.

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Batterie</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1.</td><td>00:00-12:00</td><td>> 70%</td><td>-</td><td>> 32kWh</td><td>Nicht günstig</td><td>-</td></tr>
</table>

Ganz im Sinne der HTW Berlin Aktion: [Dein Stromspreicher kann mehr](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/) soll mit dieser Regel verhindert werden, dass an sonnereichen Tagen morgens der Speicher erst geladen wird um dann gegen Mittag voll zu sein und ins Netz einzuspeisen.
