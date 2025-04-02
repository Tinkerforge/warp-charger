---
sidebar_position: 10
---

# Häufig gestellte Fragen (FAQ)

## Förderung

### Ist ein WARP Charger förderfähig nach KfW 442?

Die Varianten Smart und Pro stehen auf der Liste der KfW und werden mit 600€ gefördert.

## Bidirektionales Laden, V2G oder V2H

### Unterstützt der WARP Charger das bidirektionale Laden, Vehicle-to-Grid (V2G) oder Vehicle-to-Home (V2H)? Kann ein Fahrzeug über die Wallbox Strom zurück ins Netz bzw. ins Haus einspeisen?

Nein.

Es gibt diverse Pilotprojekte bei denen V2G- oder V2H-Konzepte auch mit AC-Wallboxen unterstützt werden. Die meisten Neuigkeiten zu dem Thema sind derzeit aber nur Ankündigungen, es gibt zur Zeit keine konkreten Produkte. Die technischen und gesetzlichen Rahmenbedingungen sind aktuell noch nicht vollständig geklärt. Selbst wenn ein Produkt auf dem Markt verfügbar wäre, so dürfte es nicht in Betrieb genommen werden.

**Erläuterung:**

Da der Fahrzeugakku immer mit Gleichspannung (DC) arbeitet, muss zwischen diesem und dem Stromnetz ein Wechselrichter (DC -> AC) installiert sein. Es gibt Fahrzeuge bei denen dieser Wechselrichter bereits im Fahrzeug installiert ist. Damit wäre es prinzipiell denkbar eine Rückspeisung über das Typ2 Ladekabel, welches für die Übertragung von Wechselspannung gedacht ist, durchzuführen.

Die meisten Ankündigungen betreffen aber Fahrzeuge, bei denen über die DC-Kontakte in der Fahrzeugbuchse (Combined Charging System; CCS-Stecker) auf den Akku zugegriffen werden kann. AC-Wallboxen, wie auch unsere WARP Charger, haben keine Möglichkeit auf diese DC-Spannung zuzugreifen, da die Wallbox über keinen CCS-Stecker verfügt. Zusätzlich fehlt den Wallboxen der notwendige Wechselrichter um aus der Gleichspannung wieder eine Wechselspannung zu erzeugen. Es gibt DC-Wallboxen am Markt, die die technische Möglichkeiten bieten, diese liegen aber in einem ganz anderen Preisbereich. Neben diesen technischen Problemen gibt es weitere offene Fragen: Dazu zählen die eigentliche Steuerung der Rückspeisung (Kommunikation zwischen Wallbox und Fahrzeug) aber auch ungeklärte regulatorische und steuerrechtliche Fragen. Zusätzlich involviert das Thema andere Gebiete, wie das Ausrollen des Smart-Meter-Gateways, die Steuerung durch die Netzbetreiber etc.

Aus unserer Sicht ist es deshalb nicht seriös damit zu werben, dass eine AC-Wallbox zukünftig V2G oder V2H unterstützt, da die zuvor genannten technischen und rechtlichen Fragestellungen noch überhaupt nicht geklärt sind. Sollte eine Nachrüstung unserer Wallboxen auf Grund unseres modularen Konzepts möglich sein, so werden wir dies zukünftig sicherlich anbieten.

## Funktion

### (Wie) ist PV-Überschussladen möglich?

