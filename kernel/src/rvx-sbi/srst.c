//
// Project Name: rvxOS
// Filename: srst.c
// Creator: Yaokai Liu
// Create Date: 2023-10-02
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <kernel/sbi.h>

struct sbiret sbi_system_reset(uint32_t reset_type, uint32_t reset_reason) {
    return sbi_ecall(reset_type, reset_reason, 0, 0, 0, 0,
                     SBI_SRST_SYSTEM_RESET, SBI_EXT_SRST);
}

