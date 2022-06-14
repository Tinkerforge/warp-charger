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

QR_CODE_COMMAND = b'W649,209,5,2,M,8,6,58,0\r'
QR_CODE_PADDING = b';;\r'

SKU_PLACEHOLDER = b'WARP2-CS-11KW-50'

SUPPLY_CABLE_PLACEHOLDER_A = b'Anschlusskabel: 123,4 m'
SUPPLY_CABLE_PLACEHOLDER_B = b'E:123.4;'

CEE_PLACEHOLDER_A = b'CEE Stecker: Jawohl'
CEE_PLACEHOLDER_B = b'C:1;'

COMMENT_1_PLACEHOLDER = b'Hier steht ein mehrzeiliger'
COMMENT_2_PLACEHOLDER = b'Kommentar f\xC3\xBCr sonstige'
COMMENT_3_PLACEHOLDER = b'Hinweise.'

COPIES_FORMAT = '^C{0}\r'

def print_accessories2_label(supply_cable, cee, comment_1, comment_2, comment_3, copies, stdout):
    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # check supply cable
    if supply_cable < 0:
        raise Exception('Invalid supply cable: {0}'.format(supply_cable))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'accessories2.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch QR code
    if template.find(QR_CODE_COMMAND) < 0:
        raise Exception('QR code command missing in EZPL file')

    supply_cable_a = 'Anschlusskabel: {0} m'.format(str(int(supply_cable) if int(supply_cable) == supply_cable else supply_cable).replace('.', ','))
    supply_cable_b = 'E:{0};'.format(supply_cable)

    offset = len(SUPPLY_CABLE_PLACEHOLDER_B) - len(supply_cable_b)

    if offset < 0:
        raise Exception('QR code data too long')

    template = template.replace(QR_CODE_PADDING, b';' * offset + QR_CODE_PADDING)

    # patch supply cable
    if template.find(SUPPLY_CABLE_PLACEHOLDER_A) < 0:
        raise Exception('Supply cable placeholder A missing in EZPL file')

    template = template.replace(SUPPLY_CABLE_PLACEHOLDER_A, supply_cable_a.encode('ascii') if supply_cable > 0 else b'')

    if template.find(SUPPLY_CABLE_PLACEHOLDER_B) < 0:
        raise Exception('Supply cable placeholder B missing in EZPL file')

    template = template.replace(SUPPLY_CABLE_PLACEHOLDER_B, supply_cable_b.encode('ascii'))

    # patch CEE
    if template.find(CEE_PLACEHOLDER_A) < 0:
        raise Exception('CEE placeholder A missing in EZPL file')

    template = template.replace(CEE_PLACEHOLDER_A, b'CEE Stecker: Ja' if cee else b'')

    if template.find(CEE_PLACEHOLDER_B) < 0:
        raise Exception('CEE placeholder B missing in EZPL file')

    template = template.replace(CEE_PLACEHOLDER_B, 'C:{0};'.format(int(cee)).encode('ascii'))

    # patch comment 1
    if template.find(COMMENT_1_PLACEHOLDER) < 0:
        raise Exception('Comment 1 placeholder missing in EZPL file')

    template = template.replace(COMMENT_1_PLACEHOLDER, comment_1.encode('latin1', errors='replace'))

    # patch comment 2
    if template.find(COMMENT_2_PLACEHOLDER) < 0:
        raise Exception('Comment 2 placeholder missing in EZPL file')

    template = template.replace(COMMENT_2_PLACEHOLDER, comment_2.encode('latin1', errors='replace'))

    # patch comment 3
    if template.find(COMMENT_3_PLACEHOLDER) < 0:
        raise Exception('Comment 3 placeholder missing in EZPL file')

    template = template.replace(COMMENT_3_PLACEHOLDER, comment_3.encode('latin1', errors='replace'))

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
        with socket.create_connection((PRINTER_HOST, PRINTER_PORT)) as s:
            s.send(template)

def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('supply_cable', type=float)
    parser.add_argument('cee', type=int, choices=[1, 0])
    parser.add_argument('comment_1')
    parser.add_argument('comment_2')
    parser.add_argument('comment_3')
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.copies > 0

    print_accessories2_label(args.supply_cable, bool(args.cee), args.comment_1, args.comment_2, args.comment_3, args.copies, args.stdout)

if __name__ == '__main__':
    main()
