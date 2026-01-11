---
sidebar_position: 1
---

# Einführung

:::note

Diese Beschreibung bezieht sich auf den WARP Energy Manager 2.0. Für Informationen zum älteren
Modell (WARP Energy Manager 1.0) kann auf die Betriebsanleitung unter
https://warp-charger.com/downloads zurückgegeriffen werden.

:::



Mit dem WARP Energy Manager bieten wir unseren Energiemanager zur Schaltschrankmontage,
mit dem der Energieverbrauch zu Hause überwacht, gesteuert und optimiert werden kann.

![image](/img/warp_energy_manager/wem2_face_side.jpg)

Der WARP Energy Manager kann abhängig von dynamischen Strompreisen,
einem Photovoltaik-Überschuss oder dem aktuellen Strom am Netzanschluss Wärmepumpen über die
SG-Ready-Schnittstelle steuern, zusätzliche Verbraucher ein- bzw. ausschalten und in
Verbindung mit WARP Charger Wallboxen Elektrofahrzeuge laden. Auch die Steuerung des Lade- und Entladevorgangs von Batteriespeichern ist zukünftig möglich.

## Features

Der WARP Energy Manager verfügt über folgende Features:

 * Integriertes lokales Energiemonitoring (Datenspeicherung auf dem Gerät)
 * Steuerung von Wärmepumpen mittels SG-Ready-Schnittstelle
 * Vier Eingänge für potentialfreie Kontake, z.B.: §14a EnwG - Steuerbare Verbrauchseinrichtung
 * Zwei Relaisausgänge zur Ansteuerung weiterer Verbraucher
 * Steuerung von bis zu 64 WARP Charger Wallboxen
 * Steuerung von Batteriespeichern (zukünftig)
 * Zugriff auf Stromzähler am Netzanschluss, Photovoltaik-Wechselrichter, Batteriespeicher
 * Photovoltaik-Überschussnutzung
 * Statisches und dynamisches Lastmanagement von WARP Chargern
 * Photovoltaik-Prognose
 * Dynamische Strompreise

### Integriertes Energiemonitoring
Die Messwerte der Stromzähler stellt der WARP Energy Manager in seinem Webinterface dar. Dort wird angezeigt,
wie groß die Leistung ist, die aus dem Stromnetz bezogen bzw., (falls eine Photovoltaik-Anlage vorhanden ist) eingespeist wird. Zusätzlich können weitere Daten, zum Beispiel
von PV-Wechselrichtern und Batteriespeichern, oder der dynamische Strompreis angezeigt werden. Leistungs- und weitere Messwerte werden dir live auf dem Webinterface
dargestellt.

![image](/img/webinterface/status/wem2-status.jpeg)

Alle fünf Minuten werden die Messwerte lokal auf der microSD-Karte des Energiemanagers gespeichert. Damit
ist der WARP Energy Manager unabhängig von Datenaufzeichnungen auf Cloud-Servern. Diese Daten kannst du
dir fur jeden Tag grafisch anzeigen lassen. Damit kannst du deinen Energieverbrauch auf Tages-, Monats- und Jahresbasis analysieren.

### Steuerung von Wallboxen
Der WARP Energy Manager kann bis zu 64 Wallboxen vom Typ WARP Charger Smart oder WARP Charger Pro
verbrauchsabhängig steuern. Die Steuerung erfolgt über eine gemeinsames Netzwerk (LAN, WLAN) zwischen den Wallboxen und dem WARP Energy Manager.
Es kann ein statisches Lastmanagement durchgefuhrt werden, bei dem ein fest eingestellter Strom je nach Anforderung unter den Wallboxen aufgeteilt wird.
Alternativ ist auch der Aufbau eines dynamischen Lastmanagements möglich. Dabei wird der Strom am Netzanschluss von einem Stromzähler gemessen. Der WARP
Energy Manager regelt dann die Wallboxen so, dass der eingestellte Maximalstrom am Netzanschluss nicht überschritten wird.
Mit verschiedenen Einstellungen kannst du definieren, unter welchen Bedingungen und mit wie viel Leistung Fahrzeuge geladen werden.


