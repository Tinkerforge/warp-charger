#!/usr/bin/python3

from api_doc_common import *
from mods import mods

import re
import os
import sys

def resolve_ref_md(match):
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
        link_text = "{}/{}".format(module, fn) if label is None else label

    return f"[{link_text}]({module}.mdx#{anchor})"

for x in mods:
    content = x.to_md()
    content = re.sub("{{{ref:([^}]*)}}}", resolve_ref_md, content)
    with open(f"../docs.warp-charger.com/docs/mqtt_http/api_referenz/{x.name}.mdx", "w") as f:
        f.write(content)
