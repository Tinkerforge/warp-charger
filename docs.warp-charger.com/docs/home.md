---
sidebar_position: 0
---

# Einführung

Willkommen auf den Dokumentationsseiten der WARP-Produktreihe von
Tinkerforge.

Hier findest du die Dokumentation zur Installation und Konfiguration von
* [WARP3 Charger](/warp_charger/introduction.md),
* [WARP Energy Manager](/warp_energy_manager/introduction.md) und
* [WARP Ladesäule](/warp_ladesäule/introduction.md).


Diese Dokumentation wird ständig gepflegt und erweitert. Wenn ihr Ideen für
weitere Dokumentation oder Beispiele habt teilt uns diese gerne mit. Auch
nehmen wir gerne weitere [kompatible Geräte](/compatible_devices/introduction.md)
in die Liste auf oder gute Fragen/Antworten für die [FAQ](/faq.md).

### Philosophie

Wir glauben, dass die Produkte den Kunden gehören. Deswegen entwickeln
Lösungen mit offenen Schnittstellen und verfolgen konsequent ein
Open-Source-Konzept (Hardware- und Software). Die Entwicklung und Fertigung
unserer Produkte erfolgt in Deutschland (Made in Germany). Wir legen unsere
Produkte auf eine lange Lebensdauer aus, achten auf Qualität und einfache
Reparierbarkeit.

#### Community

