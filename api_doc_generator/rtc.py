from api_doc_common import *

rtc = Module("rtc", "Zeiteinstellungen der Real-Time Clock", "Benötigt das Feature <a href=\"#features_nfc\"><code>\"rtc\"</code></a>.", "", Version.ANY, [
    Func("time", FuncType.CONFIGURATION, Elem.OBJECT("Die aktuelle Zeit auf der Real-Time Clock. Kann über rtc/time_update mit dem selben Payload gesetzt werden.", members={
            "year": Elem.INT("Das Jahr. 2000 bis 2099"),
            "month": Elem.INT("Der Monat. 1 bis 12"),
            "day": Elem.INT("Der Tag. 1 bis 31"),
            "hour": Elem.INT("Die Stunde. 0 bis 23"),
            "minute": Elem.INT("Die Minute. 0 bis 59"),
            "second": Elem.INT("Die Sekunde. 0 bis 59"),
            "weekday": Elem.INT("Der Wochentag. 0 (Montag) bis 6 (Sonntag)."),
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Real-Time-Clock-Konfiguration. Diese kann über rtc/config_update mit dem selben Payload aktualisiert werden.", members={
            "auto_sync": Elem.BOOL("Gibt an, ob beim Laden des Webinterfaces automatisch die Zeit auf der RTC gestellt werden soll, falls keine Netzwerk-Zeitsynchronisierung vorliegt.", constants=[
                Const(True, "Die RTC-Zeit wird automatisch auf die Systemzeit des Geräts gesetzt, dass das Webinterface aufgerufen hat."),
                Const(False, "Die RTC-Zeit wird nur manuell gesetzt.")
            ]),
        })
    )
])
