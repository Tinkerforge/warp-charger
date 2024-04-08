from api_doc_common import *

meters = Module("meters", "Stromzähler", "",
    """WARP Charger und Energy Manager unterstützen mehrere Stromzähler.
    Die Stromzähler-API ist aufgeteilt in einem allgemeinen Teil unter meters/...
    und einen Stromzähler-spezifischen Teil unter meters/X/... wobei X einer Stromzähler-Nummer entspricht.
    Der Stromzähler-spezifische Teil beinhaltet immer {{{ref:meters/X/value_ids}}}, {{{ref:meters/X/values}}}, {{{ref:meters/X/live}}} und {{{ref:meters/X/history}}} mit dem unten dokumentierten Inhalt.
    Beispielsweise können die Messwerte des ersten Stromzählers (der die Stromzählernummer 0 besitzt) unter meters/0/values gelesen werden.
    Außerdem hat jeder Zähler die APIs {{{ref:meters/X/config}}}, {{{ref:meters/X/state}}} und {{{ref:meters/X/errors}}}, deren Inhalt von der Klasse des Stromzählers abhängt.
    Die Stromzählerklasse wird als das <a href="#unions_section">Union</a>-Tag von {{{ref:meters/X/config}}} angegeben.
    <br><br>
    Jeder Stromzähler meldet seine Messwerte unter {{{ref:meters/X/values}}} als ein Array von Floats.
    Welcher Messwert wie zu interpretieren ist, kann unter {{{ref:meters/X/value_ids}}} (einem Array von Ints, den sogenannten MeterValueIDs) ausgelesen werden:
    Wenn beispielsweise an Index 3 in {{{ref:meters/X/value_ids}}} die MeterValueID 13 gelesen wird, dann ist der {{{ref:meters/X/values}}}-Wert an Index 3 als der Phasenstrom auf L1 zu interpretieren.
    Alle MeterValueIDs sind auf Github dokumentiert: <a href="https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv">Dokumentation der MeterValueIDs</a>
    """,
    Version.ANY, [
    Func("X/values", FuncType.STATE, Elem.ARRAY("Die Messwerte des X. Stromzählers. Die Bedeutung der Messwerte kann aus {{{ref:meters/X/value_ids}}} ermittelt werden. Bei einem API-Stromzähler können diese Werte über meters/X/update geschrieben werden", member_type=EType.FLOAT)),

    Func("X/value_ids", FuncType.STATE, Elem.ARRAY("Die MeterValueIDs des X. Stromzählers. Der n-te Eintrag in diesem Array gibt die Bedeutung des n-ten Messwerts aus {{{ref:meters/X/values}}} an. <a href=\"https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv\">Dokumentation der MeterValueIDs</a>", member_type=EType.INT)),

    Func("X/history", FuncType.HTTP_ONLY, Elem.OBJECT("Eine 48-Stunden-Historie der Ladeleistung des X. Stromzählers in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", members={
        "offset": Elem.FLOAT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.s),
        "samples": Elem.ARRAY("Die gemessenen Werte.", unit=Units.W, member_type=EType.INT)
    })),

    Func("X/live", FuncType.HTTP_ONLY, Elem.OBJECT("Die letzten Ladeleistungs-Messwerte des X. Stromzählers. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meters/X/history}}} generiert.", members={
        "offset": Elem.FLOAT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.s),
        "samples_per_second": Elem.FLOAT("Die Anzahl der gemessenen Werte pro Sekunde.", unit=Units.Hz),
        "samples": Elem.ARRAY("Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", unit=Units.W, member_type=EType.INT)
    })),

    Func("X/config", FuncType.CONFIGURATION, Elem.UNION("Die Konfiguration des X. Stromzählers. Das Union-Tag gibt die Zählerklasse an.", members={
        0: Elem.NULL("Kein Stromzähler konfiguriert."),
        1: Elem.OBJECT("Interner Stromzähler (an RS485-Bricklet)", version=Version.WARP1, members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "type_override": Elem.INT("Erlaubt es den verbauten Zählertyp zu überschreiben, falls die Auto-Detektion nicht funktioniert.", constants=[
                Const(0, "Kein Stromzähler verfügbar"),
                Const(1, "SDM72"),
                Const(2, "SDM630"),
                Const(3, "SDM72V2"),
                Const(255, "Typ-Override nicht aktiv. Stromzählertyp wird automatisch detektiert.")
            ])
        }),
        2: Elem.OBJECT("Interner Stromzähler (an EVSE-2.0-Bricklet)", version=Version.WARP2 | Version.WARP3, members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers")
        }),
        3: Elem.OBJECT("Stromzähler angeschlossen am WARP Energy Manager", version=Version.WARPEM, members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
        }),
        4: Elem.OBJECT("API-Stromzähler", members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "value_ids": Elem.ARRAY("MeterValueIDs, die über die API {{{ref:meters/X/values:meters/X/update}}} gesetzt werden können sollen. <a href=\"https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv\">Dokumentation der MeterValueIDs</a>", member_type=EType.INT)
        }),
        5: Elem.OBJECT("SunSpec-Stromzähler über Modbus-TCP", members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "host": Elem.STRING("Hostname oder IP-Adresse des SunSpec-Geräts"),
            "port": Elem.INT("Port des SunSpec-Geräts. Typischerweise 502"),
            "device_addess": Elem.INT("Modbus-Device-Adresse des Sunspec-Geräts"),
            "model_id": Elem.INT("SunSpec-Model-ID"),
        })
    })),

    Func("X/state", FuncType.STATE, Elem.OBJECT("Der Zustand des X. Stromzählers. Der Inhalt dieser API hängt vom Typ des Stromzählers ab, der in {{{ref:meters/X/config}}} konfiguriert wurde.", members={
            0: Elem.NULL("Kein Stromzähler konfiguriert."),
            "1, 2, 3": Elem.OBJECT("Zustand des internen Stromzählers", members={
                "type": Elem.INT("Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jedem Gerät unterstützt!", constants=[
                    Const(0, "Kein Stromzähler verfügbar"),
                    Const(1, "SDM72", Version.WARP1),
                    Const(2, "SDM630", Version.ANY),
                    Const(3, "SDM72V2", Version.ANY),
                    Const(4, "SDM72CTM", Version.WARPEM),
                    Const(5, "SDM630MCT", Version.WARPEM)
                ]),
            }),
            4: Elem.NULL("Zustand des API-Stromzählers. Im Moment leer."),
            5: Elem.NULL("Zustand des SunSpec-Stromzählers. Im Moment leer.")
        })
    ),

    Func("X/errors", FuncType.STATE, Elem.OBJECT("Fehlerzähler der Kommunikation mit dem Stromzähler. Der Inhalt dieser API hängt vom Typ des Stromzählers ab, der in {{{ref:meters/X/config}}} konfiguriert wurde.", members={
             0: Elem.NULL("Kein Stromzähler konfiguriert."),
             "1, 2, 3": Elem.OBJECT("Fehlerzähler des internen Stromzählers", members={
                "meter": Elem.INT("Kommunikationsfehler zwischen RS485 Bricklet und Stromzähler.", version=Version.WARP1),
                "bricklet": Elem.INT("Kommunikationsfehler zwischen ESP Brick und RS485 Bricklet.", version=Version.WARP1),
                "bricklet_reset": Elem.INT("Unerwartete Resets des RS485 Bricklets.", version=Version.WARP1),

                "local_timeout": Elem.INT("Local Timeout", version=Version.WARP2 | Version.WARP3 | Version.WARPEM),
                "global_timeout": Elem.INT("Global Timeout", version=Version.WARP2 | Version.WARP3 | Version.WARPEM),
                "illegal_function": Elem.INT("Illegal Function", version=Version.WARP2 | Version.WARP3 | Version.WARPEM),
                "illegal_data_access": Elem.INT("Illegal Data Access", version=Version.WARP2 | Version.WARP3 | Version.WARPEM),
                "illegal_data_value": Elem.INT("Illegal Data Value", version=Version.WARP2 | Version.WARP3 | Version.WARPEM),
                "slave_device_failure": Elem.INT("Slave Device Failure", version=Version.WARP2 | Version.WARP3 | Version.WARPEM),
            }),
            4: Elem.NULL("Fehlerzähler des API-Stromzählers. Im Moment leer."),
            5: Elem.NULL("Fehlerzähler des SunSpec-Stromzählers. Im Moment leer."),
        })
    ),

    Func("X/reset", FuncType.COMMAND, Elem.NULL("Setzt alle zurücksetzbaren (Alle Werte deren \"kind\"-Eintrag \"resettable\" ist: <a href=\"https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv\">Dokumentation der MeterValueIDs</a>) Zählerwerte des X. Stromzählers zurück."), command_is_action=True),
    Func("X/last_reset", FuncType.STATE, Elem.OBJECT("Der Zeitpunkt des letzten Zähler-Resets (siehe {{{ref:meters/X/reset}}}) als Unix-Timestamp. 0 falls kein Reset durchgeführt wurde. Falls zum Zeitpunkt des letzten Resets keine Zeitsynchronisierung vorlag, ist dieser Wert stattdessen ein Zähler, der angibt, wie oft ein Reset durchgeführt wurde.", members={
            "last_reset": Elem.INT("Unix-Timestamp des Zeitpunkts des letzten Zähler-Resets.", unit=Units.s)
        })
    ),


    Func("history", FuncType.HTTP_ONLY, Elem.OBJECT("Eine 48-Stunden-Historie der Ladeleistung in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", members={
        "offset": Elem.FLOAT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.s),
        "samples": Elem.ARRAY("Die gemessenen Werte aller Stromzähler. Die Größe des Arrays ist 2 bei WARP1 und WARP2, 7 beim WARP Energy Manager.", members=
            2 * [Elem.ARRAY("Die gemessenen Werte des jeweiligen Stromzählers", unit=Units.W, member_type=EType.INT)]
        )
    })),

    Func("live", FuncType.HTTP_ONLY, Elem.OBJECT("Die letzten Ladeleistungs-Messwerte. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meters/history}}} generiert.", members={
        "offset": Elem.FLOAT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.s),
        "samples_per_second": Elem.FLOAT("Die Anzahl der gemessenen Werte pro Sekunde.", unit=Units.Hz),
        "samples": Elem.ARRAY("Die gemessenen Werte aller Stromzähler. Die Größe des Arrays ist 2 bei WARP1 und WARP2, 7 beim WARP Energy Manager..", members=
            2 * [Elem.ARRAY("Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", unit=Units.W, member_type=EType.INT)]
        )
    }))
])
