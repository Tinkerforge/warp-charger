from api_doc_common import *

ethernet = Module("ethernet", "LAN-Verbindung", "Benötigt das Feature <a href=\"#features_ethernet\"><code>\"ethernet\"</code></a>.", Version.WARP2 | Version.WARPEM, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der aktuelle LAN-Zustand.", members={
            "connection_state": Elem.INT("Zustand der Verbindung zum konfigurierten LAN.", constants=[
                Const(0,"Nicht konfiguriert"),
                Const(1,"Nicht verbunden"),
                Const(2,"Verbinde"),
                Const(3,"Verbunden"),
            ]),
            "ip": Elem.STRING("Aktuelle IP der Wallbox im konfigurierten Netz. 0.0.0.0 falls keine Verbindung besteht."),
            "subnet": Elem.STRING("Aktuelle Subnetzmaske der Wallbox im konfigurierten Netz. 0.0.0.0 falls keine Verbindung besteht."),
            "full_duplex": Elem.BOOL("true bei einer Full-Duplex-Verbindung, sonst false"),
            "link_speed": Elem.INT("Ausgehandelte Verbindungsgeschwindigkeit.", unit=Units.Mbps, constants=[
                Const(0,"nicht verbunden"),
                Const(10,""),
                Const(100,""),
            ]),
            "connection_start": Elem.INT("Zeit in Millisekunden zu der die letzte Verbindung aufgebaut wurde.", unit=Units.ms),
            "connection_end": Elem.INT("Zeit in Millisekunden zu der die letzte Verbindung getrennt wurde.", unit=Units.ms)
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die LAN-Verbindungskonfiguration. Diese kann über ethernet/config_update mit dem selben Payload aktualisiert werden.", members={
            "enable_ethernet": Elem.BOOL("Gibt an ob eine LAN-Verbindung zum konfigurierten Netzwerk aufgebaut werden soll.", constants=[
                Const(True, "Wenn eine LAN-Verbindung aufgebaut werden soll."),
                Const(False, "Wenn nicht.")
            ]),
            "ip": Elem.STRING("IP-Adresse, die die Wallbox im konfigurierten Netz verwenden soll. Dieser Eintrag und die folgenden sind optional und können als \"0.0.0.0\" übergeben werden, falls die automatische IP-Adressvergabe (DHCP) verwendet werden soll."),
            "gateway": Elem.STRING("Gateway-Adresse, die die Wallbox im konfigurierten Netz verwenden soll."),
            "subnet": Elem.STRING("Subnetzmaske, die die Wallbox im konfigurierten Netz verwenden soll."),
            "dns": Elem.STRING("DNS-Server-Adresse, die die Wallbox im konfigurierten Netz verwenden soll."),
            "dns2": Elem.STRING("Alternative DNS-Server-Adresse, die die Wallbox im konfigurierten Netz verwenden soll."),
        })
    ),
])
