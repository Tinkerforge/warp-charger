from api_doc_common import *

heating = Module("heating", "Heizung", "", "Über das `heating`-Modul können Einstellungen für die Heizungssteuerung vorgenommen werden.", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der Heizungssteuerung.", members={
        "sgr_blocking_type": Elem.INT("SG-Ready Ausgang 1 Konfiguration (wird für den blockierenden Betrieb verwendet).", constants=[
            Const(0, "Aktiv wenn geschlossen"),
            Const(1, "Aktiv wenn geöffnet"),
        ]),
        "sgr_extended_type": Elem.INT("SG-Ready Ausgang 2 Konfiguration (wird für den erweiterten Betrieb verwendet).", constants=[
            Const(0, "Aktiv wenn geschlossen"),
            Const(1, "Aktiv wenn geöffnet"),
        ]),
        "min_hold_time": Elem.INT("Mindesthaltezeitfür SG-Ready-Ausgang 1 und SG-Ready-Ausgang 2."),
        "meter_slot_grid_power": Elem.INT("Gibt an, welcher Stromzähler für die Regelung als Hausanschlusszähler betrachtet wird."),
        "control_period":  Elem.INT("", constants=[
            Const(0, "24 Stunden"),
            Const(1, "12 Stunden"),
            Const(2, "8 Stunden"),
            Const(3, "6 Stunden"),
            Const(4, "4 Stunden"),
        ]),
        "extended_logging": Elem.BOOL("Gibt an, ob weiterführende Informationen zu den Steuerentscheidungen im Ereignis-Log aufgezeichnet werden sollen."),
        "yield_forecast": Elem.BOOL("Gibt an, ob die PV-Ertragsprognose für die Heizungssteuerung verwendet werden soll."),
        "yield_forecast_threshold": Elem.INT("Grenzwert Für die PV-Ertragsprognose. Wenn die PV-Ertragsprognosen-Steuerung aktiviert ist und die Prognose größer als die eingestellte Energie ausfällt, entfällt die Dynamische-Strom­preis-Steuerung und es wird ausschließlich der PV-Über­schuss genutzt.", unit=Units.kWh),
        "extended": Elem.BOOL("Gibt an, ob die Steuerung des erweiterten Betriebs aktiviert werden soll."),
        "extended_hours": Elem.INT("Anzahl der (günstigsten) Stunden für die der erweiterte Betrieb genutzt werden soll.", unit=Units.h),
        "blocking": Elem.BOOL("Gibt an, ob die Steuerung des blockierenden Betriebs aktiviert werden soll."),
        "blocking_hours": Elem.INT("Anzahl der (teuersten) Stunden für die der blockierende Betrieb genutzt werden soll.", unit=Units.h),
        "pv_excess_control": Elem.BOOL("Gibt an, ob die PV-Überschusssteuerung aktiviert werden soll."),
        "pv_excess_control_threshold": Elem.INT("Grenzewert für die PV-Überschusssteuerung. Wenn die PV-Überschusssteuerung aktiviert ist und der PV-Überschuss größer als der eingestellte Wert ausfällt, wird die Heizung nur bei PV-Überschuss in den erweiterten Betrieb gebracht.", unit=Units.W),
        "p14enwg": Elem.BOOL("Gibt an, ob die §14a EnWG-Steuerung aktiviert werden soll."),
        "p14enwg_input": Elem.INT("Gibt an, welcher Eingang des Energiemanagers für die Abschaltung per §14a EnWG genutzt werden soll.", constants=[
            Const(0, "Eingang 1"),
            Const(1, "Eingang 2"),
            Const(1, "Eingang 3"),
            Const(1, "Eingang 4"),
        ]),
        "p14enwg_type": Elem.INT("Konfiguration für den Eingang.", constants=[
            Const(0, "Aktiv wenn geschlossen"),
            Const(1, "Aktiv wenn geöffnet"),
        ])
    })),

    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der Heizungssteuerung.", members={
        "sgr_blocking": Elem.BOOL("Gibt an, ob der blockierende Betrieb aktiv ist."),
        "sgr_extended": Elem.BOOL("Gibt an, ob der erweiterte Betrieb aktiv ist."),
        "p14enwg": Elem.BOOL("Gibt an, ob blockierender Betrieb auf Grund von §14a EnWG aktiv ist."),
        "next_update": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der angibt wann die Heizungssteuerung die nächste Aktualisierung durchführt."),
    })),
])
