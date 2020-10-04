// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
#include "../drivers/ps_2_ctlr.h"
#include "../drivers/keyboard.h"
#include "../mylibc/mylibc.h"

void main(void) {
    int r;
    unsigned char st;
    unsigned char resp;

    clear_screen();
    print_at("Edsger Dijkstra!\n", 0, 0);

    r = get_ctlr_stat(&st); // Read status register
    print_byteb (st);
    print("\n");

/*    resp = send_cmd (IDENTIFY_KBD); // ID KBD
    print_byteh (resp);
    print("\n");

    resp = rcv_data ();
    print_byteh (resp);
    print("\n");

    resp = rcv_data ();
    print_byteh (resp);
    print("\n");*/

    /*

    * [x] Does this clear the inhibit bit in the status register?
        * No.
    * [x] Does this stop the kbd from sending scan codes?
        * Yes.

    */

    resp = send_cmd (DISABLE_SCANNING); // Disable scanning
    print_byteh (resp);
    print("\n");

/*    r = get_ctlr_stat(&st); // Read status register
    print_byteb (st);
    print("\n");*/

    resp = send_cmd (GET_SET_SCAN_CODE_SET);
    print_byteh (resp);
    print("\n");

    resp = send_cmd (GET_SCAN_CODE_SET);
    print_byteh (resp);
    print("\n");

    resp = rcv_data ();
    print_byteh (resp);
    print("\n");

    return;
}