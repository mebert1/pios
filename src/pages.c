#include "list.h"

#define NPAGES 128

extern int __end;

struct ppage physical_page_array[NPAGES];
struct ppage *free_list = NULL;
struct ppage *allocd_list = NULL;

void init_pfa_list(void) {
	void *physical_addr = (((unsigned long) &__end) & (0x200000 - 1)) + 0x200000;
	for(int i = 0; i < NPAGES i++) {
		physical_page_array[i].physical_addr = physical_addr;;
		list_add(&free_list, physical_page_array[i]);
		physical_addr += 0x200000;
	}
}

struct ppage *allocare_physical_pages(unsigned int npages) {
	
}

void free_physical_pages(struct ppage *ppage_list) {


