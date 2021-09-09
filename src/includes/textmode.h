#ifndef BIOS_TEXT_MODE_H
#define BIOS_TEXT_MODE_H 
#include "./typedefs.h"

#define VGA_COLS 80 
#define VGA_MEM (uint8_t*)0xb8000

void print_char(char character, uint8_t color);
void print_str(char *str, uint8_t color);
void set_cursor(uint8_t pos);

#endif 
