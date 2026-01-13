#!/usr/bin/python3

from api_doc_common import *
from mods import mods

import re
import os
import sys

LOCALES = ['de', 'en']
OUTPUT_PATHS = {
    'de': '../docs.warp-charger.com/docs/interfaces/mqtt_http/api_reference/',
    'en': '../docs.warp-charger.com/i18n/en/docusaurus-plugin-content-docs/current/interfaces/mqtt_http/api_reference/'
}

def resolve_ref_md(match, locale):
    ref = match.group(1)
    label = None
    if ":" in ref:
        ref, label = ref.split(":", 1)

    module, fn = parse_api_name(ref)
    if module == "misc":
        anchor = ref
        link_text = ref if label is None else label
    else:
        anchor = "{}_{}".format(module, fn.replace("/", "_"))
        link_text = "`{}/{}`".format(module, fn) if label is None else label

    # Links are locale-agnostic as Docusaurus handles the locale prefix
    return f"[{link_text}](/interfaces/mqtt_http/api_reference/{module}.mdx#{anchor})"

def resolve_mod_ref_md(match, locale):
    ref = match.group(1)
    if ":" in ref:
        ref, label = ref.split(":", 1)
    else:
        label = f'`{ref}`-Modul' if locale == 'de' else f'`{ref}` module'

    module = ref
    return f"[{label}](/interfaces/mqtt_http/api_reference/{ref}.mdx)"

print(f"Generating API documentation for locales: {LOCALES}")

for locale in LOCALES:
    print(f"\n=== Generating {locale} documentation ===")

    # Ensure output directory exists
    os.makedirs(OUTPUT_PATHS[locale], exist_ok=True)

    for x in mods:
        content = x.to_md(locale=locale)
        content = re.sub("{{{ref:([^}]*)}}}", lambda m: resolve_ref_md(m, locale), content)
        content = re.sub("{{{mod_ref:([^}]*)}}}", lambda m: resolve_mod_ref_md(m, locale), content)

        output_file = f"{OUTPUT_PATHS[locale]}{x.name}.mdx"
        with open(output_file, "w") as f:
            f.write(content)
        print(f"  Generated: {x.name}.mdx")
