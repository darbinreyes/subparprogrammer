#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "queue.h"

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
    int num_page_frames = 3;
    int *ref_str = NULL;
    char *ref_str_arg = "2 6 0 2 5 4 1 6 3 7";

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

    free(ref_str);

    test_queue();

    return 0;
}

typedef struct _list_node_t {
    int e;
    struct _list_node_t *next;
} list_node_t;

typedef struct _list_t {
    list_node_t *head;
    list_node_t *tail;
    int len;
} list_t;


int alloc_list(list_t *l, int len) {
    list_node_t *tn;

    assert(l != NULL && len >= 0);

    if (l == NULL || len < 0) {
        return 1;
    }

    l->len = len;

    if(len == 0) { // Empty list.
        l->head = NULL;
        l->tail = NULL;
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (i == 0) {
            l->head = calloc(1, sizeof(list_node_t));
            if (l->head == NULL)
                return 2;
            tn = l->head;
        } else {
            tn->next = calloc(1, sizeof(list_node_t));
            if (tn->next == NULL)
                return 2;
            tn = tn->next;
        }
    }

    l->tail = tn;

    return 0;
}

int free_list(list_t *l) {

    assert(l != NULL);

    if (l == NULL) {
        return 1;
    }

    if (l->head == NULL)
        return 0; // Empty list.

    for(list_node_t *tn = l->head, *tn2 = l->head->next; tn != NULL; ) {
        free(tn);
        tn = tn2;
        if (tn2 != NULL && tn2->next != NULL)
            tn2 = tn2->next;
    }

    return 0;
}


int free_list2(list_t *l) {
    list_node_t *n0, *n1;

    assert(l != NULL);

    if (l == NULL) {
        return 1;
    }

    if (l->head == NULL)
        return 0; // Empty list.

    n0 = l->head;
    n1 = n0->next;

    while(n0 != NULL) {
        free(n0);

        n0 = n1;

        if(n1 != NULL && n1->next != NULL) {
            n1 = n1->next;
        }
    }

    return 0;
}

int init_list(list_t *l, int *e, int elen) {
    int i;
    list_node_t *n;
    // head = stack bottom = LRU page. = e[0].
    // tail = stack top = MRU page. = e[elen-1].

    assert(l != NULL && e != NULL && elen > 0 && l->len == elen);

    if (l == NULL || e == NULL || elen <= 0 || l->len != elen) {
        return 1;
    }

    for(i = 0, n = l->head; i < elen && n != NULL; i++, n = n->next) {
        n->e = e[i];
    }

    return 0;
}

int list_contains(list_t *l, int e) {
    // If e occurs more than once, the search terminates when the first occurrence is found.
    list_node_t *n;


    assert(l != NULL);

    if(l == NULL) {
        return -1;
    }

    if(l->len == 0) { // Empty list.
        return 0;
    }

    n = l->head;

    while (n != NULL) {
        if(n->e == e)
            return 1; // found!
        n = n->next;
    }

    return 0; // Not in list!
}

int list_remove_node(list_t *l, int e, list_node_t **rm_n) {
    // Searches for the first node with entry e, removes it from the list if found, the removed node is returned to the called in *rm_n. If not found *rm_n = NULL.
    // Returns 0 if the e is not in the list. Returns 1 if e is found. Other values indicate an error occurred.
    list_node_t *b, *n, *a;

    assert(l != NULL && rm_n != NULL);

    if (l == NULL || rm_n == NULL) {
        return -1;
    }

    if(l->len == 0) { // Empty list.
        *rm_n = NULL;
        return 0;
    }

    /*
        3 cases:
            Head removal
            Tail removal
            Middle removal
    */

    b = NULL;
    n = l->head;

    while(n != NULL) {
        if(n->e == e) {
            break;
        }

        b = n;
        n = n->next;
    }

    if(n == NULL) { // e is not in the list.
        *rm_n = NULL;
        return 0;
    }

    *rm_n = n; // Return removed node.
    l->len--; // Removing 1 node.

    if(l->len == 0) { // Removing the only node in the list.
        assert(l->head == l->tail);
        l->head = NULL;
        l->tail = NULL;
        return 1;
    }

    a = n->next; // node after the node being removed.

    if(n == l->head) { // head removal
        l->head = a; // new head is the node after the current head.
        n->next = NULL; // unlink node being removed.
        return 1;
    }

    if(n == l->tail) { // tail removal
        l->tail = b; // new tail is node before the node being removed.
        l->tail->next = NULL; // Tail next must be marked NULL.
        return 1;
    }

    // middle removal
    assert(b != NULL && a != NULL);
    b->next = a;
    n->next = NULL;

    return 1;

//  l->len-- ; if found e and removed it. ++ inside list_add_head/tail/at().
}

int list_add_tail(list_t *l, list_node_t *n) {
    assert(l != NULL && n != NULL);

    if(l == NULL || n == NULL) {
        return -1;
    }

    n->next = NULL; // Tail next must be marked NULL.
    l->len++;
    if(l->len == 1) { // first node being added to the list
        l->head = n;
        l->tail = n;
        return 0;
    }

    l->tail->next = n;
    l->tail = n;

    return 0;
}

int list_add_head(list_t *l, list_node_t *n) {
    assert(l != NULL && n != NULL);

    if(l == NULL || n == NULL) {
        return -1;
    }

    l->len++;

    if(l->len == 1) { // first node being added to the list
        l->head = n;
        l->tail = n;
        n->next = NULL; // Tail next must be marked NULL.
        return 0;
    }

    n->next = l->head;
    l->head = n;
    return 0;
}
