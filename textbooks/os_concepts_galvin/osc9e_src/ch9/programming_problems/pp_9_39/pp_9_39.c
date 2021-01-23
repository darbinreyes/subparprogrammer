#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "page_repl.h"
#include "args.h"

/*!
    @function rand_ref_str

    @discussion Fills reference string ref_str with ref_str_len random integers
    in the range 0-9.

    @param ref_str_len Length of ref_str array.

    @param ref_str Array of integers to be filled with random numbers in range
                   0-9.

    @result 0 if successful. Otherwise an error occurred.
*/
int rand_ref_str(int ref_str_len, int *ref_str) {

    if (ref_str_len <= 0 || ref_str == NULL) {
        return 1;
    }

    sranddev();

    for(int i = 0; i < ref_str_len; i++) {
        ref_str[i] = rand()/(RAND_MAX/10 + 1);
    }

    return 0;
}

/*!
    @function get_ref_str_len

    @discussion Returns the length of a reference string encoded as a string of
    space separated non-negative integers.

    @param ref_str_arg Reference string encoded as a character string e.g.
    "2 3 5".

    @param ref_str_len If successful, upon return, the length of the reference
    string. e.g. if ref_str_arg = "2 3 5" then *ref_str_len == 3.

    @result 0 if successful. Otherwise an error occurred, in which case the
    program should bail.
*/
int get_ref_str_len(const char * const ref_str_arg, int * const ref_str_len) {
    char *endptr = NULL;
    int len = 0;

    if (ref_str_arg == NULL || ref_str_len == NULL) {
        return 1;
    }

    while (*ref_str_arg != '\0') {
        strtol(str)
        if(isdigit(*ref_str_arg))
            len++;

        ref_str_arg++;
    }

    *ref_str_len = len;

    return 0;
}

/*!
    @function arg_ref_str

    @discussion Fills reference string ref_str with ref_str_len integers
    obtained from ref_str_arg.


    @param ref_str_arg Reference string encoded as a character string. It must
                       consist of space separated integers in the range 0-9.

    @param ref_str_len Length of ref_str array.

    @param ref_str Array of integers to be filled with random numbers in range
                   0-9.

    @result 0 if successful. Otherwise an error occurred.
*/
int arg_ref_str(char *ref_str_arg, int ref_str_len, int *ref_str) {
    int i = 0;

    if (ref_str_arg == NULL || ref_str_len <= 0 || ref_str == NULL) {
        return 1;
    }

    while (*ref_str_arg != '\0') {
        if(isdigit(*ref_str_arg)) {
            if(i >= ref_str_len)
                return 2; // Found more digits than expected.

            ref_str[i] = atoi(ref_str_arg);
            i++;
        }

        ref_str_arg++;
    }

    return 0;
}

/* Reference string from exercise 9.8 - the page fault counts match the
   solution. */
static char *fixed_ref_str_arg = "1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6";

/*!*/
int print_ref_str(int *ref_str, int ref_str_len) {

    if(ref_str == NULL || ref_str_len <= 0) {
        assert(0);
        return 1;
    }

    printf("reference string length = %d.\n", ref_str_len);
    printf("reference string =\n");

    for(int i = 0; i < ref_str_len; i++) {
        printf("%d ", ref_str[i]);
    }

    printf("\n");

    return 0;
}

/*!
    @function run_mode0

    @discussion No arguments provided. Uses fixed reference string. Prints a
    table of the number for page faults for FIFO, LRU, and OPT for a number of
    page frames from 1 to 7.
*/
int run_mode0(int *ref_str, int ref_str_len, int npf) {
    int p0, p1, p2;
    int npf_l = 1, npf_h = 8;

    if(ref_str == NULL || ref_str_len <= 0) {
        assert(0);
        return 1;
    }

    if (npf > 0) {
        npf_l = npf;
        npf_h = npf + 1;
    }

    //printf("Running in mode 0.\n");

    print_ref_str(ref_str, ref_str_len);

    printf("# page frames | FIFO | LRU | OPT\n");

    for(int i = npf_l; i < npf_h; i++) {
        p0 = do_fifo(ref_str_len, ref_str, i);
        p1 = do_lru(ref_str_len, ref_str, i);
        p2 = do_opt(ref_str_len, ref_str, i);
        printf("%13d | %4d | %3d | %3d\n", i, p0, p1, p2);
    }

    return 0;
}

int main(int argc, char **argv) {
    int i;
    int ref_str_len = 25;
    int num_page_frames = -1;
    int *ref_str = NULL;
    char *arg_name = NULL;
    int use_rand = 0;

    if (argc == 1) { // Usage: a.out
        if(get_ref_str_len(fixed_ref_str_arg, &ref_str_len))
            return 2;

        ref_str = calloc(ref_str_len, sizeof(int));

        if(ref_str == NULL) {
            assert(0);
            printf("calloc() returned NULL! Bye!\n");
            return 1;
        }

        if(arg_ref_str(fixed_ref_str_arg, ref_str_len, ref_str))
            return 3;

        run_mode0(ref_str, ref_str_len, -1);
        free(ref_str);
        return 0;
    }

    arg_name = "-npf"; // Number of page frames

    if(get_arg_pi(argc, argv, &num_page_frames, arg_name) < 0) {
        printf("Error getting %s arg.\n", arg_name);
        return 4;
    }

    if (argc == 3 && num_page_frames > 0) { // Usage: a.out -npf 7
        if(get_ref_str_len(fixed_ref_str_arg, &ref_str_len))
            return 2;

        ref_str = calloc(ref_str_len, sizeof(int));

        if(ref_str == NULL) {
            assert(0);
            printf("calloc() returned NULL! Bye!\n");
            return 1;
        }

        if(arg_ref_str(fixed_ref_str_arg, ref_str_len, ref_str))
            return 3;

        run_mode0(ref_str, ref_str_len, num_page_frames);
        free(ref_str);
        return 0;
    }

    arg_name = "-rand";

    if (get_arg_bool(argc, argv, &use_rand, arg_name) < 0) {
        printf("Error getting %s arg.\n", arg_name);
        return 6;
    }

    if(argc == 4 && use_rand) { // a.out -npf 9 -rand
        printf("-rand arg. present\n");
        ref_str_len = 20;
        ref_str = calloc(ref_str_len, sizeof(int));

        if(ref_str == NULL) {
            printf("calloc() returned NULL! Bye!\n");
            return 1;
        }

        if(rand_ref_str(ref_str_len, ref_str))
            return 2;

        run_mode0(ref_str, ref_str_len, num_page_frames);
        free(ref_str);
        return 0;
    }

    printf("Unsupported command line arg. combination. Bye!\n");
    return 0;
    ///////////////////////TODO

    arg_name = "-rsl"; // Reference string length

    if(get_arg_pi(argc, argv, &ref_str_len, arg_name) < 0) {
        printf("Error getting %s arg.\n", arg_name);
        return 5;
    }

    return 0;
}