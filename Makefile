# NOTE: To use this makefile in a development setup, the environment
# variables OOC_DEV_ROOT and MAIN_MAKEFILE must be set.  This is
# easiest done by cd-ing to the top-level directory of the project and
# sourcing the file ENV there: `. ENV' (this assumes a Bourne
# compatible shell).
# 
# In an installation setup, simply run "./configure" and do "make
# install".  In this case, OOC_DEV_ROOT must not be set.

ifndef OOC_DEV_ROOT
export OOC_DEV_ROOT=$(shell pwd)
export MAIN_MAKEFILE=$(OOC_DEV_ROOT)/rsrc/OOC/Makefile.ooc-main
endif

include $(OOC_DEV_ROOT)/Makefile.config

# When build from a distribution tarball, then the bootstrap compiler is
# the one build from the C sources in the tarball.  To be able to run
# "make install" directly from the development environment, this variable
# must point to an existing compiler executable.
BOOTSTRAP_COMPILER?=stage0/oo2c

# TEST_SUBDIRS: List of subdirectories with testcases.
TEST_SUBDIRS=\
  $(addprefix tests/config/,sections cmdline environment simple) \
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

test_programs=TestScanner TestParser TestSymTab TestConfigSections TestConfigCmdLine TestConfigEnv TestConfigSimple TestInterfaceGen TestTexinfo TestCompile TestH2O TestWebServer TestCodec encdec AllModules RunTests

all: lib/obj/liboo2c.la bin/oo2c

.PHONY: clean distclean test main-clean oo2c install intall-strip

