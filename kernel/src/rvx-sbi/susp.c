//
// Project Name: rvxOS
// Filename: susp.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_system_suspend(uint32_t sleep_type,
        unsigned long resume_addr, unsigned long opaque)
{
    return sbi_ecall(sleep_type, resume_addr, opaque, 0, 0, 0,
                     SBI_SUSP_SYSTEM_SUSPEND, SBI_EXT_SUSP);
}
