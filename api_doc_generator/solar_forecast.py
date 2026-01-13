from api_doc_common import *

solar_forecast = Module("solar_forecast", T({'de': "PV-Ertragsprogrnose", 'en': "PV Yield Forecast"}), "", T({'de': "Über das `solar_forecast`-Modul kann eine PV-Ertragsprognose konfiguriert und ausgelesen werden.", 'en': "The `solar_forecast` module allows configuration and reading of a PV yield forecast."}), Version.WARP2 | Version.WARP3 | Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der PV-Ertragsprognose.", 'en': "The PV yield forecast configuration."}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob die PV-Ertragsprognose verwendet werden soll.", 'en': "Indicates whether the PV yield forecast should be used."})),
        "api_url": Elem.STRING(T({'de': "Endpoint-URL des Servers für dynamische Strompreise.", 'en': "Endpoint URL of the server for dynamic electricity prices."})),
        "cert_id": Elem.INT(T({'de': "ID des CA-Zertifikats, das zur Prüfung des Zertifikats des Prognose-Servers genutzt wird. Siehe {{{ref:certs/state}}}.", 'en': "ID of the CA certificate used to verify the certificate of the forecast server. See {{{ref:certs/state}}}."})),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der PV-Ertragsprognose.", 'en': "The state of the PV yield forecast."}), members={
        "wh_today": Elem.INT(T({'de': "Gesamttagesvorhersage für heute über alle PV-Flächen in Wh. -1 falls keine Vorhersagedaten für heute verfügbar sind.", 'en': "Total daily forecast for today across all PV planes in Wh. -1 if no forecast data is available for today."})),
        "wh_today_remaining": Elem.INT(T({'de': "Verbleibende Energie der Tagesvorhersage von jetzt bis Mitternacht über alle PV-Flächen in Wh. -1 falls keine Vorhersagedaten für heute verfügbar sind.", 'en': "Remaining energy of the daily forecast from now until midnight across all PV planes in Wh. -1 if no forecast data is available for today."})),
        "wh_tomorrow": Elem.INT(T({'de': "Gesamttagesvorhersage für morgen über alle PV-Flächen in Wh. -1 falls keine Vorhersagedaten für morgen verfügbar sind.", 'en': "Total daily forecast for tomorrow across all PV planes in Wh. -1 if no forecast data is available for tomorrow."})),
        "rate_limit": Elem.INT(T({'de': "Gibt an, wie viele API-Aufrufe alle zwei Stunden getätigt werden dürfen.", 'en': "Indicates how many API calls may be made every two hours."})),
        "rate_remaining": Elem.INT(T({'de': "Gibt an, wie viele API-Aufrufe im aktuellen Zeitfenster getätigt wurden.", 'en': "Indicates how many API calls have been made in the current time window."})),
        "next_api_call": Elem.INT(T({'de': "Gibt an, wann der nächste API-Aufruf getätigt wird.", 'en': "Indicates when the next API call will be made."})),
    })),

    Func("planes/X/state", FuncType.STATE, Elem.OBJECT(T({'de': "Status der PV-Flächen", 'en': "Status of the PV planes"}), members={
            "last_sync": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die PV-Ertragsprognose das letzte Mal aktualisiert wurde.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the PV yield forecast was last updated."})),
            "last_check": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die PV-Ertragsprognose das letzte Mal abgefragt wurde.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the PV yield forecast was last queried."})),
            "next_check": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die PV-Ertragsprognose das nächste Mal abgefragt wird.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the PV yield forecast will be queried next."})),
            "place": Elem.STRING(T({'de': "Ort der konfigurierten PV-Fläche.", 'en': "Location of the configured PV plane."})),
        })
    ),

    Func("planes/X/config", FuncType.CONFIGURATION, Elem.OBJECT("", members={
        "enable": Elem.BOOL(T({'de': "Aktiviert die PV-Fläche.", 'en': "Enables the PV plane."})),
        "name": Elem.STRING(T({'de': "Anzeigename der PV-Fläche.", 'en': "Display name of the PV plane."})),
        "lat": Elem.INT(T({'de': "Breitengrad (z.B. 51.8847°)", 'en': "Latitude (e.g., 51.8847°)"}), unit=Units.tenthousands_degree),
        "long": Elem.INT(T({'de': "Längengrad (z.B. 8.6225°)", 'en': "Longitude (e.g., 8.6225°)"}), unit=Units.tenthousands_degree),
        "dec": Elem.INT(T({'de': "Neigung (0° horizontal bis 90° vertikal)", 'en': "Inclination (0° horizontal to 90° vertical)"}), unit=Units.degree),
        "az": Elem.INT(T({'de': "Azimut (-180° = Norden, -90° = Osten, 0° = Süden, 90° = Westen, 180° = Norden)", 'en': "Azimuth (-180° = North, -90° = East, 0° = South, 90° = West, 180° = North)"}), unit=Units.degree),
        "wp": Elem.INT(T({'de': "Peak-Leistung der PV-Fläche.", 'en': "Peak power of the PV plane."}), unit=Units.Wp),
    })),

    Func("planes/X/forecast", FuncType.STATE, Elem.OBJECT("", members={
        "first_date":  Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, zu welchem Zeitpunkt die erste PV-Ertragsprognose im `forecast`-Array gilt.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the time for which the first PV yield forecast in the `forecast` array is valid."})),
        "resolution":  Elem.INT(T({'de': "Zeitliche Auflösung der PV-Ertragsprognose im `forecast`-Array.", 'en': "Time resolution of the PV yield forecast in the `forecast` array."}), constants=[
            Const(0, T({'de': "15 Minuten", 'en': "15 minutes"})),
            Const(1, T({'de': "60 Minuten", 'en': "60 minutes"})),
        ]),
        "forecast": Elem.ARRAY(T({'de': "Array von PV-Ertragsprognose-Werten für maximal zwei Tage. Das erste Element des Arrays ist für den Zeitpunkt `first_date` und die Auflösung legt fest, wie weit die Elemente zueinander zeitlich versetzt sind.", 'en': "Array of PV yield forecast values for up to two days. The first element of the array is for the time `first_date` and the resolution determines how far apart the elements are in time."}), members=49 * [Elem.INT("")], unit=Units.Wh),
    })),
])
