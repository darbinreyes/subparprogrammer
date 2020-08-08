/*

    https://www.hackerrank.com/challenges/jesse-and-cookies/problem

    Success Rate: 67.21%

*/

/* Scratch Work.

We are given an array of integers `A` whose size is N ([1, 1 000 000])
and whose members `A[i]` are all non-negative ([0, 1 000 000]).

We are also given a non-negative integer `k` ([0, 1 000 000 000]).

The task is:

repetition

`n` = 0

while len(`A`) > 1 && !all_greater_than_or_equal_to(`A`, `k`) {

remove the two least members from `A`, call them `c0`, `c1`.
compute `cn` =  c0 + 2 * c1
place `cn` in A.
n++

}

assert: len(`A`) <= 1 || all_greater_than_or_equal_to(`A`, `k`)

if len(`A`) == 1 && `A[0]` < k
    return -1 // means no solution is possible.


return `n`

*/

/* Scratch Work.


We could try starting with a sorted array, but as we are removing and then adding
items to the array this would require resorting O(n^2) each time we remove or add an item.
We can avoid resorting by because the array is sorted, insertion is O(n).

Using a sorted linked list would also involve O(n) insertion.

Since we are removing the minimum element in each iteration, a min heap seems
appropriate. Adding and removing is O(log.n).

Other considerations:

* When should we return -1?
  * As soon as len(`A`) and `A[last]` < k, no solution is possible.


if k == 0, we can immediately return 0, since each element in the array is
bounded by [0, 1 000 000] and it is given that the array contains at least 1
element.

Variable sizes:

Does `k` fit in an int? Yes.

What about the array `A`? In the worst case, we might end up with a value =
N_max * A_i_max = 10^6 * 10^6 = 10^12, this suggests that we should use
**long.**

Plan:

Insert my min heap implementation from a previous problem

Add code to create a min heap from the array 'A'.

Implement `all_greater_than_or_equal_to()`

Implement while loop above using min heap operations.


*/

#include <stdio.h>

//#define NDEBUG // This disables asserts at compile time.

#include <assert.h>

#define HEAP_ARRAY_SIZE 100001
// Our heap array will be 1 based to make indexing simpler.
#define HEAP_SIZE (HEAP_ARRAY_SIZE - 1)

#define ROOT_INDEX 1

/* Improving upon my heap implementation in `subparprogrammer/coding_interviews/hackerrank/qheap1/max_heap.c`.

TODO: Generalize by:

1.[x] Replacing static externals with struct * arg. to functions.
2.[x] Use #define to toggle whether this is a min heap or a max heap.
Remark on #2. If we use a #define, we can only toggle between the two heap types at compile time.

8.[x] Add arg checks to all functions.

3.[ ] Replace simple functions with macros.

4.[ ] Allow storage of types other than int. This will require the user to provide
function a comparison function.

5.[ ] Allow the heap to grow if it becomes full. Could just double the array size when it becomes full.
6.[ ] Add a header file so that using the heap only requires including a header. Dont forget #include guards.
7.[ ] ? Consider lumping the heap operations into the heap struct using UEFI style function pointers.

*/

typedef struct _heap_t {
    /* Represents a min or max heap. */
    const int min_or_max_heap; // 0 means min heap, otherwise this is a max heap.
    int heap_array[HEAP_ARRAY_SIZE];
    int num_entries;
} heap_t;

/*

    Returns -1 if heap is NULL. Returns 1 if the heap is empty. Returns 0 if not empty.

*/
int heap_is_empty(heap_t *heap) {
    if (heap == NULL) {
        assert(0);
        return -1;
    }

    return (heap->num_entries == 0);
}

/*

    Returns -1 if heap is NULL. Returns 1 if the heap is full. Returns 0 if not full.

*/
int heap_is_full(heap_t *heap) {
    if (heap == NULL) {
        assert(0);
        return -1;
    }

    return (heap->num_entries == HEAP_SIZE);
}

/*

    Returns -1 if `parent` is not > 0, which is an invalid index. Otherwise,
    returns the index ( > 0) of the left child of node `parent`.

*/
int left_child(int parent) {
    if(parent <= 0) {  // Valid indexes into the heap array start at 1.
        assert(0);
        return -1;
    }

    return 2 * parent;
}

