---
sidebar_position: 5
---

# Fehlerbehebung

Fehlerzustände werden von der Wallbox durch die blaue LED im Deckel dargestellt. Bei den
Varianten WARP2 Charger Smart und WARP2 Charger Pro gibt das Webinterface bzw. die
Statusseite des Ladecontrollers weitere Informationen.

## Fehlersuche

### Blaue LED ist aus

Für diesen Fehlerzustand gibt es verschiedene mögliche Ursachen:

 * Die blaue LED geht nach etwa 15 Minuten Inaktivität aus. Das Drücken des Tasters oder das Anschließen eines Elektrofahrzeugs weckt die Wallbox wieder und die LED sollte wieder dauerhaft leuchten.
 * Die Wallbox ist nicht mit Strom versorgt. Mögliche Ursachen: Stromausfall, Sicherung oder Fehlerstromschutzschalter haben ausgelöst.
 * Der interne Ladecontroller ist ohne Strom. Die Wallbox verfügt intern über zwei Feinsicherungen, gegebenenfalls ist eine defekt.
 * Das innere Anschlusskabel zum Deckel wurde nicht korrekt aufgesteckt (zum Beispiel am Taster 180° verdreht).

### Blaue LED blinkt sehr schnell

Nach dem Einschalten der Stromversorgung kalibriert die Wallbox die DC-Fehlerstromerkennung.
Nach drei Sekunden sollte die Kalibrierung abgeschlossen sein und die blaue LED sollte
dauerhaft leuchten (betriebsbereit).

### Blaue LED blinkt zweimal im Intervall, Webinterface zeigt Schalterfehler

