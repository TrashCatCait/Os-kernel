#ifndef KER_IO_H
#define KER_IO_H
#include "inttypes.h"

uint8_t in_byte(uint16_t port);
void out_byte(uint16_t port, uint8_t val);

#endif
