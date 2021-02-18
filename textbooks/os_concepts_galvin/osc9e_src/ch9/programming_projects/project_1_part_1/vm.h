/*!
    @header Virtual memory definitions.

*/
#ifndef __VM_H__
#define __VM_H__
/*!
    @defined ADDR_NBITS
    @discussion The number of bits in a virtual address.
*/
#define ADDR_NBITS (16U)

/*!
    @defined PAGE_OFFSET_NBITS
    @discussion The number of bits used to represent a byte offset into a page.
    This must be less than the number of bits in an address.

    @TODO assert(PAGE_OFFSET_NBITS < ADDR_NBITS)
*/
#define PAGE_OFFSET_NBITS (8U)

/*!
    @defined ADDR_UINT_T
    @discussion Unsigned integer type used to represent virtual addresses.
*/
#define ADDR_UINT_T unsigned long

/*!
    @typedef addr_t
    @discussion Typedef for the unsigned integer type used to represent virtual
    addresses.
*/
typedef ADDR_UINT_T addr_t;

/*!
    @defined MAX_V_ADDR
    @discussion The max value of a virtual address is equal to the max unsigned
    integer value that can be represented with the number of bits in a virtual
    address.

*/
#define MAX_V_ADDR ((1UL << ADDR_NBITS) - 1UL)
#endif