#include <smbios.h>
#include <strings.h>
#include <textmode.h>

/*
 * all printing is used as debug and to give me visual representations
 * will obvisually be removed from final kernel 
 */


uint8_t *find_smbios32(uint8_t *start, const uint8_t *end) {
    struct smbios32_entry *smbios32;
    set_cursor(cords_to_pos(0,6));

    for(;start < end; start += 16) {
	smbios32 = (struct smbios32_entry*) start;
	if(strn_cmp(smbios32->anchor_str, "_SM_", 4)) {
	    print_str("SMBIOS found\n",0x0f);
	    print_strn(smbios32->dmi_anchor_str, 0x0f, 5);
	    return start;
	}

    }
    print_str("SMBIOS not found",0x0f);
    return NULL;
}

/*
 * search for the 64 bit entry point
 * according to what I've heard this is 
 * post 2015 though may have been around before that 
 * Maybe... depends how accurate what I've read is.
 * Either way if it exists we will find it if not 
 * we just have to relie on the 32bit entry point.
 */
uint8_t *find_smbios64(uint8_t *start, const uint8_t *end) {
    struct smbios64_entry *smbios64;
    set_cursor(cords_to_pos(0,8));
    
    for(; start < end; start += 16) {
	smbios64 = (struct smbios64_entry*) start;

	if(strn_cmp(smbios64->anchor_str, "_SM3_", 5)) {
	    print_str("SMBIOS 64 found", 0x0f);
	    return start;
	}
    }

    print_str("SMBIOS 64 not found", 0x0f);
    return NULL; 
}
