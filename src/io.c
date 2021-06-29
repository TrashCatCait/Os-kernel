#include "includes/io.h"
//IO
uint8_t in_byte(uint16_t port){
    uint8_t output;
    asm volatile ("inb %1, %0" : "=a"(output) : "Nd"(port));
    return output;
}

void out_byte(uint16_t port, uint8_t value){
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

