FC210TP
=======

TMK Firmware for a hand wired Leopold FC210TP numberpad.


Why?
----

For some reason the default layout on this numberpad did not output number pad code.

TMK OneKey
----------

This was built on top of the OneKey firmware: https://github.com/tmk/tmk_keyboard/tree/master/keyboard/onekey

Due to using this as a guide for the ProMicro: https://hackaday.io/project/8282-alpen-clack/log/27475-use-a-pro-micro-in-a-keyboard


Build
-----

Paste these file over the ones found in the OneKey sub directory.

   make

The file `matrix.c` has to match the way your switches are wired.


Flashing
--------

### For windows

Software:

* Arduino: https://www.arduino.cc/en/Main/Software
* Drivers: https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide

Steps:

1. Connect the Pro Micro to USB
2. Point it at the downloaded drivers if it doesn't install automatically
3. Open the device manager in preperation, find the "Ports (COM& LPT)" section and note which deviced are already connected
4. Put the Pro Mirco into bootloader by shorting the pins RST and GND:
   - Use a pair of tweezers
   - Squeeze them to about the right distance
   - Touch RST and GND with the two ends of it
   - Lift one side
   - Put the lifted up side back on the pad
   - Lift the whole tweezer
5. You should notice a new port open in the device manager
6. Use the port number in the `flash.ps1` file
   - In the example there is `-P com4`
   - You need to change all the paths to match your enviroment
7. When executing the flash you should see the Pro Micro light up red, a lot of scrolling text in the console and then a confirmation of the flash shortly after

### For Linux

Follow this guife: http://deskthority.net/workshop-f7/how-to-use-a-pro-micro-as-a-cheap-controller-converter-like-soarer-s-t8448.html
