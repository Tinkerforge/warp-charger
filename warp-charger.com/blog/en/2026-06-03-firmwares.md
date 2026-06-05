title: "Firmware Update"
slug: firmware-update
date: 2026-06-03
tag: Firmware

Today we released the new firmware 2.11.0 for all WARP Chargers and firmware 1.6.0 for the WARP Energy Manager 2.0, as well as 2.7.0 for the WARP Energy Manager 1.0.
In addition to many detailed improvements, the following features have been added:

# Central User Management
If the WARP Charger or WARP Energy Manager is configured as a load manager for additional WARP Chargers, the "Central Management" property can now be activated in the web interface under "Energy Management" -> "Wallboxes".
When activated, the load manager's users are used for charge authorization, e.g. via NFC tag. Additionally, the load manager then centrally records all charging sessions of all controlled wallboxes.
This allows up to 64 wallboxes to be centrally managed and a shared charging logbook to be created or sent.
Due to this change, the structure has changed slightly. There is no longer a separate page for NFC tag management. It has been integrated into the user management.

# Additional Devices Added
The list of our supported devices continues to grow. Q-Cells inverters are now also supported with their own profile. After much development effort, control of Kostal Plenticore G3 and Plus G2 inverters with battery control is now also possible. Many thanks to the customers who allowed us to test this!

The complete changelog can be found as always on our download page under the respective firmware: Firmwares (https://warp-charger.com/de/software/downloads#firmware)
