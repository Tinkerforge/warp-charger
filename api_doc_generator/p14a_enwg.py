from api_doc_common import *

p14a_enwg = Module("p14a_enwg", T({'de': "§14a EnWG", 'en': "§14a EnWG"}), "", T({'de': "Über das `p14a_enwg`-Modul können die Einstellungen für die Steuerung gemäß §14a des Energiewirtschaftsgesetzes (EnWG) konfiguriert werden. §14a EnWG ermöglicht es Netzbetreibern, den Strombezug steuerbarer Verbrauchseinrichtungen (Wallboxen, Wärmepumpen, Batteriespeicher, Klimaanlagen) temporär zu reduzieren, um eine lokale Netzüberlastung zu vermeiden. Die Geräte werden dabei nie vollständig abgeschaltet. Eine Mindestleistung von 4200 W bleibt stets verfügbar.", 'en': "The `p14a_enwg` module allows configuration of settings for control according to §14a of the German Energy Industry Act (EnWG). §14a EnWG allows grid operators to temporarily reduce the power consumption of controllable consumer devices (wallboxes, heat pumps, battery storage, air conditioning) to prevent local grid overload. The devices are never fully shut off. A minimum of 4200 W always remains available."}), Version.WARP2 | Version.WARP3 | Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der §14a-EnWG-Steuerung.", 'en': "The §14a EnWG control configuration."}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob die §14a-EnWG-Steuerung aktiviert werden soll.", 'en': "Specifies whether §14a EnWG control should be enabled."})),
        "source": Elem.UNION(T({'de': "Signalquelle für die §14a-EnWG-Steuerung.", 'en': "Signal source for §14a EnWG control."}), members={
            0: Elem.OBJECT(T({'de': "Eingang", 'en': "Input"}), members={
                "limit_on_close": Elem.BOOL(T({'de': "Gibt an, ob die §14a-Steuerung bei geschlossenem oder geöffnetem Eingang aktiv ist.", 'en': "Specifies whether §14a control is active when the input is closed or open."}), constants=[
                    Const(True, T({'de': "Aktiv wenn geschlossen", 'en': "Active when closed"})),
                    Const(False, T({'de': "Aktiv wenn geöffnet", 'en': "Active when open"})),
                ]),
                "limit_w": Elem.INT(T({'de': "Leistungslimit in Watt, das bei Auslösung über den Eingang angewendet wird.", 'en': "Power limit in watts applied when triggered via the input."}), unit=Units.W),
                "input_index": Elem.INT(T({'de': "Gibt an, welcher Eingang des Energy Managers für die §14a-Steuerung verwendet wird.", 'en': "Specifies which Energy Manager input is used for §14a control."}), constants=[
                    Const(0, T({'de': "Eingang 1", 'en': "Input 1"}), version=Version.WEMX),
                    Const(1, T({'de': "Eingang 2", 'en': "Input 2"}), version=Version.WEMX),
                    Const(2, T({'de': "Eingang 3", 'en': "Input 3"}), version=Version.WEM2),
                    Const(3, T({'de': "Eingang 4", 'en': "Input 4"}), version=Version.WEM2),
                ], version=Version.WEMX),
            }),
            1: Elem.NULL(T({'de': "EEBUS", 'en': "EEBUS"})),
            2: Elem.NULL(T({'de': "API", 'en': "API"})),
        }),
        "limit_charger": Elem.BOOL(T({'de': "Gibt an, ob das §14a-Leistungslimit auf diese Wallbox angewendet werden soll.", 'en': "Specifies whether the §14a power limit should be applied to this charger."}), version=Version.WARP2 | Version.WARP3),
        "limit_charge_manager": Elem.BOOL(T({'de': "Gibt an, ob das §14a-Leistungslimit auf verwaltete Wallboxen angewendet werden soll.", 'en': "Specifies whether the §14a power limit should be applied to managed chargers."})),
        "limit_heating": Elem.BOOL(T({'de': "Gibt an, ob das §14a-Leistungslimit auf die Heizungssteuerung angewendet werden soll.", 'en': "Specifies whether the §14a power limit should be applied to heating control."}), version=Version.WEM2),
        "heating_max_power": Elem.INT(T({'de': "Maximale Leistungsaufnahme der Heizungsanlage.", 'en': "Maximum power draw of the heating system."}), unit=Units.W, version=Version.WEM2),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der §14a-EnWG-Steuerung.", 'en': "The state of the §14a EnWG control."}), members={
        "active": Elem.BOOL(T({'de': "Gibt an, ob die §14a-Steuerung aktuell aktiv ist, d.h. ob eine Leistungsbegrenzung vorliegt.", 'en': "Indicates whether §14a control is currently active, i.e. whether a power limitation is in effect."})),
        "limit_w": Elem.INT(T({'de': "Das aktuell wirksame Leistungslimit. Ist 0 wenn die §14a-Steuerung nicht aktiv ist.", 'en': "The current effective power limit. Is 0 when §14a control is not active."}), unit=Units.W),
    })),

    Func("control", FuncType.STATE, Elem.OBJECT(T({'de': "Der Steuerungszustand für die API-Quelle. Wird beim Neustart auf inaktiv zurückgesetzt. Die Werte werden nur berücksichtigt, wenn die Signalquelle auf API (2) gesetzt ist.", 'en': "The control state for the API source. Resets to inactive on reboot. Values are only considered when the signal source is set to API (2)."}), members={
        "active": Elem.BOOL(T({'de': "Gibt an, ob die §14a-Steuerung über die API aktiv ist.", 'en': "Indicates whether §14a control is active via the API."})),
        "limit_w": Elem.INT(T({'de': "Leistungslimit in Watt, das über die API gesetzt wird.", 'en': "Power limit in watts set via the API."}), unit=Units.W),
    })),

    Func("control_update", FuncType.COMMAND, Elem.OBJECT(T({'de': "Setzt den §14a-Steuerungszustand über die API. Funktioniert nur, wenn die Signalquelle auf API (2) gesetzt ist. Der Zustand ist volatil und wird beim Neustart auf inaktiv zurückgesetzt.", 'en': "Sets the §14a control state via the API. Only works when the signal source is set to API (2). The state is volatile and resets to inactive on reboot."}), members={
        "active": Elem.BOOL(T({'de': "Aktiviert oder deaktiviert die §14a-Steuerung über die API.", 'en': "Activates or deactivates §14a control via the API."})),
        "limit_w": Elem.INT(T({'de': "Leistungslimit in Watt.", 'en': "Power limit in watts."}), unit=Units.W),
    })),
])
