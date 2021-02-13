/*!

    @header Chapter 9 Programming Project: Designing a Virtual Memory Manager
    @discussion
    * A program that translates logical to physical addresses.
    * Virtual address space size: 2^16 = 65536.
    * Given a file containing **logical addresses**.
    * We will simulate the use of a TLB and a page table.
    * Each logical address will be translated to its physical address.

Specifics
===
    * The given file containing logical addresses is a list of
      **32-bit integers**.
    * You should mask off the rightmost 16-bits of each logical address.
    * The 16-bit values are to be divided into an 8-bit page number and an 8-bit
      page offset: viz. bits[15:8] = page number bits[7:0] = offset.
    * Other specifics:
    * 2^8 entries in the page table.
      (= size_of_virtual_address_space/size_of_a_page = 2^16/2^8 = 2^8 = 256).
    * Page size of 2^8 bytes.
      (= 2^(number_of_bits_in_page_offset_field_of_logical_address)).
    * A TLB with space for 16 entries. (=2^4).
      (Key=Page Number, Value=Frame Number).
    * Frame size of 2^8 bytes. (frame size always = page size = 2^8 bytes).
    * 256 frames. (This implies that the physical address space =
      number_of_frames * frame_size = 2^8 * 2^8 = 2^16 bytes, therefore the
      virtual address space size == the physical address space size.)
    * Physical memory of 65536 bytes = 2^16 bytes. (Hence above bullet point).
    * Your program only needs to support reading physical address, not writing
      to physical addresses.

Address Translation
===
    * Again, translation will involve both a TLB and a page table.
    * 1. Extract page number from logical address. (Read address from a line in
      file addresses.txt, mask out the low order 16 bits, take bits[15:8] as the
      page number).
      2. Consult the TLB to translate the page number to a frame number.
      If we have a TLB-hit, the TLB provides the frame number, the physical
      address = <frame_number , page offset>.
      else, we have a TLB-miss, we consult the page-table for the frame number,
      again the physical address = <frame_number , page offset>.
      If page table does not contain the frame number, a **page fault** has
      occurred. Thus the page is not in memory, it must be read in from the
      backing store into physical memory.

Handling Page Faults
===
    * The program will implement demand paging, i.e. a page is read into
      physical memory from the backing store only when a page fault occurs.
    * The backing store is represented by the given file BACKING_STORE.bin. This
      is a binary file 65536 bytes in size.
    * When a page fault occurs, a 256-byte page should be read in from the .bin
      file into physical memory.
    * Example: Page number 15 results in a page fault -> read in page number 15
      from the backing store into physical memory -> update the page table and
      TLB. All subsequent accesses to page number 15 should be resolved in the
      TLB or the page table. (After being brought into memory, page number 15
      should never result in a page fault, since this project specifies that the
      physical address space size = the virtual address space size, therefore no
      page every gets kicked out of physical memory. In practice, the physical
      address space size is the lesser, and we must replace pages in physical
      memory according to some page replacement strategy, such as FIFO, LRU,
      MRU, LFU, MFU, or ideally "OPT". Furthermore, this project specifies a
      very simplified algorithm for locating a page on the backing store when a
      page fault occurs, viz. the size of the virtual address space = the size
      of the backing store, and the page resides on the backing store exactly
      where it resides in the virtual address space. In practice, a page fault
      causes a trap to the OS, and the OS consults some internal table
      associated with the page faulting process that indicates where on the
      backing store the page resides e.g. if the backing store is a hard disk,
      then some sort of cylinder-head-sector based address.)
    * It is given that you treat BACKING_STORE.bin as a random access file using
      the standard C lib. functions fseek(), fread(), etc. .
    * This part of the project does not require the use of a page replacement
      strategy since the virtual address space size = the physical address space
      size, and all of physical address space is available for demand paging. In
      practice, part of physical memory must be used for the e.g. OS, and MMI/O.

Test File
===
    * addresses.txt contains the logical addresses to be translated, one address
      per line. The byte value read from the corresponding physical address
      should be output as a signed char value.

How to Begin
===
    * Start by obtaining the page number and page offset.
    * Start without a TLB, use a page table only, add the TLB after you verify
    the program is correct using the page table only. Recall the TLB only speeds
    things up, like normal the normal CPU caches.
    * Recall that the TLB only has 16 entries, so a replacement strategy will be
      requireD: use FIFO or LRU.

How to Run Your Program
===
    * Example: `./a.out addresses.txt`
    * addresses.txt contains 1000 logical addresses.
    * The program should output 3 values as indicated in the file correct.txt.

Statistics
===
    * The program should report:
    1. page-fault rate = percent of address references that results in a page
    fault.
    2. TLB-hit rate = percent of address references that were resolved in the
    TLB. (My remark: nice to have, implement and compare FIFO vs. LRU TLB entry
    replacement).
    * It is noted that addresses.txt was generated randomly, therefore do not
      expect a high TLB hit rate. In practice, real programs exhibit memory
      access locality.

My Remarks
===
    * It is manifest that it is up to me to decide where in physical memory a
      page being being read in from the backing store should be placed. The
      simplest choice seems to be the next free page of physical memory, we can
      simple fill physical memory starting from lowest page number up the
      highest page number.

Modifications
===
    * I will treat this as "part 2" of the project.
    * "Suggested": use a physical address space that is smaller than the virtual
      address space, specifically, make the physical address space 128 page
      frames instead of 256 page frames. This will require that you keep track
      of free page frames and that you implement a page replacement strategy:
      use either FIFO or LRU page replacement.
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

/*!
    @defined ADDR_UINT_T
    @discussion Unsigned integer type used to represent virtual addresses.
*/
#define ADDR_UINT_T unsigned short

