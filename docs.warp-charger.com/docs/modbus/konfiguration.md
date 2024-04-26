---
sidebar_position: 1
---

# Konfiguration

Das Modbus-Protokoll ist ein Kommunikationsprotokoll welches es in
verschienden Varianten gibt.

Die WARP Charger unterstützen [https://de.wikipedia.org/wiki/Modbus](Modbus/TCP)
und agieren dabei als Modbus-Server. Im Auslieferungszustand ist Modbus deaktiviert
Unter dem Menüpunkt `Schnittstellen` -> `Modbus/TCP` kann Modbus aktiviert und
konfiguriert werden.

![image](/img/modbus/modbus_configuration.png)

Es ist möglich zwischen `Deaktiviert`, `Nur Lesezugriff` und `Lese-/Schreibzugriff`
zu wählen:

![image](/img/modbus/modbus_access.png)

Zusätzlich kann der Modbus/TCP-Port eingestellt werden und eine Registertablle
ausgewählt werden:

![image](/img/modbus/modbus_table.png)

Aktuell wird die [WARP Charger Registertablle](registertabelle) sowie
die Registertabellen von `Bender CC613` und der `Keba C-Series` unterstützt.

Wählt man eine der Fremd-Registertabellen simuliert der WARP Charger die
entsprechenden Register-Zuordnungen von Bender und Keba. So kann ein WARP
Charger in eine Heimautomatisierung oder einen Energiemanager o.ä. eingebunden
wenn diese Unterstützung für eine der beiden Fremd-Registertabellen haben.