---
sidebar_position: 9
---

import { SortableDataTable, SortableDataButton } from "@site/src/components/SortableDataTable";
import { columns, meters, moduleTests } from "./meters.table";

# Kompatible Stromzähler

Um ein [PV-Überschlussladen](warp_charger/pv_excess_charging) zu ermöglichen, musss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen Stromzähler am Hausanschluss haben,
da nur dort der eigentliche PV-Überschuss ermittelt werden kann.

Meistens ist bereits ein Zähler am Hausanschluss vorhanden. Wir unterstützen unterschiedliche Möglichkeiten
um auf diese bereits vorhandenen Zähler zuzugreifen. Die folgende Liste besteht aus Protokollen die wir
implementiert haben und Geräten die wir bereits erfolgreich getestet haben.

[SunSpec](https://sunspec.org/sunspec-modbus-specifications/) ist ein offener Kommunikationsstandard, der gemeinsame Parameter und Einstellungen für die Überwachung und Steuerung von dezentralen Energieerzeugungsanlagen festlegt.

Ist ein Wechselrichter oder Energiemanager vorhanden der Zugriff auf einen Stromzähler am Hausanschluss hat, kann dieser oft über SunSpec per Modbus/TCP ausgelesen werden. Es gibt auch Stromzähler welche direkt SunSpec unterstützen.

Generell sollte jedes SunSpec-kompatible Gerät ausgelesen werden können, wir führen hier allerdings nur getestet Geräte auf.

Wenn du einen Wechselrichter oder Energiemanager mit SunSpec-Unterstützung hast der bei dir funktionert und noch nicht in der Liste ist, schicke uns doch eine Email an [info@tinkerforge.com](mailto://info@tinkerforge.com) damit wir die Liste aktualisieren können.

:::note

Der WARP Energy Manager kann Stromzähler per Modbus/RTU auslesen. Dies ist vor allem interessant wenn noch kein
Zähler am Hausanschluss vorhanden ist. In dem Fall kann ein WARP Energy Manager sowie ein kompatibler
Modbus/RTU-Stromzähler gesetzt werden. Diese Zähler sind auch in der Liste mit aufgeführt.

:::

<SortableDataTable
  columns={columns}
  data={ meters }
/>

<SortableDataButton
  text="Füge neuen Stromzähler hinzu"
  editUrl="https://github.com/Tinkerforge/warp-charger/blob/master/docs.warp-charger.com/docs/meters.table.js"
/>
