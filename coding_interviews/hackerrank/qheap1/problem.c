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