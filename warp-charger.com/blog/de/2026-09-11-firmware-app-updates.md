title: "Firmware- und App-Updates: IPv6, Home Assistant und gespeicherte Zugangsdaten"
slug: firmware-app-updates
date: 2026-09-11
tag: Software

Neue Updates für alle WARP-Geräte und unsere Apps sind da! Aktuell sind **WARP1/2/3/4 2.13.1**, **WARP Energy Manager 2.9.1**, **WARP Energy Manager 2.0 1.8.1** und die **WARP App 2.1.0 für iOS und Android**.

## Firmware: Die wichtigsten Neuerungen

- **IPv6 und Länderkonfiguration** sowie Unterstützung der **OVE-Richtlinie R 37 beim WARP4**. Dynamische Strompreise sind jetzt auch für Belgien verfügbar.
- **Mehr Home Assistant:** MQTT-Discovery gibt es nun auch für beide WARP Energy Manager. Bei den Wallboxen wurde die Home Assistant-MQTT-Discovery um weitere Komponenten ergänzt.
- **Mehr Automatisierung:** Neue Bedingungen „Zählerwert“ und „Nach Neustart“. „NFC Tag erkannt“ funktioniert nun auch für kontrollierte Wallboxen.
- **WARP4: Verbesserte Fahrzeugkommunikation** mit kürzerem Wechsel von ISO 15118 zu IEC 61851, optional noch schnellerem Timeout sowie Autocharge- und Kompatibilitätsverbesserungen für Tesla, Cupra e-HYBRID und weitere Fahrzeuge mit Aptiv-Ladegerät.
- Dazu kommen Verbesserungen an Batteriesteuerung, Lastmanagement und Zähleranbindung sowie zahlreiche Stabilitätskorrekturen.

**Wichtig beim Update:** Wer bereits **WARP1/2/3/4 2.13.0**, **WARP Energy Manager 2.9.0** oder **WARP Energy Manager 2.0 1.8.0** installiert hat, muss die neue Firmware **von Hand herunterladen und manuell installieren**. Ein Fehler in diesen Vorgängerversionen verhindert das Auto-Update.

Alle Firmware-Dateien und vollständigen Changelogs gibt es auf unserer [Download-Seite](/de/software/downloads#firmware).

## App 2.1.0: Zugangsdaten speichern

Die App kann jetzt **Zugangsdaten für lokale WARP-Geräte speichern**, sodass sie bei der nächsten Anmeldung nicht erneut eingegeben werden müssen. Außerdem werden HTTPS-Verbindungen zu lokalen Geräten unterstützt, und Links zwischen ihnen öffnen sich direkt in der App. Zum Aktualisieren oder erneuten Verbinden genügt es, am oberen Seitenrand nach unten zu ziehen.

Jetzt aktualisieren: [iOS im App Store](https://apps.apple.com/de/app/warp-by-tinkerforge/id6736695801) · [Android bei Google Play](https://play.google.com/store/apps/details?id=com.tinkerforge.warp&hl=de)
