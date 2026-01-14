from api_doc_common import *

evse = Module("evse", T({'de': "Ladecontroller (EVSE)", 'en': "Charge Controller (EVSE)"}), "", T({'de': "Das `evse`-Modul verwaltet Zustand und Konfiguration des Ladecontrollers.", 'en': "The `evse` module manages the state and configuration of the charge controller."}), Version.WARPX.with_desc('**Benötigt das Feature <a href="#features_evse"><code>"evse"</code></a>**'),[
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand des Ladecontrollers.", 'en': "The state of the charge controller."}), members={
            "iec61851_state": Elem.INT(T({'de': "Der aktuelle Zustand nach IEC 61851", 'en': "The current state according to IEC 61851"}), constants=[
                    Const(0, T({'de': "A: Nicht verbunden", 'en': "A: Not connected"})),
                    Const(1, T({'de': "B: Verbunden", 'en': "B: Connected"})),
                    Const(2, T({'de': "C: Lädt", 'en': "C: Charging"})),
                    Const(3, T({'de': "D: Lädt mit Belüftung (nicht unterstützt)", 'en': "D: Charging with ventilation (not supported)"})),
                    Const(4, T({'de': "E/F: Fehler", 'en': "E/F: Error"})),
            ]),
            "charger_state": Elem.INT(T({'de': "Der aktuelle Zustand, aufbereitet vom Ladecontroller", 'en': "The current state, processed by the charge controller"}), constants=[
                    Const(0, T({'de': "Nicht verbunden", 'en': "Not connected"})),
                    Const(1, T({'de': "Warte auf Ladefreigabe", 'en': "Waiting for charge release"})),
                    Const(2, T({'de': "Ladebereit", 'en': "Ready to charge"})),
                    Const(3, T({'de': "Lädt", 'en': "Charging"})),
                    Const(4, T({'de': "Fehler", 'en': "Error"})),
            ]),
            "contactor_state": Elem.INT(T({'de': "Zustand der Schützüberwachung.", 'en': "State of the contactor monitoring."}), constants=[
                Const(0, T({'de': "Nicht stromführend vor und nach dem Schütz", 'en': "Not live before and after contactor"}), version=Version.WARP1 | Version.WARP2),
                Const(1, T({'de': "Stromführend vor, aber nicht stromführend nach dem Schütz", 'en': "Live before, but not live after contactor"}), version=Version.WARP1 | Version.WARP2),
                Const(2, T({'de': "Nicht stromführend vor, aber stromführend nach dem Schütz", 'en': "Not live before, but live after contactor"}), version=Version.WARP1 | Version.WARP2),
                Const(3, T({'de': "Stromführend vor und nach dem Schütz", 'en': "Live before and after contactor"}), version=Version.WARP1 | Version.WARP2),
                Const("00000..11111", T({'de': """Bitmaske, die den Schützzustand angibt. Von Bit 0 bis Bit 4:
                - **0** - Schütz-L1+N-Hilfskontakt: (gibt an ob das Schütz geschaltet ist) 1 = geschlossen; 0 = geöffnet
                - **1** - Schütz L2+L3-Hilfskontakt: (gibt an ob das Schütz geschaltet ist) 1 = geschlossen; 0 = geöffnet
                - **2** - Schützfehler: (siehe contactor_error) 1 = Fehler; 0 = kein Fehler
                - **3** - Schütz-Spulenanschluss: 1 = Ein oder beide Schütze sollen geschaltet sein (siehe Zustand der Phasenumschaltung) 0 = Kein Schütz soll geschaltet sein
                - **4** - Zustand der Phasenumschaltung (gibt an, welche Schütze geschaltet werden wenn das Spulenanschluss-Bit 1 ist). 1 = Beide Schütze werden geschaltet; dreiphasig. 0 = Nur das L1+N-Schütz wird geschaltet; einphasig """, 'en': """Bit mask indicating the contactor state. From bit 0 to bit 4:
                - **0** - Contactor L1+N auxiliary contact: (indicates if contactor is switched) 1 = closed; 0 = open
                - **1** - Contactor L2+L3 auxiliary contact: (indicates if contactor is switched) 1 = closed; 0 = open
                - **2** - Contactor error: (see contactor_error) 1 = error; 0 = no error
                - **3** - Contactor coil connection: 1 = One or both contactors should be switched (see phase switching state) 0 = No contactor should be switched
                - **4** - Phase switching state (indicates which contactors are switched when the coil connection bit is 1). 1 = Both contactors are switched; three-phase. 0 = Only the L1+N contactor is switched; single-phase """}), version=Version.WARP3)
            ]),
            "contactor_error": Elem.INT(T({'de': "Fehlercode der Schützüberwachung. Ein Wert ungleich 0 zeigt einen Fehler an.", 'en': "Error code of the contactor monitoring. A value other than 0 indicates an error."}), constants=[
                Const(0, T({'de': "Kein Fehler", 'en': "No error"})),
                Const(1, T({'de': "Schütz sollte durchschalten.<br/>Kein Strom vor Schütz, kein Strom nach Schütz.<br/>Stromversorgung prüfen.", 'en': "Contactor should be closed.<br/>No current before contactor, no current after contactor.<br/>Check power supply."}), version=Version.WARP1 | Version.WARP2),
                Const(2, T({'de': "Schütz sollte durchschalten.<br/>Strom vor Schütz, kein Strom nach Schütz.<br/>Schütz defekt?", 'en': "Contactor should be closed.<br/>Current before contactor, no current after contactor.<br/>Contactor defective?"}), version=Version.WARP1 | Version.WARP2),
                Const(3, T({'de': "Schütz sollte durchschalten.<br/>Kein Strom vor Schütz, Strom nach Schütz.<br/>Verkabelung prüfen.", 'en': "Contactor should be closed.<br/>No current before contactor, current after contactor.<br/>Check wiring."}), version=Version.WARP1 | Version.WARP2),
                Const(4, T({'de': "Schütz sollte <strong>nicht</strong> durchschalten.<br/>Kein Strom vor Schütz, kein Strom nach Schütz.<br/>Stromversorgung prüfen.", 'en': "Contactor should <strong>not</strong> be closed.<br/>No current before contactor, no current after contactor.<br/>Check power supply."}), version=Version.WARP1 | Version.WARP2),
                Const(5, T({'de': "Schütz sollte <strong>nicht</strong> durchschalten.<br/>Kein Strom vor Schütz, Strom nach Schütz.<br/>Verkabelung prüfen.", 'en': "Contactor should <strong>not</strong> be closed.<br/>No current before contactor, current after contactor.<br/>Check wiring."}), version=Version.WARP1 | Version.WARP2),
                Const(6, T({'de': "Schütz sollte <strong>nicht</strong> durchschalten.<br/>Strom vor Schütz, Strom nach Schütz.<br/>Schütz defekt?", 'en': "Contactor should <strong>not</strong> be closed.<br/>Current before contactor, current after contactor.<br/>Contactor defective?"}), version=Version.WARP1 | Version.WARP2),

                Const(1, T({'de': "Schütz L2+L3 nicht durchgeschaltet.<br/>Beide Schütze sollten durchgeschaltet sein.", 'en': "Contactor L2+L3 not closed.<br/>Both contactors should be closed."}), version=Version.WARP3),
                Const(2, T({'de': "Schütz L1+N nicht durchgeschaltet.<br/>Beide Schütze sollten durchgeschaltet sein.", 'en': "Contactor L1+N not closed.<br/>Both contactors should be closed."}), version=Version.WARP3),
                Const(3, T({'de': "Beide Schütze nicht durchgeschaltet.<br/>Beide Schütze sollten durchgeschaltet sein.", 'en': "Both contactors not closed.<br/>Both contactors should be closed."}), version=Version.WARP3),
                Const(4, T({'de': "Schütz L2+L3 durchgeschaltet.<br/>Nur Schütz L1+N sollte durchgeschaltet sein.", 'en': "Contactor L2+L3 closed.<br/>Only contactor L1+N should be closed."}), version=Version.WARP3),
                Const(5, T({'de': "Schütz L2+L3 durchgeschaltet, Schütz L1+N nicht durchgeschaltet.<br/>Nur Schütz L1+N sollte durchgeschaltet sein.", 'en': "Contactor L2+L3 closed, contactor L1+N not closed.<br/>Only contactor L1+N should be closed."}), version=Version.WARP3),
                Const(6, T({'de': "Beide Schütze durchgeschaltet.<br/>Nur Schütz L1+N sollte durchgeschaltet sein.", 'en': "Both contactors closed.<br/>Only contactor L1+N should be closed."}), version=Version.WARP3),
                Const(7, T({'de': "Beide Schütze durchgeschaltet.<br/>Kein Schütz sollte durchgeschaltet sein.", 'en': "Both contactors closed.<br/>No contactor should be closed."}), version=Version.WARP3),
                Const(8, T({'de': "Schütz L1+N durchgeschaltet.<br/>Kein Schütz sollte durchgeschaltet sein.", 'en': "Contactor L1+N closed.<br/>No contactor should be closed."}), version=Version.WARP3),
                Const(9, T({'de': "Schütz L2+L3 durchgeschaltet.<br/>Kein Schütz sollte durchgeschaltet sein.", 'en': "Contactor L2+L3 closed.<br/>No contactor should be closed."}), version=Version.WARP3),
                Const(10, T({'de': "Beide Schütze durchgeschaltet.<br/>Kein Schütz sollte durchgeschaltet sein.", 'en': "Both contactors closed.<br/>No contactor should be closed."}), version=Version.WARP3),
                Const(11, T({'de': "Schütz L1+N durchgeschaltet.<br/>Kein Schütz sollte durchgeschaltet sein.", 'en': "Contactor L1+N closed.<br/>No contactor should be closed."}), version=Version.WARP3),
                Const(12, T({'de': "Schütz L2+L3 durchgeschaltet.<br/>Kein Schütz sollte durchgeschaltet sein.", 'en': "Contactor L2+L3 closed.<br/>No contactor should be closed."}), version=Version.WARP3),
                Const(13, T({'de': "Reserviert.", 'en': "Reserved."}), version=Version.WARP3),
            ]),
            "allowed_charging_current": Elem.INT(T({'de': "Maximal erlaubter Ladestrom, der dem Fahrzeug zur Verfügung gestellt wird. Dieser Strom ist das Minimum der Stromgrenzen aller Ladeslots.", 'en': "Maximum allowed charging current provided to the vehicle. This current is the minimum of the current limits of all charge slots."}), unit=Units.mA),
            "error_state": Elem.INT(T({'de': 'Der aktuelle Fehlerzustand. [Siehe Handbuch für Details](https://warp-charger.com/downloads/#documents)', 'en': 'The current error state. [See manual for details](https://warp-charger.com/downloads/#documents)'}), constants=[
                Const(0, T({'de': "OK", 'en': "OK"})),
                Const(2, T({'de': "Schalterfehler", 'en': "Switch error"})),
                Const(3, T({'de': "DC-Fehlerstromüberwachungsfehler", 'en': "DC residual current monitoring error"})),
                Const(4, T({'de': "Schützfehler", 'en': "Contactor error"})),
                Const(5, T({'de': "Kommunikationsfehler", 'en': "Communication error"})),
            ]),
            "lock_state": Elem.INT(T({'de': "Zustand der Kabelverriegelung (nur relevant für Wallboxen mit Typ-2-Dose; Stand jetzt wurde kein WARP Charger mit Typ-2-Dose hergestellt)", 'en': "State of the cable lock (only relevant for chargers with Type 2 socket; as of now, no WARP Charger with Type 2 socket has been manufactured)"}), constants=[
                Const(0, T({'de': "Initialisierung", 'en': "Initialization"})),
                Const(1, T({'de': "Offen", 'en': "Open"})),
                Const(2, T({'de': "Schließend", 'en': "Closing"})),
                Const(3, T({'de': "Geschlossen", 'en': "Closed"})),
                Const(4, T({'de': "Öffnend", 'en': "Opening"})),
                Const(5, T({'de': "Fehler", 'en': "Error"})),
            ]),
            "dc_fault_current_state": Elem.INT(T({'de': "Der Zustand des DC-Fehlerstrom-Schutzmoduls. Falls ein Gleichstromfehler auftritt, kann nicht mehr geladen werden, bis das Schutzmodul zurückgesetzt wurde. <strong>Vor dem Zurücksetzen muss der Grund des Fehlers unbedingt behoben werden!</strong> {{{ref:evse/reset_dc_fault_current_state}}} setzt das Modul zurück.", 'en': "The state of the DC residual current protection module. If a DC fault occurs, charging is no longer possible until the protection module has been reset. <strong>Before resetting, the cause of the fault must be fixed!</strong> {{{ref:evse/reset_dc_fault_current_state}}} resets the module."}), constants=[
                Const(0, T({'de': "Kein Fehler", 'en': "No error"})),
                Const(1, T({'de': "6 mA Fehlerstrom detektiert", 'en': "6 mA residual current detected"})),
                Const(2, T({'de': "Systemfehler", 'en': "System error"})),
                Const(3, T({'de': "Unbekannter fehler", 'en': "Unknown error"})),
                Const(4, T({'de': "Kalibrierungsfehler", 'en': "Calibration error"})),
                Const(5, T({'de': "AC-Fehler", 'en': "AC error"})),
                Const(6, T({'de': "AC- und DC-Fehler", 'en': "AC and DC error"})),
            ], version=Version.WARP2 | Version.WARP3)
        })
    ),

    Func("hardware_configuration", FuncType.STATE, Elem.OBJECT(T({'de': "Die Hardwarekonfiguration des Ladecontrollers.", 'en': "The hardware configuration of the charge controller."}), members={
            "jumper_configuration": Elem.INT(T({'de': "Der Maximalstrom des eingehenden Kabels. Dieser Strom wird auf dem Ladecontroller durch Jumper oder eine Steckplatine mit Schaltern konfiguriert.", 'en': "The maximum current of the incoming cable. This current is configured on the charge controller via jumpers or a circuit board with switches."}), constants=[
                    Const(0, T({'de': "6 Ampere", 'en': "6 amperes"})),
                    Const(1, T({'de': "10 Ampere", 'en': "10 amperes"})),
                    Const(2, T({'de': "13 Ampere", 'en': "13 amperes"})),
                    Const(3, T({'de': "16 Ampere", 'en': "16 amperes"})),
                    Const(4, T({'de': "20 Ampere", 'en': "20 amperes"})),
                    Const(5, T({'de': "25 Ampere", 'en': "25 amperes"})),
                    Const(6, T({'de': "32 Ampere", 'en': "32 amperes"})),
                    Const(7, T({'de': "Kontrolliert durch Software", 'en': "Controlled by software"})),
                    Const(8, T({'de': "Nicht konfiguriert", 'en': "Not configured"})),
            ]),
            "has_lock_switch": Elem.BOOL(T({'de': "Gibt an, ob die Wallbox über eine Kabelverriegelung verfügt.", 'en': "Indicates whether the charger has a cable lock."}), constants=[
                Const(False, T({'de': "Wallbox hat fest angeschlagenes Typ-2-Ladekabel", 'en': "Charger has permanently attached Type 2 charging cable"})),
                Const(True, T({'de': "Wallbox hat eine Typ-2-Dose mit Kabelverriegelung", 'en': "Charger has a Type 2 socket with cable lock"})),
            ]),
            "evse_version": Elem.INT(T({'de': "Hardware-Version des Ladecontrollers", 'en': "Hardware version of the charge controller"}), constants=[
                Const(14, U("EVSE 1.4"), Version.WARP1),
                Const(15, U("EVSE 1.5"), Version.WARP1),
                Const(20, U("EVSE 2.0"), Version.WARP2),
                Const(30, U("EVSE 3.0"), Version.WARP3)
            ]),
            "energy_meter_type": Elem.INT(T({'de': "Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jeder Wallbox unterstützt!", 'en': "Type of the installed energy meter. Not every energy meter is supported by every charger!"}), constants=[
                Const(0, T({'de': "Kein Stromzähler verfügbar", 'en': "No energy meter available"})),
                Const(1, U("Eastron SDM72"), Version.WARP1),
                Const(2, U("Eastron SDM630"), Version.WARP2 | Version.WARP3),
                Const(3, U("Eastron SDM72V2"), Version.WARP2 | Version.WARP3),
                Const(4, U("Eastron SDM72CTM"), Version.WARP2 | Version.WARP3),
                Const(5, U("Eastron SDM630MCT"), Version.WARP2 | Version.WARP3),
                Const(6, U("Eltako DSZ15DZMOD"), Version.WARP2 | Version.WARP3),
                Const(7, U("YTL DEM4A"), Version.WARP2 | Version.WARP3)
            ], version=Version.WARP2 | Version.WARP3)
        })
    ),

    Func("slots", FuncType.STATE, Elem.ARRAY(T({'de': "Der Zustand der Ladestromgrenzen. Der erlaubte Ladestrom `allowed_charging_current` aus {{{ref:evse/state}}} ist das Minimum aller Ladeslots, die aktiv sind. Siehe TODO LINK für Details.", 'en': "The state of the charging current limits. The allowed charging current `allowed_charging_current` from {{{ref:evse/state}}} is the minimum of all charge slots that are active. See TODO LINK for details."}), members=[
            * 15 * [Elem.OBJECT(T({'de': "Ein Ladeslot", 'en': "A charge slot"}), members = {
                "max_current": Elem.INT(T({'de': "Maximal erlaubter Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", 'en': "Maximum allowed charging current. 6000 (=6 amperes) to 32000 (=32 amperes) or 0 if the slot is blocked."}), unit=Units.mA),
                "active": Elem.BOOL(T({'de': "Gibt an ob dieser Slot aktiv ist.", 'en': "Indicates whether this slot is active."}), constants=[
                    Const(True, T({'de': "Slot ist aktiv", 'en': "Slot is active"})),
                    Const(False, T({'de': "Slot ist nicht aktiv", 'en': "Slot is not active"})),
                ]),
                "clear_on_disconnect": Elem.BOOL(T({'de': "Gibt an, ob der Ladestrom dieses Slots beim Abziehen eines Fahrzeugs auf 0 (=Ladevorgang blockiert) gesetzt wird.", 'en': "Indicates whether the charging current of this slot is set to 0 (=charging blocked) when a vehicle is disconnected."}), constants=[
                    Const(True, T({'de': "Slot wird beim Abziehen blockieren", 'en': "Slot will block on disconnect"})),
                    Const(False, T({'de': "Slot wird gesetzten Ladestrom beim Abziehen beibehalten", 'en': "Slot will keep set charging current on disconnect"})),
                ]),
            })]
        ])
    ),

    Func("button_state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand des Tasters in der Frontblende.", 'en': "The state of the button in the front panel."}), members= {
            "button_press_time": Elem.INT(T({'de': "Zeit zu der zuletzt der Taster gedrückt wurde. 0 falls der Taster seit dem Start des Ladecontrollers nicht betätigt wurde.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", 'en': "Time at which the button was last pressed. 0 if the button has not been pressed since the charge controller started.<br/><br/> Warning: This time is measured directly via the processor clock. The accuracy is therefore only sufficient for time measurements in the range of minutes to a few hours. The time measurement overflows after approximately 50 days and starts again at 0."}), unit=Units.ms),
            "button_release_time": Elem.INT(T({'de': "Zeit zu der zuletzt der Taster losgelassen wurde. 0 falls der Taster seit dem Start des Ladecontrollers nicht betätigt wurde.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", 'en': "Time at which the button was last released. 0 if the button has not been pressed since the charge controller started.<br/><br/> Warning: This time is measured directly via the processor clock. The accuracy is therefore only sufficient for time measurements in the range of minutes to a few hours. The time measurement overflows after approximately 50 days and starts again at 0."}), unit=Units.ms),
            "button_pressed": Elem.BOOL(T({'de': "true, falls der Taster derzeit gedrückt ist, sonst false", 'en': "true if the button is currently pressed, otherwise false"})),
        })
    ),

    Func("indicator_led", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der Zustand der LED im Taster. Kann geschrieben werden, falls die LED-Steuerung per API (siehe {{{ref:evse/led_configuration}}}) erlaubt wurde. Die Farbe der LED kann nur bei WARP3 gesteuert werden.", 'en': "The state of the LED in the button. Can be written if LED control via API (see {{{ref:evse/led_configuration}}}) has been enabled. The LED color can only be controlled on WARP3."}), members={
            "indication": Elem.INT(T({'de': "Aktuell gesetzter Zustand.", 'en': "Currently set state."}), constants=[
                Const(-1, T({'de': "EVSE kontrolliert LED", 'en': "EVSE controls LED"})),
                Const(0, T({'de': "Aus", 'en': "Off"})),
                Const("1..254", T({'de': "Per PWM gedimmtes leuchten", 'en': "PWM dimmed light"}), version=Version.WARP1 | Version.WARP2),
                Const(255, T({'de': "An", 'en': "On"}), version=Version.WARP1 | Version.WARP2),
                Const(1001, T({'de': "Bestätigendes Blinken (z.B: NFC-Tag wurde erkannt)", 'en': "Confirming blink (e.g.: NFC tag recognized)"}), version=Version.WARP1 | Version.WARP2),
                Const(1002, T({'de': "Ablehnendes Blinken (z.B: NFC-Tag ist unbekannt)", 'en': "Rejecting blink (e.g.: NFC tag unknown)"}), version=Version.WARP1 | Version.WARP2),
                Const(1003, T({'de': "Aufforderndes Blinken (z.B: NFC-Tag wird zum Laden benötigt)", 'en': "Prompting blink (e.g.: NFC tag required for charging)"}), version=Version.WARP1 | Version.WARP2),
                Const("2001..2010", T({'de': "Fehler-Blinken 1 bis 10.", 'en': "Error blink 1 to 10."}), version=Version.WARP1 | Version.WARP2),

                Const("1..254", T({'de': "Per PWM gedimmtes Leuchten; Standardfarbe Blau", 'en': "PWM dimmed light; default color blue"}), version=Version.WARP3),
                Const(255, T({'de': "An; Standardfarbe Blau", 'en': "On; default color blue"}), version=Version.WARP3),
                Const(1001, T({'de': "Bestätigendes Blinken (z.B: NFC-Tag wurde erkannt); Standardfarbe Grün", 'en': "Confirming blink (e.g.: NFC tag recognized); default color green"}), version=Version.WARP3),
                Const(1002, T({'de': "Ablehnendes Blinken (z.B: NFC-Tag ist unbekannt); Standardfarbe Rot", 'en': "Rejecting blink (e.g.: NFC tag unknown); default color red"}), version=Version.WARP3),
                Const(1003, T({'de': "Aufforderndes Blinken (z.B: NFC-Tag wird zum Laden benötigt); Standardfarbe Orange", 'en': "Prompting blink (e.g.: NFC tag required for charging); default color orange"}), version=Version.WARP3),
                Const("2001..2010", T({'de': "Fehler-Blinken 1 bis 10.; Standardfarbe Rot", 'en': "Error blink 1 to 10.; default color red"}), version=Version.WARP3),
            ]),
            "duration": Elem.INT(T({'de': "Dauer für die der gesetzte Zustand erhalten bleibt.", 'en': "Duration for which the set state is maintained."}), unit=Units.ms),
            "color_h": Elem.INT(T({'de': 'Farbwert der LED im [HSV-Farbraum](https://de.wikipedia.org/wiki/HSV-Farbraum). Erlaubt sind Werte von 0 bis 359', 'en': 'Hue value of the LED in [HSV color space](https://en.wikipedia.org/wiki/HSL_and_HSV). Allowed values are from 0 to 359'}), unit=Units.degree),
            "color_s": Elem.INT(T({'de': 'Farbsättigung der LED im [HSV-Farbraum](https://de.wikipedia.org/wiki/HSV-Farbraum). Erlaubt sind Werte von 0 bis 255', 'en': 'Saturation of the LED in [HSV color space](https://en.wikipedia.org/wiki/HSL_and_HSV). Allowed values are from 0 to 255'})),
            "color_v": Elem.INT(T({'de': 'Helligkeit der LED im [HSV-Farbraum](https://de.wikipedia.org/wiki/HSV-Farbraum). Eine Helligkeit von 0 verwendet die Standardfarbe der `indication` bzw. Blau bei WARP1 oder WARP2. Erlaubt sind Werte von 0 bis 255', 'en': 'Brightness of the LED in [HSV color space](https://en.wikipedia.org/wiki/HSL_and_HSV). A brightness of 0 uses the default color of the `indication` or blue for WARP1 or WARP2. Allowed values are from 0 to 255'})),
        })
    ),

    Func("low_level_state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Low-Level-Zustand des Ladecontrollers.", 'en': "The low-level state of the charge controller."}), members={
            "led_state": Elem.INT(T({'de': "Der Zustand der am Ladecontroller angeschlossenen LED", 'en': "The state of the LED connected to the charge controller"}), constants=[
                    Const(0, T({'de': "Aus", 'en': "Off"})),
                    Const(1, T({'de': "An", 'en': "On"})),
                    Const(2, T({'de': "Blinkt", 'en': "Blinking"})),
                    Const(3, T({'de': "Flackert", 'en': "Flickering"})),
                    Const(4, T({'de': "Atmet", 'en': "Breathing"})),
                    Const(5, T({'de': "API, siehe {{{ref:evse/indicator_led}}}", 'en': "API, see {{{ref:evse/indicator_led}}}"})),
            ]),
            "cp_pwm_duty_cycle": Elem.INT(T({'de': "Tastverhältnis der Pulsweitenmodulation auf dem CP-Signal.", 'en': "Duty cycle of the pulse width modulation on the CP signal."}), unit=Units.tenth_percent),
            "adc_values": Elem.ARRAY(T({'de': "16-Bit ADC-Rohwerte der Spannungsmessungen", 'en': "16-bit ADC raw values of the voltage measurements"}), members=[
                Elem.INT(U("CP/PE"), version=Version.WARP1),
                Elem.INT(U("PP/PE"), version=Version.WARP1),

                Elem.INT(T({'de': "CP/PE vor Widerstand (PWM High)", 'en': "CP/PE before resistor (PWM High)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(T({'de': "CP/PE nach Widerstand (PWM High)", 'en': "CP/PE after resistor (PWM High)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(T({'de': "CP/PE vor Widerstand (PWM Low)", 'en': "CP/PE before resistor (PWM Low)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(T({'de': "CP/PE nach Widerstand (PWM Low)", 'en': "CP/PE after resistor (PWM Low)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(U("PP/PE"), version=Version.WARP2 | Version.WARP3),
                Elem.INT(U("+12V Rail"), version=Version.WARP2 | Version.WARP3),
                Elem.INT(U("-12V Rail"), version=Version.WARP2 | Version.WARP3),
            ]),
            "voltages": Elem.ARRAY(T({'de': "Aus den ADC-Werten berechnete Spannungen", 'en': "Voltages calculated from ADC values"}), unit=Units.mV, members=[
                Elem.INT(U("CP/PE"), version=Version.WARP1),
                Elem.INT(U("PP/PE"), version=Version.WARP1),
                Elem.INT(T({'de': "Maximalspannung CP/PE", 'en': "Maximum voltage CP/PE"}), version=Version.WARP1),

                Elem.INT(T({'de': "CP/PE vor Widerstand (PWM High)", 'en': "CP/PE before resistor (PWM High)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(T({'de': "CP/PE nach Widerstand (PWM High)", 'en': "CP/PE after resistor (PWM High)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(T({'de': "CP/PE vor Widerstand (PWM Low)", 'en': "CP/PE before resistor (PWM Low)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(T({'de': "CP/PE nach Widerstand (PWM Low)", 'en': "CP/PE after resistor (PWM Low)"}), version=Version.WARP2 | Version.WARP3),
                Elem.INT(U("PP/PE"), version=Version.WARP2 | Version.WARP3),
                Elem.INT(U("+12V Rail"), version=Version.WARP2 | Version.WARP3),
                Elem.INT(U("-12V Rail"), version=Version.WARP2 | Version.WARP3),
            ]),
            "resistances": Elem.ARRAY(T({'de': "Aus den Spannungen berechnete Widerstände", 'en': "Resistances calculated from voltages"}), unit=Units.ohm, members=[
                Elem.INT(U("CP/PE")),
                Elem.INT(U("PP/PE")),
            ]),
            "gpio": Elem.ARRAY(T({'de': "Signale auf den GPIOs", 'en': "Signals on the GPIOs"}), members=[
                Elem.BOOL(T({'de': "Eingang", 'en': "Input"}), version=Version.WARP1),
                Elem.BOOL(T({'de': "Ausgang", 'en': "Output"}), version=Version.WARP1),
                Elem.BOOL(T({'de': "Motoreingangsschalter", 'en': "Motor input switch"}), version=Version.WARP1),
                Elem.BOOL(T({'de': "Relais", 'en': "Relay"}), version=Version.WARP1),
                Elem.BOOL(T({'de': "Motorfehler", 'en': "Motor error"}), version=Version.WARP1),

                Elem.BOOL(T({'de': "Stromkonfiguration 0", 'en': "Current configuration 0"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Motorfehler", 'en': "Motor error"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Gleichstromfehler", 'en': "DC fault"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Stromkonfiguration 1", 'en': "Current configuration 1"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "DC-Fehlerstromschutz-Test", 'en': "DC residual current protection test"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Abschalteingang", 'en': "Shutdown input"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Taster", 'en': "Button"}), version=Version.WARP2),
                Elem.BOOL(U("CP-PWM"), version=Version.WARP2),
                Elem.BOOL(T({'de': "Motoreingangsschalter", 'en': "Motor input switch"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Schützsteuerung", 'en': "Contactor control"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Konfigurierbarer Ausgang", 'en': "Configurable output"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "CP-Trennung", 'en': "CP disconnect"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Motor aktiv", 'en': "Motor active"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Motor-Phase", 'en': "Motor phase"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Schützprüfung vorher", 'en': "Contactor check before"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Schützprüfung nachher", 'en': "Contactor check after"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Konfigurierbarer Eingang", 'en': "Configurable input"}), version=Version.WARP2),
                Elem.BOOL(U("DC X6"), version=Version.WARP2),
                Elem.BOOL(U("DC X30"), version=Version.WARP2),
                Elem.BOOL(U("LED"), version=Version.WARP2),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP2),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP2),

                Elem.BOOL(U("DC X30"), version=Version.WARP3),
                Elem.BOOL(U("DC X6"), version=Version.WARP3),
                Elem.BOOL(T({'de': "DC-Fehler", 'en': "DC fault"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "DC-Fehlerstromschutz-Test", 'en': "DC residual current protection test"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "EVSE-Status-LED", 'en': "EVSE status LED"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Taster", 'en': "Button"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "LED rot", 'en': "LED red"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "LED blau", 'en': "LED blue"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "LED grün", 'en': "LED green"}), version=Version.WARP3),
                Elem.BOOL(U("CP-PWM"), version=Version.WARP3),
                Elem.BOOL(T({'de': "Schütz 1", 'en': "Contactor 1"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Schütz 0", 'en': "Contactor 0"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Schütz 1 Feedback", 'en': "Contactor 1 feedback"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Schütz 0 Feedback", 'en': "Contactor 0 feedback"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "PE-Prüfung", 'en': "PE check"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Stromkonfiguration 1", 'en': "Current configuration 1"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "CP-Trennung", 'en': "CP disconnect"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Stromkonfiguration 0", 'en': "Current configuration 0"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Abschalteingang", 'en': "Shutdown input"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Versionsdetektion", 'en': "Version detection"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP3),
                Elem.BOOL(T({'de': "Nicht belegt", 'en': "Not assigned"}), version=Version.WARP3),
            ]),
            "charging_time": Elem.INT(T({'de': "Ungefähre Zeit des Ladevorgangs. Nur für Lastmanagementzwecke zu verwenden!", 'en': "Approximate duration of the charging process. Only to be used for load management purposes!"}), unit=Units.ms),
            "time_since_state_change": Elem.INT(T({'de': "Zeit seit dem letzten IEC-61851-Zustandswechsel. Falls der Zustand 2 (= B: Lädt) ist, entspricht dieser Wert der Ladezeit.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", 'en': "Time since the last IEC 61851 state change. If the state is 2 (= B: Charging), this value corresponds to the charging time.<br/><br/> Warning: This time is measured directly via the processor clock. The accuracy is therefore only sufficient for time measurements in the range of minutes to a few hours. The time measurement overflows after approximately 50 days and starts again at 0."}), unit=Units.ms),
            "uptime": Elem.INT(T({'de': "Zeit seit Starten des Ladecontrollers.<br/><br/> Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", 'en': "Time since the charge controller started.<br/><br/> Warning: This time is measured directly via the processor clock. The accuracy is therefore only sufficient for time measurements in the range of minutes to a few hours. The time measurement overflows after approximately 50 days and starts again at 0."}), unit=Units.ms),
            "time_since_dc_fault_check": Elem.INT(T({'de': "Zeit seit dem letzten Test des DC-Fehlerstrom-Schutzmoduls. Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", 'en': "Time since the last test of the DC residual current protection module. Warning: This time is measured directly via the processor clock. The accuracy is therefore only sufficient for time measurements in the range of minutes to a few hours. The time measurement overflows after approximately 50 days and starts again at 0."}), unit=Units.ms, version=Version.WARP2 | Version.WARP3),
            "dc_fault_sensor_type": Elem.INT(T({'de': "Typ des DC-Fehlerstrom-Sensors", 'en': "Type of DC residual current sensor"}), version=Version.WARP2 | Version.WARP3, constants=[
                Const(0, U("X904")),
                Const(1, U("X804"))
            ]),
            "dc_fault_pins": Elem.INT(T({'de': "Zustand der Pins des DC-Schutzmodul beim letzten Fehler, falls ein Fehler aufgetreten ist. Kalibrierungsfehlercode, falls ein Kalibrierungsfehler aufgetreten ist.", 'en': "State of the DC protection module pins at the last error, if an error occurred. Calibration error code, if a calibration error occurred."}), version=Version.WARP2 | Version.WARP3),
            "phases_current": Elem.INT(T({'de': "Aktueller Zustand der Phasenumschaltung", 'en': "Current state of phase switching"}), version=Version.WARP3, constants=[
                Const(1, T({'de': "einphasig", 'en': "single-phase"})),
                Const(3, T({'de': "dreiphasig", 'en': "three-phase"}))
            ]),
            "phases_requested": Elem.INT(T({'de': "Angeforderter Zustand der Phasenumschaltung", 'en': "Requested state of phase switching"}), version=Version.WARP3, constants=[
                Const(1, T({'de': "einphasig", 'en': "single-phase"})),
                Const(3, T({'de': "dreiphasig", 'en': "three-phase"}))
            ]),
            "phases_state": Elem.INT(T({'de': "Zustand der Phasenumschaltung", 'en': "State of phase switching"}), version=Version.WARP3, constants=[
                Const(0, T({'de': "Derzeit wird keine Umschaltung durchgeführt", 'en': "Currently no switching is being performed"})),
                Const(1, T({'de': "Stoppe Ladevorgang, warte auf Abschaltung durch Fahrzeug", 'en': "Stop charging process, waiting for shutdown by vehicle"})),
                Const(2, T({'de': "Ladevorgang angehalten. Schalte Schütz ab", 'en': "Charging process stopped. Switch off contactor"})),
                Const(3, T({'de': "Schütz abgeschaltet. Trenne Control Pilot.", 'en': "Contactor switched off. Disconnect control pilot."})),
                Const(4, T({'de': "Control Pilot getrennt. Wechsle zwischen drei- und einphasig.", 'en': "Control pilot disconnected. Switch between three-phase and single-phase."})),
                Const(5, T({'de': "Phasen gewechselt. Verbinde Control Pilot.", 'en': "Phases switched. Connect control pilot."})),
                Const(6, T({'de': "Control Pilot verbunden. Starte Ladevorgang, warte auf Stromanforderung durch Fahrzeug", 'en': "Control pilot connected. Start charging process, waiting for current request by vehicle"})),
                Const(7, T({'de': "Fahrzeug fordert Strom an. Schalte Schütz.", 'en': "Vehicle requests current. Switch contactor."})),
            ]),
            "phases_info": Elem.INT(T({'de': "Weitere Informationen zur Phasenumschaltung", 'en': "Additional information about phase switching"}), version=Version.WARP3, constants=[
                Const(0, T({'de': "Umschaltungszustand normal", 'en': "Switching state normal"})),
                Const(1, T({'de': "Ladecontroller hat automatische Umschaltung von drei- auf einphasig durchgeführt. Siehe {{{ref:evse/phase_auto_switch}}}", 'en': "Charge controller performed automatic switching from three-phase to single-phase. See {{{ref:evse/phase_auto_switch}}}"}))
            ]),
            "temperature": Elem.INT(T({'de': "Temperatur des Ladecontrollers", 'en': "Temperature of the charge controller"}), version=Version.WARP3, unit=Units.hundredth_degree_celsius)
        })
    ),

    Func("external_current", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der von der externen Steuerung vorgegebene Ladestrom.", 'en': "The charging current specified by the external control."}), members={
            "current": Elem.INT(T({'de': "Der von der externen Steuerung vorgegebene Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", 'en': "The charging current specified by the external control. 6000 (=6 amperes) to 32000 (=32 amperes) or 0 if the slot is blocked."}), unit=Units.mA)
        })
    ),

    Func("external_clear_on_disconnect", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob der von der externen Ladesteuerung vorgegebene Ladestrom beim Abziehen eines Fahrzeugs automatisch auf 0 gesetzt werden soll.", 'en': "Indicates whether the charging current specified by the external charging control should be automatically set to 0 when a vehicle is disconnected."}), members={
            "clear_on_disconnect": Elem.BOOL(T({'de': "Gibt an, ob der Ladestrom dieses Slots beim Abziehen eines Fahrzeugs auf 0 gesetzt wird.", 'en': "Indicates whether the charging current of this slot is set to 0 when a vehicle is disconnected."}), constants=[
                Const(True, T({'de': "Slot wird beim Abziehen blockieren", 'en': "Slot will block on disconnect"})),
                Const(False, T({'de': "Slot wird gesetzten Ladestrom beim Abziehen beibehalten", 'en': "Slot will keep set charging current on disconnect"})),
            ])
        })
    ),

    Func("management_current", FuncType.STATE, Elem.OBJECT(T({'de': "Der vom Lastmanagement vorgegebene Ladestrom.", 'en': "The charging current specified by load management."}), members={
            "current": Elem.INT(T({'de': "6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockieren soll.", 'en': "6000 (=6 amperes) to 32000 (=32 amperes) or 0 if the slot should be blocked."}), unit=Units.mA)
        })
    ),

    Func("auto_start_charging", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguriert, ob ein angeschlossenes Fahrzeug selbstständig geladen wird.", 'en': "Configures whether a connected vehicle is charged automatically."}), members={
            "auto_start_charging": Elem.BOOL(T({'de': "Konfiguriert, ob ein angeschlossenes Fahrzeug selbstständig geladen wird. Falls aktiviert, beginnt sofort, wenn das Fahrzeug angeschlossen wird der Ladevorgang. Falls deaktiviert, kann das Laden mit {{{ref:evse/start_charging}}} gestartet werden. Diese Einstellung setzt `clear_on_disconnect` der Ladestromgrenze 4 (Manuelle Ladefreigabe)", 'en': "Configures whether a connected vehicle is charged automatically. If enabled, charging starts immediately when the vehicle is connected. If disabled, charging can be started with {{{ref:evse/start_charging}}}. This setting sets `clear_on_disconnect` of charge current limit 4 (Manual charge release)"})),
        })
    ),

    Func("global_current", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der über das Webinterface vorgegebene Ladestrom. **Achtung: Dieser Strom wird auf dem Ladecontroller persistent gespeichert. Für häufige Änderungen sollte stattdessen {{{ref:evse/external_current}}} verwendet werden, um den Flash des Ladecontrollers zu schonen!**", 'en': "The charging current specified via the web interface. **Warning: This current is stored persistently on the charge controller. For frequent changes, {{{ref:evse/external_current}}} should be used instead to preserve the charge controller's flash memory!**"}), members={
            "current": Elem.INT(T({'de': "Der über das Webinterface vorgegebene Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", 'en': "The charging current specified via the web interface. 6000 (=6 amperes) to 32000 (=32 amperes) or 0 if the slot is blocked."}), unit=Units.mA)
        })
    ),

    Func("management_enabled", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob der Ladeslot des Lastmanagements aktiv ist.", 'en': "Indicates whether the load management charge slot is active."}), members={
            "enabled": Elem.BOOL(T({'de': "true wenn Lastmanagement aktiviert ist, sonst false", 'en': "true if load management is enabled, otherwise false"}))
        })
    ),

    Func("user_current", FuncType.STATE, Elem.OBJECT(T({'de': "Der von der Benutzerautorisierung erlaubte Ladestrom.", 'en': "The charging current allowed by user authorization."}), members={
            "current": Elem.INT(T({'de': "Der von der Benutzerautorisierung erlaubte Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", 'en': "The charging current allowed by user authorization. 6000 (=6 amperes) to 32000 (=32 amperes) or 0 if the slot is blocked."}), unit=Units.mA)
        })
    ),

    Func("user_enabled", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob der Ladeslot der Benutzerautorisierung aktiv ist.", 'en': "Indicates whether the user authorization charge slot is active."}), members={
            "enabled": Elem.BOOL(T({'de': "true wenn die Benutzerautorisierung aktiviert ist, sonst false", 'en': "true if user authorization is enabled, otherwise false"}))
        })
    ),

    Func("external_enabled", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob der Ladeslot der externen Steuerung aktiv ist.", 'en': "Indicates whether the external control charge slot is active."}), members={
            "enabled": Elem.BOOL(T({'de': "true wenn die externe Steuerung aktiviert ist, sonst false", 'en': "true if external control is enabled, otherwise false"}))
        })
    ),

    Func("external_defaults", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die nach einem Neustart des Ladecontrollers übernommenen Einstellungen des Ladeslots der externen Steuerung.", 'en': "The settings of the external control charge slot adopted after a restart of the charge controller."}), members={
            "current": Elem.INT(T({'de': "Der nach einem Neustart übernommene Maximalstrom im Ladeslot der externen Steuerung. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", 'en': "The maximum current in the external control charge slot adopted after a restart. 6000 (=6 amperes) to 32000 (=32 amperes) or 0 if the slot is blocked."}), unit=Units.mA),
            "clear_on_disconnect": Elem.BOOL(T({'de': "Gibt an, ob der Ladestrom dieses Slots beim Abziehen eines Fahrzeugs auf 0 gesetzt wird.", 'en': "Indicates whether the charging current of this slot is set to 0 when a vehicle is disconnected."}), constants=[
                Const(True, T({'de': "Slot wird beim Abziehen blockieren", 'en': "Slot will block on disconnect"})),
                Const(False, T({'de': "Slot wird gesetzten Ladestrom beim Abziehen beibehalten", 'en': "Slot will keep set charging current on disconnect"})),
            ]),
        })
    ),

    Func("modbus_tcp_enabled", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob die Ladeslots für Modbus-TCP aktiv sind (und damit ob Modbus-TCP Schreibzugriff gewährt wurde).", 'en': "Indicates whether the charge slots for Modbus TCP are active (and thus whether Modbus TCP write access has been granted)."}), members={
            "enabled": Elem.BOOL(T({'de': "true wenn die Ladeslots für Modbus-TCP aktiviert sind, sonst false", 'en': "true if the charge slots for Modbus TCP are enabled, otherwise false"}))
        })
    ),

    Func("ocpp_enabled", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob der Ladeslot für OCPP aktiv ist.", 'en': "Indicates whether the charge slot for OCPP is active."}), members={
            "enabled": Elem.BOOL(T({'de': "true wenn OCPP aktiviert ist, sonst false", 'en': "true if OCPP is enabled, otherwise false"}))
        })
    ),

    Func("automation_current", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der von der Automatisierung erlaubte Ladestrom.", 'en': "The charging current allowed by automation."}), members={
            "current": Elem.INT(T({'de': "Der von der Automatisierung erlaubte Ladestrom. 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 falls der Slot blockiert.", 'en': "The charging current allowed by automation. 6000 (=6 amperes) to 32000 (=32 amperes) or 0 if the slot is blocked."}), unit=Units.mA)
        })
    ),

    Func("gpio_configuration", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der konfigurierbaren Ein- und Ausgänge.", 'en': "The configuration of the configurable inputs and outputs."}), version=Version.WARP2 | Version.WARP3, members={
            "shutdown_input": Elem.INT(T({'de': "Die Konfiguration des Abschalteingangs.", 'en': "The configuration of the shutdown input."}), constants=[
                Const(0, T({'de': "Nicht konfiguriert", 'en': "Not configured"})),
                Const(1, T({'de': "Abschalten wenn geöffnet", 'en': "Shutdown when open"})),
                Const(2, T({'de': "Abschalten wenn geschlossen", 'en': "Shutdown when closed"})),
                Const(3, T({'de': "Begrenzen auf 4200 W wenn geöffnet (§14 EnWG)", 'en': "Limit to 4200 W when open (§14 EnWG)"})),
                Const(4, T({'de': "Begrenzen auf 4200 W wenn geschlossen (§14 EnWG)", 'en': "Limit to 4200 W when closed (§14 EnWG)"})),
            ]),
            "input": Elem.INT(T({'de': "Die Konfiguration des konfigurierbaren Eingangs. Wird bei WARP3 ignoriert.", 'en': "The configuration of the configurable input. Ignored on WARP3."}), constants=[
                Const(0, T({'de': "Nicht konfiguriert", 'en': "Not configured"})),
                Const(1, T({'de': "Blockiert wenn geschlossen", 'en': "Blocked when closed"})),
                Const(2, T({'de': "Limitiert auf 6 A wenn geschlossen", 'en': "Limited to 6 A when closed"})),
                Const(3, T({'de': "Limitiert auf 8 A wenn geschlossen", 'en': "Limited to 8 A when closed"})),
                Const(4, T({'de': "Limitiert auf 10 A wenn geschlossen", 'en': "Limited to 10 A when closed"})),
                Const(5, T({'de': "Limitiert auf 13 A wenn geschlossen", 'en': "Limited to 13 A when closed"})),
                Const(6, T({'de': "Limitiert auf 16 A wenn geschlossen", 'en': "Limited to 16 A when closed"})),
                Const(7, T({'de': "Limitiert auf 20 A wenn geschlossen", 'en': "Limited to 20 A when closed"})),
                Const(8, T({'de': "Limitiert auf 25 A wenn geschlossen", 'en': "Limited to 25 A when closed"})),
                Const(9, T({'de': "Blockiert wenn geöffnet", 'en': "Blocked when open"})),
                Const(10, T({'de': "Limitiert auf 6 A wenn geöffnet", 'en': "Limited to 6 A when open"})),
                Const(11, T({'de': "Limitiert auf 8 A wenn geöffnet", 'en': "Limited to 8 A when open"})),
                Const(12, T({'de': "Limitiert auf 10 A wenn geöffnet", 'en': "Limited to 10 A when open"})),
                Const(13, T({'de': "Limitiert auf 13 A wenn geöffnet", 'en': "Limited to 13 A when open"})),
                Const(14, T({'de': "Limitiert auf 16 A wenn geöffnet", 'en': "Limited to 16 A when open"})),
                Const(15, T({'de': "Limitiert auf 20 A wenn geöffnet", 'en': "Limited to 20 A when open"})),
                Const(16, T({'de': "Limitiert auf 25 A wenn geöffnet", 'en': "Limited to 25 A when open"})),
            ]),
            "output": Elem.INT(T({'de': "Die Konfiguration des konfigurierbaren Ausgangs. Wird bei WARP3 ignoriert.", 'en': "The configuration of the configurable output. Ignored on WARP3."}), constants=[
                Const(0, T({'de': "Verbunden mit Masse", 'en': "Connected to ground"})),
                Const(1, T({'de': "Hochohmig", 'en': "High-impedance"})),
            ]),
        })
    ),

    Func("button_configuration", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration des Tasters in der Frontblende. Benötigt das Feature <a href=\"#features_button_configuration\"><code>\"button_configuration\"</code></a>", 'en': "The configuration of the button in the front panel. Requires the feature <a href=\"#features_button_configuration\"><code>\"button_configuration\"</code></a>"}), members={
            "button": Elem.INT(T({'de': "Die Konfiguration des Tasters in der Frontblende.", 'en': "The configuration of the button in the front panel."}), constants=[
                Const(0, T({'de': "Deaktiviert", 'en': "Disabled"})),
                Const(1, T({'de': "Ladestart wenn gedrückt", 'en': "Start charging when pressed"})),
                Const(2, T({'de': "Ladestop wenn gedrückt", 'en': "Stop charging when pressed"})),
                Const(3, T({'de': "Ladestart/stop wenn gedrückt", 'en': "Start/stop charging when pressed"})),
            ]),
        },
        version=Version.WARP2 | Version.WARP3)
    ),

    Func("led_configuration", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der LED des Tasters in der Frontblende.", 'en': "The configuration of the LED in the front panel button."}), members={
            "enable_api": Elem.BOOL(T({'de': "Legt fest, ob die LED über die {{{ref:evse/indicator_led}}}-API oder über Modbus TCP gesteuert werden darf.", 'en': "Determines whether the LED may be controlled via the {{{ref:evse/indicator_led}}} API or via Modbus TCP."}), constants=[
                Const(False, T({'de': "LED darf nicht gesteuert werden. Aufrufe von {{{ref:evse/indicator_led}}} werden ignoriert", 'en': "LED may not be controlled. Calls to {{{ref:evse/indicator_led}}} are ignored"})),
                Const(True, T({'de': "LED darf gesteuert werden. Aufrufe von {{{ref:evse/indicator_led}}} werden nur dann ignoriert, wenn das EVSE einen Fehlerzustand anzeigen möchte.", 'en': "LED may be controlled. Calls to {{{ref:evse/indicator_led}}} are only ignored when the EVSE wants to display an error state."}))
            ]),
        })
    ),

    Func("user_calibration", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Erlaubt es, die werksseitige Kalibrierung des EVSEs auszulesen und zu überschreiben. Um die Kalibierung auf den Werkszustand zurückzusetzen, kann ein Payload mit user_calibration_active auf false geschickt werden. Die weiteren Werte werden dann ignoriert.", 'en': "Allows reading and overwriting the factory calibration of the EVSE. To reset the calibration to factory state, a payload with user_calibration_active set to false can be sent. The other values are then ignored."}), members={
            "user_calibration_active": Elem.BOOL(T({'de': "Gibt an, ob die werksseitige Kalibrierung überschrieben wurde.", 'en': "Indicates whether the factory calibration has been overwritten."})),
            "voltage_diff": Elem.INT(T({'de': "Einer der Kalibrierungsparameter.", 'en': "One of the calibration parameters."})),
            "voltage_mul": Elem.INT(T({'de': "Einer der Kalibrierungsparameter.", 'en': "One of the calibration parameters."})),
            "voltage_div": Elem.INT(T({'de': "Einer der Kalibrierungsparameter.", 'en': "One of the calibration parameters."})),
            "resistance_2700": Elem.INT(T({'de': "Einer der Kalibrierungsparameter.", 'en': "One of the calibration parameters."})),
            "resistance_880": Elem.ARRAY(T({'de': "Einer der Kalibrierungsparameter.", 'en': "One of the calibration parameters."}), member_type=EType.INT),
        },
        version=Version.WARP1)
    ),

    Func("ev_wakeup", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob das EVSE automatisch versucht die Ladeelektronik des Fahrzeugs aus einem Energiesparmodus zu wecken, indem ein Abziehen und Anstecken des Ladekabels vorgetäuscht wird. (Control-Pilot-Trennung/CP-Trennung) Benötigt das Feature <a href=\"#features_cp_disconnect\"><code>\"cp_disconnect\"</code></a>", 'en': "Indicates whether the EVSE automatically attempts to wake the vehicle's charging electronics from power saving mode by simulating unplugging and plugging in the charging cable. (Control Pilot disconnect/CP disconnect) Requires the feature <a href=\"#features_cp_disconnect\"><code>\"cp_disconnect\"</code></a>"}), version=Version.WARP2 | Version.WARP3, members={
            "enabled": Elem.BOOL(T({'de': "true wenn die Ladeelektronik des Fahrzeugs geweckt werden soll", 'en': "true if the vehicle's charging electronics should be woken up"}))
        })
    ),

    Func("control_pilot_disconnect", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob ein Abziehen und Anstecken des Ladekabels vorgetäuscht ist. (Control-Pilot-Trennung/CP-Trennung) <strong>Aktualisierungen werden ignoriert, falls das Lastmanagement aktiviert ist.</strong> Siehe {{{ref:evse/management_enabled}}}.  Benötigt das Feature <a href=\"#features_cp_disconnect\"><code>\"cp_disconnect\"</code></a>", 'en': "Indicates whether unplugging and plugging in the charging cable is simulated. (Control Pilot disconnect/CP disconnect) <strong>Updates are ignored if load management is enabled.</strong> See {{{ref:evse/management_enabled}}}.  Requires the feature <a href=\"#features_cp_disconnect\"><code>\"cp_disconnect\"</code></a>"}), version=Version.WARP2 | Version.WARP3, members={
            "disconnect": Elem.BOOL(T({'de': "true falls CP getrennt ist, sonst false", 'en': "true if CP is disconnected, otherwise false"}))
        })
    ),

    Func("boost_mode", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, ob das EVSE der Ladeelektronik des Fahrzeugs einen leicht höheren Ladestrom vorgibt (+ 0,24 A) um Messfehler der Ladeelektronik zu kompensieren. Nur Verwenden, falls ein Fahrzeug mit einem kleineren als dem erlaubten Ladestrom lädt!", 'en': "Indicates whether the EVSE specifies a slightly higher charging current (+ 0.24 A) to the vehicle's charging electronics to compensate for measurement errors in the charging electronics. Only use if a vehicle charges with a lower than the allowed charging current!"}), members={
            "enabled": Elem.BOOL(T({'de': "true falls der Boost-Modus aktiviert ist, sonst false", 'en': "true if boost mode is enabled, otherwise false"}))
        })
    ),

    Func("phase_auto_switch", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguriert, ob ein WARP3 Charger Pro automatisch von drei- auf einphasiges Laden wechseln soll, wenn ein Fahrzeug angeschlossen ist, dass nur auf L1 Strom bezieht.", 'en': "Configures whether a WARP3 Charger Pro should automatically switch from three-phase to single-phase charging when a vehicle is connected that only draws current on L1."}), version=Version.WARP3, members={
            "enabled": Elem.BOOL(T({'de': "true falls die automatische Umschaltung aktiviert ist, sonst false", 'en': "true if automatic switching is enabled, otherwise false"}))
        })
    ),

    Func("phases_connected", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguriert, ob die Wallbox fest ein- oder dreiphasig angeschlossen ist. Damit wird z.B. die 4200 W-Limitierung nach §14 EnWG berechnet", 'en': "Configures whether the charger is permanently connected single-phase or three-phase. This is used to calculate the 4200 W limitation according to §14 EnWG"}), version=Version.WARP2 | Version.WARP3, members={
            "phases": Elem.INT(T({'de': "Maximale Anzahl der angeschlossenen Phasen. Eine Wallbox hinter einem Phasenumschaltungsschütz (z.B mit dem WARP Energy Manager) ist dreiphasig angeschlossen.", 'en': "Maximum number of connected phases. A charger behind a phase switching contactor (e.g. with the WARP Energy Manager) is connected three-phase."}), constants=[
                Const(1, T({'de': "Wallbox ist fest einphasig angeschlossen", 'en': "Charger is permanently connected single-phase"})),
                Const(3, T({'de': "Wallbox ist fest dreiphasig, oder hinter einem Phasenumschaltungsschütz angeschlossen", 'en': "Charger is permanently connected three-phase, or behind a phase switching contactor"}))
            ])
        })
    ),


    Func("reset_dc_fault_current_state", FuncType.COMMAND, Elem.OBJECT(T({'de': "Setzt das DC-Fehlerstrom-Schutzmodul zurück. <strong>Vor dem Zurücksetzen muss der Grund des Fehlers unbedingt behoben werden!</strong>", 'en': "Resets the DC residual current protection module. <strong>Before resetting, the cause of the fault must be fixed!</strong>"}), version=Version.WARP2 | Version.WARP3, members={
            "password": Elem.INT(T({'de': "Passwort, das zum Zurücksetzen benötigt wird. Das Passwort lautet 0xDC42FA23.", 'en': "Password required for reset. The password is 0xDC42FA23."}))
        })
    ),

    Func("trigger_dc_fault_test", FuncType.COMMAND, Elem.NULL(T({'de': "Startet einen Test des DC-Fehlerstrom-Schutzmoduls.", 'en': "Starts a test of the DC residual current protection module."}), version=Version.WARP2 | Version.WARP3)),

    Func("gp_output", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der aktuelle Wert des konfigurierbaren Ausgangs.", 'en': "The current value of the configurable output."}), version=Version.WARP2, members={
            "gp_output": Elem.INT(T({'de': "Der aktuelle Wert des konfigurierbaren Ausgangs.", 'en': "The current value of the configurable output."}), constants=[
                Const(0, T({'de': "Verbunden mit Masse", 'en': "Connected to ground"})),
                Const(1, T({'de': "Hochohmig", 'en': "High-impedance"})),
            ]),
        })
    ),

    Func("stop_charging", FuncType.COMMAND, Elem.NULL(T({'de': "Beendet den laufenden Ladevorgang. Ein Aufruf dieser Funktion ist äquivalent zum Stoppen über den Taster an der Wallbox: Es wird TODO LINK Slot 4 blockiert. Ein Ladevorgang kann mit {{{ref:evse/start_charging}}} wieder gestartet werden.", 'en': "Stops the current charging process. Calling this function is equivalent to stopping via the button on the charger: TODO LINK Slot 4 is blocked. Charging can be restarted with {{{ref:evse/start_charging}}}."})), command_is_action=True),

    Func("start_charging", FuncType.COMMAND, Elem.NULL(T({'de': "Startet einen Ladevorgang. Ein Aufruf dieser Funktion ist äquivalent zum Starten über den Taster an der Wallbox: Es wird TODO LINK Slot 4 freigegeben. Ein Ladevorgang kann mit {{{ref:evse/stop_charging}}} wieder gestoppt werden.", 'en': "Starts a charging process. Calling this function is equivalent to starting via the button on the charger: TODO LINK Slot 4 is released. Charging can be stopped again with {{{ref:evse/stop_charging}}}."})), command_is_action=True),

    #Func("start_debug", FuncType.HTTP_ONLY, Elem.OPAQUE("Startet ein Ladeprotokoll. Es werden hochfrequent Messwerte des Ladecontrollers auf die WebSockets geschrieben, bis {{{ref:evse/stop_debug}}} aufgerufen wird.")),
    #Func("stop_debug", FuncType.HTTP_ONLY, Elem.OPAQUE("Stoppt ein Ladeprotokoll. Siehe {{{ref:evse/start_debug}}} für Details.")),

    Func("meter_config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Gibt an, welcher Stromzähler als der im WARP Charger verbaute Stromzähler betrachtet werden soll, z.B. für Ladetracker, Ladelimits, usw. Damit kann beispielsweise ein externer Zähler für die Aufzeichnung von Ladevorgängen verwendet werden.\n\n:::tip\n\nFür das PV-Überschussladen muss ein anderer Zähler genutzt werden, der die Werte am Hausanschlusspunkt misst. Die ID dieses Zählers wird nicht hier, sondern mit `meter_slot_grid_power` in {{{ref:power_manager/config}}} gesetzt\n\n:::", 'en': "Indicates which energy meter should be considered as the energy meter installed in the WARP Charger, e.g. for charge tracker, charge limits, etc. This allows, for example, an external meter to be used for recording charging processes.\n\n:::tip\n\nFor PV excess charging, a different meter must be used that measures the values at the grid connection point. The ID of this meter is not set here, but with `meter_slot_grid_power` in {{{ref:power_manager/config}}}\n\n:::"}), members={
        "slot": Elem.INT(T({'de': "Stromzählerslot, der verwendet werden soll", 'en': "Energy meter slot to be used"}))
    }))
])
