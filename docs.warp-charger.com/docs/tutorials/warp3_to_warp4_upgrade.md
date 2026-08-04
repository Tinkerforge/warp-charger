---
sidebar_position: 9
---

# Upgrade von WARP3 auf WARP4

Dieses Tutorial zeigt Schritt für Schritt, wie ein WARP3 Charger mit dem
[WARP3 zu WARP4 Upgradesatz](https://shop.warp-charger.com/de/warp3-to-warp4-upgrade-set.html)
auf die Ladeelektronik des WARP4 Chargers aufgerüstet wird. Damit stehen
anschließend viele Funktionen des WARP4 Chargers zur Verfügung, insbesondere
die ISO-15118-Kommunikation mit dem Fahrzeug (z.B. für [SoC-Anzeige und
Autocharge](/docs/tutorials/soc_autocharge)).

Die Ladeelektronik von WARP3 und WARP4 ist mechanisch kompatibel. Beim Upgrade
wird der komplette Elektronik-Stapel getauscht. Alle Anschlüsse sind identisch
geblieben, sodass alle vorhandenen Kabel weiterverwendet werden können.

:::danger

Die in diesem Tutorial beschriebenen Arbeiten sollten von einer
ausgewiesenen Elektrofachkraft durchgeführt werden.

:::

## Schritt 1: Upgradesatz konfigurieren

Vor dem Einbau muss der Upgradesatz passend zur vorhandenen Installation
konfiguriert werden. Es müssen zwei Dinge eingestellt werden:

**Maximaler Ladestrom der Zuleitung:** Über die vier DIP-Schalter rechts auf
dem Ladecontroller (EVSE) wird der maximale Ladestrom abhängig von der
hausseitigen Leitungsabsicherung eingestellt. Die Schalterstellung sollte von
der alten WARP3-Ladeelektronik übernommen werden. Die Bedeutung der
Schalterstellungen ist im Abschnitt
[Einstellen des Ladestroms](/docs/warp4/assembly_and_installation#einstellen-des-ladestroms)
der WARP4-Anleitung beschrieben.

![image](/img/warp4/hardware_dip_vertical.png)

**Maximalstrom des Typ-2-Ladekabels:** Zwischen DIP-Schalter und Klemmblock
befindet sich ein kleiner Jumper. Mit diesem wird konfiguriert, ob ein
16A-Ladekabel (11 kW) oder ein 32A-Ladekabel (22 kW) verbaut ist. Der Jumper
lässt sich am besten mit einer kleinen Zange umsetzen. Die korrekte Position
ist auf der Leiterkarte beschriftet.

:::note

Beim WARP3 wurde der Maximalstrom des Ladekabels über einen Widerstand am
PP-Eingang konfiguriert. Beim WARP4 ist das weiterhin möglich (mittlere
Jumper-Position), einfacher ist aber die direkte Auswahl von 16 A oder 32 A
per Jumper.

:::

![image](/img/tutorials/warp3_to_warp4_upgrade/step1_jumper.jpg)

## Schritt 2: Wallbox stromlos machen

Vor allen weiteren Arbeiten muss die Wallbox stromlos geschaltet werden
(Leitungsschutzschalter bzw. Fehlerstromschutzschalter der Zuleitung
ausschalten). Die Spannungsfreiheit ist vor dem Öffnen der Wallbox zu prüfen.

![image](/img/tutorials/warp3_to_warp4_upgrade/step2_power_off.jpg)

## Schritt 3: Wallbox öffnen

Zum Öffnen der Wallbox werden die vier Kreuzschlitzschrauben des Deckels
gelöst. Der Taster im Deckel ist über ein Anschlusskabel verbunden und muss
durch Drücken des Rasthebels vom Kabel gelöst werden. Zusätzlich muss der
Erdungsstecker von der Frontblende abgesteckt werden. Danach kann der Deckel
zur Seite gelegt werden.

![image](/img/tutorials/warp3_to_warp4_upgrade/step3_open.jpg)

## Schritt 4: Kabel von der Ladeelektronik entfernen

Folgende Kabel werden von der alten Ladeelektronik abgesteckt:

* Ethernet-Kabel
* Modbus-Kabel (nur WARP3 Charger Pro: Verbindung zum Stromzähler)
* CP-Leitung des Typ-2-Ladekabels
* Kabel des Fronttasters

![image](/img/tutorials/warp3_to_warp4_upgrade/step4_cables.jpg)

## Schritt 5: Alten Elektronik-Stapel lösen

Der alte Elektronik-Stapel kann jetzt von der Hutschiene gelöst und aus der
Wallbox entnommen werden. Dabei werden die folgenden Kabel entfernt, die
vorher schlecht erreichbar waren:

* Stromkabel (Stromversorgung der Ladeelektronik)
* Contactor-Check-Kabel (Schützüberwachung)
* Kabel zum NFC Bricklet

Zum lösen des Stapels mit einem Schlitz-Schraubendreher den
Hutschienenhalter öffnen.

![image](/img/tutorials/warp3_to_warp4_upgrade/step5_remove_stack.jpg)

## Schritt 6: Neuen Elektronik-Stapel einsetzen

Der neue WARP4-Elektronik-Stapel wird auf die Hutschiene aufgesetzt. Direkt
beim Einsetzen werden die folgenden Kabel wieder verbunden, bevor sie schlecht
erreichbar sind:

* Stromkabel
* Contactor-Check-Kabel
* Kabel zum NFC Bricklet

Zum Befestigen des neuen Stapels nach dem Einsetzen mit einem
Schlitz-Schraubendreher den gelben Befestigungsriegel in Richtung Hutschiene
schieben.

![image](/img/tutorials/warp3_to_warp4_upgrade/step6_insert_stack.jpg)

## Schritt 7: Restliche Kabel verbinden

Anschließend werden die in Schritt 4 entfernten Kabel wieder angeschlossen:

* Ethernet-Kabel
* Modbus-Kabel (nur WARP3 Charger Pro)
* CP-Leitung des Typ-2-Ladekabels
* Kabel des Fronttasters

Die Belegung des Klemmblocks ist auf der Leiterkarte beschriftet. Der feste
Sitz aller Steckverbindungen ist zu prüfen.

![image](/img/tutorials/warp3_to_warp4_upgrade/step7_connect_cables.jpg)

## Schritt 8: WARP4-Aufkleber aufkleben

Die neue Ladeelektronik spannt einen eigenen WLAN-Access-Point mit neuen
Zugangsdaten auf. Der im Upgradesatz enthaltene WARP4-Aufkleber mit den neuen
WLAN-Zugangsdaten wird über den vorhandenen WARP3-Aufkleber geklebt.

Im Upgradesatz befindet sich ein zweiter Aufkleber mit den WLAN-Zugangsdaten.
Dieser kann über den Aufkleber in der Original-Betriebsanleitung geklebt
werden oder an einer anderen, gut wiederauffindbaren Stelle außerhalb der
Wallbox aufbewahrt werden oder z.B. in der Unterverteilung an den
Sicherungsautomat geklebt werden (wie in diesem Tutorial, siehe unten).

![image](/img/tutorials/warp3_to_warp4_upgrade/step8_sticker.jpg)

## Schritt 9: Wallbox verschließen

Beim Aufsetzen des Deckels werden das Kabel des Fronttasters und der
Erdungsstecker an der Frontblende wieder angesteckt. Danach wird der Deckel
mit den vier Kreuzschlitzschrauben verschraubt.

## Schritt 10: Wallbox wieder mit Strom versorgen

Die Stromversorgung der Wallbox wird wieder eingeschaltet. Die LED blinkt
anschließend magenta, während die Wallbox eine Kalibrierung der
DC-Fehlerstromerkennung durchführt. Nach Abschluss der Kalibrierung leuchtet
die LED dauerhaft blau. Die Wallbox ist nun betriebsbereit.

![image](/img/tutorials/warp3_to_warp4_upgrade/step10_power_on.jpg)

## Inbetriebnahme

Die Inbetriebnahme kann danach wie im Tutorial
[Erste Schritte](/docs/tutorials/first_steps)
beschrieben vorgenommen werden.
