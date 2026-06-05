---
sidebar_position: 3
---

# Wallboxen

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc1', 'wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />



:::note

Ein WARP Charger Smart oder Pro kann als Lastmanager konfiguriert werden.
Bis zu 64 WARP Charger (inkl. des Lastmanagers selbst) können somit von
einer Wallbox verwaltet werden.

Auch der WARP Energy Manager kann als Lastmanager für bis zu 64 WARP Charger
konfiguriert werden.

:::

![image](/img/webinterface/energy_management/chargers.png)

Auf dieser Seite werden die kontrollierten Wallboxen konfiguriert. Die hier vorgenommenen Einstellungen
beeinflussen das [Lastmanagement](/docs/tutorials/chargemanagement) zwischen den Wallboxen.

Typ-2-Wallboxen kommunizieren den angeschlossenen Fahrzeugen den maximal zur Verfügung stehenden Ladestrom.
Das Fahrzeug entscheidet, ob dieser Ladestrom voll ausgenutzt wird und ob ein Ladevorgang ein-, zwei oder dreiphasig durchgeführt wird.


Handelt es sich um einen WARP Charger, so muss als erste Einstellung konfiguriert werden wie die Wallbox gesteuert wird (**Fremdsteuerung**):

 * **Deaktiviert**: Es findet kein Lastmanagement statt. Die Wallbox ist vollständig eigenständig.
 * **Fremdgesteuert**: Die Wallbox wird von einem anderen Lastmanager verwaltet. Es müssen keine weiteren Einstellungen vorgenommen werden.
 * **Lastmanager/PV-Überschussladen**: Die Wallbox arbeitet als Lastmanager. Dies ist auch der Fall, wenn sie nur eigenständig die Funktion [PV-Überschussladen](/docs/tutorials/pv_excess_charging) ausführen soll. Es sind weitere Einstellungen vorzunehmen.


## Konfiguration Lastmanager

Wird ein WARP Charger oder WARP Energy Manager als Lastmanager konfiguriert sind folgende Einstellungen vorzunehmen:

### Maximale Gesamtstrom

Dies ist der maximale Strom der Zuleitung zu den Wallboxen gelastmangeten Wallboxen. Der
Lastmanager stellt sicher, dass dieser Strom auf keiner Phase überschritten wird, indem niemals mehr als dieser Strom an die Wallboxen verteilt wird (statisches Lastmanagement).

Besitzen alle Wallboxen ausreichend dimensionierte getrennte Zuleitungen kann dieser Strom so hoch eingestellt werden, dass alle Wallboxen sicher ihren Maximalstrom erhalten. Alle andere Komponenten, wie zum Beispiel der Netzanschluss,
müssen dann den konfigurierten maximalen Gesamtstrom liefern können. Der individuelle Maximalstrom jeder Wallbox bleibt hiervon unberührt.


:::note

Hierbei handelt es sich um ein statisches Lastmanagement, bei dem davon ausgegangen wird, dass der eingestellte Strom auf jeder Phase zu jeder Zeit zur Verfügung steht.
Andere Verbraucher als WARP Charger, welche vom Lastmanager nicht gesteuert werden können, werden nicht berücksichtigt!

:::

### Zentrale Verwaltung

Zusätzlich zum statischen und/oder dynamischen Lastmanagement und dem PV-Überschussladen kann die zentrale Verwaltung verwendet werden.

Wenn diese aktiv ist, dann werden Ladevorgänge an kontrollierten Wallboxen dann nur gestartet, wenn sich Benutzer authentifizieren (z.B. über ein NFC-Tag, oder über die Status-Seite des Lastmanagers).
Benutzer und NFC-Tags müssen in der [Benutzerverwaltung](/docs/webinterface/users/user_management) des Lastmanagers konfiguriert werden.

Außerdem werden Ladevorgänge der kontrollierten Wallboxen im [Ladetracker](/docs/webinterface/energy_management/charge_tracker) des Lastmanagers aufgezeichnet.
Im Ladetracker können dann Ladelogs heruntergeladen, bzw. periodisch per Mail verschickt werden, die die gesammelten Ladevorgänge aller Wallboxen umfassen.

:::note

Die Freigabe der Ladevorgänge über die zentrale Verwaltung ist nicht an eine eventuell konfigurierte Ladefreigabe in der [Benutzerverwaltung](/docs/webinterface/users/user_management) einer kontrollierten Wallbox gekoppelt.
Es ist prinzipiell möglich, sowohl die (lokale) Ladefreigabe, als auch die zentrale Verwaltung zu aktivieren, Benutzer und NFC-Tags müssen dann aber sowohl dem Lastmanager, als auch der kontrollierten Wallbox bekannt sein. **Wir empfehlen nur entweder die zentrale Verwaltung oder die (lokale) Ladefreigabe zu verwenden**

:::

### Kontrollierte Wallboxen

Am Ende der Seite werden die vom Lastmanager *Kontrollierten Wallboxen* konfiguriert und dargestellt.
Weitere Wallboxen können mittels Klick auf *+* hinzugefügt werden. Dazu muss der Anzeigename und die IP-Adresse oder der Hostname der
Wallbox eingetragen werden und mittels Klick auf *hinzufügen* übernommen werden. Automatisch ermittelte Wallboxen, die noch nicht vom
Lastmanager gesteuert werden, werden als Liste dargestellt. Fur jede Wallbox kann zusätzlich die Phasenrotation eingestellt werden. Diese Information ist für das dynamische Lastmanagement relevant.


:::note

Für die Einrichtung eines Lastmanagements gibt es ein eigenes Tutorial: [Lastmanagement](/docs/tutorials/chargemanagement)

:::
