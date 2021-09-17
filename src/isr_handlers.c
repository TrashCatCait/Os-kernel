#include <io.h>
#include <isr_handlers.h>
#include <pic.h>
#include <textmode.h>

void isr0_handler() {
    clear_scr(0x0f);
    print_str("EXCEPTION: DIVISION BY ZERO", 0x4f);
}

void isr1_handler() {

}

void isr2_handler() {

}

void isr3_handler() {

}

void isr4_handler() {

}

void isr5_handler() {

}

void isr6_handler() {

}

void isr7_handler() {
}

void isr8_handler() {
    clear_scr(0x0f);
    print_str("Exception: Double Fault",0x4f);
    kernel_hang();
}

void isr9_handler() {
    clear_scr(0x0f);
    print_str("Exception: Co-Processor Segement overun", 0x0f);
    kernel_hang();
}

void isr10_handler() {

}

void isr11_handler() {

}

void isr12_handler() {

}

void isr13_handler() {
    clear_scr(0x0f);
    print_str("Exception: General Protection Fault",0x4f);
    kernel_hang();
}

void isr14_handler() {
    clear_scr(0x0f); 
    print_str("Exception: Page fault",0x4f);
    kernel_hang();
}

void isr15_handler() {
    
}

void isr16_handler() {

}

void isr17_handler() {

}

void isr18_handler() {

}

void isr19_handler() {

}

void isr20_handler() {

}

void isr21_handler() {

}

void isr22_handler() {

}

void isr23_handler() {

}

void isr24_handler() {

}

void isr25_handler() {

}
void isr26_handler() {

}

void isr27_handler() {

}

void isr28_handler() {

}

void isr29_handler() {

}

void isr30_handler() {

}

void isr31_handler() {

}

void isr32_handler() {
    
    out_byte(0x20,0x20);
    out_byte(0xa0,0x20);
}

//called from ASM
void isr33_handler() {
    set_cursor(240);
    print_str("Hello Interupts",0x0f);
    //send end of interupt to pic
    out_byte(0x20, 0x20);
    out_byte(0xa0, 0x20);
}
