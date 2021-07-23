#include "includes/idt.h"
#include "includes/io.h"

idtentry_t idt[256];
extern uint64_t isr1;

void isr1_handle() {
    uint8_t scanCode = in_byte(0x60);
    
    out_byte(0x20, 0x20);
    out_byte(0x20, 0x20);
}

void remap_pic(uint8_t offset1, uint8_t offset2){
    uint8_t mask1, mask2;

    mask1 = in_byte(PIC1_DATA);
    mask2 = in_byte(PIC2_DATA);


    //start init in cascade mode
    out_byte(PIC1_COMMAND, 0x11);
    wait_io();
    out_byte(PIC2_COMMAND, 0x11);
    wait_io();

    out_byte(PIC1_DATA, offset1);                 // ICW2: Master PIC vector offset
	wait_io();
	out_byte(PIC2_DATA, offset2);                 // ICW2: Slave PIC vector offset
	wait_io();


	out_byte(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	wait_io();
	out_byte(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
	wait_io();
 
	out_byte(PIC1_DATA, 0x01);
	wait_io();
	out_byte(PIC2_DATA, 0x01);
	wait_io();
 
	out_byte(PIC1_DATA, mask1);   // restore saved masks.
	out_byte(PIC2_DATA, mask2);
}

void idt_set_descriptor(uint8_t vector, uint64_t isr, uint8_t flag) {
    idtentry_t *entry = &idt[vector];

    entry->offset_low = (uint64_t) &isr & 0xffff;
    entry->selector = 0x38;
    entry->ist = 0;
    entry->type = flag;
    entry->offset_med = ((uint64_t)&isr >> 16) & 0xffff;
    entry->offset_high = ((uint64_t)&isr >> 32) & 0xffffffff;
    entry->resevered = 0;
}

void init_idt() {
    
    idt_set_descriptor(0x20, isr1, 0x8e);
    remap_pic(0x20, 0x28);
    out_byte(0x21, 0xfd);
    out_byte(0xa1, 0xff);

    loadidt();
}
