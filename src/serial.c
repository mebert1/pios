#include "serial.h"
#include <stdint.h>

#define MU_IO_ADR 0x3F215040

void putc(int data) {
	uint32_t * mu_io_reg = (uint32_t *) MU_IO_ADR;
	*mu_io_reg = data;
}








