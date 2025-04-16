from api_doc_common import *

solar_forecast = Module("solar_forecast", "PV-Ertragsprogrnose", "", "Über das `solar_forecast`-Modul kann eine PV-Ertragsprognose konfiguriert und ausgelesen werden.", Version.WARP2 | Version.WARP3 | Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der PV-Ertragsprognose.", members={
        "enable": Elem.BOOL("Gibt an, ob die PV-Ertragsprognose verwendet werden soll."),
        "api_url": Elem.STRING("Endpoint-URL des Servers für dynamische Strompreise."),
        "cert_id": Elem.INT("ID des CA-Zertifikats, das zur Prüfung des Zertifikats des Prognose-Servers genutzt wird. Siehe {{{ref:certs/state}}}."),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der PV-Ertragsprognose.", members={
        "wh_today": Elem.INT("Gesamttagesvorhersage für heute über alle PV-Flächen in Wh. -1 falls keine Vorhersagedaten für heute verfügbar sind."),
        "wh_today_remaining": Elem.INT("Verbleibende Energie der Tagesvorhersage von jetzt bis Mitternacht über alle PV-Flächen in Wh. -1 falls keine Vorhersagedaten für heute verfügbar sind."),
        "wh_tomorrow": Elem.INT("Gesamttagesvorhersage für morgen über alle PV-Flächen in Wh. -1 falls keine Vorhersagedaten für morgen verfügbar sind."),
        "rate_limit": Elem.INT("Gibt an, wie viele API-Aufrufe alle zwei Stunden getätigt werden dürfen."),
        "rate_remaining": Elem.INT("Gibt an, wie viele API-Aufrufe im aktuellen Zeitfenster getätigt wurden."),
        "next_api_call": Elem.INT("Gibt an, wann der nächste API-Aufruf getätigt wird."),
    })),

    Func("planes/X/state", FuncType.STATE, Elem.OBJECT("Status der PV-Flächen", members={
            "last_sync": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die PV-Ertragsprognose das letzte Mal aktualisiert wurde."),
            "last_check": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die PV-Ertragsprognose das letzte Mal abgefragt wurde."),
            "next_check": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die PV-Ertragsprognose das nächste Mal abgefragt wird."),
            "place": Elem.STRING("Ort der konfigurierten PV-Fläche."),
        })
    ),

    Func("planes/X/config", FuncType.CONFIGURATION, Elem.OBJECT("", members={
        "enable": Elem.BOOL("Aktiviert die PV-Fläche."),
        "name": Elem.STRING("Anzeigename der PV-Fläche."),
        "lat": Elem.INT("Breitengrad (z.B. 51.8847°)", unit=Units.tenthousands_degree),
        "long": Elem.INT("Längengrad (z.B. 8.6225°)", unit=Units.tenthousands_degree),
        "dec": Elem.INT("Neigung (0° horizontal bis 90° vertikal)", unit=Units.degree),
        "az": Elem.INT("Azimut (-180° = Norden, -90° = Osten, 0° = Süden, 90° = Westen, 180° = Norden)", unit=Units.degree),
        "wp": Elem.INT("Peak-Leistung der PV-Fläche.", unit=Units.Wp),
    })),

    Func("planes/X/forecast", FuncType.STATE, Elem.OBJECT("", members={
        "first_date":  Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, zu welchem Zeitpunkt die erste PV-Ertragsprognose im `forecast`-Array gilt."),
        "resolution":  Elem.INT("Zeitliche Auflösung der PV-Ertragsprognose im `forecast`-Array.", constants=[
            Const(0, "15 Minuten"),
            Const(1, "60 Minuten"),
        ]),
        "forecast": Elem.ARRAY("Array von PV-Ertragsprognose-Werten für maximal zwei Tage. Das erste Element des Arrays ist für den Zeitpunkt `first_date` und die Auflösung legt fest, wie weit die Elemente zueinander zeitlich versetzt sind.", members=49 * [Elem.INT("")], unit=Units.Wh),
    })),
])
