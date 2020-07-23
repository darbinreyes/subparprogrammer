/*

    https://www.hackerrank.com/challenges/qheap1/problem

    Success Rate: 67.73%

*/

/* ******* Scratch Work *******
    Notes from Carrano, Chapter 26, A Heap Implementation.

    A heap is a complete binary tree whose nodes are ordered in specific manner.
    In a maxheap each node is greater than or equal to the objects in the nodes
    descendants.

    The interface to a maxheap has the following methods:
    void add(T newEntry)
    T removeMax();
    T getMax();
    isEmpty();
    getSize();
    clear();

    See pg. 714.

    NEXT:

    Finished reviewing heap implementation.
    Might want to use a function pointer for node comparison.
    Implement max heap, convert to min heap.
    Define how to handle array size and how to mark entries as empty.

    The fundamental concept of a heap is the observation that it can be
    represented as a complete binary tree and that a complete binary tree can
    always be represented by an array.

************** */

/* ******* Input Constraints *******

Q >= 1, && Q <= 100000 // Therefore the heap must have a size >= 100000

v >= -1000000000 && v <= 1000000000 // There an int is sufficient to hold values. We can use 2^31 = 2147483648 to mark empty elements in the array.

************** */

#include <stdio.h>
#define HEAP_ARRAY_SIZE 100001
// Our heap array will be 1 based to make indexing simpler.
#define MAX_HEAP_ENTRIES (HEAP_ARRAY_SIZE - 1)
static int num_entries = 0;
static int heap_array[HEAP_ARRAY_SIZE];

#define ROOT_INDEX 1

// Returns 1 if the heap is empty. Returns 0 otherwise.
int heap_is_empty(void) {
    return (num_entries == 0);
}

// Returns 1 if the heap is full. Returns 0 otherwise.
int heap_is_full(void) {
    return (num_entries == MAX_HEAP_ENTRIES);
}


