from api_doc_common import *

def charger(version):
    return [Elem.OBJECT(T({'de': "Eine zu steuernde Wallbox", 'en': "A charger to be controlled"}), version=version, members = {
        "host": Elem.STRING(T({'de': "IP-Adresse der zu steuernden Wallbox", 'en': "IP address of the charger to be controlled"})),
        "name": Elem.STRING(T({'de': "Anzeigename der zu steuernden Wallbox", 'en': "Display name of the charger to be controlled"})),
        "rot": Elem.INT(T({'de': "Phasenrotation der zu steuernden Wallbox", 'en': "Phase rotation of the charger to be controlled"}), constants=[
                Const(0, T({'de': "Unbekannt", 'en': "Unknown"})),
                Const(1, U("L123")),
                Const(2, U("L132")),
                Const(3, U("L231")),
                Const(4, U("L213")),
                Const(5, U("L321")),
                Const(6, U("L312")),
        ])
})]

charge_manager = Module("charge_manager", T({'de': "Lastmanager", 'en': "Charge Manager"}), "", T({'de': "Das `charge_manager`-Modul implementiert einen Lastmanager, der eine verfügbare Menge Strom auf ein oder mehrere WARP Charger (jeder Generation) verteilen kann. Der Lastmanager stellt sicher, dass der konfigurierte Verbund an WARP Chargern niemals mehr als den verfügbaren Strom beziehen und versucht diesen möglichst fair zu verteilen. Ein WARP Energy Manager verwendet den Lastmanager außerdem um die Phasenumschaltung eines Verbunds an WARP Chargern über ein externes Schütz sicher umzusetzen.", 'en': "The `charge_manager` module implements a charge manager that can distribute an available amount of current across one or more WARP Chargers (of any generation). The charge manager ensures that the configured group of WARP Chargers never draws more than the available current and attempts to distribute it as fairly as possible. A WARP Energy Manager also uses the charge manager to safely implement phase switching of a group of WARP Chargers via an external contactor."}), Version.ANY, [
    Func("available_current", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der derzeit zur Verfügung stehende Strom. Dieser Strom wird unter den konfigurierten Wallboxen aufgeteilt.", 'en': "The currently available current. This current is distributed among the configured chargers."}), members={
            "current": Elem.INT(T({'de': "Der zur Verfügung stehende Strom. Es werden nur Ströme akzeptiert, die kleiner als der konfigurierte Maximalstrom maximum_available_current aus {{{ref:charge_manager/config}}} sind.", 'en': "The available current. Only currents that are less than the configured maximum current maximum_available_current from {{{ref:charge_manager/config}}} are accepted."}), unit=Units.mA),
        })
    ),

    Func("state", FuncType.STATE, Elem.OPAQUE(T({'de': "Der Zustand des Lastmanagers und aller konfigurierten Wallboxen. Wird vom Webinterface zur Anzeige verwendet. <strong>Änderungen an diesem Objekt werden nicht als API-Bruch betrachtet!</strong>", 'en': "The state of the charge manager and all configured chargers. Used by the web interface for display. <strong>Changes to this object are not considered an API breaking change!</strong>"}))),
    Func("low_level_state", FuncType.STATE, Elem.OPAQUE(T({'de': "Der Low-Level-Zustand des Lastmanagers und aller konfigurierten Wallboxen. Wird vom Webinterface zur Anzeige verwendet. <strong>Änderungen an diesem Objekt werden nicht als API-Bruch betrachtet!</strong>", 'en': "The low-level state of the charge manager and all configured chargers. Used by the web interface for display. <strong>Changes to this object are not considered an API breaking change!</strong>"}))),
    Func("low_level_config", FuncType.CONFIGURATION, Elem.OPAQUE(T({'de': "Die Low-Level-Konfiguration des Lastmanagers. Wird zum Fine-Tuning des Verteilungsalgorithmus verwendet. <strong>Änderungen an diesem Objekt werden nicht als API-Bruch betrachtet!</strong>", 'en': "The low-level configuration of the charge manager. Used for fine-tuning the distribution algorithm. <strong>Changes to this object are not considered an API breaking change!</strong>"}))),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Lastmanager-Konfiguration.", 'en': "The charge manager configuration."}), members={
            "enable_charge_manager": Elem.BOOL(T({'de': "Gibt an, ob der Lastmanager aktiviert sein soll.", 'en': "Specifies whether the charge manager should be enabled."}), constants=[
                Const(True, T({'de': "Wenn der Lastmanager aktiviert ist.", 'en': "If the charge manager is enabled."})),
                Const(False, T({'de': "Wenn der Lastmanager nicht aktiviert ist.", 'en': "If the charge manager is not enabled."}))
            ]),
            "enable_watchdog": Elem.BOOL(T({'de': "Gibt an, ob der Watchdog aktiviert sein soll. Der Watchdog setzt, wenn 30 Sekunden lang keine Nachricht auf {{{ref:charge_manager/available_current}}} einging, den verfügbaren Strom auf die Default-Einstellung (default_available_current). Damit kann die Robustheit gegen Ausfall einer externen Steuerung, z.B. bei PV-Überschussladung erhöht werden.", 'en': "Specifies whether the watchdog should be enabled. The watchdog sets the available current to the default setting (default_available_current) if no message is received on {{{ref:charge_manager/available_current}}} for 30 seconds. This increases robustness against failure of external control, e.g. with PV excess charging."}), constants=[
                Const(True, T({'de': "Wenn der Watchdog aktiviert ist.", 'en': "If the watchdog is enabled."})),
                Const(False, T({'de': "Wenn der Watchdog nicht aktiviert ist.", 'en': "If the watchdog is not enabled."}))
            ]),
            "verbose": Elem.BOOL(T({'de': "Gibt an, ob jeder Stromverteilung im Ereignis-Log vermerkt werden soll.", 'en': "Specifies whether each current distribution should be recorded in the event log."}), constants=[
                Const(True, T({'de': "Wenn Stromverteilungen geloggt werden sollen.", 'en': "If current distributions should be logged."})),
                Const(False, T({'de': "Wenn Stromverteilungen nicht geloggt werden sollen.", 'en': "If current distributions should not be logged."}))
            ]),
            "default_available_current": Elem.INT(T({'de': "Strom der nach Neustart des Lastmanagers zur Verfügung stehen soll. Beim Auslösen setzt der Watchdog den verfügbaren Strom auf diesen Strom zurück.", 'en': "Current that should be available after restart of the charge manager. When triggered, the watchdog resets the available current to this current."}), unit=Units.mA),
            "maximum_available_current": Elem.INT(T({'de': "Maximum, das über die API und das Webinterface jeweils als verfügbarer Strom gesetzt werden darf. Sollte auf den maximal erlaubten Strom der Anbindung des Wallbox-Verbunds konfiguriert werden, der z.b. durch Hausanschlusses, die Absicherung oder die Zuleitung begrenzt ist.", 'en': "Maximum that may be set as available current via the API and web interface. Should be configured to the maximum permitted current of the charger group connection, which is limited e.g. by the grid connection, fusing or supply line."}), unit=Units.mA),
            "minimum_current_auto": Elem.BOOL(T({'de': "Gibt an, ob der Minimal-Ladestrom anhand des gewählten Fahrzeugtypes (minimum_current_vehicle_type) gesetzt wird.", 'en': "Specifies whether the minimum charge current is set based on the selected vehicle type (minimum_current_vehicle_type)."}), constants=[
                Const(True, T({'de': "Minimal-Ladestrom wird anhand des gewählten Fahrzeugtypes gesetzt. minimum_current und minimum_current_1p werden ignoriert, bzw. überschrieben.", 'en': "Minimum charge current is set based on the selected vehicle type. minimum_current and minimum_current_1p are ignored or overwritten."})),
                Const(False, T({'de': "minimum_current und minimum_current_1p bestimmen den Minimal-Ladestrom.", 'en': "minimum_current and minimum_current_1p determine the minimum charge current."}))
            ]),
            "minimum_current_vehicle_type": Elem.INT(T({'de': "Fahrzeugtyp für den der Minimal-Ladestrom gewählt wird.", 'en': "Vehicle type for which the minimum charge current is selected."}), constants=[
                Const(0, T({'de': "Kein spezifischer Fahrzeugtyp gewählt.", 'en': "No specific vehicle type selected."})),
                Const(1, T({'de': "Renault Twingo Z.E., Renault ZOE R110 oder R135", 'en': "Renault Twingo Z.E., Renault ZOE R110 or R135"}))
            ]),
            "minimum_current": Elem.INT(T({'de': "Kleinste Strommenge, die einer Wallbox im dreiphasigen Betrieb zugeteilt werden soll, damit diese einen Ladevorgang beginnt. Hiermit kann beeinflusst werden wie viele Wallboxen gleichzeitig laden.", 'en': "Smallest amount of current to be allocated to a charger in three-phase operation for it to start a charging session. This can influence how many chargers charge simultaneously."}), unit=Units.mA),
            "minimum_current_1p": Elem.INT(T({'de': "Kleinste Strommenge, die einer Wallbox im einphasigen Betrieb zugeteilt werden soll, damit diese einen Ladevorgang beginnt. Hiermit kann beeinflusst werden wie viele Wallboxen gleichzeitig laden.", 'en': "Smallest amount of current to be allocated to a charger in single-phase operation for it to start a charging session. This can influence how many chargers charge simultaneously."}), unit=Units.mA),
            "requested_current_threshold": Elem.INT(T({'de': "Wallboxen mit einem Stromzähler, der Phasenströme misst, werden requested_current_threshold Sekunden nach dem Ladestart auf den größten Phasenstrom plus den konfigurierten Spielraum limitiert. Damit kann der verfügbare Strom effizienter auf mehrere Wallboxen verteilt werden.", 'en': "Chargers with an electricity meter that measures phase currents are limited to the largest phase current plus the configured margin requested_current_threshold seconds after charge start. This allows the available current to be distributed more efficiently across multiple chargers."}), unit=Units.s),
            "requested_current_margin": Elem.INT(T({'de': "Spielraum, der auf den größten gemessenen Phasenstrom aufgeschlagen wird.", 'en': "Margin added to the largest measured phase current."}), unit=Units.mA),
            "chargers": Elem.ARRAY(T({'de': "Wallboxen, die vom Lastmanager gesteuert werden sollen.", 'en': "Chargers to be controlled by the charge manager."}), members=
                  10 * charger(Version.WARP1)
                + 64 * charger(Version.WARP2 | Version.WARP3 | Version.WEMX)
            )
        })
    )
])
