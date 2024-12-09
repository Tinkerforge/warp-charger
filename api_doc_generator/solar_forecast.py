from api_doc_common import *

solar_forecast = Module("solar_forecast", "PV-Ertragsprogrnose", "", "Über das `solar_forecast`-Modul kann eine PV-Ertragsprognose konfiguriert und ausgelesen werden.", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der PV-Ertragsprognose.", members={
        "enable": Elem.BOOL("Gibt an, ob die PV-Ertragsprognose verwendet werden soll."),
        "api_url": Elem.STRING(""),
        "cert_id": Elem.INT(""),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der PV-Ertragsprognose.", members={
        "rate_limit": Elem.INT(""),
        "rate_remaining": Elem.INT(""),
        "next_api_call": Elem.INT(""),
    })),

    Func("planes/X/state", FuncType.STATE, Elem.OBJECT("", members={
            "last_sync": Elem.INT(""),
            "last_check": Elem.INT(""),
            "next_check": Elem.INT(""),
            "place": Elem.STRING(""),
        })
    ),

    Func("planes/X/config", FuncType.CONFIGURATION, Elem.OBJECT("", members={
        "enable": Elem.BOOL(""),
        "name": Elem.STRING(""),
        "lat": Elem.INT(""),
        "long": Elem.INT(""),
        "dec": Elem.INT(""),
        "az": Elem.INT(""),
        "wp": Elem.INT(""),
    })),

    Func("planes/X/forecast", FuncType.STATE, Elem.OBJECT("", members={
        "first_date": Elem.INT(""),
        "resolution": Elem.INT(""),
        "forecast": Elem.ARRAY("", members=49 * [Elem.INT("")])
    })),
])
