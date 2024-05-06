
.section	.init

	.option	norvc
	.type   _start, @function
	.global _start

	.cfi_startproc

	# init registers
	mv	    x1,  zero
	mv	    x2,  zero
	mv	    x3,  zero
	mv	    x4,  zero
	mv	    x5,  zero
	mv	    x6,  zero
	mv	    x7,  zero
	mv	    x8,  zero
	mv	    x9,  zero
	mv		x10, zero
	mv		x11, zero
	mv		x12, zero
	mv		x13, zero
	mv		x14, zero
	mv		x15, zero
	mv		x16, zero
	mv		x18, zero
	mv		x19, zero
	mv		x20, zero
	mv		x21, zero
	mv		x22, zero
	mv		x23, zero
	mv		x24, zero
	mv		x25, zero
	mv		x26, zero
	mv		x27, zero
	mv		x28, zero
	mv		x29, zero
	mv		x30, zero
	mv		x31, zero

_start:
	# trap init
	la      t0, __mscratch_base
	csrw    mscratch, t0
	la      t0, __m_trap_handle
	csrw	mtvec, t0

    # set MPP = M-Mode, and enable MPIE
	li      t0, (3 << 11 | 1 << 7)
	csrr    a1, mstatus
	or      t0, t0, a1
	csrw    mstatus, t0
	csrr    t1, mstatus



    # set the global_pointer
    .option push
    .option norelax
    la      gp, _global_pointer
    .option pop

     # Disable mem page.
     csrw    satp, zero

	# setup stack
	la	    sp, _stack_top

	# jump crt init
	jal	    ra, __crt_init

    wfi
	.cfi_endproc

.section	.fini

.end
