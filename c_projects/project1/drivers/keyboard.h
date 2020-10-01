#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

int PS_2_controller_get_status_register(unsigned char *ctlr_stat);
unsigned char send_disable_kbd_cmd (void);
unsigned char send_kbd_cmd (unsigned char cmd);
unsigned char receive_kbd_byte (void);
#endif