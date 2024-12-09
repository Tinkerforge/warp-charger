from api_doc_common import *

day_ahead_prices = Module("day_ahead_prices", "Dynamische Strompreise", "", "Über das `day_ahead_prices`-Modul können dynamische Strompreise konfiguriert und ausgelesen werden.", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der dynamischen Strompreise.", members={
        "enable": Elem.BOOL("Gibt an, ob dynamische Strompreise verwendet werden sollen. Wenn aktiviert, werden die Preise einmal pro Tag für die nächsten 24 Stunden von einem externen Server abgerufen. Um dynamische Strompreise nutzen zu können wird ein Internetzugang benötigt."),
        "api_url":  Elem.STRING(""),
        "region":  Elem.INT("", constants=[
            Const(0, "DE"),
            Const(1, "AT"),
            Const(2, "LU"),
        ]),
        "resolution":  Elem.INT("", constants=[
            Const(0, "15 Minuten"),
            Const(1, "60 Minuten"),
        ]),
        "cert_id":  Elem.INT(""),
        "vat":  Elem.INT(""),
        "grid_costs_and_taxes":  Elem.INT(""),
        "supplier_markup":  Elem.INT(""),
        "supplier_base_fee":  Elem.INT(""),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der dynamischen Strompreise.", members={
        "last_sync": Elem.INT(""),
        "last_check": Elem.INT(""),
        "next_check": Elem.INT(""),
        "current_price": Elem.INT(""),
    })),

    Func("prices", FuncType.STATE, Elem.OBJECT("Die dynamischen Strompreise.", members={
        "first_date":  Elem.INT(""),
        "resolution":  Elem.INT(""),
        "prices": Elem.ARRAY("", members=[* 25*4*2 * [Elem.INT("")]])
    })),
])
