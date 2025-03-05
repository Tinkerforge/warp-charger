---
sidebar_position: 4
---

# Lastmanagement

Mit dem Lastmanagement ist es möglich, einen verfügbaren
Gesamt-Ladestrom zwischen bis zu 64 WARP Chargern aufzuteilen. Hierbei
wird ein WARP Charger oder ein WARP Energy Manager als Lastmanager konfiguriert, der die weiteren bis zu
63 Wallboxen im Verbund steuert und ihnen Ladeströme zuweist.

Ohne Stromzähler am Hausanschluss kann ein fester Gesamtstrom verteilt werden,
um zum Beispiel den Hausanschluss nicht zu überlasten. Dieser Gesamtstrom kann über das
Webinterface und die API gesetzt werden.

Wenn ein Zähler am Hausanschluss vorhanden ist und vom Lastmanager ausgelesen werden kann
(siehe [kompatible Geräte](/compatible_devices/introduction.md)), kann das dynamische Lastmanagement verwendet werden,
das sicherstellt, dass der Hausanschluss nie durch die WARP Charger überlastet wird, auch wenn andere Verbraucher
zu- oder abgeschaltet werden. Außerdem kann dann das PV-Überschussladen verwendet werden.

## Funktionsweise

Durch das Lastmanagement kontrollierte Wallboxen laden nur, wenn ihnen
vom Lastmanager ein Ladestrom freigegeben wird. Wenn eine gewisse
Zeit lang kein Ladestrom freigegeben wurde, oder der Lastmanager nicht erreicht werden kann,
stoppt die Wallbox den Ladevorgang automatisch.
Der Lastmanager stoppt seinerseits das
Laden an allen kontrollierten Wallboxen, wenn eine Wallbox nicht mehr
reagiert oder erreicht wird. Damit wird sichergestellt, dass der
verfügbare Strom nicht überschritten wird.

Der Lastmanager verteilt den verfügbaren Strom möglichst fair zwischen
Wallboxen, die laden bzw. ladebereit sind, stellt sicher,
dass die Zuleitung zu den Wallboxen und der Hausanschluss nicht überlastet werden,
nutzt gegebenenfalls einen vorhandenen PV-Überschuss aus (siehe [PV-Überschussladen](/tutorials/pv_excess_charging.md))
und versucht Schaltvorgänge zu minimieren.

## Schritt 1: Konfiguration fremdgesteuerte Wallboxen

Um das Lastmanagement zu verwenden, muss zunächst auf allen Wallboxen,
die gesteuert werden sollen, der Fremdsteuerungsmodus unter
`Energiemanagement` -> `Wallboxen` auf "fremdgesteuert"
konfiguriert werden. In diesem Modus lädt eine Wallbox nur noch, wenn
der Ladevorgang vom Lastmanager freigegeben wird.

![image](/img/tutorials/chargemanagement/load_management_external_control.jpg)

Mehr ist für die fremdgesteuerten Wallboxen nicht einzustellen.

Weitere Informationen hierzu gibt es in der Webinterface-Dokumentation: [Wallboxen](/webinterface/energy_management/wallboxes.md)

## Schritt 2: Konfiguration Lastmanager

:::info

Es ist auch möglich den WARP Energy Manager als Lastmanager zu konfigurieren.
Die Konfigurationsseite ist dort unter `Energiemanagement` -> `Lastmanagement`
zu finden und genauso durchführbar wie hier beschrieben.

:::

Auf der Wallbox, die die anderen Wallboxen steuern soll (dem
Lastmanager), muss zunächst der Fremdsteuerungsmodus "Lastmanager"
gewählt werden. Zusätzlich muss hier jede Wallbox, die gesteuert werden
soll, als "Kontrollierte Wallbox" hinzugefügt werden. Bei Klick auf
"Wallbox hinzufügen" erscheinen nach wenigen Sekunden alle Wallboxen,
die vom Lastmanager erreicht werden können. Durch Klicken auf eine
gefundene Wallbox wird diese hinzugefügt. Wallboxen, die nicht
hinzugefügt werden können, werden grau hinterlegt.

