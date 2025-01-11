#!/bin/bash

./print-accessories2-label.py -s "WARP3 Extras" 0 0 0 432.1 1 0 customer:SO/5555 "Lorem ipsum dolor sit amet consetetur" "sadipscing elitr, sed diam nonumy"
echo ""
./print-accessories2-label.py -s "WARP3 Extras" 1 1 1 0.0 0 SO/5555 customer:SO/5555 "Lorem ipsum dolor sit amet consetetur" "sadipscing elitr, sed diam nonumy"
