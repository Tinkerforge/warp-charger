---
sidebar_position: 2
---

# Montage und Installation

## Sicherheitshinweise

### Allgemein

Die Wallbox ist so konstruiert, dass ein sicherer Betrieb gewährleistet ist, wenn sie korrekt
installiert wurde, in einem einwandfreien technischen Zustand ist und diese Betriebsanleitung
befolgt wird.

:::note

Die Wallbox darf nur von einer ausgewiesenen Elektrofachkraft installiert werden.

:::

### Bestimmungsgemäße Verwendung

Mit der WARP1 Wallbox können Elektrofahrzeuge gemäß DIN EN 61851-1 geladen werden. Für andere
Anwendungen ist die Wallbox nicht geeignet. Eine Verwendung an Orten, an denen explosionsfähige
oder brennbare Substanzen lagern, ist nicht zulässig. Jegliche Modifikation des Ladesystems sowie
der Betrieb mit Verlängerungskabeln, Mehrfachsteckdosen oder Ähnlichem ist verboten. Der
Ladestecker ist vor Beschädigungen, Feuchtigkeit und Verschmutzungen zu schützen und darf nicht
genutzt werden, wenn kein sicherer Betrieb gewährleistet werden kann.

:::note

Mit einem beschädigten, verschmutzten oder feuchten Ladestecker darf kein Ladevorgang durchgeführt
werden.

:::

### Gerätestörung / Technischer Defekt

Sollte es Anzeichen für einen technischen Defekt geben, trenne sofort die Stromversorgung zur
Wallbox, indem du die Wallbox-Sicherung in der Hausinstallation abschaltest. Markiere die
Sicherung mit dem Hinweis, dass sie nicht wieder eingeschaltet werden darf, und informiere
umgehend den Installateur.

### Schutzeinrichtungen der Wallbox

Der AC-Fehlerstromschutz wird über den hausseitig verbauten Typ-A AC-Fehlerstromschutzschalter
(RCCB) oder einen eigens dafür installierten Typ-A 30 mA-Fehlerstromschutzschalter gewährleistet.
Die Wallbox ist mit einem integrierten DC-Fehlerstromwächter der Firma Alcona ausgestattet
(ALC-DC6-CO30). Bei einem DC-Fehlerstrom ≥ 6 mA generiert dieser einen AC-Fehlerstrom, der den
hausseitig verbauten Typ-A-Fehlerstromschutzschalter sicher auslöst (AC-Auslösestrom ≥ 70 mA).
Somit wird sichergestellt, dass bei Auftreten eines DC-Fehlerstroms die Stromversorgung
unterbrochen wird.

Darüber hinaus bietet die Wallbox weitere Schutzeinrichtungen: Dazu zählt eine permanente
Erdungsüberwachung (PE). Ist die Erdung unterbrochen, so geht die Wallbox in einen Fehlerzustand.
Zusätzlich prüft die Wallbox bei jedem Schaltvorgang, ob das verbaute Schütz korrekt schaltet.
Sollte das Schütz defekt sein (schaltet nicht an oder ab), geht die Wallbox ebenfalls in einen
Fehlerzustand.

## Montage

### Lieferumfang

Im Lieferumfang der Wallbox befinden sich:

 * Vormontierte Wallbox inkl. Deckel
 * Bohrschablone
 * Betriebsanleitung
 * Testprotokoll der Wallbox

### Montageort

Nach Möglichkeit sollte die Wallbox vor Witterungseinflüssen geschützt installiert werden.
Direkte Sonneneinstrahlung ist zu vermeiden, um ein unnötiges Aufheizen der Wallbox zu
verhindern. Auf eine ausreichende Belüftung ist zu achten.

### Wandmontage

Zur Montage der Wallbox muss der Deckel entfernt werden. Dazu müssen die vier
Kreuzschlitzschrauben gelöst werden. Nach dem Lösen der Schrauben kann der Deckel von der
Box heruntergenommen werden.

![image](/img/warp1/warp_screw_points_ready.jpg)

![image](/img/warp1/warp_button_connect_arrow_ready.jpg)

:::note

Der Taster im Deckel ist über ein Anschlusskabel verbunden und muss durch Drücken der Raste
vom Kabel gelöst werden.

:::

Zusätzlich muss der Erdungsstecker von der Frontblende abgesteckt werden. Erst danach kann der
Deckel vollständig zur Seite gelegt werden.

Nach dem Entfernen des Deckels kann das Gehäuse an die Wand montiert werden. Zum Bohren der
Befestigungslöcher kann die mitgelieferte Bohrschablone genutzt werden. Auf einen ausreichend
stabilen Untergrund ist bei der Montage zu achten.

### Anforderungen an die Elektroinstallation

Die Wahl des Leitungsquerschnitts und der Leitungsabsicherung der Wallbox-Zuleitung muss in
Übereinstimmung mit den nationalen Vorschriften erfolgen. Es sollte ein 3-poliger
Leitungsschutzschalter mit C-Charakteristik verwendet werden. Die Wallbox verfügt über eine
interne DC-Fehlerstromerkennung, welche bei einem DC-Fehlerstrom ≥ 6 mA einen
70 mA-AC-Fehlerstrom erzeugt, der dazu gedacht ist, einen vorgeschalteten
AC-Fehlerstromschutzschalter (RCCB) auszulösen.

