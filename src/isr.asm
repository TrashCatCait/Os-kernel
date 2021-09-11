[bits 64]

section .text 
    global isr1
    extern isr1_handler
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

isr1:
   pushaq
   call isr1_handler
   popaq
   iretq
