from api_doc_common import *

require_meter = Module("require_meter", T({'de': "Zählerüberwachung", 'en': "Meter Monitoring"}), "", "", Version.WARPX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die Konfiguration der Zählerüberwachung.", 'en': "The meter monitoring configuration."}), members={
        "config": Elem.INT(T({'de': "Konfiguration der Zählerüberwachung.", 'en': "Meter monitoring configuration."}), constants=[
            Const(0, T({'de': "Es wurde noch nie ein Stromzähler gesehen. Zählerüberwachung deaktiviert. Sobald das erste Mal ein Stromzähler erkannt wird, wird dieser Wert automatisch auf 2 geändert.", 'en': "No electricity meter has been detected yet. Meter monitoring disabled. As soon as a meter is detected for the first time, this value will automatically be changed to 2."})),
            Const(1, T({'de': "Es wurde bereits einmal ein Stromzähler gesehen. Zählerüberwachung deaktiviert.", 'en': "An electricity meter has been detected before. Meter monitoring disabled."})),
            Const(2, T({'de': "Es wurde bereits einmal ein Stromzähler gesehen. Zählerüberwachung aktiviert.", 'en': "An electricity meter has been detected before. Meter monitoring enabled."})),
        ])
    }))
])
