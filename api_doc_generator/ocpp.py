from api_doc_common import *

ocpp = Module("ocpp", T({'de': "OCPP-Verbindung", 'en': "OCPP Connection"}), "", "", Version.WARP2 | Version.WARP3, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguration der OCPP-Verbindung", 'en': "OCPP connection configuration"}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob eine Verbindung zum konfigurierten OCPP-Server aufgebaut werden soll. Damit nicht nur das Auslesen des Zustands, sondern zusätzlich eine Steuerung möglich ist, muss außerdem {{{ref:evse/ocpp_enabled}}} true sein.", 'en': "Indicates whether a connection to the configured OCPP server should be established. For control functionality in addition to state readout, {{{ref:evse/ocpp_enabled}}} must also be true."})),
        "url": Elem.STRING(T({'de': "Endpoint-URL des OCPP-Servers. Muss mit dem Schema ws:// (unverschlüsselt!) oder wss:// (TLS-verschlüsselt) beginnen und darf <strong>nicht</strong> auf / enden.", 'en': "Endpoint URL of the OCPP server. Must start with the scheme ws:// (unencrypted!) or wss:// (TLS-encrypted) and must <strong>not</strong> end with /."})),
        "identity": Elem.STRING(T({'de': "Identität der Wallbox. Wird an die Endpoint-URL angehangen und als Benutzername für die Autorisierung verwendet", 'en': "Identity of the charger. Appended to the endpoint URL and used as username for authorization"})),
        "enable_auth": Elem.BOOL(T({'de': "Gibt an, dass eine Autorisierung per HTTP-Basic-Auth durchgeführt werden soll.", 'en': "Indicates that authorization via HTTP Basic Auth should be performed."})),
        "pass": Elem.STRING(T({'de': "HTTP-Basic-Auth Passwort. Wenn das Passwort exakt 40 Zeichen lang ist und nur aus Hex-Zeichen (0-9, A-F, a-f) besteht, wird es als hexadezimale Repräsentation eines 20 Byte langen Authorization-Keys betrachtet.", 'en': "HTTP Basic Auth password. If the password is exactly 40 characters long and consists only of hex characters (0-9, A-F, a-f), it is treated as a hexadecimal representation of a 20-byte authorization key."}), censored=True),
        "cert_id": Elem.INT(T({'de': "ID des TLS-Zertifikats, dass zum Aufbau einer TLS-verschlüsselten Verbindung verwendet werden soll.", 'en': "ID of the TLS certificate to be used for establishing a TLS-encrypted connection."}), constants=[
                Const(-1, T({'de': "Verwende eingebettetes Zertifikatsbundle", 'en': "Use embedded certificate bundle"})),
                Const(">= 0", T({'de': "Verwende Zertifikat mit dieser ID", 'en': "Use certificate with this ID"}))
            ]),
    })),
    Func("reset", FuncType.COMMAND, Elem.NULL(T({'de': "Setzt den OCPP-Zustand zurück. <strong>Nicht gesendete Transaktionsdaten gehen verloren!</strong>", 'en': "Resets the OCPP state. <strong>Unsent transaction data will be lost!</strong>"})))
])
