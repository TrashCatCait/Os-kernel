#ifndef ACPI_H
#define ACPI_H
#include <typedefs.h>

struct rsdp_descriptor {
    char signature[8];
    uint8_t checksum;
    char oem_id[6];
    uint8_t revision;
    uint32_t rsdt_address;
}__attribute__((packed));

struct rsdp_descriptor_2 {
    struct rsdp_descriptor version_one;
    uint32_t length;
    uint64_t xsdt_address;
    uint8_t extended_checksum;
    uint8_t reserve[3];
}__attribute__((packed));

uint8_t *find_rsdp(uint8_t *start, const uint8_t *end);

#endif 