Die Wallbox wurde nicht korrekt installiert. Die Schalter-Einstellung des Ladecontrollers
ist noch auf dem Werkszustand. Siehe Abschnitt
[Einstellen des Ladestroms](/docs/warp2/assembly_and_installation#einstellen-des-ladestroms).

### Blaue LED blinkt dreimal im Intervall, Webinterface zeigt DC-Fehler

Ein DC-Fehlerstrom wurde erkannt. Der Fehler kann entweder über die Webseite der Wallbox
oder über ein kurzzeitiges Trennen der Stromversorgung der Wallbox zurückgesetzt werden.
Achtung: den Hinweis zu DC-Fehlerströmen im Abschnitt
[Schutzeinrichtungen der Wallbox](/docs/warp2/assembly_and_installation#schutzeinrichtungen-der-wallbox)
beachten!

### Blaue LED blinkt viermal im Intervall, Webinterface zeigt Schützfehler

Für diesen Fehlerzustand gibt es verschiedene mögliche Ursachen:

 * Erdungsfehler der Wallbox (ggf. PE nicht korrekt angeschlossen?)
 * Phase L1 ohne Spannung (ggf. L1/N vertauscht?)
 * Schütz schaltet nicht korrekt ein (keine Spannung an L1 nach dem Schütz), kein Kontakt.
 * Schütz schaltet nicht korrekt ab (Spannung von L1 liegt trotz Abschalten noch nach dem Schütz an), "Schütz klebt".
 * Eine der beiden internen Feinsicherungen ist defekt.

### Blaue LED blinkt fünfmal im Intervall, Webinterface zeigt Kommunikationsfehler

Es besteht ein Kommunikationsfehler mit dem Elektrofahrzeug. Bei erstmaligem Auftreten das
Ladekabel vom Fahrzeug trennen, 10 Sekunden warten und das Ladekabel erneut mit dem
Fahrzeug verbinden (erneuter Ladevorgang). Sollte das Problem bestehen bleiben, so kann es
verschiedene Gründe dafür geben:

 * Es liegt ein Fehler beim Ladekabel vor (Kurzschluss, verschmutzte / feuchte Kontakte o.ä.). Die Wallbox ist dann sofort außer Betrieb zu nehmen und in Stand zu setzen.
 * Es liegt ein technischer Defekt beim Fahrzeug vor.
 * Es liegt ein technischer Defekt bei der Wallbox vor (Ladecontroller defekt o.ä.).
 * Das Fahrzeug fordert den IEC 61851-1 Status "D - Laden mit Belüftung" an. Dieser Modus wird von der Wallbox nicht unterstützt.
 * Das Fahrzeug übermittelt den IEC 61851-1 Status E oder F. In beiden Fällen handelt es sich um einen Fehler, den das Fahrzeug erkannt hat.

### Die Wallbox ist nicht über LAN / WLAN erreichbar, aber die blaue LED leuchtet

In diesem Fall ist zu prüfen, ob die Wallbox gegebenenfalls in den Access-Point-Fallback
gegangen ist. Wie im Werkszustand eröffnet die Wallbox dann ein eigenes WLAN. Wenn die
Zugangsdaten nicht geändert wurden, entsprechen sie den Werkseinstellungen und sind dem
Aufkleber auf der Rückseite der Anleitung zu entnehmen.

## Wiederherstellungsmodus

Falls die Wallbox weder ihren Access Point öffnet noch über ein konfiguriertes Netzwerk auf
das Webinterface zugegriffen werden kann, kannst du wie folgt den Wiederherstellungsmodus
starten:

 1. Mache die Wallbox stromlos.
 2. Halte den Taster im Deckel gedrückt.
 3. Schalte den Strom der Wallbox wieder ein (ggf. mittels einer zweiten Person).
 4. Halte den Taster mindestens 10, aber maximal 30 Sekunden gedrückt.

Die Wallbox startet dann im Wiederherstellungsmodus. Zunächst werden die
Netzwerkeinstellungen gelöscht sowie die Anmeldung deaktiviert. Anschließend sollte es
wieder möglich sein, über den Access Point auf die Wallbox zuzugreifen.

Durch erneutes Trennen und Verbinden der Stromversorgung innerhalb der ersten Minute im
Wiederherstellungsmodus kann ein Zurücksetzen auf Werkszustand ausgelöst werden.

## Zurücksetzen auf Werkszustand

Falls das Webinterface nicht korrekt funktioniert oder die Konfiguration defekt ist, kannst
du auf der Firmware-Aktualisierungs-Unterseite alle Einstellungen auf den Werkszustand
zurücksetzen.

:::warning

Durch das Zurücksetzen auf Werkszustand gehen **alle** Konfigurationen, angelegte Benutzer,
angelernte NFC-Tags und getrackte Ladevorgänge verloren.

:::

Nach dem Zurücksetzen startet das Webinterface wieder und öffnet den Access-Point mit der
SSID und Passphrase, die auf dem Aufkleber vermerkt sind. Die Wallbox kann jetzt wieder
konfiguriert werden.

Damit getrackte Ladevorgänge nicht verloren gehen, kann alternativ nur die Konfiguration
zurückgesetzt werden. Angelegte Benutzer (aber nicht der Benutzerverlauf des Ladetrackers)
und NFC-Tags werden dennoch gelöscht.

Falls das Webinterface nicht mehr zu erreichen ist, bestehen folgende Optionen:

Falls eine Netzwerkverbindung aufgebaut werden kann, aber das Webinterface selbst nicht mehr
funktioniert, kann versucht werden, die Recovery-Seite zu öffnen. Falls man über den Access
Point der Wallbox verbunden ist, gelangt man auf die Recovery-Seite unter
http://10.0.0.1/recovery. Bei einer bestehenden Verbindung zu einem LAN oder WLAN erreicht
man die Seite über http://[konfigurierter_hostname]/recovery, also z.B.
http://warp2-ABC/recovery. Mittels der Recovery-Seite kann man die Wallbox neustarten,
Firmware-Updates einspielen, die Wallbox auf den Werkszustand zurücksetzen (Factory Reset),
Debug-Reports herunterladen und die HTTP-API verwenden.

### Wallbox neu flashen

Alternativ kann man die Wallbox (genauer: den verbauten ESP32 Ethernet Brick) neu flashen.
Dazu wird ein PC mit installiertem Brick Viewer 2.4.20 oder neuer benötigt. Diesen findet
man unter https://www.tinkerforge.com/de/doc/Software/Brickv.html. Außerdem wird ein
USB-C-Kabel benötigt, um den Brick an den PC anzuschließen. Brick Daemon wird nicht
benötigt. Zum Neuflashen geht man wie folgt vor:

 1. Wallbox stromlos machen.
 2. Wallbox-Deckel abnehmen wie im Abschnitt Wandmontage beschrieben.
 3. Rechts in der Wallbox befindet sich der ESP32 Ethernet Brick. Die vier schwarzen Kunststoffschrauben losschrauben (1) und das LAN-Kabel sowie die zwei Bricklet-Kabel mit weißem Stecker abziehen (2). Danach kann der ESP32 Ethernet Brick aus der Wallbox genommen werden.

![image](/img/warp2/warp_factory_reset_cropped.jpg)

 4. Der ESP32 Ethernet Brick muss dann per USB-C an den PC angeschlossen und der Brick Viewer gestartet werden.
 5. Anschließend links unten auf Updates / Flashing und dann oben auf Brick klicken.

![image](/img/warp2/warp_factory_flash.png)

 6. Bei Serial Port den Port auswählen, an dem der Brick angeschlossen ist. Typischerweise sollte nur ein Port in der Liste auftauchen. Der richtige Port ist einer, an dem ein "CP2102N USB to UART Bridge Controller" bzw. ein "ESP32 Ethernet Brick" aufgeführt wird.
 7. Unter Firmware den "WARP2 Charger" auswählen. Die aktuelle Firmware-Version wird automatisch ausgewählt.
 8. Auf "Flash" klicken. Der Flash-Vorgang ist beendet, wenn die Status-LED des ESP32 Ethernet Brick beginnt blau zu blinken.
 9. Nachdem der Brick neu geflasht wurde, kann dieser vom PC abgezogen und wie folgt in die Wallbox eingebaut werden.
 10. Zuerst die weißen Bricklet-Stecker sowie das LAN-Kabel wieder einstecken.
 11. Dann den Brick mit den Kunststoffschrauben auf die entsprechenden Abstandshalter schrauben.
 12. Jetzt die Wallbox schließen, indem zuerst der Taster im Deckel sowie der Erdungsstecker angeschlossen werden. Anschließend den Deckel aufsetzen und die vier Schrauben festziehen.
 13. Die Wallbox kann jetzt wieder mit Strom versorgt werden. Wenn der Flash-Vorgang erfolgreich war, sollte die Wallbox jetzt wieder den WLAN-Access-Point eröffnen und kann eingerichtet werden.

## Probleme bei Ladevorgängen lösen

Treten Ladeabbrüche auf, so kann dies verschiedene Ursachen haben. Mögliche Ursachen können
eine fehlerhafte Installation der Wallbox oder ein technischer Defekt der Wallbox oder des
Fahrzeugs sein. Folgende Punkte sollten überprüft werden:

 * **Sitz des Typ-2-Steckers:** Ein nicht vollständig eingesteckter Typ-2-Stecker kann dazu führen, dass ein Fahrzeug nicht oder nur in einem Notlademodus mit minimaler Leistung lädt. Ein Indiz kann hier sein, dass das Fahrzeug den Typ-2-Stecker nicht korrekt verriegelt.
 * **Inspektion aller Komponenten:** Es sollten alle Komponenten auf Beschädigungen und Nässe kontrolliert werden.
 * **Webinterface der Wallbox:** Steht nur bei den Varianten Smart und Pro zur Verfügung. Die Statusseite gibt den Ladestatus, den erlaubten Ladestrom und den Grund für eventuelle Limitierungen aus Sicht der Wallbox an. Detailliertere Informationen gibt die Unterseite Ladestatus. Hier kann auch ein Ladeprotokoll erzeugt werden, welches alle Werte des Ladevorgangs aufzeichnet.
 * **Messung durch einen Elektriker:** Elektrische Probleme können von einem Elektriker diagnostiziert werden. Er kann prüfen, ob alle Leiter korrekt angeschlossen sind.

## Lastmanagementfehler

Bei der Verwendung des Lastmanagements können zwei Arten von Fehlern auftreten:
Wallbox-Fehler, die nur eine spezifische Wallbox betreffen, und Management-Fehler, bei
deren Auftreten das Laden an **allen** gesteuerten Wallboxen gestoppt wird.

Wallbox-Fehler müssen an der entsprechenden Wallbox behoben werden. Hier hilft die
[Fehlersuche](#fehlersuche). Im Folgenden wird die Diagnose von Management-Fehlern
erläutert:

 * **Kommunikationsfehler / Wallbox nicht erreichbar:** Eine Wallbox kann nicht zuverlässig erreicht werden. Eventuell liegt ein Verbindungsproblem vor. In diesem Fall die Netzwerkverbindung bzw. das Netzwerkkabel und die IP-Konfiguration der Wallbox prüfen.
 * **Firmware inkompatibel:** Das Lastmanagement benötigt kompatible Firmwares auf allen beteiligten Wallboxen. Die jeweils aktuellsten Firmwares sollten zueinander kompatibel sein, auch wenn WARP(1) und WARP2 Charger in einem Lastmanagementverbund verwendet werden.
 * **Lastmanagement deaktiviert:** Bei einer der zu steuernden Wallboxen ist das Lastmanagement deaktiviert. Damit ist keine Steuerung durch den Lastmanager möglich. Das Lastmanagement kann auf der Ladecontroller-Unterseite aktiviert werden.
 * **Ladecontroller nicht erreichbar:** Der Ladecontroller einer Wallbox kann nicht erreicht werden, die Wallbox selbst aber schon. In diesem Fall sollte das Ereignis-Log der betroffenen Wallbox geprüft werden.
 * **Ladecontroller reagiert nicht:** Der Ladecontroller einer Wallbox reagiert nicht auf Stromzuweisungen. Eventuell ist auf diesem das Lastmanagement deaktiviert.

## Ersatzteile

Ersatzteile für den WARP2 Charger [sind in unserem Shop erhältlich](https://shop.warp-charger.com/de/spare-parts/warp2-spare-parts.html):

| Artikelnummer | Bauteil |
|-|-|
| WARP-CON-4P-63A | Schaltschütz 4 Pol, Hutschiene, 63 A |
| WARP2-METER-3PH-MID | Zweirichtungs-Drehstromzähler, 3 Phasen, RS485, MID |
| WARP-T2-5M-16A | Typ-2-Stecker mit 5 m Kabel, 11 kW / 16 A |
| WARP-T2-5M-32A | Typ-2-Stecker mit 5 m Kabel, 22 kW / 32 A |
| WARP-T2-75M-16A | Typ-2-Stecker mit 7,5 m Kabel, 11 kW / 16 A |
| WARP-T2-75M-32A | Typ-2-Stecker mit 7,5 m Kabel, 22 kW / 32 A |
| WARP-FUSE-0.5A | 2x Feinsicherung 5×20 mm, mittelträge, 0,5 A |
| WARP-ETH-FEED-THR | Ethernet-Gehäusedurchführung |
| WARP-NFC-STICKER | NFC-Aufkleber |
| WARP2-DC-PROTECT | DC-Fehlerstromschutzmodul (6 mA) |
| WARP2-CASE | WARP2 Gehäuse |
| WARP2-CABLE-HARNESS | WARP2 Kabelbaum |
| WARP2-TERMINAL-BLOCKS | WARP2 Klemmen-Baugruppe |
| WARP2-NFC-CARD | 3× WARP2 NFC-Karten |
| WARP2-SCREWS | WARP2 Schraubenset |
| WARP2-PB-LED | WARP2 Taster/LED |
| WARP-RES-220 | Widerstand 220 Ω |
| WARP-RES-680 | Widerstand 680 Ω |
| WARP2-ESP32-ETH | ESP32 Ethernet Brick mit WARP2-Firmware |
| 2167 | EVSE Bricklet 2.0 |
| 286 | NFC Bricklet |
| 6150 | Bricklet-Kabel 15 cm (7p-7p) |
| 6149 | Bricklet-Kabel 6 cm (7p-7p) |

## Sicherungswechsel

Die Wallbox ist intern über zwei 5×20 mm Feinsicherungen (mittelträge (m), 500 mA)
abgesichert. Tinkerforge verbaut Sicherungen vom Typ "ESKA 521.014".
