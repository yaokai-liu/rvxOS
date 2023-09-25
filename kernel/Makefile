include ../make.config

KERNEL_ROOT = $(PROJECT_ROOT)/kernel
KERNEL_DIR = $(KERNEL_ROOT)/kernel
ARCH_DIR = $(KERNEL_ROOT)/arch/$(TARGET_PLATFORM)

include $(ARCH_DIR)/make.config

ACFLAGS += $(KERNEL_ARCH_ACFLAGS)
CCFLAGS += $(KERNEL_ARCH_CCFLAGS)
XCFLAGS += $(KERNEL_ARCH_XCFLAGS)
LDFLAGS += $(KERNEL_ARCH_LDFLAGS)

DBINIT = gdbinit

KERNEL_OBJS= $(KERNEL_ARCH_OBJS) $(KERNEL_DIR)/kernel.o $(ARCH_DIR)/tty.o

OBJS =  $(ARCH_DIR)/crt1.o \
	$(ARCH_DIR)/crti.o \
	$(KERNEL_OBJS) \
	$(ARCH_DIR)/crtn.o

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S .x

all: rvxOS.kernel

debug: rvxOS.kernel
	$(CROSS_COMPILE)-objcopy --only-keep-debug $(COMPILE_TEMP_DIR)/$< $(COMPILE_TEMP_DIR)/os.symbol
	$(CROSS_COMPILE)-strip --strip-debug --strip-unneeded $(COMPILE_TEMP_DIR)/$<
	$(CROSS_COMPILE)-objcopy --add-gnu-debuglink=$(COMPILE_TEMP_DIR)/os.symbol $(COMPILE_TEMP_DIR)/$<
	nohup $(SYS_EMU) -nographic $(KERNEL_ARCH_EMUFLAGS) -D $(COMPILE_TEMP_DIR)/os-run.log \
		-kernel $(COMPILE_TEMP_DIR)/$< -s -S > $(COMPILE_TEMP_DIR)/nohub.out &
	$(ARCH_DB) $(COMPILE_TEMP_DIR)/$< -q -x $(DBINIT)

demu: rvxOS.kernel
	$(SYS_EMU) $(KERNEL_ARCH_EMUFLAGS) -d int -kernel $(COMPILE_TEMP_DIR)/$<

emu: rvxOS.kernel
	$(SYS_EMU) $(KERNEL_ARCH_EMUFLAGS) -serial mon:stdio -kernel $(COMPILE_TEMP_DIR)/$<


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
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d


install: install-headers install-kernel

install-headers:
	mkdir -p $(USR_INCLUDE_DIR)
	cp -R --preserve=timestamps $(KERNEL_ROOT)/include/. $(USR_INCLUDE_DIR)/.

install-kernel: rvxOS.kernel
	mkdir -p $(SYS_BOOT_DIR)
	cp $(COMPILE_TEMP_DIR)/rvxOS.kernel $(SYS_BOOT_DIR)

-include $(OBJS:.o=.d)

