---
sidebar_position: 8
---

# PV-Ertragsprognose

:::note

Die PV-Ertragsprognose ist in folgende Produkte integriert:

* WARP2 Charger
* WARP3 Charger
* WARP Energy Manager 1.0
* WARP Energy Manager 2.0

:::

Wenn eine PV-Anlage vorhanden ist, kann eine PV-Ertragsprognose von [forecast.solar](https://forecast.solar/) verwendet werden um die [Heizungssteuerung](/warp_energy_manager/heating.md) (Energy Manager) und den [Ladeplan des Eco-Modus](/warp_charger/eco_mode.md) zu verbessern.

Dazu muss das Feature unter `Energiemanagement -> PV-Ertragsprognose` aktiviert werden.

![image](/img/solar_forecast/configuration.png)

Danach können bis zu sechs PV-Flächen mit unterschiedlicher Position und Ausrichtung hinzugefügt werden.

![image](/img/solar_forecast/plane.png)

Für jede Fläche müssen folgende Daten für eine erfolgreiche PV-Ertragsprognose bekannt sein:

* Breitengrad,
* Längengrad,
* Neigung,
* Azimut und
* Peak-Leistung der PV-Fläche in kWp.

Zusätzlich kann der Fläche ein Anzeigename gegeben werden.

## Status

Nachdem die PV-Ertragsprognose konfiguert und aktiviert ist, gibt es weiter unten auf der Seite eine Übersicht der Prognose. Die Prognose wird ca. alle 2 Stunden aktualisiert und sollte sich dadurch kontinuierlich verbessern.

![image](/img/solar_forecast/status.png)