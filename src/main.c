#include "includes/typedefs.h"
#include "includes/textmode.h"


void kernel_main() {
    set_cursor(0); //set the cursor to position zero.
    print_str("Hello world from an elf kernel written in C", 0x1f);
}
