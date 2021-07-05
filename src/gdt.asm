;This was initally done in C however this lead to much larger executeable size so I just reimplemented it in ASM
gdt_start:
null:
dq 0x00 ;;null segement should be zero  
gdt_kernel_code:
dw 0x00
dw 0x00
db 0x00
db 0x9a
db 0xa0 
db 0x00
gdt_kernel_data:
dw 0x00
dw 0x00
db 0x00
db 0x92
db 0xa0
db 0x00

user_null:
dq 0x00 ;;null should be zero
gdt_user_code:
dw 0x00
dw 0x00
db 0x00
db 0x9a
db 0xa0 
db 0x00
gdt_user_data:
dw 0x00 
dw 0x00
db 0x00
db 0x92
db 0xa0
db 0x00
gdt_end:

gdt_pointer:
dw gdt_end - gdt_start - 1 ;size of gdt - 1
dq gdt_start ;offset 

;There is probably a way to do this with inline C but I'm not super comfortable with that. So instead did it in straight ASM and linked it with C.

load_gdt:
lgdt [gdt_pointer] ;This function will be called from C meaning out gdt descriptor should be stored in RDI
;These labels are used so that if the table changes these offset will still be correct
mov ax, gdt_kernel_data ;;set ax to the data offset 
mov ds, ax ;;set all the other registers to this.
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax
pop rdi ;;pop the return address into rdi
mov rax, gdt_kernel_code ;;load in the kernel code
push rax ;;push it 
push rdi ;;push it back on the stack
retfq ;Return to our C code


;define this as global 
global load_gdt
