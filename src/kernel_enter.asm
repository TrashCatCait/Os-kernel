[bits 64]

section .catboot
    dd 0xcafebabe

section .text
    global kernel_start
    extern kernel_main

kernel_start:
    cli
    mov rax,0x2f202f202f202f20
    mov rdi,0xb8000
    mov rcx,500
    rep stosq
    call kernel_main
    jmp $

