//
// Project Name: rvxOS
// Filename: minfo.h
// Creator: Yaokai Liu
// Create Date: 2023-09-30
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <csrrw.h>

#define __csrr(_csr) \
inline long m_read_##_csr(void) {                   \
    register long t0 __asm ("t0");                  \
    __asm volatile ("csrr  t0, "#_csr : "+r" (t0));  \
    return t0;                                      \
}

__csrr(misa)
__csrr(mvendorid)
__csrr(marchid)
__csrr(mimpid)

__csrr(mhartid)

__csrr(mstatus)
__csrr(mstatush)

__csrr(mtvec)
__csrr(mtval)

__csrr(medeleg)
__csrr(mideleg)

__csrr(mie)
__csrr(mip)

__csrr(mepc)
__csrr(mcause)
__csrr(mscratch)





#define __csrw(_csr) \
inline long m_write_##_csr(void) {                          \
    register long t0 __asm ("t0");                      \
    __asm volatile ("csrw  "#_csr ", t0" : "+r" (t0));  \
    return t0;                                          \
}

__csrw(mstatus)
__csrw(mstatush)

__csrw(medeleg)
__csrw(mideleg)

__csrw(mscratch)

