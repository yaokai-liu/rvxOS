
#ifndef _KERNEL_TTY_H_
#define _KERNEL_TTY_H_

#include <stddef.h>

void uart_initialize(void);
void uart_putchar(char c);
void uart_write(const char* data, size_t size);
void uart_write_string(const char* data);
void uart_write_line(const char * data);

#endif // _KERNEL_TTY_H_

