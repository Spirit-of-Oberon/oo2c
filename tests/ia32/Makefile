# This test suite holds test cases that primarily check properties
# of the SSA code generator.  Their content and progression are geared
# toward the progress of the SSA back-end, and toward pecularities arising
# from the SSA view on program code.  In the (not so near) future, these
# test cases are to be moved to tests/compile.
# 
# This directory holds only "run" and "error" test cases.  That is, each
# test case produces an executable that is subsequently evaluated.  Tests
# of the categories "accept" and "reject" belong into tests/compile/.

TEST_DRIVER=RunTests
TEST_DRIVER_FLAGS=--out-module Out0
TEST_PROCESSOR=TestCompile
TEST_BASE=tests/ia32

include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.tests-framework
