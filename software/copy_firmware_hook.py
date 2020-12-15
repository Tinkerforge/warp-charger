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
