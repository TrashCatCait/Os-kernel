#ifndef IDT_H
#define IDT_H
#include "inttypes.h"

#define interuptGate 0b10001110
#define callGate 0b10001100
#define trapGate 0b10001111

//Based on https://wiki.osdev.org/Interrupts_tutorial 
typedef struct {
    uint16_t offsetLow; // 0..15
    uint16_t selector;
    uint8_t ist; // 0..2 IST offset rest 0
    uint8_t typeAttr; // interupt type
    uint16_t offsetMed;
    uint32_t offsetHigh;
    uint32_t zero; //reserved
}__attribute__((packed)) idt64_entry_t;

typedef struct {
    uint16_t limit;
    uint64_t base;
}__attribute__((packed)) idtr_t;

void init_idt();

#endif
