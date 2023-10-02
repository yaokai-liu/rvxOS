//
// Project Name: rvxOS
// Filename: hsm.c
// Creator: Yaokai Liu
// Create Date: 2023-10-01
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_hart_start(unsigned long hartid, unsigned long start_addr, unsigned long opaque) {
    return sbi_ecall(hartid, start_addr, opaque, 0, 0, 0,
                     SBI_HSM_HART_START, SBI_EXT_HSM);
}

struct sbiret sbi_hart_stop(void) {
    return sbi_ecall(0, 0, 0, 0, 0, 0,
                     SBI_HSM_HART_STOP, SBI_EXT_HSM);
}

struct sbiret sbi_hart_get_status(unsigned long hartid) {
    return sbi_ecall(hartid, 0, 0, 0, 0, 0,
                     SBI_HSM_HART_GET_STATUS, SBI_EXT_HSM);
}

struct sbiret sbi_hart_suspend(uint32_t suspend_type, unsigned long resume_addr, unsigned long opaque) {
    return sbi_ecall(suspend_type, resume_addr, opaque, 0, 0, 0,
                     SBI_HSM_HART_SUSPEND, SBI_EXT_HSM);
}

