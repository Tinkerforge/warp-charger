---
sidebar_position: 2
---

# Netzwerk-Konfiguration

Beim WARP3 Charger Basic können nach der elektrischen Installation keine
weiteren Einstellungen vorgenommen werden. Die nachfolgende Beschreibung
bezieht sich daher nur auf die Smart- bzw. Pro-Variante des WARP
Chargers.

Um weitere Einstellungen durchführen zu können, muss zuerst eine
Verbindung zur Wallbox hergestellt werden, damit diese über das
Webinterface mittels Webbrowser konfiguriert werden kann.

## Schritt 1: Verbindung zur Wallbox herstellen

### Option 1: WLAN

Im Werkszustand öffnet die Wallbox einen WLAN-Access-Point. Über diesen
kann die Konfiguration der Wallbox vorgenommen werden, indem auf das
Webinterface der Wallbox zugegriffen wird.

Die Zugangsdaten des Access-Points finden sich auf dem
WLAN-Zugangsdaten-Aufkleber auf der Rückseite der Betriebsanleitung. Es kann
entweder der QR-Code des Aufklebers, der das WLAN automatisch
konfiguriert, oder die SSID und Passphrase verwendet werden. Die meisten
Kamera-Apps von Smartphones unterstützen das Auslesen des QR-Codes und
das automatische Verbinden mit dem WLAN. Viele Smartphones erkennen,
dass über den Access-Point der Wallbox kein Zugriff auf das Internet
möglich ist. Deshalb muss gegebenenfalls die mobile Datenverbindung
(z.B. LTE) deaktiviert werden, oder eine Nachfrage, ob die Verbindung
zum Access-Point der Wallbox getrennt werden soll, verneint werden.

