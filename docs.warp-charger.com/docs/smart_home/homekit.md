---
sidebar_position: 3
---

# HomeKit

Dein [WARP Charger](@current-charger/introduction) kann mit HomeKit über [Homebridge](https://homebridge.io) verbunden werden.

Dafür wird das Plugin [homebridge-warp-charger](https://www.npmjs.com/package/homebridge-warp-charger?activeTab=readme) verwendet, das über die HTTP-API mit dem WARP Charger kommuniziert.

Da HomeKit offiziell keine Wallboxen als Gerätetyp unterstützt, muss hier mit Workarounds gearbeitet werden, um die Daten der Wallbox bereitzustellen.

## Einrichten in Homebridge

Es wird angenommen, dass Homebridge bereits nach einer der [offiziellen Anleitungen](https://github.com/homebridge/homebridge/wiki/) installiert ist.

Zuerst suchst du nach dem Plugin "homebridge-warp-charger" und installierst es.

![Plugin search](/img/smart_home/homekit/search_plugin.png)

Anschließend wird der WARP Charger in Homebridge konfiguriert.

![Plugin configure](/img/smart_home/homekit/config_device.png)

Wenn die Verbindung erfolgreich ist, erscheinen unter "Accessories" mehrere Einträge, die zu deinem WARP Charger gehören. Diese können dort weiter konfiguriert und in Homebridge zugewiesen werden.

Standardmäßig aktualisiert das Plugin seine Daten im 60 Sekunden intervall.
Diese Frequenz kann mit der "Poll Interval" funktion angepasst werden.