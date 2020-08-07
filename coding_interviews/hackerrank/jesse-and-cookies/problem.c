/*

    https://www.hackerrank.com/challenges/jesse-and-cookies/problem

    Success Rate: 67.21%

*/

/* Scratch Work.

We are given an array of integers `A` whose size is N ([1, 1 000 000])
and whose members `A[i]` are all non-negative ([0, 1 000 000]).

We are also given a non-negative integer `k` ([0, 1 000 000 000]).

The task is:

repetition

`n` = 0

while len(`A`) > 1 && !all_greater_than_or_equal_to(`A`, `k`) {

remove the two least members from `A`, call them `c0`, `c1`.
compute `cn` =  c0 + 2 * c1
place `cn` in A.
n++

}

assert: len(`A`) <= 1 || all_greater_than_or_equal_to(`A`, `k`)

if len(`A`) == 1 && `A[0]` < k
    return -1 // means no solution is possible.


return `n`

*/

/* Scratch Work.


We could try starting with a sorted array, but as we are removing and then adding
items to the array this would require resorting O(n^2) each time we remove or add an item.
We can avoid resorting by because the array is sorted, insertion is O(n).

Using a sorted linked list would also involve O(n) insertion.

Since we are removing the minimum element in each iteration, a min heap seems
appropriate. Adding and removing is O(log.n).

Other considerations:

* When should we return -1?
  * As soon as len(`A`) and `A[last]` < k, no solution is possible.


if k == 0, we can immediately return 0, since each element in the array is
bounded by [0, 1 000 000] and it is given that the array contains at least 1
element.

Variable sizes:

Does `k` fit in an int? Yes.

What about the array `A`? In the worst case, we might end up with a value =
N_max * A_i_max = 10^6 * 10^6 = 10^12, this suggests that we should use
**long.**

Plan:

Insert my min heap implementation from a previous problem

Add code to create a min heap from the array 'A'.

Implement `all_greater_than_or_equal_to()`

Implement while loop above using min heap operations.


*/

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

    Constructs a heap from the given array of values.

    @param[in] v The array of values.
    @param[in] l The length of the array.

    @retval 0 If successful.
    @retval 1 Otherwise, an error occurred.

*/
int  heap_create(int *v, int l) {
    int i;
    if (l <= 0 || v == NULL)
        return 1;

    /* For now, this operation is only valid for creating a new array. */
    if (!heap_is_empty())
        return 1;

    if (l > HEAP_SIZE) /* Given array is too large. */
        return 1;

    /* Fill the heap array in the same order as given */
    for (i = 0; i < l; i++)
        heap_array[i + 1] = v[i];

    num_entries = l;

    /*

        Perform a reheap at every node starting from the last node, up to and
        including the root node. Since reheaping a single node is a no-op we
        should skip calling reheap on any leaf nodes. This is achieved by
        starting the  reheaps at the parent node of the last leaf, which is node
        num_entries/2.

    */
    for (i = num_entries/2; i > 0; i--)
        reheap(i, heap_array[i]);

    return 0;
}


int main(void) {
    return 0;
}