Die Entwicklung unserer Produkte erfolgt sehr eng mit unserer Community zusammen:
 * [Tinkerunity](https://www.tinkerunity.org/forum/13-warp-charger/)

Egal ob neue Ideen, Bugreports oder Beta-Tester wir freuen uns über die intensive Zusammenarbeit!

#### Offene Schnittstellen

WARP Energy Manager 2.0, WARP3 Charger Smart und WARP3 Charger Pro können
in andere Systeme mittels den offenen Schnittstellen eingebunden werden:
* [MQTT/HTTP API](/interfaces/mqtt_http/introduction.md)
* [Modbus-Schnittstelle](/interfaces/modbus/introduction.md)
* [OCPP](/interfaces/ocpp.md) (nur WARP Charger)

#### Verzicht auf Cloud

Wir versuchen möglichst alle Funktionen lokal auf dem Gerät zu implementieren.
So wird zum Beispiel das Ladelogbuch lokal auf den Wallboxen gespeichert. Soll
daraus eine Abrechnung als PDF generiert werden, so erfolgt dies auf der
Wallbox und in deinem Browser. Also ohne eine Cloud.

In den Fällen, bei denen wir auf Daten aus einer Cloud technisch angewiesen sind
(z.B.: PV-Prognose, dynamische Strompreise, Fernzugriff), versuchen wir dennoch möglichst
viele Funktionen auf dem jeweiligen Gerät zu implementieren und nicht in der Cloud.
Das heißt wir versuchen nach Möglichkeit keine Daten in der Cloud zu speichern, sondern
lokal auf den Geräten.

Als Beispiel ist der Fernzugriff, der auch von den Android und iOS Apps genutzt wird,
technisch ein VPN Tunnel zwischen dem Browser/der App und dem Gerät (WARP Charger oder WARP Energy Manager).
Der Datenaustausch erfolgt also zwischen den beiden Teilnehmern und nicht über [my.warp-charger.com](https://my.warp-charger.com).

### Kompatibilität zu Fremdgeräten

Unser Ziel ist es, dass unsere Produkte auch mit Geräten anderer Hersteller
zusammenarbeiten. So ist es möglich auf die Daten von PV-Wechselrichtern, Stromzählern
oder Batteriespeichern von anderen Herstellern zuzugreifen und zum Beispiel für das PV-Überschussladen
oder ein dynamisches Lastmanagement zu nutzen.

Die Liste der kompatiblen Geräte lässt sich hier finden: [Liste kompatibler Geräte](/docs/compatible_devices/introduction.md)

### Sonnenstrom nutzen

#### Photovoltaik-Überschussladen

[WARP3 Charger Smart und Pro](/warp_charger/introduction.md)
können direkt und ohne zusätzliche Hardware ein PV-Überschussladen
durchführen. Das heißt anstatt das überschüssige Energie der PV-Anlage
in das Stromnetz eingespeist wird, wird diese in das Elektrofahrzeug
geladen. Dazu muss die Wallbox nur elektrisch angeschlossen und mittels
LAN oder WLAN ins Netzwerk gebracht werden. Zusätzlich muss ein
Stromzähler am Hausanschluss verfügbar sein, der von der Wallbox
ausgewertet werden kann. Mittels der Leistungs-Messwerte von diesem
Stromzähler erfolgt dann das PV-Überschussladen. Einer Übersicht über
die aktuell unterstützen Geräte, die die Leistung am Hausanschluss
messen können, lassen sich im Artikel
[kompatible Geräte](/compatible_devices/introduction.md) finden.

#### Heizung mit dem Photovoltaik-Überschuss betreiben

Analog zum PV-Überschussladen kann ein [WARP Energy Manager 2.0](/warp_energy_manager/introduction.md)
genutzt werden um eine Wärmepumpe mit SG-Ready Schnittstelle in den erweiterten
Betrieb zu versetzen. Somit kann ein PV-Überschuss auch für die Heizung genutzt werden.

### Dynamische Strompreise

[WARP3 Charger Smart und Pro](/warp_charger/introduction.md) und der [WARP Energy Manager 2.0](/warp_energy_manager/introduction.md)
können direkt die Strom-Erzeugerpreise bei der Strombörse abrufen. Zusätzliche Kosten, wie zum Beispiel Netzentgelte und Steuern können
individuell konfiguriert werden. Somit unterstützen wir jeden Anbieter dynamischer Strompreise ohne auf eine individuelle Implementierung
der Schnittstellen des Anbieters angewiesen zu sein.

### §14a - Steuerbare Verbrauchseinrichtungen
Wallboxen, Wärmepumpen und Batteriespeicher sind nach §14A sogenannte steuerbare Verbrauchseinrichtungen. Wir bieten
verschiedene Möglichkeiten wie die gesetzlichen Anforderungen erfüllt werden können. Siehe [Tutorial - Steuerbare Verbrauchseinrichtungen](/docs/tutorials/verbrauchseinrichtung)


### Lastmanagement

#### Mehrere Wallboxen an einer Leitung betreiben - Statisches Lastmanagement

Teilen sich mehrere WARP Charger eine Zuleitung, so müssen die
Ladeströme der angeschlossenen Wallboxen gegebenenfalls begrenzt werden.
WARP3 Charger Smart und WARP3 Charger Pro verfügen über ein integriertes
[Lastmanagement](/docs/tutorials/chargemanagement.md).
Die Wallboxen müssen sich nur innerhalb eines
Netzwerks (LAN, WLAN) befinden. Ein gesonderter Stromzähler ist für das
*statische* Lastmanagement nicht notwendig.

#### Nicht ausreichend dimensionierter Netzanschluss - Dynamisches Lastmanagement

Ist der Netzanschluss nicht ausreichend dimensioniert um eine oder
mehrere Wallboxen betreiben zu können, hilft das dynamische Lastmanagement.
Gerade bei größeren Objekten ist der Netzanschluss oftmals rechnerisch ausgereizt,
wenn angenommen wird, dass alle Verbraucher eingeschaltet werden.
In der Praxis kommt dies aber eigentlich nie vor, so dass Wallboxen
dennoch betrieben werden können. Die Wallboxen müssen dann abhängig von
den aktuellen Phasenströmen am Netzanschluss gesteuert werden, um sicherzustellen,
dass keine der drei Phasen überlastet
wird. Ist ein geeigneter Stromzähler am Netzanschluss vorhanden, der die
Phasenströme messen kann, so kann das dynamische Lastmanagement direkt
von einem WARP Charger übernommen werden. Einer Übersicht über die
aktuell unterstützen Geräte, die die Leistung am Hausanschluss
messen können, lassen sich im Artikel
[kompatible Geräte](/docs/compatible_devices/introduction.md) finden.

