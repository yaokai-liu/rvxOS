#include <sys/power.h>
#include <uart.h>
#include <common/kio.h>
#include <csrrw.h>
#include <sbi.h>
#define kernel_main _main

static const char * PLATFORM_NAME   = "RISC-V";
static const int PLATFORM_XLEN      = 64;

void kernel_main(void) {
	uart_initialize();
    long misa = m_read_misa();
    kprintf("System Platform: %s %d-bit\n", PLATFORM_NAME, PLATFORM_XLEN);
    kprintf("Supported ISA Extensions: \n\t");
    for (int i = 0; i < 26; i ++) {
        if ((1 << i) & misa) {
            kprintf("%c", i + 'A');
        }
    }
    uart_putchar('\n');

    kprintf("Hello, %c-Mode!\n", 'M');
    struct sbiret r = sbi_probe_extension(10086);
    if (r.error == SBI_SUCCESS) {
        kprintf("SBI Implication ID: %c%c%c\n",
                (r.value >> 16) % 256,
                (r.value >> 8) % 256,
                r.value % 256);
    } else {
        kprintf("Unsupported SBI Implementation: %d.", r.value);
    }
    poweroff();
}

