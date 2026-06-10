---
sidebar_position: 10
---

# Frequently Asked Questions (FAQ)

## The Most Common Questions

### Who is allowed to install the WARP4 Charger?
Installation must be carried out by a qualified electrician. The electrician also takes care of the required registration with the grid operator.

### Do I need a Type B RCD?
No. The WARP4 has integrated DC fault current detection (RDC-DD). A Type A RCD in the building installation is sufficient.

### Does the WARP4 also work without internet access / without the cloud?
All functions of the WARP4 run locally on the charger. Operation and configuration are done via the integrated web interface in your own home network, entirely without forced cloud usage. Only functions such as PV yield forecasting, the use of dynamic electricity prices, or the use of the apps require an internet connection.

### How do I integrate the charger into my smart home?
The WARP4 supports open standards such as MQTT, Modbus TCP, and the HTTP API. This allows it to be seamlessly integrated into Home Assistant, ioBroker, openHAB, and other smart home systems.

### How do I connect the charger to my existing PV system?
We support over 100 devices from other manufacturers and can directly access the data of energy meters, PV inverters, and storage systems. The installation of additional hardware, e.g. an extra energy meter for the charger, is therefore usually unnecessary, since existing hardware can be used by the charger. The [complete compatibility list is available here](/compatible_devices/devices.mdx).

### Which devices are supported?
The WARP4 communicates with numerous smart meters, PV inverters, electricity storage systems, and heat pumps from various manufacturers. A complete compatibility list can be found in the documentation.

### Why is only the Pro version prepared for bidirectional charging and able to read out the SoC?
Only the Pro version has an energy meter. We assume that this is necessary for bidirectional charging in order to react to problems with the power grid (anti-islanding protection). The SoC of a vehicle can be read out via ISO15118-2, but unfortunately not during an ongoing charging process. During charging, the Pro can calculate the state of charge using the energy meter.

### Which variant is suitable for billing?
For billing, e.g. for company cars or at the workplace, we recommend the WARP4 Pro with a MID-certified meter and a charge log with energy recording. For applications that require a calibration-law-compliant solution, the WARP4 is currently not suitable.

### What is the difference between MID-certified and calibration-law-compliant?
The energy meter of the Pro version is MID-certified. This refers to the measurement accuracy of the energy meter. The term "calibration-law-compliant charger" refers not only to the energy meter but to the entire charger. For example, the energy meter must sign every charging process. The data is uploaded and made available in the transparency software. In theory, this allows a user to check whether billing was done correctly. In addition, the charger must be protected against tampering. As a result, many parts inside the charger are sealed and cannot simply be replaced by an electrician. After the calibration period of 8 years has expired, the charger may no longer be used for billing purposes. The energy meter can only be replaced by the manufacturer.

### Is the charger eligible under the "Funding for Charging in Multi-Family Buildings" program?
Yes, the WARP4 is on the list of eligible chargers under our company name "Tinkerforge GmbH".

### Does the WARP4 comply with §14a EnWG?
Yes. The WARP4 supports grid-friendly control according to §14a EnWG, including an EEBUS interface for communication with the grid operator's control box standard.


## Hardware
### Upgrade from WARP3 to WARP4

A complete upgrade from WARP3 to WARP4 is possible. However, the housing must then also be replaced. For the vast majority of customers, this is probably not necessary, since only an upgrade to the WARP4 charging electronics with ISO15118 is desired. This replacement is very easy! All connections have remained identical.
The charging electronics of WARP3 and WARP4 are mechanically compatible and can be easily replaced. To do this, all cables must be unplugged from the charging electronics. It can then be removed from the DIN rail.
Next, the WARP4 charging electronics are placed on the DIN rail and all cables are reconnected. The only difference is that on the WARP3 the maximum current of the charging cable was set via a resistor (PP resistor).
On the WARP4 this is also possible, but in addition the charging cable can simply be set using a jumper (16A or 32A).

We offer an upgrade kit for the charging electronics: [WARP3 to WARP4 upgrade kit](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp3-to-warp4-upgrade-set.html).


### Upgrade from WARP4 Smart to WARP4 Pro
The WARP4 Pro has a viewing window in the housing so that the display of the energy meter can be seen from the outside. The following components are required:

