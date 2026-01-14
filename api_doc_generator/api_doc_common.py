from dataclasses import dataclass
from enum import Enum, IntEnum, IntFlag, auto
from typing import Union, Optional, Callable
import itertools
import traceback
from pathlib import Path

import re

import os

# Translatable string helper class
class T:
    def __init__(self, translations: Union[str, dict]):
        if isinstance(translations, str):
            # Print plain strings during generation to see where T() is still missing
            # (for some stuff plain strings might be OK)
            if len(translations) > 0:
                f = ''
                for frame in reversed(traceback.extract_stack()):
                    p = Path(frame.filename)
                    if p.parent.name == 'api_doc_generator' and p.name not in ['api_doc_common.py', 'generator.py']:
                        f = f'{frame.filename}:{frame.lineno} '
                        break
                print(f"{f}Plain string passed to T(): '{translations[:50]}'")
            self.translations = {'de': translations, 'en': translations}
        elif isinstance(translations, dict):
            self.translations = translations
        else:
            raise TypeError(f"T() expects str or dict, got {type(translations)}")

    def get(self, locale: str) -> str:
        if locale in self.translations:
            return self.translations[locale]
        elif 'de' in self.translations:
            return self.translations['de']
        else:
            return list(self.translations.values())[0]

    def __repr__(self):
        return f"T({self.translations})"

def _ensure_T(value):
    if isinstance(value, T):
        return value
    elif isinstance(value, str):
        return T(value)
    else:
        raise TypeError(f"Expected T or str, got {type(value)}")

def get_example_from_file(api: str, prefix_version: str, locale: str = 'de'):
    if prefix_version == "warp":
        prefix_version = "warp1"

    try:
        path = f'./examples/{api}_{locale}.jsonc'

        _dir, file = api.rsplit("/", 1)
        versioned_dir = f'./examples/{_dir}'
        for x in os.listdir(versioned_dir):
            if x.split('.', 1)[0] == file and f'.{prefix_version}_{locale}.jsonc' in x:
                path = os.path.join(versioned_dir, x)
                break

        with open(path, 'r') as f:
            result = f.read().strip().split("/*§§§", 1)
            if len(result) == 1:
                result.append("")
            result = [x.strip() for x in result]
            result[1] = result[1].removesuffix("*/").strip()
            return result
    except Exception as e:
        return None, None

def wrap_non_empty(prefix, middle, suffix):
    if len(middle) == 0:
        return ''

    return prefix + middle + suffix

def parse_api_name(api_name):
    if '/' not in api_name:
        mod = "misc"
        fn = api_name
    else:
        mod, fn = api_name.split("/", 1)

    fn = re.sub(r"^\d+/", "X/", fn, count=1)
    return mod, fn

@dataclass
class Unit:
    name: 'T'
    abbr: str

    def to_html(self, locale: str = 'de'):
        return '(<abbr title="{}">{}</abbr>)'.format(self.name.get(locale), self.abbr)

