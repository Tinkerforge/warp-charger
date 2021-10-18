Build instructions
------------------

- Install nodejs and npm (left as exercise for the reader)
- Install platformio:
  pip install -U platformio

- Create a soft link or clone the esp32-brick git:
  ln -s ../../esp32-brick .
  or
  git clone https://github.com/Tinkerforge/esp32-brick

- Run "platformio run -e warp" to build the firmware. The firmware can be found in .pio/build/warp/firmware.bin
- Alternatively run "platformio run -e warp -t upload -t monitor" to build and upload the firmware to an ESP32 and start the serial monitor
