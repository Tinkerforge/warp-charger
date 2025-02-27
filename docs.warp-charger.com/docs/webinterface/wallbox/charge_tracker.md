---
sidebar_position: 3
---

# Ladetracker

![image](/img/webinterface/wallbox/warp-charge_tracker.jpeg)

Der WARP3 Charger zeichnet alle durchgeführten Ladevorgänge auf.
Pro Ladevorgang werden die folgenden Informationen gespeichert:
 * Startdatum und Zeit des Ladevorgangs, falls Datum und Zeit bekannt sind.
 * Benutzer, der den Ladevorgang gestartet hat, falls bekannt.
 * Zählerstand beim Start und Ende des Ladevorgangs (nur WARP3 Charger Pro). Hieraus wird die geladene Energie in kWh berechnet.
 * Dauer des Ladevorgangs
 
Aus diesen Informationen und dem konfigurierten Strompreis werden die Kosten der Ladevorgänge berechnet.
Die Kosten werden nicht pro Ladevorgang aufgezeichnet, sondern anhand des konfigurierten Strompreises berechnet.
Das heißt insbesondere, dass, wenn der Strompreis geändert wird, auch die angezeiten Kosten älterer Ladevorgänge geändert werden.

Damit Ladevorgänge einem Benutzer zugeordnet werden können, muss
 * mindestens ein Benutzer angelegt sein und die Ladefreigabe der Benutzerverwaltung aktiviert sein.
 * dem Benutzer ein [NFC-Tag](/docs/webinterface/users/nfc-tags) zugeordnet sein
 
Im Werkszustand sind drei Benutzer mit je einem NFC-Tag eingerichtet. Es muss dann nur die Ladefreigabe unter [Benutzerverwaltung](/docs/webinterface/users/user_management) aktiviert werden.
Diese Informationen werden nur auf dem WARP3 Charger gespeichert. Aufgezeichnete Ladevorgänge können im Webinterface auf der Ladetracker-Unterseite entweder als ***PDF***, oder als ein ***CSV***-Dokument, kompatibel zu üblichen
Tabellenkalkulationsprogrammen, heruntergeladen werden. Außerdem kann das erzeugte Dokument vorgefiltert werden, um beispielsweise nur Ladevorgänge eines bestimmten Benutzers in einem festgelegten Zeitraum zu erhalten.
Werden die Ladevorgänge als PDF heruntergeladen, so kann zusätzlich ein ***Briefkopf*** angegeben werden. Dieser kann maximal 6 Zeilen zu je 50 Zeichen umfassen. Der Briefkopf wird in der PDF so hinterlegt, dass er bei üblicher
Faltung im Fenster eines Briefumschlags sichtbar ist.

Werden die Ladevorgänge als CSV heruntergeladen, kann zwischen zwei Formaten gewählt werden:
 * Excel-kompatibel Erzeugt eine CSV-Datei, die ohne Importkonfiguration von Excel geladen werden kann. Der Feldtrenner ist ein Semikolon, in der ersten Zeile wird dies (für andere Sprachversionen) mit sep=; ¨ markiert. Die Datei wird Windows-1252 kodiert, deshalb sind möglicherweise nicht alle Benutzernamen
darstellbar.
 * RFC4180 Erzeugt eine CSV-Datei die nach RFC4180 formatiert ist. Der Feldtrenner ist ein Komma, die Datei wird UTF-8 kodiert.

Der WARP3 Charger kann bis zu 7680 Ladevorgänge aufzeichnen.

![image](/img/webinterface/wallbox/warp-charge_tracker2.jpeg)
