# This test suite extends the one from tests/ssa: After running the
# usual run/error tests, the C code generated for the test case's
# module is compared with a reference file.  Differences between the C
# output and the reference are reported as errors.
# 
# These tests allow keep an eye on the quality of the C output of the
# SSA back-end.  Changes that introduce variations to the C
# translations can be spotted, evaluated, and if need be corrected.
# The output of the back-end is always subject to better code
# optimization, or better translation techniques, which means that
# differences are not always errors.  In such a case, the reference
# file is adjusted to match the new situation.
#
# This directory holds only "run" and "error" test cases.  That is, each
# test case produces an executable that is subsequently evaluated.  Tests
# of the categories "accept" and "reject" belong into tests/compile/.

TEST_DRIVER=RunTests
TEST_DRIVER_FLAGS=--out-module Out0
TEST_PROCESSOR=TestCompile
TEST_BASE=tests/ssa-c-output

OUT_FILES=$(wildcard $(OOC_DEV_ROOT)/$(TEST_BASE)/wd/obj/[^x]*[^_].c)

include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.tests-framework

%.diff:
	$(DIFF) $(dir $*)../../ref/obj/$(notdir $*) $*

# note: this rule must be evaluated in a separate make process, once
# test1-runall has been completed, or $(OUTFILES) will be incomplete
test-diff-all: $(addsuffix .diff,$(OUT_FILES))
	$(PRINT) Done checking C output.

test-runall: test1-runall
	$(MAKE) -f $(OOC_DEV_ROOT)/$(TEST_BASE)/Makefile test-diff-all
