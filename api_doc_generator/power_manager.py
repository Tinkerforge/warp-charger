from api_doc_common import *

# Helper for repeated charge mode constants
CHARGE_MODE_CONSTANTS = [
    Const(0, T({'de': "Schnell. Lädt Fahrzeuge so schnell wie möglich, selbst wenn dafür Netzbezug notwendig ist.", 'en': "Fast. Charges vehicles as quickly as possible, even if grid power is required."})),
    Const(1, T({'de': "Aus. Fahrzeuge werden nicht geladen.", 'en': "Off. Vehicles are not charged."})),
    Const(2, T({'de': "PV. Fahrzeuge werden nur vom PV-Überschuss geladen. Steht nur zur Verfügung, wenn excess_charging_enable true ist.", 'en': "PV. Vehicles are only charged from PV excess. Only available if excess_charging_enable is true."})),
    Const(3, T({'de': "Min + PV. Erlaubt die konfigurierte Mindest-Ladeleistung (guaranteed_power), auch wenn diese (teilweise) aus dem Netz bezogen werden muss. Wenn ein größerer PV-Überschuss zur Verfügung steht, wird dieser verwendet. Steht nur zur Verfügung, wenn excess_charging_enable true ist.", 'en': "Min + PV. Allows the configured minimum charging power (guaranteed_power), even if it must be (partially) drawn from the grid. If greater PV excess is available, it is used. Only available if excess_charging_enable is true."})),
]

