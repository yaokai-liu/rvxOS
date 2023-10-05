//
// Project Name: rvxOS
// Filename: trap.S
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

// store all registers to _dest
.macro  sar _dest
    sd  ra, 0x00(\_dest)
	sd  sp, 0x08(\_dest)
	sd  gp, 0x10(\_dest)
	sd  tp, 0x18(\_dest)
	sd  t0, 0x20(\_dest)
	sd  t1, 0x28(\_dest)
	sd  t2, 0x30(\_dest)
	sd  s0, 0x38(\_dest)
	sd  s1, 0x40(\_dest)
	sd  a0, 0x48(\_dest)
	sd  a1, 0x50(\_dest)
	sd  a2, 0x58(\_dest)
	sd  a3, 0x60(\_dest)
	sd  a4, 0x68(\_dest)
	sd  a5, 0x70(\_dest)
	sd  a6, 0x78(\_dest)
	sd  a7, 0x80(\_dest)
	sd  s2, 0x88(\_dest)
	sd  s3, 0x90(\_dest)
	sd  s4, 0x98(\_dest)
	sd  s5, 0xa0(\_dest)
	sd  s6, 0xa8(\_dest)
	sd  s7, 0xb0(\_dest)
	sd  s8, 0xb8(\_dest)
	sd  s9, 0xc0(\_dest)
	sd s10, 0xc8(\_dest)
	sd s11, 0xd0(\_dest)
	sd  t3, 0xd8(\_dest)
	sd  t4, 0xe0(\_dest)
	sd  t5, 0xe0(\_dest)
	sd  t6, 0xf0(\_dest)
.endm

// load all registers from _dest
.macro  lar _dest
    ld  ra, 0x00(\_dest)
	ld  sp, 0x08(\_dest)
	ld  gp, 0x10(\_dest)
	ld  tp, 0x18(\_dest)
	ld  t0, 0x20(\_dest)
	ld  t1, 0x28(\_dest)
	ld  t2, 0x30(\_dest)
	ld  s0, 0x38(\_dest)
	ld  s1, 0x40(\_dest)
	ld  a0, 0x48(\_dest)
	ld  a1, 0x50(\_dest)
	ld  a2, 0x58(\_dest)
	ld  a3, 0x60(\_dest)
	ld  a4, 0x68(\_dest)
	ld  a5, 0x70(\_dest)
	ld  a6, 0x78(\_dest)
	ld  a7, 0x80(\_dest)
	ld  s2, 0x88(\_dest)
	ld  s3, 0x90(\_dest)
	ld  s4, 0x98(\_dest)
	ld  s5, 0xa0(\_dest)
	ld  s6, 0xa8(\_dest)
	ld  s7, 0xb0(\_dest)
	ld  s8, 0xb8(\_dest)
	ld  s9, 0xc0(\_dest)
	ld s10, 0xc8(\_dest)
	ld s11, 0xd0(\_dest)
	ld  t3, 0xd8(\_dest)
	ld  t4, 0xe0(\_dest)
	ld  t5, 0xe0(\_dest)
	ld  t6, 0xf0(\_dest)
.endm


.section    .text
    .type   _mtvec_, @function
    .global _mtvec_
_mtvec_:

before_process:
    csrr    t6, mscratch
    sar     t6
    csrw    mscratch, t6

real_handle:
    csrr    a0, mepc
    csrr    a1, mcause
    call    trap_handler
    csrw    mepc, a0

after_process:
    csrr    t6, mscratch
    lar     t6
    mret
