---
sidebar_position: 1
---

# Einstellungen

Auf dieser Seite können verschiedene Einstellungen
des Ladecontrollers verändert werden:

![image](/img/webinterface/wallbox/warp-settings.jpeg)

## Manuelle Ladefreigabe

Wenn die manuelle Ladefreigabe aktiviert wird, wird ein Ladevorgang niemals automatisch begonnen.
Jeder Ladevorgang muss über das Webinterface, die API oder (je nach Tastereinstellung)
den Taster gestartet werden. Die manuelle Ladefreigabe blockiert zusätzlich zu eventuell anderen aktiven
Ladestromgrenzen. Das heißt, dass sie nicht aktiviert werden muss, wenn Ladevorgänge beispielsweise mit
der Benutzerfreigabe per NFC-Tag, oder der Steuerung
per OCPP kontrolliert werden.


## Status-LED-Steuerung

Ermöglicht die Steuerung der Front-LED mit einer externen Steuerung oder über
die API, z.B. für eine externe NFC-Freigabe.

## Boost-Modus

Die Ladeelektronik mancher Fahrzeuge interpretiert einen vom WARP3 Charger vorgeschriebenen Ladestrom zu niedrig.
Der Boost-Modus versucht, diesen Effekt auszugleichen, indem ein leicht höherer Ladestrom kommuniziert wird.


## Zähleruberwachung

Im WARP3 Charger Pro ist ein Stromzähler verbaut. Wenn diese Option aktiviert ist, wird ein Ladevorgang unterbrochen
bzw. nicht freigegeben, falls der Stromzähler bzw. die Kommunikation mit diesem gestört zu sein scheint. Wenn die
Zählerüberwachung aktiviert ist, wird somit sichergestellt, dass die geladene Energie zu jedem aufgezeichneten Ladevorgang erfasst wird.


## Zeitlimit

Setzt ein generelles Zeitlimit fur Ladevorgänge. Nach Ablauf des Limits muss ein Fahrzeug abgezogen werden, um einen erneuten Ladevorgang zu ermöglichen. Das Zeitlimit kann fur den
nächsten oder laufenden Ladevorgang auf der Statusseite überschrieben werden.

## Energielimit

Setzt beim WARP3 Charger Pro ein generelles Energielimit für Ladevorgänge. Diese Funktion
wird analog zum Zeitlimit eingerichtet.

## Tastereinstellung

Hiermit wird konfiguriert, welche Funktion der Taster an der Front des WARP3 Chargers haben soll. Im halböffentlichen Raum kann es
beispielsweise sinnvoll sein, den Ladestop per Taster zu verbieten.

## Abschalteingang

Am Abschalteingang kann zum Beispiel ein Rundsteuerempfänger angeschlossen werden. Hier kann eingestellt werden, wie auf Änderungen
am Abschalteingang reagiert werden soll. In der Standardkonfiguration der Wallbox wird auf 4200 W limitiert, wenn der Abschalteingang geschlossen ist, siehe
[Steuerbare Verbrauchseinrichtung nach §14a EnWG](/docs/tutorials/verbrauchseinrichtung).


## Fahrzeug-Weckruf

Die Ladeelektronik mancher Fahrzeuge wechselt in einen Energiesparmodus, falls ein
Ladevorgang nicht innerhalb einer gewissen Zeit gestartet wird. Der Fahrzeug-Weckruf versucht, solche
Ladeelektroniken automatisch zu wecken, falls das Fahrzeug nicht innerhalb von 30 Sekunden reagiert, wenn
Strom zur Verfugung steht. Umgesetzt wird dies durch eine kurzzeitige Trennung des Control-Pilot- bzw. CP-Signals.


***Automatischer Phasenwechsel***

Diese Option steht nur für den WARP3 Charger Pro zur Verfügung. Ist
die Option aktiviert, wird bei einem laufenden Ladevorgang mit dem internen Stromzähler ermittelt, ob das
Fahrzeug nur einphasig lädt. Ist dies der Fall, schaltet die Wallbox automatisch auf einphasiges Laden um.


***Zuleitung***

Hier wird konfiguriert, ob die Wallbox dreiphasig oder
einphasig angeschlossen ist. Ist die Wallbox nur einphasig angeschlossen und hier auch so konfiguriert, wird
das zweite Schütz für die Phasen L2 und L3 nie geschaltet, außerdem wird die Begrenzung der Ladeleistung
nach §14 EnWG entsprechend berechnet.
