// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"

void main(void) {
    unsigned char *video_memory = (unsigned char *) 0x000b8000;
    *video_memory = 'D';
    *(video_memory + 1) = 0x0f; // White on black.
    print_ch_at('i', 0, 0, 1);
    print_ch_at('j', 0, 0, 2);
    print_ch_at('k', 0, 0, 3);
    print_ch_at('s', 0, 0, 4);
    print_ch_at('t', 0, 0, 5);
    print_ch_at('r', 0, 0, 6);
    print_ch_at('a', 0, 0, 7);
    print_ch_at(0, 0, 0, 8);
    print_ch_at('X', 0, -1, -1);
    print_ch_at('Y', 0, -1, -1);
    print_ch_at('Z', 0, -1, -1);
    //print_ch_at('j', 0, 0, 2);
    //print_ch_at('k', 0, -1, -1);
    print("Darbin Reyes!");
    return;
}