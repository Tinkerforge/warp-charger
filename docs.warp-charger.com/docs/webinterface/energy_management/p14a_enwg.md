---
sidebar_position: 11
---

# §14a EnWG

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />


§14a des Energiewirtschaftsgesetzes (EnWG) ermöglicht es Netzbetreibern, den Strombezug steuerbarer Verbrauchseinrichtungen (Wallboxen, Wärmepumpen, Batteriespeicher, Klimaanlagen) temporär zu reduzieren, um eine Überlastung des lokalen Stromnetzes zu vermeiden. Die Geräte werden dabei nie vollständig abgeschaltet. Eine Mindestleistung von 4200 W bleibt stets verfügbar.

Auf dieser Seite wird die zentrale §14a-EnWG-Steuerung konfiguriert. Abhängig von der gewählten Signalquelle wird bei Empfang eines Steuersignals das berechnete Leistungslimit automatisch auf die konfigurierten Verbraucher (Wallboxen und/oder Heizung) angewendet.

:::note

Die §14a-EnWG-Steuerung ist auf dem WARP Charger und dem WARP Energy Manager verfügbar. Je nach Gerät stehen unterschiedliche Signalquellen und Zielgeräte zur Verfügung.

:::

![image](/img/webinterface/energy_management/p14a_enwg.png)

## Konfiguration

### §14a EnWG aktiviert

Aktiviert oder deaktiviert die §14a-EnWG-Steuerung. Ist die Steuerung deaktiviert, werden keine Leistungslimits angewendet.

### Signalquelle

Die Signalquelle bestimmt, woher das Steuersignal des Netzbetreibers empfangen wird. Es stehen folgende Optionen zur Verfügung:

- **Abschalteingang der Wallbox** (nur WARP Charger): Das Signal wird über den potentialfreien Abschalteingang innerhalb der Wallbox empfangen. Ein Rundsteuerempfänger oder eine Steuerbox des Netzbetreibers wird hierzu direkt an den Abschalteingang angeschlossen.
- **Eingang des WARP Energy Manager** (nur Energy Manager): Das Signal wird über einen der Eingänge des WARP Energy Managers empfangen (WARP Energy Manager 2.0: vier Eingänge, WARP Energy Manager: zwei Eingänge). Der Rundsteuerempfänger oder die Steuerbox wird an einen Eingang des Energy Managers angeschlossen.
- **EEBUS**: Das Steuersignal wird über die [EEBUS-Schnittstelle](/docs/interfaces/eebus) empfangen. EEBUS kann als Schnittstelle zur Steuerung von Verbrauchseinrichtungen durch Netzbetreiber genutzt werden. EEBUS muss dazu zusätzlich unter `Schnittstellen` -> `EEBUS` aktiviert sein. Das Leistungslimit gibt in diesem Fall die Steuerbox vor.
- **API**: Das Steuersignal wird per HTTP/MQTT-API empfangen. Details zur API finden sich in der API-Dokumentation unter [`p14a_enwg/control_update`](/docs/interfaces/mqtt_http/api_reference/p14a_enwg). Das Leistungslimit wird dabei mit übergeben.

Die folgenden Einstellungen **Eingang**, **Geräteanzahl** und **Aktiv bei** werden nur angezeigt, wenn als Signalquelle ein Eingang (Abschalteingang der Wallbox bzw. Eingang des WARP Energy Manager) gewählt ist.

### Eingang (nur Energy Manager)

Wählt den Eingang des WARP Energy Managers, an dem der Rundsteuerempfänger oder die Steuerbox angeschlossen ist.

### Geräteanzahl

Anzahl der steuerbaren Verbrauchseinrichtungen, die über das Energiemanagementsystem gesteuert werden. Die Mindestleistung für ein einzelnes Gerät beträgt 4200 W. Bei mehreren Geräten wird die Mindestleistung mit Gleichzeitigkeitsfaktoren berechnet:

**4200 W + (Anzahl der Geräte − 1) × Gleichzeitigkeitsfaktor × 4200 W**

