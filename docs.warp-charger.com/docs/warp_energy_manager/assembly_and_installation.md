---
sidebar_position: 1
---

# Montage und Installation

### Lieferumfang

Im Lieferumfang des WARP Energy Managers befinden sich:
-   WARP Energy Manager (Hutschienenmodul)
-   Steckbare Schraubklemmen
    -   2-pol Schraubklemme 5 mm (230 V Stromversorgung (L+N))
    -   2-pol Schraubklemme 5 mm (Schütz)
    -   4-pol Schraubklemme 3.5 mm (Eingänge)
    -   2-pol Schraubklemme 3.5 mm (Relaisausgang)
    -   4-pol Schraubklemme 3.5 mm (RS485 Modbus-RTU)
-   Betriebsanleitung inkl. individueller WLAN-Zugangsdaten
-   RJ45-LAN-Winkeladapter

### Montageort

Der WARP Energy Manager darf nur in einem geeigneten Verteilerschrank im
Innenbereich installiert werden. Er ist vor Staub, Nässe und
unsachgemäßem Zugriff zu schützen. Es sollte eine LAN-Verbindung zum
WARP Energy Manager gelegt werden, da in vielen Fällen eine Anbindung
des WARP Energy Managers mittels WLAN aufgrund der Metallabschirmung der
Verteilung nicht zuverlässig möglich ist.

Es muss ausreichend Platz vorhanden sein. Es darf kein Druck auf die
Kabel ausgeübt werden, insbesondere nicht auf die LAN-Verbindung. Aus
diesem Grund empfehlen wir die Verwendung des mitgelieferten
LAN-Winkeladapters.

Zur Montage des WARP Energy Managers muss dieser auf die Hutschiene
gesetzt werden. Das Gehäuse muss so installiert werden, dass die
Anschlüsse nach unten zeigen.

![image](/img/wem_shared_with_manual/wem_mounting.jpg)

Zuerst wird die obere Halterung auf die Hutschiene aufgesetzt und
anschließend die Untere. Der Energiemanager sollte sich selbstständig
verriegeln, falls dies nicht der Fall ist, kann mit einem
Schraubendreher an der schwarzen Verriegelung auf der Unterseite
nachgeholfen werden.

Soll der WARP Energy Manager wieder von der Hutschiene entfernt werden,
so müssen zuerst alle Zuleitungen entfernt werden (**Achtung:
Spannungsfreiheit sicherstellen!**). Anschließend kann mittels
Schlitz-Schraubendreher die schwarze Federverriegelung gezogen und der
Energiemanager von der Hutschiene gehoben werden. Dabei sollte zuerst
die untere Halterung angehoben werden, gefolgt von der oberen Halterung.

Elektrischer Anschluss
----------------------

Die in diesem Kapitel beschriebenen Arbeiten dürfen nur von einer
ausgewiesenen Elektrofachkraft durchgeführt werden!

![image](/img/wem_shared_with_manual/wem_connections.jpg)

### Stromversorgung

Nachdem der WARP Energy Manager montiert wurde, kann dieser
angeschlossen werden. Die Schraubklemmen sind steckbar, sodass der
elektrische Anschluss außerhalb erfolgen kann. Anschließend können die
Schraubklemmen wieder in den WARP Energy Manager gesteckt werden.

Die Stromversorgung des WARP Energy Managers erfolgt über eine
zweipolige Schraubklemme (**L**+**N**). Die Zuleitung ist mit einem
max. 16 Leitungsschutzschalter mit B-Charakteristik abzusichern.

Die Stromversorgung des Energiemanagers ist zusätzlich intern über eine
Glassicherung (mittelträge (m), 500) abgesichert.

### Schütz zur Phasenumschaltung

Es ist nur dann notwendig, ein Schütz zu installieren, wenn eine
Phasenumschaltung erfolgen soll. Wenn keine Umschaltung erfolgen soll,
können die Wallboxen ohne Schütz fest ein- oder dreiphasig angeschlossen
werden.

