#!/usr/bin/python3
from api_doc_common import *

from mods import mods

import json
import sys

def typecheck(et: EType, obj, consts: Optional[list[Const]], path):
    if consts is not None and obj not in [x.val for x in consts]:
        print("{}: Implementation value {} not in list of constants".format(path, obj))
        return

    if et == EType.OBJECT and not isinstance(obj, dict):
        print("{}: Type mismatch: Documented OBJECT, returned {}".format(path, type(obj)))
        return
    if et == EType.ARRAY and not isinstance(obj, list):
        print("{}: Type mismatch: Documented ARRAY, returned {}".format(path, type(obj)))
        return
    if et == EType.STRING and not isinstance(obj, str):
        print("{}: Type mismatch: Documented STRING, returned {}".format(path, type(obj)))
        return
    if et == EType.INT and (not isinstance(obj, int) or isinstance(obj, bool)): # True and False are ints
        print("{}: Type mismatch: Documented INT, returned {}".format(path, type(obj)))
        return
    # We have to allow None (null in JSON) for floats, because a NaN can not be represented in JSON. ArduinoJSON turns NaNs into nulls.
    if et == EType.FLOAT and not isinstance(obj, float) and not isinstance(obj, int) and not obj is None:
        print("{}: Type mismatch: Documented FLOAT, returned {}".format(path, type(obj)))
        return
    if et == EType.BOOL and not isinstance(obj, bool):
        print("{}: Type mismatch: Documented BOOL, returned {}".format(path, type(obj)))
        return
    if et == EType.NULL and not obj is None:
        print("{}: Type mismatch: Documented NULL, returned {}".format(path, type(obj)))
        return
    if et == EType.OPAQUE:
        return

def check_elem_doc(e: Elem, obj, path):
    if e.censored:
        if obj is not None and obj != "":
            print("{}: Documented as censored but implementation returned value {}".format(path, obj))
        return

    if e.type_ == EType.OBJECT:
        if not isinstance(obj, dict):
            print("{}: Documented as object but implementation returned value {}".format(path, obj))
            return

        if set(e.val.keys()) != set(obj.keys()):
            conf_but_not_impl = set(e.val.keys()) - set(obj.keys())
            impl_but_not_conf = set(obj.keys()) - set(e.val.keys())

            if len(conf_but_not_impl) != 0 and len(impl_but_not_conf) != 0:
                print("{}: key mismatch. Implementation misses: {} Documentation misses {}".format(path, conf_but_not_impl, impl_but_not_conf))
            elif len(conf_but_not_impl) != 0:
                print("{}: key mismatch. Implementation misses: {}".format(path, conf_but_not_impl))
            elif len(impl_but_not_conf) != 0:
                print("{}: key mismatch. Documentation misses: {}".format(path, impl_but_not_conf))
            return

        for k in obj.keys():
            check_elem_doc(e.val[k], obj[k], "{}[{}]".format(path, k))
        return

    if e.type_ == EType.ARRAY:
        if not isinstance(obj, list):
            print("{}: Documented as array but implementation returned value {}".format(path, obj))
            return

        if e.val is not None:
            if len(e.val) != len(obj):
                print("{}: Array length mismatch: Documentation {} implementation {}".format(path, len(e.val), len(obj)))
                return

            for i in range(len(obj)):
                check_elem_doc(e.val[i], obj[i], "{}[{}]".format(path, i))
            return

        if e.is_var_length_array:
            for i, x in enumerate(obj):
                typecheck(e.var_length_array_type, x, e.constants, "{}(var-length)[{}]".format(path, i))
            return

    return typecheck(e.type_, obj, e.constants, path)


if len(sys.argv) != 3:
    print("Usage: {} [version] [path/to/debug_report.json]".format(sys.argv[0]))
    sys.exit(0)

# Those may appear in a debug report, but are not documented
UNDOCUMENTED = [
    "uptime",
    "free_heap_bytes",
    "largest_free_heap_block",
    "devices",
    "error_counters",
    "debug/state",
    "proxy/devices",
    "proxy/error_counters",
    "evse/reflash",
    "evse/reset",
    "nfc/reflash",
    "nfc/reset",
    "rs485/reflash",
    "rs485/reset",
    "ethernet/force_reset",
    "charge_manager/scan",
    "info/ws",
    "ocpp/state",
    "ocpp/configuration",
    "rtc/reflash",
    "rtc/reset",
    "energy_manager/reflash",
    "energy_manager/reset",
    "energy_manager/debug_config",
]

version = Version(int(sys.argv[1]))

mods = [m for m in mods if version in m.version]

# Those are documented, but will not appear in a debug report. Typically raw commands.
IMPLEMENTED = [
    "charge_tracker/remove_all_charges",
    "users/modify"
]

all_functions = set(["{}/{}".format(m.name, f.name) if m.name != "misc" else f.name for m in mods for f in m.functions])

for m in mods:
    for f in m.functions:
        if f.type_ == FuncType.HTTP_ONLY:
            all_functions.discard("{}/{}".format(m.name, f.name) if m.name != "misc" else f.name)
        if version not in f.root.version:
            all_functions.discard("{}/{}".format(m.name, f.name) if m.name != "misc" else f.name)

for x in IMPLEMENTED:
    all_functions.discard(x)

def filter_elem(e: Elem, ver: int):
    if e.val is None:
        return e

    if isinstance(e.val, list):
        e.val = [filter_elem(x, ver) for x in e.val if ver in x.version]

    if isinstance(e.val, dict):
        e.val = {k: filter_elem(v, ver) for k, v in e.val.items() if ver in v.version}

    return e

for m in mods:
    m.functions = [f for f in m.functions if version in f.root.version]
    for f in m.functions:
        f.root = filter_elem(f.root, version)

with open(sys.argv[2]) as f:
    debug_report = json.load(f)

for k, v in debug_report.items():
    all_functions.discard(k)

    if k in UNDOCUMENTED:
        continue
    if k.endswith("_update") and k.replace("_update", "") in debug_report:
        continue
    if k.endswith("_modified") and k.replace("_modified", "") in debug_report:
        continue
    if k.endswith("_reset") and k.replace("_reset", "") in debug_report:
        continue

    if '/' not in k:
        mod = "misc"
        fn = k
    else:
        mod, fn = k.split("/")

    for m in mods:
        if m.name != mod:
            continue
        config_mod = m
        break
    else:
        print("Implemented function {mod}/{fn}: Module {mod} not found in documentation!".format(mod=mod, fn=fn))
        continue

    for f in config_mod.functions:
        if f.name != fn:
            continue
        config_func = f
        break
    else:
        print("Implemented function {mod}/{fn}: Function {fn} not found in documentation module {mod}!".format(mod=mod, fn=fn))
        continue

    check_elem_doc(config_func.root, v, "{mod}/{fn}".format(mod=mod, fn=fn))

print("Documented functions that were not found in debug report:")
print("   ", "\n    ".join(all_functions))
