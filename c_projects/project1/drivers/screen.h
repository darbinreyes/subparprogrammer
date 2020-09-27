#ifndef __SCREEN_H__ // Add a standard include guard.
#define __SCREEN_H__


#define VIDEO_ADDRESS 0xB8000
#define MAX_ROWS 25
#define MAX_COLS 80

/* Character attribute byte for color scheme. */
#define CHAR_ATTR_WHITE_ON_BLACK 0x0F

/* screen device I/O ports */
#define REG_SCREEN_CTRL_IO_PORT 0x3D4
#define REG_SCREEN_DATA_IO_PORT 0x3D5

/*

CRTC Registers - Cursor position control.


Cursor Location High 0xE = 0d14.
Cursor Location Low 0xF = 0d15.

*/

#define CURSOR_LOCATION_HIGH_BYTE 0x0E
#define CURSOR_LOCATION_LOW_BYTE 0x0F

/*

The author does not go into detail about where this numbers came from. The notes
below are a summary of my search for legitimate/accurate documentation.

Relevant documentation.
===

The screen device we use here is called the "IBM VGA". This is a screen device
from the late 1990's. The low level interface to this device involves:

1. Over 300 internal registers.
2. MMIO, the device in its default mode responds to
host memory access in a range starting at address 0xB8000 up tp 0xBFFFF.
3. About a dozen I/O ports are used to access registers in #1.

Links:

[A concise intro. to the IBM VGA device](https://wiki.osdev.org/VGA_Hardware)
[Deep dive, every possible detail you might want to know. Well written.](http://www.osdever.net/FreeVGA/home.htm#vga)
[Further reading, (1998!) home page of above link](http://www.osdever.net/FreeVGA/home.htm)
[Manipulating the Text-mode Cursor](http://www.osdever.net/FreeVGA/vga/textcur.htm)
[Cathode Ray Tube Controller (CRTC) Registers, in here we find the registers that allow us to control text mode cursor position](http://www.osdever.net/FreeVGA/vga/crtcreg.htm)

Remark: In 1998, engineers hard to reference this immense documentation on
physical paper tomes, flipping back and forth to cope with inter-chapter
references. Sounds painful.

Remark: In order to control 300+ internal VGA registers with roughly 12 I/O
ports a register indexing scheme is used. For example, I/O port number will be
used to provide an index, which selects a particular register, then a second I/O
port is used to read/write a single byte of data to the index-selected register.
This scheme is used with the 0x3D4-0x3D5 I/O ports.

*/

#endif