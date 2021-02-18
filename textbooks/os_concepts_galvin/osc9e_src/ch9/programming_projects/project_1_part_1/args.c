#include <stdio.h>
#include <assert.h>
#include "vm.h"

/*!
    @function valid_int_sizes
    @discussion Verifies that the size of integers and virtual address
    definitions are valid/as expected.
    @result 0 if valid. Otherwise not valid.
*/
int valid_int_sizes(void) {
    // Verify the size of integers.
    if (sizeof(short) != 2 || sizeof(int) != 4 || sizeof(long) != 8) {
        fprintf(stderr, "Unexpected int size.\n");
        assert(0);
        return 1;
    }
    /* This program only deals with virtual addresses less than 64-bits wide. */
    if (!(ADDR_NBITS < sizeof(addr_t) * 8) || !(PAGE_OFFSET_NBITS < ADDR_NBITS)) {
        fprintf(stderr, "Unsupported virtual address size/def.\n");
        assert(0);
        return 1;
    }

    return 0;
}

/*!
    @function valid_args
    @discussion Checks that the args passed to main() are valid.
    @param argc The usual main() arg.
    @param argv The usual main() arg.
    @result 0 if valid. Otherwise not valid.
*/
int valid_args (int argc, const char * const * const argv) {
    if (argc < 1 || argv == NULL) {
        assert(0);
        return 1;
    }

    if (argc <= 2) {
        fprintf(stderr, \
                "Usage 1: ./a.out. The default input filename is "\
               "addresses.txt.\n"\
                "Usage 2: ./a.out addresses.txt. addresses.txt can be any "\
                "filename.\n");
        return 1;
    }

    return 0;
}