include ../make.config

KERNEL_ROOT = $(PROJECT_ROOT)/kernel
KERNEL_SRC_DIR = $(KERNEL_ROOT)/src
BARBONS_DIR = $(KERNEL_SRC_DIR)/barbons
ARCH_DIR = $(KERNEL_SRC_DIR)/arch/$(TARGET_PLATFORM)
COMMON_DIR = $(KERNEL_SRC_DIR)/common
CSRR_DIR = $(KERNEL_SRC_DIR)/csrr
SYS_DIR = $(KERNEL_SRC_DIR)/sys
SBI_DIR = $(KERNEL_SRC_DIR)/rvx-sbi
SEE_DIR = $(KERNEL_SRC_DIR)/rvx-see
TRAP_DIR = $(KERNEL_SRC_DIR)/trap

KERNEL_INCLUDE_DIR = $(KERNEL_ROOT)/include
KERNEL_CCONFIG_DIR = $(KERNEL_ROOT)/cconfig


include $(KERNEL_CCONFIG_DIR)/arch/riscv64.make.config

ACFLAGS += $(KERNEL_ARCH_ACFLAGS)
CCFLAGS += $(KERNEL_ARCH_CCFLAGS)
XCFLAGS += $(KERNEL_ARCH_XCFLAGS)
LDFLAGS += $(KERNEL_ARCH_LDFLAGS)

DBINIT = gdbinit

KERNEL_ARCH_OBJS = $(ARCH_DIR)/crt1.o $(ARCH_DIR)/crti.o $(ARCH_DIR)/crtn.o

CSR_OBJS = $(CSRR_DIR)/minfo.o

KERNEL_OBJS = $(KERNEL_ARCH_OBJS) $(BARBONS_DIR)/kernel.o $(BARBONS_DIR)/uart.o

COMMON_OBJS = $(COMMON_DIR)/kprintf.o $(COMMON_DIR)/upper_c.o $(COMMON_DIR)/hex_digit.o

SYS_OBJS = $(SYS_DIR)/power.o

TRAP_OBJS = $(TRAP_DIR)/trap.o $(TRAP_DIR)/tvec.o

SBI_OBJS = $(SBI_DIR)/ecall.o $(SBI_DIR)/base.o \
		   $(SBI_DIR)/time.o $(SBI_DIR)/ipi.o \
		   $(SBI_DIR)/rfence.o $(SBI_DIR)/hsm.o \
		   $(SBI_DIR)/srst.o $(SBI_DIR)/pmu.o \
		   $(SBI_DIR)/dbcn.o $(SBI_DIR)/susp.o \
		   $(SBI_DIR)/cppc.o $(SBI_DIR)/nacl.o \
		   $(SBI_DIR)/sta.o

SEE_OBJS = $(SEE_DIR)/base.o

OBJS = $(KERNEL_OBJS) $(COMMON_OBJS)\
 	   $(CSR_OBJS) $(SYS_OBJS) \
 	   $(SBI_OBJS) $(SEE_OBJS) \
 	   $(TRAP_OBJS)

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S .x

all: rvxOS.kernel

debug: rvxOS.kernel
	$(CROSS_COMPILE)-objcopy --only-keep-debug $(COMPILE_TEMP_DIR)/$< $(COMPILE_TEMP_DIR)/os.symbol
	$(CROSS_COMPILE)-strip --strip-debug --strip-unneeded $(COMPILE_TEMP_DIR)/$<
	$(CROSS_COMPILE)-objcopy --add-gnu-debuglink=$(COMPILE_TEMP_DIR)/os.symbol $(COMPILE_TEMP_DIR)/$<
	nohup $(SYS_EMU) -nographic $(KERNEL_ARCH_EMUFLAGS) -D $(COMPILE_TEMP_DIR)/os-run.log \
		-kernel $(COMPILE_TEMP_DIR)/$< -S -s > $(COMPILE_TEMP_DIR)/nohub.out &
	$(ARCH_DB) $(COMPILE_TEMP_DIR)/$< -q -x $(DBINIT)

demu: rvxOS.kernel
	$(SYS_EMU) $(KERNEL_ARCH_EMUFLAGS) -d int -kernel $(COMPILE_TEMP_DIR)/$<

emu: rvxOS.kernel
	$(SYS_EMU) $(KERNEL_ARCH_EMUFLAGS) -serial mon:stdio -kernel $(COMPILE_TEMP_DIR)/$<

rvx-sbi: $(SBI_OBJS)
	$(ARCH_LD) --relocatable --sysroot=$(SYSROOT) $(SBI_OBJS) -o $(COMPILE_TEMP_DIR)/$@.a

rvxOS.kernel: $(OBJS) $(KERNEL_ROOT)/kernel.ld
	mkdir -p $(COMPILE_TEMP_DIR)
	$(ARCH_LD) $(LDFLAGS) $(OBJS) -o $(COMPILE_TEMP_DIR)/$@

.S.o:
	$(ARCH_AC) -MD -c $< -o $@ $(ACFLAGS)

.c.o:
	$(ARCH_CC) -MD -c $< -o $@ $(CCFLAGS)

.x.o:
	$(ARCH_XC) -MD -c $< -o $@ $(XCFLAGS)


clean:
	rm -f $(COMPILE_TEMP_DIR)/*
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS) *.a */*.a */*/*.a
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d


install: install-headers install-kernel

install-headers:
	mkdir -p $(USR_INCLUDE_DIR)
	cp -R --preserve=timestamps $(KERNEL_INCLUDE_DIR)/. $(USR_INCLUDE_DIR)/.
	cp -R --preserve=timestamps $(XDEF_DIR)/. $(USR_INCLUDE_DIR)/.

install-kernel: rvxOS.kernel
	mkdir -p $(SYS_BOOT_DIR)
	cp $(COMPILE_TEMP_DIR)/rvxOS.kernel $(SYS_BOOT_DIR)

-include $(OBJS:.o=.d)

