---
sidebar_position: 2
---

# Montage und Installation

## Sicherheitshinweise

Die Wallbox ist so konstruiert, dass ein sicherer Betrieb gewährleistet ist, wenn sie
korrekt installiert wurde, in einem einwandfreien technischen Zustand ist und diese
Betriebsanleitung befolgt wird.

:::warning

Die Wallbox darf nur von einer ausgewiesenen Elektrofachkraft installiert werden.

:::

### Bestimmungsgemäße Verwendung

Mit dem WARP2 Charger können Elektrofahrzeuge gemäß DIN EN 61851-1 geladen werden. Für
andere Anwendungen ist die Wallbox nicht geeignet. Eine Verwendung an Orten, an denen
explosionsfähige oder brennbare Substanzen lagern, ist nicht zulässig. Jegliche
Modifikation des Ladesystems und auch der Betrieb mit Verlängerungskabeln,
Mehrfach-Steckdosen oder Ähnlichem ist verboten. Der Ladestecker ist vor Beschädigungen,
Feuchtigkeit und Verschmutzungen zu schützen und darf nicht genutzt werden, wenn kein
sicherer Betrieb gewährleistet werden kann.

:::warning

Mit einem beschädigten, verschmutzten oder feuchten Ladestecker darf kein Ladevorgang
durchgeführt werden.

:::

### Gerätestörung / Technischer Defekt

Sollte es Anzeichen für einen technischen Defekt geben, ist sofort die Stromversorgung
der Wallbox durch Abschalten der Wallbox-Sicherung im Verteilerkasten zu trennen. Die
Sicherung ist mit dem Hinweis, dass sie nicht wieder eingeschaltet werden darf, zu
markieren. Danach ist eine Elektrofachkraft zu informieren.

### Schutzeinrichtungen der Wallbox

Der AC-Fehlerstromschutz wird über den hausseitig verbauten Typ-A
AC-Fehlerstromschutzschalter (RCCB) oder einen eigens dafür installierten Typ-A
30 mA-Fehlerstromschutzschalter gewährleistet. Die Wallbox ist mit einer integrierten
DC-Fehlerstromüberwachung ausgestattet. Bei einem DC-Fehlerstrom ≥ 6 mA wird dieser
Fehlerstrom von der Wallbox erkannt und die Verbindung zum Fahrzeug wird sofort
unterbrochen (Schütz schaltet ab). Die Wallbox befindet sich ab sofort in einem
Fehlerzustand und kann erst durch Aus- und Einschalten der Stromversorgung oder über das
Webinterface wieder zurückgesetzt werden.

:::warning

Tritt ein DC-Fehlerstrom auf, ist unbedingt die Ursache zu ermitteln! Ein DC-Fehlerstrom
kann den vorgeschalteten Fehlerstromschutzschalter "erblinden" lassen, so dass dann auch
Wechselspannungs (AC)-Fehlerströme nicht mehr korrekt erkannt werden!

:::

Darüber hinaus bietet die Wallbox weitere Schutzeinrichtungen: Dazu zählt eine permanente
Erdungsüberwachung (PE). Ist die Erdung unterbrochen, so geht die Wallbox in einen
Fehlerzustand. Außerdem prüft die Wallbox bei jedem Schaltvorgang, ob das verbaute Schütz
korrekt schaltet. Sollte das Schütz nicht mehr korrekt schalten, geht die Wallbox
ebenfalls in einen Fehlerzustand. Fehler können wie in der [Fehlerbehebung](/docs/warp2/troubleshooting)
beschrieben diagnostiziert werden.

## Montage

### Lieferumfang

Im Lieferumfang der Wallbox befinden sich:

-   Vormontierte Wallbox inkl. Deckel
-   DIN-A4-Umschlag mit:
    -   Betriebsanleitung
    -   Testprotokoll der Wallbox
    -   Bohrschablone

Bei den Varianten Smart und Pro zusätzlich:

-   Drei NFC-Karten

### Montageort

Nach Möglichkeit sollte die Wallbox vor Witterungseinflüssen geschützt installiert
werden. Direkte Sonneneinstrahlung ist zu vermeiden, um ein unnötiges Aufheizen der
Wallbox zu verhindern. Auf eine ausreichende Belüftung ist zu achten. Die
Staubschutzkappe des Typ-2-Steckers sollte nicht aufgesteckt werden, wenn diese durch
Regen o.ä. mit Wasser voll laufen könnte. In diesem Fall droht eine Korrosion der
Kontakte des Typ-2-Steckers.

### Wandmontage

