dnl Autoconf requirements
AC_PREREQ(2.52)
AC_INIT(OOC,0.1,mia@de.uu.net)
AC_CONFIG_SRCDIR(src/OOC/Parser.Mod)
AC_CONFIG_HEADER(lib/src/__config.h)
AC_SUBST(OOC_DEV_ROOT,[`cd "$srcdir" && pwd`])

dnl information on the package

dnl checks for programs
AC_PROG_INSTALL
AC_PATH_PROGS(OOC,oo2c Oo2c,oo2c)
AC_PATH_PROGS(OOEF,ooef Ooef,ooef)
AC_PATH_PROGS(OOCN,oocn Oocn,oocn)
AC_PATH_PROG(DIFF,diff,diff)
AC_PATH_PROG(XSLTPROC,xsltproc,xsltproc)
AC_PATH_PROG(PERL,perl,perl)

dnl checks for libraries
AC_CHECK_LIB(gc,GC_malloc)

dnl checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS(sys/time.h unistd.h io.h pwd.h utime.h gc/gc.h)
AC_HEADER_TIME

dnl checks for types
OOC_CHECK_LONG_SIZE_T()
OOC_CHECK_INT64_T()

dnl checks for structures

dnl checks for compiler characteristics

dnl checks for library functions
AC_TYPE_SIGNAL
dnl   ANSI functions:
AC_CHECK_FUNCS(atexit raise)
dnl   BSD functions:
AC_CHECK_FUNCS(gettimeofday settimeofday)

dnl checks for system services

AC_CONFIG_FILES(ENV rsrc/OOC/Makefile.config rsrc/OOC/TestFramework/config.xml)
AC_OUTPUT
