---
sidebar_position: 1
---

# Einführung

[WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) können direkt auf die Daten von
anderen Fremdgeräten zugreifen.

Dazu zählen die Daten von Stromzählern (zum Beispiel am Netzanschluss),
Daten von PV-Wechselrichtern zur aktuellen Erzeugung
aber auch Daten zur Leistung von Batteriespeichern oder Leistungsdaten von Verbrauchern (Last). Die ausgelesenen Daten
können von einem WARP Charger oder WARP Energy Manager
zur Regelung von Wallboxen (PV-Überschussladen), zur PV-Überschussnutzung einer Wärmepumpe oder aber für ein
dynamisches Lastmanagement verwendet werden.

Der WARP Energy Manager zeichnet zusätzlich der ermittelten Daten lokal auf seiner SD-Karte auf. Über das Webinterface können in der [Energiebilanz](/docs/webinterface/energy_manager/energy_analysis)
die aufgezeichneten Daten analysiert werden.

Um auf die Daten zugreifen zu können, sind wir auf die von dem jeweiligen Geräte-Hersteller bereitgestellte [Schnittstellen](/compatible_devices/interfaces.md) angewiesen.
Abhängig vom Gerät und Hersteller muss dazu die passende [Schnittstelle](/compatible_devices/interfaces.md) im Webinterface unter [Stromzähler](/webinterface/energy_management/energy_meters.md)
auf dem [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) konfiguriert werden.

:::note

Die Liste der kompatiblen Geräte befindet sich hier: [Liste kompatibler Geräte](/docs/compatible_devices/devices)

:::



## Messort von Gerätedaten

Wir unterscheiden zwischen vier verschiedenen Messorten von Datenquellen. Diese sind nachfolgend aufgeführt.
Teilweise unterstützen Geräte mehrere Messorte parallel. So gibt es zum Beispiel Hybrid-Wechselrichter die Daten
zu allen vier Messorten liefern.

Die Messorte werden genutzt um die einzelnen Datenquellen zuordnen und zusammenfassen zu können und
daraus eine Energie-Übersicht erstellen zu können.

Stromzählern ohne feste Rolle können einem Messort händisch zugeordnet werden. Somit kann ein Stromzähler installiert werden
um zum Beispiel die Last zu erfassen. Ebenso ist es möglich einen Stromzähler am Netzanschluss zu installieren
und ihm den Messorte "Netzanschluss" zuzuordnen, sollte kein auswertbarer Stromzähler vorhanden sein.

### Netzanschluss

Wenn eine PV-Anlage bereits installiert ist, ist meist auch ein Zähler ("Smartmeter") am Netzanschluss installiert.
Dieser ist dann am PV-Wechselrichter angebunden und kann oftmals über den Wechselrichter ausgelesen werden.
Wir unterstützen verschiedene Möglichkeiten um auf diese Zähler zuzugreifen.

### PV

PV-Wechselrichter (auch Hybrid-Wechselrichter) stellen oftmals Daten zu ihrer aktuellen PV-Erzeugung zur Verfügung.

### Batteriespeicher

Ein Hybrid-Wechselrichter ist eine Kombination aus Photovoltaik-Wechselrichter und Batterie-Wechselrichter.
Diese Wechselrichter stellen oftmals neben den Daten zur PV-Erzeugung auch Daten zur aktuellen Leistung der Batterie (Laden/Entladen) bereit.
Es gibt auch reine Batteriewechselrichter auf die zugegriffen werden kann.

Zukünftig wird für viele Modelle auch eine Steuerung des Speichers möglich sein.

### Last

Um erfassen zu können wohin die erzeugte Leistung fliest gibt es den Messort "Last". Manche Wechselrichter verfügen auch über einen auslesbaren Lastausgang.

## Anwendungen
### PV-Überschussladen

Für ein [PV-Überschlussladen](/tutorials/pv_excess_charging.md) muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen
Stromzähler am **Netzanschluss (Netz)** haben, da nur dort der eigentliche
PV-Überschuss ermittelt werden kann.

:::note

