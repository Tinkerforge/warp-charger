#!/usr/bin/python3 -u

import os
import re
import glob


class SemVer:
    def __init__(self, major, minor, patch, beta, build=None):
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


def main():
    for name in glob.glob('*_firmware_v1.txt'):
        prefix = name.replace('_v1.txt', '')

        with open(name, 'r') as f:
            last_semver = None

            for line in f.readlines():
                semver = parse_semver(line)

                if semver == None:
                    print(f'Cannot parse {repr(line)} from {name}')
                elif last_semver != None and semver >= last_semver:
                    print(f'{semver} is not smaller than {last_semver} in {name}')

                last_semver = semver

                for suffix in ['.elf', '_changelog_en.txt', '_changelog_de.txt', '_merged.bin', '_merged.bin.sha256']:
                    extra = prefix + '_' + str(semver).replace('.', '_').replace('-', '_').replace('+', '_') + suffix

                    if not os.path.exists(extra):
                        print(f'{extra} is missing')

if __name__ == '__main__':
    main()
