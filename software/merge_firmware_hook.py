Import("env", "projenv")

from collections import namedtuple
import functools
import os
import shutil
import subprocess
import sys
import time

my_flags = env.ParseFlags(env['BUILD_FLAGS'])
defines = {k: v for (k, v) in my_flags.get("CPPDEFINES")}

env.AddPostAction(
    "$BUILD_DIR/${PROGNAME}.elf",
    env.VerboseAction(" ".join([
        "cp", "$BUILD_DIR/${PROGNAME}.elf", "$BUILD_DIR/../../../build/{}.elf".format(defines.get("__FIRMWARE_NAME__"))
    ]), "Copying $BUILD_DIR/${PROGNAME}.elf")
)

env.AddPostAction(
    "$BUILD_DIR/${PROGNAME}.bin",
    env.VerboseAction(" ".join([
        "cp", "$BUILD_DIR/${PROGNAME}.bin", "$BUILD_DIR/../../../build/{}.bin".format(defines.get("__FIRMWARE_NAME__"))
    ]), "Copying $BUILD_DIR/${PROGNAME}.bin")
)

env.AddPostAction(
    "$BUILD_DIR/${PROGNAME}.bin",
    env.VerboseAction(" ".join([
        "python3", "merge_bins.py",
        "0x1000", "$BUILD_DIR/../../../bootloader_dio_40m.bin",
        "0x8000", "$BUILD_DIR/partitions.bin",
        "0xe000", "$BUILD_DIR/../../../boot_app0.bin",
        "0x10000", "$BUILD_DIR/${PROGNAME}.bin",
        "$BUILD_DIR/../../../build/{}-merged.bin".format(defines.get("__FIRMWARE_NAME__"))
    ]), "Merging firmware.bin")
)
