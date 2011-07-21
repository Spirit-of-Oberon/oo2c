TEST_DRIVER=RunTests
TEST_DRIVER_FLAGS=--out-module Out0
TEST_PROCESSOR=TestCompile
TEST_BASE=tests/ssa-x86-output

OUT_FILES=$(wildcard $(OOC_DEV_ROOT)/$(TEST_BASE)/wd/obj/[^x]*[^_].s)

include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.tests-framework

%.diff:
	$(DIFF) $(dir $*)../../ref/obj/$(notdir $*) $*

# note: this rule must be evaluated in a separate make process, once
# test1-runall has been completed, or $(OUTFILES) will be incomplete
test-diff-all: $(addsuffix .diff,$(OUT_FILES))
	$(PRINT) Done checking assembler output.

test-runall: test1-runall
	$(MAKE) -f $(OOC_DEV_ROOT)/$(TEST_BASE)/Makefile test-diff-all
