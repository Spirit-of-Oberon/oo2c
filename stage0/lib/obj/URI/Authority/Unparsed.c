#include <URI/Authority/Unparsed.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI_Authority_Unparsed__Init(URI_Authority_Unparsed__Authority auth, Object__String unparsed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)auth;
  URI__InitAuthority((URI__Authority)i0);
  i1 = (OOC_INT32)unparsed;
  _assert((i1!=(OOC_INT32)0), 127, 1480);
  *(OOC_INT32*)(_check_pointer(i0, 1513)) = i1;
  return;
  ;
}

URI_Authority_Unparsed__Authority URI_Authority_Unparsed__New(Object__String unparsed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Authority_Unparsed__Authority.baseTypes[0]);
  i1 = (OOC_INT32)unparsed;
  URI_Authority_Unparsed__Init((URI_Authority_Unparsed__Authority)i0, (Object__String)i1);
  return (URI_Authority_Unparsed__Authority)i0;
  ;
}

URI_Authority_Unparsed__Authority URI_Authority_Unparsed__AuthorityDesc_Clone(URI_Authority_Unparsed__Authority auth) {
  register OOC_INT32 i0,i1;
  URI_Authority_Unparsed__Authority copy;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Authority_Unparsed__Authority.baseTypes[0]);
  copy = (URI_Authority_Unparsed__Authority)i0;
  i1 = (OOC_INT32)auth;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1810)))), URI__AuthorityDesc_Copy)),URI__AuthorityDesc_Copy)((URI__Authority)i1, (URI__Authority)i0);
  return (URI_Authority_Unparsed__Authority)i0;
  ;
}

void URI_Authority_Unparsed__AuthorityDesc_Copy(URI_Authority_Unparsed__Authority auth, URI__Authority dest) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)dest;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1999)))), &_td_URI_Authority_Unparsed__AuthorityDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1990)))), 1990);
  goto l4;
l3:
  i1 = (OOC_INT32)auth;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2042));
  *(OOC_INT32*)(_check_pointer(i0, 2024)) = i1;
l4:
  return;
  ;
}

void URI_Authority_Unparsed__AuthorityDesc_ParseAuthority(URI_Authority_Unparsed__Authority auth, Object__CharsLatin1 str, OOC_INT16 offset) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i = 0;
  i0 = (OOC_INT32)str;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2321)), 0);
  i1 = URI_CharClass__SkipAuthChar((void*)(_check_pointer(i0, 2321)), i1, (void*)(OOC_INT32)&i);
  if (!i1) goto l7;
l2_loop:
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2321)), 0);
  i1 = URI_CharClass__SkipAuthChar((void*)(_check_pointer(i0, 2321)), i1, (void*)(OOC_INT32)&i);
  if (i1) goto l2_loop;
l7:
  i1 = _check_pointer(i0, 2346);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = i;
  i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 2346)));
  i1 = i1!=0u;
  if (i1) goto l10;
  i1 = (OOC_INT32)auth;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2529)), 0);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i0, 2529)), i2, 0, i3);
  *(OOC_INT32*)(_check_pointer(i1, 2490)) = i0;
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

void URI_Authority_Unparsed__AuthorityDesc_WriteXML(URI_Authority_Unparsed__Authority auth, TextRider__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2644)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<authority-unparsed>", 22);
  i1 = (OOC_INT32)auth;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2715));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2696)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2733)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</authority-unparsed>", 22);
  return;
  ;
}

void URI_Authority_Unparsed__AuthorityDesc_Append(URI_Authority_Unparsed__Authority auth, ADT_StringBuffer__StringBuffer sb) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sb;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2873)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1));
  i1 = (OOC_INT32)auth;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2906));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2894)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  return;
  ;
}

void OOC_URI_Authority_Unparsed_init(void) {
  _c0 = Object__NewLatin1Region("Illegal character in authority component", 41, 0, 40);
  _c1 = Object__NewLatin1Region("//", 3, 0, 2);

  return;
  ;
}

/* --- */
