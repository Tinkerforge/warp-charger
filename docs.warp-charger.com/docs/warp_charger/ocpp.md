---
sidebar_position: 8
---

# OCPP

Soll eine Wallbox in eine Cloud eingebunden werden oder eine große Menge von
Wallboxen gemanagt werden, wird dafür oft der OCPP-Standard verwendet.

OCPP (Open Charge Point Protocol) ist ein standardisiertes
Kommunikationsprotokoll zwischen Ladestationen und einem zentralen
Managementsystem. Die WARP2 und WARP3 Charger unterstützen OCPPJ 1.6 Core Profile
und Smart Charging Profile.

## Konfiguration

Um OCPP zu nutzen, muss die Wallbox zunächst in der verwendeten Cloud
hinzugefügt werden. Wir nutzen in diesem Beispiel https://ladefoxx.one.
Die notwendingen Einstellungen sind allerdings auf jede Cloud bzw
jeden OCPP-Server vorzunehmen.

![image](/img/first_steps/ocpp_configuration_ladefoxx.png)

Auf ladefoxx.one wird insbesondere die Ladepunkt-Identität eingetragen
(im Screenshot "Controller ID" genannent). Diese gibt der WARP Charger vor.

Nach dem Speichern wird dann von der Cloud ein Passwort oder Hex-Key 
bereitgestellt. Dieses muss zusammen mit mit der passenden Endpoint-URL
beim WARP Charger unter `Schnittstellen` -> `OCPP` eingetragen werden

![image](/img/first_steps/ocpp_configuration_warp.png)

Wenn das eingegebene Passwort exakt 40 Zeichen lang ist und nur aus
Hexadezimal-Zeichen (0-9, A-F, a-f) besteht, wird es als Hex-Key
interpretiert, der ein 20 Byte langen Schlüssel kodiert.

Es ist auch möglich das keine Autorisierung erforderlich ist, in diesem
Fall kann die Autorisierung im WARP Charger deaktiviert werden.

Unter den Punkten Debug und Konfigurationen finden sich weiterführende
Informationen, mit denen Probleme bei der Interaktion mit einem
OCPP-Server diagnostiziert werden können.