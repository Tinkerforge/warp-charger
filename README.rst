WARP Charger
============

You can find more information, technical details etc. about WARP Chargers at http://warp-charger.com.

This repository contains the source of this web site, all released firmwares, the manual and some additional information.

The main software of WARP Chargers is running on a ESP32.
It can be found found at https://github.com/Tinkerforge/esp32-firmware

More information about the hardware can be found here:

ESP32 Ethernet Brick:
 * https://github.com/Tinkerforge/esp32-ethernet-brick

EVSE Bricklet:
 * https://github.com/Tinkerforge/evse-v2-bricklet


Repository Content
------------------

documents/:
 * Contains test reports, data sheets and manuals for the WARP Charger itself and used components

firmwares/:
 * All released firmwares as well as their .elf files used for decoding stack traces and further debugging

hardware/:
 * Contains KiCad project files for some custom PCBs used in the WARP Charger

label/:
 * Scripts and other files used to create and print the type label sticker

manual/:
 * LaTeX source and used resources for the manual

warp-charger.com/:
 * The source of the WARP Charger web site

Firmwares
---------

The firmwares folder contains all released firmwares as bin files. These can be flashed
using the web interface or over USB using https://github.com/espressif/esptool/ at offset 0x1000.
The folder also contains the ELF files with debug information.

Hardware
--------

Parts of the hardware are designed with the open source EDA Suite KiCad
(http://www.kicad.org). Before you are able to open the files,
you have to install the Tinkerforge kicad-libraries
(https://github.com/Tinkerforge/kicad-libraries). You can either clone
them directly in hardware/ or clone them in a separate folder and
symlink them into hardware/
(ln -s kicad_path/kicad-libraries project_path/hardware). After that you
can open the .pro file in hardware/ with KiCad and from there view and
modify the schematics and the PCB layout.
