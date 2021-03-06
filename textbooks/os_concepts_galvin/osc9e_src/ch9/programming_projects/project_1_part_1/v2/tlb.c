/*!
    @header TLB related definitions.
*/

#include <stdio.h>
#include <assert.h>
#include "vm.h"

/*! @discussion Represents the TLB. */
static tlb_entry_t tlb[TLB_LEN];

/*!
    @function in_tlb
    @discussion Consults the TLB for a translation.

    @param page_num The page number.

    @param frame_num On a TLB-hit, the corresponding frame number. On a
    TLB-miss, untouched.

    @result 1 on a TLB-hit, 0 on a TLB-miss.
*/
int in_tlb(addr_t page_num, addr_t *frame_num) {
    size_t i;

    if (frame_num == NULL) {
        assert(0);
        return 0;
    }

    for (i = 0; i < TLB_LEN; i++) {
        if (tlb[i].valid && tlb[i].pn == page_num) {
            //printf("TLB-hit!\n");
            *frame_num = tlb[i].fn;
            return 1;
        }
    }
    //printf("TLB-miss!\n");
    return 0;
}

/*!
    @function tlb_add
    @discussion Updates the TLB with a new translation entry - for use after a
    page fault occurs. Entries are replaced according to FIFO.

    @param page_num The page number.

    @param frame_num The frame number.

    @result 0 if successful.
*/
int tlb_add(addr_t page_num, addr_t frame_num) {
    /* Implements FIFO TLB entry replacement using a circular array index. */

    /* @IMPORTANT Since we are not required to replace any pages, once the
    TLB is full, all entries remain valid, we only need to update the entry's
    page number and frame number. @TODO This is no longer true once we are
    evicting pages from memory and thus TLB entries are being invalidated. We
    only want to replace an entry if the TLB is full.
    TLB_LEN = 3. victim = 0.

    []<
    []
    []

    victim = 0. (page_num, frame_num)=[2|0]

    [2|0] // State of TLB after call.
    []< // victim index
    []

    victim = 1. (page_num, frame_num)=[5|1]

    [2|0]
    [5|1]
    []<

    victim = 2. (page_num, frame_num)=[7|2]

    [2|0]<
    [5|1]
    [7|2]

    // At this point the next call will replace entry 0. Which is correct
    according to FIFO replacement.

    victim = 0. (page_num, frame_num)=[1|3]

    [1|3] // replaced entry
    [5|1]<
    [7|2]

    // Do we need to check whether or not a page is already in the TLB before
    an add? We only add on a page fault, we only invalidate when a page is
    evicted, we only replace when the TLB is full and an add occurs. The assert
    below performs this sanity check.

    It seems that now we have a queue in which items can be removed from places
    other than the head. In this case an array based queue will not suffice.

    */
    static size_t victim = 0;
    addr_t t;
    size_t i;

    assert(!in_tlb(page_num, &t)); // Sanity check.

    for (i = 0; i < TLB_LEN; i++) {
        if (!tlb[i].valid) {
            printf("TLB not full\n");
            break;
        }
    }

    tlb[victim].pn = page_num;
    tlb[victim].fn = frame_num;

    tlb[victim].valid = 1;
    victim++;
    victim = victim % TLB_LEN;
    return 0;
}

/*!
    @function tlb_rm

    @discussion Removes the specified entry from the TLB. This operation is
    necessary any time we evict a page from memory.

    @param page_num The page number.

    @param frame_num The frame number.

    @result 0 if successful.
*/
int tlb_rm(addr_t page_num, addr_t frame_num) {
    size_t i;

    // Remark: TLB's are small, so in most cases we won't remove any entry.

    for (i = 0; i < TLB_LEN; i++) {
        if (tlb[i].valid && tlb[i].pn == page_num && tlb[i].fn == frame_num) {
            // Remove entry.
            tlb[i].valid = 0;
            /* PAGE_TABLE_LEN is not a valid frame or page number, so it is a
               good value to use for marking entries as removed. */
            tlb[i].fn = PAGE_TABLE_LEN;
            tlb[i].pn = PAGE_TABLE_LEN;
            /* @IMPORTANT Possible bug. I never see this print. This implies
            that each page that is evicted from memory by chance never happens
            to have an entry in TLB. */
            printf("TLB entry removed.\n");
            break;
        }
    }

    return 0;
}