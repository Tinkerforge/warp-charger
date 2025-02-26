---
sidebar_position: 3
---

# Heizung

Die Heizungssteuerung kann auf dem Energy Manager 2.0 unter *Energiemanagement* -> *Heizung* gefunden werden.
Es kann die Ansteuerung einer Wärmepumpe mittels der SG-Ready-Schnittstelle konfiguriert werden. Im
Normalbetrieb der Wärmepumpe wird diese nicht gesteuert. Mittels SG-Ready kann die Wärmepumpe aber auch
in einen blockierenden Betrieb versetzt werden. Das heißt die Wärmepumpe läuft dann nicht. Alternativ kann die
Heizung auch aufgefordert werden in einem erweiterten Betrieb zu laufen. Je nach Konfiguration der Wärmepumpe
erhöht sie die Zieltemperaturen für Warmwasser und Heizungsvorlauf.

Nachfolgend werden die Einstellungen kurz zusammengefasst. Weitere Informationen und Konfigurationsbeispiele
gibt es in den Hilfetexten im Webinterface.

![image](/img/wem2_shared_with_manual/web_heating1.jpg)

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

![image](/img/wem2_shared_with_manual/web_heating2.jpg)

## Blockierender Betrieb

Der blockierende Betrieb wird geschaltet,
- in einer zeitbasierten Steuerung:
- **bei den teuersten X Stunden** innerhalb der **Regelzeit**
Wird der Schwellwert des zuvor konfigurierten PV-Überschuss am Netzanschluss überschritten,
so wird der blockierende Betrieb aufgehoben und die Wärmepumpe in den erweiterten Betrieb versetzt.

![image](/img/wem2_shared_with_manual/web_heating3.jpg)

Maximal kann die Summe der konfigurierten Stunden für den erweiterten und dem blockierenden
Betrieb der eingestellten Regelzeit entsprechen. In diesem Fall befindet sich die Wärmepumpe nie im Normalbetrieb.

## Status

In diesem Abschnitt wird im Graph dargestellt, wann für den aktuellen Strompreisverlauf
eine Einschaltempfehlung (grün) gegeben und wann die Heizung blockiert wird (rot).
Werden Zeitblöcke nicht markiert, dann befindet sich die Wärmepumpe hier im Normalbetrieb.
Im Graph wird nicht das Einschalten des erweiterten Betriebs für den Fall eines
PV-Überschuss berücksichtigt, sondern nur die zeitbasierte Steuerung.

![image](/img/wem2_shared_with_manual/web_heating4.jpg)

## §14a EnWG

Soll der SG-Ready Ausgang für den blockierenden Betrieb genutzt werden um auf Grund von
**S14a EnWG** die Heizung zu sperren, so kann in diesem Abschnitt der entsprechende
Eingang des WARP Energy Managers gewählt werden.

![image](/img/wem2_shared_with_manual/web_heating5.jpg)
