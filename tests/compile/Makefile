# Primary test suite for the compiler.  It contains all kinds of
# tests, including "accept" and "reject" test cases.  This means, that
# unlike tests/ssa and tests/ssa-c-output, this directory also
# contains tests that check the error reporting (and error recovery)
# capabilites of the compiler front-end.
# 
# At the moment, the "run" test cases are only evaluated using the IR
# to C back-end.  In the future, once the back-ends currently under
# development are feature complete, I intend to extend the test
# framework so that all tests are run for all back-ends.  For now,
# tests exercising the SSA back-end are in tests/ssa.

TEST_DRIVER=RunTests
TEST_DRIVER_FLAGS=--out-module Out0
TEST_PROCESSOR=TestCompile
TEST_BASE=tests/compile

include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.tests-framework