/*

    Returns -1 if `parent` is not > 0, which is an invalid index. Otherwise,
    returns the index ( > 0) of the right child of node `parent`.

*/
int right_child(int parent) {
    if(parent <= 0) {  // Valid indexes into the heap array start at 1.
        assert(0);
        return -1;
    }

    return 2 * parent + 1;
}

/*

    Returns -1 if `child` is not > 0, which is an invalid index. Otherwise,
    returns the index ( > 0) of the parent of node `child`.

*/
int parent(int child) {

    if(child <= 0) {
        assert(0);
        return -1;
    }

    return child/2;
}

void float_up(heap_t *heap, int i, int v) {
    int p;
    int c;

    if (heap == NULL || i <= 0) {
        assert(0);
        return;
    }

    p = parent(i);

    if (p == -1) { // Error, bail.
        assert(0);
        return;
    }

    if (p == 0) { // The root has been replaced.
        heap->heap_array[ROOT_INDEX] = v;
        return;
    }

    if(!heap->min_or_max_heap)
        c = v < heap->heap_array[p];
    else
        c = v > heap->heap_array[p];

    if (c) {
        heap->heap_array[i] = heap->heap_array[p];
        float_up(heap, p, v);
    } else {
        // assert v >= heap_array[p]
        heap->heap_array[i] = v;
        return;
    }
}

/*

    Returns -1 if heap is NULL.
    Returns 1 if successfully added v to the heap or if v is already in the
    heap. Returns 0 if the v could not be added, e.g. if the heap is full.

*/
int heap_add(heap_t *heap, int v) {

    if (heap == NULL) {
        assert(0);
        return -1;
    }

    if (heap_is_full(heap))
        return 0;

    heap->num_entries++;
    float_up(heap, heap->num_entries, v);

    return 1;
}

/*

    Returns -1 if an error occurred.

    This is a helper function for reheap().

    If heap is a min heap, returns the index of the child with the lesser value. If i has no children, 0 is returned.
    If heap is a max heap, returns the index of the child with the greater value. If i has no children, 0 is returned.

*/
int reheap_child(heap_t *heap, int i) {
    int lc_i, rc_i, reheap_child_i;
    int c;

    if (heap == NULL) {
        assert(0);
        return -1;
    }

    lc_i = left_child(i);
    rc_i = right_child(i);

    if (lc_i == -1 || rc_i == -1) {
        assert(0);
        return -1;
    }

    if (lc_i <= heap->num_entries && rc_i <= heap->num_entries) {
        if(!heap->min_or_max_heap)
            c = heap->heap_array[lc_i] < heap->heap_array[rc_i];
        else
            c = heap->heap_array[lc_i] > heap->heap_array[rc_i];

        if (c)
            reheap_child_i = lc_i;
        else
            reheap_child_i = rc_i;
    } else if (lc_i <= heap->num_entries) {
        reheap_child_i = lc_i;
    } else if (rc_i <= heap->num_entries) {
        reheap_child_i = rc_i;
    } else {
        /* i is a node without any children. */
        reheap_child_i = 0;
    }

    return reheap_child_i;
}

/*

    A reheap operation transforms a semiheap into a heap. A semiheap is a heap
    in which only the root node's value is out of place. This operation is used for
    instance, when the root node is removed from the heap in order to
    reestablish the heap invariant. It is also used to more efficiently form a heap
    from a given array of values.

    Performs a reheap operation at the subtree rooted at node `i` in order to
    find an appropriate location for value `v` in the heap.

*/
void reheap(heap_t *heap, int i, int v) {
    int reheap_child_i;
    int c;

    if (heap == NULL) {
        assert(0);
        return;
    }

    reheap_child_i = reheap_child(heap, i);

    if (reheap_child_i == -1) { // Error, bail.
        assert(0);
        return;
    }

    if(reheap_child_i <= 0) {
        heap->heap_array[i] = v;
        return;
    }

    if(!heap->min_or_max_heap)
        c = v > heap->heap_array[reheap_child_i];
    else
        c = v < heap->heap_array[reheap_child_i];

    if (c) {
        heap->heap_array[i] = heap->heap_array[reheap_child_i];
        reheap(heap, reheap_child_i, v);
    } else {
        heap->heap_array[i] = v;
    }
}

