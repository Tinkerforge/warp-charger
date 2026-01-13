---
sidebar_position: 4
---

# Battery Storage

:::note

    Battery storage control is currently still in development and is not yet part of the release firmware!
    
    We have published a beta firmware on Tinkerunity that generally supports controlling a battery storage via Modbus/TCP commands. Download here: [Tinkerunity - Beta Test Battery Storage Control](https://www.tinkerunity.org/topic/13229-beta-test-batteriespeicher-steuerung-phase-2/).

    It cannot be guaranteed that these battery storage settings will be correctly transferred during a firmware update!
:::


## Battery Storage Control

Many manufacturers support external control of battery storage via [Modbus/TCP](/compatible_devices/interfaces.md#modbustcp) interface.
Usually the battery storage is controlled via the connected inverter and not the battery directly. The registers provided for control differ depending on the manufacturer and device, so not all devices
support all functions. The implementation of each function also varies greatly from device to device!

### General Idea

The storage is not regulated by us. It performs its manufacturer-defined function. This means that normally a PV excess is used to charge the storage and the storage tries to compensate for the power consumption of a load.
However, with the functions listed below, this control can be intervened.

## Creating a Battery Storage

We enable controlling a battery storage via Modbus/TCP. We try to offer presets for storage systems known to us that can be directly selected.
Unfortunately, it is not easy to determine the correct values without access to a system. Therefore, we are very dependent on the community here.

If no preset is stored for a storage system, the respective registers can be created manually. Three functions listed below can be implemented.
Not all functions need to be implemented for the respective storage system. However, if a function is implemented, the cancellation of this function must also be implemented.

Individual registers can be written, but also multiple registers in one command. It is recommended to write registers that are consecutive as one block in one command. 

### Allow Charging from Grid

This function attempts to force the storage to charge to 100% SoC. If the charging power is not covered by PV, the storage should charge with power from the grid. The following possibilities are known to us to implement this function:

 * Set general "Minimum SoC" to 100%. However, this only works if the system then also draws power from the grid for charging.
 * Set and activate a charging schedule with the time range 00:00-23:59 and a target SoC of 100%.

### Prohibit Discharging

With this function, the storage is prohibited from discharging. The following possibilities are known to us to implement this function:

 * Set the "Maximum Discharge Current" to 0A.
 * Set the "Minimum SoC" to 100%. This only works if the system then does NOT draw power from the grid for charging but only disables discharging.

### Prohibit Charging

This function prohibits the storage from charging. The following possibilities are known to us to implement this function:

 * Set the "Maximum Charge Current" to 0A.
 * Set the "Maximum Charge Power" to 0W.

## Schedule for Dynamic Electricity Price

With the electricity price schedule, cheap and expensive hours can be defined. These properties can then be used in the rules. Only the number of respective hours in 15-minute steps needs to be defined.
A graph then displays the hours for the current electricity price curve.

## Using Battery Storage - Defining Rules

Multiple rules can be defined for each function. A function is executed when all conditions of an assigned rule are met. If no rule for a function is met, the function is deactivated.
That means the cancellation of the function is executed cyclically (the respective Modbus registers are written).

Each rule consists of a description (free text for the user) and multiple conditions. Not all conditions need to be defined. If only two conditions should be used, the rest can be set to "ignored".
The following conditions can be defined: A time period, a battery charge level (SoC), an electricity price, and the value of the PV yield forecast. Additionally, an electricity price schedule can be activated in which the most expensive
and the cheapest X hours are defined. Finally, the charging mode "Fast Charging" can be used as a condition.

The comparison to the specified values can be defined as "less than" or "greater than". If a value should not be used, "is ignored" should be configured.

## Example Rules
The following rules serve as examples. For your own use, the parameters must be adjusted.

### Allow Charging from Grid

If all defined conditions of a rule are met, the storage will be charged from the grid.

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>Battery</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Schedule</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1.</td><td>-</td><td>< 60%</td><td>< 5.0ct</td><td>< 20kWh</td><td>Cheap</td><td>-</td></tr>
<tr><td>2.</td><td>-</td><td>< 30%</td><td>-</td><td>-</td><td>Cheap</td><td>-</td></tr>
</table>

The first rule is designed to recharge the storage to 60% with "cheap" electricity when the expected PV yield for the current day is insufficient. For this, the "cheap" hours defined in the electricity price schedule are used. But only if their cost is below 5ct.
The second rule is intended so that if the first rule doesn't apply, at an SoC below 30%, charging up to 30% still occurs during cheap hours.

### Battery Discharge Prohibition

If all defined conditions of a rule are met, the storage will no longer be discharged.

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>Battery</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Schedule</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1.</td><td>-</td><td>< 20%</td><td>-</td><td>-</td><td>Not expensive</td><td>-</td></tr>
<tr><td>2.</td><td>-</td><td>-</td><td>-</td><td>-</td><td>-</td><td>Active</td></tr>
</table>

The first rule is designed to leave a reserve of 20% against high electricity prices. If electricity is "Not expensive" and the SoC is less than 20%, the storage will no longer be discharged. However, if electricity switches to "expensive", this rule doesn't apply and the storage will be discharged.
The second rule is designed to not discharge the storage when a vehicle is being charged via "Fast Charging". If desired, this can also be linked to an SoC.


### Battery Charging Prohibition

If all defined conditions of a rule are met, the storage will no longer be charged.

<table>
<tr><td><b>Description</b></td><td><b>Time</b></td><td><b>Battery</b></td><td><b>Electricity Price</b></td><td><b>PV Yield</b></td><td><b>Price Schedule</b></td><td><b>Fast Charging</b></td></tr>
<tr><td>1.</td><td>00:00-12:00</td><td>> 70%</td><td>-</td><td>> 32kWh</td><td>Not cheap</td><td>-</td></tr>
</table>

Entirely in the spirit of the HTW Berlin campaign: [Your Battery Storage Can Do More](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/) this rule is intended to prevent the storage from being charged first in the morning on sunny days only to be full by noon and feed into the grid.
