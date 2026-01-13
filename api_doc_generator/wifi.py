from api_doc_common import *

wifi = Module("wifi", T({'de': "WLAN-Konfiguration", 'en': "Wi-Fi Configuration"}), "", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der aktuelle WLAN-Zustand.", 'en': "The current Wi-Fi state."}), members={
            "connection_state": Elem.INT(T({'de': "Zustand der Verbindung zum konfigurierten WLAN. Siehe {{{ref:wifi/sta_config}}}", 'en': "State of the connection to the configured Wi-Fi. See {{{ref:wifi/sta_config}}}"}), constants=[
                Const(0, T({'de': "Nicht konfiguriert", 'en': "Not configured"})),
                Const(1, T({'de': "Nicht verbunden", 'en': "Not connected"})),
                Const(2, T({'de': "Verbinde", 'en': "Connecting"})),
                Const(3, T({'de': "Verbunden", 'en': "Connected"})),
            ]),
            "ap_state": Elem.INT(T({'de': "Zustand des WLAN-Access-Points. Siehe {{{ref:wifi/ap_config}}}", 'en': "State of the Wi-Fi access point. See {{{ref:wifi/ap_config}}}"}), constants=[
                Const(0, T({'de': "Deaktiviert", 'en': "Disabled"})),
                Const(1, T({'de': "Aktiviert", 'en': "Enabled"})),
                Const(2, T({'de': "Fallback inaktiv", 'en': "Fallback inactive"})),
                Const(3, T({'de': "Fallback aktiv", 'en': "Fallback active"})),
            ]),
            "ap_bssid": Elem.STRING(T({'de': "BSSID des WLAN-Access-Points.", 'en': "BSSID of the Wi-Fi access point."})),
            "ap_sta_count": Elem.INT(T({'de': "Anzahl der aktuell zum WLAN-Access-Point verbundenen Geräte.", 'en': "Number of devices currently connected to the Wi-Fi access point."})),
            "sta_ip": Elem.STRING(T({'de': "Aktuelle IP des Geräts im konfigurierten Netz. 0.0.0.0 falls keine Verbindung besteht.", 'en': "Current IP of the device in the configured network. 0.0.0.0 if no connection exists."})),
            "sta_subnet": Elem.STRING(T({'de': "Aktuelle Subnetzmaske des Geräts im konfigurierten Netz. 0.0.0.0 falls keine Verbindung besteht.", 'en': "Current subnet mask of the device in the configured network. 0.0.0.0 if no connection exists."})),
            "sta_rssi": Elem.INT(T({'de': "Die aktuelle Empfangsqualität. 0 falls keine Verbindung besteht, sonst negativ. Werte näher 0 entsprechen einem besseren Empfang.", 'en': "The current reception quality. 0 if no connection exists, otherwise negative. Values closer to 0 indicate better reception."})),
            "sta_bssid": Elem.STRING(T({'de': "Die BSSID der Gegenstelle, zu der das Gerät verbunden ist.", 'en': "The BSSID of the remote station to which the device is connected."})),
            "connection_start": Elem.INT(T({'de': "Zeit in Millisekunden, zu der die letzte Verbindung aufgebaut wurde.", 'en': "Time in milliseconds when the last connection was established."}), unit=Units.ms),
            "connection_end": Elem.INT(T({'de': "Zeit in Millisekunden, zu der die letzte Verbindung getrennt wurde.", 'en': "Time in milliseconds when the last connection was disconnected."}), unit=Units.ms)
        })
    ),

    Func("scan", FuncType.COMMAND, Elem.NULL(T({'de': "Löst einen Scan nach WLANs aus. Die Scan-Ergebnisse können derzeit nur über HTTP abgefragt werden.", 'en': "Triggers a scan for Wi-Fi networks. The scan results can currently only be queried via HTTP."})), command_is_action=True),

    Func("sta_config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die WLAN-Verbindungskonfiguration.", 'en': "The Wi-Fi connection configuration."}), members={
            "enable_sta": Elem.BOOL(T({'de': "Gibt an, ob eine WLAN-Verbindung zum konfigurierten Netzwerk aufgebaut werden soll.", 'en': "Indicates whether a Wi-Fi connection to the configured network should be established."}), constants=[
                Const(True, T({'de': "Wenn eine WLAN-Verbindung aufgebaut werden soll.", 'en': "If a Wi-Fi connection should be established."})),
                Const(False, T({'de': "Wenn nicht.", 'en': "If not."}))
            ]),
            "ssid": Elem.STRING(T({'de': "SSID, zu der sich verbunden werden soll.", 'en': "SSID to which the device should connect."})),
            "bssid": Elem.ARRAY(T({'de': "BSSID, zu der sich verbunden werden soll. Dieser Eintrag ist optional und kann leer übergeben werden, wird aber für das bssid_lock benötigt.", 'en': "BSSID to which the device should connect. This entry is optional and can be left empty, but is required for bssid_lock."}), members=[
                * 6 * [Elem.INT("")]
            ]),
            "bssid_lock": Elem.BOOL(T({'de': "Legt fest, ob sich nur zum WLAN mit der gesetzten BSSID verbunden werden soll. Deaktiviert lassen, falls Repeater o.Ä. verwendet werden sollen.", 'en': "Specifies whether to connect only to the Wi-Fi network with the specified BSSID. Leave disabled if repeaters or similar should be used."}), constants=[
                Const(True, T({'de': "Verbindet sich nur zum Access Point mit der übergebenen BSSID.", 'en': "Connects only to the access point with the specified BSSID."})),
                Const(False, T({'de': "Verbindet sich zu jedem Access Point mit der konfigurierten SSID, z.B. mit Repeatern.", 'en': "Connects to any access point with the configured SSID, e.g., with repeaters."}))
            ]),
            "enable_11b": Elem.BOOL(T({'de': "Legt fest, ob der veraltete und langsame [802.11b-Modus](https://de.wikipedia.org/wiki/Wireless_Local_Area_Network#IEEE_802.11b) verwendet werden darf. Dieser verlangsamt auch andere Geräte, die zum WLAN verbunden sind, kann aber die Empfangsqualität und Robustheit der Verbindung leicht verbessern.", 'en': "Specifies whether the outdated and slow [802.11b mode](https://en.wikipedia.org/wiki/IEEE_802.11b-1999) may be used. This also slows down other devices connected to the Wi-Fi, but can slightly improve reception quality and connection robustness."}), constants=[
                Const(True, T({'de': "Erlaube Verwendung des 802.11b-Modus", 'en': "Allow use of 802.11b mode"})),
                Const(False, T({'de': "Verbiete Verwendung des 802.11b-Modus", 'en': "Forbid use of 802.11b mode"}))
            ]),
            "passphrase": Elem.STRING(T({'de': "Die WLAN-Passphrase. Maximal 63 Byte. Dieser Eintrag ist optional und kann leer übergeben werden, falls sich zu einem unverschlüsselten WLAN verbunden werden soll.", 'en': "The Wi-Fi passphrase. Maximum 63 bytes. This entry is optional and can be left empty if connecting to an unencrypted Wi-Fi network."}), censored=True),
            "ip": Elem.STRING(T({'de': "IP-Adresse, die das Gerät im konfigurierten Netz verwenden soll. Dieser Eintrag und die folgenden sind optional und können als \"0.0.0.0\" übergeben werden, falls die automatische IP-Adressvergabe (DHCP) verwendet werden soll.", 'en': "IP address the device should use in the configured network. This entry and the following are optional and can be passed as \"0.0.0.0\" if automatic IP address assignment (DHCP) should be used."})),
            "gateway": Elem.STRING(T({'de': "Gateway-Adresse, die das Gerät im konfigurierten Netz verwenden soll.", 'en': "Gateway address the device should use in the configured network."})),
            "subnet": Elem.STRING(T({'de': "Subnetzmaske, die das Gerät im konfigurierten Netz verwenden soll.", 'en': "Subnet mask the device should use in the configured network."})),
            "dns": Elem.STRING(T({'de': "DNS-Server-Adresse, die das Gerät im konfigurierten Netz verwenden soll.", 'en': "DNS server address the device should use in the configured network."})),
            "dns2": Elem.STRING(T({'de': "Alternative DNS-Server-Adresse, die das Gerät im konfigurierten Netz verwenden soll.", 'en': "Alternative DNS server address the device should use in the configured network."})),
            "wpa_eap_config": Elem.UNION(T({'de': "WPA-Enterprise-Konfiguration", 'en': "WPA Enterprise configuration"}), members={
                0: Elem.NULL(T({'de': "WPA Personal", 'en': "WPA Personal"})),
                1: Elem.OBJECT(T({'de': "EAP-TLS", 'en': "EAP-TLS"}), members={
                    "ca_cert_id": Elem.INT(T({'de': "ID des CA-Zertifikats, das zur Prüfung des Zertifikats des RADIUS-Servers genutzt wird. Siehe {{{ref:certs/state}}}", 'en': "ID of the CA certificate used to verify the RADIUS server's certificate. See {{{ref:certs/state}}}"})),
                    "identity": Elem.STRING(T({'de': "Anonyme Identität für dem Verbindungsaufbau zum RADIUS-Server. (Optional) [Siehe hier für Details](https://security.stackexchange.com/a/201848)", 'en': "Anonymous identity for connection establishment to the RADIUS server. (Optional) [See here for details](https://security.stackexchange.com/a/201848)"})),
                    "client_cert_id": Elem.INT(T({'de': "ID des Client-Zertifikats, mit dem sich beim RADIUS-Server autorisiert werden soll. (Optional) Siehe {{{ref:certs/state}}}", 'en': "ID of the client certificate used for authorization with the RADIUS server. (Optional) See {{{ref:certs/state}}}"})),
                    "client_key_id": Elem.INT(T({'de': "ID des Zertifikats-Keys, mit dem das Client-Zertifikat verschlüsselt ist. (Optional) Siehe {{{ref:certs/state}}}", 'en': "ID of the certificate key used to encrypt the client certificate. (Optional) See {{{ref:certs/state}}}"})),
                }),
                2: Elem.OBJECT(T({'de': "EAP-PEAP oder EAP-TTLS", 'en': "EAP-PEAP or EAP-TTLS"}), members={
                    "ca_cert_id": Elem.INT(T({'de': "ID des CA-Zertifikats, das zur Prüfung des Zertifikats des RADIUS-Servers genutzt wird. Siehe {{{ref:certs/state}}}", 'en': "ID of the CA certificate used to verify the RADIUS server's certificate. See {{{ref:certs/state}}}"})),
                    "identity": Elem.STRING(T({'de': "Anonyme Identität für dem Verbindungsaufbau zum RADIUS-Server. (Optional) [Siehe hier für Details](https://security.stackexchange.com/a/201848)", 'en': "Anonymous identity for connection establishment to the RADIUS server. (Optional) [See here for details](https://security.stackexchange.com/a/201848)"})),
                    "username": Elem.STRING(T({'de': "Benutzername", 'en': "Username"})),
                    "password": Elem.STRING(T({'de': "Passwort", 'en': "Password"}), censored=True),
                    "client_cert_id": Elem.INT(T({'de': "ID des Client-Zertifikats, mit dem sich beim RADIUS-Server autorisiert werden soll. (Optional) Siehe {{{ref:certs/state}}}", 'en': "ID of the client certificate used for authorization with the RADIUS server. (Optional) See {{{ref:certs/state}}}"})),
                    "client_key_id": Elem.INT(T({'de': "ID des Zertifikats-Keys, mit dem das Client-Zertifikat verschlüsselt ist. (Optional) Siehe {{{ref:certs/state}}}", 'en': "ID of the certificate key used to encrypt the client certificate. (Optional) See {{{ref:certs/state}}}"})),
                }),
            })
        })
    ),

    Func("ap_config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die WLAN-Access-Point-Konfiguration. <strong>Achtung! Wenn der Access Point deaktiviert wird, und die WLAN-Verbindung bzw. LAN-Verbindung nicht aufgebaut werden kann, bzw. nicht konfiguriert wurde, kann der ESP nur noch durch einen Factory-Reset erreicht werden!</strong> Wir empfehlen, den Access Point immer im Fallback-Modus zu belassen.", 'en': "The Wi-Fi access point configuration. <strong>Warning! If the access point is disabled and the Wi-Fi connection or LAN connection cannot be established or was not configured, the ESP can only be reached via a factory reset!</strong> We recommend always leaving the access point in fallback mode."}), members={
            "enable_ap": Elem.BOOL(T({'de': "Gibt an, ob der Access Point aktiviert werden soll.", 'en': "Indicates whether the access point should be enabled."}), constants=[
                Const(True, T({'de': "Der AP soll aktiviert werden. Ggfalls. nur als Fallback (siehe ap_fallback_only)", 'en': "The AP should be enabled. Possibly only as fallback (see ap_fallback_only)"})),
                Const(False, T({'de': "Der AP soll immer deaktiviert bleiben.", 'en': "The AP should always remain disabled."}))
            ]),
            "ap_fallback_only": Elem.BOOL(T({'de': "Gibt an, ob der Access Point nur aktiviert werden soll, falls die WLAN- und LAN-Verbindungen nicht aufgebaut werden können. Wird ignoriert, falls enable_ap false ist.", 'en': "Indicates whether the access point should only be enabled if Wi-Fi and LAN connections cannot be established. Ignored if enable_ap is false."}), constants=[
                Const(True, T({'de': "Der AP soll nur aktiviert werden, falls die WLAN- und LAN-Verbindungen nicht aufgebaut werden können.", 'en': "The AP should only be enabled if Wi-Fi and LAN connections cannot be established."})),
                Const(False, T({'de': "Der AP soll immer aktiviert bleiben.", 'en': "The AP should always remain enabled."}))
            ]),
            "ssid": Elem.STRING(T({'de': "SSID, zu der sich verbunden werden soll.", 'en': "SSID to which devices should connect."})),
            "hide_ssid": Elem.BOOL(T({'de': "true falls die SSID versteckt werden soll, ansonsten false.", 'en': "true if the SSID should be hidden, otherwise false."})),
            "passphrase": Elem.STRING(T({'de': "Die WLAN-Passphrase. Maximal 63 Byte.", 'en': "The Wi-Fi passphrase. Maximum 63 bytes."}), censored=True),
            "channel": Elem.INT(T({'de': "Kanal, auf dem der Access Point erreichbar sein soll. Gültige Werte sind 1 bis 13 oder 0, falls beim Start ein möglichst unbelegter Kanal ausgewählt werden soll.", 'en': "Channel on which the access point should be accessible. Valid values are 1 to 13, or 0 if an unoccupied channel should be selected at startup."})),
            "ip": Elem.STRING(T({'de': "IP-Adresse, die das Gerät im konfigurierten Netz verwenden soll. Dieser Eintrag und die folgenden sind optional und können als \"0.0.0.0\" übergeben werden, falls die automatische IP-Adressvergabe (DHCP) verwendet werden soll.", 'en': "IP address the device should use in the configured network. This entry and the following are optional and can be passed as \"0.0.0.0\" if automatic IP address assignment (DHCP) should be used."})),
            "gateway": Elem.STRING(T({'de': "Gateway-Adresse, die das Gerät im konfigurierten Netz verwenden soll.", 'en': "Gateway address the device should use in the configured network."})),
            "subnet": Elem.STRING(T({'de': "Subnetzmaske, die das Gerät im konfigurierten Netz verwenden soll.", 'en': "Subnet mask the device should use in the configured network."})),
        })
    ),

    Func("scan_results", FuncType.HTTP_ONLY, Elem.ARRAY(T({'de': "Die WLANs, die aufgrund einer durch wifi/scan ausgelösten Suche gefunden wurden.", 'en': "The Wi-Fi networks found as a result of a search triggered by wifi/scan."}), is_var_length_array=True, members=[
            Elem.OBJECT("", members={
            "ssid": Elem.STRING(T({'de': "SSID des gefundenen WLANs. Leer bei versteckten Access Points.", 'en': "SSID of the found Wi-Fi network. Empty for hidden access points."})),
            "bssid": Elem.STRING(T({'de': "BSSID des gefundenen WLANs.", 'en': "BSSID of the found Wi-Fi network."})),
            "rssi": Elem.INT(T({'de': 'Die Empfangsqualität des gefundenen WLANs. Immer ein negativer Wert, wobei Werte nahe 0 eine bessere Empfangsqualität bedeuten. [Siehe hier für Details](https://de.wikipedia.org/wiki/Received_Signal_Strength_Indication)', 'en': 'The reception quality of the found Wi-Fi network. Always a negative value, where values close to 0 indicate better reception quality. [See here for details](https://en.wikipedia.org/wiki/Received_signal_strength_indication)'})),
            "channel": Elem.INT(T({'de': 'Kanal des gefundenen WLANs.', 'en': 'Channel of the found Wi-Fi network.'})),
            "encryption": Elem.INT(T({'de': "Verschlüsselungsstandard des gefundenen WLANs", 'en': "Encryption standard of the found Wi-Fi network"}), constants=[
                Const(0, T({'de': "Unverschlüsselt", 'en': "Unencrypted"})),
                Const(1, "WEP"),
                Const(2, "WPA-PSK"),
                Const(3, "WPA2-PSK"),
                Const(4, "WPA/WPA2-PSK"),
                Const(5, "WPA2-Enterprise"),
                Const(6, T({'de': "Unbekannt", 'en': "Unknown"}))
            ])
            })
    ]))
])
