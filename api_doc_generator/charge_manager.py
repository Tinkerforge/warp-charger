from api_doc_common import *

charge_manager = Module("charge_manager", "Lastmanager", "", "", Version.ANY, [
    Func("available_current", FuncType.STATE, Elem.OBJECT("Der derzeit zur Verfügung stehende Strom. Kann über charge_manager/available_current_update aktualisiert werden. Dieser Strom wird unter den konfigurierten Wallboxen aufgeteilt.", members={
            "current": Elem.INT("Der zur Verfügung stehende Strom. Darf nicht großer sein als der konfigurierte Maximalstrom maximum_available_current aus {{{ref:charge_manager/config}}}.", unit=Units.mA),
        })
    ),

    Func("available_phases", FuncType.STATE, Elem.OBJECT("Anzahl der derzeit verbundenen Phasen der Wallboxen. Kann über charge_manager/available_phases_update aktualisiert werden.", members={
            "phases": Elem.INT("Anzahl der verbundenen Phasen. Legt fest, ob der einphasige oder dreiphasige minimale Ladestrom für die Stromverteilung beachtet wird. Wird üblicherweise durch die Phasenumschaltung des Energy Managers vorgegeben.", unit=Units.mA),
        })
    ),

    Func("state", FuncType.STATE, Elem.OPAQUE("Der Zustand des Lastmanagers und aller konfigurierten Wallboxen. Wird vom Webinterface zur Anzeige verwendet. <strong>Änderungen an diesem Object werden nicht als API-Bruch betrachtet!</strong>")),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Lastmanager-Konfiguration. Diese kann über charge_manager/config_update mit dem selben Payload aktualisiert werden.", members={
            "enable_charge_manager": Elem.BOOL("Gibt an, ob der Lastmanager aktiviert sein soll.", constants=[
                Const(True, "Wenn der Lastmanager aktiviert ist."),
                Const(False, "Wenn der Lastmanager nicht aktiviert ist.")
            ]),
            "enable_watchdog": Elem.BOOL("Gibt an, ob der Watchdog aktiviert sein soll. Der Watchdog setzt, wenn 30 Sekunden lang keine Nachricht auf {{{ref:charge_manager/available_current_update}}} einging, den verfügbaren Strom auf die Default-Einstellung (default_available_current). Damit kann die Robustheit gegen Ausfall einer externen Steuerung, z.B. bei PV-Überschussladung erhöht werden.", constants=[
                Const(True, "Wenn der Watchdog aktiviert ist."),
                Const(False, "Wenn der Watchdog nicht aktiviert ist.")
            ]),
            "verbose": Elem.BOOL("Gibt an, ob jeder Stromverteilung im Ereignis-Log vermerkt werden soll.", constants=[
                Const(True, "Wenn Stromverteilungen geloggt werden sollen."),
                Const(False, "Wenn Stromverteilungen nicht geloggt werden sollen.")
            ]),
            "default_available_current": Elem.INT("Strom der nach Neustart des Lastmanagers zur Verfügung stehen soll. Beim Auslösen setzt der Watchdog den verfügbaren Strom auf diesen Strom zurück.", unit=Units.mA),
            "maximum_available_current": Elem.INT("Maximum, das über die API und das Webinterface jeweils als verfügbarer Strom gesetzt werden darf. Sollte auf den maximal erlaubten Strom der Anbindung des Wallbox-Verbunds konfiguriert werden, der z.b. durch Hausanschlusses, die Absicherung oder die Zuleitung begrenzt ist.", unit=Units.mA),
            "minimum_current_auto": Elem.BOOL("Gibt an, ob der Minimal-Ladestrom anhand des gewählten Fahrzeugtypes (minimum_current_vehicle_type) gesetzt wird.", constants=[
                Const(True, "Minimal-Ladestrom wird anhand des gewählten Fahrzeugtypes gesetzt. minimum_current und minimum_current_1p werden ignoriert, bzw. überschrieben."),
                Const(False, "minimum_current und minimum_current_1p bestimmen den Minimal-Ladestrom.")
            ]),
            "minimum_current_vehicle_type": Elem.INT("Fahrzeugtyp für den der Minimal-Ladestrom gewählt wird.", constants=[
                Const(0, "Kein spezifischer Fahrzeugtyp gewählt."),
                Const(1, "Renault Twingo Z.E., Renault ZOE R110 oder R135")
            ]),
            "minimum_current": Elem.INT("Kleinste Strommenge, die einer Wallbox im dreiphasigen Betrieb zugeteilt werden soll, damit diese einen Ladevorgang beginnt. Hiermit kann beeinflusst werden wie viele Wallboxen gleichzeitig laden.", unit=Units.mA),
            "minimum_current_1p": Elem.INT("Kleinste Strommenge, die einer Wallbox im einphasigen Betrieb zugeteilt werden soll, damit diese einen Ladevorgang beginnt. Hiermit kann beeinflusst werden wie viele Wallboxen gleichzeitig laden.", unit=Units.mA),
            "requested_current_threshold": Elem.INT("Wallboxen mit einem Stromzähler, der Phasenströme misst, werden requested_current_threshold Sekunden nach dem Ladestart auf den größten Phasenstrom plus den konfigurierten Spielraum limitiert. Damit kann der verfügbare Strom effizienter auf mehrere Wallboxen verteilt werden.", unit=Units.s),
            "requested_current_margin": Elem.INT("Spielraum, der auf den größten gemessenen Phasenstrom aufgeschlagen wird.", unit=Units.mA),
            "chargers": Elem.ARRAY("Wallboxen, die vom Lastmanager gesteuert werden sollen.", members=[
                * 10 * [Elem.OBJECT("Eine zu steuernde Wallbox", members = {
                    "host": Elem.STRING("IP-Adresse der zu steuernden Wallbox"),
                    "name": Elem.STRING("Anzeigename der zu steuernden Wallbox")
                })]
            ])
        })
    )
])
