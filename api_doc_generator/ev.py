from api_doc_common import *

ev = Module("ev", T({'de': "Fahrzeuge", 'en': "Vehicles"}), "",
    T({'de': """Über das `ev`-Modul können Fahrzeug-Profile konfiguriert werden.
    Fahrzeuge werden anhand ihrer MAC-Adresse identifiziert, die sie z.B. beim Verbindungsaufbau
    per ISO 15118 (Autocharge) übermitteln oder die per {{{ref:ev/inject_ev}}} über die API vorgetäuscht werden kann.
    Anhand des zugeordneten Profils können Ladevorgänge einem Benutzer zugeordnet (Autocharge)
    und der Ladestand (SoC) des Fahrzeugs über Batteriekapazität und Ladeeffizienz geschätzt werden.
    """, 'en': """The `ev` module allows configuring vehicle profiles.
    Vehicles are identified by their MAC address, which they transmit e.g. when connecting
    via ISO 15118 (Autocharge) or which can be spoofed via the API using {{{ref:ev/inject_ev}}}.
    Based on the matched profile, charging sessions can be assigned to a user (Autocharge)
    and the state of charge (SoC) of the vehicle can be estimated from battery capacity and charging efficiency.
    """}),
    Version.WARP4, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der Zustand des aktuell verbundenen Fahrzeugs.", 'en': "The state of the currently connected vehicle."}), members={
        "active_ev_index": Elem.INT(T({'de': "Index des zugeordneten Fahrzeug-Profils in {{{ref:ev/config}}}. -1 falls kein Fahrzeug verbunden ist oder das Fahrzeug keinem Profil zugeordnet werden konnte.", 'en': "Index of the matched vehicle profile in {{{ref:ev/config}}}. -1 if no vehicle is connected or the vehicle could not be matched to a profile."})),
        "name": Elem.STRING(T({'de': "Name des zugeordneten Fahrzeug-Profils. Leer, falls kein Fahrzeug verbunden ist oder das Fahrzeug keinem Profil zugeordnet werden konnte.", 'en': "Name of the matched vehicle profile. Empty if no vehicle is connected or the vehicle could not be matched to a profile."})),
        "mac": Elem.STRING(T({'de': "MAC-Adresse des verbundenen Fahrzeugs im Format `AA:BB:CC:DD:EE:FF`. Leer, falls kein Fahrzeug verbunden ist.", 'en': "MAC address of the connected vehicle in the format `AA:BB:CC:DD:EE:FF`. Empty if no vehicle is connected."}), censored_in_debug_report=True),
        "soc": Elem.FLOAT(T({'de': "Aktueller Ladestand (SoC) des Fahrzeugs in Prozent. Wird entweder vom Fahrzeug übermittelt (ISO 15118-20), über {{{ref:ev/inject_soc}}} gesetzt oder anhand der geladenen Energie, der Batteriekapazität und der Ladeeffizienz geschätzt. null, falls unbekannt.", 'en': "Current state of charge (SoC) of the vehicle in percent. Either transmitted by the vehicle (ISO 15118-20), set via {{{ref:ev/inject_soc}}} or estimated from the charged energy, the battery capacity and the charging efficiency. null if unknown."}), unit=Units.percent),
        "capacity": Elem.FLOAT(T({'de': "Batteriekapazität des verbundenen Fahrzeugs in kWh. Wird dem zugeordneten Fahrzeug-Profil entnommen oder vom Fahrzeug übermittelt (ISO 15118-20). null, falls kein Fahrzeug verbunden ist.", 'en': "Battery capacity of the connected vehicle in kWh. Taken from the matched vehicle profile or transmitted by the vehicle (ISO 15118-20). null if no vehicle is connected."}), unit=Units.kWh),
        "charging_efficiency": Elem.FLOAT(T({'de': "Ladeeffizienz des verbundenen Fahrzeugs: Verhältnis von gespeicherter zu verbrauchter Energie. Wird dem zugeordneten Fahrzeug-Profil entnommen. 0,92 falls kein Profil zugeordnet ist.", 'en': "Charging efficiency of the connected vehicle: ratio of stored to consumed energy. Taken from the matched vehicle profile. 0.92 if no profile is matched."})),
    })),

    Func("seen_macs", FuncType.STATE, Elem.ARRAY(T({'de': "Die MAC-Adressen der zuletzt verbundenen Fahrzeuge (maximal 8). Hilfreich, um die MAC-Adresse eines Fahrzeugs zu ermitteln, das in {{{ref:ev/config}}} konfiguriert werden soll.", 'en': "The MAC addresses of the most recently connected vehicles (up to 8). Helpful for determining the MAC address of a vehicle to be configured in {{{ref:ev/config}}}."}), is_var_length_array=True, members=[
        Elem.OBJECT(T({'de': "Eine gesehene MAC-Adresse", 'en': "A seen MAC address"}), members={
            "mac": Elem.STRING(T({'de': "MAC-Adresse des Fahrzeugs im Format `AA:BB:CC:DD:EE:FF`.", 'en': "MAC address of the vehicle in the format `AA:BB:CC:DD:EE:FF`."}), censored_in_debug_report=True),
            "seen_at": Elem.INT(T({'de': "Zeitpunkt, zu dem die MAC-Adresse zuletzt gesehen wurde, in Millisekunden seit Systemstart.", 'en': "Time at which the MAC address was last seen, in milliseconds since boot."}), unit=Units.ms),
        })
    ])),

    Func("inject_soc", FuncType.COMMAND, Elem.OBJECT(T({'de': "Setzt den Ladestand (SoC) des aktuell verbundenen Fahrzeugs über die API. Ausgehend von diesem Wert wird der Ladestand anhand der geladenen Energie, der Batteriekapazität und der Ladeeffizienz weiter geschätzt.", 'en': "Sets the state of charge (SoC) of the currently connected vehicle via the API. Starting from this value, the SoC is further estimated from the charged energy, the battery capacity and the charging efficiency."}), members={
        "soc": Elem.FLOAT(T({'de': "Ladestand in Prozent. Muss zwischen 0 und 100 liegen.", 'en': "State of charge in percent. Must be between 0 and 100."}), unit=Units.percent),
    }), command_is_action=True),

    Func("inject_ev", FuncType.COMMAND, Elem.OBJECT(T({'de': "Täuscht vor, dass sich ein Fahrzeug mit der übergebenen MAC-Adresse verbunden hat. Hiermit kann über die API ein Fahrzeug identifiziert werden, das seine MAC-Adresse nicht selbst (per ISO 15118) übermittelt. Falls die MAC-Adresse einem Fahrzeug-Profil aus {{{ref:ev/config}}} zugeordnet werden kann, werden dessen Einstellungen übernommen und (falls Autocharge aktiv ist) der Ladevorgang dem konfigurierten Benutzer zugeordnet.", 'en': "Pretends that a vehicle with the given MAC address has connected. This allows identifying a vehicle via the API that does not transmit its MAC address itself (via ISO 15118). If the MAC address can be matched to a vehicle profile from {{{ref:ev/config}}}, its settings are applied and (if Autocharge is active) the charging session is assigned to the configured user."}), members={
        "mac": Elem.STRING(T({'de': "MAC-Adresse des Fahrzeugs im Format `AA:BB:CC:DD:EE:FF`.", 'en': "MAC address of the vehicle in the format `AA:BB:CC:DD:EE:FF`."}), censored_in_debug_report=True),
    }), command_is_action=True),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die konfigurierten Fahrzeug-Profile.", 'en': "The configured vehicle profiles."}), members={
        "evs": Elem.ARRAY(T({'de': "Liste der Fahrzeug-Profile (maximal 16).", 'en': "List of vehicle profiles (up to 16)."}), is_var_length_array=True, members=[
            Elem.OBJECT(T({'de': "Ein Fahrzeug-Profil", 'en': "A vehicle profile"}), members={
                "name": Elem.STRING(T({'de': "Name zur Identifikation dieses Fahrzeugs. Maximal 16 Zeichen.", 'en': "Name to identify this vehicle. Up to 16 characters."})),
                "mac": Elem.STRING(T({'de': "MAC-Adresse des Fahrzeugs im Format `AA:BB:CC:DD:EE:FF`. Falls das Fahrzeug einen Teil seiner Adresse zwischen Ladevorgängen ändert (z.B. VW-ID-Modelle), können die wechselnden Bytes mit `xx` als Platzhalter markiert werden, z.B. `AA:BB:CC:xx:xx:xx`.", 'en': "MAC address of the vehicle in the format `AA:BB:CC:DD:EE:FF`. If the vehicle changes part of its address between charging sessions (e.g. VW ID models), the changing bytes can be marked with `xx` as wildcard, e.g. `AA:BB:CC:xx:xx:xx`."}), censored_in_debug_report=True),
                "capacity": Elem.FLOAT(T({'de': "Batteriekapazität des Fahrzeugs in kWh. Wird zur Schätzung des Ladestands verwendet. 0, falls unbekannt (dann werden 60 kWh angenommen).", 'en': "Battery capacity of the vehicle in kWh. Used to estimate the state of charge. 0 if unknown (then 60 kWh are assumed)."}), unit=Units.kWh),
                "charging_efficiency": Elem.FLOAT(T({'de': "Ladeeffizienz des Fahrzeugs: Verhältnis von gespeicherter zu verbrauchter Energie. Wird zur Schätzung des Ladestands verwendet. Typischerweise 0,92.", 'en': "Charging efficiency of the vehicle: ratio of stored to consumed energy. Used to estimate the state of charge. Typically 0.92."})),
                "user_id": Elem.INT(T({'de': "ID des Benutzers, dem dieses Fahrzeug zugeordnet ist, oder 0 falls es keinem Benutzer zugeordnet ist. Wird das Fahrzeug erkannt und ist Autocharge aktiv, wird der Ladevorgang diesem Benutzer zugeordnet.", 'en': "ID of the user this vehicle is assigned to, or 0 if it is not assigned to any user. If the vehicle is detected and Autocharge is active, the charging session is assigned to this user."})),
            })
        ]),
    })),
])
