#ifndef BIOS_TEXT_MODE_H
#define BIOS_TEXT_MODE_H 
#include "./typedefs.h"

#define VGA_COLS 80 
#define VGA_MEM (uint8_t*)0xb8000

/*functions for BIOS VGA text mode screen control to be used until we initialse GPU*/

void set_cursor(uint16_t pos);
void print_char(char character, uint8_t color);
void print_str(char *str, uint8_t color);
void clear_scr();

#endif 
