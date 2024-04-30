from api_doc_common import *

misc = Module("misc", "Sonstiges", "", "", Version.ANY, [
    Func("reboot", FuncType.COMMAND, Elem.NULL("Startet den ESP neu, um beispielsweise Konfigurationsänderungen anzuwenden."), command_is_action=True),

    Func("debug_report", FuncType.HTTP_ONLY, Elem.OPAQUE("Generiert einen Debug-Report. Dieser besteht aus allen Zuständen und Konfigurationen, sowie den letzten empfangenen Kommandos und Konfigurationsupdates. Passwörter werden, genau wie bei Konfigurationsabfragen, zensiert.")),

    Func("force_reboot", FuncType.HTTP_ONLY, Elem.OPAQUE("Erzwingt einen sofortigen Neustart des ESPs. Nützlich, falls {{{ref:reboot}}} aus irgendwelchen Gründen hängt.")),

    Func("flash_firmware", FuncType.HTTP_ONLY, Elem.OPAQUE("Nimmt ein Firmware-Update als POST entgegen, dass dann geflasht wird.")),

    Func("config_reset", FuncType.COMMAND, Elem.OBJECT("Setzt alle Einstellungen zurück aber behält aufgezeichnete Ladevorgänge und die Nutzernamenhistorie. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", members={
        "do_i_know_what_i_am_doing": Elem.BOOL("Gibt an ob der Löschvorgang ausgeführt werden soll", constants=[
                Const(True, "Alle Einstellungen löschen"),
                Const(False, "Keine Aktion durchführen"),
            ]
        )
    })),

    Func("factory_reset", FuncType.COMMAND, Elem.OBJECT("Setzt alle Einstellungen zurück und löscht alle aufgezeichneten Ladevorgänge. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", members={
        "do_i_know_what_i_am_doing": Elem.BOOL("Gibt an ob der Löschvorgang ausgeführt werden soll", constants=[
                Const(True, "Alle Einstellungen, aufgezeichneten Ladevorgänge und die Nutzernamenhistorie löschen"),
                Const(False, "Keine Aktion durchführen"),
            ]
        )
    })),
], hide_prefix=True)
