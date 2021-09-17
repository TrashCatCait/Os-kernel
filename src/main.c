#include <acpi.h>
#include <gdt.h>
#include <idt.h>
#include <io.h>
#include <smbios.h>
#include <textmode.h>
#include <typedefs.h>

typedef struct framebfr {
    uint8_t *buffer_base;
    size_t size;
    uint32_t width;
    uint32_t height;
    uint32_t ppsl;
} framebfr_t;

typedef struct efi_memory {
    uint32_t type;
    uint32_t pad;
    uint64_t paddr;
    uint64_t vaddr;
    uint64_t numofPages;
    uint64_t attr;
}__attribute__((packed)) efi_memory_t;

//at the moment we assume e820 is supported by BIOS but may add the option to use others.
//should this be unsupported but for now this should encapsulate all PC's newer than 2002ish.
//after all the boot signature could be changed from BIOS to e820, then e*** for any other BIOS
//memory maps are going to support
typedef struct e820_memory {
    uint64_t base_addr;
    uint64_t length;
    uint32_t type;
    uint32_t attr;
} e820_memory_t;

typedef struct bootinfo {
    char signature[4];
    uint64_t memmap_loc;
}__attribute__((packed)) bootinfo_t;

/*
 * honestly I'm more happy I managed to boot a 64 bit elf file from nothing
 * but BIOS I've done this with UEFI before but wanted to do BIOS as it's just
 * more educational imho
 * - Cat 2021/09/09
 */

//I put all init stuff in here for simplicity
void kernel_init() {
    clear_interupts(); //clear hardware interupts 
    clear_scr(0x0f);
    set_cursor(0); //set the cursor to position zero.
    print_str("Hello world from an elf kernel written in C", 0x0f);
    
    init_gdt(); //set up and attempt to load GDT
    set_cursor(80); //set cursor position to 80 
    print_str("Loaded Kernel GDT Successfully",0x0f); //print string
    
    init_idt(); //set up and load IDT
    set_cursor(160); 
    print_str("Loaded IDT Successfully please press a key to trigger an interupt",0x0f);
    //uint8_t *rsdpptr = find_rsdp((uint8_t*)0x000e0000, (uint8_t*)0x000fffff);


    //uint8_t *smbios = find_smbios32((uint8_t*)0x000e0000, (uint8_t *)0x000fffff);
    //uint8_t *smbios64 = find_smbios64((uint8_t*)0x000e0000, (uint8_t *)0x00200000/*0x001fffff*/);
}

void kernel_main(framebfr_t *framebuffer) {
    kernel_init(); //initliase the kernel
    if(framebuffer->width == 320) {
    for(size_t i = 0; i < framebuffer->size; i++)
    {
	framebuffer->buffer_base[i] = 0x01;
    }
    for(uint32_t i = 0; i < framebuffer->width; i++)
    {
	framebuffer->buffer_base[i] = 0x02;
    }
    for(size_t i = 0; i < framebuffer->size; i+=framebuffer->width)
    {
	framebuffer->buffer_base[i] = 0x03;
    }
    }	
    while(1) {
	hlt_c(); //halt the CPU until interupt occurs
    }
}
