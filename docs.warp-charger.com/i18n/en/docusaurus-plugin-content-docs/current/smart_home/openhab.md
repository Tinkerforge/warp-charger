---
sidebar_position: 7
---

# OpenHAB

## Introduction

Your [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md) is compatible with [OpenHAB](https://www.openhab.org).
OpenHAB is an open-source software solution for home automation that connects components from various manufacturers in a vendor- and protocol-neutral way on a single platform.

[MQTT](/docs/interfaces/mqtt_http/introduction) can be used to connect WARP devices. 
Since OpenHAB supports the same discovery mechanism as [Home Assistant](/smart_home/home_assistant.md), seamless integration is possible.

## Integration via MQTT

### OpenHAB Configuration
We assume that you have already installed OpenHAB. Additionally, you need an MQTT broker, as OpenHAB does not include a broker. We recommend [Mosquitto](https://mosquitto.org).

After the initial setup, the necessary bindings must be installed. 
We need the MQTT Binding and the Home Assistant Binding.

![MQTT Bindings](/img/smart_home/openhab/binding_install.png)

After installation, we only need to configure MQTT.

To do this, go to *Settings &rarr; Things &rarr; "+" &rarr; MQTT Binding &rarr; MQTT Broker*.
The broker's address is entered there. 
If a username or password is set on the broker, or if MQTTS (MQTT over TLS) is to be used, this can be configured in the advanced settings. 
It is also important that discovery is enabled in the advanced settings.

### WARP Charger/WARP Energy Manager Configuration

The WARP Charger/WARP Energy Manager is configured as described in [MQTT/HTTP API](/interfaces/mqtt_http/introduction.md). 
The address of the configured MQTT broker is entered as the broker hostname. 
The discovery mode is set to "Home Assistant" and the topic prefix to "homeassistant".

## Integration in OpenHAB

After both sides are configured, the WARP device should appear in *Settings &rarr; Things &rarr; Inbox*. This can take up to fifteen minutes.
To force a quick discovery, you can first restart the WARP device and, if that doesn't help, the OpenHAB server. 

The discovered devices are added from the Inbox as a Thing.

Finally, we add the devices to the Model: *Settings &rarr; Model*. 
Select *Create Equipment from Thing* and choose the WARP device.

The description of the data points and under what circumstances they are available can be found in the [Home Assistant documentation](/smart_home/home_assistant.md#mqtt-sensorwerte-in-home-assistant-via-autodiscovery).