### `clean'
###      Delete all files from the current directory that are normally
###      created by building the program.  Don't delete the files that
###      record the configuration.  Also preserve files that could be made
###      by building, but normally aren't because the distribution comes
###      with them.
main-clean: doc-clean test-cleanall
	for i in sym obj sym-v1 obj-v1; do rm -Rf ${top_builddir}/$$i; done
	for i in lib/sym lib/obj; do rm -Rf ${top_builddir}/$$i; done
	rm -f src/XML oo2c
	for i in ${test_programs}; do rm -f $$i; done
	-cd stage0 && rm -f *.o */*.o */*/*.o */*/*/*.o
	rm -Rf "$(DOC_DIR)" stage1 stage2 tests/lib-TestCompile gmon.out
	${MAKE} -C tests/hostess-ooc1 test-clean
	${MAKE} -C tests/benchmark clean

### `distclean'
###      Delete all files from the current directory that are created by
###      configuring or building the program.  If you have unpacked the
###      source and built the program without creating any other files,
###      `make distclean' should leave only the files that were in the
###      distribution.
distclean: main-clean
	rm -f ENV Makefile.config rsrc/OOC/oo2crc.xml rsrc/OOC/oo2crc.xml.mk oo2crc-install.xml rsrc/OOC/TestFramework/config.xml src/OOC/Config/Autoconf.Mod
	rm -f lib/src/__config.h config.log config.status
	rm -Rf autom4te.cache stage0/bin bin

### `cvs-clean'
###      Delete everything that should not appear in the CVS.
cvsclean: distclean
	rm -Rf stage0

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
	$(MKDIR) $(OOC_DEV_ROOT)/sym $(OOC_DEV_ROOT)/obj $(OOC_DEV_ROOT)/sym-v1 $(OOC_DEV_ROOT)/obj-v1
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


### Create header file that is used as input for GNU autoconf.
lib/src/__config.h.in: configure.ac
	autoheader

### Create configure script using GNU autoconf.
configure: configure.ac lib/src/__config.h.in
	autoconf

### Some variables are defined recursively by configure.  Expanding these
### variables is best done by the make utility itself.  This rule puts the
### expanded values into the OOC configuration file oo2crc.xml.
$(OOC_DEV_ROOT)/rsrc/OOC/oo2crc.xml: $(OOC_DEV_ROOT)/rsrc/OOC/oo2crc.xml.mk $(OOC_DEV_ROOT)/Makefile.config
	sed -e 's:%libdir%:$(libdir):g' \
	    -e 's:%oocdir%:$(oocdir):g' \
	    -e 's:%bindir%:$(bindir):g' \
	    -e 's:%INSTALL%:$(INSTALL):g' \
	    -e 's:%INSTALL_PROGRAM%:$(INSTALL_PROGRAM):g' \
	    -e 's:%INSTALL_DATA%:$(INSTALL_DATA):g' \
		$(OOC_DEV_ROOT)/rsrc/OOC/oo2crc.xml.mk >$(OOC_DEV_ROOT)/rsrc/OOC/oo2crc.xml
rsrc/OOC/oo2crc.xml: $(OOC_DEV_ROOT)/rsrc/OOC/oo2crc.xml

### This configuration file is used to build and install the compiler and
### library from scratch.  It must not refer to any stale data that may
### be present on the target system.
$(OOC_DEV_ROOT)/oo2crc-install.xml: $(OOC_DEV_ROOT)/rsrc/OOC/oo2crc.xml
	sed -e 's:<file-system>:<!--:g' -e 's:</file-system>:-->:g' $(OOC_DEV_ROOT)/rsrc/OOC/oo2crc.xml >$(OOC_DEV_ROOT)/oo2crc-install.xml

dist: $(OOC_DEV_ROOT)/oo2crc-install.xml
	-$(MKDIR) $(OOC_DEV_ROOT)/sym $(OOC_DEV_ROOT)/obj $(OOC_DEV_ROOT)/sym-v1 $(OOC_DEV_ROOT)/obj-v1 2>/dev/null
	$(OOC) --make -O $(OFLAGS) oo2c
	rm -Rf stage0
	mkdir stage0 stage0/lib
	ln -s ../src stage0/src
	ln -s ../../lib/src stage0/lib/src
	./oo2c --config oo2crc-install.xml --make -r stage0/lib -r stage0 --cc true $(OFLAGS) stage0/src/oo2c.Mod
	rm -Rf stage0/sym/* stage0/lib/sym/*
	cd stage0 && $(PERL) $(OOC_DEV_ROOT)/rsrc/OOC/makefilegen.pl >Makefile.ext
	${MAKE} distclean
	cd .. && tar -c -v --exclude CVS --exclude '*~' --exclude '.#*' -f - ooc2 | bzip2 -9 >ooc2-dist-`date +"%Y%m%d"`.tar.bz2

### Create initial compiler executable from distributed C sources.
stage0/oo2c:
	${MAKE} -C stage0 -f Makefile.ext oo2c

### Build library from core modules using the initial compiler executable.
lib/obj/liboo2c.la: $(BOOTSTRAP_COMPILER) $(OOC_DEV_ROOT)/oo2crc-install.xml
	$(BOOTSTRAP_COMPILER) --config oo2crc-install.xml -r lib $(OFLAGS) --build-package liboo2c

### Build second compiler using the initial compiler executable and the
### library lib/obj/liboo2c.la.
bin/oo2c: $(BOOTSTRAP_COMPILER) $(OOC_DEV_ROOT)/oo2crc-install.xml lib/obj/liboo2c.la
	$(BOOTSTRAP_COMPILER) --config oo2crc-install.xml -r lib -r . $(OFLAGS) --build-package oo2c

install: lib/obj/liboo2c.la bin/oo2c
	$(INSTALL) -d $(oocdir)/pkginfo
	$(BOOTSTRAP_COMPILER) --config oo2crc-install.xml -r lib --install-program "$(INSTALL_PROGRAM)" $(OFLAGS) --install-package liboo2c
	$(BOOTSTRAP_COMPILER) --config oo2crc-install.xml -r lib -r . --install-program "$(INSTALL_PROGRAM)" $(OFLAGS) --install-package oo2c
	chmod a+x $(oocdir)/install-sh

install-strip:
	${MAKE} INSTALL_PROGRAM='$(INSTALL_PROGRAM) -s' install

uninstall: FRC
	$(BOOTSTRAP_COMPILER) --config oo2crc-install.xml $(OFLAGS) --uninstall-package oo2c liboo2c

ifdef MAIN_MAKEFILE
include $(MAIN_MAKEFILE)
endif
