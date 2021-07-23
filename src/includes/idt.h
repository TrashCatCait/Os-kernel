#ifndef SRC_INCLUDES_IDT_H
#define SRC_INCLUDES_IDT_H
#include "inttypes.h"

#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)

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
    uint8_t type;
    uint16_t offset_med;
    uint32_t offset_high;
    uint32_t resevered;
}__attribute__((packed)) idtentry_t;

typedef struct idtr {
    uint16_t limit;
    uint64_t base;
}__attribute__((packed)) idtr_t;

void isr1_handle();

void init_idt();
void idt_set_descriptor(uint8_t vector, uint64_t isr, uint8_t flag);
void remap_pic(uint8_t mask1, uint8_t mask2);
extern void loadidt();



#endif
