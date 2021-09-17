#include <acpi.h>
#include <strings.h>
#include <textmode.h>

/*
 * Techincally working ACPI code but i need to add a lot more check to this
 * to make it actually work well and handle different situations well
 */

uint8_t *find_rsdp(uint8_t* start, const uint8_t *end) {
    struct rsdp_descriptor_2 *rsdp;

    for(; start < end; start += 16){
	rsdp = (struct rsdp_descriptor_2*) start;
	
	if(strn_cmp(rsdp->version_one.signature, "RSD PTR ", 8)) {
	    set_cursor(cords_to_pos(0, 4));
	    print_str("RSD PTR FOUND?\n", 0x0f);
	    print_strn(rsdp->version_one.signature, 0x0f, 8);
	    return start;
	}
    }
    return 0;
}
