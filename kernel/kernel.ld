
OUTPUT_FORMAT("elf64-littleriscv")
OUTPUT_ARCH("riscv")
ENTRY(_start)

SECTIONS
{
	. = 0x080000000;
	PROVIDE(_mem_start = . );
	.text BLOCK(4K): ALIGN(4K) {
		PROVIDE(_text_start = . );
		*(.init)
		*(.text)
		*(.fini)
		PROVIDE(_text_end = . );
	}

	.rodata BLOCK(4K): ALIGN(4K) {
		PROVIDE(_rodata_start = . );
		*(.rodata)
		PROVIDE(_rodata_end = . );
	}

	.data BLOCK(4K): ALIGN(4K) {
		PROVIDE(_data_start = . );
		*(.data)
		PROVIDE(_data_end = . );
	}

	.bss BLOCK(4K): ALIGN(4K) {
		PROVIDE(_bss_start = . );
		*(COMMON)
		*(.bss)
		PROVIDE(_mscratch = .);
		. += 4K;
		. = ALIGN(0x1000);
		PROVIDE( _global_pointer = . );
		PROVIDE(_bss_end = . );
	}

	PROVIDE(_heap_start = _bss_end);
	PROVIDE(_stack_top = _heap_start + 4K);
}
