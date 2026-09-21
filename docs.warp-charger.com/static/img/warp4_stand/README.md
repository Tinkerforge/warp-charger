# WARP4 stand illustrations

Photographs and `stand_drawings.pdf` are copied from `manual_stand/img4/`.
The PDF is the corrected vector drawing used by the printed manual. The website
uses SVG exports of its pages; the PDF is also available for download.

To refresh the drawings, run from `docs.warp-charger.com`:

```sh
cp ../manual_stand/img4/stand_drawings.pdf static/img/warp4_stand/stand_drawings.pdf
pdftocairo -svg -f 1 -l 1 static/img/warp4_stand/stand_drawings.pdf static/img/warp4_stand/foundation.svg
pdftocairo -svg -f 2 -l 2 static/img/warp4_stand/stand_drawings.pdf static/img/warp4_stand/dimensions.svg
```
