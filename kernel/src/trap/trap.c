//
// Project Name: rvxOS
// Filename: trap.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//
#include <trap.h>
#include <xdef.h>
#include <uart.h>
#include <sys/power.h>
#include <stdint.h>
#include <firmware/SEE.h>

#define __IO_AR_D(__io, __dest)  do {            \
    __asm__ volatile (__io"  x0, 0x00("__dest")"); \
    __asm__ volatile (__io"  ra, 0x08("__dest")"); \
    __asm__ volatile (__io"  sp, 0x10("__dest")"); \
    __asm__ volatile (__io"  gp, 0x18("__dest")"); \
    __asm__ volatile (__io"  tp, 0x20("__dest")"); \
    __asm__ volatile (__io"  s0, 0x28("__dest")"); \
    __asm__ volatile (__io"  s1, 0x30("__dest")"); \
    __asm__ volatile (__io"  s2, 0x38("__dest")"); \
    __asm__ volatile (__io"  s3, 0x40("__dest")"); \
    __asm__ volatile (__io"  s4, 0x48("__dest")"); \
    __asm__ volatile (__io"  s5, 0x50("__dest")"); \
    __asm__ volatile (__io"  s6, 0x58("__dest")"); \
    __asm__ volatile (__io"  s7, 0x60("__dest")"); \
    __asm__ volatile (__io"  s8, 0x68("__dest")"); \
    __asm__ volatile (__io"  s9, 0x70("__dest")"); \
    __asm__ volatile (__io" s10, 0x78("__dest")"); \
    __asm__ volatile (__io" s11, 0x80("__dest")"); \
    __asm__ volatile (__io"  a0, 0x88("__dest")"); \
    __asm__ volatile (__io"  a1, 0x90("__dest")"); \
    __asm__ volatile (__io"  a2, 0x98("__dest")"); \
    __asm__ volatile (__io"  a3, 0xa0("__dest")"); \
    __asm__ volatile (__io"  a4, 0xa8("__dest")"); \
    __asm__ volatile (__io"  a5, 0xb0("__dest")"); \
    __asm__ volatile (__io"  a6, 0xb8("__dest")"); \
    __asm__ volatile (__io"  a7, 0xc0("__dest")"); \
    __asm__ volatile (__io"  t0, 0xc8("__dest")"); \
    __asm__ volatile (__io"  t1, 0xd0("__dest")"); \
    __asm__ volatile (__io"  t2, 0xd8("__dest")"); \
    __asm__ volatile (__io"  t3, 0xe0("__dest")"); \
    __asm__ volatile (__io"  t4, 0xe8("__dest")"); \
    __asm__ volatile (__io"  t5, 0xf0("__dest")"); \
    __asm__ volatile (__io"  t6, 0xf8("__dest")"); \
} while (false)

#define LARD(_dest)  __IO_AR_D("ld", _dest)
#define SARD(_dest)  __IO_AR_D("sd", _dest)


typedef enum {
    inst_addr_misaligned = 0,
    inst_access_fault = 1,
    illegal_inst = 2,
    breakpoint = 3,
    load_addr_misaligned = 4,
    load_access_fault = 5,
    samo_addr_misaligned = 6,
    samo_access_fault = 7,
    env_call_from_user = 8,
    env_call_from_super = 9,
    env_call_from_machine = 11,
    inst_page_fault = 12,
    load_page_fault = 13,
    samo_page_fault = 15,
} e_type;
static const char * EXCEPTIONS[] = {
        [inst_addr_misaligned]  = "Instruction address misaligned",
        [inst_access_fault]     = "Instruction access fault",
        [illegal_inst]          = "Illegal instruction",
        [breakpoint]            = "Breakpoint",
        [load_addr_misaligned]  = "Load address misaligned",
        [load_access_fault]     = "Load access fault",
        [samo_addr_misaligned]  = "Store/AMO address misaligned",
        [samo_access_fault]     = "Store/AMO access fault",
        [env_call_from_user]    = "Environment call from U-mode",
        [env_call_from_super]   = "Environment call from S-mode",
        [10] = NULL,
        [env_call_from_machine] = "Environment call from M-mode",
        [inst_page_fault]       = "Instruction page fault",
        [load_page_fault]       = "Load page fault",
        [14] = NULL,
        [samo_page_fault]       = "Store/AMO page fault",

        // reserved
        [16 ... 23] = NULL,
        // designated for custom use
        [24 ... 31] = NULL,
        //reserved
        [32 ... 47] = NULL,
        // designated for custom use
        [48 ... 63] = NULL,

        // >=64 reserved
};

typedef enum {
    soft_int_from_super = 1,
    soft_int_from_user = 3,
    timer_from_super = 5,
    timer_from_machine = 7,
    ext_int_from_super = 9,
    ext_int_from_machine = 11,
} i_type;
static const char * INTERRUPTS[] = {
        [0] = NULL,
        [soft_int_from_super] = "Supervisor software interrupt",
        [2] = NULL,
        [soft_int_from_user] = "Machine software interrupt",
        [4] = NULL,
        [timer_from_super] = "Supervisor timer interrupt",
        [6] = NULL,
        [timer_from_machine] = "Machine timer interrupt",
        [8] = NULL,
        [ext_int_from_super] = "Supervisor external interrupt",
        [10] = NULL,
        [ext_int_from_machine] = "Machine external interrupt",

        [12 ... 15] = NULL,

        // >=16 designated for platform use
};


__m_align void __m_trap_handle() {
    __asm__ volatile ("csrrw  a0, mcause, a0");
    __asm__ volatile ("csrrw  ra, mepc, ra");
    __asm__ volatile ("bltz   a0, interrupt_process");
    __asm__ volatile ("jal    ra, exception_process");

    __builtin_unreachable();
}


__m_align void exception_process(unsigned long _mcause) {
    __asm__ volatile ("csrrw  fp, mscratch, fp");
    SARD("fp");
    switch (_mcause) {
        // TODO:
        case env_call_from_user:
        case env_call_from_super:
        case env_call_from_machine: {
            __asm__ volatile ("csrrw  a0, mcause, a0");
            __asm__ volatile ("csrrw  ra, mepc, ra");

            __asm__ volatile ("addi   sp, sp, -16");
            __asm__ volatile ("sd     ra, 8(sp)");

            __asm__ volatile ("call   sbi_execute");
            __asm__ volatile ("csrrw  a0, mepc, a0");
            __asm__ volatile ("addi   a0, a0, 4");
            __asm__ volatile ("csrrw  a0, mepc, a0");

            __asm__ volatile ("ld     ra, 8(sp)");
            __asm__ volatile ("addi   sp, sp, 16");
            __asm__ volatile ("mret");
        }
    }
    if (_mcause >= lenof(EXCEPTIONS) || !EXCEPTIONS[_mcause]) {
        uart_write_line("Unknown exception");
    } else {
        uart_write_line(EXCEPTIONS[_mcause]);
    }
    poweroff();
    __builtin_unreachable();
}

__m_align void interrupt_process(unsigned long _mcause) {
    _mcause = (_mcause << 1) >> 1;
    if (_mcause >= lenof(INTERRUPTS) || !INTERRUPTS[_mcause]) {
        uart_write_line("Unknown interrupt");
        __asm__ volatile ("mret");
        __builtin_unreachable();
    }
    uart_write_line(INTERRUPTS[_mcause]);
    switch (_mcause) {
        // TODO:
        default: {
            poweroff();
        }
    }
    LARD("s2");
    __asm__ volatile ("csrrw  s2, mscratch, s2");
    __asm__ volatile ("mret");
    __builtin_unreachable();
}