Für das PV-Überschussladen muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
***Wirk­leistung (Bezug minus Ein­speisung); Σ L1, L2, L3 \[W\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.

:::

Ist zusätzlich ein Batteriespeicher vorhanden und ist dieser ebenfalls auslesbar,
macht es Sinn diesen ebenfalls anzulegen, so dass das PV-Überschussladen diesen
berücksichtigen kann.

*Das PV-Überschussladen regelt die Summe der Wirkleistung so, dass überschüssige Leistung
in ein Fahrzeug geladen anstatt in das Stromnetz zurückgespeist wird.*

### Dynamisches Lastmanagement

Für das [dynamisches Lastmanagement](/tutorials/chargemanagement.md), muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen
Stromzähler am **Netzanschluss (Netz)** haben, da nur dort die aktuellen
Phasenströme ermittelt werden können.

:::note

Für das dynamisches Lastmanagement muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
 * ***Strom (Bezug minus Ein­speisung); L1 \[A\]*** bzw. ***Strom (Bezug plus Ein­speisung); L1 \[A\]*** oder ***Strom (Bezug); L1 \[A\]***
 * ***Strom (Bezug minus Ein­speisung); L2 \[A\]*** bzw. ***Strom (Bezug plus Ein­speisung); L2 \[A\]*** oder ***Strom (Bezug); L2 \[A\]***
 * ***Strom (Bezug minus Ein­speisung); L3 \[A\]*** bzw. ***Strom (Bezug plus Ein­speisung); L3 \[A\]*** oder ***Strom (Bezug); L3 \[A\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.
Ob ***"Bezug"***, ***"Bezug minus Einspeisung"***, ***"Bezug plus Einspeisung"*** gewählt werden muss, hängt von dem jeweiligen Stromzähler ab. Dies kann im Zweifelsfall ausprobiert werden.

:::

*Das dynamische Lastmanagement regelt Ladevorgänge so, dass auf keiner Phase (L1, L2, L3) der maximal eingestellte Phasenstrom überschritten wird.*

### Batteriesteuerung


:::note

    Die Steuerung von Batteriespeichern befindet sich zur Zeit noch in der Entwicklung und ist noch nicht Teil der Release-Firmware!

    Auf Tinkerunity haben wir eine Beta-Firmware veröffentlicht, die generell das Steuern eines Batteriespeichers mittels Modbus/TCP Befehlen unterstützt. Download hier: [Tinkerunity -  Beta-Test Batteriespeicher-Steuerung
](https://www.tinkerunity.org/topic/13229-beta-test-batteriespeicher-steuerung-phase-2/).

    Zur Zeit müssen noch die jeweiligen Register zur Steuerung angelegt werden. Ein Export bzw. Import dieser Einstellungen ist möglich. Zukünftig wird es, analog zu den Stromzählern, natürlich auswählbare "Presets" für diese Speicher geben.
    Das Verhalten ist zur Zeit durch Anlegen von Regeln zu definieren. Nach der Testphase ist es geplant diese Regeln durch ein bedienerfreundlicheres Nutzerinterface zu ersetzen oder zu ergänzen.

    Es kann nicht garantiert werden, dass diese Batteriespeicher-Einstellungen bei einem Firmwareupdate korrekt übernommen werden!
:::


#### Steuerung von Batteriespeichern

Viele Hersteller unterstützen die externe Steuerung von Batteriespeichern mittels [Modbus/TCP](/docs/compatible_devices/interfaces#modbustcp) Schnittstelle.
Meist wird der Batteriespeicher über den angeschlossenen Wechselrichter gesteuert und nicht die Batterie direkt. Die zur Verfügung gestellten Register zur Steuerung unterscheiden sich je nach Hersteller und Gerät, so dass nicht alle Geräte
alle Funktionen unterstützen. Auch die Umsetzung der jeweiligen Funktion unterscheidet sich stark von Gerät zu Gerät!

#### Generelle Idee

Der Speicher wird von uns nicht geregelt. Er übt seine vom Hersteller definierte Funktion aus. Das heißt im Normalfall wird ein PV-Überschuss zur Ladung des Speichers genutzt und der Speicher versucht die Leistungsaufnahme eines Verbrauchers
zu kompensieren. Mit den nachfolgend aufgeführten Funktionen kann aber in diese Regelung eingegriffen werden.

#### Anlegen eines Batteriespeichers

Wir ermöglichen es einen Batteriespeicher mittels Modbus/TCP zu steuern. Analog zu den Stromzählern muss der Host, Port und der Adressmodus definiert werden. 

Für diesen Speicher können anschließend drei nachfolgend aufgelistet Funktionen implementiert werden. Es müssen nicht alle Funktionen für den jeweiligen Speicher
implementiert werden. Wird aber eine Funktion implementiert, so muss auch die Aufhebung dieser Funktion implementiert werden.

Es können einzelne Register, aber auch mehrere Register in einem Befehl geschrieben werden. Es wird empfohlen Register, die aufeinanderfolgend sind, als ein Block in einem Befehl zu schreiben. 

#### Laden vom Netz erlauben

Diese Funktion versucht den Speicher zu zwingen, auf 100% SoC zu laden. Wird die Ladeleistung nicht über PV gedeckt, so soll der Speicher mit Strom aus dem Netz laden. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Genereller "Minimum SoC" auf 100% setzen. Dies funktioniert aber nur, wenn das System dann auch Strom aus dem Netz zum Laden bezieht.
 * Setzen und Aktivieren eines Ladeplans mit dem Uhrzeitbereich 00:00-23:59 Uhr und einem Ziel-SoC von 100%.

#### Entladen verbieten

Mit dieser Funktion wird dem Speicher verboten zu entladen. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Setzen des "Maximalen Entladestroms" auf 0A.
 * Setzen des "Minimum SoC" auf 100%. Dies funktioniert nur, wenn das System dann NICHT Strom aus dem Netz zum Laden bezieht sonder nur das Entladen deaktiviert.

#### Laden verbieten

Diese Funktion verbietet dem Speicher das Laden. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Setzen des "Maximalen Ladestroms" auf 0A.


### Verwendung des Batteriespeichers - Definition von Regeln

Für jede Funktion können mehrere Regeln definiert werden. Sind die Bedingungen einer Regel erfüllt, so wird die dazugehörige Funktion ausgeführt. Ist keine Regel für eine Funktion erfüllt, so wird die Funktion deaktiviert. Sprich es wird die Aufhebung der Funktion ausgeführt.

Jede Regel besteht aus einer Beschreibung (Freitext für den Nutzer), der Angabe eines Batterieladestands (SoC), eines Strompreises und einem Wert der PV-Ertragsprognose. Der Vergleich zu den angegebenen Werten kann als "kleiner als" oder "größer als" definiert werden.
Soll ein Wert nicht verwendet werden, so ist "wird ignoriert" zu konfigurieren.

Folgene Anwendungen sind als Beispiel möglich:

#### Netz-Ladung zu den günstigsten Stunden
Wenn die PV-Prognose für den aktuellen Tag unter einem gewissen Wert liegt, wird der Batteriespeicher bis zu einem gewissen SoC in den günstigsten Stunden aus dem Netz geladen.

**Beispiel:**

*Unter "Regeln für Ladung-vom-Netz-Erlaubnis" eine Regel anlegen mit der Beschreibung "Hausspeicher Minimum": Wenn Batterieladestand kleiner als 50% und dynamischer Strompreis kleiner als 30ct und PV-Ertragsprognose kleiner als 20kWh.*

Die Idee dahinter ist, dass ein minimaler Ladestand von 50% eingehalten werden soll, wenn für den Tag ein geringer PV-Ertrag erwartet wird (in diesem Fall 20kWh). Geladen werden soll aber nur, wenn der Strompreis kleiner 30ct beträgt.
Es ist denkbar weitere Regeln anzulegen, die andere Bedingungen definieren. So könnte als Beispiel die Batterie weiter aufgeladen werden, wenn der Strompreis geringer ist oder der erwartete PV-Ertrag geringer.

#### Batteriespeicher im "Schnell"-Lademodus nicht entladen
Im Wallbox-Lademodus "Schnell" kann das Entladen des Haus-Batteriespeichers verhindert werden. Diese Funktion ist vordefiniert und muss nur mittels "Batterieentladung beim Schnellladen verbieten" aktiviert werden.

#### Netzdienliches Laden des Batteriespeichers
Morgens, wenn das Netz noch den PV-Strom verwenden kann und somit noch eine Einspeisevergütung gezahlt wird, wird der Batteriespeicher nicht geladen und stattdessen in das Stromnetz eingespeist. Wenn dann gegen Mittag der PV-Strom nicht vom Stromnetz benötigt wird
und somit keine Einspeisevergütung mehr gezahlt wird, wird der Speicher geladen. Siehe auch [HTW-Berlin: Dein Stromspeicher kann mehr!](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/).

**Beispiel:**

*Unter "Regeln für Bat­te­rie­la­dungs-Verbot" eine Regel anlegen mit der Beschreibung "Speicheroptimierung": Wenn Batterieladestand größer 60% und dynamischer Strompreis größer als 20ct und PV-Ertragsprognose größer als 20kWh.*

Der betrachtete dynamische Strompreis beinhaltet alle konfigurierten Kosten. Die Annahme in diesem Beispiel ist, dass die weiteren Preisbestandteile 20ct pro kWh ausmachen. Das heißt bei einem Strompreis größer als 20ct sind die Strom-Erzeugungskosten noch positiv.
In diesem Fall wird der Strom vom Netz also noch benötigt und man erhält noch eine Einspeisevergütung. Das Ziel der Regel ist es, den Speicher in diesem Fall also nicht zu laden und stattdessen den PV-Überschuss in das Stromnetz einzuspeisen. Wird der "Strompreis negativ",
also der dynamische Strompreis fällt unter die definierten 20ct, dann würde die Regel aufgehoben und der Speicher ganz normal über den PV-Überschuss geladen.

Mit den Parametern "Batterieladestand" und "PV-Ertragsprognose" kann gesteuert werden, wie viel vom PV-Ertrag des Tages noch übrig bleiben muss um den Batteriespeicher an dem Tag noch zu laden. Im Winter, also bei geringem PV-Ertrag, möchte man zum Beispiel vermutlich nicht,
dass der PV-Überschuss nicht auch morgens schon in die Batterie fließt. Es können mehrere Regeln angelegt werden, die verschiedene Mindest-Ladestände mit PV-Ertragsprognosen verknüpfen.

