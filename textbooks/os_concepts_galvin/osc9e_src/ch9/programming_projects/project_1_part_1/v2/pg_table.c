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
int page_table_add(addr_t page_num, addr_t frame_num) {
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
    t = malloc(sizeof(*t));
    assert(t);
    t->pg_tbl_entry = &page_table[page_num];
    INIT_LIST_HEAD(&t->list);
    list_add_tail(&t->list, &pages_list);
    list_for_each_entry(ptr, &pages_list, list) {
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

    if (page_num >= PAGE_TABLE_LEN) {
        assert(0);
        return 1;
    }

    if (frame_num == NULL) {
        assert(0);
        return 1;
    }

    if (page_table_rm(victim_frame)) {
        assert(0);
        return 2;
    }

    if(backing_store_pg_in(page_num, p_mem_addr() + victim_frame * PAGE_SIZE)) {
      assert(0);
      return 3;
    }

    if(page_table_add(page_num, victim_frame)) {
        assert(0);
        return 4;
    }

    *frame_num = victim_frame;

    //printf("Replaced page in frame number %lu\n", victim_frame);

    victim_frame++;
    victim_frame = victim_frame % NUM_PAGE_FRAMES;

    return 0;
}

#define PHYSICAL_ADDR(fn, pgoff) ( ( (fn) << PAGE_OFFSET_NBITS ) | (pgoff) );

int no_tlb_translate_v2p_addr(addr_t vaddr, addr_t *paddr) {
    /*! @discussion The page frame number of the next free frame. */
    static addr_t free_frame = 0;
    addr_t page_offset, page_num, frame_num;
    size_t i;

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

    if (page_table[page_num].valid) {
        // The page is in memory.
        *paddr = PHYSICAL_ADDR(page_table[page_num].fn, page_offset);
        return 0;
    }

    /* Page fault! Must get the page from the backing store. */

    npf++; // Statistics

    if (free_frame < NUM_PAGE_FRAMES) {
        // Use a free frame.
        frame_num = free_frame;
        if(backing_store_pg_in(page_num, p_mem_addr() + frame_num * PAGE_SIZE)) {
          assert(0);
          return 3;
        }

        if(page_table_add(page_num, frame_num)) {
          assert(0);
          return 3;
        }

        free_frame++;
    } else {
        // No free frame available, page replacement required.
        if (page_replace(page_num, &frame_num)) {
            assert(0);
            return 3;
        }
    }

    *paddr = PHYSICAL_ADDR(frame_num, page_offset);
    return 0;
}