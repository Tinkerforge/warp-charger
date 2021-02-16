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


def get_changelog_version():
    versions = []

    with open(os.path.join('changelog.txt'), 'r') as f:
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

            if len(versions) > 0:
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

def main():
    # Add build flags
    t = time.time()
    build_time_flag = '-D_BUILD_TIME_=0x{:x}'.format(int(t))
    version = get_changelog_version()
    major_flag = '-D_MAJOR_={}'.format(version[0])
    minor_flag = '-D_MINOR_={}'.format(version[1])
    patch_flag = '-D_PATCH_={}'.format(version[2])

    name = env.GetProjectOption("name")
    display_name = env.GetProjectOption("display_name")
    host_prefix_flag = "-D__HOST_PREFIX__=\\\"{}\\\"".format(name)

    firmware_name_flag = "-D_FIRMWARE_NAME_={}_firmware_{}_{:x}".format(name, '_'.join(version), int(t))

    env.Append(
        BUILD_FLAGS=[
            build_time_flag,
            host_prefix_flag,
            firmware_name_flag,
            major_flag,
            minor_flag,
            patch_flag
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

        shutil.copytree(os.path.join(mod_path), os.path.join("src", "modules", name.under))

    specialize_template("main.cpp.template", os.path.join("src", "main.cpp"), {
        '{{{module_includes}}}': '\n'.join(['#include "modules/{0}/{0}.h"'.format(x.under) for x in backend_modules]),
        '{{{module_decls}}}': '\n'.join(['{} {};'.format(x.camel, x.under) for x in backend_modules]),
        '{{{module_setup}}}': '\n    '.join(['{}.setup();'.format(x.under) for x in backend_modules]),
        '{{{module_register_urls}}}': '\n    '.join(['{}.register_urls();'.format(x.under) for x in backend_modules]),
        '{{{module_loop}}}': '\n    '.join(['{}.loop();'.format(x.under) for x in backend_modules]),
        '{{{display_name}}}': display_name,
        '{{{module_init_config}}}': ',\n        '.join('{{"{0}", Config::Bool({0}.initialized)}}'.format(x.under) for x in backend_modules)
    })

    # Embed frontend modules
    navbar_entries = []
    content_entries = []
    status_entries = []
    frontend_modules = [FlavoredName(x).get() for x in env.GetProjectOption("frontend_modules").splitlines()]

    recreate_dir(os.path.join("web", "src", "ts", "modules"))
    for name in frontend_modules:
        mod_path = os.path.join("modules", "frontend", name.under)

        if not os.path.exists(mod_path) or not os.path.isdir(mod_path):
            mod_path = os.path.join("esp32-brick", "software", mod_path)

        if not os.path.exists(mod_path) or not os.path.isdir(mod_path):
            print("Frontend module {} not found.".format(name.space, mod_path))

        if os.path.exists(os.path.join(mod_path, 'navbar.html')):
            with open(os.path.join(mod_path, 'navbar.html')) as f:
                navbar_entries.append(f.read())

        if os.path.exists(os.path.join(mod_path, 'content.html')):
            with open(os.path.join(mod_path, 'content.html')) as f:
                content_entries.append(f.read())

        if os.path.exists(os.path.join(mod_path, 'status.html')):
            with open(os.path.join(mod_path, 'status.html')) as f:
                status_entries.append(f.read())

        shutil.copy(os.path.join(mod_path, 'main.ts'), os.path.join("web", "src", "ts", "modules", name.under + ".ts"))

    specialize_template(os.path.join("web", "index.html.template"), os.path.join("web", "src", "index.html"), {
        '{{{navbar}}}': '\n                        '.join(navbar_entries),
        '{{{content}}}': '\n                    '.join(content_entries),
        '{{{status}}}': '\n                            '.join(status_entries),
        '{{{display_name}}}': display_name
    })

    specialize_template(os.path.join("web", "main.ts.template"), os.path.join("web", "src", "main.ts"), {
        '{{{module_imports}}}': '\n'.join(['import * as {0} from "./ts/modules/{0}";'.format(x.under) for x in frontend_modules]),
        '{{{module_interface}}}': ',\n    '.join('{}: boolean'.format(x.under) for x in backend_modules),
        '{{{modules}}}': ', '.join([x.under for x in frontend_modules]),
    })

    # Generate web interface
    with ChangedDirectory('web'):
        subprocess.run(["npx", "gulp"])

    shutil.copy2("web/dist/index.html.h", "src/index.html.h")

main()
