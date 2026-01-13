from api_doc_common import *

def user(version):
    return [Elem.OBJECT(T({'de': "Ein Benutzer", 'en': "A user"}), version=version, members={
        "id": Elem.INT(T({'de': "ID des Benutzers (1-255)", 'en': "ID of the user (1-255)"})),
        "roles": Elem.INT(T({'de': "Berechtigungen des Benutzers. Wird noch nicht verwendet.", 'en': "Permissions of the user. Not yet used."})),
        "current": Elem.INT(T({'de': "Diesem Benutzer erlaubter Ladestrom 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 um diesem Nutzer das Laden zu verbieten", 'en': "Charging current allowed for this user 6000 (=6 Ampere) to 32000 (=32 Ampere) or 0 to prohibit charging for this user"}), unit=Units.mA),
        "display_name": Elem.STRING(T({'de': "Anzeigename des Benutzers. Wird auch im Ladetracker verwendet.", 'en': "Display name of the user. Also used in the charge tracker."})),
        "username": Elem.STRING(T({'de': "Nutzername zum Anmelden im Webinterface und der HTTP-API.", 'en': "Username for logging into the web interface and HTTP API."})),
        "digest_hash": Elem.STRING(T({'de': "HTTP-Digest-Hash. Wird als leerer String zurückgegeben, falls die Anmeldung für diesen Nutzer deaktiviert ist. Wird als null zurückgegeben wenn die Anmeldung für diesen Nutzer aktiviert ist.", 'en': "HTTP Digest hash. Returned as empty string if login is disabled for this user. Returned as null if login is enabled for this user."}), censored=True)
    })
    ]

