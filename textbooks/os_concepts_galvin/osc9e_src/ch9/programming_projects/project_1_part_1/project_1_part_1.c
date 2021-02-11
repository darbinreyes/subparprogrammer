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
    * 2^8 entries in the page table. (= size_of_virtual_address_space/size_of_a_page = 2^16/2^8 = 2^8 = 256).
    * Page size of 2^8 bytes. (= 2^(number_of_bits_in_page_offset_field_of_logical_address))
    * A TLB with space for 16 entries. (=2^4). (Key=Page Number, Value=Frame Number).
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
      If we have a TLB-hit, the TLB provides the frame number, the physical address = <frame_number , page offset>.
      else, we have a TLB-miss, we consult the page-table for the frame number, again the physical address = <frame_number , page offset>.
          If page table does not contain the frame number, a **page fault** has occurred. Thus the page is not in memory, it must be read in from the backing store into physical memory.
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


/*

    Array of virtual addresses read from addresses.txt.
    It is given that each address fits in a 16-bit integer and that there are
    1000 of them.

*/
#define NVADDRESSES 1000
static short vaddrs[NVADDRESSES];

/*
Temporary string buffer for use with fgets() when reading addresses.txt line by
line.

// Temp.
18446744073709551615 = 2**64 - 1
+1 for sizeof('\n').
//

The minimum size for this buffer would be
sizeof("65536") // 5 chars + 1 NULL terminator
+1 for potential new line character after that. Total = 7 bytes.

*/
static char t_addr_str[sizeof("65536") + 1];

/*!

    @function main

    @discussion Given: to run the program, use `./a.out addresses.txt`.

    @param argc

    @param argv

    @result
*/
int main (int argc, const char * const * const argv) {
    FILE *vaddrs_fp;
    const char *vaddrs_fname = "addresses.txt";
    long t_vaddr;
    size_t i = 0;


    assert(sizeof(short) == 2); // Verify the size of integers.
    assert(sizeof(int) == 4);
    assert(sizeof(long) == 8);

    if (argc != 1 && argc != 2) {
        printf("Usage 1: ./a.out. The default input filename is addresses.txt.\n");
        printf("Usage 2: ./a.out addresses.txt. addresses.txt can be any properly formatted filename.\n");
        return 1;
    }

    if (argc == 2) { // Use given filename instead of default.
        vaddrs_fname = argv[1];
    }

    printf("Input \"addresses\" filename is: \"%s\"\n", vaddrs_fname);

    printf("OK...\n");

    /*
        Read file addresses.txt 1 line at a time.
        For each line, if the line is not empty, and we haven't reached EOF,
        convert address to an unsigned integer, take lower 16 bits,
        print the page number and page offset. Compare page offset to
        correct.txt.
    */

    errno = 0; // Per man page.
    vaddrs_fp = fopen (vaddrs_fname, "r");

    if (vaddrs_fp == NULL) {
        printf("fopen(\"r\") returned NULL! filename = %s. error = %s.\n", vaddrs_fname, strerror(errno));
        return 3;
    }

    clearerr(vaddrs_fp); // Not necessary at this point, just a precaution/reminder for later.
    while (fgets(t_addr_str, sizeof(t_addr_str), vaddrs_fp) && !feof(vaddrs_fp)) {
        printf("line %lu = %s", i, t_addr_str);
        i++;
    }

    if (feof(vaddrs_fp) && ferror(vaddrs_fp)) {
        printf("Got fgets() error! filename = %s. error = %s.\n", vaddrs_fname, strerror(errno));
        return 4; // Bail. FYI: The OS will close the file.
    }

    errno = 0;
    if (fclose(vaddrs_fp)) {
        printf("fclose() returned error! filename = %s. error = %s.\n", vaddrs_fname, strerror(errno));
        return 5;
    }

    printf("Done.\n");
    return 0;
}