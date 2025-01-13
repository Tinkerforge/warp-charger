---
sidebar_position: 1
---

# Montage und Installation

:::note

Diese Beschriebung bezieht sich auf den WARP Energymanager 2.0. Für Informationen zum älteren
Modell, dem WARP Energy Manager (1.0), kann auf die Betriebsanleitung unter
https://warp-charger.com/downloads zurückgegeriffen werden.

:::

### Lieferumfang

Im Lieferumfang des WARP Energy Managers 2.0 befinden sich:
-   WARP Energy Manager 2.0 (Hutschienenmodul)
-   Steckbare Schraubklemmen
    -   2-pol Schraubklemme 5 mm (230 VAC Stromversorgung (L+N))
    -   4-pol Schraubklemme 5 mm (2x Relaisausgang)
    -   4-pol Schraubklemme 3.5 mm (RS485 Modbus-RTU)
    -   4-pol Schraubklemme 3.5 mm (SG-Ready Ausgang)
    -   6-pol Schraubklemme 3.5 mm (4x Eingang)
-   Betriebsanleitung inkl. individueller WLAN-Zugangsdaten
-   RJ45-LAN-Winkeladapter

### Montageort

Der WARP Energy Manager 2.0 darf nur in einem geeigneten Verteilerschrank im
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
gesetzt werden. Das Gehäuse muss so installiert werden, dass der LAN
Anschluss bzw. die Hutschienen-Verriegelung nach unten zeigt.

![image](/img/wem_shared_with_manual/wem_mounting.jpg)

Zuerst wird die obere Halterung auf die Hutschiene aufgesetzt und
anschließend die Untere. Der Energiemanager sollte sich selbstständig
verriegeln, falls dies nicht der Fall ist, kann mit einem
Schraubendreher an der schwarzen Verriegelung auf der Unterseite
nachgeholfen werden.

Soll der WARP Energy Manager 2.0 wieder von der Hutschiene entfernt werden,
so müssen zuerst alle Zuleitungen entfernt werden (**Achtung:
Spannungsfreiheit sicherstellen!**). Anschließend kann mittels
Schlitz-Schraubendreher die schwarze Federverriegelung gezogen und der
Energiemanager von der Hutschiene gehoben werden. Dabei sollte zuerst
die untere Halterung angehoben werden, gefolgt von der oberen Halterung.

Elektrischer Anschluss
----------------------

Die in diesem Kapitel beschriebenen Arbeiten dürfen nur von einer
ausgewiesenen Elektrofachkraft durchgeführt werden!

![image](/img/wem_shared_with_manual/wem_connections-2.jpg)

### Stromversorgung

Nachdem der WARP Energy Manager 2.0 montiert wurde, kann dieser
angeschlossen werden. Die Schraubklemmen sind steckbar, sodass der
elektrische Anschluss außerhalb erfolgen kann. Anschließend können die
Schraubklemmen wieder in den WARP Energy Manager gesteckt werden.

Die Stromversorgung des WARP Energy Managers erfolgt über eine
zweipolige Schraubklemme (**L**+**N**). Die Zuleitung ist mit einem
max. 16A Leitungsschutzschalter mit B-Charakteristik abzusichern.

Die Stromversorgung des Energiemanagers ist intern über eine
Glassicherung (träge (T), 2A) abgesichert.

### Modbus (RS485)

An diesen Anschluss kann ein kompatibler RS485 Modbus-RTU Stromzähler
angeschlossen werden. Kompatible Stromzähler sind in der Liste unter dem
Eintrag Anbindung mit "WARP Energy Manager" gekennzeichnet. Die
Liste aller kompatibler Geräte lässt sich auf der Seite der
[Kompatiblen Stromzähler](https://docs.warp-charger.com/docs/compatible_meters/#bekannte-kompatible-ger%C3%A4te)
finden.

Die Steckerbelegung ist **12V, A, B, GND**. Der Anschluss **12V** darf
nicht belegt werden. **A (+), B (-), GND** sind entsprechend am
jeweiligen Stromzähler anzuschließen. Je nach Zähler wird GND nicht
angeschlossen.


### Eingänge

Der WARP Energy Manager 2.0 besitzt vier Eingänge für
potentialfreie Kontakte. An diesen können Schließer oder
Öffner angeschlossen werden. Das Verhalten des Energiemanagers in Bezug
auf diese Eingänge kann im Webinterface konfiguriert werden.
Jeweils zwei Eingänge besitzen einen Common (C)-Anschluss.
Dieser ist mit einer Seite des Schließes/ Öffners
zu verbinden. Die andere Seite ist dann auf den jeweiligen
Eingang zu legen.

### SG-Ready Ausgang

Wärmepumpen, die über eine [SG-Ready](https://www.waermepumpe.de/normen-technik/sg-ready/)-Schnittstelle
gesteuert werden können, können hier angeschlossen werden.
Dazu bietet der WARP Energy Manager 2.0 zwei Relais-Ausgänge.
Ausgang 1 wird betätigt, wenn der Betrieb
blockiert werden soll (Betriebszustand 1). Ausgang 2 wird
betätigt, wenn der Wärmepumpe eine Einschaltempfehlung
für den erweiterten Betrieb für Raumheizung und
Warmwasserbereitung gegeben werden soll (Betriebszustand 3).

### Relais-Ausgänge

Mit den zwei potentialfreien Relaisschaltausgängen können
bis zu 230 VAC/ 3A geschaltet werden. Das Ansteuern dieser Relais
erfolgt über vom Nutzer zu definierende Regeln.

### LAN-Anschluss

Die Steuerung der Wallboxen erfolgt über ein Netzwerk. Wir empfehlen den
Anschluss des WARP Energy Managers 2.0 per LAN. Der dafür notwendige
LAN-Anschluss befindet sich im eingebauten Zustand vor den anderen
Anschlüssen. Um Beschädigungen zu vermeiden, ist die LAN-Buchse flexibel
befestigt. Wir empfehlen es dennoch, ein LAN-Kabel nicht direkt an den
Energiemanager anzuschließen, sondern den mitgelieferten
RJ45-Winkeladapters zwischen Energiemanager und LAN-Kabel zu verwenden.

Der Energiemanager ist noch nicht betriebsbereit! Er muss jetzt über das
Webinterface konfiguriert werden.
