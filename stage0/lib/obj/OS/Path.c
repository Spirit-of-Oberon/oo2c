#include <OS/Path.d>
#include <__oo2c.h>
#include <setjmp.h>

Object__String OS_Path__DirName(Object__String path) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)path;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 1118));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1096)))), Object__StringDesc_LastIndexOf)),Object__StringDesc_LastIndexOf)((Object__String)i0, 47u, i1);
  i = i1;
  i2 = i1>=0;
  if (i2) goto l3;
  return (Object__String)((OOC_INT32)_c0);
  goto l25;
l3:
  j = i1;
  i2 = i1>0;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1297)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i1-1));
  i2 = i2==47u;
  
l8:
  if (i2) goto l10;
  i2=i1;
  goto l20;
l10:
  i2=i1;
l11_loop:
  i2 = i2-1;
  j = i2;
  i3 = i2>0;
  if (i3) goto l14;
  i3=0u;
  goto l16;
l14:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1297)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i2-1));
  i3 = i3==47u;
  
l16:
  if (i3) goto l11_loop;
l20:
  i3 = i2==0;
  if (i3) goto l23;
  i = i2;
  i1=i2;
  goto l24;
l23:
  i1 = i1+1;
  i = i1;
  
l24:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1549)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, 0, i1);
  return (Object__String)i0;
l25:
  _failed_function(954); return 0;
  ;
}

Object__String OS_Path__BaseName(Object__String path) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)path;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2089));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2067)))), Object__StringDesc_LastIndexOf)),Object__StringDesc_LastIndexOf)((Object__String)i0, 47u, i1);
  i = i1;
  i2 = i1>=0;
  if (i2) goto l3;
  return (Object__String)i0;
  goto l4;
l3:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 2157));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2137)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, (i1+1), i2);
  return (Object__String)i0;
l4:
  _failed_function(1690); return 0;
  ;
}

void OS_Path__SplitExt(Object__String path, Object__String *root, Object__String *ext) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)path;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2668));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2646)))), Object__StringDesc_LastIndexOf)),Object__StringDesc_LastIndexOf)((Object__String)i0, 46u, i1);
  i = i1;
  i2 = i1>=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2701)))), Object__StringDesc_IndexOf)),Object__StringDesc_IndexOf)((Object__String)i0, 47u, i1);
  i2 = i2<0;
  
l5:
  if (i2) goto l7;
  *root = (Object__String)i0;
  *ext = (Object__String)((OOC_INT32)_c1);
  goto l8;
l7:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2746)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, 0, i1);
  *root = (Object__String)i2;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 2799));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2781)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, i1, i2);
  *ext = (Object__String)i0;
l8:
  return;
  ;
}

Object__CharsLatin1 OS_Path__Encode(Object__String path) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)path;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3350)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 95u);
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  return (Object__CharsLatin1)i0;
  ;
}

Object__String OS_Path__Decode(const OOC_CHAR8 path[], OOC_LEN path_0d) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)path, path_0d);
  return (Object__String)i0;
  ;
}

void OOC_OS_Path_init(void) {
  _c0 = Object__NewLatin1Region("", 1, 0, 0);
  _c1 = Object__NewLatin1Region("", 1, 0, 0);

  return;
  ;
}

/* --- */
