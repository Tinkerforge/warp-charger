from api_doc_common import *

power_manager = Module("power_manager", "Konfiguration des PV-Überschussladens", "", "", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration des Power Managers", members={
            "enabled": Elem.BOOL("Obsolet. Gibt an, ob der Power Manager aktiviert ist. Dieser Wert wird automatisch überschrieben, abhängig davon, ob PV-Überschussladen oder dynamisches Lastmanagement aktiviert sind."),
            "default_mode": Elem.INT("Der nach einem Neustart des Power Managers verwendete Lademodus", constants=[
                Const(0, "Schnell. Lädt Fahrzeuge so schnell wie möglich, selbst wenn dafür Netzbezug notwendig ist."),
                Const(1, "Aus. Fahrzeuge werden nicht geladen."),
                Const(2, "PV. Fahrzeuge werden nur vom PV-Überschuss geladen. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
                Const(3, "Min + PV. Erlaubt die konfigurierte Mindest-Ladeleistung (guaranteed_power), auch wenn diese (teilweise) aus dem Netz bezogen werden muss. Wenn ein größerer PV-Überschuss zur Verfügung steht, wird dieser verwendet. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
            ]),
            "excess_charging_enable": Elem.BOOL("Wenn aktiviert, regelt der Power Manager die von ihm kontrollierten Verbraucher abhängig vom Überschuss einer vorhandenen Photovoltaikanlage. Wenn deaktiviert, wird die maximale Leistung unter Einhaltung der maximale Strombelastbarkeit der Zuleitungen erlaubt."),
            "phase_switching_mode": Elem.INT("", constants=[
                Const(0, "Automatischer Wechsel zwischen drei- und einphasigem Laden. Nur möglich, wenn contactor_installed true ist."),
                Const(1, "Immer einphasig"),
                Const(2, "Immer dreiphasig"),
                Const(4, "Einphasiger PV-Modus, dreiphasiger Schnell-Modus"),
            ]),
            "target_power_from_grid": Elem.INT("Soll-Netzbezug für Überschussregelung. Gibt den gewünschten Netzbezug (positive Werte) bzw. Netzeinspeisung (negative Werte) im PV-Lademodus vor. Damit kann auch die Priorität gegenüber einem Batteriespeicher beeinflusst werden.", unit=Units.W),
            "guaranteed_power": Elem.INT("Mindest-Ladeleistung, die für den Min + PV-Lademodus verwendet wird. Diese Leistung wird bei unzureichendem PV-Überschuss (teilweise) aus dem Netz bezogen.", unit=Units.W),
            "cloud_filter_mode": Elem.INT("Modus des Wolkenfilters, um im PV-Lademodus Überreaktionen bei kurzzeitiger Änderung der Bewölkung zu vermeiden.", constants=[
                Const(0, "Kein Wolkenfilter."),
                Const(1, "Schwacher Wolkenfilter."),
                Const(2, "Mittlerer Wolkenfilter."),
                Const(3, "Starker Wolkenfilter."),
            ]),
            "meter_slot_grid_power": Elem.INT("Gibt an, welcher Stromzähler für die Regelung als Hausanschlusszähler betrachtet wird."),
            "meter_slot_battery_power": Elem.INT("Gibt an, welcher Stromzähler für die Regelung als Batteriespeicher-Stromzähler betrachtet wird."),
            "battery_mode": Elem.INT("Speicherpriorität im Verhältnis zu Wallboxen", constants=[
                Const(0, "Wallboxen bevorzugen, überschüssige Leistung für Speicher"),
                Const(1, "Speicher bevorzugen, überschüssige Leistung für Wallboxen"),
            ]),
            "battery_inverted": Elem.BOOL("Invertiert das Vorzeichen der Speicherleistung für Batteriespeicher, die beim Laden negative und beim Entladen positive Leistungswerte melden."),
            "battery_deadzone": Elem.INT("Bezugs- und Einspeise-Toleranz am Netzanschluss, während der Speicher aktiv ist. Für Batteriespeicher, die einen gewissen Bezug und Einspeisung beim Entladen bzw. Laden erlauben. Die Toleranz sollte auf das 1,5-fache des erwarteten Bezugs und Einspeisung gestellt werden."),
        })
    ),
    Func("dynamic_load_config", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration des dynamischen Lastmanagements", members={
            "enabled": Elem.BOOL("Aktiviert dynamisches Lastmanagement."),
            "meter_slot_grid_currents": Elem.INT("Gibt an, welcher Stromzähler für die Regelung als Hausanschlusszähler betrachtet wird."),
            "current_limit": Elem.INT("Maximal gewünschter Strom am Netzanschluss in Milliampere. Dies ist üblicherweise der Nennwert der Absicherung."),
            "largest_consumer_current": Elem.INT("Strombedarf des größten Einzelverbrauchers pro Phase in Milliampere, ausgenommen gesteuerter Wallboxen."),
            "safety_margin_pct": Elem.INT("Zusätzliche Sicherheitsmarge in Prozent, relativ zum maximalen Strom am Netzanschluss."),
        })
    ),
    Func("state", FuncType.STATE, Elem.OBJECT("Zustand des Power Managers", members={
            "config_error_flags": Elem.INT("Aktive Konfigurationsfehler des Power Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Konfigurationsfehlern auftreten können.", constants=[
                Const(0, "Kein Fehler"),
                Const("0x00000001", "Phasenumschaltung oder Schütz nicht konfiguriert"),
                Const("0x00000002", "Maximaler Gesamtstrom der Wallboxen nicht konfiguriert"),
                Const("0x00000004", "Keine Wallboxen konfiguriert"),
                Const("0x00000008", "Überschussladen aktiviert aber kein Stromzähler eingerichtet"),
            ]),
            "external_control": Elem.INT("Status der externen Steuerung zur Phasenumschaltung.", constants=[
                Const(0, "Externe Steuerung bereit für Kommandos."),
                Const(1, "Externe Steuerung über die Einstellungen deaktiviert."),
                Const(2, "Externe Steuerung ist aktiviert aber aktuell nicht verfügbar. Gründe sind unter anderem: ausgelöste Schützüberwachung, eine oder mehrere Wallboxen nicht erreichbar oder unterstützen keine CP-Trennung, Ladevorgang blockiert durch Eingang 3."),
                Const(3, "Phasenumschaltung wird gerade durchgeführt; ankommende Kommandos werden ignoriert."),
            ]),
        })
    ),
    Func("low_level_state", FuncType.STATE, Elem.OPAQUE("Der interne Zustand des Power Managers. Wird zum Anzeigen von Debug-Informationen verwendet. <strong>Änderungen an diesem Objekt werden nicht als API-Bruch betrachtet!</strong>")),
    Func("charge_mode", FuncType.CONFIGURATION, Elem.OBJECT("Aktuell verwendeter Lademodus.", members={
            "mode": Elem.INT("", constants=[
                Const(0, "Schnell. Lädt Fahrzeuge so schnell wie möglich, selbst wenn dafür Netzbezug notwendig ist."),
                Const(1, "Aus. Fahrzeuge werden nicht geladen."),
                Const(2, "PV. Fahrzeuge werden nur vom PV-Überschuss geladen. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
                Const(3, "Min + PV. Erlaubt die konfigurierte Mindest-Ladeleistung (guaranteed_power), auch wenn diese (teilweise) aus dem Netz bezogen werden muss. Wenn ein größerer PV-Überschuss zur Verfügung steht, wird dieser verwendet. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
            ])
        })
    ),
    Func("external_control", FuncType.CONFIGURATION, Elem.OBJECT("Phasenanforderung für externe Steuerung. Kann geschrieben werden, wenn external_control in {{{ref:power_manager/state}}} 0 ist.", members={
            "phases_wanted": Elem.INT("", constants=[
                Const(0, "Keine Phasen angefordert, keine Stromfreigabe."),
                Const(1, "Eine Phase angefordert."),
                Const(3, "Drei Phasen angefordert."),
            ])
        })
    )
])
