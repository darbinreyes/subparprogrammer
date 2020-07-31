/*

    See problem.c for problem solution.

    The problem specifies a min heap be used, this is my implementation of a max
    heap, which I then turned into a min heap implementation.

    maxheap_sort.c is an implementation of the "heap sort" algorithm, which is
    based on the idea sorting by placing items into a max heap and then removing
    the root node 1 at a time until the max heap is empty.

*/
#include <stdio.h>
#include <assert.h>

/*

    Notes from Carrano on "using a heap to sort an array", a.k.a. heap sort.

    Algorithm v0:

        Place all array entries into the heap.
        Remove the root 1 at a time.

    Algorithm v1:

        The sorting can be done with less memory and less operations if we don't
        use the heap ADT. We want to sort a given array in place, without using
        an extra array inside the heap ADT. Also sorting algorithms in general
        always sort in place. Also, our heap ADT uses 1 based indexing, but for
        sorting in place we need to adapt our heap code to use 0 based
        indexing.

        We want to mimic  the max heap's array based implementation.

        1. Call reheap repeatedly on the array, like our heap_create(a[]).




*/

#define ROOT_INDEX 0

int parent_i(int i) {
    assert(i >= 0);

    if (i == 0) // The root node has no parent.
        return -1;

    if (i % 2 == 0)
        return i / 2 - 1;
    else
        return i / 2;
}

int left_child_i(int i) {
    assert(i >= 0);
    return i * 2 + 1;
}

int right_child_i(int i) {
    assert(i >= 0);
    return i * 2 + 2;
}

#define HEAP_SIZE 64

static int heap[HEAP_SIZE];
static int num_entries = 0; // ! We are using 0 indexing, so the last leaf node is at position num_entries - 1. Valid node indexes are defined by i < num_entries.

int larger_child_i(int i) {
    int l, r;

    assert(i >= 0);

    l = left_child_i(i);
    r = right_child_i(i);

    if (l < num_entries && r < num_entries) {
        if (heap[l] > heap[r])
            return l;
        else
            return r;
    } else if (l < num_entries) {
        return l; // Only a left child.
    } else if (r < num_entries) {
        return r; // Only a right child.
    } else {
        return -1; // Node i has no children.
    }
}

void reheap(int i, int v) {
    int largerc_i;
    // assert: The root node has been removed and the last leaf value has been copied the root node. A reheap transforms a heap in which only the root node is out of place (a.k.a a semiheap) into a heap.

    assert(i >= 0);

    largerc_i = larger_child_i(i);

    if (largerc_i == -1) { // Node i has no children.
        heap[i] = v;
        return;
    }

    // Copy the larger child value up towards the root.
    if (heap[largerc_i] > v) {
        heap[i] = heap[largerc_i];
        reheap(largerc_i, v);
    } else {
        heap[i] = v;
    }
}

int last_leaf_i(void) {
    assert(num_entries > 0);

    return num_entries - 1;
}

void heap_create(int a[], int l) {
    int i = 0;

    assert (num_entries == 0);

    assert(l >= 0);
    assert(a != NULL);

    if (l == 0) // Nothing to do.
        return;

    // Init. heap with as is array.
    for (i = 0; i < l; i++) {
        heap[i] = a[i];
        num_entries++;
    }

    // Reheap starting at the parent of the last leaf node ending at the root (reverse level order).
    i = parent_i(last_leaf_i());

    if (i == -1) // The last leaf is also the root node, i.e. l = 1.
        return;

    while (i >= 0) {
        reheap(i, heap[i]);
        i--;
    }
}


// Print each level of the heap on a separate line.
void _print_heap(int n, int start_i) {
    int i;

    for (i = start_i; i < (start_i + n) && i < num_entries; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");

    if (i >= num_entries)
        return;

    n *= 2;
    _print_heap (n, i);
}

void print_heap(void) {
    _print_heap(1, 0);
}

void print_heap_array (void) {
    for (int i = 0; i < num_entries; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

void max_heap_sort (int a[], int l) {
    int v;

    assert(l >= 0);
    assert(a != NULL);
    assert(num_entries > 0);
    // assert: a is a max heap.

    /*

        "The largest item in the array is now

        first in the array,

        so we swap it with the last item in the array,

        The array is now partitioned into a tree region

        and a sorted region."

    */

    // Swap root with last. Array is now partitioned.
    v = heap[last_leaf_i()];
    heap[last_leaf_i()] = heap[ROOT_INDEX];
    heap[ROOT_INDEX] = v;
    a[last_leaf_i()] = heap[last_leaf_i()];
    num_entries--;
    reheap(ROOT_INDEX, heap[ROOT_INDEX]);
}
void print_array(int a[], int l) {
    while (l-- > 0)
        printf("%d ", *a++);

    printf("\n");
}
int main(void) {
    int a[] = {20, 40, 30, 10, 90, 70};
    int a2[64];
    int l = sizeof(a)/sizeof(*a);
    heap_create(a, l);
    print_heap_array();
    print_heap();
    while (num_entries > 0)
        max_heap_sort (a2, 64);

    print_array(a2, l);
    return 0;
}