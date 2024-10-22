---
sidebar_position: 10
---

import { SortableDataTable, SortableDataButton } from "@site/src/components/SortableDataTable";
import { columns, meters, moduleTests } from "./meters.table";

# Kompatible Stromzähler

WARP Charger und der WARP Energy Manager können direkt auf die Daten von
Stromzähler zugreifen.

Dies sind Daten zur Erzeugung von PV-Wechselrichtern
aber auch Daten von Batteriespeicher und Daten
vom Netzanschluss (auch Hausanschluss genannt). Die ausgelesenen Stromzählerwerte
können von einem WARP Charger oder Energy Manager
für Regelungen (PV-Überschuss, dyn. Lastmanagement) verwendet
bzw. zur Auswertung aufgezeichnet werden.

Für ein [PV-Überschlussladen](/warp_charger/pv_excess_charging.md) oder
ein [dynamisches Lastmanagement](warp_charger/chargemanagement.md), muss
der WARP Charger oder der WARP Energy Manager Zugriff auf einen
Stromzähler am **Netzanschluss (Netz)** haben, da nur dort der eigentliche
PV-Überschuss bzw. die aktuellen Phasenströme ermittelt werden können.

Meistens ist bereits ein Zähler am Netzanschluss vorhanden. Wir
unterstützen verschiedene Möglichkeiten um auf diese Zähler zuzugreifen.
Ist ein Stromzähler direkt am PV-Wechselrichter angeschlossen, dann kann
oftmals über den Wechselrichter auf die Zählerdaten zugegriffen werden.

Folgende Möglichkeiten gibt es auf Zählerdaten vom Netzanschluss,
PV-Wechselrichter oder der Batterie zuzugreifen:

## SunSpec