class Units:
    A = Unit(T({'de': "Ampere", 'en': "Ampere"}), "A")
    Ah = Unit(T({'de': "Amperestunde", 'en': "Ampere-hour"}), "Ah")
    ct_per_month = Unit(T({'de': "Cent pro Monat", 'en': "Cent per month"}), "ct/M")
    degree = Unit(T({'de': "Grad", 'en': "Degree"}), "°")
    h = Unit(T({'de': "Stunde", 'en': "Hour"}), "h")
    hundredth_cent_per_kWh = Unit(T({'de': "Hundertstel Cent pro Kilowattstunde", 'en': "Hundredth cent per kilowatt-hour"}), "ct/kWh/100")
    hundredth_percent = Unit(T({'de': "Hundertstel Prozent", 'en': "Hundredth percent"}), "%/100")
    hundredth_degree_celsius = Unit(T({'de': "Hundertstel Grad Celsius", 'en': "Hundredth degree Celsius"}), "°/100")
    Hz = Unit(T({'de': "Hertz", 'en': "Hertz"}), "Hz")
    kVAh = Unit(T({'de': "Kilovoltamperestunde", 'en': "Kilovolt-ampere-hour"}), "kVAh")
    kvarh = Unit(T({'de': "Kilovoltampere Reaktiv Stunde", 'en': "Kilovolt-ampere reactive hour"}), "kvarh")
    kWh = Unit(T({'de': "Kilowattstunde", 'en': "Kilowatt-hour"}), "kWh")
    min_ = Unit(T({'de': "Minute", 'en': "Minute"}), "min")
    mA = Unit(T({'de': "Milliampere", 'en': "Milliampere"}), "mA")
    ms = Unit(T({'de': "Millisekunde", 'en': "Millisecond"}), "ms")
    mV = Unit(T({'de': "Millivolt", 'en': "Millivolt"}), "mV")
    Mbps = Unit(T({'de': "Megabit pro Sekunde", 'en': "Megabit per second"}), "Mbit/s")
    ohm = Unit(T({'de': "Ohm", 'en': "Ohm"}), "Ω")
    percent = Unit(T({'de': "Prozent", 'en': "Percent"}), "%")
    s = Unit(T({'de': "Sekunde", 'en': "Second"}), "s")
    thousands_cent_per_kWh = Unit(T({'de': "Tausendstel Cent pro Kilowattstunde", 'en': "Thousandth cent per kilowatt-hour"}), "ct/kWh/1000")
    tenthousands_degree = Unit(T({'de': "Zehntausendstel Grad", 'en': "Ten-thousandth degree"}), "°/10000")
    tenth_percent = Unit(T({'de': "Zehntel Prozent", 'en': "Tenth percent"}), "%/10")
    V = Unit(T({'de': "Volt", 'en': "Volt"}), "V")
    VA = Unit(T({'de': "Voltampere", 'en': "Volt-ampere"}), "VA")
    var = Unit(T({'de': "Voltampere Reaktiv", 'en': "Volt-ampere reactive"}), "var")
    Wp = Unit(T({'de': "Watt Peak", 'en': "Watt peak"}), "Wp")
    W = Unit(T({'de': "Watt", 'en': "Watt"}), "W")
    Wh = Unit(T({'de': "Wattstunde", 'en': "Watt-hour"}), "Wh")

class FuncType(IntEnum):
    STATE = 0
    COMMAND = 1
    CONFIGURATION = 2
    HTTP_ONLY = 3

    # def name_singular(self):
    #     return {
    #         FuncType.STATE: "Zustand",
    #         FuncType.COMMAND: "Kommando",
    #         FuncType.CONFIGURATION: "Konfiguration",
    #         FuncType.HTTP_ONLY: "HTTP-Spezifisch"
    #     }[self]

    # def name_plural(self):
    #     return {
    #         FuncType.STATE: "Zustände",
    #         FuncType.COMMAND: "Kommandos",
    #         FuncType.CONFIGURATION: "Konfigurationen",
    #         FuncType.HTTP_ONLY: "HTTP-Spezifisch"
    #     }[self]

@dataclass
class Func:
    name: str
    type_: FuncType
    root: 'Elem'
    command_is_action: bool = False

    def api_name(self, module):
        return module + "/" + self.name if module is not None else self.name

class EType(IntEnum):
    OBJECT = 0
    ARRAY = 1
    STRING = 2
    INT = 3
    FLOAT = 4
    BOOL = 5
    NULL = 6
    OPAQUE = 7
    UNION = 8
    HIDDEN_UNION = 9 # something that behaves as if it was a union, but the tag is not a part of this element.

class Version(IntFlag):
    # -1 in two's complement has all bits set, so ALL matches any version
    # Also -1 is sorted before the specific versions, which is required for
    # the layout of generated constant lists.
    ANY = -1
    WARP1 = 1
    WARP2 = 2
    WARP3 = 4
    WARPX = WARP1 | WARP2 | WARP3
    WEM = 8
    WEM2 = 16
    WEMX = WEM | WEM2

    def __init__(self, *args, **kwargs):
        self.desc = None

    def css_classes(self):
        if self == Version.ANY:
            return Version.ANY.name.lower()
        return " ".join([x.name for x in Version if x in self]).lower()

    def label(self, row=False, locale: str = 'de'):
        if self == Version.ANY:
            return ""

        translations = {
            'de': {
                'prefix_normal': "<strong>",
                'prefix_row': "<strong>(Nur ",
                'suffix_normal': ":</strong><br/>",
                'suffix_row': ")</strong> ",
                'and': " und "
            },
            'en': {
                'prefix_normal': "<strong>",
                'prefix_row': "<strong>(Only ",
                'suffix_normal': ":</strong><br/>",
                'suffix_row': ")</strong> ",
                'and': " and "
            }
        }

        t = translations.get(locale, translations['de'])
        prefix = t['prefix_normal'] if not row else t['prefix_row']
        suffix = t['suffix_normal'] if not row else t['suffix_row']

        return prefix + t['and'].join([{
            Version.WARP1: "WARP 1",
            Version.WARP2: "WARP 2",
            Version.WARP3: "WARP 3",
            Version.WEM: "Energy Manager",
            Version.WEM2: "Energy Manager 2.0",
        }[x] for x in Version if x in self]) + suffix

    def with_desc(self, desc):
        self.desc = desc
        return self

