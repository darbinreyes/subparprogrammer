/*

    A rudimentary IBM VGA driver.

    Driver Interface Features:
    * Printing to the screen.

    The author does not go into detail about where this numbers came from. The
    notes below are a summary of my search for legitimate/accurate
    documentation.

    Relevant documentation.
    ===

    The screen device we use here is called the "IBM VGA". This is a screen
    device from the late 1990's. The low level interface to this device
    involves:

    1. Over 300 internal registers.
    2. MMIO, the device in its default mode responds to
    host memory access in a range starting at address 0xB8000 up to 0xBFFFF.
    3. About a dozen I/O ports are used to access registers in #1.

    Links:

    [A concise intro. to the IBM VGA device](https://wiki.osdev.org/VGA_Hardware)
    [Deep dive, every possible detail you might want to know. Well written.](http://www.osdever.net/FreeVGA/home.htm#vga)
    [Further reading, (1998!) home page of above link](http://www.osdever.net/FreeVGA/home.htm)
    [Manipulating the Text-mode Cursor](http://www.osdever.net/FreeVGA/vga/textcur.htm)
    [Cathode Ray Tube Controller (CRTC) Registers, in here we find the registers that allow us to control text mode cursor position](http://www.osdever.net/FreeVGA/vga/crtcreg.htm)

    Remark: In 1998, engineers had to reference this immense documentation on
    physical paper tomes, flipping back and forth to cope with inter-chapter
    references. Sounds painful.

    Remark: In order to control 300+ internal VGA registers with roughly 12 I/O
    ports a register indexing scheme is used. For example, an I/O port will be
    used to provide an index, which selects a particular register, then a second
    I/O port is used to read/write a single byte of data to the index-selected
    register. This scheme is used with the 0x3D4-0x3D5 I/O ports.


    Related to Nick Blundel's Text
    ===

    Remark: This is clearly chosen as our first driver implementation because
    the use of interrupts is not absolutely necessary. At least no interrupts
    are needed for implementing print.

    Goal: print("Dijkstra").

    Remark: Note the lack of features in our function, "print()" ,compared to
    C's printf(), recall that the "f" == formatted, i.e. we are not implementing
    format specifier support, nor making use of C's variable argument mechanism
    that printf requires in order to implement.


    Plan:

        print_char()

        get_cursor()
        set_cursor()
        get_screen_offset()
        handle_scrolling().

*/

#include "screen.h"
#include "../kernel/low_level.h"



int row_col_to_screen_video_mem_offset(int row, int col);

int get_cursor(void);

void set_cursor(int vid_mem_offset);

int handle_scrolling(int vid_mem_offset);


