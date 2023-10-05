//
// Project Name: rvxOS
// Filename: trap.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//
#include <trap.h>
#include <sys/power.h>
#include <csrrw.h>
#include <xdef.h>
#include <uart.h>
#include <firmware/SEE.h>

static const char * EXCEPTIONS[] = {
        [0] = "Instruction address misaligned",
        [1] = "Instruction access fault",
        [2] = "Illegal instruction",
        [3] = "Breakpoint",
        [4] = "Load address misaligned",
        [5] = "Load access fault",
        [6] = "Store/AMO address misaligned",
        [7] = "Store/AMO access fault",
        [8] = "Environment call from U-mode",
        [9] = "Environment call from S-mode",
        [10] = NULL,
        [11] = "Environment call from M-mode",
        [12] = "Instruction page fault",
        [13] = "Load page fault",
        [14] = NULL,
        [15] = "Store/AMO page fault",

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

static const char * INTERRUPTS[] = {
        [0] = NULL,
        [1] = "Supervisor software interrupt",
        [2] = NULL,
        [3] = "Machine software interrupt",
        [4] = NULL,
        [5] = "Supervisor timer interrupt",
        [6] = NULL,
        [7] = "Machine timer interrupt",
        [8] = NULL,
        [9] = "Supervisor external interrupt",
        [10] = NULL,
        [11] = "Machine external interrupt",
        [12 ... 15] = NULL,

        // >=16 designated for platform use
};


__m_align unsigned long trap_handler(unsigned long _mepc, long _mcause) {
    if (_mcause < 0) {
        interrupt_process((_mcause << 1) >> 1);
    } else {
        _mepc = exception_process(_mepc, _mcause);
    }
    return _mepc;
}


__m_align unsigned long exception_process(unsigned long _mepc, long _mcause) {
    if (_mcause >= lenof(EXCEPTIONS) || !EXCEPTIONS[_mcause]) {
        uart_write_line("Unknown exception");
        // TODO:
        return _mepc;
    }
    uart_write_line(EXCEPTIONS[_mcause]);
    switch (_mcause) {
        // TODO:
    }
    if (_mcause >= 8 && _mcause <= 11) {
        _mepc += 4;
    }
    return _mepc;
}

__m_align void interrupt_process(unsigned long _mcause) {
    if (_mcause >= lenof(INTERRUPTS) || !INTERRUPTS[_mcause]) {
        uart_write_line("Unknown interrupt");
        return;
    }
    uart_write_line(INTERRUPTS[_mcause]);
    // TODO:
}
