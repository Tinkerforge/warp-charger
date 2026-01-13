---
sidebar_position: 4
---

# EEBus

:::note

Coming soon! - This interface is currently in development. Support for EEBus will be provided via software update.

:::

EEBus is a communication standard that will be used in the future by energy network operators, among others, to reduce the load on the power grid. EEBus is therefore intended to be used
to control controllable consumption devices (e.g. wallboxes) that fall under [§14a EnWG](/tutorials/verbrauchseinrichtung.md). EEBus is standardized, but many detailed questions remain regarding
the exact implementation by the grid operators. We are therefore currently developing the EEBus interface, but are still waiting for information and testing opportunities from the grid operators.

EEBus defines various use cases. For control by the grid operator, the LPC (Limitation of Power Consumption) use case is required. This is currently being implemented by us.

For HEMS (Home Energy Management System) control, other use cases are defined by EEBus. Unfortunately, HEMS manufacturers do not seem to clearly communicate which use cases they support. For the E-Mobility area, EEBus defines, for example, the use cases: Coordinated EV Charging, Overload Protection by EV Charging Current Curtailment, Optimization of Self-Consumption during EV Charging, EV Charging Electricity Measurement, EV Charging Summary, EV Commissioning and Configuration, EVSE Commissioning and Configuration. In a second step, we will start implementing use cases from the E-Mobility area.
