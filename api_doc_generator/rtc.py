from api_doc_common import *

rtc = Module("rtc",
    T({'de': "Zeiteinstellungen der Real-Time Clock", 'en': "Real-Time Clock Settings"}),
    T({'de': "Benötigt das Feature <a href=\"#features_nfc\"><code>\"rtc\"</code></a>.",
       'en': "Requires the <a href=\"#features_nfc\"><code>\"rtc\"</code></a> feature."}),
    "",
    Version.ANY, [
    Func("time", FuncType.CONFIGURATION, Elem.OBJECT(
        T({'de': "Die aktuelle Zeit auf der Real-Time Clock.",
           'en': "The current time on the Real-Time Clock."}),
        members={
            "year": Elem.INT(T({'de': "Das Jahr. 2000 bis 2099", 'en': "The year. 2000 to 2099"})),
            "month": Elem.INT(T({'de': "Der Monat. 1 bis 12", 'en': "The month. 1 to 12"})),
            "day": Elem.INT(T({'de': "Der Tag. 1 bis 31", 'en': "The day. 1 to 31"})),
            "hour": Elem.INT(T({'de': "Die Stunde. 0 bis 23", 'en': "The hour. 0 to 23"})),
            "minute": Elem.INT(T({'de': "Die Minute. 0 bis 59", 'en': "The minute. 0 to 59"})),
            "second": Elem.INT(T({'de': "Die Sekunde. 0 bis 59", 'en': "The second. 0 to 59"})),
            "weekday": Elem.INT(T({'de': "Der Wochentag. 0 (Montag) bis 6 (Sonntag).",
                                   'en': "The weekday. 0 (Monday) to 6 (Sunday)."})),
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(
        T({'de': "Die Real-Time-Clock-Konfiguration.",
           'en': "The Real-Time Clock configuration."}),
        members={
            "auto_sync": Elem.BOOL(
                T({'de': "Gibt an, ob beim Laden des Webinterfaces automatisch die Zeit auf der RTC gestellt werden soll, falls keine Netzwerk-Zeitsynchronisierung vorliegt.",
                   'en': "Specifies whether the time on the RTC should be automatically set when loading the web interface, if no network time synchronization is available."}),
                constants=[
                    Const(True, T({'de': "Die RTC-Zeit wird automatisch auf die Systemzeit des Geräts gesetzt, dass das Webinterface aufgerufen hat.",
                                   'en': "The RTC time is automatically set to the system time of the device that accessed the web interface."})),
                    Const(False, T({'de': "Die RTC-Zeit wird nur manuell gesetzt.",
                                    'en': "The RTC time is only set manually."}))
                ]),
        })
    )
])
