from api_doc_common import *

meter = Module("meter", T({'de': "Veraltete Stromzähler-API", 'en': "Legacy Electricity Meter API"}), T({'de': "Bei Neuentwicklungen stattdessen {{{mod_ref:meters}}} verwenden!", 'en': "Use {{{mod_ref:meters}}} for new developments instead!"}),
    T({'de': "Die veraltete Stromzähler-API unterstützt nur einen Stromzähler (den, der als `linked_meter_slot` in {{{ref:meters_legacy_api/config}}} konfiguriert ist) und kann nur eine Teilmenge der unterstützten Stromzählerwerte melden und verarbeiten. Die veraltete API wird vom {{{mod_ref:meters_legacy_api}}}-Modul emuliert.", 'en': "The legacy electricity meter API only supports one electricity meter (the one configured as `linked_meter_slot` in {{{ref:meters_legacy_api/config}}}) and can only report and process a subset of the supported electricity meter values. The legacy API is emulated by the {{{mod_ref:meters_legacy_api}}} module."}),
    Version.ANY, [
    Func("state", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Der Zustand des Stromzählers.", 'en': "The state of the electricity meter."}), members={
            "state": Elem.INT(T({'de': "Zustand des Stromzählers", 'en': "State of the electricity meter"}), constants=[
                Const(0, T({'de': "Kein Stromzähler verbunden", 'en': "No electricity meter connected"})),
                Const(1, T({'de': "Stromzähler unzuverlässig, eventuell nur einphasig verbunden.", 'en': "Electricity meter unreliable, possibly only single-phase connected."})),
                Const(2, T({'de': "Stromzähler verbunden", 'en': "Electricity meter connected"})),
            ]),
            "type": Elem.INT(T({'de': "Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jedem Gerät unterstützt!", 'en': "Type of the installed electricity meter. Not every meter is supported by every device!"}), constants=[
                Const(0, T({'de': "Kein Stromzähler verfügbar", 'en': "No electricity meter available"})),
                Const(1, "Eastron SDM72", Version.WARP1),
                Const(2, "Eastron SDM630", Version.ANY),
                Const(3, "Eastron SDM72V2", Version.ANY),
                Const(4, "Eastron SDM72CTM", Version.WARP2 | Version.WARP3 | Version.WEMX),
                Const(5, "Eastron SDM630MCT", Version.WARP2 | Version.WARP3 | Version.WEMX),
                Const(6, "Eltako DSZ15DZMOD", Version.WARP2 | Version.WARP3 | Version.WEMX),
                Const(7, "YTL DEM4A", Version.WARP2 | Version.WARP3 | Version.WEMX),
            ])
        })
    ),

    Func("values", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Messwerte des Stromzählers. Benötigt das Feature <a href=\"#features_meter\"><code>\"meter\"</code></a>", 'en': "The measurement values of the electricity meter. Requires the feature <a href=\"#features_meter\"><code>\"meter\"</code></a>"}), members={
            "power": Elem.FLOAT(T({'de': "Die aktuelle Ladeleistung.", 'en': "The current charging power."}), unit=Units.W),
            "energy_rel": Elem.FLOAT(T({'de': "Die geladene Energie seit dem letzten Reset.", 'en': "The charged energy since the last reset."}), unit=Units.kWh),
            "energy_abs": Elem.FLOAT(T({'de': "Die geladene Energie seit der Herstellung des Stromzählers.", 'en': "The charged energy since the manufacture of the electricity meter."}), unit=Units.kWh),
        })
    ),

    Func("phases", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Angeschlossene und aktive Phasen. Benötigt das Feature <a href=\"#features_meter_phases\"><code>\"meter_phases\"</code></a>.", 'en': "Connected and active phases. Requires the feature <a href=\"#features_meter_phases\"><code>\"meter_phases\"</code></a>."}), members={
            "phases_active": Elem.ARRAY(T({'de': "Die derzeit aktiven Phasen", 'en': "The currently active phases"}), members=[
                Elem.BOOL(T({'de': "Phase L1 aktiv", 'en': "Phase L1 active"})),
                Elem.BOOL(T({'de': "Phase L2 aktiv", 'en': "Phase L2 active"})),
                Elem.BOOL(T({'de': "Phase L3 aktiv", 'en': "Phase L3 active"})),
            ]),
            "phases_connected": Elem.ARRAY(T({'de': "Die angeschlossenen Phasen", 'en': "The connected phases"}), members=[
                Elem.BOOL(T({'de': "Phase L1 angeschlossen", 'en': "Phase L1 connected"})),
                Elem.BOOL(T({'de': "Phase L2 angeschlossen", 'en': "Phase L2 connected"})),
                Elem.BOOL(T({'de': "Phase L3 angeschlossen", 'en': "Phase L3 connected"})),
            ])
        })
    ),

    Func("error_counters", FuncType.STATE, Elem.OBJECT(T({'de': "Fehlerzähler der Kommunikation mit dem Stromzähler.", 'en': "Error counters for communication with the electricity meter."}), members={
            "meter": Elem.INT(T({'de': "Kommunikationsfehler zwischen RS485 Bricklet und Stromzähler.", 'en': "Communication errors between RS485 Bricklet and electricity meter."}), version=Version.WARP1),
            "bricklet": Elem.INT(T({'de': "Kommunikationsfehler zwischen ESP Brick und RS485 Bricklet.", 'en': "Communication errors between ESP Brick and RS485 Bricklet."}), version=Version.WARP1),
            "bricklet_reset": Elem.INT(T({'de': "Unerwartete Resets des RS485 Bricklets.", 'en': "Unexpected resets of the RS485 Bricklet."}), version=Version.WARP1),

            "local_timeout": Elem.INT("Local Timeout", version=Version.WARP2 | Version.WARP3 | Version.WEMX),
            "global_timeout": Elem.INT("Global Timeout", version=Version.WARP2 | Version.WARP3 | Version.WEMX),
            "illegal_function": Elem.INT("Illegal Function", version=Version.WARP2 | Version.WARP3 | Version.WEMX),
            "illegal_data_access": Elem.INT("Illegal Data Access", version=Version.WARP2 | Version.WARP3 | Version.WEMX),
            "illegal_data_value": Elem.INT("Illegal Data Value", version=Version.WARP2 | Version.WARP3 | Version.WEMX),
            "slave_device_failure": Elem.INT("Slave Device Failure", version=Version.WARP2 | Version.WARP3 | Version.WEMX),
        })
    ),

    Func("all_values", FuncType.CONFIGURATION, Elem.ARRAY(T({'de': "Alle Messwerte, die vom eingebauten Stromzähler gemessen werden. Benötigt das Feature <a href=\"#features_meter_all_values\"><code>\"meter_all_values\"</code></a>. Hintereinanderliegende Werte die mit .. gekennzeichnet sind, beziehen sich auf die drei Phasen L1, L2 und L3.", 'en': "All measurement values measured by the built-in electricity meter. Requires the feature <a href=\"#features_meter_all_values\"><code>\"meter_all_values\"</code></a>. Consecutive values marked with .. refer to the three phases L1, L2 and L3."}), members=[
            * 3 * [Elem.FLOAT(T({'de': "Spannung gegen Neutral", 'en': "Voltage to neutral"}), unit=Units.V)],
            * 3 * [Elem.FLOAT(T({'de': "Strom", 'en': "Current"}), unit=Units.A)],
            * 3 * [Elem.FLOAT(T({'de': "Wirkleistung", 'en': "Active power"}), unit=Units.W)],
            * 3 * [Elem.FLOAT(T({'de': "Scheinleistung", 'en': "Apparent power"}), unit=Units.VA)],
            * 3 * [Elem.FLOAT(T({'de': "Blindleistung", 'en': "Reactive power"}), unit=Units.var)],
            * 3 * [Elem.FLOAT(T({'de': "Leistungsfaktor; Das Vorzeichen des Leistungsfaktors gibt die Richtung des Stromflusses an.", 'en': "Power factor; The sign of the power factor indicates the direction of current flow."}))],
            * 3 * [Elem.FLOAT(T({'de': "relative Phasenverschiebung", 'en': "Relative phase shift"}), unit=Units.degree)],

            Elem.FLOAT(T({'de': "Durchschnittliche Spannung gegen Neutral", 'en': "Average voltage to neutral"}), unit=Units.V),
            Elem.FLOAT(T({'de': "Durchschnittlicher Strom", 'en': "Average current"}), unit=Units.A),
            Elem.FLOAT(T({'de': "Summe der Phasenströme", 'en': "Sum of phase currents"}), unit=Units.A),
            Elem.FLOAT(T({'de': "Gesamtwirkleistung", 'en': "Total active power"}), unit=Units.W),
            Elem.FLOAT(T({'de': "Gesamtscheinleistung", 'en': "Total apparent power"}), unit=Units.VA),
            Elem.FLOAT(T({'de': "Gesamtblindleistung", 'en': "Total reactive power"}), unit=Units.var),
            Elem.FLOAT(T({'de': "Gesamtleistungsfaktor", 'en': "Total power factor"})),
            Elem.FLOAT(T({'de': "Gesamtphasenverschiebung", 'en': "Total phase shift"}), unit=Units.degree),
            Elem.FLOAT(T({'de': "Frequenz der Versorgungsspannung", 'en': "Supply voltage frequency"}), unit=Units.Hz),
            Elem.FLOAT(T({'de': "Wirkenergie (Import; vom Fahrzeug aufgenommen)", 'en': "Active energy (import; consumed by vehicle)"}), unit=Units.kWh),
            Elem.FLOAT(T({'de': "Wirkenergie (Export; vom Fahrzeug abgegeben)", 'en': "Active energy (export; supplied by vehicle)"}), unit=Units.kWh),
            Elem.FLOAT(T({'de': "Blindenergie (Import; vom Fahrzeug aufgenommen)", 'en': "Reactive energy (import; consumed by vehicle)"}), unit=Units.kvarh),
            Elem.FLOAT(T({'de': "Blindenergie (Export; vom Fahrzeug abgegeben)", 'en': "Reactive energy (export; supplied by vehicle)"}), unit=Units.kvarh),
            Elem.FLOAT(T({'de': "Gesamtscheinenergie", 'en': "Total apparent energy"}), unit=Units.kVAh),
            Elem.FLOAT(T({'de': "Transportierte elektrische Ladung", 'en': "Transported electric charge"}), unit=Units.Ah),
            Elem.FLOAT(T({'de': "Bezogene Wirkleistung; Entspricht Import-Export-Differenz", 'en': "Consumed active power; Equals import-export difference"}), unit=Units.W),
            Elem.FLOAT(T({'de': "Max. bezogene Wirkleistung; Höchster gemessener Wert", 'en': "Max. consumed active power; Highest measured value"}), unit=Units.W),
            Elem.FLOAT(T({'de': "Bezogene Scheinleistung; Entspricht Import-Export-Differenz", 'en': "Consumed apparent power; Equals import-export difference"}), unit=Units.VA),
            Elem.FLOAT(T({'de': "Max. bezogene Scheinleistung; Höchster gemessener Wert", 'en': "Max. consumed apparent power; Highest measured value"}), unit=Units.VA),
            Elem.FLOAT(T({'de': "Bezogener Neutralleiterstrom", 'en': "Consumed neutral current"}), unit=Units.A),
            Elem.FLOAT(T({'de': "Max. bezogener Neutralleiterstrom; Höchster gemessener Wert", 'en': "Max. consumed neutral current; Highest measured value"}), unit=Units.A),
            Elem.FLOAT(T({'de': "Spannung L1 zu L2", 'en': "Voltage L1 to L2"}), unit=Units.V),
            Elem.FLOAT(T({'de': "Spannung L2 zu L3", 'en': "Voltage L2 to L3"}), unit=Units.V),
            Elem.FLOAT(T({'de': "Spannung L3 zu L1", 'en': "Voltage L3 to L1"}), unit=Units.V),
            Elem.FLOAT(T({'de': "Durchschnittliche Spannung zwischen Phasen", 'en': "Average voltage between phases"}), unit=Units.V),
            Elem.FLOAT(T({'de': "Neutralleiterstrom", 'en': "Neutral current"}), unit=Units.A),


            * 3 * [Elem.FLOAT(T({'de': "Total Harmonic Distortion (THD) der Spannung", 'en': "Total Harmonic Distortion (THD) of voltage"}), unit=Units.percent)],
            * 3 * [Elem.FLOAT(T({'de': "Total Harmonic Distortion (THD) des Stroms", 'en': "Total Harmonic Distortion (THD) of current"}), unit=Units.percent)],
            Elem.FLOAT(T({'de': "Durchschnittliche Spannungs-THD", 'en': "Average voltage THD"}), unit=Units.percent),
            Elem.FLOAT(T({'de': "Durchschnittliche Strom-THD", 'en': "Average current THD"}), unit=Units.percent),

            * 3 * [Elem.FLOAT(T({'de': "Bezogener Strom", 'en': "Consumed current"}), unit=Units.A)],
            * 3 * [Elem.FLOAT(T({'de': "Max. bezogener Strom; Höchster gemessener Wert", 'en': "Max. consumed current; Highest measured value"}), unit=Units.A)],

            Elem.FLOAT(T({'de': "Spannungs-THD L1 zu L2", 'en': "Voltage THD L1 to L2"}), unit=Units.percent),
            Elem.FLOAT(T({'de': "Spannungs-THD L2 zu L3", 'en': "Voltage THD L2 to L3"}), unit=Units.percent),
            Elem.FLOAT(T({'de': "Spannungs-THD L3 zu L1", 'en': "Voltage THD L3 to L1"}), unit=Units.percent),
            Elem.FLOAT(T({'de': "Durchschnittliche Spannungs-THD zwischen Phasen", 'en': "Average voltage THD between phases"}), unit=Units.percent),
            Elem.FLOAT(T({'de': "Summe der Gesamtwirkenergien; Import-Export-Summe aller Phasen", 'en': "Sum of total active energies; Import-export sum of all phases"}), unit=Units.kWh),
            Elem.FLOAT(T({'de': "Summe der Gesamtblindenergien; Import-Export-Summe aller Phasen", 'en': "Sum of total reactive energies; Import-export sum of all phases"}), unit=Units.kvarh),

            * 3 * [Elem.FLOAT(T({'de': "Wirkenergie (Import; vom Fahrzeug aufgenommen)", 'en': "Active energy (import; consumed by vehicle)"}), unit=Units.kWh)],
            * 3 * [Elem.FLOAT(T({'de': "Wirkenergie (Export; vom Fahrzeug abgegeben)", 'en': "Active energy (export; supplied by vehicle)"}), unit=Units.kWh)],
            * 3 * [Elem.FLOAT(T({'de': "Gesamtwirkenergie; Import-Export-Summe", 'en': "Total active energy; Import-export sum"}), unit=Units.kWh)],
            * 3 * [Elem.FLOAT(T({'de': "Blindenergie (Import; vom Fahrzeug aufgenommen)", 'en': "Reactive energy (import; consumed by vehicle)"}), unit=Units.kvarh)],
            * 3 * [Elem.FLOAT(T({'de': "Blindenergie (Export; vom Fahrzeug abgegeben)", 'en': "Reactive energy (export; supplied by vehicle)"}), unit=Units.kvarh)],
            * 3 * [Elem.FLOAT(T({'de': "Gesamtblindenergie; Import-Export-Summe", 'en': "Total reactive energy; Import-export sum"}), unit=Units.kvarh)],
        ])
    ),

    Func("reset", FuncType.COMMAND, Elem.NULL(T({'de': "Setzt den Energiezähler zurück.", 'en': "Resets the energy meter."})), command_is_action=True),
    Func("last_reset", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zeitpunkt des letzten Zähler-Resets (siehe {{{ref:meter/reset}}}) als Unix-Timestamp. 0 falls kein Reset durchgeführt wurde, oder zum Zeitpunkt des Resets keine Netzwerk-Zeitsynchronisierung vorlag.", 'en': "The time of the last meter reset (see {{{ref:meter/reset}}}) as Unix timestamp. 0 if no reset was performed, or if no network time synchronization was available at the time of the reset."}), members={
            "last_reset": Elem.INT(T({'de': "Unix-Timestamp des Zeitpunkts des letzten Zähler-Resets.", 'en': "Unix timestamp of the time of the last meter reset."}), unit=Units.s)
        })
    ),

    Func("type_override", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Erlaubt es den verbauten Zählertyp zu überschreiben, falls die Auto-Detektion nicht funktioniert.", 'en': "Allows overriding the installed meter type if auto-detection does not work."}), version=Version.WARP1, members={
            "type": Elem.INT(T({'de': "Stromzählertyp, der verwendet werden soll", 'en': "Electricity meter type to be used"}), constants=[
                Const(0, T({'de': "Kein Stromzähler verfügbar", 'en': "No electricity meter available"})),
                Const(1, "SDM72"),
                Const(2, "SDM630"),
                Const(3, "SDM72V2"),
                Const(255, T({'de': "Typ-Override nicht aktiv. Stromzählertyp wird automatisch detektiert.", 'en': "Type override not active. Electricity meter type is automatically detected."}))
            ])
        })
    ),

    Func("history", FuncType.HTTP_ONLY, Elem.OBJECT(T({'de': "Eine 48-Stunden-Historie der Ladeleistung in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", 'en': "A 48-hour history of charging power in watts. Missing values are indicated by null. The history is filled from back to front, so null values only occur consecutively at the beginning of the array if the ESP was restarted within the last 48 hours. Up to 720 values are output, which corresponds to one measurement value every 4 minutes. These measurement values are the respective average of these 4 minutes."}), members={
        "offset": Elem.INT(T({'de': "Das Alter des zuletzt gemessenen Wertes.", 'en': "The age of the last measured value."}), unit=Units.ms),
        "samples": Elem.ARRAY(T({'de': "Die gemessenen Werte.", 'en': "The measured values."}), unit=Units.W, member_type=EType.INT)
    })),

    Func("live", FuncType.HTTP_ONLY, Elem.OBJECT(T({'de': "Die letzten Ladeleistungs-Messwerte. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meter/history}}} generiert.", 'en': "The last charging power measurement values. Based on these values, the average values for {{{ref:meter/history}}} are generated."}), members={
        "offset": Elem.INT(T({'de': "Das Alter des zuletzt gemessenen Wertes.", 'en': "The age of the last measured value."}), unit=Units.ms),
        "samples_per_second": Elem.FLOAT(T({'de': "Die Anzahl der gemessenen Werte pro Sekunde.", 'en': "The number of measured values per second."}), unit=Units.Hz),
        "samples": Elem.ARRAY(T({'de': "Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", 'en': "The measured values. Depending on the length of the array and the samples_per_second value, it can be determined how far back in time the measurement values reach."}), unit=Units.W, member_type=EType.INT)
    }))
])
