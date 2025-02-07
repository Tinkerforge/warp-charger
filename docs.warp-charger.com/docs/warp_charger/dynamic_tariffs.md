---
sidebar_position: 9
---

# Dynamischer Strompreis

:::note

Dynamische Strompreise sind in folgende Produkte integriert:

* WARP2 Charger
* WARP3 Charger
* WARP Energy Manager 1.0
* WARP Energy Manager 2.0

:::

Wenn ein dynamischer Stromtarif (z.B. über Tibber oder Awattar) vorhanden ist, können die dynamischen Strompreise verwendet werden um die [Heizungssteuerung](/warp_energy_manager/heating.md) (Energy Manager) und den [Ladeplan des Eco-Modus](/warp_charger/eco_mode.md) zu verbessern.

Dazu muss das Feature unter `Energiemanagement -> Dynamischer Strompreis` aktiviert werden.

![image](/img/dynamic_tariffs/configuration.png)

Notwendige Einstellungen sind die Region und die Auflösung welche vom Stromanbieter verwendet werden.

Optional können stromanbieterspezfische Zusatzkosten angeben werden. Die dy­na­mi­schen Bör­sen­strom­prei­se sind nur ein Teil der Strom­kos­ten. Es fallen zu­sätz­li­che fixe Steuern, Netz­ent­gel­te und Auf­schlä­ge an.

Die MwSt bezieht sich auf die MwSt die auf den Börs­en­strom­preis anfällt (in DE aktuell 19%). Weitere Zu­satz­kos­ten können in der Rechnung des Strom­an­bie­ters nach­ge­schaut werden.

Es gibt drei sinnvolle Mög­lich­kei­ten für die op­ti­o­na­len Ein­stell­ungen:

* Alles auf 0 lassen: Es wird der Netto-Bör­sen­preis angezeigt,
* MwSt auf 0 lassen und bei den Gebühren den Net­to­preis eintragen: Es wird der Netto-Strom­preis inkl. Gebühren angezeigt.
* MwSt korrekt eintragen und bei den Gebühren den Brut­to­preis eintragen: Es wird der Brutto-Strom­preis inkl. Gebühren angezeigt.

Zur Regelung werden un­ab­hän­gig von den Zu­satz­kos­ten immer nur die dy­na­mi­schen Netto-Bör­sen­prei­se verwendet.

## Status

Nachdem die dynamischen Strompreise konfiguert und aktiviert sind, gibt es weiter unten auf der Seite eine Übersicht der Strompreise.

![image](/img/dynamic_tariffs/status.png)