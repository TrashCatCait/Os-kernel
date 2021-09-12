#ifndef SMBIOS_H
#define SMBIOS_H
#include "./typedefs.h"

struct smbios32_entry {
    char anchor_str[4]; //version 1 - 2.9 anchor string
    uint8_t checksum; //This value added with rest of table should be 0 due to overflowing
    uint8_t length; //length of entry point table
    uint8_t major_ver; //major version number
    uint8_t minor_ver; //minor version number
    uint16_t max_struct_size; //maximum size of SMBIOS struct
    uint8_t entry_point_revision;
    int8_t formatted_area[5];
    char dmi_anchor_str[5]; //anchor string _DMI_
    uint8_t dmi_checksum; //check sum from dmi_anchor_str onwords 
    uint16_t table_length; //length of table containing all SMBIOS structs 
    uint32_t table_addr; //Address of the table 
    uint16_t no_of_structs; //number of structures in table 
    uint8_t bcd_revision; //
};


struct smbios64_entry {
    char anchor_str[5]; //version 3
    uint8_t checksum; //This value added with rest of table should be 0 due to overflowing
    uint8_t length; //length of entry point table
    uint8_t major_ver; //major version number
    uint8_t minor_ver; //minor version number
    uint8_t doc_rev; 
    uint8_t entry_point_rev;

};

//function to located pre 2015 structure
uint8_t *find_smbios32(uint8_t *start, uint8_t *end);
//function to located post 2015 structure
uint8_t *find_smbios64(uint8_t *start, uint8_t *end);


#endif