### SG-Ready-Schnittstelle zur Ansteuerung von Wärmepumpen
Der WARP Energy Manager besitzt eine [SG-Ready Schnittstelle](/webinterface/energy_management/heater.md) mit der Wärmepumpen gesteuert werden können. Diese besteht laut Standard aus zwei Relais-Ausgängen. Mit einem Ausgang kann die Wärmepumpe
vollständig blockiert werden, zum Beispiel wenn der Strompreis einen Schwellwert ubersteigt. Die Wärmepumpe kann mit dem zweiten Ausgang in einen erweiterten Betrieb
versetzt werden, bei dem die Heizkreis- und Warmwassertemperaturen etwas erhöht werden. Damit lassen sich zum
Beispiel ein Photovoltaik-Überschuss oder günstige Strompreise effizient nutzen. Ist keiner der Ausgänge geschaltet
verrichtet die Wärmepumpe ganz normal ihren Dienst.

### Zwei Relaisausgäge zur Ansteuerung weiterer Verbraucher
Der WARP Energy Manager verfügt über zwei Relais-Ausgänge. Mit diesen Ausgängen können zum Beispiel
230V Verbraucher direkt oder mittels zwischengeschaltetem Schütz auch größere Lasten geschaltet werden. Als Beispiel können so Heizstäbe gesteuert werden.

### Vier Eingänge, z.B. für §14a EnWG - Steuerbare Verbrauchseinrichtung
An die vier Eingänge des WARP Energy Managers kann jeweils ein potentialfreier Kontakt (Schließer/Öffner) angeschlossen werden.
Diese Eingänge können fur vom Anwender konfigurierbare Regeln genutzt werden. Eine Anwendung ist die Nutzung eines Eingangs um nach §14a
EnWG vom Energy Manager gesteuerte Wallboxen und die Wärmepumpe in der Leistung zu reduzieren.

### Fronttaster mit Display
Ein 320x240 Pixel TFT Display zeigt Systeminformationen an. Dazu kann die Anzeige der sechs Kacheln auf dem
Display konfiguriert werden. Es können zum Beispiel die Leistung am Netzanschluss, Zustandsinformationen von Wallboxen, der Status der SG-Ready-Schnittstelle,
der Wert des dynamischen Strompreises etc. angezeigt werden. Das Display schaltet sich nach 5 Minuten Inaktivität ab.

Zusätzlich verfügt der WARP Energy Manager über einen Fronttaster. Durch Drücken dieses Tasters kann zwischen verschiedenen Screens gewechselt werden. Zusätzlich zeigt
die Farbe des Tasters an ob es Probleme gibt (Farbe rot) oder nicht (Farbe grün).

## Anwendungen

### PV-Überschussnutzung

Ist eine Photovoltaik-Anlage vorhanden, möchte man möglichst viel vom selbst produzierten Strom nutzen. Der WARP Energy Manager kann
dabei helfen, indem Elektrofahrzeuge mit diesem Strom geladen werden ([PV-Überschussladen](/tutorials/pv_excess_charging.md)). Der Strom kann aber auch genutzt werden um zum Beispiel eine Wärmepumpe im erweiterten Betrieb
zu betreiben. Zusätzlich können an den Relaisausgängen weitere Verbraucher, wie zum Beispiel Heizstäbe, angeschlossen werden. Der Energy Manager kann diese dann zum Beispiel einschalten, wenn trotz
Elektrofahrzeug-Ladung und Ansteuern der Wärmepumpe noch PV-Überschuss übrig ist.

Für die PV-Überschussnutzung benötigt der WARP Energy Manager einen Stromzähler an deinem Stromnetzanschluss, um den Überschuss, d.h. die Einspeisung von
elektrischer Leistung ins Stromnetz, zu ermitteln. Der WARP Energy Manager steuert dann die Geräte so, dass keine Leistung ins Netz eingespeist wird
(Netzbezug = 0) oder aber ein definierter Netzbezug eingehalten wird. Dies ist abhängig von den Einstellungen. Siehe dazu die [Liste kompatibler Stromzähler](/docs/compatible_devices/introduction.md).

