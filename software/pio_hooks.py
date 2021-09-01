#!/bin/python

Import("env")

from collections import namedtuple
import functools
import os
import shutil
import subprocess
import sys
import time
import re
from zlib import crc32

NameFlavors = namedtuple('NameFlavors', 'space lower camel headless under upper dash camel_abbrv lower_no_space camel_constant_safe')

class FlavoredName(object):
    def __init__(self, name):
        self.words = name.split(' ')
        self.cache = {}

    def get(self, skip=0, suffix=''):
        key = str(skip) + ',' + suffix

        try:
            return self.cache[key]
        except KeyError:
            if skip < 0:
                words = self.words[:skip]
            else:
                words = self.words[skip:]

            words[-1] += suffix

            self.cache[key] = NameFlavors(' '.join(words), # space
                                          ' '.join(words).lower(), # lower
                                          ''.join(words), # camel
                                          ''.join([words[0].lower()] + words[1:]), # headless
                                          '_'.join(words).lower(), # under
                                          '_'.join(words).upper(), # upper
                                          '-'.join(words).lower(), # dash
                                          ''.join([word.capitalize() for word in words]),  # camel_abbrv; like camel, but produces GetSpiTfp... instead of GetSPITFP...
                                          ''.join(words).lower(),
                                          # camel_constant_safe; inserts '_' between digit-words to disambiguate between 1,1ms and 11ms
                                          functools.reduce(lambda l, r: l + '_' + r if (l[-1].isdigit() and r[0].isdigit()) else l + r, words))

            return self.cache[key]

def recreate_dir(path):
    if os.path.exists(path):
        shutil.rmtree(path)

    os.makedirs(path)

def specialize_template(template_filename, destination_filename, replacements, check_completeness=True, remove_template=False):
    lines = []
    replaced = set()

    with open(template_filename, 'r') as f:
        for line in f.readlines():
            for key in replacements:
                replaced_line = line.replace(key, replacements[key])

                if replaced_line != line:
                    replaced.add(key)

                line = replaced_line

            lines.append(line)

    if check_completeness and replaced != set(replacements.keys()):
        raise Exception('Not all replacements for {0} have been applied. Missing are {1}'.format(template_filename, ', '.join(set(replacements.keys() - replaced))))

    with open(destination_filename, 'w') as f:
        f.writelines(lines)

    if remove_template:
        os.remove(template_filename)

# use "with ChangedDirectory('/path/to/abc')" instead of "os.chdir('/path/to/abc')"
class ChangedDirectory(object):
    def __init__(self, path):
        self.path = path
        self.previous_path = None

    def __enter__(self):
        self.previous_path = os.getcwd()
        os.chdir(self.path)

    def __exit__(self, type_, value, traceback):
        os.chdir(self.previous_path)


def get_changelog_version(name):
    versions = []

    with open(os.path.join('changelog_{}.txt'.format(name)), 'r') as f:
        for i, line in enumerate(f.readlines()):
            line = line.rstrip()

            if len(line) == 0:
                continue

            if re.match(r'^(?:- [A-Z0-9\(]|  ([A-Za-z0-9\(\"]|--hide-payload)).*$', line) != None:
                continue

            m = re.match(r'^(?:<unknown>|20[0-9]{2}-[0-9]{2}-[0-9]{2}): ([0-9]+)\.([0-9]+)\.([0-9]+) \((?:<unknown>|[a-f0-9]+)\)$', line)

            if m == None:
                raise Exception('invalid line {} in changelog: {}'.format(i + 1, line))

            version = (int(m.group(1)), int(m.group(2)), int(m.group(3)))

            if version[0] not in [0, 1, 2]:
                raise Exception('invalid major version in changelog: {}'.format(version))

            if version[2] < 90 and len(versions) > 0:
                if versions[-1] >= version:
                    raise Exception('invalid version order in changelog: {} -> {}'.format(versions[-1], version))

                if versions[-1][0] == version[0] and versions[-1][1] == version[1] and versions[-1][2] + 1 != version[2]:
                    raise Exception('invalid version jump in changelog: {} -> {}'.format(versions[-1], version))

                if versions[-1][0] == version[0] and versions[-1][1] != version[1] and versions[-1][1] + 1 != version[1]:
                    raise Exception('invalid version jump in changelog: {} -> {}'.format(versions[-1], version))

                if versions[-1][1] != version[1] and version[2] != 0:
                    raise Exception('invalid version jump in changelog: {} -> {}'.format(versions[-1], version))

                if versions[-1][0] != version[0] and (version[1] != 0 or version[2] != 0):
                    raise Exception('invalid version jump in changelog: {} -> {}'.format(versions[-1], version))

            versions.append(version)

    if len(versions) == 0:
        raise Exception('no version found in changelog')

    version = (str(versions[-1][0]), str(versions[-1][1]), str(versions[-1][2]))
    return version

