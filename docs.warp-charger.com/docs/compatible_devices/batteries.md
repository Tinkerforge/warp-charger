---
sidebar_position: 4
---

# Batteriespeicher

:::note

    Die Steuerung von Batteriespeichern befindet sich zur Zeit noch in der Entwicklung!
    
    Generell werden Speicher unterstützt, die mittels [Modbus/TCP](/docs/compatible_devices/interfaces#modbustcp) Befehlen gesteuert werden können.
    Es können eigene (benutzerdefinierte) Registertabellen angelegt werden, mit dem ein Speicher gesteuert werden kann. 
    Da dies ein größeres technisches Know-How benötigt arbeiten wir daran Voreinstellungen für Speicher zu bieten.
    Wir erweitern die Liste laufend!

:::


## Was heißt Steuerung eines Batteriespeichers?

Viele Hersteller unterstützen die externe Steuerung von Batteriespeichern mittels [Modbus/TCP](/docs/compatible_devices/interfaces#modbustcp) Schnittstelle.
Meist wird der Batteriespeicher über den angeschlossenen Wechselrichter gesteuert und nicht die Batterie direkt. Die zur Verfügung gestellten Register zur Steuerung 
unterscheiden sich je nach Hersteller und Gerät. Die Umsetzung der jeweiligen Funktion unterscheidet sich ebenfalls stark,
so dass sich die Einstellungen zwischen verschiedenen Geräten nicht zwingend vergleichen lassen.

Der Speicher wird von uns NICHT geregelt. Er übt seine vom Hersteller definierte Funktion aus. Das heißt im Normalfall wird ein PV-Überschuss zur Ladung des Speichers genutzt und der Speicher versucht die Leistungsaufnahme eines Verbrauchers
zu kompensieren. Mittels nutzerdefinierbarer Regeln in der Batteriesteuerung können aber Parameter so gesetzt werden, dass zum Beispiel das Laden gesperrt ist und ein Überschuss nicht in den Speicher fliest.

## Anlegen eines Batteriespeichers

:::note

    Das Anlegen eines Batteriespeichers ist im Webinterface beschrieben: Siehe [Batteriesteuerung](/docs/webinterface/energy_management/battery_control)

:::


Wir ermöglichen es einen Batteriespeicher mittels [Modbus/TCP](/docs/compatible_devices/interfaces#modbustcp) zu steuern. Wir versuchen für uns bekannte Speicher Voreinstellungen zu bieten, die direkt ausgewählt werden können.
Leider ist es nicht einfach die korrekten Werte ohne Zugriff auf eine Anlage zu ermitteln. Daher sind wir hier sehr auf die Community angewiesen. In der [Liste der kompatiblen Geräte](/docs/compatible_devices/devices) sind
Batteriespeicher die wir steuern können mit "BS" gekennzeichnet.

Ist keine Voreinstellung für einen Speicher hinterlegt, so können die jeweiligen Register händisch angelegt werden. Dazu müssen die Registersets für die nachfolgend genannten sechs verschiedenen Modi
implementiert werden. Es können einzelne Register, aber auch mehrere Register in einem Befehl geschrieben werden. Es wird empfohlen Register, die aufeinanderfolgend sind, als ein Block in einem Befehl zu schreiben.
Siehe dazu den nachfolgenden Abschnitt [Benutzerdefinierte Batteriespeicher - Speichermodi](/docs/compatible_devices/batteries#benutzerdefinierte-batteriespeicher---speichermodi).
Wichtig ist unbedingt den "Speichermodus: Normal Laden, normal Entladen" zu implementieren und in diesem die Standardparameter des Speichers zu setzen.


## Benutzerdefinierte Batteriespeicher - Speichermodi

Die Batteriesteuerung befindet sich immer in einem von den sechs nachfolgend genannten Modi. Über Regeln kann definiert werden unter welchen Bedingungen in welchen Modi gewechselt wird.
Existiert keine Voreinstellung für einen Speicher, so können die Registersets händisch (benutzerdefiniert) angelegt werden. In diesem Fall muss jeweils ein Registerset für jeden Modi hinterlegt werden, so dass
die Batteriesteuerung zwischen den jeweiligen Modi wechseln kann.

**Speichermodus: Normal Laden, normal Entladen**

Dies ist der Standardmodus eines Speichers. Der Speicher versucht den Netzanschluss auszuregeln. Ein PV-Überschuss wird zum Laden des Speichers verwendet, wohingegen eine Last durch Entladen des
Speichers ausgeregelt wird. In diesem Modus greift die Batteriesteuerung nicht in die Parameter des Speichers ein, sondern setzt die Standardparameter des Speichers. Dies kann zum Beispiel der volle
Lade- und Entladestrom sein.

**Speichermodus: Normal Laden, Entladen blo­ckie­ren**

In diesem Modi wird dem Speicher verboten zu entladen. Typische Möglichkeiten diesen Modus zu implementieren sind:

 * Setzen des "Maximalen Entladestroms" auf 0A.
 * Setzen des "Minimum SoC" auf 100%. Dies funktioniert nur, wenn das System dann NICHT Strom aus dem Netz zum Laden bezieht sonder nur das Entladen deaktiviert.

**Speichermodus: Laden blo­ckie­ren, normal Entladen**

Dieser Modi verbietet dem Speicher das Laden. Folgende Möglichkeiten sind uns bekannt diesen Modus zu implementieren:

 * Setzen des "Maximalen Ladestroms" auf 0A.
 * Setzen der "Maximalen Ladeleistung" auf 0W.
 
**Speichermodus: Laden blo­ckie­ren, Entladen blo­ckie­ren**

In diesem Modi wird der Speicher passiv. Er lädt nicht und entlädt auch nicht. Möglichkeiten dies zu implementieren sind:

 * Setzen des "Maximalen Ladestroms" auf 0A und des "Maximalen Entladestroms" auf 0A.
 * Setzen der "Maximalen Ladeleistung" auf 0W und der "Maximalen Entladeleistung" auf 0W.

**Speichermodus: Laden blo­ckie­ren, Entladen erzwingen**

Um Leistung in das Netz abzugeben ist dieser Modus gedacht. Der Speicher lädt nicht, aber entlädt mit der definierten Leistung ins Netz. Möglichkeiten dies zu implementieren sind:

 * Setzen des "EMS Modus" auf "Force Discharge" und setzen der "Maximalen Ladeleistung" auf 0W .
 * Setzen des "Netzbezugs" auf -xW. Hierdurch wird der Speicher mit -(xW + Hauslast) entladen.

**Speichermodus: Laden erzwingen, Entladen blo­ckie­ren**

Um aktiv aus dem Netz zu laden wird dieser Modus verwendet. Der Speicher entlädt nicht, aber lädt mit einer definierten Leistung. Typische Möglichkeiten diesen Modus zu implementieren sind:

 * Setzen des "EMS Modus" auf "Force Charge" und setzen der "Maximalen Entladeleistung" auf 0W .
 * Setzen des "Netzbezugs" auf xW. Hierdurch wird der Speicher mit xW - Hauslast geladen.

## Herstellerspezifische Implementierung

Die Implementierung der Speichermodi ist je nach Hersteller und Gerät verschieden. Im [ESP32-Firmware Git](https://github.com/Tinkerforge/esp32-firmware/tree/master/software/src/modules/batteries_modbus_tcp)
sind für jeden Hersteller Python-Dateien vorhanden in denen die jeweiligen Registersets definiert sind, die zur Steuerung verwendet werden.

