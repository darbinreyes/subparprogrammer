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

#define HEAP_ARRAY_SIZE 100001
#define MAX_HEAP_ENTRIES (HEAP_ARRAY_SIZE - 1) // Our heap array will be 1 based to make indexing simpler.
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
    if(heap_is_empty()) // Heap is empty
        return 0;
    // TODO: can we do this without searching every node. The ADT heap does not include this function.
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

    if (v > heap_array[p]) { // Since heap_add() checks heap_contains(), we will never have heap_array[i] == heap_array[p] here.
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

// Returns 1 if successfully added v to the heap or if v is already in the heap. Returns 0 if the v could not be added, e.g. if the heap is full.
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

void reheap(int i, int v) {
    int lc_i, rc_i, largerc_i;

    lc_i = left_child(i);
    rc_i = right_child(i);

    if (lc_i <= num_entries && rc_i <= num_entries) {
        if (heap_array[lc_i] > heap_array[rc_i]) // Never equal since we aren't allowing duplicates.
            largerc_i = lc_i;
        else
            largerc_i = rc_i;
    } else if (lc_i <= num_entries) {
        // Since the heap is always a complete binary tree, a node with less than 2 children can only have a left child. Otherwise it has no children.
        largerc_i = lc_i;
    } else {
        // i is a node without any children.
        largerc_i = -1;
    }

    if(largerc_i == -1) {
        heap_array[i] = v;
        return;
    }


    // assert node at position i has two children or 1 left child.

    if (v < heap_array[largerc_i]) {
        heap_array[i] = heap_array[largerc_i];
        reheap(largerc_i, v);
    } else {
        // assert v >= heap_array[largerc_i]
        // Since duplicates are not allowed we can assert
        // assert v > heap_array[largerc_i]
        // i.e. v is greater than the largest child of node i, therefore v should be the parent of heap_array[largerc_i].
        heap_array[i] = v;
        return;
    }
}

// Returns 1 if the root is successfully removed, returns the root value in v. Returns 0 if an error occurred, e.g. the heap is empty.
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

    // The standard algorithm is: 1. Place the last leaf at the root, this forms a "semi-heap" 2. Perform a re-heap to create a heap again.
    *v = heap_array[ROOT_INDEX];
    heap_array[ROOT_INDEX] = heap_array[num_entries];
    num_entries--;
    reheap(ROOT_INDEX, heap_array[ROOT_INDEX]);
    return 1;
}

int main(void) {
    return 0;
}
