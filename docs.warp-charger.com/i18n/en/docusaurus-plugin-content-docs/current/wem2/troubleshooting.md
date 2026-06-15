---
sidebar_position: 5
---

# Troubleshooting

Error states are indicated by the WARP Energy Manager 2.0 LED of the front button in red. Generally, the [Energy Manager web interface](/webinterface/energy_manager/debug.md) provides more information about the error.

## Error Diagnosis

### Display is off, front button LED is not lit

The WARP Energy Manager is probably without power. The 230V power connection and internal fuse should be checked.

### Display is off, front button LED is green

The display backlight turns off after a period of inactivity. Pressing the front button wakes it up again.

### The WARP Energy Manager 2.0 is not reachable via LAN / WiFi, but the front button LED is green

In this case, check whether the WARP Energy Manager has possibly gone into access point fallback. As in factory state, the Energy Manager then opens its own WiFi.
If the access data has not been changed, it corresponds to the factory settings and can be found on the sticker on the back of the manual.


## Fuse Replacement

The WARP Energy Manager is internally protected by a 5×20 mm fine fuse (slow-blow (T), 2 A). Tinkerforge uses fuses of type "ESKA 522.520". 
