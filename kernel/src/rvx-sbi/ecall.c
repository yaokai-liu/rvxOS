//
// Project Name: rvxOS
// Filename: ecall.S
// Creator: Yaokai Liu
// Create Date: 2023-10-01
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <kernel/sbi.h>
#include <stdint.h>

struct sbiret sbi_ecall(unsigned long arg0, unsigned long arg1,
                        unsigned long arg2, unsigned long arg3,
                        unsigned long arg4, unsigned long arg5,
                        int fid, int eid)
{
    register uintptr_t a0 __asm ("a0") = (uintptr_t)(arg0);
    register uintptr_t a1 __asm ("a1") = (uintptr_t)(arg1);
    register uintptr_t a2 __asm ("a2") = (uintptr_t)(arg2);
    register uintptr_t a3 __asm ("a3") = (uintptr_t)(arg3);
    register uintptr_t a4 __asm ("a4") = (uintptr_t)(arg4);
    register uintptr_t a5 __asm ("a5") = (uintptr_t)(arg5);
    register uintptr_t a6 __asm ("a6") = (uintptr_t)(fid);
    register uintptr_t a7 __asm ("a7") = (uintptr_t)(eid);
    __asm volatile ("ecall"
            : "+r" (a0), "+r" (a1)
            : "r" (a2), "r" (a3), "r" (a4), "r" (a5), "r" (a6), "r" (a7)
            : "memory");
    return (struct sbiret) {a0, a1};
}