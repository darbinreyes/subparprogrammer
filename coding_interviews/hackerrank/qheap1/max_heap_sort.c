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

// If i has children, returns the index of the larger child.
int larger_child_i(int heap[], int num_entries, int i) {
    int l, r;

    assert(heap != NULL);
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

void reheap(int heap[], int num_entries, int i, int v) {
    int largerc_i;

    // assert: The root node has been removed and the last leaf value has been copied the root node. A reheap transforms a heap in which only the root node is out of place (a.k.a a semiheap) into a heap. OR, we are creating a heap from a given array.

    assert(heap != NULL);
    assert(i >= 0);


    largerc_i = larger_child_i(heap, num_entries, i);

    if (largerc_i == -1) { // Node i has no children, no reheap is necessary.
        heap[i] = v;
        return;
    }

    // Copy the larger child value up towards the root.
    if (heap[largerc_i] > v) {
        heap[i] = heap[largerc_i];
        reheap(heap, num_entries, largerc_i, v);
    } else {
        heap[i] = v;
    }
}

int last_leaf_i(int num_entries) {

    assert(num_entries > 0);

    return num_entries - 1;
}

void heap_create(int a[], int l) {
    int i;

    assert(a != NULL);
    assert(l >= 0);

    if (l <= 1) // Nothing to do.
        return;

    i = parent_i(last_leaf_i(l));

    if (i == -1) // Node i does not have children, nothing to reheap.
        return;

    // Reheap starting at the parent of the last leaf node and ending at the root node (i.e. reverse level order).
    while (i >= 0) {
        reheap(a, l, i, a[i]);
        i--;
    }
}


// Print each level of the heap on a separate line.
void _print_heap(int heap[], int num_entries, int n, int start_i) {
    int i;

    assert(heap != NULL);

    if (num_entries == 0) {
        printf("Heap is empty.\n");
        return;
    }

    // Print nodes in the current level
    for (i = start_i; i < (start_i + n) && i < num_entries; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");

    if (i >= num_entries) // Done printing.
        return;

    n *= 2; // Each level has 2x the number of nodes as the previous level.
    _print_heap (heap, num_entries, n, i);
}

void print_heap(int heap[], int num_entries) {

    assert(heap != NULL);

    _print_heap(heap, num_entries, 1, 0);
}

void print_heap_array (int heap[], int num_entries) {

    assert(heap != NULL);
    assert(num_entries >= 0);

    if (num_entries == 0) {
        printf("Heap is empty.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++)
        printf("%d ", heap[i]);


    printf("\n");
}

// Returns the number of entries at the beginning of the array that form the heap partition. Elements after this partition form the sorted array. Returns 0 when sorting is completed.
int max_heap_sort (int heap[], int num_entries) {
    int v;

    assert(heap != NULL);
    assert(num_entries >= 0);

    if (num_entries == 0 || num_entries == 1) // No sorting work required.
        return 0;

    // assert: a is a max heap.

    /*

        "The largest item in the array is now

        first in the array,

        so we swap it with the last item in the array,

        The array is now partitioned into a tree region

        and a sorted region."

    */

    // Swap root node with last leaf node and decrement number of nodes. Array is now partitioned into a heap part and a sorted part.
    v = heap[last_leaf_i(num_entries)];
    heap[last_leaf_i(num_entries)] = heap[ROOT_INDEX];
    heap[ROOT_INDEX] = v;
    num_entries--;
    reheap(heap, num_entries, ROOT_INDEX, heap[ROOT_INDEX]);

    max_heap_sort (heap, num_entries); // Recursive call.

    return num_entries;
}

void print_array(int a[], int l) {

    if (l == 0) {
        printf("Array is empty.\n");
        return;
    }

    while (l-- > 0)
        printf("%d ", *a++);

    printf("\n");
}

int main(void) {
    int a[] = {20, 40, 30, 10, 90, 70};
    int const l = sizeof(a)/sizeof(*a);

    // Tested l = 0 l = 1, l = 2, l = 6.

    heap_create(a, l);

    print_heap_array(a, l);
    print_heap(a, l);

    max_heap_sort (a, l);

    print_array(a, l);

    return 0;
}