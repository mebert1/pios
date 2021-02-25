#include "serial.h"
#include "rprintf.h"
#include <stdint.h>


extern int __bss_start;
extern int __bss_end;
extern int __bss_size;

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
	// clear_bss();

	// initialize green LED and turn it on
	// led_init();
	// led_on();

	// send String to serial port
	esp_printf((void *)putc, "ApplePi says Hi");
	
	while(1) {}
}
