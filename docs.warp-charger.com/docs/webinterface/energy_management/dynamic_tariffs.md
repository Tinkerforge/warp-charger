---
sidebar_position: 6
---

# Dynamischer Strompreis

Wenn ein dynamischer Stromtarif (z.B. über Tibber oder Awattar) vorhanden ist, können die dynamischen Strompreise verwendet werden um die [Heizungssteuerung](/webinterface/energy_management/heater.md) ([WARP Energy Manager](/docs/warp_energy_manager/introduction)) und den [Ladeplan des Eco-Modus](/webinterface/energy_management/eco_mode.md) ([WARP Charger](/docs/warp_charger/introduction)) zu verbessern.


![image](/img/webinterface/energy_management/wem2-dynamic_tarrif1.png)

Notwendige Einstellungen sind die Region und die Auflösung welche vom Stromanbieter verwendet werden.

Optional können stromanbieterspezfische Zusatzkosten angeben werden. Die dynamischen Börsenstrompreise sind nur ein Teil der Strom­kosten. Es fallen zu­sätzliche fixe Steuern, Netzentgelte und Aufschläge an.

Die MwSt bezieht sich auf die MwSt die auf den Börsenstrompreis anfällt (in DE aktuell 19%). Weitere Zusatzkosten können in der Rechnung des Stromanbieters nachgeschaut werden.

Es gibt drei sinnvolle Möglichkeiten für die optionalen Einstellungen:

* Alles auf 0 lassen: Es wird der Netto-Börsenpreis angezeigt,
* MwSt auf 0 lassen und bei den Gebühren den Nettopreis eintragen: Es wird der Netto-Strom­preis inkl. Gebühren angezeigt.
* MwSt korrekt eintragen und bei den Gebühren den Bruttopreis eintragen: Es wird der Brutto-Strom­preis inkl. Gebühren angezeigt.

Zur Regelung werden unabhängig von den Zusatzkosten immer nur die dyna­mischen Netto-Börsenpreise verwendet.

## Status

Nachdem die dynamischen Strompreise konfiguriert und aktiviert sind, gibt es weiter unten auf der Seite eine Übersicht der Strompreise.

![image](/img/webinterface/energy_management/wem2-dynamic_tarrif2.png)

