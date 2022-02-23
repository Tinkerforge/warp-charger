from api_doc_common import *

charge_tracker = Module("charge_tracker", "Ladetracker", "", Version.ANY, [
    Func("last_charges", FuncType.STATE, Elem.ARRAY("Die letzten (bis zu) fünf getrackten Ladungen", members=[
        * 5 * [Elem.OBJECT("Eine getrackte Ladung", members={
            "timestamp_minutes": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt der Ladung angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", unit=Units.min_),
            "charge_duration": Elem.INT("Dauer des Ladevorgangs.", unit=Units.s),
            "user_id": Elem.INT("ID des Benutzers der die Ladung gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist."),
            "energy_charged": Elem.FLOAT("Geladene Energie. null falls zum Start- oder Endzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh)
        })]
    ])),

    Func("current_charge", FuncType.STATE, Elem.OBJECT("Information zum aktuell laufenden Ladevorgang. Falls kein Ladevorgang läuft, hat die user_id den Wert -1", members={
        "user_id": Elem.INT("ID des Benutzers der die Ladung gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist. -1 falls gerade kein Ladevorgang läuft."),
        "meter_start": Elem.FLOAT("Zählerstand bei Start der Ladung. null falls zum Startzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh),
        "evse_uptime_start": Elem.INT("Uptime des Ladecontrollers beim Start der Ladung. Um zu berechnen, wie lange der Ladevogang bereits läuft kann die aktuelle Uptime aus {{{ref:evse/low_level_state}}} verwendet werden.", unit=Units.s),
        "timestamp_minutes": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt der Ladung angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", unit=Units.min_)
    })),

    Func("charge_log", FuncType.HTTP_ONLY, Elem.ARRAY("Gibt alle getrackten Ladungen in folgendem Binärformat aus. Ladeeinträge sind 16 Byte lang und werden nacheinander ausgegeben. Die folgenden Indizes sind Byte-offsets relativ zum Start einer getrackten Ladung. Alle Werte sind in little-endian.", members=[
        * 4 * [Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der den Startzeitpunkt der Ladung angibt. 0 falls zum Startzeitpunkt keine Zeitsynchronisierung verfügbar war.", unit=Units.min_, type_name_override='uint32')],
        * 4 * [Elem.FLOAT("Zählerstand bei Start der Ladung. NaN falls zum Startzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh)],
        Elem.INT("ID des Benutzers der die Ladung gestartet hat. 0 falls eine Freigabe ohne Nutzerzuordnung erfolgt ist.", type_name_override='uint8'),
        * 3 * [Elem.INT("Dauer des Ladevorgangs.", unit=Units.s, type_name_override='uint32 (3 Byte verwendet)')],
        * 4 * [Elem.FLOAT("Zählerstand bei Ende der Ladung. NaN falls zum Endzeitpunkt kein Zähler verfügbar war.", unit=Units.kWh)],
    ])),
])
