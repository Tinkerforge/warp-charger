from api_doc_common import *

# Helper for repeated duration constants
DURATION_CONSTANTS = [
    Const(0, T({'de': "Unbegrenzt", 'en': "Unlimited"})),
    Const(1, T({'de': "15 Minuten", 'en': "15 minutes"})),
    Const(2, T({'de': "30 Minuten", 'en': "30 minutes"})),
    Const(3, T({'de': "45 Minuten", 'en': "45 minutes"})),
    Const(4, T({'de': "1 Stunde", 'en': "1 hour"})),
    Const(5, T({'de': "2 Stunden", 'en': "2 hours"})),
    Const(6, T({'de': "3 Stunden", 'en': "3 hours"})),
    Const(7, T({'de': "4 Stunden", 'en': "4 hours"})),
    Const(8, T({'de': "6 Stunden", 'en': "6 hours"})),
    Const(9, T({'de': "8 Stunden", 'en': "8 hours"})),
    Const(10, T({'de': "12 Stunden", 'en': "12 hours"})),
]

charge_limits = Module("charge_limits", T({'de': "Ladezeit- und -energielimits", 'en': "Charge Time and Energy Limits"}), "", T({'de': "Mit dem `charge_limits`-Modul können Energie- und Zeitlimits definiert werden, nach denen ein Ladevorgang beendet wird. Es können sowohl Standardlimits gesetzt werden ({{{ref:charge_limits/default_limits}}}, als auch Limits für den laufenden oder nächsten Ladevorgang überschrieben werden ({{{ref:charge_limits/override_duration}}} und {{{ref:charge_limits/override_energy}}})", 'en': "The `charge_limits` module allows defining energy and time limits after which a charging session is terminated. Both default limits can be set ({{{ref:charge_limits/default_limits}}}), as well as overriding limits for the current or next charging session ({{{ref:charge_limits/override_duration}}} and {{{ref:charge_limits/override_energy}}})"}), Version.WARPX, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Aktueller Zustand der Zeit- und Energielimits", 'en': "Current state of time and energy limits"}), members={
            "start_timestamp_ms": Elem.INT(T({'de': "Startzeitstempel des aktuellen Ladevorgangs. 0 falls kein Ladevorgang läuft.", 'en': "Start timestamp of the current charging session. 0 if no charging session is running."}), unit=Units.ms),
            "target_timestamp_ms": Elem.INT(T({'de': "Zielzeitstempel des aktuellen Ladevorgangs. 0 falls kein Ladevorgang läuft. Gleich dem Startzeitstempel, falls kein Zeitlimit gesetzt ist.", 'en': "Target timestamp of the current charging session. 0 if no charging session is running. Equal to the start timestamp if no time limit is set."}), unit=Units.ms),
            "start_energy_kwh": Elem.FLOAT(T({'de': "Startzählerwert des aktuellen Ladevorgangs. null falls kein Ladevorgang läuft, oder kein Stromzähler zur Verfügung steht.", 'en': "Start meter value of the current charging session. null if no charging session is running or no electricity meter is available."}), unit=Units.kWh),
            "target_energy_kwh": Elem.FLOAT(T({'de': "Zielzählerwert des aktuellen Ladevorgangs. null falls kein Ladevorgang läuft, oder kein Stromzähler zur Verfügung steht. Gleich dem Startzählerwert, falls kein Energiewert gesetzt ist.", 'en': "Target meter value of the current charging session. null if no charging session is running or no electricity meter is available. Equal to the start meter value if no energy value is set."}), unit=Units.kWh),
        })
    ),

    Func("default_limits", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguration der Zeit- und Energielimits für Ladevorgänge.", 'en': "Configuration of time and energy limits for charging sessions."}), members={
            "duration": Elem.INT(T({'de': "Zeitlimit eines Ladevorgangs. Nach Ablaufen des Zeitlimits wird der Ladevorgang gestoppt.", 'en': "Time limit of a charging session. The charging session is stopped after the time limit expires."}), constants=DURATION_CONSTANTS),
            "energy_wh": Elem.INT(T({'de': "Energielimit eines Ladevorgangs. Nach Ablaufen des Energielimits wird der Ladevorgang gestoppt.", 'en': "Energy limit of a charging session. The charging session is stopped after the energy limit expires."}), unit=Units.Wh),
        })
    ),

    Func("active_limits", FuncType.STATE, Elem.OBJECT(T({'de': "Aktive Zeit- und Energielimits für den aktuellen oder nächsten Ladevorgang. Können über {{{ref:charge_limits/override_duration}}} und {{{ref:charge_limits/override_energy}}} aktualisiert werden.", 'en': "Active time and energy limits for the current or next charging session. Can be updated via {{{ref:charge_limits/override_duration}}} and {{{ref:charge_limits/override_energy}}}."}), members={
            "duration": Elem.INT(T({'de': "Zeitlimit eines Ladevorgangs. Nach Ablaufen des Zeitlimits wird der Ladevorgang gestoppt.", 'en': "Time limit of a charging session. The charging session is stopped after the time limit expires."}), constants=DURATION_CONSTANTS),
            "energy_wh": Elem.INT(T({'de': "Energielimit eines Ladevorgangs. Nach Ablaufen des Energielimits wird der Ladevorgang gestoppt.", 'en': "Energy limit of a charging session. The charging session is stopped after the energy limit expires."}), unit=Units.Wh),
        })
    ),

    Func("override_duration", FuncType.COMMAND, Elem.OBJECT(T({'de': "Überschreibt das Zeitlimit für den aktuellen oder nächsten Ladevorgang.", 'en': "Overrides the time limit for the current or next charging session."}), members={
            "duration": Elem.INT(T({'de': "Zeitlimit eines Ladevorgangs. Nach Ablaufen des Zeitlimits wird der Ladevorgang gestoppt.", 'en': "Time limit of a charging session. The charging session is stopped after the time limit expires."}), constants=DURATION_CONSTANTS)
        })
    ),

    Func("override_energy", FuncType.COMMAND, Elem.OBJECT(T({'de': "Überschreibt das Energielimit für den aktuellen oder nächsten Ladevorgang.", 'en': "Overrides the energy limit for the current or next charging session."}), members={
            "energy_wh": Elem.INT(T({'de': "Energielimit eines Ladevorgangs. Nach Ablaufen des Energielimits wird der Ladevorgang gestoppt.", 'en': "Energy limit of a charging session. The charging session is stopped after the energy limit expires."}), unit=Units.Wh),
        })
    ),

    Func("restart", FuncType.COMMAND, Elem.NULL(T({'de': "Setzt die Ladelimits zurück, so als ob ein neuer Ladevorgang begonnen hätte, behält aber die überschriebenen Ladelimits bei. Mit dieser API und {{{ref:charge_limits/override_duration}}} und {{{ref:charge_limits/override_energy}}} kann zu einem beliebigen Zeitpunkt ein neues \"absolutes\" Ladelimit gesetzt werden.", 'en': "Resets the charge limits as if a new charging session had started, but keeps the overridden charge limits. With this API and {{{ref:charge_limits/override_duration}}} and {{{ref:charge_limits/override_energy}}}, a new \"absolute\" charge limit can be set at any time."}))
    ),
])