Entscheidend ist hier, dass nur eine Leistungsregelung stattfindet, die einzelnen Phasenströme werden nicht geregelt. Da der Netzbetreiber-Stromzähler, der die Stromkosten ermittelt, saldierend arbeitet, ist eine Phasenstromregelung nicht notwendig.

### Statisches Lastmanagement

Teilen sich mehrere Wallboxen eine gemeinsame Zuleitung, ist oft der Maximalstrom durch diese Zuleitung begrenzt. Als Beispiel könnten sich mehrere
Wallboxen eine 32A Leitung teilen. Zwei Wallboxen könnten jeweils als 11kW Wallboxen (2x16A) betrieben werden. Es wäre aber auch möglich, eine
Wallbox mit 32kW (32A) zu betreiben, wenn die zweite Wallbox nicht genutzt wird. Für diese Anwendungen kommt das [statische Lastmanagement](/docs/tutorials/chargemanagement.md) zum Einsatz.

Der WARP Energy Manager kann das statische Lastmanagement für die Wallboxen übernehmen. Hierbei ist kein Stromzähler notwendig, es ist nur der
Maximalstrom der Zuleitung zu definieren. Dieser Strom muss jederzeit zur Verfügung stehen. Der Energiemanager verteilt den Strom
je nach Anforderung an die kontrollierten Wallboxen.

### Dynamisches Lastmanagement

In manchen Fällen ist ein [dynamisches Lastmanagement](/docs/tutorials/chargemanagement.md) auf Phasenstromebene erforderlich. Ein typisches Beispiel dafür sind Mietobjekte, bei denen der Stromnetzanschluss der
Immobilie nicht ausreicht, um mehrere Wallboxen gleichzeitig zu betreiben. Die Absicherung des Netzanschlusses beschränkt den zulässigen Phasenstrom.

Im einfachsten Fall kann für alle Wallboxen ein bestimmter Phasenstrom garantiert werden. In diesem Fall können die Wallboxen ein statisches Lastmanagement durchführen,
bei dem der verfügbare Phasenstrom zwischen den WARP Chargern aufgeteilt wird.

Oftmals kann jedoch nicht garantiert werden, dass ein bestimmter Phasenstrom jederzeit für Ladevorgänge zur Verfügung steht, da sich die Wallboxen den Netzanschluss mit anderen Verbrauchern teilen.
Wenn diese Verbraucher ein- und ausgeschaltet werden, ändert sich der für die Wallboxen zur Verfügung stehende Phasenstrom ständig. In diesem Fall ist ein dynamisches Lastmanagement notwendig, um
sicherzustellen, dass der maximale Phasenstrom nicht überschritten wird und keine Sicherung auslöst.

Der WARP Energy Manager ermöglicht ein dynamisches Lastmanagement auf Phasenstromebene. Dazu ist ein Stromzähler am Stromnetzanschluss erforderlich, der vom Energiemanager
ausgewertet werden kann. Der Energiemanager überwacht den zur Verfügung stehenden Phasenstrom vom Netzanschluss und regelt die Leistung der Wallboxen entsprechend.
Dadurch wird sichergestellt, dass der maximale Phasenstrom nicht überschritten wird und keine Sicherung auslöst. Wenn eine Photovoltaik-Anlage vorhanden ist und Energie
produziert, erhöht sie automatisch die zur Verfügung stehende Leistung für den Energiemanager, um das Laden der Elektrofahrzeuge zu optimieren.

### Kombination PV + Lastmanagement
Die PV-Überschussnutzung und ein statisches bzw. dynamisches Lastmanagement können kombiniert werden. Der WARP Energy Manager betreibt dann die
Leistungsregelung für das PV-Überschussladen und stellt parallel sicher, dass die Phasenstrom-Begrenzungen durch das Lastmanagement eingehalten werden.
