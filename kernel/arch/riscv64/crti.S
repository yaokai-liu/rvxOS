
.section	.init
	.option norvc
	.type   __crt_init, @function
	.global	__crt_init

__crt_init:
	.cfi_startproc
	addi    sp, sp, -8
	sd      ra, 0(sp)
	# init the BSS section
	la	    t5, _bss_start
	la	    t6, _bss_end
bss_init:
	sd	    zero, 0(t5)
	addi	t5, t5, 8
	bleu	t5, t6, bss_init

__main_entry:
	# set exception address
	la	    t0, _main
	csrw	mepc, t0

	# jump to function
	jal     ra, _main
_break:
	ld      ra, 0(sp)
	addi    sp, sp, 8
	ret
	.cfi_endproc

.section	.fini
.end
