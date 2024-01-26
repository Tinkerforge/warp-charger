#!/usr/bin/python3

from api_doc_common import *
from mods import mods

import re
import os
import sys

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

    if destination_filename != None:
        with open(destination_filename, 'w') as f:
            f.writelines(lines)

    if remove_template:
        os.remove(template_filename)

    if destination_filename == None:
        return ''.join(lines)

#def generate_html(f: Func, module: str) -> str:
#    return f.root.root_to_html(f, module)

def resolve_ref(match, reference_link_texts):
    ref = match.group(1)
    module, fn = parse_api_name(ref)
    if module == "misc":
        anchor = ref
        link_text = ref
    else:
        anchor = "{}_{}".format(module, fn)
        link_text = "{}/{}".format(module, fn)

    if anchor not in reference_link_texts:
        if anchor.endswith("_update") and anchor.replace("_update", "") in reference_link_texts:
            anchor = anchor.replace("_update", "")
        else:
            print("Can't resolve reference {} ({}).".format(link_text, anchor))
            return 'UNRESOLVED REFERENCE {}'.format(anchor)

    return '<a class="scrollto text-monospace" href="#{}">{}</a>'.format(anchor, link_text)

nav_module_template = """<a class="nav-link ms-3" href="#reference-{module_name}">{module_display_name}</a>
    <div class="collapse">
        <nav class="nav nav-pills flex-column">
        {functions}
        </nav>
    </div>"""
nav_function_template = """<a class="nav-link" href="#{link}" style="margin-left: 2rem !important;">{link_text}</a>"""
nav_group_template = """<span class="ms-5">{}</span>"""

reference_link_texts = []
nav_mods = []
for m in mods:
    nav_fns = []
    for group, fns in itertools.groupby(m.functions, key=lambda f: f.type_):
        fns = list(fns)
        nav_fns.append(nav_group_template.format(group.name_plural()))
        nav_fns += [nav_function_template.format(
                link=("{}/{}".format(m.name, f.name) if not m.hide_prefix else f.name).replace("/", "_"),
                link_text="{}/<wbr>{}".format(m.name, f.name) if not m.hide_prefix else f.name) for f in fns]

        reference_link_texts += ["{}_{}".format(m.name, f.name) if not m.hide_prefix else f.name for f in fns]
    nav_mods.append(
        nav_module_template.format(
            module_name=m.name,
            module_display_name=m.display_name,
            functions="\n".join(nav_fns)))

nav = "\n".join(nav_mods)

reference = "\n".join([x.to_html() for x in mods])
reference = re.sub("{{{ref:([^}]*)}}}", lambda x: resolve_ref(x, reference_link_texts), reference)

suffix = "" if len(sys.argv) == 1 else "_" + sys.argv[1]
api_html = specialize_template("api.html.template", None, {
    "{reference}": reference,
    "{reference-nav}": nav
})

with open("../warp-charger.com/api{}.html".format(suffix), "w") as f:
    f.write('\n'.join([line.rstrip() for line in api_html.split('\n')]))
