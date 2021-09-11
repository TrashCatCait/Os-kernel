#include "includes/idt.h"
#include "includes/isr.h"
#include "includes/typedefs.h"

void idt_set_isr(idt64_entry_t *entry, void *isr, uint8_t flags) {
    entry->reserved = 0;
    entry->offset_low = (uint64_t)isr & 0xffff;
    entry->offset_mid = ((uint64_t)isr >> 16) & 0xffff;
    entry->offset_high = ((uint64_t)isr >> 32) & 0xffffffff;
    entry->ist = 0;
    entry->kernel_cs = 0x08;
    entry->type_attr = flags;

}

void init_idt() {
    static idt64_entry_t idt[256]; //256 entries in IDT
    idtr64_t idtDesc;

    idt_set_isr(&idt[1], &isr1, 0x8e);
    

    idtDesc.size = sizeof(idt) - 1;
    idtDesc.offset = (uint64_t)&idt[0];

    load_idt(&idtDesc);
}
