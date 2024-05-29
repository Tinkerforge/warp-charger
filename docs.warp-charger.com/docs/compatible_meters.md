---
sidebar_position: 9
---

import { SortableDataTable, SortableDataButton } from "@site/src/components/SortableDataTable";
import { columns, meters, moduleTests } from "./meters.table";

# Kompatible Stromzähler

WARP Charger und der WARP Energy Manager können direkt auf die Daten von
Stromzähler zugreifen.

Dies sind Daten zur Erzeugung von PV-Wechselrichtern 
aber auch Daten von Batteriespeicher und Daten
vom Stromnetz- bzw. Hausanschluss. Die ausgelesenen Stromzählerwerte 
können von einem WARP Charger oder Energy Manager 
für Regelungen (PV-Überschuss, dyn. Lastmanagement) verwendet 
bzw. zur Auswertung aufgezeichnet werden.

Für ein [PV-Überschlussladen](/warp_charger/pv_excess_charging.md) oder
ein [dynamisches Lastmanagement](warp_charger/chargemanagement.md), muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen 
Stromzähler am **Hausanschluss (Netz)** haben, da nur dort der eigentliche 
PV-Überschuss bzw. die aktuellen Phasenströme ermittelt werden können.

Meistens ist bereits ein Zähler am Hausanschluss vorhanden. Wir 
unterstützen verschiedene Möglichkeiten um auf diese Zähler zuzugreifen. 
Ist ein Stromzähler direkt am PV-Wechselrichter angeschlossen, dann kann
oftmals über den Wechselrichter auf die Zählerdaten zugegriffen werden. 

Folgende Möglichkeiten gibt es auf Zählerdaten vom Netzanschluss, 
PV-Wechselrichter oder der Batterie zuzugreifen:

## SunSpec

[SunSpec](https://sunspec.org/sunspec-modbus-specifications/) ist ein 
Kommunikationsstandard für PV-Wechselrichter.
WARP Charger und der WARP Energy Manager können SunSpec Geräte mittels 
LAN oder WLAN direkt auslesen.

Ist ein Wechselrichter oder Energiemanager vorhanden, 
der **Zugriff auf einen Stromzähler am Hausanschluss hat**, kann dieser 
oft über SunSpec über das Netzwerk ausgelesen werden. 

SunSpec bietet den Vorteil, dass kompatible Geräte direkt vom WARP 
Charger und WARP Energy Manager erkannt und ausgelesen werden können.
Bei der Konfiguration muss nur SunSpec als Klasse ausgewählt und die IP
Adresse des Geräts ausgewählt werden. Das System listet alle erkannten 
Geräte auf, so dass diese einfach zugeordnet werden können.

## Modbus/TCP

Nicht alle Geräte unterstützen SunSpec. Wir arbeiten daran die 
wichtigsten Geräte, welche nicht per SunSpec nutzbar sind, dennoch zu 
unterstützen. Der Zugriff mittels Modbus/TCP über LAN oder 
WLAN ist eine andere weit verbreitete Möglichkeit und wird von vielen
Geräten unterstützt.

Bei Modbus/TCP müssen Informationen bereitgestellt werden, welche 
Register gelesen und wie die Werte interpretiert werden müssen. Hierzu
gibt es zwei Möglichkeiten:


### Vordefinierte Registertabelle

Für uns bekannte Geräte haben wir bereits Registertabellen vordefiniert.
Sind diese vorhanden, muss nur die entsprechende Voreinstellung 
ausgewählt werden und die bereitgestellten Zähler zugeordnet werden.


### Benutzerdefinierte Registertabelle

Wird von uns noch keine gerätespezifische Registertabelle zur Verfügung 
gestellt, so kann diese auch selbst definiert werden. In den 
benutzerdefinierten Einstellungen muss nur der Adressmodus festgelegt 
und anschließend die gewünschten Register angelegt werden. Es können der
Typ des Registers, ein Offset (Verschiebung), ein Skalierfaktor (Float)
und die Zuordnung auf einen Zählerwert (z.B. Wirk-Leistung L1) definiert
werden.


## SMA Speedwire

SMA Geräte können über die SMA Speedwire Schnittstelle ausgelesen werden.

## API

Die MQTT und HTTP WARP Push API
kann genutzt werden um von extern Zählerdaten dem WARP Charger oder
dem WARP Energy Manager mitzuteilen. Siehe 
[API Referenz - Meters](/docs/mqtt_http/api_reference/meters).

## WARP Energy Manager - Modbus/RTU (RS485)

Der WARP Energy Manager kann Stromzähler direkt per Modbus/RTU (RS485) 
auslesen. Dies ist vor allem interessant wenn noch kein Zähler am 
Hausanschluss vorhanden ist. In dem Fall kann ein WARP Energy Manager 
sowie ein kompatibler Modbus/RTU-Stromzähler gesetzt werden. Diese 
Zähler sind auch in der Liste mit aufgeführt.

## Bekannte kompatible Geräte

Die folgende Liste führt Geräte auf, die erfolgreich getestet wurden. 

:::note

Wenn du ein Gerät besitzt, das du erfolgreich 
getestest hast und dieses noch nicht in der Liste aufgeführt ist, 
schicke uns doch eine Email an 
[info@tinkerforge.com](mailto://info@tinkerforge.com) damit wir die 
Liste erweitern können.

Solltest du einen Stromzähler/PV-Wechselrichter besitzen, den du mittels
der generellen Modbus/TCP Schnittstelle eingebunden hast, so melde dich 
gerne im Forum auf 
[Tinkerunity](https://www.tinkerunity.org/forum/13-warp-charger/).
Wir schauen dann, dass wir eine herstellerspezifische Lösung 
implementieren.

:::

<SortableDataTable
  columns={columns}
  data={ meters }
/>

<SortableDataButton
  text="Füge neuen Stromzähler hinzu"
  editUrl="https://github.com/Tinkerforge/warp-charger/blob/master/docs.warp-charger.com/docs/meters.table.js"
/>
