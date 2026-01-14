from api_doc_common import *

automation = Module("automation", T({'de': "Automatisierung", 'en': "Automation"}), "", T({'de': "Mit dem `automation`-Modul können einfache Regeln ausgeführt werden. Eine Regel besteht aus einer auszuführenden Aktion, sowie aus einer Bedingung, die zutreffen muss, damit die Aktion ausgeführt wird.", 'en': "With the `automation` module, simple rules can be executed. A rule consists of an action to be executed and a condition that must be met for the action to be executed."}), Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand der Automatisierung. Gibt an, welche Bedingungen und Aktionen von dieser Firmware unterstützt werden und welche der unterstützten Bedingungen und Aktionen im Moment ausgeführt werden können. Je nach Konfiguration können bestimmte Bedingungen und Aktionen nicht ausgeführt werden, beispielsweise kann nicht auf MQTT-Nachrichten reagiert werden, wenn keine MQTT-Verbindung konfiguriert ist.", 'en': "The state of the automation. Indicates which conditions and actions are supported by this firmware and which of the supported conditions and actions can currently be executed. Depending on the configuration, certain conditions and actions cannot be executed, for example, MQTT messages cannot be responded to if no MQTT connection is configured."}), members={
        "registered_triggers": Elem.ARRAY(T({'de': "Dieser Firmware bekannte Bedingungen (Union-Tags des Triggers einer Regel aus {{{ref:automation/config}}}).", 'en': "Conditions known to this firmware (union tags of the trigger of a rule from {{{ref:automation/config}}})."}), members=[
            * 19 * [Elem.INT(T({'de': "Eine bekannte Bedingung.", 'en': "A known condition."}))]]),
        "registered_actions": Elem.ARRAY(T({'de': "Dieser Firmware bekannte Aktionen (Union-Tags der Aktion einer Regel aus {{{ref:automation/config}}})", 'en': "Actions known to this firmware (union tags of the action of a rule from {{{ref:automation/config}}})"}), members=[
            * 16 * [Elem.INT(T({'de': "Eine bekannte Aktion.", 'en': "A known action."}))]]),

        "enabled_triggers": Elem.ARRAY(T({'de': "Aktuell ausführbare Bedingungen (Union-Tags des Triggers einer Regel aus {{{ref:automation/config}}}). Ist immer eine Teilmenge der `registered_triggers`.", 'en': "Currently executable conditions (union tags of the trigger of a rule from {{{ref:automation/config}}}). Is always a subset of `registered_triggers`."}), members=[
            * 19 * [Elem.INT(T({'de': "Eine ausführbare Bedingung.", 'en': "An executable condition."}))]]),
        "enabled_actions": Elem.ARRAY(T({'de': "Aktuell ausführbare Aktionen (Union-Tags der Aktion einer Regel aus {{{ref:automation/config}}}). Ist immer eine Teilmenge der `registered_actions`.", 'en': "Currently executable actions (union tags of the action of a rule from {{{ref:automation/config}}}). Is always a subset of `registered_actions`."}), members=[
            * 16 * [Elem.INT(T({'de': "Eine ausführbare Aktion.", 'en': "An executable action."}))]]),
    })),
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der Automatisierung.", 'en': "The configuration of the automation."}), members={
            "tasks": Elem.ARRAY(T({'de': "Konfigurierte Regeln", 'en': "Configured rules"}), members=[
                * 14 * [Elem.OBJECT(T({'de': "Eine Automatisierungsregel", 'en': "An automation rule"}), members = {
                    "trigger": Elem.UNION(T({'de': "Bedingung, die zutreffen muss, damit Aktion ausgeführt wird", 'en': "Condition that must be met for the action to be executed"}), members={
                        0: Elem.NULL(T({'de': "Keine Bedingung konfiguriert.", 'en': "No condition configured."})),
                        1: Elem.OBJECT(T({'de': "Zu einem bestimmten Zeitpunkt.", 'en': "At a specific time."}), members={
                            "mday": Elem.INT(T({'de': "Tag des Monats (1 bis 31 oder -1, 0, 32)", 'en': "Day of month (1 to 31 or -1, 0, 32)"}), constants=[
                                Const(-1, T({'de': "Jeder Tag des Monats", 'en': "Every day of the month"})),
                                Const(0, T({'de': "Jeder Tag des Monats", 'en': "Every day of the month"})),
                                Const(32, T({'de': "Letzter Tag des Monats", 'en': "Last day of the month"}))
                            ]),
                            "wday": Elem.INT(T({'de': "Wochentag", 'en': "Weekday"}), constants=[
                                Const(-1, T({'de': "Jeder Tag der Woche", 'en': "Every day of the week"})),
                                Const(0, T({'de': "Sonntag", 'en': "Sunday"})),
                                Const(1, T({'de': "Montag", 'en': "Monday"})),
                                Const(2, T({'de': "Dienstag", 'en': "Tuesday"})),
                                Const(3, T({'de': "Mittwoch", 'en': "Wednesday"})),
                                Const(4, T({'de': "Donnerstag", 'en': "Thursday"})),
                                Const(5, T({'de': "Freitag", 'en': "Friday"})),
                                Const(6, T({'de': "Samstag", 'en': "Saturday"})),
                                Const(7, T({'de': "Sonntag", 'en': "Sunday"})),
                                Const(8, T({'de': "Wochentags (Montag bis Freitag)", 'en': "Weekdays (Monday to Friday)"})),
                                Const(9, T({'de': "Am Wochenende (Samstag und Sonntag)", 'en': "On weekends (Saturday and Sunday)"})),
                            ]),
                            "hour": Elem.INT(T({'de': "Stunde des Tages (0 bis 23 oder -1)", 'en': "Hour of day (0 to 23 or -1)"}), constants=[
                                Const(-1, T({'de': "Stündlich", 'en': "Hourly"})),
                            ]),
                            "minute": Elem.INT(T({'de': "Minute des Tages (0 bis 59 oder -1)", 'en': "Minute of day (0 to 59 or -1)"}), constants=[
                                Const(-1, T({'de': "Minütlich", 'en': "Every minute"})),
                            ])
                        }),
                        2: Elem.OBJECT(T({'de': "Wechsel des Ladestatus", 'en': "Change of charging state"}), version=Version.WARPX, members={
                            "old_charger_state": Elem.INT(T({'de': "Ladestatus vor dem Übergang", 'en': "Charging state before transition"}), constants=[
                                Const(-1, T({'de': "Beliebiger Ladestatus", 'en': "Any charging state"})),
                                Const(0, T({'de': "Fahrzeug getrennt", 'en': "Vehicle disconnected"})),
                                Const(1, T({'de': "Warte auf Freigabe", 'en': "Waiting for release"})),
                                Const(2, T({'de': "Ladebereit", 'en': "Ready to charge"})),
                                Const(3, T({'de': "Lädt", 'en': "Charging"})),
                                Const(4, T({'de': "Fehler", 'en': "Error"}))
                            ]),
                            "new_charger_state": Elem.INT(T({'de': "Ladestatus nach dem Übergang", 'en': "Charging state after transition"}), constants=[
                                Const(-1, T({'de': "Beliebiger Ladestatus", 'en': "Any charging state"})),
                                Const(0, T({'de': "Fahrzeug getrennt", 'en': "Vehicle disconnected"})),
                                Const(1, T({'de': "Warte auf Freigabe", 'en': "Waiting for release"})),
                                Const(2, T({'de': "Ladebereit", 'en': "Ready to charge"})),
                                Const(3, T({'de': "Lädt", 'en': "Charging"})),
                                Const(4, T({'de': "Fehler", 'en': "Error"}))
                            ]),
                        }),
                        3: Elem.OBJECT(T({'de': "Empfang einer MQTT-Nachricht", 'en': "Receipt of an MQTT message"}), members={
                            "topic_filter": Elem.STRING(T({'de': "MQTT-Topic-Filter, mit dem auf Nachrichten gewartet werden soll.", 'en': "MQTT topic filter to wait for messages with."})),
                            "payload": Elem.STRING(T({'de': "Payload, der in der Nachricht enthalten sein soll", 'en': "Payload that should be contained in the message"})),
                            "retain": Elem.BOOL(T({'de': "Gibt an, ob auf retained-Pakete reagiert werden soll", 'en': "Indicates whether to react to retained packets"})),
                            "use_prefix": Elem.BOOL(T({'de': "Gibt an, ob der konfigurierte Global-Topic-Prefix (siehe {{{ref:mqtt/config}}}) vor dem konfigurierten Topic vorangestellt werden soll.", 'en': "Indicates whether the configured global topic prefix (see {{{ref:mqtt/config}}}) should be prepended to the configured topic."}))
                        }),
                        4: Elem.NULL(T({'de': "Drücken des Fronttasters", 'en': "Pressing the front button"}), version=Version.WARP2 | Version.WARP3),
                        5: Elem.OBJECT(T({'de': "Erkennen eines NFC-Tags", 'en': "Detection of an NFC tag"}), version=Version.WARPX, members={
                            "tag_type": Elem.INT(T({'de': "Typ des Tags", 'en': "Type of tag"}), constants=[
                                Const(0, U("Mifare Classic")),
                                Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
                                Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
                                Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
                                Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
                            ]),
                            "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. 01:23:AB:3D", 'en': "ID of the tag. Up to 10 hex bytes depending on tag type, separated by ':'. e.g. 01:23:AB:3D"})),
                        }),
                        6: Elem.NULL(T({'de': "Erreichen des Ladezeit- oder Energie-Limits", 'en': "Reaching the charging time or energy limit"}), version=Version.WARPX),
                        7: Elem.OBJECT(T({'de': "Schalten des Abschalteingangs", 'en': "Switching of the shutdown input"}), version=Version.WARP2 | Version.WARP3, members={
                            "closed": Elem.BOOL(T({'de': "Gibt an, ob bei geöffnetem oder geschlossenem Eingang reagiert werden soll", 'en': "Indicates whether to react when the input is open or closed"}), constants=[
                                Const(True, T({'de': "Reagieren bei geöffnetem Eingang", 'en': "React when input is open"})),
                                Const(False, T({'de': "Reagieren bei geschlossenem Eingang", 'en': "React when input is closed"})),
                            ])
                        }),
                        8: Elem.OBJECT(T({'de': "Schalten des konfigurierbaren Eingangs", 'en': "Switching of the configurable input"}), version=Version.WARP2, members={
                            "closed": Elem.BOOL(T({'de': "Gibt an, ob bei geöffnetem oder geschlossenem Eingang reagiert werden soll", 'en': "Indicates whether to react when the input is open or closed"}), constants=[
                                Const(True, T({'de': "Reagieren bei geöffnetem Eingang", 'en': "React when input is open"})),
                                Const(False, T({'de': "Reagieren bei geschlossenem Eingang", 'en': "React when input is closed"})),
                            ])
                        }),
                        9: Elem.NULL(T({'de': "Auslösen des Watchdogs der externen Steuerung.", 'en': "Triggering of the external control watchdog."}), version=Version.WARPX),
                        10: Elem.NULL(T({'de': "Erkennen eines Fehlers durch die Zählerüberwachung", 'en': "Detection of an error by the meter monitoring"}), version=Version.WARPX),
                        11: Elem.NULL(T({'de': "Auslösen des Watchdogs des Lastmanagements.", 'en': "Triggering of the load management watchdog."})),
                        12: Elem.OBJECT(T({'de': "Schalten von Eingang 3", 'en': "Switching of input 3"}), version=Version.WEM, members={
                            "state": Elem.BOOL(T({'de': "Gibt an, ob bei geöffnetem oder geschlossenem Eingang reagiert werden soll", 'en': "Indicates whether to react when the input is open or closed"}), constants=[
                                Const(True, T({'de': "Reagieren bei geöffnetem Eingang", 'en': "React when input is open"})),
                                Const(False, T({'de': "Reagieren bei geschlossenem Eingang", 'en': "React when input is closed"})),
                            ])
                        }),
                        13: Elem.OBJECT(T({'de': "Schalten von Eingang 4", 'en': "Switching of input 4"}), version=Version.WEM, members={
                            "state": Elem.BOOL(T({'de': "Gibt an, ob bei geöffnetem oder geschlossenem Eingang reagiert werden soll", 'en': "Indicates whether to react when the input is open or closed"}), constants=[
                                Const(True, T({'de': "Reagieren bei geöffnetem Eingang", 'en': "React when input is open"})),
                                Const(False, T({'de': "Reagieren bei geschlossenem Eingang", 'en': "React when input is closed"})),
                            ])
                        }),
                        14: Elem.OBJECT(T({'de': "Schalten der Phasenumschaltung", 'en': "Switching of the phase switching"}), version=Version.WEM, members={
                            "phase": Elem.INT(T({'de': "Gibt an, ob beim Umschalten auf ein- oder dreiphasig reagiert werden soll", 'en': "Indicates whether to react when switching to single-phase or three-phase"}), constants=[
                                Const(1, T({'de': "Reagieren beim Wechsel auf einphasig", 'en': "React when switching to single-phase"})),
                                Const(3, T({'de': "Reagieren beim Wechsel auf dreiphasig", 'en': "React when switching to three-phase"})),
                            ])
                        }),
                        15: Elem.OBJECT(T({'de': "Erkennen eines Fehlers durch die Schützüberwachung", 'en': "Detection of an error by the contactor monitoring"}), version=Version.WEM, members={
                            "contactor_okay": Elem.BOOL(T({'de': "Gibt an, ob reagiert werden soll, wenn ein oder kein Schützfehler vorliegt.", 'en': "Indicates whether to react when a contactor error is present or not."}), constants=[
                                Const(True, T({'de': "Reagieren wenn ein Schützfehler erkannt wurde", 'en': "React when a contactor error was detected"})),
                                Const(False, T({'de': "Reagieren wenn kein Schützfehler erkannt wurde", 'en': "React when no contactor error was detected"})),
                            ])
                        }),
                        16: Elem.OBJECT(T({'de': "Strom verfügbar TODO", 'en': "Power available TODO"}), members={
                            "power_available": Elem.BOOL(T({'de': "Gibt an, ob reagiert werden soll, wenn Strom verfügbar, oder nicht verfügbar ist.", 'en': "Indicates whether to react when power is available or not available."}), constants=[
                                Const(True, T({'de': "Reagieren wenn Strom verfügbar ist", 'en': "React when power is available"})),
                                Const(False, T({'de': "Reagieren wenn kein Strom verfügbar ist", 'en': "React when no power is available"})),
                            ])
                        }),
                        17: Elem.OBJECT(T({'de': "Messen von Netzbezug- oder Einspeisung", 'en': "Measurement of grid consumption or feed-in"}), members={
                            "drawing_power": Elem.BOOL(T({'de': "Gibt an, ob reagiert werden soll, wenn Strom ins Netz eingespeist, oder aus dem Netz bezogen wird.", 'en': "Indicates whether to react when power is fed into the grid or drawn from the grid."}), constants=[
                                Const(True, T({'de': "Reagieren wenn Strom bezogen wird", 'en': "React when power is drawn"})),
                                Const(False, T({'de': "Reagieren wenn Strom eingespeist wird", 'en': "React when power is fed in"})),
                            ])
                        }),
                        18: Elem.OBJECT(T({'de': "Empfang eines HTTP-Requests", 'en': "Receipt of an HTTP request"}), members={
                            "method": Elem.INT(T({'de': "Gibt an, bei welchen HTTP-Methoden reagiert werden soll", 'en': "Indicates which HTTP methods to react to"}), constants=[
                                Const(0, T({'de': "Reagiere auf GET", 'en': "React to GET"})),
                                Const(1, T({'de': "Reagiere auf POST", 'en': "React to POST"})),
                                Const(2, T({'de': "Reagiere auf PUT", 'en': "React to PUT"})),
                                Const(3, T({'de': "Reagiere auf POST und PUT", 'en': "React to POST and PUT"})),
                                Const(4, T({'de': "Reagiere auf GET, POST und PUT", 'en': "React to GET, POST and PUT"})),
                            ]),
                            "url_suffix": Elem.STRING(T({'de': "URL-Suffix auf dem auf HTTP-Requests gewartet wird. Wird an http://[hostname]/automation_trigger/ angehangen.", 'en': "URL suffix on which HTTP requests are waited for. Is appended to http://[hostname]/automation_trigger/."})),
                            "payload": Elem.STRING(T({'de': "Payload, der im HTTP-Request enthalten sein muss, damit die Regel auslöst. Darf (insbesondere bei HTTP GET) leer sein.", 'en': "Payload that must be contained in the HTTP request for the rule to trigger. May be empty (especially for HTTP GET)."}))
                        }),
                    }),
                    "action": Elem.UNION(T({'de': "Aktion, die ausgeführt werden soll", 'en': "Action to be executed"}), members={
                        0: Elem.NULL(T({'de': "Keine Aktion konfiguriert.", 'en': "No action configured."})),
                        1: Elem.OBJECT(T({'de': "Schreibe ins Ereignislog", 'en': "Write to event log"}), members={
                            "message": Elem.STRING(T({'de': "Nachricht, die ins Ereignislog geschrieben werden soll", 'en': "Message to be written to the event log"}))
                        }),
                        2: Elem.OBJECT(T({'de': "Sende eine MQTT-Nachricht", 'en': "Send an MQTT message"}), members={
                            "topic": Elem.STRING(T({'de': "MQTT-Topic, an das die Nachricht gesendet werden soll.", 'en': "MQTT topic to which the message should be sent."})),
                            "payload": Elem.STRING(T({'de': "Payload, der in der Nachricht enthalten sein soll", 'en': "Payload that should be contained in the message"})),
                            "retain": Elem.BOOL(T({'de': "Gibt an, ob die Nachricht retained werden soll", 'en': "Indicates whether the message should be retained"})),
                            "use_prefix": Elem.BOOL(T({'de': "Gibt an, ob der konfigurierte Global-Topic-Prefix (siehe {{{ref:mqtt/config}}}) vor dem konfigurierten Topic vorangestellt werden soll.", 'en': "Indicates whether the configured global topic prefix (see {{{ref:mqtt/config}}}) should be prepended to the configured topic."}))
                        }),
                        3: Elem.OBJECT(T({'de': "Limitiere den Ladestrom", 'en': "Limit the charging current"}), version=Version.WARPX, members={
                            "current": Elem.INT(T({'de': "Ladestromlimit, dass gesetzt werden soll", 'en': "Charging current limit to be set"}))
                        }),
                        4: Elem.OBJECT(T({'de': "Zeige auf der Fronttaster-LED an", 'en': "Display on the front button LED"}), version=Version.WARPX, members={
                            "indication": Elem.INT(T({'de': "Blinkmuster, dass angezeigt werden soll.", 'en': "Blink pattern to be displayed."}), constants=[
                                Const(-1, T({'de': "EVSE kontrolliert LED", 'en': "EVSE controls LED"})),
                                Const(0, T({'de': "Aus", 'en': "Off"})),
                                Const("1..254", T({'de': "Per PWM gedimmtes leuchten", 'en': "PWM dimmed lighting"})),
                                Const(255, T({'de': "An", 'en': "On"})),
                                Const(1001, T({'de': "Bestätigendes Blinken (z.B: NFC-Tag wurde erkannt)", 'en': "Confirming blink (e.g.: NFC tag was detected)"})),
                                Const(1002, T({'de': "Ablehnendes Blinken (z.B: NFC-Tag ist unbekannt)", 'en': "Rejecting blink (e.g.: NFC tag is unknown)"})),
                                Const(1003, T({'de': "Aufforderndes Blinken (z.B: NFC-Tag wird zum Laden benötigt)", 'en': "Prompting blink (e.g.: NFC tag is required for charging)"})),
                                Const("2001..2010", T({'de': "Fehler-Blinken 1 bis 10.", 'en': "Error blink 1 to 10."})),
                            ]),
                            "duration": Elem.INT(T({'de': "Dauer für die der gesetzte Zustand erhalten bleibt.", 'en': "Duration for which the set state is maintained."}), unit=Units.ms),
                            "color_h": Elem.INT(T({'de': 'Farbwert der LED im [HSV-Farbraum](https://de.wikipedia.org/wiki/HSV-Farbraum). Erlaubt sind Werte von 0 bis 359', 'en': 'Hue value of the LED in [HSV color space](https://en.wikipedia.org/wiki/HSL_and_HSV). Allowed values are 0 to 359'}), unit=Units.degree),
                            "color_s": Elem.INT(T({'de': 'Farbsättigung der LED im [HSV-Farbraum](https://de.wikipedia.org/wiki/HSV-Farbraum). Erlaubt sind Werte von 0 bis 255', 'en': 'Saturation of the LED in [HSV color space](https://en.wikipedia.org/wiki/HSL_and_HSV). Allowed values are 0 to 255'})),
                            "color_v": Elem.INT(T({'de': 'Helligkeit der LED im [HSV-Farbraum](https://de.wikipedia.org/wiki/HSV-Farbraum). Eine Helligkeit von 0 verwendet die Standardfarbe der `indication` bzw. Blau bei WARP1 oder WARP2. Erlaubt sind Werte von 0 bis 255', 'en': 'Value (brightness) of the LED in [HSV color space](https://en.wikipedia.org/wiki/HSL_and_HSV). A brightness of 0 uses the default color of the `indication` or blue for WARP1 or WARP2. Allowed values are 0 to 255'})),
                        }),
                        5: Elem.OBJECT(T({'de': "Setze einen Stromzähler zurück", 'en': "Reset an electricity meter"}), members={
                            "meter_slot": Elem.INT(T({'de': "Meter-Slot-ID des Zählers, der zurückgesetzt werden soll", 'en': "Meter slot ID of the meter to be reset"}))
                        }),
                        6: Elem.OBJECT(T({'de': "Setze den für den Lastmanager verfügbaren Strom.", 'en': "Set the current available for the load manager."}), members={
                            "current": Elem.INT(T({'de': "Verfügbarer Strom, der gesetzt werden soll", 'en': "Available current to be set"}))
                        }),
                        7: Elem.OBJECT(T({'de': "Simuliere ein NFC-Tags", 'en': "Simulate an NFC tag"}), version=Version.WARPX, members={
                            "tag_type": Elem.INT(T({'de': "Typ des Tags.", 'en': "Type of tag."}), constants=[
                                Const(0, U("Mifare Classic")),
                                Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
                                Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
                                Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
                                Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
                            ]),
                            "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. 01:23:AB:3D", 'en': "ID of the tag. Up to 10 hex bytes depending on tag type, separated by ':'. e.g. 01:23:AB:3D"})),
                            "action": Elem.INT(T({'de': "Gibt an ob das Tag nur zum Starten oder Stoppen eines Ladevorgangs, oder für beides genutzt werden soll", 'en': "Indicates whether the tag should only be used for starting or stopping a charging session, or for both"}), constants=[
                                Const(0, T({'de': "Tag kann Ladevorgänge starten und stoppen", 'en': "Tag can start and stop charging sessions"})),
                                Const(0, T({'de': "Tag kann Ladevorgänge starten", 'en': "Tag can start charging sessions"})),
                                Const(0, T({'de': "Tag kann Ladevorgänge stoppen", 'en': "Tag can stop charging sessions"})),
                            ])
                        }),
                        8: Elem.OBJECT(T({'de': "Setze das Ladezeit- oder Energielimit", 'en': "Set the charging time or energy limit"}), version=Version.WARPX, members={
                            "restart": Elem.BOOL(T({'de': "Gibt an, ob die neuen Limits relativ zum bestehenden Ladevorgang, oder absolut gelten sollen. Wenn beispielsweise ein Ladevorgang seit 17 Minuten läuft und diese Aktion mit duration = 2 (30 Minuten) ausgelöst wird, dann darf, wenn restart false ist, der Ladevorgang noch weitere 13 Minuten laufen, sodass insgesamt 30 Minuten geladen wurde. Wenn restart true ist, darf weitere 30 Minuten, insgesamt also 47 Minuten geladen werden.", 'en': "Indicates whether the new limits should apply relative to the existing charging session, or absolutely. For example, if a charging session has been running for 17 minutes and this action is triggered with duration = 2 (30 minutes), then if restart is false, the charging session may continue for another 13 minutes, so that a total of 30 minutes has been charged. If restart is true, it may charge for another 30 minutes, i.e. a total of 47 minutes."}), constants=[
                                Const(False, T({'de': "Neues Ladelimit gilt relativ zum laufenden Ladevorgang. Z.B. Verlängerung <strong>auf</strong> 30 Minuten.", 'en': "New charging limit applies relative to the running charging session. E.g. extension <strong>to</strong> 30 minutes."})),
                                Const(True, T({'de': "Neues Ladelimit gilt absolut. Z.B. Verlängerung <strong>um</strong> 30 Minuten.", 'en': "New charging limit applies absolutely. E.g. extension <strong>by</strong> 30 minutes."}))
                            ]),
                            "duration": Elem.INT(T({'de': "Zeitlimit eines Ladevorgangs. Nach Ablaufen des Zeitlimits wird der Ladevorgang gestoppt.", 'en': "Time limit of a charging session. After the time limit expires, the charging session is stopped."}), constants=[
                                Const(-1, T({'de': "Zeitlimit nicht verändern", 'en': "Do not change time limit"})),
                                Const(0, T({'de': "Unbegrenzt", 'en': "Unlimited"})),
                                Const(1, T({'de': "15 Minuten", 'en': "15 minutes"})),
                                Const(2, T({'de': "30 Minuten", 'en': "30 minutes"})),
                                Const(3, T({'de': "45 Minuten", 'en': "45 minutes"})),
                                Const(4, T({'de': "1 Stunde", 'en': "1 hour"})),
                                Const(5, T({'de': "2 Stunden", 'en': "2 hours"})),
                                Const(6, T({'de': "3 Stunden", 'en': "3 hours"})),
                                Const(7, T({'de': "4 Stunden", 'en': "4 hours"})),
                                Const(8, T({'de': "6 Stunden", 'en': "6 hours"})),
                                Const(9, T({'de': "8 Stunden", 'en': "8 hours"})),
                                Const(10, T({'de': "12 Stunden", 'en': "12 hours"})),
                            ]),
                            "energy_wh": Elem.INT(T({'de': "Energielimit eines Ladevorgangs. Nach Ablaufen des Energielimits wird der Ladevorgang gestoppt.", 'en': "Energy limit of a charging session. After the energy limit is reached, the charging session is stopped."}), unit=Units.Wh, constants=[
                                Const(-1, T({'de': "Energielimit nicht verändern", 'en': "Do not change energy limit"}))
                            ]),
                        }),
                        9: Elem.OBJECT(T({'de': "Schalte den konfigurierbaren Ausgang", 'en': "Switch the configurable output"}), version=Version.WARP2, members={
                            "state": Elem.INT(T({'de': "Gibt an, ob der konfigurierte Ausgang geschlossen oder geöffnet werden soll.", 'en': "Indicates whether the configured output should be closed or opened."}), constants=[
                                Const(0, T({'de': "Geschlossen (verbunden mit Masse)", 'en': "Closed (connected to ground)"})),
                                Const(1, T({'de': "Geöffnet (hochohmig)", 'en': "Open (high impedance)"})),
                            ])
                        }),
                        #10: Elem.OBJECT("Lösche die aufgezeichneten Ladevorgänge", version=Version.WARPX, members={}),
                        11: Elem.OBJECT(T({'de': "Starte eine Phasenumschaltung", 'en': "Start a phase switching"}), version=Version.WARP3 | Version.WEM, members={
                            "phases_wanted": Elem.INT(T({'de': "Gibt an, auf ein- oder dreiphasig umgeschalted werden soll", 'en': "Indicates whether to switch to single-phase or three-phase"}), constants=[
                                Const(1, T({'de': "Wechsele auf einphasig", 'en': "Switch to single-phase"})),
                                Const(3, T({'de': "Wechsele auf dreiphasig", 'en': "Switch to three-phase"})),
                            ])
                        }),
                        12: Elem.OBJECT(T({'de': "Wechsle den Lademodus", 'en': "Change the charging mode"}), version=Version.WARP3 | Version.WEM, members={
                            "mode": Elem.INT(T({'de': "Gewünschter Lademodus. Siehe {{{ref:power_manager/charge_mode}}}", 'en': "Desired charging mode. See {{{ref:power_manager/charge_mode}}}"}), constants=[
                                Const(0, T({'de': "Schnell", 'en': "Fast"})),
                                Const(1, T({'de': "Aus", 'en': "Off"})),
                                Const(2, U("PV")),
                                Const(3, U("Min + PV")),
                            ])
                        }),
                        13: Elem.OBJECT(T({'de': "Schalte den Relais-Ausgang", 'en': "Switch the relay output"}), version=Version.WEM, members={
                            "state": Elem.BOOL(T({'de': "Gibt an, ob der Relais-Ausgang geschlossen oder geöffnet werden soll.", 'en': "Indicates whether the relay output should be closed or opened."}), constants=[
                                Const(True, T({'de': "Geschlossen", 'en': "Closed"})),
                                Const(False, T({'de': "Geöffnet", 'en': "Open"})),
                            ])
                        }),
                        14: Elem.OBJECT(T({'de': "Limitiere den ???TODO???-Strom", 'en': "Limit the ???TODO??? current"}), version=Version.WARP3 | Version.WEM, members={
                            "current": Elem.INT(T({'de': "Stromlimit, dass gesetzt werden soll", 'en': "Current limit to be set"}), constants=[
                                Const(-1, T({'de': "Stromlimit aufheben", 'en': "Remove current limit"}))
                            ])
                        }),
                        15: Elem.OBJECT(T({'de': "Blockiere oder gebe Ladevorgänge frei", 'en': "Block or release charging sessions"}), version=Version.WEM, members={
                            "slot": Elem.INT(T({'de': "Blockierslot, der verwendet werden soll. Ladevorgänge werden nur dann erlaubt, wenn alle 4 Blockierslots nicht blockieren.", 'en': "Blocking slot to be used. Charging sessions are only allowed if all 4 blocking slots are not blocking."})),
                            "block": Elem.BOOL(T({'de': "Gibt an, ob der gewählte Blockierslot blockiert, oder freigegeben werden soll", 'en': "Indicates whether the selected blocking slot should be blocked or released"}), constants=[
                                Const(False, T({'de': "Gib gewählten Blockierslot frei", 'en': "Release selected blocking slot"})),
                                Const(True, T({'de': "Blockiere gewählten Blockierslot", 'en': "Block selected blocking slot"}))
                            ])
                        }),
                    }),
                })]
            ])
        })
    ),
])
