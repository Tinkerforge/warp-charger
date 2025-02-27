---
sidebar_position: 1
---

# Stromzähler

:::note

Stromzähler können bei WARP Chargern und beim WARP Energy Manager konfiguriert werden.

:::

![image](/img/webinterface/energy_management/wem2-energy_meters.jpeg)

Auf dieser Seite kann die Kommunikation mit Stromzählern konfiguriert werden. Da der WARP3 Charger Pro uber einen eingebauten Stromzähler verfügt, ist
dieser bei allen WARP3 Chargern Pro vorkonfiguriert. Beim WARP3 Charger Smart kann dieser Zähler entfernt werden.

Im Graph wird die gemessene Leistung aller konfigurierten Stromzähler angezeigt, entweder als Verlauf über
die letzten 48h oder als Live-Ansicht. Die Ansicht jedes Zählers kann aufgeklappt werden, um weitere Statistiken
und Messwerte anzuzeigen. Dazu muss auf den jeweiligen blauen Pfeil geklickt werden.

Es können insgesamt fünf Stromzähler konfiguriert werden. Dazu zählen Stromzähler, Wechselrichter oder Batterien, die mittels SunSpec-, Modbus/TCP-oder SMA Speedwire-Schnittstelle ausgelesen werden können.
An dem WARP Energy Manager können mittels RS485 kompatible Stromzähler angeschlossen und ausgelesen werden. Zusätzlich können virtuelle Stromzähler anegelt werden, die über 
die [API](/docs/interfaces/mqtt_http/introduction) befüllt werden können.

Die Liste der kompatiblen Geräte wird laufend erweitert. Sie ist unter [kompatible Geräte](/docs/compatible_devices/introduction) zu finden.



Für das [Photovoltaik-Überschussladen](/docs/tutorials/pv_excess_charging) ist es notwendig, einen Stromzähler
anzulegen, der den Leistungs-Überschuss (typischerweise am Hausanschluss) misst. Soll ein [Dynamisches Lastmanagement](/docs/tutorials/chargemanagement) realisiert werden ist ebenfalls ein Stromzähler am Netzanschluss notwendig. Dieser muss zusätzlich zu der Gesamtleistung die Phasenströme messen können.

SunSpec-(mittels Modbus TCP)-Geräte können nach Angabe des Hosts automatisch erkannt werden. Abhängig von den Fähigkeiten des SunSpec-Geräts werden verschiedene Messwerte abgerufen. Es können auch Modbus-TCP-Geräte ausgelesen werden, die SunSpec nicht unterstutzen. Wir bieten vordefinierte
Registertabellen fur bestimmte Geräte. Von uns nicht unterstützte Modbus-TCP-Geräte können über eine benutzerdefinierte Registertabelle ausgelesen werden.
