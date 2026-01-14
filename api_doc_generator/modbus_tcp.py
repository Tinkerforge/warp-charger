from api_doc_common import *

modbus_tcp = Module("modbus_tcp", U("Modbus/TCP"), "", "", Version.WARPX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguration des Modbus/TCP-Servers", 'en': "Modbus/TCP server configuration"}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob der Modbus/TCP-Server aktiv ist. Damit nicht nur das Auslesen des Zustands, sondern zusätzlich eine Steuerung möglich ist, muss außerdem {{{ref:evse/modbus_tcp_enabled}}} true sein.", 'en': "Indicates whether the Modbus/TCP server is active. For control functionality in addition to state readout, {{{ref:evse/modbus_tcp_enabled}}} must also be true."})),
        "port": Elem.INT(T({'de': "Port auf dem der Modbus/TCP-Server auf eingehende Verbindungen wartet. Typischerweise 502.", 'en': "Port on which the Modbus/TCP server listens for incoming connections. Typically 502."})),
        "table": Elem.INT(T({'de': "Registertabelle, die vom Modbus/TCP-Server verwendet wird.", 'en': "Register table used by the Modbus/TCP server."}), constants=[
            Const(0, T({'de': "WARP-Charger-Registertabelle", 'en': "WARP Charger register table"})),
            Const(1, T({'de': "Registertabelle kompatibel zu Bender CC612/613", 'en': "Register table compatible with Bender CC612/613"})),
            Const(2, T({'de': "Registertabelle kompatibel zu Keba C-Series", 'en': "Register table compatible with Keba C-Series"})),
        ]),
        "send_illegal_data_address": Elem.BOOL(T({'de': "Gibt an, ob der Modbus/TCP-Server IllegalDataAddress-Fehler schickt, wenn unbekannte Register gelesen werden", 'en': "Indicates whether the Modbus/TCP server sends IllegalDataAddress errors when unknown registers are read"}), constants=[
            Const(True, T({'de': "Der Server antwortet mit einem IllegalDataAddress-Fehler, wenn ein unbekanntes Register gelesen wird.", 'en': "The server responds with an IllegalDataAddress error when an unknown register is read."})),
            Const(False, T({'de': "Der Server antwortet mit dem Wert 0, wenn ein unbekanntes Register gelesen wird.", 'en': "The server responds with value 0 when an unknown register is read."})),
        ]),
    }))
])
