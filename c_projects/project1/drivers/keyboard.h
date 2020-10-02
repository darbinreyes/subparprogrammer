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

* Identifier naming convention
  * Identifiers with a format like "x_or_y", have the meaning that x = 0 and y = 1.

References
===
["8042" PS/2 Controller](https://wiki.osdev.org/%228042%22_PS/2_Controller).
[PS/2 Keyboard](https://wiki.osdev.org/Keyboard_Controller)
[8042.TXT](http://bochs.sourceforge.net/techspec/8042.TXT)
[XT, AT, and PS/2 I/O port addresses](http://bochs.sourceforge.net/techspec/PORTS.LST)
[]()


*/
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

/*

I/O ports used for communication with the PS/2 controller.


*/
#define IO_PORT_PS_2_CTLR_DATA          (0x60) // CTLR = ConTroLleR.
#define IO_PORT_PS_2_CTLR_STAT_REGISTER (0x64)
#define IO_PORT_PS_2_CTLR_CMD_REGISTER  (0x64)

/*

#defines that are useful for testing values read from P/S 2 controller status register.


#define IBUF_IS_FULL (1)
#define IBUF_IS_EMPTY (0)
#define OBUF_IS_FULL (1)
#define OBUF_IS_EMPTY (0)
*/
#define BUF_IS_EMPTY (0)
#define BUF_IS_FULL (1)


/*

Commands that can be sent to a PS/2 keyboard device.

*/
#define DISABLE_KBD_CMD (0xF5)
#define IDENTIFY_DEVICE_CMD (0xF2)

typedef
struct _ps2_ctrl_stat_t {
/*

PS/2 controller status register bit definitions.

*/
unsigned char obuf_is_full:1;
unsigned char ibuf_is_full:1;
unsigned char sys_fw_post_passed:1;
unsigned char ibuf_dev_or_ctlr:1;
unsigned char rsvd:2;
unsigned char time_out_err:1;
unsigned char parity_err:1;
} ps2_ctrl_stat_t;


    resp = send_kbd_cmd (0xF5); // Disable scanning
    print_byteb (resp);

    print("\n resp = ");
    resp = send_kbd_cmd (0xF2); // ID KBD

int PS_2_controller_get_status_register(unsigned char *ctlr_stat);
unsigned char send_disable_kbd_cmd (void);
unsigned char send_kbd_cmd (unsigned char cmd);
unsigned char receive_kbd_byte (void);
#endif