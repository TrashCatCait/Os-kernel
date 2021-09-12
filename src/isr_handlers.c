#include "includes/isr_handlers.h"
#include "includes/io.h"
#include "includes/textmode.h"

void isr14_handler() {
    
    print_str("EXCEPTION: PAGE FAULT",0x0f);
    while(1);
}

//called from ASM
void isr33_handler() {
    uint8_t scan_code = in_byte(0x0060); //read byte in from keyboard 
    set_cursor(240);
    print_str("Hello Interupts",0x0f);
    //send end of interupt to pic
    out_byte(0x20, 0x20);
    out_byte(0xa0, 0x20);
}
