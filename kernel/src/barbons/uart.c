
#include <stddef.h>
#include <stdint.h>
#include <uart.h>

static unsigned char * const UART_ADDR = (unsigned char *)0x10000000;

void uart_initialize(void) {
    volatile uint8_t *ptr = (uint8_t *)UART_ADDR;

    // set word length to 8 (LCR[1:0])
    const uint8_t LCR = 0b11;
    ptr[3] = LCR;

    // enable FIFO (FCR[0])
    ptr[2] = 0b1;

    // enable receiver buffer interrupts(IER[0])
    ptr[1] = 0b1;

    // an emulator not need to do this
    // uint16_t divisor = 592;
    // uint8_t divisor_least = divisor & 0xff;
    // uint8_t divisor_most = divisor >> 8;
    // ptr[3] = LCR | 0x80;
    // ptr[0] = divisor_least;
    // ptr[1] = divisor_most;
    // ptr[3] = LCR;
}

void uart_putchar(char c) {
    *UART_ADDR = c;
}

void uart_write(const char* data, size_t size) {
    while(size > 0) {
        uart_putchar(*data);
        data++; size --;
    }
    return;
}

void uart_write_string(const char* data) {
    while(*data != '\0') {
        uart_putchar(*data);
        data++;
    }
    return;
}

void uart_write_line(const char * data) {
    uart_write_string(data);
    uart_putchar('\n');
}