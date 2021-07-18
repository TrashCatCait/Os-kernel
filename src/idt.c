#include "includes/idt.h"
#include "includes/io.h"
#include "includes/utils.h"
#include "includes/inttypes.h"
#include "includes/interupts.h"
#include "includes/loadidt.h"

__attribute__((aligned(0x10))) 
static idt64_entry_t idt[256];
static idtr_t idtr;

void idt_set_desc(uint8_t vector, void *isr, uint8_t flags) {
    idt64_entry_t* descriptor = &idt[vector]; 

    descriptor->selector = 0x08; //GDT kernel offset
    descriptor->offsetLow = (uint16_t)((uint64_t)isr & 0x000000000000ffff);
    descriptor->ist = 0;
    descriptor->typeAttr = flags;
    descriptor->offsetMed = (uint16_t)((uint64_t)isr & 0x00000000ffff0000 >> 16);
    descriptor->offsetHigh = (uint32_t)((uint64_t)isr & 0xffffffff00000000 >> 32);
    descriptor->zero = 0;

}

void init_idt() {
    remap_pic(0x20, 0x28); 
    for(int i = 0; i < 256; i++) {
        idt_set_desc(0, 0, 0);
    }
    idt_set_desc(0x2d, &isr1_handle, 0x8e);
    idtr.limit = (sizeof(idt64_entry_t) * 256) - 1; 
    idtr.base = (uint64_t) &idt;
       
    load_idt(&idtr);
    
}
