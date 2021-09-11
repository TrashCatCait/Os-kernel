#include "includes/typedefs.h"
#include "includes/textmode.h"
#include "includes/gdt.h"
#include "includes/io.h"

/*
 * honestly I'm more happy I managed to boot a 64 bit elf file from nothing
 * but BIOS I've done this with UEFI before but wanted to do BIOS as it's just
 * more educational imho
 * - Cat 2021/09/09
 */

//I put all init stuff in here for simplicity
void kernel_init() {
    clear_interupts(); //clear hardware interupts 
    clear_scr(); //clear the screen.
    set_cursor(0); //set the cursor to position zero.
    print_str("Hello world from an elf kernel written in C", 0x1f);
    
    init_gdt(); //set up and attempt to load GDT
    set_cursor(80); //set cursor position to 80 
    print_str("Loaded Kernel GDT Successfully",0x1f); //print string
}

void kernel_main() {
    kernel_init(); //initliase the kernel
    while(1) {
	hlt_c(); //halt the CPU until interupt occurs
    }
}
