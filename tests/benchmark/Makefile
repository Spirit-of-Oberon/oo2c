include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.config

# Extra flags to GCC
CCFLAGS = -traditional-cpp 

# location of library directory
LIB = $(OOC_DEV_ROOT)/lib

# command to compile benchmarks
COMPILE = $(OOC_DEV_ROOT)/TestCompile -r $(OOC_DEV_ROOT)/lib -r wd --use-ssa

# command to generate assembley output from C
CCC = gcc $(CCFLAGS) -O2 -S -I$(LIB)/src -I$(LIB)/obj -Iwd/obj

# benchmarks to test for ASM output
BENCHMARKS = FFT Sort

test: setup
	$(COMPILE) --make Benchmark 

compile: setup
	$(COMPILE) --make Benchmark 2>&1 | grep -v module | $(OOEF)

setup:
	rm -rf wd
	mkdir wd wd/obj wd/sym wd/asm
	ln -s ../src wd/src

# Attempt to find the differences in assembled output
# This is a quick hack, but probably as good as it will get

asm: test
	for i in $(BENCHMARKS); do \
	  $(CCC) wd/obj/$$i.c -o wd/asm/$$i.s; \
	  $(CCC) wd/src/$${i}C.c -o wd/asm/$${i}C.s; \
          diff -yd wd/asm/$$i.s wd/asm/$${i}C.s > wd/asm/$$i.diff; \
          true; \
	done
	
clean:
	rm -rf wd
