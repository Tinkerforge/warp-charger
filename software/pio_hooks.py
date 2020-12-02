#!/bin/python

Import("env")

from collections import namedtuple
import functools
import os
import shutil
import subprocess
import sys
import time

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

def main():
    # Add build flags
    git_commit = subprocess.check_output(['git', 'rev-parse', 'HEAD']).decode('utf-8').strip()
    git_commit = '{:x}'.format(int(time.time())) + git_commit[:8]
    git_flag = '-D__COMMIT_ID__=0x{}ull'.format(git_commit)

    name = env.GetProjectOption("name")
    display_name = env.GetProjectOption("display_name")
    host_prefix_flag = "-D__HOST_PREFIX__=\\\"{}-\\\"".format(name)

    env.Append(
        BUILD_FLAGS=[
            git_flag,
            host_prefix_flag
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
        '{{{module_on_event_connect}}}': '\n        '.join(['{}.onEventConnect(client);'.format(x.under) for x in backend_modules]),
        '{{{module_loop}}}': '\n    '.join(['{}.loop();'.format(x.under) for x in backend_modules]),
        '{{{display_name}}}': display_name
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
        '{{{modules}}}': ', '.join([x.under for x in frontend_modules]),
    })

    # Generate web interface
    with ChangedDirectory('web'):
        subprocess.run(["npx", "gulp"])

    shutil.copy2("web/dist/index.html.h", "src/index.html.h")

main()
