/*

    GOAL: A PS/2 keyboard driver that allows you to get keyboard input from the
    use.

*/


#include "../kernel/low_level.h"
#include "../mylibc/mylibc.h"
#include "keyboard.h"

/*

    Returns the response to an identify command sent to the PS/2 device
    connected to the first PS/2 controller's port. Most likely, it is
    a keyboard device. The response may consist of 0, 1, or 2 bytes.

*/
int PS_2_controller_port1_get_device_ID (unsigned char *id) {
    return 0;
}

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

/*


*/
unsigned char send_disable_kbd_cmd (void) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // SEND.
    // Send the KBD a disable command (Stop sending scan codes/ignore the user).

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT1) == BUF_IS_FULL ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT1) == BUF_IS_FULL )) {
        return 2;
    }

    port_byte_out (IO_PORT_PS_2_CTLR_DATA, DISABLE_KBD_CMD); // Disable KBD command.


    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == BUF_IS_EMPTY ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    resp = port_byte_in (IO_PORT_PS_2_CTLR_DATA);

    return resp;

}


/*


*/
unsigned char send_kbd_cmd (unsigned char cmd) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // SEND.
    // Send the KBD a disable command (Stop sending scan codes/ignore the user).

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT1) == BUF_IS_FULL ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT1) == BUF_IS_FULL )) {
        return 2;
    }

    port_byte_out (IO_PORT_PS_2_CTLR_DATA, cmd); // Disable KBD command.


    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == BUF_IS_EMPTY ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 3;
    }

    if (( (st_reg & BIT0) == BUF_IS_EMPTY )) {
        return 4;
    }

    resp = port_byte_in (IO_PORT_PS_2_CTLR_DATA);

    return resp;

}

/*



*/
unsigned char receive_kbd_byte (void) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = PS_2_controller_get_status_register(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == BUF_IS_EMPTY ) ) {
        r = PS_2_controller_get_status_register(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT0) == BUF_IS_EMPTY )) {
        return 2;
    }

    resp = port_byte_in (IO_PORT_PS_2_CTLR_DATA);

    return resp;

}