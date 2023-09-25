
#include <kernel/tty.h>

static unsigned char * const uart = (unsigned char *)0x10000000;

void terminal_initialize(void) {

}

void terminal_putchar(char c) {
    *uart = c;
    return;
}

void terminal_write(const char* data, size_t size) {
    while(size > 0) {
        terminal_putchar(*data);
        data++; size --;
    }
    return;
}

void terminal_write_string(const char* data) {
    while(*data != '\0') {
        terminal_putchar(*data);
        data++;
    }
    return;
}
