#include <URI/Scheme/Opaque.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI_Scheme_Opaque__Init(URI_Scheme_Opaque__Generic uri, Object__String schemeId, Object__String opaque) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)schemeId;
  URI__InitOpaqueURI((URI__OpaqueURI)i0, (Object__String)i1);
  i1 = (OOC_INT32)opaque;
  _assert((i1!=(OOC_INT32)0), 127, 1299);
  *(OOC_INT32*)((_check_pointer(i0, 1329))+4) = i1;
  return;
  ;
}

URI_Scheme_Opaque__Generic URI_Scheme_Opaque__New(Object__String schemeId, Object__String opaque) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Opaque__Generic.baseTypes[0]);
  i1 = (OOC_INT32)schemeId;
  i2 = (OOC_INT32)opaque;
  URI_Scheme_Opaque__Init((URI_Scheme_Opaque__Generic)i0, (Object__String)i1, (Object__String)i2);
  return (URI_Scheme_Opaque__Generic)i0;
  ;
}

URI_Scheme_Opaque__Generic URI_Scheme_Opaque__GenericDesc_Clone(URI_Scheme_Opaque__Generic uri) {
  register OOC_INT32 i0,i1;
  URI_Scheme_Opaque__Generic copy;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_Opaque__Generic.baseTypes[0]);
  copy = (URI_Scheme_Opaque__Generic)i0;
  i1 = (OOC_INT32)uri;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1622)))), URI__URIDesc_Copy)),URI__URIDesc_Copy)((URI__URI)i1, (URI__URI)i0);
  return (URI_Scheme_Opaque__Generic)i0;
  ;
}

void URI_Scheme_Opaque__GenericDesc_Copy(URI_Scheme_Opaque__Generic uri, URI__URI dest) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)dest;
  URI__URIDesc_Copy((URI__URI)i0, (URI__URI)i1);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1759)))), &_td_URI_Scheme_Opaque__GenericDesc);
  if (i2) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1750)))), 1750);
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1797))+4);
  *(OOC_INT32*)((_check_pointer(i1, 1782))+4) = i0;
l4:
  return;
  ;
}

static OOC_INT16 URI_Scheme_Opaque__IsValidOpaqueStr(const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  OOC_INT16 i;

  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 1942)));
  i0 = i0==47u;
  if (i0) goto l14;
  i = 0;
  i0 = URI_CharClass__SkipURIC((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)&i);
  if (!i0) goto l9;
l4_loop:
  i0 = URI_CharClass__SkipURIC((void*)(OOC_INT32)str, str_0d, (void*)(OOC_INT32)&i);
  if (i0) goto l4_loop;
l9:
  i0 = i;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 2057)));
  i1 = i1==0u;
  if (i1) goto l12;
  return i0;
  goto l15;
l12:
  return (-1);
  goto l15;
l14:
  return 0;
l15:
  _failed_function(1838); return 0;
  ;
}

void URI_Scheme_Opaque__GenericDesc_ParseOpaquePart(URI_Scheme_Opaque__Generic uri, Object__CharsLatin1 str, OOC_INT16 offset) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT16 pos;

  i0 = (OOC_INT32)str;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2345)), 0);
  i1 = URI_Scheme_Opaque__IsValidOpaqueStr((void*)(_check_pointer(i0, 2345)), i1);
  pos = i1;
  i2 = i1<0;
  if (i2) goto l3;
  i0 = offset;
  i2 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i2, (Object__String)((OOC_INT32)_c0), (i1+i0));
  Exception__Raise((void*)i2);
  goto l4;
l3:
  i1 = (OOC_INT32)uri;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2428)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i0, 2428)), i2);
  i0 = (OOC_INT32)URI_String__Unescape((Object__String)i0);
  *(OOC_INT32*)((_check_pointer(i1, 2380))+4) = i0;
l4:
  return;
  ;
}

void URI_Scheme_Opaque__GenericDesc_WriteXML(URI_Scheme_Opaque__Generic uri, TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2681)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<opaque-uri>", 14);
  i1 = (OOC_INT32)uri;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2731));
  i2 = i2!=0;
  if (!i2) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2761)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<scheme>", 10);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2821));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2803)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2841)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</scheme>", 10);
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2883)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<opaque-part>", 15);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2946))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2928)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2962)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</opaque-part>", 15);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3001)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012</opaque-uri>", 15);
  return;
  ;
}

Object__String8 URI_Scheme_Opaque__GenericDesc_ToString(URI_Scheme_Opaque__Generic uri) {
  register OOC_INT32 i0,i1;
  ADT_StringBuffer__StringBuffer sb;
  Object__String str;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c1));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)uri;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3216)))), URI__URIDesc_AppendScheme)),URI__URIDesc_AppendScheme)((URI__URI)i1, (ADT_StringBuffer__StringBuffer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3266))+4);
  URI_String__AppendEscaped((Object__String)i1, ";/?:@&=+$,[]", 13, (ADT_StringBuffer__StringBuffer)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3314)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  str = (Object__String)i0;
  return (Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3349)))), &_td_Object__String8Desc, 3349));
  ;
}

void OOC_URI_Scheme_Opaque_init(void) {
  _c0 = Object__NewLatin1Region("Illegal character for opaque component of an URI", 49, 0, 48);
  _c1 = Object__NewLatin1Region("", 1, 0, 0);

  return;
  ;
}

/* --- */
