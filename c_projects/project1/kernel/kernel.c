// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
#include "../drivers/ps_2_ctlr.h"
#include "../drivers/keyboard.h"
#include "../mylibc/mylibc.h"

int main(void) {
    int r;
    unsigned char b;
    unsigned char sc[2];
    char c;
    ps_2_ctrl_stat_t stat;

    clear_screen();
    print_at("Edsger Dijkstra!\n", 0, 0);

    while(1) { // Test getting both 1 byte and 2 byte scan codes using a single function.
        r = get_scan_code2(sc);

        if (r != 0) {
            print("Error 2.\n");
            return 1;
        }

        if (sc[1] != 0x00) {
            print(" 2 byte sc.");
            print("[");
            print_byteh(sc[0]);
            print("]");
            print("[");
            print_byteh(sc[1]);
            print("]\n");
        } else {
            print(" 1 byte sc.");
            print("[");
            print_byteh(sc[0]);
            print("]\n");
        }
    }
    return 0;
}