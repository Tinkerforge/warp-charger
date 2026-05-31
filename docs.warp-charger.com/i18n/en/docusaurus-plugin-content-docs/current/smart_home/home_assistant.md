---
sidebar_position: 2
---

# Home Assistant

## Introduction

Your [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md) is compatible with [Home Assistant](https://www.home-assistant.io).
Home Assistant is an open-source home automation solution with broad device support.

For connecting WARP devices, Modbus and MQTT can be used. In this guide, we will use MQTT.
Furthermore, it is assumed that Home Assistant is already installed and operational.
Instructions for this can be found on the [official website](https://www.home-assistant.io/installation/).

## MQTT

### Setting up MQTT in Home Assistant

First, MQTT must be activated in Home Assistant.
Go to **Settings** -> **Devices & Services** -> **Add Integration** in the web interface.
In the window that opens, search for "MQTT" and select it.
Various MQTT integrations are available.
We simply need MQTT:

![MQTT Integration Selection](/img/smart_home/homeassistant/mqtt_selection.png)

You will then be asked about the MQTT broker.
If you don't want to use your own MQTT broker, the easiest way is to use the official MQTT broker app.
This is installed automatically.

![MQTT Broker Selection](/img/smart_home/homeassistant/mqtt_broker_select.png)

:::warning
If Home Assistant was installed as a Docker container, adding apps via the web interface is not possible.
The MQTT broker must be installed and configured manually.
Installation in a Docker container is therefore only recommended for advanced users.
:::
![MQTT Broker install success](/img/smart_home/homeassistant/mqtt_broker_install_success.png)

Finally, go to **Settings** -> **Apps** -> **Mosquitto broker** -> **Configuration** and create a login there.
Here you can also find the ports for the various MQTT protocols.

Don't forget to save!

![MQTT Broker Login creation](/img/smart_home/homeassistant/mqtt_broker_login.png)

### Setting up MQTT in WARP Charger/WARP Energy Manager

The MQTT broker is configured in the MQTT settings according to the [Introduction](/interfaces/mqtt_http/introduction.md).

For automatic integration into Home Assistant, we recommend activating the Discovery mode and setting it to "Home Assistant".
![HA Autodiscovery](/img/smart_home/homeassistant/mqtt_discovery.png)
By default, "homeassistant" is the topic on which Home Assistant listens for Discovery messages.
The Discovery messages are sent every 15 minutes. It can therefore take up to fifteen minutes for the devices to appear in Home Assistant.

### MQTT Sensor Values in Home Assistant

Autodiscovery adds various sensors and controls automatically. Which ones are added depends on whether the device is a WARP Charger or WARP Energy Manager.
Some values are added as disabled entities.

![Disabled Entities](/img/smart_home/homeassistant/ha_disabled_entities.png)

These must be manually enabled when the respective function is activated in the WARP Charger or WARP Energy Manager.
There you can find, for example, the energy meter values for the Energy Manager and the solar forecasts.

:::note
The localization of the entities depends on the language of the web interface of the WARP Charger/WARP Energy Manager.
:::

## Modbus/TCP
:::note
Coming soon...
:::

* [Modbus/TCP](/interfaces/modbus/introduction.md)

