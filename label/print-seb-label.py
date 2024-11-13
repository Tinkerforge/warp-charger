#!/usr/bin/python3 -u

import os
import sys
import re
import argparse
import socket
from datetime import datetime
import urllib.request
import ssl
import tinkerforge_util as tfutil  # sudo apt install python3-tinkerforge-util

QR_CODE_COMMAND = b'W645,213,5,2,M,8,6,61,0\r'
QR_CODE_PADDING = b';;\r'

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'6000000001'

BUILD_DATE_PLACEHOLDER = b'2023-01'

MAC_ADDRESS_PLACEHOLDER = b'11:22:33:44:55:66'

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

    return '3{0:09}'.format(serial_number)


def print_wem_label(version, serial_number, build_date, mac_address, instances, copies, stdout, force_build_date):
    # check instances
    if instances < 1 or instances > 25:
        raise Exception('Invalid instances: {0}'.format(instances))

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # check version
    if re.match(r'^1\.(0|[1-9][0-9]*)$', version) == None:
        raise Exception('Invalid version: {0}'.format(version))

    # check serial number
    if re.match(r'^(-|3[0-9]{9})$', serial_number) == None:
        raise Exception('Invalid serial number: {0}'.format(serial_number))

    # check build date
    parsed_build_date = datetime.strptime(build_date, '%Y-%m')

    if parsed_build_date.strftime('%Y-%m') != build_date:
        raise Exception('Invalid build date: {0}'.format(build_date))

    now = datetime.now()

    if not force_build_date and (parsed_build_date.year < now.year or (parsed_build_date.year == now.year and parsed_build_date.month < now.month)):
        raise Exception('Invalid build date: {0}'.format(build_date))

    # check MAC address
    if re.match(r'^[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}:[0-9A-F]{2}$', mac_address) == None:
        raise Exception('Invalid MAC addressr: {0}'.format(mac_address))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'seb.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch QR code
    if template.find(QR_CODE_COMMAND) < 0:
        raise Exception('QR code command missing in EZPL file')

    offset = len(MAC_ADDRESS_PLACEHOLDER) - len(mac_address) + len(VERSION_PLACEHOLDER) - len(version)

    if offset < 0:
        raise Exception('QR code data too long')

    template = template.replace(QR_CODE_PADDING, b';' * offset + QR_CODE_PADDING)

    # patch version
    if template.find(VERSION_PLACEHOLDER) < 0:
        raise Exception('Version placeholder missing in EZPL file')

    template = template.replace(VERSION_PLACEHOLDER, version.encode('ascii'))

    # patch build date
    if template.find(BUILD_DATE_PLACEHOLDER) < 0:
        raise Exception('Build date placeholder missing in EZPL file')

    template = template.replace(BUILD_DATE_PLACEHOLDER, build_date.encode('ascii'))

    # patch MAC address
    if template.find(MAC_ADDRESS_PLACEHOLDER) < 0:
        raise Exception('MAC address placeholder missing in EZPL file')

    template = template.replace(MAC_ADDRESS_PLACEHOLDER, mac_address.encode('ascii'))

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
        with socket.create_connection((tfutil.get_tf_printer_host('warp-docket'), 9100)) as s:
            s.send(data)


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('version')
    parser.add_argument('serial_number')
    parser.add_argument('build_date')
    parser.add_argument('mac_address')
    parser.add_argument('-i', '--instances', type=int, default=1)
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')
    parser.add_argument('--force-build-date', action='store_true')

    args = parser.parse_args()

    assert args.instances > 0
    assert args.copies > 0

    print_wem_label(args.version, args.serial_number, args.build_date, args.mac_address, args.instances, args.copies, args.stdout, args.force_build_date)


if __name__ == '__main__':
    main()
