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

#define parent_index(i) ({ \
    assert((i) > 0); \
    ( (i) % 2 == 0 ) ?  ((i)/2 - 1) : ((i)/2); })

#define left_child_index(i) ({ \
    assert((i) >= 0); \
    ((i) * 2 + 1); })

#define right_child_index(i) ({ \
    assert((i) >= 0); \
    ((i) * 2 + 2); })

// If i has children, returns the index of the larger child.
int larger_child_i(int heap[], int num_entries, int i) {
    int l, r;

    assert(heap != NULL);
    assert(i >= 0);

    l = left_child_index(i);
    r = right_child_index(i);

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

#define last_leaf_index(num_entries) ({ \
    assert(num_entries > 0); \
    ( (num_entries) > 0 ) ?  ( (num_entries) - 1) : 0; })


void heap_create(int a[], int l) {
    int i;

    assert(a != NULL);
    assert(l >= 0);

    if (l <= 1) // Nothing to do.
        return;

    i = parent_index(last_leaf_index(l));

    if (i == -1) // Node i does not have children, nothing to reheap.
        return;

    // Reheap starting at the parent of the last leaf node and ending at the root node (i.e. reverse level order).
    while (i >= 0) {
        reheap(a, l, i, a[i]);
        i--;
    }
}

#define array_swap(arr, i, j) ({ \
    typeof((arr)[0]) t = (arr)[(i)]; \
    (arr)[(i)] = (arr)[(j)]; \
    (arr)[(j)] = t; })


// Returns the number of entries at the beginning of the array that form the heap partition. Elements after this partition form the sorted array. Returns 0 when sorting is completed.
void _max_heap_sort (int heap[], int num_entries) {
    assert(heap != NULL);
    assert(num_entries >= 0);

    if (num_entries == 0 || num_entries == 1) // No sorting work required.
        return;

    // assert: a is a max heap.

    /*

        "The largest item in the array is now

        first in the array,

        so we swap it with the last item in the array,

        The array is now partitioned into a tree region

        and a sorted region."

    */

    // Swap root node with last leaf node and decrement number of nodes. Array is now partitioned into a heap part and a sorted part.
    array_swap(heap, last_leaf_index(num_entries) , ROOT_INDEX);

    num_entries--;
    reheap(heap, num_entries, ROOT_INDEX, heap[ROOT_INDEX]);

    _max_heap_sort (heap, num_entries); // Recursive call.
}

void max_heap_sort(int heap[], int num_entries) {
    heap_create(heap, num_entries); // Create the initial heap.
    _max_heap_sort(heap, num_entries);
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

    max_heap_sort (a, l);

    print_array(a, l);

    return 0;
}