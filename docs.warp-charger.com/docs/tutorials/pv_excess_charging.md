---
sidebar_position: 3
---

# PV-Überschussladen

Beim Photovoltaik-Überschussladen ist das Ziel, die nicht selbst
genutzte Leistung einer Photovoltaikanlage in ein Elektrofahrzeug zu
laden, anstatt sie in das Stromnetz einzuspeisen. Die Maximierung der
Eigenstromnutzung steht hier im Vordergrund.

## Funktionsweise

Steht ein entsprechender Stromzähler zur Verfügung, kann die Wallbox den
Ladevorgang so steuern, dass auf einen Soll-Netzbezug geregelt wird.

Typischerweise handelt es sich um einen Stromzähler am Netzanschluss
(auch Hausanschluss genannt),
der auf einen Bezug von 0 W geregelt werden soll. Das heißt, die gesamte
PV-Leistung soll in das Fahrzeug geladen werden, ohne dass ein Netzbezug
stattfindet ("PV-Überschuss").

WARP3 Charger Smart und Pro sind mit zwei getrennten Schützen
ausgestattet und können somit intern zwischen einem einphasigen und
dreiphasigen Ladevorgang umschalten. Das Umschalten auf eine einphasige
Ladung bietet den Vorteil, dass auch geringe Leistungsüberschüsse in ein
Fahrzeug geladen werden können (ab ca. 1,4 kW), wohingegen ein
dreiphasiger Ladevorgang die jeweilige Maximalleistung der Wallbox
ermöglicht (11 kW oder 22 kW).

Wenn das PV-Überschussladen eingerichtet ist stehen vier **Lademodi** zur Verfügung:

**Aus:** Alle Ladevorgänge werden gestoppt

**PV:** Fahrzeuge werden nur aus dem PV-Überschuss geladen.
Wenn nicht genügend Überschuss zur Verfügung steht, wird der
Ladevorgang gestoppt.

**Min+PV:** Fahrzeuge werden aus dem PV-Überschuss geladen. Falls nicht genügend
Überschuss zur Verfügung steht, wird Strom aus dem Netz bezogen,
damit Ladevorgänge nicht gestoppt werden. Der erlaubte Netzbezug
kann konfiguriert werden.

**Schnell:** Fahrzeuge werden so schnell wie möglich geladen, unabhängig davon,
wie viel PV-Überschuss zur Verfügung steht.

## Schritt 1: Konfiguration Stromzähler {#add_meter}

Um das PV-Überschussladen einzurichten muss zuerst ein Stromzähler hinzugefügt
werden der den PV-Überschuss messen kann.

Der Stromzähler wird über die Seite `Energiemanagement` -> `Stromzähler` hinzugefügt.
Dort kann unter "Einstellungen" über das "+" ein Zähler ausgewählt werden. Bei
einem WARP Charger Pro ist hier bereits der Zähler in der Wallbox vorhanden und
es muss ein weiterer hinzugefügt werden. Bei einer WARP Charter Smart reicht
für das PV-Überschussladen der Zähler am Netzanschluss, der den PV-Überschuss messen
kann. Dazu muss der Zähler den Wert "Wirkleistung (Bezug minus Einspeisung) Summe
über L1, L2, L3" liefern.

![image](/img/first_steps/pv_add_meter.png)

Es können unterschiedliche Zählerarten hinzugefügt werden. Es werden
Geräte (für gewöhnlich Wechselrichter) unterstützt die SunSpec
unterstützen. Des weiteren gibt es unterstützung für merhere proprietäre
Hersteller-Protokolle, unter anderem SMA und SunGrow. Eine andere Möglichkeit
ist es den Zähler über eine Hausautomatisierung o.ä. virtuell über die API
anzulegen.

Siehe [Liste der unterstützen und von uns getesteten Zähler](/compatible_meters.md).

Im folgenden Beispiel für wir einen KOSTAL Smart Energy Meter als
Zähler hinzugefügt. Dafür muss nur einmal die IP-Adresse des Zählers
eingetragen werden und auf "Suche Starten" geklickt werden.

![image](/img/first_steps/pv_add_meter_sunspec.png)

Danach muss noch einmal auf übernehmen geklickt werden und dann auf
"Speichern" damit die neuen Einstellungen übernommen werden.

Der Zähler taucht dann in der Liste der Zähler auf und wird auch im
Ladeverlauf angezeigt.

![image](/img/first_steps/pv_add_meter_sunspec_kostal.png)

## Schritt 2: Konfiguration Überschussladen

Nachdem der Zähler hinzugefügt wurde kann das PV-Überschussladen unter
`Energiemanagement` -> `PV-Überschussladen` konfiguriert werden.

![image](/img/first_steps/pv_configuration.png)

Folgende Einstellungen können vorgenommen werden:

**Überschussladen aktiviert**: Schaltet den PV-Überschussregler ein oder aus.

**Umschaltungsmodus**: Definiert das Verhalten der Phasenumschaltung.

**Standardlademodus**: Der Lademodus, der bei einem Neustart des WARP3 Chargers verwendet
wird.

**Stromzähler**: Der Stromzähler, mit dem der PV-Überschuss gemessen wird. Dieser
Stromzähler muss vorher entsprechend Abschnitt angelegt werden.

**Min+PV: Mindestladeleistung**: Legt fest, welche Leistung im "Min+PV"-Lademodus aus dem Netz
bezogen werden darf.

**Regelverhalten**: Legt fest, auf welchen Netzbezug geregelt werden soll, damit
beispielsweise ein Batteriespeicher höher oder niedriger priorisiert
wird als das Laden von Fahrzeugen.

**Wolkenfilter**: Stellt die Trägheit der Regelung ein. Bei wechselnd bewölktem Wetter
ist es sinnvoll, dass die Regelung träge reagiert, damit kurze
Schwankungen der PV-Leistung geglättet werden.
