#ifndef GDT_H
#define GDT_H
#include <typedefs.h>

typedef struct gdt_entry {
    uint16_t limit_low : 16; 
    uint16_t base_low : 16;
    uint8_t base_med : 8; //39
    uint8_t accessed : 1; //40
    uint8_t read_write : 1; //41
    uint8_t direction_bit : 1; //42
    uint8_t executeable : 1; //43
    uint8_t descriptor : 1; //44
    uint8_t priv_lvl : 2; //46
    uint8_t present : 1; //47 
    uint8_t limit_high : 4; //51
    uint8_t avail : 1; //used only in software not in hardware
    uint8_t long_mode : 1;
    uint8_t size : 1;
    uint8_t gran : 1;
    uint8_t base_high : 8;
}__attribute__((packed)) gdt_entry_t; //create type of a packed structure for entry

typedef struct gdtr {
    uint16_t size;
    uint64_t offset;
}__attribute__((packed)) gdtr_t; //create type of gdt descriptor

void init_gdt();
extern void load_gdt(gdtr_t *descriptor); //calls external asm code

#endif 
