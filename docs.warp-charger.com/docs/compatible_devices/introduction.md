---
sidebar_position: 1
---

# Einführung

[WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) können direkt auf die Daten von
Stromzähler zugreifen.

Dies sind Daten zur Erzeugung von PV-Wechselrichtern
aber auch Daten von Batteriespeicher und Daten
vom Netzanschluss (auch Hausanschluss genannt). Die ausgelesenen Stromzählerwerte
können von einem WARP Charger oder Energy Manager
für Regelungen (PV-Überschuss, dyn. Lastmanagement) verwendet
bzw. zur Auswertung aufgezeichnet werden.

Für ein [PV-Überschlussladen](/tutorials/pv_excess_charging.md) oder
ein [dynamisches Lastmanagement](/tutorials/chargemanagement.md), muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen
Stromzähler am **Netzanschluss (Netz)** haben, da nur dort der eigentliche
PV-Überschuss bzw. die aktuellen Phasenströme ermittelt werden können.

Meistens ist bereits ein Zähler am Netzanschluss vorhanden. Wir
unterstützen verschiedene Möglichkeiten um auf diese Zähler zuzugreifen.
Ist ein Stromzähler direkt am PV-Wechselrichter angeschlossen, dann kann
oftmals über den Wechselrichter auf die Zählerdaten zugegriffen werden.
