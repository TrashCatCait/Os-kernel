#include "./includes/interupts.h"
#include "./includes/io.h"
#include "./includes/inttypes.h"
#include "./includes/kernel.h"
 
__attribute__ ((interrupt))
void isr1_handle(struct interrupt_frame *frame) {
    __asm__("xor %rax, %rax");
    uint8_t scancode = in_byte(0x60);
    out_byte(0x20, 0x20);
	out_byte(0xa0, 0x20);
}

void remap_pic(uint8_t offset1, uint8_t offset2){ 
    uint8_t a1, a2;

    a1 = in_byte(PIC1_DATA);
    a2 = in_byte(PIC2_DATA);


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
 
	out_byte(PIC1_DATA, 0xfd);   // restore saved masks.
	out_byte(PIC2_DATA, 0xff);

}
