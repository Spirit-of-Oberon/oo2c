TEST_PROG=../../TestSymTab

.PHONY: all clean test ${TEST_PROG}

all: test

${TEST_PROG}:
	cd `dirname ${TEST_PROG}` && ${OOC} -MOv `basename ${TEST_PROG}`

test-output:
	mkdir test-output test-output/wf test-output/not-wf

test: test-output ${TEST_PROG}
	rm -Rf wf/doc/xml not-wf/doc/xml wf/sym not-wf/sym
	env TEST_PROG="${TEST_PROG}" DIFF="${DIFF}" ./wf-names-only.sh
	env TEST_PROG="${TEST_PROG}" DIFF="${DIFF}" ./wf-resolve-names.sh
	env TEST_PROG="${TEST_PROG}" DIFF="${DIFF}" ./not-wf.sh

clean:
	rm -Rf test-output wf/doc wf/sym not-wf/doc not-wf/sym
