from api_doc_common import *

info = Module("info", "Allgemeine Informationen", "", "", Version.ANY, [
    Func("version", FuncType.STATE, Elem.OBJECT("Version der Wallbox-Firmware.", members={
            "firmware": Elem.STRING("Die Firmware-Version, die aktuell ausgeführt wird."),
            "config": Elem.STRING("Die Version der Konfiguration, die aktuell verwendet wird."),
            "config_type": Elem.STRING("Typ der auf diesem Gerät gespeicherten Konfiguration."),
        })
    ),

    Func("modules", FuncType.STATE, Elem.OPAQUE("Initialisierungszustand der Firmware-Module.")),
    Func("features", FuncType.STATE, Elem.OPAQUE("Unterstützte Hardwarefeatures. Siehe <a class=\"scrollto\" href=\"#features_section\">Features</a> für Details.")),
    Func("name", FuncType.STATE, Elem.OBJECT("Name und Typ der Wallbox", members={
            "name": Elem.STRING("Der Name der Wallbox. Besteht aus Typ und UID der Wallbox."),
            "type": Elem.STRING("Typ der Wallbox.", constants=[
                Const("warp", "Ein WARP Charger"),
                Const("warp2", "Ein WARP2 Charger"),
                Const("warp3", "Ein WARP3 Charger"),
                Const("wem", "Ein WARP Energy Manager"),
            ]),
            "display_type": Elem.STRING("Benutzerlesbarer Typ der Wallbox. Gibt neben der Hardware-Version die Variante (Smart, Pro), die maximale Ladeleistung und eventuelle Upgrades an. z.B. \"WARP2 Charger Pro 11kW +NFC\""),
            "uid": Elem.STRING("UID der Wallbox bzw. des verbauten ESP (Ethernet) Bricks.")
        })
    ),
    Func("display_name", FuncType.CONFIGURATION, Elem.OBJECT("Benutzerlesbarer Name der Wallbox.", members={
            "display_name": Elem.STRING("Der Anzeigename.")
        })
    ),

    Func("last_boots", FuncType.STATE, Elem.ARRAY("Debug-Informationen über die letzten Firmware-Ausführungen",  members=[
                * 10 * [Elem.OBJECT("Debug-Informationen über eine Firmware-Ausführung", members = {
            "reset_reason": Elem.INT("Grund des Neustarts. Siehe <a href=\"https://docs.espressif.com/projects/esp-idf/en/v4.4.3/esp32/api-reference/system/system.html?highlight=esp_reset_reason#_CPPv418esp_reset_reason_t\">Espressif-Dokumentation</a>"),
            "boot_count": Elem.INT("Zähler der angibt, der wievielte Neustart seit dem die Wallbox vom Strom getrennt wurde, durchgeführt wird. Ein Eintrag in last_boots wird erst fünf Minuten nach dem Start der Wallbox geschrieben um den Flash zu schonen. Falls innerhalb der ersten fünf Minuten neugestartet wird, kann ein Eintrag verloren gehen, was anhand dieses Zählers bemerkt werden kann"),
            "uptime": Elem.INT("Laufzeit der Firmware-Ausführung (32-Bit).", unit=Units.ms),
            "uptime_overflows": Elem.INT("Anzahl der Überläufe von uptime."),
            "timestamp_min": Elem.INT("Unix-Timestamp in Minuten der Firmware-Ausführung.")
            })]
        ])
    ),
])
