#include <sys/power.h>
#include <kernel/uart.h>
#include <common/kio.h>
#define kernel_main _main

void kernel_main(void) {
	uart_initialize();
    kprintf("Hello, %s world!\n", "RISC-V");
    kprintf("Hello, %c-Mode!\n", 'M');
    poweroff();
}

