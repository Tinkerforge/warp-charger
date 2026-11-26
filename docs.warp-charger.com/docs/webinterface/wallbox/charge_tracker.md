---
sidebar_position: 3
---

# Ladetracker

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc1', 'wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />


![image](/img/webinterface/wallbox/charge_tracker.png)

Der WARP Charger zeichnet alle durchgeführten Ladevorgänge auf.

Ein WARP Charger oder WARP Energy Manager, der als Lastmanager mit zentraler Verwaltung auftritt, zeichnet alle Ladevorgänge kontrollierter Wallboxen auf.

Pro Ladevorgang werden die folgenden Informationen gespeichert:
 * Startdatum und Zeit des Ladevorgangs, falls Datum und Zeit bekannt sind.
 * Benutzer, der den Ladevorgang gestartet hat, falls bekannt.
 * Zählerstand beim Start und Ende des Ladevorgangs (nur bei Wallboxen mit Stromzähler, z.B. WARP Charger Pro). Hieraus wird die geladene Energie in kWh berechnet.
 * Dauer des Ladevorgangs
 * Wallbox, an der geladen wurde (bei zentraler Verwaltung durch einen Lastmanager)

Es können bis zu 32768 Ladevorgänge aufgezeichnet werden.

## Strompreis

Aus den aufgezeichneten Informationen und dem konfigurierten Strompreis werden die Kosten der Ladevorgänge berechnet.
Die Kosten werden nicht pro Ladevorgang aufgezeichnet, sondern anhand des konfigurierten Strompreises berechnet.
Das heißt insbesondere, dass, wenn der Strompreis geändert wird, auch die angezeigten Kosten älterer Ladevorgänge geändert werden.

Es wird immer der hier konfigurierte Strompreis verwendet. Ein [dynamischer Strompreis](/docs/webinterface/energy_management/dynamic_tariffs) wird nicht berücksichtigt.
Außerdem wird immer die gesamte ins Fahrzeug geladene Energie aufgezeichnet, unabhängig von ihrer Herkunft (Netzanschluss, Batteriespeicher, PV, etc.).

## Zuordnung zu Benutzern

Damit Ladevorgänge einem Benutzer zugeordnet werden können, muss
 * mindestens ein Benutzer angelegt sein und entweder die Ladefreigabe der Benutzerverwaltung oder die zentrale Verwaltung des Lastmanagers aktiviert sein.
 * dem Benutzer ein [NFC-Tag](/docs/webinterface/users/user_management#nfc-freigabe) oder beim WARP4 Charger ein [Fahrzeug](/docs/webinterface/users/vehicles#zuordnung-zu-benutzern) zugeordnet sein. Ladevorgänge, die per Autocharge freigegeben werden, werden dem Benutzer des erkannten Fahrzeugs zugeordnet.

Im Werkszustand sind drei Benutzer mit je einem NFC-Tag eingerichtet. Es muss dann nur die Ladefreigabe unter [Benutzerverwaltung](/docs/webinterface/users/user_management) aktiviert werden.

## E-Mail-Versand

Ist der [Fernzugriff](/docs/webinterface/system/remote_access) eingerichtet, kann das Ladelog automatisch per E-Mail an Fernzugriffsbenutzer gesendet werden.
Am Anfang jedes Monats wird das Ladelog des vergangenen Monats an die konfigurierten Benutzer gesendet. Es wird erst gesendet, wenn die Uhrzeit synchronisiert ist und gerade kein Ladevorgang läuft.
Der Zeitpunkt des nächsten Versands wird unter **Nächster Versand** angezeigt.

Es können bis zu fünf Fernzugriffsbenutzer konfiguriert werden. Pro Benutzer können Benutzerfilter, Wallbox-Filter, Dateiformat, Sprache, **Leere Ladevorgänge ausblenden** und je nach Dateiformat Briefkopf bzw. CSV-Format eingestellt werden.
Mit **Test-Versand** kann im Dialog sofort ein Ladelog an den ausgewählten Benutzer gesendet werden.

:::note

Die per E-Mail gesendeten Ladelogs sind aus technischen Gründen nicht Ende-zu-Ende-verschlüsselt.

:::

## Ladelog herunterladen

Aufgezeichnete Ladevorgänge können entweder als ***PDF*** oder als ***CSV***-Dokument, kompatibel zu üblichen Tabellenkalkulationsprogrammen, heruntergeladen werden.
Das erzeugte Dokument kann vorgefiltert werden:
 * **Benutzerfilter**: Nur Ladevorgänge eines bestimmten Benutzers, aller konfigurierten Benutzer oder gelöschter Benutzer.
 * **Wallbox-Filter**: Nur Ladevorgänge einer bestimmten Wallbox, aller kontrollierten Wallboxen oder gelöschter Wallboxen. Relevant bei zentraler Verwaltung durch einen Lastmanager.
 * **Zeitfilter**: Nur Ladevorgänge in einem bestimmten Zeitraum.
 * **Leere Ladevorgänge ausblenden**: Ladevorgänge, bei denen höchstens 1 Wh geladen wurde, werden nicht übernommen.

Unter **Sprache** wird ausgewählt, ob das Dokument auf Deutsch oder Englisch erzeugt wird.

Werden die Ladevorgänge als PDF heruntergeladen, so kann zusätzlich ein ***Briefkopf*** angegeben werden. Dieser kann maximal 6 Zeilen zu je 50 Zeichen umfassen. Der Briefkopf wird in der PDF so hinterlegt, dass er bei üblicher
Faltung im Fenster eines Briefumschlags sichtbar ist.

Werden die Ladevorgänge als CSV heruntergeladen, kann zwischen zwei Formaten gewählt werden:
 * **Excel-kompatibel**: Erzeugt eine CSV-Datei, die ohne Importkonfiguration von Excel geladen werden kann. Der Feldtrenner ist ein Semikolon, in der ersten Zeile wird dies (für andere Sprachversionen) mit `sep=;` markiert. Die Datei wird Windows-1252 kodiert, deshalb sind möglicherweise nicht alle Benutzernamen
darstellbar.
 * **RFC 4180**: Erzeugt eine CSV-Datei die nach RFC 4180 formatiert ist. Der Feldtrenner ist ein Komma, die Datei wird UTF-8 kodiert.

Ist der Fernzugriff eingerichtet, kann das Dokument mit **E-Mail senden an** statt es herunterzuladen auch direkt an einen Fernzugriffsbenutzer gesendet werden.

## Aufgezeichnete Ladevorgänge

![image](/img/webinterface/wallbox/charge_tracker2.png)

Hier werden die Anzahl der aufgezeichneten Ladevorgänge und der Startzeitpunkt des ältesten aufgezeichneten Ladevorgangs angezeigt.
Unter **Letzte Ladevorgänge** werden die letzten 30 Ladevorgänge mit Benutzer, Startzeitpunkt, geladener Energie, Dauer und Wallbox angezeigt. Ist ein Strompreis konfiguriert, werden zusätzlich die Kosten angezeigt.

Mit **Ladevorgänge löschen** werden alle aufgezeichneten Ladevorgänge und der Benutzernamen-Verlauf gelöscht. Danach wird das Gerät neu gestartet. Diese Aktion kann nicht rückgängig gemacht werden.
