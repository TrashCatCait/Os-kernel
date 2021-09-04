[bits 64]

section .bootcat
dq 0x6980081e


section .text
    global kernel_start

kernel_start:
    mov rdi,0xb8000
    mov rax, 0x2f202f202f202f20
    mov ecx, 500
    rep stosq
    jmp $

section .data

section .rodata

section .bss
