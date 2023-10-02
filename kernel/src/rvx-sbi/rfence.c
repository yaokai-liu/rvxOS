//
// Project Name: rvxOS
// Filename: rfence.c
// Creator: Yaokai Liu
// Create Date: 2023-10-01
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_remote_fence_i(unsigned long hart_mask, unsigned long hart_mask_base) {
    return sbi_ecall(hart_mask, hart_mask_base, 0, 0, 0, 0,
                     SBI_RFENCE_REMOTE_FENCE_I, SBI_EXT_RFENCE);
}

struct sbiret sbi_remote_sfence_vma(unsigned long hart_mask, unsigned long hart_mask_base,
                                    unsigned long start_addr, unsigned long size)
{
    return sbi_ecall(hart_mask, hart_mask_base, start_addr, size, 0, 0,
                     SBI_RFENCE_REMOTE_SFENCE_VMA, SBI_EXT_RFENCE);
}

struct sbiret sbi_remote_sfence_vma_asid(unsigned long hart_mask, unsigned long hart_mask_base,
                                         unsigned long start_addr, unsigned long size,
                                         unsigned long asid)
{
    return sbi_ecall(hart_mask, hart_mask_base, start_addr, size, asid, 0,
                     SBI_RFENCE_REMOTE_SFENCE_VMA_ASID, SBI_EXT_RFENCE);
}

struct sbiret sbi_remote_hfence_gvma_vmid(unsigned long hart_mask, unsigned long hart_mask_base,
                                         unsigned long start_addr, unsigned long size,
                                         unsigned long vmid)
{
    return sbi_ecall(hart_mask, hart_mask_base, start_addr, size, vmid, 0,
                     SBI_RFENCE_REMOTE_HFENCE_GVMA_VMID, SBI_EXT_RFENCE);
}

struct sbiret sbi_remote_hfence_gvma(unsigned long hart_mask, unsigned long hart_mask_base,
                                     unsigned long start_addr, unsigned long size)
{
    return sbi_ecall(hart_mask, hart_mask_base, start_addr, size, 0, 0,
                     SBI_RFENCE_REMOTE_HFENCE_GVMA, SBI_EXT_RFENCE);
}

struct sbiret sbi_remote_hfence_vvma_amid(unsigned long hart_mask, unsigned long hart_mask_base,
                                         unsigned long start_addr, unsigned long size,
                                         unsigned long amid)
{
    return sbi_ecall(hart_mask, hart_mask_base, start_addr, size, amid, 0,
                     SBI_RFENCE_REMOTE_HFENCE_VVMA_ASID, SBI_EXT_RFENCE);
}

struct sbiret sbi_remote_hfence_vvma(unsigned long hart_mask, unsigned long hart_mask_base,
                                     unsigned long start_addr, unsigned long size)
{
    return sbi_ecall(hart_mask, hart_mask_base, start_addr, size, 0, 0,
                     SBI_RFENCE_REMOTE_HFENCE_VVMA, SBI_EXT_RFENCE);
}

