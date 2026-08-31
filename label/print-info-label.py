#!/usr/bin/python3 -u

import os
import sys
import argparse
import socket
import time
import tinkerforge_util as tfutil  # sudo apt install python3-tinkerforge-util

ORDER_ID_PLACEHOLDER = b'SO/98765'
INFO_1_PLACEHOLDER = b'Hinweis 1'
INFO_2_PLACEHOLDER = b'Hinweis 2'
INFO_3_PLACEHOLDER = b'Hinweis 3'
INFO_4_PLACEHOLDER = b'Hinweis 4'
INFO_5_PLACEHOLDER = b'Hinweis 5'

COPIES_FORMAT = '^C{0}\r'


def print_internal2_label(order_id, info, copies, stdout):
    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'info.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch order ID
    if template.find(ORDER_ID_PLACEHOLDER) < 0:
        raise Exception('Order ID placeholder missing in EZPL file')

    template = template.replace(ORDER_ID_PLACEHOLDER, order_id.encode('latin1', errors='replace'))

    # split info
    info_lines = []
    info_words = []

    for word in info.split(' '):
        if len(' '.join(info_words + [word])) > 32 and len(info_words) > 0:
            info_lines.append(' '.join(info_words))
            info_words = []

        info_words.append(word)

    if len(info_words) > 0:
        info_lines.append(' '.join(info_words))

    while len(info_lines) < 3:
        info_lines.append('')

    # patch info 1
    if template.find(INFO_1_PLACEHOLDER) < 0:
        raise Exception('Info 1 placeholder missing in EZPL file')

    template = template.replace(INFO_1_PLACEHOLDER, info_lines[0].encode('latin1', errors='replace'))

    # patch info 2
    if template.find(INFO_2_PLACEHOLDER) < 0:
        raise Exception('Info 2 placeholder missing in EZPL file')

    template = template.replace(INFO_2_PLACEHOLDER, info_lines[1].encode('latin1', errors='replace'))

    # patch info 3
    if template.find(INFO_3_PLACEHOLDER) < 0:
        raise Exception('Info 3 placeholder missing in EZPL file')

    template = template.replace(INFO_3_PLACEHOLDER, info_lines[2].encode('latin1', errors='replace'))

    # patch info 4
    if template.find(INFO_4_PLACEHOLDER) < 0:
        raise Exception('Info 4 placeholder missing in EZPL file')

    template = template.replace(INFO_4_PLACEHOLDER, info_lines[3].encode('latin1', errors='replace'))

    # patch info 5
    if template.find(INFO_5_PLACEHOLDER) < 0:
        raise Exception('Info 5 placeholder missing in EZPL file')

    template = template.replace(INFO_5_PLACEHOLDER, info_lines[4].encode('latin1', errors='replace'))

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
        with socket.create_connection((tfutil.get_tf_printer_host('warp-docket-paper'), 9100)) as s:
            s.send(template)
            time.sleep(1)


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('order_id')
    parser.add_argument('info')
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.copies > 0

    print_internal2_label(args.order_id, args.info, args.copies, args.stdout)


if __name__ == '__main__':
    main()
