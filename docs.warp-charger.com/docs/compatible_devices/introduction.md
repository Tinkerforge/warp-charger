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
Coming soon - Wird mittels Softwareupdate bereitgestellt.
:::

Bisher kann die Leistung von Batteriespeichern nur gelesen werden. Zukünftig wird es für gewisse Modelle möglich sein, dass der Lade- und Entladevorgang gesteuert werden kann (wenn der Hersteller es unterstützt).
Zum Einen kann somit auf Wunsch bei einem Schnelllade-Vorgang das Entladen eines Speichers verhindert werden. Zum Anderen kann der Speicher auch auf Grundlage von dynamischen Strompreisen gesteuert werden. Somit ist zum
Beispiel im Winter das Laden des Speichers bei günstigen Strompreisen aus dem Netz möglich.

:::note

Auf Tinkerunity haben wir eine Beta-Firmware veröffentlicht, die generell das Steuern eines Batteriespeichers mittels Modbus/TCP Befehlen unterstützt. Download hier: [Tinkerunity -  Beta-Test Batteriespeicher-Steuerung
](https://www.tinkerunity.org/topic/12962-beta-test-batteriespeicher-steuerung/).

:::


Die Firmware ist dazu gedacht erste Erfahrungen zu sammeln und je nach Hersteller und Gerät die korrekten Registereinstellungen zu bestimmen. Die Firmware ist daher an erfahrene Benutzer gerichtet und nicht für einen produktiven Einsatz gedacht.

Folgende Aktionen werden unterstützt und jeweils durch zwei Befehle implementiert:
 * Steuerung des Ladevorgangs aus dem Netz
   * Befehl: "*Laden vom Netz erlauben*"
   * Befehl: "*Erlaubnis zum Laden vom Netz zurücknehmen*"
 * Steuerung der Speicher Entladung
   * Befehl: "*Entladen verbieten*"
   * Befehl: "*Verbot zum Entladen zurücknehmen*"

Die ersten beiden Befehle steuern den Ladevorgang des Speichers aus dem Netz. Die anderen Beiden steuern den generellen Entladevorgang des Speichers. Bis zu 16 Modbus/TCP Register können zur Implementierung jedes Befehls geschrieben werden.
Alle Befehle können manuell durch Klicken auf den "Ausführen" Taster ausgelöst werden. Die eigentliche Logik zur Steuerung des Speichers, die auf diese Befehle zurückgreift, wird zur Zeit noch implementiert (Laden bei günstigen Strompreisen etc.).
Sie wird zeitnah mit einer weiteren Beta-Firmware veröffenlicht.

Die aktuelle Beta-Firmware nutzt aber bereits die Steuerung der Speicher Entladung um, sofern aktiviert, bei einem Schnellladevorgang die Entladung des Speichers zu unterbinden.


:::note Herstellerspezifische Implementierung

Es gibt kein generelles Vorgehen für alle Hersteller und Geräte, wie die jeweiligen Befehle implementiert werden können. Generell muss das Gerät eine Steuerung des Speichers mittels Modbus/TCP erlauben.
Es muss eine Sequenz von Schreibbefehlen in Register gefunden werden, die den jeweiligen Befehl implementiert.

:::

**Steuerung der Speicher Entladung**

Zur Steuerung der Entladung kann oftmals einfach der maximale Entladestrom gesetzt werden.
Wird dieser auf 0A gesetzt, so kann hiermit der Befehl "*Entladen verbieten*" implementiert werden. Um den Befehl "*Verbot zum Entladen zurücknehmen*" zu implementieren, kann der Entladestrom dann wieder auf den Ursprungswert
zurückgesetzt werden.

**Steuerung des Ladevorgangs aus dem Netz**

Die Steuerung der Ladung aus dem Netz ist oftmals komplizierter. Viele Hersteller bieten die Aktivierung von Zeitplänen, bei denen für einen gewissen Zeitraum ein Ziel-State of Charge (Target SoC o.ä.) definiert werden kann. Ist dieser SoC nicht
erreicht lädt der Speicher aus dem Netz. Sind diese Zeitpläne vorhanden und können per Modbus/TCP konfiguriert werden, so kann damit die Netzladung implementiert werden.

Eine Implementierung wäre dann für den Befehl: "*Laden vom Netz erlauben*" so, dass ein Zeitplan aktiviert wird, der zu allen Uhrzeiten den Speicher zu 100% lädt.
Für den Befehl: "*Erlaubnis zum Laden vom Netz zurücknehmen*" wäre dieser Zeitplan dann zu deaktivieren oder den Ziel-State of Charge auf ein Minimum, zum Beispiel 20%, zu setzen.


