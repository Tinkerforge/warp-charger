from api_doc_common import *

certs = Module("certs", T({'de': "TLS-Zertifikatsverwaltung", 'en': "TLS Certificate Management"}), "", T({'de': "Das `certs`-Modul verwaltet TLS-Zertifikate, die für den Aufbau von TLS-Verbindungen (z.B. für https oder mqtts) verwendet werden. Zusätzlich zu den Zertifikaten, die hier hinterlegt werden können, ist in allen Firmwares das [Zertifikatsbundle des NSS-Projekts von Mozilla](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/protocols/esp_crt_bundle.html) eingebettet. Dieses Bundle umfasst Root-Zertifikate mit denen Verbindungen zu den meisten öffentlich erreichbaren Servern aufgebaut werden können.", 'en': "The `certs` module manages TLS certificates used for establishing TLS connections (e.g., for https or mqtts). In addition to the certificates that can be stored here, all firmwares have the [Mozilla NSS project certificate bundle](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/protocols/esp_crt_bundle.html) embedded. This bundle includes root certificates that allow connections to most publicly accessible servers."}), Version.ANY, [
    Func("state", FuncType.STATE, Elem.OBJECT(T({'de': "Der aktuelle Zustand der TLS-Zertifikatsverwaltung.", 'en': "The current state of TLS certificate management."}), members={
            "certs": Elem.ARRAY(T({'de': "Bekannte TLS-Zertifikate.", 'en': "Known TLS certificates."}), members=[
                * 8 * [Elem.OBJECT(T({'de': "Ein TLS-Zertifikat", 'en': "A TLS certificate"}), members = {
                    "id": Elem.INT(T({'de': "ID des Zertifikats", 'en': "ID of the certificate"})),
                    "name": Elem.STRING(T({'de': "Anzeigename des Zertifikats", 'en': "Display name of the certificate"}))
                })]
            ])
        })
    ),

    Func("add", FuncType.COMMAND, Elem.OBJECT(T({'de': "Fügt ein neues TLS-Zertifikat hinzu.", 'en': "Adds a new TLS certificate."}), members={
        "id": Elem.INT(T({'de': "ID des Zertifikats, dass hinzugefügt werden soll. Darf nicht bereits von einem Zertifikat verwendet werden.", 'en': "ID of the certificate to be added. Must not already be used by a certificate."})),
        "name": Elem.STRING(T({'de': "Anzeigename des Zertifikats.", 'en': "Display name of the certificate."})),
        "cert": Elem.STRING(T({'de': "Zertifikat im PEM-Format", 'en': "Certificate in PEM format"})),
    }), command_is_action=True),

    Func("modify", FuncType.COMMAND, Elem.OBJECT(T({'de': "Modifiziert ein vorhandenes TLS-Zertifikat.", 'en': "Modifies an existing TLS certificate."}), members={
        "id": Elem.INT(T({'de': "ID des Zertifikats, dass modifiziert werden soll.", 'en': "ID of the certificate to be modified."})),
        "name": Elem.STRING(T({'de': "Anzeigename des Zertifikats.", 'en': "Display name of the certificate."})),
        "cert": Elem.STRING(T({'de': "Zertifikat im PEM-Format", 'en': "Certificate in PEM format"})),
    }), command_is_action=True),

    Func("remove", FuncType.COMMAND, Elem.OBJECT(T({'de': "Löscht ein vorhandenes TLS-Zertifikat.", 'en': "Deletes an existing TLS certificate."}), members={
        "id": Elem.INT(T({'de': "ID des Zertifikats, dass gelöscht werden soll.", 'en': "ID of the certificate to be deleted."}))
    }), command_is_action=True),
])
