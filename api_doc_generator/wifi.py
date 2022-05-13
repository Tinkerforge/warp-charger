from api_doc_common import *

wifi = Module("wifi", "WLAN-Konfiguration", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der aktuelle WLAN-Zustand.", members={
            "connection_state": Elem.INT("Zustand der Verbindung zum konfigurierten WLAN. Siehe {{{ref:wifi/sta_config}}}", constants=[
                Const(0,"Nicht konfiguriert"),
                Const(1,"Nicht verbunden"),
                Const(2,"Verbinde"),
                Const(3,"Verbunden"),
            ]),
            "ap_state": Elem.INT("Zustand des WLAN-Access-Points. Siehe {{{ref:wifi/ap_config}}}", constants=[
                Const(0,"Deaktiviert"),
                Const(1,"Aktiviert"),
                Const(2,"Fallback inaktiv"),
                Const(3,"Fallback aktiv"),
            ]),
            "ap_bssid": Elem.STRING("BSSID des WLAN-Access-Points."),
            "sta_ip": Elem.STRING("Aktuelle IP der Wallbox im konfigurierten Netz. 0.0.0.0 falls keine Verbindung besteht."),
            "sta_rssi": Elem.INT("Die aktuelle Empfangsqualität. 0 falls keine Verbindung besteht, sonst negativ. Werte näher 0 entsprechen einem besseren Empfang."),
            "sta_bssid": Elem.STRING("Die BSSID der Gegenstelle, zu der die Wallbox verbunden ist."),
        })
    ),

    Func("scan", FuncType.COMMAND, Elem.NULL("Löst einen Scan nach WLANs aus. Die Scan-Ergebnisse können derzeit nur über HTTP abgefragt werden."), command_is_action=True),

    Func("sta_config", FuncType.CONFIGURATION, Elem.OBJECT("Die WLAN-Verbindungskonfiguration. Diese kann über wifi/sta_config_update mit dem selben Payload aktualisiert werden.", members={
            "enable_sta": Elem.BOOL("Gibt an ob eine WLAN-Verbindung zum konfigurierten Netzwerk aufgebaut werden soll.", constants=[
                Const(True, "Wenn eine WLAN-Verbindung aufgebaut werden soll."),
                Const(False, "Wenn nicht.")
            ]),
            "ssid": Elem.STRING("SSID zu der sich verbunden werden soll."),
            "bssid": Elem.ARRAY("BSSID zu der sich verbunden werden soll. Dieser Eintrag ist optional und kann leer übergeben werden, wird aber für das bssid_lock benötigt.", members=[
                * 6 * [Elem.INT("")]
            ]),
            "bssid_lock": Elem.BOOL("Legt fest, ob sich nur zum WLAN mit der gesetzten BSSID verbunden werden soll. Deaktiviert lassen, falls Repeater o.Ä. verwendet werden sollen.", constants=[
                Const(True, "Verbindet sich nur zum Access Point mit der übergebenen BSSID."),
                Const(False, "Verbindet sich nur zu jedem Access Point mit der konfigurierten SSID, z.B. mit Repeatern.")
            ]),
            "passphrase": Elem.STRING("Die WLAN-Passphrase. Maximal 63 Byte. Dieser Eintrag ist optional und kann leer übergeben werden, falls sich zu einem unverschlüsselten WLAN verbunden werden soll.", censored=True),
            "ip": Elem.STRING("IP-Adresse, die die Wallbox im konfigurierten Netz verwenden soll. Dieser Eintrag und die folgenden sind optional und können als \"0.0.0.0\" übergeben werden, falls die automatische IP-Adressvergabe (DHCP) verwendet werden soll."),
            "gateway": Elem.STRING("Gateway-Adresse, die die Wallbox im konfigurierten Netz verwenden soll."),
            "subnet": Elem.STRING("Subnetzmaske, die die Wallbox im konfigurierten Netz verwenden soll."),
            "dns": Elem.STRING("DNS-Server-Adresse, die die Wallbox im konfigurierten Netz verwenden soll."),
            "dns2": Elem.STRING("Alternative DNS-Server-Adresse, die die Wallbox im konfigurierten Netz verwenden soll."),
        })
    ),

    Func("ap_config", FuncType.CONFIGURATION, Elem.OBJECT("Die WLAN-Access-Point-Konfiguration. Diese kann über wifi/ap_config_update mit dem selben Payload aktualisiert werden. <strong>Achtung! Wenn der Access Point deaktiviert wird, und die WLAN-Verbindung bzw. LAN-Verbindung nicht aufgebaut werden kann, bzw. nicht konfiguriert wurde, kann der ESP nur noch durch einen Factory-Reset erreicht werden!</strong> Wir empfehlen, den Access Point immer im Fallback-Modus zu belassen.", members={
            "enable_ap": Elem.BOOL("Gibt an ob der Access Point aktiviert werden soll.", constants=[
                Const(True, "Der AP soll aktiviert werden. Ggfalls. nur als Fallback (siehe ap_fallback_only)"),
                Const(False, "Der AP soll immer deaktiviert bleiben.")
            ]),
            "ap_fallback_only": Elem.BOOL("Gibt an ob der Access Point nur aktiviert werden soll, falls die WLAN- und LAN-Verbindungen nicht aufgebaut werden können. Wird ignoriert, falls enable_ap false ist.", constants=[
                Const(True, "Der AP soll nur aktiviert werden, falls die WLAN- und LAN-Verbindungen nicht aufgebaut werden können."),
                Const(False, "Der AP soll immer aktiviert bleiben.")
            ]),
            "ssid": Elem.STRING("SSID zu der sich verbunden werden soll."),
            "hide_ssid": Elem.BOOL("true falls die SSID versteckt werden soll, ansonsten false."),
            "passphrase": Elem.STRING("Die WLAN-Passphrase. Maximal 63 Byte.", censored=True),
            "channel": Elem.INT("Kanal, auf dem der Access Point erreichbar sein soll. Gültige Werte sind 1 bis 13 und 0, falls beim Start ein möglichst unbelegter Kanal ausgewählt werden soll."),
            "ip": Elem.STRING("IP-Adresse, die die Wallbox im konfigurierten Netz verwenden soll. Dieser Eintrag und die folgenden sind optional und können als \"0.0.0.0\" übergeben werden, falls die automatische IP-Adressvergabe (DHCP) verwendet werden soll."),
            "gateway": Elem.STRING("Gateway-Adresse, die die Wallbox im konfigurierten Netz verwenden soll."),
            "subnet": Elem.STRING("Subnetzmaske, die die Wallbox im konfigurierten Netz verwenden soll."),
        })
    ),

    Func("scan_results", FuncType.HTTP_ONLY, Elem.OPAQUE("Die WLANs, die aufgrund einer durch wifi/scan ausgelösten Suche gefunden wurden. Ein Array aus Objekten des folgenden Formats:" +
            Elem.OBJECT("", members={
            "ssid": Elem.STRING("SSID des gefundenen WLANs. Leer bei versteckten Access Points."),
            "bssid": Elem.STRING("BSSID des gefundenen WLANs."),
            "rssi": Elem.INT('Die Empfangsqualität des gefundenen WLANs. Immer ein negativer Wert, wobei Werte nahe 0 eine bessere Empfangsqualität bedeuten. <a href="https://de.wikipedia.org/wiki/Received_Signal_Strength_Indication">Siehe hier für Details.</a>'),
            "channel": Elem.INT('Kanal des gefundenen WLANs.'),
            "encryption": Elem.INT("Verschlüsselungsstandard des gefundenen WLANs", constants=[
                Const(0, "Unverschlüsselt"),
                Const(1, "WEP"),
                Const(2, "WPA-PSK"),
                Const(3, "WPA2-PSK"),
                Const(4, "WPA/WPA2-PSK"),
                Const(5, "WPA2-Enterprise"),
                Const(6, "Unbekannt")
            ])
        }).to_html_table(True)
    ))
])
