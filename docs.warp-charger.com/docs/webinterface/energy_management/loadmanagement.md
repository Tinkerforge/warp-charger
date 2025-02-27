---
sidebar_position: 5
---

# Lastmanagement

:::note

Die Konfiguration eines Lastmanagement ist auch im Tutorial [Lastmanagement](/docs/tutorials/chargemanagement) beschrieben.

:::

Mit dem Lastmanagement ist es möglich, einen verfügbaren Gesamt-Ladestrom zwischen bis zu 64 WARP Chargern aufzuteilen. Hierbei wird ein [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) als
Lastmanager konfiguriert, der die weiteren bis zu 63 Wallboxen (WARP Energy Manager: 64 Wallboxen) im Verbund steuert und ihnen Ladeströme zuweist.

![image](/img/webinterface/energy_management/warp-loadmanagement.jpeg)

Auf der Seite des Lastmanagement kann ein ***Automatischer minimaler Ladestrom*** aktiviert werden: Der Typ2 Ladestandard definiert als minimalen Ladestrom 6A. Aber nicht alle unterstützen diesen Ladestrom je nach Lademodus (1 phasig/3 phasig).
Zum Teil muss ein etwas höherer minimaler Ladestrom gewählt werden.

## Dynamisches Lastmanagement

Damit das dynamische Lastmanagement verwendet werden kann, muss zunächst ein [Stromzähler](/docs/webinterface/energy_management/energy_meters) hinzugefügt
werden, der die Phasenströme am Hausanschluss messen kann. Dieser kann, sofern gewünscht, auch für ein [PV-Überschussladen](/tutorials/pv_excess_charging.md) verwendet werden, das dynamische Lastmanagement
kann aber auch ohne PV-Anlage verwendet werden. Dieser Stromzähler muss vorher angelegt werden.

Für das dynamische Lastmanagement sind dann folgende Einstellungen notwendig:

* **Stromzähler***: Stromzähler auf dem das dynamische Lastmanagement regelt.
* ***Maximaler Strom am Netzanschluss***: Maximal zulässiger Phasenstrom am Netzanschluss. Dieser ist typischerweise der Nennwert der Absicherung. Das dynamische Lastmanagment stellt sicher, dass dieser Wert nicht uberschritten wird.
* ***Strombedarf des größten Eizelverbrauchers***: Zu erwartende Stromverbrauch des größten Verbrauchers. Dieser kann beispielsweise ein Durchlauferhitzer oder eine Wärmepumpe sein, mindestens aber 16 Ampere aus einer Schuko-Dose. Der Wert gibt den größten zu erwartenden
plötzlichen Sprung des Strombezugs am Zähler an, den das dynamische Lastmanagement kurzfristig (in unter 30 Sekunden) kompensieren können muss.
* ***Zusätzliche Sicherheitsmarge***: Zusätzliche prozentuale Sicherheitsmarge, die vom dynamischen Lastmanagement einkalkuliert wird.
