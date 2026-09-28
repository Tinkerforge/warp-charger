#!/usr/bin/env -S python3 -u

import sys
import os
import re
import glob
import hashlib


has_error = False


class SemanticVersion:
    def __init__(self, major, minor, patch, beta=255, timestamp=0xffffffff):
        self.major = major
        self.minor = minor
        self.patch = patch
        self.beta = beta  # 255 == no beta
        self.timestamp = timestamp  # 0xffffffff == no timestamp

    def to_string(self, separators=('.', '-', '.', '+')):
        if self.beta >= 255:
            beta = ''
        else:
            beta = f'{separators[1]}beta{separators[2]}{self.beta}'

        if self.timestamp >= 0xffffffff:
            timestamp = ''
        else:
            timestamp = f'{separators[3]}{self.timestamp:x}'

        return f'{self.major}{separators[0]}{self.minor}{separators[0]}{self.patch}{beta}{timestamp}'

    def __str__(self):
        return self.to_string()

    def to_path(self):
        return self.to_string(separators=('_', '_', '_', '_'))

    def as_tuple(self):
        return (self.major, self.minor, self.patch, self.beta, self.timestamp)

    def _check_type(self, operator, other):
        if not isinstance(other, SemanticVersion):
            raise TypeError(f"'{operator}' not supported between instances of {type(self).__name__} and {type(other).__name__}")

    def __eq__(self, other):
        if other == None:
            return False

        self._check_type('==', other)

        return self.as_tuple() == other.as_tuple()

    def __ne__(self, other):
        if other == None:
            return True

        self._check_type('!=', other)

        return self.as_tuple() != other.as_tuple()

    def __lt__(self, other):
        self._check_type('<', other)

        return self.as_tuple() < other.as_tuple()

    def __le__(self, other):
        self._check_type('<=', other)

        return self.as_tuple() <= other.as_tuple()

    def __gt__(self, other):
        self._check_type('>', other)

        return self.as_tuple() > other.as_tuple()

    def __ge__(self, other):
        self._check_type('>=', other)

        return self.as_tuple() >= other.as_tuple()

    @staticmethod
    def from_string(string):
        m = re.match(r'^([1-9][0-9]*)\.(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)(?:-beta\.([1-9][0-9]*))?(?:\+([0-9a-fA-F]+))?$', string)

        if m != None:
            return SemanticVersion(int(m.group(1)),
                                   int(m.group(2)),
                                   int(m.group(3)),
                                   beta=int(m.group(4)) if m.group(4) != None else 255,
                                   timestamp=int(m.group(5), 16) if m.group(5) != None else 0xffffffff)

        return None


def print_error(*args):
    global has_error

    has_error = True

    print(*args)