:::note

Um im Fehlerfall eine Abschaltung zu garantieren, ist ein vorgeschalteter
30 mA-Fehlerstromschutzschalter (RCCB) Typ-A notwendig.

:::

Die Wallbox darf nur in einem TN / TT-Netz angeschlossen werden.

## Elektrischer Anschluss

:::note

Die in diesem Abschnitt beschriebenen Arbeiten dürfen nur von einer ausgewiesenen
Elektrofachkraft durchgeführt werden.

:::

Der elektrische Anschluss unterscheidet sich bei den Varianten Basic / Smart (ohne Zähler)
und Pro (mit Zähler).

![image](/img/warp1/warp_basic_inlay_ready.jpg)

WARP1 Charger Basic.

![image](/img/warp1/warp_pro_inlay_ready.jpg)

WARP1 Charger Pro.

### Variante Basic / Smart

Nachdem die Wallbox montiert wurde, kann sie nun angeschlossen werden. Dazu ist zusätzlich zum
Deckel auch der interne Berührungsschutz zu entfernen. Dieser wird durch Lösen der vier
Schlitzschrauben entfernt.

Bei der Variante Smart ist auf dem Berührungsschutz ein WLAN-Controller (ESP32 Brick)
angeschlossen, zu dem zwei Kabel führen: ein zweipoliges Stromversorgungskabel und ein
siebenpoliges Bricklet-Kabel, über das die Verbindung mit dem Ladecontroller (EVSE Bricklet)
auf der Hutschiene hergestellt wird. Es reicht aus, den Berührungsschutz ohne Trennung dieser
Leitungen einfach zur Seite zu legen. Soll der Berührungsschutz dennoch vollständig entfernt
werden, so müssen diese Kabel getrennt werden. Beide Kabel werden am besten direkt an der linken
bzw. der Unterseite des ESP32 Brick ausgesteckt. Das Bricklet-Kabel verfügt über eine kleine
Verriegelungstaste, die zum Entfernen gedrückt werden muss.

![image](/img/warp1/warp_cable_cut_ready.jpg)

Bei den Wallbox-Varianten Basic und Smart wird die Zuleitung an einen internen Phoenix Contact
PT 6 Klemmenblock angeschlossen. Um bei starren Leitern maximalen Bewegungsspielraum zu bieten,
werden die Adern um den Klemmenblock geführt und von der Rückseite angeschlossen. Wir empfehlen,
das Kabel dafür auf einer Länge von 20 cm abzumanteln. Für die PT 6 Klemmen wird vom Hersteller
eine Abisolierlänge von 10 mm bis 12 mm vorgegeben.

Die Adern werden anhand der Reihenfolge und Klemmenbeschriftungen in die Klemmen gesteckt.
Anschließend sollten die Adern vorsichtig nach unten gedrückt werden, sodass später die
Frontblende wieder über dem Klemmenblock angebracht werden kann. Als Letztes muss die
Kabelverschraubung festgezogen werden. Die Verschraubung hat einen Klemmbereich von 11 mm bis
22 mm und soll laut Hersteller mit 10 Nm angezogen werden.

