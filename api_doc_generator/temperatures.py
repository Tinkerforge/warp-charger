from api_doc_common import *

temperatures = Module("temperatures", T({'de': "Außentemperatur", 'en': "Outside Temperature"}), "", T({'de': "Über das `temperatures`-Modul können Außentemperaturvorhersagen konfiguriert und ausgelesen werden. Die Tagesmitteltemperatur wird vom Heizungsmodul für die Temperatur-Heizkurve verwendet.", 'en': "The `temperatures` module allows configuration and reading of outdoor temperature forecasts. The daily average temperature is used by the heating module for the temperature heating curve."}), Version.WEM2, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der Außentemperatur.", 'en': "The outside temperature configuration."}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob die Temperaturvorhersage aktiviert ist.", 'en': "Indicates whether the temperature forecast is enabled."})),
        "source": Elem.INT(T({'de': "Quelle der Temperaturdaten.", 'en': "Source of the temperature data."}), constants=[
            Const(0, T({'de': "Wetterdienst", 'en': "Weather service"})),
            Const(1, U("Push")),
        ]),
        "api_url": Elem.STRING(T({'de': "Endpoint-URL des Wetterdienst-Servers.", 'en': "Endpoint URL of the weather service server."})),
        "lat": Elem.INT(T({'de': "Breitengrad (z.B. 51.8846°)", 'en': "Latitude (e.g., 51.8846°)"}), unit=Units.tenthousands_degree, censored_in_debug_report=True),
        "long": Elem.INT(T({'de': "Längengrad (z.B. 8.6251°)", 'en': "Longitude (e.g., 8.6251°)"}), unit=Units.tenthousands_degree, censored_in_debug_report=True),
        "cert_id": Elem.INT(T({'de': "ID des CA-Zertifikats, das zur Prüfung des Zertifikats des Wetterdienst-Servers genutzt wird. Siehe {{{ref:certs/state}}}.", 'en': "ID of the CA certificate used to verify the certificate of the weather service server. See {{{ref:certs/state}}}."})),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der Außentemperatur.", 'en': "The outside temperature state."}), members={
        "last_sync": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die Temperaturdaten das letzte Mal erfolgreich aktualisiert wurden.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the temperature data was last successfully updated."})),
        "last_check": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die Temperaturdaten das letzte Mal abgefragt wurden.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the temperature data was last queried."})),
        "next_check": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, wann die Temperaturdaten das nächste Mal abgefragt werden.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the temperature data will be queried next."})),
        "current": Elem.INT(T({'de': "Aktuelle Außentemperatur in Zehntel °C. 0x7FFF falls nicht verfügbar.", 'en': "Current outdoor temperature in tenths of °C. 0x7FFF if not available."})),
        "today_min": Elem.INT(T({'de': "Minimale Tagestemperatur für heute in Zehntel °C. 0x7FFF falls nicht verfügbar.", 'en': "Minimum daily temperature for today in tenths of °C. 0x7FFF if not available."})),
        "today_max": Elem.INT(T({'de': "Maximale Tagestemperatur für heute in Zehntel °C. 0x7FFF falls nicht verfügbar.", 'en': "Maximum daily temperature for today in tenths of °C. 0x7FFF if not available."})),
        "today_avg": Elem.INT(T({'de': "Tagesmitteltemperatur für heute in Zehntel °C. 0x7FFF falls nicht verfügbar.", 'en': "Daily average temperature for today in tenths of °C. 0x7FFF if not available."})),
        "tomorrow_min": Elem.INT(T({'de': "Minimale Tagestemperatur für morgen in Zehntel °C. 0x7FFF falls nicht verfügbar.", 'en': "Minimum daily temperature for tomorrow in tenths of °C. 0x7FFF if not available."})),
        "tomorrow_max": Elem.INT(T({'de': "Maximale Tagestemperatur für morgen in Zehntel °C. 0x7FFF falls nicht verfügbar.", 'en': "Maximum daily temperature for tomorrow in tenths of °C. 0x7FFF if not available."})),
        "tomorrow_avg": Elem.INT(T({'de': "Tagesmitteltemperatur für morgen in Zehntel °C. 0x7FFF falls nicht verfügbar.", 'en': "Daily average temperature for tomorrow in tenths of °C. 0x7FFF if not available."})),
    })),

    Func("temperatures", FuncType.STATE, Elem.OBJECT(T({'de': "Stündliche Temperaturvorhersage.", 'en': "Hourly temperature forecast."}), members={
        "first_date": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, zu welchem Zeitpunkt der erste Temperaturwert im `temperatures`-Array gilt.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the time for which the first temperature value in the `temperatures` array is valid."})),
        "temperatures": Elem.ARRAY(T({'de': "Array von Temperaturwerten in Zehntel °C. Das erste Element des Arrays gilt für den Zeitpunkt `first_date`, jedes weitere Element für die jeweils nächste Stunde.", 'en': "Array of temperature values in tenths of °C. The first element of the array is for the time `first_date`, each subsequent element for the next hour."}), member_type=EType.INT, is_var_length_array=True),
    })),

    Func("temperatures_update", FuncType.COMMAND, Elem.OBJECT(T({'de': "Aktualisiert die Temperaturvorhersage über die API. Funktioniert nur wenn die `source` auf Push (1) gesetzt ist.", 'en': "Updates the temperature forecast via the API. Only works when the `source` is set to Push (1)."}), members={
        "first_date": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt, zu welchem Zeitpunkt der erste Temperaturwert im `temperatures`-Array gilt.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the time for which the first temperature value in the `temperatures` array is valid."})),
        "temperatures": Elem.ARRAY(T({'de': "Array von Temperaturwerten in Zehntel °C. Das erste Element des Arrays gilt für den Zeitpunkt `first_date`, jedes weitere Element für die jeweils nächste Stunde.", 'en': "Array of temperature values in tenths of °C. The first element of the array is for the time `first_date`, each subsequent element for the next hour."}), member_type=EType.INT, is_var_length_array=True),
    }), command_is_action=True),
])