PV-Überschussladen kann direkt mit dem WARP3 Charger (ohne zusätzliche Hardware) oder über dem [WARP Energy Manager](https://warp-charger.com/warp-energy-manager/) realisiert werden. Dazu kann ein vorhandener Zähler am Hausanschluss per SunSpec ausgelesen werden.

Technisch versierte Nutzer können alternativ eine PV-Überschusssteuerung mit EVCC einrichten. [Die Einrichtung von EVCC wird hier beschrieben.](/smart_home/evcc.md)

Mehr Informationen dazu gibt es auf [https://warp-charger.com/pv-ueberschussladen](https://warp-charger.com/pv-ueberschussladen/).

### Kann der WARP Charger den Ladezustand eines angeschlossenen Fahrzeugs abfragen? Kann bis zu einem gewissen Ladezustand (z.B. bis 80 %) geladen werden?

Nein. Es gibt aber die Möglichkeit mit EVCC über die APIs, die von vielen Fahrzeugherstellern angeboten werden, den Ladezustand abzufragen. EVCC kann dann einen WARP Charger so steuern, dass nur bis zu einem gewissen Ladezustand geladen wird. [Die Einrichtung von EVCC wird hier beschrieben.](/smart_home/evcc.md)

### Ist es möglich den Ladestrom auf unter 6 Ampere zu konfigurieren?

Nicht durch den WARP Charger. Die Ladung erfolgt nach den Standard IEC 61851. Dieser Standard definiert, dass eine Wallbox, wenn sie das Laden freigibt einen Maximalstrom kommunizieren muss. Dieser Maximalstrom muss mindestens 6 Ampere betragen.

Es gibt allerdings Fahrzeuge, die so konfiguriert werden können, dass sie weniger als den von der Wallbox vorgegebenen Maximalstrom beziehen.

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

Es gibt verschiedene Möglichkeiten, die Ladefunktion einen WARP Chargers zu kontrollieren:

* Über HTTP, MQTT, OCPP bzw. Modbus/TCP kann die Wallbox gesteuert werden. Siehe auch [API-Dokumentation](/docs/interfaces/mqtt_http/introduction)
* Das Verhalten auf die Eingänge des WARP Energy Managers können konfiguriert werden. Unter anderem ist eine Reduktion der Ladeleistung/Abschaltung möglich. Der WARP Energy Manager steuert die Wallboxen über eine (WLAN/LAN-)Netzwerkverbindung, so dass eine Steuerung aus der Ferne möglich ist.
* Es ist auch möglich einen Rundsteuerempfänger oder ähnlichen Abschalter direkt an die Wallbox anschließen. Hierzu gibt es in der Wallbox einen konfigurierbaren Abschalteingang. Eventuell muss zur Durchführung des Abschalters ein Loch in das Gehäuse der Wallbox gebohrt werden.
* Mehr Informationen zu diesem Thema gibt es auch auf der Infoseite zu [§14a EnWG](https://warp-charger.com/%c2%a714a-enwg/).

### Kann ein bereits vorhandener/anderer Stromzähler verwendet werden?

Der WARP3 Charger wird mit einem DSZ15DZMOD-3x80A von Eltako ausgeliefert. Zusätzlich werden auch noch die Stromzähler vom Typ SDM630 oder SDM72 V2 von Eastron unterstützt. Andere Stromzähler werden nicht unterstützt.

## Lastmanagement

### Wie viele Teilnehmer werden vom Lastmanager unterstützt?

Ein WARP3 Charger kann als Lastmanager konfiguriert werden. Dieser kann in Summe (inkl. sich selbst) maximal 64 Wallboxen kontrollieren.

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



## Upgrade von WARP Chargern

Wir versuchen soweit möglich auch ältere WARP Charger mit den neusten Features auszustatten. Daher veröffentlichen wir auch für WARP1 Wallboxen nach wie vor Updates.

### Upgrade von WARP Charger Smart auf WARP Charger Pro

Der Unterschied zwischen den beiden Versionen besteht in dem zusätzlich installierten MID geeichten Stromzähler. Bei WARP3 kann dieser nachgerüstet werden. Dazu muss nur der Klemmblock nach links geschoben werden und zusätzlich der Stromzähler installiert werden. Dieser wird mit einem Daten-Verbindungskabel am EVSE angeschlossen. Zusätzlich ist ein Verbindungskabel zwischen Klemmen und Stromzähler notwendig. Alle drei Bauteile sind im Shop erhätlich:

* [Stromzähler DSZ15DZMOD-3x80A](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts/electricity-meter-dsz15dzmod-3x80a.html)
* [Anschlusskabel für DSZ15DZMOD-3x80A](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts/anschlusskabel-fuer-dsz15.html)
* [WARP3 Kabelbaum](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts/warp3-cable-harness.html)

### Upgrade WARP2 auf WARP3

Aufgrund des modularen Aufbaus der Wallboxen ist auch ein Upgrade der Hardware prinzipiell möglich. Der Umbau ist vergleichsweise umfangreich, da die gesamte Technik der Wallbox getauscht werden muss. Nur das Ladekabel und das Gehäuse, der Stromzähler, sowie das verbaute NFC Bricklet können wiederverwendet werden. Alle Teile sind auch einzeln in unserem Shop erhätlich:

* [WARP3 Ersatzteile](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts.html)

Auf Tinkerunity gibt es zu dem Thema auch weitere Informationen: [Link](https://www.tinkerunity.org/topic/12097-warp2-zu-warp3-aufr%C3%BCsten/?do=findComment&comment=55013)
