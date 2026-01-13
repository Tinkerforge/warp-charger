from api_doc_common import *

front_panel = Module("front_panel", T({'de': "Frontblende", 'en': "Front Panel"}), "", T({'de': "Über das `front_panel`-Modul können Einstellungen des Displays in der Frontblende vorgenommen werden.", 'en': "The `front_panel` module allows configuration of the display in the front panel."}), Version.WEM2, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der Frontblende.", 'en': "The front panel configuration."}), members={
        "enable": Elem.BOOL(T({'de': "Gibt an, ob das Display aktiviert werden soll. Ist das Display deaktiviert kann es über den Taster an der Frontblende auch nicht wider aktiviert werden. Ist das Display aktiviert, geht es um Strom zu sparen nach 60 Minuten wieder aus, es kann allerdings durch einen betötigen des Tasters wieder aktiviert werden.", 'en': "Indicates whether the display should be enabled. If the display is disabled, it cannot be reactivated via the button on the front panel. If the display is enabled, it will turn off after 60 minutes to save power, but can be reactivated by pressing the button."})),
        "tiles": Elem.ARRAY(T({'de': "Gibt an welche Kachel was anzeigen soll in der Reihenfolge oben links, mitte links, unten links, oben rechts, mitte rechts, unten rechts.", 'en': "Specifies what each tile should display in the order: top left, middle left, bottom left, top right, middle right, bottom right."}), members=[
            * 6 * [Elem.UNION(T({'de': "Kachel-Konfiguration", 'en': "Tile configuration"}), members={
                0: Elem.NULL(T({'de': "Leere Kachel", 'en': "Empty tile"})),
                1: Elem.INT(T({'de': "Wallbox", 'en': "Wallbox"})),
                2: Elem.NULL(T({'de': "Lastmanagement", 'en': "Load management"})),
                3: Elem.INT(T({'de': "Zähler", 'en': "Meter"})),
                4: Elem.INT(T({'de': "Dynamischer Strompreis", 'en': "Dynamic electricity price"})),
                5: Elem.INT(T({'de': "PV-Ertragsprognose", 'en': "PV yield forecast"})),
                6: Elem.NULL(T({'de': "Status des Energy Managers", 'en': "Energy Manager status"})),
                7: Elem.NULL(T({'de': "Status der Heizung", 'en': "Heating status"})),
            })]
        ])
    }))
])
