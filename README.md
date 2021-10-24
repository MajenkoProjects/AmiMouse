AmiMouse
========

A small conversion sketch to allow a PS/2 mouse to be used on
an Amiga. This reads the mouse data from PS/2 then outputs the
rotary encoder pulse train for the corresponding movement.

Tested on an A500 with an Arduino Nano.

Required Libraries
------------------

* [PS2-Mouse-Arduino](https://github.com/kristopher/PS2-Mouse-Arduino)

Connections
-----------

    Arduino     PS/2      Amiga 9 pin D     Function
    D5          Pin 1                       PS/2 Data
    D6          Pin 5                       PS/2 Clock
    D7                    Pin 2             Horizontal 1
    D8                    Pin 4             Horizontal 2
    D9                    Pin 3             Vertical 1
    D10                   Pin 1             Vertical 2
    D11                   Pin 6             LMB
    D12                   Pin 9             RMB
    D13                   Pin 5             MMB
    5V          Pin 4     Pin 7             Power
    GND         Pin 3     Pin 8             Ground


