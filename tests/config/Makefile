subdirs=sections cmdline environment simple

.PHONY: clean test

clean:
	for i in ${subdirs}; do (cd $$i && ${MAKE} clean); done

test:
	set -e; for i in ${subdirs}; do (cd $$i && ${MAKE} test) || exit 1; done
