from api_doc_common import *

meters_legacy_api = Module("meters_legacy_api", "Konfiguration der emulierten veralteten Stromzähler-API", "", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der emulierten veralteten Stromzähler-API", members={
        "writable": Elem.BOOL("Gibt an, ob die veraltete Stromzähler-API geschrieben werden kann.")
    })),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der emulierten veralteten Stromzähler-API", members={
        "linked_meter_slot": Elem.INT("Stromzähler, auf den die emulierte veraltete Stromzähler-API abgebildet werden soll")
    }))
])
