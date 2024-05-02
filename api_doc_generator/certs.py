from api_doc_common import *

certs = Module("certs", "TLS-Zertifikatsverwaltung", "", "Das `certs`-Modul verwaltet TLS-Zertifikate, die für den Aufbau von TLS-Verbindungen (z.B. für https oder mqtts) verwendet werden. Zusätzlich zu den Zertifikaten, die hier hinterlegt werden können, ist in allen Firmwares das [Zertifikatsbundle des NSS-Projekts von Mozilla](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/protocols/esp_crt_bundle.html) eingebettet. Dieses Bundle umfasst Root-Zertifikate mit denen Verbindungen zu den meisten öffentlich erreichbaren Servern aufgebaut werden können.", Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT("Der aktuelle Zustand der TLS-Zertifikatsverwaltung.", members={
            "certs": Elem.ARRAY("Bekannte TLS-Zertifikate.", members=[
                * 8 * [Elem.OBJECT("Ein TLS-Zertifikat", members = {
                    "id": Elem.INT("ID des Zertifikats"),
                    "name": Elem.STRING("Anzeigename des Zertifikats")
                })]
            ])
        })
    ),

    Func("add", FuncType.COMMAND, Elem.OBJECT("Fügt ein neues TLS-Zertifikat hinzu.", members={
        "id": Elem.INT("ID des Zertifikats, dass hinzugefügt werden soll. Darf nicht bereits von einem Zertifikat verwendet werden."),
        "name": Elem.STRING("Anzeigename des Zertifikats."),
        "cert": Elem.STRING("Zertifikat im PEM-Format"),
    }), command_is_action=True),

    Func("modify", FuncType.COMMAND, Elem.OBJECT("Modifiziert ein vorhandenes TLS-Zertifikat.", members={
        "id": Elem.INT("ID des Zertifikats, dass modifiziert werden soll."),
        "name": Elem.STRING("Anzeigename des Zertifikats."),
        "cert": Elem.STRING("Zertifikat im PEM-Format"),
    }), command_is_action=True),

    Func("remove", FuncType.COMMAND, Elem.OBJECT("Löscht ein vorhandenes TLS-Zertifikat.", members={
        "id": Elem.INT("ID des Zertifikats, dass gelöscht werden soll.")
    }), command_is_action=True),
])
