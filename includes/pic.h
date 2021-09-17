#ifndef PIC_H
#define PIC_H

#include <typedefs.h>

#define PIC1 0x0020
#define PIC2 0x00a0
#define PIC1_COM PIC1 
#define PIC2_COM PIC2 
#define PIC1_DATA (PIC1+1)
#define PIC2_DATA (PIC2+1)

void remap_pic(uint8_t moffset, uint8_t soffset);
void mask_pic(uint8_t mmask, uint8_t smask);

#endif 
