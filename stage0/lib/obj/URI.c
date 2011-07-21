#include <URI.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI__InitURI(URI__URI uri, Object__String schemeId) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)schemeId;
  *(OOC_INT32*)(_check_pointer(i0, 5312)) = i1;
  return;
  ;
}

URI__URI URI__URIDesc_Clone(URI__URI uri) {

  _failed_function(5383); return 0;
  ;
}

void URI__URIDesc_Copy(URI__URI uri, URI__URI dest) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5820));
  i1 = i1==0;
  if (i1) goto l3;
  i1 = (OOC_INT32)dest;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5907));
  *(OOC_INT32*)(_check_pointer(i1, 5890)) = i0;
  goto l4;
l3:
  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)(_check_pointer(i0, 5853)) = 0;
l4:
  return;
  ;
}

void URI__URIDesc_SetSchemeId(URI__URI uri, Object__String schemeId) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)schemeId;
  *(OOC_INT32*)(_check_pointer(i0, 6136)) = i1;
  return;
  ;
}

void URI__URIDesc_WriteXML(URI__URI uri, TextRider__Writer w) {

  return;
  ;
}

Object__String8 URI__URIDesc_ToString(URI__URI uri) {

  _failed_function(6384); return 0;
  ;
}

void URI__URIDesc_AppendScheme(URI__URI uri, ADT_StringBuffer__StringBuffer sb) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6779));
  i1 = i1!=0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)sb;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6821));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6810)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6842)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c0));
l4:
  return;
  ;
}

URI__URI URI__URIDesc_MakeRelative(URI__URI uri, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)uri;
  return (URI__URI)i0;
  ;
}

IO__ByteChannel URI__URIDesc_GetChannel(URI__URI uri, OOC_INT8 mode) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_IO__NotImplemented.baseTypes[0]);
  IO__ErrorDesc_INIT((IO__Error)i0, (Object__String)(OOC_INT32)0);
  Exception__Raise((void*)i0);
  _failed_function(7633); return 0;
  ;
}

void URI__InitOpaqueURI(URI__OpaqueURI uri, Object__String schemeId) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)schemeId;
  URI__InitURI((URI__URI)i0, (Object__String)i1);
  return;
  ;
}

void URI__OpaqueURIDesc_ParseOpaquePart(URI__OpaqueURI uri, Object__CharsLatin1 str, OOC_INT16 offset) {

  return;
  ;
}

void URI__InitAuthority(URI__Authority auth) {

  return;
  ;
}

URI__Authority URI__AuthorityDesc_Clone(URI__Authority auth) {

  _failed_function(9874); return 0;
  ;
}

void URI__AuthorityDesc_Copy(URI__Authority auth, URI__Authority dest) {

  return;
  ;
}

void URI__AuthorityDesc_ParseAuthority(URI__Authority auth, Object__CharsLatin1 str, OOC_INT16 offset) {

  return;
  ;
}

void URI__AuthorityDesc_WriteXML(URI__Authority auth, TextRider__Writer w) {

  return;
  ;
}

void URI__AuthorityDesc_Append(URI__Authority auth, ADT_StringBuffer__StringBuffer sb) {

  return;
  ;
}

void URI__InitQuery(URI__Query query) {

  return;
  ;
}

URI__Query URI__QueryDesc_Clone(URI__Query query) {

  _failed_function(11393); return 0;
  ;
}

void URI__QueryDesc_Copy(URI__Query query, URI__Query dest) {

  return;
  ;
}

void URI__QueryDesc_ParseQuery(URI__Query query, Object__CharsLatin1 str, OOC_INT16 offset) {

  return;
  ;
}

void URI__QueryDesc_WriteXML(URI__Query query, TextRider__Writer w) {

  return;
  ;
}

void URI__QueryDesc_Append(URI__Query query, ADT_StringBuffer__StringBuffer sb) {

  return;
  ;
}