Hier kann auch die Phasenrotation einer Wallbox konfiguriert werden,
so diese bekannt ist. Der Lastmanager kann bessere Entscheidungen treffen,
wenn die Phasenrotation (eines Teils) der gesteuerten Wallboxen bekannst ist.
[Siehe hier für Details](#phase_rotation)

![image](/img/tutorials/chargemanagement/load_management_add_wallbox.png)

Nach Zuordnung der Wallboxen muss der "Maximale Gesamtstrom" konfiguriert
werden. Dieser ist typischerweise die Belastbarkeit der gemeinsamen
Zuleitung der Wallboxen.

![image](/img/tutorials/chargemanagement/load_management_wallbox_added.png)

Weitere Informationen hierzu gibt es in der Webinterface-Dokumentation: [Lastmanagement](/webinterface/energy_management/loadmanagement.md)

## Schritt 3: Konfiguration dynamisches Lastmanagement

Damit das dynamische Lastmanagement verwendet werden kann, muss zunächst ein
Stromzähler hinzugefügt werden, der die Phasenströme am Hausanschluss messen kann.
Dieser kann, so gewünscht, auch für ein PV-Überschussladen verwendet werden,
das dynamische Lastmanagement kann aber auch ohne PV-Anlage verwendet werden.
Der Abschnitt [Konfiguration Stromzähler](/tutorials/pv_excess_charging.md#add_meter) beschreibt,
wie ein Zähler hinzugefügt wird.

Nachdem ein Zähler hinzugefügt wurde, kann auf der `Energiemanagement`
-> `Lastmanagement`-Unterseite das dynamische Lastmanagement aktiviert und konfiguriert werden.

![image](/img/tutorials/chargemanagement/load_management_dynamic.png)

Zunächst muss der eben konfigurierte Stromzähler ausgewählt werden.

Danach muss der **Maximale Strom am Netzanschluss** konfiguriert werden.
Dieser ist typischerweise der Nennwert der Absicherung.
Das dynamische Lastmanagment stellt sicher, dass dieser Wert nicht überschritten wird.

Als letztes muss der zu erwartende **Stromverbrauch des größten Verbrauchers** konfiguriert werden.
Dieser kann beispielsweise ein Durchlauferhitzer oder eine Wärmepumpe sein, mindestens aber
16 Ampere aus einer Schuko-Dose. Der Wert gibt den größten zu er­war­ten­den plötz­li­chen Sprung des Strom­bezugs am Zähler an, den das dy­na­mi­sche Last­manage­ment kurz­fris­tig (in unter 30 Sekunden) kom­pen­sieren können muss.

:::info

Die vom Last­manage­ment ge­steu­er­ten Wallboxen müssen nicht be­rück­sich­tigt werden!

:::

## Erweiterte Lastmanagement-Konfigurationen

Weitere Einstellungen finden sich auf der Unterseite `Energiemanagement`
-> `Lastmanagement`.

Je nach Einsatzzweck (z.B. PV-Überschussladen auf mehreren Wallboxen)
können die folgenden Einstellungen hilfreich sein. Diese werden für eine
einfache Lastverteilung, z.B. 16 A auf zwei Wallboxen, *nicht* benötigt.
Die Optionen finden sich unter den "Experteneinstellungen".

![image](/img/tutorials/chargemanagement/load_management_expert.png)

### Stromverteilungsprotokoll aktiviert

Wenn das Stromverteilungsprotokoll aktiv ist, fügt der Lastmanager dem
Ereignis-Log detaillierte Ausgaben hinzu, wann immer Strom umverteilt
wird. Damit kann unerwartetes Verhalten des Lastmanagements untersucht
werden.

### Watchdog aktiviert

Der Watchdog erlaubt es der steuernden Wallbox, auf Ausfälle einer
externen Steuerung zu reagieren. Falls über die API der Wallbox nicht
mindestens alle 30 Sekunden der verfügbare Strom gesetzt wird und der
Watchdog aktiv ist, wird der verfügbare Strom wieder zurück auf den
**Voreingestellt verfügbarer Strom** gesetzt. Falls die externe
Steuerung später wieder läuft, wird der Watchdog zurückgesetzt.

Der Watchdog sollte nur dann aktiviert werden, wenn eine selbst
programmierte Steuerung den für den Wallbox-Verbund verfügbaren Strom
über die API dynamisch ändern soll. Für den normalen
Lastmanagement-Betrieb ist der Watchdog nicht notwendig.

### Maximaler Gesamtstrom

Der maximal verfügbare Strom ist das Maximum, das über das Webinterface
bzw. die API als verfügbarer Strom gesetzt werden darf. Größere Ströme
werden nicht akzeptiert. Falls eine externe Steuerung verwendet wird,
empfehlen wir, den maximal verfügbaren Strom anhand der Kapazität der
Zuleitungen und des Hausanschlusses so zu beschränken, dass durch die
externe Steuerung nie zu große Ströme gesetzt werden können.

### Voreingestellt verfügbarer Strom

Der voreingestellt verfügbare Strom ist der, der vom Lastmanagement
verteilt werden darf, nachdem die steuernde Wallbox neugestartet wurde.
Der verfügbare Strom kann über die API neu gesetzt werden, nach einem
Neustart der Wallbox wird aber zunächst der voreingestellte Strom
verwendet. Falls beispielsweise durch eine externe Steuerung der
verfügbare PV-Überschussstrom gesetzt werden soll, kann der
voreingestellte Strom auf 0 konfiguriert werden, damit zwingend erst
geladen wird, wenn die externe Steuerung mindestens einmal den
verfügbaren Strom gesetzt hat.

:::info

Der voreingestellt verfügbare Strom kann nicht konfiguriert werden,
falls PV-Überschussladen oder dynamisches Lastmanagement verwendet werden.

:::

### Länge der Startphase und Spielraum des Phasenstroms

WARP Charger Pro können den realen Strombezug des Fahrzeugs pro Phase
messen. Mit dieser Information kann das Lastmanagement effizienter Strom
verteilen: Falls beispielsweise der Strombezug eines Fahrzeug sinkt,
weil der Akku bald voll ist, oder ein Fahrzeug, das nur mit 16 laden
kann, an einer 64 Wallbox angeschlossen ist, kann der übrige Strom auf
andere Wallboxen im Lastmanagementverbund verteilt werden.

Damit ein Fahrzeug mehr Strom anfordern kann, darf das Lastmanagement
eine Wallbox nicht exakt auf den realen Strombezug (den maximalen
Phasenstrom) limitieren, sondern muss einen gewissen Spielraum zulassen,
damit Fahrzeug und Lastmanager nachregeln können.

Für WARP Charger Smart sind diese Einstellungen nicht relevant, der
Lastmanager nimmt bei Wallboxen ohne Stromzähler immer an, dass der
zugeteilte Strom komplett vom Fahrzeug verwendet wird.

Die **Länge der Startphase** gibt an, wie lange der reale Strombezug
eines Fahrzeugs ignoriert wird, einer Wallbox also der maximal
verfügbare Strom zugewiesen wird. Die Länge der Startphase sollte also
länger sein als die Startverzögerung eines angeschlossenen Fahrzeugs,
damit dieses beim Ladebeginn sofort den präferierten Strom beziehen
kann.

Der **Spielraum des Phasenstroms** gibt an, wie viel mehr Strom als der
reale Strombezug des Fahrzeugs einer Wallbox zugeteilt werden soll,
sobald die Startphase beendet ist. Dieser Spielraum ist notwendig, damit
das Fahrzeug mehr Strom anfordern kann.

Viele Fahrzeuge laden nicht exakt mit dem vorgegebenen Ladestrom,
sondern unterstützen nur Abstufungen von beispielsweise 0,5. Ein solches
Fahrzeug würde also bei einer Stromvorgabe von 6,23 nur mit 6 laden und
müsste mehr als 6,5 zugeteilt bekommen, damit es von der Stufe 6 auf die
Stufe 6,5 springt. Damit dieses Fahrzeug mehr Strom anfordern kann,
müsste der Spielraum also mehr als 0,5 betragen.

### Minimaler Ladestrom

Der minimale Ladestrom ist der Strom, der für eine Wallbox zur Verfügung
stehen muss, damit diese lädt. Dieser Strom muss mindestens 6 betragen.
Bestimmte Fahrzeuge laden aber erst bei höheren Strömen effizient. Mit
einem WARP3 Charger Pro kann der Leistungsfaktor ermittelt werden.

Wir empfehlen die automatische Einstellung des minimalen Ladestroms, die
sich nach der Wahl des Fahrzeugmodells richtet.

Mit dem minimalen Ladestrom kann zusätzlich gesteuert werden, wie viele
Fahrzeuge gleichzeitig laden können. Maximal sind
"Verfügbarer Strom" geteilt durch "Minimaler Ladestrom"
Ladevorgänge gleichzeitig möglich. Falls beispielsweise nicht möglichst
viele Fahrzeuge zwar langsam, dafür aber gleichzeitig geladen werden
sollen, sondern mehrere Fahrzeuge möglichst schnell nacheinander geladen
werden sollen, kann der minimale Ladestrom auf 32 gesetzt werden.

### Phasenrotation {#phase_rotation}

Jeder kontrollierten Wallbox kann eine Phasenrotation zugewiesen werden.
Diese gibt an, wie die Wallbox in Relation zum Netz­an­schluss- bzw. PV-Über­schuss-Zähler oder zu den anderen Wallboxen an­ge­schlos­sen ist. Ty­pi­scher­wei­se werden nur rechts­dre­hen­de Pha­sen­ro­ta­ti­o­nen verwendet.

Eine Wallbox, die, wenn sie einphasig lädt, die Netz­an­schluss­pha­se L2 belastet, ist dann bei­spiels­weise mit der Pha­sen­ro­ta­ti­on L231 an­ge­schlos­sen.

Wenn die Pha­sen­ro­ta­ti­on aller oder auch nur eines Teils der ge­steu­er­ten Wallboxen bekannt ist, können mehr Fahrzeuge parallel geladen werden und PV- und Netz­an­schluss­li­mits besser aus­ge­reizt werden: Eine Wallbox mit un­be­kann­ter Pha­sen­ro­ta­ti­on wird, wenn sie einphasig lädt, vom Last­manage­ment so behandelt als ob sie alle drei Phasen belasten würde.

### Lastmanagement-Details

[Hier finden sich Details zur Funktionsweise des Lastmanagements.](/tutorials/charge_management_details.md)
