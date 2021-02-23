EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "DC Protect"
Date "2021-02-23"
Rev "1.0"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2020, T.Schneidermann <tim@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 500  7750 0    40   ~ 0
Copyright Tinkerforge GmbH 2021.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
$Comp
L tinkerforge:DC-Protect U1
U 1 1 603506D1
P 6700 3600
F 0 "U1" H 6650 4250 50  0000 L CNN
F 1 "DC-Protect" V 6950 3350 50  0000 L CNN
F 2 "kicad-libraries:DC-Protect" H 6900 4050 50  0001 C CNN
F 3 "" H 6900 4050 50  0001 C CNN
	1    6700 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 3550 6300 3550
Wire Wire Line
	6300 3700 5750 3700
Wire Wire Line
	6300 3250 5450 3250
Wire Wire Line
	5450 3250 5450 3350
Wire Wire Line
	5450 3350 4500 3350
Wire Wire Line
	4500 3250 5200 3250
Wire Wire Line
	5200 3250 5200 3100
Wire Wire Line
	5200 3100 6300 3100
Wire Wire Line
	4500 3850 5200 3850
Wire Wire Line
	5200 3850 5200 4000
Wire Wire Line
	5200 4000 6300 4000
Wire Wire Line
	6300 3850 5450 3850
Wire Wire Line
	5450 3850 5450 3750
Wire Wire Line
	5450 3750 4500 3750
Wire Wire Line
	5750 3650 5750 3700
Wire Wire Line
	4500 3650 5750 3650
Wire Wire Line
	4500 3450 5750 3450
Wire Wire Line
	5750 3450 5750 3400
Wire Wire Line
	5750 3400 6300 3400
$Comp
L tinkerforge:GND #PWR0101
U 1 1 603516D0
P 5750 3700
F 0 "#PWR0101" H 5750 3450 50  0001 C CNN
F 1 "GND" H 5900 3600 50  0000 C CNN
F 2 "" H 5750 3700 50  0000 C CNN
F 3 "" H 5750 3700 50  0000 C CNN
	1    5750 3700
	1    0    0    -1  
$EndComp
Connection ~ 5750 3700
$Comp
L tinkerforge:CON-SENSOR2-BLANK P1
U 1 1 60362595
P 4150 3550
F 0 "P1" H 4067 4097 60  0000 C CNN
F 1 "CON-SENSOR2-BLANK" H 4067 3991 60  0000 C CNN
F 2 "kicad-libraries:CON-SENSOR2_180" H 4250 3400 60  0001 C CNN
F 3 "" H 4250 3400 60  0000 C CNN
	1    4150 3550
	-1   0    0    -1  
$EndComp
$Comp
L tinkerforge:GND #PWR0102
U 1 1 60362E67
P 4150 4000
F 0 "#PWR0102" H 4150 3750 50  0001 C CNN
F 1 "GND" H 4300 3900 50  0000 C CNN
F 2 "" H 4150 4000 50  0000 C CNN
F 3 "" H 4150 4000 50  0000 C CNN
	1    4150 4000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
