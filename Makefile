# NOTE: This makefile is slowly migrating towards a more centralized structure.
# To use it, the environment variable OOC_DEV_ROOT and MAIN_MAKEFILE must be
# set.  This is easiest done by cd-ing to the top-level directory of the
# project and sourcing the file ENV there: `. ENV' (this assumes a Bourne
# compatible shell)

ifndef OOC_DEV_ROOT
export OOC_DEV_ROOT=$(shell pwd)
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

all: stage1/lib/obj/liboo2c.o

.PHONY: mkdir clean distclean test main-clean oo2c install intall-strip

### `mkdir'
###      Build all the directories we're going to install oo2c in.   Since
###      we may be creating several layers of directories, we use mkinstalldirs
###      instead of mkdir.  Not all systems' mkdir programs have the `-p' flag.
mkdir: FRC
	(umask 022; $(OOC_DEV_ROOT)/mkinstalldirs ${bindir} ${libdir}/lib/src)

### `clean'
###      Delete all files from the current directory that are normally
###      created by building the program.  Don't delete the files that
###      record the configuration.  Also preserve files that could be made
###      by building, but normally aren't because the distribution comes
###      with them.
main-clean: doc-clean test-cleanall
	for i in sym obj; do rm -Rf ${top_builddir}/$$i/*; done
	for i in lib/sym lib/obj; do rm -Rf ${top_builddir}/$$i; done
	rm -f src/XML oo2c
	for i in ${test_programs}; do rm -f $$i; done
	-rmdir ${top_builddir}/sym ${top_builddir}/obj
	rm -Rf "$(DOC_DIR)" stage1 stage2 gmon.out
	${MAKE} -C tests/hostess-ooc1 test-clean
	${MAKE} -C tests/benchmark clean

### `package-clean'
###      Delete everything that should not appear in the tar ball produced
###      by "make dist".
package-clean: main-clean
	rm -f ENV rsrc/OOC/Makefile.config rsrc/OOC/oo2crc.xml rsrc/OOC/TestFramework/config.xml src/OOC/Config/Autoconf.Mod
	rm -f lib/src/__config.h config.log config.status
	rm -Rf autom4te.cache

### `distclean'
###      Delete all files from the current directory that are created by
###      configuring or building the program.  If you have unpacked the
###      source and built the program without creating any other files,
###      `make distclean' should leave only the files that were in the
###      distribution.
distclean: package-clean
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


lib/src/__config.h.in: configure.ac
	autoheader

configure: configure.ac lib/src/__config.h.in
	autoconf


oo2c:
	-$(MKDIR) $(OOC_DEV_ROOT)/sym $(OOC_DEV_ROOT)/obj 2>/dev/null
	$(OOC) --make -O $(OFLAGS) oo2c

dist: oo2c
	rm -Rf stage0
	mkdir stage0 stage0/lib
	ln -s ../src stage0/src
	ln -s ../../lib/src stage0/lib/src
	./oo2c --make -r stage0/lib -r stage0 --cc true stage0/src/oo2c.Mod
	rm -Rf stage0/sym/* stage0/lib/sym/*
	cd stage0 && $(PERL) $(OOC_DEV_ROOT)/rsrc/OOC/makefilegen.pl >Makefile.ext
	${MAKE} package-clean
	cd .. && tar  -c -v -j --exclude CVS --exclude '*~' --exclude '.#*' -f ooc2-dist-`date +"%Y%m%d"`.tar.bz2 ooc2

stage0/exe/oo2c:
	${MAKE} -C stage0 -f Makefile.ext oo2c

stage1/src/oo2c.Mod:
	mkdir -p stage1
	ln -s ../src stage1/src

stage1/lib/src/RT0.Mod:
	mkdir -p stage1/lib
	ln -s ../../lib/src stage1/lib/src

stage1/exe/oo2c: stage0/exe/oo2c stage1/lib/src/RT0.Mod stage1/src/oo2c.Mod
	stage0/oo2c --config rsrc/OOC/oo2crc.xml -r stage1/lib -r stage1 --make stage1/src/oo2c.Mod

stage1/lib/obj/liboo2c.o: stage1/exe/oo2c
	stage1/exe/oo2c --config rsrc/OOC/oo2crc.xml -r stage1/lib --make liboo2c
	chmod -R a+rX,go-w stage1/lib lib/src
	chmod 644 rsrc/OOC/oo2crc.xml

install: stage1/lib/obj/liboo2c.o mkdir
	(umask 022; cp -R stage1/lib/sym stage1/lib/obj $(libdir)/lib)
	cd $(libdir)/lib/obj && rm -f *.[cd] */*.[cd] */*/*.[cd] */*/*/*.[cd]
	(umask 022; cp stage1/lib/src/*.h $(libdir)/lib/src)
	(umask 022; cp rsrc/OOC/oo2crc.xml $(libdir))
	${INSTALL_PROGRAM} stage1/exe/oo2c $(bindir)

install-strip:
	${MAKE} INSTALL_PROGRAM='$(INSTALL_PROGRAM) -s' install

ifdef MAIN_MAKEFILE
include $(MAIN_MAKEFILE)
endif
