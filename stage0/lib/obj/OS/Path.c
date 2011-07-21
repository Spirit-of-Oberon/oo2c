#include <OS/Path.d>
#include <__oo2c.h>
#include <setjmp.h>

Object__String OS_Path__DirName(Object__String path) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)path;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 1143));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1121)))), Object__StringDesc_LastIndexOf)),Object__StringDesc_LastIndexOf)((Object__String)i0, 47u, i1);
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
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1322)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i1-1));
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
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1322)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, (i2-1));
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1574)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, 0, i1);
  return (Object__String)i0;
l25:
  _failed_function(979); return 0;
  ;
}

Object__String OS_Path__BaseName(Object__String path) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)path;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2114));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2092)))), Object__StringDesc_LastIndexOf)),Object__StringDesc_LastIndexOf)((Object__String)i0, 47u, i1);
  i = i1;
  i2 = i1>=0;
  if (i2) goto l3;
  return (Object__String)i0;
  goto l4;
l3:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 2182));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2162)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, (i1+1), i2);
  return (Object__String)i0;
l4:
  _failed_function(1715); return 0;
  ;
}

void OS_Path__SplitExt(Object__String path, Object__String *root, Object__String *ext) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)path;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2693));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2671)))), Object__StringDesc_LastIndexOf)),Object__StringDesc_LastIndexOf)((Object__String)i0, 46u, i1);
  i = i1;
  i2 = i1>=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2726)))), Object__StringDesc_IndexOf)),Object__StringDesc_IndexOf)((Object__String)i0, 47u, i1);
  i2 = i2<0;
  
l5:
  if (i2) goto l7;
  *root = (Object__String)i0;
  *ext = (Object__String)((OOC_INT32)_c1);
  goto l8;
l7:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2771)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, 0, i1);
  *root = (Object__String)i2;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 2824));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2806)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, i1, i2);
  *ext = (Object__String)i0;
l8:
  return;
  ;
}

Object__CharsLatin1 OS_Path__Encode(Object__String path) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)path;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3375)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 95u);
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

Object__String OS_Path__QuoteForShell(Object__String path) {
  register OOC_INT32 i0;
  auto Object__String OS_Path__QuoteForShell_EscapeReservedChars(Object__String s, Object__String reserved, OOC_CHAR8 escape);
    
    Object__String OS_Path__QuoteForShell_EscapeReservedChars(Object__String s, Object__String reserved, OOC_CHAR8 escape) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_CHAR8 needQuote;
      ADT_StringBuffer__StringBuffer sb;
      OOC_INT32 i;
      OOC_CHAR32 c;

      needQuote = 0u;
      i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c2));
      sb = (ADT_StringBuffer__StringBuffer)i0;
      i1 = (OOC_INT32)s;
      i = 0;
      i2 = *(OOC_INT32*)(_check_pointer(i1, 4671));
      i3 = 0<i2;
      if (i3) goto l3;
      i2=0u;
      goto l17;
l3:
      i3 = (OOC_INT32)reserved;
      i4 = escape;
      i5=0;i6=0u;
l4_loop:
      i7 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4698)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i5);
      c = i7;
      i8 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4727)))), Object__StringDesc_IndexOf)),Object__StringDesc_IndexOf)((Object__String)i3, i7, 0);
      i8 = i8>=0;
      if (i8) goto l11;
      i8 = i7==32u;
      if (!i8) goto l12;
      needQuote = 1u;
      i6=1u;
      goto l12;
l11:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4762)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, i4);
      needQuote = 1u;
      i6=1u;
l12:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4887)))), ADT_StringBuffer__StringBufferDesc_AppendChar)),ADT_StringBuffer__StringBufferDesc_AppendChar)((ADT_StringBuffer__StringBuffer)i0, i7);
      i5 = i5+1;
      i = i5;
      i7 = i5<i2;
      if (i7) goto l4_loop;
l16:
      i2=i6;
l17:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4918)))), ADT_StringBuffer__StringBufferDesc_AppendChar)),ADT_StringBuffer__StringBufferDesc_AppendChar)((ADT_StringBuffer__StringBuffer)i0, 34u);
      if (i2) goto l20;
      return (Object__String)i1;
      goto l21;
l20:
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4973)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
      return (Object__String)i0;
l21:
      _failed_function(4418); return 0;
      ;
    }


  i0 = (OOC_INT32)path;
  i0 = (OOC_INT32)OS_Path__QuoteForShell_EscapeReservedChars((Object__String)i0, (Object__String)((OOC_INT32)_c3), 92u);
  return (Object__String)i0;
  ;
}

void OOC_OS_Path_init(void) {
  _c0 = Object__NewLatin1Region("", 1, 0, 0);
  _c1 = Object__NewLatin1Region("", 1, 0, 0);
  _c2 = Object__NewLatin1Char(34u);
  _c3 = Object__NewLatin1Region("\134\"", 3, 0, 2);

  return;
  ;
}

/* --- */
