//
// Project Name: rvxOS
// Filename: dbcn.c
// Creator: Yaokai Liu
// Create Date: 2023-10-02
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_debug_console_write( unsigned long num_bytes,
        unsigned long base_addr_lo, unsigned long base_addr_hi)
{
    return sbi_ecall(num_bytes, base_addr_lo, base_addr_hi, 0 ,0 ,0,
                     SBI_DBCN_WRITE, SBI_EXT_DBCN);
}

struct sbiret sbi_debug_console_read( unsigned long num_bytes,
        unsigned long base_addr_lo, unsigned long base_addr_hi)
{
    return sbi_ecall(num_bytes, base_addr_lo, base_addr_hi, 0 ,0 ,0,
                     SBI_DBCN_READ, SBI_EXT_DBCN);
}

struct sbiret sbi_debug_console_write_byte(uint8_t byte) {
    return sbi_ecall(byte, 0, 0, 0, 0, 0,
                     SBI_DBCN_WRITE_BYTE, SBI_EXT_DBCN);
}
