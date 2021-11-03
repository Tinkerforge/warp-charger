from api_doc_common import *

nfc = Module("nfc", "NFC-Ladefreigabe", "", Version.ANY, [
    Func("seen_tags", FuncType.STATE, Elem.ARRAY("Die zuletzt von der Wallbox gesehenen NFC-Tags.", members=[
            * 8 * [Elem.OBJECT("Ein gesehenes NFC-Tag", members = {
                "tag_type": Elem.INT("Typ des Tags", constants=[
                    Const(0, "Mifare Classic"),
                    Const(1, "NFC Forum Typ 1"),
                    Const(2, "NFC Forum Typ 2"),
                    Const(3, "NFC Forum Typ 3"),
                    Const(4, "NFC Forum Typ 4"),
                ]),
                "tag_id": Elem.ARRAY("ID des Tags. Je nach Tag-Typ bis zu 10 Byte.", member_type=EType.INT),
                "last_seen": Elem.INT("Zeit in Millisekunden vor der das Tag zuletzt gesehen wurde.", unit=Units.ms)
            })]
        ])
    ),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Die NFC-Konfiguration. Diese kann über nfc/config_update mit dem selben Payload aktualisiert werden.", members={
            "require_tag_to_start": Elem.BOOL("Gibt an, ob ein Tag zum Starten einer Ladung benötigt wird.", constants=[
                Const(True, "Wenn eine Ladung nur mit einem NFC-Tag, oder über das Webinterface/die API freigegeben werden kann."),
                Const(False, "Wenn kein NFC-Tag zum Laden benötigt wird.")
            ]),
            "require_tag_to_stop": Elem.BOOL("Gibt an, ob ein Tag zum Stoppen einer Ladung benötigt wird.", constants=[
                Const(True, "Wenn eine Ladung nur mit einem NFC-Tag, oder über das Webinterface/die API gestoppt werden kann."),
                Const(False, "Wenn kein NFC-Tag zum Stoppen einer Ladung benötigt wird. <strong>Wenn aktiviert, wird die Stop-Funktion des Buttons an der Frontplatte deaktiviert, sowie {{{ref:evse/button_configuration_update}}} blockiert!</strong>")
            ]),
            "authorized_tags": Elem.ARRAY("Eine Liste authorisierter Tags.", members=[
                * 8 * [
                    Elem.OBJECT("Ein autorisiertes NFC-Tag", members={
                        "tag_name": Elem.STRING("Anzeigename des Tags."),
                        "tag_type": Elem.INT("Typ des Tags.", constants=[
                            Const(0, "Mifare Classic"),
                            Const(1, "NFC Forum Typ 1"),
                            Const(2, "NFC Forum Typ 2"),
                            Const(3, "NFC Forum Typ 3"),
                            Const(4, "NFC Forum Typ 4"),
                        ]),
                        "tag_id": Elem.ARRAY("ID des Tags. Je nach Tag-Typ bis zu 10 Byte.", member_type=EType.INT),
                    })
                ]
            ]),
        })
    )
])
