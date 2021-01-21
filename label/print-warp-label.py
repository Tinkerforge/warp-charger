#!/usr/bin/python3 -u

import os
import sys
import re
import argparse
import socket
from datetime import datetime
import urllib.request
import ssl

PRINTER_HOST = 'BP730i'
PRINTER_PORT = 9100

QR_CODE_FORMAT = 'W649,209,5,2,M,8,6,{0},0\r'
QR_CODE_LENGTH = 56

DESCRIPTION_PLACEHOLDER = b'WARP Charger Smart, 11 kW, 5 m, CEE'

TYPE_PLACEHOLDER = b'WARP-CS-11KW-50-CEE'

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'5000000001'

DATE_PLACEHOLDER = b'2021-01-13'

VOLTAGE_PLACEHOLDER = b'230 / 400'

CURRENT_PLACEHOLDER = b'16 A'

CONDUCTOR_PLACEHOLDER = b'1P / 3P'

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

def print_warp_label(type_, version, serial_number, date, copies=1):
    # parse type
    m = re.match('^WARP-C(B|S|P)-(11|22)KW-(50|75)(|-CEE)$', type_)

    if m == None:
        raise Exception('Invalid type: {0}'.format(type_))

    type_model = m.group(1)
    type_power = m.group(2)
    type_cable = m.group(3)
    type_cee = len(m.group(4)) != 0

    description = b'WARP Charger '

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

    if type_cee:
        description += b', CEE'

    if type_model in ['B', 'S']:
        voltage = b'230 / 400'
    elif type_model == 'P':
        voltage = b'400'
    else:
        assert False, type_model

    if type_power == '11':
        current = b'16 A'
    elif type_power == '22':
        current = b'32 A'
    else:
        assert False, type_power

    if type_model in ['B', 'S']:
        conductor = b'1P / 3P'
    elif type_model == 'P':
        conductor = b'3P'
    else:
        assert False, type_model

    # check version
    if re.match('^[1-9]\.(0|[1-9][0-9]*)$', version) == None:
        raise Exception('Invalid version: {0}'.format(version))

    # check serial number
    if serial_number == '-':
        serial_number = get_next_serial_number()

    if re.match('^5[0-9]{9}$', serial_number) == None:
        raise Exception('Invalid serial number: {0}'.format(serial_number))

    # check date
    datetime.strptime(date, '%Y-%m-%d')

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'warp.prn'), 'rb') as f:
        data = f.read()

    if data.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch QR code
    qr_code_command = QR_CODE_FORMAT.format(QR_CODE_LENGTH).encode('ascii')

    if data.find(qr_code_command) < 0:
        raise Exception('QR code command missing in EZPL file')

    data = data.replace(qr_code_command, QR_CODE_FORMAT.format(QR_CODE_LENGTH - len(TYPE_PLACEHOLDER) - len(VERSION_PLACEHOLDER) + len(type_) + len(version)).encode('ascii'))

    # patch description
    if data.find(DESCRIPTION_PLACEHOLDER) < 0:
        raise Exception('Description placeholder missing in EZPL file')

    data = data.replace(DESCRIPTION_PLACEHOLDER, description)

    # patch type
    if data.find(TYPE_PLACEHOLDER) < 0:
        raise Exception('Type placeholder missing in EZPL file')

    data = data.replace(TYPE_PLACEHOLDER, type_.encode('ascii'))

    # patch version
    if data.find(VERSION_PLACEHOLDER) < 0:
        raise Exception('Version placeholder missing in EZPL file')

    data = data.replace(VERSION_PLACEHOLDER, version.encode('ascii'))

    # patch serial number
    if data.find(SERIAL_NUMBER_PLACEHOLDER) < 0:
        raise Exception('Serial number placeholder missing in EZPL file')

    data = data.replace(SERIAL_NUMBER_PLACEHOLDER, serial_number.encode('ascii'))

    # patch date
    if data.find(DATE_PLACEHOLDER) < 0:
        raise Exception('Date placeholder missing in EZPL file')

    data = data.replace(DATE_PLACEHOLDER, date.encode('ascii'))

    # patch voltage
    if data.find(VOLTAGE_PLACEHOLDER) < 0:
        raise Exception('Voltage placeholder missing in EZPL file')

    data = data.replace(VOLTAGE_PLACEHOLDER, voltage)

    # patch current
    if data.find(CURRENT_PLACEHOLDER) < 0:
        raise Exception('Current placeholder missing in EZPL file')

    data = data.replace(CURRENT_PLACEHOLDER, current)

    # patch conductor
    if data.find(CONDUCTOR_PLACEHOLDER) < 0:
        raise Exception('Conductor placeholder missing in EZPL file')

    data = data.replace(CONDUCTOR_PLACEHOLDER, conductor)

    # patch copies
    copies_command = COPIES_FORMAT.format(1).encode('ascii')

    if data.find(copies_command) < 0:
        raise Exception('Copies command missing in EZPL file')

    data = data.replace(copies_command, COPIES_FORMAT.format(copies).encode('ascii'))

    # print label
    with socket.create_connection((PRINTER_HOST, PRINTER_PORT)) as s:
        s.send(data)

def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('type')
    parser.add_argument('version')
    parser.add_argument('serial_number')
    parser.add_argument('date')
    parser.add_argument('-c', '--copies', type=int, default=1)

    args = parser.parse_args()

    print_warp_label(args.type, args.version, args.serial_number, args.date, args.copies)

if __name__ == '__main__':
    main()
