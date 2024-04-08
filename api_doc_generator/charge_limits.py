from api_doc_common import *

charge_limits = Module("charge_limits", "Ladezeit- und -energielimits", "", "", Version.CHARGER, [
    Func("state", FuncType.STATE, Elem.OBJECT("Aktueller Zustand der Zeit- und Energielimits", members={
            "start_timestamp_ms": Elem.INT("Startzeitstempel des aktuellen Ladevorgangs. 0 falls kein Ladevorgang läuft.", unit=Units.ms),
            "target_timestamp_ms": Elem.INT("Zielzeitstempel des aktuellen Ladevorgangs. 0 falls kein Ladevorgang läuft. Gleich dem Startzeitstempel, falls kein Zeitlimit gesetzt ist.", unit=Units.ms),
            "start_energy_kwh": Elem.FLOAT("Startzählerwert des aktuellen Ladevorgangs. null falls kein Ladevorgang läuft, oder kein Stromzähler zur Verfügung steht.", unit=Units.kWh),
            "target_energy_kwh": Elem.FLOAT("Zielzählerwert des aktuellen Ladevorgangs. null falls kein Ladevorgang läuft, oder kein Stromzähler zur Verfügung steht. Gleich dem Startzählerwert, falls kein Energiewert gesetzt ist.", unit=Units.kWh),
        })
    ),

    Func("default_limits", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration der Zeit- und Energielimits für Ladevorgänge. Diese kann über charge_limits/default_limits_update mit dem selben Payload aktualisiert werden.", members={
            "duration": Elem.INT("Zeitlimit eines Ladevorgangs. Nach Ablaufen des Zeitlimits wird der Ladevorgang gestoppt.", constants=[
                Const(0, "Unbegrenzt"),
                Const(1, "15 Minuten"),
                Const(2, "30 Minuten"),
                Const(3, "45 Minuten"),
                Const(4, "1 Stunde"),
                Const(5, "2 Stunden"),
                Const(6, "3 Stunden"),
                Const(7, "4 Stunden"),
                Const(8, "6 Stunden"),
                Const(9, "8 Stunden"),
                Const(10, "12 Stunden"),
            ]),
            "energy_wh": Elem.INT("Energielimit eines Ladevorgangs. Nach Ablaufen des Energielimits wird der Ladevorgang gestoppt.", unit=Units.Wh),
        })
    ),

    Func("active_limits", FuncType.STATE, Elem.OBJECT("Aktive Zeit- und Energielimits für den aktuellen oder nächsten Ladevorgang. Können über {{{ref:charge_limits/override_duration}}} und {{{ref:charge_limits/override_energy}}} aktualisiert werden.", members={
            "duration": Elem.INT("Zeitlimit eines Ladevorgangs. Nach Ablaufen des Zeitlimits wird der Ladevorgang gestoppt.", constants=[
                Const(0, "Unbegrenzt"),
                Const(1, "15 Minuten"),
                Const(2, "30 Minuten"),
                Const(3, "45 Minuten"),
                Const(4, "1 Stunde"),
                Const(5, "2 Stunden"),
                Const(6, "3 Stunden"),
                Const(7, "4 Stunden"),
                Const(8, "6 Stunden"),
                Const(9, "8 Stunden"),
                Const(10, "12 Stunden"),
            ]),
            "energy_wh": Elem.INT("Energielimit eines Ladevorgangs. Nach Ablaufen des Energielimits wird der Ladevorgang gestoppt.", unit=Units.Wh),
        })
    ),

    Func("override_duration", FuncType.COMMAND, Elem.OBJECT("Überschreibt das Zeitlimit für den aktuellen oder nächsten Ladevorgang.", members={
            "duration": Elem.INT("Zeitlimit eines Ladevorgangs. Nach Ablaufen des Zeitlimits wird der Ladevorgang gestoppt.", constants=[
                Const(0, "Unbegrenzt"),
                Const(1, "15 Minuten"),
                Const(2, "30 Minuten"),
                Const(3, "45 Minuten"),
                Const(4, "1 Stunde"),
                Const(5, "2 Stunden"),
                Const(6, "3 Stunden"),
                Const(7, "4 Stunden"),
                Const(8, "6 Stunden"),
                Const(9, "8 Stunden"),
                Const(10, "12 Stunden"),
            ])
        })
    ),

    Func("override_energy", FuncType.COMMAND, Elem.OBJECT("Überschreibt das Energielimit für den aktuellen oder nächsten Ladevorgang.", members={
            "energy_wh": Elem.INT("Energielimit eines Ladevorgangs. Nach Ablaufen des Energielimits wird der Ladevorgang gestoppt.", unit=Units.Wh),
        })
    ),

    Func("restart", FuncType.COMMAND, Elem.NULL("Setzt die Ladelimits zurück, so als ob ein neuer Ladevorgang begonnen hätte, behält aber die überschriebenen Ladelimits bei. Mit dieser API und {{{ref:charge_limits/override_duration}}} und {{{ref:charge_limits/override_energy}}} kann zu einem beliebigen Zeitpunkt ein neues \"absolutes\" Ladelimit gesetzt werden.")
    ),
])
