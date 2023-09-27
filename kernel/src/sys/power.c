//
// Project Name: rvxOS
// Filename: power.c
// Creator: Yaokai Liu
// Create Date: 2023-09-26
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sys/power.h>
#include <kernel/uart.h>
#include <stdint.h>

static uint32_t * const SYS_CON_ADDR = (uint32_t *)0x100000;

void poweroff(void) {
    uart_write_line("Poweroff requested.");
    *SYS_CON_ADDR = 0x5555;
}

void reboot(void) {
    uart_write_line("Reboot requested.");
    *SYS_CON_ADDR = 0x7777;
}