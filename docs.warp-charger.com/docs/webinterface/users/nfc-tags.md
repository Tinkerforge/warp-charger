---
sidebar_position: 1
---

# NFC-Tags

:::note

Diese Konfiguration ist nur für [WARP Charger](/docs/warp_charger/introduction) verfügbar.

:::

![image](/img/webinterface/users/warp-users-nfc1.jpeg)

Der [WARP3 Charger](/docs/warp_charger/introduction) unterstützt eine Ladefreigabe per NFC. Wenn diese aktiviert ist, muss zum Starten und/oder Stoppen eines
Ladevorgangs ein NFC-Tag, das einem Benutzer zugeordnet ist, an die rechte Seite der Wallbox gehalten werden.
Es können beliebige NFC-Tags der Typen 1 bis 4 sowie Mifare Classic angelernt werden. Der WARP3 Charger unterstützt bis zu 32 angelernte Tags.

Auf der NFC-Unterseite des Webinterfaces können die berechtigten Tags konfiguriert werden. Im Werkszustand sind
die drei mitgelieferten NFC-Karten angelernt, das Starten und Stoppen eines Ladevorgangs ist aber so konfiguriert,
dass eine Freigabe ohne Tag möglich ist. Durch Klicken auf den *+*-Button kann ein neues Tag angelernt werden.

![image](/img/webinterface/users/warp-users-nfc2.jpeg)

Es werden die zuletzt erkannten, aber noch nicht berechtigten Tags in einer Liste anzeigt, durch Klicken auf eines der Tags kann dieses übernommen werden.
Ein Neustart der Wallbox leert die Liste. Sollen also mehrere Tags nacheinander hinzugefugt werden, empfehlen wir, die Tags nacheinander an die Wallbox zu halten.
Die Tags werden chronologisch in der Liste aufgeführt und können nacheinander angelegt und existierenden Benutzern zugeordnet werden. Wurden alle NFC-Tags angelernt,
können die Einstellungen gespeichert und die Wallbox neugestartet werden.

Alternativ können Tag-ID und -Typ manuell eingegeben werden. Dies ist zum Beispiel sinnvoll, wenn Tag-ID und
-Typ mittels externer Geräte (z.B. Smartphone mit passender App) ermittelt und eingetragen werden sollen.
