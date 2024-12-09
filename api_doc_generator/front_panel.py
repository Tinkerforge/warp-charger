from api_doc_common import *

front_panel = Module("front_panel", "Frontblende", "", "Über das `front_panel`-Modul können Einstellungen des Displays in der Frontblende vorgenommen werden.", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der Frontblende.", members={
        "enable": Elem.BOOL("Gibt an, ob das Display aktiviert werden soll. Ist das Display deaktiviert kann es über den Taster an der Frontblende auch nicht wider aktiviert werden. Ist das Display aktiviert, geht es um Strom zu sparen nach 60 Minuten wieder aus, es kann allerdings durch einen betötigen des Tasters wieder aktiviert werden."),
        "tiles": Elem.ARRAY("", members=[
            * 6 * [Elem.UNION("Kachel-Konfiguration", members={
                0: Elem.NULL("Leere Kachel"),
                1: Elem.INT("Wallbox"),
                2: Elem.NULL("Lastmanagement"),
                3: Elem.INT("Zähler"),
                4: Elem.INT("Dynamischer Strompreis"),
                5: Elem.INT("PV-Ertragsprognose"),
                6: Elem.NULL("Status des Energy Managers"),
                7: Elem.NULL("Status der Heizung"),
            })]
        ])
    }))
]),