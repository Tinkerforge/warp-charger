#!/usr/bin/python3 -u

import os
import sys
import argparse
import socket
import time

HEADER_PLACEHOLDER = 'WARP2 Zubehör für Bestellung SO/98765'.encode('utf-8')

ITEM_FORMAT = 'Artikel {}'
ITEM_MAX_COUNT = 6

DATA_MATRIX_FORMAT = 'XRB851,409,5,2,{}\r'
DATA_MATRIX_PLACEHOLDER = DATA_MATRIX_FORMAT.format(17).encode('ascii')

SKU_FORMAT = '{}\r'
SKU_PLACEHOLDER = SKU_FORMAT.format('WARP-T2-DS-CURVED').encode('ascii')

COPIES_FORMAT = '^C{0}\r'

ITEM_NAMES = {
    'WARP-EM':           'WARP Energy Manager',
    'WARP-EM2':          'WARP Energy Manager 2.0',
    'WARP-T2-DS-HOOK':   'Wandhalter für Stecker und Ladekabel',
    'WARP-T2-DS-CURVED': 'Wandhalter für Stecker, gebogen',
    'WARP-T2-DS':        'Wandhalter für Stecker, gerade',
    'WARP-HOOK':         'Wandhaken für Ladekabel',
    'WARP-S-M6-3MM':     'Sicherheitsschrauben (4 Stück)',
    'WARP-NFC-CARD':     'WARP NFC Karten (3 Stück)',
    '6102':              'NFC Aufkleber, weiss (5 Stück)',
    '6103':              'NFC Aufkleber, transparent (5 Stück)',
    '6104':              'NFC Schlüsselanhänger, schwarz',
    '6105':              'NFC Schlüsselanhänger, rot',
}


def print_accessories2_label(header, items, copies, stdout):
    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # check items
    if len(items) > ITEM_MAX_COUNT:
        raise Exception('Too many items: {0}'.format(len(items)))

    item_skus = []
    item_counts = []

    for item in items:
        parts = item.split(':')

        if len(parts) != 2:
            raise Exception(f'Malformed item: {item}')

        sku, count = parts

        try:
            count = int(count)
        except:
            raise Exception(f'Malformed item count: {item}')

        if count < 1:
            raise Exception(f'Item count too low: {item}')

        item_skus.append(sku)
        item_counts.append(count)

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'accessories2.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch header
    if template.find(HEADER_PLACEHOLDER) < 0:
        raise Exception('Header placeholder missing in EZPL file')

    template = template.replace(HEADER_PLACEHOLDER, header.encode('latin1', errors='replace'))

    # patch data matrix code
    if template.find(DATA_MATRIX_PLACEHOLDER) < 0:
        raise Exception('Data matrix placeholder missing in EZPL file')

    template = template.replace(DATA_MATRIX_PLACEHOLDER, DATA_MATRIX_FORMAT.format(len(item_skus[0])).encode('ascii') if len(item_skus) == 1 else b'') \
                       .replace(SKU_PLACEHOLDER, SKU_FORMAT.format(item_skus[0]).encode('ascii') if len(item_skus) == 1 else b'')

    # patch items
    for i in range(ITEM_MAX_COUNT):
        item_placeholder = ITEM_FORMAT.format(i + 1).encode('ascii')

        if template.find(item_placeholder) < 0:
            raise Exception(f'Item placeholder {i + 1} missing in EZPL file')

        if i < len(item_skus):
            try:
                item_name = f'{item_counts[i]}x {ITEM_NAMES[item_skus[i]]} [{item_skus[i]}]'.encode('latin1', errors='replace')
            except KeyError:
                raise Exception(f'Unknown item: {item_skus[i]}')
        else:
            item_name = b''

        template = template.replace(item_placeholder, item_name)

    # patch copies
    copies_command = COPIES_FORMAT.format(1).encode('ascii')

    if template.find(copies_command) < 0:
        raise Exception('Copies command missing in EZPL file')

    template = template.replace(copies_command, COPIES_FORMAT.format(copies).encode('ascii'))

    # print label
    if stdout:
        sys.stdout.buffer.write(template)
        sys.stdout.buffer.flush()
    else:
        with socket.create_connection((tfutil.get_tf_printer_host('warp-docket'), 9100)) as s:
            s.send(template)
            time.sleep(1)


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('header')
    parser.add_argument('item', nargs='+')
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.copies > 0

    print_accessories2_label(args.header, args.item, args.copies, args.stdout)


if __name__ == '__main__':
    main()
