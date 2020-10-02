// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
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
    print_at("Edsger Dijkstra!", 0, 0);

    r = PS_2_controller_get_status_register(&st);
    print_byteb (st);

    print("\n resp = ");
    resp = send_kbd_cmd (0xF5); // Disable scanning
    print_byteb (resp);

    print("\n resp = ");
    resp = send_kbd_cmd (0xF2); // ID KBD
    print_byteb (resp);

    print("\n resp = ");
    resp = receive_kbd_byte ();
    print_byteb (resp);

    print("\n resp = ");
    resp = receive_kbd_byte ();
    print_byteb (resp);

    return;
}