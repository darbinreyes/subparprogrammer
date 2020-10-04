// Print a single character to via direct write to video memory.

#include "../drivers/screen.h"
#include "../drivers/ps_2_ctlr.h"
#include "../drivers/keyboard.h"
#include "../mylibc/mylibc.h"

int main(void) {
    int r;
    unsigned char stat;
    unsigned char b;

    clear_screen();
    print_at("Edsger Dijkstra!\n", 0, 0);

    r = get_ctlr_stat(&stat); // Read status register

    if (r != 0) {
        print("Error 0.\n");
        return 1;
    }

    print_byteb (stat);
    print("\n");

    r = send_byte (DISABLE_SCANNING); // Disable scanning

    if (r != 0) {
        print("Error 1.\n");
        return 1;
    }
    r = rcv_byte (&b);

    if (r != 0) {
        print("Error 2.\n");
        return 1;
    }

    print_byteh (b);
    print("\n");

    return 0;
}