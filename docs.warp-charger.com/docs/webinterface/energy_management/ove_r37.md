---
sidebar_position: 13
---

# OVE R 37

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc4']} />

Die OVE-Richtlinie R 37 legt in Österreich Anforderungen an Ladeeinrichtungen für Elektrofahrzeuge fest, mit denen das Stromnetz gestützt wird. Dazu gehören z.B. das Abschalten bei Unterspannung und ein verzögertes, langsames Wiederzuschalten nach einer Netzstörung. Der WARP4 Charger setzt diese Funktionen direkt im Ladecontroller um.

Die Seite erscheint unter `Energiemanagement`, wenn unter [System -> Einstellungen](/docs/webinterface/system/settings.md) als Land **Österreich** ausgewählt ist. Ist OVE R 37 aktiviert, bleibt die Seite auch nach einem Wechsel des Landes sichtbar.

![image](/img/webinterface/energy_management/ove_r37.png)

:::note

Die Konfiguration darf nur von einer Elektrofachkraft geändert werden. Zum Speichern ist das Elektriker-Passwort `Ele4223W` erforderlich.

:::

## Funktionen

Bei aktiviertem OVE R 37 gelten die folgenden Funktionen. Spannung, Strom und Frequenz werden dabei vom Stromzähler der Wallbox gemessen.

- **Unterspannungsauslösung**: Liegt die Spannung einer Phase länger als die Beobachtungszeit unter der Auslöseschwelle, wird der Ladevorgang unterbrochen.
- **Wiederzuschaltung**: Nach einer Auslösung wird erst wieder geladen, wenn alle Phasenspannungen zwischen 0,9 und 1,09 pu (207 V bis 251 V) und die Netzfrequenz zwischen 49,9 Hz und 50,1 Hz liegen und diese Bedingungen für die gesamte Wiederzuschalt-Wartezeit erfüllt sind. Wird eine Bedingung währenddessen verletzt, beginnt die Wartezeit von vorne.
- **Hochlauframpe**: Nach dem Wiederzuschalten beginnt der Ladestrom bei 6 A und steigt um 1 A pro Minute bis auf 32 A.
- **Neustart**: Nach einem Neustart der Wallbox (z.B. nach einem Stromausfall) wird ein Ladevorgang nicht sofort fortgesetzt. Ist innerhalb von 30 Sekunden ein Fahrzeug angeschlossen, läuft derselbe Ablauf wie nach einer Auslösung (Wartezeit und Hochlauframpe).
- **Symmetrie**: Ein- und zweiphasiges Laden ist auf 16 A begrenzt. Beim dreiphasigen Laden wird der Ladestrom auf 16 A begrenzt, wenn sich die Ströme der Phasen um mehr als 16 A unterscheiden.
- **Zufällige Startverzögerung**: Ladevorgänge mit vorgegebener Startzeit, z.B. über eine [Automatisierungsregel](/docs/webinterface/wallbox/automation.md), starten mit einer zufälligen Verzögerung von 0 bis 300 Sekunden.

Ob OVE R 37 den Ladevorgang gerade blockiert oder begrenzt, ist auch auf der Seite [Ladestatus](/docs/webinterface/wallbox/charge_status.md) unter der Ladestromgrenze **OVE R 37** zu sehen.

## Konfiguration

### OVE R 37 aktiviert

Aktiviert oder deaktiviert die OVE-R-37-Funktionen.

Die folgenden Parameter sind im Auslieferungszustand bereits auf die von der Richtlinie geforderten Standardwerte eingestellt. In der Regel muss OVE R 37 nur aktiviert werden.

### Unterspannungs-Auslöseschwelle

Die Spannung, unterhalb der ausgelöst wird. Sie wird in Tausendstel der Nennspannung von 230 V angegeben (‰ pu). Der Standardwert 800 entspricht 0,80 pu, also etwa 184 V.

### Unterspannungs-Beobachtungszeit

Wie lange die Spannung unter der Auslöseschwelle liegen muss, bevor ausgelöst wird. Standardwert: 3000 ms.

### Wiederzuschalt-Wartezeit

Wie lange die Bedingungen für die Wiederzuschaltung erfüllt sein müssen, bevor nach einer Auslösung wieder geladen wird. Zulässig sind 0 bis 300 Sekunden, Standardwert: 60 s.

### Elektriker-Passwort

Wird zum Speichern der Konfiguration benötigt.

## Status

Ist OVE R 37 aktiviert, wird oben auf der Seite der aktuelle Zustand angezeigt:

- **OVE-R-37-Zustand**:
  - **Normal**: Laden ist uneingeschränkt möglich.
  - **Ausgelöst**: Der Ladevorgang wurde unterbrochen, die Bedingungen für die Wiederzuschaltung sind nicht erfüllt.
  - **Warten auf Wiederzuschaltung**: Die Bedingungen sind erfüllt, die Wiederzuschalt-Wartezeit läuft.
  - **Hochlauf**: Die Hochlauframpe ist aktiv.
  - **Warten nach Neustart**: Die Wallbox wurde vor weniger als 30 Sekunden neu gestartet.
- **Auslösegrund**: Der Grund der letzten Auslösung, z.B. Unterspannung.
- **Ladestart-Verzögerung**: Wird angezeigt, solange die zufällige Startverzögerung läuft.
- **Spannung im Bereich**: Ob alle angeschlossenen Phasenspannungen zwischen 0,9 und 1,1 pu (207 V bis 253 V) liegen. Eine Spannung außerhalb dieses Bereichs löst nicht automatisch aus. Ausgelöst wird erst unterhalb der Unterspannungs-Auslöseschwelle.
- **Frequenz im Bereich**: Ob die Netzfrequenz zwischen 49,9 Hz und 50,1 Hz liegt. Die Frequenz löst einen laufenden Ladevorgang nicht aus, sie ist nur eine Bedingung für die Wiederzuschaltung.

## Weitere Informationen

- [System -> Einstellungen](/docs/webinterface/system/settings.md): Auswahl des Landes
- [Ladestatus](/docs/webinterface/wallbox/charge_status.md): Ladestromgrenzen der Wallbox
