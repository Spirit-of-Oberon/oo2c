subdirs=make scanner parser symtab config oberon-doc interface

include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.config

.PHONY: clean test

clean:
	for i in ${subdirs}; do (cd $$i && ${MAKE} clean); done

test:
	set -e; for i in ${subdirs}; do (cd $$i && ${MAKE} test) || exit 1; done
