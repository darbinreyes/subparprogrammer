#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "queue.h"
#include "list.h"

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

int do_lru(int len, int *rf, const int npf);

int main(int argc, char **argv) {
    int i;
    int ref_str_len = 100;
    int num_page_frames = 3;
    int *ref_str = NULL;
    char *ref_str_arg = "1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6";
    int page_faults;

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

    printf("reference string length = %d. number of page frames = %d.\n", ref_str_len, num_page_frames);
    printf("reference string =\n");

    for(i = 0; i < ref_str_len; i++) {
        printf("%d ", ref_str[i]);
    }

    printf("\n");

    page_faults = do_lru(ref_str_len, ref_str, num_page_frames);

    printf("LRU page faults = %d\n", page_faults);

    free(ref_str);

    //test_queue();

    //test_list();

    return 0;
}

int do_lru(int len, int *rf, const int npf) {
    int n_free_pf = npf;
    int i = 0;
    int page_num;
    int num_page_faults = 0;
    list_t l;
    list_node_t *n = NULL;

    alloc_list(&l, 0);

    while (i < len) {
        page_num = rf[i];
        i++;

        if(list_contains(&l, page_num) == 1) {
            // Page in memory - update MRU page.
            if(list_remove_node(&l, page_num, &n) == 1)
                assert(list_add_tail(&l, n) == 0);
            else
                assert(0); // Should be in list - we just checked.
        } else {
            // Page not in memory - page fault
            num_page_faults++;

            if(n_free_pf-- > 0) {
                // Place page in a free frame - make it the MRU
                n = calloc(1, sizeof(list_node_t));
                assert(n != NULL);
                n->e = page_num;
                assert(list_add_tail(&l, n) == 0);
            } else {
                // Replace LRU page with page just referenced.

                assert(l.len > 0); // We should have a least one page frame

                if(list_remove_node(&l, l.head->e, &n) == 1) { // Remove head = LRU page.
                    n->e = page_num;
                    assert(list_add_tail(&l, n) == 0);
                } else
                    assert(0);
            }

        }
    }

    free_list2(&l);

    return num_page_faults;
}