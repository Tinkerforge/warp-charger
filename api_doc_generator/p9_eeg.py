from api_doc_common import *

def relay_level(desc: T, version: Version = Version.ANY):
    return Elem.INT(desc, constants=[
        Const(0, T({'de': "0 %", 'en': "0 %"})),
        Const(30, T({'de': "30 %", 'en': "30 %"})),
        Const(60, T({'de': "60 %", 'en': "60 %"})),
        Const(255, T({'de': "Relais wird nicht verwendet", 'en': "Relay is not used"})),
    ], version=version)

p9_eeg = Module("p9_eeg", T({'de': "§9 EEG", 'en': "§9 EEG"}), "", T({'de': "Über das `p9_eeg`-Modul wird die Einspeisebegrenzung gemäß §9 des Erneuerbare-Energien-Gesetzes (EEG) konfiguriert. Das Leistungslimit des Netzbetreibers wird in eine der Stufen 0 %, 30 %, 60 % oder 100 % der Nennleistung des Wechselrichters umgerechnet. Die Stufe wird über die Relais des Energy Managers an den Eingang des Wechselrichters für Rundsteuerempfänger gegeben. Es wird immer die höchste Stufe gewählt, die das Limit einhält. Ist kein Relais geschlossen, gilt immer 100 %.", 'en': "The `p9_eeg` module configures the feed-in limitation according to §9 of the German Renewable Energy Sources Act (EEG). The power limit of the grid operator is converted into one of the levels 0 %, 30 %, 60 % or 100 % of the inverter's rated power. The level is passed via the relays of the Energy Manager to the inverter's input for ripple control receivers. The highest level that complies with the limit is always used. If no relay is closed, 100 % always applies."}), Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der §9-EEG-Steuerung.", 'en': "The §9 EEG control configuration."}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob die §9-EEG-Steuerung aktiviert werden soll. Ist sie aktiviert, müssen `inverter_power_w` gesetzt und mindestens ein Relais verwendet werden.", 'en': "Specifies whether §9 EEG control should be enabled. If it is enabled, `inverter_power_w` must be set and at least one relay must be used."})),
        "source": Elem.INT(T({'de': "Signalquelle für das Limit des Netzbetreibers.", 'en': "Signal source for the limit of the grid operator."}), constants=[
            Const(0, T({'de': "EEBUS (Use Case LPP)", 'en': "EEBUS (use case LPP)"})),
            Const(1, T({'de': "API (siehe {{{ref:p9_eeg/control_update}}})", 'en': "API (see {{{ref:p9_eeg/control_update}}})"})),
        ]),
        "inverter_power_w": Elem.INT(T({'de': "AC-Nennleistung des Wechselrichters. Die Stufen beziehen sich auf diese Leistung.", 'en': "AC rated power of the inverter. The levels refer to this power."}), unit=Units.W),
        "relays": Elem.ARRAY(T({'de': "Stufe, die der Wechselrichter bei geschlossenem Relais einstellt. Jede Stufe kann nur einem Relais zugeordnet werden.", 'en': "Level the inverter applies while the relay is closed. Each level can only be assigned to one relay."}), unit=Units.percent, members=[
            relay_level(T({'de': "Relais 1", 'en': "Relay 1"})),
            relay_level(T({'de': "Relais 2", 'en': "Relay 2"}), version=Version.WEM2),
        ]),
        "default_level_pct": Elem.INT(T({'de': "Stufe, die gilt, solange die Signalquelle noch kein Limit geliefert hat. Muss 100 oder die Stufe eines verwendeten Relais sein. Bei der Signalquelle EEBUS ist sie zusätzlich der voreingestellte Failsafe-Wert des Use Cases LPP, solange die Steuerbox keinen eigenen Failsafe-Wert geschrieben hat.", 'en': "Level that applies as long as the signal source has not provided a limit. Must be 100 or the level of a relay in use. With the signal source EEBUS it is also the pre-configured failsafe value of the LPP use case, as long as the control box has not written its own failsafe value."}), unit=Units.percent),
    })),

    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der §9-EEG-Steuerung.", 'en': "The state of the §9 EEG control."}), members={
        "limit_active": Elem.BOOL(T({'de': "Gibt an, ob die Signalquelle aktuell ein Limit vorgibt.", 'en': "Indicates whether the signal source currently specifies a limit."})),
        "limit_w": Elem.INT(T({'de': "Das von der Signalquelle vorgegebene Limit. Ist 0, wenn kein Limit vorgegeben ist.", 'en': "The limit specified by the signal source. Is 0 if no limit is specified."}), unit=Units.W),
        "level_pct": Elem.INT(T({'de': "Die aktuell an den Wechselrichter gegebene Stufe. Die Einspeisung ist begrenzt, wenn die Stufe unter 100 liegt.", 'en': "The level currently passed to the inverter. The feed-in is limited if the level is below 100."}), unit=Units.percent),
        "default_active": Elem.BOOL(T({'de': "Gibt an, ob die Standardstufe verwendet wird, da die Signalquelle noch kein Limit geliefert hat.", 'en': "Indicates whether the default level is used because the signal source has not provided a limit yet."})),
        "limit_reachable": Elem.BOOL(T({'de': "Gibt an, ob das Limit mit den verfügbaren Stufen eingehalten werden kann. Ist false, wenn das Limit unter der niedrigsten verfügbaren Stufe liegt. In diesem Fall wird die niedrigste Stufe verwendet.", 'en': "Indicates whether the limit can be complied with using the available levels. Is false if the limit is below the lowest available level. In this case the lowest level is used."})),
    })),

    Func("control", FuncType.STATE, Elem.OBJECT(T({'de': "Der Steuerungszustand für die API-Quelle. Die Werte werden nur berücksichtigt, wenn die Signalquelle auf API (1) gesetzt ist. Nach einem Neustart gilt die Standardstufe bis zum ersten Aufruf von {{{ref:p9_eeg/control_update}}}.", 'en': "The control state for the API source. Values are only considered when the signal source is set to API (1). After a reboot, the default level applies until the first call of {{{ref:p9_eeg/control_update}}}."}), members={
        "active": Elem.BOOL(T({'de': "Gibt an, ob über die API ein Limit vorgegeben ist.", 'en': "Indicates whether a limit is specified via the API."})),
        "limit_w": Elem.INT(T({'de': "Über die API vorgegebenes Limit der Einspeiseleistung.", 'en': "Feed-in power limit specified via the API."}), unit=Units.W),
    })),

    Func("control_update", FuncType.COMMAND, Elem.OBJECT(T({'de': "Setzt das Limit über die API. Wird nur berücksichtigt, wenn die Signalquelle auf API (1) gesetzt ist. Der Zustand ist volatil.", 'en': "Sets the limit via the API. Only considered when the signal source is set to API (1). The state is volatile."}), members={
        "active": Elem.BOOL(T({'de': "Aktiviert oder deaktiviert das Limit.", 'en': "Activates or deactivates the limit."})),
        "limit_w": Elem.INT(T({'de': "Limit der Einspeiseleistung.", 'en': "Feed-in power limit."}), unit=Units.W),
    })),
])
