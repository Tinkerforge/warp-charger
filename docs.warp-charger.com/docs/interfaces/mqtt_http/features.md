---
sidebar_position: 3
---

# Features

WARP Charger und Energy Manager melden die jeweils unterstützten Features auf dem Topic [`info/features`](api_reference/info#info_features). Mithilfe der Features ist es möglich, dass eine Anwendung die API so verwendet, dass sie mit allen Versionen und Varianten des WARP Chargers kompatibel ist. Feature-Voraussetzungen sind an API-Topics in der Referenz vermerkt. Folgende Features können angeboten werden:

## `evse` Ladecontroller

Ein Ladecontroller steht zur Verfügung. Dieses Feature sollte bei allen WARP Chargern, deren Hardware funktionsfähig ist, vorhanden sein.

## `cp_disconnect` Control Pilot Disconnect

Der Ladecontroller kann das Control Pilot-Signal unterbrechen.

## `phase_switch` Phasenwechsel

Hardware und Konfiguration erlauben eine manuelle Phasenumschaltung mit der API [`power_manager/external_control_update`](api_reference/power_manager#power_manager_external_control_update).

## `button_configuration` Button-Konfiguration

Das Verhalten des Tasters an der Front der Wallbox kann umkonfiguriert werden. Bei WARP1 ist das nicht möglich, da der Taster und der Schlüsselschalter nicht voneinander unterschieden werden können.

## `ethernet` Ethernet

Es ist ein ESP Ethernet Brick verbaut. Eine LAN-Verbindung ist möglich.

## `meters` Stromzähler

Von mindestens einem Stromzähler konnten erfolgreich Werte gelesen werden.

## `nfc` NFC-Bricklet

Ein NFC-Bricklet wurde gefunden. Freischaltung per NFC ist möglich.

## `rtc` Real Time Clock

Ein RTC-Bricklet oder der RTC-Chip einer WARP3 oder eines Energy Managers wurde gefunden. Die Systemzeit wird auch ohne Netzwerk-Zeitsynchronisierung über Neustarts hinweg erhalten.

## `meter` (veraltete API) Stromzähler

Ein Stromzähler und Hardware zum Auslesen desselben über RS485 ist verfügbar. Dieses Feature wird erst gesetzt, wenn ein Stromzähler mindestens einmal erfolgreich über Modbus ausgelesen wurde.

## `meter_phases` (veraltete API) Stromzähler misst phasenweise

Der verbaute Stromzähler kann Energie und weitere Messwerte einzelner Phasen messen.

## `meter_all_values` (veraltete API) Stromzähler misst weitere Werte

Der verbaute Stromzähler kann weitere Messwerte auslesen.
