#ifndef KERNEL_H
#define KERNEL_H
#include "utils.h"

void ker_init(efiinfo_t kernelInfo); 
void _start(efiinfo_t kernelInfo);

#endif