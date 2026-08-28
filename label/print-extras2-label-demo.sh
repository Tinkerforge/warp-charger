#!/bin/bash

./print-extras2-label.py -s "WARP3 Extras" 0 0 0 432.1 1 0 customer:t_h_100 "Lorem ipsum dolor sit amet consetetur" "sadipscing elitr, sed diam nonumy"
echo ""
./print-extras2-label.py -s "WARP3 Extras" 1 1 1 0.0 0 "SO/5555 Test Customer 123456789" customer:t_h_100 "Lorem ipsum dolor sit amet consetetur" "sadipscing elitr, sed diam nonumy"
