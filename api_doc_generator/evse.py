from api_doc_common import *

evse = Module("evse", "Ladecontroller (EVSE)", "", Version.ANY,[
    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand des Ladecontrollers.", members={
            "iec61851_state": Elem.INT("Der aktuelle Zustand nach IEC 61851", constants=[
                    Const(0, "A: Nicht verbunden (Sicht des Fahrzeugs)"),
                    Const(1, "B: Verbunden"),
                    Const(2, "C: Lädt"),
                    Const(3, "D: Lädt mit Belüftung (nicht unterstützt)"),
                    Const(4, "E/F: Fehler"),
            ]),
            "vehicle_state": Elem.INT("Der aktuelle Zustand, aufbereitet vom Ladecontroller", constants=[
                    Const(0, "Nicht verbunden (Sicht der Wallbox)"),
                    Const(1, "Verbunden"),
                    Const(2, "Lädt"),
                    Const(3, "Fehler"),
            ]),
            "contactor_state": Elem.INT("Schützüberwachung. Überwacht wird die Spannung vor und nach dem Schütz", constants=[
                Const(0, "Nicht stromführend vor und nach dem Schütz"),
                Const(1, "Nicht stromführend vor, aber stromführend nach dem Schütz"),
                Const(2, "Stromführend vor, aber nicht stromführend nach dem Schütz"),
                Const(3, "Stromführend vor und nach dem Schütz"),
            ]),
            "contactor_error": Elem.INT("Fehlercode der Schützüberwachung. Ein Wert ungleich 0 zeigt einen Fehler an."),
            "charge_release": Elem.INT("Ladefreigabe. Gibt an, ob automatisch, manuell oder nicht geladen werden kann.", constants=[
                Const(0, "Automatisch: Sobald ein Fahrzeug angeschlossen wird, kann es mit dem Laden beginnen. Dieser Modus ist aktiv, wenn {{{ref:evse/auto_start_charging}}} aktiviert ist und das Laden nicht abgebrochen wurde."),
                Const(1, "Manuell: Wenn ein Fahrzeug angeschlossen wird, wird es erst geladen, wenn das Laden manuell freigegeben wird. Dieser Modus wird aktiviert, wenn {{{ref:evse/auto_start_charging}}} deaktiviert, der Knopf an der Wallbox gedrückt oder evse/stop_charging aufgerufen wird. Die manuelle Freigabe kann über das Webinterface, oder durch einen API-Aufruf von {{{ref:evse/start_charging}}} erfolgen."),
                Const(2, "Deaktiviert: Das Laden ist blockiert, da die Wallbox entweder in einem Fehlerzustand ist, oder durch den Schlüsselschalter deaktiviert wurde."),
            ]),
            "allowed_charging_current": Elem.INT("Maximal erlaubter Ladestrom, der dem Fahrzeug zur Verfügung gestellt wird. Dieser Strom ist das Minimum folgender Ströme:<ul><li>Maximaler Strom des eingehenden Kabels</li><li>Maximaler Strom des ausgehenden Kabels</li><li>Maximaler Strom, der über MQTT oder das Webinterface konfiguriert wurde</li></ul>", unit=Units.mA),
            "error_state": Elem.INT('Der aktuelle Fehlerzustand. <a href="https://www.warp-charger.com/#documents">Siehe Handbuch für Details.</a>', constants=[
                Const(0, "OK"),
                Const(1, "Schalterfehler"),
                Const(2, "Kalibrierungsfehler"),
                Const(3, "Schützfehler"),
                Const(4, "Kommunikationsfehler"),
            ]),
            "lock_state": Elem.INT("Zustand der Kabelverriegelung (nur relevant für Wallboxen mit Typ-2-Dose)", constants=[
                Const(0, "Initialisierung"),
                Const(1, "Offen"),
                Const(2, "Schließend"),
                Const(3, "Geschlossen"),
                Const(4, "Öffnend"),
                Const(5, "Fehler"),
            ]),
            "time_since_state_change": Elem.INT("Zeit seit dem letzten IEC-61851-Zustandswechsel. Falls der Zustand 2 (= B: Lädt) ist, entspricht dieser Wert der Ladezeit.", unit=Units.ms),
            "uptime": Elem.INT("Zeit seit Starten des Ladecontrollers.", unit=Units.ms)
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
            ])
        })
    ),

    Func("low_level_state", FuncType.STATE, Elem.OBJECT("Der Low-Level-Zustand des Ladecontrollers.", members={
            "low_level_mode_enabled": Elem.BOOL("Zeigt an, ob der Low-Level-Modus aktiv ist. Wird derzeit nicht unterstützt.", version=Version.WARP1_ONLY),
            "led_state": Elem.INT("Der Zustand der am Ladecontroller angeschlossenen LED", constants=[
                    Const(0, "Aus"),
                    Const(1, "An"),
                    Const(2, "Blinkt"),
                    Const(3, "Flackert"),
                    Const(4, "Atmet"),
            ]),
            "cp_pwm_duty_cycle": Elem.INT("Tastverhältnis der Pulsweitenmodulation auf dem CP-Signal.", unit=Units.tenth_percent),
            "adc_values": Elem.ARRAY("16-Bit ADC-Rohwerte der Spannungsmessungen", members=[
                Elem.INT("CP/PE", version=Version.WARP1_ONLY),
                Elem.INT("PP/PE", version=Version.WARP1_ONLY),

                Elem.INT("CP/PE vor Widerstand (PWM High)", version=Version.WARP2_ONLY),
                Elem.INT("CP/PE nach Widerstand (PWM High)", version=Version.WARP2_ONLY),
                Elem.INT("CP/PE vor Widerstand (PWM Low)", version=Version.WARP2_ONLY),
                Elem.INT("CP/PE nach Widerstand (PWM Low)", version=Version.WARP2_ONLY),
                Elem.INT("PP/PE", version=Version.WARP2_ONLY),
                Elem.INT("+12V Rail", version=Version.WARP2_ONLY),
                Elem.INT("-12V Rail", version=Version.WARP2_ONLY),
            ]),
            "voltages": Elem.ARRAY("Aus den ADC-Werten berechnete Spannungen", unit=Units.mV, members=[
                Elem.INT("CP/PE", version=Version.WARP1_ONLY),
                Elem.INT("PP/PE", version=Version.WARP1_ONLY),
                Elem.INT("Maximalspannung CP/PE", version=Version.WARP1_ONLY),

                Elem.INT("CP/PE vor Widerstand (PWM High)", version=Version.WARP2_ONLY),
                Elem.INT("CP/PE nach Widerstand (PWM High)", version=Version.WARP2_ONLY),
                Elem.INT("CP/PE vor Widerstand (PWM Low)", version=Version.WARP2_ONLY),
                Elem.INT("CP/PE nach Widerstand (PWM Low)", version=Version.WARP2_ONLY),
                Elem.INT("PP/PE", version=Version.WARP2_ONLY),
                Elem.INT("+12V Rail", version=Version.WARP2_ONLY),
                Elem.INT("-12V Rail", version=Version.WARP2_ONLY),
            ]),
            "resistances": Elem.ARRAY("Aus den Spannungen berechnete Widerstände", unit=Units.ohm, members=[
                Elem.INT("CP/PE"),
                Elem.INT("PP/PE"),
            ]),
            "gpio": Elem.ARRAY("Signale auf den GPIOs", members=[
                Elem.BOOL("Eingang", version=Version.WARP1_ONLY),
                Elem.BOOL("Ausgang", version=Version.WARP1_ONLY),
                Elem.BOOL("Motoreingangsschalter", version=Version.WARP1_ONLY),
                Elem.BOOL("Relais", version=Version.WARP1_ONLY),
                Elem.BOOL("Motorfehler", version=Version.WARP1_ONLY),

                Elem.BOOL("Stromkonfiguration 0", version=Version.WARP2_ONLY),
                Elem.BOOL("Motorfehler", version=Version.WARP2_ONLY),
                Elem.BOOL("Gleichstromfehler", version=Version.WARP2_ONLY),
                Elem.BOOL("Stromkonfiguration 1", version=Version.WARP2_ONLY),
                Elem.BOOL("DC-Fehlerstromschutz-Test", version=Version.WARP2_ONLY),
                Elem.BOOL("Abschaltung", version=Version.WARP2_ONLY),
                Elem.BOOL("Taster", version=Version.WARP2_ONLY),
                Elem.BOOL("CP-PWM", version=Version.WARP2_ONLY),
                Elem.BOOL("Motoreingangsschalter", version=Version.WARP2_ONLY),
                Elem.BOOL("Schützsteuerung", version=Version.WARP2_ONLY),
                Elem.BOOL("Konfigurierbarer Ausgang", version=Version.WARP2_ONLY),
                Elem.BOOL("CP-Trennung", version=Version.WARP2_ONLY),
                Elem.BOOL("Motor aktiv", version=Version.WARP2_ONLY),
                Elem.BOOL("Motor-Phase", version=Version.WARP2_ONLY),
                Elem.BOOL("Schützprüfung vorher", version=Version.WARP2_ONLY),
                Elem.BOOL("Schützprüfung nachher", version=Version.WARP2_ONLY),
                Elem.BOOL("Konfigurierbarer Eingang", version=Version.WARP2_ONLY),
                Elem.BOOL("DC X6", version=Version.WARP2_ONLY),
                Elem.BOOL("DC X30", version=Version.WARP2_ONLY),
                Elem.BOOL("LED", version=Version.WARP2_ONLY),
                Elem.BOOL("Nicht belegt", version=Version.WARP2_ONLY),
                Elem.BOOL("Nicht belegt", version=Version.WARP2_ONLY),
                Elem.BOOL("Nicht belegt", version=Version.WARP2_ONLY),
                Elem.BOOL("Nicht belegt", version=Version.WARP2_ONLY),
            ]),
            "hardware_version": Elem.INT("Die von der Firmware des EVSEs detektierte Hardware-Version des EVSEs.", version=Version.WARP1_ONLY),
            "charging_time": Elem.INT("Ungefähre Zeit des Ladevorgangs. Nur für Lastmanagementzwecke zu verwenden!", unit=Units.ms),
        })
    ),

    Func("max_charging_current", FuncType.STATE, Elem.OBJECT("Die maximalen Ladeströme des Ladecontrollers. Das Minimum dieser Ströme ist der tatsächliche maximale Ladestrom, der dem Fahrzeug bereitgestellt wird. Alle Ströme haben einen Minimalwert von 6000 (6 Ampere) und einen Maximalwert von 32000 (32 Ampere).", members={
            "max_current_configured": Elem.INT("Der maximale konfigurierte Ladestrom. Kann durch {{{ref:evse/current_limit}}} oder das Webinterface eingestellt werden.", unit=Units.mA),
            "max_current_incoming_cable": Elem.INT("Der maximale Ladestrom des eingehenden Kabels. Siehe {{{ref:evse/hardware_configuration}}}.", unit=Units.mA),
            "max_current_outgoing_cable": Elem.INT("Der maximale Ladestrom des ausgehenden Kabels. Fest konfiguriert, falls das Kabel angeschlagen ist.", unit=Units.mA),
            "max_current_managed": Elem.INT("Der maximale Ladestrom der vom Lastmanager zugeteilt wurde. Wird ignoriert wenn Lastmanagement (Siehe {{{ref:evse/managed}}}) deaktiviert ist.", unit=Units.mA),
        })
    ),

    Func("auto_start_charging", FuncType.STATE, Elem.OBJECT("Konfiguriert, ob ein angeschlossenes Fahrzeug selbstständig geladen wird. Dieser Wert kann über evse/auto_start_charging_update mit dem selben Payload aktualisiert werden. Achtung: Ein Neustart des Ladecontrollers setzt diesen Wert zurück auf true.", members={
            "auto_start_charging": Elem.BOOL("Konfiguriert, ob ein angeschlossenes Fahrzeug selbstständig geladen wird. Falls aktiviert, beginnt sofort, wenn das Fahrzeug angeschlossen wird der Ladevorgang. Falls deaktiviert, kann das Laden mit {{{ref:evse/start_charging}}} gestartet werden."),
        })
    ),

    Func("user_calibration", FuncType.STATE, Elem.OBJECT("Erlaubt es, die werksseitige Kalibrierung des EVSEs auszulesen und zu überschreiben. Dieser Wert kann über evse/user_calibration_update mit dem selben Payload aktualisiert werden. Um die Kalibierung auf den Werkszustand zurückzusetzen, kann ein Payload mit user_calibration_active auf false geschickt werden. Die weiteren Werte werden dann ignoriert.", members={
            "user_calibration_active": Elem.BOOL("Gibt an, ob die werksseitige Kalibrierung überschrieben wurde."),
            "voltage_diff": Elem.INT("Einer der Kalibrierungsparameter."),
            "voltage_mul": Elem.INT("Einer der Kalibrierungsparameter."),
            "voltage_div": Elem.INT("Einer der Kalibrierungsparameter."),
            "resistance_2700": Elem.INT("Einer der Kalibrierungsparameter."),
            "resistance_880": Elem.ARRAY("Einer der Kalibrierungsparameter.", member_type=EType.INT),
        },
        version=Version.WARP1_ONLY)
    ),

    Func("energy_meter_state", FuncType.STATE, Elem.OBJECT("Bei WARP 2 wird der Stromzähler vom Ladecontroller selbst ausgelesen. evse/energy_meter_state liefert den Zustand des Stromzählers.", members={
            "available": Elem.BOOL("Gibt an, ob ein Stromzähler gefunden wurde."),
            "error_count": Elem.ARRAY("Fehlerzähler der Kommunikation mit dem Stromzähler", members=[
                Elem.INT("Local Timeouts"),
                Elem.INT("Global Timeouts"),
                Elem.INT("Illegal Function"),
                Elem.INT("Illegal Data Access"),
                Elem.INT("Illegal Data Value"),
                Elem.INT("Slave Device Failure"),
            ]),
        },
        version=Version.WARP2_ONLY)
    ),

    Func("energy_meter_values", FuncType.STATE, Elem.OBJECT("Bei WARP 2 wird der Stromzähler vom Ladecontroller selbst ausgelesen. evse/energy_meter_values liefert die zuletzt gelesenen Werte.", members={
            "power": Elem.FLOAT("Die aktuelle Ladeleistung.", unit=Units.W),
            "energy_rel": Elem.FLOAT("Die geladene Energie seit dem letzten Reset.", unit=Units.kWh),
            "energy_abs": Elem.FLOAT("Die geladene Energie seit der Herstellung des Stromzählers.", unit=Units.kWh),
            "phases_active": Elem.ARRAY("Die derzeit aktiven Phasen", members=[
                Elem.BOOL("Phase L1 aktiv"),
                Elem.BOOL("Phase L2 aktiv"),
                Elem.BOOL("Phase L3 aktiv"),
            ]),
            "phases_connected": Elem.ARRAY("Die angeschlossenen Phasen", members=[
                Elem.BOOL("Phase L1 angeschlossen"),
                Elem.BOOL("Phase L2 angeschlossen"),
                Elem.BOOL("Phase L3 angeschlossen"),
            ]),
        },
        version=Version.WARP2_ONLY)
    ),

    Func("dc_fault_current_state", FuncType.STATE, Elem.OBJECT("Der Zustand des DC-Fehlerstrom-Schutzmoduls. Falls ein Gleichstromfehler auftritt, kann nicht mehr geladen werden, bis das Schutzmodul zurückgesetzt wurde. <strong>Vor dem Zurücksetzen muss der Grund des Fehlers unbedingt behoben werden!</strong> {{{ref:evse/reset_dc_fault_current}}} setzt das Modul zurück.", members={
            "state": Elem.INT("Der Zustand des DC-Fehlerstrom-Schutzmoduls", constants=[
                Const(0, "Kein Fehler"),
                Const(1, "6 mA Fehlerstrom detektiert"),
                Const(2, "Systemfehler"),
                Const(3, "Unbekannter fehler"),
                Const(4, "Kalibrierungsfehler"),
            ])
        },
        version=Version.WARP2_ONLY)
    ),

    Func("gpio_configuration", FuncType.STATE, Elem.OBJECT("Die Konfiguration der konfigurierbaren Ein- und Ausgänge. Diese kann über {{{ref:evse/gpio_configuration_update}}} mit dem selben Payload aktualisiert werden.", members={
            "shutdown_input": Elem.INT("Die Konfiguration des Abschalteingangs.", constants=[
                Const(0, "Nicht konfiguriert"),
                Const(1, "Abschalten wenn geöffnet"),
                Const(2, "Abschalten wenn geschlossen"),
            ]),
            "input": Elem.INT("Die Konfiguration des konfigurierbaren Eingangs.", constants=[
                Const(0, "Nicht konfiguriert"),
            ]),
            "output": Elem.INT("Die Konfiguration des konfigurierbaren Ausgangs.", constants=[
                Const(0, "Verbunden mit Masse"),
                Const(1, "Hochohmig"),
            ]),
        },
        version=Version.WARP2_ONLY)
    ),

    Func("button_configuration", FuncType.STATE, Elem.OBJECT("Die Konfiguration des Tasters in der Frontblende. Diese kann über evse/button_configuration_update mit dem selben Payload aktualisiert werden. <strong>Das NFC-Modul kann diese Konfiguration ändern und sperren, um sicherzustellen, dass ein NFC-Tag zum Starten/Stoppen einer Ladung notwendig ist!</strong>", members={
            "button": Elem.INT("Die Konfiguration des Tasters in der Frontblende.", constants=[
                Const(0, "Deaktiviert"),
                Const(1, "Ladestart wenn gedrückt"),
                Const(2, "Ladestop wenn gedrückt"),
                Const(3, "Ladestart/stop wenn gedrückt"),
            ]),
        },
        version=Version.WARP2_ONLY)
    ),

    Func("button_state", FuncType.STATE, Elem.OBJECT("Der Zustand des Tasters in der Frontblende.", members= {
            "button_press_time": Elem.INT("Zeit zu der zuletzt der Taster gedrückt wurde. 0 falls der Taster seit dem Start des Ladecontrollers nicht betätigt wurde.", unit=Units.ms),
            "button_release_time": Elem.INT("Zeit zu der zuletzt der Taster losgelassen wurde. 0 falls der Taster seit dem Start des Ladecontrollers nicht betätigt wurde.", unit=Units.ms),
            "button_pressed": Elem.BOOL("true, falls der Taster derzeit gedrückt ist, sonst false"),
        })
    ),

    Func("managed", FuncType.STATE, Elem.OBJECT("Legt fest, ob der Ladestrom, der vom Lastmanager zugeteilt wurde, in die Berechnung des maximalen Ladestroms eingeht (siehe {{{ref:evse/max_charging_current}}}). Damit das Lastmanagement zwischen WARP Chargern funktioniert, muss dies aktiviert sein. Der Wert kann über {{{ref:evse/managed_update}}} aktualisiert werden.", members={
            "managed": Elem.BOOL("true wenn Lastmanagement aktiviert ist, sonst false"),
        })
    ),

    Func("current_limit", FuncType.COMMAND, Elem.OBJECT("Begrenzt den Ladestrom.", members={
            "current": Elem.INT("Begrenzt den Ladestrom auf den übergebenen Wert. Der Strom hat einen Minimalwert von 6000 (6 Ampere) und einen Maximalwert von 32000 (32 Ampere).", unit=Units.mA)
        })
    ),

    Func("stop_charging", FuncType.COMMAND, Elem.NULL("Beendet den laufenden Ladevorgang. Ein Ladevorgang kann mit {{{ref:evse/start_charging}}} wieder gestartet werden."), command_is_action=True),

    Func("start_charging", FuncType.COMMAND, Elem.NULL("Startet einen Ladevorgang. Ein Ladevorgang kann mit {{{ref:evse/stop_charging}}} wieder gestoppt werden."), command_is_action=True),

    Func("reset_dc_fault_current", FuncType.COMMAND, Elem.OBJECT("Setzt das DC-Fehlerstrom-Schutzmodul zurück. <strong>Vor dem Zurücksetzen muss der Grund des Fehlers unbedingt behoben werden!</strong>", members={
            "password": Elem.INT("Passwort, das zum Zurücksetzen benötigt wird. Das Passwort lautet 0xDC42FA23.")
        })
    ),

    Func("managed_current_update", FuncType.COMMAND, Elem.OBJECT("Setzt eine neue Strombegrenzung des Lastmanagements. <strong>Diese Funktion muss vom Lastmanager periodisch aufgerufen werden, selbst wenn sich die Strombegrenzung nicht ändert. Anderenfalls setzt der Ladecontroller den Lastmanagement-Strom nach 30 Sekunden auf 0 Ampere.</strong>", members={
            "current": Elem.INT("Der Strom hat einen Minimalwert von 6000 (6 Ampere) und einen Maximalwert von 32000 (32 Ampere). Dieser Strom kann zusätzlich auf 0 gesetzt werden, um das Laden zu verbieten.", unit=Units.mA)
        })
    ),
])
