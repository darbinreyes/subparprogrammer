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

/*!
    @typedef pg_list_t
    @discussion Represents a node in the list that is used to implement
    page replacement. Each node points to a valid page table entry which can be
    used to determine the associated page number and frame number.
    @field pg_tbl_entry The associated page table entry.
    @field list Contains pointers to the next and previous nodes in the list.
*/
typedef struct _pg_list_t {
    pg_tbl_entry_t *pg_tbl_entry;
    struct list_head list;
} pg_list_t;

/* @pages_list Handle to the list of pages currently in memory. @pages_list.next
points to the head of the list, @pages_list.prev points to the tail of the list.
The list is maintained in FIFO order such that the head is the first-in page. */
static LIST_HEAD(pages_list);

size_t npf; // @npf Total number of page faults.

/* Represents the page table. */
static pg_tbl_entry_t page_table[PAGE_TABLE_LEN];

/*!
    @discussion Updates the page table to reflect that a particular page is no
    longer in memory because a page replacement took place. Returns the frame
    number of the entry before the entry is marked as invalid.

*/
int page_table_rm(addr_t page_num, addr_t *frame_num) {
    size_t i;

    if (page_num >= PAGE_TABLE_LEN) {
        assert(0);
        return 1;
    }

    if (frame_num == NULL) {
        assert(0);
        return 1;
    }

    if(!page_table[page_num].valid) {
        /* We should only be removing valid page table entries in the list
           should be valid. */
        assert(0);
        return 1;
    }

    page_table[page_num].valid = 0; // No longer in memory.

    *frame_num = page_table[page_num].fn;
    /* Mark with an invalid page number. */
    page_table[page_num].fn = PAGE_TABLE_LEN;

    return 0;
}

/*!
    @discussion Adds a list node to the tail of the FIFO list used to implement
    page replacement. The node points to the given associated page table entry.
    Memory for the node is obtained from malloc(), the caller is responsible for
    calling free().
    Remark: We never need to remove an entry from the list. During page
    replacement we reused the node at the front of the list and move it to the
    back of the list.
*/
int fifo_list_add(pg_tbl_entry_t *pte) {
    pg_list_t *t;

    if (pte == NULL) {
        assert(0);
        return 1;
    }

    t = malloc(sizeof(*t));

    if (t == NULL) {
        assert(0);
        return 1;
    }

    t->pg_tbl_entry = pte;
    INIT_LIST_HEAD(&t->list);
    list_add_tail(&t->list, &pages_list);
    return 0;
}

/*!
    @discussion Updates the page table to reflect that a page is now in memory.
    @page_num is the page number that identifies the page table entry that will
    be updated. @frame_num is the frame number in which the page resides, it
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

    pg_list_t *ptr;

    list_for_each_entry(ptr, &pages_list, list) {
        printf("[%lu|%lu]->", (ptr->pg_tbl_entry - page_table), ptr->pg_tbl_entry->fn);
    }

    printf("\n");

    return 0;
}

/*!
    @discussion When a page fault occurs and there are no free frames a page
    must be replaced. This function performs a page replacement.
*/
int page_replace(addr_t page_num, addr_t *frame_num) {
    addr_t victim_frame;
    pg_list_t *t;

    if (page_num >= PAGE_TABLE_LEN) {
        assert(0);
        return 1;
    }

    if (frame_num == NULL) {
        assert(0);
        return 1;
    }

    if (list_empty(&pages_list)) {
        /* We are performing page replacement, the list should not be empty, the
           list should contain as many nodes as there are page frames. */
        assert(0);
        return 1;
    }

    // The victim page is always the page at the head of the list.
    t = list_first_entry(&pages_list, pg_list_t, list);

    if(page_table_rm(t->pg_tbl_entry - page_table, &victim_frame)) {
        assert(0);
        return 1;
    }

    if(backing_store_pg_in(page_num, p_mem_addr() + victim_frame * PAGE_SIZE)) {
      assert(0);
      return 3;
    }

    if(page_table_add(page_num, victim_frame)) {
        assert(0);
        return 4;
    }

    /* Update page table entry pointer of the list node to point to the entry of
     the page that was paged in. */
    t->pg_tbl_entry = &page_table[page_num];

    /* Move the list entry from the head to the tail of the queue. This page is
    now the one most recently brought into memory. */
    list_move_tail(&t->list, &pages_list);

    *frame_num = victim_frame;

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

        if(page_table_add(page_num, frame_num)) {
          assert(0);
          return 1;
        }

        if (fifo_list_add(&page_table[page_num])){
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