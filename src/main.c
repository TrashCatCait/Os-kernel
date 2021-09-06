
//64 bit
typedef unsigned long long uint64_t;
typedef long long int64_t;

//32 bit
typedef unsigned int uint32_t;
typedef int int32_t;

//16 bit
typedef unsigned short uint16_t;
typedef short int16_t;

//8 bit
typedef unsigned char uint8_t;
typedef char int8_t;

//Define the length as 80 chars long
#define VGA_COLS 80
#define VGA_MEM (uint8_t*)0x00000000000b8000 

static uint16_t cursor_pos; 

void print_char(int8_t character, uint8_t color) {
    *(VGA_MEM + (cursor_pos * 2)) = character;
    *(VGA_MEM + (cursor_pos * 2) + 1) = color;
    cursor_pos++;
}

void print_str(char *str, uint8_t color, int len) {
    *(VGA_MEM + (cursor_pos * 2)) = *str;
    *(VGA_MEM + (cursor_pos * 2) + 1) = color;
}	

void kernel_main() {
    cursor_pos = 0;
    //Tried to get print_str working but it's 5 am and for some
    //reason making a character just causes a page fault and I'm
    //unsure as to why so I need to look into that.
    //Either way wooo C code now i just have to track down that 
    //page fault
    print_char('H',0x2f);
    print_char('e',0x2f);
    print_char('l',0x2f);
    print_char('l',0x2f);
    print_char('o',0x2f);
}
