---
sidebar_position: 8
---

# PV Yield Forecast

:::note

If a PV system is available, a PV yield forecast can be used to improve the [heater control](/webinterface/energy_management/heater.md) (Energy Manager) and the [charging schedule of Eco Mode](/webinterface/energy_management/eco_mode.md).

![image](/img/webinterface/energy_management/wem2-solar_forecast1.png)

The source can be set to either **Automatic via forecast service** or **Push via API**. In the automatic variant, the forecast is obtained from [forecast.solar](https://forecast.solar/). In push mode, the forecast data is provided via the API endpoint [solar_forecast/planes/X/forecast_update](/interfaces/mqtt_http/api_reference/solar_forecast).

Up to six PV surfaces with different positions and orientations can be added.

![image](/img/webinterface/energy_management/wem2-solar_forecast-plane.png)

For each surface, the following data must be known for a successful PV yield forecast:

* Latitude,
* Longitude,
* Tilt,
* Azimuth and
* Peak power of the PV surface in kWp.

Additionally, a display name can be assigned to the surface.

## Status

After the PV yield forecast has been configured and activated, there is an overview of the forecast further down on the page. The forecast is updated approximately every 2 hours and should continuously improve.

![image](/img/webinterface/energy_management/wem2-solar_forecast2.png)
