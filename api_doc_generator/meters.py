from api_doc_common import *

def meters_x_get_tag_fn(api: str, info: list):
    meter = api.rsplit("/", 1)[0]
    return next(x for x in info if x["path"] == meter + "/config")["content"]["tag"]

meters = Module("meters", "Stromzähler", "",
    """WARP Charger und Energy Manager unterstützen mehrere Stromzähler.
    Die Stromzähler-API ist aufgeteilt in einem allgemeinen Teil unter `meters/...`
    und einen Stromzähler-spezifischen Teil unter `meters/X/...` wobei `X` einer Stromzähler-Nummer entspricht.
    Der Stromzähler-spezifische Teil beinhaltet immer
    - {{{ref:meters/X/value_ids}}}
    - {{{ref:meters/X/values}}}
    - {{{ref:meters/X/live}}}
    - {{{ref:meters/X/history}}}

    Beispielsweise können die Messwerte des ersten Stromzählers (der die Stromzählernummer 0 besitzt) unter `meters/0/values` gelesen werden.
    Außerdem hat jeder Zähler die APIs
    - {{{ref:meters/X/config}}}
    - {{{ref:meters/X/state}}}
    - {{{ref:meters/X/errors}}}

    deren Inhalt von der Klasse des Stromzählers abhängt.
    Die Stromzählerklasse wird als das <a href="#unions_section">Union</a>-Tag von {{{ref:meters/X/config}}} angegeben.

    Jeder Stromzähler meldet seine Messwerte unter {{{ref:meters/X/values}}} als ein Array von Floats.
    Welcher Messwert wie zu interpretieren ist, kann unter {{{ref:meters/X/value_ids}}} (einem Array von Ints, den sogenannten MeterValueIDs) ausgelesen werden:
    Wenn beispielsweise an Index 3 in {{{ref:meters/X/value_ids}}} die MeterValueID 13 gelesen wird, dann ist der {{{ref:meters/X/values}}}-Wert an Index 3 als der Phasenstrom auf L1 zu interpretieren.

    Alle MeterValueIDs sind auf Github dokumentiert: [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)
    <br/>
    <br/>
    """,
    Version.ANY, [
    Func("X/values", FuncType.STATE, Elem.ARRAY("Die Messwerte des X. Stromzählers. Die Bedeutung der Messwerte kann aus {{{ref:meters/X/value_ids}}} ermittelt werden.", member_type=EType.FLOAT)),
    Func("X/update", FuncType.COMMAND, Elem.ARRAY("Aktualisiert die Messwerte des X. Stromzählers. Kann nur bei einem API-Stromzähler (Union-Tag 4 in der entsprechenden {{{ref:meters/X/config}}}) verwendet werden.", member_type=EType.FLOAT)),

    Func("X/value_ids", FuncType.STATE, Elem.ARRAY("Die MeterValueIDs des X. Stromzählers. Der n-te Eintrag in diesem Array gibt die Bedeutung des n-ten Messwerts aus {{{ref:meters/X/values}}} an. [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)", member_type=EType.INT)),

    Func("X/history", FuncType.HTTP_ONLY, Elem.OBJECT("Eine 48-Stunden-Historie der Ladeleistung des X. Stromzählers in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", members={
        "offset": Elem.INT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.ms),
        "samples": Elem.ARRAY("Die gemessenen Werte.", unit=Units.W, member_type=EType.INT)
    })),

    Func("X/live", FuncType.HTTP_ONLY, Elem.OBJECT("Die letzten Ladeleistungs-Messwerte des X. Stromzählers. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meters/X/history}}} generiert.", members={
        "offset": Elem.INT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.ms),
        "samples_per_second": Elem.FLOAT("Die Anzahl der gemessenen Werte pro Sekunde.", unit=Units.Hz),
        "samples": Elem.ARRAY("Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", unit=Units.W, member_type=EType.INT)
    })),

    Func("X/config", FuncType.CONFIGURATION, Elem.UNION("Die Konfiguration des X. Stromzählers. Das Union-Tag gibt die Zählerklasse an.", tab_id="metersXConfig", members={
        0: Elem.NULL("Kein Stromzähler konfiguriert."),
        1: Elem.OBJECT("Interner Stromzähler (an RS485-Bricklet)", version=Version.WARP1, members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
            "type_override": Elem.INT("Erlaubt es den verbauten Zählertyp zu überschreiben, falls die Auto-Detektion nicht funktioniert.", constants=[
                Const(0, "Kein Stromzähler verfügbar"),
                Const(1, "SDM72"),
                Const(2, "SDM630"),
                Const(3, "SDM72V2"),
                Const(255, "Typ-Override nicht aktiv. Stromzählertyp wird automatisch detektiert.")
            ])
        }),
        2: Elem.OBJECT("Interner Stromzähler (an EVSE-2.0-Bricklet)", version=Version.WARP2 | Version.WARP3, members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
        }),
        3: Elem.OBJECT("Stromzähler angeschlossen am WARP Energy Manager", version=Version.WEMX, members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
        }),
        4: Elem.OBJECT("API-Stromzähler", members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
            "value_ids": Elem.ARRAY("MeterValueIDs, die über die API {{{ref:meters/X/values:meters/X/update}}} gesetzt werden können sollen. [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)", member_type=EType.INT)
        }),
        5: Elem.OBJECT("SunSpec-Gerät über Modbus-TCP", members={
            "display_name": Elem.STRING("Anzeigename des Geräts"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
            "host": Elem.STRING("Hostname oder IP-Adresse des SunSpec-Geräts"),
            "port": Elem.INT("Port des SunSpec-Geräts. Typischerweise 502"),
            "device_address": Elem.INT("Modbus-Device-Adresse des Sunspec-Geräts"),
            "manufacturer_name": Elem.STRING("Name des Herstellers des SunSpec-Geräts. Die Kombination aus `manufacturer_name`, `model_name` und `serial_number` sollte ein Gerät weltweit eindeutig identifizieren."),
            "model_name": Elem.STRING("Name des Modells des SunSpec-Geräts."),
            "serial_number": Elem.STRING("Seriennummer des SunSpec-Geräts."),
            "model_id": Elem.INT("SunSpec-Model-ID"),
            "model_instance": Elem.INT("Gibt an wie viele SunSpec-Modelle mit gleicher `model_id` übersprungen werden, bis das gewünsche Modell gleicher ID erreicht ist."),
        }),
        6: Elem.OBJECT("Modbus-TCP-Stromzähler.", members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
            "host": Elem.STRING("Hostname oder IP-Adresse des SunSpec-Geräts"),
            "port": Elem.INT("Port des SunSpec-Geräts. Typischerweise 502"),
            "table": Elem.UNION("Registertabelle, die gelesen werden soll.", members={
                0: Elem.NULL("Keine Registertabelle konfiguriert."),
                1: Elem.OBJECT("Benutzerdefinierte Registertabelle", members={
                    "device_address": Elem.INT("Geräteadresse."),
                    "register_address_mode": Elem.INT("Gibt an, ob die konfigurierten Registerstartadressen im Webinterface als Adressen oder Registernummern angezeigt werden.", constants=[
                        Const(0, "Startadressen werden als Registeraddressen angezeigt. Die erste Adresse ist 0."),
                        Const(1, "Startadressen werden als Registernummern angezeigt. Die erste Registernummer ist 1."),
                    ]),
                    "registers": Elem.ARRAY("Registertabelle", members=
                        36 * [
                            Elem.OBJECT("Ein Register, dass gelesen werden soll", members={
                                "rtype": Elem.INT("Registertyp", constants=[
                                    Const(0, "Holding Register"),
                                    Const(1, "Input Register"),
                                ]),
                                "addr": Elem.INT("Startadresse des Registers."),
                                "vtype": Elem.INT("Wert-Typ", constants=[
                                    Const(1, "Ein Register, 16-Bit, Ganzzahl, vorzeichenlos"),
                                    Const(9, "Ein Register, 16-Bit, Ganzzahl, vorzeichenbehaftet"),
                                    Const(2, "Zwei Register, 32-Bit, Ganzzahl, vorzeichenlos, Big-Endian"),
                                    Const(34, "Zwei Register, 32-Bit, Ganzzahl, vorzeichenlos, Little-Endian"),
                                    Const(10, "Zwei Register, 32-Bit, Ganzzahl, vorzeichenbehaftet, Big-Endian"),
                                    Const(42, "Zwei Register, 32-Bit, Ganzzahl, vorzeichenbehaftet, Little-Endian"),
                                    Const(26, "Zwei Register, 32-Bit, Gleitkommazahl, Big-Endian"),
                                    Const(58, "Zwei Register, 32-Bit, Gleitkommazahl, Little-Endian"),
                                    Const(4, "Vier Register, 64-Bit, Ganzzahl, vorzeichenlos, Big-Endian"),
                                    Const(36, "Vier Register, 64-Bit, Ganzzahl, vorzeichenlos, Little-Endian"),
                                    Const(12, "Vier Register, 64-Bit, Ganzzahl, vorzeichenbehaftet, Big-Endian"),
                                    Const(44, "Vier Register, 64-Bit, Ganzzahl, vorzeichenbehaftet, Little-Endian"),
                                    Const(28, "Vier Register, 64-Bit, Gleitkommazahl, Big-Endian"),
                                    Const(60, "Vier Register, 64-Bit, Gleitkommazahl, Little-Endian")
                                ]),
                                "off": Elem.FLOAT("Offset, dass auf den gelesenen Wert addiert werden soll. Der Offset-Wert wird addiert, bevor der Skalierungsfaktor angewandt wird."),
                                "scale": Elem.FLOAT("Skalierungsfaktor, mit dem der gelesene Wert multipliziert werden soll. Der Skalierungsfaktor wirkt auf den Wert, der durch die Addition des gelesenen Wertes mit dem Offset entstanden ist."),
                                "id": Elem.INT("MeterValueID, die die Interpretation des gelesenen Werts angibt. [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)")
                            })
                        ]
                    )
                }),
                2: Elem.OBJECT("Sungrow Hybrid-Wechselrichter (SH...)", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher"),
                        Const(4, "Last")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                }),
                3: Elem.OBJECT("Sungrow String-Wechselrichter (SG...)", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Last")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                }),
                4: Elem.OBJECT("Solarmax Max.Storage", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                }),
                5: Elem.OBJECT("Victron Energy GX", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher"),
                        Const(4, "Last")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 100."),
                }),
                6: Elem.OBJECT("Deye Hybrid-Wechselrichter", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher"),
                        Const(4, "Last")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                }),
                7: Elem.OBJECT("AlphaESS Hybrid-Wechselrichter", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                }),
                8: Elem.OBJECT("Shelly Pro EM", members={
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                    "monophase_channel": Elem.INT("Kanal, der gelesen werden soll.", constants=[
                        Const(0, "Kein Kanal ausgewählt"),
                        Const(1, "Kanal 1"),
                        Const(2, "Kanal 2")
                    ]),
                    "monophase_mapping": Elem.INT("Phase der die Messwerte zugeordnet werden.", constants=[
                        Const(0, "Keine Phase ausgewählt"),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                9: Elem.OBJECT("Shelly Pro 3EM", members={
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                    "device_profile": Elem.INT("Gibt an, ob eine oder alle drei Phasen gelesen werden sollen.", constants=[
                        Const(0, "Dreiphasig. `monophase_channel` und `monophase_mapping` werden ignoriert."),
                        Const(1, "Einphasig")
                    ]),
                    "monophase_channel": Elem.INT("Kanal, der gelesen werden soll.", constants=[
                        Const(0, "Kein Kanal ausgewählt"),
                        Const(1, "Kanal 1"),
                        Const(2, "Kanal 2"),
                        Const(3, "Kanal 3")
                    ]),
                    "monophase_mapping": Elem.INT("Phase der die Messwerte zugeordnet werden.", constants=[
                        Const(0, "Keine Phase ausgewählt"),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                10: Elem.OBJECT("GoodWe Hybrid-Wechselrichter", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher"),
                        Const(4, "Last"),
                        Const(5, "Backup-Last"),
                        Const(6, "Zähler")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 247."),
                }),

                11: Elem.OBJECT("Solax Hybrid-Wechselrichter", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                }),
                12: Elem.OBJECT("Fronius GEN24 Plus", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter (wird nicht verwendet)"),
                        Const(2, "Netzanschluss (wird nicht verwendet)"),
                        Const(3, "Speicher")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                }),
                13: Elem.OBJECT("Hailei Hybrid-Wechselrichter", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 85."),
                }),
                14: Elem.OBJECT("Fox ESS H3 Hybrid-Wechselrichter", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 247."),
                }),

                **{15 + i: Elem.OBJECT(f"Siemens {siemens_subtype} Stromzähler", members={
                        "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                    }) for i, siemens_subtype in enumerate([
                        "PAC2200",
                        "PAC3120",
                        "PAC3200",
                        "PAC3220",
                        "PAC4200",
                        "PAC4220",
                        ])
                },

                21: Elem.OBJECT("Carlo Gavazzi EM24 DIN Stromzähler", members={"device_address": Elem.INT("Geräteadresse. Typischerweise 1.")}),
                22: Elem.OBJECT("Carlo Gavazzi EM24 E1 Stromzähler", members={"device_address": Elem.INT("Geräteadresse. Typischerweise 1.")}),

                23: Elem.OBJECT("Carlo Gavazzi EM100 Stromzähler", members={
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                    "phase": Elem.INT("Phase der die Messwerte zugeordnet werden.", constants=[
                        Const(0, "Keine Phase ausgewählt"),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                24: Elem.OBJECT("Carlo Gavazzi ET100 Stromzähler", members={
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                    "phase": Elem.INT("Phase der die Messwerte zugeordnet werden.", constants=[
                        Const(0, "Keine Phase ausgewählt"),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),

                25: Elem.OBJECT("Carlo Gavazzi EM210 Stromzähler", members={"device_address": Elem.INT("Geräteadresse. Typischerweise 1.")}),

                26: Elem.OBJECT("Carlo Gavazzi EM270 Stromzähler", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Zähler"),
                        Const(2, "Stromwandler 1"),
                        Const(3, "Stromwandler 2")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1.")
                }),
                27: Elem.OBJECT("Carlo Gavazzi EM280 Stromzähler", members={
                    "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Zähler"),
                        Const(2, "Stromwandler 1"),
                        Const(3, "Stromwandler 2")
                    ]),
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1.")
                }),

                28: Elem.OBJECT("Carlo Gavazzi EM300 Stromzähler", members={"device_address": Elem.INT("Geräteadresse. Typischerweise 1.")}),
                29: Elem.OBJECT("Carlo Gavazzi ET300 Stromzähler", members={"device_address": Elem.INT("Geräteadresse. Typischerweise 1.")}),
                30: Elem.OBJECT("Carlo Gavazzi EM510 Stromzähler", members={
                    "device_address": Elem.INT("Geräteadresse. Typischerweise 1."),
                    "phase": Elem.INT("Phase der die Messwerte zugeordnet werden.", constants=[
                        Const(0, "Keine Phase ausgewählt"),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                31: Elem.OBJECT("Carlo Gavazzi EM530 Stromzähler", members={"device_address": Elem.INT("Geräteadresse. Typischerweise 1.")}),
                32: Elem.OBJECT("Carlo Gavazzi EM540 Stromzähler", members={"device_address": Elem.INT("Geräteadresse. Typischerweise 1.")})
            })
        }),
        7: Elem.OBJECT("SMA Speedwire-Stromzähler.", members={
            "display_name": Elem.STRING("Anzeigename des Stromzählers"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
        }),
        8: Elem.OBJECT("RCT Power Wechselrichter", members={
            "display_name": Elem.STRING("Anzeigename des Wechselrichters"),
            "location": Elem.INT("Messort", constants=[
                Const(0, "Unbekannt"),
                Const(1, "Andere"),
                Const(2, "Wallbox"),
                Const(3, "Wechselrichter"),
                Const(4, "Netzanschluss"),
                Const(5, "Speicher"),
                Const(6, "Last"),
                Const(7, "PV"),
            ]),
            "host": Elem.STRING("Hostname oder IP-Adresse des Wechselrichters"),
            "port": Elem.INT("Port des Wechselrichters. Typischerweise 8899"),
            "virtual_meter": Elem.INT("Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", constants=[
                        Const(0, "Kein virtueller Zähler ausgewählt"),
                        Const(1, "Wechselrichter (wird nicht verwendet)"),
                        Const(2, "Netzanschluss"),
                        Const(3, "Speicher")
                    ]),
        })
    })),

    Func("X/state", FuncType.STATE, Elem.HIDDEN_UNION("Der Zustand des X. Stromzählers. Der Inhalt dieser API hängt vom Typ des Stromzählers ab, der in {{{ref:meters/X/config}}} konfiguriert wurde.", tab_id="metersXConfig", get_tag_fn=meters_x_get_tag_fn, members={
            0: Elem.NULL("Kein Stromzähler konfiguriert."),
            1: Elem.OBJECT("Zustand des internen Stromzählers", members={
                "type": Elem.INT("Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jedem Gerät unterstützt!", constants=[
                    Const(0, "Kein Stromzähler verfügbar"),
                    Const(1, "SDM72"),
                    Const(2, "SDM630"),
                    Const(3, "SDM72V2")
                ])
            }),
            **{x: Elem.OBJECT("Zustand des internen Stromzählers", members={
                "type": Elem.INT("Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jedem Gerät unterstützt!", constants=[
                    Const(0, "Kein Stromzähler verfügbar"),
                    Const(2, "SDM630"),
                    Const(3, "SDM72V2"),
                    Const(4, "SDM72CTM"),
                    Const(5, "SDM630MCT"),
                    Const(6, "DSZ15DZMOD"),
                    Const(7, "DEM4A"),
                ]),
            }) for x in [2, 3]},
            4: Elem.NULL("Zustand des API-Stromzählers. Im Moment leer."),
            5: Elem.NULL("Zustand des SunSpec-Stromzählers. Im Moment leer.")
        })
    ),

    Func("X/errors", FuncType.STATE, Elem.HIDDEN_UNION("Fehlerzähler der Kommunikation mit dem Stromzähler. Der Inhalt dieser API hängt vom Typ des Stromzählers ab, der in {{{ref:meters/X/config}}} konfiguriert wurde.", tab_id="metersXConfig", get_tag_fn=meters_x_get_tag_fn, members={
             0: Elem.NULL("Kein Stromzähler konfiguriert."),
             1: Elem.OBJECT("Fehlerzähler des internen Stromzählers", members={
                "meter": Elem.INT("Kommunikationsfehler zwischen RS485 Bricklet und Stromzähler."),
                "bricklet": Elem.INT("Kommunikationsfehler zwischen ESP Brick und RS485 Bricklet."),
                "bricklet_reset": Elem.INT("Unerwartete Resets des RS485 Bricklets.")
             }),
             **{x: Elem.OBJECT("Fehlerzähler des internen Stromzählers", members={
                "local_timeout": Elem.INT("Local Timeout"),
                "global_timeout": Elem.INT("Global Timeout"),
                "illegal_function": Elem.INT("Illegal Function"),
                "illegal_data_access": Elem.INT("Illegal Data Access"),
                "illegal_data_value": Elem.INT("Illegal Data Value"),
                "slave_device_failure": Elem.INT("Slave Device Failure"),
            }) for x in [2, 3]},
            4: Elem.NULL("Fehlerzähler des API-Stromzählers. Im Moment leer."),
            5: Elem.NULL("Fehlerzähler des SunSpec-Stromzählers. Im Moment leer."),
        })
    ),

    Func("X/reset", FuncType.COMMAND, Elem.NULL("Setzt alle zurücksetzbaren (Alle Werte deren `kind`-Eintrag `resettable` ist: [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)) Zählerwerte des X. Stromzählers zurück."), command_is_action=True),
    Func("X/last_reset", FuncType.STATE, Elem.OBJECT("Der Zeitpunkt des letzten Zähler-Resets (siehe {{{ref:meters/X/reset}}}) als Unix-Timestamp. 0 falls kein Reset durchgeführt wurde. Falls zum Zeitpunkt des letzten Resets keine Zeitsynchronisierung vorlag, ist dieser Wert stattdessen ein Zähler, der angibt, wie oft ein Reset durchgeführt wurde.", members={
            "last_reset": Elem.INT("Unix-Timestamp des Zeitpunkts des letzten Zähler-Resets.", unit=Units.s)
        })
    ),


    Func("history", FuncType.HTTP_ONLY, Elem.OBJECT("Eine 48-Stunden-Historie der Ladeleistung in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", members={
        "offset": Elem.INT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.ms),
        "samples": Elem.ARRAY("Die gemessenen Werte aller Stromzähler.", members=
              (2 * [Elem.ARRAY("Die gemessenen Werte des jeweiligen Stromzählers. Null falls ein Zähler nicht konfiguriert ist.", unit=Units.W, member_type=EType.INT, version=Version.WARP1)])
            + (5 * [Elem.ARRAY("Die gemessenen Werte des jeweiligen Stromzählers. Null falls ein Zähler nicht konfiguriert ist.", unit=Units.W, member_type=EType.INT, version=Version.WARP2 | Version.WARP3)])
            + (7 * [Elem.ARRAY("Die gemessenen Werte des jeweiligen Stromzählers. Null falls ein Zähler nicht konfiguriert ist.", unit=Units.W, member_type=EType.INT, version=Version.WEMX)])
        )
    })),

    Func("live", FuncType.HTTP_ONLY, Elem.OBJECT("Die letzten Ladeleistungs-Messwerte. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meters/history}}} generiert. Es werden bis zu 720 Werte ausgegeben, das entspricht 6 Minuten bei einem Messwert alle 500 Millisekunden.", members={
        "offset": Elem.INT("Das Alter des zuletzt gemessenen Wertes.", unit=Units.ms),
        "samples_per_second": Elem.FLOAT("Die Anzahl der gemessenen Werte pro Sekunde.", unit=Units.Hz),
        "samples": Elem.ARRAY("Die gemessenen Werte aller Stromzähler.", members=
             (2 * [Elem.ARRAY("Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", unit=Units.W, member_type=EType.INT, version=Version.WARP1)]
            + 5 * [Elem.ARRAY("Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", unit=Units.W, member_type=EType.INT, version=Version.WARP2 | Version.WARP3)]
            + 7 * [Elem.ARRAY("Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", unit=Units.W, member_type=EType.INT, version=Version.WEMX)])
        )
    }))
])
