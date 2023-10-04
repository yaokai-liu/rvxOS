//
// Project Name: rvxOS
// Filename: cppc.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_cppc_probe(uint32_t cppc_reg_id) {
    return sbi_ecall(cppc_reg_id, 0, 0, 0, 0, 0,
                     SBI_CPPC_PROBE, SBI_EXT_CPPC);
}

struct sbiret sbi_cppc_read(uint32_t cppc_reg_id) {
    return sbi_ecall(cppc_reg_id, 0, 0, 0, 0, 0,
                     SBI_CPPC_READ, SBI_EXT_CPPC);
}

struct sbiret sbi_cppc_read_hi(uint32_t cppc_reg_id) {
    return sbi_ecall(cppc_reg_id, 0, 0, 0, 0, 0,
                     SBI_CPPC_READ_HI, SBI_EXT_CPPC);
}

struct sbiret sbi_cppc_write(uint32_t cppc_reg_id, uint64_t val) {
    return sbi_ecall(cppc_reg_id, val, 0, 0, 0, 0,
                     SBI_CPPC_WRITE, SBI_EXT_CPPC);
}

