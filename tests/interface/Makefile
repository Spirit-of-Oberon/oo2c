TEST_PROG=../../TestInterfaceGen

.PHONY: all clean test ${TEST_PROG}

all: test

${TEST_PROG}:
	cd `dirname ${TEST_PROG}` && ${OOC} -MOv `basename ${TEST_PROG}`

test-output:
	mkdir test-output test-output/not-wf

test: ${TEST_PROG} test-output
	rm -Rf wf/doc/xml not-wf/doc/xml wf/sym not-wf/sym
	env TEST_PROG="${TEST_PROG}" DIFF="${DIFF}" ./wf.sh
	env TEST_PROG="${TEST_PROG}" DIFF="${DIFF}" ./not-wf.sh

clean:
	rm -Rf wf/doc wf/sym not-wf/sym test-output
