from api_doc_common import *

mqtt = Module("mqtt", "MQTT-Verbindung", "", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der aktuelle MQTT-Zustand.", members={
            "connection_state": Elem.INT("Zustand der Verbindung zum MQTT-Broker", constants=[
                Const(0, "Nicht konfiguriert"),
                Const(1, "Nicht verbunden"),
                Const(2, "Verbunden"),
                Const(3, "Fehler"),
            ]),
            "last_error": Elem.INT("Der zuletzt aufgetretene Fehler. -1 falls kein Fehler aufgetreten ist."),
        })
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die MQTT-Konfiguration. Diese kann über mqtt/config_update mit dem selben Payload aktualisiert werden.", members={
            "enable_mqtt": Elem.BOOL("Gibt an ob eine MQTT-Verbindung zum konfigurierten Broker aufgebaut werden soll.", constants=[
                Const(True, "Wenn MQTT aktiviert ist."),
                Const(False, "Wenn MQTT deaktiviert ist.")
            ]),
            "broker_host": Elem.STRING("Hostname oder IP-Adresse des MQTT-Brokers, zu dem sich die Wallbox verbinden soll."),
            "broker_port": Elem.INT("Port des MQTT-Brokers zu dem sich die Wallbox verbinden soll. Typischerweise 1883."),
            "broker_username": Elem.STRING("Username mit dem sich zum Broker verbunden werden soll. Leer falls keine Authentifizierung verwendet wird."),
            "broker_password": Elem.STRING("Passwort mit dem sich zum Broker verbunden werden soll. Leer falls keine Authentisierung verwendet wird.", censored=True),
            "global_topic_prefix": Elem.STRING("Präfix der allen MQTT-Topics vorangestellt wird. Normalerweise warp/[UID der Wallbox] bzw. warp2/[UID der Wallbox]."),
            "client_name": Elem.STRING("Name unter dem sich die Wallbox beim Broker registriert. <strong>Das ist nicht der Username zur Authentisierung.</strong>"),
        })
    )
])
