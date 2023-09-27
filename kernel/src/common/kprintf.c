//
// Project Name: rvxOS
// Filename: kprintf.c
// Creator: Yaokai Liu
// Create Date: 2023-09-25
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <kernel/uart.h>
#include <common/charize.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

void kvprintf(const char * _format, va_list _arg);

void kprintf(const char * _format, ...) {
    va_list arg;
    va_start(arg, _format);
    kvprintf(_format, arg);
    va_end(arg);
}

void kvprintf(const char * _format, va_list _arg) {
    while(*_format) {
        if (*_format == '%') {
            ++ _format;
            if (!*_format) {
                uart_putchar('%');
                return;
            }
            switch (*_format) {
                case 'd':
                case 'i': {
                    int n = va_arg(_arg, int);
                    if (n == -2147483648) {
                        uart_write_string("-2147483648");
                        break;
                    }
                    if (n < 0) {
                        uart_putchar('-');
                        n = ~n + 1;
                    }
                    char buf[10]; // 32 bits int will not more than pow(10, 10).
                    int i = 0;
                    for (; n > 0; i++, n /= 10) {
                        buf[i] = '0' + n % 10;
                    }
                    for (; i > 0; i--) {
                        uart_putchar(buf[i]);
                    }
                    break;
                }
                case 'u': {
                    unsigned int n = va_arg(_arg, unsigned int);
                    char buf[10]; // 32 bits unsigned int will not more than pow(10, 10).
                    int i = 0;
                    for (; n > 0; i++, n /= 10) {
                        buf[i] = '0' + n % 10;
                    }
                    for (; i > 0; i--) {
                        uart_putchar(buf[i]);
                    }
                    break;
                }
                case 'o': {
                    unsigned int n = va_arg(_arg, unsigned int);
                    char buf[11]; // 32 bits int will not more than pow(10, 10).
                    int i = 0;
                    for (; n > 0; i++, n /= 8) {
                        buf[i] = '0' + n % 8;
                    }
                    for (; i > 0; i--) {
                        uart_putchar(buf[i]);
                    }
                    break;
                }
                case 'x': {
                    unsigned int n = va_arg(_arg, unsigned int);
                    char buf[8]; // 32 bits int will not more than pow(10, 10).
                    int i = 0;
                    for (; n > 0; i++, n /= 16) {
                        buf[i] = hex_digit(n % 16);
                    }
                    for (; i > 0; i--) {
                        uart_putchar(buf[i]);
                    }
                    break;
                }
                case 'X': {
                    unsigned int n = va_arg(_arg, unsigned int);
                    char buf[8]; // 32 bits int will not more than pow(10, 10).
                    int i = 0;
                    for (; n > 0; i++, n /= 16) {
                        buf[i] = hex_digit(n % 16);
                    }
                    for (; i > 0; i--) {
                        char c = upper_c(buf[i]);
                        uart_putchar(c);
                    }
                    break;
                }
                case 'c': {
                    uart_putchar(va_arg(_arg, int) % 256);
                    break;
                }
                case 's': {
                    uart_write_string(va_arg(_arg, char *));
                    break;
                }
                case 'p': {
                    size_t ptr = va_arg(_arg, size_t);
                    char buf[8]; // 32 bits int will not more than pow(10, 10).
                    int i = 0;
                    for (; ptr > 0; i++, ptr /= 16) {
                        buf[i] = hex_digit(ptr % 16);
                    }
                    for (; i > 0; i--) {
                        char c = upper_c(buf[i]);
                        uart_putchar(c);
                    }
                    break;
                }
                case '%': {
                    uart_putchar('%');
                    break;
                }
                default: {
                    uart_putchar('%');
                    uart_putchar(*_format);
                }
            }
        } else {
            uart_putchar(*_format);
        }
        ++ _format;
    }
}


