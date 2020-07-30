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

v >= -1000000000 && v <= 1 000 000 000 // Therefore an int is sufficient to hold values. We can use 2^31 = 2 147 483 648 to mark empty elements in the array.

************** */

#include <stdio.h>
#include <stdlib.h>

#define HEAP_ARRAY_SIZE 100001
// Our heap array will be 1 based to make indexing simpler.
#define HEAP_SIZE (HEAP_ARRAY_SIZE - 1)
static int num_entries = 0;
static int heap_array[HEAP_ARRAY_SIZE];

#define ROOT_INDEX 1

// Returns 1 if the heap is empty. Returns 0 otherwise.
int heap_is_empty(void) {
    return (num_entries == 0);
}

// Returns 1 if the heap is full. Returns 0 otherwise.
int heap_is_full(void) {
    return (num_entries == HEAP_SIZE);
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

    if (v < heap_array[p]) {
        heap_array[i] = heap_array[p];
        float_up(p, v);
    } else {
        // assert v >= heap_array[p]
        heap_array[i] = v;
        return;
    }
}

/*

    Returns 1 if successfully added v to the heap or if v is already in the
    heap. Returns 0 if the v could not be added, e.g. if the heap is full.

*/
int heap_add(int v) {

    if (heap_is_full())
        return 0;

    num_entries++;
    float_up(num_entries, v);

    return 1;
}

int smaller_child(int i) {
    int lc_i, rc_i, smallerc_i;

    lc_i = left_child(i);
    rc_i = right_child(i);

    if (lc_i <= num_entries && rc_i <= num_entries) {
        if (heap_array[lc_i] < heap_array[rc_i])
            smallerc_i = lc_i;
        else
            smallerc_i = rc_i;
    } else if (lc_i <= num_entries) {
        smallerc_i = lc_i;
    } else if (rc_i <= num_entries) {
        smallerc_i = rc_i;
    } else {
        /* i is a node without any children. */
        smallerc_i = 0;
    }

    return smallerc_i;
}

void reheap(int i, int v) {
    int smallerc_i;

    smallerc_i = smaller_child(i);

    if(smallerc_i <= 0) {
        heap_array[i] = v;
        return;
    }

    if (v > heap_array[smallerc_i]) {
        heap_array[i] = heap_array[smallerc_i];
        reheap(smallerc_i, v);
    } else {
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

    Returns 1 if value v was removed from the heap. Returns 0 otherwise.

*/
int heap_rm_value(int v) {
    int i;

    if (heap_is_empty())
        return 0;

    for (i = 1; i <= num_entries; i++) {
        if (heap_array[i] == v)
            break;
    }

    if (i > num_entries)
        return 0; // v was not in the heap.

    // treat removing value v as removing the root of the heap rooted at i.
    heap_array[i] = heap_array[num_entries];
    num_entries--;
    reheap(i, heap_array[i]);

    return 1;
}

int heap_peek_root(int *v) {
    if (v == NULL)
        return 0;

    if (heap_is_empty())
        return 0;

    *v = heap_array[ROOT_INDEX];
    return 1;
}

// Print each level of the heap on a separate line.
void _print_heap(int n, int start_i) {
    int i;

    for (i = start_i; i < (start_i + n) && i <= num_entries; i++) {
        printf("%d ", heap_array[i]);
    }

    printf("\n");

    if (i > num_entries)
        return;

    n *= 2;
    _print_heap (n, i);
}

void print_heap(void) {
    _print_heap(1, 1);
}


int main(void) {
    /*
    int v[] = {90, 80, 60, 70, 30, 20, 50, 10, 40};
    int l = sizeof(v)/sizeof(v[0]);
    int i, t;

    for (i = 0; i < l; i++)
        heap_add(v[i]);

    print_heap();
    heap_rm_root(&t);
    print_heap();
    heap_rm_value(90);
    print_heap();
    */

    /* The hackerrank problem specifies deleting a specific
    element from the heap, but this is not a standard method
    of the heap ADT. This could be implemented by reheaping to
    fill the empty spot created by removing an element.

    I have implemented this operation in heap_rm_value(). */
    char line[32];
    int Q, op, v;

    gets(line);

    Q = atoi(line);

    if (Q == 0)
        return 0; // Nothing to do.

    while (Q > 0) {
        gets(line);

        if (line[0] == '1') {
            sscanf(line, "%d %d", &op, &v);
            heap_add(v);
        } else if (line[0] == '2') {
            sscanf(line, "%d %d", &op, &v);
            heap_rm_value(v);
        } else if (line[0] == '3') {
            heap_peek_root(&v);
            printf("%d\n", v);
        } else {
            return 1; // Invalid query type.
        }
        Q--;
    }


    // Solved.

    return 0;
}
