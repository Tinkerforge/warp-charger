---
sidebar_position: 8
---

# PV-Ertragsprognose

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />

Wenn eine PV-Anlage vorhanden ist, kann eine PV-Ertragsprognose verwendet werden um die [Heizungssteuerung](/docs/webinterface/energy_management/heater.md) (Energy Manager) und den [Ladeplan des Eco-Modus](/docs/webinterface/energy_management/eco_mode.md) zu verbessern.

![image](/img/webinterface/energy_management/wem2-solar_forecast1.png)

Als Quelle kann zwischen **Automatisch über Prognosedienst** und **Push über API** gewählt werden. Bei der automatischen Variante wird die Prognose von [forecast.solar](https://forecast.solar/) bezogen. Beim Push-Modus werden die Prognosedaten über den API-Endpunkt [solar_forecast/planes/X/forecast_update](/docs/interfaces/mqtt_http/api_reference/solar_forecast) bereitgestellt.

Es können bis zu sechs PV-Flächen mit unterschiedlicher Position und Ausrichtung hinzugefügt werden.

![image](/img/webinterface/energy_management/wem2-solar_forecast-plane.png)

Für jede Fläche müssen folgende Daten für eine erfolgreiche PV-Ertragsprognose bekannt sein:

* Breitengrad,
* Längengrad,
* Neigung,
* Azimut und
* Peak-Leistung der PV-Fläche in kWp.

Zusätzlich kann der Fläche ein Anzeigename gegeben werden.

## Status

Nachdem die PV-Ertragsprognose konfiguert und aktiviert ist, gibt es weiter unten auf der Seite eine Übersicht der Prognose. Die Prognose wird ca. alle 2 Stunden aktualisiert und sollte sich dadurch kontinuierlich verbessern.

![image](/img/webinterface/energy_management/wem2-solar_forecast2.png)
