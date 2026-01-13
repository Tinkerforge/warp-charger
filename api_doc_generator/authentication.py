from api_doc_common import *

authentication = Module("authentication",
    T({'de': "Zugangsdaten", 'en': "Credentials"}),
    "",
    T({'de': "Das `authentication`-Modul kann den Zugriff auf das Webinterfaces und die HTTP-API durch die Prüfung von Zugangsdaten absichern. Wenn aktiviert verlangt das Modul eine [Digest Access Authentication](https://en.wikipedia.org/wiki/Digest_access_authentication) nach [RFC 2617](https://datatracker.ietf.org/doc/html/rfc2617). Als Realm wird `esp32-lib` verwendet.",
       'en': "The `authentication` module can secure access to the web interface and HTTP API by verifying credentials. When enabled, the module requires [Digest Access Authentication](https://en.wikipedia.org/wiki/Digest_access_authentication) according to [RFC 2617](https://datatracker.ietf.org/doc/html/rfc2617). The realm used is `esp32-lib`."}),
    Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(
        T({'de': "Zugangsdaten, die für die Verwendung von Webinterface und HTTP-API abgefragt werden sollen.",
           'en': "Credentials to be requested for using the web interface and HTTP API."}),
        members={
            "enable_auth": Elem.BOOL(
                T({'de': "Gibt an, ob zur Verwendung von Webinterface und HTTP-API Zugangsdaten nötig sein sollen.",
                   'en': "Specifies whether credentials should be required for using the web interface and HTTP API."}),
                constants=[
                    Const(True, T({'de': "Falls Zugangsdaten verlangt werden sollen.",
                                   'en': "If credentials should be required."})),
                    Const(False, T({'de': "Wenn nicht.",
                                    'en': "If not."}))
                ]),
            "username": Elem.STRING(
                T({'de': "Der Benutzername, dem Zugriff auf Webinterface und HTTP-API gewährt werden.",
                   'en': "The username to be granted access to the web interface and HTTP API."})),
            "digest_hash": Elem.STRING(
                T({'de': "Der [Digest Hash (HA1)](https://en.wikipedia.org/wiki/Digest_access_authentication), dem Zugriff auf Webinterface und HTTP-API gewährt werden. Als realm wird `esp32-lib` verwendet.",
                   'en': "The [Digest Hash (HA1)](https://en.wikipedia.org/wiki/Digest_access_authentication) to be granted access to the web interface and HTTP API. The realm used is `esp32-lib`."}),
                censored=True),
        })
    ),
],
    not_supported_text=T({'de': 'Wallboxen verwenden das mächtigere {{{mod_ref:users}}}.',
                          'en': 'Wallboxes use the more powerful {{{mod_ref:users}}}.'}))
