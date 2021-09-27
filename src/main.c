#include <acpi.h>
#include <gdt.h>
#include <idt.h>
#include <io.h>
#include <smbios.h>
#include <typedefs.h>
#include <gui.h>
/*
 * honestly I'm more happy I managed to boot a 64 bit elf file from nothing
 * but BIOS I've done this with UEFI before but wanted to do BIOS as it's just
 * more educational imho
 * - Cat 2021/09/09
 */

//I put all init stuff in here for simplicity
void kernel_init(framebfr_t *fb, bootinfo_t *bi) {
    clear_interupts();
    setup_bfr(fb); 
    load_font(bi);
    clear_gui(0x00);

    draw_str8x16("Hello world from an elf kernel written in C", 0x0f, 0, 0);

    init_gdt(); //set up and attempt to load GDT
    draw_str8x16("Loaded Kernel GDT Successfully",0x0f, 0, 16); //print string

    init_idt(); //set up and load IDT
    draw_str8x16("Loaded IDT Successfully please press a key to trigger an interupt",0x0f, 0, 0);
    uint8_t *rsdpptr = find_rsdp((uint8_t*)0x000e0000, (uint8_t*)0x000fffff);

    //uint8_t *smbios = find_smbios32((uint8_t*)0x000e0000, (uint8_t *)0x000fffff);
    //uint8_t *smbios64 = find_smbios64((uint8_t*)0x000e0000, (uint8_t *)0x00200000/*0x001fffff*/);
}


void kernel_main(framebfr_t *fb, bootinfo_t *bootinfo) {
    kernel_init(fb, bootinfo); //initliase the kernel
    clear_gui(0x00);
    while(1) {
	hlt_c(); //halt the CPU until interupt occurs
    }
}
