/* ***********************************************************
 * This file was automatically generated on 2021-02-08.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#include "display_names.h"

#ifdef TF_IMPLEMENT_GET_DEVICE_DISPLAY_NAME
const char *tf_get_device_display_name(uint16_t device_id) {
    switch(device_id) {
        case  111: return "HAT Brick";
        case  112: return "HAT Zero Brick";
        case 2130: return "Accelerometer Bricklet 2.0";
        case  297: return "Air Quality Bricklet";
        case 2131: return "Ambient Light Bricklet 3.0";
        case  295: return "Analog In Bricklet 3.0";
        case 2115: return "Analog Out Bricklet 3.0";
        case 2117: return "Barometer Bricklet 2.0";
        case 2107: return "CAN Bricklet 2.0";
        case 2147: return "CO2 Bricklet 2.0";
        case 2128: return "Color Bricklet 2.0";
        case 2153: return "Compass Bricklet";
        case 2125: return "Distance IR Bricklet 2.0";
        case  299: return "Distance US Bricklet 2.0";
        case  285: return "DMX Bricklet";
        case 2119: return "Dual Button Bricklet 2.0";
        case 2146: return "E-Paper 296x128 Bricklet";
        case 2152: return "Energy Monitor Bricklet";
        case  276: return "GPS Bricklet 2.0";
        case 2132: return "Hall Effect Bricklet 2.0";
        case  283: return "Humidity Bricklet 2.0";
        case 2161: return "IMU Bricklet 3.0";
        case 2116: return "Industrial Analog Out Bricklet 2.0";
        case  293: return "Industrial Counter Bricklet";
        case 2100: return "Industrial Digital In 4 Bricklet 2.0";
        case 2124: return "Industrial Digital Out 4 Bricklet 2.0";
        case 2120: return "Industrial Dual 0-20mA Bricklet 2.0";
        case 2162: return "Industrial Dual AC Relay Bricklet";
        case 2121: return "Industrial Dual Analog In Bricklet 2.0";
        case  284: return "Industrial Dual Relay Bricklet";
        case 2102: return "Industrial Quad Relay Bricklet 2.0";
        case 2114: return "IO-16 Bricklet 2.0";
        case 2111: return "IO-4 Bricklet 2.0";
        case 2122: return "Isolator Bricklet";
        case 2138: return "Joystick Bricklet 2.0";
        case 2144: return "Laser Range Finder Bricklet 2.0";
        case  298: return "LCD 128x64 Bricklet";
        case 2103: return "LED Strip Bricklet 2.0";
        case 2139: return "Linear Poti Bricklet 2.0";
        case 2104: return "Load Cell Bricklet 2.0";
        case  292: return "Motion Detector Bricklet 2.0";
        case  267: return "Motorized Linear Poti Bricklet";
        case 2129: return "Multi Touch Bricklet 2.0";
        case  286: return "NFC Bricklet";
        case 2112: return "OLED 128x64 Bricklet 2.0";
        case 2123: return "One Wire Bricklet";
        case  288: return "Outdoor Weather Bricklet";
        case 2110: return "Particulate Matter Bricklet";
        case 2156: return "Performance DC Bricklet";
        case 2145: return "Piezo Speaker Bricklet 2.0";
        case 2101: return "PTC Bricklet 2.0";
        case 2106: return "Real-Time Clock Bricklet 2.0";
        case  289: return "Remote Switch Bricklet 2.0";
        case  282: return "RGB LED Button Bricklet";
        case  272: return "RGB LED Matrix Bricklet";
        case 2127: return "RGB LED Bricklet 2.0";
        case  294: return "Rotary Encoder Bricklet 2.0";
        case 2140: return "Rotary Poti Bricklet 2.0";
        case 2108: return "RS232 Bricklet 2.0";
        case  277: return "RS485 Bricklet";
        case 2137: return "Segment Display 4x7 Bricklet 2.0";
        case 2157: return "Servo Bricklet 2.0";
        case  296: return "Solid State Relay Bricklet 2.0";
        case  290: return "Sound Pressure Level Bricklet";
        case  291: return "Temperature IR Bricklet 2.0";
        case 2113: return "Temperature Bricklet 2.0";
        case  278: return "Thermal Imaging Bricklet";
        case 2109: return "Thermocouple Bricklet 2.0";
        case 2118: return "UV Light Bricklet 2.0";
        case 2105: return "Voltage/Current Bricklet 2.0";
        case  279: return "XMC1400 Breakout Bricklet";
          default: return "unknown device";
    }
}
#endif