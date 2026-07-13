---
sidebar_position: 2
---

# Home Assistant

## Introduction

Your [WARP Charger](@current-charger/introduction) or [WARP Energy Manager](@current-wem/introduction) is compatible with [Home Assistant](https://www.home-assistant.io).
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
We need the simple MQTT integration:

![MQTT Integration Selection](/img/smart_home/homeassistant/mqtt_selection.png)

You will then be asked about the MQTT broker.
If you don't want to use your own MQTT broker, the easiest way is to use the official MQTT broker app.
This is installed automatically.

![MQTT Broker Selection](/img/smart_home/homeassistant/mqtt_broker_select.png)

:::warning
If Home Assistant was installed as a Docker container, adding apps via the web interface is not possible.
In this case, the MQTT broker must be installed and configured separately.
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

### MQTT Sensor Values in Home Assistant via Autodiscovery

Autodiscovery automatically adds various sensors and controls. Which ones are added depends on whether the device is a WARP Charger or WARP Energy Manager and which functions are activated (e.g. solar forecast).

Autodiscovery will remove discovered elements again should they no longer be available.

#### Automatically Added Entities
The following entities are provided via autodiscovery:

| Name | Type | Description | Available when |
|------|------|-------------|----------------|
| Charge status | Sensor | Current charge status of the charger | EVSE present (WARP Charger) |
| Current charge mode EVSE | Sensor | Shows the current charge mode of the EVSE as an enum | EVSE present (WARP Charger) |
| Charging current limit | Number | Maximum charging current in A (0–32 A), controllable | EVSE present (WARP Charger) |
| Allowed charging current | Sensor | Currently allowed charging current in A | EVSE present (WARP Charger) |
| Start charging | Button | Starts the charging process | EVSE present (WARP Charger) |
| Stop charging | Button | Stops the charging process | EVSE present (WARP Charger) |
| Charging cable connected | Binary Sensor | Indicates whether a charging cable is connected | EVSE present (WARP Charger) |
| Charger ready to charge | Binary Sensor | Indicates whether the charger is ready to charge | EVSE present (WARP Charger) |
| Charger charging | Binary Sensor | Indicates whether charging is currently in progress | EVSE present (WARP Charger) |
| Charger error | Binary Sensor | Indicates whether an error is present | EVSE present (WARP Charger) |
| Charger available | Binary Sensor | Indicates whether the charger is reachable | EVSE present (WARP Charger) |
| Front button pressed | Binary Sensor | Indicates whether the front button is pressed | EVSE present (WARP Charger) |
| Limited according to §14a EnWG | Sensor | Indicates whether a limitation according to §14a EnWG is active | §14a EnWG activated in the configuration |
| Active charge mode | Select | Select charge mode (Fast, Off, PV, Min + PV), controllable | PV excess charging or dynamic load management activated |
| Current charge mode | Sensor | Shows the currently active charge mode | PV excess charging or dynamic load management activated |
| Solar forecast tomorrow | Sensor | Forecasted PV yield for tomorrow in kWh | Solar forecast activated |
| Solar forecast today | Sensor | Forecasted PV yield for today in kWh | Solar forecast activated |
| Solar forecast from now | Sensor | Remaining forecasted PV yield for today in kWh | Solar forecast activated |
| Spot market price | Sensor | Current spot market electricity price in ct/kWh | Dynamic electricity prices activated |

Additionally, for each configured meter slot (meter 0 to N), the following measured values are provided, provided the respective measured value is supported by the meter:

| Name | Description | Unit |
|------|-------------|------|
| Voltage (L1-N) | Voltage of phase L1 against neutral | V |
| Voltage (L2-N) | Voltage of phase L2 against neutral | V |
| Voltage (L3-N) | Voltage of phase L3 against neutral | V |
| Current (consumption plus feed-in) (L1) | Current on phase L1 | A |
| Current (consumption plus feed-in) (L2) | Current on phase L2 | A |
| Current (consumption plus feed-in) (L3) | Current on phase L3 | A |
| Active power (consumption minus feed-in) (Σ L1, L2, L3) | Total active power | W |
| Active energy (consumption) (Σ L1, L2, L3; since last reset) | Consumed active energy since last reset | kWh |
| Active energy (feed-in) (Σ L1, L2, L3; since last reset) | Fed-in active energy since last reset | kWh |
| Power factor (Σ L1, L2, L3) | Power factor, sign indicates direction of current flow | - |
| Frequency (⌀ L1, L2, L3) | Grid frequency | Hz |


:::note
The localization of the entities depends on the language of the web interface of the WARP Charger/WARP Energy Manager.
:::

## Modbus/TCP
:::note
Coming soon...
:::

* [Modbus/TCP](/interfaces/modbus/introduction.md)

