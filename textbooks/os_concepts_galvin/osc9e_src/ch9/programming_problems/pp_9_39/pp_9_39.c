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
    @function len_ref_str_arg

    @discussion Returns the length of the fixed (instead of random) reference
    string supplied on the command line as a string of characters.

    @param ref_str_arg Reference string encoded as a character string. It must
    consist of space separated integers in the range 0-9.

    @param ref_str_len If successful, upon return, the length of the reference
    string. e.g. if ref_str_arg = "2 3 5", *ref_str_len == 3.

    @result 0 if successful. Otherwise an error occurred.
*/
int len_ref_str_arg(char *ref_str_arg, int *ref_str_len) {
    char *endptr = NULL;
    int len = 0;

    if (ref_str_arg == NULL || ref_str_len == NULL) {
        return 1;
    }

    while (*ref_str_arg != '\0') {
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

int main(int argc, char **argv) {
    int i;
    int ref_str_len = 100;
    int num_page_frames = 2;
    int *ref_str = NULL;
    char *ref_str_arg = "1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6";
    int p0, p1, p2;

#define FIXED_REF_STR 1

#if FIXED_REF_STR
    if(len_ref_str_arg(ref_str_arg, &ref_str_len))
        return 2;

    printf("Fixed ref_str_len = %d\n", ref_str_len);

    ref_str = calloc(ref_str_len, sizeof(int));

    if(ref_str == NULL) {
        printf("calloc() returned NULL! Bye!\n");
        return 1;
    }

    if(arg_ref_str(ref_str_arg, ref_str_len, ref_str))
        return 3;

#else
    ref_str = calloc(ref_str_len, sizeof(int));

    if(ref_str == NULL) {
        printf("calloc() returned NULL! Bye!\n");
        return 1;
    }

    if(rand_ref_str(ref_str_len, ref_str))
        return 2;
#endif

    if(get_arg_npf(argc, argv, &num_page_frames) < 0) {
        printf("Error getting -npf arg.\n");
        return 4;
    }

    printf("reference string length = %d. number of page frames = %d.\n", ref_str_len, num_page_frames);
    printf("reference string =\n");

    for(i = 0; i < ref_str_len; i++) {
        printf("%d ", ref_str[i]);
    }

    printf("\n");

    printf("# page frames | FIFO | LRU | OPT\n");

    for(i = 1; i < 8; i++) {
        p0 = do_fifo(ref_str_len, ref_str, i);
        p1 = do_lru(ref_str_len, ref_str, i);
        p2 = do_opt(ref_str_len, ref_str, i);
        printf("%13d | %4d | %3d | %3d\n", i, p0, p1, p2);
    }

    free(ref_str);

    return 0;
}