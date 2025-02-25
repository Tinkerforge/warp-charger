---
sidebar_position: 5
---

# Fehlerbehebung

Fehlerzustände werden von der Wallbox durch die LED im Fronttaster rot dargestellt. Bei den Varianten WARP3 Charger Smart und WARP3 Charger Pro gibt das Webinterface bzw. die Ladestatus-Unterseite weitere Informationen.
Weitere Informationen hierzu gibt es auch in der [PDF Betriebsanleitung](https://www.warp-charger.com/downloads/)

## Fehlersuche

### LED ist aus

Für diesen Fehlerzustand gibt es verschiedene mögliche Ursachen:

 * Die LED geht nach etwa 15 Minuten Inaktivität aus. Das Drücken des Tasters oder das Anschließen eines Elektrofahrzeugs weckt die Wallbox wieder und die LED sollte wieder dauerhaft blau leuchten.
 * Die Wallbox ist nicht mit Strom versorgt. Mögliche Ursachen: Stromausfall, Sicherung oder Fehlerstromschutzschalter haben ausgelöst.
 * Der interne Ladecontroller ist ohne Strom. Die Wallbox verfügt intern über eine Feinsicherung, gegebenenfalls ist diese defekt.
 * Das innere Anschlusskabel zum Deckel wurde nicht korrekt aufgesteckt (zum Beispiel am Taster 180° verdreht).

### LED blinkt sehr schnell magenta

Nach dem Einschalten der Stromversorgung kalibriert die Wallbox die DC-Fehlerstromerkennung. Nach drei Sekunden sollte die Kalibrierung abgeschlossen sein und die LED sollte dauerhaft blau leuchten (betriebsbereit).

### LED blinkt zweimal rot im Intervall, dass Webinterface zeigt Schalterfehler

Die Wallbox wurde nicht korrekt installiert. Die Schaltereinstellung des Ladecontrollers ist noch auf dem Werkszustand.

### LED blinkt dreimal rot im Intervall, dass Webinterface zeigt DC-Fehler

Ein DC-Fehlerstrom wurde erkannt. Der Fehler kann entweder über die Webseite der Wallbox oder über ein kurzzeitiges Trennen der Stromversorgung der Wallbox zurückgesetzt werden.

### LED blinkt viermal rot im Intervall, dass Webinterface zeigt Schützfehler bzw. PE Fehler

Für diesen Blinkcode gibt es zwei verschiedene Fehlerzustände mit verschiedenen möglichen Ursachen:

Schützfehler:

 * Eines der Schütze schaltet nicht korrekt ein
 * Eines der Schütze schaltet nicht korrekt ab,
 * "Das Schütz klebt"

Das Webinterface der Wallbox gibt weitere Informationen, um welches Schütz es sich handelt.

PE-Fehler:

 * Phase L1 ohne Spannung (ggf. L1/N vertauscht)
 * Erdungsfehler der Wallbox (ggf. PE nicht korrekt angeschlossen)

### LED blinkt fünfmal rot im Intervall, dass Webinterface zeigt Kommunikationsfehler

Es besteht ein Kommunikationsfehler mit dem Elektrofahrzeug. Bei erstmaligem Auftreten das Ladekabel vom Fahrzeug trennen, 10 Sekunden warten und das Ladekabel erneut mit dem Fahrzeug verbinden (erneuter Ladevorgang).
Sollte das Problem bestehen bleiben, so kann es verschiedene Gründe dafür geben:

 * Es liegt ein Fehler beim Ladekabel vor (Kurzschluss, verschmutze / feuchte Kontakte o.ä.). Die Wallbox ist dann sofort außer Betrieb zu nehmen und in Stand zu setzen.
 * Es liegt ein technischer Defekt beim Fahrzeug vor.
 * Es liegt ein technischer Defekt bei der Wallbox vor (Ladecontroller defekt o.ä.).
 * Das Fahrzeug fordert den IEC 61851-1 Status "D - Laden mit Belüftung" an. Dieser Modus wird von der Wallbox nicht unterstützt.
 * Das Fahrzeug übermittelt den IEC 61851-1 Status E oder F. In beiden Fällen handelt es sich um einen Fehler, den das Fahrzeug erkannt hat.

### Die Wallbox ist nicht über LAN / WLAN erreichbar, aber die LED leuchtet blau

In diesem Fall ist zu prüfen, ob die Wallbox gegebenenfalls in den Access-Point-Fallback gegangen ist. Wie im Werkszustand eröffnet die Wallbox dann ein eigenes WLAN.
Wenn die Zugangsdaten nicht geändert wurden, entsprechen sie den Werkseinstellungen und sind dem Aufkleber auf der Rückseite der Anleitung zu entnehmen.

## Wiederherstellungsmodus

Falls die Wallbox weder ihren Access-Point öffnet noch über ein konfiguriertes Netzwerk auf das Webinterface zugegriffen werden kann, kannst wie folgt der Wiederherstellungsmodus gestartet werden:

 1. Wallbox stromlos machen
 2. Taster im Deckel gedrückt halten
 3. Stromversorgung der Wallbox wieder herstellen (ggf. mit einer zweiten Person).
 4. Taster ungefähr 20 Sekunden lang (mindestens 10, aber maximal 30) gedrückt halten.

Die Wallbox startet dann im Wiederherstellungsmodus. Zunächst werden die Netzwerkeinstellungen gelöscht sowie die Anmeldung deaktiviert. Anschließend sollte es wieder möglich sein, über den Access-Point auf die Wallbox zuzugreifen.
Durch erneutes Trennen und Verbinden der Stromversorgung innerhalb der ersten Minute im Wiederherstellungsmodus kann ein Zurücksetzen auf Werkszustand ausgelöst werden.

## Zurücksetzen auf Werkszustand

Falls das Webinterface nicht korrekt funktioniert oder die Konfiguration defekt ist, können auf der Unterseite Firmware-Aktualisierung alle Einstellungen auf den Werkszustand zurückgesetzt werden.

**Hinweis** Durch das Zurücksetzen auf Werkszustand gehen alle Konfigurationen, angelegten Benutzer, angelernten NFC-Tags und aufgezeichneten Ladevorgänge verloren.
Nach dem Zurücksetzen startet das Webinterface wieder und öffnet den Access-Point mit der SSID und Passphrase, die auf dem Aufkleber vermerkt sind. Die Wallbox kann jetzt wieder erneut konfiguriert werden.

Damit aufgezeichnete Ladevorgänge nicht verloren gehen, kann alternativ nur die Konfiguration zurückgesetzt werden. Angelegte Benutzer (aber nicht der Benutzerverlauf des Ladetrackers) und NFC-Tags werden dennoch gelöscht.
Falls eine Netzwerkverbindung aufgebaut werden kann, aber das Webinterface selbst nicht mehr funktioniert, kann versucht werden, die Recovery-Seite zu öffnen. Falls eine Verbindung über den Access-Point der Wallbox besteht, kann die Recovery-Seite unter
http://10.0.0.1/recovery aufgerufen werden. Bei einer bestehenden Verbindung zu einem Netzwerk kann die Seite über http://konfigurierter_hostname/recovery, also z.B. http://warp3-ABC/recovery erreicht werden. Auf der Recovery-Seite kann die Wallbox
neugestartet oder auf den Werkszustand zurückgesetzt (Factory Reset) werden und es können Firmware-Updates einspielt, Debug-Reports heruntergeladen und die HTTP-API verwendet werden.

## Probleme bei Ladevorgängen lösen

Treten Ladeabbrüche auf, so kann dies verschiedene Ursachen haben. Mögliche Ursachen können eine fehlerhafte Installation der Wallbox oder ein technischer Defekt der Wallbox oder des Fahrzeugs sein. Folgende Punkte sollten überprüft werden:

 * **Sitz des Typ-2-Steckers:** Ein nicht vollständig eingesteckter Typ-2-Stecker kann dazu führen, dass ein Fahrzeug nicht oder nur in einem Notlademodus mit minimaler Leistung lädt. Ein Indiz hierfür kann sein, dass das Fahrzeug den Typ-2-Stecker nicht korrekt verriegelt.
 * **Inspektion aller Komponenten:** Es sollten alle Komponenten auf Beschädigungen und Nässe kontrolliert werden.
 * **Webinterface der Wallbox:** Steht nur bei den Varianten Smart und Pro zur Verfügung. Die Statusseite gibt den Ladestatus, den erlaubten Ladestrom und den Grund für eventuelle Limitierungen aus Sicht der Wallbox an. Detailliertere Informationen gibt die Unterseite Ladestatus. Hier kann außerdem ein Ladeprotokoll erzeugt werden,
welches alle Werte des Ladevorgangs aufzeichnet.
 * **Messung durch eine Elektrofachkraft:** Elektrische Probleme können von einer Elektrofachkraft diagnostiziert werden. Sie kann prüfen, ob alle Leiter korrekt angeschlossen sind.

## Lastmanagementfehler

Bei der Verwendung des Lastmanagements können zwei Arten von Fehlern auftreten: Wallbox-Fehler, die nur eine spezifische Wallbox betreffen, und Management-Fehler, bei deren Auftreten das Laden an allen gesteuerten Wallboxen gestoppt wird.
Wallbox-Fehler müssen an der entsprechenden Wallbox behoben werden. Hier hilft die [PDF Betriebsanleitung](https://www.warp-charger.com/downloads/) weiter.

Im Folgenden wird die Diagnose von Management-Fehlern erläutert:

 * **Kommunikationsfehler / Wallbox nicht erreichbar**: Eine Wallbox kann nicht zuverlässig erreicht werden. Eventuell liegt ein Verbindungsproblem vor. In diesem Fall die Netzwerkverbindung bzw. das Netzwerkkabel und die IP-Konfiguration der Wallbox prüfen.
 * **Firmware inkompatibel:** Das Lastmanagement benötigt kompatible Firmwares auf allen beteiligten Wallboxen. Die jeweils aktuellen Firmwares sollten zueinander kompatibel sein, selbst wenn WARP(1), WARP2 und WARP3 Charger in einem Lastmanagementverbund verwendet werden.
 * **Fremdsteuerung deaktiviert:** Bei einer der zu steuernden Wallboxen ist die Fremdsteuerung deaktiviert. Damit ist keine Steuerung durch den Lastmanager möglich. Die Fremdsteuerung kann auf der Wallboxen-Unterseite aktiviert werden.
 * **Ladecontroller nicht erreichbar:** Der Ladecontroller einer Wallbox kann nicht erreicht werden, die Wallbox selbst aber schon. In diesem Fall sollte das Ereignis-Log der betroffenen Wallbox geprüft werden.
 * **Ladecontroller reagiert nicht:** Der Ladecontroller einer Wallbox reagiert nicht auf Stromzuweisungen. In diesem Fall sollte das Ereignis-Log der betroffenen Wallbox geprüft werden.

## Sicherungswechsel

Die Wallbox ist intern über eine 5×20 mm Feinsicherung (träge (T), 2 A) abgesichert. Tinkerforge verbaut Sicherungen vom Typ "ESKA 522.520". Die Sicherung befindet sich rechts in der Wallbox auf dem Ladecontroller (EVSE) in einem grünen Sicherungsgehäuse.
