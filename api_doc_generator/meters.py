from api_doc_common import *

# Helper constants for repeated location values
LOCATION_CONSTANTS = [
    Const(0, T({'de': "Unbekannt", 'en': "Unknown"})),
    Const(1, T({'de': "Andere", 'en': "Other"})),
    Const(2, "Wallbox"),
    Const(3, T({'de': "Wechselrichter", 'en': "Inverter"})),
    Const(4, T({'de': "Netzanschluss", 'en': "Grid connection"})),
    Const(5, T({'de': "Speicher", 'en': "Storage"})),
    Const(6, T({'de': "Last", 'en': "Load"})),
    Const(7, "PV"),
]

def meters_x_get_tag_fn(api: str, info: list):
    meter = api.rsplit("/", 1)[0]
    return next(x for x in info if x["path"] == meter + "/config")["content"]["tag"]

meters = Module("meters", T({'de': "Stromzähler", 'en': "Electricity Meters"}), "",
    T({'de': """WARP Charger und Energy Manager unterstützen mehrere Stromzähler.
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
    """, 'en': """WARP Charger and Energy Manager support multiple electricity meters.
    The electricity meter API is divided into a general part under `meters/...`
    and a meter-specific part under `meters/X/...` where `X` corresponds to a meter number.
    The meter-specific part always includes
    - {{{ref:meters/X/value_ids}}}
    - {{{ref:meters/X/values}}}
    - {{{ref:meters/X/live}}}
    - {{{ref:meters/X/history}}}

    For example, the measurement values of the first electricity meter (which has meter number 0) can be read under `meters/0/values`.
    Additionally, each meter has the APIs
    - {{{ref:meters/X/config}}}
    - {{{ref:meters/X/state}}}
    - {{{ref:meters/X/errors}}}

    whose content depends on the class of the electricity meter.
    The electricity meter class is specified as the <a href="#unions_section">union</a> tag of {{{ref:meters/X/config}}}.

    Each electricity meter reports its measurement values under {{{ref:meters/X/values}}} as an array of floats.
    Which measurement value should be interpreted in which way can be read from {{{ref:meters/X/value_ids}}} (an array of ints, the so-called MeterValueIDs):
    For example, if MeterValueID 13 is read at index 3 in {{{ref:meters/X/value_ids}}}, then the {{{ref:meters/X/values}}} value at index 3 should be interpreted as the phase current on L1.

    All MeterValueIDs are documented on Github: [List of all MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)
    <br/>
    <br/>
    """}),
    Version.ANY, [
    Func("X/values", FuncType.STATE, Elem.ARRAY(T({'de': "Die Messwerte des X. Stromzählers. Die Bedeutung der Messwerte kann aus {{{ref:meters/X/value_ids}}} ermittelt werden.", 'en': "The measurement values of the X. electricity meter. The meaning of the measurement values can be determined from {{{ref:meters/X/value_ids}}}."}), member_type=EType.FLOAT)),
    Func("X/update", FuncType.COMMAND, Elem.ARRAY(T({'de': "Aktualisiert die Messwerte des X. Stromzählers. Kann nur bei einem API-Stromzähler (Union-Tag 4 in der entsprechenden {{{ref:meters/X/config}}}) verwendet werden.", 'en': "Updates the measurement values of the X. electricity meter. Can only be used with an API electricity meter (union tag 4 in the corresponding {{{ref:meters/X/config}}})."}), member_type=EType.FLOAT)),

    Func("X/value_ids", FuncType.STATE, Elem.ARRAY(T({'de': "Die MeterValueIDs des X. Stromzählers. Der n-te Eintrag in diesem Array gibt die Bedeutung des n-ten Messwerts aus {{{ref:meters/X/values}}} an. [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)", 'en': "The MeterValueIDs of the X. electricity meter. The n-th entry in this array indicates the meaning of the n-th measurement value from {{{ref:meters/X/values}}}. [List of all MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)"}), member_type=EType.INT)),

    Func("X/history", FuncType.HTTP_ONLY, Elem.OBJECT(T({'de': "Eine 48-Stunden-Historie der Ladeleistung des X. Stromzählers in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", 'en': "A 48-hour history of the charging power of the X. electricity meter in watts. Missing values are indicated by null. The history is filled from back to front, so null values only occur consecutively at the beginning of the array if the ESP was restarted within the last 48 hours. Up to 720 values are output, which corresponds to one measurement value every 4 minutes. These measurement values are the respective average of these 4 minutes."}), members={
        "offset": Elem.INT(T({'de': "Das Alter des zuletzt gemessenen Wertes.", 'en': "The age of the last measured value."}), unit=Units.ms),
        "samples": Elem.ARRAY(T({'de': "Die gemessenen Werte.", 'en': "The measured values."}), unit=Units.W, member_type=EType.INT)
    })),

    Func("X/live", FuncType.HTTP_ONLY, Elem.OBJECT(T({'de': "Die letzten Ladeleistungs-Messwerte des X. Stromzählers. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meters/X/history}}} generiert.", 'en': "The last charging power measurement values of the X. electricity meter. Based on these values, the average values for {{{ref:meters/X/history}}} are generated."}), members={
        "offset": Elem.INT(T({'de': "Das Alter des zuletzt gemessenen Wertes.", 'en': "The age of the last measured value."}), unit=Units.ms),
        "samples_per_second": Elem.FLOAT(T({'de': "Die Anzahl der gemessenen Werte pro Sekunde.", 'en': "The number of measured values per second."}), unit=Units.Hz),
        "samples": Elem.ARRAY(T({'de': "Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", 'en': "The measured values. Depending on the length of the array and the samples_per_second value, it can be determined how far back in time the measurement values reach."}), unit=Units.W, member_type=EType.INT)
    })),

    Func("X/config", FuncType.CONFIGURATION, Elem.UNION(T({'de': "Die Konfiguration des X. Stromzählers. Das Union-Tag gibt die Zählerklasse an.", 'en': "The configuration of the X. electricity meter. The union tag specifies the meter class."}), tab_id="metersXConfig", members={
        0: Elem.NULL(T({'de': "Kein Stromzähler konfiguriert.", 'en': "No electricity meter configured."})),
        1: Elem.OBJECT(T({'de': "Interner Stromzähler (an RS485-Bricklet)", 'en': "Internal electricity meter (on RS485 Bricklet)"}), version=Version.WARP1, members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Stromzählers", 'en': "Display name of the electricity meter"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
            "type_override": Elem.INT(T({'de': "Erlaubt es den verbauten Zählertyp zu überschreiben, falls die Auto-Detektion nicht funktioniert.", 'en': "Allows overriding the installed meter type if auto-detection does not work."}), constants=[
                Const(0, T({'de': "Kein Stromzähler verfügbar", 'en': "No electricity meter available"})),
                Const(1, "Eastron SDM72"),
                Const(2, "Eastron SDM630"),
                Const(3, "Eastron SDM72V2"),
                Const(255, T({'de': "Typ-Override nicht aktiv. Stromzählertyp wird automatisch detektiert.", 'en': "Type override not active. Electricity meter type is automatically detected."}))
            ])
        }),
        2: Elem.OBJECT(T({'de': "Interner Stromzähler (an EVSE-2.0-Bricklet)", 'en': "Internal electricity meter (on EVSE 2.0 Bricklet)"}), version=Version.WARP2 | Version.WARP3, members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Stromzählers", 'en': "Display name of the electricity meter"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
        }),
        3: Elem.OBJECT(T({'de': "Stromzähler angeschlossen am WARP Energy Manager", 'en': "Electricity meter connected to WARP Energy Manager"}), version=Version.WEMX, members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Stromzählers", 'en': "Display name of the electricity meter"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
        }),
        4: Elem.OBJECT(T({'de': "API-Stromzähler", 'en': "API electricity meter"}), members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Stromzählers", 'en': "Display name of the electricity meter"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
            "value_ids": Elem.ARRAY(T({'de': "MeterValueIDs, die über die API {{{ref:meters/X/values:meters/X/update}}} gesetzt werden können sollen. [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)", 'en': "MeterValueIDs that should be settable via the API {{{ref:meters/X/values:meters/X/update}}}. [List of all MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)"}), member_type=EType.INT)
        }),
        5: Elem.OBJECT(T({'de': "SunSpec-Gerät über Modbus-TCP", 'en': "SunSpec device via Modbus TCP"}), members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Geräts", 'en': "Display name of the device"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
            "host": Elem.STRING(T({'de': "Hostname oder IP-Adresse des SunSpec-Geräts", 'en': "Hostname or IP address of the SunSpec device"})),
            "port": Elem.INT(T({'de': "Port des SunSpec-Geräts. Typischerweise 502", 'en': "Port of the SunSpec device. Typically 502"})),
            "device_address": Elem.INT(T({'de': "Modbus-Device-Adresse des Sunspec-Geräts", 'en': "Modbus device address of the SunSpec device"})),
            "manufacturer_name": Elem.STRING(T({'de': "Name des Herstellers des SunSpec-Geräts. Die Kombination aus `manufacturer_name`, `model_name` und `serial_number` sollte ein Gerät weltweit eindeutig identifizieren.", 'en': "Name of the manufacturer of the SunSpec device. The combination of `manufacturer_name`, `model_name` and `serial_number` should uniquely identify a device worldwide."})),
            "model_name": Elem.STRING(T({'de': "Name des Modells des SunSpec-Geräts.", 'en': "Name of the model of the SunSpec device."})),
            "serial_number": Elem.STRING(T({'de': "Seriennummer des SunSpec-Geräts.", 'en': "Serial number of the SunSpec device."})),
            "model_id": Elem.INT(T({'de': "SunSpec-Model-ID", 'en': "SunSpec model ID"})),
            "model_instance": Elem.INT(T({'de': "Gibt an wie viele SunSpec-Modelle mit gleicher `model_id` übersprungen werden, bis das gewünsche Modell gleicher ID erreicht ist.", 'en': "Indicates how many SunSpec models with the same `model_id` should be skipped until the desired model with the same ID is reached."})),
        }),
        6: Elem.OBJECT(T({'de': "Modbus-TCP-Stromzähler.", 'en': "Modbus TCP electricity meter."}), members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Stromzählers", 'en': "Display name of the electricity meter"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
            "host": Elem.STRING(T({'de': "Hostname oder IP-Adresse des SunSpec-Geräts", 'en': "Hostname or IP address of the SunSpec device"})),
            "port": Elem.INT(T({'de': "Port des SunSpec-Geräts. Typischerweise 502", 'en': "Port of the SunSpec device. Typically 502"})),
            "table": Elem.UNION(T({'de': "Registertabelle, die gelesen werden soll.", 'en': "Register table to be read."}), members={
                0: Elem.NULL(T({'de': "Keine Registertabelle konfiguriert.", 'en': "No register table configured."})),
                1: Elem.OBJECT(T({'de': "Benutzerdefinierte Registertabelle", 'en': "Custom register table"}), members={
                    "device_address": Elem.INT(T({'de': "Geräteadresse.", 'en': "Device address."})),
                    "register_address_mode": Elem.INT(T({'de': "Gibt an, ob die konfigurierten Registerstartadressen im Webinterface als Adressen oder Registernummern angezeigt werden.", 'en': "Indicates whether the configured register start addresses are displayed in the web interface as addresses or register numbers."}), constants=[
                        Const(0, T({'de': "Startadressen werden als Registeraddressen angezeigt. Die erste Adresse ist 0.", 'en': "Start addresses are displayed as register addresses. The first address is 0."})),
                        Const(1, T({'de': "Startadressen werden als Registernummern angezeigt. Die erste Registernummer ist 1.", 'en': "Start addresses are displayed as register numbers. The first register number is 1."})),
                    ]),
                    "registers": Elem.ARRAY(T({'de': "Registertabelle", 'en': "Register table"}), members=
                        36 * [
                            Elem.OBJECT(T({'de': "Ein Register, dass gelesen werden soll", 'en': "A register to be read"}), members={
                                "rtype": Elem.INT(T({'de': "Registertyp", 'en': "Register type"}), constants=[
                                    Const(0, "Holding Register"),
                                    Const(1, "Input Register"),
                                ]),
                                "addr": Elem.INT(T({'de': "Startadresse des Registers.", 'en': "Start address of the register."})),
                                "vtype": Elem.INT(T({'de': "Wert-Typ", 'en': "Value type"}), constants=[
                                    Const(1, T({'de': "Ein Register, 16-Bit, Ganzzahl, vorzeichenlos", 'en': "One register, 16-bit, integer, unsigned"})),
                                    Const(9, T({'de': "Ein Register, 16-Bit, Ganzzahl, vorzeichenbehaftet", 'en': "One register, 16-bit, integer, signed"})),
                                    Const(2, T({'de': "Zwei Register, 32-Bit, Ganzzahl, vorzeichenlos, Big-Endian", 'en': "Two registers, 32-bit, integer, unsigned, big-endian"})),
                                    Const(34, T({'de': "Zwei Register, 32-Bit, Ganzzahl, vorzeichenlos, Little-Endian", 'en': "Two registers, 32-bit, integer, unsigned, little-endian"})),
                                    Const(10, T({'de': "Zwei Register, 32-Bit, Ganzzahl, vorzeichenbehaftet, Big-Endian", 'en': "Two registers, 32-bit, integer, signed, big-endian"})),
                                    Const(42, T({'de': "Zwei Register, 32-Bit, Ganzzahl, vorzeichenbehaftet, Little-Endian", 'en': "Two registers, 32-bit, integer, signed, little-endian"})),
                                    Const(26, T({'de': "Zwei Register, 32-Bit, Gleitkommazahl, Big-Endian", 'en': "Two registers, 32-bit, floating point, big-endian"})),
                                    Const(58, T({'de': "Zwei Register, 32-Bit, Gleitkommazahl, Little-Endian", 'en': "Two registers, 32-bit, floating point, little-endian"})),
                                    Const(4, T({'de': "Vier Register, 64-Bit, Ganzzahl, vorzeichenlos, Big-Endian", 'en': "Four registers, 64-bit, integer, unsigned, big-endian"})),
                                    Const(36, T({'de': "Vier Register, 64-Bit, Ganzzahl, vorzeichenlos, Little-Endian", 'en': "Four registers, 64-bit, integer, unsigned, little-endian"})),
                                    Const(12, T({'de': "Vier Register, 64-Bit, Ganzzahl, vorzeichenbehaftet, Big-Endian", 'en': "Four registers, 64-bit, integer, signed, big-endian"})),
                                    Const(44, T({'de': "Vier Register, 64-Bit, Ganzzahl, vorzeichenbehaftet, Little-Endian", 'en': "Four registers, 64-bit, integer, signed, little-endian"})),
                                    Const(28, T({'de': "Vier Register, 64-Bit, Gleitkommazahl, Big-Endian", 'en': "Four registers, 64-bit, floating point, big-endian"})),
                                    Const(60, T({'de': "Vier Register, 64-Bit, Gleitkommazahl, Little-Endian", 'en': "Four registers, 64-bit, floating point, little-endian"}))
                                ]),
                                "off": Elem.FLOAT(T({'de': "Offset, dass auf den gelesenen Wert addiert werden soll. Der Offset-Wert wird addiert, bevor der Skalierungsfaktor angewandt wird.", 'en': "Offset to be added to the read value. The offset value is added before the scaling factor is applied."})),
                                "scale": Elem.FLOAT(T({'de': "Skalierungsfaktor, mit dem der gelesene Wert multipliziert werden soll. Der Skalierungsfaktor wirkt auf den Wert, der durch die Addition des gelesenen Wertes mit dem Offset entstanden ist.", 'en': "Scaling factor by which the read value should be multiplied. The scaling factor acts on the value that results from adding the offset to the read value."})),
                                "id": Elem.INT(T({'de': "MeterValueID, die die Interpretation des gelesenen Werts angibt. [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)", 'en': "MeterValueID that indicates the interpretation of the read value. [List of all MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)"}))
                            })
                        ]
                    )
                }),
                2: Elem.OBJECT(T({'de': "Sungrow Hybrid-Wechselrichter (SH...)", 'en': "Sungrow hybrid inverter (SH...)"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"})),
                        Const(4, T({'de': "Last", 'en': "Load"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                }),
                3: Elem.OBJECT(T({'de': "Sungrow String-Wechselrichter (SG...)", 'en': "Sungrow string inverter (SG...)"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Last", 'en': "Load"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                }),
                4: Elem.OBJECT(T({'de': "Solarmax Max.Storage", 'en': "Solarmax Max.Storage"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                }),
                5: Elem.OBJECT(T({'de': "Victron Energy GX", 'en': "Victron Energy GX"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"})),
                        Const(4, T({'de': "Last", 'en': "Load"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 100.", 'en': "Device address. Typically 100."})),
                }),
                6: Elem.OBJECT(T({'de': "Deye Hybrid-Wechselrichter", 'en': "Deye hybrid inverter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"})),
                        Const(4, T({'de': "Last", 'en': "Load"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                }),
                7: Elem.OBJECT(T({'de': "AlphaESS Hybrid-Wechselrichter", 'en': "AlphaESS hybrid inverter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                }),
                8: Elem.OBJECT(T({'de': "Shelly Pro EM", 'en': "Shelly Pro EM"}), members={
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                    "monophase_channel": Elem.INT(T({'de': "Kanal, der gelesen werden soll.", 'en': "Channel to be read."}), constants=[
                        Const(0, T({'de': "Kein Kanal ausgewählt", 'en': "No channel selected"})),
                        Const(1, T({'de': "Kanal 1", 'en': "Channel 1"})),
                        Const(2, T({'de': "Kanal 2", 'en': "Channel 2"}))
                    ]),
                    "monophase_mapping": Elem.INT(T({'de': "Phase der die Messwerte zugeordnet werden.", 'en': "Phase to which the measurement values are assigned."}), constants=[
                        Const(0, T({'de': "Keine Phase ausgewählt", 'en': "No phase selected"})),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                9: Elem.OBJECT(T({'de': "Shelly Pro 3EM", 'en': "Shelly Pro 3EM"}), members={
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                    "device_profile": Elem.INT(T({'de': "Gibt an, ob eine oder alle drei Phasen gelesen werden sollen.", 'en': "Indicates whether one or all three phases should be read."}), constants=[
                        Const(0, T({'de': "Dreiphasig. `monophase_channel` und `monophase_mapping` werden ignoriert.", 'en': "Three-phase. `monophase_channel` and `monophase_mapping` are ignored."})),
                        Const(1, T({'de': "Einphasig", 'en': "Single-phase"}))
                    ]),
                    "monophase_channel": Elem.INT(T({'de': "Kanal, der gelesen werden soll.", 'en': "Channel to be read."}), constants=[
                        Const(0, T({'de': "Kein Kanal ausgewählt", 'en': "No channel selected"})),
                        Const(1, T({'de': "Kanal 1", 'en': "Channel 1"})),
                        Const(2, T({'de': "Kanal 2", 'en': "Channel 2"})),
                        Const(3, T({'de': "Kanal 3", 'en': "Channel 3"}))
                    ]),
                    "monophase_mapping": Elem.INT(T({'de': "Phase der die Messwerte zugeordnet werden.", 'en': "Phase to which the measurement values are assigned."}), constants=[
                        Const(0, T({'de': "Keine Phase ausgewählt", 'en': "No phase selected"})),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                10: Elem.OBJECT(T({'de': "GoodWe Hybrid-Wechselrichter", 'en': "GoodWe hybrid inverter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"})),
                        Const(4, T({'de': "Last", 'en': "Load"})),
                        Const(5, T({'de': "Backup-Last", 'en': "Backup load"})),
                        Const(6, T({'de': "Zähler", 'en': "Meter"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 247.", 'en': "Device address. Typically 247."})),
                }),

                11: Elem.OBJECT(T({'de': "Solax Hybrid-Wechselrichter", 'en': "Solax hybrid inverter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                }),
                12: Elem.OBJECT(T({'de': "Fronius GEN24 Plus", 'en': "Fronius GEN24 Plus"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter (wird nicht verwendet)", 'en': "Inverter (not used)"})),
                        Const(2, T({'de': "Netzanschluss (wird nicht verwendet)", 'en': "Grid connection (not used)"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                }),
                13: Elem.OBJECT(T({'de': "Hailei Hybrid-Wechselrichter", 'en': "Hailei hybrid inverter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 85.", 'en': "Device address. Typically 85."})),
                }),
                14: Elem.OBJECT(T({'de': "Fox ESS H3 Hybrid-Wechselrichter", 'en': "Fox ESS H3 hybrid inverter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter", 'en': "Inverter"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 247.", 'en': "Device address. Typically 247."})),
                }),

                **{15 + i: Elem.OBJECT(T({'de': f"Siemens {siemens_subtype} Stromzähler", 'en': f"Siemens {siemens_subtype} electricity meter"}), members={
                        "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                    }) for i, siemens_subtype in enumerate([
                        "PAC2200",
                        "PAC3120",
                        "PAC3200",
                        "PAC3220",
                        "PAC4200",
                        "PAC4220",
                        ])
                },

                21: Elem.OBJECT(T({'de': "Carlo Gavazzi EM24 DIN Stromzähler", 'en': "Carlo Gavazzi EM24 DIN electricity meter"}), members={"device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))}),
                22: Elem.OBJECT(T({'de': "Carlo Gavazzi EM24 E1 Stromzähler", 'en': "Carlo Gavazzi EM24 E1 electricity meter"}), members={"device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))}),

                23: Elem.OBJECT(T({'de': "Carlo Gavazzi EM100 Stromzähler", 'en': "Carlo Gavazzi EM100 electricity meter"}), members={
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                    "phase": Elem.INT(T({'de': "Phase der die Messwerte zugeordnet werden.", 'en': "Phase to which the measurement values are assigned."}), constants=[
                        Const(0, T({'de': "Keine Phase ausgewählt", 'en': "No phase selected"})),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                24: Elem.OBJECT(T({'de': "Carlo Gavazzi ET100 Stromzähler", 'en': "Carlo Gavazzi ET100 electricity meter"}), members={
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                    "phase": Elem.INT(T({'de': "Phase der die Messwerte zugeordnet werden.", 'en': "Phase to which the measurement values are assigned."}), constants=[
                        Const(0, T({'de': "Keine Phase ausgewählt", 'en': "No phase selected"})),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),

                25: Elem.OBJECT(T({'de': "Carlo Gavazzi EM210 Stromzähler", 'en': "Carlo Gavazzi EM210 electricity meter"}), members={"device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))}),

                26: Elem.OBJECT(T({'de': "Carlo Gavazzi EM270 Stromzähler", 'en': "Carlo Gavazzi EM270 electricity meter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Zähler", 'en': "Meter"})),
                        Const(2, T({'de': "Stromwandler 1", 'en': "Current transformer 1"})),
                        Const(3, T({'de': "Stromwandler 2", 'en': "Current transformer 2"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))
                }),
                27: Elem.OBJECT(T({'de': "Carlo Gavazzi EM280 Stromzähler", 'en': "Carlo Gavazzi EM280 electricity meter"}), members={
                    "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Zähler", 'en': "Meter"})),
                        Const(2, T({'de': "Stromwandler 1", 'en': "Current transformer 1"})),
                        Const(3, T({'de': "Stromwandler 2", 'en': "Current transformer 2"}))
                    ]),
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))
                }),

                28: Elem.OBJECT(T({'de': "Carlo Gavazzi EM300 Stromzähler", 'en': "Carlo Gavazzi EM300 electricity meter"}), members={"device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))}),
                29: Elem.OBJECT(T({'de': "Carlo Gavazzi ET300 Stromzähler", 'en': "Carlo Gavazzi ET300 electricity meter"}), members={"device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))}),
                30: Elem.OBJECT(T({'de': "Carlo Gavazzi EM510 Stromzähler", 'en': "Carlo Gavazzi EM510 electricity meter"}), members={
                    "device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."})),
                    "phase": Elem.INT(T({'de': "Phase der die Messwerte zugeordnet werden.", 'en': "Phase to which the measurement values are assigned."}), constants=[
                        Const(0, T({'de': "Keine Phase ausgewählt", 'en': "No phase selected"})),
                        Const(1, "L1"),
                        Const(2, "L2"),
                        Const(3, "L3")
                    ]),
                }),
                31: Elem.OBJECT(T({'de': "Carlo Gavazzi EM530 Stromzähler", 'en': "Carlo Gavazzi EM530 electricity meter"}), members={"device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))}),
                32: Elem.OBJECT(T({'de': "Carlo Gavazzi EM540 Stromzähler", 'en': "Carlo Gavazzi EM540 electricity meter"}), members={"device_address": Elem.INT(T({'de': "Geräteadresse. Typischerweise 1.", 'en': "Device address. Typically 1."}))})
            })
        }),
        7: Elem.OBJECT(T({'de': "SMA Speedwire-Stromzähler.", 'en': "SMA Speedwire electricity meter."}), members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Stromzählers", 'en': "Display name of the electricity meter"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
        }),
        8: Elem.OBJECT(T({'de': "RCT Power Wechselrichter", 'en': "RCT Power inverter"}), members={
            "display_name": Elem.STRING(T({'de': "Anzeigename des Wechselrichters", 'en': "Display name of the inverter"})),
            "location": Elem.INT(T({'de': "Messort", 'en': "Measurement location"}), constants=LOCATION_CONSTANTS),
            "host": Elem.STRING(T({'de': "Hostname oder IP-Adresse des Wechselrichters", 'en': "Hostname or IP address of the inverter"})),
            "port": Elem.INT(T({'de': "Port des Wechselrichters. Typischerweise 8899", 'en': "Port of the inverter. Typically 8899"})),
            "virtual_meter": Elem.INT(T({'de': "Virtueller Zähler. Gibt an welcher Teil der Registertabelle gelesen wird.", 'en': "Virtual meter. Indicates which part of the register table is read."}), constants=[
                        Const(0, T({'de': "Kein virtueller Zähler ausgewählt", 'en': "No virtual meter selected"})),
                        Const(1, T({'de': "Wechselrichter (wird nicht verwendet)", 'en': "Inverter (not used)"})),
                        Const(2, T({'de': "Netzanschluss", 'en': "Grid connection"})),
                        Const(3, T({'de': "Speicher", 'en': "Storage"}))
                    ]),
        })
    })),

    Func("X/state", FuncType.STATE, Elem.HIDDEN_UNION(T({'de': "Der Zustand des X. Stromzählers. Der Inhalt dieser API hängt vom Typ des Stromzählers ab, der in {{{ref:meters/X/config}}} konfiguriert wurde.", 'en': "The state of the X. electricity meter. The content of this API depends on the type of electricity meter configured in {{{ref:meters/X/config}}}."}), tab_id="metersXConfig", get_tag_fn=meters_x_get_tag_fn, members={
            0: Elem.NULL(T({'de': "Kein Stromzähler konfiguriert.", 'en': "No electricity meter configured."})),
            1: Elem.OBJECT(T({'de': "Zustand des internen Stromzählers", 'en': "State of the internal electricity meter"}), members={
                "type": Elem.INT(T({'de': "Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jedem Gerät unterstützt!", 'en': "Type of the installed electricity meter. Not every meter is supported by every device!"}), constants=[
                    Const(0, T({'de': "Kein Stromzähler verfügbar", 'en': "No electricity meter available"})),
                    Const(1, "Eastron SDM72"),
                    Const(2, "Eastron SDM630"),
                    Const(3, "Eastron SDM72V2")
                ])
            }),
            **{x: Elem.OBJECT(T({'de': "Zustand des internen Stromzählers", 'en': "State of the internal electricity meter"}), members={
                "type": Elem.INT(T({'de': "Typ des verbauten Stromzählers. Nicht jeder Stromzähler wird von jedem Gerät unterstützt!", 'en': "Type of the installed electricity meter. Not every meter is supported by every device!"}), constants=[
                    Const(0, T({'de': "Kein Stromzähler verfügbar", 'en': "No electricity meter available"})),
                    Const(2, "Eastron SDM630"),
                    Const(3, "Eastron SDM72V2"),
                    Const(4, "Eastron SDM72CTM"),
                    Const(5, "Eastron SDM630MCT"),
                    Const(6, "Eltako DSZ15DZMOD"),
                    Const(7, "YTL DEM4A"),
                ]),
            }) for x in [2, 3]},
            4: Elem.NULL(T({'de': "Zustand des API-Stromzählers. Im Moment leer.", 'en': "State of the API electricity meter. Currently empty."})),
            5: Elem.NULL(T({'de': "Zustand des SunSpec-Stromzählers. Im Moment leer.", 'en': "State of the SunSpec electricity meter. Currently empty."}))
        })
    ),

    Func("X/errors", FuncType.STATE, Elem.HIDDEN_UNION(T({'de': "Fehlerzähler der Kommunikation mit dem Stromzähler. Der Inhalt dieser API hängt vom Typ des Stromzählers ab, der in {{{ref:meters/X/config}}} konfiguriert wurde.", 'en': "Error counters for communication with the electricity meter. The content of this API depends on the type of electricity meter configured in {{{ref:meters/X/config}}}."}), tab_id="metersXConfig", get_tag_fn=meters_x_get_tag_fn, members={
             0: Elem.NULL(T({'de': "Kein Stromzähler konfiguriert.", 'en': "No electricity meter configured."})),
             1: Elem.OBJECT(T({'de': "Fehlerzähler des internen Stromzählers", 'en': "Error counters of the internal electricity meter"}), members={
                "meter": Elem.INT(T({'de': "Kommunikationsfehler zwischen RS485 Bricklet und Stromzähler.", 'en': "Communication errors between RS485 Bricklet and electricity meter."})),
                "bricklet": Elem.INT(T({'de': "Kommunikationsfehler zwischen ESP Brick und RS485 Bricklet.", 'en': "Communication errors between ESP Brick and RS485 Bricklet."})),
                "bricklet_reset": Elem.INT(T({'de': "Unerwartete Resets des RS485 Bricklets.", 'en': "Unexpected resets of the RS485 Bricklet."}))
             }),
             **{x: Elem.OBJECT(T({'de': "Fehlerzähler des internen Stromzählers", 'en': "Error counters of the internal electricity meter"}), members={
                "local_timeout": Elem.INT(T({'de': "Lokaler Timeout", 'en': "Local Timeout"})),
                "global_timeout": Elem.INT(T({'de': "Globaler Timeout", 'en': "Global Timeout"})),
                "illegal_function": Elem.INT(T({'de': "Illegale Funktion", 'en': "Illegal Function"})),
                "illegal_data_access": Elem.INT(T({'de': "Illegaler Datenzugriff", 'en': "Illegal Data Access"})),
                "illegal_data_value": Elem.INT(T({'de': "Illegaler Datenwert", 'en': "Illegal Data Value"})),
                "slave_device_failure": Elem.INT(T({'de': "Slave-Gerätefehler", 'en': "Slave Device Failure"})),
            }) for x in [2, 3]},
            4: Elem.NULL(T({'de': "Fehlerzähler des API-Stromzählers. Im Moment leer.", 'en': "Error counters of the API electricity meter. Currently empty."})),
            5: Elem.NULL(T({'de': "Fehlerzähler des SunSpec-Stromzählers. Im Moment leer.", 'en': "Error counters of the SunSpec electricity meter. Currently empty."})),
        })
    ),

    Func("X/reset", FuncType.COMMAND, Elem.NULL(T({'de': "Setzt alle zurücksetzbaren (Alle Werte deren `kind`-Eintrag `resettable` ist: [Liste aller MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)) Zählerwerte des X. Stromzählers zurück.", 'en': "Resets all resettable (all values whose `kind` entry is `resettable`: [List of all MeterValueIDs](https://github.com/Tinkerforge/esp32-firmware/blob/master/software/src/modules/meters/meter_value_id.csv)) meter values of the X. electricity meter."})), command_is_action=True),
    Func("X/last_reset", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zeitpunkt des letzten Zähler-Resets (siehe {{{ref:meters/X/reset}}}) als Unix-Timestamp. 0 falls kein Reset durchgeführt wurde. Falls zum Zeitpunkt des letzten Resets keine Zeitsynchronisierung vorlag, ist dieser Wert stattdessen ein Zähler, der angibt, wie oft ein Reset durchgeführt wurde.", 'en': "The time of the last meter reset (see {{{ref:meters/X/reset}}}) as Unix timestamp. 0 if no reset was performed. If no time synchronization was available at the time of the last reset, this value is instead a counter indicating how many times a reset was performed."}), members={
            "last_reset": Elem.INT(T({'de': "Unix-Timestamp des Zeitpunkts des letzten Zähler-Resets.", 'en': "Unix timestamp of the time of the last meter reset."}), unit=Units.s)
        })
    ),


    Func("history", FuncType.HTTP_ONLY, Elem.OBJECT(T({'de': "Eine 48-Stunden-Historie der Ladeleistung in Watt. Bisher fehlende Werte werden durch null angezeigt. Die Historie wird von hinten nach vorne gefüllt, sodass null-Werte nur geschlossen am Anfang des Arrays auftreten, falls der ESP innerhalb der letzten 48 Stunden neugestartet wurde. Es werden bis zu 720 Werte ausgegeben, das entspricht einem Messwert alle 4 Minuten. Diese Messwerte sind der jeweilige Durchschnitt dieser 4 Minuten.", 'en': "A 48-hour history of charging power in watts. Missing values are indicated by null. The history is filled from back to front, so null values only occur consecutively at the beginning of the array if the ESP was restarted within the last 48 hours. Up to 720 values are output, which corresponds to one measurement value every 4 minutes. These measurement values are the respective average of these 4 minutes."}), members={
        "offset": Elem.INT(T({'de': "Das Alter des zuletzt gemessenen Wertes.", 'en': "The age of the last measured value."}), unit=Units.ms),
        "samples": Elem.ARRAY(T({'de': "Die gemessenen Werte aller Stromzähler.", 'en': "The measured values of all electricity meters."}), members=
              (2 * [Elem.ARRAY(T({'de': "Die gemessenen Werte des jeweiligen Stromzählers. Null falls ein Zähler nicht konfiguriert ist.", 'en': "The measured values of the respective electricity meter. Null if a meter is not configured."}), unit=Units.W, member_type=EType.INT, version=Version.WARP1)])
            + (5 * [Elem.ARRAY(T({'de': "Die gemessenen Werte des jeweiligen Stromzählers. Null falls ein Zähler nicht konfiguriert ist.", 'en': "The measured values of the respective electricity meter. Null if a meter is not configured."}), unit=Units.W, member_type=EType.INT, version=Version.WARP2 | Version.WARP3)])
            + (7 * [Elem.ARRAY(T({'de': "Die gemessenen Werte des jeweiligen Stromzählers. Null falls ein Zähler nicht konfiguriert ist.", 'en': "The measured values of the respective electricity meter. Null if a meter is not configured."}), unit=Units.W, member_type=EType.INT, version=Version.WEMX)])
        )
    })),

    Func("live", FuncType.HTTP_ONLY, Elem.OBJECT(T({'de': "Die letzten Ladeleistungs-Messwerte. Auf Basis dieser Werte werden die Durchschnittswerte für {{{ref:meters/history}}} generiert. Es werden bis zu 720 Werte ausgegeben, das entspricht 6 Minuten bei einem Messwert alle 500 Millisekunden.", 'en': "The last charging power measurement values. Based on these values, the average values for {{{ref:meters/history}}} are generated. Up to 720 values are output, which corresponds to 6 minutes with one measurement value every 500 milliseconds."}), members={
        "offset": Elem.INT(T({'de': "Das Alter des zuletzt gemessenen Wertes.", 'en': "The age of the last measured value."}), unit=Units.ms),
        "samples_per_second": Elem.FLOAT(T({'de': "Die Anzahl der gemessenen Werte pro Sekunde.", 'en': "The number of measured values per second."}), unit=Units.Hz),
        "samples": Elem.ARRAY(T({'de': "Die gemessenen Werte aller Stromzähler.", 'en': "The measured values of all electricity meters."}), members=
             (2 * [Elem.ARRAY(T({'de': "Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", 'en': "The measured values. Depending on the length of the array and the samples_per_second value, it can be determined how far back in time the measurement values reach."}), unit=Units.W, member_type=EType.INT, version=Version.WARP1)]
            + 5 * [Elem.ARRAY(T({'de': "Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", 'en': "The measured values. Depending on the length of the array and the samples_per_second value, it can be determined how far back in time the measurement values reach."}), unit=Units.W, member_type=EType.INT, version=Version.WARP2 | Version.WARP3)]
            + 7 * [Elem.ARRAY(T({'de': "Die gemessenen Werte. Abhängig von der Länge des Arrays und dem samples_per_second-Wert kann ermittelt werden, wie weit in die Vergangenheit die Messwerte reichen.", 'en': "The measured values. Depending on the length of the array and the samples_per_second value, it can be determined how far back in time the measurement values reach."}), unit=Units.W, member_type=EType.INT, version=Version.WEMX)])
        )
    }))
])
