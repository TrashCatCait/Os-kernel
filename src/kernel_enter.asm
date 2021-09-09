[bits 64]

section .catboot
    dd 0xcafebabe

section .text
    global kernel_start
    extern kernel_main

kernel_start:
    cli
    
    mov rax,0x1f201f201f201f20
    mov rdi,0xb8000
    mov rcx,500
    rep stosq

    call kernel_main ;we should never return here.
    cli ;disable interupts
    jmp $ ;but if we do somehow loop endlessly

section .data

section .rodata

section .bss
