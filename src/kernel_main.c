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

void kernel_main(void) {
	clear_bss();
	led_init();
	led_on();
	while(1);
}
