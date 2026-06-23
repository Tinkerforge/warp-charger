#!/usr/bin/python3 -u

import os
import sys
import re
import argparse
import socket
from datetime import datetime
import urllib.request
import ssl
import time
import tinkerforge_util as tfutil  # sudo apt install python3-tinkerforge-util

QR_CODE_COMMAND = b'W649,209,5,2,M,8,6,57,0\r'
QR_CODE_PADDING = b';;\r'

DESCRIPTION_PLACEHOLDER = b'WARP2 Charger Smart, 11 kW, 5 m, pulverbeschichtet'

SKU_PLACEHOLDER = b'WARP2-CS-11KW-50-PC'

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'5000000001'

BUILD_DATE_PLACEHOLDER = b'2021-01'

CURRENT_PLACEHOLDER = b', 16 A'

COPIES_FORMAT = '^C{0}\r'

EXTRAS_FORMAT = ';A:{0};'


def get_next_serial_number():
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'staging_password.txt'), 'r') as f:
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


def print_warp2_label(sku, version, serial_number, build_date, custom_type2, instances, copies, stdout, force_build_date, extras):
    # check instances
    if instances < 1 or instances > 25:
        raise Exception('Invalid instances: {0}'.format(instances))

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # parse SKU
    m = re.match(r'^(WARP4)-(C(?:S|P|E))-(SS|PC)-((?:11|22)?(?:50|75)?|CC)-(W|C)$', sku)

    if m != None:
        sku_product = m.group(1)
        sku_model = m.group(2)
        sku_material = m.group(3)

        if m.group(4).startswith('11'):
            sku_type2_power = '11'
        elif m.group(4).startswith('22'):
            sku_type2_power = '22'
        elif m.group(4) == 'CC':
            sku_type2_power = 'CC'

        if m.group(4).endswith('50'):
            sku_type2_length = '50'
        elif m.group(4).endswith('75'):
            sku_type2_length = '75'
        elif m.group(4) == 'CC':
            sku_type2_length = 'CC'
    else:
        m = re.match(r'^(WARP(?:2|3))-(C(?:B|S|P))-(11|22)KW-(50|75|CC)(?:-(PC))?$', sku)

        if m == None:
            raise Exception('Invalid SKU: {0}'.format(sku))

        sku_product = m.group(1)
        sku_model = m.group(2)
        sku_material = m.group(5) if m.group(5) != None else 'SS'
        sku_type2_power = m.group(3)
        sku_type2_length = m.group(4)

    if custom_type2 == 'no':
        custom_type2_cable = 'no'
        custom_type2_power = None
        custom_type2_length = None
    else:
        custom_type2_cable, custom_type2_power, custom_type2_length = custom_type2.split('_')
        custom_type2_length = round(int(custom_type2_length) / 10, 1)

    if sku_product == 'WARP2':
        description = b'WARP2 Charger'
    elif sku_product == 'WARP3':
        description = b'WARP3 Charger'
    elif sku_product == 'WARP4':
        description = b'WARP4 Charger'
    else:
        assert False, sku_product

    if sku_model == 'CB':
        description += b' Basic'
    elif sku_model == 'CS':
        description += b' Smart'
    elif sku_model == 'CP':
        description += b' Pro'
    elif sku_model == 'CE':
        description += b' Eichrecht'
    else:
        assert False, sku_model

    if sku_type2_power == '11':
        description += b', 11 kW'
    elif sku_type2_power == '22':
        description += b', 22 kW'
    elif sku_type2_power == 'CC':
        assert sku_type2_length == 'CC', sku_type2_length

        if custom_type2_power == None:
            pass
        elif custom_type2_power == 'h':
            description += b', 11 kW'
        elif custom_type2_power == 'f':
            description += b', 22 kW'
        else:
            assert False, custom_type2_power
    else:
        assert False, sku_type2_power

    if sku_type2_length == '50':
        description += b', 5 m'
    elif sku_type2_length == '75':
        description += b', 7,5 m'
    elif sku_type2_length == 'CC':
        if sku_product == 'WARP2':
            assert False, (sku_product, sku_type2_length)
        elif sku_product == 'WARP4':
            assert sku_type2_power == 'CC', sku_type2_power

        if custom_type2_length != None:
            description += f', {int(custom_type2_length) if int(custom_type2_length) == custom_type2_length else custom_type2_length} m'.replace('.', ',').encode('ascii')
    else:
        assert False, sku_type2_length

    if sku_material == None:
        pass
    elif sku_material == 'SS':
        description += b', Edelstahl'
    elif sku_material == 'PC':
        description += b', Pulverlack'
    else:
        assert False, sku_material

    if sku_type2_power == '11':
        current = b', 16 A'
    elif sku_type2_power == '22':
        current = b', 32 A'
    elif sku_type2_power == 'CC':
        if custom_type2_power == None:
            current = b''
        elif custom_type2_power == 'h':
            current = b', 16 A'
        elif custom_type2_power == 'f':
            current = b', 32 A'
    else:
        assert False, sku_type2_power

    # check version
    if re.match(r'^{0}\.(0|[1-9][0-9]*)$'.format(sku_product[-1:]), version) == None:
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

    offset = len(SKU_PLACEHOLDER) - len(sku) + len(VERSION_PLACEHOLDER) - len(version)

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

    # patch extras
    extras_placeholder = EXTRAS_FORMAT.format('0').encode('ascii')

    if template.find(extras_placeholder) < 0:
        raise Exception('Extras placeholder missing in EZPL file')

    template = template.replace(extras_placeholder, EXTRAS_FORMAT.format('1' if extras else '0').encode('ascii'))

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
            time.sleep(2)


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('sku')
    parser.add_argument('version')
    parser.add_argument('serial_number')
    parser.add_argument('build_date')
    parser.add_argument('custom_type2')
    parser.add_argument('-i', '--instances', type=int, default=1)
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')
    parser.add_argument('--force-build-date', action='store_true')
    parser.add_argument('--extras', action='store_true')

    args = parser.parse_args()

    assert args.instances > 0
    assert args.copies > 0

    print_warp2_label(args.sku, args.version, args.serial_number, args.build_date, args.custom_type2, args.instances, args.copies, args.stdout, args.force_build_date, args.extras)


if __name__ == '__main__':
    main()
