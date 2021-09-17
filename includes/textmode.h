#ifndef BIOS_TEXT_MODE_H
#define BIOS_TEXT_MODE_H 
#include <typedefs.h>
#include <va_list.h>

#define VGA_COLS 80 
#define VGA_MEM (uint8_t*)0xb8000

/*functions for BIOS VGA text mode screen control to be used until we initialse GPU*/

uint16_t cords_to_pos(uint8_t col, uint8_t row);
void set_cursor(uint16_t pos);
void print_char(char character, uint8_t color);
void print_str(char *str, uint8_t color);
void clear_scr(uint8_t color);
void scroll();
void print_strn(char *str, uint8_t color, uint32_t len);
void print_num(int64_t number, int len);

#endif 
