include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.config

COMPILE = $(OOC_DEV_ROOT)/TestCompile -r $(OOC_DEV_ROOT)/lib -r wd --use-ssa

test: setup
	$(COMPILE) --make Benchmark 

compile: setup
	$(COMPILE) --make Benchmark 2>&1 | grep -v module | $(OOEF)

setup:
	rm -rf wd
	mkdir wd wd/obj wd/sym
	ln -s ../src wd/src

clean:
	rm -rf wd
