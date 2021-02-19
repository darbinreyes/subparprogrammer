/*!

    @header Chapter 9 Programming Project: Designing a Virtual Memory Manager
    @discussion This implementation starts with *v0.c and adds a TLB.
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
      page ever gets kicked out of physical memory. In practice, the physical
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
      required: use FIFO or LRU.

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
#include "vm.h"
#include "args.h"
#include "get_vaddrs.h"

int translate_v2p_addr(addr_t vaddr, addr_t *paddr);
int p_mem_read(addr_t paddr, signed char *v);

/*
    @function translate_all
    @discussion Translates all virtual addresses to physical addresses and
    prints the result.
    @result 0 if successful.
*/
int translate_all(void) {
    size_t i;
    addr_t paddr;
    signed char v;

    for (i = 0; i < vaddrs_len; i++) {
        if(translate_v2p_addr(vaddrs[i], &paddr)) {
            assert(0);
            return 1;
        }
        //Virtual address: 16916 Physical address: 20 Value: 0
        if(p_mem_read(paddr, &v)) {
            assert(0);
            return 2;
        }

        printf("Virtual address: %lu Physical address: %lu Value: %d\n",
               vaddrs[i], paddr, v);
    }

    return 0;
}

/*!

    @function main

    @discussion To run the program, use `./a.out addresses.txt`.

    @param argc The usual main() arg.
    @param argv The usual main() arg.

    @result 0 if successful.
*/
int main (int argc, const char * const * const argv) {
    const char *fname = NULL;

    if (valid_int_sizes()) {
      return 1;
    }

    if (valid_args (argc, argv)) {
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

    if (translate_all()) {
        return 4;
    }

    printf("Done.\n");

    return 0;
}

/*!
    @function backing_store_read

    @discussion Reads a page (page_num) from the backing store into the
    specified address in physical memory (dst).

    @param page_num Identifies the location of a page on the backing to read
    from.
    @param dst The destination address in physical memory for the read.

    @result 0 if successful.
*/
int backing_store_read(addr_t page_num, unsigned char *dst) {
    /*! @discussion Temporary buffer used for destination of a read operation on
        the backing store. */
    static unsigned char page_io_buffer[PAGE_SIZE];
    const char *bs_fname = "BACKING_STORE.bin";
    static FILE *bs_fp;
    size_t nb;

    if (dst == NULL) {
        assert(0);
        return 1;
    }

    if (page_num >= NUM_BS_PAGES) {
        fprintf(stderr, "page_num is out of bounds for backing store. " \
                "%lu >= %lu.\n", page_num, NUM_BS_PAGES);
        assert(0);
        return 1;
    }

    if (!bs_fp) { // Backing store file not open yet.
        errno = 0;
        bs_fp = fopen(bs_fname, "r");
        if (!bs_fp) {
            fprintf(stderr, "fopen(\"r\") returned NULL! filename = %s. "\
                    "error = %s.\n", bs_fname, strerror(errno));
            assert(0);
            return 2;
        }
    }

    errno = 0;
    if(fseek(bs_fp, page_num * PAGE_SIZE, SEEK_SET)) {
        fprintf(stderr, "fseek() error!  filename = %s. error = %s.\n", \
                bs_fname, strerror(errno));
        assert(0);
        return 3;
    }

    errno = 0;
    nb = fread(page_io_buffer, 1, sizeof(page_io_buffer), bs_fp);
    if (nb < sizeof(page_io_buffer) && ferror(bs_fp)) {
        fprintf(stderr, "fread() short byte count + error. filename = %s. "
                "error = %s.\n", bs_fname, strerror(errno));
        assert(0);
        return 4;
    }

    if (feof(bs_fp) && ferror(bs_fp)) {
        fprintf(stderr, "fread() error! filename = %s. error = %s.\n", \
                bs_fname, strerror(errno));
        assert(0);
        return 5;
    }

    memcpy(dst, page_io_buffer, sizeof(page_io_buffer));

    return 0;
}

static unsigned char p_mem[P_MEM_SIZE];

/*!
    @function translate_v2p_addr

    @discussion Translates the given virtual address to a physical address.

    @param vaddr The virtual address.
    @param paddr The physical address if successful.

    @result 0 if successful. Otherwise error.
*/
int translate_v2p_addr(addr_t vaddr, addr_t *paddr) {
    /*! @discussion The page frame number of the next free frame. When a page
        fault occurs, the new page is read into physical memory at byte address
        == free_framen * PAGE_SIZE. */
    static addr_t free_framen = 0;
    static pg_tbl_entry_t page_table[PAGE_TABLE_LEN];
    addr_t page_offset, page_num, frame_num;
    /*
        Steps:
        Extract the page offset and page number from the virtual address.

        Take the page number as an index into the page table to obtain the page
        table entry.

        If the page table entry indicates that the page is in memory, save the
        frame number from that page table entry. Otherwise a page fault has
        occurred, i.e. the page is not in memory. Read the page from the backing
        store into a free frame in physical memory, and update the page table.
        Save the frame number of the free frame.

        Concatenate the saved frame number and page offset to form the physical
        address.
    */
    if (paddr == NULL) {
        assert(0);
        return 1;
    }

    page_offset = (vaddr & (PAGE_SIZE - 1));
    page_num = (vaddr & (V_MEM_SIZE - 1)) >> PAGE_OFFSET_NBITS;

    if (page_num >= PAGE_TABLE_LEN) {
        assert(0);
        return 1;
    }

    if (page_table[page_num].im) {
        // The page is in memory.
        frame_num = page_table[page_num].fn;
    } else {
        // Page fault! Get the page from the backing store, update page_table.
        frame_num = free_framen;

        if (frame_num >= NUM_PAGE_FRAMES) {
            fprintf(stderr, "frame_num is out of bounds %lu >= %lu.\n", \
                    frame_num, NUM_PAGE_FRAMES);
            assert(0);
            return 2;
        }

        if(backing_store_read(page_num, p_mem + frame_num * PAGE_SIZE)) {
            assert(0);
            return 3;
        }

        page_table[page_num].fn = frame_num;
        page_table[page_num].im = 1;
        free_framen++;
    }

    assert(frame_num < NUM_PAGE_FRAMES);

    *paddr = (frame_num << PAGE_OFFSET_NBITS) | page_offset;
    return 0;
}

/*!
    @function p_mem_read

    @discussion Returns the value of a byte in physical memory at the given
    physical address.

    @param paddr The physical address.

    @param v If successful, the value of the byte at the address.

    @result 0 if successful.
*/
int p_mem_read(addr_t paddr, signed char *v) {
    if (paddr >= P_MEM_SIZE) {
        assert(0);
        return 1;
    }

    if (v == NULL) {
        assert(0);
        return 2;
    }

    *v = p_mem[paddr];
    return 0;
}
