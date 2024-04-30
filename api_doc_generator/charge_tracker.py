from api_doc_common import *

charge_tracker = Module("charge_tracker", "Ladetracker", "", "", Version.CHARGER, [
    Func("state", FuncType.STATE, Elem.OBJECT("Zustand des Ladeträckers", members={
            "tracked_charges": Elem.INT("Anzahl der insgesamt aufgezeichneten Ladevorgänge."),
            "first_charge_timestamp": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des <strong>ersten</strong> Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", unit=Units.min_)
        })
    ),
    Func("last_charges", FuncType.STATE, Elem.ARRAY("Die letzten (bis zu) 30 aufgezeichneten Ladevorgänge", members=[
        * 30 * [Elem.OBJECT("Ein getrackter Ladevorgang", members={
            "timestamp_minutes": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", unit=Units.min_),
            "charge_duration": Elem.INT("Dauer des Ladevorgangs.", unit=Units.s),
            "user_id": Elem.INT("ID des Benutzers der den Ladevorgang gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist."),
            "energy_charged": Elem.FLOAT("Geladene Energie. null falls zum Start- oder Endzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh)
        })]
    ])),

    Func("current_charge", FuncType.STATE, Elem.OBJECT("Information zum aktuell laufenden Ladevorgang. Falls kein Ladevorgang läuft, hat die user_id den Wert -1", members={
        "user_id": Elem.INT("ID des Benutzers der den Ladevorgang gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist. -1 falls gerade kein Ladevorgang läuft."),
        "meter_start": Elem.FLOAT("Zählerstand bei Start des Ladevorgangs. null falls zum Startzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh),
        "evse_uptime_start": Elem.INT("Uptime des Ladecontrollers beim Start des Ladevorgangs. Um zu berechnen, wie lange der Ladevogang bereits läuft kann die aktuelle Uptime aus {{{ref:evse/low_level_state}}} verwendet werden.", unit=Units.s),
        "timestamp_minutes": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", unit=Units.min_),
        "authorization_type": Elem.INT("Gibt an wie der Ladevorgang freigeschaltet wurde.", constants=[
            Const(0, "Benutzerfreigabe deaktiviert, Ladevorgang wurde bei Anstecken des Fahrzeugs freigegeben. authorization_info ist null."),
            Const(1, "Typ der Freischaltung ging verloren, da der ESP während des Ladevorgangs neugestartet wurde. authorization_info ist null."),
            Const(2, "Ladevorgang wurde durch NFC-Tag freigegeben. NFC-Tag wurde physisch an den WARP Charger gehalten. authorization_info enthält tag_id und tag_type."),
            Const(3, "Ladevorgang wurde durch NFC-Tag freigegeben. NFC-Tag wurde per {{{ref:nfc/inject_tag}}} vorgetäuscht. authorization_info enthält tag_id und tag_type."),
        ]),
        "authorization_info": Elem.OPAQUE("Weiterführende Informationen zur Benutzerfreigabe. Format hängt vom authorization_type ab.")
    })),

    Func("remove_all_charges", FuncType.COMMAND, Elem.OBJECT("Löscht alle aufgezeichneten Ladevorgänge und die Nutzernamenhistorie. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", members={
        "do_i_know_what_i_am_doing": Elem.BOOL("Gibt an ob der Löschvorgang ausgeführt werden soll", constants=[
                Const(True, "Alle aufgezeichneten Ladevorgänge und die Nutzernamenhistorie löschen"),
                Const(False, "Keine Aktion durchführen"),
            ]
        )
    })),

    Func("charge_log", FuncType.HTTP_ONLY, Elem.ARRAY("Gibt alle aufgezeichneten Ladevorgänge in folgendem Binärformat aus. Einträge entsprechen jeweils einem Ladevorgang, sind 16 Byte lang und werden nacheinander ausgegeben. Die folgenden Indizes sind Byte-Offsets relativ zum Start eines aufgezeichneten Ladevorgangs. Alle Werte sind im Little-Endian-Format.", members=[
        * 4 * [Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", unit=Units.min_, type_name_override='uint32')],
        * 4 * [Elem.FLOAT("Zählerstand bei Start des Ladevorgangs. NaN falls zum Startzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh)],
        Elem.INT("ID des Benutzers der den Ladevorgang gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist.", type_name_override='uint8'),
        * 3 * [Elem.INT("Dauer des Ladevorgangs.", unit=Units.s, type_name_override='uint32 (3 Byte verwendet)')],
        * 4 * [Elem.FLOAT("Zählerstand bei Ende des Ladevorgangs. NaN falls zum Endzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh)],
    ])),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Ladetracker-Konfiguration.", members={
            "electricity_price": Elem.INT("Strompreis der im Webinterface und Ladelog verwendet wird um Ladekosten zu berechnen", unit=Units.hundredth_cent_per_kWh)
    }))
])
