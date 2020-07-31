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

// Returns the index of the parent of node i.
int parent_i(int i) {
    assert(i >= 0);

    if (i == 0) // The root node has no parent, indicate this with a negative index.
        return -1;

    // assert: i > 0

    if (i % 2 == 0) // Since i > 0 at this point, and the smallest even number is 2, the return value will never be negative.
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

typedef struct _heap_t {
    int heap[HEAP_SIZE];
    int num_entries; // ! We are using 0 indexing, so the last leaf node is at position num_entries - 1. Valid node indexes are defined by i < num_entries.
} heap_t;

// If i has children, returns the index of the larger child.
int larger_child_i(heap_t * const h, int i) {
    int l, r;

    assert(h != NULL);
    assert(i >= 0);

    l = left_child_i(i);
    r = right_child_i(i);

    if (l < h->num_entries && r < h->num_entries) {
        if (h->heap[l] > h->heap[r])
            return l;
        else
            return r;
    } else if (l < h->num_entries) {
        return l; // Only a left child.
    } else if (r < h->num_entries) {
        return r; // Only a right child.
    } else {
        return -1; // Node i has no children.
    }
}

void reheap(heap_t * const h, int i, int v) {
    int largerc_i;

    // assert: The root node has been removed and the last leaf value has been copied the root node. A reheap transforms a heap in which only the root node is out of place (a.k.a a semiheap) into a heap. OR, we are creating a heap from a given array.
    assert(h != NULL);
    assert(i >= 0);

    largerc_i = larger_child_i(h, i);

    if (largerc_i == -1) { // Node i has no children, no work to do.
        h->heap[i] = v;
        return;
    }

    // Swap the larger child value up towards the root.
    if (h->heap[largerc_i] > v) {
        h->heap[i] = h->heap[largerc_i];
        reheap(h, largerc_i, v);
    } else {
        h->heap[i] = v;
    }
}

int last_leaf_i(heap_t * const h) {
    assert(h != NULL);
    assert(h->num_entries > 0);

    return h->num_entries - 1;
}

void heap_create(heap_t * const h, int a[], int l) {
    int i = 0;

    assert(h != NULL);
    assert(a != NULL);
    assert(l >= 0);
    assert (h->num_entries == 0); // heap_create() is only valid if the heap is empty.

    if (l == 0) // Nothing to do.
        return;

    // Init. heap with array in the given order.
    for (i = 0; i < l; i++) {
        h->heap[i] = a[i];
        h->num_entries++;
    }

    i = parent_i(last_leaf_i(h));

    if (i == -1) // The last leaf is also the root node, i.e. l = 1.
        return;

    // Reheap starting at the parent of the last leaf node and ending at the root node (i.e. reverse level order).
    while (i >= 0) {
        reheap(h, i, h->heap[i]);
        i--;
    }
}


// Print each level of the heap on a separate line.
void _print_heap(heap_t * const h, int n, int start_i) {
    int i;

    assert(h != NULL);

    if (h->num_entries == 0) {
        printf("Heap is empty.\n");
        return;
    }

    for (i = start_i; i < (start_i + n) && i < h->num_entries; i++) {
        printf("%d ", h->heap[i]);
    }

    printf("\n");

    if (i >= h->num_entries) // Done printing.
        return;

    n *= 2; // Each level has 2x the number of nodes as the previous level.
    _print_heap (h, n, i);
}

void print_heap(heap_t * const h) {

    assert(h != NULL);

    _print_heap(h, 1, 0);
}

void print_heap_array (heap_t * const h) {

    assert(h != NULL);

    if (h->num_entries == 0) {
        printf("Heap is empty.\n");
        return;
    }

    for (int i = 0; i < h->num_entries; i++) {
        printf("%d ", h->heap[i]);
    }

    printf("\n");
}

void max_heap_sort (heap_t * const h, int a[], int l) {
    int v;

    assert(h != NULL);
    assert(l >= 0);
    assert(a != NULL);
    assert(h->num_entries > 0);

    // assert: a is a max heap.

    /*

        "The largest item in the array is now

        first in the array,

        so we swap it with the last item in the array,

        The array is now partitioned into a tree region

        and a sorted region."

    */

    // Swap root with last. Array is now partitioned.
    v = h->heap[last_leaf_i(h)];
    h->heap[last_leaf_i(h)] = h->heap[ROOT_INDEX];
    h->heap[ROOT_INDEX] = v;
    a[last_leaf_i(h)] = h->heap[last_leaf_i(h)]; // Return next sorted value.
    h->num_entries--;
    reheap(h, ROOT_INDEX, h->heap[ROOT_INDEX]);
}

void print_array(int a[], int l) {

    while (l-- > 0)
        printf("%d ", *a++);

    printf("\n");
}

int main(void) {
    heap_t h;
    int a[] = {20, 40, 30, 10, 90, 70};
    int a2[64];
    int l = sizeof(a)/sizeof(*a);

    h.num_entries = 0;

    heap_create(&h, a, l);
    print_heap_array(&h);
    print_heap(&h);

    while (h.num_entries > 0)
        max_heap_sort (&h, a2, 64);

    print_array(a2, l);
    return 0;
}