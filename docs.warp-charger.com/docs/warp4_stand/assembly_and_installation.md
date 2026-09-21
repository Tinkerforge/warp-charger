---
sidebar_position: 2
---

# Montage und Installation

:::warning
Die Montage, elektrische Installation und erste Inbetriebnahme dürfen nur von
einer qualifizierten Elektrofachkraft durchgeführt werden. Die Betriebsanleitungen
der Ladesäule und der verbauten WARP4 Charger sind zu beachten.
:::

## Öffnen der Ladesäule

Die geteilte Rückseite ist mit Verschlussriegeln ausgestattet, die mit dem
mitgelieferten Schaltschrankschlüssel geöffnet werden. Zum Entfernen des oberen
Rückenteils muss zuerst das untere Rückenteil entfernt werden.

![Geteilte Rückseite der WARP4 Ladesäule mit vier Verschlussriegeln](/img/warp4_stand/stand-back.jpg)

## Montage

### Lieferumfang

Die Mengen gelten für die Variante mit einer bzw. zwei Wallboxen:

- Ladesäule mit Fuß und zwei Rückenteilen mit jeweils zwei Verschlussriegeln
- Vormontierte Montagehilfe mit zwei Streben, vier M8-Gewindestangen,
  vier Unterlegscheiben und 16 M8-Muttern
- Schaltschrankschlüssel
- Ein bzw. zwei Kabelhalter mit jeweils vier M6×16-Innensechskantschrauben
- Vier bzw. acht M6×35-Innensechskantschrauben zur Befestigung der Wallboxen
- Zwei bzw. drei Erdungsschraubensets, jeweils mit einer M6×16-Innensechskantschraube,
  zwei M6-Unterlegscheiben und einer M6-Fächerscheibe
- Betriebsanleitung

**Nur bei Bestellung mit Verteilergehäuse und Kabelanschlussset** sind zusätzlich enthalten:

- Verteilergehäuse mit Hutschiene, einem bzw. zwei Klemmenblöcken und
  RJ45-Hutschienen-Patchkabelverbinder
- Vier M6×10-Innensechskantschrauben zur Befestigung des Verteilergehäuses
- Ein bzw. zwei RJ45-Patchkabel, jeweils 1,5 m lang
- Eine bzw. zwei Wallboxanschlussleitungen
- Eine Erdungsanschlussleitung für die Verteilerbox
- Eine bzw. zwei Erdungsanschlussleitungen zu den Befestigungspunkten hinter den Wallboxen

WARP4 Charger werden separat bestellt.

### Montageort

