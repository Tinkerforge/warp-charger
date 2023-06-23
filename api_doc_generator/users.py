from api_doc_common import *

users = Module("users", "Benutzerverwaltung", "", Version.WARP1 | Version.WARP2, [
    Func("config", FuncType.STATE, Elem.OBJECT("Die Benutzerkonfiguration. Kann über die nachfolgenden Kommandos modifiziert werden.", members={
            "users": Elem.ARRAY("Die Benutzer", members=[
                * 17 * [Elem.OBJECT("Ein Benutzer", members={
                    "id": Elem.INT("ID des Benutzers (1-255)"),
                    "roles": Elem.INT("Berechtigungen des Benutzers. Wird noch nicht verwendet."),
                    "current": Elem.INT("Diesem Benutzer erlaubter Ladestrom 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 um diesem Nutzer das Laden zu verbieten", unit=Units.mA),
                    "display_name": Elem.STRING("Anzeigename des Benutzers. Wird auch im Ladetracker verwendet."),
                    "username": Elem.STRING("Nutzername zum Anmelden im Webinterface und der HTTP-API."),
                    "digest_hash": Elem.STRING("HTTP-Digest-Hash. Wird als leerer String zurückgegeben, falls die Anmeldung für diesen Nutzer deaktiviert ist.", censored=True)
                })
                ]]),
            "next_user_id": Elem.INT("ID des nächsten anzulegenden Nutzers."),
            "http_auth_enabled": Elem.BOOL("Gibt an ob zur Verwendung von Webinterface und HTTP-API Zugangsdaten nötig sein sollen.", constants=[
                Const(True, "Falls Zugangsdaten verlangt werden sollen."),
                Const(False, "Wenn nicht.")
            ]),
        })
    ),

    Func("add", FuncType.COMMAND, Elem.OBJECT("Fügt einen neuen Benutzer hinzu.", members={
        "id": Elem.INT("ID des anzulegenden Nutzers. Muss dem aktuellen Wert von next_user_id aus {{{ref:users/config}}} entsprechen."),
        "roles": Elem.INT("Berechtigungen des Benutzers. Wird noch nicht verwendet."),
        "current": Elem.INT("Diesem Benutzer erlaubter Ladestrom 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 um diesem Nutzer das Laden zu verbieten", unit=Units.mA),
        "display_name": Elem.STRING("Anzeigename des Benutzers. Wird auch im Ladetracker verwendet."),
        "username": Elem.STRING("Nutzername zum Anmelden im Webinterface und der HTTP-API."),
        "digest_hash": Elem.STRING("HTTP-Digest-Hash des anzulegenden Nutzers. Ein leerer String verbietet das Anmelden im Webinterface.")
    }), command_is_action=True),

    Func("remove", FuncType.COMMAND, Elem.OBJECT("Löscht einen Benutzer.", members={
        "id": Elem.INT("ID des zu löschenden Nutzers")
    }), command_is_action=True),

    Func("modify", FuncType.COMMAND, Elem.OBJECT("Modifiziert einen Benutzer.", members={
        "id": Elem.INT("ID des zu modifizierenden Nutzers."),
        "roles": Elem.INT("Berechtigungen des Benutzers. Wird noch nicht verwendet."),
        "current": Elem.INT("Diesem Benutzer erlaubter Ladestrom 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 um diesem Nutzer das Laden zu verbieten", unit=Units.mA),
        "display_name": Elem.STRING("Anzeigename des Benutzers. Wird auch im Ladetracker verwendet."),
        "username": Elem.STRING("Nutzername zum Anmelden im Webinterface und der HTTP-API."),
        "digest_hash": Elem.STRING("HTTP-Digest-Hash des Nutzers. Ein leerer String verbietet das Anmelden im Webinterface.")
    }), command_is_action=True),

    Func("http_auth_update", FuncType.COMMAND, Elem.OBJECT("Schreibt http_auth_enabled aus {{{ref:users/config}}}.", members={
        "enabled": Elem.BOOL("Legt fest ob zur Verwendung von Webinterface und HTTP-API Zugangsdaten nötig sein sollen.", constants=[
            Const(True, "Falls Zugangsdaten verlangt werden sollen."),
            Const(False, "Wenn nicht.")
        ]),
    }), command_is_action=True),

    Func("all_usernames", FuncType.HTTP_ONLY, Elem.OPAQUE("Für das Ladetracking werden die Anzeigenamen gelöschter Benutzer separat im Flash gespeichert. Diese Funktion gibt alle Anzeigenamen, die möglicherweise in den getrackten Ladungen vorkommen in einem Binärformat aus."))
])
