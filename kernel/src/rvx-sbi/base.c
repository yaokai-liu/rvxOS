//
// Project Name: rvxOS
// Filename: sbi.S
// Creator: Yaokai Liu
// Create Date: 2023-09-30
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

// Base Extension
// EID: 0x10
inline struct sbiret __sbi_base_ecall(int fid) {
    return sbi_ecall(0, 0, 0, 0, 0, 0, fid, SBI_EXT_BASE);
}

struct sbiret sbi_get_spec_version(void) {
    return __sbi_base_ecall(SBI_BASE_GET_SPEC_VERSION);
}

struct sbiret sbi_get_impl_id(void) {
    return __sbi_base_ecall(SBI_BASE_GET_IMP_ID);
}

struct sbiret sbi_get_impl_version(void) {
    return __sbi_base_ecall(SBI_BASE_GET_IMP_VERSION);
}

struct sbiret sbi_probe_extension(long extension_id) {
    return sbi_ecall(extension_id, 0, 0, 0, 0, 0,
                     SBI_BASE_PROBE_EXT, SBI_EXT_BASE);
}

struct sbiret sbi_get_mvendorid(void) {
    return __sbi_base_ecall(SBI_BASE_GET_MVENDORID);
}

struct sbiret sbi_get_marchid(void) {
    return __sbi_base_ecall(SBI_BASE_GET_MARCHID);
}

struct sbiret sbi_get_mimpid(void) {
    return __sbi_base_ecall(SBI_BASE_GET_MIMPID);
}