- Beachte die Anforderungen an den [Montageort des WARP4 Chargers](/warp4/assembly_and_installation.md#montageort).
- An Straßen und öffentlichen Parkplätzen ist ein entsprechender Anfahr-/Rammschutz erforderlich.
- Zwischen nebeneinander aufgestellten Säulen müssen mindestens 200 mm Abstand bleiben.
- Die Aufstellfläche muss vollständig plan sein.

:::warning
Die Säule darf nicht auf Asphalt installiert werden, da dort die Standsicherheit
nicht gewährleistet ist.
:::

### Herstellung des Fundaments

Für einen sicheren Stand wird ein Betonfundament empfohlen. Seine Auslegung,
Konstruktion und Ausführung liegen in der Verantwortung des Fundamentherstellers
und müssen an die örtlichen Gegebenheiten angepasst werden. Die in der Zeichnung
angegebenen **470 × 250 × 800 mm (Breite × Tiefe × Höhe)** sind Mindestmaße.

Die Montagehilfe wird vormontiert geliefert. Ihre Oberkante muss bündig mit der
Betonoberfläche positioniert werden; die Gewindestangen müssen wie in der
Zeichnung angegeben 20 bis 25 mm überstehen. Die Oberfläche eben und glatt
ausführen. Wasser muss abfließen können und darf sich nicht am Fundament sammeln.

Die Stromversorgungs-, Erdungs- und gegebenenfalls Netzwerkkabel müssen mittig
durch die 110 × 55 mm große ovale Aussparung geführt werden und mindestens
**1500 mm aus dem Fundament herausragen**. Schutzschläuche bzw. Leerrohre müssen
mindestens **300 mm überstehen**. Die Kabel während der Fundamentherstellung vor
Beschädigungen schützen. Ein Erdungsanschluss ist zwingend erforderlich.

[![Fundamentzeichnung mit Mindestmaßen, Montagehilfe und Kabelüberständen](/img/warp4_stand/foundation.svg)](/img/warp4_stand/stand_drawings.pdf)

[Fundament- und Maßzeichnungen als PDF](/img/warp4_stand/stand_drawings.pdf)

### Montage der Ladesäule

Nach dem Aushärten des Fundaments:

1. Die Rückenteile der Säule entfernen.
2. Die vier oberen M8-Muttern und Unterlegscheiben der Montagehilfe abnehmen.
3. Die Säule über die aus dem Fundament ragenden Kabel und Gewindestangen setzen.
4. Die Säule mit den zuvor entfernten Unterlegscheiben und Muttern befestigen.

### Montage des Kabelhalters

Jeden Kabelhalter unterhalb der zugehörigen Wallbox mit den vier mitgelieferten
M6×16-Innensechskantschrauben befestigen. Die Schrauben werden von außen durch
den Kabelhalter eingeschraubt.

![Kabelhalter mit vier Befestigungsschrauben](/img/warp4_stand/cable-hook.jpg)

## Elektrische Installation

Jede Wallbox wird separat angeschlossen. Es gelten die
[Anforderungen an die Elektroinstallation des WARP4 Chargers](/warp4/assembly_and_installation.md#anforderungen-an-die-elektroinstallation).

### Erdung

Der Erdungssternpunkt befindet sich an einer M6×16-Schraube in der linken
Fußplatte. An dieser Schraube laufen alle Erdungsleitungen zusammen.

![Erdungssternpunkt in der Fußplatte](/img/warp4_stand/earth_star.jpg)

Mit dem optionalen Verteilergehäuse wird eine 0,83 m lange Erdungsleitung mit
M6-Ringschuh und Aderendhülse geliefert. Sie verbindet den Sternpunkt mit der
Erdungsklemme im Verteilergehäuse und darüber mit dem Schutzleiter der Zuleitung.
Ohne Verteilergehäuse muss der Erdungsanschluss anderweitig hergestellt werden.

Vom Sternpunkt führt eine 1,5 m lange Erdungsleitung mit zwei M6-Ringschuhen zur
M6-Mutter in der Säule hinter der Wallbox. Die Befestigung erfolgt innen mit
M6×16-Schraube, Fächer- und Unterlegscheiben. Bei zwei Wallboxen wird zusätzlich
der entsprechende Punkt am oberen Rückenteil verbunden.

![Erdungsanschluss an der Säule hinter der Wallbox](/img/warp4_stand/earth_wb.jpg)

### Wallbox montieren und anschließen

Für die Montage an der Säule muss die Wallbox auf
[rückseitige Kabeleinführung](/warp4/assembly_and_installation.md#kabeleinführung-von-der-rückseite)
umgebaut werden. Dazu die unteren Kabelverschraubungen mit den rückseitigen
Blindstopfen tauschen.

Beim optionalen Anschlussset sind die Stromleitungen 0,8 m lang und an einem Ende
12 cm, am anderen 18 cm abgemantelt. Zuerst die 18-cm-Seite rückseitig in die
Wallbox einführen, nach deren Anleitung anschließen und die Kabelverschraubung
festziehen.

Zum Einführen des RJ45-Steckers den Dichtstopfen aus der M25-Kabelverschraubung
nehmen. Den Stopfen seitlich bis zur Kabelbohrung schlitzen, um das Kabel legen
und wieder einsetzen. Anschließend die Verschraubung festziehen und das
Patchkabel anschließen.

Die Wallbox mit den vorbereiteten Leitungen an der Säule positionieren und mit
vier M6×35-Innensechskantschrauben befestigen. Bei Verwendung des Verteilergehäuses
die 12-cm-Seite der Stromleitung sowie das Patchkabel durch dessen
Kabelverschraubungen führen und dort anschließen. Ohne das optionale Set müssen
geeignete Anschlussleitungen entsprechend der Wallboxanleitung angefertigt werden.

### Optionales Verteilergehäuse

Das Verteilergehäuse wird innerhalb der Säule unterhalb der Wallbox an den
vorgesehenen Punkten befestigt. Dazu den Deckel abnehmen und die vier
mitgelieferten M6×10-Innensechskantschrauben verwenden.

![Optionales Verteilergehäuse mit Klemmen und RJ45-Verbinder](/img/warp4_stand/box.jpg)

Die Klemmen vom Typ Contaclip ZRK 10/2A oder vergleichbar nehmen ein- und
mehrdrähtige Leiter bis 16 mm² sowie Leiter mit Aderendhülse bis 10 mm² auf.
Die Abisolierlänge beträgt 10 mm. Die Leiter anhand der Klemmenbeschriftung
anschließen. Nach Anschluss und Prüfung den Deckel wieder schließen.

### Ethernet

Die Ethernetleitungen können im optionalen Verteilergehäuse über die
mitgelieferten Patchkabel und den RJ45-Hutschienen-Patchkabelverbinder verbunden
werden. Die [LAN-Anschlussanleitung des WARP4 Chargers](/warp4/assembly_and_installation.md#lan-rj45-kabel-anfertigen)
ist zu beachten.

## Prüfung und Inbetriebnahme

Nach der Installation sind die [Prüfungen für den WARP4 Charger](/warp4/assembly_and_installation.md#prüfungen)
durchzuführen. Anschließend werden die Wallboxen gemäß
[Konfiguration und Einrichtung](/warp4/configuration_and_setup.md) in Betrieb
genommen. Die Säule selbst hat keine Software oder Konfiguration.