// Returns 1 if v is in the heap. Returns 0 otherwise.
int heap_contains(int v) {

    /*

        This function cannot be implemented by performing an addition of value
        v, for, we can construct two heaps containing value v in which v is
        located. The only thing we can assert is that, if v is greater than the
        root value, then v is certainly not in the heap, otherwise, v may or may
        not be in the heap.

    */
    if(heap_is_empty()) // Heap is empty
        return 0;
    /*

        TODO: can we do this without searching every node. The ADT heap does not
        include this function.

    */
    return 0;
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

void float_up(int i, int v) {
    int p;

    p = parent(i);

    if (p == 0) { // The root has been replaced.
        heap_array[ROOT_INDEX] = v;
        return;
    }

    if (v > heap_array[p]) {
        /*

            Since heap_add() checks heap_contains(), we will never have
            heap_array[i] == heap_array[p] here.

        */
        heap_array[i] = heap_array[p];
        float_up(p, v);
    } else {
        // assert heap_array[i] <= heap_array[p]
        heap_array[i] = v;
        return;
    }
}

/* ******* Scratch Work *******

heap_add(10,85)
=== call 0
i = 10|v = 85
p = 5
if 85 > 30
    heap_array[10] = heap_array[5];
    float_up(5, 85)
=== call 1
i = 5|v = 85
p = 2
if 85 > 80
    heap_array[5] = heap_array[2];
    float_up(2, 85)
=== call 2
i = 2|v = 85
p = 1
if 85 > 90 // false.

else // true
    heap_array[2] = 85;
***********************
Continuing at call 2 with v := 91.
=== call 2
i = 2|v = 91
p = 1
if 91 > 90
    heap_array[2] = heap_array[1];
    float_up(1, 91)
=== call 3
i = 1|v = 91
p = 0

*******

statement|i  |v  |p
---------|---|---|---
0        |1  |91 |0

******* ******* */

/*

    Returns 1 if successfully added v to the heap or if v is already in the
    heap. Returns 0 if the v could not be added, e.g. if the heap is full.

*/
int heap_add(int v) {
    // if value v is already in the heap.
    if (heap_contains(v)) // TODO:
        return 1;

    if (heap_is_full())
        return 0;

    num_entries++;
    float_up(num_entries, v);

    return 1;
}

/* ******* ******* */
/* reheapv2() is the reheap implementation as implemented
by Data Structures, Carrano. */

/*

    Returns 1 if the node identified by `i` has a child. Returns 0 otherwise, in
    this case, by definition, `i` is a leaf node.

*/
int has_child(int i) {
    int lc_i, rc_i;

    lc_i = left_child(i);
    rc_i = right_child(i);

    if (lc_i <= num_entries || rc_i <= num_entries)
        return 1;

    return 0;
}

/*

    Returns the index of the larger child of the specified node.


    @param[in] i  The index of a node in the heap.


    @retval j <= 0  If the node does not have children.
    @retval j > 0   If the node has children. If the node has two children, j is
                    the index of the node containing the larger value.
                    Otherwise, j is the index of the one and only child.

*/
int larger_child(int i) {
    int lc_i, rc_i, largerc_i;

    lc_i = left_child(i);
    rc_i = right_child(i);

    if (lc_i <= num_entries && rc_i <= num_entries) {
        /* Never equal since we aren't allowing duplicates. */
        if (heap_array[lc_i] > heap_array[rc_i])
            largerc_i = lc_i;
        else
            largerc_i = rc_i;
    } else if (lc_i <= num_entries) {
        /*

            Since the heap is always a complete binary tree, a node with less
            than 2 children can only have a left child. Otherwise it has no
            children. The two blocks below should never execute.
        */
        largerc_i = lc_i;
    } else if (rc_i <= num_entries) {
        largerc_i = rc_i;
    } else {
        /* i is a node without any children. */
        largerc_i = 0;
    }

    return largerc_i;
}

void reheapv2(int root_index) {
    /* Transforms the semiheap rooted at root_index into a heap */
    int done = 0;
    int orphan = heap_array[root_index];
    int larger_child_index;

    while (!done &&  (larger_child_index = larger_child(root_index)) > 0) {
        if (orphan < heap_array[larger_child_index]) {
            heap_array[root_index] = heap_array[larger_child_index];
            root_index = larger_child_index;
        } else
            done = 1;
    }

    heap_array[root_index] = orphan;
}

/* ******* ******* */


void reheap(int i, int v) {
    int largerc_i;

    largerc_i = larger_child(i)

    if(largerc_i <= 0) {
        heap_array[i] = v;
        return;
    }

    // assert node at position i has two children or 1 left child.

    if (v < heap_array[largerc_i]) {
        heap_array[i] = heap_array[largerc_i];
        reheap(largerc_i, v);
    } else {
        /*

            assert v >= heap_array[largerc_i]
            Since duplicates are not allowed we can assert
            assert v > heap_array[largerc_i]

            i.e. v is greater than the largest child of node i, therefore v
            should be the parent of heap_array[largerc_i].

        */
        heap_array[i] = v;
    }
}

/*

    Returns 1 if the root is successfully removed, returns the root value in v.
    Returns 0 if an error occurred, e.g. the heap is empty.

*/
int heap_rm_root(int *v) {

    if (v == NULL)
        return 0;

    if (heap_is_empty())
        return 0;

    if (num_entries == 1) { // Single entry in the heap, return the root.
        *v = heap_array[num_entries];
        num_entries--;
        return 1;
    }

    // assert num_entries > 1

    /*

        The standard algorithm is: 1. Place the last leaf at the root, this
        forms a "semi-heap" 2. Perform a re-heap to create a heap again.

    */
    *v = heap_array[ROOT_INDEX];
    heap_array[ROOT_INDEX] = heap_array[num_entries];
    num_entries--;
    reheap(ROOT_INDEX, heap_array[ROOT_INDEX]);
    return 1;
}

/*

    int  heap_create(int a[], int l);

    Creating a heap from a given array of values.

    The most obvious implementation of this is to use the heap_add() function
    on each value in the given array. Since the real work in heap_add() is done
    by the float_up() function, and the float_up() function is O(log.n), adding
    n entries is O(n * log.n).

    We can do better by exploiting the reheap() function. The observation that
    leads to this improvement is that using heap_add() maintains the defining
    heap property at each addition. But we if we only need the final state of
    the array to be a heap, then we have some flexibility in the intermediate
    steps leading up to the a heap upon termination. We can implement
    heap_create() with O(n) by maintaining a semiheap at each intermediate step.
    The final reheap operation produces a heap.

    The algorithm is:

    1. Place the given array into the heap array in the given order.

    2. Starting from the last leaf, continuing in reverse level order, we reheap
    at every node until we reach the root. The final reheap that occurs at the
    root produces a heap. [Note that the reheap operation is a recursive
    operation, therefore a reheap at the root of a tall binary tree
    potentially recurses from the very top down to the leaf nodes.]

*/

int main(void) {
    return 0;
}
