/*!
    @header Page table related definitions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "backing_store.h"
#include "vm.h"
#include "pmem.h"
#include "list.h"

struct pg_info {
    pg_tbl_entry_t *pg_tbl_entry;
    struct list_head list;
};

// List of pages currently in memory in FIFO order.
static LIST_HEAD(pages_list);

size_t npf; // Total number of page faults.

/* Represents the page table. */
static pg_tbl_entry_t page_table[PAGE_TABLE_LEN];

/*!
    @discussion Updates the page table to reflect that a particular page is no
    longer in memory because a page replacement took place.

    The page table is scanned for a valid page table entry with a frame
    number == `frame_num` and, if found, marks that page table entry as invalid.
    It is an error if no such page table entry is found.
*/
int page_table_rm(addr_t frame_num) {
    size_t i;

    if (frame_num >= NUM_PAGE_FRAMES) {
        assert(0);
        return 1;
    }

    for (i = 0; i < PAGE_TABLE_LEN; i++) {
        if (page_table[i].valid && page_table[i].fn == frame_num) {
            page_table[i].valid = 0; // No longer in memory.
            /* Mark with an invalid page number. */
            page_table[i].fn = PAGE_TABLE_LEN;
            break;
        }
    }

    if (i >= PAGE_TABLE_LEN) {
        /*! @discussion By definition a page being evicted must currently reside
            in memory, and hence have a corresponding valid entry in the page table. */
        assert(0);
        return 2;
    }

    return 0;
}

/*!
    @discussion Updates the page table to reflect that a page is now in memory.
    `page_num` is the page number that identifies the page table entry that will
    be updated. `frame_num` is the frame number in which the page resides, it
    will be saved in the identified page table entry. Finally, the page table
    entry is marked as valid.

*/
int page_table_add(addr_t page_num, addr_t frame_num, struct pg_info *pg_info_entry) {
    if (page_num >= PAGE_TABLE_LEN) {
        assert(0);
        return 1;
    }

    if (frame_num >= NUM_PAGE_FRAMES) {
        assert(0);
        return 2;
    }

    if(page_table[page_num].valid) {
        assert(0);
        return 3;
    }

    page_table[page_num].fn = frame_num;
    page_table[page_num].valid = 1;

    // START Update the FIFO list of pages.
    struct pg_info *t, *ptr;

    if (pg_info_entry == NULL) {
        printf("Using new list entry.\n");
        t = malloc(sizeof(*t));
        assert(t);
        t->pg_tbl_entry = &page_table[page_num];
        INIT_LIST_HEAD(&t->list);
        list_add_tail(&t->list, &pages_list);
    } else {
        printf("Re-using list entry.\n");
        pg_info_entry->pg_tbl_entry = &page_table[page_num];
    }
    list_for_each_entry(ptr, &pages_list, list) {
        /* TEMP. - for each list entry - print page_num and frame num.
           NOTE: Even with vmem size == pmem size, only (243+1)/256 frames are
           used. */
        printf("[%lu|%lu]->", (ptr->pg_tbl_entry - page_table), ptr->pg_tbl_entry->fn);
    }
    printf("\n");
    // END Update the FIFO
    return 0;
}

