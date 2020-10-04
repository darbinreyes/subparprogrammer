#include "../mylibc/mylibc.h"
#include "../kernel/low_level.h"
#include "ps_2_ctlr.h"

// TODO: driver start()
// TODO: driver stop()

/*

    Returns the value of the PS/2 controller's status register.

    @retval -1 Arg. NULL.

    @retval 0 Successful. The status has been returned in cntlr_stat.

*/
int get_ctlr_stat(unsigned char *ctlr_stat) {
    // TODO: Use bit packed structure.
    if (ctlr_stat == NULL)
        return -1;

    *ctlr_stat = port_byte_in (IO_PS2_CTLR_STAT_REGISTER);
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
    r = get_ctlr_stat(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT1) == 1 ) ) {
        r = get_ctlr_stat(&st_reg);
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
    r = get_ctlr_stat(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == 0 ) ) {
        r = get_ctlr_stat(&st_reg);
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
    r = get_ctlr_stat(&st_reg);

    while (timeout_counter > 0 && ( (st_reg & BIT0) == 0 ) ) {
        r = get_ctlr_stat(&st_reg);
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