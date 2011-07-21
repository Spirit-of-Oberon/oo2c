#include <OOC/Config/Assembler.d>
#include <__oo2c.h>
#include <setjmp.h>

Object__String OOC_Config_Assembler__AssembleFileCmd(URI__URI in, URI__URI out) {
  register OOC_INT32 i0,i1;
  ADT_StringBuffer__StringBuffer sb;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c0));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)in;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1121)))), &_td_URI_Scheme_File__URIDesc, 1121)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1105)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1144)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1));
  i1 = (OOC_INT32)out;
  i1 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1184)))), &_td_URI_Scheme_File__URIDesc, 1184)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1167)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1214)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  return (Object__String)i0;
  ;
}

void OOC_OOC_Config_Assembler_init(void) {
  _c0 = Object__NewLatin1Region("as ", 4, 0, 3);
  _c1 = Object__NewLatin1Region(" -o ", 5, 0, 4);

  return;
  ;
}

/* --- */