/*

    Print a single character to the screen at the specified position. The
    meaning of "position": the screen is treated as a 25x80 grid of characters
    i.e. 25 rows, 80 columns. The special position <row, col> == <-1, -1>
    instructs the function to print the character at the current cursor
    position. The cursor position is automatically advanced after any print,
    regardless of the arguments.

    The cursor position is automatically advanced after each call to this
    function, so that a subsequent call prints to the next adjacent cursor
    position. The screen position <row, col> == <0,0> corresponds to the
    top-left character cell, the position <row, col> == <24, 79> corresponds to
    the bottom right character cell.

    Rudimentary automatic scrolling is handled, i.e. after printing the
    specified character if <row, col> == <25, 0>, every row is shifted upwards
    by 1 row, thus overwriting row == 0 and clearing row == 24, and the cursor
    position is set to <row, col> == <24, 0>.

    cattr is used to set the character's foreground and background color (TODO:
    specifics). If cattr == 0, the function uses foreground/background color
    == WHITE/BLACK, otherwise the given cattr value is used.

    c == '\n' is handled specially, it has the natural behavior: it moves the
    cursor position 1 row below the current row.

*/
void print_ch_at(char c, char cattr, int row, int col) {
    unsigned char *vid_mem;
    int vid_mem_offset;
    int trow;

    /*

        Start of video memory address in text mode, 2 bytes each, first byte is
        the ASCII code of the character, second byte is the character display
        attributes e.g. text color.

    */
    vid_mem = (unsigned char *) VIDEO_ADDRESS;

    if (cattr == 0)
        cattr = CHAR_ATTR_WHITE_ON_BLACK;

    /* Determine where the character wills be printed. */
    if (row >= 0 && col >= 0) {
        // vid_mem_offset = get_screen_offset(row, col); // row_col_to_screen_video_mem_offset(row, col).
        vid_mem_offset = row_col_to_screen_video_mem_offset(row, col);
    } else {
        // vid_mem_offset = get_cursor(); // get_current_cursor_pos_video_mem_offset().
        vid_mem_offset = get_cursor();
    }

    if (c == '\n') {
        /* Move cursor to a new line. */

        /*

            Convert vid_mem_offset into current row position. The algebra is:
            `(row * MAX_COLS + col) * 2` / `(MAX_COLS* 2)` == row.

        */
        trow = vid_mem_offset / (MAX_COLS * 2);
        // vid_mem_offset = // get_screen_offset(79, rows); // row_col_to_screen_video_mem_offset(trows, 79);
        /*

            Set the video memory offset to the last column of the current row.
            Then the code below will increment the video memory offset, which
            has the net effect of leaving the cursor at the first column of the
            next row.

        */
        vid_mem_offset = row_col_to_screen_video_mem_offset(trow, 79);
    } else {
        /* Print the character as-is. */
        vid_mem[vid_mem_offset] = c;
        vid_mem[vid_mem_offset + 1] = cattr;
    }

    /* Implement rudimentary auto scrolling. */

    /* Advance the cursor position. */
    vid_mem_offset += 2;

    // offset = handle_scrolling(offset); // vid_mem_offset = handle_scrolling(vid_mem_offset);

    //vid_mem_offset = handle_scrolling(vid_mem_offset);

    // Use the handle_scrolling(offset) result.
    // set_cursor(offset); //  set_cursor(vid_mem_offset);

    set_cursor(vid_mem_offset);
}

/****** Helper functions. *******/

// vid_mem_offset = get_screen_offset(row, col); // row_col_to_screen_video_mem_offset(row, col).
int row_col_to_screen_video_mem_offset(int row, int col) {
    return ((row * MAX_COLS) + col) * 2;
}

/*

    Returns the video memory offset corresponding to the current position of the
    cursor.

*/
int get_cursor(void) {
    int vid_mem_offset;

    port_byte_out(REG_SCREEN_CTRL_IO_PORT, CURSOR_LOCATION_HIGH_BYTE);
    vid_mem_offset = port_byte_in(REG_SCREEN_DATA_IO_PORT) << 8;
    port_byte_out(REG_SCREEN_CTRL_IO_PORT, CURSOR_LOCATION_LOW_BYTE);
    vid_mem_offset += port_byte_in(REG_SCREEN_DATA_IO_PORT);

    /*

        The cursor position is stored in the VGA's internal registers in the
        form of a character cell offset, as opposed to a video memory offset. A
        character cell offset is = `row * MAX_COLS + col` while the video memory
        offset is = `(row * MAX_COLS + col) * 2` since in video memory space
        each character cell gets 2 bytes: viz. <ASCII CODE> and <ATTRIBUTES>.

    */


    return vid_mem_offset * 2;
}

/*

    Takes a cursor position in the form of a video memory offset, converts that
    into a character offset, and finally writes that character offset into the
    appropriate VGA internal registers.


*/
void set_cursor(int vid_mem_offset) {

    /*

        The algebra is: character offset = `(row * MAX_COLS + col) * 2` / `2` ==
        `(row * MAX_COLS + col)`.

    */
    vid_mem_offset /= 2;

    port_byte_out(REG_SCREEN_CTRL_IO_PORT, CURSOR_LOCATION_HIGH_BYTE);
    port_byte_out(REG_SCREEN_DATA_IO_PORT, (unsigned char) (vid_mem_offset >> 8) );
    port_byte_out(REG_SCREEN_CTRL_IO_PORT, CURSOR_LOCATION_LOW_BYTE);
    port_byte_out(REG_SCREEN_DATA_IO_PORT, (vid_mem_offset & 0x00FF) );

}

int handle_scrolling(int vid_mem_offset) {
    // TODO:
    return vid_mem_offset;
}


void print(char *s) {

    while (*s != '\0') {
        print_ch_at(*s, 0, -1, -1);
        s++;
    }
}

/* TODO: scrolling , clear screen, print_at(). */