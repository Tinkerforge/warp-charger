---
sidebar_position: 10
---

# Häufig gestellte Fragen (FAQ)

## Die häufigsten Fragen

### Wer darf den WARP4 Charger installieren?
Die Installation muss durch eine qualifizierte Elektrofachkraft erfolgen. Diese kümmert sich auch um die erforderliche Anmeldung beim Netzbetreiber.

### Benötige ich einen FI Typ B?
Nein. Die WARP4 verfügt über eine integrierte DC-Fehlerstromerkennung (RDC-DD). Ein FI Typ A in der hausinternen Installation ist ausreichend.

### Funktioniert WARP4 auch ohne Internetzugang/ ohne Cloud?
Alle Funktionen der WARP4 laufen lokal auf der Wallbox. Bedienung und Konfiguration erfolgen über das integrierte Webinterface im eigenen Heimnetzwerk, ganz ohne Cloud-Zwang. Einzig Funktionen wie PV-Ertragsprognose, die Nutzung dynamischer Strompreise oder die Nutzung der Apps setzen eine Internetverbindung voraus.

### Wie binde ich die Wallbox ins Smart Home ein?
Die WARP4 unterstützt offene Standards wie MQTT, Modbus TCP und HTTP-API. Damit lässt sie sich nahtlos in Home Assistant, ioBroker, openHAB und weitere Smart-Home-Systeme integrieren.

### Wie verbinde ich die Wallbox mit meiner bestehenden PV-Anlage?
Wir unterstützen über 100 Geräte anderer Hersteller und können direkt auf die Daten von Stromzählern, PV-Wechselrichtern und Speichern zugreifen. Die Installation zusätzlicher Hardware, z.B. eines extra Stromzählers für die Wallbox, entfällt somit meist, da bestehende Hardware von der Wallbox genutzt werden kann. Hier gibt es die [vollständige Kompatibilitätsliste](/docs/compatible_devices/devices/).

### Welche Geräte werden unterstützt?
Die WARP4 kommuniziert mit zahlreichen Smart-Metern, PV-Wechselrichtern, Stromspeichern und Wärmepumpen verschiedener Hersteller. Eine vollständige Kompatibilitätsliste finden Sie in der Dokumentation.

### Warum ist nur die Pro Version für das bidirektionale Laden vorbereitet und kann den SoC auslesen?
Nur die Pro Version verfügt über einen Stromzähler. Wir gehen davon aus, dass dieser für das bidirektionale Laden notwendig ist, um auf Probleme mit dem Stromnetz zu reagieren (NA-Schutz). Der SoC eines Fahrzeugs kann per ISO15118-2 ausgelesen werden, allerdings leider nicht während eines laufenden Ladevorgangs. Die Pro kann während des Ladevorgangs den Ladezustand über den Stromzähler mitrechnen.

### Welche Variante ist abrechnungsgeeignet?
Für eine Abrechnung, etwa bei Dienstwagen oder am Arbeitsplatz, empfehlen wir die WARP4 Pro mit MID-zertifiziertem Zähler und Ladelogbuch mit Energieerfassung. Für Anwendungen, bei denen eine eichrechtskonforme Lösung benötigt wird, ist WARP4 zurzeit nicht geeignet.

### Was ist der Unterschied zwischen MID-geeicht und eichrechtskonform?
Der Stromzähler der Pro Version ist MID-geeicht. Dies bezieht sich auf die Messgenauigkeit des Stromzählers. Der Begriff \"eichrechtskonforme Wallbox\" bezieht sich nicht nur auf den Stromzähler, sondern auf die gesamte Wallbox. So muss der Stromzähler jeden Ladevorgang signieren. Die Daten werden hochgeladen und in der Transparenzsoftware bereitgestellt. Theoretisch kann damit ein Nutzer nachsehen ob die Abrechnung korrekt erfolgte. Zusätzlich muss die Wallbox manipulationsgeschützt sein. Dies führt dazu, dass viele Teile in der Wallbox verplombt sind und nicht einfach von einem Elektriker getauscht werden können. Nach Ablauf der Eichfrist von 8 Jahren darf die Wallbox nicht mehr für Abrechnungszwecke verwendet werden. Ein Tausch des Stromzählers ist nur durch den Hersteller möglich.

