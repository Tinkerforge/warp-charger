---
sidebar_position: 3
---

# Fernzugriff

## Einführung
Mit Dem Fernzugriff kann immer und von überall über [my.warp-charger.com](https://my.warp-charger.com) auf einen [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) zugegriffen werden.
Die Apps (iOS und Android) nutzen den Fernzugriff, so dass dieser auch für die App Nutzung konfiguriert werden muss.

## Funktionsweise und Datenschutz
Kurz und knapp zusammengefasst wird bei jeder Verbindung über den Fernzugriff ein eigenes, verschlüsseltes VPN aufgemacht. Dieses VPN hat nur zwei Teilnehmer, das Gerät, über welches der Fernzugriff geöffnet wird und der WARP Charger/WARP Energy Manager auf den zugegriffen wird. Dadurch können wir sicherstellen, dass nur du Daten von deiner Wallbox abrufen kannst (nichtmal wir können das!).

Alle Daten, bis auf deine E-Mail-Adresse und dein (frei wählbarer) Nutzername werden verschlüsselt auf userem Server gespeichert. So, dass auch wir diese Daten nicht entschlüsseln können.

Eine detailiertere Beschreibung, die auch technisch mehr in die Tiefe geht findest du in userem [Forum](https://www.tinkerunity.org/topic/12365-fernzugriff-alpha).

## Einrichtung
Zuerst wird ein Account unter [my.warp-charger.com](https://my.warp-charger.com) benötigt. Dieser muss angelegt und bestätigt werden.

Das Gerät muss nach dem Hinzufügen des ersten Nutzers neugestartet werden. Nach dem Hinzufügen weiterer Nutzer ist kein Neustart mehr notwendig.

![image](/img/webinterface/system/warp-system_remote_access.jpeg)

### Mit Zugangsdaten
Über den "+" Button das Menü zum Hinzufügen eines Fernzugriff-Nutzers öffnen, die Zugangsdaten zum Account eintragen (die Daten werden nicht gespeichert),
auf "Hinzufügen" klicken.

### Mit Authorisierungstoken
Das Hinzufügen eines Accounts mit einem Authorisierungstoken geht schneller, da das Authorisierungstoken bereits alle benötigten Informationen enthält.

Authorisierungstoken können auf der entsprechenden [Unterseite](https://my.warp-charger.com/tokens) erstellt werden.

Um des Gerätes mittels Authorisierungstoken zu registrieren muss im Menü zum Hinzufügen die Option "Authorisierungstoken" ausgewählt werden.
Im Anschluss das Authorisierungstoken in das entsprechende Feld kopieren und auf "Hinzufügen klicken".

## Entfernen aus dem Fernzugriff
Um ein Gerät temporär aus dem Fernzugriff zu entfernen reicht es, wenn der Fernzugriff unter `System -> Fernzugriff` deaktiviert wird.

Wenn ein Nutzer dauerhaft vom Gerät entfernt werden soll kann diesüber den "Löschen"-Knopf neben der E-Mail-Adresse getan werden.
Der Zugriff des Nutzers ist damit bereits entfernt. Um dies mit dem Server zu synchronisieren muss das Gerät neu gestartet werden.

Alternativ gibt es einen Knopf zum Entfernen auf der Übersichtsseite des Fernzugriffs.
Dabei ist zu beachten, dass das Gerät dabei zwar aus dem Account entfernt und jeglicher Zugang über den Fernzugriff blockiert wird, der Fernzugriff auf der Wallbox selber allerdings aktiviert bleibt.

## iOS App
Unsere iOS App ist im Apple App Store verfügbar: [WARP Charger iOS App](https://apps.apple.com/us/app/warp-by-tinkerforge/id6736695801)

## Android App
Unsere Android App ist im Android Playstore verfügbar: [WARP Charger Android App](https://play.google.com/store/apps/details?id=com.tinkerforge.warp)

## Recovery Seite
Die Recovery Seite der Wallbox/des Energy Managers kann auch über den Fernzugriff aufgerufen werden. Dazu ist ein Gerät mit Tastatur erforderlich.
Mit der Tastenkombination Strg + Shift + Alt + R kann die Recovery Seite geladen werden während eine Verbindung besteht. Sollte das nicht funktionieren
muss eventuell der Fokus vom Webinterface genommen werden, indem der Footer einmal mit der Maus angeklickt wird.
