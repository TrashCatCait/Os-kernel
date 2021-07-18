out_byte:
mov dx,di ;;mov port from lower bytes of rdi to dx
mov ax,si ;;mov data from lower bytes of rsi to ax
out dx,al ;;sent data from al to port in dx
retq

out_word:
mov dx,di
mov ax,si
out dx,ax
retq

out_dword: 
mov dx,di
mov eax,esi
out dx,eax
retq

in_byte:
mov dx,di ;;mov the port from lower bytes of rdi to dx
xor rax,rax ;;Xor rax as we return ax and dont want left overs
in al,dx ;;port byte from port in dx into al then return
retq

in_word:
mov dx,di
xor rax,rax
in ax,dx
retq

in_dword:
mov dx,di 
xor rax,rax
in eax,dx
retq

wait_io: 
push ax ;Save value of register 
xor al,al ;xor it 
out 0x80, al ;out to 0x80
pop ax ;pop the original value (ps not sure if this matters but probably an idea to save it just in case)
retq

;;hlt the system until the next interupt
hltloop:
hlt
retq

;;hang the computer and clear interupts 
;;Hlt the process and if a special interupt such as NMI
;;jmp back and halt the computer again
hangloop:
cli 
hlt 
jmp hangloop
retq
;;as far as I know there is no way in C 
;;so for easyness I made a function 
;;I can call from C same with sti 
clear_int:
cli
retq
;;enable interupts
enable_int:
sti
retq 

global enable_int
global clear_int
global hltloop
global hangloop
global in_byte
global out_byte
global in_word
global out_word
global in_dword
global out_dword
global wait_io
