---
sidebar_position: 6
---

# Dynamic Tariff

If a dynamic electricity tariff (e.g. via Tibber or Awattar) is available, the dynamic electricity prices can be used to improve the [heating control](/webinterface/energy_management/heater.md) ([WARP Energy Manager](/warp_energy_manager/introduction.md)) and the [charging schedule of Eco Mode](/webinterface/energy_management/eco_mode.md) ([WARP Charger](/warp_charger/introduction.md)).

:::note

Instead of implementing a different interface for each electricity provider, the system retrieves the general electricity exchange data (day-ahead prices) from the European Network of Transmission System Operators for Electricity (ENTSO-E).
The respective dynamic electricity price (from Tibber, Awattar, etc.) is composed of these electricity costs, as well as provider-specific additional costs (grid fees, taxes, price surcharges, VAT).
By configuring these according to the respective provider, the dynamic electricity price of the provider is calculated.
:::

![image](/img/webinterface/energy_management/wem2-dynamic_tarrif1.png)

Required settings are the region and the resolution used by the electricity provider.

Optionally, electricity provider-specific additional costs can be specified. The dynamic exchange electricity prices are only part of the electricity costs. Additional fixed taxes, grid fees, and surcharges apply.

The VAT refers to the VAT applied to the exchange electricity price (currently 19% in Germany). Additional costs can be found in the electricity provider's invoice.

There are three sensible options for the optional settings:

* Leave everything at 0: The net exchange price is displayed,
* Leave VAT at 0 and enter the net price in the fees: The net electricity price including fees is displayed.
* Enter VAT correctly and enter the gross price in the fees: The gross electricity price including fees is displayed.

For regulation, only the dynamic net exchange prices are always used, regardless of the additional costs.

## Status

After the dynamic electricity prices have been configured and activated, there is an overview of the electricity prices further down on the page.

![image](/img/webinterface/energy_management/wem2-dynamic_tarrif2.png)

