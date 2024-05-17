---
sidebar_position: 9
---

import { SortableDataTable, SortableDataButton } from "@site/src/components/SortableDataTable";
import { columns, meters, moduleTests } from "./meters.table";

# Kompatible Stromzähler

Für ein [PV-Überschlussladen](/warp_charger/pv_excess_charging.md) oder
ein [dynamisches Lastmanagement](warp_charger/chargemanagement.md), muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen 
Stromzähler am Hausanschluss haben, da nur dort der eigentliche 
PV-Überschuss bzw. der aktuelle Phasenstrom ermittelt werden kann.

Meistens ist bereits ein Zähler am Hausanschluss vorhanden. Wir 
unterstützen verschiedene Möglichkeiten um auf diese bereits vorhandenen 
Zähler zuzugreifen. Oftmals kann über einen PV-Wechselrichter auf 
Zählerwerte zugegriffen werden. Die folgende Liste führt Geräte auf, 
die wir implementiert und bereits erfolgreich getestet haben. 

Generell unterstützen wir
[SunSpec](https://sunspec.org/sunspec-modbus-specifications/) per 
Modbus/TCP als offenen Kommunikationsstandard für PV-Wechselrichter.
Ist ein Wechselrichter oder Energiemanager vorhanden, der Zugriff auf 
einen Stromzähler am Hausanschluss hat, kann dieser oft über 
SunSpec per Modbus/TCP ausgelesen werden. 
Es gibt auch Stromzähler, die direkt SunSpec unterstützen.
Generell sollte jedes SunSpec-kompatible Gerät ausgelesen werden können,
wir führen hier allerdings nur getestet Geräte auf.

Der WARP Energy Manager kann Stromzähler per Modbus/RTU auslesen. Dies 
ist vor allem interessant wenn noch kein Zähler am Hausanschluss 
vorhanden ist. In dem Fall kann ein WARP Energy Manager sowie ein
kompatibler Modbus/RTU-Stromzähler gesetzt werden. Diese Zähler sind 
auch in der Liste mit aufgeführt.

Zusätzlich haben wir begonnen herstellerspezifische Protokolle zu 
implementieren um auch die nicht ganz so offenen Geräte zu unterstützen.

:::note

Wenn du einen Wechselrichter oder Energiemanager mit 
SunSpec-Unterstützung besitzt, den du erfolgreich getestest hast
und dieser noch nicht in der Liste ist, schicke uns doch eine Email an 
[info@tinkerforge.com](mailto://info@tinkerforge.com) damit wir die 
Liste aktualisieren können.

Solltest du einen Stromzähler/PV-Wechselrichter besitzen, den wir noch 
nicht unterstützen, so melde dich gerne im Forum auf 
[Tinkerunity](https://www.tinkerunity.org/forum/13-warp-charger/).
Wir schauen dann, ob wir eine herstellerspezifische Lösung 
implementieren können.

:::

<SortableDataTable
  columns={columns}
  data={ meters }
/>

<SortableDataButton
  text="Füge neuen Stromzähler hinzu"
  editUrl="https://github.com/Tinkerforge/warp-charger/blob/master/docs.warp-charger.com/docs/meters.table.js"
/>
