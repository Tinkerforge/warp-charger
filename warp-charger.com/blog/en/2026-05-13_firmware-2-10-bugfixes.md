title: "Firmware update: new bugfix releases"
slug: firmware-2.10.x-bugfixes
date: 2026-05-13
tag: Firmware

After the big [feature update to version 2.10](/en/blog/firmware-dark-mode-status-widget), we have released several bugfix updates over the past few days. They fix smaller issues and improve compatibility with additional meters.

## Current versions

The latest versions for the individual devices are:

- **WARP Charger**: firmware **2.10.2**
- **WARP2 Charger**: firmware **2.10.3**
- **WARP3 Charger**: firmware **2.10.3**
- **WARP Energy Manager**: firmware **2.6.2**
- **WARP Energy Manager 2.0**: firmware **1.5.2**

As usual, your device automatically suggests the matching update in the web interface. You can also find all firmware files and changelogs on our [download page](/en/software/downloads#firmware).

## What was fixed?

The most important changes of the bugfix releases at a glance:

- Restored TLS 1.3 signature algorithms in TLS 1.2. Among other things, this makes the solar forecast work reliably again.
- Disallowed overriding known meter locations to prevent misconfiguration.
- Fixed the Iskra WM3M4C's non-resettable energy values being incorrectly marked as resettable.
- Fixed charge log generation with a time filter as well as the configuration of automation rules.
- Improved the readability of the graphs and fixed the configuration of Carlo Gavazzi EM270 and EM280 meters.

As always, you can find the complete list of changes in the changelog directly in the web interface of your device or on our [download page](/en/software/downloads#firmware).

We hope you enjoy the update!
