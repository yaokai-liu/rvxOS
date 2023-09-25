
include make.config

.PHONY: all clean

all:

clean:
	rm -f $(COMPILE_TEMP_DIR)/*
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d
	rm -r $(SYSROOT)
