from dataclasses import dataclass
from enum import Enum, IntEnum, IntFlag, auto
from typing import Union, Optional, Callable
import itertools

import re

import os

def get_example_from_file(api: str, prefix_version: str):
    if prefix_version == "warp":
        prefix_version = "warp1"

    try:
        path = f'./examples/{api}.jsonc'

        _dir, file = api.rsplit("/", 1)
        versioned_dir = f'./examples/{_dir}'
        for x in os.listdir(versioned_dir):
            if x.startswith(file) and f'.{prefix_version}.' in x and x.endswith('.jsonc'):
                path = os.path.join(versioned_dir, x)
                break

        with open(path, 'r') as f:
            return f.read().strip()
    except Exception as e:
        print(f"Failed to load example for {api} ({prefix_version}): {e}")
        return None

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
    name: str
    abbr: str

    def to_html(self):
        return '(<abbr title="{}">{}</abbr>)'.format(self.name, self.abbr)

class Units:
    A = Unit("Ampere", "A")
    Ah = Unit("Amperestunde", "Ah")
    degree = Unit("Grad", "°")
    Hz = Unit("Hertz", "Hz")
    kVAh = Unit("Kilovoltamperestunde", "kVAh")
    kvarh = Unit("Kilovoltampere Reaktiv Stunde", "kvarh")
    kWh = Unit("Kilowattstunde", "kWh")
    min_ = Unit("Minute", "min")
    mA = Unit("Milliampere", "mA")
    ms = Unit("Millisekunde", "ms")
    mV = Unit("Millivolt", "mV")
    Mbps = Unit("Megabit pro Sekunde", "Mbit/s")
    ohm = Unit("Ohm", "Ω")
    percent = Unit("Prozent", "%")
    s = Unit("Sekunde", "s")
    tenth_percent = Unit("Zehntel Prozent", "%/10")
    V = Unit("Volt", "V")
    VA = Unit("Voltampere", "VA")
    var = Unit("Voltampere Reaktiv", "var")
    W = Unit("Watt", "W")
    Wh = Unit("Wattstunde", "Wh")
    hundredth_cent_per_kWh = Unit("Hundertstel Cent pro Kilowattstunde", "ct/kWh/100")
    hundreth_degree_celsius = Unit("Hundertstel Grad Celsius", "°/100")

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
    CHARGER = WARP1 | WARP2 | WARP3
    WEM = 8

    def __init__(self, *args, **kwargs):
        self.desc = None

    def css_classes(self):
        if self == Version.ANY:
            return Version.ANY.name.lower()
        return " ".join([x.name for x in Version if x in self]).lower()

    def label(self, row=False):
        if self == Version.ANY:
            return ""
        prefix = "<strong>" if not row else "<strong>(Nur "
        suffix = ":</strong><br/>" if not row else ")</strong> "
        return prefix + " und ".join([{
            Version.WARP1: "WARP 1",
            Version.WARP2: "WARP 2",
            Version.WARP3: "WARP 3",
            Version.WEM: "Energy Manager",
        }[x] for x in Version if x in self]) + suffix

    def with_desc(self, desc):
        self.desc = desc
        return self

@dataclass
class Const:
    val: str
    desc: str
    version: Version = Version.ANY

