---
sidebar_position: 1
---

# Introduction

The Modbus protocol is a communication protocol that exists in
various variants.

The WARP Charger supports [Modbus/TCP](https://de.wikipedia.org/wiki/Modbus)
and acts as a Modbus server. Modbus is disabled by default.
Under the menu item `Interfaces` -> `Modbus/TCP`, Modbus can be activated and
configured.

![image](/img/modbus/modbus_configuration.png)

It is possible to choose between `Disabled`, `Read Only`, and `Read/Write`
access:

![image](/img/modbus/modbus_access.png)

Additionally, the Modbus/TCP port can be set and a register table
can be selected:

![image](/img/modbus/modbus_table.png)

Currently, the [WARP Charger register table](/interfaces/modbus/registertable.mdx) as well as
the register tables of `Bender CC613` and the `Keba C-Series` are supported.

If one of the third-party register tables is selected, the WARP Charger simulates the
corresponding register assignments of Bender and Keba. This allows a WARP
Charger to be integrated into a home automation system or energy manager, etc.
if they have support for one of the two third-party register tables.
