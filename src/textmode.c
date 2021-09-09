#include "./includes/textmode.h"

static uint16_t cursor_pos; 

void print_char(int8_t character, uint8_t color) {
    *(VGA_MEM + (cursor_pos * 2)) = character;
    *(VGA_MEM + (cursor_pos * 2) + 1) = color;
    cursor_pos++;
}

void print_str(char *str, uint8_t color) {
    
    while(*str != 0) //loop until null term is read
    {
	print_char(*str, color); //call print char code with
	str++; //increment char pointer + 1 
    }
}

void set_cursor(uint8_t pos) {
    //need IO to actually implement inb and outb needed 
    cursor_pos = pos;
}