/*!
    @typedef addr_t
    @discussion Typedef for the unsigned integer type used to represent virtual
    addresses.
*/
typedef ADDR_UINT_T addr_t;

/*!
    @defined ADDR_NBITS
    @discussion The number of bits in a virtual address.
*/
#define ADDR_NBITS (sizeof(addr_t) * 8)

/*!
    @defined MAX_V_ADDR
    @discussion The max value of a virtual address is equal to the max unsigned
    integer value that can be represented with the number of bits in a virtual
    address.

*/
#define MAX_V_ADDR ((addr_t)~0UL)

/*
    // @TODO Why didn't this work???? //#define MAX_V_ADDR (~((addr_t)0U))
    $ a.out addresses_error.txt
    ...
    line # 999.
    line is 45563
    Virtual address # 998. 45563 = 0xB1FB
    line # 1000.
    line is 66666
    Virtual address # 999. 1130 = 0x46A
    Done.
*/

/*!
    @defined MAX_V_ADDR_UL
    @discussion MAX_V_ADDR value type cast to an unsigned long. Used for
    verifying that addresses read from addresses.txt are within the valid range
    for virtual addresses. addresses.txt is parsed using strtol(), hence the use
    of long.
*/
#define MAX_V_ADDR_UL ((unsigned long) MAX_V_ADDR)


/*!
    @defined MAX_NUM_V_ADDRS
    @discussion The max number of virtual addresses allowed in the addresses.txt
    file.
*/
#define MAX_NUM_V_ADDRS 1000U

static addr_t vaddrs[MAX_NUM_V_ADDRS]; /* Array of virtual addresses read
                                              from addresses.txt. It is given
                                              that each address fits in a 16-bit
                                              integer and that there are 1000 of
                                              them. */

