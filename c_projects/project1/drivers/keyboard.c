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


/*

From my notes:

* As an OS dev. you are free to set the key codes as you wish. There are
* commonly used schemes however: 8-bits total per key code, upper 3 bits = KB
* row, lower 5 bits = KB col, KB treated as a grid. Once you define your key
* codes you must ensure that all KB drivers use the same key codes. FYI: your
* key codes can also be used by non-KB devices, like a mouse, in which a right
* click might be reported as “key code 0xF1”. Thus, when your state machine
* receives a complete, possibly multi-byte, scan code, you convert it to your
* single byte key code.

*/

struct _scan_code_set_1_to_ascii {
unsigned char scan_code;
char ascii_code;
};


struct _scan_code_set_1_to_key_code {
unsigned char scan_code;
unsigned char ascii_code;
unsigned char r;
unsigned char c;
};
/* , {0x00, '?', -1, -1} */
struct _scan_code_set_1_to_key_code sc_to_kc_tbl[][] = {
{ {0x01, '?', 0, 0}, {0x3B, 'X', 0, 1}, {0x3C, 'X', 0, 2}, {0x3D, 'X', 0, 3}, {0x3E, 'X', 0, 4}, {0x3F, 'X', 0, 5}, {0x40, 'X', 0, 6}, {0x41, 'X', 0, 7}, {0x42, 'X', 0, 8}, {0x43, 'X', 0, 9}, {0x44, 'X', 0, 10}, {0x57, 'X', 0, 11}, {0x58, 'X', 0, 12}, {0x00, '?', 0, 13}, {0x00, '?', 0, 14}, {0x00, '?', 0, 15}, {0x00, '?', 0, 16}, {0x00, '?', 0, 17},  {0x00, '?', 0, 18}, {0x00, '?', 0, 19}, {0x00, '?', 0, 20} }, /*[x]*/
{ {0x29, '`', 1, 0}, {0x02, '1', 1, 1}, {0x03, '2', 1, 2}, {0x04, '3', 1, 3}, {0x05, '4', 1, 4}, {0x06, '5', 1, 5}, {0x07, '6', 1, 6}, {0x08, '7', 1, 7}, {0x09, '8', 1, 8}, {0x0A, '9', 1, 9}, {0x0B, '0', 1, 10}, {0x0C, '-', 1, 11}, {0x0D, '=', 1, 12}, {0x0E, '?', 1, 13}, {0x00, '?', 1, 14}, {0x00, '?', 1, 15}, {0x00, '?', 1, 16}, {0x00, '?', 1, 17},  {0x00, '=', 1, 18}, {0x00, '/', 1, 19}, {0x37, '*', 1, 20} }, /*[x]*/
{ {0x0F, '?', 2, 0}, {0x10, 'q', 2, 1}, {0x11, 'w', 2, 2}, {0x12, 'e', 2, 3}, {0x13, 'r', 2, 4}, {0x14, 't', 2, 5}, {0x15, 'y', 2, 6}, {0x16, 'u', 2, 7}, {0x17, 'i', 2, 8}, {0x18, 'o', 2, 9}, {0x19, 'p', 2, 10}, {0x1A, '[', 2, 11}, {0x1B, ']', 2, 12}, {0x2B,'\\', 2, 13}, {0x00, '?', 2, 14}, {0x00, '?', 2, 15}, {0x00, '?', 2, 16}, {0x47, '7', 2, 22},  {0x48, '8', 2, 23}, {0x49, '9', 2, 24}, {0x4A, '-', 2, 25} }, /*[x]*/
{ {0x3A, '?', 3, 0}, {0x1E, 'a', 3, 1}, {0x1F, 's', 3, 2}, {0x20, 'd', 3, 3}, {0x21, 'f', 3, 4}, {0x22, 'g', 3, 5}, {0x23, 'h', 3, 6}, {0x24, 'j', 3, 7}, {0x25, 'k', 3, 8}, {0x26, 'l', 3, 9}, {0x27, ';', 3, 10},{0x28, '\'', 3, 11}, {0x1C, '?', 3, 12}, {0x4B, '4', 3, 13}, {0x4C, '5', 3, 14}, {0x4D, '6', 3, 15}, {0x4E, '+', 3, 16} }, /*[x]*/
{ {0x2A, '?', 4, 0}, {0x2C, 'z', 4, 1}, {0x2D, 'x', 4, 2}, {0x2E, 'c', 4, 3}, {0x2F, 'v', 4, 4}, {0x30, 'b', 4, 5}, {0x31, 'n', 4, 6}, {0x32, 'm', 4, 7}, {0x33, ',', 4, 8}, {0x34, '.', 4, 9}, {0x35, '/', 4, 10}, {0x36, '?', 4, 11}, {0x00, '?', 4, 12}, {0x4F, '1', 4, 13}, {0x50, '2', 4, 14}, {0x51, '3', 4, 15}}, /*[]*/
{ {0x1D, '?', 5, 0}, {0x38, '?', 5, 1}, {0x00, '?', 5, 2}, {0x39, ' ', 5, 3}, {0x00, '?', 5, 4}, {0x00, '?', 5, 5}, {0x00, '?' /*RCTRL 0xE0, 0x1D*/, 5, 6}, {0x00, '?'/*CLEFT 0xE0, 0x4B*/, 5, 7}, {0x00, '?'/*CDOWN0 xE0, 0x50*/, 5, 8}, {0x00, '?'/*CRIGHT 0xE0, 0x4D*/, 5, 9}, {0x52, '0', 5, 10}, {0x53, '.', 5, 11}, {0x00, '?'/*NUMENTER 0xE0, 0x1C*/, 5, 12} } /*[x]*/
};

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