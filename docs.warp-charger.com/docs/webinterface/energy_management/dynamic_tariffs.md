---
sidebar_position: 7
---

# Dynamischer Strompreis

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />


Wenn ein dynamischer Stromtarif (z.B. über Tibber oder Awattar) vorhanden ist, können die dynamischen Strompreise verwendet werden um die [Heizungssteuerung](/webinterface/energy_management/heater.md) ([WARP Energy Manager](/docs/warp_energy_manager/introduction)) und den [Ladeplan des Eco-Modus](/webinterface/energy_management/eco_mode.md) ([WARP Charger](/docs/warp_charger/introduction)) zu verbessern.

:::note

Anstatt für jeden Stromanbieter eine andere Schnittstelle zu implementieren, bezieht das System die allgemeinen Strombörsendaten (Day-Ahead Preise) vom Verband Europäischer Übertragungsnetzbetreiber (ENTSO-E).
Der jeweilige dynamische Strompreis (von Tibber, Awattar o.ä.) setzt sich aus diesen Stromkosten, sowie anbieterspezifischen Zusatzkosten (Netzentgelte, Steuern, Preisaufschläge, MwSt) zusammen.
Konfiguriert man diese dem jeweiligen Anbieter entsprechend, so wird der dynamische Strompreis des Anbieters berechnet.
:::

![image](/img/webinterface/energy_management/wem2-dynamic_tarrif1.png)

Als Quelle kann zwischen **Automatisch über Strombörse** und **Push über API** gewählt werden. Bei der automatischen Variante werden die Day-Ahead-Preise von [ENTSO-E](https://www.entsoe.eu/about/) bezogen. Beim Push-Modus werden die Preisdaten über den API-Endpunkt [day_ahead_prices/prices_update](/docs/interfaces/mqtt_http/api_reference/day_ahead_prices) bereitgestellt.

Bei der automatischen Quelle sind Region und Auflösung zu konfigurieren.

Optional können stromanbieterspezfische Zusatzkosten angeben werden. Die dynamischen Börsenstrompreise sind nur ein Teil der Strom­kosten. Es fallen zu­sätzliche fixe Steuern, Netzentgelte und Aufschläge an.

Die MwSt bezieht sich auf die MwSt die auf den Börsenstrompreis anfällt (in DE aktuell 19%). Weitere Zusatzkosten können in der Rechnung des Stromanbieters nachgeschaut werden.

Es gibt drei sinnvolle Möglichkeiten für die optionalen Einstellungen:

* Alles auf 0 lassen: Es wird der Netto-Börsenpreis angezeigt,
* MwSt auf 0 lassen und bei den Gebühren den Nettopreis eintragen: Es wird der Netto-Strom­preis inkl. Gebühren angezeigt.
* MwSt korrekt eintragen und bei den Gebühren den Bruttopreis eintragen: Es wird der Brutto-Strom­preis inkl. Gebühren angezeigt.

Zur Regelung werden unabhängig von den Zusatzkosten immer nur die dyna­mischen Netto-Börsenpreise verwendet.

## Preiskalender

Der Preiskalender ermöglicht es, feste Preise bzw. Preisaufschläge pro Wochentag und Viertelstunde zu definieren. Dies ist besonders nützlich zur Umsetzung von **Modul 3 nach § 14a EnWG** (zeitvariable Netzentgelte).

Der Preiskalender kann in zwei Modi verwendet werden:

* **In Kombination mit dem dynamischen Strompreis**: Die Kalenderpreise werden als Aufschläge zu den Day-Ahead-Börsenstrompreisen addiert.
* **Ohne dynamischen Strompreis (Standalone)**: Wenn der dynamische Strompreis deaktiviert ist, werden die Kalenderpreise direkt als Strompreise verwendet. So kann ein fester Preisverlauf pro Wochentag definiert werden, z.B. für Tarife mit festen Hoch- und Niedertarifzeiten.

### Konfiguration

Um den Preiskalender zu aktivieren, wird der Schalter "Preiskalender" aktiviert. Es erscheint daraufhin eine Kalenderansicht mit einer Wochenübersicht (Montag bis Sonntag) in Viertelstundenauflösung (96 Zeitfenster pro Tag).

Über die Schaltfläche **Kalender bearbeiten** öffnet sich ein Dialog in dem die Preise eingetragen werden können:

1. **Zellen auswählen**: Durch Klicken und Ziehen können ein oder mehrere Zeitfenster ausgewählt werden.
2. **Preis eingeben**: Im Eingabefeld wird der gewünschte Preis in ct/kWh eingegeben.
3. **Übernehmen**: Mit Klick auf "Übernehmen" wird der eingegebene Preis auf alle ausgewählten Zellen angewendet.
4. **Speichern**: Mit Klick auf "Speichern" wird der Kalender übernommen.

Die Zellen werden farblich kodiert dargestellt.

### Beispiel: Modul 3 nach § 14a EnWG

Modul 3 sieht zeitvariable Netzentgelte vor. In der Praxis bedeutet das, dass in Schwachlastzeiten (z.B. nachts) reduzierte und in Hochlastzeiten (z.B. abends) erhöhte Netzentgelte gelten.

Um dies abzubilden, werden die Netzentgeltdifferenzen im Kalender eingetragen. Wenn beispielsweise das Netzentgelt in den Schwachlastzeiten 3 ct/kWh niedriger und in den Hochlastzeiten 2 ct/kWh höher ist als der Normaltarif, werden -3 und +2 in die entsprechenden Zeitfenster eingetragen. Diese Aufschläge werden dann automatisch zu den Day-Ahead-Preisen addiert.

## Status

Nachdem die dynamischen Strompreise konfiguriert und aktiviert sind, gibt es weiter unten auf der Seite eine Übersicht der Strompreise.

![image](/img/webinterface/energy_management/wem2-dynamic_tarrif2.png)

Im Preisdiagramm wird der Strompreisverlauf für heute und morgen angezeigt. Wenn sowohl der Börsenstrompreis als auch der Preiskalender aktiviert sind, werden die beiden Anteile (Börsenstrompreis und Kalenderpreis) im Diagramm separat und gestapelt dargestellt.
