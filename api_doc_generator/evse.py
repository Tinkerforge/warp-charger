from api_doc_common import *

evse = Module("evse", "Ladecontroller (EVSE)", "Benötigt das Feature <a href=\"#features_evse\"><code>\"evse\"</code></a>", Version.WARP1 | Version.WARP2,[
    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand des Ladecontrollers.", members={
            "iec61851_state": Elem.INT("Der aktuelle Zustand nach IEC 61851", constants=[
                    Const(0, "A: Nicht verbunden"),
                    Const(1, "B: Verbunden"),
                    Const(2, "C: Lädt"),
                    Const(3, "D: Lädt mit Belüftung (nicht unterstützt)"),
                    Const(4, "E/F: Fehler"),
            ]),
            "charger_state": Elem.INT("Der aktuelle Zustand, aufbereitet vom Ladecontroller", constants=[
                    Const(0, "Nicht verbunden"),
                    Const(1, "Warte auf Ladefreigabe"),
                    Const(2, "Ladebereit"),
                    Const(3, "Lädt"),
                    Const(4, "Fehler"),
            ]),
            "contactor_state": Elem.INT("Schützüberwachung. Überwacht wird die Spannung vor und nach dem Schütz", constants=[
                Const(0, "Nicht stromführend vor und nach dem Schütz"),
                Const(1, "Stromführend vor, aber nicht stromführend nach dem Schütz"),
                Const(2, "Nicht stromführend vor, aber stromführend nach dem Schütz"),
                Const(3, "Stromführend vor und nach dem Schütz"),
            ]),
            "contactor_error": Elem.INT("Fehlercode der Schützüberwachung. Ein Wert ungleich 0 zeigt einen Fehler an.", constants=[
                Const(0, "Kein Fehler"),
                Const(1, "Schütz sollte durchschalten.<br/><span class=\"pe-4\"></span>Kein Strom vor Schütz, kein Strom nach Schütz.<br/><span class=\"pe-4\"></span>Stromversorgung prüfen."),
                Const(2, "Schütz sollte durchschalten.<br/><span class=\"pe-4\"></span>Strom vor Schütz, kein Strom nach Schütz.<br/><span class=\"pe-4\"></span>Schütz defekt?"),
                Const(3, "Schütz sollte durchschalten.<br/><span class=\"pe-4\"></span>Kein Strom vor Schütz, Strom nach Schütz.<br/><span class=\"pe-4\"></span>Verkabelung prüfen."),
                Const(4, "Schütz sollte <strong>nicht</strong> durchschalten.<br/><span class=\"pe-4\"></span>Kein Strom vor Schütz, kein Strom nach Schütz.<br/><span class=\"pe-4\"></span>Stromversorgung prüfen."),
                Const(5, "Schütz sollte <strong>nicht</strong> durchschalten.<br/><span class=\"pe-4\"></span>Kein Strom vor Schütz, Strom nach Schütz.<br/><span class=\"pe-4\"></span>Verkabelung prüfen."),
                Const(6, "Schütz sollte <strong>nicht</strong> durchschalten.<br/><span class=\"pe-4\"></span>Strom vor Schütz, Strom nach Schütz.<br/><span class=\"pe-4\"></span>Schütz defekt?"),
            ]),
            "allowed_charging_current": Elem.INT("Maximal erlaubter Ladestrom, der dem Fahrzeug zur Verfügung gestellt wird. Dieser Strom ist das Minimum der Stromgrenzen aller Ladeslots.", unit=Units.mA),
            "error_state": Elem.INT('Der aktuelle Fehlerzustand. <a href="https://www.warp-charger.com/#documents">Siehe Handbuch für Details.</a>', constants=[
                Const(0, "OK"),
                Const(2, "Schalterfehler"),
                Const(3, "DC-Fehlerstromüberwachungsfehler"),
                Const(4, "Schützfehler"),
                Const(5, "Kommunikationsfehler"),
            ]),
            "lock_state": Elem.INT("Zustand der Kabelverriegelung (nur relevant für Wallboxen mit Typ-2-Dose)", constants=[
                Const(0, "Initialisierung"),
                Const(1, "Offen"),
                Const(2, "Schließend"),
                Const(3, "Geschlossen"),
                Const(4, "Öffnend"),
                Const(5, "Fehler"),
            ]),
            "dc_fault_current_state": Elem.INT("Der Zustand des DC-Fehlerstrom-Schutzmoduls. Falls ein Gleichstromfehler auftritt, kann nicht mehr geladen werden, bis das Schutzmodul zurückgesetzt wurde. <strong>Vor dem Zurücksetzen muss der Grund des Fehlers unbedingt behoben werden!</strong> {{{ref:evse/reset_dc_fault_current_state}}} setzt das Modul zurück.", constants=[
                Const(0, "Kein Fehler"),
                Const(1, "6 mA Fehlerstrom detektiert"),
                Const(2, "Systemfehler"),
                Const(3, "Unbekannter fehler"),
                Const(4, "Kalibrierungsfehler"),
            ], version=Version.WARP2)
        })
    ),

    Func("hardware_configuration", FuncType.STATE, Elem.OBJECT("Die Hardwarekonfiguration des Ladecontrollers.", members={
            "jumper_configuration": Elem.INT("Der Maximalstrom des eingehenden Kabels. Dieser Strom wird auf dem Ladecontroller durch Jumper oder eine Steckplatine mit Schaltern konfiguriert.", constants=[
                    Const(0, "6 Ampere"),
                    Const(1, "10 Ampere"),
                    Const(2, "13 Ampere"),
                    Const(3, "16 Ampere"),
                    Const(4, "20 Ampere"),
                    Const(5, "25 Ampere"),
                    Const(6, "32 Ampere"),
                    Const(7, "Kontrolliert durch Software"),
                    Const(8, "Nicht konfiguriert"),
            ]),
            "has_lock_switch": Elem.BOOL("Gibt an, ob die Wallbox über eine Kabelverriegelung verfügt.", constants=[
                Const(False, "Wallbox hat fest angeschlagenes Typ-2-Ladekabel"),
                Const(True, "Wallbox hat eine Typ-2-Dose mit Kabelverriegelung"),
            ]),
            "evse_version": Elem.INT("Hardware-Version des Ladecontrollers", constants=[
                Const(14, "EVSE 1.4", Version.WARP1),
                Const(15, "EVSE 1.5", Version.WARP1),
                Const(20, "EVSE 2.0", Version.WARP2)
            ]),
            "energy_meter_type": Elem.INT("Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jeder Wallbox unterstützt!", constants=[
                Const(0, "Kein Stromzähler verfügbar"),
                Const(1, "SDM72", Version.WARP1),
                Const(2, "SDM630", Version.WARP2),
                Const(3, "SDM72V2", Version.WARP2)
            ], version=Version.WARP2)
        })
    ),

    Func("slots", FuncType.STATE, Elem.ARRAY("Der Zustand der Ladeslots. Siehe TODO LINK für Details.", members=[
            * 13 * [Elem.OBJECT("Ein Ladeslot", members = {
                "max_current": Elem.INT("Maximal erlaubter Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", unit=Units.mA),
                "active": Elem.BOOL("Gibt an ob dieser Slot aktiv ist.", constants=[
                    Const(True, "Slot ist aktiv"),
                    Const(False, "Slot ist nicht aktiv"),
                ]),
                "clear_on_disconnect": Elem.BOOL("Gibt an, ob der Ladestrom dieses Slots beim Abziehen eines Fahrzeugs auf 0 gesetzt wird.", constants=[
                    Const(True, "Slot wird beim Abziehen blockieren"),
                    Const(False, "Slot wird gesetzten Ladestrom beim Abziehen beibehalten"),
                ]),
            })]
        ])
    ),

    Func("button_state", FuncType.STATE, Elem.OBJECT("Der Zustand des Tasters in der Frontblende.", members= {
            "button_press_time": Elem.INT("Zeit zu der zuletzt der Taster gedrückt wurde. 0 falls der Taster seit dem Start des Ladecontrollers nicht betätigt wurde.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", unit=Units.ms),
            "button_release_time": Elem.INT("Zeit zu der zuletzt der Taster losgelassen wurde. 0 falls der Taster seit dem Start des Ladecontrollers nicht betätigt wurde.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", unit=Units.ms),
            "button_pressed": Elem.BOOL("true, falls der Taster derzeit gedrückt ist, sonst false"),
        })
    ),

    Func("indicator_led", FuncType.STATE, Elem.OBJECT("Der Zustand der LED im Taster", members={
            "indication": Elem.INT("Aktuell gesetzter Zustand.", constants=[
                Const(-1, "EVSE kontrolliert LED"),
                Const(0, "Aus"),
                Const("1..254", "Per PWM gedimmtes leuchten"),
                Const(255, "An"),
                Const(1001, "Bestätigendes Blinken (z.B: NFC-Tag wurde erkannt)"),
                Const(1002, "Ablehnendes Blinken (z.B: NFC-Tag ist unbekannt)"),
                Const(1003, "Aufforderndes Blinken (z.B: NFC-Tag wird zum Laden benötigt)"),
            ]),
            "duration": Elem.INT("Dauer für die der gesetzte Zustand erhalten bleibt.", unit=Units.ms)
        })
    ),

    Func("low_level_state", FuncType.STATE, Elem.OBJECT("Der Low-Level-Zustand des Ladecontrollers.", members={
            "led_state": Elem.INT("Der Zustand der am Ladecontroller angeschlossenen LED", constants=[
                    Const(0, "Aus"),
                    Const(1, "An"),
                    Const(2, "Blinkt"),
                    Const(3, "Flackert"),
                    Const(4, "Atmet"),
                    Const(5, "API, siehe {{{ref:evse/indicator_led}}}"),
            ]),
            "cp_pwm_duty_cycle": Elem.INT("Tastverhältnis der Pulsweitenmodulation auf dem CP-Signal.", unit=Units.tenth_percent),
            "adc_values": Elem.ARRAY("16-Bit ADC-Rohwerte der Spannungsmessungen", members=[
                Elem.INT("CP/PE", version=Version.WARP1),
                Elem.INT("PP/PE", version=Version.WARP1),

                Elem.INT("CP/PE vor Widerstand (PWM High)", version=Version.WARP2),
                Elem.INT("CP/PE nach Widerstand (PWM High)", version=Version.WARP2),
                Elem.INT("CP/PE vor Widerstand (PWM Low)", version=Version.WARP2),
                Elem.INT("CP/PE nach Widerstand (PWM Low)", version=Version.WARP2),
                Elem.INT("PP/PE", version=Version.WARP2),
                Elem.INT("+12V Rail", version=Version.WARP2),
                Elem.INT("-12V Rail", version=Version.WARP2),
            ]),
            "voltages": Elem.ARRAY("Aus den ADC-Werten berechnete Spannungen", unit=Units.mV, members=[
                Elem.INT("CP/PE", version=Version.WARP1),
                Elem.INT("PP/PE", version=Version.WARP1),
                Elem.INT("Maximalspannung CP/PE", version=Version.WARP1),

                Elem.INT("CP/PE vor Widerstand (PWM High)", version=Version.WARP2),
                Elem.INT("CP/PE nach Widerstand (PWM High)", version=Version.WARP2),
                Elem.INT("CP/PE vor Widerstand (PWM Low)", version=Version.WARP2),
                Elem.INT("CP/PE nach Widerstand (PWM Low)", version=Version.WARP2),
                Elem.INT("PP/PE", version=Version.WARP2),
                Elem.INT("+12V Rail", version=Version.WARP2),
                Elem.INT("-12V Rail", version=Version.WARP2),
            ]),
            "resistances": Elem.ARRAY("Aus den Spannungen berechnete Widerstände", unit=Units.ohm, members=[
                Elem.INT("CP/PE"),
                Elem.INT("PP/PE"),
            ]),
            "gpio": Elem.ARRAY("Signale auf den GPIOs", members=[
                Elem.BOOL("Eingang", version=Version.WARP1),
                Elem.BOOL("Ausgang", version=Version.WARP1),
                Elem.BOOL("Motoreingangsschalter", version=Version.WARP1),
                Elem.BOOL("Relais", version=Version.WARP1),
                Elem.BOOL("Motorfehler", version=Version.WARP1),

                Elem.BOOL("Stromkonfiguration 0", version=Version.WARP2),
                Elem.BOOL("Motorfehler", version=Version.WARP2),
                Elem.BOOL("Gleichstromfehler", version=Version.WARP2),
                Elem.BOOL("Stromkonfiguration 1", version=Version.WARP2),
                Elem.BOOL("DC-Fehlerstromschutz-Test", version=Version.WARP2),
                Elem.BOOL("Abschaltung", version=Version.WARP2),
                Elem.BOOL("Taster", version=Version.WARP2),
                Elem.BOOL("CP-PWM", version=Version.WARP2),
                Elem.BOOL("Motoreingangsschalter", version=Version.WARP2),
                Elem.BOOL("Schützsteuerung", version=Version.WARP2),
                Elem.BOOL("Konfigurierbarer Ausgang", version=Version.WARP2),
                Elem.BOOL("CP-Trennung", version=Version.WARP2),
                Elem.BOOL("Motor aktiv", version=Version.WARP2),
                Elem.BOOL("Motor-Phase", version=Version.WARP2),
                Elem.BOOL("Schützprüfung vorher", version=Version.WARP2),
                Elem.BOOL("Schützprüfung nachher", version=Version.WARP2),
                Elem.BOOL("Konfigurierbarer Eingang", version=Version.WARP2),
                Elem.BOOL("DC X6", version=Version.WARP2),
                Elem.BOOL("DC X30", version=Version.WARP2),
                Elem.BOOL("LED", version=Version.WARP2),
                Elem.BOOL("Nicht belegt", version=Version.WARP2),
                Elem.BOOL("Nicht belegt", version=Version.WARP2),
                Elem.BOOL("Nicht belegt", version=Version.WARP2),
                Elem.BOOL("Nicht belegt", version=Version.WARP2),
            ]),
            "charging_time": Elem.INT("Ungefähre Zeit des Ladevorgangs. Nur für Lastmanagementzwecke zu verwenden!", unit=Units.ms),
            "time_since_state_change": Elem.INT("Zeit seit dem letzten IEC-61851-Zustandswechsel. Falls der Zustand 2 (= B: Lädt) ist, entspricht dieser Wert der Ladezeit.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", unit=Units.ms),
            "uptime": Elem.INT("Zeit seit Starten des Ladecontrollers.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", unit=Units.ms)
        })
    ),

    Func("external_current", FuncType.STATE, Elem.OBJECT("Der von der externen Steuerung vorgegebene Ladestrom. Kann über evse/external_current_update mit dem selben Payload gesetzt werden.", members={
            "current": Elem.INT("Der von der externen Steuerung vorgegebene Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", unit=Units.mA)
        })
    ),

    Func("external_clear_on_disconnect", FuncType.STATE, Elem.OBJECT("Gibt an, ob der von der externen Ladesteuerung vorgegebene Ladestrom beim Abziehen eines Fahrzeugs automatisch auf 0 gesetzt werden soll. Kann über evse/external_clear_on_disconnect_update mit dem selben Payload gesetzt werden.", members={
            "clear_on_disconnect": Elem.BOOL("Gibt an, ob der Ladestrom dieses Slots beim Abziehen eines Fahrzeugs auf 0 gesetzt wird.", constants=[
                Const(True, "Slot wird beim Abziehen blockieren"),
                Const(False, "Slot wird gesetzten Ladestrom beim Abziehen beibehalten"),
            ])
        })
    ),

    Func("management_current", FuncType.STATE, Elem.OBJECT("Der vom Lastmanagement vorgegebene Ladestrom. Kann über evse/management_current_update mit dem selben Payload gesetzt werden.", members={
            "current": Elem.INT("6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockieren soll.", unit=Units.mA)
        })
    ),

    Func("auto_start_charging", FuncType.STATE, Elem.OBJECT("Konfiguriert, ob ein angeschlossenes Fahrzeug selbstständig geladen wird. Dieser Wert kann über evse/auto_start_charging_update mit dem selben Payload aktualisiert werden.", members={
            "auto_start_charging": Elem.BOOL("Konfiguriert, ob ein angeschlossenes Fahrzeug selbstständig geladen wird. Falls aktiviert, beginnt sofort, wenn das Fahrzeug angeschlossen wird der Ladevorgang. Falls deaktiviert, kann das Laden mit {{{ref:evse/start_charging}}} gestartet werden."),
        })
    ),

    Func("global_current", FuncType.STATE, Elem.OBJECT("Der über das Webinterface vorgegebene Ladestrom. Kann über evse/global_current_update mit dem selben Payload gesetzt werden.", members={
            "current": Elem.INT("Der über das Webinterface vorgegebene Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", unit=Units.mA)
        })
    ),

    Func("management_enabled", FuncType.STATE, Elem.OBJECT("Gibt an, ob der Ladeslot des Lastmanagements aktiv ist. Der Wert kann über evse/management_enabled_update mit dem selben Payload aktualisiert werden.", members={
            "enabled": Elem.BOOL("true wenn Lastmanagement aktiviert ist, sonst false")
        })
    ),

    Func("user_current", FuncType.STATE, Elem.OBJECT("Der von der Benutzerautorisierung erlaubte Ladestrom.", members={
            "current": Elem.INT("Der von der Benutzerautorisierung erlaubte Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", unit=Units.mA)
        })
    ),

    Func("user_enabled", FuncType.STATE, Elem.OBJECT("Gibt an, ob der Ladeslot der Benutzerautorisierung aktiv ist. Der Wert kann über evse/user_enabled_update mit dem selben Payload aktualisiert werden.", members={
            "enabled": Elem.BOOL("true wenn die Benutzerautorisierung aktiviert ist, sonst false")
        })
    ),

    Func("external_enabled", FuncType.STATE, Elem.OBJECT("Gibt an, ob der Ladeslot der externen Steuerung aktiv ist. Der Wert kann über evse/external_enabled_update mit dem selben Payload aktualisiert werden.", members={
            "enabled": Elem.BOOL("true wenn die externe Steuerung aktiviert ist, sonst false")
        })
    ),

    Func("external_defaults", FuncType.STATE, Elem.OBJECT("Die nach einem Neustart des Ladecontrollers übernommenen Einstellungen des Ladeslots der externen Steuerung. Der Wert kann über evse/external_defaults_update mit dem selben Payload aktualisiert werden.", members={
            "current": Elem.INT("Der nach einem Neustart übernommene Maximalstrom im Ladeslot der externen Steuerung. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", unit=Units.mA),
            "clear_on_disconnect": Elem.BOOL("Gibt an, ob der Ladestrom dieses Slots beim Abziehen eines Fahrzeugs auf 0 gesetzt wird.", constants=[
                Const(True, "Slot wird beim Abziehen blockieren"),
                Const(False, "Slot wird gesetzten Ladestrom beim Abziehen beibehalten"),
            ]),
        })
    ),

    Func("modbus_tcp_enabled", FuncType.STATE, Elem.OBJECT("Gibt an, ob die Ladeslots für Modbus-TCP aktiv sind (und damit ob Modbus-TCP Schreibzugriff gewährt wurde). Der Wert kann über evse/modbus_tcp_enabled_update mit dem selben Payload aktualisiert werden.", members={
            "enabled": Elem.BOOL("true wenn die Ladeslots für Modbus-TCP aktiviert sind, sonst false")
        })
    ),

    Func("ocpp_enabled", FuncType.STATE, Elem.OBJECT("Gibt an, ob der Ladeslot für OCPP aktiv ist. Der Wert kann über evse/ocpp_enabled_update mit dem selben Payload aktualisiert werden.", members={
            "enabled": Elem.BOOL("true wenn OCPP aktiviert ist, sonst false")
        })
    ),

    Func("gpio_configuration", FuncType.STATE, Elem.OBJECT("Die Konfiguration der konfigurierbaren Ein- und Ausgänge. Kann über evse/gpio_configuration_update mit dem selben Payload aktualisiert werden.", members={
            "shutdown_input": Elem.INT("Die Konfiguration des Abschalteingangs.", constants=[
                Const(0, "Nicht konfiguriert"),
                Const(1, "Abschalten wenn geöffnet"),
                Const(2, "Abschalten wenn geschlossen"),
            ]),
            "input": Elem.INT("Die Konfiguration des konfigurierbaren Eingangs.", constants=[
                Const(0, "Nicht konfiguriert"),
                Const(1, "Blockiert wenn geschlossen"),
                Const(2, "Limitiert auf 6 A wenn geschlossen"),
                Const(3, "Limitiert auf 8 A wenn geschlossen"),
                Const(4, "Limitiert auf 10 A wenn geschlossen"),
                Const(5, "Limitiert auf 13 A wenn geschlossen"),
                Const(6, "Limitiert auf 16 A wenn geschlossen"),
                Const(7, "Limitiert auf 20 A wenn geschlossen"),
                Const(8, "Limitiert auf 25 A wenn geschlossen"),
                Const(9, "Blockiert wenn geöffnet"),
                Const(10, "Limitiert auf 6 A wenn geöffnet"),
                Const(11, "Limitiert auf 8 A wenn geöffnet"),
                Const(12, "Limitiert auf 10 A wenn geöffnet"),
                Const(13, "Limitiert auf 13 A wenn geöffnet"),
                Const(14, "Limitiert auf 16 A wenn geöffnet"),
                Const(15, "Limitiert auf 20 A wenn geöffnet"),
                Const(16, "Limitiert auf 25 A wenn geöffnet"),
            ]),
            "output": Elem.INT("Die Konfiguration des konfigurierbaren Ausgangs.", constants=[
                Const(0, "Verbunden mit Masse"),
                Const(1, "Hochohmig"),
            ]),
        },
        version=Version.WARP2)
    ),

    Func("button_configuration", FuncType.STATE, Elem.OBJECT("Die Konfiguration des Tasters in der Frontblende. Diese kann über evse/button_configuration_update mit dem selben Payload aktualisiert werden. Benötigt das Feature <a href=\"#features_button_configuration\"><code>\"button_configuration\"</code></a>", members={
            "button": Elem.INT("Die Konfiguration des Tasters in der Frontblende.", constants=[
                Const(0, "Deaktiviert"),
                Const(1, "Ladestart wenn gedrückt"),
                Const(2, "Ladestop wenn gedrückt"),
                Const(3, "Ladestart/stop wenn gedrückt"),
            ]),
        },
        version=Version.WARP2)
    ),

    Func("user_calibration", FuncType.STATE, Elem.OBJECT("Erlaubt es, die werksseitige Kalibrierung des EVSEs auszulesen und zu überschreiben. Dieser Wert kann über evse/user_calibration_update mit dem selben Payload aktualisiert werden. Um die Kalibierung auf den Werkszustand zurückzusetzen, kann ein Payload mit user_calibration_active auf false geschickt werden. Die weiteren Werte werden dann ignoriert.", members={
            "user_calibration_active": Elem.BOOL("Gibt an, ob die werksseitige Kalibrierung überschrieben wurde."),
            "voltage_diff": Elem.INT("Einer der Kalibrierungsparameter."),
            "voltage_mul": Elem.INT("Einer der Kalibrierungsparameter."),
            "voltage_div": Elem.INT("Einer der Kalibrierungsparameter."),
            "resistance_2700": Elem.INT("Einer der Kalibrierungsparameter."),
            "resistance_880": Elem.ARRAY("Einer der Kalibrierungsparameter.", member_type=EType.INT),
        },
        version=Version.WARP1)
    ),

    Func("ev_wakeup", FuncType.STATE, Elem.OBJECT("Gibt an, ob das EVSE automatisch versucht die Ladeelektronik des Fahrzeugs aus einem Energiesparmodus zu wecken, indem ein Abziehen und Anstecken des Ladekabels vorgetäuscht wird. (Control-Pilot-Trennung/CP-Trennung) Dieser Wert kann über evse/ev_wakeup_update mit dem selben Payload aktualisiert werden. Benötigt das Feature <a href=\"#features_cp_disconnect\"><code>\"cp_disconnect\"</code></a>", version=Version.WARP2, members={
            "enabled": Elem.BOOL("true wenn die Ladeelektronik des Fahrzeugs geweckt werden soll")
        })
    ),

    Func("control_pilot_disconnect", FuncType.STATE, Elem.OBJECT("Gibt an, ob ein Abziehen und Anstecken des Ladekabels vorgetäuscht ist. (Control-Pilot-Trennung/CP-Trennung) Dieser Wert kann über evse/control_pilot_disconnect_update mit dem selben Payload aktualisiert werden. <strong>Aktualisierungen werden ignoriert, falls das Lastmanagement aktiviert ist.</strong> Siehe {{{ref:evse/management_enabled}}}.  Benötigt das Feature <a href=\"#features_cp_disconnect\"><code>\"cp_disconnect\"</code></a>", version=Version.WARP2, members={
            "disconnect": Elem.BOOL("true CP getrennt ist, sonst false")
        })
    ),

     Func("boost_mode", FuncType.STATE, Elem.OBJECT("Gibt an, ob das EVSE der Ladeelektronik des Fahrzeugs einen leicht höheren Ladestrom vorgibt (+ 0,24 A) um Messfehler der Ladeelektronik zu kompensieren. Nur Verwenden, falls ein Fahrzeug mit einem kleineren als dem erlaubten Ladestrom lädt! Dieser Wert kann über evse/boost_mode_update mit dem selben Payload aktualisiert werden.", members={
            "enabled": Elem.BOOL("true CP getrennt ist, sonst false")
        })
    ),

    Func("reset_dc_fault_current_state", FuncType.COMMAND, Elem.OBJECT("Setzt das DC-Fehlerstrom-Schutzmodul zurück. <strong>Vor dem Zurücksetzen muss der Grund des Fehlers unbedingt behoben werden!</strong>", version=Version.WARP2, members={
            "password": Elem.INT("Passwort, das zum Zurücksetzen benötigt wird. Das Passwort lautet 0xDC42FA23.")
        })
    ),

    Func("stop_charging", FuncType.COMMAND, Elem.NULL("Beendet den laufenden Ladevorgang. Ein Aufruf dieser Funktion ist äquivalent zum Stoppen über den Taster an der Wallbox: Es wird TODO LINK Slot 4 blockiert. Ein Ladevorgang kann mit {{{ref:evse/start_charging}}} wieder gestartet werden."), command_is_action=True),

    Func("start_charging", FuncType.COMMAND, Elem.NULL("Startet einen Ladevorgang. Ein Aufruf dieser Funktion ist äquivalent zum Starten über den Taster an der Wallbox: Es wird TODO LINK Slot 4 freigegeben. Ein Ladevorgang kann mit {{{ref:evse/stop_charging}}} wieder gestoppt werden."), command_is_action=True),

    Func("start_debug", FuncType.HTTP_ONLY, Elem.OPAQUE("Startet ein Ladeprotokoll. Es werden hochfrequent Messwerte des Ladecontrollers auf die WebSockets geschrieben, bis {{{ref:evse/stop_debug}}} aufgerufen wird.")),
    Func("stop_debug", FuncType.HTTP_ONLY, Elem.OPAQUE("Stoppt ein Ladeprotokoll. Siehe {{{ref:evse/start_debug}}} für Details."))
])