@dataclass
class Elem:
    type_: EType
    desc: str
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
    def OBJECT(desc: str, *, members: dict[str, 'Elem'], censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.OBJECT, desc, None, members, None, False, None, None, censored, version, None, None, None)

    @staticmethod
    def ARRAY(desc: str, *, unit: Optional[Unit] = None, members: Optional[list['Elem']] = None, member_type: Optional[EType] = None, member_unit: Optional[Unit] = None, censored: bool = False, version: Version = Version.ANY, is_var_length_array: bool = False):
        if members is None and member_type is None:
            raise Exception("Array without members and member_type is not supported!")
        if members is not None and member_type is not None and any(x.type_ != member_type for x in members):
            raise Exception("Type mismatch between members and member_type!")
        return Elem(EType.ARRAY, desc, unit, members, None, is_var_length_array or (members is None), member_type if member_type is not None else members[0].type_, member_unit, censored, version, None, None, None)

    @staticmethod
    def STRING(desc: str, *, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.STRING, desc, None, None, constants, False, None, None, censored, version, None, None, None)

    @staticmethod
    def INT(desc: str, *, type_name_override: Optional[str] = None, unit: Optional[Unit] = None, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.INT, desc, unit, None, constants, False, None, None, censored, version, type_name_override, None, None)

    @staticmethod
    def FLOAT(desc: str, *, unit: Optional[Unit] = None, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.FLOAT, desc, unit, None, constants, False, None, None, censored, version, None, None, None)

    @staticmethod
    def BOOL(desc: str, *, constants: Optional[list[Const]] = None, censored: bool = False, version: Version = Version.ANY):
        return Elem(EType.BOOL, desc, None, None, constants, False, None, None, censored, version, None, None, None)

    @staticmethod
    def NULL(desc: str, *, version: Version = Version.ANY):
        return Elem(EType.NULL, desc, None, None, None, False, None, None, False, version, None, None, None)

    @staticmethod
    def OPAQUE(desc: str):
        return Elem(EType.OPAQUE, desc, None, None, None, False, None, None, False, Version.ANY, None, None, None)

    @staticmethod
    def UNION(desc: str, *, members: dict[int, 'Elem'], censored: bool = False, version: Version = Version.ANY, tab_id = None):
        return Elem(EType.UNION, desc, None, members, None, False, None, None, censored, version, None, tab_id, None)

    @staticmethod
    def HIDDEN_UNION(desc: str, *, members: dict[int, 'Elem'], get_tag_fn: Optional[Callable[[str, dict], int]], censored: bool = False, version: Version = Version.ANY, tab_id = None):
        return Elem(EType.HIDDEN_UNION, desc, None, members, None, False, None, None, censored, version, None, tab_id, get_tag_fn)

    def get_type(self, version=Version.ANY) -> str:
        if self.type_ in (EType.OBJECT,
                          EType.STRING,
                          EType.INT,
                          EType.FLOAT,
                          EType.BOOL,
                          EType.UNION,
                          EType.NULL):
            return self.type_.name.lower()

        if self.type_ == EType.HIDDEN_UNION:
            raise Exception("not supported")

        if self.type_ == EType.ARRAY:
            if self.is_var_length_array:
                return self.var_length_array_type.name.lower() + "[..]"

            if len(set([x.version for x in self.val if version in x.version or version == Version.ANY])) > 1:
                return [x for x in self.val if version in x.version or version == Version.ANY][0].get_type() + "[..]"

            return [x for x in self.val if version in x.version or version == Version.ANY][0].get_type() + "[{}]".format(len([x for x in self.val if version in x.version or version == Version.ANY]))

    def get_unit(self) -> str:
        if self.type_ in (EType.OBJECT,
                          EType.STRING,
                          EType.INT,
                          EType.FLOAT,
                          EType.BOOL,
                          EType.OPAQUE,
                          EType.UNION,
                          EType.NULL):
            return self.unit.to_html() if self.unit is not None else ''

        if self.type_ == EType.HIDDEN_UNION:
            raise Exception("not supported")

        if self.type_ == EType.ARRAY:
            if self.is_var_length_array:
                return self.var_length_array_unit.to_html() if self.var_length_array_unit is not None else ''

            if all(x.get_unit() == '' for x in self.val):
                return self.unit.to_html() if self.unit is not None else ''

            if len(set([x.get_unit() for x in self.val])) == len(self.val):
                return self.val[0].get_unit()

            print("Warning: Array with more than one unit found! Those units will not be documented")
            return ''

    def to_table_row(self, key_name: str, version: Version) -> str:
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
                    unit=wrap_non_empty(' ', self.get_unit(), ''))

        desc = self.desc

        if self.constants is not None:
            for ver, constants in itertools.groupby(sorted(self.constants, key=lambda c: c.version), key=lambda c: c.version):
                if version != Version.ANY and version not in ver:
                    continue

                consts = []
                for c in constants:
                    val = c.val
                    if self.type_ == EType.BOOL:
                        val = str(val).lower()
                    consts.append(constant_entry_template.format(val=val, desc=c.desc))

                if len(consts) == 0:
                    continue

                desc += constants_template.format(version_label=("\n" + ver.label() + "\n\n") if version == Version.ANY else "",
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
                        d = m.desc
                        # If the whole array is composed of identical entries without description, skip the whole list. This is used for example in IPs.
                        if d == "":
                            if count == len(members):
                                return result

                        if m.type_ == EType.OBJECT:
                            d += m.to_table(False, version)
                        mems.append(constant_entry_template.format(val="[{}]".format(idx) if count == 1 else "[{}..{}]".format(idx, idx + count - 1), desc=d))
                        idx += count

                    if len(mems) == 0:
                        continue

                    result += constants_template.format(version_label=("\n" + ver.label() + "\n\n") if version == Version.ANY else "",
                                                        entries='\n'.join(mems))
                return result
            desc = get_desc(desc)

        if self.type_ == EType.OBJECT:
            desc += self.to_table(is_root=False, version=version)
        elif self.type_ == EType.UNION or self.type_ == EType.HIDDEN_UNION:
            desc += "\n" + self.to_tabs(is_root=False, version=version)

        return row_template.format(version_class=self.version.css_classes(),
                                   name=name,
                                   version_prefix=self.version.label(row=True),
                                   desc=desc.replace("\n", "\n        "))

    def to_tabs(self, is_root: bool, version: Version):
        groupId = ""
        if self.union_tab_id is not None:
            groupId = f' groupId="{self.union_tab_id}"'

        if self.type_ == EType.UNION:
            result = f'<MultilineTabs className="unique-tabs"{groupId}>\n'
        elif self.type_ == EType.HIDDEN_UNION:
            result = f'<Tabs className="hidden-tabs"{groupId}>\n'

        if self.version != Version.ANY and all(v.version == self.version for k, v in self.val.items()):
            print(f"Union element '{self.desc}' and all its children specify the same version {self.version.name}. Remove version from children!")

        members = []
        for k, v in self.val.items():
            if not(version in v.version or version == Version.ANY):
                continue

            members.append(f"""<TabItem value="{k}" label="{k} - {v.desc}">
{v.to_table(False, version)}
</TabItem>
""")

        if len(members) == 0:
            print(f"Union element '{self.desc}' is empty in version {version.name} but is marked as supported in this version!")

        result += "\n".join(members)

        if self.type_ == EType.UNION:
            result += f'</MultilineTabs>\n'
        elif self.type_ == EType.HIDDEN_UNION:
            result += f'</Tabs>\n'

        return result

    def get_examples(self, f: Func, module: str, version: Version) -> str:
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

        example_state_template = f""":::info[Beispiel]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST z.B. {prefix_version}-AbCd
```
            #### Lesen
```bash
curl http://$HOST/{f.api_name(module)}
```
        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
```bash
# $BROKER z.B. my_mosquitto.localdomain
# $PREFIX z.B. {prefix_version}/AbCd
```
            #### Lesen
```bash
mosquitto_sub -v -C 1 -h $BROKER -t $PREFIX/{f.api_name(module)}
```
        </TabItem>
    </Tabs>

```jsx
{{payload}}
```
:::
"""

        example_command_template = f""":::info[Beispiel]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST z.B. {prefix_version}-AbCd
```
            #### Schreiben
```bash
curl http://$HOST/{f.api_name(module)} -d '{{payload}}'
```
        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
```bash
# $BROKER z.B. my_mosquitto.localdomain
# $PREFIX z.B. {prefix_version}/AbCd
```
            #### Schreiben
```bash
mosquitto_pub -h $BROKER -t $PREFIX/{f.api_name(module)} -m '{{payload}}'
```
        </TabItem>
    </Tabs>
:::
"""

        example_config_template = f""":::info[Beispiel]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST z.B. {prefix_version}-AbCd
```

            #### Lesen
```bash
curl http://$HOST/{f.api_name(module)}
```
```jsx
{{read_payload}}
```

            #### Schreiben

```bash
curl http://$HOST/{f.api_name(module)} -d '{{write_payload}}'
```
        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
```bash
# $BROKER z.B. my_mosquitto.localdomain
# $PREFIX z.B. {prefix_version}/AbCd
```

            #### Lesen
```bash
mosquitto_sub -v -C 1 -h $BROKER -t $PREFIX/{f.api_name(module)}
```
```jsx
{{read_payload}}
```

            #### Schreiben
            Mit MQTT auf <code>$PREFIX/{f.api_name(module)}<strong>_update</strong></code>

```bash
mosquitto_pub -h $BROKER -t $PREFIX/{f.api_name(module)}_update -m '{{write_payload}}'
```
        </TabItem>
    </Tabs>
:::
"""

        example_http_only_template = f""":::info[Beispiel]
    <Tabs groupId="apiType" queryString className="hidden-tabs">
        <TabItem value="http" label="HTTP (curl)">
```bash
# $HOST z.B. {prefix_version}-AbCd
```
```bash
curl http://$HOST/{f.api_name(module)}
```
```jsx
{{payload}}
```

        </TabItem>
        <TabItem value="mqtt" label="MQTT (mosquitto)">
            **Wird nur von der HTTP-API unterstützt**
        </TabItem>
    </Tabs>
:::
"""

        if f.type_ == FuncType.STATE:
            payload = get_example_from_file(f.api_name(module), prefix_version)
            if payload is not None:
                return example_state_template.format(payload=payload)
            return ""
        elif f.type_ == FuncType.COMMAND:
            payload = get_example_from_file(f.api_name(module), prefix_version)
            if payload is not None:
                return example_command_template.format(payload=payload)
            if f.root.type_ == EType.NULL:
                return example_command_template.format(payload="null")

            return ""
        elif f.type_ == FuncType.CONFIGURATION:
            read_payload = get_example_from_file(f.api_name(module), prefix_version)
            write_payload = get_example_from_file(f.api_name(module) + "_update", prefix_version)
            if read_payload is not None and write_payload is not None:
                return example_config_template.format(read_payload=read_payload,
                                                      write_payload=write_payload)
            return ""
        elif f.type_ == FuncType.HTTP_ONLY:
            payload = get_example_from_file(f.api_name(module), prefix_version)
            if payload is not None:
                return example_http_only_template.format(payload=payload)
            return ""
        else:
            print(f"Function type {f.type_} not supported for examples yet!")
            return ""

    def root_to_md(self, f: Func, module: str, version: Version) -> str:
        if not(version in self.version or version == Version.ANY):
            return ""

        version_desc = ""
        if version == Version.ANY:
            version_desc = self.version.desc if hasattr(self.version, "desc") and self.version.desc is not None else self.version.label(row=True)

        content = f'## `{f.api_name(module)}` {{#{(f.api_name(module)).replace("/", "_") + "_" + version.name.lower()}}}\n'

        if f.type_ == FuncType.HTTP_ONLY:
            content += """<Tabs groupId="apiType" queryString className="hidden-tabs">
    <TabItem value="http" label="HTTP (curl)">
"""
        content += f"""
{version_desc}
{self.desc}
"""

        if self.type_ == EType.NULL:
            content += '**Leerer Payload. Es muss einer der folgenden Werte übergeben werden: `null`, `""`, `false`, `0`, `[]` oder `{}`**\n'
            if f.type_ != FuncType.COMMAND:
                print("Function {} has a null payload but is not a command?!?".format(f.name))

        if f.command_is_action:
            content += '<Tabs groupId="apiType" queryString className="hidden-tabs"><TabItem value="http"></TabItem><TabItem value="mqtt"><Admonition type="warning" title="Löst eine einmalige Aktion aus. Nachrichten, die über den Broker retained wurden, werden ignoriert."></Admonition></TabItem></Tabs>\n'

        content += self.get_examples(f, module, version)

        if self.type_ == EType.NULL:
            table = ""
        elif self.type_ == EType.ARRAY and self.is_var_length_array:
            table = self.to_table(is_root=True, version=version)
        elif self.type_ == EType.UNION or self.type_ == EType.HIDDEN_UNION:
            table = self.to_tabs(is_root=True, version=version)
        else:
            table = self.to_table(is_root=True, version=version)

        if f.type_ != FuncType.STATE and self.type_ == EType.OBJECT and len(self.val.items()) == 1 and not "do_i_know_what_i_am_doing" in self.val:
            table = "\n\n**<a href=\"#states_section_shortcuts\">Kann abgekürzt werden.</a>**" + table

        content += "\n" + table + "\n"

        if f.type_ == FuncType.HTTP_ONLY:
            content += """    </TabItem>
    <TabItem value="mqtt" label="MQTT (mosquitto)">
        <Admonition type="warning" title="Wird nur von der HTTP-API unterstützt"></Admonition>
    </TabItem>
</Tabs>
"""

        return content

    def to_table(self, is_root: bool, version: Version) -> str:
        table_template = """
<table>
    <thead>
        <tr>
            <th scope="col">{name_or_index}</th>
            <th scope="col">Bedeutung</th>
        </tr>
    </thead>
    <tbody>
{rows}
    </tbody>
</table>"""

        if self.type_ == EType.UNION or self.type_ == EType.HIDDEN_UNION:
            raise Exception("Don't document union as table!")

        if self.type_ == EType.OBJECT:
            if self.version != Version.ANY and all(v.version == self.version for k, v in self.val.items()):
                print(f"Object element '{self.desc}' and all its children specify the same version {self.version.name}. Remove version from children!")
            rows = [v.to_table_row(k, version) for k, v in self.val.items() if version in v.version or version == Version.ANY]
            if len(rows) == 0:
                print(f"Object element '{self.desc}' is empty in version {version.name} but is marked as supported in this version!")
            return table_template.format(name_or_index="Name", rows='\n'.join(rows))

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
                rows.append(group.to_table_row(length, version))
                idx += count

            return table_template.format(name_or_index="Index", rows='\n'.join(rows))

        if self.type_ == EType.OPAQUE:
            return ""

        # primitive

        result = '{type}{unit}: {desc}'.format(
                    type=self.get_type(version=version),
                    unit=wrap_non_empty(' ', self.get_unit(), ''),
                    desc=self.desc)

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
                    consts.append(constant_entry_template.format(val=val, desc=c.desc))

                if len(consts) == 0:
                    continue

                result += constants_template.format(version_label=("\n" + ver.label() + "\n\n") if version == Version.ANY else "",
                                                  entries='\n'.join(consts))

        return result


@dataclass
class Module:
    name: str
    display_name: str
    subheader: str
    desc: str
    version: Version
    functions: list[Func]
    hide_prefix: bool = False

    def to_md(self) -> str:
        result = f"""{{/* This file is autogenerated. Edit warp-charger/api_doc_generator/{self.name}.py! */}}
import MultilineTabs from '@site/src/components/MultilineTabs';
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import Admonition from '@theme/Admonition';

# {self.display_name}
"""

        result += f"**{self.subheader}**\n" if len(self.subheader) > 0 else ""
        result += self.desc + "\n"

        # Just create all versions in separate tabs for now.
        # This is inefficient because modules that are the same in every firmware
        # are generated 5 times.

        result += '<Tabs groupId="hardwareType" queryString className="hidden-tabs">\n'

        for ver in list(Version) + [Version.ANY]:
            result += f'<TabItem value="{ver.name.lower()}">\n'

            if ver not in self.version and ver != Version.ANY:
                result += 'Auf dieser Hardware nicht unterstützt!\n</TabItem>\n'
                continue

            functions = []

            for group, fns in itertools.groupby(self.functions, key=lambda f: f.type_):
                fns = list(fns)

                for f in fns:
                    functions.append(f.root.root_to_md(f, self.name if not self.hide_prefix else None, ver))

            result += "\n<br/><br/><br/>\n".join(functions)
            result += '</TabItem>\n'

        result += '</Tabs>\n'

        toc = []

        for group, fns in itertools.groupby(self.functions, key=lambda f: f.type_):
            fns = list(fns)

            for f in fns:
                toc.append(f"""{{
    "value": "{"{}/{}".format(self.name, f.name) if not self.hide_prefix else f.name}",
    "id": "{"{}_{}".format(self.name, f.name.replace("/", "_")) if not self.hide_prefix else f.name}",
    "level": 2,
    {"" if f.root.version == Version.ANY else ('"hardwareType": ["' + '","'.join(f.root.version.css_classes().split(" ")) + '"]')}
}},""")

        result += f"""
export const toc = [
    {"".join(toc)}
];
"""

        return result