Wenn die Verbindung mit dem Access-Point der Wallbox hergestellt ist,
kann das Webinterface unter [http://10.0.0.1](http://10.0.0.1) über einen beliebigen
Browser erreicht werden. Alternativ kann dazu der nebenstehende QR-Code
gescannt werden.

### Option 2: LAN

Wenn ein LAN-Kabel eingesteckt wird verbindet sich die Wallbox
automatisch mit einem kabelgebundenen Netzwerk, (IP-Address-Bezug per
DHCP). Die Wallbox kann dann entweder über die zugewiesene IP Adresse
http://[IP-der-Wallbox], z.B.
http://192.168.0.42 oder den Hostnamen der Wallbox
http://[hostname], z.B. http://warp3-ABC erreicht werden.

Der Hostname der Wallbox ist identisch zur SSID des WLAN-Access-Points.
Der Hostnamen findet sich auf dem WLAN-Zugangsdaten-Aufkleber auf der
Rückseite dieser Anleitung.

Kann die per DHCP an die Wallbox vergebene IP nicht ermittelt werden, so
kann der zuvor genannte Zugriff auf das Webinterface über den
WLAN-Access-Point genutzt werden, um die IP-Adresse der
LAN-Schnittstelle zu ermitteln.

## Schritt 2: Integration in das eigene Netzwerk

Die Wallbox kann per WLAN oder LAN in ein Netzwerk eingebunden werden.
Im Menüpunkt Netzwerk finden sich alle Einstellungsmöglichkeiten:

![image](/img/first_steps/network_config_with_menu.png)


Unter Einstellungen kann der Hostname des WARP3 Chargers in allen verbundenen
Netzwerken konfiguriert werden. Außerdem kann mDNS aktiviert oder
deaktiviert werden. Über mDNS können andere Geräte im Netzwerk den WARP3
Charger finden. Damit wird zum Beispiel das Einrichten eines
Lastmanagementverbunds vereinfacht. Zusätzlich kann der Port, auf dem
das Webinterface erreichbar ist, geändert werden (Standard ist Port 80).

### WLAN-Verbindung

Eine Möglichkeit, um die Wallbox in ein Netzwerk zu integrieren, ist
mittels WLAN. Durch Drücken des "Netzwerksuche"-Buttons öffnet sich ein
Menü, in dem das gewünschte WLAN ausgewählt werden kann.

![image](/img/first_steps/network_wifi_search.png)

Es werden dann
automatisch Netzwerkname (SSID) und BSSID eingetragen, sowie die
Verbindung beim Neustart aktiviert. Gegebenenfalls muss jetzt noch die
Passphrase des gewählten Netzes eintragen werden.

![image](/img/first_steps/network_wifi.png)

Die Konfiguration kann jetzt mit dem Speichern-Button abgespeichert
werden. Das Webinterface startet dann neu und verbindet sich mit dem
konfigurierten WLAN. Die Statusseite zeigt an, ob die Verbindung
erfolgreich war. Der Access-Point bleibt weiterhin geöffnet, sodass
Konfigurationsfehler behoben werden können. Da der Access-Point den
gleichen Kanal wie ein eventuell verbundenes Netz verwendet, kann es
sein, dass die Verbindung zum Access-Point neu aufgebaut werden muss.

Bei einer erfolgreichen Verbindung sollte die Wallbox jetzt im
konfigurierten Netzwerk unter
http://[konfigurierter_hostname, z.B. http://warp3-ABC erreichbar sein.

### WLAN-Access-Point

Der Access-Point kann in einem von zwei Modi betrieben werden: Entweder
kann er immer aktiv sein oder nur dann, wenn die Verbindung zu einem
anderen WLAN bzw. zu einem LAN nicht konfiguriert oder fehlgeschlagen
ist. Außerdem kann der Access-Point komplett deaktiviert werden.

![image](/img/first_steps/network_wifi_ap.png)

Wir empfehlen, den Access-Point nie komplett zu deaktivieren, da sonst
bei einer fehlgeschlagenen Verbindung zu einem anderen Netzwerk das
Webinterface nicht mehr erreicht werden kann. Die Wallbox kann dann nur
über den Wiederherstellungsmodus oder ein
Zurücksetzen auf Werkszustand erreicht werden.

Der Modus des Access-Points, Netzwerkname, Passphrase usw. können hier
festgelegt werden.

### LAN-Verbindung

Alternativ zur WLAN-Verbindung kann die Wallbox auch per LAN
kabelgebunden ins Netzwerk integriert werden. In den meisten Fällen wird
eine LAN-Verbindung automatisch hergestellt, falls ein Kabel eingesteckt
ist (IP-Adresse wird per DHCP bezogen). Es ist aber auch möglich, eine
statische IP-Konfiguration einzutragen, oder, falls gewünscht, die
LAN-Verbindung komplett zu deaktivieren.

![image](/img/first_steps/network_lan.png)

Bei einer erfolgreichen Verbindung sollte die Wallbox jetzt im LAN unter
http://[konfigurierter_hostname], z.B. http://warp3-ABC erreichbar sein.

Die LAN- und WLAN-Verbindung sollten nicht gleichzeitig zum selben
Netzwerk bzw. IP-Bereich verbunden sein, da es sonst zu
Verbindungsproblemen kommen kann.

### WireGuard

Mit WireGuard kann die Wallbox mittels einer verschlüsselten Verbindung
in ein virtuelles privates Netzwerk (VPN) eingebunden werden. WireGuard
wird von verschiedenen Routern direkt unterstützt. Das VPN kann zum
Beispiel genutzt werden, um aus der Ferne auf die Wallboxen zuzugreifen,
das Wallbox-Netzwerk vor einem Zugriff zu schützen oder das
Lastmanagement zwischen den Wallboxen abzusichern.

Die notwendigen Parameter sind WireGuard-spezifisch und werden an dieser
Stelle nicht gesondert erläutert. Weitere Informationen finden sich auf
https://www.wireguard.com.

![image](/img/first_steps/network_wireguard.png)

Ist die Wallbox per WLAN (Accesspoint) oder LAN mittels Browser
erreichbar, kann die weitere Konfiguration durchgeführt werden. Das
Webinterface ist im Abschnitt vollständig beschrieben.

## Schritt 3: Firmware-Aktualisierung

Generell empfehlen wir, nach der Installation ein Update der
Wallbox-Firmware durchzuführen, um die neusten Funktionen und ggf.
Bugfixes zu erhalten. Siehe [Firmware-Aktualisierung](firmware_update).