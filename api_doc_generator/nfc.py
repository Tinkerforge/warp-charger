from api_doc_common import *

def tag(version):
    return [
        Elem.OBJECT(T({'de': "Ein autorisiertes NFC-Tag", 'en': "An authorized NFC tag"}), version=version, members={
            "user_id": Elem.INT(T({'de': "ID des Nutzers dem dieses Tag zugeordnet ist, oder 0 falls es keinem Nutzer zugeordnet ist.", 'en': "ID of the user this tag is assigned to, or 0 if it is not assigned to any user."})),
            "tag_type": Elem.INT(T({'de': "Typ des Tags.", 'en': "Type of the tag."}), constants=[
                Const(0, U("Mifare Classic")),
                Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
                Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
                Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
                Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
            ]),
            "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. `01:23:AB:3D`", 'en': "ID of the tag. Depending on tag type, up to 10 hex bytes separated by ':'. e.g. `01:23:AB:3D`"})),
        })
    ]

nfc = Module("nfc", T({'de': "NFC-Ladefreigabe", 'en': "NFC Charge Authorization"}), T({'de': "Benötigt das Feature <a href=\"#features_nfc\"><code>\"nfc\"</code></a>.", 'en': "Requires the <a href=\"#features_nfc\"><code>\"nfc\"</code></a> feature."}), "", Version.WARPX, [
    Func("seen_tags", FuncType.STATE, Elem.ARRAY(T({'de': "Die zuletzt von der Wallbox gesehenen NFC-Tags.", 'en': "The NFC tags most recently seen by the wallbox."}), members=[
            * 8 * [Elem.OBJECT(T({'de': "Ein gesehenes NFC-Tag", 'en': "A seen NFC tag"}), members = {
                "tag_type": Elem.INT(T({'de': "Typ des Tags", 'en': "Type of the tag"}), constants=[
                    Const(0, U("Mifare Classic")),
                    Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
                    Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
                    Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
                    Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
                ]),
                "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. `01:23:AB:3D`", 'en': "ID of the tag. Depending on tag type, up to 10 hex bytes separated by ':'. e.g. `01:23:AB:3D`"})),
                "last_seen": Elem.INT(T({'de': "Zeit in Millisekunden vor der das Tag zuletzt gesehen wurde.", 'en': "Time in milliseconds since the tag was last seen."}), unit=Units.ms)
            })],
            Elem.OBJECT(T({'de': "Das von {{{ref:nfc/inject_tag}}} vorgetäuschte Tag", 'en': "The tag spoofed by {{{ref:nfc/inject_tag}}}"}), members = {
                "tag_type": Elem.INT(T({'de': "Typ des Tags", 'en': "Type of the tag"}), constants=[
                    Const(0, U("Mifare Classic")),
                    Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
                    Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
                    Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
                    Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
                ]),
                "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. `01:23:AB:3D`", 'en': "ID of the tag. Depending on tag type, up to 10 hex bytes separated by ':'. e.g. `01:23:AB:3D`"})),
                "last_seen": Elem.INT(T({'de': "Zeit in Millisekunden vor der das Tag zuletzt gesehen wurde.", 'en': "Time in milliseconds since the tag was last seen."}), unit=Units.ms)
            })
        ])
    ),

    Func("inject_tag", FuncType.COMMAND, Elem.OBJECT(T({'de': "Täuscht vor, dass ein Tag vom NFC-Leser erkannt wurde. Hiermit kann über die API ein Ladevorgang für einen bestimmten Benutzer gestartet oder gestoppt werden. Analog zur physischen Verwendung eines Tags wird der Ladevorgang bei Aufruf der API abwechselnd freigegeben oder blockiert. Siehe {{{ref:nfc/inject_tag_start}}} und {{{ref:nfc/inject_tag_stop}}} für genauere Kontrolle. Das vorgetauschte Tag ist immer der letzte Eintrag in {{{ref:nfc/seen_tags}}}", 'en': "Pretends that a tag was detected by the NFC reader. This can be used to start or stop a charging session for a specific user via the API. Analogous to the physical use of a tag, the charging session is alternately authorized or blocked with each API call. See {{{ref:nfc/inject_tag_start}}} and {{{ref:nfc/inject_tag_stop}}} for more precise control. The spoofed tag is always the last entry in {{{ref:nfc/seen_tags}}}"}), members={
        "tag_type": Elem.INT(T({'de': "Typ des Tags.", 'en': "Type of the tag."}), constants=[
            Const(0, U("Mifare Classic")),
            Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
            Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
            Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
            Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
        ]),
        "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. `01:23:AB:3D`", 'en': "ID of the tag. Depending on tag type, up to 10 hex bytes separated by ':'. e.g. `01:23:AB:3D`"})),
    }), True),

     Func("inject_tag_start", FuncType.COMMAND, Elem.OBJECT(T({'de': "Täuscht vor, dass ein Tag vom NFC-Leser erkannt wurde. Das Tag wird nur zum <strong>Starten</strong> eines Ladevorgangs verwendet. Das vorgetauschte Tag ist immer der letzte Eintrag in {{{ref:nfc/seen_tags}}}", 'en': "Pretends that a tag was detected by the NFC reader. The tag is only used to <strong>start</strong> a charging session. The spoofed tag is always the last entry in {{{ref:nfc/seen_tags}}}"}), members={
        "tag_type": Elem.INT(T({'de': "Typ des Tags.", 'en': "Type of the tag."}), constants=[
            Const(0, U("Mifare Classic")),
            Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
            Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
            Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
            Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
        ]),
        "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. `01:23:AB:3D`", 'en': "ID of the tag. Depending on tag type, up to 10 hex bytes separated by ':'. e.g. `01:23:AB:3D`"})),
    }), True),

     Func("inject_tag_stop", FuncType.COMMAND, Elem.OBJECT(T({'de': "Täuscht vor, dass ein Tag vom NFC-Leser erkannt wurde. Das Tag wird nur zum <strong>Stoppen</strong> eines Ladevorgangs verwendet. Das vorgetauschte Tag ist immer der letzte Eintrag in {{{ref:nfc/seen_tags}}}", 'en': "Pretends that a tag was detected by the NFC reader. The tag is only used to <strong>stop</strong> a charging session. The spoofed tag is always the last entry in {{{ref:nfc/seen_tags}}}"}), members={
        "tag_type": Elem.INT(T({'de': "Typ des Tags.", 'en': "Type of the tag."}), constants=[
            Const(0, U("Mifare Classic")),
            Const(1, T({'de': "NFC Forum Typ 1", 'en': "NFC Forum Type 1"})),
            Const(2, T({'de': "NFC Forum Typ 2", 'en': "NFC Forum Type 2"})),
            Const(3, T({'de': "NFC Forum Typ 3", 'en': "NFC Forum Type 3"})),
            Const(4, T({'de': "NFC Forum Typ 4", 'en': "NFC Forum Type 4"})),
        ]),
        "tag_id": Elem.STRING(T({'de': "ID des Tags. Je nach Tag-Typ bis zu 10 Hex-Bytes, separiert durch ':'. z.B. `01:23:AB:3D`", 'en': "ID of the tag. Depending on tag type, up to 10 hex bytes separated by ':'. e.g. `01:23:AB:3D`"})),
    }), True),

    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Die NFC-Konfiguration.", 'en': "The NFC configuration."}), members={
            "deadtime_post_start": Elem.INT(T({'de': "Erlaubt das Stoppen eines Ladevorgangs mit einem NFC-Tag erst nach dieser Zeit, um Fehlbedienung zu vermeiden.", 'en': "Allows stopping a charging session with an NFC tag only after this time to avoid accidental operation."}), unit=Units.s),
            "authorized_tags": Elem.ARRAY(T({'de': "Eine Liste authorisierter Tags.", 'en': "A list of authorized tags."}), members=
                  16 * tag(Version.WARP1)
                + 32 * tag(Version.WARP2 | Version.WARP3)
            ),
        })
    ),
])
