/*!
    @header Page Replacement Algorithms
    Functions that implement the LRU, FIFO and OPT page replacement.
*/
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "arr.h"

int do_lru(const int len_rs, const int * const rs, const int npf) {
    int n_free_pf = npf;
    int i = 0;
    int page_num;
    int num_page_faults = 0;
    list_t l;
    list_node_t *n = NULL;

    alloc_list(&l, 0);

    while (i < len_rs) {
        page_num = rs[i];
        i++;

        if(list_contains(&l, page_num) == 1) {
            // Page in memory - update MRU page.
            if(list_remove_node(&l, page_num, &n) == 1)
                assert(list_add_tail(&l, n) == 0);
            else
                assert(0); // Should be in list - we just checked.
        } else {
            // Page not in memory - page fault
            num_page_faults++;

            if(n_free_pf-- > 0) {
                // Place page in a free frame - make it the MRU
                n = calloc(1, sizeof(list_node_t));
                assert(n != NULL);
                n->e = page_num;
                assert(list_add_tail(&l, n) == 0);
            } else {
                // Replace LRU page with page just referenced.

                assert(l.len > 0); // We should have a least one page frame

                if(list_remove_node(&l, l.head->e, &n) == 1) { // Remove head = LRU page.
                    n->e = page_num;
                    assert(list_add_tail(&l, n) == 0);
                } else
                    assert(0);
            }

        }
    }

    free_list2(&l);

    return num_page_faults;
}

/*!
    @function opt_r

    @discussion Replaces one of the pages in the page_frames array with the new
    page being brought into memory, which is page_num. rs is the remaining part
    of the reference string, excluding page_num, len_rs is the length of rs. If
    successful, one of the pages in page_frames will have been replaced
    (overwritten) with page_num.

    @field page_frames    The array of page frames representing the pages that
                          are currently in memory.

    @field rs    The remaining unprocessed part of the reference string,
                 excluding page_num. A reference string represents the memory
                 accesses against which a page replacement algorithm is tested.

    @field len_rs    The length of the rs array.

    @field page_num  The page number which caused the most recent page fault and
                     is being brought into memory via page replacement.

    @result 0 if successful. Other values indicate error.
*/
static int opt_r(arr_t *page_frames, const int * const rs, const int len_rs, const int page_num) {
    int ffnr_i = -1; // ffnr = furthest future next reference. Current index into page_frames->arr of the page to be replaced.
    int ffnr_j = -1; // ffnr = furthest future next reference. Current index into rs of the page to be replaced. This index can be thought of as how far into the future page number rs[ffnr_j] will be referenced.
    int i, j;

    assert(page_frames != NULL && page_frames->arr != NULL && page_frames->num_entries > 0);

    if (page_frames == NULL || page_frames->arr == NULL || page_frames->num_entries <= 0) {
        return 1;
    }

    assert(rs != NULL && len_rs >= 0);

    if (rs == NULL || len_rs < 0) {
        return 2;
    }

    for(i = 0; i < page_frames->num_entries; i++) {
        for(j = 0; j < len_rs; j++) {
            if(page_frames->arr[i] == rs[j])
                break;
        }

        if(j == len_rs) {
            /* Page is never referenced again, we can end the search early and
            replaced this page.
            */
            page_frames->arr[i] = page_num;
            return 0;
        } else {
            if(j > ffnr_j) {
                // This page is referenced further into the future, update the candidate replacement page.
                ffnr_j = j;
                ffnr_i = i;
            }
        }
    }

    // Sanity check - we should always find a page to replace.
    assert(ffnr_i >= 0 && ffnr_j >= 0);

    if (ffnr_i < 0 || ffnr_j < 0) {
        return 3;
    }

    // Replace the page.
    page_frames->arr[ffnr_i] = page_num;

    return 0;
}