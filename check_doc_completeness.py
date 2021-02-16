#!/usr/bin/python3
import json
import sys

from bs4 import BeautifulSoup

if len(sys.argv) != 2:
    print("Usage: {} [path/to/debug_report.json]".format(sys.argv[0]))
    sys.exit(0)

UNDOCUMENTED = [
    "free_heap_bytes",
    "largest_free_heap_block",
    "devices",
    "error_counters",
    "modules",
    "debug/state",
    "proxy/devices",
    "proxy/error_counters"
]

with open("warp-charger.com/api.html") as fp:
    soup = BeautifulSoup(fp, 'html.parser')

entries = sum([s.select('div[id]') for s in soup.select('#reference')[0].select('section')], [])

documented = {}

for e in entries:
    topic = e.get_text()
    payload_keys = [x.get_text() for x in e.parent.select('th[scope="row"]')]
    documented[topic] = payload_keys


with open(sys.argv[1]) as f:
    debug_report = json.load(f)

for k, v in debug_report.items():
    if k in UNDOCUMENTED:
        continue
    if k.endswith("_update") and k.replace("_update", "") in debug_report:
        continue

    if k not in documented:
        print("Topic {} is undocumented.".format(k))
        continue

    impl_dict = isinstance(v, dict)
    doc_dict = len(documented[k]) > 0
    if impl_dict != doc_dict:
        print("Topic {} is {}implemented as object, but is {}documented as such.".format(k, "" if impl_dict else "not ", "" if doc_dict else "not "))
        continue

    if not impl_dict:
        continue

    for impl_key, impl_val in v.items():
        if impl_key not in documented[k]:
            print("Topic {} is missing the implemented key {}.".format(k, impl_key))

    for doc_key in documented[k]:
        if doc_key not in v:
            print("Topic {} documents key {}, but this key is missing in the implementation.".format(k, doc_key))
