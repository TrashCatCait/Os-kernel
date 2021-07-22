#ifndef IDT_H
#define IDT_H
#include "inttypes.h"

#define CALLGATE16 0x4
#define TASKGATE 0x5
#define INTERUPTGATE16 0x6
#define TRAPGATE16 0x7

#define CALLGATE32 0xC
#define INTERUPTGATE32 0xE
#define TRAPGATE32 0xF

typedef struct idtentry {
    uint16_t offset_low; //offset
    uint16_t selector; //code segement selector of GDT
    uint8_t ist; //bits 0..2 holds IST offset.
    uint8_t type : 4;
    uint8_t storage : 1;
    uint8_t priv_lvl : 2;
    uint8_t present : 1;
    uint16_t offset_med;
    uint32_t offset_high;
    uint32_t resevered;
}__attribute__((packed)) idtentry_t;

typedef struct idtr {
    uint16_t limit;
    uint64_t base;
}__attribute__((packed)) idtr_t;

#endif
