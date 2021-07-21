#include "includes/inttypes.h"
#include "includes/gdt.h"
#include "includes/io.h"
#include "includes/kernel.h"

efiinfo_t *KI;
framebuffer_t *FB;

void ker_init(efiinfo_t kernelInfo) {
    //define global pointers of the boot info
    KI = &kernelInfo;
    FB = &kernelInfo.frameBuf;
    clear_int();
    //red means gdt error
    clr_scr_gop(FB->scanLine, FB->width, FB->height, 0xff0000, FB->baseAdd);
    init_gdt();

    //Green means idt error
    clr_scr_gop(FB->scanLine, FB->width, FB->height, 0x00ff00, FB->baseAdd);
    //init_idt();
    //enable_int();
    
    //blue means we got to the end of the ker_init function
    clr_scr_gop(FB->scanLine, FB->width, FB->height, 0x0000ff, FB->baseAdd);
}

void ker_start(efiinfo_t kernelInfo) {
    ker_init(kernelInfo);
    while (1) {

        //this is treated as success for now
    }
}

