//
// Project Name: rvxOS
// Filename: ipi.c
// Creator: Yaokai Liu
// Create Date: 2023-10-01
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <kernel/sbi.h>

struct sbiret sbi_send_ipi(unsigned long hart_mask, unsigned long hart_mask_base) {
    return sbi_ecall(hart_mask, hart_mask_base, 0, 0, 0, 0,
                     SBI_IPI_SEND_IPI, SBI_EXT_IPI);
}