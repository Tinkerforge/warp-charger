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

QR_CODE_COMMAND = b'W619,119,5,2,M,8,6,84,0\r'
QR_CODE_PADDING = b';;\r'

DESCRIPTION_PLACEHOLDER = b'Smart, 11 kW, 5 m, ZL 12 m, CEE'

TYPE_PLACEHOLDER = b'WARP-CS-11KW-50-CEE'

SUPPLY_CABLE_EXTENSION_PLACEHOLDER_A = b'+10m'
SUPPLY_CABLE_EXTENSION_PLACEHOLDER_B = b'E:10;'

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'5000000001'

BUILD_DATE_PLACEHOLDER = b'2021-01'

ORDER_PLACEHOLDER = b'SO/B202012345'

ITEM_PLACEHOLDER = b'111/222'

ORDER_DATE_PLACEHOLDER = b'1970-01-01 00:00:00'

NAME_PLACEHOLDER = b'Max Mustermann'

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

def print_docket_label(type_, supply_cable_extension, version, serial_number, build_date, order, item, order_date, name, instances, copies, stdout):
    # check instances
    if instances < 1 or instances > 25:
        raise Exception('Invalid instances: {0}'.format(instances))

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # check supply cable extension
    if supply_cable_extension < 0:
        raise Exception('Invalid supply cable extension: {0}'.format(supply_cable_extension))

    # parse type
    m = re.match('^WARP-C(B|S|P)-(11|22)KW-(50|75)(|-CEE)$', type_)

    if m == None:
        raise Exception('Invalid type: {0}'.format(type_))

    type_model = m.group(1)
    type_power = m.group(2)
    type_type2_cable_length = m.group(3)
    type_cee = len(m.group(4)) != 0

    if type_model == 'B':
        description = b'Basic'
    elif type_model == 'S':
        description = b'Smart'
    elif type_model == 'P':
        description = b'Pro'
    else:
        assert False, type_model

    if type_power == '11':
        description += b', 11 kW'
    elif type_power == '22':
        description += b', 22 kW'
    else:
        assert False, type_power

    if type_type2_cable_length == '50':
        description += b', 5 m'
    elif type_type2_cable_length == '75':
        description += b', 7,5 m'
    else:
        assert False, type_type2_cable_length

    if type_model == 'P':
        supply_cable_length = 2
    elif type_cee:
        supply_cable_length = 2
    else:
        supply_cable_length = 0

    supply_cable_length += supply_cable_extension

    description += ', ZL {0} m'.format(supply_cable_length).encode('ascii')

    if type_cee:
        description += b', CEE'

    # check version
    if re.match('^[1-9]\.(0|[1-9][0-9]*)$', version) == None:
        raise Exception('Invalid version: {0}'.format(version))

    # check serial number
    if re.match('^-|5[0-9]{9}$', serial_number) == None:
        raise Exception('Invalid serial number: {0}'.format(serial_number))

    # check build date
    parsed_build_date = datetime.strptime(build_date, '%Y-%m')
    now = datetime.now()

    if parsed_build_date.year < now.year or (parsed_build_date.year == now.year and parsed_build_date.month < now.month):
        raise Exception('Invalid build date: {0}'.format(build_date))

    # check order
    if re.match('^SO/B?[0-9]+$', order) == None:
        raise Exception('Invalid order: {0}'.format(order))

    # check item
    if re.match('^[1-9][0-9]*/[1-9][0-9]*$', item) == None:
        raise Exception('Invalid item: {0}'.format(item))

    # check order date
    datetime.strptime(order_date, '%Y-%m-%d %H:%M:%S')

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'docket.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch QR code
    if template.find(QR_CODE_COMMAND) < 0:
        raise Exception('QR code command missing in EZPL file')

    offset = len(TYPE_PLACEHOLDER) - len(type_) + \
             len(VERSION_PLACEHOLDER) - len(version) + \
             len(ORDER_PLACEHOLDER) - len(order) + \
             len(ITEM_PLACEHOLDER) - len(item)

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

    # patch supply cable extension
    if template.find(SUPPLY_CABLE_EXTENSION_PLACEHOLDER_A) < 0:
        raise Exception('Supply cable extension placeholder A missing in EZPL file')

    template = template.replace(SUPPLY_CABLE_EXTENSION_PLACEHOLDER_A, '+{0}m'.format(supply_cable_extension).encode('ascii'))

    if template.find(SUPPLY_CABLE_EXTENSION_PLACEHOLDER_B) < 0:
        raise Exception('Supply cable extension placeholder B missing in EZPL file')

    template = template.replace(SUPPLY_CABLE_EXTENSION_PLACEHOLDER_B, 'E:{0};'.format(supply_cable_extension).encode('ascii'))

    # patch version
    if template.find(VERSION_PLACEHOLDER) < 0:
        raise Exception('Version placeholder missing in EZPL file')

    template = template.replace(VERSION_PLACEHOLDER, version.encode('ascii'))

    # patch build date
    if template.find(BUILD_DATE_PLACEHOLDER) < 0:
        raise Exception('Build date placeholder missing in EZPL file')

    template = template.replace(BUILD_DATE_PLACEHOLDER, build_date.encode('ascii'))

    # patch order
    if template.find(ORDER_PLACEHOLDER) < 0:
        raise Exception('Order placeholder missing in EZPL file')

    template = template.replace(ORDER_PLACEHOLDER, order.encode('ascii'))

    # patch item
    if template.find(ITEM_PLACEHOLDER) < 0:
        raise Exception('Item placeholder missing in EZPL file')

    template = template.replace(ITEM_PLACEHOLDER, item.encode('ascii'))

    # patch order date
    if template.find(ORDER_DATE_PLACEHOLDER) < 0:
        raise Exception('Order date placeholder missing in EZPL file')

    template = template.replace(ORDER_DATE_PLACEHOLDER, order_date.encode('ascii'))

    # patch name
    if template.find(NAME_PLACEHOLDER) < 0:
        raise Exception('Name placeholder missing in EZPL file')

    template = template.replace(NAME_PLACEHOLDER, name.encode('latin1', errors='replace'))

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
    parser.add_argument('supply_cable_extension', type=int)
    parser.add_argument('version')
    parser.add_argument('serial_number')
    parser.add_argument('build_date')
    parser.add_argument('order')
    parser.add_argument('item')
    parser.add_argument('order_date')
    parser.add_argument('name')
    parser.add_argument('-i', '--instances', type=int, default=1)
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.instances > 0
    assert args.copies > 0

    print_docket_label(args.type, args.supply_cable_extension, args.version, args.serial_number, args.build_date, args.order, args.item, args.order_date, args.name, args.instances, args.copies, args.stdout)

if __name__ == '__main__':
    main()
