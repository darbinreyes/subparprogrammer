/*

    See problem.c for problem solution.

    The problem specifies a min heap be used, this is my implementation of a max
    heap, which I then turned into a min heap implementation.

    maxheap_sort.c is an implementation of the "heap sort" algorithm, which is
    based on the idea sorting by placing items into a max heap and then removing
    the root node 1 at a time until the max heap is empty.

*/


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

int main(void) {
    int a[] = {20, 40, 30, 10, 90, 70};
    return 0;
}