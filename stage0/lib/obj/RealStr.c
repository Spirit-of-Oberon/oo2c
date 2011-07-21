#include <RealStr.d>
#include <__oo2c.h>
#include <setjmp.h>

void RealStr__StrToReal(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_REAL32 *real, OOC_INT8 *res) {
  register OOC_INT32 i0;
  register OOC_REAL32 f0;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = RealConv__FormatReal((void*)(OOC_INT32)str, str_0d);
  *res = i0;
  i0 = _in(i0,3u);
  if (!i0) goto l4;
  f0 = RealConv__ValueReal((void*)(OOC_INT32)str, str_0d);
  *real = f0;
l4:
  return;
  ;
}

void RealStr__RealToFloat(OOC_REAL32 real, OOC_INT16 sigFigs, OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  register OOC_REAL32 f0;
  OOC_CHAR8 s[32];

  i0 = sigFigs;
  i1 = i0<1;
  if (i1) goto l3;
  i1 = i0>9;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (!i1) goto l8;
  i0=9;
l8:
  f0 = real;
  sprintf((void*)(OOC_INT32)s, "%-+#.*E", (i0-1), f0);
  Real0__NormalizeFloat((void*)(OOC_INT32)s, 32);
  _copy_8((const void*)(OOC_INT32)s,(void*)(OOC_INT32)str,str_0d);
  return;
  ;
}

void RealStr__RealToEng(OOC_REAL32 real, OOC_INT16 sigFigs, OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  register OOC_REAL32 f0;
  OOC_CHAR8 s[32];

  i0 = sigFigs;
  i1 = i0<1;
  if (i1) goto l3;
  i1 = i0>9;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (!i1) goto l8;
  i0=9;
l8:
  f0 = real;
  sprintf((void*)(OOC_INT32)s, "%-+#.*E", (i0-1), f0);
  Real0__FormatForEng((void*)(OOC_INT32)s, 32);
  _copy_8((const void*)(OOC_INT32)s,(void*)(OOC_INT32)str,str_0d);
  return;
  ;
}

void RealStr__RealToFixed(OOC_REAL32 real, OOC_INT16 place, OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  register OOC_REAL32 f0;
  OOC_CHAR8 s[70];

  i0 = place;
  i1 = i0<0;
  if (i1) goto l3;
  i1=i0;
  goto l4;
l3:
  i1=9;
l4:
  f0 = real;
  sprintf((void*)(OOC_INT32)s, "%-+#.*f", i1, f0);
  Real0__FormatForFixed((void*)(OOC_INT32)s, 70, i0);
  _copy_8((const void*)(OOC_INT32)s,(void*)(OOC_INT32)str,str_0d);
  return;
  ;
}

void RealStr__RealToStr(OOC_REAL32 real, OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  register OOC_REAL32 f0;
  OOC_CHAR8 s[70];

  f0 = real;
  RealStr__RealToFixed(f0, (-1), (void*)(OOC_INT32)s, 70);
  i0 = Strings__Length((void*)(OOC_INT32)s, 70);
  i0 = (str_0d-i0)-1;
  i1 = i0>0;
  if (i1) goto l12;
  i0 = i0<0;
  if (!i0) goto l13;
  RealStr__RealToFloat(f0, 1, (void*)(OOC_INT32)s, 70);
  i0 = Strings__Length((void*)(OOC_INT32)s, 70);
  i0 = (str_0d-i0)-1;
  i1 = i0>1;
  if (!i1) goto l13;
  RealStr__RealToFloat(f0, i0, (void*)(OOC_INT32)s, 70);
  i1 = Strings__Length((void*)(OOC_INT32)s, 70);
  i1 = i1<(str_0d-1);
  if (!i1) goto l13;
  RealStr__RealToFloat(f0, (i0+1), (void*)(OOC_INT32)s, 70);
  goto l13;
l12:
  RealStr__RealToFixed(f0, (i0-1), (void*)(OOC_INT32)s, 70);
l13:
  _copy_8((const void*)(OOC_INT32)s,(void*)(OOC_INT32)str,str_0d);
  return;
  ;
}

void OOC_RealStr_init(void) {

  return;
  ;
}

/* --- */
