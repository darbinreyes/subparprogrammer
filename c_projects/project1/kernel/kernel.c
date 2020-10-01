// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
#include "../drivers/keyboard.h"
#include "../mylibc/mylibc.h"

void main(void) {
    int r;
    unsigned char st;

    // unsigned char *video_memory = (unsigned char *) 0x000b8000;
    // *video_memory = 'D';
    // *(video_memory + 1) = 0x0f; // White on black.
    // print_ch_at('i', 0, 0, 1);
    // print_ch_at('j', 0, 0, 2);
    // print_ch_at('k', 0, 0, 3);
    // print_ch_at('s', 0, 0, 4);
    // print_ch_at('t', 0, 0, 5);
    // print_ch_at('r', 0, 0, 6);
    // print_ch_at('a', 0, 0, 7);
    // print_ch_at(0, 0, 0, 8);
    // print_ch_at('X', 0, -1, -1);
    // print_ch_at('Y', 0, -1, -1);
    // print_ch_at('Z', 0, -1, -1);
    // print_ch_at('\n', 0, -1, -1);
    // print_ch_at('\n', 0, -1, -1);
    //print_ch_at('j', 0, 0, 2);
    //print_ch_at('k', 0, -1, -1);
    //print("Darbin Reyes!");
    //clear_screen();
    //print_at("Edsger Dijkstra!", 24, 73);

    clear_screen();
    print_at("Edsger Dijkstra!", 0, 0);
    //while (1) {
        r = PS_2_controller_get_status_register(&st);
        print_byteb (st);
    //}

    // if (r == -1) {
    //     print(" Arg. NULL.");
    // } else if (r == 0) {
    //     print(" Success. ");
    //     // if (st)
    //     //     print(" POST PASSED!");
    //     // else
    //     //     print(" POST FAILED! WTF! ");
    //     print_byteb (st);
    // } else {
    //     print(" WTF?");
    // }
    return;
}