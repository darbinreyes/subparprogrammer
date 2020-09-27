#include "screen.h"

/*

Remark: This is clearly chosen as our first driver implementation
because the use of interrupts is not absolutely necessary. At least no
interrupts are needed for implementing print.

Goal: print("Dijkstra").

Remark: Note the lack of features in our function, "print()" ,compared to C's
printf(), recall that the "f" == formatted, i.e. we are not implementing format
specifier support, nor making use of C's variable argument mechanism that printf
requires in order to implement.


Plan:

print_char()

get_cursor()
set_cursor()
get_screen_offset()
handle_scrolling().

*/


/*



Print a single character to the screen at the specified position. The meaning of
"position": the screen is treated as a 25x80 grid of characters i.e. 25 rows, 80
columns. The special position row, col == -1, -1 instructs the function to print
the character at the current cursor position.

The cursor position is automatically advanced after each call to this function,
so that a subsequent call prints to the next adjacent cursor position. The
screen position row, col == 0,0 corresponds to the top-left character cell, the
position row, col == 24, 79 corresponds to the bottom right character cell.
Rudimentary automatic scrolling is handled, i.e. when a call to this function is
indicates the character cell is "off the screen" (row, col == 25, 0), then the
text on each row is shifted up by 1, replacing row 0 with row 1, row n with n +
1, the the last row, row 24, is simply blanked out forming a fresh row for the
next characters to be printed.

*/

void printc_at(char c, char cattr, int row, int col) {
    unsigned char *vid_mem =
}

