---
sidebar_position: 8
---

# Victron

## Integration von WARP Chargern in Venus OS Geräte

Victron nutzt auf den Venus OS Geräten (z.B. dem Cerbo GX) dbus. Über
dbus können auch andere Geräte angebunden werden. Victron selbst bietet
eine Integration von Wallboxen in Venus OS. Mit dem Projekt

[dbus-warp-charger](https://github.com/Tinkerforge/dbus-warp-charger)

können WARP Charger in Venus OS integriert werden. Venus OS steuert
dann den WARP Charger. Allerdings bietet
Victron keine Unterstützung für eine automatische Phasenumschaltung,
so dass diese nicht unterstützt wird.

Für eigene Integrationen bieten sich ansonsten die folgenden Schnittstellen
an:

* [MQTT/HTTP API](/docs/interfaces/mqtt_http/introduction)
* [Modbus/TCP](/docs/interfaces/modbus/introduction)


## Einbinden von Victron Geräten in WARP Geräte

Alternativ ist es auch möglich Victron Geräte in [WARP Chargern](/docs/warp_charger/introduction) oder dem
[WARP Energy Manager](/docs/warp_energy_manager/introduction) einzubinden.

Hierbei fragt der WARP Charger oder WARP Energy Manager die Daten bei den Victron
Geräten ab. Die Steuerung bleib bei dem WARP Gerät. Alle Funktionen bleiben somit erhalten. So ist zum Beispiel
eine automatische Phasenumschaltung beim [PV-Überschussladen](/docs/tutorials/pv_excess_charging)
oder auch ein [dynamisches Lastmanagement](/docs/tutorials/chargemanagement) möglich.

Siehe dazu:
 * [Einführung kompatible Geräte](/docs/compatible_devices/introduction)
 * [Kompatible Victron Geräte](/docs/compatible_devices/devices#victron-energy)
