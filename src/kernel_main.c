#include "serial.h"
#include "rprintf.h"
#include <stdint.h>
#include "page.h"


extern int __bss_start;
extern int __bss_end;
extern int __bss_size;
extern struct ppage* free_list;

void blink(unsigned int delay_s);
void led_init();
void led_on();

void clear_bss(void) {

	char* begin_bss	= (char*) & __bss_start;
	
	for(int i = 0; i < __bss_size; i++) {
		begin_bss[i] = 0;
	}
}

void kernel_main() {

	// clear BBS segment of pi
	clear_bss();

	// Print string to greet user
	esp_printf((void *)putc, "ApplePi says Hi\n");
	
	init_pfa_list();
	struct ppage *test = free_list->next;
	test = test->next;
	esp_printf((void *)putc, "Physical addr: %x\n", test->physical_addr);

	test = allocate_physical_pages(2);
	esp_printf((void *)putc, "Allocated addr: %x\n", test->physical_addr);
	test = allocate_physical_pages(2);
	esp_printf((void *)putc, "Allocated addr: %x\n", test->physical_addr);
	free_physical_pages(test);
	esp_printf((void *)putc, "Addr after free: %x\n", test->physical_addr);

	while(1) {}
}
