dnl OOC_CHECK_LONG_SIZE_T()
dnl Checks whether size_t is a `long' type, or just unsigned
AC_DEFUN(OOC_CHECK_LONG_SIZE_T,
[AC_REQUIRE([AC_HEADER_STDC])dnl
AC_MSG_CHECKING(whether size_t is long)
AC_CACHE_VAL(ooc_cv_type_long_size_t,
[AC_EGREP_CPP([typedef[^a-z_].*long.*[^a-z_]size_t],
[#include <sys/types.h>
#if STDC_HEADERS
#include <stdlib.h>
#endif], ooc_cv_type_long_size_t=yes, ooc_cv_type_long_size_t=no)])dnl
AC_MSG_RESULT($ooc_cv_type_long_size_t)
if test $ooc_cv_type_long_size_t = no; then
  AC_DEFINE(OOC_SIZE_T, unsigned)
else
  AC_DEFINE(OOC_SIZE_T, unsigned long)
fi])


dnl OOC_CHECK_INT64_T()
dnl Checks whether a 64 bit int type exists.
AC_DEFUN(OOC_CHECK_INT64_T,
[ooc_int64_t=""
AC_CHECK_SIZEOF(long int,0)
if test $ac_cv_sizeof_long_int = 8; then
  ooc_int64_t="long int"
  ooc_target_long_int="HUGEINT"
  ooc_target_long_set="SYSTEM.SET64"
else
  ooc_target_long_int="LONGINT"
  ooc_target_long_set="SET"
  AC_CHECK_SIZEOF(long long int,0)
  if test $ac_cv_sizeof_long_long_int = 8; then
    ooc_int64_t="long long int"
  fi
fi

if test -z "$ooc_int64_t"; then
  AC_DEFINE_UNQUOTED(OOC_INT64_T, long int)
  ooc_target_integer=32
else
  AC_DEFINE_UNQUOTED(OOC_INT64_T, $ooc_int64_t)
  ooc_target_integer=64
fi
AC_SUBST(ooc_target_integer)
AC_SUBST(ooc_target_long_int)
AC_SUBST(ooc_target_long_set)
])
