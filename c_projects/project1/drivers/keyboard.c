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


struct _sctokc_t {
unsigned char scan_code;
unsigned char ascii_code;
unsigned char r;
unsigned char c;
};
/* , {0x00, '?', -1, -1} */
struct _sctokc_t sc_to_kc_tbl[][21] = { // State == pressed.
 {  {0x01, '?'/*ESC*/, 0, 0},   {0x3B, 'X'/*F1*/, 0, 1},   {0x3C, 'X'/*F2*/, 0, 2},         {0x3D, 'X'/*F3*/, 0, 3}, {0x3E, 'X'/*F4*/, 0, 4},         {0x3F, 'X'/*F5*/, 0, 5},           {0x40, 'X'/*F6*/, 0, 6},           {0x41, 'X'/*F7*/, 0, 7},            {0x42, 'X'/*F8*/, 0, 8},           {0x43, 'X'/*F9*/, 0, 9},          {0x44, 'X'/*F10*/, 0, 10}, {0x57, 'X'/*F11*/, 0, 11},   {0x58, 'X'/*F12*/, 0, 12},              {0x00, '?'/*EJECT No-Sc*/, 0, 13}, {0x00, '?'/*F13 No-Sc*/, 0, 14},        {0x00, '?'/*F14 No-Sc*/, 0, 15},        {0x00, '?'/*F15 No-Sc*/, 0, 16},         {0x00, '?'/*F16 No-Sc*/, 0, 17},       {0x00, '?'/*F17 No-Sc*/, 0, 18},   {0x00, '?'/*F18 No-Sc*/, 0, 19},              {0x00, '?'/*F19 No-Sc*/, 0, 20} }, /*[x][x]*/
 {  {0x29, '`', 1, 0},          {0x02, '1', 1, 1},         {0x03, '2', 1, 2},               {0x04, '3', 1, 3},       {0x05, '4', 1, 4},               {0x06, '5', 1, 5},                 {0x07, '6', 1, 6},                 {0x08, '7', 1, 7},                  {0x09, '8', 1, 8},                 {0x0A, '9', 1, 9},                {0x0B, '0', 1, 10},        {0x0C, '-', 1, 11},          {0x0D, '=', 1, 12},                     {0x0E, '?'/*DEL*/, 1, 13},         {0x00, '?'/*Fn No-Sc*/, 1, 14},         {0xE0/*0x47*/, '?'/*HOME*/, 1, 15},     {0xE0/*0x49*/, '?'/*PGUP*/, 1, 16},      {0x00, '?'/*NUMCLEAR  No-Sc*/, 1, 17}, {0x00, '='/*NUMEQ No-Sc*/, 1, 18}, {0xE0/*0x35*/, '/'/*NUMSLASH*/, 1, 19},       {0x37, '*', 1, 20} }, /*[x][x]*/
 {  {0x0F, '?'/*TAB*/, 2, 0},   {0x10, 'q', 2, 1},         {0x11, 'w', 2, 2},               {0x12, 'e', 2, 3},       {0x13, 'r', 2, 4},               {0x14, 't', 2, 5},                 {0x15, 'y', 2, 6},                 {0x16, 'u', 2, 7},                  {0x17, 'i', 2, 8},                 {0x18, 'o', 2, 9},                {0x19, 'p', 2, 10},        {0x1A, '[', 2, 11},          {0x1B, ']', 2, 12},                     {0x2B,'\\', 2, 13},                {0xE0/*0x53*/, '?'/*DEL*/, 2, 14},      {0xE0/*0x4F*/, '?'/*END*/, 2, 15},      {0xE0/*0x51*/, '?'/*PGDWN*/, 2, 16},     {0x47, '7', 2, 17},                    {0x48, '8', 2, 18},                {0x49, '9', 2, 19},                           {0x4A, '-', 2, 20} }, /*[x][x]*/
 {  {0x3A, '?'/*CAPL*/, 3, 0},  {0x1E, 'a', 3, 1},         {0x1F, 's', 3, 2},               {0x20, 'd', 3, 3},       {0x21, 'f', 3, 4},               {0x22, 'g', 3, 5},                 {0x23, 'h', 3, 6},                 {0x24, 'j', 3, 7},                  {0x25, 'k', 3, 8},                 {0x26, 'l', 3, 9},                {0x27, ';', 3, 10},        {0x28, '\'', 3, 11},         {0x1C, '?'/*ENTR*/, 3, 12},             {0x4B, '4', 3, 13},                {0x4C, '5', 3, 14},                     {0x4D, '6', 3, 15},                     {0x4E, '+', 3, 16} }, /*[x][x]*/
 {  {0x2A, '?'/*LSHFT*/, 4, 0}, {0x2C, 'z', 4, 1},         {0x2D, 'x', 4, 2},               {0x2E, 'c', 4, 3},       {0x2F, 'v', 4, 4},               {0x30, 'b', 4, 5},                 {0x31, 'n', 4, 6},                 {0x32, 'm', 4, 7},                  {0x33, ',', 4, 8},                 {0x34, '.', 4, 9},                {0x35, '/', 4, 10},        {0x36, '?'/*RSHFT*/, 4, 11}, {0xE0/*0x48*/, '?'/*UP*/, 4, 12},       {0x4F, '1', 4, 13},                {0x50, '2', 4, 14},                     {0x51, '3', 4, 15} }, /*[x][x]*/
 {  {0x1D, '?'/*LCTRL*/, 5, 0}, {0x38, '?'/*LALT*/, 5, 1}, {0x00, '?'/*LCMD No-Sc*/, 5, 2}, {0x39, ' ', 5, 3},       {0x00, '?'/*RCMD No-Sc*/, 5, 4}, {0xE0/*0x38*/, '?'/*RALT*/, 5, 5}, {0xE0/*1D*/, '?' /*RCTRL*/, 5, 6}, {0xE0/*0x4B*/, '?'/*CLEFT*/, 5, 7}, {0xE0/*0x50*/, '?'/*DOWN*/, 5, 8}, {0xE0/*4D*/, '?'/*RIGHT*/, 5, 9}, {0x52, '0', 5, 10},        {0x53, '.', 5, 11},          {0xE0/*0x1C*/, '?'/*NUMENTER*/, 5, 12} } /*[x][x]*/
};