/*

    Returns 1 if the root is successfully removed, returns the root value in v.
    Returns 0 if an error occurred, e.g. the heap is empty.

*/
int heap_rm_root(heap_t *heap, int *v) {

    if (heap == NULL || v == NULL) {
        assert(0);
        return 0;
    }

    if (heap_is_empty(heap) == 1)
        return 0;

    if (heap->num_entries == 1) { // Single entry in the heap, return the root.
        *v = heap->heap_array[heap->num_entries];
        heap->num_entries--;
        return 1;
    }

    // assert num_entries > 1

    /*

        The standard algorithm is: 1. Place the last leaf at the root, this
        forms a "semi-heap" 2. Perform a re-heap to create a heap again.

    */
    *v = heap->heap_array[ROOT_INDEX];
    heap->heap_array[ROOT_INDEX] = heap->heap_array[heap->num_entries];
    heap->num_entries--;
    reheap(heap, ROOT_INDEX, heap->heap_array[ROOT_INDEX]);
    return 1;
}

/*

    Constructs a heap from the given array of values.

    @param[in] v The array of values.
    @param[in] l The length of the array.

    @retval 0 If successful.
    @retval 1 Otherwise, an error occurred.

*/
int  heap_create(heap_t *heap, int *v, int l) {
    int i;

    if (heap == NULL || v == NULL || l < 0) {
        assert(0);
        return 1;
    }

    /* For now, this operation is only valid for creating a new array. */
    if (heap_is_empty(heap) != 1)
        return 1;

    if (l > HEAP_SIZE) /* Given array is too large. */
        return 1;

    /* Fill the heap array in the same order as given */
    for (i = 0; i < l; i++)
        heap->heap_array[i + 1] = v[i];

    heap->num_entries = l;

    /*

        Perform a reheap at every node starting from the last node, up to and
        including the root node. Since reheaping a single node is a no-op we
        should skip calling reheap on any leaf nodes. This is achieved by
        starting the  reheaps at the parent node of the last leaf, which is node
        num_entries/2.

    */
    for (i = heap->num_entries/2; i > 0; i--)
        reheap(heap, i, heap->heap_array[i]);

    return 0;
}

/*

    Returns the value at the root of the heap in v, the heap is not modified. Returns
    1 if successful. 0 otherwise.

*/
int heap_peek_root(heap_t *heap, int *v) {

    if (heap == NULL || v == NULL) {
        assert(0);
        return 0;
    }

    if (heap_is_empty(heap) == 1)
        return 0;

    *v = heap->heap_array[ROOT_INDEX];
    return 1;
}

// Print each level of the heap on a separate line.
void _print_heap(heap_t *heap, int n, int start_i) {
    int i;

    // No arg check here since this function is wrapped with print_heap().

    for (i = start_i; i < (start_i + n) && i <= heap->num_entries; i++) {
        printf("%d ", heap->heap_array[i]);
    }

    printf("\n");

    if (i > heap->num_entries)
        return;

    n *= 2;
    _print_heap (heap, n, i);
}

void print_heap(heap_t *heap) {

    if (heap == NULL) {
        assert(0);
        return;
    }

    if (heap->num_entries == 0) {
        printf("Empty heap.\n");
        return;
    }

    _print_heap(heap, 1, 1);
}

/* I borrowed this macro style from linux/list.h. */
 // Declare a max heap variable.
#define MAX_HEAP(name) \
    heap_t name = {1}

// Declare a min heap variable.
#define MIN_HEAP(name) \
    heap_t name = {0}


int main(void) {
    int v[] = {20, 40, 30, 10, 90, 70};
    int l = sizeof(v)/sizeof(v[0]);
    int t;

    static MIN_HEAP(min_heap);
    static MAX_HEAP(max_heap);

    assert(min_heap.min_or_max_heap == 0);
    assert(max_heap.min_or_max_heap != 0);

    heap_create (&min_heap, v, l);
    print_heap(&min_heap);
    heap_rm_root(&min_heap, &t);
    print_heap(&min_heap);

    heap_create (&max_heap, v, l);
    print_heap(&max_heap);
    heap_rm_root(&max_heap, &t);
    print_heap(&max_heap);

    return 0;
}