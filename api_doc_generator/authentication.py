from api_doc_common import *

authentication = Module("authentication", "Zugangsdaten", "", "", Version.WARPEM, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Zugangsdaten, die für die Verwendung von Webinterface und HTTP-API abgefragt werden sollen.", members={
            "enable_auth": Elem.BOOL("Gibt an ob zur Verwendung von Webinterface und HTTP-API Zugangsdaten nötig sein sollen.", constants=[
                Const(True, "Falls Zugangsdaten verlangt werden sollen."),
                Const(False, "Wenn nicht.")
            ]),
            "username": Elem.STRING("Der Benutzername, dem Zugriff auf Webinterface und HTTP-API gewährt werden."),
            "digest_hash": Elem.STRING("Der <a href=\"https://en.wikipedia.org/wiki/Digest_access_authentication\">Digest Hash</a>, dem Zugriff auf Webinterface und HTTP-API gewährt werden.", censored=True),
        })
    ),
])
