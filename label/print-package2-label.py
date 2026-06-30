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

EAN13_PLACEHOLDER = b'4251640705480'
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

    'WARP2-CB-11KW-50-PC': b'4251640705442',
    'WARP2-CB-11KW-75-PC': b'4251640705459',
    'WARP2-CB-22KW-50-PC': b'4251640705466',
    'WARP2-CB-22KW-75-PC': b'4251640705473',

    'WARP2-CS-11KW-50-PC': b'4251640705480',
    'WARP2-CS-11KW-75-PC': b'4251640705497',
    'WARP2-CS-22KW-50-PC': b'4251640705503',
    'WARP2-CS-22KW-75-PC': b'4251640705510',

    'WARP2-CP-11KW-50-PC': b'4251640705527',
    'WARP2-CP-11KW-75-PC': b'4251640705534',
    'WARP2-CP-22KW-50-PC': b'4251640705541',
    'WARP2-CP-22KW-75-PC': b'4251640705558',

    'WARP3-CB-11KW-50': b'4251640705596',
    'WARP3-CB-11KW-75': b'4251640705602',
    'WARP3-CB-11KW-CC': b'4251640705978',
    'WARP3-CB-22KW-50': b'4251640705619',
    'WARP3-CB-22KW-75': b'4251640705626',
    'WARP3-CB-22KW-CC': b'4251640705992',

    'WARP3-CS-11KW-50': b'4251640705633',
    'WARP3-CS-11KW-75': b'4251640705640',
    'WARP3-CS-11KW-CC': b'4251640706012',
    'WARP3-CS-22KW-50': b'4251640705657',
    'WARP3-CS-22KW-75': b'4251640705664',
    'WARP3-CS-22KW-CC': b'4251640706036',

    'WARP3-CP-11KW-50': b'4251640705671',
    'WARP3-CP-11KW-75': b'4251640705688',
    'WARP3-CP-11KW-CC': b'4251640706050',
    'WARP3-CP-22KW-50': b'4251640705695',
    'WARP3-CP-22KW-75': b'4251640705701',
    'WARP3-CP-22KW-CC': b'4251640706074',

    'WARP3-CB-11KW-50-PC': b'4251640705718',
    'WARP3-CB-11KW-75-PC': b'4251640705725',
    'WARP3-CB-11KW-CC-PC': b'4251640705985',
    'WARP3-CB-22KW-50-PC': b'4251640705732',
    'WARP3-CB-22KW-75-PC': b'4251640705749',
    'WARP3-CB-22KW-CC-PC': b'4251640706005',

    'WARP3-CS-11KW-50-PC': b'4251640705756',
    'WARP3-CS-11KW-75-PC': b'4251640705763',
    'WARP3-CS-11KW-CC-PC': b'4251640706029',
    'WARP3-CS-22KW-50-PC': b'4251640705770',
    'WARP3-CS-22KW-75-PC': b'4251640705787',
    'WARP3-CS-22KW-CC-PC': b'4251640706043',

    'WARP3-CP-11KW-50-PC': b'4251640705794',
    'WARP3-CP-11KW-75-PC': b'4251640705800',
    'WARP3-CP-11KW-CC-PC': b'4251640706067',
    'WARP3-CP-22KW-50-PC': b'4251640705817',
    'WARP3-CP-22KW-75-PC': b'4251640705824',
    'WARP3-CP-22KW-CC-PC': b'4251640706081',

    'WARP4-CS-SS-1150-W': b'4251640707385',
    'WARP4-CS-SS-1150-C': b'4251640707378',
    'WARP4-CS-SS-1175-W': b'4251640707361',
    'WARP4-CS-SS-1175-C': b'4251640707354',
    'WARP4-CS-SS-2250-W': b'4251640707347',
    'WARP4-CS-SS-2250-C': b'4251640707330',
    'WARP4-CS-SS-2275-W': b'4251640707323',
    'WARP4-CS-SS-2275-C': b'4251640707316',
    'WARP4-CS-SS-CC-W':   b'4251640707309',
    'WARP4-CS-SS-CC-C':   b'4251640707293',
    'WARP4-CS-PC-1150-W': b'4251640707286',
    'WARP4-CS-PC-1150-C': b'4251640707279',
    'WARP4-CS-PC-1175-W': b'4251640707262',
    'WARP4-CS-PC-1175-C': b'4251640707255',
    'WARP4-CS-PC-2250-W': b'4251640707248',
    'WARP4-CS-PC-2250-C': b'4251640707231',
    'WARP4-CS-PC-2275-W': b'4251640707224',
    'WARP4-CS-PC-2275-C': b'4251640707217',
    'WARP4-CS-PC-CC-W':   b'4251640707200',
    'WARP4-CS-PC-CC-C':   b'4251640707194',

    'WARP4-CP-SS-1150-W': b'4251640707187',
    'WARP4-CP-SS-1150-C': b'4251640707170',
    'WARP4-CP-SS-1175-W': b'4251640707163',
    'WARP4-CP-SS-1175-C': b'4251640707156',
    'WARP4-CP-SS-2250-W': b'4251640707149',
    'WARP4-CP-SS-2250-C': b'4251640707132',
    'WARP4-CP-SS-2275-W': b'4251640707125',
    'WARP4-CP-SS-2275-C': b'4251640707118',
    'WARP4-CP-SS-CC-W':   b'4251640707101',
    'WARP4-CP-SS-CC-C':   b'4251640707095',
    'WARP4-CP-PC-1150-W': b'4251640707088',
    'WARP4-CP-PC-1150-C': b'4251640707071',
    'WARP4-CP-PC-1175-W': b'4251640707064',
    'WARP4-CP-PC-1175-C': b'4251640707057',
    'WARP4-CP-PC-2250-W': b'4251640707040',
    'WARP4-CP-PC-2250-C': b'4251640707033',
    'WARP4-CP-PC-2275-W': b'4251640707026',
    'WARP4-CP-PC-2275-C': b'4251640707019',
    'WARP4-CP-PC-CC-W':   b'4251640707002',
    'WARP4-CP-PC-CC-C':   b'4251640706999',

    'WARP4-CE-SS-1150-W': b'4251640706982',
    'WARP4-CE-SS-1150-C': b'4251640706975',
    'WARP4-CE-SS-1175-W': b'4251640706968',
    'WARP4-CE-SS-1175-C': b'4251640706951',
    'WARP4-CE-SS-2250-W': b'4251640706944',
    'WARP4-CE-SS-2250-C': b'4251640706937',
    'WARP4-CE-SS-2275-W': b'4251640706920',
    'WARP4-CE-SS-2275-C': b'4251640706913',
    'WARP4-CE-SS-CC-W':   b'4251640706906',
    'WARP4-CE-SS-CC-C':   b'4251640706890',
    'WARP4-CE-PC-1150-W': b'4251640706883',
    'WARP4-CE-PC-1150-C': b'4251640706876',
    'WARP4-CE-PC-1175-W': b'4251640706869',
    'WARP4-CE-PC-1175-C': b'4251640706852',
    'WARP4-CE-PC-2250-W': b'4251640706845',
    'WARP4-CE-PC-2250-C': b'4251640706838',
    'WARP4-CE-PC-2275-W': b'4251640706821',
    'WARP4-CE-PC-2275-C': b'4251640706814',
    'WARP4-CE-PC-CC-W':   b'4251640706807',
    'WARP4-CE-PC-CC-C':   b'4251640706791',

    'WARP-EM': b'4251640705381',
    'WARP-EM2': b'4251640706098',
}