/*
21
21
21

17
16
13
*/
int sc_to_kc_tbl_row_len[] = {21, 21, 21, 17, 16, 13};


char scan_code_to_ascii (unsigned char sc) {
//    int i = 0;
//    int j = 0;
    // for (i = 0, j = 0; i < 6 && j < sc_to_kc_tbl_row_len[i]; i++, j++) {
    //     if (sc == sc_to_kc_tbl[i][j].scan_code)
    //         return sc_to_kc_tbl[i][j].ascii_code;
    // }

    for (int j = 0; j < 21; j++) { /*[x]*/
        // After F12, keys not generate a scan code. Must use fn+F1-F12 to generate scan codes for FN keys, where N < 13.
        if (sc == sc_to_kc_tbl[0][j].scan_code)
            return sc_to_kc_tbl[0][j].ascii_code;
    }

    for (int j = 0; j < 21; j++) { /*[x]*/
        // Fn, does not generate a scan code // NUMPAD =, does not generate a scan code.
        if (sc == sc_to_kc_tbl[1][j].scan_code)
            return sc_to_kc_tbl[1][j].ascii_code;
    }

    for (int j = 0; j < 21; j++) { /*[x]*/
        if (sc == sc_to_kc_tbl[2][j].scan_code)
            return sc_to_kc_tbl[2][j].ascii_code;
    }

    for (int j = 0; j < 17; j++) { /*[x]*/
        // CAPS LOCK DOES NOT GENERATE A SCAN CODE ON RELEASE.
        if (sc == sc_to_kc_tbl[3][j].scan_code)
            return sc_to_kc_tbl[3][j].ascii_code;
    }

    for (int j = 0; j < 16; j++) { /*[x]*/
        //
        if (sc == sc_to_kc_tbl[4][j].scan_code)
            return sc_to_kc_tbl[4][j].ascii_code;
    }

    for (int j = 0; j < 13; j++) { /*[x]*/
        //
        if (sc == sc_to_kc_tbl[5][j].scan_code)
            return sc_to_kc_tbl[5][j].ascii_code;
    }

    return '?';
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