from api_doc_common import *

wireguard = Module("wireguard", "WireGuard-Verbindung", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der aktuelle WireGuard-Zustand.", members={
            "state": Elem.INT("Zustand der Verbindung zum WireGuard-Peer", constants=[
                Const(0, "Nicht konfiguriert"),
                Const(1, "Warte auf Zeitsynchronisierung"),
                Const(2, "Nicht verbunden"),
                Const(3, "Verbunden"),
            ]),
            "connection_start": Elem.INT("Zeit in Millisekunden zu der die letzte Verbindung aufgebaut wurde.", unit=Units.ms),
            "connection_end": Elem.INT("Zeit in Millisekunden zu der die letzte Verbindung getrennt wurde.", unit=Units.ms)
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die WireGuard-Konfiguration. Diese kann über wireguard/config_update mit dem selben Payload aktualisiert werden.", members={
            "enable": Elem.BOOL("Gibt an ob eine WireGuard-Verbindung zum konfigurierten Peer aufgebaut werden soll.", constants=[
                Const(True, "Wenn WireGuard aktiviert ist."),
                Const(False, "Wenn WireGuard deaktiviert ist.")
            ]),
            "make_default_interface": Elem.BOOL("Gibt an ob aller nicht-lokaler Netzwerkverkehr über WireGuard geroutet werden soll.", constants=[
                Const(True, "Wenn WireGuard das Default-Interface ist: Sämtlicher nicht-lokaler Netzwerkverkehr wird über WireGuard geroutet."),
                Const(False, "Wenn WireGuard nicht das Default-Interface ist: Nur Netzwerkverkehr im WireGuard-Subnetz wird über WireGuard geroutet.")
            ]),

            "internal_ip": Elem.STRING("IP-Adresse der Wallbox im WireGuard-Netzwerk"),
            "internal_subnet": Elem.STRING("Subnetzmaske des WireGuard-Netzwerks"),
            "internal_gateway": Elem.STRING("Gateway des WireGuard-Netzwerks"),
            "remote_host": Elem.STRING("öffentliche Adresse oder Hostname des Peers zu dem eine WireGuard-Verbindung aufgebaut werden soll"),
            "remote_port": Elem.INT("Port des Peers zu dem eine WireGuard-Verbindung aufgebaut werden soll"),
            "private_key": Elem.STRING("Privater Schlüssel der Wallbox (44 Base64-Zeichen oder leer)", censored=True),
            "remote_public_key": Elem.STRING("Öffentlicher Schlüssel des Peers zu dem eine WireGuard-Verbindung aufgebaut werden soll (44 Base64-Zeichen oder leer)", censored=True),
            "preshared_key": Elem.STRING("Geteilter Schlüssel (PSK) der Verbindung zwischen Wallbox und Peer (44 Base64-Zeichen oder leer)", censored=True),
            "allowed_ip": Elem.STRING("Erlaubte Quell-IP von Paketen, die über die WireGuard-Verbindung empfangen werden. 0.0.0.0 damit alle empfangenen Pakete verarbeitet werden"),
            "allowed_subnet":  Elem.STRING("Erlaubte Subnetzmaske von Paketen, die über die WireGuard-Verbindung empfangen werden. 0.0.0.0 damit alle empfangenen Pakete verarbeitet werden")
        })
    )
])
