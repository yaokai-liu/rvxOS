//
// Project Name: rvxOS
// Filename: minfo.h
// Creator: Yaokai Liu
// Create Date: 2023-09-30
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <kernel/csrr.h>

#define __csrr(_csr) \
inline long m_read_##_csr(void) {   \
    register long a0 __asm ("a0");  \
    __asm volatile (                \
        "csrr  a0, "#_csr           \
        :"+r" (a0));                \
    return a0;                      \
}


__csrr(misa)
__csrr(mvendorid)
__csrr(marchid)
__csrr(mimpid)

__csrr(mhartid)

__csrr(mstatus)
__csrr(mstatush)

__csrr(mtvec)

__csrr(medeleg)
__csrr(mideleg)

__csrr(mie)
__csrr(mip)

