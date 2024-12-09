from api_doc_common import *

heating = Module("heating", "Heizung", "", "Über das `heating`-Modul können Einstellungen für die Heizungssteuerung vorgenommen werden.", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der Heizungssteuerung.", members={
        "sg_ready_blocking_active_type": Elem.INT(""),
        "sg_ready_extended_active_type": Elem.INT(""),
        "minimum_holding_time": Elem.INT(""),
        "meter_slot_grid_power": Elem.INT(""),
        "control_period":  Elem.INT("", constants=[
            Const(0, "24 Stunden"),
            Const(1, "12 Stunden"),
            Const(2, "8 Stunden"),
            Const(3, "6 Stunden"),
            Const(4, "4 Stunden"),
        ]),
        "extended_logging_active": Elem.BOOL(""),
        "yield_forecast_active": Elem.BOOL(""),
        "yield_forecast_threshold": Elem.INT(""),
        "extended_active": Elem.BOOL(""),
        "extended_hours": Elem.INT(""),
        "blocking_active": Elem.BOOL(""),
        "blocking_hours": Elem.INT(""),
        "pv_excess_control_active": Elem.BOOL(""),
        "pv_excess_control_threshold": Elem.INT(""),
        "p14enwg_active": Elem.BOOL(""),
        "p14enwg_input": Elem.INT(""),
        "p14enwg_active_type": Elem.INT(""),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der Heizungssteuerung.", members={
        "sg_ready_blocking_active": Elem.BOOL(""),
        "sg_ready_extended_active": Elem.BOOL(""),
        "p14enwg_active": Elem.BOOL(""),
        "remaining_holding_time": Elem.INT(""),
    })),
])