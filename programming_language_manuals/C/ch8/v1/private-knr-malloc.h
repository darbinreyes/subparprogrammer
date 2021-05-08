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

/*!
    @defined NBYTES_TO_NUNITS
    @discussion Round up size in bytes to the nearest multiple of sizeof(Header). + 1 unit for the header
*/
#define NBYTES_TO_NUNITS(nb) ( ( (nb) + sizeof(Header) - 1)/sizeof(Header) + 1 )

#endif