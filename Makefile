# NOTE: This makefile is slowly migrating towards a more centralized structure.
# To use it, the environment variable OOC_DEV_ROOT and MAIN_MAKEFILE must be
# set.  This is easiest done by cd-ing to the top-level directory of the
# project and sourcing the file ENV there: `. ENV' (this assumes a Bourne
# compatible shell)

# TEST_SUBDIRS: List of subdirectories with testcases.
#TEST_SUBDIRS=tests/compile


top_builddir=$(OOC_DEV_ROOT)
subdirs=tests

test_programs=TestScanner TestParser TestSymTab TestConfigSections TestConfigCmdLine TestConfigEnv TestConfigSimple TestInterfaceGen TestTexinfo TestMake TestCompile AllModules RunTests

all:


.PHONY: mkdir clean distclean test

### `mkdir'
###      Build all the directories we're going to install oo2c in.   Since
###      we may be creating several layers of directories, we use mkinstalldirs
###      instead of mkdir.  Not all systems' mkdir programs have the `-p' flag.
mkdir: FRC
	(umask 022; for i in sym obj; do \
	  $(OOC_DEV_ROOT)/mkinstalldirs ${top_builddir}/$$i; \
	done)

### `clean'
###      Delete all files from the current directory that are normally
###      created by building the program.  Don't delete the files that
###      record the configuration.  Also preserve files that could be made
###      by building, but normally aren't because the distribution comes
###      with them.
clean: doc-clean test-clean
	for i in sym obj; do rm -Rf ${top_builddir}/$$i/*; done
	for i in lib/sym lib/obj; do rm -Rf ${top_builddir}/$$i; done
	rm -f src/XML
	for i in ${test_programs}; do rm -f $$i; done
	for i in ${subdirs}; do cd $$i && ${MAKE} clean; done
	-rmdir ${top_builddir}/sym ${top_builddir}/obj
	${MAKE} -C tests/hostess-ooc1 test-clean

### `distclean'
###      Delete all files from the current directory that are created by
###      configuring or building the program.  If you have unpacked the
###      source and built the program without creating any other files,
###      `make distclean' should leave only the files that were in the
###      distribution.
distclean: clean

FRC:

### `test'
###      Perform all available regression tests.
test: mkdir test-runall
	cd tests && ${MAKE} test

test-hostess-ooc1:
	${MAKE} -C tests/hostess-ooc1 test-runall

include $(MAIN_MAKEFILE)
