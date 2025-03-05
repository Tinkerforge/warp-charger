---
sidebar_position: 3
---

# Fernzugriff

### Einführung
Mit Dem Fernzugriff kann immer und von überall über [my.warp-charger.com](https://my.warp-charger.com) auf einen [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) zugegriffen werden. 
Die Apps (iOS und Android) nutzen den Fernzugriff, so dass dieser auch für die App Nutzung konfiguriert werden muss.

### Funktionsweise und Datenschutz
Kurz und knapp zusammengefasst wird bei jeder Verbindung über den Fernzugriff ein eigenes, verschlüsseltes VPN aufgemacht. Dieses VPN hat nur zwei Teilnehmer, dass Gerät über welches der Fernzugriff geöffnet wird und der WARP Charger/WARP Energy Manager auf den zugegriffen wird. Dadurch können wir sicherstellen, dass nur du Daten von deiner Wallbox abrufen kannst (nichtmal wir können das!).

Alle Daten, bis auf deine E-Mail-Adresse und dein (frei wählbarer) Nutzername werden verschlüsselt auf userem Server gespeichert. So, dass auch wir diese Daten nicht entschlüsseln können.

Eine detailiertere Beschreibung, die auch technisch mehr in die Tiefe geht findest du in userem [Forum](https://www.tinkerunity.org/topic/12365-fernzugriff-alpha).

### Einrichtung
Zuerst wird ein Account unter [my.warp-charger.com](https://my.warp-charger.com) benötigt. Dieser muss angelegt und bestätigt werden.

![image](/img/webinterface/system/warp-system_remote_access.jpeg)

Danach muss der Fernzugriff auf dem jeweiligen Gerät unter `System -> Fernzugriff` aktiviert und die Zugangsdaten eingetragen werden. Anschließend müssen die Einstellungen gespeichert und ein Neustart durchgeführt werden.

### Entfernen aus dem Fernzugriff
Um ein Gerät aus dem Fernzugriff zu entfernen reicht es, wenn der Fernzugriff unter `System -> Fernzugriff` deaktiviert wird. Nach dem Speicherung und Neustarten entfernt sich das Gerät selbstständig aus dem Account, sofern sie eine Verbindung zum Internet hat.

Alternativ gibt es einen Knopf zum Entfernen auf der Übersichtsseite des Fernzugriffs. 

Dabei ist zu beachten, dass das Gerät dabei zwar aus dem Account entfernt und jeglicher Zugang über den Fernzugriff blockiert wird, der Fernzugriff auf der Wallbox selber allerdings aktiviert bleibt.

### iOS App
Unsere iOS App ist im Apple App Store verfügbar: [WARP Charger iOS App](https://apps.apple.com/us/app/warp-by-tinkerforge/id6736695801)

### Android App
Unsere Android App ist im Android Playstore verfügbar: [WARP Charger Android App](https://play.google.com/store/apps/details?id=com.tinkerforge.warp)

