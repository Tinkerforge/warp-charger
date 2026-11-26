---
sidebar_position: 12
---

# §9 EEG

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wem1', 'wem2']} />

§9 des Erneuerbare-Energien-Gesetzes (EEG) verpflichtet Betreiber von PV-Anlagen, dem Netzbetreiber die Reduzierung der Einspeiseleistung zu ermöglichen. Der Netzbetreiber gibt dazu über eine Steuerbox ein Leistungslimit vor.

Der WARP Energy Manager empfängt dieses Limit und gibt es über seine Relais an den Wechselrichter weiter. Viele Wechselrichter besitzen dafür einen Eingang für Rundsteuerempfänger (oft DRM oder RSE genannt), über den die Einspeisung in den Stufen 0 %, 30 %, 60 % und 100 % der Nennleistung begrenzt werden kann. Jedes Relais des Energy Managers wird mit dem Kontakt einer Stufe verbunden. Der Energy Manager rechnet das Limit des Netzbetreibers in eine dieser Stufen um und schließt das passende Relais. Automatisierungsregeln sind dafür nicht notwendig.

![image](/img/webinterface/energy_management/p9_eeg.png)

## Anschluss des Wechselrichters

Jedes verwendete Relais wird mit dem Kontakt des Wechselrichters für eine Stufe verbunden, z.B. Relais 1 mit dem Kontakt für 30 % und Relais 2 mit dem Kontakt für 0 %. Welcher Pin des Wechselrichters zu welcher Stufe gehört, steht in der Anleitung des Wechselrichters.

- Es ist immer höchstens ein Relais geschlossen. Beim Wechsel der Stufe wird zuerst das alte Relais geöffnet und danach das neue geschlossen.
- Ist kein Relais geschlossen, gilt immer 100 %. Der Wechselrichter muss so konfiguriert sein, dass er ohne geschlossenen Kontakt mit voller Leistung einspeist. Ein Kontakt für 100 % wird nicht angeschlossen.
- Der WARP Energy Manager 2.0 besitzt zwei Relais, damit stehen neben 100 % zwei weitere Stufen zur Verfügung. Der WARP Energy Manager besitzt ein Relais und damit eine weitere Stufe.

:::note

Relais, die von §9 EEG verwendet werden, können nicht mehr über [Automatisierungsregeln](/docs/webinterface/energy_manager/automation.md) oder die API geschaltet werden.

:::

## Konfiguration

### §9 EEG aktiviert

Aktiviert oder deaktiviert die §9-EEG-Steuerung. Beim Deaktivieren werden die verwendeten Relais geöffnet und wieder freigegeben.

### Signalquelle

Die Signalquelle bestimmt, woher das Limit des Netzbetreibers empfangen wird:

- **EEBUS**: Das Limit wird über den EEBUS-Use-Case **LPP** (Limitation of Power Production) von der Steuerbox des Netzbetreibers empfangen. EEBUS muss dazu zusätzlich unter `Schnittstellen` -> `EEBUS` aktiviert sein. Siehe [EEBUS-Schnittstelle](/docs/interfaces/eebus.md#einspeisebegrenzung).
- **API**: Das Limit wird per HTTP/MQTT-API gesetzt. Details finden sich in der API-Dokumentation unter [`p9_eeg/control_update`](/docs/interfaces/mqtt_http/api_reference/p9_eeg).

### Nennleistung des Wechselrichters

Die AC-Nennleistung des Wechselrichters in Watt. Die Stufen des Wechselrichters beziehen sich auf seine Nennleistung und nicht auf die installierte Modulleistung (kWp). Die Nennleistung steht im Datenblatt des Wechselrichters.

### Relais 1 und Relais 2

Die Stufe, die der Wechselrichter bei geschlossenem Relais einstellt: **0 %**, **30 %**, **60 %** oder **Nicht verwendet**. Hinter jeder Stufe wird die zugehörige Leistung angezeigt. Jede Stufe kann nur einem Relais zugeordnet werden. Mindestens ein Relais muss verwendet werden.

### Standardstufe

Die Stufe, die gilt, solange von der Signalquelle noch kein Limit vorliegt. Zur Auswahl stehen 100 % und die Stufen der verwendeten Relais.

- **API**: Die Standardstufe gilt nach einem Neustart bis zum ersten Aufruf von `p9_eeg/control_update`.
- **EEBUS**: Die Standardstufe gilt, solange EEBUS deaktiviert ist oder noch startet. Zusätzlich ist sie der voreingestellte Failsafe-Wert des Use Cases LPP. Dieser gilt nach einem Neustart und wenn die Verbindung zur Steuerbox abbricht. Hat die Steuerbox selbst einen Failsafe-Wert geschrieben, hat dieser Vorrang.

## Berechnung der Stufe

Der Energy Manager wählt immer die höchste verfügbare Stufe, die das Limit des Netzbetreibers einhält.

Beispiel mit einem Wechselrichter mit 10000 W Nennleistung, Relais 1 auf 30 % und Relais 2 auf 0 %:

| Limit des Netzbetreibers | Stufe | Geschlossenes Relais |
|---|---|---|
| Keine Begrenzung | 100 % | Keines |
| 10000 W und mehr | 100 % | Keines |
| 4200 W | 30 % (3000 W) | Relais 1 |
| 3000 W | 30 % (3000 W) | Relais 1 |
| 2999 W | 0 % (0 W) | Relais 2 |

Liegt das Limit unter der niedrigsten verfügbaren Stufe (z.B. 2000 W, wenn nur 30 % verwendet wird), wird die niedrigste Stufe eingestellt und ein Hinweis angezeigt. In diesem Fall wird das Limit nicht eingehalten. Für eine vollständige Abschaltung muss ein Relais auf 0 % konfiguriert sein.

## Status

Ist §9 EEG aktiviert, wird oben auf der Seite der aktuelle Zustand angezeigt:

- **Status**: Die aktuell eingestellte Stufe, z.B. "Nicht begrenzt (100 %)", "Einspeisung auf 30 % begrenzt" oder "Standardstufe aktiv (100 %)".
- **Angefordertes Limit**: Das von der Signalquelle vorgegebene Limit in Watt (nur bei aktiver Begrenzung).

Zusätzlich erscheint in der Statusanzeige des Webinterfaces (oben rechts, in der App auf der Statusseite) der Eintrag "9 EEG" mit dem aktuellen Zustand.

## Automatisierung

Für weitere Aktionen bei einer Begrenzung, z.B. das Einschalten eines Verbrauchers, steht in den [Automatisierungsregeln](/docs/webinterface/energy_manager/automation.md) die Bedingung **§9 EEG (Einspeisebegrenzung)** zur Verfügung. Sie reagiert auf die Zustände **Begrenzt** und **Nicht begrenzt**. Die Einspeisung gilt als begrenzt, wenn eine Stufe unter 100 % eingestellt ist. Das gilt unabhängig von der Signalquelle, also auch bei Steuerung über die API und für die Standardstufe.

## Weitere Informationen

- [EEBUS-Schnittstelle](/docs/interfaces/eebus.md): Details zur EEBUS-Anbindung
- [§14a EnWG](/docs/webinterface/energy_management/p14a_enwg.md): Begrenzung des Strombezugs steuerbarer Verbrauchseinrichtungen
