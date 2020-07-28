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



int main(void) {
    return 0;
}
