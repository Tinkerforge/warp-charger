title: "Firmware and app updates: IPv6, Home Assistant and saved login details"
slug: firmware-app-updates
date: 2026-09-11
tag: Software

New updates for all WARP devices and our apps are here! The latest versions are **WARP1/2/3/4 2.13.1**, **WARP Energy Manager 2.9.1**, **WARP Energy Manager 2.0 1.8.1** and the **WARP app 2.1.0 for iOS and Android**.

## Firmware highlights

- **IPv6 and country configuration**, plus support for the **OVE R 37 guideline on WARP4**. Dynamic electricity prices are now also available for Belgium.
- **More Home Assistant integration:** MQTT discovery is now available for both WARP Energy Managers. For chargers, Home Assistant MQTT discovery has been extended with more components.
- **More automation:** New “Meter value” and “After restart” conditions. “NFC tag detected” now also works for managed chargers.
- **WARP4: Improved vehicle communication** with a faster transition from ISO 15118 to IEC 61851, an optional even faster timeout, and Autocharge and compatibility improvements for Tesla, Cupra e-HYBRID and other vehicles with Aptiv onboard chargers.
- Further improvements cover battery control, load management and meter integration, alongside numerous stability fixes.

**Important update information:** If you have already installed **WARP1/2/3/4 2.13.0**, **WARP Energy Manager 2.9.0** or **WARP Energy Manager 2.0 1.8.0**, you must **download and install the new firmware manually**. A bug in those previous versions prevents automatic updates.

All firmware files and full changelogs are available on our [download page](/en/software/downloads#firmware).

## App 2.1.0: Save your login details

The app can now **save login details for local WARP devices**, so you don’t have to enter them again the next time you log in. HTTPS connections to local devices are also supported, and links between them open directly in the app. Pull down at the top of the page to refresh or reconnect.

Update now: [iOS on the App Store](https://apps.apple.com/us/app/warp-by-tinkerforge/id6736695801) · [Android on Google Play](https://play.google.com/store/apps/details?id=com.tinkerforge.warp&hl=en)
