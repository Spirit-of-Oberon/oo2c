dnl Autoconf requirements
AC_PREREQ(2.53)
AC_INIT(OOC,2.0.5,mia@de.uu.net)
AC_CONFIG_SRCDIR(src/OOC/Parser.Mod)
AC_CONFIG_HEADER(lib/src/__config.h)

dnl information on the package
AC_SUBST(OOC_DEV_ROOT,[`cd "$srcdir" && pwd`])
AC_SUBST(COMPILER_VERSION,[$PACKAGE_VERSION])
AC_SUBST(COMPILER_MAJOR,[`echo $COMPILER_VERSION|sed -e 's:\..*$::'`])
AC_SUBST(COMPILER_MINOR,[`echo $COMPILER_VERSION|sed -e 's:^[[^.]]*\.::' -e 's:\..*$::'`])
AC_SUBST(OFLAGS)

dnl checks for programs
AC_PROG_INSTALL
AC_PATH_PROG(OOC,oo2c,[bin/oo2c --config oo2crc-install.xml])
AC_PATH_PROG(OOEF,ooef,[bin/ooef])
AC_PATH_PROG(DIFF,diff,diff)
AC_PATH_PROG(XSLTPROC,xsltproc,no)
AC_PATH_PROG(PERL,perl,/usr/bin/perl)

AC_ARG_ENABLE(libs, [  --disable-libs          don't build static/shared libraries with libtool],,enable_libs=yes)
if test $enable_libs = yes; then
  AC_PATH_PROG(LIBTOOL,libtool,no)
else
  LIBTOOL="no";
  AC_MSG_CHECKING([for libtool])
  AC_MSG_RESULT([disabled])
fi

dnl checks for libraries
AC_CHECK_LIB(m,sin)
AC_CHECK_LIB(gc,GC_malloc)
AC_CHECK_LIB(xnet,socket)
if test $ac_cv_lib_xnet_socket = yes; then
   have_libxnet=TRUE
else
   have_libxnet=FALSE
fi
AC_SUBST(have_libxnet)

dnl checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS(sys/time.h unistd.h io.h pwd.h utime.h stdint.h gc/gc.h)
AC_HEADER_TIME

dnl checks for types
OOC_CHECK_INT64_T()
AC_CHECK_SIZEOF(void*,4)
AC_SUBST(ooc_target_address,[`expr $ac_cv_sizeof_voidp '*' 8`])
AC_SUBST(ooc_target_address_type,["longint"])
if test $ooc_target_address = 64; then
  ooc_target_address_type="hugeint"
fi

dnl checks for structures

dnl checks for compiler characteristics

dnl checks for library functions
AC_TYPE_SIGNAL
dnl   ANSI functions:
AC_CHECK_FUNCS(atexit raise)
dnl   BSD functions:
AC_CHECK_FUNCS(gettimeofday settimeofday)
dnl   GNU extensions:
AC_CHECK_FUNCS(backtrace_symbols readdir_r)
dnl   math functions:
AC_CHECK_FUNCS(lrint)

dnl checks for system services

AC_CONFIG_FILES([ENV Makefile.config rsrc/OOC/oo2crc.xml.mk lib/pkginfo.xml 
		 src/OOC/Config/Autoconf.Mod rsrc/OOC/TestFramework/config.xml
		 rsrc/OOC/oobacktrace])
AC_OUTPUT
