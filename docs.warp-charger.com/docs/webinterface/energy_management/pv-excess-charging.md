---
sidebar_position: 4
---

# PV-Überschussladen

:::note

Die Konfiguration eines PV-Überschussladens ist auch im Tutorial [Photovoltaik-Überschussladen](/docs/tutorials/pv_excess_charging) beschrieben.

:::

Beim Photovoltaik-Überschussladen ist das Ziel, die nicht selbst genutzte Leistung einer Photovoltaikanlage in ein Elektrofahrzeug zu laden, anstatt sie in das Stromnetz
einzuspeisen. Die Maximierung der Eigenstromnutzung steht hier im Vordergrund. Diese Funktion kann von einem [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) ausgeführt werden.

![image](/img/webinterface/energy_management/warp-pv_excess_charging.jpeg)

Folgende Einstellungen können auf der Seite vorgenommen werden:
 * **Überschussladen aktiviert**: Schaltet den PV-Überschussregler ein oder aus.
 * **Standardlademodus**: Der Lademodus, der bei einem Neustart des WARP3 Chargers verwendet wird.
 * **Stromzähler**: Der Stromzähler, mit dem der PV-Überschuss gemessen wird. Dieser Stromzähler muss unter [Stromzähler](/docs/webinterface/energy_management/energy_meters) angelegt werden.
 * **Min+PV: Mindestladeleistung**: Legt fest, welche Leistung im *Min+PV*-Lademodus aus dem Netz bezogen werden darf.
 * **Regelverhalten**: Legt fest, auf welchen Netzbezug geregelt werden soll, damit beispielsweise ein Batteriespeicher höher oder niedriger priorisiert wird als das Laden von Fahrzeugen.
 * **Wolkenfilter**: Stellt die Trägheit der Regelung ein. Bei wechselnd bewölktem Wetter ist es sinnvoll, dass die Regelung träge reagiert, damit kurze Schwankungen der PV-Leistung geglättet werden.

Ist ein Batteriespeicher vorhanden regelt dieser gegen die PV-Überschussregelung an. Wenn der Batteriespeicher über einen [Stromzähler](/docs/webinterface/energy_management/energy_meters) ausgelesen werden kann, kann der Speicher direkt von der Regelung beachtet werden.
Dazu müssen folgende Einstellungen vorgenommen werden:
 * **Stromzähler**: Der Stromzähler, der dem Batteriespeicher zugeordnet ist
 * **Speicherpriorität**: Hier kann konfiguriert werden ob Wallboxen oder der Speicher höher priorisiert werden.
 * **Energieflussrichtung des Speichers**: Manche Speicher liefern je nach Konfiguration abweichende Vorzeichen beim Laden und dem Entladen. Das verhalten kann hier konfiguriert werden.
 * **Bezugs- und Einspeisetoleranz**: Der Regelwert auf dem geregelt wird.
