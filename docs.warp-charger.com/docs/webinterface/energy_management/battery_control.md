---
sidebar_position: 2
---

# Batteriesteuerung

:::note

    Die Steuerung von Batteriespeichern befindet sich zur Zeit noch in der Entwicklung!

    Speicher können von einem [WARP Charger 1,2,3](/docs/warp_charger/introduction) (ab Firmware 2.9.0) oder [WARP Energy Manager 2](/docs/warp_energy_manager/introduction) (ab Firmware 2.5.0) über das Netzwerk gesteuert werden.
    
    Generell werden Speicher unterstützt, die mittels [Modbus/TCP](/docs/compatible_devices/interfaces#modbustcp) Befehlen gesteuert werden können.
    Es können eigene (benutzerdefinierte) Registertabellen angelegt werden, mit dem ein Speicher gesteuert werden kann. 

    Wir arbeiten daran für möglichst viele Geräte Voreinstellungen zu bieten.
    Die aktuell unterstützen Speicher bzw. Hybrid Wechselrichter sind in der [Liste der kompatiblen Geräte](/docs/compatible_devices/devices) zu finden.
    Sie unterstützen das Feature [Batteriesteuerung (BS)](/docs/compatible_devices/introduction#batteriesteuerung-bs).

    Die Batteriesteuerung übernimmt nicht die vollständige Kontrolle über den Speicher und regelt z.B. nicht seine Leistung.
    Die Batteriesteuerung setzt nur Parameter des Speichers (z.B. den "maximalen Ladestrom") um diesen zu steuern. Die eigentliche Regelung verbleibt beim Speicher bzw. dem angeschlossenen Hybridwechselrichter.

:::


![image](/img/webinterface/energy_management/batterycontrol.jpeg)


## Anlegen eines Batteriespeichers

Nach dem aktivieren der Batteriesteuerung kann ein Speicher angelegt werden. Dazu ist das "+" Symbol zu klicken und als Klasse "Modbus/TCP" gewählt werden. Anschließend ist der Anzeigename, Host, Port sowie die dazugehörige
Registertabelle zu wählen. Danach sind weitere gerätespezifische Parameter einzustellen. Dies kann zum Beispiel die Ladeleistung oder ein Soll-Netzbezug sein. Am Ende muss der Speicher hinzugefügt werden und alle Einstellung mittels
Klick auf "Speichern" und anschließendem Neustart übernommen werden.

Ist keine Registertabelle (Voreinstellung) für ein Gerät vorhanden, so kann auch eine benutzerdefinierte Registertabelle angelegt werden. Hierbei müssen Registersets für jeden Speichermodi definiert werden. Wie dies funktioniert ist
unter [Anlegen eines Batteriespeichers](/docs/compatible_devices/batteries#anlegen-eines-batteriespeichers) beschrieben.


## Einstellungen

### Zeitplan für dy­na­mi­schen Strom­preis

Ist ein [dynamisches Strompreis](/docs/webinterface/energy_management/dynamic_tariffs) konfiguriert, so können hier die "günstigen Stunden" und die "teuren Stunden" konfiguriert werden. Dies ist in 15min Schritten (=0,25h) möglich.
Diese Eigenschaften können dann in den Regeln verwendet werden um damit zum Beispiel das Laden aus dem Netz zu steuern oder das Entladen zu blockieren. Ein Graph zeigt die Stunden dann für den aktuellen Strompreisverlauf an.

### Regeln

Es können jeweils bis zu 32 Lade- und Entladeregeln angelegt werden. Der Aufbau ist für alle identisch:

![image](/img/webinterface/energy_management/batterycontrol-rule-charge.jpeg)
![image](/img/webinterface/energy_management/batterycontrol-rule-discharge.jpeg)


Für jede Regel kann eine **Beschreibung** (Freitext) angelegt werden, sowie Bedingungen die auf die Parameter **Zeit**, dem **Ladestand (SoC)** der Batterie, der aktuelle (dynamische) **Strompreis**, die **PV-Ertragsprognose**,
Bedingungen zum oben definierten **Strompreisplan** oder ob bei einer Wallbox eine **Schnellladung** aktiv ist Bezug nehmen. Für die Parameter können Vergleiche definiert werden, so dass zum Beispiel ein Strompreis **kleiner** 12 Cent als
Bedingung oder ein Ladestand **größer** als 50% definiert werden kann. Es müssen nicht alle Parameter als Bedingung der Regel genutzt werden. Parameter können ignoriert werden.

Sind **ALLE** Bedingungen einer Regel erfüllt (**UND**), so ist die Regel aktiv und es wird die definierte **Aktion** durchgeführt:

Aktionen für Laderegeln sind:

 * **Erzwingen**: Der Speicher lädt. Ist die Ladeleistung nicht durch PV o.ä. gedeckt, so wird auch Strom aus dem Netz bezogen.
 * **Blockieren**: Dem Speicher wird verboten zu laden. Ist ein PV-Überschuss vorhanden, so fliest dieser nicht mehr in den Speicher.

Aktionen für Entladeregeln sind:

 * **Erzwingen**: Der Speicher entlädt. Wird die Entladeleistung nicht vollständig von Verbrauchern genutzt, so wird auch Strom in das Netz eingespeist.
 * **Blockieren**: Dem Speicher wird verboten zu entladen. Lasten werden vom Speicher nicht mehr ausgeglichen.


Die Batteriesteuerung wertet alle Regeln anhand ihrer Reihenfolge aus und führt die erste Regel aus, deren Bedingungen alle erfüllt sind (**ODER**). Dies gilt sowohl für die Laderegeln als auch für die Entladeregeln.
Dadurch ergibt sich, dass sich der Speicher in einem von sechs verschiedenen Modi befinden kann. Siehe dazu [technische Beschreibung zu Batteriespeichern](/docs/compatible_devices/batteries#benutzerdefinierte-batteriespeicher---speichermodi).
Der Speichermodus wird oben auf der Webseite dargestellt.

Eine aktive Regel wird mit einem blauen Strich auf der linken Seite gekennzeichnet. Damit ist erkennbar welche Regel dafür verantwortlich ist, dass der Speicher seinen Modus *normal* für das Laden oder Entladen verlässt.

## Beispiele zu Speicherregeln

Die Konfiguration der Regeln ist immer kunden- und anwendungsspezifisch. Nachfolgend geben wir einige Beispiele. Die jeweiligen Parameterwerte sind aber immer Abhängig von der jeweiligen Größe der PV-Anlage, des Speichers und den Verbräuchen.

### Bei günstigen Strompreisen aus dem Netz laden

Bei der Nutzung dynamischer Strompreise kann es Sinn machen, den Speicher zu günstigen Zeiten zu laden um in Zeiten teurer Strompreise keinen Netzbezug zu haben. Um diese Funktion zu nutzen
muss als erstes der **Zeitplan für dy­na­mi­schen Strom­preis** konfiguriert werden. Als Beispiel kann als **Günstige Stunden** die Anzahl der Stunden gewählt werden, die benötigt wird um den Speicher voll zu laden.
Für die **Teuren Stunden** kann die Anzahl der Stunden gewählt werden, die der Speicher normalerweise ausreicht um den gesamten Bedarf zu decken.

Folgende Bedingungen könnten als Laderegeln für die Aktion **Laden erzwingen** definiert werden:

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Ladestand</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1.</td><td>-</td><td>< 100 %</td><td>< 5,0ct</td><td>< 20kWh</td><td>Günstig</td><td>-</td></tr>
<tr><td>2.</td><td>-</td><td>< 60 %</td><td>< 8,0ct</td><td>< 10kWh</td><td>Günstig</td><td>-</td></tr>
<tr><td>3.</td><td>-</td><td>< 30%</td><td>-</td><td>-</td><td>Günstig</td><td>-</td></tr>
</table>

Die erste Regel dient dazu den Speicher mit "günstigen" Strom voll zu laden, wenn der erwartete PV-Ertrag an dem aktuellen Tag nicht ausreicht. Dazu werden die im Strompreisplan definierten "günstigen" Stunden genutzt. Aber nur, wenn deren Kosten unter 5 Cent liegen.
Die zweite Regel ist dazu gedacht, dass wenn die erste Regel nicht greift, bei einem Ladestand unter 60% dennoch zu den günstigen Stunden bis 60% zu laden, aber nur wenn der Strompreis immer noch unter 8 Cent liegt. Die dritte Regel ist dazu gedacht,
dass wenn die ersten beiden Regeln nicht greifen, bei einem Ladestand unter 30% dennoch zu den günstigen Stunden bis 30% zu laden. Hierbei wird der eigentliche Strompreis und der erwartete PV-Ertrag dann ignoriert. Die Regel ist nur aktiv, wenn wir uns in den günstigen Stunden befinden.

### Bei großem PV-Überschuss verbieten zu laden

Diese Funktion klingt im ersten Moment unsinnig. Wir möchten verbieten, dass der Speicher sich lädt, wenn ein PV-Überschuss vorhanden ist. In diesem Fall würde der Speicher dann den Überschuss nicht selbst nutzen,
sondern den Überschuss in das Netz einspeisen. Es kann aber sinnvoll sein den Überschuss nicht zum Laden des Speichers zu nutzen. Und zwar dann wenn man einen hohen PV-Überschuss erwartet.

Ganz im Sinne der HTW Berlin Aktion: [Dein Stromspreicher kann mehr](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/) soll mit dieser Regel verhindert werden,
dass an sonnereichen Tagen morgens der Speicher erst geladen wird um dann gegen Mittag voll zu sein und ins Netz einzuspeisen. Die Regel mit der Aktion **Laden blockieren** dazu könnte wie folgt aussehen:

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Ladestand</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1.</td><td>00:00-12:00</td><td>> 70%</td><td>> 0ct</td><td>> 32kWh</td><td>-</td><td>-</td></tr>
</table>

Die Regel verbietet das Laden des Speichers am Vormittag, wenn der Speicher schon einen Ladestand von > 70% besitzt und ein großer PV-Ertrag zu erwarten ist. Damit wird dann morgens noch eingespeist zu Zeiten
an denen das Stromnetz den Strom noch benötigt und man noch eine Einspeisevergütung erhält. Wir behalten uns aber noch ~30% Akkukapazität frei um zu den Zeiten in denen das Stromnetz den Strom nicht mehr benötigt (Strompreis kleiner als 0 Cent)
und wir auch keine Einspeisevergütung erhalten den Speicher noch laden zu können.


### Bei nicht teuren Strompreisen verbieten zu entladen

Es gibt gute Gründe um einen Speicher zu verbieten zu entladen. Als Beispiel macht es keinen Sinn den Speicher zu günstigen Strompreisen aus dem Netz zu laden und direkt danach bei "nicht teuren" Strompreisen direkt wieder zu entladen (Umwandlungsverluste etc.).
Zusätzlich möchte man ggf. nicht, dass der Speicher entladen wird, wenn ein Fahrzeug geladen wird. Beispielhaft könnte eine Regel mit der Aktion **Entladen blockieren** wir folgt aussehen:

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Ladestand</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1.</td><td>-</td><td>-</td><td>-</td><td>-</td><td>Nicht teuer</td><td>-</td></tr>
</table>

Die Regel dient dazu den Speicher nur zu entladen, wenn der Strompreis teuer ist (umgesetzt als Entladeverbot bei **nicht teuer**). Damit würde der Speicher genutzt um einen Strombezug aus dem Netz während der teuren Stunden laut definierten Stromplan zu verhindern.

Mit den weiteren Parametern lässt sich die Regel noch weiter optimieren:

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Ladestand</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1b.</td><td>-</td><td>< 80%</td><td>-</td><td>-</td><td>Nicht teuer</td><td>-</td></tr>
</table>

In diesem Fall (**1b**) würde der Speicher bis 80% Ladestand immer entladen, darunter aber nur in den teuren Stunden. Weitere Optimierungen wären zum Beispiel möglich, indem die PV-Prognose ebenfalls als Parameter genutzt wird.


Soll die Kapazität des Batteriespeichers nicht genutzt werden um ein Fahrzeug zu laden, so kann folgende Regel mit der Aktion **Entladen blockieren** genutzt werden um dies zu verhindern:

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Ladestand</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>2.</td><td>-</td><td>-</td><td>-</td><td>-</td><td>-</td><td>Aktiv</td></tr>
</table>

Zusammen mit dem [Eco-Modus](/docs/webinterface/energy_management/eco_mode) der Wallboxen kann somit das Fahrzeug günstig aus dem Netz geladen werden, ohne das eine Ladung aus dem Haus-Batteriespeicher erfolgt.
Ist zeitgleich eine Laderegel für den Batteriespeicher aktiv würden das Fahrzeug und der Batteriespeicher zeitgleich geladen.

Auch diese Regel kann erweitert werden zum Beispiel mit einer Bedingung zum Ladestand, so dass nur ein Teil der Batteriekapazität zum Laden des Fahrzeugs verwendet wird.


### Bei hohen Vergütungen den Speicher aktiv entladen

Möchte man aktiv den Speicher entladen um zum Beispiel in Zeiten hoher Vergütungen in das Stromnetz einzuspeisen, so ist dies mit einer Regel und der Aktion **Entladen erzwingen** wie folgt möglich:

<table>
<tr><td><b>Beschreibung</b></td><td><b>Zeit</b></td><td><b>Ladestand</b></td><td><b>Strompreis</b></td><td><b>PV-Ertrag</b></td><td><b>Strompreisplan</b></td><td><b>Schnellladung</b></td></tr>
<tr><td>1.</td><td>-</td><td>-</td><td>> 15ct</td><td>-</td><td>teuer</td><td>-</td></tr>
</table>

Der Speicher würde zu den "teuren Stunden" (Zeitplan für dy­na­mi­schen Strom­preis) entladen sobald der Strompreis größer als 15 Cent beträgt.

## Beispielkonfiguration

Nachfolgend ein komplexes Beispiel wie eine Regelkonfiguration aussehen kann.

![image](/img/webinterface/energy_management/batterycontrol-rules-example.jpeg)

Die Laderegel **Supergünstig Nachts** mit der Aktion **Ladung erzwingen** wird aktiv wenn wenig Sonne erwartet wird (kleiner als 16kWh), so zum Beispiel im Winter. Ist der Strompreis Nachts (00:00 - 06:00 Uhr) kleiner als 2 Cent und befinden wir uns in den günstigen Stunden,
dann wird der Speicher bis auf 100\% geladen (keine Beschränkung des Ladestands). Mit dieser Regel wird der Speicher im Winter bei sehr günstigen Strompreisen nachts vollgeladen.

Die Laderegeln **Keine Sonne + günstig** sowie **Keine Sonne + günstig 2** mit der Aktion **Ladung erzwingen** dienen dazu den Speicher bei günstigen Strompreisen aus dem Netz bis zu einem gewissen State-of-Charge zu laden. Abhängig vom Strompreis wird der Speicher entweder
bis 80\% oder bis 60\% geladen. Dies aber nur wenn ein moderater PV-Ertrag erwartet wird. Analog dazu wurden auch zwei Entladeregeln mit der Aktion **Entladen blockieren** angelegt. Diese sind identisch angelegt, das State-of-Charge wurde aber um 1\% erhöht.
Der Grund für die Entladeregeln ist, dass bei einem Ladestand kleiner 100\% der Speicher als Beispiel bis 80\% Ladestand geladen wird. Dann werden die Bedingung der Regel mit kleiner als 80\% Ladestand nicht mehr erfüllt. Der Speicher geht wieder in den "Normalmodus" und entlädt sich.
Bei 79\% Ladestand wird die Laderegel wieder aktiviert und lädt den Speicher wieder bis auf 80\% Ladestand. Das System schwingt also (Laden/Entladen). Um dieses Schwingen zu unterbinden wurden jeweils zu jeder Laderegel eine Entladeregel mit 1\% höherem Ladestand angelegt.
Somit ist gleichzeitig zum Laden in dem Zustand immer das Entladen verboten und der Ladestand bleibt unverändert.

Die Regel **Reserve halten** ist analog aufgebaut (Lade- und Entladeregel) und dient dazu einen Ladestand von 30\% als Reserve zu halten, der für die teuren Stunden genutzt wird um in diesen keinen Strom beziehen zu müssen. Die Regeln sorgen dafür, dass auf 30\% Ladestand
aufgeladen in den nicht teuren Stunden aufgeladen wird und dieser Ladestand auch gehalten wird (1\% höhere Entladen-blockieren-Regel). Befinden wir uns in einem Zeitraum, der laut Strompreisplan **teuer** ist, so greifen die Regeln nicht und der Speicher fällt zurück
in den Normalbetrieb. Damit entlädt er sich und es wird kein Strom aus dem Netz bezogen.

Die Laderegel **HTW Berlin** soll die Aktion [Dein Stromspreicher kann mehr](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/) unterstützen. Die Regel sorgt dafür, dass an Vormittagen mit sehr großer erwarteter PV-Erzeugung der Speicher nur bis 70\%
geladen wird und anschließend das Laden blockiert wird. Dies ist in der Sommerzeit früh morgens der Fall. Anschließend wird der Speicher nicht mehr weiter geladen und der Überschuss geht in das Stromnetz. Sobald der Strompreis negativ wird greift die Regel nicht mehr.
Das Laden des Batteriespeichers wird also nicht mehr blockiert. Er lädt nun wieder und es wird nicht mehr in das Stromnetz eingespeist.

Die Entladeregel **Minimum SoC** dieht dazu immer einen Ladestand von 4% zu halten, da unter 5% eine Entladung blockiert wird.

Um ein Fahrzeug nicht aus dem Batteriespeicher zu laden ist mit der Regel **Schnelladen** eine Regel definiert worden, die das Entladen des Speichers blockiert, wenn eine Schnelladung erfolgt.

## Technische Umsetzung der Batteriesteuerung

Die Batteriesteuerung übernimmt nicht die vollständige Kontrolle vom Speicher und regelt zum Beispiel nicht die Leistung vom Batteriespeicher!
Der Speicher übt immer seine vom Hersteller definierte Funktion aus. Das heißt im Normalfall wird ein PV-Überschuss zur Ladung des Speichers genutzt und der Speicher versucht die Leistungsaufnahme eines Verbrauchers
zu kompensieren.

Die Speichersteuerung verändert nur die Parameter des Speichers und verändert so ein Verhalten.
Als Beispiel kann die Batteriesteuerung das Laden des Speichers blockieren.
Die technische Umsetzung ist je nach Gerät verschieden. Als Beispiel kann dazu der Parameter des "maximalen Ladestroms" auf 0A gesetzt werden, wodurch das Laden gesperrt ist.
Soll der Speicher wieder in den Normalbetrieb wechseln, müssen die Parameter wieder auf ihre Voreinstellungen zurückgesetzt werden. Als Beispiel könnte der "maximale Ladestrom" dann wieder auf 25A (Voreinstellung) zurückgesetzt werden.

Eine detailierte technische Beschreibung zur Batteriesteuerung ist hier zu finden: [Technische Beschreibung zu Batteriesteuerung](compatible_devices/batteries.md)
