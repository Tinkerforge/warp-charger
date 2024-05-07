---
sidebar_position: 1
---

# Einführung

WARP Charger Smart Pro können über MQTT und HTTP ihren aktuellen Zustand melden und gesteuert werden. Während die MQTT-API zunächst aktiviert und konfiguriert werden muss, kann die HTTP-API sofort verwendet werden, da sie auch vom Webinterface selbst benutzt wird.

## MQTT

:::warning

Falls die Wallbox mit ioBroker verwendet wird, sollte ein anderer MQTT-Broker, als der, der als ioBroker-Addon verfügbar ist, verwendet werden. Der MQTT-Broker von ioBroker verhält sich in mehreren Belangen nicht konform zur MQTT-Spezifikation, was zu verschiedenen Problemen führt.

:::

### Konfiguration

Damit die Wallbox über MQTT kommuniziert, muss zunächst im Webinterface die Verbindung zum MQTT-Broker konfiguriert werden. Folgende Einstellungen können vorgenommen werden:

- **Broker-Hostname oder IP-Adresse** Der Hostname oder die IP-Adresse des Brokers zu dem sich die Wallbox verbinden soll.
- **Broker-Port** Der Port unter dem der Broker erreichbar ist. Der typische MQTT-Port 1883 ist voreingestellt.
- **Broker-Benutzername und Passwort** Manche Broker unterstützen eine Authentifizierung mit Benutzername und Passwort.
- **Topic-Präfix** Dieser Präfix wird allen Topics vorangestellt, die die Wallbox verwendet. Voreingestellt ist `warp/AbCd`, `warp2/AbCd`, `warp3/AbCd` bzw. `wem/AbCd` wobei `AbCd` eine eindeutige Kennung pro Wallbox ist, es sind aber andere Präfixe wie z.B. garage_links möglich. Falls mehrere Wallboxen mit dem selben Broker kommunizieren müssen eindeutige Präfixe pro Box gewählt werden.
- **Client-ID** Mit dieser ID registriert sich die Wallbox beim Broker.

Nachdem die Konfiguration gesetzt und der "MQTT aktiviert"-Schalter gesetzt ist, kann die Konfiguration gespeichert werden. Der ESP startet dann neu und verbindet sich zum Broker. Auf der Status-Seite wird angezeigt, ob die Verbindung aufgebaut werden konnte.

![MQTT-Einstellungsseite](/img/mqtt/mqtt_ui.png)

