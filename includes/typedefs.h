#ifndef INT_TYPE_DEFS
#define INT_TYPE_DEFS

//64 bit
typedef unsigned long long uint64_t;
typedef long long int64_t;
typedef uint64_t size_t;

//32 bit
typedef unsigned int uint32_t;
typedef int int32_t;

//16 bit
typedef unsigned short uint16_t;
typedef short int16_t;

//8 bit
typedef unsigned char uint8_t;
typedef char int8_t;

//NULL
#define NULL 0

//Structures
typedef struct framebfr {
    uint8_t *buffer_base;
    size_t size;
    uint32_t width;
    uint32_t height;
    uint32_t ppsl;
}__attribute__((packed)) framebfr_t;

typedef struct efi_memory {
    uint32_t type;
    uint32_t pad;
    uint64_t paddr;
    uint64_t vaddr;
    uint64_t numofPages;
    uint64_t attr;
} efi_memory_t;

//at the moment we assume e820 is supported by BIOS but may add the option to use others.
//should this be unsupported but for now this should encapsulate all PC's newer than 2002ish.
//after all the boot signature could be changed from BIOS to e820, then e*** for any other BIOS
//memory maps are going to support
typedef struct e820_memory {
    uint64_t base_addr;
    uint64_t length;
    uint32_t type;
    uint32_t attr;
}__attribute__((packed)) e820_memory_t;

typedef struct bootinfo {
    char signature[4];
    uint8_t *memmap_loc;
    uint8_t *fontmap;
}__attribute__((packed)) bootinfo_t;



#endif
