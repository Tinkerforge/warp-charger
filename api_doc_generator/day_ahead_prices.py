from api_doc_common import *

day_ahead_prices = Module("day_ahead_prices", T({'de': "Dynamische Strompreise", 'en': "Dynamic Electricity Prices"}), "", T({'de': "Über das `day_ahead_prices`-Modul können dynamische Strompreise konfiguriert und ausgelesen werden.", 'en': "The `day_ahead_prices` module allows configuration and reading of dynamic electricity prices."}), Version.WARP2 | Version.WARP3 | Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der dynamischen Strompreise.", 'en': "The dynamic electricity prices configuration."}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob dynamische Strompreise verwendet werden sollen. Wenn die Quelle auf Strombörse gesetzt ist, werden die Preise einmal pro Tag für die nächsten 24 Stunden von einem externen Server abgerufen. In diesem Fall wird ein Internetzugang benötigt. Bei Push-Modus werden die Preise von einem externen System über die API bereitgestellt.", 'en': "Indicates whether dynamic electricity prices should be used. When the source is set to spot market, prices are retrieved once per day for the next 24 hours from an external server. In this case, internet access is required. In push mode, prices are provided by an external system via the API."})),
        "source": Elem.INT(T({'de': "Quelle der dynamischen Strompreise.", 'en': "Source of the dynamic electricity prices."}), constants=[
            Const(0, T({'de': "Strombörse", 'en': "Spot market"})),
            Const(1, U("Push")),
        ]),
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
        "enable_calendar":  Elem.BOOL(T({'de': "Gibt an, ob der Preiskalender aktiviert werden soll. Der Preiskalender erlaubt es, wöchentlich wiederkehrende Preisaufschläge oder -abschläge in 15-Minuten-Intervallen zu hinterlegen. Diese werden auf die Börsenstrompreise aufaddiert oder, wenn die Quelle auf Push gesetzt ist und keine Strompreise vorliegen, als eigenständige Preise verwendet.", 'en': "Indicates whether the price calendar should be enabled. The price calendar allows weekly recurring price surcharges or discounts to be configured in 15-minute intervals. These are added to the spot market prices or, if the source is set to Push and no electricity prices are available, used as standalone prices."})),
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

    Func("prices_update", FuncType.COMMAND, Elem.OBJECT(T({'de': "Aktualisiert die dynamischen Strompreise über die API. Funktioniert nur, wenn `enable` aktiviert und die `source` auf Push (1) gesetzt ist.", 'en': "Updates the dynamic electricity prices via the API. Only works when `enable` is activated and the `source` is set to Push (1)."}), members={
        "first_date":  Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, zu welchem Zeitpunkt der erste Preis im `prices`-Array gilt.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the time for which the first price in the `prices` array is valid."})),
        "resolution":  Elem.INT(T({'de': "Zeitliche Auflösung der dynamischen Strompreise im `prices`-Array.", 'en': "Time resolution of the dynamic electricity prices in the `prices` array."}), constants=[
            Const(0, T({'de': "15 Minuten", 'en': "15 minutes"})),
            Const(1, T({'de': "60 Minuten", 'en': "60 minutes"})),
        ]),
        "prices": Elem.ARRAY(T({'de': "Array von dynamischen Strompreisen für maximal zwei Tage. Das erste Element des Arrays ist für den Zeitpunkt `first_date` und die Auflösung legt fest, wie weit die Elemente zueinander zeitlich versetzt sind.", 'en': "Array of dynamic electricity prices for up to two days. The first element of the array is for the time `first_date` and the resolution determines how far apart the elements are in time."}), members=25*4*2 * [Elem.INT("")], unit=Units.thousands_cent_per_kWh),
    }), command_is_action=True),

    Func("calendar", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der Preiskalender. Enthält wöchentlich wiederkehrende Preisaufschläge oder -abschläge in 15-Minuten-Intervallen. Das Array enthält 672 Einträge (7 Tage × 96 Viertelstunden). Die Tage beginnen bei Montag (Index 0–95) und enden bei Sonntag (Index 576–671).", 'en': "The price calendar. Contains weekly recurring price surcharges or discounts in 15-minute intervals. The array contains 672 entries (7 days × 96 quarter-hours). Days start on Monday (index 0–95) and end on Sunday (index 576–671)."}), members={
        "prices": Elem.ARRAY(T({'de': "Array von 672 Preisaufschlägen oder -abschlägen. Jeder Eintrag entspricht einem 15-Minuten-Intervall einer Woche, beginnend bei Montag 00:00.", 'en': "Array of 672 price surcharges or discounts. Each entry corresponds to a 15-minute interval of a week, starting on Monday 00:00."}), members=672 * [Elem.INT("")], unit=Units.thousands_cent_per_kWh),
    })),
])