Im Folgenden werden die [`mosquitto_pub`](https://mosquitto.org/man/mosquitto_pub-1.html) und [`mosquitto_sub`](https://mosquitto.org/man/mosquitto_sub-1.html)-Befehle des [Mosquitto-MQTT-Brokers](https://mosquitto.org/) verwendet, um mit dem Broker zu kommunizieren.

### Grundlagen

Wenn die Verbindung zum Broker erfolgreich aufgebaut wurde, sollten jetzt bereits erste Nachrichten der Wallbox eintreffen. Sämtliche Nachrichten der Wallbox sind Strings im [JSON-Format](https://www.json.org/json-de.html). Genauso müssen alle Nachrichten, die zur Wallbox geschickt werden, das JSON-Format einhalten.

Mit
```bash
mosquitto_sub -v -t "warp/AbCd/#"
```
können alle Nachrichten der Wallbox angezeigt werden. (Den Präfix `warp/AbCd` durch den konfigurierten ersetzen) Es könnte z.B. die folgende Nachricht auf [`warp/AbCd/evse/state`](api_referenz/evse#evse_state) empfangen werden:
```jsx
{
  "iec61851_state": 1,
  "charger_state": 2,
  "contactor_state": 1,
  "contactor_error": 0,
  "allowed_charging_current": 32000,
  "error_state": 0,
  "lock_state": 0,
  "dc_fault_current_state": 0
}
```
Die Nachrichten des Topics [`evse/state`](api_referenz/evse#evse_state) geben einen Überblick über den Zustand des Ladecontrollers. Beispielsweise liegt der erlaubte Ladestrom gerade bei 32000, also 32 Ampere.

Durch Senden der Nachricht `{"current":8000}` an das Topic  [`evse/global_current_update`](api_referenz/evse#evse_global_current_update) kann der Ladestrom auf 8 Ampere begrenzt werden, zum Beispiel so:
```bash
mosquitto_pub -t "warp/AbCd/evse/global_current_update" -m "{\"current\": 8000}"
```
(Damit die Beispiele auch mit cmd.exe von Windows kompatibel sind, werden nur doppelte Anführungszeichen verwendet. Anführungszeichen in JSON-Nachrichten müssen deshalb mit \ escapt werden.)

:::info

Zur Vereinfachung wird hier [`evse/global_current_update`](api_referenz/evse#evse_global_current) verwendet. Der mit dieser API gesetzte Strom wird im Flash des Ladecontrollers gespeichert und sollte deshalb **nicht häufig** gesetzt werden, um den Flash zu schonen. Häufige Änderungen des Ladestroms (z.B. für eine externe Steuerung, ein PV-Überschussladen ö.Ä. ) sollten stattdessen über die API [`evse/external_current_update`](api_referenz/evse#evse_external_current) erfolgen, die auf der Unterseite Wallbox -> Einstellung mit dem Punkt "Externe Steuerung" aktiviert werden kann.

:::

Der Ladestrom ist jetzt auf 8 Ampere begrenzt, was die Wallbox durch eine neue Nachricht anzeigt:

```jsx
{
  "iec61851_state": 1,
  "charger_state": 2,
  "contactor_state": 1,
  "contactor_error": 0,
  "allowed_charging_current": 8000,
  "error_state": 0,
  "lock_state": 0,
  "dc_fault_current_state": 0
}
```

APIs, die aus einem JSON-Objekt mit exakt einem Wert bestehen, können abgekürzt werden, indem direkt der Wert geschickt wird:
```bash
mosquitto_pub -t "warp/AbCd/evse/global_current_update" -m 8000
```

## HTTP

### Konfiguration

Die HTTP-API kann ohne vorherige Konfiguration verwendet werden. Optional können auf der Benutzer- (bei Wallboxen) bzw. der Zugangsdaten-Unterseite (beim WARP Energy Manager) Zugangsdaten für das Webinterface und die HTTP-API konfiguriert werden. Alle Requests müssen dann mit der [Digest access authentication](https://en.wikipedia.org/wiki/Digest_access_authentication) authentisiert werden. Nicht authentifizierte Requests werden von der Wallbox mit dem HTTP-Code [401](https://http.cat/401) beantwortet. Eine Ausnahme bildet die Hauptseite des Webinterfaces, die den meisten Browsern auf einen nicht authentifizierten Request mit der Login-Seite antwortet.

### Grundlagen

Die HTTP-API ist strukturell identisch zur MQTT-API: Wenn die MQTT-API beispielsweise das Topic [`warp/AbCd/evse/state`](api_referenz/evse#evse_state) verwendet, kann die selbe API über die URL `http://warp-AbCd/evse/state erreicht werden`. Die HTTP-API verfügt allerdings über einige fortgeschrittene Funktionen, die nicht über MQTT verfügbar sind. Es können zusätzlich die [WebSockets](https://en.wikipedia.org/wiki/WebSocket) unter z.B. `ws://warp-AbCd/ws` verwendet werden. Über eine WebSocket-Verbindung überträgt die Wallbox (analog zu MQTT) automatisch aktualisierte Werte.

Um Analog zum MQTT-Beispiel alle von der Wallbox gesendeten Nachrichten zu empfangen, kann eine WebSocket-Verbindung benutzt werden. Hierzu und für die weiteren Beispiele werden [websocat](https://github.com/vi/websocat) und [curl](https://curl.se/) verwendet und davon ausgegangen, dass die Wallbox unter dem Hostnamen warp-AbCd erreichbar ist.

Mit websocat ws://warp-AbCd/ws könnte unter anderem folgende Nachricht empfangen werden:
```jsx
{
  "topic": "evse/state",
  "payload": {
    "iec61851_state": 1,
    "charger_state": 2,
    "contactor_state": 1,
    "contactor_error": 0,
    "allowed_charging_current": 32000,
    "error_state": 0,
    "lock_state": 0,
    "dc_fault_current_state": 0
  }
}
```

Diese Nachricht ist äquivalent zu der aus den MQTT-Grundlagen, allerdings ist das MQTT-Topic hier Teil der JSON-Struktur, da kein vergleichbares Konzept für WebSockets existiert.

Wenn nur eine Information abgefragt werden soll, kann mit curl eine einzelne URL aufgerufen werden:
```bash
curl -s http://warp-AbCd/evse/state
```
liefert äquivalente JSON-Daten:
```jsx
{
  "iec61851_state": 1,
  "charger_state": 2,
  "contactor_state": 1,
  "contactor_error": 0,
  "allowed_charging_current": 32000,
  "error_state": 0,
  "lock_state": 0,
  "dc_fault_current_state": 0
}
```
Mit [jq](https://stedolan.github.io/jq/) können einzelne Werte aus einem JSON-Objekt extrahiert werden:
```bash
curl -s http://warp-AbCd/evse/state | jq ".allowed_charging_current"
```
gibt 32000, also den erlaubten Ladestrom von 32 Ampere zurück.

Jetzt soll der Ladestrom auf 8 Ampere begrenzt werden. Dafür wird die Nachricht `{"current":8000}` an die URL http://warp-AbCd/evse/global_current_update geschickt:
```bash
curl -X PUT -d "{\"current\":8000}" warp-AbCd/evse/global_current_update
```

:::info

Zur Vereinfachung wird hier [`evse/global_current_update`](api_referenz/evse#evse_global_current) verwendet. Der mit dieser API gesetzte Strom wird im Flash des Ladecontrollers gespeichert und sollte deshalb **nicht häufig** gesetzt werden, um den Flash zu schonen. Häufige Änderungen des Ladestroms (z.B. für eine externe Steuerung, ein PV-Überschussladen ö.Ä. ) sollten stattdessen über die API [`evse/external_current_update`](api_referenz/evse#evse_external_current) erfolgen, die auf der Unterseite Wallbox -> Einstellung mit dem Punkt "Externe Steuerung" aktiviert werden kann.

:::

Folgende Vereinfachungen sind möglich:
- Im Beispiel wird die HTTP-Methode `PUT` verwendet, `POST` wird aber auch akzeptiert. curl verwendet automatisch `POST`, wenn Daten geschickt werden sollen.
- APIs, die auf der Adresse `warp-AbCd/X` gelesen und auf `warp-AbCd/X_update` geschrieben werden können, können (nur über HTTP!) auch auf `warp-AbCd/X geschrieben werden.
- APIs, die aus einem JSON-Objekt mit exakt einem Wert bestehen, können abgekürzt werden, indem direkt der Wert geschickt wird.

Kombiniert kann das Setzen des Ladestroms also wie folgt abgekürzt werden:
```bash
curl -d 8000 warp-AbCd/evse/global_current
```

Jetzt sollte
```bash
curl -s http://warp-AbCd/evse/state | jq ".allowed_charging_current"
```
8000, also 8 Ampere zurückgeben.

## Unions {#unions}

Verschiedene APIs des WARP Chargers benutzen [Unions](https://de.wikipedia.org/wiki/Verbund_(Datentyp)#Unions) (auch bekannt als [Summentypen](https://de.wikipedia.org/wiki/Algebraischer_Datentyp#Summentyp)), um veränderliche Objekte auszudrücken. Eine Union besteht aus deren Daten, sowie einem Tag, dass angibt welche Variante der Daten verwendet wird. Als Tag wird immer eine Zahl verwendet. Tag und Daten werden in einem JSON-Array mit immer genau zwei Einträgen dargestellt. Ein Wert der entweder ein Objekt mit zwei Einträgen oder eine Zeichenkette sein soll, könnte z.B. so ausgedrückt werden:
```jsx
[0, {"entry_a": 123, "entry_b": "abc"}]
```
bzw.
```jsx
[1, "Hello World"]
```

Ein konkreteres Beispiel: Die API [`meters/1/config`](api_referenz/meters#meters_X_config) konfiguriert den Stromzähler im Slot 1. Eine Wallbox im Auslieferungszustand hat nur einen Stromzähler auf Slot 0 (den möglicherweise intern verbauten Zähler) konfiguriert. Deshalb hat `meters/1/config` standardmäßig den Wert
```jsx
[0, null]
```
also das Tag 0 mit keinen weiteren Daten (ausgedrückt durch `null`)
Laut [Dokumentation dieser API](api_referenz/meters#meters_X_config) bedeutet das Tag 0, dass kein Stromzähler konfiguriert ist.

Soll stattdessen ein Zähler konfiguriert werden, der seine Werte über das SMA Speedwire-Protokoll empfängt (Tag 7), wird zusätzlich der Anzeigename des Zählers benötigt. Es muss also die folgende Konfiguration gesetzt werden:
```jsx
[7, { "display_name": "Mein Zähler" }]
```

Um den Inhalt einer bestimmten Variante einer Union zu ermitteln, kann das Tag geändert werden, ohne neue Daten zu setzen. Wenn beispielsweise die folgende Konfiguration gesetzt wird:
```jsx
[6, null]
```
und danach `meters/1/config` gelesen wird, wird der folgende Wert zurückgegeben:
```jsx
[6, { "display_name": "", "host": "", "port": 502, "table": [0, null] }]
```
Tag 6 ist ein Modbus-TCP-Zähler, für den der Anzeigename, Host und Port sowie die zu verwendende Registertabelle angegeben werden müssen. Die Registertabelle ist wiederum eine Union.
