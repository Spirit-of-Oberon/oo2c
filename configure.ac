dnl Autoconf requirements
AC_PREREQ(2.53)
AC_INIT(OOC,2.1.6,mva@users.sf.net)
AC_CONFIG_SRCDIR(src/OOC/Parser.Mod)
AC_CONFIG_HEADER(lib/src/__config.h)

dnl information on the package
AC_SUBST(OOC_DEV_ROOT,[`cd "$srcdir" && pwd`])
AC_SUBST(COMPILER_VERSION,[$PACKAGE_VERSION])
AC_SUBST(COMPILER_MAJOR,[`echo $COMPILER_VERSION|sed -e 's:\..*$::'`])
AC_SUBST(COMPILER_MINOR,[`echo $COMPILER_VERSION|sed -e 's:^[[^.]]*\.::' -e 's:\..*$::'`])
AC_SUBST(TARGET_OS)
AC_EGREP_CPP(yes,
[#ifdef WIN32
  yes
#endif], TARGET_OS="Win32", TARGET_OS="Unix")
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

dnl optional packages
OOC_ARG_ENABLE_PTHREADS()

dnl checks for libraries
OOC_CHECK_LIB(dl,dlopen)
OOC_CHECK_LIB(gc,GC_malloc)
OOC_CHECK_LIB(xnet,socket)
OOC_CHECK_LIB(rt,sem_init)
OOC_CHECK_LIB(posix4,sem_init)
if test $TARGET_OS = Win32; then
  ooc_have_lib_m=FALSE
  OOC_CHECK_LIB(mingwex,main)
  OOC_CHECK_LIB(wsock32,main)
else
  OOC_CHECK_LIB(m,sin)
  ooc_have_lib_mingwex=FALSE
  ooc_have_lib_wsock32=FALSE
fi

dnl checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS(sys/time.h unistd.h io.h pwd.h utime.h stdint.h inttypes.h gc/gc.h)
AC_HEADER_TIME

dnl checks for types
OOC_CHECK_INT64_T()
AC_CHECK_SIZEOF(void*,4)
AC_SUBST(ooc_target_address,[`expr $ac_cv_sizeof_voidp '*' 8`])
AC_SUBST(ooc_target_address_type,["longint"])
if test $ooc_target_address = 64; then
  ooc_target_address_type="hugeint"
fi
AC_CHECK_TYPES([ssize_t],,,[#include <unistd.h>])

dnl checks for structures
AC_CHECK_MEMBER(struct stat.st_mtime_usec,[AC_DEFINE(HAVE_STRUCT_STAT_USEC,1,[Define to 1 if struct stat has usec members.])],,[#include <sys/stat.h>])

dnl checks for compiler characteristics

dnl checks for library functions
AC_TYPE_SIGNAL
dnl   ANSI functions:
AC_CHECK_FUNCS(atexit raise)
dnl   POSIX functions:
AC_CHECK_FUNCS(ftruncate)
dnl   BSD functions:
AC_CHECK_FUNCS(gettimeofday settimeofday mkstemp)
dnl   GNU extensions:
AC_CHECK_FUNCS(backtrace_symbols readdir_r)
dnl   math functions:
AC_CHECK_FUNCS(lrint)

dnl checks for system services

AC_CONFIG_FILES([ENV Makefile.config rsrc/OOC/oo2crc.xml.mk lib/pkginfo.xml 
		 src/OOC/Config/Autoconf.Mod rsrc/OOC/TestFramework/config.xml
		 rsrc/OOC/oobacktrace])
AC_OUTPUT
