#include <io.h>
#include <textmode.h>

static uint16_t cursor_pos; 
/*
 * Makes setting exact position of the cursor easier
 * INPUT: uint8_t col 
 * OUTPUT: uint16_t cursor position
 */
uint16_t cords_to_pos(uint8_t col, uint8_t row) {
    return row * VGA_COLS + col; 
}

void set_cursor(uint16_t pos) {
    //need IO to actually implement inb and outb needed 
    out_byte(0x03d4,0x0f);
    out_byte(0x03d5,(uint8_t)(pos & 0xff));
    out_byte(0x03d4,0x0e);
    out_byte(0x03d5,(uint8_t)(pos >> 8 & 0xff));
    cursor_pos = pos;
}

void print_char(int8_t character, uint8_t color) {
    switch(character) {
	case '\n':
	    set_cursor(cursor_pos + 80);
	    set_cursor(cursor_pos -= cursor_pos % 80);
	    break;
	default:
	    *(VGA_MEM + (cursor_pos * 2)) = character;
	    *(VGA_MEM + (cursor_pos * 2) + 1) = color;
	    cursor_pos++;
	    set_cursor(cursor_pos);
    }
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

/*
 * print string function that works with non null terminated strings
 */
void print_strn(char *str, uint8_t color, uint32_t len) {
    int position = 0;
    while(position < len) {
	print_char(*str, color);
	position++;
	str++;
    }
}

