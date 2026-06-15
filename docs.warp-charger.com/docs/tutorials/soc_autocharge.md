---
sidebar_position: 7
---

# SoC und Autocharge

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc4']} />

Dieses Tutorial zeigt Schritt für Schritt, wie die SoC-Anzeige (Ladestand des Fahrzeugs)
und Autocharge eingerichtet werden.

* **SoC-Anzeige:** Die Wallbox liest den Ladestand (State of Charge) des Fahrzeugs aus
  und schätzt ihn während des Ladevorgangs fort.
* **Autocharge:** Die automatische Ladefreigabe per Fahrzeugidentifikation. Die Wallbox
  erkennt das Fahrzeug anhand seiner MAC-Adresse und gibt den Ladevorgang automatisch
  frei, ohne dass ein NFC-Tag benötigt wird.

Beide Funktionen nutzen die ISO-15118-Kommunikation zwischen Fahrzeug und Wallbox und
sind daher nur beim WARP4 Charger verfügbar. Voraussetzung ist ein Fahrzeug, das die
ISO-15118-Kommunikation unterstützt.

Wie diese Kommunikation im Detail abläuft, welche Standards es dafür gibt und was der
WARP Charger aktuell unterstützt, erklärt der Artikel
[ISO 15118 Details](/docs/tutorials/iso15118_details).

Der grundsätzliche Ablauf ist:

1. SoC-Auslesen und/oder Autocharge aktivieren.
2. Fahrzeug anschließen, damit es von der Wallbox erkannt wird.
3. Das erkannte Fahrzeug als Fahrzeug-Profil anlegen.
4. Das Fahrzeug einem Benutzer zuordnen (für Autocharge mit Ladefreigabe und
   Ladelogbuch).

## Schritt 1: SoC-Auslesen und/oder Autocharge aktivieren

Im Webinterface unter `Wallbox` -> `ISO 15118` werden die ISO-15118-Funktionen aktiviert:

* **Autocharge** aktivieren, um die automatische Ladefreigabe per Fahrzeugidentifikation
  zu nutzen.
* **SoC auslesen** aktivieren, um den Ladestand des Fahrzeugs anzuzeigen. Diese Funktion
  benötigt den eingebauten Stromzähler des WARP4 Charger Pro.

![image](/img/tutorials/soc_autocharge/iso15118_settings.png)

Weitere Informationen hierzu gibt es in der Webinterface-Dokumentation:
[ISO 15118](/docs/webinterface/wallbox/iso15118).

## Schritt 2: Fahrzeug anschließen

Schließe nun das Fahrzeug an die Wallbox an. Beim Verbinden kommuniziert die Wallbox kurz
mit dem Fahrzeug, um dessen eindeutige Netzwerkkennung (MAC-Adresse) auszulesen. Dieser
Vorgang dauert je nach Fahrzeug etwa 5 bis 20 Sekunden.

Wird zusätzlich der Ladestand ausgelesen, kann dies je nach Fahrzeug etwa 10 bis 45
Sekunden dauern.

:::note

Damit das Fahrzeug erkannt wird, muss es mindestens einmal mit der Wallbox verbunden
gewesen sein, nachdem Autocharge bzw. das SoC-Auslesen aktiviert wurde.

:::

## Schritt 3: Erkanntes Fahrzeug als Profil anlegen

Wechsle nun im Webinterface zu `Benutzer` -> `Fahrzeuge` und klicke auf den +-Button, um
ein neues Fahrzeug-Profil anzulegen.

Im sich öffnenden Fenster werden unter **Zuletzt gesehene MACs** die kürzlich von der
Wallbox erkannten Fahrzeug-MAC-Adressen aufgelistet. Das in Schritt 2 angeschlossene
Fahrzeug sollte hier erscheinen. Durch Klicken auf den +-Button neben der Adresse wird
diese direkt in das Feld *MAC-Adresse* übernommen.

![image](/img/tutorials/soc_autocharge/add_vehicle.png)

Trage anschließend die restlichen Angaben ein:

* **Name:** Ein frei wählbarer Name zur Identifikation des Fahrzeugs.
* **Wechselnde Adresse:** Aktiviere diese Option, falls das Fahrzeug einen Teil seiner
  MAC-Adresse zwischen Ladevorgängen ändert (z.B. bei VW ID-Modellen). Dann wird nur der
  feste vordere Teil der Adresse zur Identifikation verwendet.
* **Batteriekapazität** und **Ladeeffizienz:** Diese Werte werden zur Schätzung des
  Ladestands verwendet. Die Standardwerte (60 kWh, 92 %) können bei Bedarf an das
  Fahrzeug angepasst werden.

Speichere das Profil und starte die Wallbox neu.

Weitere Informationen hierzu gibt es in der Webinterface-Dokumentation:
[Fahrzeuge](/docs/webinterface/users/vehicles).

:::info

Für die reine SoC-Anzeige ist die Einrichtung damit abgeschlossen. Sobald das Fahrzeug
verbunden ist, werden Name und Ladestand auf der Seite *Fahrzeuge*, bei den Stromzählern
und auf der Status-Seite angezeigt. Für Autocharge folgt noch Schritt 4.

:::

## Schritt 4: Fahrzeug einem Benutzer zuordnen

Damit per Autocharge freigegebene Ladevorgänge einem Benutzer zugeordnet werden und dessen
individuelle Ladestromgrenze angewendet werden kann, wird das Fahrzeug einem Benutzer zugeordnet.

Wechsle dazu zu `Benutzer` -> `Benutzerverwaltung` und lege einen neuen Benutzer an oder
bearbeite einen bestehenden. Im Abschnitt **Fahrzeuge** kann über den +-Button das zuvor
angelegte Fahrzeug-Profil ausgewählt und dem Benutzer zugeordnet werden.

![image](/img/tutorials/soc_autocharge/assign_user.png)

Damit Ladevorgänge tatsächlich nur für berechtigte Fahrzeuge freigegeben werden, muss
zusätzlich die **Ladefreigabe** in der Benutzerverwaltung aktiviert werden, analog zur
Freigabe per NFC-Tag. Ist die Ladefreigabe nicht aktiviert, lädt jedes Fahrzeug. Das
zugeordnete Fahrzeug wird dann nur zur Zuordnung im Ladelogbuch verwendet.

:::note

Wird die zentrale Verwaltung eines Lastmanagers verwendet, ist die Ladefreigabe
automatisch aktiv: Ladevorgänge an den kontrollierten Wallboxen werden dann ohnehin nur
nach Authentifizierung freigegeben. Die (lokale) Ladefreigabe muss in diesem Fall nicht
zusätzlich aktiviert werden. Siehe
[Wallboxen](/docs/webinterface/energy_management/wallboxes).

:::

Weitere Informationen hierzu gibt es in der Webinterface-Dokumentation:
[Benutzerverwaltung](/docs/webinterface/users/user_management).

## Ergebnis

Nach der Einrichtung erkennt die Wallbox das Fahrzeug beim Anschließen automatisch:

* Der Ladevorgang wird per Autocharge freigegeben (bei aktivierter Ladefreigabe nur für
  bekannte, zugeordnete Fahrzeuge) und im Ladelogbuch dem zugeordneten Benutzer
  zugeschrieben.
* Der Ladestand des Fahrzeugs wird ausgelesen, geschätzt und angezeigt.
