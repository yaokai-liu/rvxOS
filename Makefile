
include make.config

.PHONY: all clean

all:

clean:
	make -C kernel clean
	make -C lib clean
	rm -f $(COMPILE_TEMP_DIR)/*
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d
	rm -rf $(SYSROOT)
