---
sidebar_position: 1
---

# Introduction

With the WARP Energy Manager 1.0, we offer our energy manager for control
cabinet mounting, with which energy consumption at home can be monitored,
controlled and optimized.

![image](/img/wem1/warp-energy-manager.png)

In conjunction with our WARP Charger chargers, the charging of electric
vehicles can be controlled depending on grid consumption and feed-in. Among
other things, this enables PV excess charging or dynamic load management.

## Features

With a three-phase bidirectional energy meter, the WARP Energy Manager 1.0 can
continuously measure the power at the grid connection (e.g. the house
connection). Various meter types and connection types are supported.

### Energy Monitoring

The WARP Energy Manager displays the measured values of the energy meter in its
web interface. It shows how much power is drawn from the grid or fed in (if a photovoltaic system is present). Power and other measured values
are displayed live on the web interface.

Every five minutes, the measured values are saved locally on the energy
manager's microSD card. This makes the WARP Energy Manager independent of data
recording on cloud servers. This data can be displayed graphically for each
day.

Additionally, energy consumption and feed-in are recorded on a daily basis.
This allows energy consumption to be analyzed on a daily, monthly and annual
basis.

### Control of Chargers

The WARP Energy Manager can control WARP Charger chargers depending on
consumption. Up to ten chargers of type WARP Charger Smart, WARP Charger Pro,
WARP2 Charger Smart and WARP2 Charger Pro are supported. Control is via a
network connection (LAN, WiFi) between the chargers and the WARP Energy
Manager.

With various settings, you can define under which conditions and with how much
power vehicles are charged.

### Phase Switching

Using an external contactor, the WARP Energy Manager can switch connected
chargers between single-phase and three-phase operation.

:::note

WARP Charger (1st generation) chargers unfortunately do not support phase
switching.

:::

Phase switching reduces the minimum charging power from approx. 4.1 kW in
three-phase operation (minimum charging current 6 A) to approx. 1.4 kW. This
means that even a small power excess can be used to charge a vehicle. Without
phase switching, charging is not possible with a small power excess and the
excess is fed into the grid. Alternatively, additional power would have to be
drawn from the grid so that charging can start.

### Inputs for Potential-Free Contacts

The WARP Energy Manager has two inputs for potential-free switching contacts.
If phase switching is used, one of these inputs is permanently used for
contactor monitoring. Otherwise, the reaction of the energy manager to the
inputs can be configured. For example, a general charge release can be
implemented or the charging current of the chargers can be limited.

### Potential-Free Relay Output

The potential-free relay switching output of the WARP Energy Manager can be
used to switch external consumers or similar. The output can be configured and
switched, for example, depending on the available power, the current grid
consumption or a completed phase switch.

:::note

The relay cannot switch mains voltage (230 V). Up to 30 V/1 A can be switched.

:::

With a future firmware update, for example, SG-Ready control inputs of heat
pumps can be controlled with this relay output.

### Status LED

The WARP Energy Manager has a status LED on the front. If PV excess charging is
enabled (see [PV Excess Charging](#pv-excess-charging)), this LED visualizes
the state at the grid connection by slowly pulsing or "breathing". The LED
colors are as follows:

- **Green**: Power is fed into the grid
- **Yellow**: Power is drawn from the grid
- **Blue**: "No" power at the grid connection (< ±200 W)

If PV excess charging is not enabled, the LED breathes green. In case of
errors, the status LED blinks (see [Troubleshooting](/docs/wem1/troubleshooting)).

## Typical Applications

### PV Excess Charging

If a photovoltaic system is present, you probably want to use as much of your
own produced electricity as possible. The WARP Energy Manager can help by
enabling pure PV excess charging, in which only excess energy is charged into
the vehicle. Alternatively, a permitted proportional grid consumption can be
defined. This is useful if the self-produced power is not sufficient to start
charging, but you still want to charge.

For PV excess charging, the WARP Energy Manager requires an energy meter at
your grid connection to determine the excess, i.e., the feed-in of electrical
power into the grid. The WARP Energy Manager then controls the chargers so that
no power is fed into the grid (grid consumption = 0) or a defined grid
consumption is maintained. This depends on your settings. See the
[list of compatible energy meters](/docs/compatible_devices/introduction) and
the tutorial on [PV excess charging](/docs/tutorials/pv_excess_charging).

The key point here is that only power regulation takes place; the individual
phase currents are not regulated. Since the grid operator's energy meter, which
determines electricity costs, operates in a balancing manner, phase current
regulation is not necessary.

### Static Load Management

When multiple chargers share a common supply line, the maximum current is often
limited by this supply line. As an example, several chargers could share a
32 A line. Two chargers could each be operated as 11 kW chargers (2 x 16 A).
However, it would also be possible to operate one charger at 22 kW (32 A) if
the second charger is not being used.
[Static load management](/docs/tutorials/chargemanagement) is used for these
applications.

The WARP Energy Manager can handle static load management for the chargers. No
energy meter is necessary here; only the maximum current of the supply line
needs to be defined. This current must be available at all times. The energy
manager distributes the current among the controlled chargers according to
demand.

### Dynamic Load Management

In some cases, [dynamic load management](/docs/tutorials/chargemanagement) at
the phase current level is required. A typical example of this is rental
properties where the grid connection of the property is insufficient to operate
multiple chargers simultaneously. The grid connection protection limits the permissible phase current.

In the simplest case, a certain phase current can be guaranteed for all
chargers. In this case, the chargers can perform static load management, where
the available phase current is divided among the WARP Chargers (see
[Static Load Management](#static-load-management)).

However, often it cannot be guaranteed that a certain phase current is always available for charging processes, as the chargers share the grid connection with other
consumers. When these consumers are switched on and off, the phase current
available for the chargers changes constantly. In this case, dynamic load
management is necessary to ensure that the maximum phase current is not
exceeded and no fuse trips.

The WARP Energy Manager enables dynamic load management at the phase current
level. This requires an energy meter at the grid connection that can be
evaluated by the energy manager. The energy manager monitors the available
phase current from the grid connection and regulates the power of the chargers
accordingly. This ensures that the maximum phase current is not exceeded and no
fuse trips. If a photovoltaic system is present and producing energy, it automatically increases the available power for the energy manager to optimize charging of electric vehicles.

### Combination PV + Load Management

PV excess charging and static or dynamic load management can be combined. The
WARP Energy Manager then operates power regulation for PV excess charging while ensuring that phase current limitations are maintained through charge management.
