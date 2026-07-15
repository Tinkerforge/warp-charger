---
sidebar_position: 3
---

# HomeKit


Your [WARP Charger](@current-charger/introduction) can be connected to HomeKit via [Homebridge](https://homebridge.io).

We use the plugin [homebridge-warp-charger](https://www.npmjs.com/package/homebridge-warp-charger?activeTab=readme), which communicates with the WARP Charger via the HTTP API.

Because HomeKit does not officially support EV chargers as a device type, the integration uses workarounds to expose the charger data.

## Setup in Homebridge

This guide assumes you have Homebridge installed following one of the [official guides](https://github.com/homebridge/homebridge/wiki/).

First search for and install the plugin "homebridge-warp-charger".

![Plugin search](/img/smart_home/homekit/search_plugin.png)

Then configure the WARP Charger in Homebridge.

![Plugin configure](/img/smart_home/homekit/config_device.png)

If the connection is successful, multiple accessories belonging to the WARP Charger will appear under Accessories. You can then assign and configure them in Homebridge.

By default the plugin reads the API in 60 second intervals. 
This can be configured with the Poll Interval option

