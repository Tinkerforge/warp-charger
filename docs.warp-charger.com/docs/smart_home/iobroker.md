---
sidebar_position: 4
---

# ioBroker

## Einführung

Dein [WARP Charger](/docs/warp_charger/introduction) oder [WARP Energy Manager](/docs/warp_energy_manager/introduction) ist mit [ioBroker](https://www.iobroker.net) kompatibel.
ioBroker ist eine freie Softwarelösung zum Zusammenführen von Komponenten zur Gebäudeautomatisierung in einer Plattform.

Die Anbindung von Geräten an ioBroker erfolgt über eine Vielzahl von (Software-)Adaptern.
Zur Anbindung der WARP Geräte stehen mehrere Adapter zur Verfügung (z.B. [OCPP](/docs/interfaces/ocpp), [Modbus/TCP](/docs/interfaces/modbus/introduction) und [MQTT](/docs/interfaces/mqtt_http/introduction)).
In dieser Einführung beschränken wir uns auf MQTT.

:::note
Dem aufmerksamen Nutzer wird vielleicht aufgefallen sein, dass es einen [WARP Adapter](https://github.com/pottio/ioBroker.warp) gibt, welcher von einem Community-Mitglied entwickelt wurde.
Wir schätzen es sehr, dass die Community Integrationen für WARP Geräte entwickelt.
Leider können wir diesen Adapter in seiner aktuellen Version 1.2.2 **nicht** empfehlen, da dieser nicht mit dem aktualisierten Webserver der WARP Firmware kompatibel ist, was zu hoher Auslastung und bis zum Absturz der Software deines WARP Geräts führen kann. 
:::

## Einbindung via MQTT

Wir gehen davon aus, dass du bereits ein laufendes ioBroker System hast.

In "Adapter" wird zuerst der MQTT Broker/Client installiert. 

![MQTT Adapter Install](/img/smart_home/iobroker/install_mqtt.png)

Anschließend muss der MQTT Adapter als Client oder als Server konfiguriert werden. 

- Wenn bereits ein MQTT Broker im Netz vorhanden ist, wird MQTT als "Client/Subscriber" konfiguriert und die Adresse des Brokers in den Verbindungseinstellungen hinterlegt. Die restlichen Einstellungen können bei ihren Standardwerten belassen werden.
- Ist noch kein MQTT Broker im Netz vorhanden, wird der Adapter als "Server/Broker" konfiguriert. Die Authentifizierung ist optional, wird aber empfohlen. 


![MQTT Adapter Configuration](/img/smart_home/iobroker/configure_mqtt.png)

MQTT sollte wie gezeigt konfiguriert sein. 
Wichtig sind das die beiden markierten Optionen deaktiviert sind da diese die Verbindung verlangsamen und zu fehlerhaftem MQTT Verhalten führen können.

![MQTT Adapter Configuration](/img/smart_home/iobroker/mqtt_settings.png)

## Verbinden des WARP-Geräts

Der WARP Charger/WARP Energy Manager wird wie in [WARP Adapter](/docs/interfaces/mqtt_http/introduction) beschrieben konfiguriert. 
Als Broker-Hostname wird dabei die Adresse des ioBrokers eingetragen.
Der Discovery-Modus kann deaktiviert werden da dieser nicht von ioBroker unterstützt wird. 

## Integration in ioBroker
### Auslesen von Werten

Die MQTT-Nachrichten von WARP Geräten sind JSON-Objekte.
ioBroker interpretiert diese Objekte standardmäßig als Strings und verarbeitet diese nicht weiter.
Um die weitere Verarbeitung von Daten zu vereinfachen, ist es am besten, diese Werte als Aliase zu extrahieren. Dafür mit Rechtsklick auf den gewünschten Datenpunkt → **Alias erstellen**.

![Begin Alias Configure](/img/smart_home/iobroker/select_alias_configure.png)

Diesen Alias kann man dann je nach Wert konfigurieren.
In diesem Beispiel wird ein Wert aus einem Array extrahiert. 
Wichtig sind die Read Formulas mit denen der Wert aus dem JSON extrahiert wird, der Wert muss zuerst geparsed und anschließend aus dem JSON ausgelesen werden.

![Alias Example Configuration](/img/smart_home/iobroker/alias_config_example.png)

Welche Werte es gibt und wie diese strukturiert sind, findet man in der [API-Dokumentation](/docs/api_reference).

Nach dem Anlegen von Aliasen können diese in Visualisierungen oder weitere Verarbeitungen eingebunden werden. 

### Schreiben von Werten

WARP Geräte erwarten Schreibzugriffe auf dem jeweiligen Topic mit angehängtem `_update`-Suffix.
Beispiel: Der Wert `charge_manager/charge_modes` wird gelesen, aber Änderungen müssen an `charge_manager/charge_modes_update` gesendet werden.

Da ioBroker diese Weiterleitung nicht automatisch übernimmt, wird dafür ein Skript im **JavaScript-Adapter** benötigt.

Das folgende Skript zeigt eine Hilfsfunktion `warpWrite` mit 3 Anwendungsbeispielen um , die einen beliebigen Wert als JSON-Nachricht an das korrekte `_update`-Topic sendet. 

```javascript
// ================================================================
// WARP Gerät: Werte über MQTT schreiben – ioBroker JavaScript-Adapter
// ================================================================

const MQTT_ADAPTER = 'mqtt.0';     // Instanz des MQTT-Adapters
const WARP_PREFIX  = 'warp3/1abc'; // Topic-Präfix (siehe WARP MQTT-Konfiguration)

/**
 * Schreibt einen Wert auf ein WARP MQTT-Topic.
 * Das WARP Gerät erwartet Schreibzugriffe auf dem Topic mit Suffix "_update". 
 * Aktionen werden ohne Suffix gesendet.
 *
 * @param {string} subTopic     - Topic ohne Präfix, z.B. "charge_manager/charge_modes"
 * @param {*}      value        - Zu schreibender Wert (wird als JSON serialisiert)
 * @param {bool}   appendUpdate - Ob ein _update suffix angehängt wird
 * @param {bool}   retainMsg    - Die message soll retained werden. Nur bei Schreibzugriffen
 */
function warpWrite(subTopic, value, appendUpdate = true, retainMsg = true) {
    let topic = WARP_PREFIX + '/' + subTopic;
    if(appendUpdate) {
        topic   = topic + '_update';
    } 
    const payload = JSON.stringify(value);

    sendTo(MQTT_ADAPTER, 'sendMessage2Client', {
        topic:   topic,
        message: payload,
        retain:  retainMsg
    });

    log('[WARP] ' + topic + ' ← ' + payload);
}


// ----------------------------------------------------------------
// Beispiel 1: Einmalig einen Wert schreiben
// Setzt charge_manager/charge_modes auf [2]
// ----------------------------------------------------------------
warpWrite('charge_manager/charge_modes', [2]);


// ----------------------------------------------------------------
// Beispiel 2: Reaktiv – Wert schreiben, wenn sich ein
//             ioBroker-Datenpunkt ändert (z.B. ein VIS-Schalter)
// ----------------------------------------------------------------
on({ id: '0_userdata.0.warp.lademodus', change: 'ne' }, function (obj) {
    const modus = Number(obj.state.val);
    warpWrite('charge_manager/charge_modes', [modus]);
});


// ----------------------------------------------------------------
// Beispiel 3:  Sende ein Befehl den Ladevorgang zu starten. 
//              Befehle müssen ohne Suffix gesendet werden. Der Inhalt ist null, "", false, 0, [] oder {}. 
//              Befehle werden nicht retained. 
// ----------------------------------------------------------------
warpWrite('evse/start_charging', "", false, false);
```

:::note
Das Skript setzt voraus, dass der [JavaScript-Adapter](https://www.iobroker.net/#en/adapters/adapterref/iobroker.javascript/README.md) installiert ist.
Es kann unter **Skripte** als neues Skript angelegt werden.

Der `sendTo`-Aufruf mit `sendMessage2Client` ist die offizielle API des MQTT-Adapters zum Veröffentlichen von Nachrichten und funktioniert sowohl im **Server/Broker**- als auch im **Client/Subscriber**-Modus.
:::

Welche Topics und welche Werte akzeptiert werden, ist in der [API-Dokumentation](/docs/api_reference) beschrieben.
