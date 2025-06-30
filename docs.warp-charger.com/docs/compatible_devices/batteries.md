---
sidebar_position: 4
---

# Batteriespeicher

:::note

    Die Steuerung von Batteriespeichern befindet sich zur Zeit noch in der Entwicklung und ist noch nicht Teil der Release-Firmware!
    
    Eine Beta-Firmware wird zeitnah im Forum auf [Tinkerunity](https://tinkerunity.org) veröffentlicht.

    Zur Zeit müssen noch die jeweiligen Register zur Steuerung angelegt werden. Ein Export bzw. Import dieser Einstellungen ist möglich. Zukünftig wird es, analog zu den Stromzählern, natürlich auswählbare "Presets" für diese Speicher geben.
    Das Verhalten ist zur Zeit durch Anlegen von Regeln zu definieren. Nach der Testphase ist es geplant diese Regeln durch ein bedienerfreundlicheres Nutzerinterface zu ersetzen oder zu ergänzen.

    Es kann nicht garantiert werden, dass diese Batteriespeicher-Einstellungen bei einem Firmwareupdate korrekt übernommen werden!
:::


## Steuerung von Batteriespeichern

Viele Hersteller unterstützen die externe Steuerung von Batteriespeichern mittels [Modbus/TCP](/docs/compatible_devices/interfaces#modbustcp) Schnittstelle.
Meist wird der Batteriespeicher über den angeschlossenen Wechselrichter gesteuert und nicht die Batterie direkt. Die zur Verfügung gestellten Register zur Steuerung unterscheiden sich je nach Hersteller und Gerät, so dass nicht alle Geräte
alle Funktionen unterstützen. Auch die Umsetzung der jeweiligen Funktion unterscheidet sich stark von Gerät zu Gerät!

### Generelle Idee

Der Speicher wird von uns nicht geregelt. Er übt seine vom Hersteller definierte Funktion aus. Das heißt im Normalfall wird ein PV-Überschuss zur Ladung des Speichers genutzt und der Speicher versucht die Leistungsaufnahme eines Verbrauchers
zu kompensieren. Mit den nachfolgend aufgeführten Funktionen kann aber in diese Regelung eingegriffen werden.

## Anlegen eines Batteriespeichers

Wir ermöglichen es einen Batteriespeicher mittels Modbus/TCP zu steuern. Analog zu den Stromzählern muss der Host, Port und der Adressmodus definiert werden. 

Für diesen Speicher können anschließend drei nachfolgend aufgelistet Funktionen implementiert werden. Es müssen nicht alle Funktionen für den jeweiligen Speicher
implementiert werden. Wird aber eine Funktion implementiert, so muss auch die Aufhebung dieser Funktion implementiert werden.

Es können einzelne Register, aber auch mehrere Register in einem Befehl geschrieben werden. Es wird empfohlen Register, die aufeinanderfolgend sind, als ein Block in einem Befehl zu schreiben. 

### Laden vom Netz erlauben

Diese Funktion versucht den Speicher zu zwingen, auf 100% SoC zu laden. Wird die Ladeleistung nicht über PV gedeckt, so soll der Speicher mit Strom aus dem Netz laden. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Genereller "Minimum SoC" auf 100% setzen. Dies funktioniert aber nur, wenn das System dann auch Strom aus dem Netz zum Laden bezieht.
 * Setzen und Aktivieren eines Ladeplans mit dem Uhrzeitbereich 00:00-23:59 Uhr und einem Ziel-SoC von 100%.

### Entladen verbieten

Mit dieser Funktion wird dem Speicher verboten zu entladen. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Setzen des "Maximalen Entladestroms" auf 0A.
 * Setzen des "Minimum SoC" auf 100%. Dies funktioniert nur, wenn das System dann NICHT Strom aus dem Netz zum Laden bezieht sonder nur das Entladen deaktiviert.

### Laden verbieten

Diese Funktion verbietet dem Speicher das Laden. Folgende Möglichkeiten sind uns bekannt diese Funktion zu implementieren:

 * Setzen des "Maximalen Ladestroms" auf 0A.


## Verwendung des Batteriespeichers - Definition von Regeln

Für jede Funktion können mehrere Regeln definiert werden. Sind die Bedingungen einer Regel erfüllt, so wird die dazugehörige Funktion ausgeführt. Ist keine Regel für eine Funktion erfüllt, so wird die Funktion deaktiviert. Sprich es wird die Aufhebung der Funktion ausgeführt.

Jede Regel besteht aus einer Beschreibung (Freitext für den Nutzer), der Angabe eines Batterieladestands (SoC), eines Strompreises und einem Wert der PV-Ertragsprognose. Der Vergleich zu den angegebenen Werten kann als "kleiner als" oder "größer als" definiert werden.
Soll ein Wert nicht verwendet werden, so ist "wird ignoriert" zu konfigurieren.

Folgene Anwendungen sind als Beispiel möglich:

### Netz-Ladung zu den günstigsten Stunden
Wenn die PV-Prognose für den aktuellen Tag unter einem gewissen Wert liegt, wird der Batteriespeicher bis zu einem gewissen SoC in den günstigsten Stunden aus dem Netz geladen.

**Beispiel:**

*Unter "Regeln für Ladung-vom-Netz-Erlaubnis" eine Regel anlegen mit der Beschreibung "Hausspeicher Minimum": Wenn Batterieladestand kleiner als 50% und dynamischer Strompreis kleiner als 30ct und PV-Ertragsprognose kleiner als 20kWh.*

Die Idee dahinter ist, dass ein minimaler Ladestand von 50% eingehalten werden soll, wenn für den Tag ein geringer PV-Ertrag erwartet wird (in diesem Fall 20kWh). Geladen werden soll aber nur, wenn der Strompreis kleiner 30ct beträgt.
Es ist denkbar weitere Regeln anzulegen, die andere Bedingungen definieren. So könnte als Beispiel die Batterie weiter aufgeladen werden, wenn der Strompreis geringer ist oder der erwartete PV-Ertrag geringer.

### Batteriespeicher im "Schnell"-Lademodus nicht entladen
Im Wallbox-Lademodus "Schnell" kann das Entladen des Haus-Batteriespeichers verhindert werden. Diese Funktion ist vordefiniert und muss nur mittels "Batterieentladung beim Schnellladen verbieten" aktiviert werden.

### Netzdienliches Laden des Batteriespeichers
Morgens, wenn das Netz noch den PV-Strom verwenden kann und somit noch eine Einspeisevergütung gezahlt wird, wird der Batteriespeicher nicht geladen und stattdessen in das Stromnetz eingespeist. Wenn dann gegen Mittag der PV-Strom nicht vom Stromnetz benötigt wird
und somit keine Einspeisevergütung mehr gezahlt wird, wird der Speicher geladen. Siehe auch [HTW-Berlin: Dein Stromspeicher kann mehr!](https://solar.htw-berlin.de/dein-stromspeicher-kann-mehr/).

**Beispiel:**

*Unter "Regeln für Bat­te­rie­la­dungs-Verbot" eine Regel anlegen mit der Beschreibung "Speicheroptimierung": Wenn Batterieladestand größer 60% und dynamischer Strompreis größer als 20ct und PV-Ertragsprognose größer als 20kWh.*

Der betrachtete dynamische Strompreis beinhaltet alle konfigurierten Kosten. Die Annahme in diesem Beispiel ist, dass die weiteren Preisbestandteile 20ct pro kWh ausmachen. Das heißt bei einem Strompreis größer als 20ct sind die Strom-Erzeugungskosten noch positiv.
In diesem Fall wird der Strom vom Netz also noch benötigt und man erhält noch eine Einspeisevergütung. Das Ziel der Regel ist es, den Speicher in diesem Fall also nicht zu laden und stattdessen den PV-Überschuss in das Stromnetz einzuspeisen. Wird der "Strompreis negativ",
also der dynamische Strompreis fällt unter die definierten 20ct, dann würde die Regel aufgehoben und der Speicher ganz normal über den PV-Überschuss geladen.

Mit den Parametern "Batterieladestand" und "PV-Ertragsprognose" kann gesteuert werden, wie viel vom PV-Ertrag des Tages noch übrig bleiben muss um den Batteriespeicher an dem Tag noch zu laden. Im Winter, also bei geringem PV-Ertrag, möchte man zum Beispiel vermutlich nicht,
dass der PV-Überschuss nicht auch morgens schon in die Batterie fließt. Es können mehrere Regeln angelegt werden, die verschiedene Mindest-Ladestände mit PV-Ertragsprognosen verknüpfen.




## Unterstützte Hersteller

:::note

    Wir sind aktuell dabei Erfahrungen mit den verschiedenen Geräten zu sammeln und sind dabei auf eure Mithilfe angewiesen! Die folgenden Geräte/Batteriespeicher konnten wir bereits testen.
    Ein jeweiliges Registerset zum Import steht jeweils zum Download bereit.

    Die Einstellungen der Registersets können natürlich nach den eigenen Wünschen angepasst werden. Als Beispiel Minimum-SoC anstatt 10% auf 5% o.ä.

    Solltest du ein Geräte erfolgreich getestet haben und möchtest die Einstellungen teilen, dann schicke uns doch eine Email an [info@tinkerforge.com](mailto:info@tinkerforge.com). Vielen Dank!
    
:::

### Alpha ESS

#### Laden vom Netz erlauben

Es wird der Ladeplan für den ganzen Tag konfiguriert, aktiviert und als Ladeziel 100% eingestellt.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 2127 | Time period control flag | 3 | Enable Time period control |
| 2133 | Charge Cut Soc | 100 | Lade nur bis 100% SoC (Voll) |
| 2134 | Time charge start time1 hours | 0 | Slot1 Beginn 0 Uhr |
| 2135 | Time charge stop time1 hours | 23 | Slot1 Ende 23 Uhr |
| 2136 | Time charge start time2 hours | 23 | Slot2 Beginn 23 Uhr |
| 2137 | Time charge stop time2 hours | 23 | Slot2 Ende 23 Uhr |
| 2142 | Time charge start time1 minutes | 0 | Slot1 Start 0 Minuten |
| 2143 | Time charge stop time1 minutes | 59 | Slot1 Stop 59 Minuten |
| 2144 | Time charge start time2 minutes | 59 | Slot2 Start 59 Minuten |
| 2145 | Time charge stop time2 minutes | 59 | Slot2 Stop 59 Minuten |

#### Laden vom Netz zurücknehmen

Es wird der Ladeplan für den ganzen Tag konfiguriert, aktiviert und als Ladeziel 10% eingestellt.
Die Idee dahinter ist, dass ein Minimum von 10% SoC garantiert werden soll.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 2127 | Time period control flag | 3 | Enable Time period control |
| 2133 | Charge Cut Soc | 10 | Lade nur bis 10% SoC (Minimum) |
| 2134 | Time charge start time1 hours | 0 | Slot1 Beginn 0 Uhr |
| 2135 | Time charge stop time1 hours | 23 | Slot1 Ende 23 Uhr |
| 2136 | Time charge start time2 hours | 23 | Slot2 Beginn 23 Uhr |
| 2137 | Time charge stop time2 hours | 23 | Slot2 Ende 23 Uhr |
| 2142 | Time charge start time1 minutes | 0 | Slot1 Start 0 Minuten |
| 2143 | Time charge stop time1 minutes | 59 | Slot1 Stop 59 Minuten |
| 2144 | Time charge start time2 minutes | 59 | Slot2 Start 59 Minuten |
| 2145 | Time charge stop time2 minutes | 59 | Slot2 Stop 59 Minuten |

#### Entladen verbieten

Es wird der Zeitplan zur Entladesteuerung für den ganzen Tag konfiguriert, aktiviert und als Reserve 100% SoC eingestellt.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 2127 | Time period control flag | 3 | Enable Time period control |
| 2128 | UPS Reserve Soc | 100 | Halte Reserve von 100% SoC (Voll) |
| 2129 | Time discharge start time1 hours | 0 | Slot1 Beginn 0 Uhr |
| 2130 | Time discharge stop time1 hours | 23 | Slot1 Ende 23 Uhr |
| 2131 | Time discharge start time2 hours | 23 | Slot2 Beginn 23 Uhr |
| 2132 | Time discharge stop time2 hours | 23 | Slot2 Ende 23 Uhr |
| 2138 | Time discharge start time1 minutes | 0 | Slot1 Start 0 Minuten |
| 2139 | Time discharge stop time1 minutes | 59 | Slot1 Stop 59 Minuten |
| 2140 | Time discharge start time2 minutes | 59 | Slot2 Start 59 Minuten |
| 2141 | Time discharge stop time2 minutes | 59 | Slot2 Stop 59 Minuten |


#### Verbot zum Entladen zu­rück­neh­men

Es wird der Zeitplan zur Entladesteuerung für den ganzen Tag konfiguriert, aktiviert und als Reserve 10% SoC eingestellt.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 2127 | Time period control flag | 3 | Enable Time period control |
| 2128 | UPS Reserve Soc | 10 | Halte Reserve von 10% SoC (Minimum) |
| 2129 | Time discharge start time1 hours | 0 | Slot1 Beginn 0 Uhr |
| 2130 | Time discharge stop time1 hours | 23 | Slot1 Ende 23 Uhr |
| 2131 | Time discharge start time2 hours | 23 | Slot2 Beginn 23 Uhr |
| 2132 | Time discharge stop time2 hours | 23 | Slot2 Ende 23 Uhr |
| 2138 | Time discharge start time1 minutes | 0 | Slot1 Start 0 Minuten |
| 2139 | Time discharge stop time1 minutes | 59 | Slot1 Stop 59 Minuten |
| 2140 | Time discharge start time2 minutes | 59 | Slot2 Start 59 Minuten |
| 2141 | Time discharge stop time2 minutes | 59 | Slot2 Stop 59 Minuten |

#### Laden verbieten

Diese Funktion scheint für Alpha ESS nicht möglich zu sein.

#### Verbot zum Laden zu­rück­neh­men

Diese Funktion scheint für Alpha ESS nicht möglich zu sein.

### Deye
#### Laden vom Netz erlauben

Es wird der Ladeplan für den ganzen Tag konfiguriert, aktiviert und als Ladeziel 100% eingestellt.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 148 | Time Points | 0 | |
| 149 | Time Points | 2359 | |
| 150 | Time Points | 2359 | |
| 151 | Time Points | 2359 | |
| 152 | Time Points | 2359 | |
| 153 | Time Points | 2359 | |
| 166 | Target SoC | 100 | |
| 167 | Target SoC | 100 | |
| 168 | Target SoC | 100 | |
| 169 | Target SoC | 100 | |
| 170 | Target SoC | 100 | |
| 161 | Target SoC | 100 | |
| 166 | Time Points Charge Enable | 1 | |
| 167 | Time Points Charge Enable | 1 | |
| 168 | Time Points Charge Enable | 1 | |
| 169 | Time Points Charge Enable | 1 | |
| 170 | Time Points Charge Enable | 1 | |
| 161 | Time Points Charge Enable | 1 | |
#### Laden vom Netz zurücknehmen

Der Ladeplan wird deaktiviert und als Ladeziel 10% eingestellt.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 166 | Target SoC | 10 | |
| 167 | Target SoC | 10 | |
| 168 | Target SoC | 10 | |
| 169 | Target SoC | 10 | |
| 170 | Target SoC | 10 | |
| 161 | Target SoC | 10 | |
| 166 | Time Points Charge Enable | 0 | |
| 167 | Time Points Charge Enable | 0 | |
| 168 | Time Points Charge Enable | 0 | |
| 169 | Time Points Charge Enable | 0 | |
| 170 | Time Points Charge Enable | 0 | |
| 161 | Time Points Charge Enable | 0 | |


#### Entladen verbieten

Den maximalen Entladestrom auf 0A setzen.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 109 | Max A discharge | 0 | Maximaler Entladestrom 0A |

#### Verbot zum Entladen zu­rück­neh­men

Den maximalen Entladestrom auf Maximum setzen. Dieser ist Modellabhängig.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 109 | Max A discharge | 50 | Maximaler Entladestrom 50A |

#### Laden verbieten

Den maximalen Ladestrom auf 0A setzen.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 108 | Max A charge | 0 | Maximaler Entladestrom 0A |

#### Verbot zum Laden zu­rück­neh­men

Den maximalen Ladestrom auf Maximum setzen. Dieser ist Modellabhängig.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 108 | Max A charge | 50 | Maximaler Ladestrom 50A |

### Fox-ESS
#### Laden vom Netz erlauben

Den Minimum-SoC auf 100% setzen

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 301 | Minimum SoC OnGrid | 100 | Minimum SoC 100% |

#### Laden vom Netz zurücknehmen

Den Minimum-SoC auf 10% setzen (Reserve).

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 301 | Minimum SoC OnGrid | 10 | Minimum SoC 10% |

#### Entladen verbieten

Den maximalen Entladestrom auf 0A setzen.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 298 | Battery maximum discharge current | 0 | Maximaler Entladestrom 0A |

#### Verbot zum Entladen zu­rück­neh­men

Den maximalen Entladestrom auf Maximum setzen. Dieser ist Modellabhängig.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 298 | Battery maximum discharge current | 50 | Maximaler Entladestrom 50A |

#### Laden verbieten

Den maximalen Ladestrom auf 0A setzen.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 297 | Battery maximum charging current | 0 | Maximaler Ladestrom 0A |

#### Verbot zum Laden zu­rück­neh­men

Den maximalen Ladestrom auf Maximum setzen. Dieser ist Modellabhängig.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 297 | Battery maximum charging current | 50 | Maximaler Ladestrom 50A |


### Fronius

Ein Speicher angeschlossen an einem Fronius
Hybrid-Wechselrichter kann mittels SunSpec gesteuert werden (Modell 124).

Dazu ist es notwendig Bitmasken schreiben zu können. Diese Funktion ist aktuell
von uns noch nicht verfügbar, wird aber nachgezogen.

#### Laden vom Netz erlauben
#### Laden vom Netz zurücknehmen
#### Entladen verbieten
#### Verbot zum Entladen zu­rück­neh­men
#### Laden verbieten
#### Verbot zum Laden zu­rück­neh­men


### Goodwe
#### Laden vom Netz erlauben
Wechsel den Modus und beziehe bis zu 10kW aus dem Netz
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47511 | EMSPowerMode | 2 | Charge PV Mode |
| 47512 | EMSPowerSet | 10000 | 10.000W from Grid |

#### Laden vom Netz zurücknehmen
Wechsel den Modus zurück und beziehe keinen Strom aus dem Netz
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47511 | EMSPowerMode | 1 | Normal Mode |
| 47512 | EMSPowerSet | 0 | 0W from Grid (will be ignored) |

#### Entladen verbieten
Den maximalen Entladestrom auf 0A setzen.
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 45355 | BattDisChgCurrMax | 0 | Maximaler Entladestrom 0A |

#### Verbot zum Entladen zu­rück­neh­men
Den maximalen Entladestrom auf Maximum setzen.
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 45355 | BattDisChgCurrMax | 1000 | Maximaler Entladestrom 100A |

#### Laden verbieten
Den maximalen Ladestrom auf 0A setzen.
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 45352 | BattChargeCurrMax | 0 | Maximaler Ladestrom 0A |

#### Verbot zum Laden zu­rück­neh­men
Den maximalen Ladestrom auf Maximum setzen.
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 45352 | BattChargeCurrMax | 1000 | Maximaler Ladestrom 100A |

### Hailei

Die Speicheransteuerung von Hailei Gen2 Hybrid Wechselrichtern
ist identisch zu Alpha-ESS.

### Huawei
#### Laden vom Netz erlauben
Aktiviere die entsprechenden Register
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47083 | Forced charging and discharging period | 1440 | Gesamte Zeitdauer 24h (Minuten)|
| 47084 | Forced charging and discharging power | 3500 | Maximalleistung 3500W |
| 47087 | Charge from grid Function | 1 | Grid Charge erlauben = 1 |
| 47088 | Grid charge cutoff SOC | 100 | Abschaltung bei 100% SoC |
| 47100 | Forcible charge/discharge | 1 | Charge |
| 47101 | Target SOC | 100 | Ziel 100% SoC |


#### Laden vom Netz zurücknehmen
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47083 | Forced charging and discharging period | 0 | deaktiviert (Minuten)|
| 47087 | Charge from grid Function | 0 | Grid Charge nicht erlauben = 0 |

#### Entladen verbieten
Die maximale Entladeleistung auf 0W setzen.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47077 | Maximum discharging power | 0 | 0W |

#### Verbot zum Entladen zu­rück­neh­men
Die maximale Entladeleistung auf Maximum setzen.
| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47077 | Maximum discharging power | 3500 | 3500W |

#### Laden verbieten
Die maximale Ladeleistung auf 0W setzen.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47075 | Maximum charging power | 0 | 0W |

#### Verbot zum Laden zu­rück­neh­men
Die maximale Ladeleistung auf Maximum setzen.

| Register | Name | Wert | Kommentar |
| --- | --- | --- | --- |
| 47075 | Maximum charging power | 3500 | 3500W |

### Kostal
#### Laden vom Netz erlauben
#### Laden vom Netz zurücknehmen
#### Entladen verbieten
#### Verbot zum Entladen zu­rück­neh­men
#### Laden verbieten
#### Verbot zum Laden zu­rück­neh­men


### SMA
#### Laden vom Netz erlauben
#### Laden vom Netz zurücknehmen
#### Entladen verbieten
#### Verbot zum Entladen zu­rück­neh­men
#### Laden verbieten
#### Verbot zum Laden zu­rück­neh­men


### Sungrow
#### Laden vom Netz erlauben
#### Laden vom Netz zurücknehmen
#### Entladen verbieten
#### Verbot zum Entladen zu­rück­neh­men
#### Laden verbieten
#### Verbot zum Laden zu­rück­neh­men


### Victron
#### Laden vom Netz erlauben
#### Laden vom Netz zurücknehmen
#### Entladen verbieten
#### Verbot zum Entladen zu­rück­neh­men
#### Laden verbieten
#### Verbot zum Laden zu­rück­neh­men
