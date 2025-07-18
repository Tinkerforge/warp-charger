#!/usr/bin/python3 -u

import os
import sys
import argparse
import socket
import re
import time
import tinkerforge_util as tfutil  # sudo apt install python3-tinkerforge-util

QR_CODE_COMMAND = b'W649,209,5,2,M,8,6,57,0\r'
QR_CODE_PADDING = b';;\r'

HEADER_PLACEHOLDER = b'WARP2 Extras'

STAND_PLACEHOLDER_A = b'Lades\xc3\xa4ule: Bitte'
STAND_PLACEHOLDER_B = b'S:1;'

STAND_DISPLAY_NAME = {
    '0': 'Nein',
    '1': 'Einfach',
    '2': 'Doppelt',
    '1-PC': 'Einfach, pulverbeschichtet',
    '2-PC': 'Doppelt, pulverbeschichtet',
}

STAND_WIRING_PLACEHOLDER_A = b'Verkabelung: Was?'
STAND_WIRING_PLACEHOLDER_B = b'W:1;'

STAND_WIRING_DISPLAY_NAME = {
    '0': 'Nein',
    '1': 'Einfach',
    '2': 'Doppelt',
}

STAND_LOCK_PLACEHOLDER_A = b'Schloss: Hier'
STAND_LOCK_PLACEHOLDER_B = b'L:1;'

SUPPLY_CABLE_PLACEHOLDER_A = b'Anschlusskabel: 123,4 m'
SUPPLY_CABLE_PLACEHOLDER_B = b'E:123.4;'

CEE_PLACEHOLDER_A = b'CEE-Stecker: Jawohl'
CEE_PLACEHOLDER_B = b'C:1;'

CUSTOM_FRONT_PANEL_PLACEHOLDER_A = b'Frontplatte: SO/12345'
CUSTOM_FRONT_PANEL_PLACEHOLDER_B = b'CFP:1;'

CUSTOM_TYPE2_CABLE_PLACEHOLDER_A = b'Typ-2-Kabel: SO/54321'
CUSTOM_TYPE2_CABLE_PLACEHOLDER_B = b'CT2:1;'

COMMENT_1_PLACEHOLDER = b'Hier steht ein mehrzeiliger'
COMMENT_2_PLACEHOLDER = b'Kommentar f\xC3\xBCr sonstige Hinweise.'

COPIES_FORMAT = '^C{0}\r'


def print_accessories2_label(header, stand, stand_wiring, stand_lock, supply_cable, cee, custom_front_panel, custom_type2_cable, comment_1, comment_2, copies, stdout):
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

    # patch header
    if template.find(HEADER_PLACEHOLDER) < 0:
        raise Exception('Header placeholder missing in EZPL file')

    template = template.replace(HEADER_PLACEHOLDER, header.encode('latin1', errors='replace'))

    # patch stand
    if template.find(STAND_PLACEHOLDER_A) < 0:
        raise Exception('Stand placeholder A missing in EZPL file')

    template = template.replace(STAND_PLACEHOLDER_A, 'Ladesäule: {0}'.format(STAND_DISPLAY_NAME[stand]).encode('latin1', errors='replace') if stand != '0' else b'')

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

    # patch stand lock
    if template.find(STAND_LOCK_PLACEHOLDER_A) < 0:
        raise Exception('Stand lock placeholder A missing in EZPL file')

    template = template.replace(STAND_LOCK_PLACEHOLDER_A, b'Schloss: Ja' if stand_lock else b'')

    if template.find(STAND_LOCK_PLACEHOLDER_B) < 0:
        raise Exception('Stand lock placeholder B missing in EZPL file')

    template = template.replace(STAND_LOCK_PLACEHOLDER_B, 'L:{0};'.format(int(stand_lock)).encode('ascii'))

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

    template = template.replace(CEE_PLACEHOLDER_A, b'CEE-Stecker: Ja' if cee else b'')

    if template.find(CEE_PLACEHOLDER_B) < 0:
        raise Exception('CEE placeholder B missing in EZPL file')

    template = template.replace(CEE_PLACEHOLDER_B, 'C:{0};'.format(int(cee)).encode('ascii'))

    # patch custom front panel
    if template.find(CUSTOM_FRONT_PANEL_PLACEHOLDER_A) < 0:
        raise Exception('Custom front panel placeholder A missing in EZPL file')

    template = template.replace(CUSTOM_FRONT_PANEL_PLACEHOLDER_A, 'Front: {0}'.format(custom_front_panel[:28]).encode('latin1', errors='replace') if custom_front_panel != '0' else b'')

    if template.find(CUSTOM_FRONT_PANEL_PLACEHOLDER_B) < 0:
        raise Exception('Custom front panel placeholder B missing in EZPL file')

    template = template.replace(CUSTOM_FRONT_PANEL_PLACEHOLDER_B, 'CFP:{0};'.format(int(custom_front_panel != '0')).encode('ascii'))

    # patch custom type2 cable
    if template.find(CUSTOM_TYPE2_CABLE_PLACEHOLDER_A) < 0:
        raise Exception('Custom type 2 cable placeholder A missing in EZPL file')

    if custom_type2_cable == 'no':
        custom_type2_cable = ''
    else:
        custom_type2_cable, order_id = custom_type2_cable.split(':')

        if custom_type2_cable == 'customer':
            custom_type2_cable = 'Kunde'
        else:
            custom_type2_cable = re.sub(r'0$', ' m', custom_type2_cable).replace('_', ' ').capitalize()

        custom_type2_cable = 'Typ-2-Kabel: {0}, {1}'.format(custom_type2_cable, order_id)

    template = template.replace(CUSTOM_TYPE2_CABLE_PLACEHOLDER_A, custom_type2_cable.encode('ascii'))

    if template.find(CUSTOM_TYPE2_CABLE_PLACEHOLDER_B) < 0:
        raise Exception('Custom type 2 cable placeholder B missing in EZPL file')

    template = template.replace(CUSTOM_TYPE2_CABLE_PLACEHOLDER_B, 'CT2:{0};'.format(int(custom_type2_cable != '0')).encode('ascii'))

    # patch comment 1
    if template.find(COMMENT_1_PLACEHOLDER) < 0:
        raise Exception('Comment 1 placeholder missing in EZPL file')

    template = template.replace(COMMENT_1_PLACEHOLDER, comment_1.encode('latin1', errors='replace'))

    # patch comment 2
    if template.find(COMMENT_2_PLACEHOLDER) < 0:
        raise Exception('Comment 2 placeholder missing in EZPL file')

    template = template.replace(COMMENT_2_PLACEHOLDER, comment_2.encode('latin1', errors='replace'))

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
    parser.add_argument('stand', choices=['0', '1', '2', '1-PC', '2-PC'])
    parser.add_argument('stand_wiring', choices=['0', '1', '2'])
    parser.add_argument('stand_lock', type=int, choices=[0, 1])
    parser.add_argument('supply_cable', type=float)
    parser.add_argument('cee', type=int, choices=[1, 0])
    parser.add_argument('custom_front_panel')
    parser.add_argument('custom_type2_cable')
    parser.add_argument('comment_1')
    parser.add_argument('comment_2')
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.copies > 0

    print_accessories2_label(args.header, args.stand, args.stand_wiring, args.stand_lock, args.supply_cable, bool(args.cee), args.custom_front_panel, args.custom_type2_cable, args.comment_1, args.comment_2, args.copies, args.stdout)


if __name__ == '__main__':
    main()
