from api_doc_common import *

energy_manager = Module("energy_manager", "Energy-Manager-Konfiguration", "", "", Version.WARPEM, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT("Konfiguration des Energy Managers", members={
            "contactor_installed": Elem.BOOL("Gibt an, ob ein Schütz angeschlossen ist, mit dem die gesteuerten Wallboxen zwischen dreiphasigem und einphasigem Betrieb umgeschaltet werden können. Eingang 4 wird dann automatisch zur Schützüberwachung verwendet.")
        })
    ),
    Func("state", FuncType.STATE, Elem.OBJECT("Zustand des Energy Managers", members={
            "phases_switched": Elem.INT("Zustand der Phasenumschaltung", constants=[
                Const(1, "Eine Phase verbunden"),
                Const(3, "Drei Phasen verbunden"),
            ]),
            "input3_state": Elem.BOOL("Zustand des Eingangs 3", constants=[
                Const(True, "Eingang geschlossen"),
                Const(False, "Eingang geöffnet"),
            ]),
            "input4_state": Elem.BOOL("Zustand des Eingangs 4", constants=[
                Const(True, "Eingang geschlossen"),
                Const(False, "Eingang geöffnet"),
            ]),
            "relay_state": Elem.BOOL("Zustand des Relais", constants=[
                Const(True, "Relais geschlossen"),
                Const(False, "Relais geöffnet"),
            ]),
            "error_flags": Elem.INT("Aktive Fehlerzustände des Energy Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Fehlerwerten auftreten können.", constants=[
                Const(0, "Kein Fehler"),
                Const("0x00000002", "Keine Netzwerkverbindung (LAN/WLAN)"),
                Const("0x00010000", "Schützüberwachung hat ausgelöst"),
                Const("0x01000000", "Interner Fehler, Bricklet nicht erreichbar"),
                Const("0x02000000", "Interner Fehler, SD-Karten-Fehler"),
                Const("0x80000000", "Ungültige Konfiguration, Details in config_error_flags"),
            ]),
            "config_error_flags": Elem.INT("Aktive Konfigurationsfehler des Energy Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Konfigurationsfehlern auftreten können.", constants=[
                Const(0, "Kein Fehler"),
                Const("0x00000001", "Phasenumschaltung oder Schütz nicht konfiguriert"),
                Const("0x00000002", "Maximaler Gesamtstrom der Wallboxen nicht konfiguriert"),
                Const("0x00000004", "Keine Wallboxen konfiguriert"),
                Const("0x00000008", "Überschussladen aktiviert aber kein Stromzähler eingerichtet"),
            ])
        })
    ),
    Func("low_level_state", FuncType.STATE, Elem.OBJECT("Low-Level-Zustand des Energy Managers", members={
            "consecutive_bricklet_errors": Elem.INT("Anzahl aufeinander folgender interner Kommunikationsfehler"),
            "contactor": Elem.BOOL("Vom Energy Manager gesetzter Zustand des Schützes", constants=[
                Const(True, "Schütz geschlossen"),
                Const(False, "Schütz geöffnet"),
            ]),
            "contactor_check_state": Elem.INT("Zustand der Schützprüfung", constants=[
                Const(0, "Schützüberwachung hat ausgelöst (Schütz defekt)"),
                Const(1, "Kein Schützfehler bekannt (Schütz in Ordnung)"),
            ]),
            "input_voltage": Elem.INT("Interne Versorgungsspannung in Millivolt.", unit=Units.mV),
            "led_rgb": Elem.ARRAY("Farbe der Status-LED", members=[
                Elem.INT("Rot: 0 (aus) bis 255 (maximale Intensität)"),
                Elem.INT("Grün: 0 (aus) bis 255 (maximale Intensität)"),
                Elem.INT("Blau: 0 (aus) bis 255 (maximale Intensität)"),
            ]),
            "uptime": Elem.INT("Zeit seit Starten des Energy Manager Bricklets.<br/><br/>Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", unit=Units.ms)
        })
    ),
    Func("sdcard_state", FuncType.STATE, Elem.OBJECT("Informationen über die eingelegte MicroSD-Karte.", members={
            "sd_status": Elem.INT("Status der SD-Karte", constants=[
                Const(0, "OK"),
                Const(1, "READ_BLOCK_TIMEOUT"),
                Const(2, "WRITE_BLOCK_TIMEOUT"),
                Const(3, "RESPONSE_TIMEOUT"),
                Const(11, "ERROR_INIT_TYPE"),
                Const(12, "ERROR_INIT_VER_OR_VOLTAGE"),
                Const(13, "ERROR_INIT_ACMD41"),
                Const(14, "ERROR_INIT_CMD58"),
                Const(15, "ERROR_INIT_CMD0"),
                Const(21, "ERROR_CID_START"),
                Const(22, "ERROR_CID_CMD10"),
                Const(31, "ERROR_CSD_START"),
                Const(32, "ERROR_CSD_CMD9"),
                Const(41, "ERROR_COUNT_TO_HIGH"),
                Const(51, "ERROR_NO_CARD"),
                Const(255, "ERROR_API_FAILURE"),
            ]),
            "lfs_status": Elem.INT("Status des Dateisystems (LittleFS) auf der SD-Karte", constants=[
                Const(0, "OK"),
                Const(255, "ERROR_API_FAILURE"),
                Const(256, "SD-Karte wird gerade formatiert")
            ]),
            "card_type": Elem.INT("SD-Kartentyp", constants=[
                Const(0, "Keine SD-Karte gefunden"),
                Const(1, "MMC"),
                Const(2, "SD"),
                Const(4, "SDSC"),
                Const(12, "SDHC/SDXC"),
            ]),
            "sector_count": Elem.INT("Größe der SD-Karte in Sektoren"),
            "sector_size": Elem.INT("Größe eines Sektors"),
            "manufacturer_id": Elem.INT("Hersteller-ID"),
            "product_rev": Elem.INT("Produktrevision"),
            "product_name": Elem.STRING("Produktname"),
        })
    ),

    Func("sdcard_format", FuncType.COMMAND, Elem.OBJECT("Formatiert die eingelegte SD-Karte und löscht damit die Historie der Energiebilanz. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", members={
        "do_i_know_what_i_am_doing": Elem.BOOL("Gibt an ob die SD-Karte formatiert werden soll", constants=[
                Const(True, "SD-Karte formatieren"),
                Const(False, "Keine Aktion durchführen"),
            ]
        )
    })),
])
