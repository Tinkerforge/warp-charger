#!/usr/bin/python3 -u

import os
import sys
import re
import argparse
import socket
from datetime import datetime
import urllib.request
import ssl

PRINTER_HOST = '192.168.178.241'
PRINTER_PORT = 9100

EAN13_PLACEHOLDER = b'4251640704810'
EAN13_NUMBERS = {
    'WARP2-CB-11KW-50': b'4251640704773',
    'WARP2-CB-11KW-75': b'4251640704780',
    'WARP2-CB-22KW-50': b'4251640704797',
    'WARP2-CB-22KW-75': b'4251640704803',

    'WARP2-CS-11KW-50': b'4251640704810',
    'WARP2-CS-11KW-75': b'4251640704827',
    'WARP2-CS-22KW-50': b'4251640704834',
    'WARP2-CS-22KW-75': b'4251640704841',

    'WARP2-CP-11KW-50': b'4251640704858',
    'WARP2-CP-11KW-75': b'4251640704865',
    'WARP2-CP-22KW-50': b'4251640704872',
    'WARP2-CP-22KW-75': b'4251640704889',

    'WARP-EM':          b'4251640705381',
}

DESCRIPTION_PLACEHOLDER = b'WARP2 Charger Smart, 11 kW, 5 m'

SKU_PLACEHOLDER = b'WARP2-CS-11KW-50'

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'5000000001'

BUILD_DATE_PLACEHOLDER = b'2021-01'

COPIES_FORMAT = '^C{0}\r'

def get_next_serial_number(kind):
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'staging-password.txt'), 'r') as f:
        staging_password = f.read().strip()

    if sys.version_info < (3, 5, 3):
        context = ssl.SSLContext(protocol=ssl.PROTOCOL_SSLv23)
    else:
        context = ssl.SSLContext()

    https_handler = urllib.request.HTTPSHandler(context=context)

    auth_handler = urllib.request.HTTPBasicAuthHandler()
    auth_handler.add_password(realm='Staging',
                              uri='https://stagingwww.tinkerforge.com',
                              user='staging',
                              passwd=staging_password)

    opener = urllib.request.build_opener(https_handler, auth_handler)
    urllib.request.install_opener(opener)

    serial_number = int(urllib.request.urlopen('https://stagingwww.tinkerforge.com/warpsn', timeout=15).read())

    return '{0}{1:09}'.format(kind, serial_number)

def print_package2_label(sku, version, serial_number, build_date, instances, copies, stdout, force_build_date):
    # check instances
    if instances < 1 or instances > 25:
        raise Exception('Invalid instances: {0}'.format(instances))

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # parse SKU
    if sku == 'WARP-EM':
        description = b'WARP Energy Manager'#
        version_major = 1
        serial_number_kind = 6
    else:
        m = re.match(r'^(?:TF-)?WARP2-C(B|S|P)-(11|22)KW-(50|75)$', sku)

        if m == None:
            raise Exception('Invalid SKU: {0}'.format(sku))

        sku_model = m.group(1)
        sku_power = m.group(2)
        sku_cable = m.group(3)

        description = b'WARP2 Charger '
        version_major = 2
        serial_number_kind = 5

        if sku_model == 'B':
            description += b'Basic'
        elif sku_model == 'S':
            description += b'Smart'
        elif sku_model == 'P':
            description += b'Pro'
        else:
            assert False, sku_model

        if sku_power == '11':
            description += b', 11 kW'
        elif sku_power == '22':
            description += b', 22 kW'
        else:
            assert False, sku_power

        if sku_cable == '50':
            description += b', 5 m'
        elif sku_cable == '75':
            description += b', 7,5 m'
        else:
            assert False, sku_cable

    # check version
    if re.match(r'^{0}\.(0|[1-9][0-9]*)$'.format(version_major), version) == None:
        raise Exception('Invalid version: {0}'.format(version))

    # check serial number
    if re.match(r'^(-|{0}[0-9]{{9}})$'.format(serial_number_kind), serial_number) == None:
        raise Exception('Invalid serial number: {0}'.format(serial_number))

    # check build date
    parsed_build_date = datetime.strptime(build_date, '%Y-%m')

    if parsed_build_date.strftime('%Y-%m') != build_date:
        raise Exception('Invalid build date: {0}'.format(build_date))

    now = datetime.now()

    if not force_build_date and (parsed_build_date.year < now.year or (parsed_build_date.year == now.year and parsed_build_date.month < now.month)):
        raise Exception('Invalid build date: {0}'.format(build_date))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'package2.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch EAN13
    if template.find(EAN13_PLACEHOLDER) < 0:
        raise Exception('EAN13 placeholder missing in EZPL file')

    base_sku = sku

    if base_sku.startswith('TF-'):
        base_sku = base_sku[3:]

    template = template.replace(EAN13_PLACEHOLDER, EAN13_NUMBERS[base_sku])

    # patch description
    if template.find(DESCRIPTION_PLACEHOLDER) < 0:
        raise Exception('Description placeholder missing in EZPL file')

    template = template.replace(DESCRIPTION_PLACEHOLDER, description)

    # patch SKU
    if template.find(SKU_PLACEHOLDER) < 0:
        raise Exception('SKU placeholder missing in EZPL file')

    template = template.replace(SKU_PLACEHOLDER, sku.encode('ascii'))

    # patch version
    if template.find(VERSION_PLACEHOLDER) < 0:
        raise Exception('Version placeholder missing in EZPL file')

    template = template.replace(VERSION_PLACEHOLDER, version.encode('ascii'))

    # patch build date
    if template.find(BUILD_DATE_PLACEHOLDER) < 0:
        raise Exception('Build date placeholder missing in EZPL file')

    template = template.replace(BUILD_DATE_PLACEHOLDER, build_date.encode('ascii'))

    # patch copies
    copies_command = COPIES_FORMAT.format(1).encode('ascii')

    if template.find(copies_command) < 0:
        raise Exception('Copies command missing in EZPL file')

    template = template.replace(copies_command, COPIES_FORMAT.format(copies).encode('ascii'))

    # patch serial number
    if template.find(SERIAL_NUMBER_PLACEHOLDER) < 0:
        raise Exception('Serial number placeholder missing in EZPL file')

    data = b''

    for _ in range(instances):
        if serial_number == '-':
            actual_serial_number = get_next_serial_number(serial_number_kind)
        else:
            actual_serial_number = serial_number

        data += template.replace(SERIAL_NUMBER_PLACEHOLDER, actual_serial_number.encode('ascii'))

    # print label
    if stdout:
        sys.stdout.buffer.write(data)
        sys.stdout.buffer.flush()
    else:
        with socket.create_connection((PRINTER_HOST, PRINTER_PORT)) as s:
            s.send(data)

def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('sku')
    parser.add_argument('version')
    parser.add_argument('serial_number')
    parser.add_argument('build_date')
    parser.add_argument('-i', '--instances', type=int, default=1)
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')
    parser.add_argument('--force-build-date', action='store_true')

    args = parser.parse_args()

    assert args.instances > 0
    assert args.copies > 0

    print_package2_label(args.sku, args.version, args.serial_number, args.build_date, args.instances, args.copies, args.stdout, args.force_build_date)

if __name__ == '__main__':
    main()
