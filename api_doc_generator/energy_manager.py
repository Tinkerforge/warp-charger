from api_doc_common import *

energy_manager = Module("energy_manager", T({'de': "Energy-Manager-Konfiguration", 'en': "Energy Manager Configuration"}), "", T({'de': "Das `energy_manager`-Modul verwaltet Zustand und Konfiguration des WARP Energy Manager Bricklets.", 'en': "The `energy_manager` module manages the state and configuration of the WARP Energy Manager Bricklet."}), Version.WEMX, [
    Func("config", FuncType.CONFIGURATION, Elem.OBJECT(T({'de': "Konfiguration des Energy Managers", 'en': "Energy Manager configuration"}), members={
            "contactor_installed": Elem.BOOL(T({'de': "Gibt an, ob ein Schütz angeschlossen ist, mit dem die gesteuerten Wallboxen zwischen dreiphasigem und einphasigem Betrieb umgeschaltet werden können. Eingang 4 wird dann automatisch zur Schützüberwachung verwendet.", 'en': "Indicates whether a contactor is connected that can switch the controlled wallboxes between three-phase and single-phase operation. Input 4 is then automatically used for contactor monitoring."}))
        })
    ),
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Zustand des Energy Managers", 'en': "Energy Manager state"}), members={
            "phases_switched": Elem.INT(T({'de': "Zustand der Phasenumschaltung", 'en': "Phase switching state"}), constants=[
                Const(1, T({'de': "Eine Phase verbunden", 'en': "One phase connected"})),
                Const(3, T({'de': "Drei Phasen verbunden", 'en': "Three phases connected"})),
            ]),
            "input3_state": Elem.BOOL(T({'de': "Zustand des Eingangs 3", 'en': "State of input 3"}), constants=[
                Const(True, T({'de': "Eingang geschlossen", 'en': "Input closed"})),
                Const(False, T({'de': "Eingang geöffnet", 'en': "Input open"})),
            ]),
            "input4_state": Elem.BOOL(T({'de': "Zustand des Eingangs 4", 'en': "State of input 4"}), constants=[
                Const(True, T({'de': "Eingang geschlossen", 'en': "Input closed"})),
                Const(False, T({'de': "Eingang geöffnet", 'en': "Input open"})),
            ]),
            "relay_state": Elem.BOOL(T({'de': "Zustand des Relais", 'en': "State of the relay"}), constants=[
                Const(True, T({'de': "Relais geschlossen", 'en': "Relay closed"})),
                Const(False, T({'de': "Relais geöffnet", 'en': "Relay open"})),
            ]),
            "error_flags": Elem.INT(T({'de': "Aktive Fehlerzustände des Energy Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Fehlerwerten auftreten können.", 'en': "Active error states of the Energy Manager. This is a bitmask, so any combination of error values can occur."}), constants=[
                Const(0, T({'de': "Kein Fehler", 'en': "No error"})),
                Const("0x00000002", T({'de': "Keine Netzwerkverbindung (LAN/WLAN)", 'en': "No network connection (LAN/WLAN)"})),
                Const("0x00010000", T({'de': "Schützüberwachung hat ausgelöst", 'en': "Contactor monitoring has triggered"})),
                Const("0x01000000", T({'de': "Interner Fehler, Bricklet nicht erreichbar", 'en': "Internal error, Bricklet not reachable"})),
                Const("0x02000000", T({'de': "Interner Fehler, SD-Karten-Fehler", 'en': "Internal error, SD card error"})),
                Const("0x80000000", T({'de': "Ungültige Konfiguration, Details in config_error_flags", 'en': "Invalid configuration, details in config_error_flags"})),
            ]),
            "config_error_flags": Elem.INT(T({'de': "Aktive Konfigurationsfehler des Energy Managers. Es handelt sich hierbei um eine Bitmaske, sodass sämtliche Kombinationen aus Konfigurationsfehlern auftreten können.", 'en': "Active configuration errors of the Energy Manager. This is a bitmask, so any combination of configuration errors can occur."}), constants=[
                Const(0, T({'de': "Kein Fehler", 'en': "No error"})),
                Const("0x00000001", T({'de': "Phasenumschaltung oder Schütz nicht konfiguriert", 'en': "Phase switching or contactor not configured"})),
                Const("0x00000002", T({'de': "Maximaler Gesamtstrom der Wallboxen nicht konfiguriert", 'en': "Maximum total current of wallboxes not configured"})),
                Const("0x00000004", T({'de': "Keine Wallboxen konfiguriert", 'en': "No wallboxes configured"})),
                Const("0x00000008", T({'de': "Überschussladen aktiviert aber kein Stromzähler eingerichtet", 'en': "Excess charging enabled but no electricity meter configured"})),
            ])
        })
    ),
    Func("low_level_state", FuncType.STATE, Elem.OBJECT(T({'de': "Low-Level-Zustand des Energy Managers", 'en': "Low-level state of the Energy Manager"}), members={
            "consecutive_bricklet_errors": Elem.INT(T({'de': "Anzahl aufeinander folgender interner Kommunikationsfehler", 'en': "Number of consecutive internal communication errors"})),
            "contactor": Elem.BOOL(T({'de': "Vom Energy Manager gesetzter Zustand des Schützes", 'en': "Contactor state set by the Energy Manager"}), constants=[
                Const(True, T({'de': "Schütz geschlossen", 'en': "Contactor closed"})),
                Const(False, T({'de': "Schütz geöffnet", 'en': "Contactor open"})),
            ]),
            "contactor_check_state": Elem.INT(T({'de': "Zustand der Schützprüfung", 'en': "Contactor check state"}), constants=[
                Const(0, T({'de': "Schützüberwachung hat ausgelöst (Schütz defekt)", 'en': "Contactor monitoring has triggered (contactor defective)"})),
                Const(1, T({'de': "Kein Schützfehler bekannt (Schütz in Ordnung)", 'en': "No contactor error known (contactor OK)"})),
            ]),
            "input_voltage": Elem.INT(T({'de': "Interne Versorgungsspannung in Millivolt.", 'en': "Internal supply voltage in millivolts."}), unit=Units.mV),
            "led_rgb": Elem.ARRAY(T({'de': "Farbe der Status-LED", 'en': "Status LED color"}), members=[
                Elem.INT(T({'de': "Rot: 0 (aus) bis 255 (maximale Intensität)", 'en': "Red: 0 (off) to 255 (maximum intensity)"})),
                Elem.INT(T({'de': "Grün: 0 (aus) bis 255 (maximale Intensität)", 'en': "Green: 0 (off) to 255 (maximum intensity)"})),
                Elem.INT(T({'de': "Blau: 0 (aus) bis 255 (maximale Intensität)", 'en': "Blue: 0 (off) to 255 (maximum intensity)"})),
            ]),
            "uptime": Elem.INT(T({'de': "Zeit seit Starten des Energy Manager Bricklets.<br/><br/>Achtung: Diese Zeit wird direkt über den Takt des Prozessors gemessen. Die Genauigkeit ist damit nur ausreichend für Zeitmessungen im Bereich Minuten bis wenige Stunden. Die Zeitmessung läuft nach ungefähr 50 Tagen über und beginnt wieder bei 0.", 'en': "Time since starting the Energy Manager Bricklet.<br/><br/>Attention: This time is measured directly via the processor clock. The accuracy is therefore only sufficient for time measurements in the range of minutes to a few hours. The time measurement overflows after approximately 50 days and starts again at 0."}), unit=Units.ms)
        })
    ),
    Func("sdcard_state", FuncType.STATE, Elem.OBJECT(T({'de': "Informationen über die eingelegte MicroSD-Karte.", 'en': "Information about the inserted MicroSD card."}), members={
            "sd_status": Elem.INT(T({'de': "Status der SD-Karte", 'en': "SD card status"}), constants=[
                Const(0, U("OK")),
                Const(1, U("READ_BLOCK_TIMEOUT")),
                Const(2, U("WRITE_BLOCK_TIMEOUT")),
                Const(3, U("RESPONSE_TIMEOUT")),
                Const(11, U("ERROR_INIT_TYPE")),
                Const(12, U("ERROR_INIT_VER_OR_VOLTAGE")),
                Const(13, U("ERROR_INIT_ACMD41")),
                Const(14, U("ERROR_INIT_CMD58")),
                Const(15, U("ERROR_INIT_CMD0")),
                Const(21, U("ERROR_CID_START")),
                Const(22, U("ERROR_CID_CMD10")),
                Const(31, U("ERROR_CSD_START")),
                Const(32, U("ERROR_CSD_CMD9")),
                Const(41, U("ERROR_COUNT_TO_HIGH")),
                Const(51, U("ERROR_NO_CARD")),
                Const(255, U("ERROR_API_FAILURE")),
            ]),
            "lfs_status": Elem.INT(T({'de': "Status des Dateisystems (LittleFS) auf der SD-Karte", 'en': "Status of the file system (LittleFS) on the SD card"}), constants=[
                Const(0, U("OK")),
                Const(255, U("ERROR_API_FAILURE")),
                Const(256, T({'de': "SD-Karte wird gerade formatiert", 'en': "SD card is being formatted"}))
            ]),
            "card_type": Elem.INT(T({'de': "SD-Kartentyp", 'en': "SD card type"}), constants=[
                Const(0, T({'de': "Keine SD-Karte gefunden", 'en': "No SD card found"})),
                Const(1, U("MMC")),
                Const(2, U("SD")),
                Const(4, U("SDSC")),
                Const(12, U("SDHC/SDXC")),
            ]),
            "sector_count": Elem.INT(T({'de': "Größe der SD-Karte in Sektoren", 'en': "SD card size in sectors"})),
            "sector_size": Elem.INT(T({'de': "Größe eines Sektors", 'en': "Size of a sector"})),
            "manufacturer_id": Elem.INT(T({'de': "Hersteller-ID", 'en': "Manufacturer ID"})),
            "product_rev": Elem.INT(T({'de': "Produktrevision", 'en': "Product revision"})),
            "product_name": Elem.STRING(T({'de': "Produktname", 'en': "Product name"})),
        })
    ),

    Func("sdcard_format", FuncType.COMMAND, Elem.OBJECT(T({'de': "Formatiert die eingelegte SD-Karte und löscht damit die Historie der Energiebilanz. <strong>Kann nicht rückgängig gemacht werden!</strong> Danach wird automatisch ein Neustart ausgeführt.", 'en': "Formats the inserted SD card and thus deletes the energy balance history. <strong>Cannot be undone!</strong> A restart is automatically performed afterwards."}), members={
        "do_i_know_what_i_am_doing": Elem.BOOL(T({'de': "Gibt an ob die SD-Karte formatiert werden soll", 'en': "Indicates whether the SD card should be formatted"}), constants=[
                Const(True, T({'de': "SD-Karte formatieren", 'en': "Format SD card"})),
                Const(False, T({'de': "Keine Aktion durchführen", 'en': "Perform no action"})),
            ]
        )
    })),
])
