from api_doc_common import *

ocpp = Module("ocpp", "OCPP-Verbindung", "", Version.WARP2, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration der OCPP-Verbindung", members={
        "enable": Elem.BOOL("Gibt an, ob eine Verbindung zum konfigurierten OCPP-Server aufgebaut werden soll. Damit nicht nur das Auslesen des Zustands, sondern zusätzlich eine Steuerung möglich ist, muss außerdem {{{ref:evse/ocpp_enabled}}} true sein."),
        "url": Elem.STRING("Endpoint-URL des OCPP-Servers. Muss mit dem Schema ws:// (unverschlüsselt!) oder wss:// (TLS-Verschlüsselt) beginnen und darf <strong>nicht</strong> auf / enden."),
        "identity": Elem.STRING("Identität der Wallbox. Wird an die Endpoint-URL angehangen und als Benutzername für die Autorisierung verwendet"),
        "enable_auth": Elem.BOOL("Gibt an, dass eine Autorisierung per HTTP-Basic-Auth durchgeführt werden soll."),
        "pass": Elem.STRING("HTTP-Basic-Auth Passwort. Wenn das Passwort exakt 40 Zeichen lang ist und nur aus Hex-Zeichen (0-9, A-F, a-f) besteht, wird es als hexadezimale Repräsentation eines 20 Byte langen Authorization-Keys betrachtet.", censored=True)
    })),
    Func("reset", FuncType.COMMAND, Elem.NULL("Setzt den OCPP-Zustand zurück. <strong>Nicht gesendete Transaktionsdaten gehen verloren!</strong>"))
])
