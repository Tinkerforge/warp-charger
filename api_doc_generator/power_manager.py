from api_doc_common import *

power_manager = Module("power_manager", "Konfiguration des PV-Überschussladens", "", "", Version.WARP3 | Version.WARPEM, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration des Power Managers", members={
        "enabled": Elem.BOOL("Gibt an ob der Power Manager aktiviert ist.", constants=[
                Const(True, "Wenn der Power Manager aktiviert ist."),
                Const(False, "Wenn der Power Manager deaktiviert ist.")
            ]),
            "default_mode": Elem.INT("Der nach einem Neustart des Power Managers verwendete Lademodus", constants=[
                Const(0, "Schnell. Lädt Fahrzeuge so schnell wie möglich, selbst wenn dafür Netzbezug notwendig ist."),
                Const(1, "Aus. Fahrzeuge werden nicht geladen."),
                Const(2, "PV. Fahrzeuge werden nur vom PV-Überschuss geladen. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
                Const(3, "Min + PV. Erlaubt die konfigurierte Mindest-Ladeleistung (guaranteed_power), auch wenn diese (teilweise) aus dem Netz bezogen werden muss. Wenn ein größerer PV-Überschuss zur Verfügung steht, wird dieser verwendet. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
            ]),
            "excess_charging_enable": Elem.BOOL("Wenn aktiviert, regelt der Energy Manager die an ihn angeschlossenen Verbraucher abhängig vom Überschuss einer vorhandenen Photovoltaikanlage. Wenn deaktiviert, wird die maximale Leistung unter Einhaltung der maximale Strombelastbarkeit der Zuleitungen erlaubt."),
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
            "meter_slot_grid_power": Elem.INT("Gibt an, welcher Stromzähler für die Regelung als Hausanschlusszähler betrachtet wird")
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
    Func("low_level_state", FuncType.STATE, Elem.OBJECT("Low-Level-Zustand des Power Managers", members={
            "power_at_meter": Elem.FLOAT("Gemessene Leistung am Hausanschluss", unit=Units.W),
            "power_at_meter_filtered": Elem.FLOAT("Geglättete gemessene Leistung am Hausanschluss", unit=Units.W),
            "power_available": Elem.INT("Zum Laden verfügbare Leistung. Dies ist ein virtueller Wert, der nicht direkt der Ladeleistung entspricht.", unit=Units.W),
            "power_available_filtered": Elem.INT("Geglättete zum Laden verfügbare Leistung. Dies ist ein virtueller Wert, der nicht direkt der Ladeleistung entspricht.", unit=Units.W),
            "overall_min_power": Elem.INT("Ladeleistung, die der Energy Manager in der aktuellen Konfiguration minimal einstellen kann, abhängig von Phasenanzahl und minimalem Ladestrom.", unit=Units.W),
            "threshold_3to1": Elem.INT("Grenzwert der Ladeleistung, unter der der Energy Manager vom dreiphasigen in den einphasigen Modus wechseln möchte.", unit=Units.W),
            "threshold_1to3": Elem.INT("Grenzwert der Ladeleistung, über der der Energy Manager vom einphasigen Modus in den dreiphasigen Modus wechseln möchte.", unit=Units.W),
            "charge_manager_available_current": Elem.INT("Ladestrom, den der Energy Manager dem Lastmanagement aktuell zur Verfügung stellt.", unit=Units.mA),
            "charge_manager_allocated_current": Elem.INT("Ladestrom, der aktuell vom Lastmanager an Wallboxen verteilt wurde.", unit=Units.mA),
            "max_current_limited": Elem.INT("Maximaler Ladestrom unter Beachtung externer Strombegrenzung", unit=Units.mA),
            "uptime_past_hysteresis": Elem.BOOL("Zeitraum nach einem Start des Power Managers, in dem ohne Wartezeit umgeschaltet werden kann.", constants=[
                Const(True, "Startphase beendet, Wartezeiten müssen eingehalten werden"),
                Const(False, "Startphase läuft, Wartezeiten werden ignoriert"),
            ]),
            "is_3phase": Elem.BOOL("Zustand der Phasenumschaltung", constants=[
                Const(True, "Kontrollierte Wallboxen werden dreiphasig versorgt"),
                Const(False, "Kontrollierte Wallboxen werden einphasig versorgt"),
            ]),
            "wants_3phase": Elem.BOOL("Entscheidung der Phasenumschaltung", constants=[
                Const(True, "Dreiphasiger Betrieb erwünscht"),
                Const(False, "Einphasiger Betrieb erwünscht"),
            ]),
            "wants_3phase_last": Elem.BOOL("Vorige Entscheidung der Phasenumschaltung", constants=[
                Const(True, "Dreiphasiger Betrieb war erwünscht"),
                Const(False, "Einphasiger Betrieb war erwünscht"),
            ]),
            "is_on_last": Elem.BOOL("Voriger Zustand der Stromfreigabe", constants=[
                Const(True, "Ladestrom für Wallboxen war freigegeben"),
                Const(False, "Ladestrom für Wallboxen war nicht freigegeben"),
            ]),
            "wants_on_last": Elem.BOOL("Vorige Entscheidung der Stromfreigabe", constants=[
                Const(True, "Freigabe für Ladestrom für Wallboxen war erwünscht"),
                Const(False, "Freigabe für Ladestrom für Wallboxen war nicht erwünscht"),
            ]),
            "phase_state_change_blocked": Elem.BOOL("Blockierung der Phasenumschaltung aufgrund von Lastschwankungen", constants=[
                Const(True, "Phasenumschaltung ist aufgrund kürzlicher Laständerungen blockiert"),
                Const(False, "Phasenumschaltung ist nicht blockiert"),
            ]),
            "phase_state_change_delay": Elem.INT("Wartezeit, bis die Phasenumschaltung nicht mehr blockiert ist", unit=Units.ms),
            "on_state_change_blocked": Elem.BOOL("Blockierung der Ladestromfreigabe aufgrund von Lastschwankungen", constants=[
                Const(True, "Ladestrom darf aufgrund kürzlicher Laständerungen nicht freigegeben oder blockiert werden"),
                Const(False, "Ladestrom darf freigegeben oder blockiert werden"),
            ]),
            "on_state_change_delay": Elem.INT("Wartezeit, bis die Ladestromfreigabe nicht mehr blockiert ist", unit=Units.ms),
            "charging_blocked": Elem.INT("Ladefreigabe wird extern blockiert, falls Wert nicht 0."),
            "switching_state": Elem.INT("Interne Automatenzustände der Phasenumschaltung", constants=[
                Const(0, "Es wird gerade keine Phasenumschaltung durchgeführt. Strom und Leistung werden überwacht."),
                Const(1, "Ladevorgänge aller Wallboxen werden beendet"),
                Const(2, "Alle Wallboxen führen CP-Trennung durch"),
                Const(3, "Schütz wird geschaltet"),
                Const(4, "Alle Wallboxen heben CP-Trennung auf"),
            ])
        })
    ),
    Func("charge_mode", FuncType.STATE, Elem.OBJECT("Aktuell verwendeter Lademodus. Kann über power_manager/charge_mode_update mit dem selben Payload aktualisiert werden.", members={
            "mode": Elem.INT("", constants=[
                Const(0, "Schnell. Lädt Fahrzeuge so schnell wie möglich, selbst wenn dafür Netzbezug notwendig ist."),
                Const(1, "Aus. Fahrzeuge werden nicht geladen."),
                Const(2, "PV. Fahrzeuge werden nur vom PV-Überschuss geladen. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
                Const(3, "Min + PV. Erlaubt die konfigurierte Mindest-Ladeleistung (guaranteed_power), auch wenn diese (teilweise) aus dem Netz bezogen werden muss. Wenn ein größerer PV-Überschuss zur Verfügung steht, wird dieser verwendet. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
            ])
        })
    ),
    Func("external_control", FuncType.STATE, Elem.OBJECT("Phasenanforderung für externe Steuerung. Nimmt über power_manager/external_control_update Kommandos zur Phasenumschaltung an, wenn external_control in power_manager/state 0 ist.", members={
            "phases_wanted": Elem.INT("", constants=[
                Const(0, "Keine Phasen angefordert, keine Stromfreigabe."),
                Const(1, "Eine Phase angefordert."),
                Const(3, "Drei Phasen angefordert."),
            ])
        })
    )
])