* [Iskra energy meter WM3M4 V2 MID RS485](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/meter-iskra-wm3m4-v2-mid.html)
* [WARP4 housing (Pro variant)](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp4-enclosure.html)
* [NFC sticker](https://shop.warp-charger.com/de/catalog/product/view/id/929/s/warp-nfc-sticker/category/64/)
* [RS485 data cable for MID energy meter Iskra WM3M4 V2](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp-meter-cable-for-iskra-wm3m4.html)
* [WARP4 Pro DIN rail set](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp4-pro-din-rail-set.html)
* [Cable set for WARP4 Smart and Pro](https://shop.warp-charger.com/de/spare-parts/warp4-spare-parts/warp4-smart-pro-cable-set.html)


### Upgrade from WARP3 Smart to WARP3 Pro

The difference between the two versions consists of the additionally installed MID-certified energy meter. For the WARP3, this can be retrofitted. To do this, only the terminal block needs to be moved to the left and the energy meter needs to be installed additionally. This is connected to the EVSE with a data connection cable. Additionally, a connection cable between terminals and energy meter is necessary. All three components are available in the shop:

* [Energy meter DSZ15DZMOD-3x80A](https://shop.warp-charger.com/de/spare-parts/warp3-spare-parts/electricity-meter-dsz15dzmod-3x80a.html)
* [Connection cable for DSZ15DZMOD-3x80A](https://shop.warp-charger.com/de/catalog/product/view/id/1036/s/anschlusskabel-fuer-dsz15/category/63/)
* [WARP3 cable harness](https://shop.warp-charger.com/de/spare-parts/warp3-spare-parts/warp3-cable-harness.html)

### Upgrade from WARP2 to WARP3

Due to the modular design of the chargers, a hardware upgrade is also possible in principle. The conversion is relatively extensive, as the entire technology of the charger must be replaced. Only the charging cable and the housing, the energy meter, and the installed NFC Bricklet can be reused. All parts are also available individually in our shop:

* [WARP3 spare parts](https://shop.warp-charger.com/de/spare-parts/warp3-spare-parts.html)

There is also more information on this topic on Tinkerunity: [Link](https://www.tinkerunity.org/topic/12097-warp2-zu-warp3-aufr%C3%BCsten/?do=findComment&comment=55013)



## Bidirectional Charging, V2G or V2H

### Does the WARP Charger support bidirectional charging, Vehicle-to-Grid (V2G) or Vehicle-to-Home (V2H)? Can a vehicle feed electricity back into the grid or home via the charger?

The WARP4 Charger Pro version is prepared for bidirectional charging on the hardware side. This is currently not yet fully technically feasible for us, as certain technical details have not yet been clarified (e.g. anti-islanding protection).
However, we assume that we will be able to add this function via a software update.

Solutions currently advertised in the media or by vehicle manufacturers do not conform to any standard and are isolated solutions from the respective manufacturers. In each case, a proprietary solution was created that works with the advertised combination of vehicle and charger, but not with other vehicles or chargers.


## Function

### (How) is PV excess charging possible?

PV excess charging can be implemented directly with a WARP Charger (without additional hardware) or via the [WARP Energy Manager](https://warp-charger.com/warp-energy-manager/). For this, an existing meter at the house connection can be read out over the network.

More information on this can be found in the documentation in the tutorial [PV Excess Charging](/tutorials/pv_excess_charging.md).

### Can the WARP Charger query the state of charge of a connected vehicle? Can charging be done up to a certain state of charge (e.g. up to 80%)?

Yes, WARP4 Pro Chargers can read out the SoC at the start of a charging process for vehicles that support this, and then update it via the built-in energy meter during charging.
For all other WARP Chargers, it is possible to query the state of charge with EVCC via the APIs offered by many vehicle manufacturers. EVCC can then control a WARP Charger so that charging only occurs up to a certain state of charge. [The setup of EVCC is described here.](/smart_home/evcc.md)

### Is it possible to configure the charging current to less than 6 amperes?

Charging is currently done according to the IEC 61851 standard. This standard defines that a charger, when it enables charging, must communicate a maximum current. This maximum current must be at least 6 amperes.
With the ISO15118-20 charging standard, it will also be possible to define lower charging powers.

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

Yes. WARP Chargers can share a house connection via the built-in charge management without overloading it. The charge management ensures that a specified power consumption is not exceeded and distributes the available charging current across multiple WARP Chargers. For WARP Chargers to be controlled via charge management, they must be operated on the same network.

### Can I deactivate a WARP Charger from the outside? How do I connect a ripple control receiver (keyword §14a EnWG)?

For the topic of §14a EnWG, we offer a dedicated tutorial that presents the various options: [§14a EnWG tutorial](/tutorials/verbrauchseinrichtung.md).

## Charge Management

### How many participants are supported by the charge manager?

A WARP Charger can be configured as a charge manager. It can control a maximum of 64 chargers in total (including itself).

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
