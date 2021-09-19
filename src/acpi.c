#include <acpi.h>
#include <strings.h>
#include <gui.h>
/*
 * Techincally working ACPI code but i need to add a lot more check to this
 * to make it actually work well and handle different situations well
 */

uint8_t *find_rsdp(uint8_t* start, const uint8_t *end) {
    struct rsdp_descriptor_2 *rsdp;

    for(; start < end; start += 16){
	rsdp = (struct rsdp_descriptor_2*) start;
	
	if(strn_cmp(rsdp->version_one.signature, "RSD PTR ", 8)) {
	    draw_str8x16("RSD PTR FOUND?\n", 0x0f,0,0);
	    return start;
	}
    }
    return 0;
}
