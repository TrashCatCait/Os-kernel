#include "includes/gdt.h"
#include "includes/inttypes.h"


void init_gdt(){
    //static should set this to all zero
    static gdtentry_t gdt[5];    
    gdtr_t gdtPointer;
    
    gdtentry_t *null = &gdt[0];
    gdtentry_t *kernelCode = &gdt[1];
    gdtentry_t *kernelData = &gdt[2];
    gdtentry_t *userCode = &gdt[3];
    gdtentry_t *userData = &gdt[4];

    kernelCode->limit_low = 0xffff;
    kernelCode->base_low = 0;
    kernelCode->base_med = 0;
    kernelCode->accessed = 0; //This is set by the CPU
    kernelCode->read_write = 1;
    kernelCode->direction_bit = 0;
    kernelCode->executeable = 1;
    kernelCode->descriptor = 1;
    kernelCode->priv_lvl = 0; // ring 3
    kernelCode->present = 1;
    kernelCode->limit_high = 0xf;
    kernelCode->avail = 0;
    kernelCode->long_mode = 1;
    kernelCode->size = 1;
    kernelCode->gran = 1;
    kernelCode->base_high = 0;

    //These entries are slightly similar.
    //So we just copy and paste them and 
    //change what needs to be changed.
    *kernelData = *kernelCode;
    kernelData->executeable = 0;

    *userCode = *kernelCode;
    userCode->priv_lvl = 3;

    *userData = *userCode;
    userData->executeable = 0;
    
    gdtPointer.size = (sizeof(gdtentry_t) * 5) - 1;
    gdtPointer.offset = (uint64_t)&gdt;
    
    loadgdt(&gdtPointer);
    return;
}