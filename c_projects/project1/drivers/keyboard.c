/*

    GOAL: A PS/2 keyboard driver that allows you to get keyboard input from the
    use.

*/


#include "../kernel/low_level.h"
#include "../mylibc/mylibc.h"

#define PS_2_CNTLR_DATA_IO_PORT 0x60
#define PS_2_CNTLR_STAT_REGISTER_IO_PORT 0x64
#define PS_2_CNTLR_CMD_REGISTER_IO_PORT 0x64

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

*/
int PS_2_controller_get_status_register(unsigned char *cntlr_stat) {
    // TODO: Use bit packed structure.
    if ()
    unsigned char port_byte_in (unsigned short port);
    return 0;
}