/*!
    @header Argument Parsing
    Functions for getting arguments from the command line. Below are some usage
    examples.

Usage:
    a.out

    Default mode: Prints the number of page faults for a fixed reference string
    and 1 to 7 page frames.
    Reference string: 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6.
----------------
    a.out -npf 8
    Run against the fixed reference string using 8 page frames.
    Argument must be > 0.
----------------
    a.out -npf 9 -rand
    Use 9 page frames against a randomly generated reference string. The random
    reference string contains only page numbers in the range 0 to 9. The random
    reference string length is 20 by default. If -npf is not specified 7
    is the default.
----------------
    a.out -npf 10 -rand -rsl 31
    Use 10 page frames against a randomly generated reference string. The random
    reference string contains only page numbers in the range 0 to 9. The random
    reference string length is set to 31. If -npf is not specified 7
    is the default.
----------------
    a.out -npf 11 -rs '1 2 3 4 5 1 2 3 6'
    Use 11 page frames against the reference string specified by the -rs
    argument. The single quotes are required.
*/
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*!

    @function get_arg_pi

    @discussion Gets a argument that is a positive integer.

    @result Less than 0 if an error occurred in which case the program should
    bail. 0 if the argument was not present, npf is untouched. 1 the argument
    was present and its value was valid.
*/
int get_arg_pi(const int argc, const char * const * const argv, int * const pi, const char * const arg_name) {
    int arg_name_present;
    int i;
    char *endptr = NULL;
    int v;

    if(argc < 0 || argv == NULL || pi == NULL || arg_name == NULL) {
        assert(0);
        return -1;
    }

    arg_name_present = 0;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], arg_name) == 0) {
            arg_name_present = 1;
            break;

        }
    }

    if(!arg_name_present) {
        return 0;
    }

    i++;

    if(i >= argc) {
        // A value is required.
        return -2;
    }

    if(strlen(argv[i]) <= 0) {
        // Again, a value is required.
        return -3;
    }

    v = strtol(argv[i], &endptr, 10);

    if(endptr != NULL && *endptr != '\0') {
        // Arg. value contained non-integer character.
        return -4;
    }

    if(v <= 0) {
        // Arg. value should be positive integer.
        return -5;
    }

    *pi = v;

    return 1;
}


