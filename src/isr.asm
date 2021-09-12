[bits 64]

section .text 
    global isr0
    global isr33
    extern isr33_handler

    

%macro pushaq 0
    push rax
    push rbx
    push rcx
    push rdx
%endmacro

%macro popaq 0
    pop rax
    pop rbx
    pop rcx
    pop rdx
%endmacro

isr0:
    pushaq
    popaq
    iretq

isr33:
   pushaq
   call isr1_handler
   popaq
   iretq
