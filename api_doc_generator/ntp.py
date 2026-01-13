from api_doc_common import *

ntp = Module("ntp",
    T({'de': "Zeitsynchronisierung", 'en': "Time Synchronization"}),
    "",
    "",
    Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT(
        T({'de': "Der Zustand der Netzwerkzeitsynchronisierung.",
           'en': "The state of network time synchronization."}),
        members={
            "synced": Elem.BOOL(
                T({'de': "Gibt an, ob das Gerät seine Zeit per NTP synchronisieren konnte.",
                   'en': "Indicates whether the device was able to synchronize its time via NTP."})),
            "time": Elem.INT(
                T({'de': "Ein Unix-Timestamp in <strong>Minuten</strong>, der die aktuelle Zeit des Geräts angibt, oder 0 falls keine Zeitsynchronisierung besteht",
                   'en': "A Unix timestamp in <strong>minutes</strong> indicating the device's current time, or 0 if no time synchronization exists"}))
        })),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(
        T({'de': "Die Konfiguration der Netzwerkzeitsynchronisierung.",
           'en': "The configuration of network time synchronization."}),
        members={
            "enable": Elem.BOOL(
                T({'de': "Gibt an, ob das Gerät per NTP seine Zeit synchronisieren soll. Die erhaltene Zeit wird zur Bestimmung der Startzeitpunkte von getrackten Ladevorgängen und im Ereignislog verwendet.",
                   'en': "Specifies whether the device should synchronize its time via NTP. The obtained time is used to determine the start times of tracked charging sessions and in the event log."})),
            "use_dhcp":  Elem.BOOL(
                T({'de': "Gibt an, ob das Gerät NTP-Server per DHCP empfangen soll. Funktioniert nur, wenn DHCP zur IP-Addressvergabe verwendet wird.",
                   'en': "Specifies whether the device should receive NTP servers via DHCP. Only works if DHCP is used for IP address assignment."})),
            "timezone":  Elem.STRING(
                T({'de': "Die Zeitzone, in der sich das Gerät befindet. z.B. \"Europe/Berlin\"",
                   'en': "The timezone in which the device is located. e.g. \"Europe/Berlin\""})),
            "server":  Elem.STRING(
                T({'de': "IP-Adresse oder Hostname des zu verwendenden Zeitservers",
                   'en': "IP address or hostname of the time server to use"})),
            "server2":  Elem.STRING(
                T({'de': "IP-Adresse oder Hostname des alternativ zu verwendenden Zeitservers",
                   'en': "IP address or hostname of the alternative time server to use"})),
        }))
])