def write_firmware_info(display_name, major, minor, patch, build_time):
    buf = bytearray([0xFF] * 4096)

    # 7121CE12F0126E
    # tink er for ge
    buf[0:7] = bytearray.fromhex("7121CE12F0126E") # magic
    buf[7] = 0x01 #firmware_info_version, note: a new version has to be backwards compatible

    name_bytes = display_name.encode("utf-8") # firmware name, max 60 chars
    buf[8:8 + len(name_bytes)] = name_bytes
    buf[8 + len(name_bytes):68] = bytes(60 - len(name_bytes))
    buf[68] = 0x00 # 0 byte to make sure string is terminated. also pads the fw version, so that the build date will be 4-byte aligned
    buf[69] = int(major)
    buf[70] = int(minor)
    buf[71] = int(patch)
    buf[72:76] = build_time.to_bytes(4, byteorder='little')
    buf[4092:4096] = crc32(buf[0:4092]).to_bytes(4, byteorder='little')

    with open(os.path.join("build", "fw_info.bin"), "wb") as f:
        f.write(buf)

def main():
    # Add build flags
    t = time.time()
    build_time_flag = '-D_BUILD_TIME_=0x{:x}'.format(int(t))

    name = env.GetProjectOption("name")
    display_name = env.GetProjectOption("display_name")
    require_fw_info = env.GetProjectOption("require_fw_info")

    version = get_changelog_version(name)
    major_flag = '-D_MAJOR_={}'.format(version[0])
    minor_flag = '-D_MINOR_={}'.format(version[1])
    patch_flag = '-D_PATCH_={}'.format(version[2])

    write_firmware_info(display_name, *version, int(t))

    host_prefix_flag = "-D__HOST_PREFIX__=\\\"{}\\\"".format(name)

    firmware_name_flag = "-D_FIRMWARE_NAME_={}_firmware_{}_{:x}".format(name, '_'.join(version), int(t))

    env.Append(
        BUILD_FLAGS=[
            build_time_flag,
            host_prefix_flag,
            firmware_name_flag,
            major_flag,
            minor_flag,
            patch_flag,
            '-D__REQUIRE_FW_INFO__={}'.format(require_fw_info)
        ]
    )

    # Embed backend modules
    recreate_dir(os.path.join("src", "modules"))
    backend_modules = [FlavoredName(x).get() for x in env.GetProjectOption("backend_modules").splitlines()]
    for name in backend_modules:
        mod_path = os.path.join("modules", "backend", name.under)
        if not os.path.exists(mod_path) or not os.path.isdir(mod_path):
            mod_path = os.path.join("esp32-brick", "software", mod_path)

        if not os.path.exists(mod_path) or not os.path.isdir(mod_path):
            print("Backend module {} not found.".format(name.space, mod_path))

        if os.path.exists(os.path.join(mod_path, "prepare.py")):
            with ChangedDirectory(mod_path):
                subprocess.run(["python3", "prepare.py"])

        shutil.copytree(os.path.join(mod_path), os.path.join("src", "modules", name.under), ignore=shutil.ignore_patterns('*ignored'))

    specialize_template("main.cpp.template", os.path.join("src", "main.cpp"), {
        '{{{module_includes}}}': '\n'.join(['#include "modules/{0}/{0}.h"'.format(x.under) for x in backend_modules]),
        '{{{module_decls}}}': '\n'.join(['{} {};'.format(x.camel, x.under) for x in backend_modules]),
        '{{{module_setup}}}': '\n    '.join(['{}.setup();'.format(x.under) for x in backend_modules]),
        '{{{module_register_urls}}}': '\n    '.join(['{}.register_urls();'.format(x.under) for x in backend_modules]),
        '{{{module_loop}}}': '\n    '.join(['{}.loop();'.format(x.under) for x in backend_modules]),
        '{{{display_name}}}': display_name,
        '{{{module_init_config}}}': ',\n        '.join('{{"{0}", Config::Bool({0}.initialized)}}'.format(x.under) for x in backend_modules if not x.under.startswith("hidden_"))
    })

    specialize_template("modules.h.template", os.path.join("src", "modules.h"), {
        '{{{module_includes}}}': '\n'.join(['#include "modules/{0}/{0}.h"'.format(x.under) for x in backend_modules]),
        '{{{module_defines}}}': '\n'.join(['#define MODULE_{}_AVAILABLE'.format(x.upper) for x in backend_modules]),
        '{{{module_extern_decls}}}': '\n'.join(['extern {} {};'.format(x.camel, x.under) for x in backend_modules]),
    })

    # Embed frontend modules
    navbar_entries = []
    content_entries = []
    status_entries = []
    main_ts_entries = []
    frontend_modules = [FlavoredName(x).get() for x in env.GetProjectOption("frontend_modules").splitlines()]

    recreate_dir(os.path.join("web", "src", "ts", "modules"))
    for name in frontend_modules:
        mod_path = os.path.join("modules", "frontend", name.under)

        if not os.path.exists(mod_path) or not os.path.isdir(mod_path):
            mod_path = os.path.join("esp32-brick", "software", mod_path)

        if not os.path.exists(mod_path) or not os.path.isdir(mod_path):
            print("Frontend module {} not found.".format(name.space, mod_path))
            sys.exit(1)

        if os.path.exists(os.path.join(mod_path, 'navbar.html')):
            with open(os.path.join(mod_path, 'navbar.html')) as f:
                navbar_entries.append(f.read())

        if os.path.exists(os.path.join(mod_path, 'content.html')):
            with open(os.path.join(mod_path, 'content.html')) as f:
                content_entries.append(f.read())

        if os.path.exists(os.path.join(mod_path, 'status.html')):
            with open(os.path.join(mod_path, 'status.html')) as f:
                status_entries.append(f.read())

        if os.path.exists(os.path.join(mod_path, 'main.ts')):
            main_ts_entries.append(name)
            shutil.copy(os.path.join(mod_path, 'main.ts'), os.path.join("web", "src", "ts", "modules", name.under + ".ts"))

    specialize_template(os.path.join("web", "index.html.template"), os.path.join("web", "src", "index.html"), {
        '{{{navbar}}}': '\n                        '.join(navbar_entries),
        '{{{content}}}': '\n                    '.join(content_entries),
        '{{{status}}}': '\n                            '.join(status_entries),
        '{{{display_name}}}': display_name
    })

    specialize_template(os.path.join("web", "main.ts.template"), os.path.join("web", "src", "main.ts"), {
        '{{{module_imports}}}': '\n'.join(['import * as {0} from "./ts/modules/{0}";'.format(x.under) for x in main_ts_entries]),
        '{{{module_interface}}}': ',\n    '.join('{}: boolean'.format(x.under) for x in backend_modules),
        '{{{modules}}}': ', '.join([x.under for x in main_ts_entries]),
    })

    # Check translation completeness
    with ChangedDirectory('web'):
        subprocess.run(["python3", "check_translation_completeness.py"], check=True)

    # Generate web interface
    with ChangedDirectory('web'):
        subprocess.run(["npx", "gulp"])

    shutil.copy2("web/dist/index.html.h", "src/index.html.h")

main()
