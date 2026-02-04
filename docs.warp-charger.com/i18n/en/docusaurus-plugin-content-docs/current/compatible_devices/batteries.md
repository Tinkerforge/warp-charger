---
sidebar_position: 4
---

# Battery Storage

:::note

    Battery storage control is currently still in development!
    
    Generally, storage systems are supported that can be controlled via [Modbus/TCP](/compatible_devices/interfaces.md#modbustcp) commands.
    Custom (user-defined) register tables can be created to control a storage system. 
    Since this requires significant technical know-how, we are working to provide presets for storage systems.
    We are continuously expanding the list!

:::


## What Does Controlling a Battery Storage Mean?

Many manufacturers support external control of battery storage via [Modbus/TCP](/compatible_devices/interfaces.md#modbustcp) interface.
Usually the battery storage is controlled via the connected inverter and not the battery directly. The registers provided for control 
differ depending on the manufacturer and device. The implementation of each function also varies greatly,
so the settings between different devices cannot necessarily be compared.

The storage is NOT regulated by us. It performs its manufacturer-defined function. This means that normally a PV excess is used to charge the storage and the storage tries to compensate for the power consumption of a load.
However, using user-definable rules in battery control, parameters can be set so that, for example, charging is blocked and excess does not flow into the storage.

## Creating a Battery Storage Entry

:::note

    Creating a battery storage entry is described in the web interface: See [Battery Control](/webinterface/energy_management/battery_control.md)

:::


We enable controlling a battery storage via [Modbus/TCP](/compatible_devices/interfaces.md#modbustcp). We try to offer presets for storage systems known to us that can be directly selected.
Unfortunately, it is not easy to determine the correct values without access to a system. Therefore, we are very dependent on the community here. In the [list of compatible devices](/compatible_devices/devices.mdx),
battery storage systems that we can control are marked with "BS".

If no preset is stored for a storage system, the respective registers can be created manually. To do this, register sets for the six different modes mentioned below must be
implemented. Individual registers can be written, but also multiple registers in one command. It is recommended to write registers that are consecutive as one block in one command.
See the following section [Custom Battery Storage - Storage Modes](/compatible_devices/batteries.md#custom-battery-storage---storage-modes).
It is important to implement the "Storage Mode: Normal Charging, Normal Discharging" and set the default parameters of the storage in it.


## Custom Battery Storage - Storage Modes

Battery control is always in one of the six modes mentioned below. Rules can be used to define under which conditions the mode is changed.
If no preset exists for a storage system, the register sets can be created manually (custom). In this case, a register set must be stored for each mode so that
battery control can switch between the respective modes.

**Storage Mode: Normal Charging, Normal Discharging**

This is the default mode of a storage system. The storage tries to regulate the grid connection. A PV excess is used to charge the storage, while a load is compensated by discharging the
storage. In this mode, battery control does not intervene in the parameters of the storage but sets the default parameters of the storage. This can be, for example, the full
charge and discharge current.

**Storage Mode: Normal Charging, Block Discharging**

In this mode, the storage is prohibited from discharging. Typical ways to implement this mode are:

 * Set the "Maximum Discharge Current" to 0A.
 * Set the "Minimum SoC" to 100%. This only works if the system then does NOT draw power from the grid for charging but only disables discharging.

**Storage Mode: Block Charging, Normal Discharging**

This mode prohibits the storage from charging. The following ways are known to us to implement this mode:

 * Set the "Maximum Charge Current" to 0A.
 * Set the "Maximum Charge Power" to 0W.
 
**Storage Mode: Block Charging, Block Discharging**

In this mode, the storage becomes passive. It does not charge and does not discharge. Ways to implement this are:

 * Set the "Maximum Charge Current" to 0A and the "Maximum Discharge Current" to 0A.
 * Set the "Maximum Charge Power" to 0W and the "Maximum Discharge Power" to 0W.

**Storage Mode: Block Charging, Force Discharging**

This mode is intended to feed power into the grid. The storage does not charge but discharges at the defined power into the grid. Ways to implement this are:

 * Set the "EMS Mode" to "Force Discharge" and set the "Maximum Charge Power" to 0W.
 * Set the "Grid Consumption" to -xW. This discharges the storage at -(xW + house load).

**Storage Mode: Force Charging, Block Discharging**

This mode is used to actively charge from the grid. The storage does not discharge but charges at a defined power. Typical ways to implement this mode are:

 * Set the "EMS Mode" to "Force Charge" and set the "Maximum Discharge Power" to 0W.
 * Set the "Grid Consumption" to xW. This charges the storage at xW - house load.

## Manufacturer-Specific Implementation

The implementation of storage modes varies depending on the manufacturer and device. In the [ESP32-Firmware Git](https://github.com/Tinkerforge/esp32-firmware/tree/master/software/src/modules/batteries_modbus_tcp),
Python files are available for each manufacturer in which the respective register sets used for control are defined.

