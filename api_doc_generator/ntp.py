from api_doc_common import *

ntp = Module("ntp", "Zeitsynchronisierung", "", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der Zustand der Netzwerkzeitsynchronisierung.", members={
        "synced": Elem.BOOL("Gibt an, ob die Wallbox ihre Zeit per NTP synchronisieren konnte."),
        "time": Elem.INT("Ein Unix-Timestamp in <strong>Minuten</strong>, der die aktuelle Zeit der Wallbox angibt, oder 0 falls keine Zeitsynchronisierung besteht")
    })),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die Konfiguration der Netzwerkzeitsynchronisierung.", members={
        "enable": Elem.BOOL("Gibt an, ob die Wallbox per NTP ihre Zeit synchronisieren soll. Die erhaltene Zeit wird zur Bestimmung der Startzeitpunkte von getrackten Ladevorgängen und im Ereignislog verwendet."),
        "use_dhcp":  Elem.BOOL("Gibt an, ob die Wallbox NTP-Server per DHCP empfangen soll. Funktioniert nur, wenn DHCP zur IP-Addressvergabe verwendet wird."),
        "timezone":  Elem.STRING("Die Zeitzone, in der sich die Wallbox befindet. z.B. \"Europe/Berlin\""),
        "server":  Elem.STRING("IP-Adresse oder Hostname des zu verwendenden Zeitservers"),
        "server2":  Elem.STRING("IP-Adresse oder Hostname des alternativ zu verwendenden Zeitservers"),
    }))
])
