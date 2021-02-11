/*!
    @header My Malloc
    malloc implementation based on the solution given at the end of chapter 8.

    @discussion
    * Memory will be obtained directly from the OS using the sblk() system call.
    * There should be no restriction on the order of calls to malloc() and
    free().
    * Memory will be managed using a linked list of free blocks.
    * To ensure that blocks are properly aligned for the objects that will be
    stored in them, blocks will consist of multi-byte units.
    * The linked list will be maintained in sorted order according to increasing
    memory address. This will aid in the process of merging adjacent blocks
    during a free() operation. During a malloc() operation, free blocks are
    allocated according to first fit. If the block being malloc'ed() is exactly
    the same size as requested, the block is returned as is, but if the block is
    bigger than requested the tail end of the block is broken off and returned.
    * To spread fragmentation evenly across blocks a search for a free block
    starts where the previous search ended.
    * When a block is free'd() we should merge adjacent blocks if we observe
    them to be contiguous.
    * NULL is returned if there is no more free memory.

*/

typedef long alignt_t; /* We are assuming that a long type has the most restrictive alignment requirements. This ensures that anything stored in our blocks is necessarily aligned. */

typedef union _mblk_t {
    struct {
        union _blk_t *prv;
        union _blk_t *nxt; // Pointer to next block.
        size_t size; // Size of this block in sizeof(mblk_t) units, the header is included in this size, thus all blocks are at least 1 unit in size while size-1 units are available for use by the user.
    } bi; // bi = block info.
    align_t x;
} mblk_t;

mblk_t h; // Handle to list. h.bi.n points to the block at the head of the list. h.bi.n == NULL means the list is empty.

mblk_t *sp; // Search pointer. Points to the block at which the last search for a free block terminated.

/*

As long as the list is not empty, it consists of a circular doubly linked list,
the list is maintained in sorted order according to increasing memory address
size. Free blocks are obtained using the sblk() system call.

*/

#define BLOCKN 1024 // minimum amount of memory requested from sblk() in units i.e. minimum is actually sblk(BLOCKN * sizeof(mblk_t)).

/*!

Returns a free block of memory from the OS given in units. At least nu units are
returned. NULL is returned of we are out of memory.

*/
mblk_t *morecore(size_t nu) {
    char *cp;
    mblk_t *fb; // free block.

    if(nu < BLOCKN)
        nu = BLOCKN;
    cp = sblk(nu * sizeof(mblk_t));

    if (cp == (char *) -1) // This is how sblk() indicates out of mem.
        return NULL;

    fb->bi.nxt = fb;
    fb->bi.prv = fb;
    fb->bi.size = nu;

    return fb;
}

/*!

*/
void *malloc(size_t n) {
    mblk_t *fb = NULL; // free block
    size_t nu = 0;
    mblk_t *beb = NULL; // big enough block

    // initially h.bi.nxt == NULL and sp == NULL

    if(n < sizeof(mblk_t)) {
        nu = 1;
    } else {
        nu = n / sizeof(mblk_t);
        if (n % sizeof(mblk_t) != 0)
            nu++;
    }

    if (h.bi.nxt == NULL) { // Our list is empty
        fb = morecore(nu);
        if (fb == NULL)
            return NULL;
        h.bi.nxt = fb;
        sp = fb;
    }

    fb = sp;
    beb = NULL;

    do {
        if (fb->bi.size >= nu) {
            beb = fb;
            break;
        }
        fb = fb->bi.nxt;
    } while (fb != sp); // As long as we haven't wrapped around.
}