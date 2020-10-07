// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
#include "../drivers/ps_2_ctlr.h"
#include "../drivers/keyboard.h"
#include "../mylibc/mylibc.h"

int main(void) {
    int r;
    unsigned char stat;
    unsigned char b;
    unsigned char sc;
    char c;

    clear_screen();
    print_at("Edsger Dijkstra!\n", 0, 0);

    r = get_ctlr_stat(&stat); // Read status register

    if (r != 0) {
        print("Error 0.\n");
        return 1;
    }

    print_byteb (stat);
    print("\n");

    // r = get_scan_code(&sc);

    // if (r != 0) {
    //     print("Error 1.\n");
    //     return 1;
    // }

    // print_byteh(sc);
    // print("\n");

    while(1) {
        r = get_scan_code(&sc);

        if (r != 0) {
            print("Error 2.\n");
            return 1;
        }

        if ( (sc & BIT7) == 0) { // Only print scan codes indicating press (not released).
            // print("[");
            // print_byteh(sc);
            // print("]");
            c = scan_code_to_ascii (sc);

            print_ch_at(c, 0, -1, -1);
            //print("\n");
        } else {
            // print("[");
            // print_byteh(sc);
            // print("]");
        }
    }

    return 0;
}