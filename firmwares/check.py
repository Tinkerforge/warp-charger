#!/usr/bin/env -S python3 -u

import sys
import os
import re
import glob
import hashlib


has_error = False


class SemVer:
    def __init__(self, major, minor, patch, beta=0, build=None):
        assert build == None or len(build) > 0, build

        self.major = major
        self.minor = minor
        self.patch = patch
        self.beta = beta
        self.build = build

    def __str__(self):
        if self.beta == 0:
            beta = ''
        else:
            beta = '-beta.{0}'.format(self.beta)

        if self.build == None:
            build = ''
        else:
            build = '+{0}'.format(self.build)

        return '{0}.{1}.{2}{3}{4}'.format(self.major, self.minor, self.patch, beta, build)

    def __eq__(self, other):
        if not isinstance(other, SemVer):
            return False

        return self.compare(other) == 0 and self.build == other.build

    def __ne__(self, other):
        if not isinstance(other, SemVer):
            return True

        return self.compare(other) != 0 or self.build != other.build

    def __lt__(self, other):
        if not isinstance(other, SemVer):
            return True

        return self.compare(other) < 0

    def __le__(self, other):
        if not isinstance(other, SemVer):
            return True

        return self.compare(other) <= 0

    def __gt__(self, other):
        if not isinstance(other, SemVer):
            return False

        return self.compare(other) > 0

    def __ge__(self, other):
        if not isinstance(other, SemVer):
            return False

        return self.compare(other) >= 0

    def compare(self, other):
        if self.major > other.major:
            return 1

        if self.major < other.major:
            return -1

        if self.minor > other.minor:
            return 1

        if self.minor < other.minor:
            return -1

        if self.patch > other.patch:
            return 1

        if self.patch < other.patch:
            return -1

        if self.beta == 0 and other.beta > 0:
            return 1

        if self.beta > 0 and other.beta == 0:
            return -1

        if self.beta > other.beta:
            return 1

        if self.beta < other.beta:
            return -1

        return 0


def parse_semver(string):
    m = re.match(r'^([1-9][0-9]*)\.(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)(?:-beta\.([1-9][0-9]*))?(?:\+([0-9a-zA-Z-]+(\.[0-9a-zA-Z-]+)*))?$', string)

    if m != None:
        return SemVer(int(m.group(1)), int(m.group(2)), int(m.group(3)), int(m.group(4) if m.group(4) != None else '0'), build=m.group(5))

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

        with open(name, 'r') as f:
            last_semver = None
            lines = list(f.readlines())

            if prefix in v1_lines and lines[:len(v1_lines[prefix])] != v1_lines[prefix]:
                print_error(f'{prefix}_v1.txt is not matching the beginning of {prefix}_v2.txt')

            for line in lines:
                semver = parse_semver(line)

                if semver == None:
                    print_error(f'Cannot parse {repr(line)} from {name}')
                    continue

                if last_semver != None and semver >= last_semver:
                    print_error(f'{semver} is not smaller than {last_semver} in {name}')

                last_semver = semver

                for suffix in ['.elf', '_changelog_en.txt', '_changelog_de.txt', '_merged.bin', '_merged.bin.sha256']:
                    semver_path = str(semver).replace('.', '_').replace('-', '_').replace('+', '_')
                    path = prefix + '_' + semver_path + suffix

                    if not os.path.exists(path):
                        print_error(f'{path} is missing')

                    if suffix == '.elf':
                        if ((prefix == 'warp_firmware' or prefix == 'warp2_firmware' or prefix == 'warp3_firmware') and semver >= SemVer(2, 5, 0)) or \
                           (prefix == 'energy_manager_firmware' and semver >= SemVer(2, 2, 0)) or \
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

    return 1 if has_error else 0


if __name__ == '__main__':
    sys.exit(main())
