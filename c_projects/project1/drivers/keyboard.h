#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "../mylibc/mylibc.h"

/*

I/O port addresses used for communication with the PS/2 controller.

*/
#define IO_PS2_CTLR_DATA          (0x60) // CTLR = ConTroLleR.
#define IO_PS2_CTLR_STAT_REGISTER (0x64)
#define IO_PS2_CTLR_CMD_REGISTER  (0x64)

/*

Commands that can be sent to a PS/2 device (e.g. keyboard). This driver assumes keyboard).

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
unsigned char send_kbd_cmd (unsigned char cmd);
unsigned char receive_kbd_byte (void);
#endif