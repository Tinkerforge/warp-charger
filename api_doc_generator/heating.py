from api_doc_common import *

heating = Module("heating", "Heizung", "", "Über das `heating`-Modul können Einstellungen für die Heizungssteuerung vorgenommen werden.", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der Heizungssteuerung.", members={
        "sgr_blocking_type": Elem.INT(""),
        "sgr_extended_type": Elem.INT(""),
        "min_hold_time": Elem.INT(""),
        "meter_slot_grid_power": Elem.INT(""),
        "control_period":  Elem.INT("", constants=[
            Const(0, "24 Stunden"),
            Const(1, "12 Stunden"),
            Const(2, "8 Stunden"),
            Const(3, "6 Stunden"),
            Const(4, "4 Stunden"),
        ]),
        "extended_logging": Elem.BOOL(""),
        "yield_forecast": Elem.BOOL(""),
        "yield_forecast_threshold": Elem.INT(""),
        "extended": Elem.BOOL(""),
        "extended_hours": Elem.INT(""),
        "blocking": Elem.BOOL(""),
        "blocking_hours": Elem.INT(""),
        "pv_excess_control": Elem.BOOL(""),
        "pv_excess_control_threshold": Elem.INT(""),
        "p14enwg": Elem.BOOL(""),
        "p14enwg_input": Elem.INT(""),
        "p14enwg_type": Elem.INT(""),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der Heizungssteuerung.", members={
        "sgr_blocking": Elem.BOOL(""),
        "sgr_extended": Elem.BOOL(""),
        "p14enwg": Elem.BOOL(""),
        "next_update": Elem.INT(""),
    })),
])
