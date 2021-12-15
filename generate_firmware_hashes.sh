#!/bin/sh
cd firmwares
for file in *.sha256; do sha256sum -c $file; done
for file in *.bin; do if [ ! -f $file.sha256 ]; then sha256sum $file > $file.sha256; fi done
