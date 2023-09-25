include ../make.config

LIB_ROOT = $(PROJECT_ROOT)/lib
LIB_DIR = $(LIB_ROOT)
XDEF_DIR = $(PROJECT_ROOT)/xdef

ACFLAGS = -c -g -Wall -Wextra -march=$(ARCH) -mabi=$(ABI) -static --sysroot=$(SYSROOT)
CCFLAGS = -c -g -Wall -Wextra -march=$(ARCH) -mabi=$(ABI) -static --sysroot=$(SYSROOT) -std=c17 -fPIC\
	-DXTYPES_USING_STDC_TYPE -DXDEF_USING_C_STD_DEF
XCFLAGS =
LDFLAGS = -z separate-code -shared
EMUFLAGS =

PLAT_OBJS = \
	instinline/$(TARGET_PLATFORM)/basic.c

FREE_OBJS = \
	$(ARCH_FREE_OBJS) \
	string/memcmp.o \
	string/memcpy.o \
	string/memset.o \
	string/strlen.o

PLAT_OBJS = \
	$(ARCH_PLAT_OBJS)

OBJS =  $(FREE_OBJS) \
	$(PLAT_OBJS)

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .c .S .x

all: libc.so

libc.so: $(OBJS)
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


install: install-headers install-libs

install-headers:
	mkdir -p $(USR_INCLUDE_DIR)
	cp --preserve=timestamps $(XDEF_DIR)/* $(USR_INCLUDE_DIR)/.
	cp -R --preserve=timestamps $(LIB_ROOT)/include/. $(USR_INCLUDE_DIR)/.

install-libs: libc.so
	mkdir -p $(USR_LIB_DIR)
	cp $(COMPILE_TEMP_DIR)/$< $(USR_LIB_DIR)

-include $(OBJS:.o=.d)

