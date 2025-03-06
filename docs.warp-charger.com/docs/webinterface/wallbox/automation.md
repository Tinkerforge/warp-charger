---
sidebar_position: 4
---

# Automatisierung

![image](/img/webinterface/wallbox/warp-automation.png)


Der WARP3 Charger kann automatisiert Regeln ausführen.
So kann etwa der Empfang von MQTT-Nachrichten, das
Auslesen eines NFC-Tags oder eine andere Bedingung Regeln ausführen,
die beispielsweise Ladevorgänge steuern,
MQTT-Nachrichten schicken oder den konfigurierbaren
Ausgang schalten. Es können bis zu 14 Regeln definiert
werden, um Vorgänge zu automatisieren. Dazu sind jeweils
eine Bedingung und die Aktion der Wallbox bei Erfüllung
der Bedingung zu definieren.

## Beispiel: Ladevorgänge nur zu bestimmten Uhrzeiten zulassen

Hierzu muss als Bedingung *Zeitpunkt*
gewählt werden. Anschließend kann über die Einstellung *Tag* und
*Uhrzeit* ein Zeitpunkt definiert werden, an
dem die Wallbox eine Aktion ausführt. In diesem Fall soll
die Aktion *Steuere Ladevorgang* und *Laden blockieren*
gewählt werden. Nach Hinzufügen der Regel blockiert die
Wallbox nun zum definierten Zeitpunkt das Laden. Mit
einer weiteren Regel kann das Laden zu einem späteren
Zeitpunkt wieder freigegeben werden. Dazu kann eine zweite Regel
eingefügt werden, indem der Zeitpunkt der Freigabe definiert und die
Aktion *Laden freigeben* gewählt wird.
Mittels dieser zwei Regeln kann also die Ladung an
gewissen Tagen und/oder Uhrzeiten eingeschränkt werden.
