from api_doc_common import *

mqtt = Module("mqtt", T({'de': "MQTT-Verbindung", 'en': "MQTT Connection"}), "", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der aktuelle MQTT-Zustand.", 'en': "The current MQTT state."}), members={
            "connection_state": Elem.INT(T({'de': "Zustand der Verbindung zum MQTT-Broker", 'en': "State of the connection to the MQTT broker"}), constants=[
                Const(0, T({'de': "Nicht konfiguriert", 'en': "Not configured"})),
                Const(1, T({'de': "Nicht verbunden", 'en': "Not connected"})),
                Const(2, T({'de': "Verbunden", 'en': "Connected"})),
                Const(3, T({'de': "Fehler", 'en': "Error"})),
            ]),
            "last_error": Elem.INT(T({'de': "Der zuletzt aufgetretene Fehler. -1 falls kein Fehler aufgetreten ist.", 'en': "The last error that occurred. -1 if no error has occurred."})),
            "connection_start": Elem.INT(T({'de': "Zeit in Millisekunden zu der die letzte Verbindung aufgebaut wurde.", 'en': "Time in milliseconds when the last connection was established."}), unit=Units.ms),
            "connection_end": Elem.INT(T({'de': "Zeit in Millisekunden zu der die letzte Verbindung getrennt wurde.", 'en': "Time in milliseconds when the last connection was disconnected."}), unit=Units.ms)
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die MQTT-Konfiguration.", 'en': "The MQTT configuration."}), members={
            "enable_mqtt": Elem.BOOL(T({'de': "Gibt an, ob eine MQTT-Verbindung zum konfigurierten Broker aufgebaut werden soll.", 'en': "Indicates whether an MQTT connection to the configured broker should be established."}), constants=[
                Const(True, T({'de': "Wenn MQTT aktiviert ist.", 'en': "If MQTT is enabled."})),
                Const(False, T({'de': "Wenn MQTT deaktiviert ist.", 'en': "If MQTT is disabled."}))
            ]),
            "read_only": Elem.BOOL(T({'de': "Gibt an, ob die MQTT-API nur gelesen, oder auch geschrieben werden darf.", 'en': "Indicates whether the MQTT API may only be read or also written."}), constants=[
                Const(True, T({'de': "Wenn die MQTT-API nur gelesen werden darf.", 'en': "If the MQTT API may only be read."})),
                Const(False, T({'de': "Wenn die MQTT-API gelesen und geschrieben werden darf.", 'en': "If the MQTT API may be read and written."}))
            ]),
            "protocol": Elem.INT(T({'de': "Das zu verwendende MQTT-Protokoll", 'en': "The MQTT protocol to use"}), constants=[
                Const(0, T({'de': "MQTT (MQTT über TCP; unverschlüsselt)", 'en': "MQTT (MQTT over TCP; unencrypted)"})),
                Const(1, T({'de': "MQTTS (MQTT über TLS; verschlüsselt)", 'en': "MQTTS (MQTT over TLS; encrypted)"})),
                Const(2, T({'de': "WS (MQTT über WebSocket; unverschlüsselt)", 'en': "WS (MQTT over WebSocket; unencrypted)"})),
                Const(3, T({'de': "WSS (MQTT über WebSocket Secure bzw. MQTT über WebSocket über TLS; verschlüsselt)", 'en': "WSS (MQTT over WebSocket Secure or MQTT over WebSocket over TLS; encrypted)"})),
            ]),
            "broker_host": Elem.STRING(T({'de': "Hostname oder IP-Adresse des MQTT-Brokers, zu dem sich das Gerät verbinden soll.", 'en': "Hostname or IP address of the MQTT broker to which the device should connect."})),
            "broker_port": Elem.INT(T({'de': "Port des MQTT-Brokers zu dem sich das Gerät verbinden soll. Typischerweise 1883.", 'en': "Port of the MQTT broker to which the device should connect. Typically 1883."})),
            "broker_username": Elem.STRING(T({'de': "Username mit dem sich zum Broker verbunden werden soll. Leer falls keine Authentifizierung verwendet wird.", 'en': "Username to use for connecting to the broker. Empty if no authentication is used."})),
            "broker_password": Elem.STRING(T({'de': "Passwort mit dem sich zum Broker verbunden werden soll. Leer falls keine Authentisierung verwendet wird.", 'en': "Password to use for connecting to the broker. Empty if no authentication is used."}), censored=True),
            "global_topic_prefix": Elem.STRING(T({'de': "Präfix der allen MQTT-Topics vorangestellt wird. Normalerweise warp/[UID des Geräts] bzw. warp2/[UID des Geräts].", 'en': "Prefix prepended to all MQTT topics. Normally warp/[device UID] or warp2/[device UID]."})),
            "client_name": Elem.STRING(T({'de': "Name unter dem sich das Gerät beim Broker registriert. <strong>Das ist nicht der Username zur Authentisierung.</strong>", 'en': "Name under which the device registers with the broker. <strong>This is not the username for authentication.</strong>"})),
            "interval": Elem.INT(T({'de': "Minimales Sendeintervall pro Topic in Sekunden. Nachrichten werden grundsätzlich nur verschickt, wenn Änderungen am Payload vorliegen. Durch ein Sendeintervall von x Sekunden wird alle x Sekunden höchstens eine Nachricht eines Topics verschickt. Falls sich der Inhalt in x Sekunden mehrfach ändert wird nur der aktuellste Inhalt übertragen.", 'en': "Minimum send interval per topic in seconds. Messages are only sent when there are changes to the payload. With a send interval of x seconds, at most one message per topic is sent every x seconds. If the content changes multiple times in x seconds, only the most recent content is transmitted."}), unit=Units.s),
            "path": Elem.STRING(T({'de': "Teil der MQTT-über-WS-URL hinter dem Hostnamen. Muss mit / beginnen. Wird ignoriert wenn \"protocol\" 0 oder 1 gewählt sind.", 'en': "Part of the MQTT-over-WS URL after the hostname. Must start with /. Ignored if \"protocol\" 0 or 1 is selected."})),
            "cert_id": Elem.INT(T({'de': "ID des CA-Zertifikats, dass zur Prüfung des Zertifikats des MQTTS bzw. WSS-Servers benutzt wird. Siehe {{{ref:certs/state}}}", 'en': "ID of the CA certificate used to verify the certificate of the MQTTS or WSS server. See {{{ref:certs/state}}}"}), constants=[
                Const(-1, T({'de': "Verwende eingebettetes Zertifikatsbundle", 'en': "Use embedded certificate bundle"})),
                Const(">= 0", T({'de': "Verwende Zertifikat mit dieser ID", 'en': "Use certificate with this ID"}))
            ]),
            "client_cert_id": Elem.INT(T({'de': "ID des Client-Zertifikats, dass zum Aufbau einer TLS-verschlüsselten Verbindung verwendet werden soll. Siehe {{{ref:certs/state}}}", 'en': "ID of the client certificate to be used for establishing a TLS-encrypted connection. See {{{ref:certs/state}}}"}), constants=[
                Const(-1, T({'de': "Nicht verwendet", 'en': "Not used"})),
                Const(">= 0", T({'de': "Verwende Zertifikat mit dieser ID", 'en': "Use certificate with this ID"}))
            ]),
            "client_key_id": Elem.INT(T({'de': "ID des Zertifikats-Keys mit dem das Client-Zertifikat verschlüsselt ist. (Optional) Siehe {{{ref:certs/state}}}", 'en': "ID of the certificate key used to encrypt the client certificate. (Optional) See {{{ref:certs/state}}}"}), constants=[
                Const(-1, T({'de': "Nicht verwendet", 'en': "Not used"})),
                Const(">= 0", T({'de': "Verwende Zertifikat mit dieser ID", 'en': "Use certificate with this ID"}))
            ]),
        })
    ),

    Func("auto_discovery_config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der MQTT Auto Discovery.", 'en': "The MQTT auto discovery configuration."}), version=Version.WARPX, members={
            "auto_discovery_mode": Elem.INT(T({'de': "Gibt an ob eine MQTT-Verbindung zum konfigurierten Broker aufgebaut werden soll.", 'en': "Indicates whether an MQTT connection to the configured broker should be established."}), constants=[
                Const(0, T({'de': "Auto Discovery deaktiviert", 'en': "Auto discovery disabled"})),
                Const(1, T({'de': "Auto Discovery im generischen Modus; Kompatibel zu z.B. openHAB und Domoticz", 'en': "Auto discovery in generic mode; Compatible with e.g. openHAB and Domoticz"})),
                Const(2, T({'de': "Auto Discovery im Home-Assistant-Modus", 'en': "Auto discovery in Home Assistant mode"}))
            ]),
            "auto_discovery_prefix": Elem.STRING(T({'de': "Präfix auf den die für Auto Discovery verwendeten Informationen gesendet werden. Typischerweise homeassistent", 'en': "Prefix to which the information used for auto discovery is sent. Typically homeassistant"}))
        })
    )
])
