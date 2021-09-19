OUTPUT_FORMAT(elf64-x86-64)
ENTRY(kernel_start)

INPUT 
(
    ./build/kernel_enter.o
    ./build/main.o
    ./build/textmode.o
    ./build/strings.o
    ./build/load_tables.o /*asm code to reload IDT, GDT, etc...*/
    ./build/gdt.o /*C code defining GDT*/
    ./build/io.o
    ./build/isr.o
    ./build/isr_handlers.o
    ./build/idt.o
    ./build/pic.o
    ./build/acpi.o
    ./build/smbios.o
    ./build/gui.o
)

SECTIONS
{
    . = 0x11000;
    .text : ALIGN(0x1000)
    {
	*(.catboot)
	*(.text)
    }
    .data : ALIGN(0x1000)
    {
	*(.data)
    }
    .rodata : ALIGN(0x1000)
    {
	*(.rodata)
    }
    .bss : ALIGN(0x1000)
    {
	*(COMMON)
	*(.bss)
    }

}
