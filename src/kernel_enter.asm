[bits 64]

section .catboot
    dd 0xcafebabe

section .text
    global kernel_start
    global load_gdt
    extern kernel_main

kernel_start:
    cli ;clear interupts as we are going to be reloading GDT and IDT.
    ;Rather than use bootloader deafults. As bootloader IDT & GDT not apporiate for 
    ;full scale os kernel 

    mov rax,0x1f201f201f201f20
    mov rdi,0xb8000
    mov rcx,500
    rep stosq

    call kernel_main ;we should never return here.
    jmp $ ;but if we do somehow loop endlessly

load_gdt:
    lgdt [rdi] ;called from C compiled on linux gdt pointer should be in RDI
    mov rax, 0x08 ;move the kernel code segement into rax 
    push rax ;push qword 0x08 to stack 
    mov rsi, segement_flush ;mov the segement address flush function to rsi
    push rsi ;push address to stack 
    retfq ;far qword return to flush function CS=0x08 and *S=0x10.

segement_flush:
    mov ax,0x10 ;set to kernel data segement of GDT
    mov ds, ax
    mov es, ax 
    mov fs, ax 
    mov gs, ax
    mov ss, ax   
    retq



section .data

section .rodata

section .bss
