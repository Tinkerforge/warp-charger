---
sidebar_position: 4
---

# ioBroker

## Introduction

Your [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md) is compatible with [ioBroker](https://www.iobroker.net).
ioBroker is a free software solution for bringing together building automation components in a single platform.

Devices are connected to ioBroker via a wide variety of (software) adapters.
Several adapters are available for connecting WARP devices (e.g. [OCPP](/interfaces/ocpp.md), [Modbus/TCP](/interfaces/modbus/introduction.md) and [MQTT](/interfaces/mqtt_http/introduction.md)).
In this introduction, we limit ourselves to MQTT.

:::note
The attentive user may have noticed that there is a [WARP adapter](https://github.com/pottio/ioBroker.warp) that was developed by a community member.
We greatly appreciate that the community develops integrations for WARP devices.
Unfortunately, we can**not** recommend this adapter in its current version 1.2.2, as it is not compatible with the updated web server of the WARP firmware, which can lead to high load and even crashes of your WARP device's software.
:::

## Integration via MQTT

We assume that you already have a running ioBroker system.

First, the MQTT broker/client is installed under "Adapters".

![MQTT Adapter Install](/img/smart_home/iobroker/install_mqtt.png)

Afterwards, the MQTT adapter must be configured as a client or as a server.

- If an MQTT broker is already present in the network, MQTT is configured as a "Client/Subscriber" and the address of the broker is entered in the connection settings. The remaining settings can be left at their default values.
- If no MQTT broker is present in the network yet, the adapter is configured as a "Server/Broker". Authentication is optional but recommended.


![MQTT Adapter Configuration](/img/smart_home/iobroker/configure_mqtt.png)

MQTT should be configured as shown. 
It is important that the two marked options are deactivated, as they can slow down the connection and lead to faulty MQTT behavior.

![MQTT Adapter Configuration](/img/smart_home/iobroker/mqtt_settings.png)

## Connecting the WARP Device

The WARP Charger/WARP Energy Manager is configured as described in [WARP adapter](/interfaces/mqtt_http/introduction.md).
The address of the ioBroker is entered as the broker hostname.
Discovery mode can be deactivated, as it is not supported by ioBroker.

## Integration in ioBroker
### Reading Values

The MQTT messages from WARP devices are JSON objects.
By default, ioBroker interprets these objects as strings and does not process them further.
To simplify further processing of data, it is best to extract these values as aliases. To do this, right-click on the desired data point → **Create alias**.

![Begin Alias Configure](/img/smart_home/iobroker/select_alias_configure.png)

This alias can then be configured depending on the value.
In this example, a value is extracted from an array.
Important are the read formulas with which the value is extracted from the JSON; the value must first be parsed and then read from the JSON.

![Alias Example Configuration](/img/smart_home/iobroker/alias_config_example.png)

Which values are available and how they are structured can be found in the [API documentation](/docs/api_reference).

After creating aliases, they can be integrated into visualizations or further processing.

### Writing Values

WARP devices expect write accesses on the respective topic with an appended `_update` suffix.
Example: The value `charge_manager/charge_modes` is read, but changes must be sent to `charge_manager/charge_modes_update`.

Since ioBroker does not handle this forwarding automatically, a script in the **JavaScript adapter** is required for this.

The following script shows a helper function `warpWrite` with 3 usage examples, which sends an arbitrary value as a JSON message to the correct `_update` topic.

```javascript
// ================================================================
// WARP device: Writing values via MQTT – ioBroker JavaScript adapter
// ================================================================

const MQTT_ADAPTER = 'mqtt.0';     // Instance of the MQTT adapter
const WARP_PREFIX  = 'warp3/1abc'; // Topic prefix (see WARP MQTT configuration)

/**
 * Writes a value to a WARP MQTT topic.
 * The WARP device expects write accesses on the topic with the suffix "_update".
 * Actions are sent without a suffix.
 *
 * @param {string} subTopic     - Topic without prefix, e.g. "charge_manager/charge_modes"
 * @param {*}      value        - Value to be written (is serialized as JSON)
 * @param {bool}   appendUpdate - Whether an _update suffix is appended
 * @param {bool}   retainMsg    - Whether the message should be retained. Only for write accesses
 */
function warpWrite(subTopic, value, appendUpdate = true, retainMsg = true) {
    let topic = WARP_PREFIX + '/' + subTopic;
    if(appendUpdate) {
        topic   = topic + '_update';
    } 
    const payload = JSON.stringify(value);

    sendTo(MQTT_ADAPTER, 'sendMessage2Client', {
        topic:   topic,
        message: payload,
        retain:  retainMsg
    });

    log('[WARP] ' + topic + ' ← ' + payload);
}


// ----------------------------------------------------------------
// Example 1: Write a value once
// Sets charge_manager/charge_modes to [2]
// ----------------------------------------------------------------
warpWrite('charge_manager/charge_modes', [2]);


// ----------------------------------------------------------------
// Example 2: Reactive – write a value when an
//            ioBroker data point changes (e.g. a VIS switch)
// ----------------------------------------------------------------
on({ id: '0_userdata.0.warp.lademodus', change: 'ne' }, function (obj) {
    const modus = Number(obj.state.val);
    warpWrite('charge_manager/charge_modes', [modus]);
});


// ----------------------------------------------------------------
// Example 3:  Send a command to start the charging process.
//             Commands must be sent without a suffix. The content is null, "", false, 0, [] or {}.
//             Commands are not retained.
// ----------------------------------------------------------------
warpWrite('evse/start_charging', "", false, false);
```

:::note
The script requires that the [JavaScript adapter](https://www.iobroker.net/#en/adapters/adapterref/iobroker.javascript/README.md) is installed.
It can be created as a new script under **Scripts**.

The `sendTo` call with `sendMessage2Client` is the official API of the MQTT adapter for publishing messages and works both in **Server/Broker** mode and in **Client/Subscriber** mode.
:::

Which topics and which values are accepted is described in the [API documentation](/docs/api_reference).
