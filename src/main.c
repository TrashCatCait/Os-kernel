#include "includes/typedefs.h"
#include "includes/textmode.h"
#include "includes/gdt.h"
/*
 * honestly I'm more happy I managed to boot a 64 bit elf file from nothing
 * but BIOS I've done this with UEFI before but wanted to do BIOS as it's just
 * more educational imho
 * - Cat 2021/09/09
 */

void kernel_main() {
    
    set_cursor(0); //set the cursor to position zero.
    print_str("Hello world from an elf kernel written in C", 0x1f);
    
    init_gdt();
    set_cursor(80); 
    print_str("Loaded Kernel GDT Successfully",0x1f);
}