/*!
    @defined V_ADDR_STR_SIZE
    @discussion Size of temporary string buffer for use with fgets() when
    reading addresses.txt line by line. Although the initial implementation of
    this program uses 16-bit virtual addresses the buffer size used here assumes 64-bits so that this value need
    not be updated if the number of bits in a virtual address is increased. The
    buffer size calculation is:
    2^64 - 1
    = (decimal, 20 digits) 18446744073709551615
    = (octal, 22 digits) 1777777777777777777777
    = (decimal, 2+20 digits) 0x18446744073709551615 // Allowing for leading 0x
    = (octal, 1+22 digits) 01777777777777777777777  // Allowing for leading 0
    = (decimal, 1+2+20 digits) -0x18446744073709551615 // Allowing for leading 0x and sign
    = (octal, 1+1+22 digits) -01777777777777777777777  // Allowing for leading 0 and sign
    Thus we conclude 1+1+22 = 24 characters are required to read a virtual
    address value as a string. Adding +1 for a null terminator and +1 for a
    potential new line character yields a final total of 26 characters.
    Finally,the value is arbitrarily increased to 32, the next nearest power of
    2.
*/
#define V_ADDR_STR_SIZE (32)

/*!
    @function init_vaddrs
    @discussion Initializes the vaddrs array according to the contents of the
    given filename.
    @param vaddrs_fname The filename of the file from which to read the virtual
    addresses.
    @result 0 if successful, otherwise error. The program should terminate.
*/
int init_vaddrs(const char *vaddrs_fname) {
    FILE *vaddrs_fp = NULL;
    size_t i = 0, ln = 1;
    unsigned long t_vaddr = 0;
    char *endptr = NULL;
    char t_addr_str[V_ADDR_STR_SIZE];

    if (vaddrs_fname == NULL) {
        assert(0);
        return 1;
    }

    errno = 0; // Per man page.
    vaddrs_fp = fopen (vaddrs_fname, "r");

    if (vaddrs_fp == NULL) {
        printf("fopen(\"r\") returned NULL! filename = %s. error = %s.\n", \
               vaddrs_fname, strerror(errno));
        return 2;
    }

    errno = 0;
    while (!feof(vaddrs_fp)) {

        if(!fgets(t_addr_str, sizeof(t_addr_str), vaddrs_fp)) {
            // EOF or error occurred.

            /* FYI: If the file ends with a empty line then fgets() must be
               called a number of times equal to the number of virtual addresses
               in the file plus one in order to reach EOF. Hence this break.*/
            printf("FYI: fgets() returned NULL.\n");
            break;
        }

        printf("line # %lu.\n", ln++);

        if (!strcmp(t_addr_str, "\n")) // Skip blank lines.
            continue;

        if (*t_addr_str == '\0') {
            printf("Unexpected empty string!\n");
            return 8;
        }

        if (t_addr_str[strlen(t_addr_str) - 1] == '\n')
            printf("line is %s", t_addr_str);
        else
            printf("line is %s\n", t_addr_str);

        // FYI: strtol() with base = 0 provides handling for hex and octal.
        errno = 0;
        t_vaddr = (unsigned long) strtol(t_addr_str, &endptr, 0);

        if (t_addr_str == endptr) {
            printf("strtol() found no digits at all! error = %s.\n", \
                   strerror(errno));
            return 3;
        }

        if (*endptr != '\n' && *endptr != '\0') {
            printf("strtol() returned unexpected endptr!\n");
            return 4;
        }

        if (errno != 0 && (t_vaddr == LONG_MAX || t_vaddr == LONG_MIN)) {
            printf("strtol() overflowed or underflowed! error = %s.\n", strerror(errno));
            return 5;
        }

        if (t_vaddr > MAX_V_ADDR_UL) {
            printf("Virtual address out of range (> %lu)! %lu = 0x%lX\n", MAX_V_ADDR_UL, t_vaddr, t_vaddr);
            return 6;
        }

        if (i >= MAX_NUM_V_ADDRS) {
            printf("Number of virtual addresses exceeds max allowed (%d).\n", MAX_NUM_V_ADDRS);
            return 7;
        }

        vaddrs[i] = (addr_t) t_vaddr;
        printf("Virtual address # %lu. %u = 0x%X\n", i, vaddrs[i], vaddrs[i]);
        i++;

    }

    if (feof(vaddrs_fp) && ferror(vaddrs_fp)) {
        /* fgets() function does not distinguish between end-of-file and error,
           and callers must use feof(3) and ferror(3) to determine which
           occurred. */
        printf("Got fgets() error! filename = %s. error = %s.\n", vaddrs_fname, strerror(errno));
        return 9; // Bail. FYI: The OS will close the file.
    }

    errno = 0;
    if (fclose(vaddrs_fp)) {
        printf("fclose() returned error! filename = %s. error = %s.\n", vaddrs_fname, strerror(errno));
        return 9;
    }

    return 0;
}