### Ist die Wallbox über die \"Förderung Laden im Mehrparteienhaus\" förderfähig?
Ja, WARP4 steht in der Liste der förderfähigen Wallboxen unter unserem Firmennamen \"Tinkerforge GmbH\".

### Erfüllt WARP4 den §14a EnWG?
Ja. Die WARP4 unterstützt die netzdienliche Steuerung nach §14a EnWG inklusive EEBUS-Schnittstelle zur Kommunikation mit dem Steuerbox-Standard des Netzbetreibers.


## Hardware
### Upgrade von WARP3 auf WARP4

Ein vollständiges Upgrade von WARP3 auf WARP4 ist möglich. Allerdings muss dann auch das Gehäuse getauscht werden. Für die allermeisten Kunden ist dies vermutlich nicht notwendig, da nur ein Upgrade auf die Ladeelektronik der WARP4 mit ISO15118 gewünscht ist. Dieser Austausch ist sehr einfach! Alle Anschlüsse sind identisch geblieben.
Die Ladeelektronik von WARP3 und WARP4 sind mechanisch kompatibel und kann einfach ausgetauscht werden. Dazu müssen alle Kabel von der Ladeelektronik abgesteckt werden. Anschließend kann diese von der Hutschiene entfernt werden.
Als nächstes wird die WARP4 Ladeelektronik auf die Hutschiene aufgesetzt und alle Kabel wieder angeschlossen. Einziger Unterschied ist, dass der Maximalstrom des Ladekabels bei WARP3 über einen Widerstand gesetzt wurde (PP Widerstand).
Bei WARP4 ist dies ebenfalls möglich, aber zusätzlich kann das Ladekabel auch mittels Jumper (16A oder 32A) einfach gesetzt werden.

Wir bieten einen Upgrade-Satz für die Ladeelektronik an: [WARP3 zu WARP4 Upgradesatz](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp3-to-warp4-upgrade-set.html).


### Upgrade von WARP4 Smart auf WARP4 Pro
WARP4 Pro verfügt über ein Sichtfenster im Gehäuse um von außen das Display des Stromzählers sehen zu können. Folgende Komponenten sind notwendig:

