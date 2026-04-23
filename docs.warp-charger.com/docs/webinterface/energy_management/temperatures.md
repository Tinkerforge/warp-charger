---
sidebar_position: 11
---

# Außentemperatur

:::note

Außentemperatur ist nur für den [WARP Energy Manager 2.0](/docs/warp_energy_manager/introduction) verfügbar.

:::

![image](/img/webinterface/energy_management/wem2-temperatures.png)

Das Außentemperatur-Modul lädt Temperaturvorhersagen (Minimum, Maximum und Tagesmittel) für die konfigurierten GPS-Koordinaten herunter. Die Daten werden alle 6 Stunden von einem Wetterdienst abgerufen und liefern Vorhersagen für heute und morgen.

Die Tagesmitteltemperatur wird vom Heizungsmodul für die [Temperatur-Heizkurve](/docs/webinterface/energy_management/heater.md#temperatur-heizkurve) verwendet, um die Stunden für erweiterten und blockierenden Betrieb automatisch an die Außenbedingungen anzupassen.

## Konfiguration

- **Quelle**: Temperaturdaten können entweder automatisch über einen Wetterdienst bezogen oder per Push über die API bereitgestellt werden. Im Push-Modus ist keine Internetverbindung erforderlich. Die Daten werden über den API-Endpunkt `temperatures/temperatures_update` geliefert.
- **Breitengrad / Längengrad**: GPS-Koordinaten des Standorts in Grad (z.B. 51,8846 / 8,6251).

## Temperaturvorhersage

Für heute und morgen werden jeweils die Werte für Minimum, Maximum und Tagesmitteltemperatur angezeigt. Zusätzlich wird ein Graph mit dem stündlichen Temperaturverlauf dargestellt.
