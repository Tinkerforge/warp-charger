---
sidebar_position: 10
---

# Eco-Modus

:::note

Der Eco-Modus ist in folgende Produkte integriert:

* WARP2 Charger
* WARP3 Charger
* WARP Energy Manager 1.0
* WARP Energy Manager 2.0

:::

Mit dem Eco-Modus ist es möglich Ladevorgänge ökonomisch und ökologisch zu optimieren.
In die Planung fließen dynamische Strompreise, PV-Ertragsprognose und die
gewünsche Abfahrtszeit sowie maximale Standzeit des Elektrofahrzeugs ein.

Anhand der Planung wird ein optimierter Ladeplan erstellt. Wird der Eco-Modus auf einem
WARP Energy Manager oder einem WARP Charger verwendet der als Lastmanager konfiguriert ist,
werden individuelle Ladepläne für alle verwalteten Wallboxen erstellt.

## Konfiguration

Der Eco-Modus kann unter Energiemanagement -> Eco-Modus aktiviert und konfiguriert werden.

![image](/img/eco_mode/configuration.png)

Wenn die Ladeplanung aktiviert ist, wird auf der Status-Seite der konfigurierbare Ladeplan angezeigt.
Es kann folgendes konfiguriert werden:

* Die maximale Standzeit,
* eine Preisuntergrenze (`Immer laden wenn Preis unter`),
* eine Preisobergrenze (`Nie laden wenn Preis über`) und
* eine Untergrenze für die PV-Ertragsprognose (`Nur wenn PV-Ertragsprognose unter`).

Die maximle Standzeit gibt an, für wie viele Stunden nach Anstecken eines Fahrzeugs ein Ladeplan erstellt wird. Beispiel: Es ist 08:00, der Ladeplan ist kon­figu­riert auf `Nutze die güns­tigs­ten 4 Stunden bis Heute um 20:00 Uhr` und die maximale Standzeit ist auf 8 Stunden ein­ge­stellt. In diesem Fall würde der Ladeplan dafür sorgen dass die güns­tigs­ten 4 Stunden genutzt werden bevor die maximale Standzeit abläuft (also z.B. bis 16:00 wenn das Auto um 08:00 ein­ge­steckt wird, aber bis 18:00 wenn das Auto um 10:00 ein­ge­steckt wird). Mit dieser Kon­figura­tion kann z.B. die Arbeitszeit von Mitarbeitern be­rück­sich­tigt werden.

Die Preisuntergrenze gibt einen Preis in Cent an, unter dem ein Lade­vorgang, un­ab­hän­gig vom Ladeplan, immer frei­gegeben wird. Es wird mit dem Netto-Börs­en­strom­preis (ohne eventuell konfigurierte Zu­satz­kos­ten) verglichen.

Die Preisogergrenze gibt einen Preis in Cent an, über dem ein Lade­vorgang, un­ab­hän­gig vom Ladeplan, nie frei­gegeben wird. Es wird mit dem Netto-Börs­en­strom­preis (ohne eventuell konfigurierte Zu­satz­kos­ten) verglichen.

Die Untergrenze für die PV-Ertragsprognose gibt einen Schwell­wert in Kilowattstunden an, über dem ein Lade­vorgang nur bei PV-Über­schuss frei­gegeben wird (der Ladeplan wird ignoriert). Beispiel: `Nur wenn PV-Er­trags­pro­gno­se unter` ist auf 75 kWh/Tag kon­figu­riert und die PV-Er­trags­pro­gno­se für heute liegt bei 80 kWh/Tag. In diesem Fall würde der Ladeplan nicht aus­geführt und nur geladen wenn PV-Über­schuss verfügbar ist. Es wird also kein Strom eingekauft, auch nicht wenn er sehr günstig wäre, wenn bekannt ist, dass genug PV-Über­schuss verfügbar sein wird.

Um die Ladeplanung nutzen zu können muss der [Dynamische Strompreis](/warp_charger/dynamic_tariffs.md). aktiviert sein. Wenn die PV-Ertragsprognose mit einfließen soll muss zusätzklich die [PV-Ertragsprognose](/warp_charger/solar_forecast.md) aktiviert sein.

## Konfigurierbarer Ladeplan (Status-Seite)

Wenn der Eco-Modus aktiviert ist und auf der Status-Seite ein Eco-Lademodus ausgewählt ist, erscheint ein konfigurierbarer Ladeplan:

![image](/img/eco_mode/charge_plan.png)

Im Ladeplan kann die Abfahrt auf

* `Heute`,
* `Morgen` oder
* `Täglich`

konfiguriert werden und eine Abfahrtszeit sowie Ladedauer angegeben werden.

Wenn der Eco-Modus auf einem Lastmanager aktiviert ist, dann wird der Ladeplan automatisch auf alle verwalteten WARP Charger angewedet. Die individuellen Ladepläne werden auch auf der Status-Seite angezeigt:

![image](/img/eco_mode/charge_plan_multi.png)

## Beispielkonfigurationen

Im folgenden führen wir Beispiele für sinnvolle Konfigurationen auf.

### Beispielkonfiguration 1: Das Auto soll mindestens 5 Stunden geladen haben wenn ich morgens zur Arbeit fahre.

In disem Fall wäre folgende Konfiguration des WARP Chargers sinnvoll:

* Abfahrt `Morgen` bis `08:00` mit Ladedauer `5 Stunden`.

Wenn in dem Beispiel das Elektrofahrzeug um 15:00 angesteckt wird, berechnet der Eco-Modus welche 5 Stunden bis morgen 08:00 die günstigsten sind und lädt entsprechend in diesen Stunden. PV-Überschussladen wird dabei (falls konfiguriert) natürlich bevorzugt.

### Beispielkonfiguration 2: In einer Firma mit mehreren Wallboxen soll jeder Mitarbeiter die günstigsten 3 Stunden am Tag laden können.

In disem Fall wäre folgende Konfiguration des Lastmanagers sinnvoll:

* Abfahrt `Täglich` bis `23:59` mit Ladedauer `3 Stunden`.
* Standzeit (in der Konfiguration des Eco-Modus) `8 Stunden`.

Wenn sich in dem Beispiel ein Mitarbeiter an eine WARP Charger anschließt und sich per NFC authentifiziert fängt seine Standzeit von 8 Stunden an. Der Eco-Modus würde dann in diesen 8 Stunden berechnen welche die günstigsten 3 Stunden sind und diese zum Laden nutzen. Auch hier wird PV-Überschussladen (falls konfiguriert) bevorzugt.

Durch diese Konfiguration ist sichergestellt dass jeder Mitarbeiter einen individuelle Ladeplan bekommt. Sowohl der Mitarbeiter der um 06:00 anfängt als auch der Mitarbeiter der um 10:00 anfängt bekommt die (in der jeweiligen Arbeitszeit die hier mit 8 Stunden angenommen wird) günstigsten Stunden.