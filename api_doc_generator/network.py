from api_doc_common import *

network = Module("network", "Netzwerk-Konfiguration", "", "", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Allgemeine Netzwerkeinstellungen", members={
        "hostname": Elem.STRING("Hostname den das Gerät in allen konfigurierten Netzwerken verwenden soll."),
        "enable_mdns": Elem.BOOL("Gibt an, ob das Gerät das Webinterface per mDNS im Netzwerk bekanntgeben soll. Per mDNS wird das Webinterface unter http://[hostname].local (z.B. http://warp2-AbC.local) erreichbar sein."),
        "web_server_port": Elem.INT("Listen-Port des Webinterfaces. Typischerweise 80")
    })),
    Func("state", FuncType.STATE, Elem.OBJECT("Allgemeiner Netzwerkzustand", members={
        "connected": Elem.BOOL("Gibt an, ob das Gerät mit einem Netzwerk verbunden ist.")
    }))
])
