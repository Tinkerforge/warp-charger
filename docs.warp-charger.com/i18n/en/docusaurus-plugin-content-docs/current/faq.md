---
sidebar_position: 10
---

# Frequently Asked Questions (FAQ)

## Funding

### Is a WARP Charger eligible for KfW 442 funding?

The Smart and Pro variants are on the KfW list and are funded with 600€.

## Bidirectional Charging, V2G or V2H

### Does the WARP Charger support bidirectional charging, Vehicle-to-Grid (V2G) or Vehicle-to-Home (V2H)? Can a vehicle feed electricity back into the grid or home via the charger?

No.

There are various pilot projects where V2G or V2H concepts are also supported with AC chargers. However, most news on this topic are currently just announcements; there are no concrete products available at the moment. The technical and legal framework conditions are not yet fully clarified. Even if a product were available on the market, it would not be allowed to be put into operation.

**Explanation:**

Since the vehicle battery always operates with direct current (DC), an inverter (DC -> AC) must be installed between it and the power grid. There are vehicles where this inverter is already installed in the vehicle. This would make it theoretically conceivable to feed back via the Type 2 charging cable, which is intended for transmitting alternating current.

However, most announcements concern vehicles where the battery can be accessed via the DC contacts in the vehicle socket (Combined Charging System; CCS plug). AC chargers, including our WARP Chargers, have no way of accessing this DC voltage since the charger does not have a CCS plug. Additionally, the chargers lack the necessary inverter to generate alternating current from direct current again. There are DC chargers on the market that offer the technical possibilities, but these are in a completely different price range. Besides these technical problems, there are other open questions: These include the actual control of the feed-back (communication between charger and vehicle) as well as unresolved regulatory and tax law questions. Additionally, the topic involves other areas, such as the rollout of the smart meter gateway, control by grid operators, etc.

From our perspective, it is therefore not credible to advertise that an AC charger will support V2G or V2H in the future, since the aforementioned technical and legal issues are not yet clarified at all. Should retrofitting of our chargers be possible due to our modular concept, we will certainly offer this in the future.

## Function

### (How) is PV excess charging possible?

