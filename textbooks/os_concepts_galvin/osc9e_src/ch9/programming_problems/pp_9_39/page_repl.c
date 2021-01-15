/*!
    @header Page Replacement Algorithms
    Functions that implement the LRU, FIFO and OPT page replacement.
*/
#include <stdlib.h>
#include <assert.h>
#include "list.h"

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