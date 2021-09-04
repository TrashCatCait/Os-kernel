#include "includes/inttypes.h"
#include "includes/gdt.h"
#include "includes/io.h"
#include "includes/kernel.h"
#include "includes/idt.h"

efiinfo_t *KI;
framebuffer_t *FB;

#define RED (uint32_t) 0xff0000
#define GREEN (uint32_t) 0x00ff00
#define BLUE (uint32_t) 0x0000ff

void ker_init(efiinfo_t kernelInfo) {
    //define global pointers of the boot info
    KI = &kernelInfo;
    FB = &kernelInfo.frameBuf;
    //Clear interupts
    clear_int();
    //red means gdt error
    clr_scr_gop(
            FB->scanLine, FB->width, 
            FB->height, RED, FB->baseAdd
            );
    //Init gdt and load it
    
    init_gdt();
    //Green means idt error
    clr_scr_gop(
            FB->scanLine, FB->width, 
            FB->height, GREEN, FB->baseAdd
            );
    init_idt();
    
    //blue means we got to the end of the ker_init function
    clr_scr_gop(
            FB->scanLine, FB->width, 
            FB->height, BLUE, FB->baseAdd
            );
    //init_paging
}

void ker_start(efiinfo_t kernelInfo) {
    hltloop();
    ker_init(kernelInfo);
    while (1) {
        clr_scr_gop(
                FB->scanLine, FB->width, FB->height, 
                (BLUE | RED), FB->baseAdd
                );
        hltloop();
    }
}