* [Iskra Stromzähler WM3M4 V2 MID RS485](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/meter-iskra-wm3m4-v2-mid.html)
* [WARP4 Gehäuse (Pro Variante)](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp4-enclosure.html)
* [NFC Aufkleber](https://shop.warp-charger.com/de/catalog/product/view/id/929/s/warp-nfc-sticker/category/64/)
* [RS485 Datenkabel für MID Stromzähler Iskra WM3M4 V2](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp-meter-cable-for-iskra-wm3m4.html)
* [WARP4 Pro Hutschienensatz](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp4-pro-din-rail-set.html)
* [Kabelsatz für WARP4 Smart und Pro](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp4-smart-pro-cable-set.html)


### Upgrade von WARP3 Smart auf WARP3 Pro

Der Unterschied zwischen den beiden Versionen besteht in dem zusätzlich installierten MID geeichten Stromzähler. Bei WARP3 kann dieser nachgerüstet werden. Dazu muss nur der Klemmblock nach links geschoben werden und zusätzlich der Stromzähler installiert werden. Dieser wird mit einem Daten-Verbindungskabel am EVSE angeschlossen. Zusätzlich ist ein Verbindungskabel zwischen Klemmen und Stromzähler notwendig. Alle drei Bauteile sind im Shop erhätlich:

* [Stromzähler DSZ15DZMOD-3x80A](https://shop.warp-charger.com/de/spare-parts/warp3-spare-parts/electricity-meter-dsz15dzmod-3x80a.html)
* [Anschlusskabel für DSZ15DZMOD-3x80A](https://shop.warp-charger.com/de/catalog/product/view/id/1036/s/anschlusskabel-fuer-dsz15/category/63/)
* [WARP3 Kabelbaum](https://shop.warp-charger.com/de/spare-parts/warp3-spare-parts/warp3-cable-harness.html)

### Upgrade von WARP2 auf WARP3

Aufgrund des modularen Aufbaus der Wallboxen ist auch ein Upgrade der Hardware prinzipiell möglich. Der Umbau ist vergleichsweise umfangreich, da die gesamte Technik der Wallbox getauscht werden muss. Nur das Ladekabel und das Gehäuse, der Stromzähler, sowie das verbaute NFC Bricklet können wiederverwendet werden. Alle Teile sind auch einzeln in unserem Shop erhätlich:

* [WARP3 Ersatzteile](https://shop.warp-charger.com/de/spare-parts/warp3-spare-parts.html)

Auf Tinkerunity gibt es zu dem Thema auch weitere Informationen: [Link](https://www.tinkerunity.org/topic/12097-warp2-zu-warp3-aufr%C3%BCsten/?do=findComment&comment=55013)



## Bidirektionales Laden, V2G oder V2H

### Unterstützt der WARP Charger das bidirektionale Laden, Vehicle-to-Grid (V2G) oder Vehicle-to-Home (V2H)? Kann ein Fahrzeug über die Wallbox Strom zurück ins Netz bzw. ins Haus einspeisen?

Die Version WARP4 Charger Pro ist hardwareseitig auf das bidirektionale Laden vorbereitet. Vollständig technisch umsetzbar ist dies zur Zeit für uns noch nicht, da gewisse technische Details noch nicht geklärt sind (z.B. NA-Schutz).
Wir gehen aber davon aus, dass wir diese Funktion per Softwareupdate nachreichen können.

Aktuell in den Medien oder von Fahrzeugherstellern beworbene Lösungen entsprechen keinem Standard und sind Insellösungen der jeweiligen Hersteller. Hierbei wurde jeweils eine properitäre Lösung geschaffen, die mit der beworbenen Kombination aus Fahrzeug und Wallbox funktioniert,
nicht aber mit anderen Fahrzeugen oder Wallboxen.


## Funktion

### (Wie) ist PV-Überschussladen möglich?

PV-Überschussladen kann direkt mit einem WARP Charger (ohne zusätzliche Hardware) oder über dem [WARP Energy Manager](https://warp-charger.com/warp-energy-manager/) realisiert werden. Dazu kann ein vorhandener Zähler am Hausanschluss über das Netzwerk ausgelesen werden.

Mehr Informationen dazu gibt es in der Dokumentation im Tutorial [PV-Überschussladen](/docs/tutorials/pv_excess_charging).

### Kann der WARP Charger den Ladezustand eines angeschlossenen Fahrzeugs abfragen? Kann bis zu einem gewissen Ladezustand (z.B. bis 80 %) geladen werden?

Ja, WARP4 Pro Charger können bei Fahrzeugen die dies unterstützen den SoC zu Beginn einer Ladung auslesen und dann über den verbauten Stromzähler während der Ladung aktualisieren.
Für alle anderen WARP Charger gibt es die Möglichkeit mit EVCC über die APIs, die von vielen Fahrzeugherstellern angeboten werden, den Ladezustand abzufragen. EVCC kann dann einen WARP Charger so steuern, dass nur bis zu einem gewissen Ladezustand geladen wird. [Die Einrichtung von EVCC wird hier beschrieben.](/smart_home/evcc.md)

### Ist es möglich den Ladestrom auf unter 6 Ampere zu konfigurieren?

Die Ladung erfolgt aktuell nach den Standard IEC 61851. Dieser Standard definiert, dass eine Wallbox, wenn sie das Laden freigibt einen Maximalstrom kommunizieren muss. Dieser Maximalstrom muss mindestens 6 Ampere betragen.
Mit dem Ladestandard ISO15118-20 wird es auch die Möglichkeit geben geringere Ladeleistungen zu definieren.

## Montage und Installation

### Welchen Leiterquerschnitt brauche ich für die Zuleitung zum WARP Charger?

Der Leiterquerschnitt sollte immer von dem Elektriker vor Ort festgelegt werden. Folgende Minimalwerte gibt es in der Praxis:

11 kW Ladeleistung

*   bis 20 Meter: 2,5 mm²
*   bis 40 Meter: 4,0 mm²
*   bis 70 Meter: 6,0 mm²

22 kW Ladeleistung

*   bis 25 Meter: 6,0 mm²
*   bis 50 Meter: 10,0 mm²
*   bis 100 Meter: 16,0 mm²

### Können mehrere Wallboxen an einem Hausanschluss betrieben werden? Kann sichergestellt werden, dass eine vorgegebene maximale Stromaufnahme nicht überschritten wird?

Ja. WARP Charger können sich über das eingebaute Lastmanagement einen Hausanschluss teilen, ohne dass dieser überlastet wird. Das Lastmanagement stellt sicher, dass eine vorgegebene Stromaufnahme nicht überschritten wird und verteilt den verfügbaren Ladestrom auf mehrere WARP Charger. Damit WARP Charger über das Lastmanagement gesteuert werden können müssen sie im selben Netzwerk betrieben werden.

### Kann ich einen WARP Charger von außen deaktivieren? Wie schließe ich einen Rundsteuerempfänger an (Stichwort §14a EnWG)?

Zum das Thema §14a EnWG bieten wir ein eigenes Tutorial, welches die verschiedenen Möglichkeiten darstellt: [Tutorial §14a EnWG](/docs/tutorials/verbrauchseinrichtung).

## Lastmanagement

### Wie viele Teilnehmer werden vom Lastmanager unterstützt?

Ein WARP Charger kann als Lastmanager konfiguriert werden. Dieser kann in Summe (inkl. sich selbst) maximal 64 Wallboxen kontrollieren.

Eine andere Möglichkeit ist es den WARP Energy Manager als Lastmanager zu konfigurieren. Dieser kann dann auch bis zu 64 Wallboxen kontrollieren.

## Webinterface

### Warum kann ich von meinem Handy/Tablet das Webinterface über den Access Point der Wallbox nicht erreichen?

Typischerweise ist das Problem, dass auf dem Handy/Tablet neben der WLAN-Verbindung zum Access Point der Wallbox außerdem auch die mobile Datenverbindung aktiv ist. Wenn die mobile Datenverbindung deaktiviert ist, sollte das Webinterface unter [http://10.0.0.1](http://10.0.0.1) erreichbar sein.

### Warum kann ich von meinem Samsung-Gerät das Webinterface nicht erreichen?

Der auf Samsung-Geräten vorinstallierte Browser "Samsung Internet" scheint die vom Webinterface verwendeten Websockets nicht korrekt zu unterstützen. Mit einem anderen Browser, z.B. Firefox oder Chrome sollte das Webinterface erreichbar sein.

## MQTT

### Warum kann die Wallbox meinen Mosquitto MQTT-Broker nicht erreichen?

Häufig ist hier das Problem, dass Mosquitto seit Version 2.0.0 standardmäßig nur lokale Verbindungen zulässt. Damit Zugriffe über das Netzwerk möglich sind, muss die Konfiguration von Mosquitto angepasst werden. Details finden sich in der [Mosquitto-Dokumentation](https://mosquitto.org/documentation/migrating-to-2-0/) und in [unserem Forum](https://www.tinkerunity.org/topic/7188-keine-verbindung-zu-mqtt/#comment-38629).

### Warum werden Änderungskommandos nicht übernommen?

Typischerweise kann der zuletzt gesetzte Wert auf einem Topic gelesen werden. Beispielsweise liefert `warp/AbC/charge_manager/available_current` den aktuell für Lastmanagement zur Verfügung stehenden Strom. Kommandos müssen an das entsprechende Topic geschickt werden, das auf `_update` endet, damit sie vom WARP Charger von dessen eigenen Nachrichten unterschieden werden können. Um den verfügbaren Strom zu aktualisieren muss z.B. auf `warp/AbC/charge_manager/available_current_update` gepublisht werden.

### Warum meldet die Wallbox MQTT: Topic ... is an action. Ignoring retained message.?

Bestimmte Kommandos sind Aktionen, setzen also keinen dauerhaften Zustand, sondern lösen einmalige Ereignisse aus. Eine "Retained Message" wird aber auf dem MQTT-Broker dauerhaft vorgehalten. Für Aktionen sind deshalb solche Messages verboten, da diese sonst, beispielsweise nach einem Neuverbinden des WARP Chargers zum MQTT-Broker, mehr als einmal verarbeitet werden könnten.



