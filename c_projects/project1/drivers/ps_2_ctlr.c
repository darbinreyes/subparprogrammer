#include "../mylibc/mylibc.h"
#include "../kernel/low_level.h"
#include "ps_2_ctlr.h"

#define POLL_COUNT (0x01 << 20)

// TODO: driver start()
// TODO: driver stop()

/*

    Returns the value of the PS/2 controller's status register.

    @retval 1 Arg. NULL.

    @retval 0 Successful. The status has been returned in cntlr_stat.

*/
int get_ctlr_stat(unsigned char *stat) {
    // TODO: Use bit packed structure.
    if (stat == NULL)
        return 1;

    *stat = port_byte_in (IO_PS2_CTLR_STAT_REGISTER);
    return 0;
}

/*

    Send.

*/
int send_byte (unsigned char b) {
    unsigned char stat;
    int timeout_counter = POLL_COUNT;
    int r;

    r = get_ctlr_stat(&stat);

    if (r != 0)
        return 4;

    while (timeout_counter > 0 && ( (stat & BIT1) == 1 ) ) {
        r = get_ctlr_stat(&stat);

        if (r != 0)
            return 4;

        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (stat & BIT1) == 1 )) {
        return 2;
    }

    port_byte_out (IO_PS2_CTLR_DATA, b);

    return 0;
}

/*

    Receive.

*/
int rcv_byte (unsigned char *b) {
    unsigned char stat;
    int timeout_counter = POLL_COUNT;
    int r;

    if (b == NULL)
        return 3;

    r = get_ctlr_stat(&stat);

    if (r != 0)
        return 4;

    while (timeout_counter > 0 && ( (stat & BIT0) == 0 ) ) {
        r = get_ctlr_stat(&stat);

        if (r != 0)
            return 4;

        timeout_counter--;
    }

    if (timeout_counter == 0) {
        return 1;
    }

    if (( (stat & BIT0) == 0 )) {
        return 2;
    }

    *b = port_byte_in (IO_PS2_CTLR_DATA);

    return 0;
}

/*

    Send a byte to the PS/2 controller.

*/
void send_byte_ctlr (unsigned char b) {
    port_byte_out (IO_PS2_CTLR_CMD_REGISTER, b);
}