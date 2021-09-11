[bits 64]

section .catboot
    dd 0xcafebabe

section .text
    global kernel_start
    extern kernel_main

kernel_start:
    call kernel_main ;we should never return here.
    jmp $ ;but if we do somehow loop endlessly

section .data

section .rodata

section .bss
