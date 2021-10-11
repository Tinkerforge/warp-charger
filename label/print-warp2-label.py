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

QR_CODE_COMMAND = b'W649,209,5,2,M,8,6,50,0\r'
QR_CODE_PADDING = b';;\r'

DESCRIPTION_PLACEHOLDER = b'WARP2 Charger Smart, 11 kW, 5 m'

TYPE_PLACEHOLDER = b'WARP2-CS-11KW-50'

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'5000000001'

BUILD_DATE_PLACEHOLDER = b'2021-01'

CURRENT_PLACEHOLDER = b'16 A'

COPIES_FORMAT = '^C{0}\r'

def get_next_serial_number():
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

    return '5{0:09}'.format(serial_number)

def print_warp_label(type_, version, serial_number, build_date, instances, copies, stdout, force_build_date):
    # check instances
    if instances < 1 or instances > 25:
        raise Exception('Invalid instances: {0}'.format(instances))

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # parse type
    m = re.match(r'^WARP2-C(B|S|P)-(11|22)KW-(50|75)$', type_)

    if m == None:
        raise Exception('Invalid type: {0}'.format(type_))

    type_model = m.group(1)
    type_power = m.group(2)
    type_cable = m.group(3)

    description = b'WARP2 Charger '

    if type_model == 'B':
        description += b'Basic'
    elif type_model == 'S':
        description += b'Smart'
    elif type_model == 'P':
        description += b'Pro'
    else:
        assert False, type_model

    if type_power == '11':
        description += b', 11 kW'
    elif type_power == '22':
        description += b', 22 kW'
    else:
        assert False, type_power

    if type_cable == '50':
        description += b', 5 m'
    elif type_cable == '75':
        description += b', 7,5 m'
    else:
        assert False, type_cable

    if type_power == '11':
        current = b'16 A'
    elif type_power == '22':
        current = b'32 A'
    else:
        assert False, type_power

    # check version
    if re.match(r'^2\.(0|[1-9][0-9]*)$', version) == None:
        raise Exception('Invalid version: {0}'.format(version))

    # check serial number
    if re.match(r'^(-|5[0-9]{9})$', serial_number) == None:
        raise Exception('Invalid serial number: {0}'.format(serial_number))

    # check build date
    parsed_build_date = datetime.strptime(build_date, '%Y-%m')

    if parsed_build_date.strftime('%Y-%m') != build_date:
        raise Exception('Invalid build date: {0}'.format(build_date))

    now = datetime.now()

    if not force_build_date and (parsed_build_date.year < now.year or (parsed_build_date.year == now.year and parsed_build_date.month < now.month)):
        raise Exception('Invalid build date: {0}'.format(build_date))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'warp2.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch QR code
    if template.find(QR_CODE_COMMAND) < 0:
        raise Exception('QR code command missing in EZPL file')

    offset = len(TYPE_PLACEHOLDER) - len(type_) + len(VERSION_PLACEHOLDER) - len(version)

    if offset < 0:
        raise Exception('QR code data too long')

    template = template.replace(QR_CODE_PADDING, b';' * offset + QR_CODE_PADDING)

    # patch description
    if template.find(DESCRIPTION_PLACEHOLDER) < 0:
        raise Exception('Description placeholder missing in EZPL file')

    template = template.replace(DESCRIPTION_PLACEHOLDER, description)

    # patch type
    if template.find(TYPE_PLACEHOLDER) < 0:
        raise Exception('Type placeholder missing in EZPL file')

    template = template.replace(TYPE_PLACEHOLDER, type_.encode('ascii'))

    # patch version
    if template.find(VERSION_PLACEHOLDER) < 0:
        raise Exception('Version placeholder missing in EZPL file')

    template = template.replace(VERSION_PLACEHOLDER, version.encode('ascii'))

    # patch build date
    if template.find(BUILD_DATE_PLACEHOLDER) < 0:
        raise Exception('Build date placeholder missing in EZPL file')

    template = template.replace(BUILD_DATE_PLACEHOLDER, build_date.encode('ascii'))

    # patch current
    if template.find(CURRENT_PLACEHOLDER) < 0:
        raise Exception('Current placeholder missing in EZPL file')

    template = template.replace(CURRENT_PLACEHOLDER, current)

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
            actual_serial_number = get_next_serial_number()
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

    parser.add_argument('type')
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

    print_warp_label(args.type, args.version, args.serial_number, args.build_date, args.instances, args.copies, args.stdout, args.force_build_date)

if __name__ == '__main__':
    main()
