[bits 64]

loadgdt:
    lgdt [rdi]
    mov rax, 0x08
    push rax
    mov rdi, flush
    push rdi
    retfq

flush:
    mov ax, 0x10
    mov ds, ax
    mov es, ax 
    mov fs, ax 
    mov gs, ax
    mov ss, ax   
    ret


global loadgdt