| Geräteanzahl | Gleichzeitigkeitsfaktor | Berechnetes Limit |
|---|---|---|
| 1 | — | 4200 W |
| 2 | 0,80 | 7560 W |
| 3 | 0,75 | 10500 W |
| 4 | 0,70 | 13020 W |
| 5 | 0,65 | 15120 W |
| 6 | 0,60 | 16800 W |
| 7 | 0,55 | 18060 W |
| 8 | 0,50 | 18900 W |
| 9 | 0,45 | 19320 W |
| ab 10 | 0,45 | 4200 W + (n − 1) × 0,45 × 4200 W |

### Aktiv bei

Bestimmt, bei welchem Zustand des Eingangs das Leistungslimit aktiv wird:

- **Geschlossen**: Das Limit wird angewendet, wenn der Eingang geschlossen ist (Standardkonfiguration).
- **Geöffnet**: Das Limit wird angewendet, wenn der Eingang geöffnet ist.

### Zielgeräte

In diesem Abschnitt wird konfiguriert, auf welche Verbraucher das Leistungslimit angewendet werden soll:

- **Diese Wallbox** (nur WARP Charger): Wendet das Leistungslimit auf die lokale Wallbox an.
- **Kontrollierte Wallboxen**: Wendet das Leistungslimit auf alle vom Lastmanagement [kontrollierten Wallboxen](/docs/webinterface/energy_management/wallboxes#kontrollierte-wallboxen) an. Dazu muss dieses Gerät das Lastmanagement der Wallboxen übernehmen.
- **Heizung** (nur WARP Energy Manager 2.0): Wendet das Leistungslimit auf die angeschlossene Heizung (Wärmepumpe via SG-Ready) an.

### Max. Leistung Heizung (nur WARP Energy Manager 2.0)

Gibt die maximale Leistungsaufnahme der Heizungsanlage in Watt an. Die Einstellung ist für eine spätere Einbindung der Heizung in das Lastmanagement vorgesehen und wird aktuell noch nicht ausgewertet.

## Status

Ist die §14a-EnWG-Steuerung aktiviert, wird oben auf der Seite der aktuelle Zustand angezeigt:

- **Status**: Zeigt an, ob das Leistungslimit gerade aktiv ist ("Aktiv") oder nicht ("Inaktiv").
- **Aktuelles Limit**: Zeigt das aktuell angewendete Leistungslimit in Watt an (nur bei aktivem Limit).

Zusätzlich erscheint in der Statusanzeige des Webinterfaces (oben rechts, in der App auf der Statusseite) der Eintrag "14a EnWG" mit dem Zustand, z.B. "Aktiv (4200 W)".

:::tip

Zum Testen der Konfiguration kann **Aktiv bei** kurzzeitig auf **Geöffnet** gestellt und gespeichert werden. Solange die Steuerbox kein Signal gibt, ist der Eingang geöffnet und das Limit wird sofort aktiv. Anschließend die Einstellung wieder auf **Geschlossen** zurückstellen und speichern.

:::

## Unterschiede zwischen WARP Charger und Energy Manager

| | WARP Charger | Energy Manager |
|---|---|---|
| **Signalquelle "Eingang"** | Abschalteingang der Wallbox | Eingang des WARP Energy Manager |
| **Eingangsauswahl** | Nicht verfügbar (nur ein Eingang) | Eingang 1-4 (WARP Energy Manager: 1-2) |
| **Diese Wallbox** | Verfügbar | Nicht verfügbar |
| **Heizung** | Nicht verfügbar | Verfügbar (WARP Energy Manager 2.0) |
| **Max. Leistung Heizung** | Nicht verfügbar | Verfügbar (WARP Energy Manager 2.0) |

## Weitere Informationen

- [Steuerbare Verbrauchseinrichtung nach §14a EnWG (Tutorial)](/docs/tutorials/verbrauchseinrichtung.md) — Übersicht über die verschiedenen Möglichkeiten zur Umsetzung
- [Heizung](/docs/webinterface/energy_management/heater.md) — Konfiguration der SG-Ready-Steuerung
- [EEBUS-Schnittstelle](/docs/interfaces/eebus) — Details zur EEBUS-Anbindung
