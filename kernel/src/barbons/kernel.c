#include <sys/power.h>
#include <kernel/uart.h>
#include <common/kio.h>
#define kernel_main _main
#define read_misa   _read_misa

long read_misa();

void kernel_main(void) {
	uart_initialize();
    kprintf("Hello, %s world!\n", "RISC-V");
    kprintf("Hello, %c-Mode!\n", 'M');
    long misa = read_misa();
    kprintf("MISA = 0x%X\n", misa);
    poweroff();
}

