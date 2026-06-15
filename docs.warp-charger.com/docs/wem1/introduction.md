---
sidebar_position: 1
---

# Einführung

Mit dem WARP Energy Manager 1.0 bieten wir unseren Energiemanager zur
Schaltschrankmontage, mit dem der Energieverbrauch zu Hause überwacht,
gesteuert und optimiert werden kann.

![image](/img/wem1/warp-energy-manager.png)

In Verbindung mit unseren WARP Charger Wallboxen kann das Laden von
Elektrofahrzeugen abhängig vom Strombezug und der Stromeinspeisung gesteuert
werden. Unter anderem ist damit ein PV-Überschussladen oder ein dynamisches
 Lastmanagement möglich.

## Features

Der WARP Energy Manager 1.0 kann mit einem dreiphasigen bidirektionalen
Stromzähler die Leistung am Stromnetzanschluss (z. B. Hausanschluss)
kontinuierlich messen. Es werden verschiedene Zählertypen und Anschlussarten
unterstützt.

### Energiemonitoring

Die Messwerte des Stromzählers stellt der WARP Energy Manager in seinem
Webinterface dar. Dort wird angezeigt, wie groß die Leistung ist, die aus dem
Stromnetz bezogen bzw., falls eine Photovoltaik-Anlage vorhanden ist,
eingespeist wird. Leistungs- und weitere Messwerte werden live auf dem
Webinterface dargestellt.

Alle fünf Minuten werden die Messwerte lokal auf der microSD-Karte des
Energiemanagers gespeichert. Damit ist der WARP Energy Manager unabhängig von
Datenaufzeichnungen auf Cloud-Servern. Diese Daten können für jeden Tag
grafisch angezeigt werden.

Zusätzlich werden auf Tagesebene Energiebezug und Einspeisung aufgezeichnet.
Damit kann der Energieverbrauch auf Tages-, Monats- und Jahresbasis analysiert
werden.

### Steuerung von Wallboxen

Der WARP Energy Manager kann WARP Charger Wallboxen verbrauchsabhängig steuern.
Bis zu zehn Wallboxen vom Typ WARP Charger Smart, WARP Charger Pro, WARP2
Charger Smart und WARP2 Charger Pro werden unterstützt. Die Steuerung erfolgt
über eine Netzwerkverbindung (LAN, WLAN) zwischen den Wallboxen und dem WARP
Energy Manager.

Mit verschiedenen Einstellungen kann definiert werden, unter welchen
Bedingungen und mit wie viel Leistung Fahrzeuge geladen werden.

### Phasenumschaltung

Mittels eines externen Schützes kann der WARP Energy Manager angeschlossene
Wallboxen zwischen einem ein- und dreiphasigen Betrieb umschalten.

:::note

WARP Charger (1. Generation) Wallboxen unterstützen leider keine
Phasenumschaltung.

:::

Durch die Phasenumschaltung kann die minimale Ladeleistung von ca. 4,1 kW bei
einem dreiphasigen Betrieb (minimaler Ladestrom 6 A) auf ca. 1,4 kW reduziert
werden. Somit kann auch ein geringer Leistungsüberschuss zum Laden eines
Fahrzeugs verwendet werden. Ohne Phasenumschaltung ist bei kleinem
Leistungsüberschuss ein Ladevorgang nicht möglich und der Überschuss wird ins
Netz eingespeist. Alternativ müsste zusätzliche Leistung aus dem Netz bezogen
werden, damit ein Ladevorgang beginnen kann.

### Eingänge für potentialfreie Kontakte

Der WARP Energy Manager verfügt über zwei Eingänge für potentialfreie
Schaltkontakte. Wird die Phasenumschaltung genutzt, wird einer dieser Eingänge
fest zur Schützüberwachung verwendet. Ansonsten kann die Reaktion des
Energiemanagers auf die Eingänge konfiguriert werden. Es kann zum Beispiel eine
generelle Ladefreigabe realisiert oder der Ladestrom der Wallboxen begrenzt
werden.

### Potentialfreier Relaisausgang

Der potentialfreie Relaisschaltausgang des WARP Energy Managers kann genutzt
werden, um externe Verbraucher o. ä. zu schalten. Der Ausgang kann konfiguriert
werden und zum Beispiel abhängig von der verfügbaren Leistung, des momentanen
Netzbezuges oder einer erfolgten Phasenumschaltung geschaltet werden.

:::note

Mit dem Relais kann keine Netzspannung (230 V) geschaltet werden. Es können bis
zu 30 V/1 A geschaltet werden.

:::

Mit einem künftigen Firmware-Update können beispielsweise SG-Ready-Steuereingänge
von Wärmepumpen mit diesem Relaisausgang gesteuert werden.

### Status-LED

