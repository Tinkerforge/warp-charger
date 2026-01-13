from api_doc_common import *

misc = Module("misc", T({'de': "Sonstiges", 'en': "Miscellaneous"}), "", "", Version.ANY, [
    Func("reboot", FuncType.COMMAND, Elem.NULL(T({'de': "Startet den ESP neu, um beispielsweise Konfigurationsänderungen anzuwenden.", 'en': "Restarts the ESP to apply configuration changes, for example."})), command_is_action=True),

    Func("debug_report", FuncType.HTTP_ONLY, Elem.OPAQUE(T({'de': "Generiert einen Debug-Report. Dieser besteht aus allen Zuständen und Konfigurationen, sowie den letzten empfangenen Kommandos und Konfigurationsupdates. Passwörter werden, genau wie bei Konfigurationsabfragen, zensiert.", 'en': "Generates a debug report. This consists of all states and configurations, as well as the last received commands and configuration updates. Passwords are censored, just like in configuration queries."}))),

    Func("force_reboot", FuncType.HTTP_ONLY, Elem.OPAQUE(T({'de': "Erzwingt einen sofortigen Neustart des ESPs. Nützlich, falls {{{ref:reboot}}} aus irgendwelchen Gründen hängt.", 'en': "Forces an immediate restart of the ESP. Useful if {{{ref:reboot}}} hangs for any reason."}))),

    Func("flash_firmware", FuncType.HTTP_ONLY, Elem.OPAQUE(T({'de': "Nimmt ein Firmware-Update als POST entgegen, dass dann geflasht wird.", 'en': "Accepts a firmware update as POST which is then flashed."}))),

    Func("config_reset", FuncType.COMMAND, Elem.OBJECT(T({'de': "Setzt alle Einstellungen zurück aber behält aufgezeichnete Ladevorgänge und die Nutzernamenhistorie. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", 'en': "Resets all settings but keeps recorded charging sessions and username history. <strong>Cannot be undone!</strong> A restart will be performed automatically afterwards."}), members={
        "do_i_know_what_i_am_doing": Elem.BOOL(T({'de': "Gibt an ob der Löschvorgang ausgeführt werden soll", 'en': "Indicates whether the deletion process should be executed"}), constants=[
                Const(True, T({'de': "Alle Einstellungen löschen", 'en': "Delete all settings"})),
                Const(False, T({'de': "Keine Aktion durchführen", 'en': "Perform no action"})),
            ]
        )
    })),

    Func("factory_reset", FuncType.COMMAND, Elem.OBJECT(T({'de': "Setzt alle Einstellungen zurück und löscht alle aufgezeichneten Ladevorgänge. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", 'en': "Resets all settings and deletes all recorded charging sessions. <strong>Cannot be undone!</strong> A restart will be performed automatically afterwards."}), members={
        "do_i_know_what_i_am_doing": Elem.BOOL(T({'de': "Gibt an ob der Löschvorgang ausgeführt werden soll", 'en': "Indicates whether the deletion process should be executed"}), constants=[
                Const(True, T({'de': "Alle Einstellungen, aufgezeichneten Ladevorgänge und die Nutzernamenhistorie löschen", 'en': "Delete all settings, recorded charging sessions, and username history"})),
                Const(False, T({'de': "Keine Aktion durchführen", 'en': "Perform no action"})),
            ]
        )
    })),
], hide_prefix=True)
