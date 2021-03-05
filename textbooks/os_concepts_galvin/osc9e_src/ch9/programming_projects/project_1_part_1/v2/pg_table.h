#ifndef __PG_TABLE_H__
#define __PG_TABLE_H__

int page_table_rm(addr_t frame_num);
int page_table_add(addr_t page_num, addr_t frame_num);
int page_replace(addr_t page_num, addr_t *frame_num);
int no_tlb_translate_v2p_addr(addr_t vaddr, addr_t *paddr);

extern size_t npf;

#endif