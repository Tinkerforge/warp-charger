WARP Charger
============

You can find more information, technical details etc. about WARP Chargers at http://warp-charger.com.

This repository contains the source of this web site, all released firmwares, the manual and some additional information.

Repository Overview
-------------------

.. DO NOT EDIT THIS OVERVIEW MANUALLY! CHANGE https://github.com/Tinkerforge/esp32-firmware/repo_overview.rst AND COPY THAT BLOCK INTO ALL REPOS LISTED BELOW. TODO: AUTOMATE THIS

Software
~~~~~~~~
- `esp32-firmware <https://github.com/Tinkerforge/esp32-firmware>`__  **Please report any issues concerning WARP hard- and software here!** Source code of the ESP32 firmware shared between all WARP Chargers and Energy Managers

- `tfjson <https://github.com/Tinkerforge/tfjson>`__ SAX style JSON serializer and deserializer
- `tfmodbustcp <https://github.com/Tinkerforge/tfmodbustcp>`__ Modbus TCP server and client implementation
- `tfocpp <https://github.com/Tinkerforge/tfocpp>`__ OCPP 1.6 implementation
- `tftools <https://github.com/Tinkerforge/tftools>`__ Miscellaneous tools and helpers

- `esp32-remote-access <https://github.com/Tinkerforge/esp32-remote-access>`__ Source code of the my.warp-charger.com remote access server

- `warp-charger <https://github.com/Tinkerforge/warp-charger>`__ The source code of (docs.)warp-charger.com and the printed manual, released firmwares, datasheets and documents, as well as some tools and hardware design files
- `api.warp-charger.com <https://github.com/Tinkerforge/api.warp-charger.com>`__ Serves APIs that are used by WARP Chargers to obtain relevant public information like day ahead prices
- `vislog.warp-charger.com <https://github.com/Tinkerforge/vislog.warp-charger.com>`__ Visualizes WARP Charger logs and EVSE debug protocols
- `dbus-warp-charger <https://github.com/Tinkerforge/dbus-warp-charger>`__ Integrates WARP Chargers into a Victron Energy Venus OS device (e.g. Cerbo GX)

WARP Charger Hardware
~~~~~~~~~~~~~~~~~~~~~~

- `esp32-brick <https://github.com/Tinkerforge/esp32-brick>`__ Hardware design files of the ESP32 Brick
- `evse-bricklet <https://github.com/Tinkerforge/evse-bricklet>`__  Firmware source code and hardware design files of the EVSE Bricklet
- `rs485-bricklet <https://github.com/Tinkerforge/rs485-bricklet>`__ Firmware source code and hardware design files of the RS485 Bricklet


WARP2 Charger Hardware
~~~~~~~~~~~~~~~~~~~~~~

- `esp32-ethernet-brick <https://github.com/Tinkerforge/esp32-ethernet-brick>`__ Hardware design files of the ESP32 Ethernet Brick
- `evse-v2-bricklet <https://github.com/Tinkerforge/evse-v2-bricklet>`__ Firmware source code and hardware design files of the EVSE 2.0 Bricklet
- `nfc-bricklet <https://github.com/Tinkerforge/nfc-bricklet>`__ Firmware source code and hardware design files of the NFC Bricklet

WARP3 Charger Hardware
~~~~~~~~~~~~~~~~~~~~~~

- `warp-esp32-ethernet-brick <https://github.com/Tinkerforge/warp-esp32-ethernet-brick>`__ Hardware design files of the WARP ESP32 Ethernet Brick
- `evse-v3-bricklet <https://github.com/Tinkerforge/evse-v3-bricklet>`__ Firmware source code and hardware design files of the EVSE 3.0 Bricklet
- `nfc-bricklet <https://github.com/Tinkerforge/nfc-bricklet>`__ Firmware source code and hardware design files of the NFC Bricklet

WARP Energy Manager Hardware
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- `esp32-ethernet-brick <https://github.com/Tinkerforge/esp32-ethernet-brick>`__ Hardware design files of the ESP32 Ethernet Brick
- `warp-energy-manager-bricklet <https://github.com/Tinkerforge/warp-energy-manager-bricklet>`__ Firmware source code and hardware design files of the WARP Energy Manager Bricklet

WARP Energy Manager 2.0 Hardware
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- `esp32-ethernet-brick <https://github.com/Tinkerforge/esp32-ethernet-brick>`__ Hardware design files of the ESP32 Ethernet Brick
- `warp-energy-manager-v2-bricklet <https://github.com/Tinkerforge/warp-energy-manager-v2-bricklet>`__ Firmware source code and hardware design files of the WARP Energy Manager 2.0 Bricklet
- `warp-front-panel-bricklet <https://github.com/Tinkerforge/warp-front-panel-bricklet>`__ Firmware source code and hardware design files of the WARP Front Panel Bricklet

Forked/patched projects
~~~~~~~~~~~~~~~~~~~~~~~

- `arduino-esp32 <https://github.com/Tinkerforge/arduino-esp32>`__
- `esp32-arduino-libs <https://github.com/Tinkerforge/esp32-arduino-libs>`__
- `WireGuard-ESP32-Arduino <https://github.com/Tinkerforge/WireGuard-ESP32-Arduino>`__


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
 * The source of the WARP Charger web site (this site is deprecated, the old hand-written html site has been moved to a wordpress)

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
