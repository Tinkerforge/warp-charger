EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Grounding Ring"
Date "2021-02-19"
Rev "1.0"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2020, T.Schneidermann <tim@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 500  7750 0    40   ~ 0
Copyright Tinkerforge GmbH 2020.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
$Comp
L tinkerforge:CONN_01X02 P1
U 1 1 6030AB74
P 7300 3500
F 0 "P1" H 7378 3541 50  0000 L CNN
F 1 "CONN_01X02" H 7378 3450 50  0000 L CNN
F 2 "kicad-libraries:JST-PH-2-SMD" H 7300 3500 50  0001 C CNN
F 3 "B2B-PH-SM4-TBT(LF)(SN)" H 7300 3500 50  0001 C CNN
	1    7300 3500
	1    0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR0101
U 1 1 6030AFF8
P 6700 3700
F 0 "#PWR0101" H 6700 3450 50  0001 C CNN
F 1 "GND" H 6705 3527 50  0000 C CNN
F 2 "" H 6700 3700 50  0000 C CNN
F 3 "" H 6700 3700 50  0000 C CNN
	1    6700 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3450 6700 3550
Wire Wire Line
	6700 3450 7100 3450
Wire Wire Line
	7100 3550 6700 3550
Connection ~ 6700 3550
Wire Wire Line
	6700 3550 6700 3700
$EndSCHEMATC
