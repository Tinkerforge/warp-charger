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

QR_CODE_COMMAND = b'W619,119,5,2,M,8,6,84,0\r'
QR_CODE_PADDING = b';;\r'

DESCRIPTION_PLACEHOLDER = b'Smart, 11 kW, 5 m, ZL 12 m, CEE'

SKU_PLACEHOLDER = b'WARP-CS-11KW-50-CEE'

EXTRA_SUPPLY_CABLE_PLACEHOLDER_A = b'+10m'
EXTRA_SUPPLY_CABLE_PLACEHOLDER_B = b'E:10;'

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'5000000001'

BUILD_DATE_PLACEHOLDER = b'2021-01'

ORDER_ID_PLACEHOLDER = b'SO/B202012345'

ITEM_PLACEHOLDER = b'111/222'

ORDER_DATE_PLACEHOLDER = b'1970-01-01 00:00:00'

CUSTOMER_PLACEHOLDER = b'Max Mustermann'

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

def sku_to_description(sku, extra_supply_cable):
    m = re.match(r'^WARP-C(B|S|P)-(11|22)KW-(50|75)(|-CEE)$', sku)

    if m == None:
        raise Exception('Invalid SKU: {0}'.format(sku))

    sku_model = m.group(1)
    sku_power = m.group(2)
    sku_type2_cable_length = m.group(3)
    sku_cee = len(m.group(4)) != 0

    if sku_model == 'B':
        description = b'Basic'
    elif sku_model == 'S':
        description = b'Smart'
    elif sku_model == 'P':
        description = b'Pro'
    else:
        assert False, sku_model

    if sku_power == '11':
        description += b', 11 kW'
    elif sku_power == '22':
        description += b', 22 kW'
    else:
        assert False, sku_power

    if sku_type2_cable_length == '50':
        description += b', 5 m'
    elif sku_type2_cable_length == '75':
        description += b', 7,5 m'
    else:
        assert False, sku_type2_cable_length

    if sku_model == 'P':
        supply_cable_length = 2
    elif sku_cee:
        supply_cable_length = 2
    else:
        supply_cable_length = 0

    supply_cable_length += extra_supply_cable

    description += ', ZL {0} m'.format(supply_cable_length).encode('ascii')

    if sku_cee:
        description += b', CEE'

    return description

def print_docket_label(sku, extra_supply_cable, version, serial_number, build_date, order_id,
                       item, order_date, customer, instances, copies, stdout, force_build_date):
    # check instances
    if instances < 1 or instances > 25:
        raise Exception('Invalid instances: {0}'.format(instances))

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # check extra supply cable
    if extra_supply_cable < 0:
        raise Exception('Invalid extra supply cable: {0}'.format(extra_supply_cable))

    # parse sku
    description = sku_to_description(sku, extra_supply_cable)

    # check version
    if re.match(r'^1\.(0|[1-9][0-9]*)$', version) == None:
        raise Exception('Invalid version: {0}'.format(version))

    # check serial number
    if re.match(r'^-|5[0-9]{9}$', serial_number) == None:
        raise Exception('Invalid serial number: {0}'.format(serial_number))

    # check build date
    parsed_build_date = datetime.strptime(build_date, '%Y-%m')
    now = datetime.now()

    if not force_build_date and (parsed_build_date.year < now.year or (parsed_build_date.year == now.year and parsed_build_date.month < now.month)):
        raise Exception('Invalid build date: {0}'.format(build_date))

    # check order id
    if re.match(r'^SO/B?[0-9]+$', order_id) == None:
        raise Exception('Invalid order ID: {0}'.format(order_id))

    # check item
    if re.match(r'^[1-9][0-9]*/[1-9][0-9]*$', item) == None:
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

    offset = len(SKU_PLACEHOLDER) - len(sku) + \
             len(VERSION_PLACEHOLDER) - len(version) + \
             len(ORDER_ID_PLACEHOLDER) - len(order_id) + \
             len(ITEM_PLACEHOLDER) - len(item)

    if offset < 0:
        raise Exception('QR code data too long')

    template = template.replace(QR_CODE_PADDING, b';' * offset + QR_CODE_PADDING)

    # patch description
    if template.find(DESCRIPTION_PLACEHOLDER) < 0:
        raise Exception('Description placeholder missing in EZPL file')

    template = template.replace(DESCRIPTION_PLACEHOLDER, description)

    # patch SKU
    if template.find(SKU_PLACEHOLDER) < 0:
        raise Exception('SKU placeholder missing in EZPL file')

    template = template.replace(SKU_PLACEHOLDER, sku.encode('ascii'))

    # patch extra supply cable
    if template.find(EXTRA_SUPPLY_CABLE_PLACEHOLDER_A) < 0:
        raise Exception('Extra supply cable placeholder A missing in EZPL file')

    template = template.replace(EXTRA_SUPPLY_CABLE_PLACEHOLDER_A, '+{0}m'.format(extra_supply_cable).encode('ascii'))

    if template.find(EXTRA_SUPPLY_CABLE_PLACEHOLDER_B) < 0:
        raise Exception('Extra supply cable placeholder B missing in EZPL file')

    template = template.replace(EXTRA_SUPPLY_CABLE_PLACEHOLDER_B, 'E:{0};'.format(extra_supply_cable).encode('ascii'))

    # patch version
    if template.find(VERSION_PLACEHOLDER) < 0:
        raise Exception('Version placeholder missing in EZPL file')

    template = template.replace(VERSION_PLACEHOLDER, version.encode('ascii'))

    # patch build date
    if template.find(BUILD_DATE_PLACEHOLDER) < 0:
        raise Exception('Build date placeholder missing in EZPL file')

    template = template.replace(BUILD_DATE_PLACEHOLDER, build_date.encode('ascii'))

    # patch order ID
    if template.find(ORDER_ID_PLACEHOLDER) < 0:
        raise Exception('Order ID placeholder missing in EZPL file')

    template = template.replace(ORDER_ID_PLACEHOLDER, order_id.encode('ascii'))

    # patch item
    if template.find(ITEM_PLACEHOLDER) < 0:
        raise Exception('Item placeholder missing in EZPL file')

    template = template.replace(ITEM_PLACEHOLDER, item.encode('ascii'))

    # patch order date
    if template.find(ORDER_DATE_PLACEHOLDER) < 0:
        raise Exception('Order date placeholder missing in EZPL file')

    template = template.replace(ORDER_DATE_PLACEHOLDER, order_date.encode('ascii'))

    # patch customer
    if template.find(CUSTOMER_PLACEHOLDER) < 0:
        raise Exception('Customer placeholder missing in EZPL file')

    template = template.replace(CUSTOMER_PLACEHOLDER, customer.encode('latin1', errors='replace'))

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

    parser.add_argument('sku')
    parser.add_argument('extra_supply_cable', type=int)
    parser.add_argument('version')
    parser.add_argument('serial_number')
    parser.add_argument('build_date')
    parser.add_argument('order_id')
    parser.add_argument('item')
    parser.add_argument('order_date')
    parser.add_argument('customer')
    parser.add_argument('-i', '--instances', type=int, default=1)
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')
    parser.add_argument('--force-build-date', action='store_true')

    args = parser.parse_args()

    assert args.instances > 0
    assert args.copies > 0

    print_docket_label(args.sku, args.extra_supply_cable, args.version, args.serial_number, args.build_date, args.order_id,
                       args.item, args.order_date, args.customer, args.instances, args.copies, args.stdout, args.force_build_date)

if __name__ == '__main__':
    main()
