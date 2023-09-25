
#include <kernel/tty.h>
#define kernel_main _main

void kernel_main(void) {
	terminal_initialize();
    terminal_write_string("Hello, world!\n\0");
}

