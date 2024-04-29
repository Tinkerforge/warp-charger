---
sidebar_position: 9
---

# Kompatible Stromzähler

Um ein [PV-Überschlussladen](https://warp-charger.com/pv-ueberschussladen/) zu ermöglichen, musss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen Stromzähler am Hausanschluss haben,
da nur dort der eigentliche PV-Überschuss ermittelt werden kann.

Meistens ist bereits ein Zähler am Hausanschluss vorhanden. Wir unterstützen unterschiedliche Möglichkeiten
um auf diese bereits vorhandenen Zähler zuzugreifen. Die folgende Liste besteht aus Protokollen die wir
implementiert haben und Geräten die wir bereits erfolgreich getestet haben.

## Sunspec

[SunSpec](https://sunspec.org/sunspec-modbus-specifications/) ist ein offener Kommunikationsstandard, der gemeinsame Parameter und Einstellungen für die Überwachung und Steuerung von dezentralen Energieerzeugungsanlagen festlegt.

Ist ein Wechselrichter oder Energiemanager vorhanden der Zugriff auf einen Stromzähler am Hausanschluss hat, kann dieser oft über SunSpec per Modbus/TCP ausgelesen werden. Es gibt auch Stromzähler welche direkt SunSpec unterstützen.

Generell sollte jedes SunSpec-kompatible Gerät ausgelesen werden können, wir führen hier allerdings nur getestet Geräte auf.

### elgris
* Smart Meter LAN 2.0

### Fronius
* Symo 8.2-3-M
* Symo 12.5-3

### KOSTAL
* Smart Energy Meter (KSEM) G2

### SMA
* Sunny Boy 2.5
* Sunny Boy 3.6

Wenn du einen Wechselrichter oder Energiemanager mit SunSpec-Unterstützung hast der bei dir funktionert und noch nicht in der Liste ist, schicke uns doch eine Email an [info@tinkerforge.com](mailto://info@tinkerforge.com) damit wir die Liste aktualisieren können.

## SMA (Speedwire)
* SMA Energy Meter 2.0
* Sunny Home Manager

## Sungrow (Modbus/TCP)

TODO

## Shelly (HTTP)

Comming Soon

## Angeschlossener Stromzähler (Modbus/RTU)

Der WARP Energy Manager kann Stromzähler per Modbus/RTU auslesen. Dies ist vor allem interessant wenn noch kein
Zähler am Hausanschluss vorhanden ist. In dem Fall kann ein WARP Energy Manager sowie einer der folgenden
kompatiblen Modbus/RTU-Stromzähler gesetzt werden:

* Eastron SDM72V2
* Eastron SDM630
* Eastron SDM630MCTV2 (Wandler-Stromzähler)
* Eltako DSZ15DZMOD
* YTL DEM4A

## Push-API (HTTP/MQTT)

Siehe [MQTT und HTTP API -> API-Referenz -> meters](./mqtt_http/api_referenz/meters)