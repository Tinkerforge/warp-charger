---
sidebar_position: 4
---

# LAN-Verbindung

:::note

Es gibt ein Tutorial, welches auch das Einbinden von einem [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) in ein Netzwerk behandelt: [Erste Schritte](/docs/tutorials/first_steps)

:::

![image](/img/webinterface/network/wem2-network_lan.jpeg)

In den meisten Fällen wird eine LAN-Verbindung automatisch
hergestellt, falls ein Kabel eingesteckt ist (IP-Adresse wird
per DHCP bezogen). Es ist aber auch möglich, eine statische IP-Konfiguration einzutragen, oder, falls gewünscht, die LAN-Verbindung komplett zu deaktivieren.
Bei einer erfolgreichen Verbindung sollte die Wallbox jetzt im LAN unter http://[konfigurierter_hostname], z.B. http://warp3-ABC erreichbar sein.

:::note

Die LAN- und WLAN-Verbindung sollten nicht gleichzeitig zum selben Netzwerk bzw. IP-Bereich verbunden sein, da es sonst zu Verbindungsproblemen kommen kann.

:::
