from api_doc_common import *

heating = Module("heating", T({'de': "Heizung", 'en': "Heating"}), "", T({'de': "Über das `heating`-Modul können Einstellungen für die Heizungssteuerung vorgenommen werden.", 'en': "The `heating` module allows settings for heating control to be configured."}), Version.WEM2, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der Heizungssteuerung.", 'en': "The heating control configuration."}), members={
        "sgr_blocking_type": Elem.INT(T({'de': "SG-Ready Ausgang 1 Konfiguration (wird für den blockierenden Betrieb verwendet).", 'en': "SG-Ready output 1 configuration (used for blocking operation)."}), constants=[
            Const(0, T({'de': "Aktiv wenn geschlossen", 'en': "Active when closed"})),
            Const(1, T({'de': "Aktiv wenn geöffnet", 'en': "Active when open"})),
        ]),
        "sgr_extended_type": Elem.INT(T({'de': "SG-Ready Ausgang 2 Konfiguration (wird für den erweiterten Betrieb verwendet).", 'en': "SG-Ready output 2 configuration (used for extended operation)."}), constants=[
            Const(0, T({'de': "Aktiv wenn geschlossen", 'en': "Active when closed"})),
            Const(1, T({'de': "Aktiv wenn geöffnet", 'en': "Active when open"})),
        ]),
        "min_hold_time": Elem.INT(T({'de': "Mindesthaltezeitfür SG-Ready-Ausgang 1 und SG-Ready-Ausgang 2.", 'en': "Minimum hold time for SG-Ready output 1 and SG-Ready output 2."})),
        "meter_slot_grid_power": Elem.INT(T({'de': "Gibt an, welcher Stromzähler für die Regelung als Hausanschlusszähler betrachtet wird.", 'en': "Specifies which electricity meter is considered the grid connection meter for control."})),
        "control_period":  Elem.INT("", constants=[
            Const(0, T({'de': "24 Stunden", 'en': "24 hours"})),
            Const(1, T({'de': "12 Stunden", 'en': "12 hours"})),
            Const(2, T({'de': "8 Stunden", 'en': "8 hours"})),
            Const(3, T({'de': "6 Stunden", 'en': "6 hours"})),
            Const(4, T({'de': "4 Stunden", 'en': "4 hours"})),
        ]),
        "extended_logging": Elem.BOOL(T({'de': "Gibt an, ob weiterführende Informationen zu den Steuerentscheidungen im Ereignis-Log aufgezeichnet werden sollen.", 'en': "Specifies whether detailed information about control decisions should be recorded in the event log."})),
        "yield_forecast": Elem.BOOL(T({'de': "Gibt an, ob die PV-Ertragsprognose für die Heizungssteuerung verwendet werden soll.", 'en': "Specifies whether the PV yield forecast should be used for heating control."})),
        "yield_forecast_threshold": Elem.INT(T({'de': "Grenzwert Für die PV-Ertragsprognose. Wenn die PV-Ertragsprognosen-Steuerung aktiviert ist und die Prognose größer als die eingestellte Energie ausfällt, entfällt die Dynamische-Strom­preis-Steuerung und es wird ausschließlich der PV-Über­schuss genutzt.", 'en': "Threshold for the PV yield forecast. When PV yield forecast control is enabled and the forecast exceeds the configured energy, dynamic electricity price control is disabled and only PV excess is used."}), unit=Units.kWh),
        "extended": Elem.BOOL(T({'de': "Gibt an, ob die Steuerung des erweiterten Betriebs aktiviert werden soll.", 'en': "Specifies whether extended operation control should be enabled."})),
        "extended_hours": Elem.INT(T({'de': "Anzahl der (günstigsten) Stunden für die der erweiterte Betrieb genutzt werden soll.", 'en': "Number of (cheapest) hours for which extended operation should be used."}), unit=Units.h),
        "blocking": Elem.BOOL(T({'de': "Gibt an, ob die Steuerung des blockierenden Betriebs aktiviert werden soll.", 'en': "Specifies whether blocking operation control should be enabled."})),
        "blocking_hours": Elem.INT(T({'de': "Anzahl der (teuersten) Stunden für die der blockierende Betrieb genutzt werden soll.", 'en': "Number of (most expensive) hours for which blocking operation should be used."}), unit=Units.h),
        "pv_excess_control": Elem.BOOL(T({'de': "Gibt an, ob die PV-Überschusssteuerung aktiviert werden soll.", 'en': "Specifies whether PV excess control should be enabled."})),
        "pv_excess_control_threshold": Elem.INT(T({'de': "Grenzewert für die PV-Überschusssteuerung. Wenn die PV-Überschusssteuerung aktiviert ist und der PV-Überschuss größer als der eingestellte Wert ausfällt, wird die Heizung nur bei PV-Überschuss in den erweiterten Betrieb gebracht.", 'en': "Threshold for PV excess control. When PV excess control is enabled and PV excess exceeds the configured value, heating is only switched to extended operation when there is PV excess."}), unit=Units.W),
        "p14enwg": Elem.BOOL(T({'de': "Gibt an, ob die §14a EnWG-Steuerung aktiviert werden soll.", 'en': "Specifies whether §14a EnWG control should be enabled."})),
        "p14enwg_input": Elem.INT(T({'de': "Gibt an, welcher Eingang des Energiemanagers für die Abschaltung per §14a EnWG genutzt werden soll.", 'en': "Specifies which input of the energy manager should be used for shutdown via §14a EnWG."}), constants=[
            Const(0, T({'de': "Eingang 1", 'en': "Input 1"})),
            Const(1, T({'de': "Eingang 2", 'en': "Input 2"})),
            Const(1, T({'de': "Eingang 3", 'en': "Input 3"})),
            Const(1, T({'de': "Eingang 4", 'en': "Input 4"})),
        ]),
        "p14enwg_type": Elem.INT(T({'de': "Konfiguration für den Eingang.", 'en': "Configuration for the input."}), constants=[
            Const(0, T({'de': "Aktiv wenn geschlossen", 'en': "Active when closed"})),
            Const(1, T({'de': "Aktiv wenn geöffnet", 'en': "Active when open"})),
        ])
    })),

    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der Heizungssteuerung.", 'en': "The heating control state."}), members={
        "sgr_blocking": Elem.BOOL(T({'de': "Gibt an, ob der blockierende Betrieb aktiv ist.", 'en': "Indicates whether blocking operation is active."})),
        "sgr_extended": Elem.BOOL(T({'de': "Gibt an, ob der erweiterte Betrieb aktiv ist.", 'en': "Indicates whether extended operation is active."})),
        "p14enwg": Elem.BOOL(T({'de': "Gibt an, ob blockierender Betrieb auf Grund von §14a EnWG aktiv ist.", 'en': "Indicates whether blocking operation is active due to §14a EnWG."})),
        "next_update": Elem.INT(T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt wann die Heizungssteuerung die nächste Aktualisierung durchführt.", 'en': "A Unix timestamp in <strong>minutes</strong> indicating when the heating control will perform the next update."})),
    })),
])
