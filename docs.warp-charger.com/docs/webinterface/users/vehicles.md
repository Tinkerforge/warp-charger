---
sidebar_position: 3
---

# Fahrzeuge

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc4']} />

Auf der Seite *Fahrzeuge* können Fahrzeug-Profile angelegt werden. Ein Fahrzeug-Profil
ordnet einem Fahrzeug einen Namen sowie weitere Eigenschaften anhand seiner
MAC-Adresse zu. Die MAC-Adresse ist eine eindeutige Netzwerkkennung, die die Wallbox
beim Verbinden eines Fahrzeugs per ISO 15118 (SLAC) ausliest.

Fahrzeug-Profile werden für zwei Funktionen verwendet:

* **Autocharge:** Die automatische Ladefreigabe per Fahrzeugidentifikation.
  Wird das Profil einem
  Benutzer zugeordnet, können Ladevorgänge diesem Benutzer im Ladelogbuch zugeordnet
  und dessen individuelle Ladestromgrenze angewendet werden.
* **Ladestand-Schätzung:** Anhand der konfigurierten Batteriekapazität und Ladeeffizienz
  wird der Ladestand (State of Charge, SoC) während des Ladevorgangs geschätzt.

:::note

Die Fahrzeugidentifikation per MAC-Adresse setzt voraus, dass die Wallbox per ISO 15118
mit dem Fahrzeug kommunizieren kann und die Option *Autocharge* in den
[ISO-15118-Einstellungen](/docs/webinterface/wallbox/iso15118#autocharge) aktiviert ist.

:::

![image](/img/webinterface/users/warp-users-vehicles1.png)

## Aktuell verbundenes Fahrzeug

Im oberen Bereich der Seite wird das aktuell verbundene Fahrzeug angezeigt. Ist kein
Fahrzeug verbunden, ist der Bereich eingeklappt.

Sobald ein Fahrzeug verbunden ist, werden folgende Informationen angezeigt:

* **Aktuell verbunden:** Der Name des passenden Fahrzeug-Profils. Ist kein Profil
  hinterlegt, wird stattdessen die MAC-Adresse des Fahrzeugs angezeigt.
* **MAC-Adresse:** Die ausgelesene MAC-Adresse des verbundenen Fahrzeugs (nur bei
  bekanntem Fahrzeug).
* **Ladestand:** Der geschätzte Ladestand, sofern dieser ausgelesen bzw. geschätzt werden konnte.
* **Batteriekapazität** und **Ladeeffizienz:** Die für die Schätzung verwendeten Werte
  aus dem Fahrzeug-Profil (nur bei bekanntem Fahrzeug).

:::info

Der Ladestand wird zu Beginn eines Ladevorgangs einmalig per ISO 15118 vom Fahrzeug
ausgelesen (Option *SoC auslesen* in den ISO-15118-Einstellungen) und anschließend
während des Ladens anhand der geladenen Energie sowie der im Profil hinterlegten
Batteriekapazität und Ladeeffizienz fortgeschrieben. Hierfür wird der eingebaute
Stromzähler des WARP4 Charger Pro benötigt.

:::

## Fahrzeug-Profile

In der Tabelle *Fahrzeug-Profile* werden alle angelegten Fahrzeuge mit Name, MAC-Adresse,
Kapazität und Effizienz aufgelistet. Es können bis zu 16 Fahrzeug-Profile angelegt werden.

Ein bestehendes Profil kann über das Stift-Symbol bearbeitet oder über das Mülleimer-Symbol
gelöscht werden. Ein neues Profil wird über den +-Button hinzugefügt.

### Fahrzeug-Profil hinzufügen

Beim Hinzufügen oder Bearbeiten eines Profils öffnet sich ein Modalfenster mit den
folgenden Eingabefeldern.

![image](/img/webinterface/users/warp-users-vehicles2.png)

* **Zuletzt gesehene MACs:** Hier werden MAC-Adressen von Fahrzeugen aufgelistet, die
  kürzlich mit der Wallbox verbunden waren, inklusive Angabe, wann sie zuletzt gesehen
  wurden. Durch Klicken auf den +-Button neben einer Adresse wird diese direkt in das
  Feld *MAC-Adresse* übernommen. Ist eine angezeigte MAC bereits einem Profil zugeordnet,
  wird dies entsprechend gekennzeichnet.

  Falls dieser WARP Charger ein Lastmanager für mehrere Wallboxen ist und die zentrale
  Verwaltung aktiviert ist (siehe Abschnitt
  [Wallboxen](/docs/webinterface/energy_management/wallboxes)), werden hier auch
  MAC-Adressen aufgelistet, die von einer der kontrollierten Wallboxen gesehen wurden.
  In diesem Fall wird zusätzlich der Ladecontroller angegeben, an dem das Fahrzeug
  gesehen wurde.
* **Name:** Ein frei wählbarer Name zur Identifikation des Fahrzeugs (maximal 16 Zeichen).
* **MAC-Adresse:** Die MAC-Adresse des Fahrzeugs im Format `AA:BB:CC:DD:EE:FF`. Üblicherweise
  wird diese über die Liste *Zuletzt gesehene MACs* übernommen, sie kann aber auch manuell
  eingegeben werden.
* **Wechselnde Adresse:** Manche Fahrzeuge ändern einen Teil ihrer MAC-Adresse zwischen
  Ladevorgängen (z.B. VW ID-Modelle). Ist dieser Schalter aktiviert, wird nur der feste
  vordere Teil der Adresse (die ersten drei Blöcke, der Herstellerteil) zur Identifikation
  verwendet; die hinteren Blöcke werden als `XX:XX:XX` dargestellt und ignoriert.
* **Batteriekapazität:** Die Netto-Batteriekapazität des Fahrzeugs in kWh.
  Dieser Wert wird zur Schätzung des Ladestands verwendet.
* **Ladeeffizienz:** Das Verhältnis von im Fahrzeug gespeicherter zu von der Wallbox
  gelieferter Energie in Prozent (Standardwert: 92 %). Wenn die Ladeeffizienz nicht
  bekannt ist, ist 92 % ein guter Startwert. Dieser Wert kann jederzeit angepasst werden.


## Zusammenspiel mit Autocharge

Damit ein passendes Fahrzeug-Profil tatsächlich zur automatischen Ladefreigabe führt,
muss die Funktion *Autocharge* in den ISO-15118-Einstellungen aktiviert sein. Ist
Autocharge aktiv, liest die Wallbox beim Verbinden eines Fahrzeugs dessen MAC-Adresse
aus und verwendet diese als Identifikationsquelle für die Ladefreigabe, analog zu einem
NFC-Tag.

Ist das passende Profil einem Benutzer zugeordnet, wird der Ladevorgang diesem Benutzer
zugeordnet.


## Zuordnung zu Benutzern

Ein Fahrzeug-Profil kann einem Benutzer zugeordnet werden, sodass per Autocharge
freigegebene Ladevorgänge diesem Benutzer im Ladelogbuch zugeschrieben und dessen
individuelle Ladestromgrenze angewendet wird. Die Zuordnung erfolgt nicht auf dieser
Seite, sondern in der [Benutzerverwaltung](/docs/webinterface/users/user_management#fahrzeuge)
beim Anlegen bzw. Bearbeiten des jeweiligen Benutzers.
