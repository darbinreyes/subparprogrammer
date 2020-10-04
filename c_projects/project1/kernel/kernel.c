// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
#include "../drivers/ps_2_ctlr.h"
#include "../drivers/keyboard.h"
#include "../mylibc/mylibc.h"

void main(void) {
    int r;
    unsigned char st;
    unsigned char resp;


    //print_ch_at('i', 0, 0, 1);
    //print_ch_at('k', 0, -1, -1);
    //print("Darbin Reyes!");
    //print_at("Edsger Dijkstra!", 24, 73);
    //clear_screen();

    clear_screen();
    print_at("Edsger Dijkstra!\n", 0, 0);

    r = rcv_ctlr_stat(&st);
    print_byteb (st);
    print("\n");

    // print("\n resp = ");
    // resp = send_cmd (0xF5); // Disable scanning
    // print_byteb (resp);

    resp = send_cmd (IDENTIFY_KBD); // ID KBD
    print_byteh (resp);
    print("\n");

    resp = rcv_data ();
    print_byteh (resp);
    print("\n");

    resp = rcv_data ();
    print_byteh (resp);

    return;
}