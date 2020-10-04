/*

INCREMENTAL GOAL:
[] short get_scn_code(void);
[] char getch(void);
[] char *prompt_user_for_str(char *prompt);
[] With interrupts.

*/


#include "../kernel/low_level.h"
#include "../mylibc/mylibc.h"
#include "ps_2_ctlr.h"
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


*/
unsigned char send_cmd (unsigned char cmd) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // SEND.
    // Send the KBD a disable command (Stop sending scan codes/ignore the user).

    timeout_counter = 1000000;
    r = rcv_ctlr_stat(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT1) == 1 ) ) {
        r = rcv_ctlr_stat(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT1) == 1 )) {
        return 2;
    }

    port_byte_out (IO_PS2_CTLR_DATA, cmd); // Disable KBD command.


    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = rcv_ctlr_stat(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == 0 ) ) {
        r = rcv_ctlr_stat(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 3;
    }

    if (( (st_reg & BIT0) == 0 )) {
        return 4;
    }

    resp = port_byte_in (IO_PS2_CTLR_DATA);

    return resp;

}

/*



*/
unsigned char rcv_data (void) {
    unsigned char resp;
    unsigned char st_reg;
    int timeout_counter;
    int r;

    // RECEIVE.
    // Wait from ACK response from KBD.

    timeout_counter = 1000000;
    r = rcv_ctlr_stat(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == 0 ) ) {
        r = rcv_ctlr_stat(&st_reg);
        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (st_reg & BIT0) == 0 )) {
        return 2;
    }

    resp = port_byte_in (IO_PS2_CTLR_DATA);

    return resp;

}