#include "../mylibc/mylibc.h"
#include "ps_2_ctlr.h"

/*

    Returns the value of the PS/2 controller's status register.

    @retval -1 Arg. NULL.

    @retval 0 Successful. The status has been returned in cntlr_stat.

*/
int rcv_ctlr_stat(unsigned char *ctlr_stat) {
    // TODO: Use bit packed structure.
    if (ctlr_stat == NULL)
        return -1;

    *ctlr_stat = port_byte_in (IO_PS2_CTLR_STAT_REGISTER);
    return 0;
}

