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

TEST_DRIVER=RunTests
TEST_PROCESSOR=TestCompile
TEST_BASE=tests/ssa-c-output

include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.tests-framework


%.diff:
	$(DIFF) wd/$* ref/$*

test-diff-all: test1-runall $(addsuffix .diff,$(patsubst wd/%,%,$(wildcard wd/obj/[^x]*[^_].c)))
	$(PRINT) Done checking C output.

test-runall: test-diff-all
