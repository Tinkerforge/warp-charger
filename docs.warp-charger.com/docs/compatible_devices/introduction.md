---
sidebar_position: 1
---

# Einführung

[WARP Charger](/warp_charger/introduction) oder [WARP Energy Manager](/warp_energy_manager/introduction) können direkt auf die Daten von
anderen Fremdgeräten zugreifen.

Dazu zählen die Daten von Stromzählern (zum Beispiel am Netzanschluss),
Daten von PV-Wechselrichtern zur aktuellen Erzeugung
aber auch Daten zur Leistung von Batteriespeichern oder Leistungsdaten von Verbrauchern (Last). Die ausgelesenen Daten
können von einem WARP Charger oder WARP Energy Manager
zur Regelung von Wallboxen (PV-Überschussladen), zur PV-Überschussnutzung einer Wärmepumpe oder aber für ein
dynamisches Lastmanagement verwendet werden.

Der WARP Energy Manager zeichnet zusätzlich der ermittelten Daten lokal auf seiner SD-Karte auf. Über das Webinterface können in der [Energiebilanz](/webinterface/energy_manager/energy_analysis)
die aufgezeichneten Daten analysiert werden.

Um auf die Daten zugreifen zu können, sind wir auf die von dem jeweiligen Geräte-Hersteller bereitgestellte [Schnittstellen](/compatible_devices/interfaces.md) angewiesen.
Abhängig vom Gerät und Hersteller muss dazu die passende [Schnittstelle](/compatible_devices/interfaces.md) im Webinterface unter [Stromzähler](/energy_management/energy_meters.md)
auf dem [WARP Charger](/warp_charger/introduction) oder [WARP Energy Manager](/warp_energy_manager/introduction) konfiguriert werden.





## Klassen von Gerätedaten

Wir unterscheiden zwischen vier verschiedenen Klassen von Datenquellen. Diese sind nachfolgend aufgeführt.
Teilweise unterstützen Geräte mehrere Klassen parallel. So gibt es zum Beispiel Hybrid-Wechselrichter die Daten
zu allen vier Klassen liefern.

Die Klassen werden genutzt um die einzelnen Datenquellen zuordnen und zusammenfassen zu können und
daraus eine Energie-Übersicht erstellen zu können.

Stromzählern ohne feste Rolle können einer Klasse händisch zugeordnet werden. Somit kann ein Stromzähler installiert werden
um zum Beispiel die Last zu erfassen. Ebenso ist es möglich einen Stromzähler am Netzanschluss zu installieren
und ihn der Klasse "Netzanschluss" zuzuordnen, sollte kein auswertbarer Stromzähler vorhanden sein.

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

Um erfassen zu können wohin die erzeugte Leistung fliest gibt es die Klasse "Last". Manche Wechselrichter verfügen auch über einen auslesbaren Lastausgang.

## Anwendungen
### PV-Überschussladen

Für ein [PV-Überschlussladen](/tutorials/pv_excess_charging.md) muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen
Stromzähler am **Netzanschluss (Netz)** haben, da nur dort der eigentliche
PV-Überschuss bzw. die aktuellen Phasenströme ermittelt werden können.

:::note

Für das PV-Überschussladen muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
***"Wirk­leistung (Bezug minus Ein­speisung); Σ L1, L2, L3 \[W\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.

:::

Ist zusätzlich ein Batteriespeicher vorhanden und ist dieser ebenfalls auslesbar,
macht es Sinn diesen ebenfalls anzulegen, so dass das PV-Überschussladen diesen
berücksichtigen kann.

### Dynamisches Lastmanagement

Für das [dynamisches Lastmanagement](/tutorials/chargemanagement.md), muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen
Stromzähler am **Netzanschluss (Netz)** haben, da nur dort die aktuellen
Phasenströme ermittelt werden können.

:::note

Für das dynamisches Lastmanagement muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
 * ***"Strom (Bezug minus Ein­speisung); L1 \[W\]*** bzw. ***"Strom (Bezug plus Ein­speisung); L1 \[W\]*** oder ***"Strom (Bezug); L1 \[W\]***
 * ***"Strom (Bezug minus Ein­speisung); L2 \[W\]*** bzw. ***"Strom (Bezug plus Ein­speisung); L2 \[W\]*** oder ***"Strom (Bezug); L2 \[W\]***
 * ***"Strom (Bezug minus Ein­speisung); L3 \[W\]*** bzw. ***"Strom (Bezug plus Ein­speisung); L3 \[W\]*** oder ***"Strom (Bezug); L3 \[W\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.
Ob ***"Bezug"***, ***"Bezug minus Einspeisung"***, ***"Bezug plus Einspeisung"*** gewählt werden muss, hängt von dem jeweiligen Stromzähler ab. Dies kann im Zweifelsfall ausprobiert werden.

:::

### Batteriesteuerung
Bisher kann die Leistung von Batteriespeichern nur gelesen werden. Zukünftig wird es für gewisse Modelle möglich sein, dass der Lade- und Entladevorgang gesteuert werden kann (wenn der Hersteller es unterstützt).
Zum Einen kann somit auf Wunsch bei einem Schnelllade-Vorgang das Entladen eines Speichers verhindert werden. Zum Anderen kann der Speicher auch auf Grundlage von dynamischen Strompreisen gesteuert werden. Somit ist zum
Beispiel im Winter das Laden des Speichers bei günstigen Strompreisen aus dem Netz möglich.

