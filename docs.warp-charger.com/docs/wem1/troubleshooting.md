---
sidebar_position: 5
---

# Fehlerbehebung

Die Status-LED des WARP Energy Managers 1.0 blinkt in Fehlerfällen. Die Farbe
gibt die Art des Fehlers an.

## Status-LED Blinkcodes

### Status-LED blinkt gelb

Ist PV-Überschussladen aktiviert, atmet die Status-LED gelb, sobald Strom aus
dem Netz bezogen wird. Dies ist kein Fehlerzustand. Sollte PV-Überschussladen
nicht aktiv sein und die Status-LED blinkt gelb, dann ist der WARP Energy
Manager nicht zum konfigurierten WLAN verbunden und es ist kein LAN-Kabel
angeschlossen.

### Status-LED blinkt rot

Blinkt die Status-LED rot, so ist der WARP Energy Manager in einem
Fehlerzustand. Gründe können eine fehlgeschlagene Schützüberwachung oder ein
interner Fehler sein. Das Webinterface gibt genauere Auskunft.

### Status-LED blinkt violett

Blinkt die Status-LED violett, so ist die Konfiguration nicht vollständig. Es
muss mindestens die unter
[Konfiguration und Einrichtung](/docs/wem1/configuration_and_setup) beschriebene
Minimalkonfiguration vorgenommen werden, damit der Energy Manager korrekt
funktioniert.

## Sicherungswechsel

Der WARP Energy Manager ist intern über zwei 5 × 20 mm Feinsicherungen
(mittelträge (m), 500 mA) abgesichert. Tinkerforge verbaut Sicherungen vom Typ
"ESKA 521.014". Die eine Sicherung befindet sich im Eingangspfad der 230 V
Stromversorgung (L). Die andere Sicherung befindet sich im Schaltausgang der
Schützsteuerung.
