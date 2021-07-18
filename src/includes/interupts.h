#ifndef INTERUPTS_H
#define INTERUPTS_H

#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)
#include "inttypes.h"
struct interrupt_frame
{
    uint16_t ip;
    uint16_t cs;
    uint16_t flags;
    uint16_t sp;
    uint16_t ss;
};
 
__attribute__ ((interrupt))
void isr1_handle(struct interrupt_frame *frame);
void remap_pic(uint8_t offset1, uint8_t offset2); 



#endif
