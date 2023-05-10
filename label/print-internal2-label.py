#!/usr/bin/python3 -u

import os
import sys
import argparse
import socket

INTERNAL_1_PLACEHOLDER = b'Hier steht ein mehrzeiliger'
INTERNAL_2_PLACEHOLDER = b'Kommentar f\xC3\xBCr sonstige'
INTERNAL_3_PLACEHOLDER = b'Hinweise und Gedanke.'
INTERNAL_4_PLACEHOLDER = b'Was man sich auch'
INTERNAL_5_PLACEHOLDER = b'immer intern mitteilen will,'
INTERNAL_6_PLACEHOLDER = b'hier ist Platz daf\xC3\xBCr.'
INTERNAL_7_PLACEHOLDER = b'Und noch zwei'
INTERNAL_8_PLACEHOLDER = b'weitere Zeilen.'

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


def print_internal2_label(internal_1, internal_2, internal_3, internal_4, internal_5, internal_6, internal_7, internal_8, copies, stdout):
    # check copies
    if copies < 1 or copies > 5:
        raise Exception('Invalid copies: {0}'.format(copies))

    # read EZPL file
    with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'internal2.prn'), 'rb') as f:
        template = f.read()

    if template.find(b'^H13\r') < 0:
        raise Exception('EZPL file is using wrong darkness setting')

    # patch internal 1
    if template.find(INTERNAL_1_PLACEHOLDER) < 0:
        raise Exception('Internal 1 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_1_PLACEHOLDER, internal_1.encode('latin1', errors='replace'))

    # patch internal 2
    if template.find(INTERNAL_2_PLACEHOLDER) < 0:
        raise Exception('Internal 2 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_2_PLACEHOLDER, internal_2.encode('latin1', errors='replace'))

    # patch internal 3
    if template.find(INTERNAL_3_PLACEHOLDER) < 0:
        raise Exception('Internal 3 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_3_PLACEHOLDER, internal_3.encode('latin1', errors='replace'))

    # patch internal 4
    if template.find(INTERNAL_4_PLACEHOLDER) < 0:
        raise Exception('Internal 4 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_4_PLACEHOLDER, internal_4.encode('latin1', errors='replace'))

    # patch internal 5
    if template.find(INTERNAL_5_PLACEHOLDER) < 0:
        raise Exception('Internal 5 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_5_PLACEHOLDER, internal_5.encode('latin1', errors='replace'))

    # patch internal 6
    if template.find(INTERNAL_6_PLACEHOLDER) < 0:
        raise Exception('Internal 6 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_6_PLACEHOLDER, internal_6.encode('latin1', errors='replace'))

    # patch internal 7
    if template.find(INTERNAL_7_PLACEHOLDER) < 0:
        raise Exception('Internal 7 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_7_PLACEHOLDER, internal_7.encode('latin1', errors='replace'))

    # patch internal 8
    if template.find(INTERNAL_8_PLACEHOLDER) < 0:
        raise Exception('Internal 8 placeholder missing in EZPL file')

    template = template.replace(INTERNAL_8_PLACEHOLDER, internal_8.encode('latin1', errors='replace'))

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

    parser.add_argument('internal_1')
    parser.add_argument('internal_2')
    parser.add_argument('internal_3')
    parser.add_argument('internal_4')
    parser.add_argument('internal_5')
    parser.add_argument('internal_6')
    parser.add_argument('internal_7')
    parser.add_argument('internal_8')
    parser.add_argument('-c', '--copies', type=int, default=1)
    parser.add_argument('-s', '--stdout', action='store_true')

    args = parser.parse_args()

    assert args.copies > 0

    print_internal2_label(args.internal_1, args.internal_2, args.internal_3, args.internal_4, args.internal_5, args.internal_6, args.internal_7, args.internal_8, args.copies, args.stdout)


if __name__ == '__main__':
    main()
