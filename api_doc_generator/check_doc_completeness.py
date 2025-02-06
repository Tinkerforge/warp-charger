#!/usr/bin/env python3

from api_doc_common import *

from mods import mods

import json
import sys

# TODO: Check that no html links are used in the reference. Use markdown links instead. A markdown link gets an icon if it is an external link.

UNDOCUMENTED_MODULES = [
    "automation_trigger", # This is a HTTP wildcard handler. We currently can't document those
    "debug",
    "hidden_proxy"
]


UNDOCUMENTED_FUNCTIONS = [
    # Maybe document in the future
        "http_only charge_tracker/pdf",
        "state info/ws", # Web socket debug info. Maybe document as opaque?
        "http_only check_firmware", # Document if we document how to flash a firmware via HTTP
        "http_only event_log",
        "http_only trace_log",
        "state ocpp/configuration",
        "state ocpp/state",

        "state power_manager/debug_config",
        "state power_manager/debug_config_modified",
        "command power_manager/debug_config_reset",
        "command power_manager/debug_config_update",
    # End maybe document in the future


    # Don't document
        # Page handlers
            "http_only ",
            "http_only manifest.json",
            "http_only recovery",
        # End page handlers

        "http_only *", # API HTTP handler

        "http_only api_info", # Only usable if DEBUG_FS_ENABLE is defined

        "command charge_manager/scan",
        "http_only charge_manager/scan_result",

        "command ethernet/force_reset", # Maybe remove this API in the future

        "http_only credential_check", # Only required for the web interface to show a nice login dialogue
        "http_only login_state", # Only required for the web interface to show a nice login dialogue
    # End don't document

    # DeviceModule API
    "state evse/identity",
    "command evse/reflash",
    "command evse/reset",
    "state nfc/identity",
    "command nfc/reflash",
    "command nfc/reset",
    "state rs485/identity",
    "command rs485/reflash",
    "command rs485/reset",
    "state rtc/identity",
    "command rtc/reflash",
    "command rtc/reset",
    "state energy_manager/identity",
    "command energy_manager/reflash",
    "command energy_manager/reset",
    "state front_panel/identity",
    "command front_panel/reflash",
    "command front_panel/reset",
]

colors = {"off":"\x1b[00m",
          "blue":   "\x1b[34m",
          "cyan":   "\x1b[36m",
          "green":  "\x1b[32m",
          "red":    "\x1b[31m",
          "gray": "\x1b[90m",
          "yellow": "\x1b[33m",
          "blink": "\x1b[5m"}

def red(s):
    return colors["red"]+s+colors["off"]

def yellow(s):
    return colors['yellow']+s+colors["off"]

pedantic = False
def print_pedantic(s):
    global pedantic
    if pedantic:
        print(colors['gray'] + s + colors['off'])