power_manager = Module("power_manager", T({'de': "Konfiguration des PV-Überschussladens", 'en': "PV Excess Charging Configuration"}), "", "", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguration des Power Managers", 'en': "Power Manager configuration"}), members={
            "enabled": Elem.BOOL(T({'de': "Obsolet. Gibt an, ob der Power Manager aktiviert ist. Dieser Wert wird automatisch überschrieben, abhängig davon, ob PV-Überschussladen oder dynamisches Lastmanagement aktiviert sind.", 'en': "Obsolete. Indicates whether the Power Manager is enabled. This value is automatically overwritten depending on whether PV excess charging or dynamic load management is enabled."})),
            "default_mode": Elem.INT(T({'de': "Der nach einem Neustart des Power Managers verwendete Lademodus", 'en': "The charge mode used after a Power Manager restart"}), constants=CHARGE_MODE_CONSTANTS),
            "excess_charging_enable": Elem.BOOL(T({'de': "Wenn aktiviert, regelt der Power Manager die von ihm kontrollierten Verbraucher abhängig vom Überschuss einer vorhandenen Photovoltaikanlage. Wenn deaktiviert, wird die maximale Leistung unter Einhaltung der maximale Strombelastbarkeit der Zuleitungen erlaubt.", 'en': "If enabled, the Power Manager controls the consumers it manages based on the excess of an existing photovoltaic system. If disabled, the maximum power is allowed while complying with the maximum current capacity of the supply lines."})),
            "phase_switching_mode": Elem.INT("", constants=[
                Const(0, T({'de': "Automatischer Wechsel zwischen drei- und einphasigem Laden. Nur möglich, wenn contactor_installed true ist.", 'en': "Automatic switching between three-phase and single-phase charging. Only possible if contactor_installed is true."})),
                Const(1, T({'de': "Immer einphasig", 'en': "Always single-phase"})),
                Const(2, T({'de': "Immer dreiphasig", 'en': "Always three-phase"})),
                Const(4, T({'de': "Einphasiger PV-Modus, dreiphasiger Schnell-Modus", 'en': "Single-phase PV mode, three-phase fast mode"})),
            ]),
            "target_power_from_grid": Elem.INT(T({'de': "Soll-Netzbezug für Überschussregelung. Gibt den gewünschten Netzbezug (positive Werte) bzw. Netzeinspeisung (negative Werte) im PV-Lademodus vor. Damit kann auch die Priorität gegenüber einem Batteriespeicher beeinflusst werden.", 'en': "Target grid power for excess control. Specifies the desired grid consumption (positive values) or grid feed-in (negative values) in PV charging mode. This can also influence the priority relative to a battery storage system."}), unit=Units.W),
            "guaranteed_power": Elem.INT(T({'de': "Mindest-Ladeleistung, die für den Min + PV-Lademodus verwendet wird. Diese Leistung wird bei unzureichendem PV-Überschuss (teilweise) aus dem Netz bezogen.", 'en': "Minimum charging power used for Min + PV charging mode. This power is (partially) drawn from the grid when PV excess is insufficient."}), unit=Units.W),
            "cloud_filter_mode": Elem.INT(T({'de': "Modus des Wolkenfilters, um im PV-Lademodus Überreaktionen bei kurzzeitiger Änderung der Bewölkung zu vermeiden.", 'en': "Cloud filter mode to avoid overreactions to short-term changes in cloud cover in PV charging mode."}), constants=[
                Const(0, T({'de': "Kein Wolkenfilter.", 'en': "No cloud filter."})),
                Const(1, T({'de': "Schwacher Wolkenfilter.", 'en': "Weak cloud filter."})),
                Const(2, T({'de': "Mittlerer Wolkenfilter.", 'en': "Medium cloud filter."})),
                Const(3, T({'de': "Starker Wolkenfilter.", 'en': "Strong cloud filter."})),
            ]),
            "meter_slot_grid_power": Elem.INT(T({'de': "Gibt an, welcher Stromzähler für die Regelung als Hausanschlusszähler betrachtet wird.", 'en': "Specifies which electricity meter is considered the grid connection meter for control."})),
            "meter_slot_battery_power": Elem.INT(T({'de': "Gibt an, welcher Stromzähler für die Regelung als Batteriespeicher-Stromzähler betrachtet wird.", 'en': "Specifies which electricity meter is considered the battery storage meter for control."})),
            "battery_mode": Elem.INT(T({'de': "Speicherpriorität im Verhältnis zu Wallboxen", 'en': "Storage priority relative to chargers"}), constants=[
                Const(0, T({'de': "Wallboxen bevorzugen, überschüssige Leistung für Speicher", 'en': "Prefer chargers, excess power for storage"})),
                Const(1, T({'de': "Speicher bevorzugen, überschüssige Leistung für Wallboxen", 'en': "Prefer storage, excess power for chargers"})),
            ]),
            "battery_inverted": Elem.BOOL(T({'de': "Invertiert das Vorzeichen der Speicherleistung für Batteriespeicher, die beim Laden negative und beim Entladen positive Leistungswerte melden.", 'en': "Inverts the sign of storage power for battery storage systems that report negative power values when charging and positive values when discharging."})),
            "battery_deadzone": Elem.INT(T({'de': "Bezugs- und Einspeise-Toleranz am Netzanschluss, während der Speicher aktiv ist. Für Batteriespeicher, die einen gewissen Bezug und Einspeisung beim Entladen bzw. Laden erlauben. Die Toleranz sollte auf das 1,5-fache des erwarteten Bezugs und Einspeisung gestellt werden.", 'en': "Grid consumption and feed-in tolerance at the grid connection while storage is active. For battery storage systems that allow a certain amount of consumption and feed-in during discharging or charging. The tolerance should be set to 1.5 times the expected consumption and feed-in."})),
        })
    ),
    Func("dynamic_load_config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguration des dynamischen Lastmanagements", 'en': "Dynamic load management configuration"}), members={
            "enabled": Elem.BOOL(T({'de': "Aktiviert dynamisches Lastmanagement.", 'en': "Enables dynamic load management."})),
            "meter_slot_grid_currents": Elem.INT(T({'de': "Gibt an, welcher Stromzähler für die Regelung als Hausanschlusszähler betrachtet wird.", 'en': "Specifies which electricity meter is considered the grid connection meter for control."})),
            "current_limit": Elem.INT(T({'de': "Maximal gewünschter Strom am Netzanschluss in Milliampere. Dies ist üblicherweise der Nennwert der Absicherung.", 'en': "Maximum desired current at the grid connection in milliamperes. This is typically the rated value of the fuse."})),
            "largest_consumer_current": Elem.INT(T({'de': "Strombedarf des größten Einzelverbrauchers pro Phase in Milliampere, ausgenommen gesteuerter Wallboxen.", 'en': "Current demand of the largest individual consumer per phase in milliamperes, excluding controlled chargers."})),
            "safety_margin_pct": Elem.INT(T({'de': "Zusätzliche Sicherheitsmarge in Prozent, relativ zum maximalen Strom am Netzanschluss.", 'en': "Additional safety margin in percent, relative to the maximum current at the grid connection."})),
        })
    ),
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Zustand des Power Managers", 'en': "Power Manager state"}), members={
            "config_error_flags": Elem.INT(T({'de': "Aktive Konfigurationsfehler des Power Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Konfigurationsfehlern auftreten können.", 'en': "Active configuration errors of the Power Manager. This is a bitmask, so any combination of configuration errors can occur."}), constants=[
                Const(0, T({'de': "Kein Fehler", 'en': "No error"})),
                Const("0x00000001", T({'de': "Phasenumschaltung oder Schütz nicht konfiguriert", 'en': "Phase switching or contactor not configured"})),
                Const("0x00000002", T({'de': "Maximaler Gesamtstrom der Wallboxen nicht konfiguriert", 'en': "Maximum total current of chargers not configured"})),
                Const("0x00000004", T({'de': "Keine Wallboxen konfiguriert", 'en': "No chargers configured"})),
                Const("0x00000008", T({'de': "Überschussladen aktiviert aber kein Stromzähler eingerichtet", 'en': "Excess charging enabled but no electricity meter configured"})),
            ]),
            "external_control": Elem.INT(T({'de': "Status der externen Steuerung zur Phasenumschaltung.", 'en': "Status of external control for phase switching."}), constants=[
                Const(0, T({'de': "Externe Steuerung bereit für Kommandos.", 'en': "External control ready for commands."})),
                Const(1, T({'de': "Externe Steuerung über die Einstellungen deaktiviert.", 'en': "External control disabled via settings."})),
                Const(2, T({'de': "Externe Steuerung ist aktiviert aber aktuell nicht verfügbar. Gründe sind unter anderem: ausgelöste Schützüberwachung, eine oder mehrere Wallboxen nicht erreichbar oder unterstützen keine CP-Trennung, Ladevorgang blockiert durch Eingang 3.", 'en': "External control is enabled but currently unavailable. Reasons include: triggered contactor monitoring, one or more chargers unreachable or do not support CP disconnect, charging session blocked by input 3."})),
                Const(3, T({'de': "Phasenumschaltung wird gerade durchgeführt; ankommende Kommandos werden ignoriert.", 'en': "Phase switching is currently being performed; incoming commands are ignored."})),
            ]),
        })
    ),
    Func("low_level_state", FuncType.STATE, Elem.OPAQUE(T({'de': "Der interne Zustand des Power Managers. Wird zum Anzeigen von Debug-Informationen verwendet. <strong>Änderungen an diesem Objekt werden nicht als API-Bruch betrachtet!</strong>", 'en': "The internal state of the Power Manager. Used for displaying debug information. <strong>Changes to this object are not considered an API breaking change!</strong>"}))),
    Func("charge_mode", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Aktuell verwendeter Lademodus.", 'en': "Currently used charge mode."}), members={
            "mode": Elem.INT("", constants=CHARGE_MODE_CONSTANTS)
        })
    ),
    Func("external_control", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Phasenanforderung für externe Steuerung. Kann geschrieben werden, wenn external_control in {{{ref:power_manager/state}}} 0 ist.", 'en': "Phase request for external control. Can be written when external_control in {{{ref:power_manager/state}}} is 0."}), members={
            "phases_wanted": Elem.INT("", constants=[
                Const(0, T({'de': "Keine Phasen angefordert, keine Stromfreigabe.", 'en': "No phases requested, no current release."})),
                Const(1, T({'de': "Eine Phase angefordert.", 'en': "One phase requested."})),
                Const(3, T({'de': "Drei Phasen angefordert.", 'en': "Three phases requested."})),
            ])
        })
    )
])