Zur Montage der Wallbox muss der Deckel entfernt werden. Dazu müssen die vier
Kreuzschlitzschrauben gelöst werden. Nach dem Lösen der Schrauben kann der Deckel von der
Wallbox heruntergenommen werden.

![image](/img/warp2/warp_screw_points_ready.jpg)

Der Taster im Deckel ist über ein Anschlusskabel verbunden und muss durch Drücken des
Rasthebels vom Kabel gelöst werden.

![image](/img/warp2/warp2_button_and_gnd_600.jpg)

Zusätzlich muss der Erdungsstecker von der Frontblende abgesteckt werden. Erst danach kann
der Deckel vollständig zur Seite gelegt werden.

Nach dem Entfernen des Deckels kann das Gehäuse an der Wand montiert werden. Zum Bohren
der Befestigungslöcher kann die mitgelieferte Bohrschablone genutzt werden. Bei der
Montage ist auf einen ausreichend stabilen Untergrund zu achten.

Wir empfehlen zur Montage den Einsatz von 5 mm- oder 6 mm-Schrauben. Die benötigte
Schraubenlänge ist abhängig vom Untergrund. Der Schraubenkopfdurchmesser darf nicht mehr
als 11 mm betragen, da ansonsten die Schraube nicht durch die entsprechende Öffnung im
Gehäuse passt. Bei einer Montage auf einer Steinwand können beispielsweise
5×80 mm-Holzschrauben mit 8×50 mm-Dübeln verwendet werden.

### Anforderungen an die Elektroinstallation

Die Wahl des Leitungsquerschnitts und der Leitungsabsicherung der Wallbox-Zuleitung muss
in Übereinstimmung mit den nationalen Vorschriften erfolgen. Üblicherweise erfolgt der
Anschluss der Wallbox dreiphasig. Dafür sollte ein dreiphasiger Leitungsschutzschalter
mit C-Charakteristik verwendet werden. Bei einem einphasigen Betrieb der Wallbox ist
dementsprechend ein einphasiger Leitungsschutzschalter einzusetzen. Die Wallbox verfügt
über eine interne DC-Fehlerstromerkennung, welche bei einem DC-Fehlerstrom ≥ 6 mA den
Ladevorgang unterbricht. Daher ist nur ein vorgeschalteter Typ-A
30 mA-Fehlerstromschutzschalter (RCCB) notwendig. Die Wallbox darf nur in einem TN / TT-Netz
angeschlossen werden.

## Elektrischer Anschluss

:::note

Die in diesem Abschnitt beschriebenen Arbeiten dürfen nur von einer ausgewiesenen
Elektrofachkraft durchgeführt werden.

:::

Nachdem die Wallbox montiert wurde, kann sie nun angeschlossen werden. Dazu muss der
Deckel entfernt werden.

![image](/img/warp2/warp_cable_cut_ready.jpg)

Die Zuleitung muss für alle Varianten wie auf dem Foto oben abgebildet angefertigt
werden. Wir empfehlen, das Kabel dafür auf einer Länge von 23 cm abzumanteln. Für die
Klemmen wird eine Abisolierlänge von 10 mm bis 12 mm vorgegeben.

Wie diese Zuleitung angeschlossen wird, unterscheidet sich bei den Varianten Basic / Smart
(ohne Zähler) und Pro (mit Zähler) und ist nachfolgend beschrieben.

### Variante Basic / Smart

![image](/img/warp2/warp2_basic_top_open.jpg)

Bei den Wallbox-Varianten Basic und Smart wird die Zuleitung an einen internen
Klemmenblock angeschlossen. Um bei starren Leitern maximalen Bewegungsspielraum zu bieten,
werden die Adern um den Klemmenblock geführt und an den freien Federklemmplätzen
angeschlossen. Die Adern werden anhand der Reihenfolge und Klemmenbeschriftungen in die
Klemmen gesteckt.

Als Letztes muss die Kabelverschraubung festgezogen werden. Die Verschraubung hat einen
Klemmbereich von 11 mm bis 22 mm und soll laut Hersteller mit 10 Nm angezogen werden.

