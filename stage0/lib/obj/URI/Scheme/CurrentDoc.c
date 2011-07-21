#include <URI/Scheme/CurrentDoc.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI_Scheme_CurrentDoc__Init(URI_Scheme_CurrentDoc__CurrentDoc uri) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)uri;
  URI__InitURI((URI__URI)i0, (Object__String)(OOC_INT32)0);
  return;
  ;
}

URI_Scheme_CurrentDoc__CurrentDoc URI_Scheme_CurrentDoc__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_CurrentDoc__CurrentDoc.baseTypes[0]);
  URI_Scheme_CurrentDoc__Init((URI_Scheme_CurrentDoc__CurrentDoc)i0);
  return (URI_Scheme_CurrentDoc__CurrentDoc)i0;
  ;
}

URI__URI URI_Scheme_CurrentDoc__CurrentDocDesc_Clone(URI_Scheme_CurrentDoc__CurrentDoc uri) {
  register OOC_INT32 i0,i1;
  URI_Scheme_CurrentDoc__CurrentDoc copy;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_CurrentDoc__CurrentDoc.baseTypes[0]);
  copy = (URI_Scheme_CurrentDoc__CurrentDoc)i0;
  i1 = (OOC_INT32)uri;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1544)))), URI__URIDesc_Copy)),URI__URIDesc_Copy)((URI__URI)i1, (URI__URI)i0);
  return (URI__URI)i0;
  ;
}

void URI_Scheme_CurrentDoc__CurrentDocDesc_Copy(URI_Scheme_CurrentDoc__CurrentDoc uri, URI__URI dest) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)dest;
  i1 = (OOC_INT32)uri;
  URI__URIDesc_Copy((URI__URI)i1, (URI__URI)i0);
  return;
  ;
}

void URI_Scheme_CurrentDoc__CurrentDocDesc_WriteXML(URI_Scheme_CurrentDoc__CurrentDoc uri, TextRider__Writer w) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1757)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\012<current-document/>", 21);
  return;
  ;
}

Object__String8 URI_Scheme_CurrentDoc__CurrentDocDesc_ToString(URI_Scheme_CurrentDoc__CurrentDoc uri) {

  return (Object__String8)((OOC_INT32)_c0);
  ;
}

void OOC_URI_Scheme_CurrentDoc_init(void) {
  _c0 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);

  return;
  ;
}

void OOC_URI_Scheme_CurrentDoc_destroy(void) {
}

/* --- */
