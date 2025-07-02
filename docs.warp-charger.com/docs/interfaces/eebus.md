---
sidebar_position: 4
---

# EEBus

:::note

Coming soon! - Diese Schnittstelle befindet sich zur Zeit in der Entwicklung. Die Unterstützung von EEBus wird mittels Softwareupdate zur Verfügung gestellt.

:::

EEBus ist ein Kommunikationsstandard der unter anderem zukünftig von Energienetzebereibern genutzt werden solli, um die Last für das Stromnetz reduzieren zu können. EEBus soll daher genutzt werden
um die Verbrauchseinrichtungen (z.B. Wallboxen), die unter den [§14a EnWG](/docs/tutorials/verbrauchseinrichtung) fallen zu steuern. EEBus ist standardisiert, allerdings stellen sich noch viele Detailfragen hinsichtlich
der genauen Implentierung seitens der Netzbetreiber. Wir entwickeln daher zur Zeit die EEBus Schnittstelle, warten aber noch auf Informationen und Testmöglichkeit seitens der Netzbetreiber.

EEBus definiert verschiedene Use Cases. Für die Steuerung vom Netzbetreiber wird der LPC (Limitation of Power Consumption) Use Case benötigt. Dieser wird zur Zeit von uns implementiert.

Für die Steuerung von HEMS werden andere Use Cases seitens EEBus definiert. Leider scheinen die HEMS Hersteller nicht wirklich mitzuteilen, welche UseCases sie unterstützen. Für den Bereich E-Mobility definiert EEBus zum Beispiel die Use-Cases: Coordinated EV Charging, Overload Protection by EV Charging Current Curtailment, Optimization of Self-Consumption during EV Charging, EV Charging Electricity Measurement, EV Charging Summary, EV Commissioning and Configuration, EVSE Commissioning and Configuration. In einem zweiten Schritt werden wir Anfangen Use Cases aus dem E-Mobility Bereich zu implementieren.