def main():
    v1_lines = {}

    for name in sorted(glob.glob('*_firmware_v1.txt')):
        prefix = name.replace('_v1.txt', '')
        size = os.stat(name).st_size

        # There is a bug in WARP <= 2.7.2, WARP2 <= 2.7.3, WARP3 <= 2.7.3, WEM <= 2.3.2, WEM2 <= 1.2.2 and SEB <= 1.2.2
        # that makes the firmware update check report a wrong malformed-index error in case the index file was received
        # in more than one chunk. Being hosted on warp-charger.com makes the index file being received as more than one
        # chunk if it's bigger than 708 byte. For backwards compatibility limit the size of the index file to 708 byte.
        if size > 708:
            print_error(f'{name} is too big: {size} > 708')

        with open(name, 'r') as f:
            v1_lines[prefix] = list(f.readlines())

    for name in sorted(glob.glob('*_firmware_v2.txt')):
        prefix = name.replace('_v2.txt', '')

        if prefix not in v1_lines:
            print_error(f'{prefix}_v1.txt is missing')

        first_semver = None

        with open(name, 'r') as f:
            last_semver = None
            lines = list(f.readlines())

            if prefix in v1_lines and lines[:len(v1_lines[prefix])] != v1_lines[prefix]:
                print_error(f'{prefix}_v1.txt is not matching the beginning of {prefix}_v2.txt')

            for line in lines:
                semver = SemanticVersion.from_string(line)

                if semver == None:
                    print_error(f'Cannot parse {repr(line)} from {name}')
                    continue

                if first_semver == None:
                    first_semver = semver

                if last_semver != None and semver >= last_semver:
                    print_error(f'{semver} is not smaller than {last_semver} in {name}')

                last_semver = semver

                for suffix in ['.elf', '_changelog_en.txt', '_changelog_de.txt', '_merged.bin', '_merged.bin.sha256']:
                    semver_path = semver.to_path()
                    path = prefix + '_' + semver_path + suffix

                    if not os.path.exists(path):
                        print_error(f'{path} is missing')

                    if suffix == '.elf':
                        if ((prefix == 'warp_firmware' or prefix == 'warp2_firmware' or prefix == 'warp3_firmware') and semver >= SemanticVersion(2, 5, 0)) or \
                           (prefix == 'energy_manager_firmware' and semver >= SemanticVersion(2, 2, 0)) or \
                           prefix == 'energy_manager_v2_firmware' or \
                           prefix == 'smart_energy_broker_firmware':
                            index_html_path = f'static_html/{semver_path}_index.html'

                            if not os.path.exists(index_html_path):
                                print_error(f'{index_html_path} is missing')
                    elif suffix == '_merged.bin':
                        with open(path, 'rb') as k:
                            firmware_data = k.read()

                        firmware_info_offset = 0xd000 - 0x1000
                        signature_info_offset = firmware_info_offset - 0x1000

                        signature_info = bytearray(firmware_data[signature_info_offset:signature_info_offset + 0x1000])

                        if signature_info[0:7] == bytes([0xff] * 7):
                            print_error(f'{path} is not sodium signed')
                    elif suffix == '_merged.bin.sha256':
                        with open(path, 'r') as k:
                            expected_sha256sum, expected_path = k.read().strip().split('  ', 1)

                        actual_path = path.replace('.sha256', '')

                        with open(actual_path, 'rb') as k:
                            firmware_data = k.read()

                        actual_sha256sum = hashlib.sha256(firmware_data).hexdigest()

                        if actual_sha256sum != expected_sha256sum:
                            print_error(f'{path} checksum mismatch: {repr(actual_sha256sum)} != {repr(expected_sha256sum)}')

                        if actual_path != expected_path:
                            print_error(f'{path} path mismatch: {repr(actual_path)} != {repr(expected_path)}')

        if first_semver != None:
            path = prefix + '_latest_merged.bin'

            if not os.path.exists(path):
                print_error(f'{path} is missing')
            else:
                expected_target = prefix + '_' + first_semver.to_path() + '_merged.bin'
                actual_target = os.readlink(path)

                if actual_target != expected_target:
                    print_error(f'Symlink {path} target mismatch: {repr(actual_target)} != {repr(expected_target)}')

    for name in sorted(glob.glob('*_firmware_v3.txt')):
        prefix = name.replace('_v3.txt', '')

        if prefix != 'warp4_firmware' and prefix not in v1_lines:
            print_error(f'{prefix}_v1.txt is missing')

        first_semver = None

        with open(name, 'r') as f:
            last_semver = None
            lines = list(f.readlines())

            if prefix != 'warp4_firmware' and prefix in v1_lines and lines[:len(v1_lines[prefix])] != v1_lines[prefix]:
                print_error(f'{prefix}_v1.txt is not matching the beginning of {prefix}_v3.txt')

            for line in lines:
                semver = SemanticVersion.from_string(line)

                if semver == None:
                    print_error(f'Cannot parse {repr(line)} from {name}')
                    continue

                if first_semver == None:
                    first_semver = semver

                if last_semver != None and semver >= last_semver:
                    print_error(f'{semver} is not smaller than {last_semver} in {name}')

                if last_semver == None:
                    link_path = prefix + '_latest_ota.bin'
                    semver_path = semver.to_path()
                    dest_path = prefix + '_' + semver_path + '_ota.bin'

                    if not os.path.exists(link_path):
                        print_error(f'{link_path} is missing')
                    elif os.readlink(link_path) != dest_path:
                        print_error(f'{link_path} links to the wrong file')

                last_semver = semver

                for suffix in ['.elf', '_changelog_en.txt', '_changelog_de.txt', '_esptool.bin', '_esptool.bin.sha256', '_ota.bin', '_ota.bin.sha256']:
                    semver_path = semver.to_path()
                    path = prefix + '_' + semver_path + suffix

                    if not os.path.exists(path):
                        print_error(f'{path} is missing')

                    if suffix == '.elf':
                        index_html_path = f'static_html/{semver_path}_index.html'

                        if not os.path.exists(index_html_path):
                            print_error(f'{index_html_path} is missing')
                    elif suffix == '_ota.bin':
                        with open(path, 'rb') as k:
                            firmware_data = k.read()

                        firmware_info_offset = 0xd000 - 0x1000
                        signature_info_offset = firmware_info_offset - 0x1000

                        signature_info = bytearray(firmware_data[signature_info_offset:signature_info_offset + 0x1000])

                        if signature_info[0:7] == bytes([0xff] * 7):
                            print_error(f'{path} is not sodium signed')
                    elif suffix in ['_esptool.bin.sha256', '_ota.bin.sha256']:
                        with open(path, 'r') as k:
                            expected_sha256sum, expected_path = k.read().strip().split('  ', 1)

                        actual_path = path.replace('.sha256', '')

                        with open(actual_path, 'rb') as k:
                            firmware_data = k.read()

                        actual_sha256sum = hashlib.sha256(firmware_data).hexdigest()

                        if actual_sha256sum != expected_sha256sum:
                            print_error(f'{path} checksum mismatch: {repr(actual_sha256sum)} != {repr(expected_sha256sum)}')

                        if actual_path != expected_path:
                            print_error(f'{path} path mismatch: {repr(actual_path)} != {repr(expected_path)}')

        if first_semver != None:
            for suffix in ['_esptool.bin', '_ota.bin']:
                path = prefix + '_latest' + suffix

                if not os.path.exists(path):
                    print_error(f'{path} is missing')
                else:
                    expected_target = prefix + '_' + first_semver.to_path() + suffix
                    actual_target = os.readlink(path)

                    if actual_target != expected_target:
                        print_error(f'Symlink {path} target mismatch: {repr(actual_target)} != {repr(expected_target)}')

    return 1 if has_error else 0


if __name__ == '__main__':
    sys.exit(main())