@dataclass
class Const:
    val: str
    desc: 'T'
    version: Version = Version.ANY

    def __post_init__(self):
        # Ensure desc field is wrapped in T()
        self.desc = _ensure_T(self.desc)

@dataclass
class Elem:
    type_: EType
    desc: 'T'
    unit: Optional[Unit]
    val: Optional[Union[list['Elem'], dict[str, 'Elem'], dict[int, 'Elem']]]
    constants: Optional[list[Const]]
    is_var_length_array: bool
    var_length_array_type: Optional[EType]
    var_length_array_unit: Optional[Unit]
    censored: bool
    version: Version
    type_name_override: Optional[str]
    union_tab_id: Optional[str]
    hidden_union_get_tag: Optional[Callable[[str, dict], int]]

    @staticmethod
    def OBJECT(desc: 'T', *, members: dict[str, 'Elem'], censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.OBJECT, _ensure_T(desc), None, members, None, False, None, None, censored, version, None, None, None)

    @staticmethod
    def ARRAY(desc: 'T', *, unit: Optional[Unit] = None, members: Optional[list['Elem']] = None, member_type: Optional[EType] = None, member_unit: Optional[Unit] = None, censored: bool = False, version: Version = Version.ANY, is_var_length_array: bool = False):
        if members is None and member_type is None:
            raise Exception("Array without members and member_type is not supported!")
        if members is not None and member_type is not None and any(x.type_ != member_type for x in members):
            raise Exception("Type mismatch between members and member_type!")
        return Elem(EType.ARRAY, _ensure_T(desc), unit, members, None, is_var_length_array or (members is None), member_type if member_type is not None else members[0].type_, member_unit, censored, version, None, None, None)

    @staticmethod
    def STRING(desc: 'T', *, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.STRING, _ensure_T(desc), None, None, constants, False, None, None, censored, version, None, None, None)

    @staticmethod
    def INT(desc: 'T', *, type_name_override: Optional[str] = None, unit: Optional[Unit] = None, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.INT, _ensure_T(desc), unit, None, constants, False, None, None, censored, version, type_name_override, None, None)

    @staticmethod
    def FLOAT(desc: 'T', *, unit: Optional[Unit] = None, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.FLOAT, _ensure_T(desc), unit, None, constants, False, None, None, censored, version, None, None, None)

    @staticmethod
    def BOOL(desc: 'T', *, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.BOOL, _ensure_T(desc), None, None, constants, False, None, None, censored, version, None, None, None)

    @staticmethod
    def NULL(desc: 'T', *, version: Version = Version.ANY):
        return Elem(EType.NULL, _ensure_T(desc), None, None, None, False, None, None, False, version, None, None, None)

    @staticmethod
    def OPAQUE(desc: 'T'):
        return Elem(EType.OPAQUE, _ensure_T(desc), None, None, None, False, None, None, False, Version.ANY, None, None, None)

    @staticmethod
    def UNION(desc: 'T', *, members: dict[int, 'Elem'], censored: bool = False, version: Version = Version.ANY, tab_id = None):
        return Elem(EType.UNION, _ensure_T(desc), None, members, None, False, None, None, censored, version, None, tab_id, None)

    @staticmethod
    def HIDDEN_UNION(desc: 'T', *, members: dict[int, 'Elem'], get_tag_fn: Optional[Callable[[str, dict], int]], censored: bool = False, version: Version = Version.ANY, tab_id = None):
        return Elem(EType.HIDDEN_UNION, _ensure_T(desc), None, members, None, False, None, None, censored, version, None, tab_id, get_tag_fn)

    def get_type(self, version=Version.ANY) -> str:
        if self.type_ in (EType.OBJECT,
                          EType.STRING,
                          EType.INT,
                          EType.FLOAT,
                          EType.BOOL,
                          EType.NULL):
            return self.type_.name.lower()

        if self.type_ == EType.UNION:
            return "[Union](/interfaces/mqtt_http/introduction.md#unions)"

        if self.type_ == EType.HIDDEN_UNION:
            raise Exception("not supported")

        if self.type_ == EType.ARRAY:
            if self.is_var_length_array:
                return self.var_length_array_type.name.lower() + "[..]"

            if len(set([x.version for x in self.val if version in x.version or version == Version.ANY])) > 1:
                return [x for x in self.val if version in x.version or version == Version.ANY][0].get_type() + "[..]"

            return [x for x in self.val if version in x.version or version == Version.ANY][0].get_type() + "[{}]".format(len([x for x in self.val if version in x.version or version == Version.ANY]))

    def get_unit(self, locale: str = 'de') -> str:
        if self.type_ in (EType.OBJECT,
                          EType.STRING,
                          EType.INT,
                          EType.FLOAT,
                          EType.BOOL,
                          EType.OPAQUE,
                          EType.UNION,
                          EType.NULL):
            return self.unit.to_html(locale) if self.unit is not None else ''

        if self.type_ == EType.HIDDEN_UNION:
            raise Exception("not supported")

        if self.type_ == EType.ARRAY:
            if self.is_var_length_array:
                return self.var_length_array_unit.to_html(locale) if self.var_length_array_unit is not None else ''

            if all(x.get_unit(locale) == '' for x in self.val):
                return self.unit.to_html(locale) if self.unit is not None else ''

            if len(set([x.get_unit(locale) for x in self.val])) == len(self.val):
                return self.val[0].get_unit(locale)

            print("Warning: Array with more than one unit found! Those units will not be documented")
            return ''

    def to_table_row(self, key_name: str, version: Version, locale: str = 'de') -> str:
        row_template = """
<tr>
    <th scope="row" style={{{{whiteSpace: "nowrap"}}}}>{name}</th>
    <td>
        {version_prefix}{desc}
    </td>
</tr>"""

        constants_template = """
{version_label}{entries}"""
        constant_entry_template = """- **{val}** - {desc}"""

        name = '`{name}`<br/>{type}{unit}'.format(
                    name=key_name,
                    type=self.get_type(version=version),
                    unit=wrap_non_empty(' ', self.get_unit(locale), ''))

        desc = self.desc.get(locale)

        if self.constants is not None:
            for ver, constants in itertools.groupby(sorted(self.constants, key=lambda c: c.version), key=lambda c: c.version):
                if version != Version.ANY and version not in ver:
                    continue

                consts = []
                for c in constants:
                    val = c.val
                    if self.type_ == EType.BOOL:
                        val = str(val).lower()
                    consts.append(constant_entry_template.format(val=val, desc=c.desc.get(locale)))

                if len(consts) == 0:
                    continue

                desc += constants_template.format(version_label=("\n" + ver.label(row=True, locale=locale) + "\n\n") if version == Version.ANY else "",
                                                  entries='\n'.join(consts))

        if self.type_ == EType.ARRAY and self.val is not None:
            # Python has no break with labels. Use function with return to "break" out of the outer loop
            def get_desc(desc):
                result = desc
                for ver, members in itertools.groupby(sorted(self.val, key=lambda c: c.version), key=lambda c: c.version):
                    if version != Version.ANY and version not in ver:
                        continue


                    members = list(members)
                    mems = []
                    idx = 0
                    for m, elements in itertools.groupby(members):
                        count = len(list(elements))
                        d = m.desc.get(locale)
                        # If the whole array is composed of identical entries without description, skip the whole list. This is used for example in IPs.
                        if d == "":
                            if count == len(members):
                                return result

                        if m.type_ == EType.OBJECT:
                            d += m.to_table(False, version, locale)
                        mems.append(constant_entry_template.format(val="[{}]".format(idx) if count == 1 else "[{}..{}]".format(idx, idx + count - 1), desc=d))
                        idx += count

                    if len(mems) == 0:
                        continue

                    result += constants_template.format(version_label=("\n" + ver.label(row=True, locale=locale) + "\n\n") if version == Version.ANY else "",
                                                        entries='\n'.join(mems))
                return result
            desc = get_desc(desc)

        if self.type_ == EType.OBJECT:
            desc += self.to_table(is_root=False, version=version, locale=locale)
        elif self.type_ == EType.UNION or self.type_ == EType.HIDDEN_UNION:
            desc += "\n" + self.to_tabs(is_root=False, version=version, locale=locale)

        return row_template.format(version_class=self.version.css_classes(),
                                   name=name,
                                   version_prefix=self.version.label(row=True, locale=locale),
                                   desc=desc.replace("\n", "\n        "))

    def to_tabs(self, is_root: bool, version: Version, locale: str = 'de'):
        groupId = ""
        if self.union_tab_id is not None:
            groupId = f' groupId="{self.union_tab_id}"'

        if self.type_ == EType.UNION:
            result = f'<MultilineTabs className="unique-tabs"{groupId}>\n'
        elif self.type_ == EType.HIDDEN_UNION:
            result = f'<Tabs className="hidden-tabs"{groupId}>\n'

        if self.version != Version.ANY and all(v.version == self.version for k, v in self.val.items()):
            print(f"Union element '{self.desc.get(locale)}' and all its children specify the same version {self.version.name}. Remove version from children!")

        members = []
        for k, v in self.val.items():
            if not(version in v.version or version == Version.ANY):
                continue

            members.append(f"""<TabItem value="{k}" label="{k} - {v.desc.get(locale)}">
{v.to_table(False, version, locale)}
</TabItem>
""")

        if len(members) == 0:
            print(f"Union element '{v.desc.get(locale)}' is empty in version {version.name} but is marked as supported in this version!")

        result += "\n".join(members)

        if self.type_ == EType.UNION:
            result += f'</MultilineTabs>\n'
        elif self.type_ == EType.HIDDEN_UNION:
            result += f'</Tabs>\n'

        return result

    def get_examples(self, f: Func, module: str, version: Version, locale: str = 'de') -> str:
        translations = {
            'de': {
                'example': 'Beispiel',
                'read': 'Lesen',
                'write': 'Schreiben',
                'or_abbreviated': 'oder abgekürzt:',
                'with_mqtt_on': 'Mit MQTT auf',
                'http_only': 'Wird nur von der HTTP-API unterstützt',
                'eg': 'z.B.'
            },
            'en': {
                'example': 'Example',
                'read': 'Read',
                'write': 'Write',
                'or_abbreviated': 'or abbreviated:',
                'with_mqtt_on': 'With MQTT on',
                'http_only': 'Only supported by the HTTP API',
                'eg': 'e.g.'
            }
        }
        t = translations.get(locale, translations['de'])

        prefix_version = version
        if version == Version.ANY:
            if self.version == Version.ANY:
                prefix_version = Version.WARP1
            else:
                prefix_version = next(x for x in self.version)
        if prefix_version == Version.WARP1:
            prefix_version = "warp"
        else:
            prefix_version = prefix_version.name.lower()

        add_shortcut = f.type_ != FuncType.STATE and self.type_ == EType.OBJECT and len(self.val.items()) == 1 and not "do_i_know_what_i_am_doing" in self.val

        def api_name(f: Func, module: str):
            return f.api_name(module).replace("meters/X/", "meters/1/")

        example_state_template = f""":::info[{t['example']}]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST {t['eg']} {prefix_version}-AbCd
```
#### {t['read']}
```bash
curl http://$HOST/{api_name(f, module)}
```
        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
```bash
# $BROKER {t['eg']} my_mosquitto.localdomain
# $PREFIX {t['eg']} {prefix_version}/AbCd
```
#### {t['read']}
```bash
mosquitto_sub -v -C 1 -h $BROKER -t $PREFIX/{api_name(f, module)}
```
        </TabItem>
    </Tabs>

{{payload}}
{{comment}}

:::
"""

        shortcut_template = f"""
{t['or_abbreviated']}
{{}}
"""

        write_http_template = f"""
```bash
curl http://$HOST/{api_name(f, module)} -d '{{payload}}'
```
"""
        write_mqtt_template = f"""
```bash
mosquitto_pub -h $BROKER -t $PREFIX/{api_name(f, module)}{{update}} -m '{{payload}}'
```
"""

        example_command_template = f""":::info[{t['example']}]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST {t['eg']} {prefix_version}-AbCd
```
#### {t['write']}{{http}}{{http_shortcut}}
{{comment}}

        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
```bash
# $BROKER {t['eg']} my_mosquitto.localdomain
# $PREFIX {t['eg']} {prefix_version}/AbCd
```
#### {t['write']}{{mqtt}}{{mqtt_shortcut}}
{{comment}}

        </TabItem>
    </Tabs>
:::
"""

        example_config_template = f""":::info[{t['example']}]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST {t['eg']} {prefix_version}-AbCd
```

#### {t['read']}
```bash
curl http://$HOST/{api_name(f, module)}
```
{{read_payload}}
{{read_comment}}


#### {t['write']}{{http}}{{http_shortcut}}
{{write_comment}}

        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
```bash
# $BROKER {t['eg']} my_mosquitto.localdomain
# $PREFIX {t['eg']} {prefix_version}/AbCd
```

#### {t['read']}
```bash
mosquitto_sub -v -C 1 -h $BROKER -t $PREFIX/{api_name(f, module)}
```
{{read_payload}}
{{read_comment}}


#### {t['write']}
            {t['with_mqtt_on']} <code>$PREFIX/{api_name(f, module)}<strong>_update</strong></code>

{{mqtt}}{{mqtt_shortcut}}
{{write_comment}}

        </TabItem>
    </Tabs>
:::
"""

        example_http_only_template = f""":::info[{t['example']}]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST {t['eg']} {prefix_version}-AbCd
```
```bash
curl http://$HOST/{api_name(f, module)}
```
{{payload}}
{{comment}}


        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
            **{t['http_only']}**
        </TabItem>
    </Tabs>
:::
"""

        def get_shortcut_payload(payload):
            return re.sub(r'^\s*\{\s*"[^"]*":\s*', "", payload[:-1], 1).strip()

        if f.type_ == FuncType.STATE:
            payload, comment = get_example_from_file(f.api_name(module), prefix_version, locale)
            if payload is not None:
                return example_state_template.format(payload=wrap_non_empty("```jsx\n", payload, "\n```"), comment=comment)
            return ""
        elif f.type_ == FuncType.COMMAND:
            payload, comment = get_example_from_file(f.api_name(module), prefix_version, locale)
            if payload is None and f.root.type_ == EType.NULL:
                payload = "null"
                comment = ""
            if payload is not None:
                http_shortcut = shortcut_template.format(write_http_template.format(payload=get_shortcut_payload(payload))) if add_shortcut else ""
                mqtt_shortcut = shortcut_template.format(write_mqtt_template.format(payload=get_shortcut_payload(payload),update="")) if add_shortcut else ""
                http = write_http_template.format(payload=payload)
                mqtt = write_mqtt_template.format(payload=payload,update="")

                return example_command_template.format(
                    http_shortcut=http_shortcut,
                    mqtt_shortcut=mqtt_shortcut,
                    http=http,
                    mqtt=mqtt,
                    comment=comment)
            return ""
        elif f.type_ == FuncType.CONFIGURATION:
            read_payload, read_comment = get_example_from_file(f.api_name(module), prefix_version, locale)
            write_payload, write_comment = get_example_from_file(f.api_name(module) + "_update", prefix_version, locale)
            if read_payload is not None:
                if write_payload is None:
                    write_payload = read_payload
                    write_comment = read_comment

                http_shortcut = shortcut_template.format(write_http_template.format(payload=get_shortcut_payload(write_payload))) if add_shortcut else ""
                mqtt_shortcut = shortcut_template.format(write_mqtt_template.format(payload=get_shortcut_payload(write_payload),update="_update")) if add_shortcut else ""
                http = write_http_template.format(payload=write_payload)
                mqtt = write_mqtt_template.format(payload=write_payload,update="_update")

                return example_config_template.format(read_payload=wrap_non_empty("```jsx\n",read_payload, "\n```"),
                                                      http_shortcut=http_shortcut,
                                                      mqtt_shortcut=mqtt_shortcut,
                                                      http=http,
                                                      mqtt=mqtt,
                                                      read_comment=read_comment,
                                                      write_comment=write_comment)
            return ""
        elif f.type_ == FuncType.HTTP_ONLY:
            payload, comment = get_example_from_file(f.api_name(module), prefix_version, locale)
            if payload is not None:
                return example_http_only_template.format(payload=wrap_non_empty("```jsx\n",payload, "\n```"), comment=comment)
            return ""
        else:
            print(f"Function type {f.type_} not supported for examples yet!")
            return ""

    def root_to_md(self, f: Func, module: str, version: Version, locale: str = 'de') -> str:
        if not(version in self.version or version == Version.ANY):
            return ""

        translations = {
            'de': {
                'empty_payload': '**Leerer Payload. Es muss einer der folgenden Werte übergeben werden: `null`, `""`, `false`, `0`, `[]` oder `{}`**\n',
                'triggers_action': 'Löst eine einmalige Aktion aus. Nachrichten, die über den Broker retained wurden, werden ignoriert.',
                'http_only': 'Wird nur von der HTTP-API unterstützt'
            },
            'en': {
                'empty_payload': '**Empty payload. One of the following values must be passed: `null`, `""`, `false`, `0`, `[]` or `{}`**\n',
                'triggers_action': 'Triggers a one-time action. Messages retained via the broker are ignored.',
                'http_only': 'Only supported by the HTTP API'
            }
        }
        t = translations.get(locale, translations['de'])

        version_desc = ""
        if version == Version.ANY:
            version_desc = self.version.desc if hasattr(self.version, "desc") and self.version.desc is not None else self.version.label(row=True, locale=locale)

        content = f'## `{f.api_name(module)}` {{#{(f.api_name(module)).replace("/", "_") + "_" + version.name.lower()}}}\n'

        if f.type_ == FuncType.HTTP_ONLY:
            content += """<Tabs groupId="apiType" queryString className="hidden-tabs">
    <TabItem value="http" label="HTTP (curl)">
"""
        content += f"""
{version_desc}
{self.desc.get(locale)}
"""

        if self.type_ == EType.NULL:
            content += t['empty_payload']
            if f.type_ != FuncType.COMMAND:
                print("Function {} has a null payload but is not a command?!?".format(f.name))

        if f.command_is_action:
            content += f'<Tabs groupId="apiType" queryString className="hidden-tabs"><TabItem value="http"></TabItem><TabItem value="mqtt"><Admonition type="warning" title="{t["triggers_action"]}"></Admonition></TabItem></Tabs>\n'

        examples = self.get_examples(f, module, version, locale)
        # Only log this once per API
        if examples == "" and version == Version.ANY:
            print(f"No examples for {f.api_name(module)}")
        content += examples

        if self.type_ == EType.NULL:
            table = ""
        elif self.type_ == EType.ARRAY and self.is_var_length_array:
            table = self.to_table(is_root=True, version=version, locale=locale)
        elif self.type_ == EType.UNION or self.type_ == EType.HIDDEN_UNION:
            table = self.to_tabs(is_root=True, version=version, locale=locale)
        else:
            table = self.to_table(is_root=True, version=version, locale=locale)

        content += "\n" + table + "\n"

        if f.type_ == FuncType.HTTP_ONLY:
            content += f"""    </TabItem>
    <TabItem value="mqtt" label="MQTT (mosquitto)">
        <Admonition type="warning" title="{t['http_only']}"></Admonition>
    </TabItem>
</Tabs>
"""

        return content

    def to_table(self, is_root: bool, version: Version, locale: str = 'de') -> str:
        translations = {
            'de': {'meaning': 'Bedeutung', 'name': 'Name', 'index': 'Index'},
            'en': {'meaning': 'Meaning', 'name': 'Name', 'index': 'Index'}
        }
        t = translations.get(locale, translations['de'])

        table_template = """
<table>
    <thead>
        <tr>
            <th scope="col">{name_or_index}</th>
            <th scope="col">""" + t['meaning'] + """</th>
        </tr>
    </thead>
    <tbody>
{rows}
    </tbody>
</table>"""

        if self.type_ == EType.UNION or self.type_ == EType.HIDDEN_UNION:
            raise Exception("Don't document union as table!")

        if self.type_ == EType.OBJECT:
            desc_str = self.desc.get(locale)
            if self.version != Version.ANY and all(v.version == self.version for k, v in self.val.items()):
                print(f"Object element '{desc_str}' and all its children specify the same version {self.version.name}. Remove version from children!")
            rows = [v.to_table_row(k, version, locale) for k, v in self.val.items() if version in v.version or version == Version.ANY]
            if len(rows) == 0:
                print(f"Object element '{desc_str}' is empty in version {version.name} but is marked as supported in this version!")
            return table_template.format(name_or_index=t['name'], rows='\n'.join(rows))

        if self.type_ == EType.ARRAY:
            idx = 0
            rows = []
            if self.is_var_length_array and self.val is None:
                return ""
            for group, elements in itertools.groupby(self.val):
                if version not in group.version and version != Version.ANY:
                    continue

                count = len(list(elements))
                if self.is_var_length_array:
                    length = "[..]"
                else:
                    length = "[{}]".format(idx) if count == 1 else "[{}..{}]".format(idx, idx + count - 1)
                rows.append(group.to_table_row(length, version, locale))
                idx += count

            return table_template.format(name_or_index=t['index'], rows='\n'.join(rows))

        if self.type_ == EType.OPAQUE:
            return ""

        # primitive
        result = '{type}{unit}: {desc}'.format(
                    type=self.get_type(version=version),
                    unit=wrap_non_empty(' ', self.get_unit(locale), ''),
                    desc=self.desc.get(locale))

        constants_template = """
{version_label}{entries}"""
        constant_entry_template = """- **{val}** - {desc}"""

        if self.constants is not None:
            for ver, constants in itertools.groupby(sorted(self.constants, key=lambda c: c.version), key=lambda c: c.version):
                if version != Version.ANY and version not in ver:
                    continue

                consts = []
                for c in constants:
                    val = c.val
                    if self.type_ == EType.BOOL:
                        val = str(val).lower()
                    const_desc = c.desc.get(locale)
                    consts.append(constant_entry_template.format(val=val, desc=const_desc))

                if len(consts) == 0:
                    continue

                result += constants_template.format(version_label=("\n" + ver.label(row=True, locale=locale) + "\n\n") if version == Version.ANY else "",
                                                  entries='\n'.join(consts))

        return result


