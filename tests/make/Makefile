TEST_PROG=../../TestMake

.PHONY: all clean test ${TEST_PROG} 

all: test

${TEST_PROG} :
	cd `dirname ${TEST_PROG}` && ${OOC} -MOv `basename ${TEST_PROG}`

test-output:
	mkdir test-output

test: test-output ${TEST_PROG} 
	env TEST_PROG="${TEST_PROG}" DIFF="${DIFF}" ./test.sh

clean:
	rm -Rf test-output
