from api_doc_common import *

day_ahead_prices = Module("day_ahead_prices", "Dynamische Strompreise", "", "Über das `day_ahead_prices`-Modul können dynamische Strompreise konfiguriert und ausgelesen werden.", Version.WARP2 | Version.WARP3 | Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der dynamischen Strompreise.", members={
        "enable": Elem.BOOL("Gibt an, ob dynamische Strompreise verwendet werden sollen. Wenn aktiviert, werden die Preise einmal pro Tag für die nächsten 24 Stunden von einem externen Server abgerufen. Um dynamische Strompreise nutzen zu können wird ein Internetzugang benötigt."),
        "api_url":  Elem.STRING("Endpoint-URL des Servers für dynamische Strompreise."),
        "region":  Elem.INT("Gebiet der dynmischen Strompreise", constants=[
            Const(0, "DE"),
            Const(1, "AT"),
            Const(2, "LU"),
        ]),
        "resolution":  Elem.INT("Auflösung der dynamischen Strompreise.", constants=[
            Const(0, "15 Minuten"),
            Const(1, "60 Minuten"),
        ]),
        "cert_id":  Elem.INT("ID des CA-Zertifikats, dass zur Prüfung des Zertifikats des RADIUS-Servers genutzt wird. Siehe {{{ref:certs/state}}}."),
        "vat":  Elem.INT("Mehrwersteuersatz der auf den Börsenstrompreis anfällt.", unit=Units.hundredth_percent),
        "grid_costs_and_taxes":  Elem.INT("Netzentgelte und Steuern (brutto falls MwSt-Satz angegeben ist).", unit=Units.thousands_cent_per_kWh),
        "supplier_markup":  Elem.INT("Stromanbieter Preisaufschlag (brutto falls MwSt-Satz angegeben ist).", unit=Units.thousands_cent_per_kWh),
        "supplier_base_fee":  Elem.INT("Stromanbieter Grundgebühr", unit=Units.ct_per_month),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der dynamischen Strompreise.", members={
        "last_sync": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt wann die Börsenstrompreise das letzte Mal aktualisiert wurden."),
        "last_check": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt wann die Börsenstrompreise das letzte Mal abgefragt wurden."),
        "next_check": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt wann die Börsenstrompreise das nächste Mal abgefragt werden."),
        "current_price": Elem.INT("Der aktuelle Börsenstrompreis.", unit=Units.thousands_cent_per_kWh),
    })),

    Func("prices", FuncType.STATE, Elem.OBJECT("Die dynamischen Strompreise.", members={
        "first_date":  Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt zu welchem Zeitpunkt der erste Preise im `prices`-Array gilt."),
        "resolution":  Elem.INT("Auflösung der dynamischen Strompreise im `prices`-Array.", constants=[
            Const(0, "15 Minuten"),
            Const(1, "60 Minuten"),
        ]),
        "prices": Elem.ARRAY("Array von dynamischen Strompreisen für maximal zwei Tage. Das erste Element des Arrays ist für den Zeitpunkt `first_date` und die Auflösung legt fest wie weit die Elemente zueinander zeitlich versetzt sind.", members=25*4*2 * [Elem.INT("")], unit=Units.thousands_cent_per_kWh),
    })),
])
