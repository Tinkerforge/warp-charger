#!/usr/bin/python3 -u

import os
import sys
import argparse
import socket
import time
import tinkerforge_util as tfutil  # sudo apt install python3-tinkerforge-util

ORDER_ID_PLACEHOLDER = b'SO/98765'
CUSTOMER_NAME_1_PLACEHOLDER = b'Max Mustermann 1'
CUSTOMER_NAME_2_PLACEHOLDER = b'Max Mustermann 2'
CUSTOMER_NAME_3_PLACEHOLDER = b'Max Mustermann 3'

COPIES_FORMAT = '^C{0}\r'


def print_internal2_label(order_id, customer_name, copies, stdout):
    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'order.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch order ID
    if template.find(ORDER_ID_PLACEHOLDER) < 0:
        raise Exception('Order ID placeholder missing in EZPL file')

    template = template.replace(ORDER_ID_PLACEHOLDER, order_id.encode('latin1', errors='replace'))

    # split customer name
    customer_name_lines = []
    customer_name_words = []

    for word in customer_name.split(' '):
        if len(' '.join(customer_name_words + [word])) > 32 and len(customer_name_words) > 0:
            customer_name_lines.append(' '.join(customer_name_words))
            customer_name_words = []

        customer_name_words.append(word)

    if len(customer_name_words) > 0:
        customer_name_lines.append(' '.join(customer_name_words))

    while len(customer_name_lines) < 3:
        customer_name_lines.append('')

    # patch customer name 1
    if template.find(CUSTOMER_NAME_1_PLACEHOLDER) < 0:
        raise Exception('Customer name 1 placeholder missing in EZPL file')

    template = template.replace(CUSTOMER_NAME_1_PLACEHOLDER, customer_name_lines[0].encode('latin1', errors='replace'))

    # patch customer name 2
    if template.find(CUSTOMER_NAME_2_PLACEHOLDER) < 0:
        raise Exception('Customer name 2 placeholder missing in EZPL file')

    template = template.replace(CUSTOMER_NAME_2_PLACEHOLDER, customer_name_lines[1].encode('latin1', errors='replace'))

    # patch customer name 3
    if template.find(CUSTOMER_NAME_3_PLACEHOLDER) < 0:
        raise Exception('Customer name 3 placeholder missing in EZPL file')

    template = template.replace(CUSTOMER_NAME_3_PLACEHOLDER, customer_name_lines[2].encode('latin1', errors='replace'))

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
    parser.add_argument('customer_name')
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.copies > 0

    print_internal2_label(args.order_id, args.customer_name, args.copies, args.stdout)


if __name__ == '__main__':
    main()
