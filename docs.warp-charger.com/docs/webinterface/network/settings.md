---
sidebar_position: 1
---

# Einstellungen

![image](/img/webinterface/network/settings.png)

Auf dieser Seite kann der *Hostname* des [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) in allen
verbundenen Netzwerken konfiguriert werden. Außerdem kann *mDNS* aktiviert oder deaktiviert werden. Über mDNS können andere Geräte im Netzwerk den WARP3 Charger/WARP Energy Manager
finden. Damit wird zum Beispiel das Einrichten eines Lastmanagementverbunds vereinfacht.

Über den **Verbindungsmodus** lässt sich festlegen, ob das Webinterface über HTTP (unsicher), HTTPS (sicher) oder beides gleichzeitig erreichbar sein soll. Der jeweilige *Port* kann konfiguriert werden (Standard ist Port 80 für HTTP bzw. 443 für HTTPS). Für HTTPS kann ein eigenes *Zertifikat* im PEM- oder DER-Format sowie der zugehörige *private Schlüssel* hinterlegt werden. Wird kein Zertifikat hinterlegt, wird ein internes selbstsigniertes Zertifikat verwendet. Eigene Zertifikate und Schlüssel können über die [TLS-Zertifikate](/docs/webinterface/system/tls-certificates)-Seite hochgeladen werden.
