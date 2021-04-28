#ifndef __PRIVATE_KNR_MALLOC_H__
#define __PRIVATE_KNR_MALLOC_H__

/*!
    @typedef Align
*/
typedef long Align; /* for alignment to long boundary */

/*!
    @union header

    @field s
    @field x
*/
union header { /* block header */
    /*!
        @struct

        @field ptr
        @field size
    */
    struct {
        union header *ptr; /* next block if on free list */
        unsigned size; /* size of this block */
    } s;
    Align x; /* force alignment of blocks */
};

/*!
    @typedef Header
*/
typedef union header Header;

#endif