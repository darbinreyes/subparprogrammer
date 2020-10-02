/*

Misc. Notes
===
* I/O naming convention is relative to the PS/2 device.
  * Output means data flow from PS/2 device to the CPU. (PS/2 device -> CPU).
  * Input means data flow from CPU to the PS/2 device. (PS/2 device <- CPU).

* function naming convention
  * device_name
  * operation_name

* I/O port naming convention
  * device_name
  * port_name e.g. the name of the register or a verb that describes what the I/O port is used for.

* Identifier naming convention (e.g. structure member names, ...)
  * Identifiers with a format like "x_or_y", have the meaning that x = 0 and y = 1.

* PS/2 controller status register values naming convention (e.g. `#define BUF_IS_EMPTY`, ...)
  * A concise name based on the description given in the corresponding reference/datasheet/specification document.
    * Example: The [spec.](http://bochs.sourceforge.net/techspec/8042.TXT) states
    that

>Bit 0  : Output  Buffer Full  - A  0 indicated  that the keyboard controller
>    output buffer  has no  data. A  1 indicated  that the controller has
>    placed  data  into  its  output  buffer  but the system not read the
>    data. When  the system  reads the  output buffer  (I/O addres  60h),
>    this bit will return to a 0.

    * corresponding to the above description, we have the following #defines
      * \#define BUF_IS_EMPTY (0)
      * \#define BUF_IS_FULL (1)

* Remark:
  * Communication with the keyboard actually involves communication with two
  devices and it is important for the programmer to be aware of this
  distinction. The two devices are the PS/2 controller (8042 chip) and the
  Keyboard device itself. Notice that the SMSC 8042 datasheet only lists the commands
  for the controller and not for the keyboard.

* Remark:
  * At the hardware level, the PS/2 controller can be connected to two separate
  PS/2 devices, via the "first and second PS/2 port". In principle any PS/2
  device can be connected to these ports (hence the existence of the "identify
  device command"), however, in the vast majority of use cases, the first port
  is connected to a PS/2 keyboard and the second port is connected to a PS/2
  mouse. Since this is intended to be a PS/2 keyboard driver, the word "keyboard"
  may be used throughout this code, but it should be understood that a different
  kind of PS/2 device other than a keyboard  may be connected to the first and
  second PS/2 port. Whenever the word "device" is used, this code is
  assuming that means a "keyboard device".

References
===
["8042" PS/2 Controller](https://wiki.osdev.org/%228042%22_PS/2_Controller).
[PS/2 Keyboard](https://wiki.osdev.org/Keyboard_Controller)
[8042.TXT - The PS/2 Controller (often called a Keyboard controller](http://bochs.sourceforge.net/techspec/8042.TXT)
[XT, AT, and PS/2 I/O port addresses](http://bochs.sourceforge.net/techspec/PORTS.LST)
[SMS "8042" Datasheet - elegantly concise and consistent with bochs' definitions](http://www.diakom.ru/el/elfirms/datashts/Smsc/42w11.pdf)
[]()
[]()
[]()


*/
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "../mylibc/mylibc.h"

/*

I/O ports used for communication with the PS/2 controller.

===osdev SMSC 8042 datasheet

OUTPUT BUFFER
The output buffer is an 8-bit **read-only register at I/O address hex 60**. The keyboard controller uses the
output buffer to send the scan code received from the keyboard and data bytes required by command to
the system. The output buffer should be read only when the output buffer full bit in the register is 1.

INPUT BUFFER
The input buffer is an 8-bit **write-only register** at I/O address hex 60 **or** 64. Writing to address hex 60
sets a flag that indicates a data write; writing to address hex 64 sets a flag that indicates a command
write. Data written to I/O address hex 60 are sent to the keyboard (unless the keyboard controller is
expecting a data byte) following the controller's input buffer only if the input buffer full bit in the status
register is set to 0.

*/
#define IO_PORT_PS_2_CTLR_DATA          (0x60) // CTLR = ConTroLleR.
#define IO_PORT_PS_2_CTLR_STAT_REGISTER (0x64)
#define IO_PORT_PS_2_CTLR_CMD_REGISTER  (0x64)



/*

Commands that can be sent to a PS/2 device (most likely a keyboard, this driver
assumes keyboard).

*/
#define DISABLE_KBD_CMD (0xF5)
#define IDENTIFY_DEVICE_CMD (0xF2)


/*
    resp = send_kbd_cmd (0xF5); // Disable scanning
    print_byteb (resp);

    print("\n resp = ");
    resp = send_kbd_cmd (0xF2); // ID KBD
*/


int PS_2_controller_get_status_register(unsigned char *ctlr_stat);
unsigned char send_disable_kbd_cmd (void);
unsigned char send_kbd_cmd (unsigned char cmd);
unsigned char receive_kbd_byte (void);
#endif