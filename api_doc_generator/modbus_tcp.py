from api_doc_common import *

modbus_tcp = Module("modbus_tcp", "Modbus/TCP", "", "", Version.CHARGER, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration des Modbus/TCP-Servers", members={
        "enable": Elem.BOOL("Gibt an, ob der Modbus/TCP-Server aktiv ist. Damit nicht nur das Auslesen des Zustands, sondern zusätzlich eine Steuerung möglich ist, muss außerdem {{{ref:evse/modbus_tcp_enabled}}} true sein."),
        "port": Elem.INT("Port auf dem der Modbus/TCP-Server auf eingehende Verbindungen wartet. Typischerweise 502."),
        "table": Elem.INT("Registertabelle, die vom Modbus/TCP-Server verwendet wird.", constants=[
            Const(0, "WARP-Charger-Registertabelle"),
            Const(1, "Registertabelle kompatibel zu Bender CC612/613"),
            Const(2, "Registertabelle kompatibel zu Keba C-Series"),
        ]),
        "send_illegal_data_address": Elem.BOOL("Gibt an, ob der Modbus/TCP-Server IllegalDataAddress-Fehler schickt, wenn unbekannte Register gelesen werden", constants=[
            Const(True, "Der Server antwortet mit einem IllegalDataAddress-Fehler, wenn ein unbekanntes Register gelesen wird."),
            Const(False, "Der Server antwortet mit dem Wert 0, wenn ein unbekanntes Register gelesen wird."),
        ]),
    }))
])