users = Module("users", T({'de': "Benutzerverwaltung", 'en': "User Management"}), "", "", Version.WARPX, [
    Func("config", FuncType.STATE, Elem.OBJECT(T({'de': "Die Benutzerkonfiguration. Kann mit {{{ref:users/add}}}, {{{ref:users/modify}}}, {{{ref:users/remove}}} und {{{ref:users/http_auth_update}}} aktualisiert werden.", 'en': "The user configuration. Can be updated with {{{ref:users/add}}}, {{{ref:users/modify}}}, {{{ref:users/remove}}} and {{{ref:users/http_auth_update}}}."}), members={
            "users": Elem.ARRAY(T({'de': "Die Benutzer", 'en': "The users"}), members=
                  17 * user(Version.WARP1)
                + 33 * user(Version.WARP2 | Version.WARP3)
            ),
            "next_user_id": Elem.INT(T({'de': "ID des nächsten anzulegenden Nutzers.", 'en': "ID of the next user to be created."})),
            "http_auth_enabled": Elem.BOOL(T({'de': "Gibt an ob zur Verwendung von Webinterface und HTTP-API Zugangsdaten nötig sein sollen.", 'en': "Indicates whether credentials are required to use the web interface and HTTP API."}), constants=[
                Const(True, T({'de': "Falls Zugangsdaten verlangt werden sollen.", 'en': "If credentials should be required."})),
                Const(False, T({'de': "Wenn nicht.", 'en': "If not."}))
            ]),
        })
    ),

    Func("add", FuncType.COMMAND, Elem.OBJECT(T({'de': "Fügt einen neuen Benutzer hinzu.", 'en': "Adds a new user."}), members={
        "id": Elem.INT(T({'de': "ID des anzulegenden Nutzers. Muss dem aktuellen Wert von next_user_id aus {{{ref:users/config}}} entsprechen.", 'en': "ID of the user to be created. Must match the current value of next_user_id from {{{ref:users/config}}}."})),
        "roles": Elem.INT(T({'de': "Berechtigungen des Benutzers. Wird noch nicht verwendet.", 'en': "Permissions of the user. Not yet used."})),
        "current": Elem.INT(T({'de': "Diesem Benutzer erlaubter Ladestrom 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 um diesem Nutzer das Laden zu verbieten", 'en': "Charging current allowed for this user 6000 (=6 Ampere) to 32000 (=32 Ampere) or 0 to prohibit charging for this user"}), unit=Units.mA),
        "display_name": Elem.STRING(T({'de': "Anzeigename des Benutzers. Wird auch im Ladetracker verwendet.", 'en': "Display name of the user. Also used in the charge tracker."})),
        "username": Elem.STRING(T({'de': "Nutzername zum Anmelden im Webinterface und der HTTP-API.", 'en': "Username for logging into the web interface and HTTP API."})),
        "digest_hash": Elem.STRING(T({'de': "HTTP-Digest-Hash des anzulegenden Nutzers. Ein leerer String verbietet das Anmelden im Webinterface.", 'en': "HTTP Digest hash of the user to be created. An empty string prohibits login to the web interface."}), censored=True)
    }), command_is_action=True),

    Func("remove", FuncType.COMMAND, Elem.OBJECT(T({'de': "Löscht einen Benutzer.", 'en': "Deletes a user."}), members={
        "id": Elem.INT(T({'de': "ID des zu löschenden Nutzers", 'en': "ID of the user to be deleted"}))
    }), command_is_action=True),

    Func("modify", FuncType.COMMAND, Elem.OBJECT(T({'de': "Modifiziert einen Benutzer.", 'en': "Modifies a user."}), members={
        "id": Elem.INT(T({'de': "ID des zu modifizierenden Nutzers.", 'en': "ID of the user to be modified."})),
        "roles": Elem.INT(T({'de': "Berechtigungen des Benutzers. Wird noch nicht verwendet.", 'en': "Permissions of the user. Not yet used."})),
        "current": Elem.INT(T({'de': "Diesem Benutzer erlaubter Ladestrom 6000 (=6 Ampere) bis 32000 (=32 Ampere) oder 0 um diesem Nutzer das Laden zu verbieten", 'en': "Charging current allowed for this user 6000 (=6 Ampere) to 32000 (=32 Ampere) or 0 to prohibit charging for this user"}), unit=Units.mA),
        "display_name": Elem.STRING(T({'de': "Anzeigename des Benutzers. Wird auch im Ladetracker verwendet.", 'en': "Display name of the user. Also used in the charge tracker."})),
        "username": Elem.STRING(T({'de': "Nutzername zum Anmelden im Webinterface und der HTTP-API.", 'en': "Username for logging into the web interface and HTTP API."})),
        "digest_hash": Elem.STRING(T({'de': "HTTP-Digest-Hash des Nutzers. Ein leerer String verbietet das Anmelden im Webinterface.", 'en': "HTTP Digest hash of the user. An empty string prohibits login to the web interface."}))
    }), command_is_action=True),

    Func("http_auth_update", FuncType.COMMAND, Elem.OBJECT(T({'de': "Schreibt http_auth_enabled aus {{{ref:users/config}}}.", 'en': "Writes http_auth_enabled from {{{ref:users/config}}}."}), members={
        "enabled": Elem.BOOL(T({'de': "Legt fest ob zur Verwendung von Webinterface und HTTP-API Zugangsdaten nötig sein sollen.", 'en': "Specifies whether credentials are required to use the web interface and HTTP API."}), constants=[
            Const(True, T({'de': "Falls Zugangsdaten verlangt werden sollen.", 'en': "If credentials should be required."})),
            Const(False, T({'de': "Wenn nicht.", 'en': "If not."}))
        ]),
    }), command_is_action=True),

    Func("all_usernames", FuncType.HTTP_ONLY, Elem.OPAQUE(T({'de': "Für das Ladetracking werden die Anzeigenamen gelöschter Benutzer separat im Flash gespeichert. Diese Funktion gibt alle Anzeigenamen, die möglicherweise in den getrackten Ladevorgängen vorkommen in einem Binärformat aus.", 'en': "For charge tracking, the display names of deleted users are stored separately in flash. This function returns all display names that may appear in tracked charging sessions in a binary format."})))
])
