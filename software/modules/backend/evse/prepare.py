# This file is duplicated for every module that embeds a firmware.
# When editing this file, keep the copies in sync!
import os
import re
import sys
from zipfile import ZipFile

firmwares = [x for x in os.listdir('.') if x.endswith(".zbin") and x.startswith("bricklet_")]
if len(firmwares) > 1:
    print("More than one firmware found in", os.getcwd())
    sys.exit(-1)

if len(firmwares) == 0:
    print("No firmware found in", os.getcwd())
    sys.exit(-1)

fw = firmwares[0]

match = re.fullmatch("bricklet_(.*)_firmware_\d+_\d+_\d+.zbin", fw)
if match is None:
    print("Firmware {} did not match naming schema".format(fw))
    sys.exit(-1)

fw_name = match.group(1)

with ZipFile(fw) as myzip:
    with myzip.open("{}-bricklet-firmware.bin".format(fw_name.replace("_", "-")), "r") as bin_file:
        with open("{}_firmware.cpp".format(fw_name), "w") as cpp:
            cpp.write("extern const unsigned char {}_bricklet_firmware_bin[] = {{\n".format(fw_name))
            written = 0
            b = bin_file.read(12)
            while len(b) != 0:
                # read first to prevent trailing , after last byte
                next_b = bin_file.read(12)
                cpp.write("    " + ", ".join(["0x{:02x}".format(x) for x in b]) + (",\n" if len(next_b) != 0 else "\n"))
                written += len(b)
                b = next_b

            cpp.write("};\n")

with open("{}_firmware.h".format(fw_name), "w") as h:
    h.write("extern const unsigned char {}_bricklet_firmware_bin[];\n".format(fw_name))
    h.write("const unsigned int {}_bricklet_firmware_bin_len = {};\n".format(fw_name, written))
