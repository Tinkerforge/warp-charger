from api_doc_common import *

network = Module("network", "Netzwerk-Konfiguration", "", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Allgemeine Netzwerkeinstellungen", members={
        "hostname": Elem.STRING("Hostname den die Wallbox in allen konfigurierten Netzwerken verwenden soll."),
        "enable_mdns": Elem.BOOL("Gibt an, ob die Wallbox das Webinterface per mDNS im Netzwerk bekanntgeben soll. Per mDNS wird das Webinterface unter http://[hostname].local (z.B. http://warp2-AbC.local) erreichbar sein.")
    }))
])