void URI__InitHierarchicalURI(URI__HierarchicalURI uri, Object__String schemeId, URI__Authority authority, URI__Query query) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)schemeId;
  URI__InitURI((URI__URI)i0, (Object__String)i1);
  i1 = (OOC_INT32)authority;
  *(OOC_INT32*)((_check_pointer(i0, 12971))+4) = i1;
  i1 = (OOC_INT32)query;
  *(OOC_INT32*)((_check_pointer(i0, 13004))+8) = i1;
  return;
  ;
}

OOC_CHAR8 URI__HierarchicalURIDesc_AuthorityMandatory(URI__HierarchicalURI uri) {

  return 0u;
  ;
}

void URI__HierarchicalURIDesc_Copy(URI__HierarchicalURI uri, URI__URI dest) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)dest;
  URI__URIDesc_Copy((URI__URI)i0, (URI__URI)i1);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13542)))), &_td_URI__HierarchicalURIDesc);
  if (i2) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13533)))), 13533);
  goto l12;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13576))+4);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l6;
  *(OOC_INT32*)((_check_pointer(i1, 13674))+4) = (OOC_INT32)0;
  goto l7;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13630))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13630))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13641)))), URI__AuthorityDesc_Clone)),URI__AuthorityDesc_Clone)((URI__Authority)i3);
  *(OOC_INT32*)((_check_pointer(i1, 13612))+4) = i2;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13717))+8);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l10;
  *(OOC_INT32*)((_check_pointer(i1, 13803))+8) = (OOC_INT32)0;
  goto l12;
l10:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13763))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13763))+8);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13770)))), URI__QueryDesc_Clone)),URI__QueryDesc_Clone)((URI__Query)i0);
  *(OOC_INT32*)((_check_pointer(i1, 13749))+8) = i0;
l12:
  return;
  ;
}

URI__Authority URI__HierarchicalURIDesc_NewAuthority(URI__HierarchicalURI uri) {

  _failed_function(13893); return 0;
  ;
}

void URI__HierarchicalURIDesc_SetAuthority(URI__HierarchicalURI uri, URI__Authority auth) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)auth;
  *(OOC_INT32*)((_check_pointer(i0, 14372))+4) = i1;
  return;
  ;
}

URI__Query URI__HierarchicalURIDesc_NewQuery(URI__HierarchicalURI uri) {

  _failed_function(14457); return 0;
  ;
}

void URI__HierarchicalURIDesc_SetQuery(URI__HierarchicalURI uri, URI__Query query) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)query;
  *(OOC_INT32*)((_check_pointer(i0, 14893))+8) = i1;
  return;
  ;
}

void URI__HierarchicalURIDesc_ResolveRelative(URI__HierarchicalURI uri, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)uri;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15229));
  i1 = i1==0;
  if (!i1) goto l3;
  i1 = (OOC_INT32)baseURI;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15282));
  *(OOC_INT32*)(_check_pointer(i0, 15261)) = i1;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15313))+4);
  i1 = i1==0;
  if (!i1) goto l6;
  i1 = (OOC_INT32)baseURI;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15368))+4);
  *(OOC_INT32*)((_check_pointer(i0, 15346))+4) = i1;
l6:
  return;
  ;
}

void URI__HierarchicalURIDesc_ClearPath(URI__HierarchicalURI uri) {

  return;
  ;
}

void URI__HierarchicalURIDesc_ParsePath(URI__HierarchicalURI uri, Object__CharsLatin1 str, OOC_CHAR8 absolute, OOC_INT16 offset) {

  return;
  ;
}

