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

    resp = send_cmd (DISABLE_SCANNING); // Disable scanning
    print_byteh (resp);
    print("\n");

    return;
}