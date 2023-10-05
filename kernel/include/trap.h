//
// Project Name: rvxOS
// Filename: trap.h
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#ifndef RVXOS_TRAP_PROCESS_H
#define RVXOS_TRAP_PROCESS_H

#define __m_return  __asm volatile ("mret")
#define __m_align   __attribute ((aligned (4)))
#define __m_no_return   __attribute ((noreturn))

__m_align unsigned long trap_handler(unsigned long _mepc, long _mcause);
__m_align unsigned long exception_process(unsigned long _mepc, long _mcause);
__m_align void interrupt_process(unsigned long _mcause);


#endif //RVXOS_TRAP_PROCESS_H
