---
sidebar_position: 3
---

# Automatisierung

:::note

Automatisierungsregeln gibt es sowohl bei den WARP Chargern als auch beim WARP Energy Manager. Die konfigurierbaren Bedingungen und Aktionen unterscheiden sich zwischen unterschiedlichen Geräten.

:::

Auf dieser Seite können Regeln definiert werden, die automatisch
ausgeführt werden sollen. Jede Regel besteht aus einer Bedingung
(z.B.: *Eingang 1 geschlossen*) und einer Aktion
(z.B.: *Schalte SG-Ready Ausgang 1 auf geschlossen*).
Es können bis zu 14 Regeln angelegt werden.

## Beispiel-Automatisierungen WARP Energy Manager

![image](/img/webinterface/energy_manager/wem2-automation.jpeg)

In diesem Beispiel wurden drei unabhängige Regeln definiert:

* Täglich um 06:43 Uhr, wechsle Lademodus auf PV.
* Wenn MQTT-Nachricht "Current" an Topic "/Control/Test" empfangen wird, begrenze den maximalen Gesamtstrom auf 16A
* Wenn Energie ins Stromnetz eingespeist wird, Relais 1 schalten.

Die ersten beiden Regeln setzen in ihrer Aktion Konfigurationen des Lastmanagement der vom Energy Manager gesteuerten Wallboxen und die dritte Regel schaltet als Aktion eines der im WARP Energy Manager verbauten Relais.

Beispiel-Screenshot des Modulfensters zum bearbeiten der ersten Regel:
![image](/img/webinterface/energy_manager/wem2-automation2.jpeg)


## Beispiel-Automatisierungen WARP Charger

![image](/img/webinterface/wallbox/warp-automation.png)

In diesem Beispiel wurden drei Regeln definiert:

* Wochentags um 07:00 Uhr, limitiere den erlaubten Ladestrom auf 0A.
* Wochentags um 16:00 Uhr, limitiere den erlaubten Ladestrom auf 32A.
* Wenn der Fronttaster gedrückt wird, limitere den erlaubten Ladestrom auf 32A.

Mit dieser Liste von Regeln wird eine Ladung Wochentags zwischen 07:00-16:00 nicht erlaubt (Regel 1 und 2), es ist allerdings möglich durch das Drücken des Fronttasters eine Ladung in diesem Zeitraum trotzdem freizuschalten (Regel 3).

Beispiel-Screenshot des Modulfensters zum bearbeiten der dritten Regel:
![image](/img/webinterface/wallbox/warp-automation-rule.png)
