from api_doc_common import *

ethernet = Module("ethernet", T({'de': "LAN-Verbindung", 'en': "LAN Connection"}), T({'de': "Benötigt das Feature <a href=\"#features_ethernet\"><code>\"ethernet\"</code></a>.", 'en': "Requires the feature <a href=\"#features_ethernet\"><code>\"ethernet\"</code></a>."}), T({'de': "Mit dem `ethernet`-Modul und passender Hardware kann eine Verbindung zu einem LAN hergestellt werden.", 'en': "The `ethernet` module and appropriate hardware allow connection to a LAN."}), Version.WARP2 | Version.WARP3 | Version.WEMX, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der LAN/Ethernet-Verbindung.", 'en': "The state of the LAN/Ethernet connection."}), members={
            "connection_state": Elem.INT(T({'de': "Verbindungszustand.", 'en': "Connection state."}), constants=[
                Const(0, T({'de': "Nicht konfiguriert", 'en': "Not configured"})),
                Const(1, T({'de': "Nicht verbunden", 'en': "Not connected"})),
                Const(2, T({'de': "Verbinde", 'en': "Connecting"})),
                Const(3, T({'de': "Verbunden", 'en': "Connected"})),
            ]),
            "ip": Elem.STRING(T({'de': "IP des Geräts im verbundenen Netzwerk. 0.0.0.0 falls keine Verbindung besteht.", 'en': "IP of the device in the connected network. 0.0.0.0 if no connection exists."})),
            "subnet": Elem.STRING(T({'de': "Verwendete Subnetzmaske des Geräts im verbundenen Netzwerk. 0.0.0.0 falls keine Verbindung besteht.", 'en': "Subnet mask used by the device in the connected network. 0.0.0.0 if no connection exists."})),
            "full_duplex": Elem.BOOL(T({'de': "true bei einer Full-Duplex-Verbindung, sonst false", 'en': "true for a full-duplex connection, otherwise false"})),
            "link_speed": Elem.INT(T({'de': "Ausgehandelte Verbindungsgeschwindigkeit.", 'en': "Negotiated connection speed."}), unit=Units.Mbps, constants=[
                Const(0, T({'de': "nicht verbunden", 'en': "not connected"})),
                Const(10,""),
                Const(100,""),
            ]),
            "connection_start": Elem.INT(T({'de': "Zeit in Millisekunden zu der zuletzt eine Verbindung aufgebaut wurde.", 'en': "Time in milliseconds when a connection was last established."}), unit=Units.ms),
            "connection_end": Elem.INT(T({'de': "Zeit in Millisekunden zu der zuletzt eine Verbindung getrennt wurde.", 'en': "Time in milliseconds when a connection was last disconnected."}), unit=Units.ms)
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der LAN/Ethernet-Verbindung..", 'en': "The LAN/Ethernet connection configuration."}), members={
            "enable_ethernet": Elem.BOOL(T({'de': "Gibt an ob eine LAN-Verbindung aufgebaut werden soll.", 'en': "Indicates whether a LAN connection should be established."}), constants=[
                Const(True, T({'de': "Wenn eine LAN-Verbindung aufgebaut werden soll.", 'en': "If a LAN connection should be established."})),
                Const(False, T({'de': "Wenn nicht.", 'en': "If not."}))
            ]),
            "ip": Elem.STRING(T({'de': "IP-Adresse, die das Gerät verwenden soll. Dieser Eintrag und die folgenden sind optional und können auf \"0.0.0.0\" gesetzt werden, falls die Addresskonfiguration automatisch per DHCP bezogen werden soll.", 'en': "IP address the device should use. This entry and the following are optional and can be set to \"0.0.0.0\" if the address configuration should be obtained automatically via DHCP."})),
            "gateway": Elem.STRING(T({'de': "Gateway-Adresse, die das Gerät verwenden soll.", 'en': "Gateway address the device should use."})),
            "subnet": Elem.STRING(T({'de': "Subnetzmaske, die das Gerät verwenden soll.", 'en': "Subnet mask the device should use."})),
            "dns": Elem.STRING(T({'de': "DNS-Server-Adresse, die das Gerät verwenden soll.", 'en': "DNS server address the device should use."})),
            "dns2": Elem.STRING(T({'de': "Alternative DNS-Server-Adresse, die das Gerät verwenden soll.", 'en': "Alternative DNS server address the device should use."})),
        })
    ),
])
