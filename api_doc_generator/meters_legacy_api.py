from api_doc_common import *

meters_legacy_api = Module("meters_legacy_api", "Konfiguration der emulierten veralteten Stromzähler-API", "", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der emulierten veralteten Stromzähler-API", members={
        "writable": Elem.BOOL("Gibt an, ob die veraltete Stromzähler-API geschrieben werden kann. Das ist nur der Fall, wenn der unter {{{ref:meters_legacy_api/config}}} als `linked_meter_slot` eingetragene Stromzähler ein Stromzähler ist, der in seiner {{{ref:meters/X/config}}} als API-Zähler konfiguriert ist.")
    })),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der emulierten veralteten Stromzähler-API", members={
        "linked_meter_slot": Elem.INT("Stromzähler, auf den die emulierte veraltete Stromzähler-API abgebildet werden soll")
    }))
])
