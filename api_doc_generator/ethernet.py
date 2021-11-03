from api_doc_common import *

ethernet = Module("ethernet", "LAN-Verbindung", "", Version.WARP2_ONLY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der aktuelle LAN-Zustand.", members={
            "connection_state": Elem.INT("Zustand der Verbindung zum konfigurierten LAN.", constants=[
                Const(0,"Nicht konfiguriert"),
                Const(1,"Nicht verbunden"),
                Const(2,"Verbinde"),
                Const(3,"Verbunden"),
            ]),
            "ip": Elem.ARRAY("Aktuelle IP der Wallbox im konfigurierten Netz. 0.0.0.0 falls keine Verbindung besteht.", members=[
                * 4 * [Elem.INT("")]
            ]),
            "full_duplex": Elem.BOOL("true bei einer Full-Duplex-Verbindung, sonst false"),
            "link_speed": Elem.INT("Ausgehandelte Verbindungsgeschwindigkeit.", unit=Units.Mbps, constants=[
                Const(10,""),
                Const(100,""),
            ])
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die LAN-Verbindungskonfiguration. Diese kann über ethernet/config_update mit dem selben Payload aktualisiert werden.", members={
            "enable_ethernet": Elem.BOOL("Gibt an ob eine LAN-Verbindung zum konfigurierten Netzwerk aufgebaut werden soll.", constants=[
                Const(True, "Wenn eine LAN-Verbindung aufgebaut werden soll."),
                Const(False, "Wenn nicht.")
            ]),
            "hostname": Elem.STRING("Hostname den die Wallbox im konfigurierten Netz verwenden soll."),
            "ip": Elem.ARRAY("IP-Adresse, die die Wallbox im konfigurierten Netz verwenden soll. Dieser Eintrag und die folgenden sind optional und können als [0, 0, 0, 0] übergeben werden, falls die automatische IP-Adressvergabe (DHCP) verwendet werden soll.", members=[
                * 4 * [Elem.INT("")]
            ]),
            "gateway": Elem.ARRAY("Gateway-Adresse, die die Wallbox im konfigurierten Netz verwenden soll.", members=[
                * 4 * [Elem.INT("")]
            ]),
            "subnet": Elem.ARRAY("Subnetzmaske, die die Wallbox im konfigurierten Netz verwenden soll.", members=[
                * 4 * [Elem.INT("")]
            ]),
            "dns": Elem.ARRAY("DNS-Server-Adresse, die die Wallbox im konfigurierten Netz verwenden soll.", members=[
                * 4 * [Elem.INT("")]
            ]),
            "dns2": Elem.ARRAY("Alternative DNS-Server-Adresse, die die Wallbox im konfigurierten Netz verwenden soll.", members=[
                * 4 * [Elem.INT("")]
            ]),
        })
    ),
])
