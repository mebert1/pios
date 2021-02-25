#include <stdint.h>

#define BIT_6 		(1<<6)
#define BIT_10 		(1<<10)
#define NOT_BITS_6_TO_8 ~(7<<6)

void led_init(void) {
	uint32_t *gpsel4 = (uint32_t *) 0xFE200010;

	*gpsel4 &= NOT_BITS_6_TO_8;
	*gpsel4 |= BIT_6;
}

void led_on(void) {
	uint32_t *gpset1 = (uint32_t *) 0xFE200020;

	*gpset1 |= BIT_10;
}

void led_off(void) {
	uint32_t *gpclr1 = (uint32_t *) 0xFE20002C;

	*gpclr1 |= BIT_10;
}

void delay(unsigned int s) {
	unsigned int i, j;
	unsigned int d = 0xFFF;

	for(i = 0; i < 0x7f; i++) {
		for(j = 0; j < (d*s); j++) {
			asm("nop");
		}
	}
}

void blink(unsigned int delay_s) {
	led_init();
	while(1) {
		led_on();
		delay(delay_s);
		led_off();
		delay(delay_s);
	}
}