Der korrekte Sitz der Adern und die Phasenzugehörigkeit sind nach der Installation zu prüfen!
Fahre anschließend mit [Einstellen des Ladestroms](#einstellen-des-ladestroms) fort.

![image](/img/warp1/warp_wire_ready.jpg)

### Variante Pro

Die Variante Pro wird direkt mit einer 2 m-Gummileitung vom Typ H07RN-F 5G ausgeliefert
(4 mm² bei 11 kW, 6 mm² bei 22 kW). Diese wird extern mit der Zuleitung verbunden, zum Beispiel
über eine Verteilerdose.

Der korrekte Sitz der Adern und die Phasenzugehörigkeit sind nach der Installation zu prüfen!
Fahre anschließend mit [Einstellen des Ladestroms](#einstellen-des-ladestroms) fort.

### Einstellen des Ladestroms

Der maximal erlaubte Ladestrom muss abhängig von der gebäudeseitigen Leitungsabsicherung
eingestellt werden. Der Ladestrom darf nicht höher gewählt werden, als es die Leitungsabsicherung
zulässt.

Zum Einstellen des Ladestroms müssen der Deckel und der interne Berührungsschutz geöffnet werden.
Der Berührungsschutz wird durch Lösen der vier Schlitzschrauben entfernt. Vom Berührungsschutz
gehen mehrere Kabel in die Wallbox. Zum Einstellen des Ladestroms muss der Berührungsschutz nicht
vollständig entfernt werden, sodass die Kabel angeschlossen bleiben dürfen.

![image](/img/warp1/warp_evse_switch_cut_ready_small.jpg)

Über zwei Schiebeschalter auf dem internen Ladecontroller (EVSE) wird der maximale Ladestrom
eingestellt. Die verschiedenen Schalterstellungen sind neben den Schaltern dokumentiert. Der
weiße Block stellt dabei jeweils die Position des Schalters dar. Im Auslieferungszustand sind die
Schalter so eingestellt, dass die Wallbox inaktiv ist. Im obigen Foto sind exemplarisch beide
Schalter auf die mittlere Position gestellt. Damit wurde eine maximale Ladeleistung von 11 kW
(16 A) vorgegeben.

:::note

Die Schalterstellung und der damit verbundene maximale Ladestrom dürfen nach der Installation nur
von einer ausgewiesenen Elektrofachkraft unter Berücksichtigung der genannten Bedingungen
geändert werden!

:::

## Prüfungen

Im Werk wurde jede Wallbox einzeln nach IEC 60364-6 sowie den entsprechenden gültigen nationalen
Vorschriften geprüft, das jeweilige Messprotokoll liegt bei. Vor der ersten Inbetriebnahme ist
dennoch eine Prüfung der Gesamtinstallation nach denselben Vorschriften notwendig.

Die Wallbox führt in den ersten ca. 12 Sekunden nach dem Herstellen der Stromversorgung eine
DC-Fehlerstromerkennungskalibrierung durch (die Wallbox-LED blinkt sehr schnell). Ein Ladevorgang
kann erst nach dieser Kalibrierung beginnen.

Bei der Messung des Isolationswiderstands wird für L1 ein niedrigerer Wert gemessen
(ca. 249 kΩ). Dies hat den Hintergrund, dass der verbaute Ladecontroller über je einen
Optokoppler mit 249 kΩ Vorwiderstand, vor und nach dem Schütz, zwischen L1 und PE verfügt
(Erdungsüberwachung, Schützüberwachung). Wird während der Messung ein EVSE-Adapter verwendet, kann
es aufgrund der genannten Überwachungsschaltung im Wechselspiel mit dem EVSE-Adapter zu
Fehlmessungen auf L2, L3 und N (gemessen gegen PE) kommen. Ist dies der Fall, so muss die
Isolationsmessung ohne EVSE-Adapter direkt am Typ-2-Stecker durchgeführt werden.

Der DC-Fehlerstromschutz kann getestet werden, indem der orangene oder schwarze Taster auf dem
DC-Fehlerstromschutzmodul gedrückt wird (siehe nachfolgendes Foto). In diesem Fall wird ein
AC-Fehlerstrom erzeugt, welcher den vorgeschalteten AC-Fehlerstromschutzschalter auslöst. Der
Taster muss bis zu 10 Sekunden lang gedrückt werden, damit ein AC-Fehlerstrom erzeugt wird.

![image](/img/warp1/warp_hole_button_ready.jpg)

## Inbetriebnahme

![image](/img/warp1/warp_button_key_ready.jpg)

Nachdem die Wallbox installiert und die korrekte elektrische Installation überprüft wurde, kann
die Wallbox in Betrieb genommen werden. Im ersten Schritt wird die Stromversorgung zur Wallbox
eingeschaltet. Die blaue LED (1) der Wallbox blinkt anschließend sehr schnell. Die Wallbox führt
für die ersten 12 Sekunden eine Kalibrierung der DC-Fehlerstrom-Schutzeinrichtung durch. Nach
Abschluss dieser Kalibrierung leuchtet die LED dauerhaft. Die Wallbox ist nun betriebsbereit.
Sollte die LED nicht permanent leuchten, ist die Wallbox entweder über den Schlüsselschalter (2)
deaktiviert, oder es wurde ein Fehler erkannt (siehe [Fehlerbehebung](/docs/warp1/troubleshooting)).

Als Nächstes kann ein Elektrofahrzeug zum Laden mit der Wallbox verbunden werden. Dazu wird die
Schutzkappe vom Ladestecker entfernt und der Stecker in die Ladebuchse des Elektrofahrzeugs
gesteckt. Nach kurzer Zeit sollte hörbar das Schütz in der Wallbox schalten und das
Elektrofahrzeug den Beginn des Ladevorgangs anzeigen. Die Wallbox-LED "atmet" während des
Ladevorgangs. Ist der Ladevorgang beendet, so leuchtet die LED permanent. Nach ca. 15 Minuten
Inaktivität schaltet sich die LED aus.

## Bedienelemente

Das Drücken des Tasters (1) auf der Frontseite unterbricht einen aktiven Ladevorgang sofort.
Alternativ kann das Ladekabel vom Elektrofahrzeug entriegelt werden, wodurch der Ladevorgang
ebenfalls unterbrochen wird. Um den Ladevorgang erneut zu starten, muss in beiden Fällen die
Verbindung zum Fahrzeug getrennt und anschließend erneut hergestellt werden (Kabel aus- und wieder
einstecken).

Über den Schlüsselschalter (2) kann die Ladefunktion der Wallbox permanent deaktiviert werden
(Stellung AUS). Laden ist dann erst wieder möglich, nachdem der Schlüsselschalter auf die Stellung
AN gebracht wurde.
