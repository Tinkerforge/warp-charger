---
sidebar_position: 1
---

# Einführung

"WARP" steht für **W**all **A**ttached **R**echarge **P**oint. Mit dem WARP1 Charger
von Tinkerforge erhältst du eine hochqualitative und langlebige Wallbox, mit der du
dein Elektrofahrzeug laden kannst. Die Wallbox ist modular aufgebaut, sodass einzelne
Komponenten einfach ausgetauscht werden können. Sowohl Hardware als auch Software sind
Open Source.

![image](/img/warp1/warp_perspective_blue_ready.jpg)

## Funktionsweise

Den WARP1 Charger bieten wir in drei Varianten an: Basic, Smart und Pro. Mit allen
Varianten kannst du dein Elektrofahrzeug nach DIN EN 61851-1 Mode 3 laden. Jedes Modell
ermöglicht einphasiges und dreiphasiges Laden (je nach Anschlussart) und ist als
11 kW- und 22 kW-Variante erhältlich. Die 11 kW- und die 22 kW-Variante unterscheiden
sich unter anderem durch den Leitungsquerschnitt des Fahrzeug-Ladekabels. Der maximale
Ladestrom kann von 16 A (dreiphasig 11 kW) bzw. 32 A (dreiphasig 22 kW) über
Schaltereinstellungen in der Wallbox reduziert werden. Minimal sind 6 A möglich.

Nach dem Einstecken des Typ-2-Ladesteckers in das Fahrzeug zeigt eine blaue LED auf der
Frontblende der Wallbox den Ladezustand an. Über einen Schlüsselschalter kann die
Lademöglichkeit der Wallbox deaktiviert werden. Innerhalb der Front-LED befindet sich ein
Taster, mit dem ein aktiver Ladevorgang sofort abgebrochen werden kann.

## Varianten

### WARP1 Charger Basic

Der WARP1 Charger Basic ist das einfachste Modell. Mit diesem kann ein Elektrofahrzeug
nach DIN EN 61851-1 Mode 3 geladen werden. Der maximale Ladestrom wird über
Schaltereinstellungen in der Wallbox vorgegeben. Der Ladezustand wird über die blaue
Front-LED angezeigt.

### WARP1 Charger Smart

Die Modellreihe WARP1 Charger Smart ist zusätzlich mit einem WLAN-Controller ausgestattet.
Dieser kann als Access Point ein eigenes WLAN eröffnen oder in ein vorhandenes Netz
eingebunden werden. Die Wallbox verfügt über ein eigenes Webinterface, auf dem der aktuelle
Ladezustand angezeigt wird und Einstellungen vorgenommen werden können. Über das Webinterface
kann zum Beispiel die Ladeleistung konfiguriert werden. Über die MQTT-Schnittstelle der
Wallbox kann die Wallbox auch ferngesteuert werden.

### WARP1 Charger Pro

Die Modellreihe WARP1 Charger Pro bietet alles, was der WARP1 Charger Smart bietet.
Zusätzlich ist diese Wallbox mit einem MID-geeichten Zähler ausgestattet. Dieser misst,
wie viel Energie (kWh) geladen wurde, und bietet Statistiken, mit denen du einen Überblick
über deine Stromkosten erhältst.

## Anschlusskabel

Alle Wallboxen werden mit einem fest angeschlossenen 5 m- oder 7,5 m-Ladekabel mit
Typ-2-Stecker geliefert. Die Modelle WARP1 Charger Basic und Smart sind ohne Anschlusskabel
(Anschluss der Zuleitung) oder mit einem 2 m-Anschlusskabel mit CEE-Stecker erhältlich.
Das Modell WARP1 Charger Pro wird immer mit einem 2 m-Anschlusskabel ausgeliefert, da aufgrund
des zusätzlich verbauten Stromzählers nicht genug Platz zur Verfügung steht, um eine Zuleitung
direkt anzuschließen. Es gibt daher die Varianten mit 2 m-Kabel und offenen Kabelenden sowie
2 m-Kabel mit CEE-Stecker.

Folgende Anschlusskabel werden verwendet (je nach gewählten Optionen):

 * 11 kW: Gummianschlussleitung H07RN-F 5G4 (4 mm² Querschnitt) + 16 A-CEE-Stecker
 * 22 kW: Gummianschlussleitung H07RN-F 5G6 (6 mm² Querschnitt) + 32 A-CEE-Stecker