@dataclass
class Module:
    name: str
    display_name: 'T'
    subheader: 'T'
    intro_section: 'T'
    version: Version
    functions: list[Func]
    hide_prefix: bool = False
    not_supported_text: 'T' = T({'de': 'Auf dieser Hardware nicht unterstützt!', 'en': 'Not supported on this hardware!'})

    def __post_init__(self):
        # Ensure all string fields are wrapped in T()
        # maybe a little bit hacky, but it works well
        self.display_name = _ensure_T(self.display_name)
        self.subheader = _ensure_T(self.subheader)
        self.intro_section = _ensure_T(self.intro_section)
        self.not_supported_text = _ensure_T(self.not_supported_text)

    def to_md(self, locale: str = 'de') -> str:
        display_name = self.display_name.get(locale)
        subheader = self.subheader.get(locale)
        intro = self.intro_section.get(locale)
        not_supported = self.not_supported_text.get(locale)

        result = f"""---
description: {display_name}
---
{{/* This file is autogenerated. Edit warp-charger/api_doc_generator/{self.name}.py! */}}
import MultilineTabs from '@site/src/components/MultilineTabs';
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import Admonition from '@theme/Admonition';

# {display_name}
"""

        result += f"**{subheader}**\n" if len(subheader) > 0 else ""
        result += intro + "\n"

        # Just create all versions in separate tabs for now.
        # This is inefficient because modules that are the same in every firmware
        # are generated 5 times.

        result += '<Tabs groupId="hardwareType" queryString className="hidden-tabs">\n'

        for ver in list(Version) + [Version.ANY]:
            result += f'<TabItem value="{ver.name.lower()}">\n'

            if ver not in self.version and ver != Version.ANY:
                result += f'{not_supported}\n</TabItem>\n'
                continue

            functions = []

            for group, fns in itertools.groupby(self.functions, key=lambda f: f.type_):
                fns = list(fns)

                for f in fns:
                    functions.append(f.root.root_to_md(f, self.name if not self.hide_prefix else None, ver, locale))

            result += "\n<br/><br/><br/>\n".join([x for x in functions if len(x) > 0])
            result += '</TabItem>\n'

        result += '</Tabs>\n'

        toc = []

        for group, fns in itertools.groupby(self.functions, key=lambda f: f.type_):
            fns = list(fns)

            for f in fns:
                if f.root.version != Version.ANY:
                    v = f.root.version
                else:
                    v = self.version

                toc.append(f"""{{
    "value": "{"{}/{}".format(self.name, f.name) if not self.hide_prefix else f.name}",
    "id": "{"{}_{}".format(self.name, f.name.replace("/", "_")) if not self.hide_prefix else f.name}",
    "level": 2,
    {"" if v == Version.ANY else ('"hardwareType": ["' + '","'.join(v.css_classes().split(" ")) + '"]')}
}},""")

        result += f"""
export const toc = [
    {"".join(toc)}
];
"""

        return result
