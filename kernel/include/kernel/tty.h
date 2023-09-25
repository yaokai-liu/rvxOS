
#ifndef _KERNEL_TTY_H_
#define _KERNEL_TTY_H_

#include <stddef.h>

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_write_string(const char* data);

#endif // _KERNEL_TTY_H_

