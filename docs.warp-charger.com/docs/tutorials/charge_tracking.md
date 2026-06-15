---
sidebar_position: 2
---

# Einrichten des Ladelogbuchs

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc1', 'wc2', 'wc3', 'wc4']} />

## Funktionsweise

Der WARP Charger zeichnet alle durchgeführten Ladevorgänge auf. Pro
Ladevorgang werden die folgenden Informationen gespeichert:

* Startdatum und Zeit des Ladevorgangs, falls Datum und Zeit bekannt
sind.
* Benutzer, der den Ladevorgang gestartet hat, falls bekannt.
* Zählerstand beim Start und Ende des Ladevorgangs (nur WARP Charger Pro).
Hieraus wird die geladene Energie in  kWh berechnet.
* Dauer des Ladevorgangs.

Aus diesen Informationen und dem konfigurierten Strompreis werden die
Kosten der Ladevorgänge berechnet. Die Kosten werden nicht pro
Ladevorgang aufgezeichnet, sondern anhand des konfigurierten
Strompreises berechnet. Das heißt insbesondere, dass, wenn der
Strompreis geändert wird, auch die angezeiten Kosten älterer
Ladevorgänge geändert werden.

Diese Informationen werden lokal auf dem WARP Charger gespeichert.
Es wird kein Internetzugang oder eine Cloud o.ä. benötigt und die
Daten werden nicht an dritte übertragen.


## Konfiguration Ladefreigabe, Nutzer und NFC-Tags

:::info
Falls mehrere Wallboxen die gleichen Benutzer/NFC-Tags verwenden sollen,
ist es ausreichend die Benutzer und NFC-Tags auf dem Lastmanager zu konfigurieren.
Es sollten dann zunächst das Lastmanagement konfiguriert und die zentrale Verwaltung aktiviert werden,
siehe [Lastmanagement](/tutorials/chargemanagement.md)

Die Ladefreigabe der Benutzerverwaltung muss dann nicht aktiviert werden.

Ladevorgänge werden im Ladelogbuch des Lastmanagers aufgezeichnet und den Benutzern zugeordnet.
:::

Damit Ladevorgänge einem Benutzer zugeordnet werden können, muss

* mindestens ein Benutzer angelegt sein und die Lade­freigabe der
Benutzerverwaltung aktiviert sein und
* dem Benutzer ein NFC-Tag zugeordnet sein.

Im Werkszustand sind drei Benutzer mit je einem NFC-Tag eingerichtet. Die
NFC-Tags sind Teil des Lieferumfangs der Wallbox
Die Benutzer können unter `Benutzer` -> `Benutzerverwaltung` bearbeitet werden.

Weitere Informationen hierzu gibt es in der Webinterface-Dokumentation: [Benutzerverwaltung](/webinterface/users/user_management.md)

![image](/img/tutorials/charge_tracking/user_configuration.png)

Im Screenshot haben wir die Ladefreigabe aktiviert. Mit aktivierter Ladefreigabe
muss eine Ladung ist erst per NFC freigegeben werden bevor die Wallbox
die Ladung startet.

Außerdem wurde zusätzlich zu den vorangelegten Benutzern einen "Doku-Nutzer"
hinzugefügt der im auf 16A Ladestrom begrenzt ist.
Dafür einfach auf das "+" unten rechts klicken und einen
Benutzernamen, einen Anzeigenamen und den maximalen Ladestrom für diesen Nutzer
eintragen.

![image](/img/tutorials/charge_tracking/user_configuration_2.png)

Hier können dem Benutzer außerdem NFC-Tags zugeordnet werden.
Die WARP Charger unterstützen dabei die NFC Kartentypen
Mifare Classic und NFC-Forum-Typ-1 bis -5.

Es können beliebige NFC-Tags von den unterstützten Typen angelernt werden
(z.B. die Zutrittskarte vom Fitnessstudio).

Zum Hinzufügen eines NFC-Tags wieder auf das "+" unten rechts klicken.

![image](/img/tutorials/charge_tracking/nfc_configuration.png)

Im Tag-hinzufügen-Fenster werden die zuletzt erkannten NFC-Tags angezeigt.
D.h. man kann zum Anlernen eines Tags einfach das Tag vor der Konfiguration
einmal an die Wallbox halten um es dann hier auszuwählen.

Im Beispiel ordnen wir dem "Doku-Nutzer" ein NFC-Forum-Typ2-Tag zu.

![image](/img/tutorials/charge_tracking/nfc_configuration_done.png)

Nach dem Hinzufügen muss noch gespeichert werden und danach kennt die
Wallbox einen neuen Benutzer der auch vom Ladelogbuch genutzt wird.

## Ladelog-Export als PDF oder CSV

Aufgezeichnete Ladevorgänge können im Webinterface unter
`Wallbox` -> `Ladetracker` entweder als PDF, oder als ein CSV-Dokument,
kompatibel zu üblichen Tabellenkalkulationsprogrammen, heruntergeladen
werden. Außerdem kann das erzeugte Dokument vorgefiltert werden, um
beispielsweise nur Ladevorgänge eines bestimmten Benutzers in einem
festgelegten Zeitraum zu erhalten.

![image](/img/tutorials/charge_tracking/charge_tracker_export.png)

Werden die Ladevorgänge als PDF heruntergeladen, so kann zusätzlich ein
Briefkopf angegeben werden. Dieser kann maximal 6 Zeilen zu je 50
Zeichen umfassen. Der Briefkopf wird in der PDF so hinterlegt, dass er
bei üblicher Faltung im Fenster eines Briefumschlags sichtbar ist.

An dieser Stelle können auch Informationen zum Firmenfahrzeug o.ä.
eingetragen werden. So ist sichergestellt dass das Ladelogbuch zu
unterschiedlichsten Unternehmensrichtlinien zum Abrechnen von
Firmen-Elektrofahrzeugen kompatibel ist.

Ein Beispiel-PDF-Ladelog kann unter
https://www.warp-charger.com/documents/beispiel_ladelog.pdf
heruntergeladen werden.

Werden die Ladevorgänge als CSV heruntergeladen, kann zwischen zwei
Formaten gewählt werden:

**Excel-kompatibel**: Erzeugt eine CSV-Datei, die ohne Importkonfiguration von Excel
geladen werden kann. Der Feldtrenner ist ein Semikolon, in der
ersten Zeile wird dies (für andere Sprachversionen) mit sep=;
markiert. Die Datei wird Windows-1252 kodiert, deshalb sind
möglicherweise nicht alle Benutzernamen darstellbar.

**RFC4180**: Erzeugt eine CSV-Datei die nach RFC4180 formatiert ist. Der
Feldtrenner ist ein Komma, die Datei wird UTF-8 kodiert.

## Ladelog ansehen

Weiter unten auf der `Ladetracker`-Unterseite können die letzten 30
Ladevorgänge auch direkt eingesehen werden.

![image](/img/tutorials/charge_tracking/charge_tracker_records.png)

Weitere Informationen hierzu gibt es in der Webinterface-Dokumentation: [Ladetracker](/webinterface/wallbox/charge_tracker.md)
