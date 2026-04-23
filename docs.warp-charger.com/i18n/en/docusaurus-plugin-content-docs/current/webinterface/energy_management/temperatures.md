---
sidebar_position: 9
---

# Outside Temperature


:::note

Outside Temperature is only available for the [WARP Energy Manager 2.0](/warp_energy_manager/introduction).

:::

![image](/img/webinterface/energy_management/wem2-temperatures.png)

The outside temperature module downloads temperature forecasts (minimum, maximum, and daily average) for the configured GPS coordinates. The data is fetched from a weather service every 6 hours and provides forecasts for today and tomorrow.

The daily average temperature is used by the heating module's [temperature heating curve](/webinterface/energy_management/heater#temperature-heating-curve) to automatically adjust extended and blocking operation hours based on outdoor conditions.

## Configuration

- **Source**: Temperature data can either be fetched automatically via a weather service or provided via push through the API. In push mode, no Internet connection is required. The data is delivered via the API endpoint `temperatures/temperatures_update`.
- **Latitude / Longitude**: GPS coordinates of the location in degrees (e.g., 51.8846 / 8.6251).

## Temperature Forecast

For today and tomorrow, the minimum, maximum, and daily average temperature values are displayed. Additionally, a graph showing the hourly temperature progression is shown.
