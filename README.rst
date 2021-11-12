WARP Charger
============

This repository contains the firmware source code and the hardware design
files, as well as the source code of the web site, all released firmwares,
documents and more.

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
