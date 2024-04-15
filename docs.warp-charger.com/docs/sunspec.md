---
sidebar_position: 8
---

# SunSpec

[SunSpec](https://sunspec.org/sunspec-modbus-specifications/) ist ein offener Kommunikationsstandard, der gemeinsame Parameter und Einstellungen für die Überwachung und Steuerung von dezentralen Energieerzeugungsanlagen festlegt.

Ist ein Wechselrichter oder Energiemanager vorhanden der Zugriff auf einen Stromzähler am Hausanschluss hat, kann dieser oft über SunSpec ausgelesen werden. Es gibt auch Stromzähler welche direkt SunSpec unterstützen.

Der WARP Charger und der WARP Energy Manager können über SunSpec diese Stromzähler auslesen. So ist es möglich [PV-Überschlussladen](https://warp-charger.com/pv-ueberschussladen/) umzusetzen ohne das zusätzliche Hardware installiert werden muss!

Generell sollte jedes SunSpec-kompatible Gerät ausgelesen werden können. Mit der folgenden Liste von Wechselrichtern/Energiemanagern/Stromzählern haben wir PV-Überschussladen mit dem WARP Charger oder dem WARP Energy Manager bereits erfolgreich getestet:

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

Wenn du einen Wechselrichter oder Energiemanager mit SunSpec-Unterstützung hast der bei dir funktionert und noch nicht in der Liste ist, schicke uns doch eine Email an [info@tinkerforge.com](info@tinkerforge.com) damit wir die Liste aktualisieren können.