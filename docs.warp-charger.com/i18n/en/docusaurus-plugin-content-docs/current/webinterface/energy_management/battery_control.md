---
sidebar_position: 2
---

# Battery Control

:::note

    Battery storage control is currently still in development!

    Storage systems can be controlled from a [WARP Charger 1,2,3](/warp_charger/introduction.md) (from firmware 2.9.0) or [WARP Energy Manager 2](/warp_energy_manager/introduction.md) (from firmware 2.5.0) over the network.
    
    Generally, storage systems are supported that can be controlled via [Modbus/TCP](/compatible_devices/interfaces.md#modbustcp) commands.
    Custom (user-defined) register tables can be created to control a storage system. 

    We are working to provide presets for as many devices as possible.
    The currently supported storage systems or hybrid inverters can be found in the [list of compatible devices](/compatible_devices/devices.mdx).
    They support the [Battery Control (BC)](/compatible_devices/introduction.md#battery-control-bc) feature.

    Battery control does not take full control of the storage system and does not, for example, regulate its power.
    Battery control only sets parameters of the storage system (e.g., the "maximum charge current") to control it. The actual regulation remains with the storage system or the connected hybrid inverter.

:::


![image](/img/webinterface/energy_management/batterycontrol.jpeg)


## Creating a Battery Storage Entry

After enabling battery control, a storage system can be created. To do this, click the "+" symbol and select "Modbus/TCP" as the class. Then enter the display name, host, port, and select the corresponding
register table. After that, additional device-specific parameters need to be configured. This can be, for example, the charge power or a target grid consumption. Finally, the storage system must be added and all settings
must be applied by clicking "Save" and then restarting.

If no register table (preset) is available for a device, a custom register table can also be created. In this case, register sets must be defined for each storage mode. How this works is
described under [Creating a Battery Storage Entry](/compatible_devices/batteries.md#creating-a-battery-storage-entry).


## Settings

### Schedule for Dynamic Electricity Price

If a [dynamic electricity price](/webinterface/energy_management/dynamic_tariffs.md) is configured, the "cheap hours" and "expensive hours" can be configured here. This is possible in 15-minute steps (=0.25h).
These properties can then be used in the rules to, for example, control charging from the grid or block discharging. A graph then shows the hours for the current electricity price curve.

### Rules

Up to 32 charge and discharge rules can be created. The structure is identical for all:

![image](/img/webinterface/energy_management/batterycontrol-rule-charge.jpeg)
![image](/img/webinterface/energy_management/batterycontrol-rule-discharge.jpeg)


For each rule, a **description** (free text) can be created, as well as conditions that refer to the parameters **time**, the battery's **state of charge (SoC)**, the current (dynamic) **electricity price**, the **PV yield forecast**,
conditions for the above-defined **electricity price plan**, or whether **fast charging** is active at a charger. Comparisons can be defined for the parameters, so that, for example, an electricity price **less than** 12 cents as a
condition or a state of charge **greater than** 50% can be defined. Not all parameters need to be used as conditions for the rule. Parameters can be ignored.

If **ALL** conditions of a rule are met (**AND**), the rule is active and the defined **action** is performed:

Actions for charge rules are:

 * **Force**: The storage charges. If the charge power is not covered by PV or similar, electricity is also drawn from the grid.
 * **Block**: The storage is prohibited from charging. If there is PV excess, it no longer flows into the storage.

Actions for discharge rules are:

 * **Force**: The storage discharges. If the discharge power is not fully used by consumers, electricity is also fed into the grid.
 * **Block**: The storage is prohibited from discharging. Loads are no longer compensated by the storage.


Battery control evaluates all rules according to their order and executes the first rule whose conditions are all met (**OR**). This applies to both charge rules and discharge rules.
As a result, the storage can be in one of six different modes. See [technical description of battery storage](/compatible_devices/batteries.md#custom-battery-storage---storage-modes).
The storage mode is displayed at the top of the web page.

An active rule is marked with a blue line on the left side. This shows which rule is responsible for the storage leaving its *normal* mode for charging or discharging.

## Example Storage Rules

The configuration of rules is always customer and application-specific. Below we provide some examples. However, the respective parameter values always depend on the size of the PV system, the storage, and the consumption.

### Charge from Grid at Cheap Electricity Prices

When using dynamic electricity prices, it can make sense to charge the storage at cheap times to avoid grid consumption during expensive electricity price periods. To use this function,
the **schedule for dynamic electricity price** must first be configured. As an example, the number of hours needed to fully charge the storage can be selected as **cheap hours**.
For **expensive hours**, the number of hours that the storage normally lasts to cover the entire demand can be selected.

The following conditions could be defined as charge rules for the **force charging** action:

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>State of Charge</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Plan</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1.</td><td>-</td><td>&lt; 100%</td><td>&lt; 5.0ct</td><td>&lt; 20kWh</td><td>Cheap</td><td>-</td></tr>
<tr><td>2.</td><td>-</td><td>&lt; 60%</td><td>&lt; 8.0ct</td><td>&lt; 10kWh</td><td>Cheap</td><td>-</td></tr>
<tr><td>3.</td><td>-</td><td>&lt; 30%</td><td>-</td><td>-</td><td>Cheap</td><td>-</td></tr>
</table>

The first rule is designed to fully charge the storage with "cheap" electricity when the expected PV yield for the current day is insufficient. For this, the "cheap" hours defined in the electricity price plan are used. But only if their cost is below 5 cents.
The second rule is intended so that if the first rule doesn't apply, at a state of charge below 60%, charging up to 60% still occurs during the cheap hours, but only if the electricity price is still below 8 cents. The third rule is intended
so that if the first two rules don't apply, at a state of charge below 30%, charging up to 30% still occurs during the cheap hours. In this case, the actual electricity price and the expected PV yield are ignored. The rule is only active when we are in the cheap hours.

### Block Charging During High PV Excess

This function sounds counterintuitive at first. We want to prohibit the storage from charging when there is PV excess. In this case, the storage would not use the excess itself,
but feed the excess into the grid. However, it can make sense not to use the excess for charging the storage. Specifically, when a high PV excess is expected.

Entirely in the spirit of the HTW Berlin campaign: [Your Battery Storage Can Do More](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/), this rule is intended to prevent
the storage from being charged first in the morning on sunny days only to be full by noon and feed into the grid. The rule with the **block charging** action could look like this:

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>State of Charge</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Plan</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1.</td><td>00:00-12:00</td><td>&gt; 70%</td><td>&gt; 0ct</td><td>&gt; 32kWh</td><td>-</td><td>-</td></tr>
</table>

The rule prohibits charging the storage in the morning if the storage already has a state of charge of > 70% and a large PV yield is expected. This means that electricity is still fed into the grid in the morning during times
when the power grid still needs the electricity and you still receive feed-in compensation. However, we keep about 30% battery capacity free to be able to charge the storage during times when the power grid no longer needs the electricity (electricity price less than 0 cents)
and we also don't receive feed-in compensation.


### Block Discharging at Non-Expensive Electricity Prices

There are good reasons to prohibit a storage from discharging. For example, it makes no sense to charge the storage from the grid at cheap electricity prices and then immediately discharge it at "non-expensive" electricity prices (conversion losses, etc.).
Additionally, you may not want the storage to discharge when a vehicle is being charged. An example rule with the **block discharging** action could look like this:

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>State of Charge</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Plan</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1.</td><td>-</td><td>-</td><td>-</td><td>-</td><td>Not expensive</td><td>-</td></tr>
</table>

The rule is designed to only discharge the storage when the electricity price is expensive (implemented as a discharge prohibition when **not expensive**). This would use the storage to prevent grid consumption during the expensive hours according to the defined price plan.

The rule can be further optimized with additional parameters:

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>State of Charge</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Plan</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1b.</td><td>-</td><td>&lt; 80%</td><td>-</td><td>-</td><td>Not expensive</td><td>-</td></tr>
</table>

In this case (**1b**), the storage would always discharge down to 80% state of charge, but below that only during the expensive hours. Further optimizations would be possible, for example, by also using the PV forecast as a parameter.


If the battery storage capacity should not be used to charge a vehicle, the following rule with the **block discharging** action can be used to prevent this:

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>State of Charge</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Plan</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>2.</td><td>-</td><td>-</td><td>-</td><td>-</td><td>-</td><td>Active</td></tr>
</table>

Together with the [Eco Mode](/webinterface/energy_management/eco_mode.md) of the chargers, the vehicle can thus be charged cheaply from the grid without charging from the home battery storage.
If a charge rule for the battery storage is active at the same time, the vehicle and battery storage would be charged simultaneously.

This rule can also be extended, for example, with a condition on the state of charge, so that only part of the battery capacity is used to charge the vehicle.


### Force Discharge at High Feed-In Tariffs

If you want to actively discharge the storage to, for example, feed into the power grid during times of high compensation, this is possible with a rule and the **force discharging** action as follows:

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>State of Charge</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Plan</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1.</td><td>-</td><td>-</td><td>&gt; 15ct</td><td>-</td><td>Expensive</td><td>-</td></tr>
</table>

The storage would discharge during the "expensive hours" (schedule for dynamic electricity price) as soon as the electricity price exceeds 15 cents.

## Example Configuration

Below is a complex example of what a rule configuration can look like.

![image](/img/webinterface/energy_management/batterycontrol-rules-example.jpeg)

The charge rule **Super cheap at night** with the **force charging** action becomes active when little sun is expected (less than 16kWh), for example in winter. If the electricity price at night (00:00 - 06:00) is less than 2 cents and we are in the cheap hours,
the storage is charged to 100% (no state of charge restriction). With this rule, the storage is fully charged at night in winter at very cheap electricity prices.

The charge rules **No sun + cheap** and **No sun + cheap 2** with the **force charging** action are designed to charge the storage from the grid at cheap electricity prices up to a certain state of charge. Depending on the electricity price, the storage is charged
either to 80% or to 60%. However, this only happens when a moderate PV yield is expected. Similarly, two discharge rules with the **block discharging** action were also created. These are set up identically, but the state of charge was increased by 1%.
The reason for the discharge rules is that at a state of charge less than 100%, the storage is charged as an example to 80% state of charge. Then the conditions of the rule with less than 80% state of charge are no longer met. The storage returns to "normal mode" and discharges.
At 79% state of charge, the charge rule is activated again and charges the storage back to 80% state of charge. The system thus oscillates (charging/discharging). To prevent this oscillation, a discharge rule with 1% higher state of charge was created for each charge rule.
Thus, discharging is always prohibited simultaneously with charging in that state, and the state of charge remains unchanged.

The rule **Keep reserve** is structured similarly (charge and discharge rule) and is designed to maintain a state of charge of 30% as a reserve, which is used for the expensive hours to avoid having to draw electricity during those times. The rules ensure that charging
up to 30% state of charge occurs during the non-expensive hours and this state of charge is also maintained (1% higher block-discharging rule). If we are in a period that is **expensive** according to the electricity price plan, the rules don't apply and the storage falls back
to normal operation. It then discharges and no electricity is drawn from the grid.

The charge rule **HTW Berlin** is intended to support the [Your Battery Storage Can Do More](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/) campaign. The rule ensures that on mornings with very high expected PV generation, the storage is only charged
to 70% and charging is then blocked. This is the case early in the morning during summer. Subsequently, the storage is no longer charged and the excess goes into the power grid. As soon as the electricity price becomes negative, the rule no longer applies.
Charging of the battery storage is then no longer blocked. It charges again and no more electricity is fed into the power grid.

The discharge rule **Minimum SoC** is designed to always maintain a state of charge of 4%, since discharging is blocked below 5%.

To prevent a vehicle from being charged from the battery storage, a rule **Fast charging** has been defined that blocks discharging of the storage when fast charging is occurring.

## Technical Implementation of Battery Control

Battery control does not take full control of the storage and does not, for example, regulate the power of the battery storage!
The storage always performs its manufacturer-defined function. This means that normally a PV excess is used to charge the storage and the storage tries to compensate for the power consumption of a load.

Storage control only changes the parameters of the storage and thus modifies behavior.
As an example, battery control can block charging of the storage.
The technical implementation varies depending on the device. As an example, the "maximum charge current" parameter can be set to 0A, which blocks charging.
If the storage should return to normal operation, the parameters must be reset to their default values. As an example, the "maximum charge current" could then be reset to 25A (default).

A detailed technical description of battery control can be found here: [Technical Description of Battery Control](compatible_devices/batteries.md)
