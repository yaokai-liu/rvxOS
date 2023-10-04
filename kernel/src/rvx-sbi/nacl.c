//
// Project Name: rvxOS
// Filename: nacl.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_nacl_probe_feature(uint32_t feature_id) {
    return sbi_ecall(feature_id, 0, 0, 0, 0, 0,
                     SBI_NACL_PROBE_FEATURE, SBI_EXT_NACL);
}

struct sbiret sbi_nacl_set_shmem(unsigned long shmem_phys_lo,
        unsigned long shmem_phys_hi, unsigned long flags)
{
    return sbi_ecall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
                     SBI_NACL_SET_SHMEM, SBI_EXT_NACL);
}

struct sbiret sbi_nacl_sync_csr(unsigned long csr_num) {
    return sbi_ecall(csr_num, 0, 0, 0, 0, 0,
                     SBI_NACL_SYNC_CSR, SBI_EXT_NACL);
}

struct sbiret sbi_nacl_sync_hfence(unsigned long entry_index) {
    return sbi_ecall(entry_index, 0, 0, 0, 0, 0,
                     SBI_NACL_SYNC_HFENCE, SBI_EXT_NACL);
}

struct sbiret sbi_nacl_sync_sret(void) {
    return sbi_ecall(0, 0, 0, 0, 0, 0,
                     SBI_NACL_SYNC_SRET, SBI_EXT_NACL);
}


