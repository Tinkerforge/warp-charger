from api_doc_common import *

meters_legacy_api = Module("meters_legacy_api", T({'de': "Konfiguration der emulierten veralteten Stromzähler-API", 'en': "Configuration of the Emulated Legacy Electricity Meter API"}), "", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der emulierten veralteten Stromzähler-API", 'en': "The state of the emulated legacy electricity meter API"}), members={
        "writable": Elem.BOOL(T({'de': "Gibt an, ob die veraltete Stromzähler-API geschrieben werden kann. Das ist nur der Fall, wenn der unter {{{ref:meters_legacy_api/config}}} als `linked_meter_slot` eingetragene Stromzähler ein Stromzähler ist, der in seiner {{{ref:meters/X/config}}} als API-Zähler konfiguriert ist.", 'en': "Indicates whether the legacy electricity meter API can be written to. This is only the case if the meter entered under {{{ref:meters_legacy_api/config}}} as `linked_meter_slot` is a meter configured as an API meter in its {{{ref:meters/X/config}}}."}))
    })),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der emulierten veralteten Stromzähler-API", 'en': "The configuration of the emulated legacy electricity meter API"}), members={
        "linked_meter_slot": Elem.INT(T({'de': "Stromzähler, auf den die emulierte veraltete Stromzähler-API abgebildet werden soll", 'en': "Meter to which the emulated legacy electricity meter API should be mapped"}))
    }))
])
