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
    "proxy/error_counters",
    "evse/reflash",
    "evse/reset"
]

with open("warp-charger.com/api.html") as fp:
    soup = BeautifulSoup(fp, 'html.parser')

entries = sum([s.select('div[id]') for s in soup.select('#reference')[0].select('section')], [])

documented = {}

def values(x):
    return x.get_text().split(" ")

def get_type(impl_val):
    # None is json null, so typically a censored password, i.e. a string
    if impl_val is None:
        return "string"
    if isinstance(impl_val, str):
        return "string"
    if isinstance(impl_val, bool):
        return "bool"
    if isinstance(impl_val, float):
        return "number"
    if isinstance(impl_val, int):
        return "number"

    if isinstance(impl_val, list):
        return "{}[{}]".format(get_type(impl_val[0]), len(impl_val))

    if isinstance(impl_val, dict):
        return "object"

def is_type_identical(l, r):
    if l == r:
        return True
    if l == "number" and r in ("float", "int", "uint"):
        return True
    if l in ("float", "int", "uint") and r == "number":
        return True

    if "[" in l and "[" in r:
        ltype = l.split("[")[0]
        rtype = r.split("[")[0]
        lcount = l.split("[")[1][:-1]
        rcount = r.split("[")[1][:-1]
        return is_type_identical(ltype, rtype) and \
               (lcount == "..." or \
                rcount == "..." or \
                lcount == rcount)

for e in entries:
    topic = values(e)[0]

    payload_keys = []
    for x in e.parent.select('th[scope="row"]'):
        l = values(x)
        payload_key = l[0]
        payload_type = l[1]
        payload_keys.append((payload_key, payload_type))

    documented[topic] = payload_keys

with open(sys.argv[1]) as f:
    debug_report = json.load(f)

for k, v in debug_report.items():
    if k in UNDOCUMENTED:
        continue
    if k.endswith("_update") and k.replace("_update", "") in debug_report:
        continue

    if k not in documented:
        print("{} is undocumented.".format(k))
        continue

    impl_dict = isinstance(v, dict)
    doc_dict = len(documented[k]) > 0
    if impl_dict != doc_dict:
        print("{} is {}implemented as object, but is {}documented as such.".format(k, "" if impl_dict else "not ", "" if doc_dict else "not "))
        continue

    if not impl_dict:
        continue

    for impl_key, impl_val in v.items():
        for doc_key, doc_type in documented[k]:
            if impl_key != doc_key:
                continue
            impl_type = get_type(impl_val)
            if not is_type_identical(impl_type, doc_type):
                print('{} key {} is implemeted as type {} but documented as type {}'.format(k, impl_key, impl_type, doc_type))
            break
        else:
            print("{} is missing the implemented key {}.".format(k, impl_key))

    for doc_key, doc_type in documented[k]:
        if doc_key not in v:
            print("{} documents key {}, but this key is missing in the implementation.".format(k, doc_key))
