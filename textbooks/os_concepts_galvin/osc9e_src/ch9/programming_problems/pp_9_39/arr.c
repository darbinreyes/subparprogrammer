/*!
    @header Array Interface.
    A simple interface to an array ADT to facilitate the implementation of the
    OPT page replacement algorithms.
*/

#include <stdlib.h>
#include "arr.h"

typedef struct _arr_t {
    int *arr;
    int arr_len;
    int num_entries;
} arr_t;

/*!
    @function alloc_arr

    @discussion Initializes
    a->arr = calloc(arr_len, sizeof(int));
    a->arr_len = arr_len;
    a->num_entries = 0;

    @param a    Pointer to an arr_t.

    @param arr_len    Length of the a->arr array to allocated.

    @result 0 on success. Otherwise an error occurred.
*/
int alloc_arr(arr_t *a, int arr_len) {

    assert(a != NULL && arr_len > 0);

    if (a == NULL || arr_len <= 0) {
        return 1;
    }

    a->arr = calloc(arr_len, sizeof(int));

    assert(a->arr != NULL);

    if(a->arr == NULL) {
        return 2;
    }

    a->arr_len = arr_len;
    a->num_entries = 0;

    return 0;
}

/*!
    @function free_arr

    @discussion Frees memory allocated by a successful call to alloc_arr().

    @param a    Pointer to an arr_t.

    @result 0 on success. Otherwise an error occurred.
*/
int free_arr(arr_t *a) {

    assert(a != NULL);

    if(a == NULL) {
        return 1;
    }
}