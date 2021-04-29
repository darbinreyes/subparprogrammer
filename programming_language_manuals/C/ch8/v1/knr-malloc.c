/*!
    @header Implementation of malloc() and free() from K&R chapter 8.7
    Example - A Storage Allocator.
    @discussion This is the implementation as presented in the book with my modifications.
*/

#include <stdio.h> // NULL
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "private-knr-malloc.h"
void print_free_list(void);

static Header base; /* empty list get started */
static Header *freep = NULL; /* start of free list */

/* malloc: general-purpose storage allocator */
void *knr_malloc(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned); // [It just occurred to me that this syntax makes it possible to make a function only locally visible. No need to move morecore() above this function, no need to declare morecore() as static.]
    unsigned nunits;

    nunits = NBYTES_TO_NUNITS(nbytes); // [typo here]
    if ((prevp = freep) == NULL) { /* no free list yet */
        base.s.ptr = freep = prevp = &base; // [typo here]
        base.s.size = 0;
    }
    printf("knr_malloc() entry\n");
    print_free_list();

    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) { // [prevp = block before, p = block after] // Note prevp = freep in condition part of if above.
        if (p->s.size >= nunits) { /* big enough */
            if (p->s.size == nunits) /* exactly */
                prevp->s.ptr = p->s.ptr; // [unlink block being returned, which is p]
            else { /* allocate the tail end*/
                p->s.size -= nunits; // [subtract size of block being returned to user]
                p += p->s.size; // [pointer arithmetic]
                p->s.size = nunits; // [size of block being returned]
            }
            freep = prevp; // [next search starts at the block before the one that was found during the current search]
            return (void *)(p+1); // ["the pointer returned to the user points to the free space within the block, which begins one unit beyond the header."]
        }

        if (p == freep) { /* wrapped around free list [therefore, no sufficiently sized block exists, we need to get a big enough block from the OS.]*/
            if ((p = morecore(nunits)) == NULL) // [if morecore() returns non-NULL, the search will resume and terminate at the freshly obtained block. don't worry about the increment part of the loop, morecore() messes with it.]
                return NULL; /* none left [i.e. the OS is telling there is no more free memory.] */
            printf("knr_malloc() AFTER morecore()\n");
            print_free_list();
        }
    }
}

#define NALLOC 1024 /* minimum #units to request [from sbrk] */
/*
    Question: [How to free memory that has been allocated by sbrk()? Can I use munmap?](https://stackoverflow.com/questions/63481614/how-to-free-memory-that-has-been-allocated-by-sbrk-can-i-use-munmap)
    ANS: Call sbrk() with a negative argument in FILO/LIFO (stack) order.
*/
/* morecore: ask system for more memory */
Header *morecore(unsigned nu) // cc errors out on the mismatched use of static. Removed.
{
    char *cp; //, *sbrk(int); // [Why didn't the compiler require that I include <unistd.h>? Is this suppressing the error? ANS: Yes]
    Header *up; // [u = unit]
    void knr_free(void *ap);

    /* "The current value of the program break is reliably returned by sbrk(0)" */
    errno = 0;
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wdeprecated-declarations"
    cp = sbrk(0); // Fixes failure of sbrk() call below.
    #pragma clang diagnostic pop
    if (cp == (char *) -1) { /* no space at all */
        perror("sbrk");
        return NULL;
    }

    printf("current program break = %p\n", (void *)cp);

    if (nu < NALLOC)
        nu = NALLOC;

    errno = 0;
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wdeprecated-declarations"
    cp = sbrk(nu * sizeof(Header)); // [sbrk arg. is in bytes]
    #pragma clang diagnostic pop
    if (cp == (char *) -1) { /* no space at all */
        perror("sbrk");
        return NULL;
    }
    up = (Header *) cp;
    up->s.size = nu;
    knr_free((void *)(up+1)); // [free expects a pointer to the byte after the header info.]"morecore inserts the additional memory into the arena **by calling free**"
    return freep;
}

/* free: put block ap in the free list */
void knr_free(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap - 1; /* point to block header */
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break; /* freed block at start or end of the arena */

    if (bp + bp->s.size == p->s.ptr) { /* join to upper nbr */ // [typo here]
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) { /* join to lower nbr [typo here]*/
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;

    freep = p;
}

#if 0
/*!
    @function main
*/
int main(void) {
    #define STR0 "The lone and level sands stretch far away."
    char *str = STR0;
    int sz = sizeof (STR0);
    char *p;

    p = knr_malloc(sz);

    if (p == NULL) {
        printf("knr_malloc returned NULL\n");
        return 1;
    }

    memcpy(p, str, sz);
    printf("%s\n", p);
    knr_free(p);

    printf("Done.\n");

    return 0;
}

#endif

void print_free_list(void) {
    Header *bp = freep;

    if (bp->s.ptr == bp) {
        printf("List EMPTY.\n");
        return;
    }

    printf("[p=%p, size=%u]->", bp, bp->s.size);

    for (bp = bp->s.ptr; bp != freep; bp = bp->s.ptr) {
        printf("[p=%p, size=%u]->", bp, bp->s.size);
    }

    printf("\n");
    return;
}