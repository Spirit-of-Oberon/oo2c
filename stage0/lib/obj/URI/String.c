#include <URI/String.d>
#include <__oo2c.h>
#include <setjmp.h>

Object__String URI_String__Unescape(Object__String x) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__CharsLatin1 str;
  OOC_INT16 i;
  OOC_CHAR8 *res;
  OOC_INT16 j;
  auto OOC_INT16 URI_String__Unescape_Hex(OOC_CHAR8 ch);
    
    OOC_INT16 URI_String__Unescape_Hex(OOC_CHAR8 ch) {
      register OOC_INT32 i0;

      i0 = ch;
      switch (i0) {
      case 48u ... 57u:
        return (i0-48);
        goto l6;
      case 97u ... 102u:
        return (i0-87);
        goto l6;
      case 65u ... 70u:
        return (i0-55);
        goto l6;
      default:
        _failed_case(i0, 1493);
        goto l6;
      }
l6:
      _failed_function(1452); return 0;
      ;
    }


  i0 = (OOC_INT32)x;
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1718)))), &_td_Object__String8Desc, 1718)));
  str = (Object__CharsLatin1)i1;
  i = 0;
  i2 = _check_pointer(i1, 1773);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT16, 1773)));
  i2 = i2!=0u;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = _check_pointer(i1, 1789);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT16, 1789)));
  i2 = i2!=37u;
  
l5:
  if (i2) goto l7;
  i2=0;
  goto l17;
l7:
  i2=0;
l8_loop:
  i2 = i2+1;
  i = i2;
  i3 = _check_pointer(i1, 1773);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 1773)));
  i3 = i3!=0u;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = _check_pointer(i1, 1789);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 1789)));
  i3 = i3!=37u;
  
l13:
  if (i3) goto l8_loop;
l17:
  i3 = _check_pointer(i1, 1837);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 1837)));
  i2 = i2==0u;
  if (i2) goto l36;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 1901)), 0);
  i0 = (OOC_INT32)RT0__NewObject(_td_URI_String__1409.baseTypes[0], i0);
  res = (void*)i0;
  i = 0;
  j = 0;
  i2 = _check_pointer(i1, 1944);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT16, 1944)));
  i2 = i2!=0u;
  if (i2) goto l22;
  i1=0;
  goto l35;
l22:
  i2=0;i3=0;
l23_loop:
  i4 = _check_pointer(i1, 1972);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT16, 1972)));
  i4 = i4==37u;
  if (i4) goto l26;
  i4 = _check_pointer(i0, 2168);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i1, 2178);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT8*)(i6+(_check_index(i2, i7, OOC_UINT16, 2178)));
  *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT16, 2168))) = i6;
  i2 = i2+1;
  i = i2;
  
  goto l30;
l26:
  i4 = _check_pointer(i0, 2001);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i1, 2020);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT8*)(i6+(_check_index((i2+1), i7, OOC_UINT16, 2020)));
  i6 = URI_String__Unescape_Hex(i6);
  i7 = _check_pointer(i1, 2039);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index((i2+2), i8, OOC_UINT16, 2039)));
  i7 = URI_String__Unescape_Hex(i7);
  *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT16, 2001))) = ((i6*16)+i7);
  i4 = _check_pointer(i0, 2065);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT16, 2065)));
  i4 = i4==0u;
  if (!i4) goto l29;
  i4 = _check_pointer(i0, 2095);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT16, 2095))) = 32u;
l29:
  i2 = i2+3;
  i = i2;
  
l30:
  i3 = i3+1;
  j = i3;
  i4 = _check_pointer(i1, 1944);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT16, 1944)));
  i4 = i4!=0u;
  if (i4) goto l23_loop;
l34:
  i1=i3;
l35:
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2280)), 0);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i0, 2280)), i2, 0, i1);
  return (Object__String)i0;
  goto l37;
l36:
  return (Object__String)i0;
l37:
  _failed_function(994); return 0;
  ;
}

void URI_String__AppendEscaped(Object__String source, const OOC_CHAR8 unreserved__ref[], OOC_LEN unreserved_0d, ADT_StringBuffer__StringBuffer dest) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(unreserved,OOC_CHAR8 ,unreserved_0d)
  Object__CharsLatin1 src;
  OOC_INT16 i;
  auto OOC_CHAR8 URI_String__AppendEscaped_ToHex(OOC_INT16 i);
    
    OOC_CHAR8 URI_String__AppendEscaped_ToHex(OOC_INT16 i) {
      register OOC_INT32 i0,i1;

      i0 = i;
      i1 = i0<10;
      if (i1) goto l3;
      return (i0+55);
      goto l4;
l3:
      return (i0+48);
l4:
      _failed_function(2962); return 0;
      ;
    }


  OOC_INITIALIZE_VPAR(unreserved__ref,unreserved,OOC_CHAR8 ,unreserved_0d)
  i0 = (OOC_INT32)source;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3164)))), &_td_Object__String8Desc, 3164)));
  src = (Object__CharsLatin1)i0;
  i = 0;
  i1 = _check_pointer(i0, 3214);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT16, 3214)));
  i1 = i1!=0u;
  if (!i1) goto l16;
  i1 = (OOC_INT32)dest;
  i2=0;
l3_loop:
  i3 = _check_pointer(i0, 3264);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 3264)));
  i3 = URI_CharClass__IsUnreserved(i3);
  i3 = !i3;
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = _check_pointer(i0, 3304);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 3304)));
  i3 = URI_CharClass__IsMember(i3, (void*)(OOC_INT32)unreserved, unreserved_0d);
  i3 = !i3;
  
l8:
  if (i3) goto l10;
  i3 = _check_pointer(i0, 3522);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 3522)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3501)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, i3);
  goto l11;
l10:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3338)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, 37u);
  i3 = _check_pointer(i0, 3405);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 3405)));
  i3 = URI_String__AppendEscaped_ToHex((i3>>4));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3374)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, i3);
  i3 = _check_pointer(i0, 3463);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 3463)));
  i3 = URI_String__AppendEscaped_ToHex((_mod(i3,16)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3432)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i1, i3);
l11:
  i2 = i2+1;
  i = i2;
  i3 = _check_pointer(i0, 3214);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 3214)));
  i3 = i3!=0u;
  if (i3) goto l3_loop;
l16:
  return;
  ;
}

void OOC_URI_String_init(void) {

  return;
  ;
}

void OOC_URI_String_destroy(void) {
}

/* --- */
