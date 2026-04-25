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
- **Eingang des WARP Energy Managers** (nur Energy Manager): Das Signal wird über einen der vier Eingänge des WARP Energy Managers empfangen. Der Rundsteuerempfänger oder die Steuerbox wird an einen Eingang des Energy Managers angeschlossen.
- **EEBUS**: Das Steuersignal wird über die [EEBUS-Schnittstelle](/docs/interfaces/eebus) empfangen. EEBUS kann als Schnittstelle zur Steuerung von Verbrauchseinrichtungen durch Netzbetreiber genutzt werden.
- **API**: Das Steuersignal wird per HTTP/MQTT-API empfangen. Details zur API finden sich in der API-Dokumentation unter `p14a_enwg/control_update`.

### Eingang (nur bei Signalquelle "Eingang des Energy Managers")

Wählt den Eingang (1–4) des WARP Energy Managers, an dem der Rundsteuerempfänger oder die Steuerbox angeschlossen ist.

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
| ab 9 | 0,45 | 18900 W + n × 0,45 × 4200 W |

### Aktiv bei

Bestimmt, bei welchem Zustand des Eingangs das Leistungslimit aktiv wird:

- **Geschlossen**: Das Limit wird angewendet, wenn der Eingang geschlossen ist (Standardkonfiguration).
- **Geöffnet**: Das Limit wird angewendet, wenn der Eingang geöffnet ist.

### Zielgeräte

In diesem Abschnitt wird konfiguriert, auf welche Verbraucher das Leistungslimit angewendet werden soll:

- **Diese Wallbox** (nur WARP Charger): Wendet das Leistungslimit auf die lokale Wallbox an.
- **Verwaltete Wallboxen**: Wendet das Leistungslimit auf alle über das Lastmanagement verwalteten Wallboxen an.
- **Heizung** (nur Energy Manager): Wendet das Leistungslimit auf die angeschlossene Heizung (Wärmepumpe via SG-Ready) an. Wird die Heizung als Zielgerät aktiviert, kann zusätzlich die **Max. Leistung Heizung** konfiguriert werden.

### Max. Leistung Heizung (nur Energy Manager)

Gibt die maximale Leistungsaufnahme der Heizungsanlage in Watt an.

## Unterschiede zwischen WARP Charger und Energy Manager

| | WARP Charger | Energy Manager |
|---|---|---|
| **Signalquelle "Eingang"** | Abschalteingang der Wallbox | Eingang 1–4 des Energy Managers |
| **Eingangsauswahl** | Nicht verfügbar (nur ein Eingang) | Eingang 1–4 wählbar |
| **Diese Wallbox** | Verfügbar | Nicht verfügbar |
| **Heizung** | Nicht verfügbar | Verfügbar |
| **Max. Leistung Heizung** | Nicht verfügbar | Verfügbar |

## Weitere Informationen

- [Steuerbare Verbrauchseinrichtung nach §14a EnWG (Tutorial)](/docs/tutorials/verbrauchseinrichtung.md) — Übersicht über die verschiedenen Möglichkeiten zur Umsetzung
- [Heizung](/docs/webinterface/energy_management/heater.md) — Konfiguration der SG-Ready-Steuerung
- [EEBUS-Schnittstelle](/docs/interfaces/eebus) — Details zur EEBUS-Anbindung
