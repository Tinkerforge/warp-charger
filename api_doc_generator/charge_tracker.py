from api_doc_common import *

charge_tracker = Module("charge_tracker", T({'de': "Ladetracker", 'en': "Charge Tracker"}), "", T({'de': "Das `charge_tracker`-Modul zeichnet Ladevorgänge auf. Ladevorgänge werden in einem kompakten Binärformat gespeichert und können in diesem, oder aufbereitet als PDF-Dokument abgerufen werden.", 'en': "The `charge_tracker` module records charging sessions. Charging sessions are stored in a compact binary format and can be retrieved in this format or processed as a PDF document."}), Version.WARPX, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Zustand des Ladetrackers", 'en': "State of the charge tracker"}), members={
            "tracked_charges": Elem.INT(T({'de': "Anzahl der insgesamt aufgezeichneten Ladevorgänge.", 'en': "Total number of recorded charging sessions."})),
            "first_charge_timestamp": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des <strong>ersten</strong> Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the start time of the <strong>first</strong> charging session. 0 if no time synchronization was available at start time."}), unit=Units.min_)
        })
    ),
    Func("last_charges", FuncType.STATE, Elem.ARRAY(T({'de': "Die letzten (bis zu) 30 aufgezeichneten Ladevorgänge", 'en': "The last (up to) 30 recorded charging sessions"}), members=[
        * 30 * [Elem.OBJECT(T({'de': "Ein getrackter Ladevorgang", 'en': "A tracked charging session"}), members={
            "timestamp_minutes": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the start time of the charging session. 0 if no time synchronization was available at start time."}), unit=Units.min_),
            "charge_duration": Elem.INT(T({'de': "Dauer des Ladevorgangs.", 'en': "Duration of the charging session."}), unit=Units.s),
            "user_id": Elem.INT(T({'de': "ID des Benutzers der den Ladevorgang gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist.", 'en': "ID of the user who started the charging session. 0 if authorization was granted without user assignment."})),
            "energy_charged": Elem.FLOAT(T({'de': "Geladene Energie. null falls zum Start- oder Endzeitpunkt kein Zähler verfügbar war.", 'en': "Energy charged. null if no meter was available at start or end time."}), unit=Units.kWh)
        })]
    ])),

    Func("current_charge", FuncType.STATE, Elem.OBJECT(T({'de': "Information zum aktuell laufenden Ladevorgang. Falls kein Ladevorgang läuft, hat die user_id den Wert -1", 'en': "Information about the currently running charging session. If no charging session is running, user_id has the value -1"}), members={
        "user_id": Elem.INT(T({'de': "ID des Benutzers der den Ladevorgang gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist. -1 falls gerade kein Ladevorgang läuft.", 'en': "ID of the user who started the charging session. 0 if authorization was granted without user assignment. -1 if no charging session is currently running."})),
        "meter_start": Elem.FLOAT(T({'de': "Zählerstand bei Start des Ladevorgangs. null falls zum Startzeitpunkt kein Zähler verfügbar war.", 'en': "Meter reading at the start of the charging session. null if no meter was available at start time."}), unit=Units.kWh),
        "evse_uptime_start": Elem.INT(T({'de': "Uptime des Ladecontrollers beim Start des Ladevorgangs. Um zu berechnen, wie lange der Ladevogang bereits läuft kann die aktuelle Uptime aus {{{ref:evse/low_level_state}}} verwendet werden.", 'en': "Uptime of the charge controller at the start of the charging session. To calculate how long the charging session has been running, the current uptime from {{{ref:evse/low_level_state}}} can be used."}), unit=Units.s),
        "timestamp_minutes": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the start time of the charging session. 0 if no time synchronization was available at start time."}), unit=Units.min_),
        "authorization_type": Elem.INT(T({'de': "Gibt an wie der Ladevorgang freigeschaltet wurde.", 'en': "Indicates how the charging session was authorized."}), constants=[
            Const(0, T({'de': "Benutzerfreigabe deaktiviert, Ladevorgang wurde bei Anstecken des Fahrzeugs freigegeben. authorization_info ist null.", 'en': "User authorization disabled, charging session was authorized when vehicle was connected. authorization_info is null."})),
            Const(1, T({'de': "Typ der Freischaltung ging verloren, da der ESP während des Ladevorgangs neugestartet wurde. authorization_info ist null.", 'en': "Authorization type was lost because the ESP restarted during the charging session. authorization_info is null."})),
            Const(2, T({'de': "Ladevorgang wurde durch NFC-Tag freigegeben. NFC-Tag wurde physisch an den WARP Charger gehalten. authorization_info enthält tag_id und tag_type.", 'en': "Charging session was authorized by NFC tag. NFC tag was physically held to the WARP Charger. authorization_info contains tag_id and tag_type."})),
            Const(3, T({'de': "Ladevorgang wurde durch NFC-Tag freigegeben. NFC-Tag wurde per {{{ref:nfc/inject_tag}}} vorgetäuscht. authorization_info enthält tag_id und tag_type.", 'en': "Charging session was authorized by NFC tag. NFC tag was spoofed via {{{ref:nfc/inject_tag}}}. authorization_info contains tag_id and tag_type."})),
        ]),
        "authorization_info": Elem.OPAQUE(T({'de': "Weiterführende Informationen zur Benutzerfreigabe. Format hängt vom authorization_type ab.", 'en': "Additional information about user authorization. Format depends on authorization_type."}))
    })),

    Func("remove_all_charges", FuncType.COMMAND, Elem.OBJECT(T({'de': "Löscht alle aufgezeichneten Ladevorgänge und die Nutzernamenhistorie. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", 'en': "Deletes all recorded charging sessions and the username history. <strong>Cannot be undone!</strong> A restart is automatically performed afterwards."}), members={
        "do_i_know_what_i_am_doing": Elem.BOOL(T({'de': "Gibt an ob der Löschvorgang ausgeführt werden soll", 'en': "Indicates whether the deletion should be performed"}), constants=[
                Const(True, T({'de': "Alle aufgezeichneten Ladevorgänge und die Nutzernamenhistorie löschen", 'en': "Delete all recorded charging sessions and the username history"})),
                Const(False, T({'de': "Keine Aktion durchführen", 'en': "Perform no action"})),
            ]
        )
    })),

    Func("charge_log", FuncType.HTTP_ONLY, Elem.ARRAY(T({'de': "Gibt alle aufgezeichneten Ladevorgänge in folgendem Binärformat aus. Einträge entsprechen jeweils einem Ladevorgang, sind 16 Byte lang und werden nacheinander ausgegeben. Die folgenden Indizes sind Byte-Offsets relativ zum Start eines aufgezeichneten Ladevorgangs. Alle Werte sind im Little-Endian-Format.", 'en': "Returns all recorded charging sessions in the following binary format. Entries each correspond to one charging session, are 16 bytes long and are output sequentially. The following indices are byte offsets relative to the start of a recorded charging session. All values are in little-endian format."}), members=[
        * 4 * [Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt des Ladevorgangs angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating the start time of the charging session. 0 if no time synchronization was available at start time."}), unit=Units.min_, type_name_override='uint32')],
        * 4 * [Elem.FLOAT(T({'de': "Zählerstand bei Start des Ladevorgangs. NaN falls zum Startzeitpunkt kein Zähler verfügbar war.", 'en': "Meter reading at the start of the charging session. NaN if no meter was available at start time."}), unit=Units.kWh)],
        Elem.INT(T({'de': "ID des Benutzers der den Ladevorgang gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist.", 'en': "ID of the user who started the charging session. 0 if authorization was granted without user assignment."}), type_name_override='uint8'),
        * 3 * [Elem.INT(T({'de': "Dauer des Ladevorgangs.", 'en': "Duration of the charging session."}), unit=Units.s, type_name_override='uint32 (3 Byte verwendet)')],
        * 4 * [Elem.FLOAT(T({'de': "Zählerstand bei Ende des Ladevorgangs. NaN falls zum Endzeitpunkt kein Zähler verfügbar war.", 'en': "Meter reading at the end of the charging session. NaN if no meter was available at end time."}), unit=Units.kWh)],
    ])),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Ladetracker-Konfiguration.", 'en': "The charge tracker configuration."}), members={
            "electricity_price": Elem.INT(T({'de': "Strompreis der im Webinterface und Ladelog verwendet wird um Ladekosten zu berechnen", 'en': "Electricity price used in the web interface and charge log to calculate charging costs"}), unit=Units.hundredth_cent_per_kWh)
    }))
])
