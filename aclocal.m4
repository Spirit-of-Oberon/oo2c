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
  AC_DEFINE_UNQUOTED(OOC_INT64_T, long int, [64 bit int type, if it exists.])
  ooc_target_integer=32
else
  AC_DEFINE_UNQUOTED(OOC_INT64_T, $ooc_int64_t, [64 bit int type, if it exists.])
  ooc_target_integer=64
fi
AC_SUBST(ooc_target_integer)
AC_SUBST(ooc_target_long_int)
AC_SUBST(ooc_target_long_set)
])


# OOC_CHECK_LIB(LIBRARY, FUNCTION,
#               [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND],
#               [OTHER-LIBRARIES])
# ------------------------------------------------------
#
# This macro is a wrapper around AC_CHECK_LIB that additionally
# sets the variable `ooc_have_lib_LIBRARY' to TRUE or FALSE, depending
# on the outcome.  AC_SUBST is called on `ooc_have_lib_LIBRARY'.
AC_DEFUN(OOC_CHECK_LIB,
[AC_CHECK_LIB([$1],[$2],[$3],[$4],[$5])
if test "$ac_cv_lib_$1_$2" = yes; then
   ooc_have_lib_$1=TRUE
else
   ooc_have_lib_$1=FALSE
fi
AC_SUBST(ooc_have_lib_$1)])
