---
sidebar_position: 4
---

# Heizung

Der WARP Energy Manager 2.0 kann eine Wärmepumpe mittels der SG-Ready-Schnittstelle ansteuern. Auf dieser Seite kann dies konfiguriert werden. Im
Normalbetrieb der Wärmepumpe wird diese nicht gesteuert. Mittels SG-Ready kann die Wärmepumpe aber auch
in einen blockierenden Betrieb versetzt werden. Das heißt die Wärmepumpe läuft dann nicht. Alternativ kann die
Heizung auch aufgefordert werden in einem erweiterten Betrieb zu laufen. Je nach Konfiguration der Wärmepumpe
erhöht sie die Zieltemperaturen für Warmwasser und Heizungsvorlauf.

Nachfolgend werden die Einstellungen kurz zusammengefasst. Weitere Informationen und Konfigurationsbeispiele
gibt es in den Hilfetexten im Webinterface.

![image](/img/webinterface/energy_management/wem2-heating1.jpg)

- **Stromzähler**: Hier muss ein zuvor konfigurierter Stromzähler am Netzanschluss ausgewählt werden, damit der PV-Überschuss gemessen werden kann.
- **Mindesthaltezeit**: Mindestzeit für die der Zustand der SG-Ready Ausgänge beibehalten wird.
- **Resthaltezeit**: Hier wird die aktuelle Resthaltezeit für die Ausgänge dargestellt. Dabei handelt es sich um die ablaufende Mindesthaltezeit. Für Tests kann die Resthaltezeit auch zurückgesetzt werden.
- **SG-Ready-Ausgang 1+2**: Konfiguration der Ausgänge.
- **Regelzeit**: Zeitraum, der für die nachfolgenden Regeln betrachtet werden soll.
- **Erweitertes Logging**: Wenn aktiv werden im Ereignis-Log weitere Informationen ausgegeben.

## Erweiterter Betrieb

Der erweiterte Betrieb wird geschaltet,
- immer wenn der Schwellwert zum **PV-Überschuss** überschritten wird (PV-Überschussnutzung).
- oder in einer zeitbasierten Steuerung:
 - **für die günstigsten X Stunden** innerhalb der **Regelzeit**
 - aber nur wenn die **PV-Ertragsprognose** für den betrachteten Zeitraum unter dem eingestellten Schwellwert liegt.

![image](/img/webinterface/energy_management/wem2-heating2.jpg)

## Blockierender Betrieb

Der blockierende Betrieb wird geschaltet,
- in einer zeitbasierten Steuerung:
- **bei den teuersten X Stunden** innerhalb der **Regelzeit**
Wird der Schwellwert des zuvor konfigurierten PV-Überschuss am Netzanschluss überschritten,
so wird der blockierende Betrieb aufgehoben und die Wärmepumpe in den erweiterten Betrieb versetzt.

![image](/img/webinterface/energy_management/wem2-heating3.jpg)

Maximal kann die Summe der konfigurierten Stunden für den erweiterten und dem blockierenden
Betrieb der eingestellten Regelzeit entsprechen. In diesem Fall befindet sich die Wärmepumpe nie im Normalbetrieb.

## Temperatur-Heizkurve

![image](/img/webinterface/energy_management/wem2-heating-curve.png)

Die Temperatur-Heizkurve ermöglicht es, die Anzahl der Stunden für den erweiterten und blockierenden Betrieb automatisch anhand der Tagesmitteltemperatur anzupassen. Dazu werden zwei Temperaturpunkte verwendet: 20 °C (warm) und -10 °C (kalt). Die Stundenanzahl wird zwischen diesen beiden Endpunkten basierend auf der aktuellen Tagesmitteltemperatur linear interpoliert.

Beispiel: Wenn der erweiterte Betrieb für 2 Stunden bei 20 °C und 8 Stunden bei -10 °C konfiguriert ist und die aktuelle Tagesmitteltemperatur 5 °C beträgt, wird der erweiterte Betrieb für 5 Stunden aktiviert.

Für die Nutzung der Heizkurve muss das [Außentemperatur](/docs/webinterface/energy_management/temperatures)-Modul aktiviert sein.

Zusätzlich gibt es die Option **Luft-Wärmepumpe**: Liegt die Tagesmitteltemperatur unter 5 °C, wird der erweiterte Betrieb auf den Zeitraum 09:00–18:00 Uhr begrenzt. Dies wird für Luft-Wärmepumpen empfohlen, die bei niedrigen Außentemperaturen ineffizient arbeiten. So wird verhindert, dass der preisbasierte Plan den erweiterten Betrieb in den kältesten Stunden (Nacht/früher Morgen) aktiviert.

## Status

In diesem Abschnitt wird im Graph dargestellt, wann für den aktuellen Strompreisverlauf
eine Einschaltempfehlung (grün) gegeben und wann die Heizung blockiert wird (rot).
Werden Zeitblöcke nicht markiert, dann befindet sich die Wärmepumpe hier im Normalbetrieb.
Der Heizplan wird so optimiert, dass die eingestellte **Mindesthaltezeit** eingehalten wird.
Es werden also keine einzelnen verstreuten Zeitfenster gewählt, sondern zusammenhängende Blöcke.
Im Graph wird nicht das Einschalten des erweiterten Betriebs für den Fall eines
PV-Überschuss berücksichtigt, sondern nur die zeitbasierte Steuerung.

![image](/img/webinterface/energy_management/wem2-heating4.jpg)

## §14a EnWG

:::note

Die §14a-EnWG-Steuerung wird zentral auf einer eigenen Seite konfiguriert: [§14a EnWG](/docs/webinterface/energy_management/p14a_enwg.md). Dort kann die Heizung als Zielgerät für das §14a-Leistungslimit aktiviert werden.

:::

Wird die Heizung in der [§14a-EnWG-Konfiguration](/docs/webinterface/energy_management/p14a_enwg.md) als Zielgerät aktiviert, so wird bei aktivem Steuersignal der SG-Ready-Ausgang für den blockierenden Betrieb geschaltet, um die Heizung zu sperren.
