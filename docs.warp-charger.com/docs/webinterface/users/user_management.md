---
sidebar_position: 2
---

# Benutzerverwaltung

:::note

Diese Konfiguration ist nur für [WARP Charger](/docs/warp_charger/introduction) verfügbar.

:::


![image](/img/webinterface/users/warp-users-user_management1.jpeg)


Es können bis zu 32 Benutzer angelegt werden. Einem angelegten Benutzer, dem ein
NFC-Tag zugeordnet wurde (siehe Abschnitt [NFC](/docs/webinterface/users/nfc-tags.md)), können vom Ladetracker Ladevorgänge
zugeordnet werden. In der Werkseinstellung sind drei Nutzer angelegt, denen
jeweils eine der mitgelieferten NFC-Karten zugeordnet wurde. Diese können umbenannt oder gelöscht werden.

Ein neuer Nutzer kann mittels Klicken auf *Benutzer hinzufügen* hinzugefügt werden. Anschließend öffnet sich
ein Modalfenster, in dem der eigentliche Benutzername, der Anzeigename (für die Anzeige im Ladetracker) und 
der dem Nutzer erlaube maximale Ladestrom eingestellt werden können. Zusätzlich kann dem Nutzer ein Passwort
fur die HTTP-Anmeldung (siehe folgenden Abschnitt) gegeben werden.

![image](/img/webinterface/users/warp-users-user_management2.jpeg)

Sollen mehrere Nutzer angelegt werden, so empfehlen wir, diese direkt nacheinander anzulegen. Anschließend müssen
die Änderungen gespeichert und die Wallbox neugestartet werden, damit die Änderungen übernommen werden.

Soll nur eine Ladefreigabe mittels NFC/Benutzerfreigabe möglich sein, so muss Benutzerautorisierung aktiviert
werden.

## Anmeldung

Wenn *Anmeldung aktiviert* ausgewählt ist, muss zum Zugriff auf das Webinterface und zur Verwendung der
HTTP-API eine Anmeldung als einer der konfigurierten Benutzer durchgeführt werden. Eine HTTP-Anmeldung ist
nur möglich, wenn dem Benutzer ein Passwort konfiguriert wurde. Die Funktion ist nur aktivierbar, wenn mindestens
ein Nutzer mit konfiguriertem Passwort existiert. Entsprechend können Benutzer erstellt werden, die nur für das 
Ladetracking per NFC-Tag verwendet werden, aber keinen Zugriff auf das Webinterface haben sollen, indem diesen
kein Passwort gegeben wird.

:::note

Wenn die Zugangsdaten der HTTP-Anmeldung verloren
gegangen sind, kann nur uber den Wiederherstellungsmodus
oder nach einem Zurücksetzen auf den Werkszustand wieder darauf
zugegriffen werden.

:::
