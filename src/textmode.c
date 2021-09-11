#include "./includes/textmode.h"
#include "./includes/io.h"

static uint16_t cursor_pos; 
void set_cursor(uint16_t pos) {
    //need IO to actually implement inb and outb needed 
    out_byte(0x03d4,0x0f);
    out_byte(0x03d5,(uint8_t)pos);
    out_byte(0x03d4,0x0e);
    out_byte(0x03d5,(uint8_t)pos >> 8);
    cursor_pos = pos;
}

void print_char(int8_t character, uint8_t color) {
    *(VGA_MEM + (cursor_pos * 2)) = character;
    *(VGA_MEM + (cursor_pos * 2) + 1) = color;
    cursor_pos++;
    set_cursor(cursor_pos);
}

void print_str(char *str, uint8_t color) {
    while(*str != 0) //loop until null term is read
    {
	print_char(*str, color); //call print char code with
	str++; //increment char pointer + 1 
    }
}

void clear_scr(uint8_t color) {
    uint64_t color64 = color;
    uint64_t value = 0;
    value += color64 << 8;
    value += color64 << 24;
    value += color64 << 40;
    value += color64 << 56;
    for(uint64_t *i = (uint64_t*)VGA_MEM; i < (uint64_t*)(VGA_MEM+4000); i++) {
	*i = value;
    }
    set_cursor(0);
}
