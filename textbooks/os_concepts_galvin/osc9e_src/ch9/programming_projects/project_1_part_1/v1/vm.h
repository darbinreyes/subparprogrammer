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
    This must be less than the number of bits in a virtual address.

    @TODO assert(PAGE_OFFSET_NBITS < ADDR_NBITS)
*/
#define PAGE_OFFSET_NBITS (8U)

/*!
    @defined ADDR_UINT_T
    @discussion Unsigned integer type used to represent virtual addresses. The
    use of unsigned long here instead of e.g. unsigned short is to make it
    easier to change the size of virtual addresses. Nothing is lost in terms of
    correctness by doing this. This program was implemented and tested on a
    machine having sizeof(unsigned long) == 8.
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

/*!
    @defined PAGE_SIZE
    @discussion The size of a page in bytes.
*/
#define PAGE_SIZE (1UL << PAGE_OFFSET_NBITS)

/*!
    @defined V_MEM_SIZE
    @discussion The size of virtual memory in bytes.
*/
#define V_MEM_SIZE (1UL << ADDR_NBITS)

/*!

    @discussion WITH_MODIFICATIONS - compile time environment variable that
    reduces the size of physical memory as described under the "Modifications"
    section of the project description. All this does is reduce the size of the
    physical address space to half that of the virtual address space.
    Specifically, physical memory is reduced from 256 page frames to 128 page
    frames. To compile use `cc *.c -DWITH_MODIFICATIONS`, otherwise compile with
    `cc *.c` to use 256 page frames.

*/
#ifdef WITH_MODIFICATIONS
    /*!
        @defined P_MEM_SIZE
        @discussion The size of physical memory in bytes.
    */
    #define P_MEM_SIZE (128 * PAGE_SIZE)
#else
    /*!
        @defined P_MEM_SIZE
        @discussion The size of physical memory in bytes, equal to the size of
        the virtual address space.
    */
    #define P_MEM_SIZE V_MEM_SIZE
#endif

/*!
    @defined BACKING_STORE_SIZE
    @discussion The size of the backing store in bytes.
*/
#define BACKING_STORE_SIZE V_MEM_SIZE

/*!
    @defined PAGE_TABLE_LEN
    @discussion The length of the page table.
*/
#define PAGE_TABLE_LEN (V_MEM_SIZE/PAGE_SIZE)

/*!
    @defined NUM_PAGE_FRAMES
    @discussion The total number of page frames.
*/
#define NUM_PAGE_FRAMES (P_MEM_SIZE/PAGE_SIZE)

/*!
    @defined NUM_BS_PAGES
    @discussion The size of the backing store divided by the size of a page.
*/
#define NUM_BS_PAGES (BACKING_STORE_SIZE/PAGE_SIZE)

/*!
    @typedef pg_tbl_entry_t

    @discussion Represents a page table entry.

    @field fn Frame number.

    @field im In Memory. 1 = the page is in memory in page frame number fn,
    0 = page fault, page is on the backing store.

    Other fields that could be included in the page table are:
    mode:3,    // UNIX style rwx permissions for this page.
    cp_on_w:1, // 1 = This page is copy-on-write, 0 = not copy-on-write.
    locked:1,  // 1 = This page is locked into memory by the OS, it cannot be
                  kicked out/replaced. Also called a "wired" in page.
    dpl:2;     // On x86, this could be a memory descriptor privilege level
                  (DPL). A value of 0 means this page contains memory accessible
                  only by the kernel. 3 means this is a user level page.

*/
typedef struct _pg_tbl_entry_t {
    addr_t fn;
    unsigned char im:1;
} pg_tbl_entry_t;

#endif