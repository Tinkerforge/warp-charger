---
sidebar_position: 2
---

# Ladestatus

![image](/img/webinterface/wallbox/warp-charge_status.jpeg)

Die Unterseite Ladestatus gibt Auskunft über den Zustand des
Ladecontrollers (EVSE) und dessen Hardwarekonfiguration.
Probleme beim Laden können mithilfe der
Informationen auf dieser Seite diagnostiziert werden.

Sollte der intern verbaute DC-Fehlerstromschutz einmal ausgelöst haben,
so kann dieser hier zurückgesetzt werden.


## Ladestromgrenzen

In diesem Abschnitt werden die aktuellen Ladestromgrenzen angezeigt. Alle Grenzen, die
derzeit aktiv sind, werden zur Entscheidung, ob ein Ladevorgang erlaubt ist, und zur Berechnung des maximalen
Ladestroms einbezogen: Nur wenn alle aktiven Ladestromgrenzen nicht blockieren, wird ein Ladevorgang erlaubt.
Der erlaubte Ladestrom ist dann das Minimum aller aktiven
Grenzen.

Folgende Grenzen können Teil der Berechnung sein:

 * **Zuleitung**: Maximalstrom der Zuleitung zum WARP3 Charger. Dieser wird über die Schalter auf dem Ladecontroller konfiguriert.

 * **Typ-2-Ladekabel**: Maximalstrom des Typ-2-Ladekabels.

 * **Abschalteingang**: Blockiert oder gibt den Ladevorgang frei, je nach Konfiguration des Abschalteingangs.

 * **Konfigurierbarer Eingang**: Kann analog zum Abschalteingang kann je nach Konfiguration blockieren, limitieren oder freigeben.

 * **Manuelle Ladefreigabe**: Kann durch Autostart-Einstellung bzw. Drücken des Tasters blockieren oder freigeben.

 * **Konfiguration**: Wird durch das Eingabefeld auf der Statusseite eingestellt. Durch den *Freigeben*-Button wird eine eventuell eingetragene Ladestromgrenze komplett aufgehoben.

 * **Benutzer/NFC**: Blockiert, bis ein Benutzer den Ladevorgang durch ein NFC-Tag freigibt, falls die Benutzerautorisierung aktiviert ist. Danach wird die diesem Benutzer zugeordnete Ladestromgrenze eingetragen.

 * **Lastmanagement**: Wird vom Lastmanager bzw. dem PV-Überschussladen gesteuert, falls aktiviert.

![image](/img/webinterface/wallbox/warp-charge_status2.jpeg)

 * **Externe Steuerung**: Wird durch eine externe Steuerung über die API, beispielsweise EVCC, gesteuert.

 * **Modbus TCP-Strom**: Beschränkung des Ladestroms bei aktivierter Modbus TCP Schnittstelle.

 * **Modbus TCP-Freigabe**: Freigabe/Blockierung des Ladevorgangs bei aktivierter Modbus TCP-Schnittstelle.

 * **OCPP**: Freigabe/Blockierung des Ladevorgangs bei aktivierter OCPP-Schnittstelle.

 * **Energie/Zeitlimit***: Begrenzung durch konfigurierte Energie- oder Zeitlimits.

 * **Zähleruberwachung**: Wird blockiert, wenn die Zähleruberwachung eingeschaltet und keine Kommunikation mit dem Stromzähler möglich ist.

 * **Automatisierung**: Begrenzung durch eine auf der Unterseite Automatisierung konfigurierte Regel.


Die Farbmarkierung neben einer Grenze hat folgende Bedeutung:

 * **Grau**: Diese Ladestromgrenze ist nicht aktiv. Sie kann den Ladevorgang nicht blockieren und geht nicht in Berechnung des erlaubten Ladestroms ein.
 * **Grün**: Diese Ladestromgrenze ist aktiv, beschränkt den erlaubten Ladestrom aber derzeit nicht.
 * **Blau**: Diese Ladestromgrenze ist aktiv und gibt ein Ladestromlimit vor. Andere aktive Grenzen limitieren den Ladestrom jedoch stärker.
 * **Gelb**: Diese Ladestromgrenze ist aktiv, blockiert den Ladevorgang nicht, gibt aber die aktuell stärkste Limitierung des Ladestroms vor.
 * **Rot**: Diese Ladestromgrenze ist aktiv und blockiert den Ladevorgang.


## Hardware-Konfiguration

Unter der Überschrift Hardware-Konfiguration werden Informationen zur verbauten Hardware aufgeführt.

## Ladeprotokoll

Bei Ladeabbruchen kann ein Ladeprotokoll helfen, die Ursache eines Fehlers zu ermitteln. Ein
Ladeprotokoll kann wie folgt aufgezeichnet werden:
 1. Ladeprotokoll im Browser starten (***Start***), Browserfenster geöffnet halten.
 2. Fahrzeug an Wallbox anschließen und Ladevorgang starten.
 3. Nach Auftreten des Fehlers ***Stop+Download*** klicken. Es sollte eine Textdatei heruntergeladen werden.
 4. Die Textdatei mit einer Problembeschreibung an info@tinkerforge.com senden.



