FC210TP
=======

TMK Firmware for a hand wired Leopold FC210TP numberpad.


Why?
----

For some reason the default layout on this numberpad did not output number pad code.

Planck TMK
----------

This was built on top of the Planck firmware made by Jack Humbert.


Build
-----

Paste these file over the ones found in the Planck sub directory.

   make

The file `matrix.c` has to match the way your switches are wired.


Flashing
--------

### For windows

Software:

* Drivers: https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
* Loader: http://xloader.russemotto.com/
* Putty: http://selfmod.net/using-usb-to-serial-converter-in-windows-7-with-putty/

Steps:

1) Connect the Pro Micro to USB
2) Point it at the downloaded drivers if it doesn't install automatically
3) Open the device manager to see what COM port it connected on - e.g. COM7
4) Open a putty serial connection at that port at 1200
5) When you close this connection, the Pro Micro will go into bootloader
6) Check in the device manager, the Pro Micro will be connected on a different port for a few seconds - e.g. COM8
7) Add this line to `devices.txt` in the XLoader folder: `Leonardo(32U4);atmega32U4;avr109;57600`
8) Set up the XLoader with the bootloader port - e.g. COM8
9) Repeat the putty connection
10) When you close the connection, be ready to click 'Upload' on XLoader


### For Linux

Follow this guife: http://deskthority.net/workshop-f7/how-to-use-a-pro-micro-as-a-cheap-controller-converter-like-soarer-s-t8448.html