Der korrekte Sitz der Adern und die Phasenzugehörigkeit sind nach der Installation zu
prüfen! Alle Verschraubungen innerhalb der Wallbox sind nachzuziehen. Als Nächstes muss
der maximale Ladestrom eingestellt werden (siehe Abschnitt
[Einstellen des Ladestroms](#einstellen-des-ladestroms)).

### Variante Pro

![image](/img/warp2/warp2_pro_top_open.jpg)

Die Variante Pro verfügt aus Platzgründen nur über einen Klemmenblock für PE. Die
Zuleitungsadern außer PE müssen oben an den Zähler angeschlossen werden.

Als Letztes muss die Kabelverschraubung festgezogen werden. Die Verschraubung hat einen
Klemmbereich von 11 mm bis 22 mm und soll laut Hersteller mit 10 Nm angezogen werden.

Der korrekte Sitz der Adern und die Phasenzugehörigkeit sind nach der Installation zu
prüfen! Alle Verschraubungen innerhalb der Wallbox sind nachzuziehen. Als Nächstes muss
der maximale Ladestrom eingestellt werden (siehe Abschnitt
[Einstellen des Ladestroms](#einstellen-des-ladestroms)).

### Variante mit werkseitig angeschlossener Zuleitung

Wird die Wallbox mit einer ab Werk vorinstallierten Zuleitung bestellt, so muss diese
außerhalb der Wallbox verbunden werden. Die Farben sind nach DIN belegt und wie folgt
zugeordnet: L1 braun, L2 schwarz, L3 grau, N blau, PE gelb/grün.

Der korrekte Sitz der Adern und die Phasenzugehörigkeit sind nach der Installation zu
prüfen! Als Nächstes muss der maximale Ladestrom eingestellt werden.

### Kabeleinführung von der Rückseite

Ab Version 2.1 des WARP Chargers kann die Kabeleinführung von der Unterseite
(Auslieferungszustand) umgebaut werden, so dass eine Kabeleinführung von der Rückseite
erfolgt.

Dazu müssen die Kabeleinführung (M32) für die Zuleitung und die Kabeleinführung für das
Netzwerkkabel vom Wallbox-Gehäuse abgeschraubt werden. Die Bohrungen in der Rückseite der
Wallbox sind im Auslieferungszustand mit Blindstopfen von innen verschlossen. Diese müssen
entfernt und in die nun offenen Bohrungen an der Unterseite eingeschraubt werden. Die
Kabeleinführungen werden anschließend von der Rückseite in das Wallbox-Gehäuse
eingeschraubt.

![image](/img/warp2/warp2_1_back_wp_ready_1000.jpg)

### Einphasiger Betrieb

Alle Wallboxen können auch einphasig angeschlossen und betrieben werden. Dazu ist
unbedingt Phase L1 anzuschließen, da diese Phase ebenfalls zur Stromversorgung der Wallbox
genutzt wird. L2 und L3 werden von der Wallbox nur durchgeschaltet und können
dementsprechend unangeschlossen bleiben.

Ein WARP2 Charger Smart oder Pro sollte im Webinterface auf den
[einphasigen Betrieb](/docs/webinterface/wallbox/settings) konfiguriert werden.

### Einstellen des Ladestroms

Der maximal erlaubte Ladestrom muss abhängig von der gebäudeseitigen Leitungsabsicherung
eingestellt werden. Der Ladestrom darf nicht höher gewählt werden, als die
Leitungsabsicherung es zulässt.

Zum Einstellen des Ladestroms muss der Deckel geöffnet werden. Über zwei Schiebeschalter
auf dem internen Ladecontroller (EVSE) wird der maximale Ladestrom wie folgt eingestellt:

![image](/img/warp2/warp2_current_configure_w_caption_600.jpg)

Die verschiedenen Schalterstellungen sind im obigen Foto dokumentiert. Der schwarze Block
stellt dabei jeweils die Position des Schalters dar. Im Werkszustand sind die Schalter so
eingestellt, dass die Wallbox inaktiv ist. Im Foto ist exemplarisch der obere Schalter auf
die linke und der untere auf die mittlere Position gestellt worden. Damit wird eine
maximale Ladeleistung bei einem dreiphasigen Betrieb von 9 kW (3×13 A) vorgegeben. Wird
die Wallbox nur einphasig angeschlossen, können maximal 3 kW (1×13 A) über die Wallbox vom
Hausanschluss bezogen werden.

:::warning

Die Schalterstellung und der damit verbundene maximale Ladestrom dürfen nach der
Installation nur von einer ausgewiesenen Elektrofachkraft unter Berücksichtigung der
genannten Bedingungen geändert werden!

:::

| Schalter oben (1) | Schalter unten (2) | Strom | Ladeleistung einphasig | Ladeleistung dreiphasig |
|-|-|-|-|-|
| links | links | 0 A | 0 kW | 0 kW |
| mitte | links | 6 A | 1,4 kW | 4,1 kW |
| rechts | links | 10 A | 2,3 kW | 6,0 kW |
| links | mitte | 13 A | 3,0 kW | 9,0 kW |
| mitte | mitte | 16 A | 3,7 kW | 11,0 kW |
| rechts | mitte | 20 A | 4,6 kW | 13,8 kW |
| links | rechts | 25 A | 5,6 kW | 17,3 kW |
| mitte | rechts | 32 A | 7,4 kW | 22,0 kW |

:::note

Wird kein maximaler Ladestrom eingestellt (0 A), so befindet sich die Wallbox in einem
Fehlerzustand.

:::

### LAN- / RJ45-Kabel anfertigen

Um den WARP Charger mittels LAN anzubinden, muss ein LAN- / RJ45-Kabel angefertigt werden.
Je nach Version der Wallbox unterscheidet sich hierbei die Ausführung.

#### WARP 2.1

Ab Version 2.1 des WARP Chargers kann das RJ45-Kabel einfach mittels einer
Kabeldurchführung in die Wallbox geführt werden. In der Wallbox befindet sich eine
kabelgebundene RJ45-Buchse, an der das eingeführte Kabel einfach mittels eines am Kabel
anzubringenden RJ45-Steckers angeschlossen werden kann. Es können somit auch größere
RJ45-Stecker, wie werkzeuglose RJ45-Stecker oder RJ45-Stecker mit einem LSA-Anschluss,
genutzt werden.

![image](/img/warp2/warp2_1_top_ready_1000.jpg)

#### WARP 2.0

Bei dem WARP Charger 2.0 befindet sich eine spritzwassergeschützte RJ45-Durchführung auf
der Unterseite, an die der in der Wallbox verbaute Controller intern angeschlossen ist. Um
ein LAN-Kabel anzuschließen, muss der Blinddeckel abgeschraubt werden.

![image](/img/warp2/warp2_ethernet3_circle_600.jpg)

Anschließend muss ein LAN-Kabel (z.B. Cat. 7) wie folgt angefertigt werden:

1.  Das LAN-Kabel durch den Aufsatz ziehen.
2.  Den mitgelieferten RJ45-Stecker auf das LAN-Kabel crimpen. Die Kontaktierung erfolgt
    typischerweise nach TIA-568 Schema A oder B. Das verwendete Schema sollte auf beiden
    Kabelseiten identisch sein.

    ![image](/img/warp2/warp2_rj45_1_600.jpg)

    :::note

    Es sollte der mitgelieferte RJ45-Stecker verwendet werden. Werkzeuglose RJ45-Stecker
    können aufgrund des begrenzten Platzes im Steckeraufsatz bei dem WARP Charger 2.0 nicht
    verwendet werden.

    :::

3.  Das Kabel im Aufsatz zurückziehen und die Zugentlastung handfest anziehen.

    ![image](/img/warp2/warp2_rj45_2_600.jpg)

Zum Schluss wird der RJ45-Stecker in die Wallbox eingesteckt und die Überwurfmutter wird
handfest angezogen.

![image](/img/warp2/warp2_ethernet4_600.jpg)

## Steuerbare Verbrauchseinrichtung nach §14a EnWG

Wallboxen gehören nach §14a EnWG zu sogenannten Steuerbaren Verbrauchseinrichtungen, da
deren Anschlussleistung über 4,2 kW beträgt. WARP Charger können auf verschiedene Arten
vom Netzbetreiber gesteuert werden. Welche Möglichkeit genutzt werden kann, hängt von den
Vorgaben des örtlichen Netzbetreibers ab. Weitere Informationen finden sich im Tutorial
[Steuerbare Verbrauchseinrichtung nach §14a EnWG](/docs/tutorials/verbrauchseinrichtung).

#### Schnittstellen (OCPP, Modbus TCP, HTTP, MQTT)

Generell kann die Ladeleistung der Wallbox über alle implementierten Schnittstellen
gesteuert werden. Netzbetreiber setzen zur Steuerung typischerweise OCPP oder Modbus TCP
ein.

#### Rundsteuerempfänger / Steuerbox

Am Abschalteingang innerhalb der Wallbox kann ein potentialfreier Kontakt (spannungsfreier
Schaltkontakt) angeschlossen werden. Dazu muss eine Steuerleitung vom Rundsteuerempfänger
oder der Steuerbox des Netzbetreibers in die Wallbox gelegt werden und am Ladecontroller
(untere Platine) am mit "Enable" beschrifteten, dreipoligen Stecker an Pin 1 und Pin 2
angeschlossen werden. Damit die Wallbox abschaltet, muss unter Wallbox -> Ladeeinstellungen
die Einstellung "Abschalteingang" auf "Begrenzen auf 4300 W wenn geschlossen" bzw. "wenn
geöffnet" konfiguriert werden.

#### Rundsteuerempfänger / Steuerbox (mittels WARP Energy Manager)

Anstatt eine Steuerleitung bis in die Wallbox zu legen, besteht auch die Möglichkeit, die
Eingänge des WARP Energy Managers mit dem Rundsteuerempfänger oder der Steuerbox zu
verbinden. Der WARP Energy Manager steuert dann die Leistung der Wallbox(en) über das
Netzwerk (LAN/WLAN). Eine gesonderte Steuerleitung entfällt. Der WARP Energy Manager muss
hierfür als Lastmanager der betreffenden Wallbox(en) konfiguriert werden. Anschließend muss
in "Energiemanager" -> "Automatisierung" folgende Regel angelegt werden:

-   **Bedingung:** "Eingang 3 geschaltet" (bzw. Eingang 4) -> "auf geschlossen"
-   **Aktion:** "Begrenze maximalen Gesamtstrom"
-   **Maximaler Gesamtstrom:** 6 A (bzw. 18 A bei einphasigem Anschluss)

## Prüfungen

Im Werk wurde jede Wallbox einzeln nach IEC 60364-6 sowie den entsprechenden gültigen
nationalen Vorschriften geprüft, das jeweilige Messprotokoll liegt bei. Vor der ersten
Inbetriebnahme ist dennoch eine Prüfung der Gesamtinstallation nach denselben Vorschriften
notwendig.

Bei der Messung des Isolationswiderstands wird für L1 ein niedrigerer Wert gemessen (ca.
249 kΩ). Dies hat den Hintergrund, dass der verbaute Ladecontroller über je einen
Optokoppler mit 249 kΩ Vorwiderstand, vor und nach dem Schütz, zwischen L1 und PE verfügt
(Erdungsüberwachung, Schützüberwachung). Wird während der Messung ein EVSE-Adapter
verwendet, kann es aufgrund der genannten Überwachungsschaltung in Wechselwirkung mit dem
EVSE-Adapter zu Fehlmessungen auf L2, L3 und N (gemessen gegen PE) kommen. Ist dies der
Fall, so muss die Isolationsmessung ohne EVSE-Adapter direkt am Typ-2-Stecker durchgeführt
werden.

Die interne DC-Fehlerstromerkennung wird von der Wallbox automatisch getestet.

Nachdem die Wallbox installiert und die korrekte elektrische Installation überprüft wurde,
kann die Wallbox in Betrieb genommen werden. Im ersten Schritt wird die Stromversorgung zur
Wallbox eingeschaltet. Die blaue LED blinkt anschließend sehr schnell. Die Wallbox führt in
den ersten drei Sekunden eine Kalibrierung der DC-Fehlerstromerkennung durch. Nach Abschluss
dieser Kalibrierung leuchtet die LED dauerhaft. Die Wallbox ist nun betriebsbereit. Sollte
die LED jetzt nicht permanent leuchten, wurde ein Fehler erkannt (siehe
[Fehlerbehebung](/docs/warp2/troubleshooting)).

Als Nächstes kann ein Elektrofahrzeug zum Laden mit der Wallbox verbunden werden. Dazu wird
die Schutzkappe vom Ladestecker entfernt und der Stecker wird in die Ladebuchse des
Elektrofahrzeugs gesteckt. Nach einer kurzen Zeit sollte hörbar das Schütz in der Wallbox
schalten und das Fahrzeug sollte den Beginn des Ladevorgangs anzeigen. Die blaue LED
"atmet" während des Ladevorgangs. Ist der Ladevorgang beendet, so leuchtet die LED
permanent. Nach ca. 15 Minuten Inaktivität schaltet sich die LED aus.

## Bedienelemente

Das Drücken des Tasters auf der Frontseite unterbricht einen aktiven Ladevorgang sofort.
Alternativ kann das Ladekabel vom Elektrofahrzeug entriegelt werden, wodurch der
Ladevorgang ebenfalls unterbrochen wird. Um den Ladevorgang erneut zu starten, muss in
beiden Fällen die Verbindung zum Fahrzeug getrennt und anschließend erneut hergestellt
werden (Kabel aus- und wieder einstecken).

Zusätzlich verfügen die Wallbox-Varianten Smart und Pro über ein NFC-Modul, wodurch eine
Ladefreigabe z.B. per Chipkarte möglich ist. Eine genaue Beschreibung findet sich im
Abschnitt [Benutzerverwaltung](/docs/webinterface/users/user_management).