Ein externes Schütz kann zur Phasenumschaltung, das heißt, der
Umschaltung zwischen einphasigem und dreiphasigem Fahrzeug-Ladevorgang,
installiert werden. Das Schütz wird mittels 230 V Schaltausgang vom WARP
Energy Manager gesteuert (**Lsw**). Der minimale Phasenstrom für das
Typ-2 Laden beträgt 6. Somit kann die Minimale Ladeleistung von 4.1 kW
auf 1.4 kW reduziert werden.

Zu Ansteuerung werden **N** und **Lsw** nach außen geführt. Der
**Lsw**-Schaltausgang ist intern über eine Glassicherung (mittelträge
(m), 500) abgesichert.

### Eingänge

Der WARP Energy Manager besitzt zwei Eingänge für potentialfreie
Kontakte. An diesen können Schließer und Öffner angeschlossen werden.
Das Verhalten des Energiemanagers in Bezug auf diese Eingänge kann im
Webinterface konfiguriert werden.

Wird ein Schütz zur Phasenumschaltung installiert, so ist der
Eingang **4** fest zur Schützüberwachung konfiguriert. Es ist
erforderlich, einen Schließer zwischen **12V** und **4** zu
installieren, der vom zu überwachenden Schütz geschaltet wird. Wird der
Zubehörartikel **WARP Energy Manager Phase Switcher** verwendet, so sind
am Statuskontakt des Schützes die Klemmen 23 und 24 zu belegen.

Wird kein Schütz zur Phasenumschaltung verwendet, kann Eingang **4** für
andere Zwecke verwendet werden. Eingang **3** steht immer für eigene
Zwecke zur Verfügung. Die Eingänge sind so ausgelegt, dass ein
potentialfreier Kontakt extern angeschlossen werden kann (Schalter als
Öffner/Schließer, Relais etc.). Die **12V** Anschlüsse der Eingänge sind
hochohmig ausgelegt, liefern keine Leistung und sind daher nicht zur
Stromversorgung anderer Verbraucher geeignet.

### Relais-Ausgang

Mit dem potentialfreien Relaisschaltausgang können bis zu 30 V/1
geschaltet werden. Das Schalten von Netzspannung ist nicht möglich!

### RS485 Modbus Stromzähler

Es ist nicht notwendig, einen RS485-Modbus-Stromzähler zu installieren.
Dieser Schritt ist optional, wenn ein anderer unterstützter Stromzähler
konfiguriert wird.

Der WARP Energy Manager benötigt einen Stromzähler, um den
Leistungsbezug regeln zu können. Eine Möglichkeit dafür ist die
Installation eines RS485-Modbus-Stromzählers. Unterstützt werden aktuell
folgende Typen:

* Eastron SDM72V2
* Eastron SDM630
* Eastron SDM630MCTV2 (Wandler-Stromzähler)
* Eltako DSZ15DZMOD
* YTL DEM4A

Die Steckerbelegung ist **12V, A, B, GND**. Der Anschluss **12V** darf
nicht belegt werden. **A (+), B (-), GND** sind entsprechend am
jeweiligen Stromzähler anzuschließen.

### LAN-Anschluss

Die Steuerung der Wallboxen erfolgt über ein Netzwerk. Wir empfehlen den
Anschluss des WARP Energy Managers per LAN. Der dafür notwendige
LAN-Anschluss befindet sich im eingebauten Zustand vor den anderen
Anschlüssen. Um Beschädigungen zu vermeiden, ist die LAN-Buchse flexibel
befestigt. Wir empfehlen es dennoch, ein LAN-Kabel nicht direkt an den
Energiemanager anzuschließen, sondern den mitgelieferten
RJ45-Winkeladapters zwischen Energiemanager und LAN-Kabel zu verwenden.

Der Energiemanager ist noch nicht betriebsbereit! Er muss jetzt über das
Webinterface konfiguriert werden. Siehe
