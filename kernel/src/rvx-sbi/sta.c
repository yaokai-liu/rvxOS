//
// Project Name: rvxOS
// Filename: sta.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_steal_time_set_shmem(unsigned long shmem_phys_lo,
        unsigned long shmem_phys_hi, unsigned long flags)
{
    return sbi_ecall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
                     SBI_STA_SHMEM, SBI_EXT_STA);
}