def check_element(elem: Elem, info: dict, name: str, path: str, keys_to_censor: list[str], version: Version, api_info: list):
    type_dict = {
        "array": EType.ARRAY,
        "bool": EType.BOOL,
        "float": EType.FLOAT,
        "int": EType.INT,
        "null": EType.NULL,
        "object": EType.OBJECT,
        "string": EType.STRING,
        "uint": EType.INT,
        "union": EType.UNION
    }

    if elem.type_ == EType.OPAQUE:
        return

    if elem.type_ != EType.HIDDEN_UNION and elem.type_ != type_dict[info["type"]]:
        print(red(f'Type mismatch: {path} is implemented as {info["type"]} but documented as {elem.type_.name}'))
        return

    if (name in keys_to_censor) != elem.censored:
        print(yellow(f'{path} is {"" if name in keys_to_censor else "not "}censored, but documented as {"" if elem.censored else "not "}censored'))

    if elem.type_ == EType.OBJECT:
        doc_missing = set(x["key"] for x in info["entries"]).difference(k for k, v in elem.val.items() if version in v.version)
        impl_missing = set(k for k, v in elem.val.items() if version in v.version).difference(x["key"] for x in info["entries"])

        if len(doc_missing) > 0:
            print(red(f"{path} undocumented keys\n"), "\t" + "\n\t".join(sorted(doc_missing)))

        if len(impl_missing) > 0:
            print(red(f"{path} documented, but unimplemented keys\n"), "\t" + "\n\t".join(sorted(impl_missing)))

        for k, v in elem.val.items():
            if version not in v.version or k in impl_missing:
                continue

            check_element(v, next(x["value"] for x in info["entries"] if x["key"] == k), k, f'{path}["{k}"]', keys_to_censor, version, api_info)
    if elem.type_ == EType.ARRAY:
        variant_type = {
            0: EType.NULL,
            1: EType.STRING,
            2: EType.FLOAT,
            3: EType.INT,
            4: EType.INT,
            5: EType.BOOL,
            6: EType.ARRAY,
            7: EType.OBJECT,
            8: EType.UNION
        }[info["variantType"]]

        if not elem.is_var_length_array and info["minElements"] != info["maxElements"]:
            print_pedantic(f'Length mismatch: {path} is not documented as variable length array but implementation minElements {info["minElements"]} != maxElements {info["maxElements"]}')

        if not elem.is_var_length_array and elem.val is not None and sum(1 for x in elem.val if version in x.version) != info["maxElements"]:
            print(red(f'Length mismatch: {path} is documented as having {sum(1 for x in elem.val if version in x.version)} entries but implementation maxElements are {info["maxElements"]}'))

        if elem.var_length_array_type is not None and elem.var_length_array_type != variant_type:
            print(red(f'Type mismatch: {path} is documented as having array members of type {elem.var_length_array_type.name} but implementation has variantType {variant_type.name}'))

        if elem.val is not None and any(m.type_ != variant_type for m in elem.val if version in m.version):
            print(red(f'Type mismatch: {path} implementation has variantType {variant_type.name} but some documented members have other types. Offending members:\n'), "\t" + "\n\t".join(f'[{i}]: {m.desc}' for i, m in enumerate(elem.val) if version in m.version and m.type_ != variant_type))

        if elem.val is not None:
            for i, m in enumerate(elem.val[:len(info["content"])]):
                if version not in m.version:
                    continue

                check_element(m, info["content"][i], str(i), path + f"[{i}]", keys_to_censor, version, api_info)
    if elem.type_ == EType.INT or elem.type_ == EType.FLOAT or elem.type_ == EType.STRING or elem.type_ == EType.BOOL:
        if elem.constants is not None:
            for c in elem.constants:
                if version not in c.version:
                    continue
                if c.val == info["val"]:
                    break
            else:
                print(red(f'{path} documented constants did not contain implementation value {info["val"]}'))

            if (elem.type_ == EType.INT and all(isinstance(c.val, int) for c in elem.constants)) or (elem.type_ == EType.FLOAT and all(isinstance(c.val, float) for c in elem.constants)) :
                min_const = min([c for c in elem.constants], key=lambda c: c.val)
                max_const = max([c for c in elem.constants], key=lambda c: c.val)
                if info["min"] != min_const.val:
                    print_pedantic(f'{path} smallest documented constant {min_const} is not implementation minimum value {info["min"]}')
                if info["max"] != max_const.val:
                    print_pedantic(f'{path} largest documented constant {max_const} is not implementation maximum value {info["max"]}')
    if elem.type_ == EType.NULL:
        pass # Nothing to do here
    if elem.type_ == EType.OPAQUE:
        pass # Nothing to do here
    if elem.type_ == EType.UNION:
        doc_missing = set(x["tag"] for x in info["prototypes"]).difference(k for k, v in elem.val.items() if version in v.version)
        impl_missing = set(k for k, v in elem.val.items() if version in v.version).difference(x["tag"] for x in info["prototypes"])

        if len(doc_missing) > 0:
            print(red(f"{path} undocumented union variants\n"), "\t" + "\n\t".join(str(x) for x in sorted(doc_missing)))

        if len(impl_missing) > 0:
            print(red(f"{path} documented, but unimplemented union variants\n"), "\t" + "\n\t".join(str(x) for x in sorted(impl_missing)))

        for k, v in elem.val.items():
            if version not in v.version or k in impl_missing:
                continue

            check_element(v, next(x["value"] for x in info["prototypes"] if x["tag"] == k), k, f'{path}({k})', keys_to_censor, version, api_info)

    if elem.type_ == EType.HIDDEN_UNION:
        tag = elem.hidden_union_get_tag(re.split(r"[\[\(]", path)[0], api_info)
        if tag not in elem.val:
            print(red(f"{path} undocumented union variant {tag}"))
        else:
            check_element(elem.val[tag], info, tag, f'{path}({tag})', keys_to_censor, version, api_info)