/*!
    @discussion When a page fault occurs and there are no free frames a page
    must be replaced. This function performs a page replacement.
*/
int page_replace(addr_t page_num, addr_t *frame_num) {
    static addr_t victim_frame = 0;
    addr_t fifo_victim_frame;

    if (page_num >= PAGE_TABLE_LEN) {
        assert(0);
        return 1;
    }

    if (frame_num == NULL) {
        assert(0);
        return 1;
    }

    // START - use FIFO list to select victim page -----------------------------

    // assert(list is not empty)

    // The victim page is the page at the head of the list.

    struct pg_info *t;

    t = list_first_entry(&pages_list, struct pg_info, list);
    fifo_victim_frame = t->pg_tbl_entry->fn;
    assert(fifo_victim_frame == victim_frame); // TEMP. - verify the circular index implementation was correct.
    // Do what page_table_rm() does, but we can skip the search.
    assert(t->pg_tbl_entry->valid);
    t->pg_tbl_entry->valid = 0; // No longer in memory.
    /* Mark with an invalid page number. */
    t->pg_tbl_entry->fn = PAGE_TABLE_LEN;
    // Move the list entry from the head to the tail of the queue.
    list_move_tail(&t->list, &pages_list);
    // END - use FIFO list to select victim page -------------------------------

    // if (page_table_rm(victim_frame)) {
    //     assert(0);
    //     return 2;
    // }

    if(backing_store_pg_in(page_num, p_mem_addr() + fifo_victim_frame * PAGE_SIZE)) {
      assert(0);
      return 3;
    }

    if(page_table_add(page_num, fifo_victim_frame, t)) {
        assert(0);
        return 4;
    }

    *frame_num = fifo_victim_frame;

    //printf("Replaced page in frame number %lu\n", victim_frame);

    victim_frame++;
    victim_frame = victim_frame % NUM_PAGE_FRAMES;

    return 0;
}

/*!
    @function no_tlb_translate_v2p_addr

    @discussion Translates the given virtual address to a physical address NOT
    using a TLB.

    @param vaddr The virtual address.
    @param paddr The physical address if successful.

    @result 0 if successful. Otherwise error.
*/
int no_tlb_translate_v2p_addr(addr_t vaddr, addr_t *paddr) {
    /* @free_frame: The page frame number of the next free frame. Initially, all
       page faults are serviced by inserting the page into a frame number equal
       to @free_frame. If @free_frame equals @NUM_PAGE_FRAMES, there are no more
       free frames and all subsequent page faults are serviced by page
       replacement. */
    static addr_t free_frame = 0;
    addr_t page_offset, page_num, frame_num;
    size_t i;

    if (vaddr > MAX_V_ADDR) {
        assert(0);
        return 1;
    }

    if (paddr == NULL) {
        assert(0);
        return 1;
    }

    /*
        Steps:
        Extract the page offset and page number from the virtual address.

        Take the page number as an index into the page table to obtain the page
        table entry.

        If the page table entry indicates that the page is in memory, save the
        frame number from that page table entry. Concatenate the frame number
        and page offset to form the physical address.

        Otherwise a page fault has occurred, i.e. the page is not in memory.

        If a page fault occurs and there is a free frame, read the page from the
        backing store into a free frame, and update the page table. Concatenate
        the free frame number and page offset to form the physical address.

        If a page fault occurs and there are no free frames, replace a page
        currently in memory with the page that generated the page fault.
        Concatenate the frame number of the new page and page offset to form the
        physical address.
    */

    page_offset = ADDR_PAGE_OFFSET(vaddr);
    page_num = ADDR_PAGE_NUM(vaddr);

    if (page_num >= PAGE_TABLE_LEN) {
        assert(0);
        return 1;
    }

    if (page_table[page_num].valid) {
        // The page is in memory.
        *paddr = PHYSICAL_ADDR(page_table[page_num].fn, page_offset);
        return 0;
    }

    /* Page fault! Must get the page from the backing store. */

    npf++; // Statistics

    if (free_frame < NUM_PAGE_FRAMES) {
        // Use a free frame.
        frame_num = free_frame++;
        if(backing_store_pg_in(page_num, p_mem_addr() + frame_num * PAGE_SIZE)) {
          assert(0);
          return 1;
        }

        if(page_table_add(page_num, frame_num, NULL)) {
          assert(0);
          return 1;
        }

        *paddr = PHYSICAL_ADDR(frame_num, page_offset);
        return 0;
    }

    // No free frame available, page replacement required.
    if (page_replace(page_num, &frame_num)) {
        assert(0);
        return 1;
    }

    *paddr = PHYSICAL_ADDR(frame_num, page_offset);
    return 0;
}