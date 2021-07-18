#include "includes/inttypes.h"
#include "includes/gdt.h"
#include "includes/io.h"
#include "includes/utils.h"
#include "includes/idt.h" 
#include "includes/kernel.h"

bootInfo *KI;
frameBuffer *FB;

void ker_init(bootInfo kernelInfo) {
    //redefine bootInfo to make it global for the kernel as this is extremly useful. Tecnically not new variables just pointers to the old ones
    KI = &kernelInfo;
    FB = &kernelInfo.frameBuf;
    clear_int();
    //Used as psudeo error code as text isn't support so if the screen stops at red I know an error has happened.
    //red means gdt error
    clrScrGop(FB->PPSL, FB->width, FB->height, 0xff0000, FB->baseAdd);

    //set up some stuff for or kernel
    load_gdt();
    //Green means idt error
    clrScrGop(FB->PPSL, FB->width, FB->height, 0x00ff00, FB->baseAdd);
    init_idt();
    enable_int();
    return;
}

void keyboard_handle(char scancode){
    clrScrGop(FB->PPSL, FB->width, FB->height, 0xfff0f0, FB->baseAdd);
}

void _start(bootInfo kernelInfo) {
    ker_init(kernelInfo);
    clrScrGop(FB->PPSL, FB->width, FB->height, 0x0000ff, FB->baseAdd); 
    while (1) {
        //this is treated as success for now
    }
    return;
}

