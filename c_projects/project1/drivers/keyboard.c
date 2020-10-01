/*

    GOAL: A PS/2 keyboard driver that allows you to get keyboard input from the
    use.

*/


#include "../kernel/low_level.h"
#include "../mylibc/mylibc.h"

#define IO_PORT_PS_2_CTLR_DATA          0x60 // CTLR = ConTroLleR.
#define IO_PORT_PS_2_CTLR_STAT_REGISTER 0x64
#define IO_PORT_PS_2_CTLR_CMD_REGISTER  0x64

/*

    Returns the response to an identify command sent to the PS/2 device
    connected to the first PS/2 controller's port. Most likely, it is
    a keyboard device. The response may consist of 0, 1, or 2 bytes.

*/
int PS_2_controller_port1_get_device_ID (unsigned char *id) {
    return 0;
}


typedef
struct _ps2_ctrl_stat_t {
/*

    PS/2 controller status register bit definitions.

    [Documentation](https://wiki.osdev.org/%228042%22_PS/2_Controller#Status_Register).

    * I/O naming convention is relative to the PS/2 device.
      * Output means data flow from PS/2 device to the CPU. (PS/2 device -> CPU).
      * Input means data flow from CPU to the PS/2 device. (PS/2 device <- CPU).

*/
unsigned char obuf_is_full:1;
unsigned char ibuf_is_full:1;
unsigned char sys_fw_post_passed:1;
unsigned char ibuf_dev_or_ctlr:1;
unsigned char rsvd:2;
unsigned char time_out_err:1;
unsigned char parity_err:1;
} ps2_ctrl_stat_t;


/*

    Returns the value of the PS/2 controller's status register.

    @retval -1 Arg. NULL.

    @retval 0 Successful. The status has been returned in cntlr_stat.

*/
int PS_2_controller_get_status_register(unsigned char *ctlr_stat) {
    // TODO: Use bit packed structure.
    if (ctlr_stat == NULL)
        return -1;

    *ctlr_stat = port_byte_in (IO_PORT_PS_2_CTLR_STAT_REGISTER);
    return 0;
}


#define DISABLE_KBD_CMD (0xF5)
#define IBUF_IS_FULL (1)
#define IBUF_IS_EMPTY (0)
#define OBUF_IS_FULL (1)
#define OBUF_IS_EMPTY (0)
#define IDENTIFY_DEVICE_CMD (0xF2)

unsigned char send_disable_kbd_cmd (void) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // SEND.
    // Send the KBD a disable command (Stop sending scan codes/ignore the user).

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT1) == IBUF_IS_FULL ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT1) == IBUF_IS_FULL )) {
        return 2;
    }

    port_byte_out (IO_PORT_PS_2_CTLR_DATA, DISABLE_KBD_CMD); // Disable KBD command.


    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == OBUF_IS_EMPTY ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    resp = port_byte_in (IO_PORT_PS_2_CTLR_DATA);

    return resp;

}



unsigned char send_kbd_cmd (unsigned char cmd) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // SEND.
    // Send the KBD a disable command (Stop sending scan codes/ignore the user).

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT1) == IBUF_IS_FULL ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT1) == IBUF_IS_FULL )) {
        return 2;
    }

    port_byte_out (IO_PORT_PS_2_CTLR_DATA, cmd); // Disable KBD command.


    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == OBUF_IS_EMPTY ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 3;
    }

    if (( (st_reg & BIT0) == OBUF_IS_EMPTY )) {
        return 4;
    }

    resp = port_byte_in (IO_PORT_PS_2_CTLR_DATA);

    return resp;

}


unsigned char receive_kbd_byte (void) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == OBUF_IS_EMPTY ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT0) == OBUF_IS_EMPTY )) {
        return 2;
    }

    resp = port_byte_in (IO_PORT_PS_2_CTLR_DATA);

    return resp;

}