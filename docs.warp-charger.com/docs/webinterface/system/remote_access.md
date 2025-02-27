---
sidebar_position: 3
---

# Fernzugriff

### Einführung
Mit Dem Fernzugriff kannst du immer und von überall über [my.warp-charger.com](https://my.warp-charger.com) auf deinen [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) zugreifen. 

### Funktionsweise und Datenschutz
Kurz und knapp zusammengefasst wird bei jeder Verbindung über den Fernzugriff ein eigenes, verschlüsseltes VPN aufgemacht. Dieses VPN hat nur zwei Teilnehmer, dass Gerät über welches du den Fernzugriff öffnest und deinen WARP Charger/WARP Energy Manager. Dadurch können wir sicherstellen, dass nur du Daten von deiner Wallbox abrufen kannst (nichtmal wir können das!).

Alle Daten, bis auf deine E-Mail-Adresse und dein (frei wählbarer) Nutzername werden verschlüsselt auf userem Server gespeichert. So, dass auch wir diese Daten nicht entschlüsseln können.

Eine detailiertere Beschreibung, die auch technisch mehr in die Tiefe geht findest du in userem [Forum](https://www.tinkerunity.org/topic/12365-fernzugriff-alpha).

### Einrichtung
Zuerst brauchst du einen Account unter [my.warp-charger.com](https://my.warp-charger.com). Bitte beachte, dass du diesen auch bestätigen musst.

![image](/img/webinterface/system/warp-system_remote_access.jpeg)

Danach aktivierst du den Fernzugriff auf deinem WARP Charger unter `System -> Fernzugriff`, trägst einfach deine Zugangsdaten ein, speicherst und startest die Wallbox neu.

### Entfernen aus dem Fernzugriff
Um deinen WARP Charger aus dem Fernzugriff zu entfernen reicht es, wenn du den Fernzugriff unter `System -> Fernzugriff` deaktivierst, speicherst und neustartest. Die Wallbox entfernt sich dabei selbstständig aus deinem Account, sofern sie eine Verbindung zum Internet hat.

Alternativ gibt es einen Knopf zum Entfernen auf der Übersichtsseite des Fernzugriffs. Bitte beachte, dass dein WARP Charger dabei zwar aus deinem Account entfernt und jeglicher Zugang über den Fernzugriff blockiert wird, der Fernzugriff auf der Wallbox selber bleibt allerdings aktiviert.

### iOS App
Unsere iOS App ist im Apple App Storte verfügbar: [WARP Charger iOS App](https://apps.apple.com/us/app/warp-by-tinkerforge/id6736695801)

### Android App

Unsere Android App ist im Android Playstore verfügbar: [WARP Charger Android App](https://play.google.com/store/apps/details?id=com.tinkerforge.warp)

