---
sidebar_position: 5
---

# Fehlerbehebung

Fehlerzustände werden vom WARP Energy Manager 2.0 LED des Fronttasters rot dargestellt. Generell gibt das Webinterface des Energymanagers weitere Informationen zum Fehler.

## Fehlersuche

### Display ist aus, Fronttaster-LED leuchtet nicht

Vermutlich ist der WARP Energy Manager ohne Strom. Prüfe den 230V Stromanschluss und die interne Sicherung.

### Display ist aus, Fronttaster-LED leuchtet grün

Die Hintergrundbeleuchtung des Displays geht nach einer Zeit Inaktivität aus. Das Drücken des Fronttasters  weckt es wieder auf.

### Der WARP Energy Manager 2.0 ist nicht über LAN / WLAN erreichbar, aber die Fronttaster-LED leuchtet grün

In diesem Fall ist zu prüfen, ob der WARP Energy Manager gegebenenfalls in den Access-Point-Fallback gegangen ist. Wie im Werkszustand eröffnet der Energy Manager dann ein eigenes WLAN.
Wenn die Zugangsdaten nicht geändert wurden, entsprechen sie den Werkseinstellungen und sind dem Aufkleber auf der Rückseite der Anleitung zu entnehmen.


## Sicherungswechsel

Der WARP Energy Manager ist intern über eine 5×20 mm Feinsicherung (träge (T), 2 A) abgesichert. Tinkerforge verbaut Sicherungen vom Typ "ESKA 522.520". 
