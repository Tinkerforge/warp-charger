from api_doc_common import *

info = Module("info", "Allgemeine Informationen", "", Version.ANY, [
Func("version", FuncType.STATE, Elem.OBJECT("Version der Wallbox-Firmware.", members={
            "firmware": Elem.STRING("Die Firmware-Version, die aktuell ausgeführt wird."),
            "config": Elem.STRING("Die Version der Konfiguration, die aktuell verwendet wird."),
        })
    ),

    Func("modules", FuncType.STATE, Elem.OPAQUE("Initialisierungszustand der Firmware-Module.")),
    Func("features", FuncType.STATE, Elem.OPAQUE("Unterstützte Hardwarefeatures. Siehe <a class=\"scrollto\" href=\"#features_section\">Features</a> für Details.")),
    Func("name", FuncType.STATE, Elem.OBJECT("Name und Typ der Wallbox", members={
            "name": Elem.STRING("Der Name der Wallbox. Besteht aus Typ und UID der Wallbox."),
            "type": Elem.STRING("Typ der Wallbox.", constants=[
                Const("warp", "Ein WARP Charger"),
                Const("warp2", "Ein WARP2 Charger"),
            ]),
            "display_type": Elem.STRING("Benutzerlesbarer Typ der Wallbox. Gibt neben der Hardware-Version die Variante (Smart, Pro), die maximale Ladeleistung und eventuelle Upgrades an. z.B. \"WARP2 Charger Pro 11kW +NFC\""),
            "uid": Elem.STRING("UID der Wallbox bzw. des verbauten ESP (Ethernet) Bricks.")
        })
    ),
    Func("display_name", FuncType.CONFIGURATION, Elem.OBJECT("Benutzerlesbarer Name der Wallbox. Kann über info/display_name_update mit dem selben Payload gesetzt werden.", members={
            "display_name": Elem.STRING("Der Anzeigename.")
        })
    )
])
