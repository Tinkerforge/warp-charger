#!/usr/bin/python3 -u

import os
import sys
import re
import argparse
import socket
from datetime import datetime
import urllib.request
import ssl


QR_CODE_COMMAND = b'W649,209,5,2,M,8,6,57,0\r'
QR_CODE_PADDING = b';;\r'

STAND_PLACEHOLDER_A = b'Lades\xc3\xa4ule: Bitte'
STAND_PLACEHOLDER_B = b'S:1;'

STAND_DISPLAY_NAME = {
    '0': 'Nein',
    '1': '1x',
    '2': '2x',
    '1-PC': '1x, pulverbeschichtet',
    '2-PC': '2x, pulverbeschichtet',
}

STAND_WIRING_PLACEHOLDER_A = b'Verkabelung: Was?'
STAND_WIRING_PLACEHOLDER_B = b'W:1;'

STAND_WIRING_DISPLAY_NAME = {
    '0': 'Nein',
    '1': '1x',
    '2': '2x',
}

SUPPLY_CABLE_PLACEHOLDER_A = b'Anschlusskabel: 123,4 m'
SUPPLY_CABLE_PLACEHOLDER_B = b'E:123.4;'

CEE_PLACEHOLDER_A = b'CEE Stecker: Jawohl'
CEE_PLACEHOLDER_B = b'C:1;'

COMMENT_1_PLACEHOLDER = b'Hier steht ein mehrzeiliger'
COMMENT_2_PLACEHOLDER = b'Kommentar f\xC3\xBCr sonstige'
COMMENT_3_PLACEHOLDER = b'Hinweise.'

COPIES_FORMAT = '^C{0}\r'


def get_tf_printer_host(task):
    import re
    import os
    import sys
    import tkinter.messagebox

    path = '~/tf_printer_host.txt'
    x = re.compile(r'^([A-Za-z0-9_-]+)\s+([0-9\.]+)$')

    try:
        with open(os.path.expanduser(path), 'r', encoding='utf-8') as f:
            for line in f.readlines():
                line = line.strip()

                if len(line) == 0 or line.startswith('#'):
                    continue

                m = x.match(line)

                if m == None:
                    message = 'WARNING: Invalid line in {0}: {1}'.format(path, repr(line))

                    print(message)
                    tkinter.messagebox.showerror(title=path, message=message)

                    continue

                other_task = m.group(1)
                other_host = m.group(2)

                if other_task != task:
                    continue

                return other_host
    except FileNotFoundError:
        pass

    message = 'ERROR: Printer host for task {0} not found in {1}'.format(task, path)

    print(message)
    tkinter.messagebox.showerror(title=path, message=message)

    sys.exit(1)


def print_accessories2_label(stand, stand_wiring, supply_cable, cee, comment_1, comment_2, comment_3, copies, stdout):
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

    # patch stand
    if template.find(STAND_PLACEHOLDER_A) < 0:
        raise Exception('Stand placeholder A missing in EZPL file')

    template = template.replace(STAND_PLACEHOLDER_A, 'Ladesäule: {0}'.format(STAND_DISPLAY_NAME[stand]).encode('utf-8') if stand != '0' else b'')

    if template.find(STAND_PLACEHOLDER_B) < 0:
        raise Exception('Stand placeholder B missing in EZPL file')

    template = template.replace(STAND_PLACEHOLDER_B, 'S:{0};'.format(stand).encode('ascii'))

    # patch stand wiring
    if template.find(STAND_WIRING_PLACEHOLDER_A) < 0:
        raise Exception('Stand wiring placeholder A missing in EZPL file')

    template = template.replace(STAND_WIRING_PLACEHOLDER_A, 'Verkabelung: {0}'.format(STAND_WIRING_DISPLAY_NAME[stand_wiring]).encode('ascii') if stand_wiring != '0' else b'')

    if template.find(STAND_WIRING_PLACEHOLDER_B) < 0:
        raise Exception('Stand wiring placeholder B missing in EZPL file')

    template = template.replace(STAND_WIRING_PLACEHOLDER_B, 'W:{0};'.format(stand_wiring).encode('ascii'))

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
        with socket.create_connection((get_tf_printer_host('warp-docket'), 9100)) as s:
            s.send(template)


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('stand', choices=['0', '1', '2', '1-PC', '2-PC'])
    parser.add_argument('stand_wiring', choices=['0', '1', '2'])
    parser.add_argument('supply_cable', type=float)
    parser.add_argument('cee', type=int, choices=[1, 0])
    parser.add_argument('comment_1')
    parser.add_argument('comment_2')
    parser.add_argument('comment_3')
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.copies > 0

    print_accessories2_label(args.stand, args.stand_wiring, args.supply_cable, bool(args.cee), args.comment_1, args.comment_2, args.comment_3, args.copies, args.stdout)


if __name__ == '__main__':
    main()