URI__URI URI__HierarchicalURIDesc_MakeRelative(URI__HierarchicalURI uri, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  ADT_StringBuffer__StringBuffer a1;
  ADT_StringBuffer__StringBuffer a2;
  URI__URI copy;
  auto OOC_CHAR8 URI__HierarchicalURIDesc_MakeRelative_Equal(Object__String s1, Object__String s2);
    
    OOC_CHAR8 URI__HierarchicalURIDesc_MakeRelative_Equal(Object__String s1, Object__String s2) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)s1;
      i1 = (OOC_INT32)s2;
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16460)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i1);
      return i0;
      ;
    }


  i0 = (OOC_INT32)baseURI;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l21;
  i1 = (OOC_INT32)uri;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16626));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16650));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16626));
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16635)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i4, (Object__Object)i3);
  i2 = !i2;
  if (i2) goto l19;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16766))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16795))+4);
  i2 = (i2==(OOC_INT32)0)!=(i3==(OOC_INT32)0);
  if (i2) goto l17;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17133))+4);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l22;
  i2 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c1));
  a1 = (ADT_StringBuffer__StringBuffer)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17194))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17194))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17205)))), URI__AuthorityDesc_Append)),URI__AuthorityDesc_Append)((URI__Authority)i1, (ADT_StringBuffer__StringBuffer)i2);
  i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c2));
  a2 = (ADT_StringBuffer__StringBuffer)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17261))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17261))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17272)))), URI__AuthorityDesc_Append)),URI__AuthorityDesc_Append)((URI__Authority)i0, (ADT_StringBuffer__StringBuffer)i1);
  i0 = *(OOC_INT32*)((_check_pointer(i2, 17299))+4);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 17311))+4);
  i0 = i0!=i3;
  if (i0) goto l11;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17332)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i2);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17347)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
  i0 = URI__HierarchicalURIDesc_MakeRelative_Equal((Object__String)i0, (Object__String)i1);
  i0 = !i0;
  
  goto l13;
l11:
  i0=1u;
l13:
  if (!i0) goto l22;
  i0 = (OOC_INT32)uri;
  return (URI__URI)i0;
  goto l22;
l17:
  return (URI__URI)i1;
  goto l22;
l19:
  return (URI__URI)i1;
  goto l22;
l21:
  i0 = (OOC_INT32)uri;
  return (URI__URI)i0;
l22:
  i0 = (OOC_INT32)uri;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17529)))), URI__URIDesc_Clone)),URI__URIDesc_Clone)((URI__URI)i0);
  copy = (URI__URI)i0;
  *(OOC_INT32*)(_check_pointer(i0, 17548)) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17576)))), &_td_URI__HierarchicalURIDesc, 17576)), 17592))+4) = (OOC_INT32)0;
  return (URI__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17628)))), &_td_URI__HierarchicalURIDesc, 17628));
  ;
}

void URI__HierarchicalURIDesc_AppendPath(URI__HierarchicalURI uri, ADT_StringBuffer__StringBuffer sb) {

  return;
  ;
}

void URI__InitFragment(URI__Fragment frag) {

  return;
  ;
}

URI__Fragment URI__FragmentDesc_Clone(URI__Fragment frag) {

  _failed_function(18086); return 0;
  ;
}

void URI__FragmentDesc_Copy(URI__Fragment frag, URI__Fragment dest) {

  return;
  ;
}

void URI__FragmentDesc_ParseFragment(URI__Fragment frag, Object__CharsLatin1 str, OOC_INT16 offset) {

  return;
  ;
}

void URI__FragmentDesc_WriteXML(URI__Fragment frag, TextRider__Writer w) {

  return;
  ;
}

void URI__FragmentDesc_Append(URI__Fragment frag, ADT_StringBuffer__StringBuffer sb) {

  return;
  ;
}

URI__Reference URI__NewReference(URI__URI uri, URI__Fragment fragment) {
  register OOC_INT32 i0,i1;
  URI__Reference ref;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI__Reference.baseTypes[0]);
  ref = (URI__Reference)i0;
  i1 = (OOC_INT32)uri;
  *(OOC_INT32*)(_check_pointer(i0, 19667)) = i1;
  i1 = (OOC_INT32)fragment;
  *(OOC_INT32*)((_check_pointer(i0, 19688))+4) = i1;
  return (URI__Reference)i0;
  ;
}

