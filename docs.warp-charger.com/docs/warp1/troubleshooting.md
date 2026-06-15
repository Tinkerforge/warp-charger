---
sidebar_position: 5
---

# Fehlerbehebung

Fehlerzustände werden von der Wallbox durch die LED im Deckel dargestellt. Bei den Varianten
WARP1 Charger Smart und WARP1 Charger Pro gibt die Statusseite des Ladecontrollers weitere
Informationen.

## Fehlersuche

### Wallbox-LED ist aus

Für diesen Fehlerzustand gibt es verschiedene mögliche Ursachen:

 * Die Wallbox ist über den Schlüsselschalter deaktiviert. Siehe [Bedienelemente](/docs/warp1/assembly_and_installation).
 * Die Wallbox-LED geht nach etwa 15 Minuten Inaktivität aus. Das Drücken des Tasters oder das Anschließen eines Elektrofahrzeugs weckt die Wallbox wieder und die LED sollte wieder dauerhaft leuchten.
 * Die Wallbox ist nicht mit Strom versorgt. Mögliche Ursachen: Stromausfall, Sicherung oder Fehlerstromschutzschalter haben ausgelöst.
 * Der interne Ladecontroller ist ohne Strom. Die Wallbox verfügt intern über zwei Feinsicherungen, gegebenenfalls ist eine defekt.
 * Das innere Anschlusskabel zum Deckel wurde am Taster um 180° verdreht aufgesteckt.

### Wallbox-LED blinkt sehr schnell

Nach dem Einschalten der Stromversorgung kalibriert die Wallbox die DC-Fehlerstromerkennung. Nach
ca. 10 Sekunden sollte die Kalibrierung abgeschlossen sein und die Wallbox-LED sollte dauerhaft
leuchten (betriebsbereit).

### Wallbox-LED blinkt zweimal im Intervall (Webinterface zeigt Schalterfehler)

Die Wallbox wurde nicht korrekt installiert. Die Schaltereinstellung des Ladecontrollers ist noch
auf dem Werkszustand. Siehe [Einstellen des Ladestroms](/docs/warp1/assembly_and_installation#einstellen-des-ladestroms).

### Wallbox-LED blinkt dreimal im Intervall (Webinterface zeigt Kalibrierungsfehler)

Die DC-Kalibrierung konnte nicht abgeschlossen werden. Die Stromversorgung der Wallbox trennen und
nach 5 Sekunden wieder einschalten. Die Kalibrierung sollte nun erfolgreich verlaufen.

:::note

Bei einer Firmware älter als 1.1.0 darf beim Einschalten der Wallbox kein Fahrzeug angeschlossen
sein, damit die Kalibrierung erfolgreich verläuft.

:::

### Wallbox-LED blinkt viermal im Intervall (Webinterface zeigt Schützfehler)

Für diesen Fehlerzustand gibt es verschiedene mögliche Ursachen:

 * Erdungsfehler der Wallbox, Erdung überprüfen
 * Phase L1 ohne Spannung
 * Schütz schaltet nicht korrekt ein (keine Spannung für L1 nach dem Schütz), kein Kontakt
 * Schütz schaltet nicht korrekt ab (Spannung von L1 liegt trotz Abschalten noch nach dem Schütz an), "Schütz klebt"
 * Eine der internen Feinsicherungen ist defekt.

### Wallbox-LED blinkt fünfmal im Intervall (Webinterface zeigt Kommunikationsfehler)

Es besteht ein Kommunikationsfehler mit dem Elektrofahrzeug. Bei erstmaligem Auftreten das
Ladekabel vom Fahrzeug trennen, 10 Sekunden warten und das Ladekabel erneut mit dem Fahrzeug
verbinden (erneuter Ladevorgang).

Sollte das Problem bestehen bleiben, so kann es verschiedene Gründe dafür geben:

 * Es liegt ein Fehler beim Ladekabel vor (Kurzschluss, verschmutzte / feuchte Kontakte o.ä.). Die Wallbox ist dann sofort außer Betrieb zu nehmen und fachmännisch in Stand zu setzen.
 * Es liegt ein technischer Defekt beim Fahrzeug vor.
 * Es liegt ein technischer Defekt bei der Wallbox vor (Ladecontroller defekt o.ä.).
 * Das Fahrzeug fordert den IEC 61851-1 Status "D" (Laden mit Belüftung) an. Dieser Modus wird von der Wallbox nicht unterstützt.
 * Das Fahrzeug übermittelt den IEC 61851-1 Status E oder F. In beiden Fällen handelt es sich um einen Fehler, den das Fahrzeug erkannt hat.

### Die Wallbox ist nicht über das WLAN erreichbar, aber die LED leuchtet

In diesem Fall ist zu prüfen, ob die Wallbox gegebenenfalls in den Access-Point-Fallback gegangen
ist. Wie im Auslieferungszustand eröffnet die Wallbox dann ein eigenes WLAN. Wenn die Zugangsdaten
nicht geändert wurden, entsprechen sie den Werkseinstellungen und sind dem Aufkleber auf der
Rückseite der Anleitung zu entnehmen.

## Ersatzteile

Ersatzteile für den WARP1 Charger [sind in unserem Shop erhältlich](https://shop.warp-charger.com/de/spare-parts/warp1-spare-parts.html):

| Artikelnummer | Bauteil |
|-|-|
| WARP-CASE | WARP Charger Case |
| WARP-CON-4P-63A | Schaltschütz 4 Pol, Hutschiene, 63 A |
| WARP-DC-PROTECT | DC-Fehlerstromschutzmodul 6 mA |
| WARP-METER-3PH-MID | Zweirichtungs-Drehstromzähler, 3 Phasen, RS485, MID |
| WARP-PS-12V | Hutschienennetzteil 230 V AC zu 12 V, 1,25 A |
| WARP-T2-5M-16A | Typ-2-Stecker mit 5 m Kabel, 11 kW / 16 A |
| WARP-T2-5M-32A | Typ-2-Stecker mit 5 m Kabel, 22 kW / 32 A |
| WARP-T2-75M-16A | Typ-2-Stecker mit 7,5 m Kabel, 11 kW / 16 A |
| WARP-T2-75M-32A | Typ-2-Stecker mit 7,5 m Kabel, 22 kW / 32 A |
| 113 | ESP32 Brick |
| 277 | RS485 Bricklet |
| 2159 | EVSE Bricklet |
| 6150 | Bricklet-Kabel 15 cm (7p-7p) |
| 6189 | 7 V bis 28 V zu 5 V Inline-Stromversorgung |

## Stromlaufplan

Ein Stromlaufplan ist in einem gesonderten Dokument verfügbar.

## Sicherungswechsel

Die Wallbox ist intern über zwei 6,3x32 mm Feinsicherungen (mittelträge (m), 500 mA) abgesichert.
Tinkerforge verbaut Sicherungen vom Typ "ESKA 632.214".
