from api_doc_common import *

info = Module("info", T({'de': "Allgemeine Informationen", 'en': "General Information"}), "", "", Version.ANY, [
    Func("version", FuncType.STATE, Elem.OBJECT(T({'de': "Version der aktuell ausgeführten Firmware.", 'en': "Version of the currently running firmware."}), members={
            "firmware": Elem.STRING(T({'de': "Die Firmware-Version, die aktuell ausgeführt wird. Siehe [Semantic Versioning](https://semver.org/)-Format.", 'en': "The firmware version currently running. See [Semantic Versioning](https://semver.org/) format."})),
            "config": Elem.STRING(T({'de': "Die Version der Konfiguration, die aktuell verwendet wird.", 'en': "The version of the configuration currently in use."})),
            "config_type": Elem.STRING(T({'de': "Typ der auf diesem Gerät gespeicherten Konfiguration.", 'en': "Type of configuration stored on this device."})),
        })
    ),

    Func("modules", FuncType.STATE, Elem.OPAQUE(T({'de': "Initialisierungszustand der Firmware-Module.", 'en': "Initialization state of firmware modules."}))),
    Func("features", FuncType.STATE, Elem.OPAQUE(T({'de': "Unterstützte Hardwarefeatures. Siehe <a class=\"scrollto\" href=\"#features_section\">Features</a> für Details.", 'en': "Supported hardware features. See <a class=\"scrollto\" href=\"#features_section\">Features</a> for details."}))),
    Func("name", FuncType.STATE, Elem.OBJECT(T({'de': "Name und Typ des Geräts", 'en': "Name and type of the device"}), members={
            "name": Elem.STRING(T({'de': "Der Name des Geräts. Besteht aus Typ und UID des Geräts.", 'en': "The name of the device. Consists of the type and UID of the device."})),
            "type": Elem.STRING(T({'de': "Typ des Geräts.", 'en': "Type of the device."}), constants=[
                Const("warp", T({'de': "Ein WARP Charger", 'en': "A WARP Charger"})),
                Const("warp2", T({'de': "Ein WARP2 Charger", 'en': "A WARP2 Charger"})),
                Const("warp3", T({'de': "Ein WARP3 Charger", 'en': "A WARP3 Charger"})),
                Const("wem", T({'de': "Ein WARP Energy Manager", 'en': "A WARP Energy Manager"})),
            ]),
            "display_type": Elem.STRING(T({'de': "Benutzerlesbarer Typ des Geräts. Gibt neben der Hardware-Version die Variante (Smart, Pro), die maximale Ladeleistung und eventuelle Upgrades an, z.B. \"WARP2 Charger Pro 11kW +NFC\"", 'en': "User-readable type of the device. Indicates the hardware version, variant (Smart, Pro), maximum charging power, and any upgrades, e.g., \"WARP2 Charger Pro 11kW +NFC\""})),
            "uid": Elem.STRING(T({'de': "UID des Geräts bzw. des verbauten ESP (Ethernet) Bricks.", 'en': "UID of the device or the installed ESP (Ethernet) Brick."}))
        })
    ),
    Func("display_name", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Benutzerlesbarer Name des Geräts.", 'en': "User-readable name of the device."}), members={
            "display_name": Elem.STRING(T({'de': "Der Anzeigename.", 'en': "The display name."}))
        })
    ),

    Func("last_boots", FuncType.STATE, Elem.ARRAY(T({'de': "Debug-Informationen über die letzten Firmware-Ausführungen", 'en': "Debug information about the last firmware executions"}),  members=[
                * 10 * [Elem.OBJECT(T({'de': "Debug-Informationen über eine Firmware-Ausführung", 'en': "Debug information about a firmware execution"}), members = {
            "reset_reason": Elem.INT(T({'de': "Grund des Neustarts. Siehe [Espressif-Dokumentation](https://docs.espressif.com/projects/esp-idf/en/v4.4.3/esp32/api-reference/system/system.html?highlight=esp_reset_reason#_CPPv418esp_reset_reason_t).", 'en': "Reason for the restart. See [Espressif documentation](https://docs.espressif.com/projects/esp-idf/en/v4.4.3/esp32/api-reference/system/system.html?highlight=esp_reset_reason#_CPPv418esp_reset_reason_t)."})),
            "boot_count": Elem.INT(T({'de': "Zähler der angibt, der wievielte Neustart seit dem das Gerät vom Strom getrennt wurde, durchgeführt wird. Ein Eintrag in last_boots wird erst fünf Minuten nach dem Start des Geräts geschrieben um den Flash zu schonen. Falls innerhalb der ersten fünf Minuten neugestartet wird, kann ein Eintrag verloren gehen, was anhand dieses Zählers bemerkt werden kann.", 'en': "Counter indicating which restart since the device was disconnected from power is being performed. An entry in last_boots is only written five minutes after device startup to preserve flash memory. If a restart occurs within the first five minutes, an entry may be lost, which can be noticed by this counter."})),
            "uptime": Elem.INT(T({'de': "Laufzeit der Firmware-Ausführung (32-Bit).", 'en': "Runtime of the firmware execution (32-bit)."}), unit=Units.ms),
            "uptime_overflows": Elem.INT(T({'de': "Anzahl der Überläufe von uptime.", 'en': "Number of uptime overflows."})),
            "timestamp_min": Elem.INT(T({'de': "Unix-Timestamp in Minuten der Firmware-Ausführung.", 'en': "Unix timestamp in minutes of the firmware execution."}))
            })]
        ])
    ),
])
