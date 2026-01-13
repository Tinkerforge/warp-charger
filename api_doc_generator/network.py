from api_doc_common import *

network = Module("network", T({'de': "Netzwerk-Konfiguration", 'en': "Network Configuration"}), "", "", Version.ANY, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Allgemeine Netzwerkeinstellungen", 'en': "General network settings"}), members={
        "hostname": Elem.STRING(T({'de': "Hostname den das Gerät in allen konfigurierten Netzwerken verwenden soll.", 'en': "Hostname the device should use in all configured networks."})),
        "enable_mdns": Elem.BOOL(T({'de': "Gibt an, ob das Gerät das Webinterface per mDNS im Netzwerk bekanntgeben soll. Per mDNS wird das Webinterface unter http://[hostname].local (z.B. http://warp2-AbC.local) erreichbar sein.", 'en': "Indicates whether the device should advertise the web interface via mDNS on the network. Via mDNS, the web interface will be accessible at http://[hostname].local (e.g., http://warp2-AbC.local)."})),
        "web_server_port": Elem.INT(T({'de': "Listen-Port des Webinterfaces. Typischerweise 80", 'en': "Listen port of the web interface. Typically 80"}))
    })),
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Allgemeiner Netzwerkzustand", 'en': "General network state"}), members={
        "connected": Elem.BOOL(T({'de': "Gibt an, ob das Gerät mit einem Netzwerk verbunden ist.", 'en': "Indicates whether the device is connected to a network."}))
    }))
])
