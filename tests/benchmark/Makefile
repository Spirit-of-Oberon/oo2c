include $(OOC_DEV_ROOT)/Makefile.config

# Extra flags to GCC
CCFLAGS = #-traditional-cpp

# location of library directory
LIB = $(OOC_DEV_ROOT)/lib

# binary that produces the tested excutables
TEST_DRIVER = oo2c

# command to compile benchmarks
COMPILE = $(OOC_DEV_ROOT)/bin/$(TEST_DRIVER) --config $(OOC_DEV_ROOT)/oo2crc-install.xml -r $(OOC_DEV_ROOT)/lib -r wd

# command to generate assembley output from C
CCC = gcc $(CCFLAGS) -O2 -S -I$(LIB)/src -I$(LIB)/obj -Iwd/obj
CCC1 = gcc $(CCFLAGS) -O2 -S -I/usr/local/lib/oo2c/lib -I/usr/local/lib/oo2c/obj -Iwd1/obj

# benchmarks to test for ASM output
BENCHMARKS = FFT Sort Array

test: compile
	wd/bin/Benchmark --all --normalise

compile: setup
	$(COMPILE) --make Benchmark

setup:
	$(MKDIR) $(OOC_DEV_ROOT)/sym $(OOC_DEV_ROOT)/obj
	cd $(OOC_DEV_ROOT) && $(OOC) -M $(OFLAGS) $(TEST_DRIVER)
	rm -rf wd
	mkdir wd wd/obj wd/sym wd/asm
	ln -s ../src wd/src

setup-ooc1:
	rm -rf wd1
	mkdir wd1 wd1/obj wd1/sym wd1/asm wd1/bin

compile-ooc1: setup-ooc1
	$(OOC) --optimize -Mv --cflags "-O2" Benchmark

test-ooc1: compile-ooc1
	wd1/bin/Benchmark --all --normalise

# Attempt to find the differences in assembled output
# This is a quick hack, but probably as good as it will get

asm: compile
	for i in $(BENCHMARKS); do \
	  $(CCC) wd/obj/$$i.c -o wd/asm/$$i.s; \
	  $(CCC) wd/src/$${i}C.c -o wd/asm/$${i}C.s; \
          diff -yd wd/asm/$$i.s wd/asm/$${i}C.s > wd/asm/$$i.diff; \
          true; \
	done

asm-ooc1: compile-ooc1
	for i in $(BENCHMARKS); do \
	  $(CCC1) wd1/obj/$$i.c -o wd1/asm/$$i.s; \
	  $(CCC1) src/$${i}C.c -o wd1/asm/$${i}C.s; \
          diff -yd wd1/asm/$$i.s wd1/asm/$${i}C.s > wd/asm/$$i.diff; \
          true; \
	done

asm-diff: asm asm-ooc1
	for i in $(BENCHMARKS); do \
          diff -yd wd/asm/$$i.s wd1/asm/$$i.s > wd/asm/$$i.v2.diff; \
          true; \
	done

clean:
	rm -rf wd wd1
