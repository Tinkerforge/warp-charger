from api_doc_common import *

wireguard = Module("wireguard", T({'de': "WireGuard-Verbindung", 'en': "WireGuard Connection"}), "", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der aktuelle WireGuard-Zustand.", 'en': "The current WireGuard state."}), members={
            "state": Elem.INT(T({'de': "Zustand der Verbindung zum WireGuard-Peer", 'en': "State of the connection to the WireGuard peer"}), constants=[
                Const(0, T({'de': "Nicht konfiguriert", 'en': "Not configured"})),
                Const(1, T({'de': "Warte auf Zeitsynchronisierung", 'en': "Waiting for time synchronization"})),
                Const(2, T({'de': "Nicht verbunden", 'en': "Not connected"})),
                Const(3, T({'de': "Verbunden", 'en': "Connected"})),
            ]),
            "connection_start": Elem.INT(T({'de': "Zeit in Millisekunden zu der die letzte Verbindung aufgebaut wurde.", 'en': "Time in milliseconds when the last connection was established."}), unit=Units.ms),
            "connection_end": Elem.INT(T({'de': "Zeit in Millisekunden zu der die letzte Verbindung getrennt wurde.", 'en': "Time in milliseconds when the last connection was disconnected."}), unit=Units.ms)
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die WireGuard-Konfiguration.", 'en': "The WireGuard configuration."}), members={
            "enable": Elem.BOOL(T({'de': "Gibt an ob eine WireGuard-Verbindung zum konfigurierten Peer aufgebaut werden soll.", 'en': "Indicates whether a WireGuard connection to the configured peer should be established."}), constants=[
                Const(True, T({'de': "Wenn WireGuard aktiviert ist.", 'en': "If WireGuard is enabled."})),
                Const(False, T({'de': "Wenn WireGuard deaktiviert ist.", 'en': "If WireGuard is disabled."}))
            ]),
            "make_default_interface": Elem.BOOL(T({'de': "Gibt an ob aller nicht-lokaler Netzwerkverkehr über WireGuard geroutet werden soll.", 'en': "Indicates whether all non-local network traffic should be routed through WireGuard."}), constants=[
                Const(True, T({'de': "Wenn WireGuard das Default-Interface ist: Sämtlicher nicht-lokaler Netzwerkverkehr wird über WireGuard geroutet.", 'en': "If WireGuard is the default interface: All non-local network traffic is routed through WireGuard."})),
                Const(False, T({'de': "Wenn WireGuard nicht das Default-Interface ist: Nur Netzwerkverkehr im WireGuard-Subnetz wird über WireGuard geroutet.", 'en': "If WireGuard is not the default interface: Only network traffic in the WireGuard subnet is routed through WireGuard."}))
            ]),

            "internal_ip": Elem.STRING(T({'de': "IP-Adresse des Geräts im WireGuard-Netzwerk", 'en': "IP address of the device in the WireGuard network"})),
            "internal_subnet": Elem.STRING(T({'de': "Subnetzmaske des WireGuard-Netzwerks", 'en': "Subnet mask of the WireGuard network"})),
            "internal_gateway": Elem.STRING(T({'de': "Gateway des WireGuard-Netzwerks", 'en': "Gateway of the WireGuard network"})),
            "remote_host": Elem.STRING(T({'de': "öffentliche Adresse oder Hostname des Peers zu dem eine WireGuard-Verbindung aufgebaut werden soll", 'en': "Public address or hostname of the peer to which a WireGuard connection should be established"})),
            "remote_port": Elem.INT(T({'de': "Port des Peers zu dem eine WireGuard-Verbindung aufgebaut werden soll", 'en': "Port of the peer to which a WireGuard connection should be established"})),
            "local_port": Elem.INT(T({'de': "Port von dem aus die WireGuard-Verbindung aufgebaut wird", 'en': "Port from which the WireGuard connection is established"})),
            "private_key": Elem.STRING(T({'de': "Privater Schlüssel des Geräts (44 Base64-Zeichen oder leer)", 'en': "Private key of the device (44 Base64 characters or empty)"}), censored=True),
            "remote_public_key": Elem.STRING(T({'de': "Öffentlicher Schlüssel des Peers zu dem eine WireGuard-Verbindung aufgebaut werden soll (44 Base64-Zeichen oder leer)", 'en': "Public key of the peer to which a WireGuard connection should be established (44 Base64 characters or empty)"}), censored=True),
            "preshared_key": Elem.STRING(T({'de': "Geteilter Schlüssel (PSK) der Verbindung zwischen Gerät und Peer (44 Base64-Zeichen oder leer)", 'en': "Preshared key (PSK) of the connection between device and peer (44 Base64 characters or empty)"}), censored=True),
            "allowed_ip": Elem.STRING(T({'de': "Erlaubte Quell-IP von Paketen, die über die WireGuard-Verbindung empfangen werden. 0.0.0.0 damit alle empfangenen Pakete verarbeitet werden", 'en': "Allowed source IP of packets received over the WireGuard connection. 0.0.0.0 to process all received packets"})),
            "allowed_subnet":  Elem.STRING(T({'de': "Erlaubte Subnetzmaske von Paketen, die über die WireGuard-Verbindung empfangen werden. 0.0.0.0 damit alle empfangenen Pakete verarbeitet werden", 'en': "Allowed subnet mask of packets received over the WireGuard connection. 0.0.0.0 to process all received packets"}))
        })
    )
])
