#ifndef KER_IO_H
#define KER_IO_H
#include "inttypes.h"

//These are prototyped here but defined in ASM

//in/out 8-bit values 
extern uint8_t in_byte(uint16_t port);
extern void out_byte(uint16_t port, uint8_t val);

//in/out 16-bit values
extern uint16_t in_word(uint16_t port);
extern void out_word(uint16_t port, uint16_t val);

//in/out 32-bit values
extern uint32_t in_dword(uint32_t port);
extern void out_dword(uint16_t port, uint32_t val);

//Wait for IO to be avaliable based on function from os-dev wiki.
extern void wait_io();

#endif
