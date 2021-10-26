import json
import os
import re
import sys

START_PATTERN = "{[index: string]:any} = "
END_PATTERN = "};"

def merge(left, right, path=[]):
    for key in right:
        if key in left:
            if isinstance(left[key], dict) and isinstance(right[key], dict):
                merge(left[key], right[key], path + [str(key)])
            else:
                print("Found ambiguous placeholder ", '.'.join(path + [key]))
        else:
            left[key] = right[key]
    return left

def flatten(list_of_lists):
    return sum(list_of_lists, [])

def get_and_delete(d, keys):
    last_d = None
    for k in keys:
        last_d = d
        d = d[k]
    del last_d[k]
    return d

def get_nested_keys(d, path=""):
    r = []
    for k, v in d.items():
        if isinstance(v, dict) and len(v) > 0:
            r += get_nested_keys(v, path + "." + k if path != "" else k)
        elif isinstance(v, str):
            r.append(path + "." + k)
    return r


def main():
    translations = {}
    used_placeholders = []

    for root, dirs, files in os.walk("./src"):
        for name in files:
            if not name.endswith(".ts"):
                continue
            with open(os.path.join(root, name)) as f:
                content = f.read()

            placeholders = re.findall('__\(([^\)]*)', content)
            try:
                placeholders.remove("s: string")
            except:
                pass
            incorrect_placeholders = [x for x in placeholders if not x[0] == '"' or not x[-1] == '"']
            if len(incorrect_placeholders) != 0:
                print("Found incorrect placeholders", incorrect_placeholders)

            used_placeholders += [x[1:-1] for x in placeholders]

            start = content.find(START_PATTERN)
            while start >= 0:
                content = content[start+len(START_PATTERN):]
                end = content.find(END_PATTERN)
                json_dict = content[:end+1]
                json_dict = re.sub(",\s*\}", "}", json_dict)
                json_dict = json_dict.replace("util.emptyText()", '""')
                try:
                    merge(translations, json.loads(json_dict))
                except Exception as e:
                    print("error:", e, json_dict)

                content = content[end+len(END_PATTERN):]
                start = content.find(START_PATTERN)

    with open("./src/index.html") as f:
        content = f.read()

    used_placeholders += flatten([x.split(" ") for x in re.findall('data-i18n="([^"]*)"', content)])

    used_placeholders = set(used_placeholders)


    used_but_missing = []

    for p in used_placeholders:
        keys = p.split(".")
        for l, v in translations.items():
            try:
                get_and_delete(v, keys)
            except KeyError:
                used_but_missing.append(l + '.' + p)

    if len(used_but_missing):
        print("Missing placeholders:")
        for x in used_but_missing:
            print("\t" + x)

    unused = get_nested_keys(translations)
    if len(unused) > 0:
        print("Unused placeholders:")
        for x in unused:
            print("\t" + x)

if __name__ == "__main__":
    main()
