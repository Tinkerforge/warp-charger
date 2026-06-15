---
sidebar_position: 2
---

# Benutzerverwaltung

import DeviceCompatibility from '@site/src/components/DeviceCompatibility';

<DeviceCompatibility supported={['wc1', 'wc2', 'wc3', 'wc4', 'wem1', 'wem2']} />

:::note

Es gibt ein Tutorial, welches auch das Nutzermanagement inkl. NFC und Ladelogbuch behandelt: [Einrichten des Ladelogbuchs](/tutorials/charge_tracking.md)

:::

![image](/img/webinterface/users/warp-users-user_management1.png)

Es können bis zu 32 Benutzer angelegt werden. Einem angelegten Benutzer, dem mindestens ein
NFC-Tag zugeordnet wurde, können vom Ladetracker Ladevorgänge
zugeordnet werden. In der Werkseinstellung sind drei Nutzer angelegt, denen
jeweils eine der mitgelieferten NFC-Karten zugeordnet wurde. Diese können umbenannt oder gelöscht werden.

Ein neuer Nutzer kann mittels Klicken auf den +-Button hinzugefügt werden. Anschließend öffnet sich
ein Modalfenster, in dem der eigentliche Benutzername, der Anzeigename (für die Anzeige im Ladetracker) und
der dem Nutzer erlaube maximale Ladestrom eingestellt werden können. Zusätzlich kann dem Nutzer ein Passwort
fur die HTTP-Anmeldung (siehe folgenden Abschnitt) gegeben werden.

![image](/img/webinterface/users/warp-users-user_management2.png)

## NFC-Freigabe

Beim Anlegen bzw. Bearbeiten eines Benutzers können diesem (wiederum durch Klicken auf den +-Button) NFC-Tags zugeordnet werden.
NFC-Tags, die kürzlich von der Wallbox detektiert wurden, werden hier aufgelistet.
Falls dieser WARP Charger oder WARP Energy Manager ein Lastmanager für mehrere Wallboxen ist und
die zentrale Verwaltung aktiviert ist (siehe Abschnitt [Wallboxen](/docs/webinterface/energy_management/wallboxes.md)),
werden NFC-Tags aufgelistet, die von einer der kontrollierten Wallboxen detektiert wurden.

Alternativ können Tag-ID und -Typ manuell eingegeben werden. Dies ist zum Beispiel sinnvoll, wenn Tag-ID und
-Typ mittels externer Geräte (z.B. Smartphone mit passender App) ermittelt und eingetragen werden sollen.

![image](/img/webinterface/users/warp-users-user_management3.png)

Es können beliebige NFC-Tags der Typen 1 bis 5 sowie Mifare Classic angelernt werden. Der WARP3 Charger unterstützt bis zu 32 angelernte Tags.

Sollen mehrere Nutzer angelegt werden, so empfehlen wir, diese direkt nacheinander anzulegen. Anschließend müssen
die Änderungen gespeichert und die Wallbox neugestartet werden, damit die Änderungen übernommen werden.

Damit Ladevorgänge nur für berechtige Benutzer erlaubt sind, muss dann die Ladefreigabe aktiviert werden.

:::info
Falls mehrere Wallboxen die gleichen Benutzer/NFC-Tags verwenden sollen,
ist es ausreichend die Benutzer und NFC-Tags auf dem Lastmanager zu konfigurieren und die zentrale Verwaltung zu aktivieren,
siehe Abschnitt [Wallboxen](/docs/webinterface/energy_management/wallboxes.md).
:::

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