DESCRIPTION_PLACEHOLDER = b'WARP2 Charger Smart, 11 kW, 5 m, pulverbeschichtet'

FULL_SKU_PLACEHOLDER = b'Typ: WARP2-CS-11KW-50-PC'

BASE_SKU_PLACEHOLDER = b'WARP2-CS-11KW-50-PC'

DATA_MATRIX_FORMAT_RECTANGLE = 'XRB97,190,5,1R,{}\r'
DATA_MATRIX_FORMAT_SQUARE = 'XRB97,190,5,2,{}\r'
DATA_MATRIX_PLACEHOLDER = DATA_MATRIX_FORMAT_RECTANGLE.format(19).encode('ascii')

VERSION_PLACEHOLDER = b'2.17'

SERIAL_NUMBER_PLACEHOLDER = b'5000000001'

BUILD_DATE_PLACEHOLDER = b'2021-01'

COPIES_FORMAT = '^C{0}\r'


def get_next_serial_number(kind):
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

    return '{0}{1:09}'.format(kind, serial_number)


def print_package2_label(full_sku, version, serial_number, build_date, custom_type2, instances, copies, stdout, force_build_date):
    # check instances
    if instances < 1 or instances > 25:
        raise Exception('Invalid instances: {0}'.format(instances))

    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # parse SKU
    base_sku = full_sku

    if base_sku.startswith('TF-'):
        base_sku = base_sku[3:]

    if base_sku == 'WARP-EM':
        description = b'WARP Energy Manager'
        version_major = 1
        serial_number_kind = 7
    elif base_sku == 'WARP-EM2':
        description = b'WARP Energy Manager 2.0'
        version_major = 2
        serial_number_kind = 7
    else:
        if base_sku.startswith('WARP4-'):
            # WARP4-XX-XX-XXXX-X
            #       CS SS 1150 W
            #       CP PC 1175 C
            #       CE    2250
            #             2275
            #             CC
            m = re.match(r'^(?:TF-)?(WARP4)-C(S|P|E)-(SS|PC)-((?:11|22)?(?:50|75)?|CC)-(W|C)$', full_sku)

            if m == None:
                raise Exception('Invalid SKU: {0}'.format(full_sku))

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
            m = re.match(r'^(?:TF-)?(WARP(?:2|3))-C(B|S|P)-(11|22)KW-(50|75|CC)(?:-(PC))?$', full_sku)

            if m == None:
                raise Exception('Invalid SKU: {0}'.format(full_sku))

            sku_product = m.group(1)
            sku_model = m.group(2)
            sku_material = m.group(5) if m.group(5) != None else 'SS'
            sku_type2_power = m.group(3)
            sku_type2_length = m.group(4)

        version_major = int(sku_product[-1:])
        serial_number_kind = 5

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

        if sku_model == 'B':
            description += b' Basic'
        elif sku_model == 'S':
            description += b' Smart'
        elif sku_model == 'P':
            description += b' Pro'
        elif sku_model == 'E':
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

    template = template.replace(EAN13_PLACEHOLDER, EAN13_NUMBERS[base_sku])

    # patch description
    if template.find(DESCRIPTION_PLACEHOLDER) < 0:
        raise Exception('Description placeholder missing in EZPL file')

    template = template.replace(DESCRIPTION_PLACEHOLDER, description)

    # patch SKU
    if template.find(FULL_SKU_PLACEHOLDER) < 0:
        raise Exception('Full SKU placeholder missing in EZPL file')

    template = template.replace(FULL_SKU_PLACEHOLDER, ('Typ: ' + full_sku).encode('ascii'))

    if template.find(BASE_SKU_PLACEHOLDER) < 0:
        raise Exception('Base SKU placeholder missing in EZPL file')

    template = template.replace(BASE_SKU_PLACEHOLDER, base_sku.encode('ascii'))

    if template.find(DATA_MATRIX_PLACEHOLDER) < 0:
        raise Exception('Data Matrix placeholder missing in EZPL file')

    if len(base_sku) < 9:
        data_matrix_format = DATA_MATRIX_FORMAT_SQUARE
    else:
        data_matrix_format = DATA_MATRIX_FORMAT_RECTANGLE

    template = template.replace(DATA_MATRIX_PLACEHOLDER, data_matrix_format.format(len(base_sku)).encode('ascii'))

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
        with socket.create_connection((tfutil.get_tf_printer_host('warp-docket'), 9100)) as s:
            s.send(data)
            time.sleep(1)


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('sku')
    parser.add_argument('version')
    parser.add_argument('serial_number')
    parser.add_argument('build_date')
    parser.add_argument('-t', '--custom-type2', default='no')
    parser.add_argument('-i', '--instances', type=int, default=1)
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')
    parser.add_argument('--force-build-date', action='store_true')

    args = parser.parse_args()

    assert args.instances > 0
    assert args.copies > 0

    print_package2_label(args.sku, args.version, args.serial_number, args.build_date, args.custom_type2, args.instances, args.copies, args.stdout, args.force_build_date)


if __name__ == '__main__':
    main()
