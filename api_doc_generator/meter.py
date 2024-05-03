from api_doc_common import *

meter = Module("meter", "Veraltete Stromzähler-API", "Bei Neuentwicklungen stattdessen {{{mod_ref:meters}}} verwenden!",
    "Die veraltete Stromzähler-API unterstützt nur einen Stromzähler (den, der als `linked_meter_slot` in {{{ref:meters_legacy_api/config}}} konfiguriert ist) und kann nur eine Teilmenge der unterstützten Stromzählerwerte melden und verarbeiten. Die veraltete API wird vom {{{mod_ref:meters_legacy_api}}}-Modul emuliert.",
    Version.ANY, [
    Func("state", FuncType.CONFIGURATION, Elem.OBJECT("Der Zustand des Stromzählers.", members={
            "state": Elem.INT("Zustand des Stromzählers", constants=[
                Const(0, "Kein Stromzähler verbunden"),
                Const(1, "Stromzähler unzuverlässig, eventuell nur einphasig verbunden."),
                Const(2, "Stromzähler verbunden"),
            ]),
            "type": Elem.INT("Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jedem Gerät unterstützt!", constants=[
                Const(0, "Kein Stromzähler verfügbar"),
                Const(1, "Eastron SDM72", Version.WARP1),
                Const(2, "Eastron SDM630", Version.ANY),
                Const(3, "Eastron SDM72V2", Version.ANY),
                Const(4, "Eastron SDM72CTM", Version.WARP2 | Version.WARP3 | Version.WEM),
                Const(5, "Eastron SDM630MCT", Version.WARP2 | Version.WARP3 | Version.WEM),
                Const(6, "Eltako DSZ15DZMOD", Version.WARP2 | Version.WARP3 | Version.WEM),
                Const(7, "YTL DEM4A", Version.WARP2 | Version.WARP3 | Version.WEM),
            ])
        })
    ),

    Func("values", FuncType.CONFIGURATION, Elem.OBJECT("Die Messwerte des Stromzählers. Benötigt das Feature <a href=\"#features_meter\"><code>\"meter\"</code></a>", members={
            "power": Elem.FLOAT("Die aktuelle Ladeleistung.", unit=Units.W),
            "energy_rel": Elem.FLOAT("Die geladene Energie seit dem letzten Reset.", unit=Units.kWh),
            "energy_abs": Elem.FLOAT("Die geladene Energie seit der Herstellung des Stromzählers.", unit=Units.kWh),
        })
    ),

    Func("phases", FuncType.CONFIGURATION, Elem.OBJECT("Angeschlossene und aktive Phasen. Benötigt das Feature <a href=\"#features_meter_phases\"><code>\"meter_phases\"</code></a>.", members={
            "phases_active": Elem.ARRAY("Die derzeit aktiven Phasen", members=[
                Elem.BOOL("Phase L1 aktiv"),
                Elem.BOOL("Phase L2 aktiv"),
                Elem.BOOL("Phase L3 aktiv"),
            ]),
            "phases_connected": Elem.ARRAY("Die angeschlossenen Phasen", members=[
                Elem.BOOL("Phase L1 angeschlossen"),
                Elem.BOOL("Phase L2 angeschlossen"),
                Elem.BOOL("Phase L3 angeschlossen"),
            ])
        })
    ),

    Func("error_counters", FuncType.STATE, Elem.OBJECT("Fehlerzähler der Kommunikation mit dem Stromzähler.", members={
            "meter": Elem.INT("Kommunikationsfehler zwischen RS485 Bricklet und Stromzähler.", version=Version.WARP1),
            "bricklet": Elem.INT("Kommunikationsfehler zwischen ESP Brick und RS485 Bricklet.", version=Version.WARP1),
            "bricklet_reset": Elem.INT("Unerwartete Resets des RS485 Bricklets.", version=Version.WARP1),

            "local_timeout": Elem.INT("Local Timeout", version=Version.WARP2 | Version.WARP3 | Version.WEM),
            "global_timeout": Elem.INT("Global Timeout", version=Version.WARP2 | Version.WARP3 | Version.WEM),
            "illegal_function": Elem.INT("Illegal Function", version=Version.WARP2 | Version.WARP3 | Version.WEM),
            "illegal_data_access": Elem.INT("Illegal Data Access", version=Version.WARP2 | Version.WARP3 | Version.WEM),
            "illegal_data_value": Elem.INT("Illegal Data Value", version=Version.WARP2 | Version.WARP3 | Version.WEM),
            "slave_device_failure": Elem.INT("Slave Device Failure", version=Version.WARP2 | Version.WARP3 | Version.WEM),
        })
    ),

    Func("all_values", FuncType.CONFIGURATION, Elem.ARRAY("Alle Messwerte, die vom eingebauten Stromzähler gemessen werden. Benötigt das Feature <a href=\"#features_meter_all_values\"><code>\"meter_all_values\"</code></a>. Hintereinanderliegende Werte die mit .. gekennzeichnet sind, beziehen sich auf die drei Phasen L1, L2 und L3.", members=[
            * 3 * [Elem.FLOAT("Spannung gegen Neutral", unit=Units.V)],
            * 3 * [Elem.FLOAT("Strom", unit=Units.A)],
            * 3 * [Elem.FLOAT("Wirkleistung", unit=Units.W)],
            * 3 * [Elem.FLOAT("Scheinleistung", unit=Units.VA)],
            * 3 * [Elem.FLOAT("Blindleistung", unit=Units.var)],
            * 3 * [Elem.FLOAT("Leistungsfaktor; Das Vorzeichen des Leistungsfaktors gibt die Richtung des Stromflusses an.")],
            * 3 * [Elem.FLOAT("relative Phasenverschiebung", unit=Units.degree)],

            Elem.FLOAT("Durchschnittliche Spannung gegen Neutral", unit=Units.V),
            Elem.FLOAT("Durchschnittlicher Strom", unit=Units.A),
            Elem.FLOAT("Summe der Phasenströme", unit=Units.A),
            Elem.FLOAT("Gesamtwirkleistung", unit=Units.W),
            Elem.FLOAT("Gesamtscheinleistung", unit=Units.VA),
            Elem.FLOAT("Gesamtblindleistung", unit=Units.var),
            Elem.FLOAT("Gesamtleistungsfaktor"),
            Elem.FLOAT("Gesamtphasenverschiebung", unit=Units.degree),
            Elem.FLOAT("Frequenz der Versorgungsspannung", unit=Units.Hz),
            Elem.FLOAT("Wirkenergie (Import; vom Fahrzeug aufgenommen)", unit=Units.kWh),
            Elem.FLOAT("Wirkenergie (Export; vom Fahrzeug abgegeben)", unit=Units.kWh),
            Elem.FLOAT("Blindenergie (Import; vom Fahrzeug aufgenommen)", unit=Units.kvarh),
            Elem.FLOAT("Blindenergie (Export; vom Fahrzeug abgegeben)", unit=Units.kvarh),
            Elem.FLOAT("Gesamtscheinenergie", unit=Units.kVAh),
            Elem.FLOAT("Transportierte elektrische Ladung", unit=Units.Ah),
            Elem.FLOAT("Bezogene Wirkleistung; Entspricht Import-Export-Differenz", unit=Units.W),
            Elem.FLOAT("Max. bezogene Wirkleistung; Höchster gemessener Wert", unit=Units.W),
            Elem.FLOAT("Bezogene Scheinleistung; Entspricht Import-Export-Differenz", unit=Units.VA),
            Elem.FLOAT("Max. bezogene Scheinleistung; Höchster gemessener Wert", unit=Units.VA),
            Elem.FLOAT("Bezogener Neutralleiterstrom", unit=Units.A),
            Elem.FLOAT("Max. bezogener Neutralleiterstrom; Höchster gemessener Wert", unit=Units.A),
            Elem.FLOAT("Spannung L1 zu L2", unit=Units.V),
            Elem.FLOAT("Spannung L2 zu L3", unit=Units.V),
            Elem.FLOAT("Spannung L3 zu L1", unit=Units.V),
            Elem.FLOAT("Durchschnittliche Spannung zwischen Phasen", unit=Units.V),
            Elem.FLOAT("Neutralleiterstrom", unit=Units.A),


            * 3 * [Elem.FLOAT("Total Harmonic Distortion (THD) der Spannung", unit=Units.percent)],
            * 3 * [Elem.FLOAT("Total Harmonic Distortion (THD) des Stroms", unit=Units.percent)],
            Elem.FLOAT("Durchschnittliche Spannungs-THD", unit=Units.percent),
            Elem.FLOAT("Durchschnittliche Strom-THD", unit=Units.percent),

            * 3 * [Elem.FLOAT("Bezogener Strom", unit=Units.A)],
            * 3 * [Elem.FLOAT("Max. bezogener Strom; Höchster gemessener Wert", unit=Units.A)],

            Elem.FLOAT("Spannungs-THD L1 zu L2", unit=Units.percent),
            Elem.FLOAT("Spannungs-THD L2 zu L3", unit=Units.percent),
            Elem.FLOAT("Spannungs-THD L3 zu L1", unit=Units.percent),
            Elem.FLOAT("Durchschnittliche Spannungs-THD zwischen Phasen", unit=Units.percent),
            Elem.FLOAT("Summe der Gesamtwirkenergien; Import-Export-Summe aller Phasen", unit=Units.kWh),
            Elem.FLOAT("Summe der Gesamtblindenergien; Import-Export-Summe aller Phasen", unit=Units.kvarh),

            * 3 * [Elem.FLOAT("Wirkenergie (Import; vom Fahrzeug aufgenommen)", unit=Units.kWh)],
            * 3 * [Elem.FLOAT("Wirkenergie (Export; vom Fahrzeug abgegeben)", unit=Units.kWh)],
            * 3 * [Elem.FLOAT("Gesamtwirkenergie; Import-Export-Summe", unit=Units.kWh)],
            * 3 * [Elem.FLOAT("Blindenergie (Import; vom Fahrzeug aufgenommen)", unit=Units.kvarh)],
            * 3 * [Elem.FLOAT("Blindenergie (Export; vom Fahrzeug abgegeben)", unit=Units.kvarh)],
            * 3 * [Elem.FLOAT("Gesamtblindenergie; Import-Export-Summe", unit=Units.kvarh)],
        ])
    ),

    Func("reset", FuncType.COMMAND, Elem.NULL("Setzt den Energiezähler zurück."), command_is_action=True),
    Func("last_reset", FuncType.STATE, Elem.OBJECT("Der Zeitpunkt des letzten Zähler-Resets (siehe {{{ref:meter/reset}}}) als Unix-Timestamp. 0 falls kein Reset durchgeführt wurde, oder zum Zeitpunkt des Resets keine Netzwerk-Zeitsynchronisierung vorlag.", members={
            "last_reset": Elem.INT("Unix-Timestamp des Zeitpunkts des letzten Zähler-Resets.", unit=Units.s)
        })
    ),

    Func("type_override", FuncType.CONFIGURATION, Elem.OBJECT("Erlaubt es den verbauten Zählertyp zu überschreiben, falls die Auto-Detektion nicht funktioniert.", version=Version.WARP1, members={
            "type": Elem.INT("Stromzählertyp, der verwendet werden soll", constants=[
                Const(0, "Kein Stromzähler verfügbar"),
                Const(1, "SDM72"),
                Const(2, "SDM630"),
                Const(3, "SDM72V2"),
                Const(255, "Typ-Override nicht aktiv. Stromzählertyp wird automatisch detektiert.")
            ])
        })
    ),

    Func("history", FuncType.HTTP_ONLY, Elem.OBJECT("Eine 48-Stunden-Historie der Ladeleistung in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", members={
        "offset": Elem.INT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.ms),
        "samples": Elem.ARRAY("Die gemessenen Werte.", unit=Units.W, member_type=EType.INT)
    })),

    Func("live", FuncType.HTTP_ONLY, Elem.OBJECT("Die letzten Ladeleistungs-Messwerte. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meter/history}}} generiert.", members={
        "offset": Elem.INT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.ms),
        "samples_per_second": Elem.FLOAT("Die Anzahl der gemessenen Werte pro Sekunde.", unit=Units.Hz),
        "samples": Elem.ARRAY("Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", unit=Units.W, member_type=EType.INT)
    }))
])
