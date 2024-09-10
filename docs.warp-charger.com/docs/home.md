---
sidebar_position: 0
---

# Einführung

Willkommen auf den Dokumentationsseiten der WARP-Produktreihe von
Tinkerforge.

Hier findest du die Dokumentation zur Installation und Konfiguration von
* [WARP3 Charger](/warp_charger/assembly_and_installation.md),
* [WARP Energy Manager](/warp_energy_manager/assembly_and_installation.md) und
* [WARP Ladesäule](/warp_ladesäule/assembly_and_installation.md).

Es gibt viele Anwendungsfälle für den WARP3 Charger. Nachfolgend werden
klassische Anwendungsfälle für WARP3 Charger Smart und WARP3 Charger Pro
Wallboxen kurz dargestellt.
Eine Detailbeschreibung folgt in der jeweiligen Produktbeschreibung.

Diese Dokumentation wird ständig gepflegt und erweitert. Wenn ihr Ideen für
weitere Dokumentation oder Beispiele habt teilt uns diese gerne mit. Auch
nehmen wir gerne weitere [kompatible Stromzähler](/compatible_meters.md)
in die Liste auf oder gute Fragen/Antworten für die [FAQ](/faq.md).

### Einbindung in andere Systeme

WARP3 Charger Smart und WARP3 Charger Pro können in andere Systeme
mittels den offenen Schnittstellen eingebunden werden:
* [MQTT/HTTP API](/mqtt_http/getting_started.md)
* [Modbus-Schnittstelle](/modbus/configuration.md)

Für spezifische Systeme gibt es eine direkte Unterstützung:
<!--- Comment me in when documented properly
* [Heimautomatisierungs-Lösungen](/smart_home/warp_automation.md)
-->
* [EVCC](/evcc.md)

### Sonnenstrom nutzen - Photovoltaik-Überschussladen

WARP3 Charger Smart und Pro
können direkt und ohne zusätzliche Hardware ein PV-Überschussladen
durchführen. Das heißt anstatt das überschüssige Energie der PV-Anlage
in das Stromnetz eingespeist wird, wird diese in das Elektrofahrzeug
geladen. Dazu muss die Wallbox nur elektrisch angeschlossen und mittels
LAN oder WLAN ins Netzwerk gebracht werden. Zusätzlich muss ein
Stromzähler am Hausanschluss verfügbar sein, der von der Wallbox
ausgewertet werden kann. Mittels der Leistungs-Messwerte von diesem
Stromzähler erfolgt dann das PV-Überschussladen. Einer Übersicht über
die aktuell unterstützen Zählertypen, die die Leistung am Hausanschluss
messen können, lassen sich im Artikel
[kompatible Stromzähler](/compatible_meters.md) finden.

### Mehrere Wallboxen an einer Leitung betreiben - Statisches Lastmanagement

Teilen sich mehrere WARP Charger eine Zuleitung, so müssen die
Ladeströme der angeschlossenen Wallboxen gegebenenfalls begrenzt werden.
WARP3 Charger Smart und WARP3 Charger Pro verfügen über ein integriertes
[statisches Lastmanagement](warp_charger/chargemanagement.md).
Die Wallboxen müssen sich nur innerhalb eines
Netzwerks (LAN, WLAN) befinden. Ein gesonderter Stromzähler ist für das
statische Lastmanagement nicht notwendig.

### Nicht ausreichend dimensionierter Netzanschluss - Dynamisches Lastmanagement

Ist der Netzanschluss nicht ausreichend dimensioniert um eine oder
mehrere Wallboxen betreiben zu können, kann gegebenenfalls ein
dynamisches Lastmanagement helfen. Gerade bei
größeren Objekten ist der Netzanschluss oftmals rechnerisch ausgereizt,
wenn angenommen wird, dass alle Verbraucher eingeschaltet werden.
In der Praxis kommt dies aber eigentlich nie vor, so dass Wallboxen
dennoch betrieben werden können. Die Wallboxen müssen dann abhängig von
den aktuellen Phasenströmen am Netzanschluss lastgeregelt werden.
Dabei muss sichergestellt werden, dass keine der drei Phasen überlastet
wird. Ist ein geeigneter Stromzähler am Netzanschluss vorhanden, der die
Phasenströme messen kann, so kann das dynamische Lastmanagement direkt
von einem WARP Charger übernommen werden. Einer Übersicht über die
aktuell unterstützen Zählertypen, die die Leistung am Hausanschluss
messen können, lassen sich im Artikel
[kompatible Stromzähler](/compatible_meters.md) finden.
