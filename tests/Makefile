subdirs=scanner parser symtab config oberon-doc interface

export DIFF=diff -u

.PHONY: clean test

clean:
	for i in ${subdirs}; do (cd $$i && ${MAKE} clean); done

test:
	set -e; for i in ${subdirs}; do (cd $$i && ${MAKE} test) || exit 1; done
