# NOTE: This makefile is slowly migrating towards a more centralized structure.
# To use it, the environment variable OOC_DEV_ROOT and MAIN_MAKEFILE must be
# set.  This is easiest done by cd-ing to the top-level directory of the
# project and sourcing the file ENV there: `. ENV' (this assumes a Bourne
# compatible shell)

ifndef OOC_DEV_ROOT
$(error Environment variable OOC_DEV_ROOT is not set)
endif
ifndef MAIN_MAKEFILE
$(error Environment variable MAIN_MAKEFILE is not set)
endif

include $(OOC_DEV_ROOT)/rsrc/OOC/Makefile.config

# TEST_SUBDIRS: List of subdirectories with testcases.
TEST_SUBDIRS=\
  $(addprefix tests/config/,sections cmdline environment simple) \
  tests/make \
  tests/scanner \
  tests/parser \
  tests/symtab \
  tests/interface \
  tests/oberon-doc \
  tests/h2o \
  tests/compile \
  tests/ssa \
  tests/lib \
  tests/ia32 \
  tests/ssa-c-output \

DOC_DIR=$(OOC_DEV_ROOT)/oocdoc

top_builddir=$(OOC_DEV_ROOT)

test_programs=TestScanner TestParser TestSymTab TestConfigSections TestConfigCmdLine TestConfigEnv TestConfigSimple TestInterfaceGen TestTexinfo TestMake TestCompile TestH2O TestWebServer AllModules RunTests

all:


.PHONY: mkdir clean distclean test main-clean

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
main-clean: doc-clean test-cleanall
	for i in sym obj; do rm -Rf ${top_builddir}/$$i/*; done
	for i in lib/sym lib/obj; do rm -Rf ${top_builddir}/$$i; done
	rm -f src/XML
	for i in ${test_programs}; do rm -f $$i; done
	-rmdir ${top_builddir}/sym ${top_builddir}/obj
	rm -Rf "$(DOC_DIR)" stage1 stage2 gmon.out
	${MAKE} -C tests/hostess-ooc1 test-clean

### `distclean'
###      Delete all files from the current directory that are created by
###      configuring or building the program.  If you have unpacked the
###      source and built the program without creating any other files,
###      `make distclean' should leave only the files that were in the
###      distribution.
distclean: main-clean
	rm -f ENV rsrc/OOC/Makefile.config rsrc/OOC/TestFramework/config.xml
	rm -f lib/src/__config.h config.log config.status

FRC:


test-hostess-ooc1:
	${MAKE} -C tests/hostess-ooc1 test-runall



### `doc'
###      Use the OOC2 infrastructure to generate HTML files from documentation
###      comments embedded in the source code.  Because this requires access
###      to source code from the oo2c core library, libadt, and libxml, we
###      first create a directory that simulates repositories for these files.
###      Then, XML and HTML files are created under this directory.  Finally,
###      an index file $(OOC_DEV_ROOT)/oocdoc/index.html is generated.
doc:
	$(MKDIR) $(OOC_DEV_ROOT)/sym $(OOC_DEV_ROOT)/obj
	cd $(OOC_DEV_ROOT) && $(OOC) -M $(OFLAGS) TestInterfaceGen
	rm -Rf $(DOC_DIR)
	mkdir $(DOC_DIR) $(DOC_DIR)/ooc2 $(DOC_DIR)/lib
	$(OOC_DEV_ROOT)/rsrc/OOC/make-pseudo-rep.sh --basedir "$(DOC_DIR)" Rts oldlib
	ln -s $(OOC_DEV_ROOT)/src $(DOC_DIR)/ooc2/src
	ln -s $(OOC_DEV_ROOT)/rsrc $(DOC_DIR)/ooc2/rsrc
	ln -s $(OOC_DEV_ROOT)/lib/src $(DOC_DIR)/lib/src
	$(OOC_DEV_ROOT)/TestInterfaceGen --error-style oo2c --html --closure -r "$(DOC_DIR)/oldlib" -r "$(DOC_DIR)/lib" -r "$(DOC_DIR)/ooc2" AllModules
	cd $(DOC_DIR) && $(OOC_DEV_ROOT)/rsrc/OOC/make-index.sh
	$(PRINT) "Done.  Index file is $(DOC_DIR)/index.html"


lib/src/__config.h.in: acconfig.h configure.ac
	autoheader

configure: configure.ac lib/src/__config.h.in
	autoconf

include $(MAIN_MAKEFILE)
