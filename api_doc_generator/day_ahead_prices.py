from api_doc_common import *

day_ahead_prices = Module("day_ahead_prices", T({'de': "Dynamische Strompreise", 'en': "Dynamic Electricity Prices"}), "", T({'de': "Über das `day_ahead_prices`-Modul können dynamische Strompreise konfiguriert und ausgelesen werden.", 'en': "The `day_ahead_prices` module allows configuration and reading of dynamic electricity prices."}), Version.WARP2 | Version.WARP3 | Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der dynamischen Strompreise.", 'en': "The dynamic electricity prices configuration."}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob dynamische Strompreise verwendet werden sollen. Wenn aktiviert, werden die Preise einmal pro Tag für die nächsten 24 Stunden von einem externen Server abgerufen. Um dynamische Strompreise nutzen zu können wird ein Internetzugang benötigt.", 'en': "Indicates whether dynamic electricity prices should be used. When enabled, prices are retrieved once per day for the next 24 hours from an external server. Internet access is required to use dynamic electricity prices."})),
        "api_url":  Elem.STRING(T({'de': "Endpoint-URL des Servers für dynamische Strompreise.", 'en': "Endpoint URL of the dynamic electricity prices server."})),
        "region":  Elem.INT(T({'de': "Gebiet der dynamischen Strompreise", 'en': "Region of the dynamic electricity prices"}), constants=[
            Const(0, U("DE")),
            Const(1, U("AT")),
            Const(2, U("LU")),
        ]),
        "resolution":  Elem.INT(T({'de': "Zeitliche Auflösung der dynamischen Strompreise.", 'en': "Time resolution of the dynamic electricity prices."}), constants=[
            Const(0, T({'de': "15 Minuten", 'en': "15 minutes"})),
            Const(1, T({'de': "60 Minuten", 'en': "60 minutes"})),
        ]),
        "cert_id":  Elem.INT(T({'de': "ID des CA-Zertifikats, das zur Prüfung des Zertifikats des Strompreis-Servers genutzt wird. Siehe {{{ref:certs/state}}}.", 'en': "ID of the CA certificate used to verify the certificate of the electricity price server. See {{{ref:certs/state}}}."})),
        "vat":  Elem.INT(T({'de': "Mehrwersteuersatz, der auf den Börsenstrompreis anfällt.", 'en': "VAT rate applied to the electricity exchange price."}), unit=Units.hundredth_percent),
        "grid_costs_and_taxes":  Elem.INT(T({'de': "Netzentgelte und Steuern (brutto falls MwSt-Satz angegeben ist).", 'en': "Grid fees and taxes (gross if VAT rate is specified)."}), unit=Units.thousands_cent_per_kWh),
        "supplier_markup":  Elem.INT(T({'de': "Stromanbieter-Preisaufschlag (brutto falls MwSt-Satz angegeben ist).", 'en': "Electricity supplier price markup (gross if VAT rate is specified)."}), unit=Units.thousands_cent_per_kWh),
        "supplier_base_fee":  Elem.INT(T({'de': "Stromanbieter-Grundgebühr", 'en': "Electricity supplier base fee"}), unit=Units.ct_per_month),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der dynamischen Strompreise.", 'en': "The state of the dynamic electricity prices."}), members={
        "last_sync": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die Börsenstrompreise das letzte Mal aktualisiert wurden.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the electricity exchange prices were last updated."})),
        "last_check": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die Börsenstrompreise das letzte Mal abgefragt wurden.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the electricity exchange prices were last queried."})),
        "next_check": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die Börsenstrompreise das nächste Mal abgefragt werden.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the electricity exchange prices will be queried next."})),
        "current_price": Elem.INT(T({'de': "Der aktuelle Börsenstrompreis.", 'en': "The current electricity exchange price."}), unit=Units.thousands_cent_per_kWh),
    })),

    Func("prices", FuncType.STATE, Elem.OBJECT(T({'de': "Die dynamischen Strompreise.", 'en': "The dynamic electricity prices."}), members={
        "first_date":  Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, zu welchem Zeitpunkt der erste Preise im `prices`-Array gilt.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the time for which the first price in the `prices` array is valid."})),
        "resolution":  Elem.INT(T({'de': "Zeitliche Auflösung der dynamischen Strompreise im `prices`-Array.", 'en': "Time resolution of the dynamic electricity prices in the `prices` array."}), constants=[
            Const(0, T({'de': "15 Minuten", 'en': "15 minutes"})),
            Const(1, T({'de': "60 Minuten", 'en': "60 minutes"})),
        ]),
        "prices": Elem.ARRAY(T({'de': "Array von dynamischen Strompreisen für maximal zwei Tage. Das erste Element des Arrays ist für den Zeitpunkt `first_date` und die Auflösung legt fest, wie weit die Elemente zueinander zeitlich versetzt sind.", 'en': "Array of dynamic electricity prices for up to two days. The first element of the array is for the time `first_date` and the resolution determines how far apart the elements are in time."}), members=25*4*2 * [Elem.INT("")], unit=Units.thousands_cent_per_kWh),
    })),
])
