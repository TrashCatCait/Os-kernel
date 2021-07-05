#ifndef IDT_H
#define IDT_H
#include "inttypes.h"

#define interuptGate 

//Based on https://wiki.osdev.org/Interrupts_tutorial 
struct idt_entry64_t {
    uint16_t offsetLow; // 0..15
    uint16_t gdtCS;
    uint8_t ist; // 0..2 IST offset rest 0
    uint8_t typeAttr; // interupt type
    uint16_t offsetMed;
    uint32_t offsetHigh;
    uint32_t zero; //reserved
};

struct idtr_t {
    uint16_t limit;
    uint64_t base;
};



#endif
