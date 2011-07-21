#include <URI/Query/Unparsed.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI_Query_Unparsed__Init(URI_Query_Unparsed__Query query, Object__String unparsed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)query;
  URI__InitQuery((URI__Query)i0);
  i1 = (OOC_INT32)unparsed;
  _assert((i1!=(OOC_INT32)0), 127, 1475);
  *(OOC_INT32*)(_check_pointer(i0, 1509)) = i1;
  return;
  ;
}

URI_Query_Unparsed__Query URI_Query_Unparsed__New(Object__String unparsed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Query_Unparsed__Query.baseTypes[0]);
  i1 = (OOC_INT32)unparsed;
  URI_Query_Unparsed__Init((URI_Query_Unparsed__Query)i0, (Object__String)i1);
  return (URI_Query_Unparsed__Query)i0;
  ;
}

URI_Query_Unparsed__Query URI_Query_Unparsed__QueryDesc_Clone(URI_Query_Unparsed__Query query) {
  register OOC_INT32 i0,i1;
  URI_Query_Unparsed__Query copy;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Query_Unparsed__Query.baseTypes[0]);
  copy = (URI_Query_Unparsed__Query)i0;
  i1 = (OOC_INT32)query;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1792)))), URI__QueryDesc_Copy)),URI__QueryDesc_Copy)((URI__Query)i1, (URI__Query)i0);
  return (URI_Query_Unparsed__Query)i0;
  ;
}

void URI_Query_Unparsed__QueryDesc_Copy(URI_Query_Unparsed__Query query, URI__Query dest) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)dest;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1975)))), &_td_URI_Query_Unparsed__QueryDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1966)))), 1966);
  goto l4;
l3:
  i1 = (OOC_INT32)query;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2014));
  *(OOC_INT32*)(_check_pointer(i0, 1996)) = i1;
l4:
  return;
  ;
}

void URI_Query_Unparsed__QueryDesc_ParseQuery(URI_Query_Unparsed__Query query, Object__CharsLatin1 str, OOC_INT16 offset) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i = 0;
  i0 = (OOC_INT32)str;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2274)), 0);
  i1 = URI_CharClass__SkipURIC((void*)(_check_pointer(i0, 2274)), i1, (void*)(OOC_INT32)&i);
  if (!i1) goto l7;
l2_loop:
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2274)), 0);
  i1 = URI_CharClass__SkipURIC((void*)(_check_pointer(i0, 2274)), i1, (void*)(OOC_INT32)&i);
  if (i1) goto l2_loop;
l7:
  i1 = _check_pointer(i0, 2299);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = i;
  i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 2299)));
  i1 = i1!=0u;
  if (i1) goto l10;
  i1 = (OOC_INT32)query;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2479)), 0);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i0, 2479)), i2, 0, i3);
  *(OOC_INT32*)(_check_pointer(i1, 2440)) = i0;
  goto l11;
l10:
  i0 = offset;
  i1 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i1, (Object__String)((OOC_INT32)_c0), (i3+i0));
  Exception__Raise((void*)i1);
l11:
  return;
  ;
}

void URI_Query_Unparsed__QueryDesc_WriteXML(URI_Query_Unparsed__Query query, TextRider__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2587)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012<query-unparsed>", 18);
  i1 = (OOC_INT32)query;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2655));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2635)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2673)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</query-unparsed>", 18);
  return;
  ;
}

void URI_Query_Unparsed__QueryDesc_Append(URI_Query_Unparsed__Query query, ADT_StringBuffer__StringBuffer sb) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sb;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2807)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1));
  i1 = (OOC_INT32)query;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2840));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2827)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_URI_Query_Unparsed_init(void) {
  _c0 = Object__NewLatin1Region((OOC_CHAR8*)"Illegal character in query component", 37, 0, 36);
  _c1 = Object__NewLatin1Char(63u);

  return;
  ;
}

void OOC_URI_Query_Unparsed_destroy(void) {
}

/* --- */