void URI__ReferenceDesc_WriteXML(URI__Reference ref, TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19922)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<uri-reference>", 17);
  i1 = (OOC_INT32)ref;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19978));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19978));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19983)))), URI__URIDesc_WriteXML)),URI__URIDesc_WriteXML)((URI__URI)i3, (TextRider__Writer)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20010))+4);
  i2 = i2!=0;
  if (!i2) goto l4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20042))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20042))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20052)))), URI__FragmentDesc_WriteXML)),URI__FragmentDesc_WriteXML)((URI__Fragment)i1, (TextRider__Writer)i0);
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20081)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012</uri-reference>", 18);
  return;
  ;
}

Object__String8 URI__ReferenceDesc_ToString(URI__Reference ref) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer sb;
  Object__String str;

  i0 = (OOC_INT32)ref;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20447));
  i1 = i1!=0;
  if (i1) goto l3;
  i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c3));
  sb = (ADT_StringBuffer__StringBuffer)i1;
  
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20497));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20497));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20501)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i2);
  i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)i1);
  sb = (ADT_StringBuffer__StringBuffer)i1;
  
l4:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20578))+4);
  i2 = i2!=0;
  if (!i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20609))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20609))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20618)))), URI__FragmentDesc_Append)),URI__FragmentDesc_Append)((URI__Fragment)i0, (ADT_StringBuffer__StringBuffer)i1);
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20653)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
  str = (Object__String)i0;
  return (Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20688)))), &_td_Object__String8Desc, 20688));
  ;
}

void URI__RegisterScheme(URI__URI scheme) {
  auto void URI__RegisterScheme_Append(URI__List *list);
    
    void URI__RegisterScheme_Append(URI__List *list) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l7;
      i1 = (OOC_INT32)scheme;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 21314));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21345))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 21352));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 21314));
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21323)))), Object__StringDesc_EqualsIgnoreCase)),Object__StringDesc_EqualsIgnoreCase)((Object__String)i1, (Object__Object)i3);
      if (i1) goto l5;
      URI__RegisterScheme_Append((void*)(_check_pointer(i0, 21430)));
      goto l8;
l5:
      i1 = (OOC_INT32)scheme;
      *(OOC_INT32*)((_check_pointer(i0, 21380))+4) = i1;
      goto l8;
l7:
      i0 = (OOC_INT32)RT0__NewObject(_td_URI__List.baseTypes[0]);
      *list = (URI__List)i0;
      *(OOC_INT32*)(_check_pointer(i0, 21250)) = (OOC_INT32)0;
      i0 = (OOC_INT32)*list;
      i1 = (OOC_INT32)scheme;
      *(OOC_INT32*)((_check_pointer(i0, 21277))+4) = i1;
l8:
      return;
      ;
    }


  URI__RegisterScheme_Append((void*)(OOC_INT32)&URI__schemeList);
  return;
  ;
}

URI__URI URI__GetScheme(Object__String name) {
  register OOC_INT32 i0,i1,i2;
  URI__List scheme;

  i0 = (OOC_INT32)URI__schemeList;
  scheme = (URI__List)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)name;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21857))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21864));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21833)))), Object__StringDesc_EqualsIgnoreCase)),Object__StringDesc_EqualsIgnoreCase)((Object__String)i1, (Object__Object)i2);
  i1 = !i1;
  
l5:
  if (!i1) goto l17;
  i1 = (OOC_INT32)name;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21900));
  scheme = (URI__List)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21857))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21864));
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21833)))), Object__StringDesc_EqualsIgnoreCase)),Object__StringDesc_EqualsIgnoreCase)((Object__String)i1, (Object__Object)i2);
  i2 = !i2;
  
l13:
  if (i2) goto l8_loop;
l17:
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l20;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21988))+4);
  return (URI__URI)i0;
  goto l21;
l20:
  return (URI__URI)(OOC_INT32)0;
l21:
  _failed_function(21532); return 0;
  ;
}

void OOC_URI_init(void) {
  _c0 = Object__NewLatin1Char(58u);
  _c1 = Object__NewLatin1Region("", 1, 0, 0);
  _c2 = Object__NewLatin1Region("", 1, 0, 0);
  _c3 = Object__NewLatin1Region("", 1, 0, 0);

  URI__schemeList = (URI__List)(OOC_INT32)0;
  return;
  ;
}

/* --- */
