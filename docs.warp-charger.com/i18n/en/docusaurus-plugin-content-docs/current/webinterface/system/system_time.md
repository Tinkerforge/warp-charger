---
sidebar_position: 4
---

# System Time

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc1', 'wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />


![image](/img/webinterface/system/warp-system_time.jpeg)

To provide the current time for recording the energy balance and the event log, the [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md) can synchronize it via NTP
over a network connection. On this page, NTP can be enabled or disabled and the time zone in which the device is located can be configured.
Additionally, it is possible to use a time server provided by the router via DHCP in addition to the configured time server. However, this only works if no static IP configuration is used in the network configuration.
