---
sidebar_position: 8
---

# Eco Mode

With Eco Mode it is possible to optimize charging processes economically and ecologically.
The planning takes into account dynamic electricity prices, PV yield forecasts, and the
desired departure time as well as maximum parking duration of the electric vehicle.

Based on the planning, an optimized charging schedule is created. For Eco Mode,
it is necessary to configure the charger as a charge manager. If multiple
chargers are managed, individual charging schedules are created for all
managed chargers.

## Configuration

![image](/img/webinterface/energy_management/warp-eco_mode1.png)

When charge scheduling is enabled, the configurable charging schedule is displayed on the status page.
The following can be configured:

* The maximum parking duration,
* a price lower limit (`Always charge when price below`),
* a price upper limit (`Never charge when price above`) and
* a lower limit for the PV yield forecast (`Only if PV yield forecast below`).

The maximum parking duration specifies for how many hours after connecting a vehicle a charging schedule is created. Example: It is 08:00, the charging schedule is configured as `Use the cheapest 4 hours until Today at 20:00` and the maximum parking duration is set to 8 hours. In this case, the charging schedule would ensure that the cheapest 4 hours are used before the maximum parking duration expires (e.g. until 16:00 if the car is plugged in at 08:00, but until 18:00 if the car is plugged in at 10:00). With this configuration, for example, the working hours of employees can be taken into account.

The price lower limit specifies a price in cents below which charging is always enabled, regardless of the charging schedule. It is compared with the net exchange electricity price (without any configured additional costs).

The price upper limit specifies a price in cents above which charging is never enabled, regardless of the charging schedule. It is compared with the net exchange electricity price (without any configured additional costs).

The lower limit for the PV yield forecast specifies a threshold in kilowatt-hours above which charging is only enabled with PV excess (the charging schedule is ignored). Example: `Only if PV yield forecast below` is configured to 75 kWh/day and the PV yield forecast for today is 80 kWh/day. In this case, the charging schedule would not be executed and charging would only occur when PV excess is available. Therefore, no electricity is purchased, even if it would be very cheap, when it is known that sufficient PV excess will be available.

To use charge scheduling, [Dynamic Tariff](/webinterface/energy_management/dynamic_tariffs.md) must be enabled. If the PV yield forecast should be included, [PV Yield Forecast](/webinterface/energy_management/solar_forecast.md) must additionally be enabled.

## Configurable Charging Schedule (Status Page)

When Eco Mode is enabled and an Eco charging mode is selected on the status page, a configurable charging schedule appears:

![image](/img/webinterface/energy_management/warp-eco_mode2.png)

In the charging schedule, the departure can be configured to

* `Today`,
* `Tomorrow` or
* `Daily`

and a departure time as well as charging duration can be specified.

When Eco Mode is enabled on a load manager, the charging schedule is automatically applied to all managed WARP Chargers. The individual charging schedules are also displayed on the status page:

![image](/img/webinterface/energy_management/warp-eco_mode3.png)

## Example Configurations

Below are examples of useful configurations.

### Example Configuration 1: The car should have charged for at least 5 hours when I drive to work in the morning.

In this case, the following configuration of the WARP Charger would be useful:

* Departure `Tomorrow` until `08:00` with charging duration `5 hours`.

If in this example the electric vehicle is plugged in at 15:00, Eco Mode calculates which 5 hours until tomorrow 08:00 are the cheapest and charges accordingly during these hours. PV excess charging is naturally prioritized (if configured).

### Example Configuration 2: In a company with multiple chargers, each employee should be able to charge during the cheapest 3 hours per day.

In this case, the following configuration of the load manager would be useful:

* Departure `Daily` until `23:59` with charging duration `3 hours`.
* Parking duration (in the Eco Mode configuration) `8 hours`.

If in this example an employee connects to a WARP Charger and authenticates via NFC, their parking duration of 8 hours begins. Eco Mode would then calculate which are the cheapest 3 hours within these 8 hours and use them for charging. Here too, PV excess charging (if configured) is prioritized.

This configuration ensures that each employee receives an individual charging schedule. Both the employee who starts at 06:00 and the employee who starts at 10:00 receive the cheapest hours (within their respective working hours, which are assumed to be 8 hours here).
