
#include <stdio.h>
#include <assert.h>

#define HEAP_ARRAY_SIZE 100001
// Our heap array will be 1 based to make indexing simpler.
#define HEAP_SIZE (HEAP_ARRAY_SIZE - 1)

#define ROOT_INDEX 1

/* Improving upon my heap implementation in `subparprogrammer/coding_interviews/hackerrank/qheap1/max_heap.c`.

TODO: Generalize by:

1.[x] Replacing static externals with struct * arg. to functions.
2.[ ] Use #define to toggle whether this is a min heap or a max heap.
Remark on #2. If we use a #define, we can only toggle between the two heap types at compile time.

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

// Returns 1 if the heap is empty. Returns 0 otherwise.
int heap_is_empty(heap_t *heap) {
    return (heap->num_entries == 0);
}

// Returns 1 if the heap is full. Returns 0 otherwise.
int heap_is_full(heap_t *heap) {
    return (heap->num_entries == HEAP_SIZE);
}

int left_child(int parent) {
    return 2 * parent;
}

int right_child(int parent) {
    return 2 * parent + 1;
}

int parent(int child) {
    return child/2;
}

void float_up(heap_t *heap, int i, int v) {
/************** max vs min heap different *******/
    int p;

    p = parent(i);

    if (p == 0) { // The root has been replaced.
        heap->heap_array[ROOT_INDEX] = v;
        return;
    }

    if (v < heap->heap_array[p]) {
        heap->heap_array[i] = heap->heap_array[p];
        float_up(heap, p, v);
    } else {
        // assert v >= heap_array[p]
        heap->heap_array[i] = v;
        return;
    }
}

/*

    Returns 1 if successfully added v to the heap or if v is already in the
    heap. Returns 0 if the v could not be added, e.g. if the heap is full.

*/
int heap_add(heap_t *heap, int v) {

    if (heap_is_full(heap))
        return 0;

    heap->num_entries++;
    float_up(heap, heap->num_entries, v);

    return 1;
}

int smaller_child(heap_t *heap, int i) {
/************** max vs min heap different *******/ // max heap uses larger_child()
    int lc_i, rc_i, smallerc_i;

    lc_i = left_child(i);
    rc_i = right_child(i);

    if (lc_i <= heap->num_entries && rc_i <= heap->num_entries) {
        if (heap->heap_array[lc_i] < heap->heap_array[rc_i])
            smallerc_i = lc_i;
        else
            smallerc_i = rc_i;
    } else if (lc_i <= heap->num_entries) {
        smallerc_i = lc_i;
    } else if (rc_i <= heap->num_entries) {
        smallerc_i = rc_i;
    } else {
        /* i is a node without any children. */
        smallerc_i = 0;
    }

    return smallerc_i;
}

/*

    Returns the index of the larger child of the specified node.


    @param[in] i  The index of a node in the heap.


    @retval j <= 0  If the node does not have children.
    @retval j > 0   If the node has children. If the node has two children, j is
                    the index of the node containing the larger value.
                    Otherwise, j is the index of the one and only child.

*/
int larger_child(heap_t *heap, int i) {
/************** max vs min heap different *******/ // See above.
    int lc_i, rc_i, largerc_i;

    lc_i = left_child(i);
    rc_i = right_child(i);

    if (lc_i <= heap->num_entries && rc_i <= heap->num_entries) {
        if (heap->heap_array[lc_i] > heap->heap_array[rc_i])
            largerc_i = lc_i;
        else
            largerc_i = rc_i;
    } else if (lc_i <= heap->num_entries) {
        /*

            Since the heap is always a complete binary tree, a node with less
            than 2 children can only have a left child. Otherwise it has no
            children. The two blocks below should never execute.
        */
        largerc_i = lc_i;
    } else if (rc_i <= heap->num_entries) {
        largerc_i = rc_i;
    } else {
        /* i is a node without any children. */
        largerc_i = 0;
    }

    return largerc_i;
}

void reheap(heap_t *heap, int i, int v) {
/************** max vs min heap different *******/
    int smallerc_i;

    smallerc_i = smaller_child(heap, i); /************** max vs min heap different *******/

    if(smallerc_i <= 0) {
        heap->heap_array[i] = v;
        return;
    }

    if (v > heap->heap_array[smallerc_i]) {
        heap->heap_array[i] = heap->heap_array[smallerc_i];
        reheap(heap, smallerc_i, v);
    } else {
        heap->heap_array[i] = v;
    }
}

/*

    Returns 1 if the root is successfully removed, returns the root value in v.
    Returns 0 if an error occurred, e.g. the heap is empty.

*/
int heap_rm_root(heap_t *heap, int *v) {

    if (v == NULL)
        return 0;

    if (heap_is_empty(heap))
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
    reheap(heap, ROOT_INDEX, heap->heap_array[ROOT_INDEX]); /************** max vs min heap different *******/
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
    if (l <= 0 || v == NULL)
        return 1;

    /* For now, this operation is only valid for creating a new array. */
    if (!heap_is_empty(heap))
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
        reheap(heap, i, heap->heap_array[i]); /************** max vs min heap different *******/

    return 0;
}

// Print each level of the heap on a separate line.
void _print_heap(heap_t *heap, int n, int start_i) {
    int i;

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
    //static heap_t heap = {1};
    static MIN_HEAP(heap);

    assert(heap.min_or_max_heap == 0);

    heap_create (&heap, v, l);
    print_heap(&heap);
    heap_rm_root(&heap, &t);
    print_heap(&heap);
    return 0;
}