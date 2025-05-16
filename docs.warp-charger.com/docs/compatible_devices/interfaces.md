---
sidebar_position: 2
---

# Schnittstellen

Mit Ausname der zum [WARP Energy Manager](/docs/warp_energy_manager/introduction)
kompatiblen Stromzählern, die an diesen [direkt angeschlossen](/compatible_devices/interfaces.md#am-warp-energy-manager-angeschlossene-stromz%C3%A4hler) werden können,
wird auf alle anderen Schnittstellen über das Netzwerk (LAN, WLAN) zugegriffen.

Nachfolgend eine Auflistung der kompatiblen Schnittstellen:

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

Für uns bekannte Geräte haben wir bereits Registertabellen vordefiniert.
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

Für das PV-Überschussladen muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
***"Wirk­leistung (Bezug minus Ein­speisung); Σ L1, L2, L3 \[W\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.

:::
:::note

Für das dynamisches Lastmanagement muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
 * ***"Strom (Bezug minus Ein­speisung); L1 \[A\]*** bzw. ***"Strom (Bezug plus Ein­speisung); L1 \[A\]*** oder ***"Strom (Bezug); L1 \[A\]***
 * ***"Strom (Bezug minus Ein­speisung); L2 \[A\]*** bzw. ***"Strom (Bezug plus Ein­speisung); L2 \[A\]*** oder ***"Strom (Bezug); L2 \[A\]***
 * ***"Strom (Bezug minus Ein­speisung); L3 \[A\]*** bzw. ***"Strom (Bezug plus Ein­speisung); L3 \[A\]*** oder ***"Strom (Bezug); L3 \[A\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.
Ob ***"Bezug"***, ***"Bezug minus Einspeisung"***, ***"Bezug plus Einspeisung"*** gewählt werden muss, hängt von dem jeweiligen Stromzähler ab. Dies kann im Zweifelsfall ausprobiert werden.

:::

## Modbus/RTU (Wandler)

Nicht alle Geräte unterstützten Modbus/TCP. Gerade ältere Geräte kommunizieren mittels
Modbus/RTU, einem zweidraht RS485 Bus. Somit können diese Geräte
nicht einfach über das Netzwerk ausgelesen werden. Es gibt aber Wandler, die einen RS485 Bus auf
LAN oder WLAN umsetzen können. Wird so ein Wandler zwischen dem Modbus/RTU (RS485) Anschluss des Geräts und dem
Netzwerk (LAN, WLAN) gesetzt, kann das Gerät mittels Modbus/TCP ausgelesen werden.

### Bekannte Wandler

Nachfolgend ein Auszug zu diversen Wandlern, mit den wichtigsten Einrichtungsschritten.

#### Ebytes NB114

![image](/img/compatible_devices/nb114-400.jpg)

Dieser Wandler kann aufgeschraubt werden und wandelt zwischen Modbus/TCP und Modbus/RTU um. Er verfügt nicht über WIFI, dafür aber über einen LAN Anschluss. Standardmäßig wird der
Wandler mit einer statischen IP Einstellung ausgeliefert. Die IP lautet 192.168.3.7. Die Zugangsdaten des Webinterfaces sind admin:admin. Folgende Einstellungen müssen gesetzt werden:

 * http://192.168.3.7 öffnen, Zugangsdaten admin:admin. Falls nicht erreichbar "Reload" Knopf am Gerät drücken.
 * Unter "Network parameter" als Work Mode "TCP Server", Port 502.
 * Unter "Serial parameter" die Einstellungen für den jeweiligen Wechselrichter konfigurieren (oftmals 9600 8N1).
 * Unter "Modbus parameter" die Einstellung "MODBUS TCP to RTU" auf "Open" setzen.


#### Elfin EW11

![image](/img/compatible_devices/elfin-ew11a-400.jpg)

Der Elfin EW11 ist ein kleines WIFI Dongle, welches zwischen Modbus/TCP und Modbus/RTU wandeln kann.
Folgende Einrichtungsschritte sind notwendig:

 * Mit AP (typischerweise EW11_XXXXX) verbinden. Kein Passwort notwendig.
 * http://10.10.100.254 öffnen, Zugangsdaten admin:admin
 * Unter "System Settings" AP+STA konfigurieren und STA Wifi einrichten
 * Unter "Serial Port Settings" die Einstellungen für den jeweiligen Wechselrichter konfigurieren (oftmals 9600 8N1), Protocol Modbus, CLI Disable
 * Unter "Communication Settings" einen TCP server auf Port 502 mit Route "Uart" anlegen und speichern. Der bereits vordefinierte "netp" kann dafür verwendet werden.


#### PUSR USR-DR302
Dieser Wandler kann auf eine Hutschiene montiert werden und wandelt zwischen Modbus/TCP und Modbus/RTU um. Er verfügt nicht über WIFI, dafür aber über einen LAN Anschluss.
Folgende Einrichtungsschritte sind notwendig:

 * Standardmäßig ist DHCP für den LAN Anschluss konfiguriert. Die Zugangsdaten für das Webinterface sind admin:admin.
 * Unter "Serial Port" die Einstellungen für den jeweiligen Wechselrichter konfigurieren (oftmals 9600 8N1), Work Mode TCP Server.


#### Waveshare RS232/485 To WIFI ETH (B) oder Waveshare RS232/485 To WIFI POE ETH (B)

![image](/img/compatible_devices/waveshare-rsto-400.jpg)

Dieser Wandler verfügt sowohl über WLAN als auch Ethernet und wandelt zwischen Modbus/TCP und Modbus/RTU um. Er kann mittels zweier Winkel irgendwo aufgeschraubt werden, aber auch mittels mitgelieferten Hutschienenhalter auf eine Hutschiene montiert werden.
Es gibt eine PoE fähige Ausführung. Anscheinend wird der Wandler mit einer statischen IP Einstellung ausgeliefert. Die IP lautet 192.168.1.200. Die Passwort des Webinterfaces lautet admin.
Im [Waveshare Wiki](https://www.waveshare.com/wiki/RS485_TO_ETH_(B)) gibt es weitere Informationen. Weitere Einstellungen können über das VirCom Tool von Waveshare vorgenommen werden.
Dieses Tool ermöglicht es auch die IP Adresse des Wandlers zu ermitteln.

Folgende Einrichtungsschritte sind notwendig:

 * http://192.168.1.200 öffnen, Password admin. Falls nicht erreichbar andere IP suchen.
 * Unter "Network Settings" als Work Mode "TCP Server".
 * Unter "Serial Settings" die Einstellungen für den jeweiligen Wechselrichter konfigurieren (oftmals 9600 8N1).
 * Unter "Multi-Host Settings" als Protocol "Modbus TCP to RTU" und "Enable Multi-host" auf "True", wenn auch andere Geräte auf den Wechselrichter zugreifen sollen.


#### Waveshare RS485 To ETH (B) oder Waveshare RS485 To POE ETH (B)
Dieser Wandler kann auf eine Hutschiene montiert werden und wandelt zwischen Modbus/TCP und Modbus/RTU um. Er verfügt nicht über WIFI, dafür aber über einen LAN Anschluss.
Es gibt eine PoE fähige Ausführung. Anscheinend wird der Wandler mit einer statischen IP Einstellung ausgeliefert. Die IP lautet 192.168.1.200. Die Passwort des Webinterfaces lautet admin.
Im [Waveshare Wiki](https://www.waveshare.com/wiki/RS485_TO_ETH_(B)) gibt es weitere Informationen. Weitere Einstellungen können über das VirCom Tool von Waveshare vorgenommen werden.
Dieses Tool ermöglicht es auch die IP Adresse des Wandlers zu ermitteln.

Folgende Einrichtungsschritte sind notwendig:

 * http://192.168.1.200 öffnen, Password admin. Falls nicht erreichbar andere IP suchen.
 * Unter "Network Settings" als Work Mode "TCP Server".
 * Unter "Serial Settings" die Einstellungen für den jeweiligen Wechselrichter konfigurieren (oftmals 9600 8N1).
 * Unter "Multi-Host Settings" als Protocol "Modbus TCP to RTU" und "Enable Multi-host" auf "True", wenn auch andere Geräte auf den Wechselrichter zugreifen sollen.

#### Waveshare RS232/485/422 To ETH (B) oder Waveshare R232/S485/422 To POE ETH (B)

Es gibt eine PoE fähige Ausführung. Anscheinend wird der Wandler mit einer statischen IP Einstellung ausgeliefert. Die IP lautet 192.168.1.200. Die Passwort des Webinterfaces lautet admin.
Im [Waveshare Wiki](https://www.waveshare.com/wiki/RS232/485/422_TO_POE_ETH_(B)) gibt es weitere Informationen. Weitere Einstellungen können über das VirCom Tool von Waveshare vorgenommen werden.
Dieses Tool ermöglicht es auch die IP Adresse des Wandlers zu ermitteln.

Folgende Einrichtungsschritte sind notwendig:

 * http://192.168.1.200 öffnen, Password admin. Falls nicht erreichbar andere IP suchen.
 * Unter "Network Settings" als Work Mode "TCP Server".
 * Unter "Serial Settings" die Einstellungen für den jeweiligen Wechselrichter konfigurieren (oftmals 9600 8N1).
 * Unter "Multi-Host Settings" als Protocol "Modbus TCP to RTU" und "Enable Multi-host" auf "True", wenn auch andere Geräte auf den Wechselrichter zugreifen sollen.


## SMA Speedwire

SMA hat mit Speedwire ein eigenes netzwerkbasiertes Kommunikationsprotokoll. Dieses wird vom Sunny Home Manager, SMA Energy Meter und
manchen Wechselrichtern unterstützt. Mit dieser Schnittstelle kann nur der Netzanschlusszähler gelesen werden.

Hier geht es zu den unterstützten SMA Geräten: [SMA Geräte](/docs/compatible_devices/devices.mdx#sma)

## RCT Power Serial Communication

RCT hat mit der RCT Power Serial Communikation ein netzwerkbasiertes Kommunikationsprotokoll. Dieses wird von Batteriewechselrichtern unterstützt.
Mit dieser Schnittstelle kann ein Netzanschlusszähler und der Batteriespeicher gelesen werden.

Hier geht es zu den unterstützten RCT Geräten: [RCT Geräte](/docs/compatible_devices/devices.mdx#rct)

## API

Die MQTT und HTTP WARP Push API
kann genutzt werden um von extern Zählerdaten dem WARP Charger oder
dem WARP Energy Manager mitzuteilen. Siehe [API Referenz - Meters](/docs/interfaces/mqtt_http/api_reference/meters.mdx).

### 1. API Stromzähler anlegen

Beim Anlegen eines API-Stromzählers können vordefinierte API-Stromzähler (Vorlagen) gewählt werden, welche die benötigten Messwerte anlegen.
Siehe [Webinterface - Stromzähler](/docs/webinterface/energy_management/energy_meters).

:::note

Für das PV-Überschussladen muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
***"Wirk­leistung (Bezug minus Ein­speisung); Σ L1, L2, L3 \[W\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.

:::
:::note

Für das dynamisches Lastmanagement muss ein Stromzähler konfiguriert werden, der mindestens folgenden Wert enthält:
 * ***Strom (Bezug minus Ein­speisung); L1 \[A\]*** bzw. ***Strom (Bezug plus Ein­speisung); L1 \[A\]*** oder ***Strom (Bezug); L1 \[A\]***
 * ***Strom (Bezug minus Ein­speisung); L2 \[A\]*** bzw. ***Strom (Bezug plus Ein­speisung); L2 \[A\]*** oder ***Strom (Bezug); L2 \[A\]***
 * ***Strom (Bezug minus Ein­speisung); L3 \[A\]*** bzw. ***Strom (Bezug plus Ein­speisung); L3 \[A\]*** oder ***Strom (Bezug); L3 \[A\]***

Dieser Wert wird für die Regelung verwendet. Weitere Werte können angelegt werden, sind aber technisch nicht notwendig.
Ob ***"Bezug"***, ***"Bezug minus Einspeisung"***, ***"Bezug plus Einspeisung"*** gewählt werden muss, hängt von dem jeweiligen Stromzähler ab. Dies kann im Zweifelsfall ausprobiert werden.

:::

### 2. Daten an API Stromzähler senden

Abhängig von den angelegten Werten muss der API Stromzähler mit Werten versorgt werden. Dazu dient die Funktion [update](/docs/interfaces/mqtt_http/api_reference/meters#meters_X_update_warp3).
Anstatt **X** muss die jeweilige Nummer des angelegten Stromzähler angegeben werden.

 * [HTTP API](/docs/interfaces/mqtt_http/api_reference/meters?apiType=http#meters_X_update_warp3)
 * [MQTT API](/docs/interfaces/mqtt_http/api_reference/meters?apiType=mqtt#meters_X_update_warp3)

 :::note

Wurde als Beispiel ein API Stromzähler nur mit dem Wert: ***Wirk­leistung (Bezug minus Ein­speisung); Σ L1, L2, L3 \[W\]*** mit der Zählernummer ***1*** angelegt, so kann an diesen der Wert ***234 Watt*** wie folgt gesendet werden:

 * HTTP: *curl http://$HOST/meters/1/update -d 234*
 * MQTT: *mosquitto_pub -h $BROKER -t $PREFIX/meters/1/update -m 234*

:::


## Am WARP Energy Manager angeschlossene Stromzähler

Der WARP Energy Manager kann bestimmte Stromzähler direkt per Modbus/RTU (RS485)
auslesen. Er besitzt dazu einen RS485 Anschluss.
Dies ist vor allem interessant wenn noch kein Zähler am
Netzanschluss vorhanden ist. In dem Fall kann ein WARP Energy Manager installiert
und zusätzlich ein kompatibler Modbus/RTU-Stromzähler an diesem direkt angeschlossen werden.
Von dem WARP Energy Manager werden nicht alle Modbus/RTU Stromzähler unterstützt,
nur die zum WARP Energy Manager in der Liste aufgeführten kompatiblen Stromzähler.
Es kann genau ein Stromzähler per RS485 am WARP Energy Manager angeschlossen und
ausgelesen werden. Mehrere Stromzähler am RS485 Anschluss sind nicht möglich.
