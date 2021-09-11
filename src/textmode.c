#include "./includes/textmode.h"
#include "./includes/io.h"

static uint16_t cursor_pos; 

void set_cursor(uint16_t pos) {
    //need IO to actually implement inb and outb needed 
    cursor_pos = pos;
}
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

//Basic function to reset BIOS VGA screen
void clear_scr() {
    uint64_t text_str = 0x1f201f201f201f20; //print spaces
    for (uint64_t* buffer = (uint64_t *)VGA_MEM; 
	buffer < (uint64_t*)(VGA_MEM + 4000); 
	buffer++) {
	*buffer = text_str;
    }
    set_cursor(0);
}