Der WARP Energy Manager besitzt auf der Frontseite eine Status-LED. Ist
PV-Überschussladen aktiviert (siehe [PV-Überschussladen](#pv-überschussladen)),
visualisiert diese LED den Zustand am Netzanschluss durch ein langsames
Pulsieren bzw. "Atmen". Die LED-Farben sind wie folgt:

- **Grün**: Leistung wird ins Netz eingespeist
- **Gelb**: Leistung wird aus dem Netz bezogen
- **Blau**: "Keine" Leistung am Netzanschluss (< ±200 W)

Wenn PV-Überschussladen nicht aktiviert ist, atmet die LED grün. In
Fehlerfällen blinkt die Status-LED (siehe [Fehlerbehebung](/docs/wem1/troubleshooting)).

## Typische Anwendungen

### PV-Überschussladen

Ist eine Photovoltaik-Anlage vorhanden, möchte man vermutlich möglichst viel
vom selbst produzierten Strom nutzen. Der WARP Energy Manager kann dabei helfen,
indem er ein reines PV-Überschussladen ermöglicht, bei dem nur überschüssige
Energie ins Fahrzeug geladen wird. Alternativ kann auch ein erlaubter anteiliger
Netzbezug definiert werden. Das ist sinnvoll, wenn die selbst produzierte
Leistung nicht ausreicht, um einen Ladevorgang zu starten, man aber dennoch
laden möchte.

Für das PV-Überschussladen benötigt der WARP Energy Manager einen Stromzähler
an deinem Stromnetzanschluss, um den Überschuss, d. h. die Einspeisung von
elektrischer Leistung ins Stromnetz, zu ermitteln. Der WARP Energy Manager
steuert dann die Wallboxen so, dass keine Leistung ins Netz eingespeist wird
(Netzbezug = 0) oder aber ein definierter Netzbezug eingehalten wird. Dies ist
abhängig von deinen Einstellungen. Siehe dazu die
[Liste kompatibler Stromzähler](/docs/compatible_devices/introduction) sowie das
Tutorial zum [PV-Überschussladen](/docs/tutorials/pv_excess_charging).

Entscheidend ist hier, dass nur eine Leistungsregelung stattfindet, die
einzelnen Phasenströme werden nicht geregelt. Da der Netzbetreiber-Stromzähler,
der die Stromkosten ermittelt, saldierend arbeitet, ist eine Phasenstromregelung
nicht notwendig.

### Statisches Lastmanagement

Teilen sich mehrere Wallboxen eine gemeinsame Zuleitung, ist oft der
Maximalstrom durch diese Zuleitung begrenzt. Als Beispiel könnten sich mehrere
Wallboxen eine 32 A Leitung teilen. Zwei Wallboxen könnten jeweils als 11 kW
Wallboxen (2 x 16 A) betrieben werden. Es wäre aber auch möglich, eine Wallbox
mit 22 kW (32 A) zu betreiben, wenn die zweite Wallbox nicht genutzt wird. Für
diese Anwendungen kommt das [statische Lastmanagement](/docs/tutorials/chargemanagement)
zum Einsatz.

Der WARP Energy Manager kann das statische Lastmanagement für die Wallboxen
übernehmen. Hierbei ist kein Stromzähler notwendig, es ist nur der Maximalstrom
der Zuleitung zu definieren. Dieser Strom muss jederzeit zur Verfügung stehen.
Der Energiemanager verteilt den Strom je nach Anforderung an die kontrollierten
Wallboxen.

### Dynamisches Lastmanagement

In manchen Fällen ist ein [dynamisches Lastmanagement](/docs/tutorials/chargemanagement)
auf Phasenstromebene erforderlich. Ein typisches Beispiel dafür sind
Mietobjekte, bei denen der Stromnetzanschluss der Immobilie nicht ausreicht, um
mehrere Wallboxen gleichzeitig zu betreiben. Die Absicherung des Netzanschlusses
beschränkt den zulässigen Phasenstrom.

Im einfachsten Fall kann für alle Wallboxen ein bestimmter Phasenstrom
garantiert werden. In diesem Fall können die Wallboxen ein statisches
Lastmanagement durchführen, bei dem der verfügbare Phasenstrom zwischen den WARP
Chargern aufgeteilt wird (siehe [Statisches Lastmanagement](#statisches-lastmanagement)).

Oftmals kann jedoch nicht garantiert werden, dass ein bestimmter Phasenstrom
jederzeit für Ladevorgänge zur Verfügung steht, da sich die Wallboxen den
Netzanschluss mit anderen Verbrauchern teilen. Wenn diese Verbraucher ein- und
ausgeschaltet werden, ändert sich der für die Wallboxen zur Verfügung stehende
Phasenstrom ständig. In diesem Fall ist ein dynamisches Lastmanagement
notwendig, um sicherzustellen, dass der maximale Phasenstrom nicht überschritten
wird und keine Sicherung auslöst.

Der WARP Energy Manager ermöglicht ein dynamisches Lastmanagement auf
Phasenstromebene. Dazu ist ein Stromzähler am Stromnetzanschluss erforderlich,
der vom Energiemanager ausgewertet werden kann. Der Energiemanager überwacht den
zur Verfügung stehenden Phasenstrom vom Netzanschluss und regelt die Leistung
der Wallboxen entsprechend. Dadurch wird sichergestellt, dass der maximale
Phasenstrom nicht überschritten wird und keine Sicherung auslöst. Wenn eine
Photovoltaik-Anlage vorhanden ist und Energie produziert, erhöht sie automatisch
die zur Verfügung stehende Leistung für den Energiemanager, um das Laden der
Elektrofahrzeuge zu optimieren.

### Kombination PV + Lastmanagement

PV-Überschussladen und ein statisches oder dynamisches Lastmanagement können
kombiniert werden. Der WARP Energy Manager betreibt dann die Leistungsregelung
für das PV-Überschussladen und stellt parallel sicher, dass die
Phasenstrom-Begrenzungen durch das Lastmanagement eingehalten werden.
