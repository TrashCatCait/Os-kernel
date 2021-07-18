#ifndef KERNEL_H
#define KERNEL_H
#include "utils.h"

void ker_init(bootInfo kernelInfo); 
void keyboard_handle(char scancode);
void _start(bootInfo kernelInfo);

#endif
