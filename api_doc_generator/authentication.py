from api_doc_common import *

authentication = Module("authentication", "Zugangsdaten", "", "Das `authentication`-Modul kann den Zugriff auf das Webinterfaces und die HTTP-API durch die Prüfung von Zugangsdaten absichern. Wenn aktiviert verlangt das Modul eine [Digest Access Authentication](https://en.wikipedia.org/wiki/Digest_access_authentication) nach [RFC 2617](https://datatracker.ietf.org/doc/html/rfc2617). Als Realm wird `esp32-lib` verwendet.", Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Zugangsdaten, die für die Verwendung von Webinterface und HTTP-API abgefragt werden sollen.", members={
            "enable_auth": Elem.BOOL("Gibt an, ob zur Verwendung von Webinterface und HTTP-API Zugangsdaten nötig sein sollen.", constants=[
                Const(True, "Falls Zugangsdaten verlangt werden sollen."),
                Const(False, "Wenn nicht.")
            ]),
            "username": Elem.STRING("Der Benutzername, dem Zugriff auf Webinterface und HTTP-API gewährt werden."),
            "digest_hash": Elem.STRING("Der [Digest Hash (HA1)](https://en.wikipedia.org/wiki/Digest_access_authentication), dem Zugriff auf Webinterface und HTTP-API gewährt werden. Als realm wird `esp32-lib` verwendet.", censored=True),
        })
    ),
],
    not_supported_text='Wallboxen verwenden das mächtigere {{{mod_ref:users}}}.')
