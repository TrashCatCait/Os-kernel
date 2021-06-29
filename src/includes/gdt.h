#ifndef GDT_H
#define GDT_H

#include "inttypes.h"

struct gdtDesc {
    uint16_t size;
    uint64_t offset;
};

struct gdtEntry {
    uint16_t limitLow;
    uint16_t baseLow;
    uint8_t baseMed;
    uint8_t accessByte;
    uint8_t limitMedFlags;
    uint8_t baseHigh;
};

struct gdt {
    struct gdtEntry null;
    struct gdtEntry Code;
    struct gdtEntry Data;
};


#endif
