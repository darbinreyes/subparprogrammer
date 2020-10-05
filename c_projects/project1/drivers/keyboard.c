/*

INCREMENTAL GOAL:
[] short get_scn_code(void);
[] char getch(void);
[] char *prompt_user_for_str(char *prompt);
[] With interrupts.

*/

#include "../mylibc/mylibc.h"
#include "ps_2_ctlr.h"
#include "keyboard.h"

// TODO: driver start()
// TODO: driver stop()

char scan_code_to_ascii (unsigned char sc) {
    if (sc == 0x1E || sc == 0x9E)
        return 'A';
    else
        return 'X';
}
// TODO: scan code -> grid key code -> ASCII code // How to distinguish 'a' vs. 'A'?
int get_scan_code(unsigned char *sc) {
    unsigned char stat;
    int r;
    unsigned char b;

    r = get_ctlr_stat(&stat);

    if (r != 0)
        return 1;

    while ( ( (stat & BIT0) == 0 ) ) { // Loop until a scan code is received.
        r = get_ctlr_stat(&stat);

        if (r != 0)
            return 1;
    }

    r = rcv_byte (&b);

    if (r != 0)
        return 2;

    *sc = b;

    return 0;
}