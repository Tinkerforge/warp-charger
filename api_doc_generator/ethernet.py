from api_doc_common import *

ethernet = Module("ethernet", "LAN-Verbindung", "Benötigt das Feature <a href=\"#features_ethernet\"><code>\"ethernet\"</code></a>.", "Mit dem `ethernet`-Modul und passender Hardware kann eine Verbindung zu einem LAN hergestellt werden.", Version.WARP2 | Version.WARP3 | Version.WEM, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der LAN/Ethernet-Verbindung.", members={
            "connection_state": Elem.INT("Verbindungszustand.", constants=[
                Const(0,"Nicht konfiguriert"),
                Const(1,"Nicht verbunden"),
                Const(2,"Verbinde"),
                Const(3,"Verbunden"),
            ]),
            "ip": Elem.STRING("IP des Geräts im verbundenen Netzwerk. 0.0.0.0 falls keine Verbindung besteht."),
            "subnet": Elem.STRING("Verwendete Subnetzmaske des Geräts im verbundenen Netzwerk. 0.0.0.0 falls keine Verbindung besteht."),
            "full_duplex": Elem.BOOL("true bei einer Full-Duplex-Verbindung, sonst false"),
            "link_speed": Elem.INT("Ausgehandelte Verbindungsgeschwindigkeit.", unit=Units.Mbps, constants=[
                Const(0,"nicht verbunden"),
                Const(10,""),
                Const(100,""),
            ]),
            "connection_start": Elem.INT("Zeit in Millisekunden zu der zuletzt eine Verbindung aufgebaut wurde.", unit=Units.ms),
            "connection_end": Elem.INT("Zeit in Millisekunden zu der zuletzt eine Verbindung getrennt wurde.", unit=Units.ms)
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der LAN/Ethernet-Verbindung..", members={
            "enable_ethernet": Elem.BOOL("Gibt an ob eine LAN-Verbindung aufgebaut werden soll.", constants=[
                Const(True, "Wenn eine LAN-Verbindung aufgebaut werden soll."),
                Const(False, "Wenn nicht.")
            ]),
            "ip": Elem.STRING("IP-Adresse, die das Gerät verwenden soll. Dieser Eintrag und die folgenden sind optional und können auf \"0.0.0.0\" gesetzt werden, falls die Addresskonfiguration automatisch per DHCP bezogen werden soll."),
            "gateway": Elem.STRING("Gateway-Adresse, die das Gerät verwenden soll."),
            "subnet": Elem.STRING("Subnetzmaske, die das Gerät verwenden soll."),
            "dns": Elem.STRING("DNS-Server-Adresse, die das Gerät verwenden soll."),
            "dns2": Elem.STRING("Alternative DNS-Server-Adresse, die das Gerät verwenden soll."),
        })
    ),
])
