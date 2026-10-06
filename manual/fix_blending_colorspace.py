#!/usr/bin/env python3
"""Set the blending color space of all transparency groups to DeviceCMYK.

pdfTeX unconditionally adds a page group with /CS /DeviceRGB to every page
that contains a PNG with alpha channel (and copies the page group of included
PDFs). Ghostscript's CMYK conversion leaves these groups untouched, so print
shops' preflight reports RGB usage and the RIP blends in RGB. After the
Ghostscript CMYK conversion all content is CMYK, so CMYK is the correct
blending space.

Requires pikepdf. Usage (modifies the file in place):
    python3 fix_blending_colorspace.py manual_warp4_print.pdf
"""

import argparse
from pathlib import Path

import pikepdf


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pdf", type=Path)
    args = parser.parse_args()

    pdf = pikepdf.open(args.pdf, allow_overwriting_input=True)
    fixed = 0

    for obj in pdf.objects:
        if isinstance(obj, pikepdf.Stream):
            d = obj.stream_dict
        elif isinstance(obj, pikepdf.Dictionary):
            d = obj
        else:
            continue

        groups = [d] if d.get("/S") == "/Transparency" else []

        # Groups can also be direct objects inside page or form dictionaries.
        group = d.get("/Group")
        if isinstance(group, pikepdf.Dictionary) and not group.is_indirect and group.get("/S") == "/Transparency":
            groups.append(group)

        for g in groups:
            if "/CS" in g and g.CS != "/DeviceCMYK":
                g.CS = pikepdf.Name.DeviceCMYK
                fixed += 1

    pdf.save(args.pdf)
    print(f"{args.pdf}: set {fixed} transparency group(s) to /DeviceCMYK")


if __name__ == "__main__":
    main()