PV excess charging can be implemented directly with the WARP3 Charger (without additional hardware) or via the [WARP Energy Manager](https://warp-charger.com/warp-energy-manager/). For this, an existing meter at the house connection can be read via SunSpec.

Technically savvy users can alternatively set up PV excess control with EVCC. [The setup of EVCC is described here.](/smart_home/evcc.md)

More information is available at [https://warp-charger.com/pv-ueberschussladen](https://warp-charger.com/pv-ueberschussladen/).

### Can the WARP Charger query the state of charge of a connected vehicle? Can charging be done up to a certain state of charge (e.g. up to 80%)?

No. However, it is possible with EVCC via the APIs offered by many vehicle manufacturers to query the state of charge. EVCC can then control a WARP Charger so that charging only occurs up to a certain state of charge. [The setup of EVCC is described here.](/smart_home/evcc.md)

### Is it possible to configure the charging current to less than 6 amperes?

Not through the WARP Charger. Charging is done according to the IEC 61851 standard. This standard defines that a charger, when it enables charging, must communicate a maximum current. This maximum current must be at least 6 amperes.

However, there are vehicles that can be configured to draw less than the maximum current specified by the charger.

## Assembly and Installation

### What conductor cross-section do I need for the supply line to the WARP Charger?

The conductor cross-section should always be determined by the electrician on site. The following are minimum values in practice:

11 kW charging power

*   up to 20 meters: 2.5 mm²
*   up to 40 meters: 4.0 mm²
*   up to 70 meters: 6.0 mm²

22 kW charging power

*   up to 25 meters: 6.0 mm²
*   up to 50 meters: 10.0 mm²
*   up to 100 meters: 16.0 mm²

### Can multiple chargers be operated on one house connection? Can it be ensured that a specified maximum power consumption is not exceeded?

Yes. WARP Chargers can share a house connection via the built-in load management without overloading it. The load management ensures that a specified power consumption is not exceeded and distributes the available charging current across multiple WARP Chargers. For WARP Chargers to be controlled via load management, they must be operated on the same network.

### Can I deactivate a WARP Charger from the outside? How do I connect a ripple control receiver (keyword §14a EnWG)?

There are various options to control the charging function of a WARP Charger:

* Via HTTP, MQTT, OCPP or Modbus/TCP the charger can be controlled. See also [API documentation](/interfaces/mqtt_http/introduction.md)
* The behavior on the inputs of the WARP Energy Manager can be configured. Among other things, a reduction of the charging power/shutdown is possible. The WARP Energy Manager controls the chargers via a (WLAN/LAN) network connection, so that remote control is possible.
* It is also possible to connect a ripple control receiver or similar switch directly to the charger. For this purpose, there is a configurable shutdown input in the charger. A hole may need to be drilled in the charger housing to implement the switch.
* More information on this topic is also available on the info page about [§14a EnWG](https://warp-charger.com/%c2%a714a-enwg/).

### Can an already existing/different electricity meter be used?

The WARP3 Charger is delivered with a DSZ15DZMOD-3x80A from Eltako. Additionally, electricity meters of type SDM630 or SDM72 V2 from Eastron are also supported. Other electricity meters are not supported.

## Charge Management

### How many participants are supported by the charge manager?

A WARP3 Charger can be configured as a charge manager. It can control a maximum of 64 chargers in total (including itself).

Another option is to configure the WARP Energy Manager as a charge manager. This can then also control up to 64 chargers.

## Web Interface

### Why can't I reach the web interface from my phone/tablet via the charger's access point?

Typically, the problem is that on the phone/tablet, in addition to the WLAN connection to the charger's access point, the mobile data connection is also active. When the mobile data connection is disabled, the web interface should be accessible at [http://10.0.0.1](http://10.0.0.1).

### Why can't I reach the web interface from my Samsung device?

The "Samsung Internet" browser preinstalled on Samsung devices does not seem to correctly support the websockets used by the web interface. With another browser, such as Firefox or Chrome, the web interface should be accessible.

## MQTT

### Why can't the charger reach my Mosquitto MQTT broker?

Often the problem here is that Mosquitto since version 2.0.0 only allows local connections by default. For access over the network to be possible, the Mosquitto configuration must be adjusted. Details can be found in the [Mosquitto documentation](https://mosquitto.org/documentation/migrating-to-2-0/) and in [our forum](https://www.tinkerunity.org/topic/7188-keine-verbindung-zu-mqtt/#comment-38629).

### Why are change commands not being accepted?

Typically, the last set value can be read on a topic. For example, `warp/AbC/charge_manager/available_current` returns the current available for charge management. Commands must be sent to the corresponding topic ending in `_update` so that they can be distinguished by the WARP Charger from its own messages. To update the available current, for example, you must publish to `warp/AbC/charge_manager/available_current_update`.

### Why does the charger report MQTT: Topic ... is an action. Ignoring retained message.?

Certain commands are actions, i.e. they do not set a permanent state but trigger one-time events. A "Retained Message" is, however, permanently stored on the MQTT broker. For actions, such messages are therefore prohibited, since they could otherwise be processed more than once, for example after reconnecting the WARP Charger to the MQTT broker.



## Upgrading WARP Chargers

We try to equip even older WARP Chargers with the latest features as far as possible. Therefore, we still release updates for WARP1 chargers.

### Upgrade from WARP Charger Smart to WARP Charger Pro

The difference between the two versions consists of the additionally installed MID-certified electricity meter. For WARP3, this can be retrofitted. To do this, only the terminal block needs to be moved to the left and the electricity meter needs to be installed additionally. This is connected to the EVSE with a data connection cable. Additionally, a connection cable between terminals and electricity meter is necessary. All three components are available in the shop:

* [Electricity meter DSZ15DZMOD-3x80A](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts/electricity-meter-dsz15dzmod-3x80a.html)
* [Connection cable for DSZ15DZMOD-3x80A](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts/anschlusskabel-fuer-dsz15.html)
* [WARP3 cable harness](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts/warp3-cable-harness.html)

### Upgrade WARP2 to WARP3

Due to the modular design of the chargers, a hardware upgrade is also possible in principle. The conversion is relatively extensive, as all the technology of the charger must be replaced. Only the charging cable and the housing, the electricity meter, and the installed NFC Bricklet can be reused. All parts are also available individually in our shop:

* [WARP3 spare parts](https://www.tinkerforge.com/de/shop/warp/warp3-spare-parts.html)

There is also more information on this topic on Tinkerunity: [Link](https://www.tinkerunity.org/topic/12097-warp2-zu-warp3-aufr%C3%BCsten/?do=findComment&comment=55013)