[SunSpec](https://sunspec.org/sunspec-modbus-specifications/) ist ein
Kommunikationsstandard für PV-Wechselrichter.
WARP Charger und der WARP Energy Manager können SunSpec Geräte mittels
LAN oder WLAN direkt auslesen.

Ist ein Wechselrichter oder Energiemanager vorhanden,
der **Zugriff auf einen Stromzähler am Netzanschluss hat**, kann dieser
oft über SunSpec über das Netzwerk ausgelesen werden.

SunSpec bietet den Vorteil, dass kompatible Geräte direkt vom WARP
Charger und WARP Energy Manager erkannt und ausgelesen werden können.
Bei der Konfiguration muss nur SunSpec als Klasse ausgewählt und die IP
Adresse des Geräts ausgewählt werden. Das System listet alle erkannten
Geräte auf, so dass diese einfach zugeordnet werden können.

## Modbus/TCP

Nicht alle Geräte unterstützen SunSpec. Wir arbeiten daran die
wichtigsten Geräte, welche nicht per SunSpec nutzbar sind, dennoch zu
unterstützen. Der Zugriff mittels Modbus/TCP über LAN oder
WLAN ist eine andere weit verbreitete Möglichkeit und wird von vielen
Geräten unterstützt.

Vier verschiedene Modelle für virtuelle Stromzähler stehen zur Verfügung:
Wechselrichter, Netzanschluss, Speicher und Last. Je nach Gerät steht
nur ein Teil dieser Stromzähler zur Verfügung.

Bei Modbus/TCP müssen Informationen bereitgestellt werden, welche
Register gelesen und wie die Werte interpretiert werden müssen. Hierzu
gibt es zwei Möglichkeiten:


### Vordefinierte Registertabelle

Für uns bekannte Geräte haben wir bereits Registertabellen vordefiniert
Sind diese vorhanden, muss nur die entsprechende Voreinstellung
ausgewählt werden und die bereitgestellten Zähler zugeordnet werden.
Diese Geräte werden in der nachfolgenden Tabelle
mit dem Protokoll Modbus/TCP aufgeführt.

Einen technischen Einblick zu den jeweiligen Implementierungen findet
man auf [Github ESP32-Firmware prepare.py](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters_modbus_tcp/prepare.py)


### Benutzerdefinierte Registertabelle

Wird von uns noch keine gerätespezifische Registertabelle zur Verfügung
gestellt, so kann diese auch selbst definiert werden. In den
benutzerdefinierten Einstellungen muss nur der Adressmodus festgelegt
und anschließend die gewünschten Register angelegt werden. Es können der
Typ des Registers, ein Offset (Verschiebung), ein Skalierfaktor (Float)
und die Zuordnung auf einen Zählerwert (z.B. Wirk-Leistung L1) definiert
werden. Prinzipiell sollte damit jedes Modbus/TCP fähige Gerät unterstützt
werden.

:::note

Für das PV Überschussladen muss ein API Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
***"Wirk­leistung (Bezug minus Ein­speisung); Σ L1, L2, L3 \[W\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.

:::


### Modbus/RTU (Wandler)

Nicht alle Geräte unterstützten Modbus/TCP. Gerade ältere Geräte kommunizieren mittels
Modbus/RTU, einem Zweidraht RS485 Bus. Somit können diese Geräte
nicht einfach über das Netzwerk ausgelesen werden. Es gibt aber Wandler, die einen RS485 Bus auf
LAN oder WLAN umsetzen können. Wird so ein Wandler zwischen dem Modbus/RTU (RS485) Anschluss des Geräts und dem
Netzwerk (LAN, WLAN) gesetzt, kann das Gerät mittels Modbus/TCP ausgelesen werden.

Nutzer im WARP Forum [Tinkerunity.org](https://www.tinkerunity.org/forum/13-warp-charger/)
setzen zum Beispiel den ***Ebytes NB114*** Wandler mit Ethernet-Anschluss ein. Dieser Wandler kostet ca. 20€.
Alternativ ist mit dem **Elfin EW11** ein Wandler mit Wifi kostengünstig verfügbar. Dieser Wandler kostet ca. 15€.

#### Elfin EW11
Der Elfin EW11 ist ein kleines Wifi Dongle, welches zwischen Modbus/TCP und Modbus/RTU wandeln kann.
Folgende Einrichtungsschritte sind hier notwendig:

 * Mit AP (typischerweise EW11_XXXXX) verbinden. Kein Passwort notwendig.
 * http://10.10.100.254 öffnen, Zugangsdaten admin:admin
 * Unter System->Settings AP+STA konfigurieren und STA Wifi einrichten
 * Serial Port Settings korrekt für den jeweiligen Wechselrichter konfigurieren (oftmals 9600 8N1), Protocol Modbus
 * Communication Settings einen TCP server auf Port 502 mit Route "Uart" anlegen und speichern. Der bereits vordefinierte "netp" kann dafür verwendet werden.


## SMA Speedwire

SMA Geräte können über die SMA Speedwire Schnittstelle ausgelesen werden.

## API

Die MQTT und HTTP WARP Push API
kann genutzt werden um von extern Zählerdaten dem WARP Charger oder
dem WARP Energy Manager mitzuteilen. Siehe
[API Referenz - Meters](/docs/mqtt_http/api_reference/meters).

## Am WARP Energy Manager angeschlossene Stromzähler

Der WARP Energy Manager kann bestimmte Stromzähler direkt per Modbus/RTU (RS485)
auslesen. Dies ist vor allem interessant wenn noch kein Zähler am
Netzanschluss vorhanden ist. In dem Fall kann ein WARP Energy Manager installiert
und zusätzlich ein kompatibler Modbus/RTU-Stromzähler an diesem angeschlossen werden.
Von dem WARP Energy Manager werden nicht alle Modbus/RTU Stromzähler unterstützt.
Zum WARP Energy Manager kompatible Stromzähler sind in der Liste mit aufgeführt.

## Bekannte kompatible Geräte

Die folgende Liste führt Geräte auf, die bereits getestet wurden.

:::note

Wenn du ein Gerät besitzt, das du getestest hast und dieses noch nicht
in der Liste aufgeführt ist, schicke uns doch eine Email an
[info@tinkerforge.com](mailto://info@tinkerforge.com) damit wir die
Liste erweitern können. Solltest du eine eigene Modbus/TCP
Registertabelle definiert haben, schicke uns diese gerne zu, damit wir
diese für alle hinterlegen können.

Solltest du Probleme mit einem der aufgeführten Geräte haben, oder aber
die Unterstützung eines Geräts wünschen, dann schreibe uns im Forum auf
[Tinkerunity](https://www.tinkerunity.org/forum/13-warp-charger/).

:::

<SortableDataTable
  columns={columns}
  data={ meters }
/>

<SortableDataButton
  text="Füge neuen Stromzähler hinzu"
  editUrl="https://github.com/Tinkerforge/warp-charger/blob/master/docs.warp-charger.com/docs/meters.table.js"
/>


## Herstellerspezifische Informationen

### Alpha Ess
Die folgenden Alpha ESS Smile Heimspeicher unterstützen eine Anbindung mittels Modbus/TCP: SMILE5, SMILE-Hi5, SMILE-Hi10, SMILE-G3-S3.6/B5/S5, SMILE-BAT-8.2PHA.
Die integration bietet die virtuellen Stromzähler "Wechselrichter", "Netzanschluss" und "Speicher".
Die Messwerte des Netzanschlusses können für ein PV-Überschussladen und für ein dynamisches Lastmanagement genutzt werden.

### Carlo Galvazzi
Der EM24 in der Ausführung mit Ethernet kann mittels Modbus/TCP ausgelesen werden.

### Deye
Deye Hybrid-Wechselrichter der SUN Serie (Nieder- und Hochspannung) unterstützen Modbus/RTU.
Mit einem Umsetzer von Modbus/RTU auf Ethernet kann auf diese auch mittels Modbus/TCP zugegriffen werden.

Wenn der Wechselrichter per WLAN im Netzwerk verfügbar ist kann über Modbus/TCP auf dessen Zählerwerte zugegriffen werden.
Für ein PV-Überschussladen und für das dyn. Lastmanagement ist ein Stromzähler am Netzanschluss notwendig, der vom Deye Wechselrichter ausgelesen werden kann.
Entgegen der Modbus/TCP Spezifikation muss für das offizielle WLAN Dongle von Deye 8899 anstatt 502 als Modbus/TCP Port ausgewählt werden.

Es wird ein virtueller Stromzähler "Netzanschluss", "Speicher", "Last" und "Wechselrichter" bereitgestellt. Netzanschluss ist nur nutzbar wenn ein externer Hardware-Stromzähler
am Netzanschluss installiert wurde und vom Wechselrichter ausgelesen werden kann.

Im [Forumpost auf Tinkerunity](https://www.tinkerunity.org/topic/12271-weitere-wechserichter-modbustcp-supporten-deye-hybrid-wechselrichter/) gibt es weitere Informationen hierzu.

### E3DC
E3DCs Hauskraftwerke unterstützen SunSpec und können somit einfach eingebunden werden.
Es werden S10 Hauskraftwerke unterstützt. Vermutlich gilt dies auch für die S20 Serie.
Damit das Hauskraftwerk eingebunden werden kann muss Modbus/TCP im SunSpec Modus aktiviert werden.
Für ein PV-Überschussladen und für das dyn. Lastmanagement ist ein Stromzähler am Netzanschluss notwendig, der vom Hauskraftwerk ausgelesen werden kann.

### Eastron
Eastron Stromzähler mit RS485 (Modbus/RTU) Schnittstelle können direkt am WARP Energy Manager angeschlossen und von diesem ausgelesen werden.
Bei den Typen SDM630 und SDM72V2 wird der Strom über den Zähler geführt. Diese Zähler werden also direkt in die Leitungen eingebaut.

Mit dem Typ SDM630MCT wird auch ein Typ unterstützt der externe Wandler nutzt. Dieser Zähler wird also nicht in die Leitungen eingebaut, sondern es
werden nur die Wandler um die Leitungen gelegt. Durch die Wahl der entsprechend dimensionierten Wandler können auch sehr große Ströme gemessen werden.

### Elgris
Das elgris Smart Meter LAN 2.0 kann einfach mittels SunSpec eingebunden werden. SunSpec sollte direkt auf dem Stromzähler aktiviert sein.

### Eltako
Der Eltako Stromzähler DSZ15DZMOD mit RS485 (Modbus/RTU) Schnittstelle kann am WARP Energy Manager angeschlossen und von diesem ausgelesen werden.

### Fronius
Fronius Wechselrichter der Primo, Symo- und der GEN24-Serie sprechen SunSpec und können direkt ausgelesen werden. Es muss nur die Datenausgabe über Modbus/TCP aktiviert werden.
Als Port sollte 502 konfiguriert werden. Als SunSpec Model Type kann "float" gewählt werden.
Für ein PV-Überschussladen und für das dyn. Lastmanagement ist ein Stromzähler am Netzanschluss notwendig, der vom Fronius Wechselrichter ausgelesen werden kann.

### Fox ESS
Fox ESS Wechselrichter scheinen nicht mittels Modbus TCP über den Fox ESS LAN oder Wifi Dongle ausgelesen werden zu können. Sie sind aber mittels RS485 (Modbus RTU) auszulesen.
Wird ein RS485 nach LAN oder WLAN Wandler installiert (siehe [Modbus RTU Wandler](/compatible_meters#modbusrtu-wandler)), so können diese Wechselrichter ebenfalls ausgelesen werden.
Am Wechselrichter muss die Geräte ID von 000 (Modbus RTU deaktiviert) auf 247 eingestellt werden. Die Einstellung dazu findet sich unter Settings -> Communication -> RS485 -> Device ID.
Das Wechselrichterpasswort ist standardmäßig auf 0000 gesetzt.

### Goodwe
Die Einbindung eines Wechselrichters der ES, EM, SBP, ET, BT, EH, BH, EHB Serie ist mittels Modbus/TCP über das LAN bzw. Wifi+LAN Modul möglich.
Wir arbeiten zur Zeit daran eine Goodwe Registertabelle zu hinterlegen (Coming Soon). Aktuell muss die Registertabelle von Hand angegeben werden.
Zukünftig werden die virtueller Stromzähler "Netzanschluss", "Speicher", "Last" und "Wechselrichter" bereitgestellt.

Ist an dem Wechselrichter ein Stromzähler angeschlossen (z.B. GM300), der vom Wechselrichter ausgelesen werden kann, kann dieser Stromzähler für ein PV-Überschussladen und ein dynamisches Lastmanagement genutzt werden.

### Hailei
Die Integration von Hailei Wechselrichtern folgt. Ein Auslesen ist mittels Modbus/TCP nach Modbus/RTU Wandlern (z.B. EW11) über die Modbus/RTU Schnittstelle des Wechselrichters möglich.

### Huawei
Wechselrichter der SUN2000 Serie (L1, M0, M1, M2, M3) können über das Huawei Smart Dongle (SmartdDongle ab Firmware SPC124) mittels Modbus/TCP ausgelesen werden. Aktuell ist noch keine Registertabelle hierfür hinterlegt.
Diese muss noch per Hand angelegt werden. Wir werden aber zeitnah eine vorwählbare Registertabelle bereitstellen.

Es werden die virtueller Stromzähler "Netzanschluss", "Speicher", "Last" und "Wechselrichter" bereitgestellt. Netzanschluss ist nur nutzbar, wenn ein externer Hardware-Stromzähler (Huawei Smart Power Sensor)
vom Typ DTSU666-H oder DDSU666-H am Wechselrichter angeschlossen wurde. Speicher ist nur nutzbar im Zusammenspiel mit der Luna2000 Batterie.

### Kaco
Kaco Wechselrichter der NH3, NX3 und TL3 Baureihe sprechen SunSpec und können direkt ausgelesen werden. Der Standardport ist 502. SunSpec muss im Protokoll Menü des Wechselrichters aktiviert werden.

### Kostal
Das Smart Energy Meter (KSEM G2) kann direkt mittels SunSpec kommunizieren.

Zusätzlich kann die Erzeugung der Piko und Plenticore Wechselrichter mittels SunSpec ausgelesen werden. Ein PV-Überschussladen nur mit dieser Wechselrichterdaten ist nicht möglich,
da dafür ein Stromzähler am Netzanschluss notwendig ist.

### RCT
RCT Wechselrichter können leider nicht mittels SunSpec oder Modbus/TCP angesprochen werden. Dies ist aber über das offengelegte RCT Power Serial Communication protokoll mittels TCP/IP möglich.
Wir planen die Implementierung des Protokolls um auch Wechselrichter von RCT einbinden zu können.

### Shelly
Der einphasige Wandler-Stromzähler Shelly Pro EM und dreiphasige Wandler-Stromzähler Shelly Pro 3EM werden unterstützt und können mittels Modbus/TCP ausgelesen werden. Beide besitzten nur eine Breite von 1 TE und messen mittels Wandler.
Somit benötigen diese nur wenig Platz und können an verschiedene Maximalströme angepasst werden. (EM: 50A, 3EM: 120A, 400A).

Wichtig ist ein Update auf die neuste Software, so dass Modbus TCP unterstützt wird. Dieses muss dann unter Settings->Modbus aktiviert werden.

Für die Stromzähler sind jeweils spezifische Registertabellen implementiert und können einfach ausgewählt werden.

### Siemens
Die Siemens SENTRON Energiezähler vom Typ 7KM2200 (PAC2200) und 7KM3200 (PAC3200) können mittels Modbus/TCP ausgelesen werden.

### SMA
SMA Geräte unterstützen zum Teil SunSpec, so dass diese direkt ausgelesen werden können. Dazu zähler zum Beispiel die Sunny Boy Wechselrichter. Andere Geräte von SMA nutzen das SMA Speedwire Protokoll.
Dieses wird ebenfalls unterstützt, so dass auch auf die Daten vom SMA Energy Meter 2.0 oder dem Sunny Home Manager zugegriffen werden können. Über diese beiden kann die Leistung am Netzanschluss gemessen
werden so dass ein PV-Überschussladen und ein dynamisches Lastmanagement mit diesen Zählerwerten möglich ist.

### SolarEdge
SolarEdge Home Wechselrichter verfügen über eine SunSpec Schnittstelle. Unseres Wissens kann diese Schnittstelle nicht selbst aktiviert werden, sondern muss vom SolarEdge Support aktiviert werden.

Ist die Schnittstelle aktiviert, so kann der Wechselrichter inklusive einem angeschlossenen Energiezähler ausgelesen werden. Ist ein Energiezähler vorhanden, so ist damit ein PV-Überschussladen und
ein dynamisches Lastmanagement möglich.

:::note

Ein Kunde berichtet davon, dass die SunSpec IDs der Geräte (Energiezähler, Wechselrichter) sich nach einem Neustart dieser Geräte ändert. Dieses führt dazu, dass die Geräte nicht mehr erreichbar sind und neu
im WARP System angelegt werden müssen. SolarEdge arbeitet an einer Lösung.

:::

### Solarmax
Das Speichersystem MAX.STORAGE kann mittels Modbus/TCP ausgelesen werden. Es steht der virtuelle Stromzähler "Wechselrichter" zur Verfügung. Dieser gibt Informationen zu den DC Leistungen des Wechselrichters der Batterie.
Zusätzlich stellt der virtuelle Stromzähler "Netzanschluss" die Leistung am Netzanschluss zur Verfügung. Ein PV-Überschussladen ist mit diesem Wert möglich.
Den SoC und die Leistung der Batterie werden mit dem virtuellen Stromzähler "Speicher" bereitgestellt.

### Solax
Solax String- und Hybridwechselrichter können über das Wi-Fi Dongle mittels Modbus/TCP ausgelesen werden. Eine Einrichtungsanleitung inkl. der unterstützen Wechselrichter gibt es in der [Solax Power Academy](https://kb.solaxpower.com/de/solution/detail/ff8080818eae9899018ec71a12ca1ea6).

### Sungrow
Sungrow Wechselrichter der Serien SGxxRT/SGxxRS/SGxxCX/SDxxCX-P2 und SHxxRT/SHxxRS können mittels Modbus/TCP ausgelesen werden. Es wird dann ein virtueller Stromzähler "Wechselrichter" erkannt.
Am Wechselrichter angeschlossene Hardware-Stromzähler vom Typ DSU555 o.ä., die von diesem ausgelesen werden können, können ebenfalls ausgelesen werden. Dazu gibt es den virtuellen Stromzähler "Netzanschluss".
Damit ist ein PV-Überschussladen möglich.
Wird an dem Wechselrichter eine Batterie angeschlossen, so kann diese ebenfalls mit dem virtuellen Stromzähler "Speicher" ausgelesen werden. Zusätzlich wird ein virtueller Stromzähler "Last" zur Verfügung gestellt.

Das Auslesen kann über einen WiNet-S mittels LAN/WLAN erfolgen (versionsabhängig). Hierbei scheint es aber je nach Hardwareversion und Firmware Probleme geben zu können. SunGrow empfielt, sofern vorhanden, direkt den LAN Anschluss
des Wechselrichters zu verwenden. Die Modbus/TCP Verbindung unterstützt oftmals anscheinend nur einen Client.

### Tasmota
Tasmota bietet ein [Smart Meter Interface](https://tasmota.github.io/docs/Smart-Meter-Interface/) damit können über ein IR-Lesekopf die Zählerwerte des Smart Meters vom Netzbetreiber ausgelesen werden.
Netzbetreiber nutzen zum Beispiel Smart Meter der Marke DZG (z.B.: DWS, DVS), EMH (z.B.: ED300, eHZ) oder Holley (z.B.: DTZ, EHZ). Eine vollständige Liste lässt sich unter dem oben genannten Link finden.

Das Smart Meter ist typischwerweise mit einem Pin gesichert und muss zuvor mittels Pin freigegeben werden. Den Pin erhält man von seinem Netzbetreiber. Es werden selbstgebaute Leseköpfe unterstützt, welche typischerweise aus einem
ESP32 und einer Fotodiode bestehen. Es gibt aber auch Fertiglösungen wie den "Hichi TTL - Lesekopf".

Technisch muss für das jeweilige Zählermodell der entsprechende [Smart Meter Descriptor](https://tasmota.github.io/docs/Smart-Meter-Interface/#smart-meter-descriptors) im ESP32 des Lesekopf hinterlegt werden.
Kann darüber der Zähler ausgelesen werden, so kann der Leistungs-Messwert (ab Tasmota Version 13.x) mittels der [HTTP API](https://docs.warp-charger.com/docs/mqtt_http/api_reference/meters)
 an einen WARP Charger oder einen WARP Energy Meter geschickt werden.

Dazu wird auf dem WARP Energy Manager oder WARP Charger ein API Stromzähler konfiguriert. Dieser erhält nur einen einzigen Wert ("Wirk­leistung (Bezug minus Ein­speisung); Σ L1, L2, L3 \[W\]).
Dieser Wert wird dann aus dem Tasmota SML Skript mittels folgender Zeile übertragen:

```
=>WebQuery http://192.168.2.30/meters/0/update POST [Content-Type:application/json] [%sml[3]%]
```

Welcher Wert übertragen wird muss durch ausprobieren herausgefunden werden. Im Testfall war es sml\[3\]. Nachfolgend ein vollständiges Beispielskript für einen DZG DWS7412.
Es wird der Wert mittels HTTP Post an den API Zähler 0 übertragen. Zusätzlich werden alle sml Messwerte anschließend ausgegeben (Print). Mit dem Print lässt sich herausfinden, welcher Wert der korrekte zum übertragen ist.

```
>D
>B
=>sensor53 r
>S
=>WebQuery http://192.168.2.30/meters/0/update POST [Content-Type:application/json] [%sml[3]%]
print %sml[0]%,%sml[1]%,%sml[2]%,%sml[3]%
>M 1
+1,3,s,16,9600,DWS7412
1,77070100010800ff@1000,Energie,kWh,energy,4
1,77070100020800ff@1000,Lieferung,kWh,en_out,4
1,77070100100700ff@1,Leistung,W,power,2
1,7707010060320101@#,SID,,meter_id,0
```

Diese Lösung lässt sich nur für ein PV-Überschussladen verwenden, da nur die Gesamtleistung übertragen wird. Für ein dynamisches Lastmanagement ist auch die Übertragung der Phasenströme notwendig. Diese kann man typischerweise
nicht von einem Smart Meter erhalten.

Hier der [Tinkerunity Blogpost](https://www.tinkerunity.org/topic/12255-z%C3%A4hler-des-netzbetreibers-sml-ir-hichi%E2%80%A6-f%C3%BCr-pv-%C3%BCberschuss/?do=findComment&comment=55374)
auf dem diese Beschreibung ursprünglich basiert.

### Victron

Victron Geräte, wie zum Beispiel die bekannten Multiplus oder Quattro Wechselrichter, werden üblicherweise von einem [GX Gerät](https://www.victronenergy.com/live/venus-os:start) gesteuert.
Ein GX Gerät stellt unter "Services" eine Zusammenfassung aller angeschlossen Geräte wie Inverter, Batterien etc. dar. Auch wenn diese Geräte per VE.BUS angeschlossen sind. Die Daten werden unter "System" summiert.
Werden als Beispiel mehrere Wechselrichter parallel betrieben, so stellt "System" die Summe der Erzeugung da. Wir unterstützen den Zugriff auf die "System"-Daten für "Netzanschluss",
"Last", "Wechselrichter" und "Speicher".

Ist ein Stromzähler am Netzanschluss installiert ("Netzanschluss") kann dieser für ein PV-Überschussladen genutzt werden.

### YTL

Der YTL Stromzähler DEM4A mit RS485 (Modbus/RTU) Schnittstelle kann direkt am WARP Energy Manager angeschlossen und von diesem ausgelesen werden.