/*!
    @function get_arg_vaddrs_filename
    @discussion Gets the addresses.txt filename argument.
    @param argc
    @param argv
    @param fname
    @result 0 if successful. Error otherwise.
*/
int get_arg_vaddrs_filename (int argc, const char * const * const argv, const char ** const fname) {
    const char *vaddrs_fname = "addresses.txt";

    if (argc < 1 || argv == NULL || fname == NULL) {
        assert(0);
        return 1;
    }

    if (argc == 2) { // Use given filename instead of default.
        vaddrs_fname = argv[1];
    }

    *fname = vaddrs_fname;

    return 0;
}

/*!

    @function main

    @discussion To run the program, use `./a.out addresses.txt`.

    @param argc

    @param argv

    @result 0 if successful.
*/
int main (int argc, const char * const * const argv) {
    const char *fname = NULL;

    if (argc < 1 || argv == NULL) {
        assert(0);
        return 1;
    }

    assert(sizeof(short) == 2); // Verify the size of integers.
    assert(sizeof(int) == 4);
    assert(sizeof(long) == 8);

    if (argc != 1 && argc != 2) {
        printf("Usage 1: ./a.out. The default input filename is \
               addresses.txt.\n");
        printf("Usage 2: ./a.out addresses.txt. addresses.txt can be any \
                filename.\n");
        return 1;
    }

    if (get_arg_vaddrs_filename (argc, argv, &fname)) {
        return 2;
    }

    printf("Input \"addresses\" filename is: \"%s\"\n", fname);

    printf("OK...\n");

    if (init_vaddrs(fname)) {
        return 3;
    }

    printf("Done.\n");

    return 0;
}

// // Scratch work //@TODO
// #define V_MEM_SIZE (1 << 16)
// #define P_MEM_SIZE (1 << 16)
// #define PAGE_SIZE (1 << 8)
// #define FRAME_SIZE PAGE_SIZE
// #define BACKING_STORE_SIZE (1 << 16)

// static unsigned char p_mem[P_MEM_SIZE];

// typedef struct _page_table_entry_t {
//     frame_number_t fn;
//     unsigned char in_pmem:1, // 1 = the page is in memory at frame number fn, 0 = page fault, page is in backing store.
//                   // Currently unused fields.
//                   mode:3, // UNIX style rwx permissions for this page.
//                   cp_on_w:1, // 1 = This page is copy on write, 0 = not copy on write.
//                   locked:1, // 1 = This page is locked into memory by the OS, it cannot be kicked out/replaced.
//                         :2;
// } page_table_entry_t;

// #define PAGE_TABLE_LEN (V_MEM_SIZE/PAGE_SIZE)

// static page_table_entry_t page_table[PAGE_TABLE_LEN];

// /*!
//     @discussion Translates the given virtual address to a physical address.

//     @result 0 if successful. Otherwise error.
// */
// int translate_v2p_addr(addr_t vaddr, addr_t *paddr) {
//     /* consult the page table, if in mem. return physical address, else a page
//        fault occurred, read the page from the backing store into physical memory
//        update the page table, re-do the translation, return the physical
//        address.
//     */
//     return 0;
// }

// static addr_t next_free_frame_base_addr = 0;
