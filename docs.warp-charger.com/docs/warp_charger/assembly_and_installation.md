---
sidebar_position: 1
---

# Montage und Installation

:::note

Ein Großteil der Online-Dokumentation ist auf WARP1, WARP2 und WARP3 anwendbar. Die Montage
und Installation unterscheidet sich bei den drei Generationen allerdings jeweils leicht. Diese
Dokumentation ist auf WARP3 ausgelegt, für Hilfe zur Montage und Installation von WARP1 und
WARP2 kann auf die jeweilige Betriebsanleitung unter https://warp-charger.com/downloads
zurückgegeriffen werden.

:::

### Lieferumfang

Im Lieferumfang der Wallbox befinden sich:
-   vormontierte Wallbox inkl. Deckel
-   DIN-A4-Umschlag mit:
    -   [Betriebsanleitung](https://www.warp-charger.com/documents/WARP3_Betriebsanleitung.pdf)
    -   Testprotokoll der Wallbox
    -   [Bohrschablone](https://www.warp-charger.com/documents/WARP3_Bohrschablone.pdf)

Bei den Varianten Smart und Pro zusätzlich:
-   drei NFC-Karten

Die Wallbox wird in einer Wellpappverpackung geliefert, der Umschlag mit dem
Zubehör befindet sich in der oberen ebene der Verpackung. Das Kabel ist in der
unteren ebene aufgerollt.

![image](/img/first_steps/packaging_opened.jpg)

### Montageort

Nach Möglichkeit sollte die Wallbox vor Witterungseinflüssen geschützt
installiert werden. Direkte Sonneneinstrahlung ist zu vermeiden, um ein
unnötiges Aufheizen der Wallbox zu verhindern. Auf eine ausreichende
Belüftung ist zu achten. Die Staubschutzkappe des Typ-2-Steckers sollte
nicht aufgesteckt werden, wenn sich diese durch Regen o.ä. mit Wasser
füllen könnte. In diesem Fall droht eine Korrosion der Kontakte.

### Wandmontage

Zur Montage der Wallbox muss der Deckel entfernt werden. Dazu müssen die
vier Kreuzschlitzschrauben (rot) gelöst werden. Nach dem Lösen der
Schrauben kann dieser von der Wallbox heruntergenommen werden.

![image](/img/warp3_shared_with_manual/resized/warp_screw_points_ready.jpg)

Der Taster im Deckel ist über ein Anschlusskabel verbunden und muss
durch Drücken des Rasthebels (blau) vom Kabel gelöst werden.

![image](/img/warp3_shared_with_manual/resized/warp3_frontLEDcable_arrow.jpg)

Zusätzlich muss der Erdungsstecker (grün) von der Frontblende abgesteckt
werden. Erst danach kann der Deckel vollständig zur Seite gelegt werden.

Nach dem Entfernen des Deckels kann das Gehäuse an der Wand montiert
werden. Zum Bohren der Befestigungslöcher kann die mitgelieferte
Bohrschablone genutzt werden. Bei der Montage ist auf einen ausreichend
stabilen Untergrund zu achten.

Wir empfehlen zur Montage den Einsatz von 5 mm- oder
6 mm-Schrauben. Die Schraubenlänge ist abhängig vom
Untergrund. Der Schraubenkopfdurchmesser darf nicht mehr als
11 mm betragen, da ansonsten die Schraube nicht durch
die entsprechende Öffnung im Gehäuse passt. Bei einer Montage auf einer
Steinwand können beispielsweise
5×80 mm-Holzschrauben mit
8×50 mm-Dübeln verwendet werden.

### Anforderungen an die Elektroinstallation

Die Wahl des Leitungsquerschnitts und der Leitungsabsicherung der
Wallbox-Zuleitung muss in Übereinstimmung mit den nationalen
Vorschriften erfolgen. Üblicherweise erfolgt der Anschluss der Wallbox
dreiphasig. Dafür sollte ein dreiphasiger Leitungsschutzschalter mit
C-Charakteristik verwendet werden. Bei einem einphasigen Betrieb der
Wallbox ist dementsprechend ein einphasiger Leitungsschutzschalter
einzusetzen. Die Wallbox verfügt über eine interne
DC-Fehlerstromerkennung, welche bei einem DC-Fehlerstrom ≥ 6 mA
den Ladevorgang unterbricht. Daher ist nur
ein vorgeschalteter Typ-A 30-AC-Fehlerstromschutzschalter (RCCB)
notwendig. Die Wallbox darf nur in einem TN / TT-Netz angeschlossen
werden.

## Elektrischer Anschluss

Die in diesem Abschnitt beschriebenen Arbeiten dürfen nur von einer
ausgewiesenen Elektrofachkraft durchgeführt werden.

Nachdem die Wallbox montiert wurde, kann sie nun angeschlossen werden.
Dazu muss der Deckel entfernt werden.

### Anschluss der Zuleitung

![image](/img/warp3_shared_with_manual/resized/warp_cable_cut_ready.jpg)

Die Zuleitung sollte für alle Varianten wie auf dem Foto oben abgebildet
angefertigt werden. Wir empfehlen, das Kabel dafür auf einer Länge von
mindestens 130 mm abzumanteln. Für die Klemmen wird eine Abisolierlänge
von 10 bis 12 mm vorgegeben.

Die Zuleitung wird am internen Klemmenblock angeschlossen. Um bei
starren Leitern maximalen Bewegungsspielraum zu bieten, werden die Adern
in einer kleinen Schlaufe über den Klemmenblock geführt und an den
freien Federklemmplätzen angeschlossen. Die Adern werden anhand der
Reihenfolge und Klemmenbeschriftungen in die Klemmen gesteckt.

![image](/img/warp3_shared_with_manual/resized/warp3_smart_open_connected.jpg)

Als Letztes muss die Kabelverschraubung festgezogen werden. Die
Verschraubung hat einen Klemmbereich von 11 mm bis 22 mm und soll laut
Hersteller mit 10 angezogen werden.

Der korrekte Sitz der Adern und die Phasenzugehörigkeit sind nach der
Installation zu prüfen! Alle Verschraubungen innerhalb der Wallbox sind
nachzuziehen. Als Nächstes muss der maximale Ladestrom eingestellt
werden.

### Kabeleinführung von der Rückseite

Die Kabeleinführung des WARP3 Chargers von der Unterseite
(Auslieferungszustand) kann umgebaut werden, so dass eine
Kabeleinführung von der Rückseite erfolgt. Dazu müssen die
Kabeleinführung (M32) für die Zuleitung und die Kabeleinführung für das
Netzwerkkabel vom Wallbox-Gehäuse abgeschraubt werden. Die Bohrungen in
der Rückseite der Wallbox sind im Auslieferungszustand von innen mit
Blindstopfen verschlossen. Diese müssen entfernt und in die nun offenen
Bohrungen an der Unterseite eingeschraubt werden. Die Kabeleinführungen
werden anschließend von der Rückseite in das Wallbox-Gehäuse
eingeschraubt.

![image](/img/warp3_shared_with_manual/resized/warp3_back.jpg)

### Variante mit werkseitig angeschlossener Zuleitung

Wird die Wallbox mit einer ab Werk vorinstallierten Zuleitung bestellt,
so muss diese außerhalb der Wallbox verbunden werden. Die Farben sind
nach DIN belegt und wie folgt zugeordnet: L1 braun, L2 schwarz, L3 grau,
N blau, PE gelb/grün.

Der korrekte Sitz der Adern und die Phasenzugehörigkeit sind nach der
Installation zu prüfen! Danach muss der maximale Ladestrom eingestellt
werden.

### Einphasiger Betrieb

Alle Wallboxen können auch einphasig angeschlossen und betrieben werden.
Dazu ist unbedingt die Phase L1 anzuschließen, da diese ebenfalls zur
Stromversorgung der Wallbox genutzt wird. L2 und L3 werden von der
Wallbox nur durchgeschaltet und können dementsprechend unangeschlossen
bleiben.

Ein WARP3 Charger Smart oder Pro sollte im Webinterface auf den
einphasigen Betrieb konfiguriert werden.

### Einstellen des Ladestroms

Der maximal erlaubte Ladestrom muss abhängig von der hausseitigen
Leitungsabsicherung eingestellt werden. Der Ladestrom darf nicht höher
gewählt werden, als es die Zuleitung bzw. Leitungsabsicherung zulässt.

Zum Einstellen des Ladestroms muss der Deckel
geöffnet werden. Über vier DIP-Schalter rechts auf dem Ladecontroller
(EVSE) wird der maximale Ladestrom wie folgt eingestellt (maximal
zulässiger Ladestrom in grau):

![image](/img/warp3_shared_with_manual/resized/warp3_switch_location.jpg)

Die verschiedenen Schalterstellungen sind im nachfolgenden Foto
dokumentiert. Im Werkszustand sind die Schalter so eingestellt, dass die
Wallbox inaktiv ist ("ungültig"). Als Beispiel ist in der zweiten Zeile
Schalter 1 auf "ON" und die Schalter 2, 3 und 4 auf "OFF" gestellt.
Damit wird bei einem dreiphasigen Betrieb eine maximale Ladeleistung von
ca. 4 kW (3×6 A) vorgegeben. Wird die Wallbox nur
einphasig angeschlossen, können vom Fahrzeug maximal 1,4 kW (1×6 A)
über die Wallbox bezogen werden.

![image](/img/first_steps/hardware_dip_vertical.png)

Die Schalterstellung und der damit verbundene maximale Ladestrom dürfen
nach der Installation nur von einer ausgewiesenen Elektrofachkraft unter
Berücksichtigung der genannten Bedingungen geändert werden!

### LAN- / RJ45-Kabel anfertigen

Um den WARP3 Charger mittels LAN anzubinden, muss ein LAN- / RJ45-Kabel
angefertigt werden. Das RJ45-Kabel kann mittels einer Kabeldurchführung
in die Wallbox geführt werden. Auf dem Ladecontroller (rechts in der
Wallbox) befindet sich eine RJ45-Buchse, an der das eingeführte Kabel
eingesteckt werden kann. Wir empfehlen, das Kabel in einem Bogen links
über den Klemmblock zu führen. Es können auch größere, zum Beispiel
werkzeuglose oder RJ45-Stecker mit einem LSA-Anschluss, genutzt werden.

![image](/img/warp3_shared_with_manual/resized/warp3_pro_open_highlighted_LAN.jpg)

## Prüfungen

Im Werk wurde jede Wallbox einzeln nach IEC 60364-6 sowie den
entsprechenden gültigen nationalen Vorschriften geprüft, das jeweilige
Messprotokoll liegt bei. Vor der ersten Inbetriebnahme ist dennoch eine
Prüfung der Gesamtinstallation nach denselben Vorschriften notwendig.

Bei der Messung des Isolationswiderstands wird für L1 ein niedrigerer
Wert gemessen (ca. 1 MΩ), da der verbaute Ladecontroller über einen
Optokoppler mit 1 MΩ Vorwiderstand zwischen L1 und PE verfügt
(Erdungsüberwachung). Wird während der Messung ein EVSE-Adapter
verwendet, kann es aufgrund der genannten Überwachungsschaltung in
Wechselwirkung mit dem EVSE-Adapter zu Fehlmessungen auf L2, L3 und N
(gemessen gegen PE) kommen. Ist dies der Fall, so muss die
Isolationsmessung ohne EVSE-Adapter direkt am Typ-2-Stecker durchgeführt
werden.

Die interne DC-Fehlerstromerkennung wird von der Wallbox automatisch
getestet.

Nachdem die Wallbox installiert und die korrekte elektrische
Installation überprüft wurde, kann die Wallbox in Betrieb genommen
werden. Im ersten Schritt wird die Stromversorgung zur Wallbox
eingeschaltet. Die LED blinkt anschließend sehr schnell magenta. Die
Wallbox führt in den ersten drei Sekunden eine Kalibrierung der
DC-Fehlerstromerkennung durch. Nach Abschluss dieser Kalibrierung
leuchtet die LED dauerhaft. Die Wallbox ist nun betriebsbereit. Sollte
die LED jetzt nicht permanent blau leuchten, wurde ein Fehler erkannt.

Als Nächstes kann ein Elektrofahrzeug zum Laden mit der Wallbox
verbunden werden. Dazu wird die Schutzkappe vom Ladestecker entfernt und
der Stecker wird in die Ladebuchse des Elektrofahrzeugs gesteckt. Nach
wenigen Sekunden sollte hörbar ein Schütz in der Wallbox schalten und
das Fahrzeug den Beginn des Ladevorgangs anzeigen. Während des
Ladevorgangs "atmet" die LED blau. Ist der Ladevorgang beendet, so
leuchtet sie permanent. Nach ca. 15 Minuten Inaktivität wird die LED
abgeschaltet.

Mittels des Fronttasters kann ein Ladevorgang sofort unterbrochen werden
(Standardeinstellung). Alternativ kann das Ladekabel vom Elektrofahrzeug
entriegelt werden, wodurch der Ladevorgang ebenfalls unterbrochen wird.
Um den Ladevorgang erneut zu starten, muss in beiden Fällen die
Verbindung zum Fahrzeug getrennt und anschließend erneut hergestellt
(Kabel aus- und wieder einstecken) oder der Ladevorgang über das
Webinterface neugestartet werden.

## Bedienelemente

Die im Fronttaster verbaute RGB-LED kann je nach Betriebszustand
verschiedene Farben annehmen. Das Verhalten bei einem Tastendruck kann
im Webinterface der Wallbox konfiguriert werden.

Zusätzlich verfügen die Wallbox-Varianten Smart und Pro über ein
NFC-Modul, mit dem eine Ladefreigabe z.B. per Chipkarte möglich ist.
Eine genaue Beschreibung findet sich im Abschnitt .

## EVSE Klemmblock / Abschalteingang

Rechts in der Wallbox befindet sich der Ladecontroller. Neben dem
DIP-Schalter, an dem der maximale Ladestrom eingestellt wird, befindet
sich ein Klemmblock. An diesem ist die CP-Leitung des Typ-2-Ladekabels
angeschlossen, sowie der PP-Widerstand, mit dem der maximale Strom des
Ladekabels definiert wird.

Zusätzlich befindet sich hier der Abschalteingang ("EN"). Dieser Eingang
muss mit PE kurzgeschlossen werden, um aktiv zu sein. PE ist mehrfach
auf dem Klemmblock vorhanden. Zur Konfiguration des Abschalteingangs
siehe [Steuerbare Verbrauseinrichtung nach §14a EnWG](/warp_charger/verbrauchseinrichtung.md).

![image](/img/warp3_shared_with_manual/resized/evse_clamp.jpg)