def main():
    if "--pedantic" in sys.argv:
        global pedantic
        pedantic = True
        sys.argv.remove("--pedantic")

    with open(sys.argv[1]) as f:
        api_info = json.load(f)

    info_name = next(x for x in api_info if x["path"] == "info/name")
    firmware_type_name = next(x for x in info_name["content"]["entries"] if x["key"] == "type")["value"]["val"]
    if firmware_type_name == "warp":
        firmware_type_name = "warp1"

    if firmware_type_name == "seb":
        firmware_type_name = "wem2"

    impl_version = next(x for x in Version if x.name.lower() == firmware_type_name)

    undocumented_modules = set()
    undocumented_functions = set()

    documented_functions = {}

    for mod in mods:
        if impl_version not in mod.version:
            continue

        for fn in mod.functions:
            if impl_version not in fn.root.version:
                continue
            documented_functions[fn.api_name(mod.name)] = fn

    for impl_fn in api_info:
        if "/" not in impl_fn["path"]:
            impl_mod_name, impl_fn_name = "misc", impl_fn["path"]
        else:
            impl_mod_name, impl_fn_name = impl_fn["path"].split("/", 1)

        if re.match(r"^\d/", impl_fn_name):
            impl_fn_name = "X/" + impl_fn_name[2:]

        impl_fn_name = re.sub(r"/\d+/", "/X/", impl_fn_name)

        try:
            doc_mod = next(m for m in mods if m.name == impl_mod_name)
        except StopIteration:
            undocumented_modules.add(impl_mod_name)
            continue

        try:
            doc_fn = next(f for f in doc_mod.functions if f.name == impl_fn_name)
        except StopIteration:
            if impl_fn_name.endswith("_update") and impl_fn["type"] == "command":
                try:
                    doc_fn = next(f for f in doc_mod.functions if f.name == impl_fn_name.removesuffix("_update") and f.type_ == FuncType.CONFIGURATION)
                except:
                    undocumented_functions.add(f'{impl_fn["type"]} {impl_fn["path"]}')
                    continue
            elif impl_fn_name.endswith("_modified") and impl_fn["type"] == "state":
                try:
                    doc_fn = next(f for f in doc_mod.functions if f.name == impl_fn_name.removesuffix("_modified") and f.type_ == FuncType.CONFIGURATION)
                    # _modified is documented once, not per config
                    continue
                except:
                    undocumented_functions.add(f'{impl_fn["type"]} {impl_fn["path"]}')
                    continue
            elif impl_fn_name.endswith("_reset") and impl_fn["type"] == "command":
                try:
                    doc_fn = next(f for f in doc_mod.functions if f.name == impl_fn_name.removesuffix("_reset") and f.type_ == FuncType.CONFIGURATION)
                    # _reset is documented once, not per config
                    continue
                except:
                    undocumented_functions.add(f'{impl_fn["type"]} {impl_fn["path"]}')
                    continue
            else:
                undocumented_functions.add(f'{impl_fn["type"]} {impl_fn["path"]}')
                continue

        documented_functions.pop(doc_fn.api_name(doc_mod.name), None)

        if impl_version not in doc_mod.version:
            print(red(f'{impl_fn["path"]} part of module {doc_mod.name} that is documented as not supporting {impl_version.name.lower()} but implementation supports it'))

        if impl_version not in doc_fn.root.version:
            print(red(f'{impl_fn["path"]} documented as not supporting {impl_version.name.lower()} but implementation supports it'))

        impl_type = {
            "state": FuncType.STATE,
            "command": FuncType.COMMAND,
            "response": FuncType.HTTP_ONLY,
            "raw_command": FuncType.COMMAND,
            "http_only": FuncType.HTTP_ONLY
        }[impl_fn["type"]]

        if impl_type != doc_fn.type_:
            if impl_type == FuncType.STATE and doc_fn.type_ == FuncType.CONFIGURATION:
                pass # TODO: Look for _update command
            elif impl_type == FuncType.COMMAND and doc_fn.type_ == FuncType.CONFIGURATION:
                pass # TODO: Check suffix
            else:
                print(red(f'{impl_fn["path"]}: Type mismatch. Implementation {impl_type.name}({impl_fn["type"]}) Documentation {doc_fn.type_.name}'))

        if impl_fn["type"] == "raw_command" or impl_type == FuncType.HTTP_ONLY:
            continue

        if impl_type == FuncType.COMMAND and doc_fn.command_is_action != impl_fn["is_action"]:
            print(red(f'{impl_fn["path"]}: Implementation is {"" if impl_fn["is_action"] else "not "}marked as action, but {"" if doc_fn.command_is_action else "not "}documented as action!'))

        check_element(doc_fn.root, impl_fn["content"], "[ROOT]", impl_fn["path"], impl_fn["keys_to_censor"], impl_version, api_info)

    if len(undocumented_modules) > 0:
        print(red("Undocumented modules\n"), "\t" + "\n\t".join(sorted(undocumented_modules.difference(UNDOCUMENTED_MODULES))))

    if len(undocumented_functions) > 0:
        print(red("Undocumented functions\n"), "\t" + "\n\t".join(sorted(undocumented_functions.difference(UNDOCUMENTED_FUNCTIONS))))

    if len(documented_functions) > 0:
        print(red("Documented, but unimplemented functions\n"), "\t" + "\n\t".join(sorted(documented_functions.keys())))

if __name__ == "__main__":
    main()
