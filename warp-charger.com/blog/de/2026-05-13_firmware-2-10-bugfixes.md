title: "Firmware-Update: Neue Bugfix-Releases"
slug: firmware-2.10.x-bugfixes
date: 2026-05-13
tag: Firmware

Nach dem großen [Funktions-Update auf Version 2.10](/de/blog/firmware-dark-mode-status-widget) haben wir in den vergangenen Tagen mehrere Bugfix-Releases nachgeschoben. Diese beheben kleinere Probleme und verbessern die Kompatibilität mit weiteren Zählern.

## Aktuelle Versionen

Die jeweils neuesten Versionen für die einzelnen Geräte sind:

- **WARP Charger**: Firmware **2.10.2**
- **WARP2 Charger**: Firmware **2.10.3**
- **WARP3 Charger**: Firmware **2.10.3**
- **WARP Energy Manager**: Firmware **2.6.2**
- **WARP Energy Manager 2.0**: Firmware **1.5.2**

Wie gewohnt schlägt Ihr Gerät das passende Update automatisch im Webinterface vor. Alle Firmware-Dateien und Changelogs finden Sie außerdem auf unserer [Download-Seite](/de/software/downloads#firmware).

## Was wurde behoben?

Die wichtigsten Änderungen der Bugfix-Releases im Überblick:

- TLS 1.3-Signatur-Algorithmen in TLS 1.2 wiederhergestellt. Dadurch funktioniert unter anderem die PV-Ertragsprognose wieder zuverlässig.
- Überschreiben bekannter Messorte verboten, um Fehlkonfigurationen zu vermeiden.
- Behoben, dass die nicht zurücksetzbaren Energiewerte des Iskra WM3M4C fälschlich als zurücksetzbar markiert waren.
- Ladelog-Generierung mit Zeitfilter sowie die Konfiguration der Automatisierungs-Regeln repariert.
- Lesbarkeit der Graphen verbessert und Konfiguration von Carlo Gavazzi EM270- und EM280-Zählern repariert.

Eine vollständige Liste aller Änderungen finden Sie wie immer im Changelog direkt im Webinterface Ihres Geräts oder auf unserer [Download-Seite](/de/software/downloads#firmware).

Wir wünschen viel Freude mit dem Update!
