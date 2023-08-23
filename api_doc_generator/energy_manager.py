from api_doc_common import *

energy_manager = Module("energy_manager", "Energy-Manager-Konfiguration", "", Version.WARPEM, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration des Energy Managers", members={
            "default_mode": Elem.INT("Der nach einem Neustart des Energy Managers verwendete Lademodus", constants=[
                Const(0, "Schnell. Lädt Fahrzeuge so schnell wie möglich, selbst wenn dafür Netzbezug notwendig ist."),
                Const(1, "Aus. Fahrzeuge werden nicht geladen."),
                Const(2, "PV. Fahrzeuge werden nur vom PV-Überschuss geladen. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
                Const(3, "Min + PV. Erlaubt die konfigurierte Mindest-Ladeleistung (guaranteed_power), auch wenn diese (teilweise) aus dem Netz bezogen werden muss. Wenn ein größerer PV-Überschuss zur Verfügung steht, wird dieser verwendet. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
            ]),
            "auto_reset_mode": Elem.BOOL("Gibt an, ob der Lademodus (siehe {{{ref:energy_manager/charge_mode}}}) täglich auf den default_mode zurückgesetzt werden soll."),
            "auto_reset_time": Elem.INT("Die Zeit, zu der der Lademodus auf den default_mode zurückgesetzt wird, falls auto_reset_mode true ist. Wird als Minute des Tages angegeben, z.B. 134 = 02:14", unit=Units.min_),
            "excess_charging_enable": Elem.BOOL("Wenn aktiviert, regelt der Energy Manager die an ihn angeschlossenen Verbraucher abhängig vom Überschuss einer vorhandenen Photovoltaikanlage. Wenn deaktiviert, wird die maximale Leistung unter Einhaltung der maximale Strombelastbarkeit der Zuleitungen erlaubt."),
            "contactor_installed": Elem.BOOL("Gibt an, ob ein Schütz angeschlossen ist, mit dem die gesteuerten Wallboxen zwischen dreiphasigem und einphasigem Betrieb umgeschaltet werden können. Eingang 4 wird dann automatisch zur Schützüberwachung verwendet."),
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


            "relay_config": Elem.INT("", constants=[
                Const(0, "Manuelles Schalten. Das Relais kann über API (siehe TODO) und Webinterface geschaltet werden."),
                Const(1, "Regelbasiertes Schalten. Wenn die konfigurierte Bedingung 'relay_rule_when' den Wert 'relay_rule_is' annimmt, wird das Relais geschlossen."),
            ]),
            "relay_rule_when": Elem.INT("Wert, gegen den relay_rule_is geprüft werden soll. Es sind nur bestimmte relay_rule_when-Werte mit bestimmten relay_rule_is-Werten erlaubt.", constants=[
                Const(0, "Eingang 3. Erlaubte relay_rule_is-Werte: 0 (Eingang geöffnet), 1 (Eingang geschlossen)"),
                Const(1, "Eingang 4. Erlaubte relay_rule_is-Werte: 0 (Eingang geöffnet), 1 (Eingang geschlossen)"),
                Const(2, "Phasenumschaltung. Erlaubte relay_rule_is-Werte: 2 (einphasig), 3 (dreiphasig)"),
                Const(3, "Schützüberwachung. Erlaubte relay_rule_is-Werte: 4 (Schützfehler), 5 (Schütz OK)"),
                Const(4, "Leistung verfügbar. Erlaubte relay_rule_is-Werte: 6 (genügend Leistung für einen Ladevorgang verfügbar), 7 (nicht genügend Leistung für einen Ladevorgang verfügbar)"),
                Const(5, "Netzbezug. Erlaubte relay_rule_is-Werte: 8 (Netzbezug) , 9 (Netzeinspeisung)")
            ]),
            "relay_rule_is": Elem.INT("Wert gegen den relay_rule_when geprüft wird.", constants=[
                Const(0, "Eingang geöffnet. Erlaubte relay_rule_when-Werte: 0 (Eingang 3), 1 (Eingang 4)"),
                Const(1, "Eingang geschlossen. Erlaubte relay_rule_when-Werte:  0 (Eingang 3), 1 (Eingang 4)"),
                Const(2, "Einphasig. Erlaubter relay_rule_when-Wert: 2 (Phasenumschaltung)"),
                Const(3, "Dreiphasig. Erlaubter relay_rule_when-Wert: 2 (Phasenumschaltung)"),
                Const(4, "Schützfehler. Erlaubter relay_rule_when-Wert: 3 (Schützüberwachung)"),
                Const(5, "Schütz OK. Erlaubter relay_rule_when-Wert: 3 (Schützüberwachung)"),
                Const(6, "Genügend Leistung für einen Ladevorgang verfügbar. Erlaubter relay_rule_when-Wert: 4 (Leistung verfügbar)"),
                Const(7, "Nicht genügend Leistung für einen Ladevorgang verfügbar. Erlaubter relay_rule_when-Wert: 4 (Leistung verfügbar)"),
                Const(8, "Netzbezug. Es wird aktuell Energie aus dem Netz bezogen. Erlaubter relay_rule_when-Wert: 5 (Netzbezug)"),
                Const(9, "Netzeinspeisung. Es wird aktuell Energie ins Netz eingespeist. Erlaubter relay_rule_when-Wert: 5 (Netzbezug)"),
            ]),


            "input3_rule_then": Elem.INT("Verhalten des Eingangs 3. Die hier konfigurierte Aktion wird durchgeführt, wenn Eingang 3 den in input3_rule_is konfigurierten Wert hat.", constants=[
                Const(0, "Nicht verwendet."),
                Const(2, "Laden blockieren. Laufende Ladevorgänge werden unterbrochen und keine neuen Ladevorgänge freigegeben, solange die Bedingung zutrifft."),
                Const(3, "Ladestrom begrenzen. Der Ladestrom wird auf den in input3_rule_then_limit gesetzten Wert begrenzt, solange die Bedingung zutrifft. Wenn die Bedingung nicht (mehr) zutrifft, wird das Ladestrom-Limit wieder entfernt."),
                Const(4, "Lademodus wechseln. input3_rule_is wird nicht berücksichtigt. Wenn Eingang 3 geschlossen wird, wird auf den in input3_rule_then_on_high konfigurierten Modus gewechselt. Wenn Eingang 3 geöffnet wird, wird auf den in input3_rule_then_on_low konfigurierten Modus gewechselt."),
            ]),
            "input3_rule_is": Elem.INT("Wert, den Eingang 3 annehmen muss, damit die in input3_rule_then konfigurierte Aktion ausgeführt wird.", constants=[
                Const(0, "Geschlossen"),
                Const(1, "Offen"),
            ]),
            "input3_rule_then_limit": Elem.INT("Ladestrom-Limit, das gesetzt wird, falls input3_rule_then auf 3 (Ladestrom begrenzen) konfiguriert ist und Eingang 3 den in input3_rule_is konfigurierten Wert hat.", unit=Units.mA),
            "input3_rule_then_on_high": Elem.INT("Lademodus, in den gewechselt wird, falls input3_rule_then auf 4 (Moduswechsel) konfiguriert ist und Eingang 3 geschlossen wird.", constants=[
                Const(0, "Schnell."),
                Const(1, "Aus."),
                Const(2, "PV."),
                Const(3, "Min + PV."),
                Const(255, "Lademodus nicht wechseln."),
            ]),
            "input3_rule_then_on_low": Elem.INT("Lademodus, in den gewechselt wird, falls input3_rule_then auf 4 (Moduswechsel) konfiguriert ist und Eingang 3 geöffnet wird.", constants=[
                Const(0, "Schnell."),
                Const(1, "Aus."),
                Const(2, "PV."),
                Const(3, "Min + PV."),
                Const(255, "Lademodus nicht wechseln."),
            ]),


            "input4_rule_then": Elem.INT("Verhalten des Eingangs 4. Die hier konfigurierte Aktion wird durchgeführt, wenn Eingang 4 den in input4_rule_is konfigurierten Wert hat.", constants=[
                Const(0, "Nicht verwendet."),
                Const(1, "Schützüberwachung. Eingang wird zur Überwachung des Schützes verwendet, das die konfigurierten Wallboxen zwischen einphasigem und dreiphasigem Betrieb umschaltet."),
                Const(2, "Laden blockieren. Laufende Ladevorgänge werden unterbrochen und keine neuen Ladevorgänge freigegeben, solange die Bedingung zutrifft."),
                Const(3, "Ladestrom begrenzen. Der Ladestrom wird auf den in input4_rule_then_limit gesetzten Wert begrenzt, solange die Bedingung zutrifft. Wenn die Bedingung nicht (mehr) zutrifft, wird das Ladestrom-Limit wieder entfernt."),
                Const(4, "Lademodus wechseln. input4_rule_is wird nicht berücksichtigt. Wenn Eingang 4 geschlossen wird, wird auf den in input4_rule_then_on_high konfigurierten Modus gewechselt. Wenn Eingang 4 geöffnet wird, wird auf den in input4_rule_then_on_low konfigurierten Modus gewechselt."),
            ]),
            "input4_rule_is": Elem.INT("Wert, den Eingang 4 annehmen muss, damit die in input4_rule_then konfigurierte Aktion ausgeführt wird.", constants=[
                Const(0, "Geschlossen"),
                Const(1, "Offen"),
            ]),
            "input4_rule_then_limit": Elem.INT("Ladestrom-Limit, das gesetzt wird, falls input4_rule_then auf 3 (Ladestrom begrenzen) konfiguriert ist und Eingang 4 den in input4_rule_is konfigurierten Wert hat.", unit=Units.mA),
            "input4_rule_then_on_high": Elem.INT("Lademodus, in den gewechselt wird, falls input4_rule_then auf 4 (Moduswechsel) konfiguriert ist und Eingang 4 geschlossen wird.", constants=[
                Const(0, "Schnell."),
                Const(1, "Aus."),
                Const(2, "PV."),
                Const(3, "Min + PV."),
                Const(255, "Lademodus nicht wechseln."),
            ]),
            "input4_rule_then_on_low": Elem.INT("Lademodus, in den gewechselt wird, falls input4_rule_then auf 4 (Moduswechsel) konfiguriert ist und Eingang 4 geöffnet wird.", constants=[
                Const(0, "Schnell."),
                Const(1, "Aus."),
                Const(2, "PV."),
                Const(3, "Min + PV."),
                Const(255, "Lademodus nicht wechseln."),
            ]),
        })
    ),
    Func("meter_config", FuncType.CONFIGURATION, Elem.OBJECT("TODO", members={
            "meter_source": Elem.INT("Quelle der Stromzählerdaten", constants=[
                Const(0, "Keine Quelle konfiguriert"),
                Const(1, "SDM630*/SDM72* am WARP Energy Manager"),
                Const(100, "Benutzerdefiniter Zähler per MQTT/HTTP-API"),
            ]),
        })
    ),
    Func("state", FuncType.STATE, Elem.OBJECT("Zustand des Energy Managers", members={
            "phases_switched": Elem.INT("Zustand der Phasenumschaltung", constants=[
                Const(1, "Eine Phase verbunden"),
                Const(3, "Drei Phasen verbunden"),
            ]),
            "input3_state": Elem.BOOL("Zustand des Eingangs 3", constants=[
                Const(True, "Eingang geschlossen"),
                Const(False, "Eingang geöffnet"),
            ]),
            "input4_state": Elem.BOOL("Zustand des Eingangs 4", constants=[
                Const(True, "Eingang geschlossen"),
                Const(False, "Eingang geöffnet"),
            ]),
            "relay_state": Elem.BOOL("Zustand des Relais", constants=[
                Const(True, "Relais geschlossen"),
                Const(False, "Relais geöffnet"),
            ]),
            "error_flags": Elem.INT("Aktive Fehlerzustände des Energy Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Fehlerwerten auftreten können.", constants=[
                Const(0, "Kein Fehler"),
                Const("0x00000002", "Keine Netzwerkverbindung (LAN/WLAN)"),
                Const("0x00010000", "Schützüberwachung hat ausgelöst"),
                Const("0x01000000", "Interner Fehler, Bricklet nicht erreichbar"),
                Const("0x02000000", "Interner Fehler, SD-Karten-Fehler"),
            ]),
            "config_error_flags": Elem.INT("Aktive Konfigurationsfehler des Energy Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Konfigurationsfehlern auftreten können.", constants=[
                Const(0, "Kein Fehler"),
                Const("0x00000001", "Phasenumschaltung oder Schütz nicht konfiguriert"),
                Const("0x00000002", "Maximaler Gesamtstrom der Wallboxen nicht konfiguriert"),
                Const("0x00000004", "Keine Wallboxen konfiguriert"),
                Const("0x00000008", "Überschussladen aktiviert aber kein Stromzähler eingerichtet"),
                Const("0x00000010", "Lastmanagement nicht verfügbar"),
            ]),
            "external_control": Elem.INT("Status der externen Steuerung zur Phasenumschaltung.", constants=[
                Const(0, "Externe Steuerung bereit für Kommandos."),
                Const(1, "Externe Steuerung über die Einstellungen deaktiviert."),
                Const(2, "Externe Steuerung ist aktiviert aber aktuell nicht verfügbar. Gründe sind unter anderem: ausgelöste Schützüberwachung, eine oder mehrere Wallboxen nicht erreichbar oder unterstützen keine CP-Trennung, Ladung blockiert durch Eingang 3."),
                Const(3, "Phasenumschaltung wird gerade durchgeführt; ankommende Kommandos werden ignoriert."),
            ]),
        })
    ),
    Func("low_level_state", FuncType.STATE, Elem.OBJECT("Low-Level-Zustand des Energy Managers", members={
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
            "uptime_past_hysteresis": Elem.BOOL("Zeitraum nach einem Start des Energy Managers, in dem ohne Wartezeit umgeschaltet werden kann.", constants=[
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
            ]),
            "consecutive_bricklet_errors": Elem.INT("Anzahl aufeinander folgender interner Kommunikationsfehler"),

            "contactor": Elem.BOOL("Vom Energy Manager gesetzter Zustand des Schützes", constants=[
                Const(True, "Schütz geschlossen"),
                Const(False, "Schütz geöffnet"),
            ]),
            "contactor_check_state": Elem.INT("Zustand der Schützprüfung", constants=[
                Const(0, "Schützüberwachung hat ausgelöst (Schütz defekt)"),
                Const(1, "Kein Schützfehler bekannt (Schütz in Ordnung)"),
            ]),
            "input_voltage": Elem.INT("Interne Versorgungsspannung in Millivolt.", unit=Units.mV),
            "led_rgb": Elem.ARRAY("Farbe der Status-LED", members=[
                Elem.INT("Rot: 0 (aus) bis 255 (maximale Intensität)"),
                Elem.INT("Grün: 0 (aus) bis 255 (maximale Intensität)"),
                Elem.INT("Blau: 0 (aus) bis 255 (maximale Intensität)"),
            ]),
            "uptime": Elem.INT("Zeit seit Starten des Energy Manager Bricklets.<br/><br/>Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", unit=Units.ms)
        })
    ),
    Func("charge_mode", FuncType.STATE, Elem.OBJECT("Aktuell verwendeter Lademodus. Kann über energy_manager/charge_mode_update mit dem selben Payload aktualisiert werden.", members={
            "mode": Elem.INT("", constants=[
                Const(0, "Schnell. Lädt Fahrzeuge so schnell wie möglich, selbst wenn dafür Netzbezug notwendig ist."),
                Const(1, "Aus. Fahrzeuge werden nicht geladen."),
                Const(2, "PV. Fahrzeuge werden nur vom PV-Überschuss geladen. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
                Const(3, "Min + PV. Erlaubt die konfigurierte Mindest-Ladeleistung (guaranteed_power), auch wenn diese (teilweise) aus dem Netz bezogen werden muss. Wenn ein größerer PV-Überschuss zur Verfügung steht, wird dieser verwendet. Steht nur zur Verfügung, wenn excess_charging_enable true ist."),
            ])
        })
    ),
    Func("external_control", FuncType.STATE, Elem.OBJECT("Phasenanforderung für externe Steuerung. Nimmt über energy_manager/external_control_update Kommandos zur Phasenumschaltung an, wenn external_control in energy_manager/state 0 ist.", members={
            "phases_wanted": Elem.INT("", constants=[
                Const(0, "Keine Phasen angefordert, keine Stromfreigabe."),
                Const(1, "Eine Phase angefordert."),
                Const(3, "Drei Phasen angefordert."),
            ])
        })
    ),
    Func("sdcard_state", FuncType.STATE, Elem.OBJECT("Informationen über die eingelegte MicroSD-Karte.", members={
            "sd_status": Elem.INT("Status der SD-Karte", constants=[
                Const(0, "OK"),
                Const(1, "READ_BLOCK_TIMEOUT"),
                Const(2, "WRITE_BLOCK_TIMEOUT"),
                Const(3, "RESPONSE_TIMEOUT"),
                Const(11, "ERROR_INIT_TYPE"),
                Const(12, "ERROR_INIT_VER_OR_VOLTAGE"),
                Const(13, "ERROR_INIT_ACMD41"),
                Const(14, "ERROR_INIT_CMD58"),
                Const(15, "ERROR_INIT_CMD0"),
                Const(21, "ERROR_CID_START"),
                Const(22, "ERROR_CID_CMD10"),
                Const(31, "ERROR_CSD_START"),
                Const(32, "ERROR_CSD_CMD9"),
                Const(41, "ERROR_COUNT_TO_HIGH"),
                Const(51, "ERROR_NO_CARD"),
                Const(255, "ERROR_API_FAILURE"),
            ]),
            "lfs_status": Elem.INT("Status des Dateisystems (LittleFS) auf der SD-Karte", constants=[
                Const(0, "OK"),
                Const(255, "ERROR_API_FAILURE"),
                Const(256, "SD-Karte wird gerade formatiert")
            ]),
            "card_type": Elem.INT("SD-Kartentyp", constants=[
                Const(0, "Keine SD-Karte gefunden"),
                Const(1, "MMC"),
                Const(2, "SD"),
                Const(4, "SDSC"),
                Const(12, "SDHC/SDXC"),
            ]),
            "sector_count": Elem.INT("Größe der SD-Karte in Sektoren"),
            "sector_size": Elem.INT("Größe eines Sektors"),
            "manufacturer_id": Elem.INT("Hersteller-ID"),
            "product_rev": Elem.INT("Produktrevision"),
            "product_name": Elem.STRING("Produktname"),
        })
    ),
])
