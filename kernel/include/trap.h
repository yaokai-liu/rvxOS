//
// Project Name: rvxOS
// Filename: trap.h
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#ifndef RVXOS_TRAP_PROCESS_H
#define RVXOS_TRAP_PROCESS_H

#include <sbi.h>

#define __m_return  __asm__ volatile ("mret")
#define __m_align   __attribute ((aligned (4)))

extern void * TRAP_HANDLE_VECTORS[];

__m_align void __m_trap_handle();
__m_align void exception_process(unsigned long _mcause);
__m_align void interrupt_process(unsigned long _mcause);


#endif //RVXOS_TRAP_PROCESS_H

